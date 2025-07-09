/********************* I2C.c *************************************/
#include "AT24C02.h"

static I2C_HandleTypeDef *hi2c_at24c02 = NULL;

// 初始化 I2C
void I2C_Init(I2C_HandleTypeDef *hi2c) {
    hi2c_at24c02 = hi2c;
}

// 检查设备是否就绪
uint8_t AT24C02_IsDeviceReady(I2C_HandleTypeDef *hi2c) {
    return (HAL_I2C_IsDeviceReady(hi2c, AT24C02_ADDRESS, 3, 100) == HAL_OK);
}

// 写入单个字节
HAL_StatusTypeDef AT24C02_WriteByte(I2C_HandleTypeDef *hi2c, uint16_t memAddress, uint8_t data) {
    uint8_t buffer[2] = {(uint8_t)(memAddress & 0xFF), data};
    
    // 等待设备就绪
    uint32_t timeout = HAL_GetTick() + 20;
    while(HAL_I2C_IsDeviceReady(hi2c, AT24C02_ADDRESS, 3, 10) != HAL_OK) {
        if(HAL_GetTick() > timeout) return HAL_TIMEOUT;
    }
    
    return HAL_I2C_Master_Transmit(hi2c, AT24C02_ADDRESS, buffer, 2, 100);
}

// 读取单个字节
HAL_StatusTypeDef AT24C02_ReadByte(I2C_HandleTypeDef *hi2c, uint16_t memAddress, uint8_t *data) {
    uint8_t addr = (uint8_t)(memAddress & 0xFF);
    HAL_StatusTypeDef status;
    
    // 发送要读取的地址
    status = HAL_I2C_Master_Transmit(hi2c, AT24C02_ADDRESS, &addr, 1, 100);
    if(status != HAL_OK) return status;
    
    // 读取数据
    return HAL_I2C_Master_Receive(hi2c, AT24C02_ADDRESS, data, 1, 100);
}

// 分页写入（自动处理页边界）
HAL_StatusTypeDef AT24C02_WritePage(I2C_HandleTypeDef *hi2c, uint16_t memAddress, uint8_t *data, uint16_t size) {
    HAL_StatusTypeDef status;
    uint16_t bytesWritten = 0;
    uint16_t pageSize = 8; // AT24C02 页大小为8字节
    
    while(bytesWritten < size) {
        // 计算当前页剩余空间
        uint16_t pageOffset = memAddress % pageSize;
        uint16_t bytesToWrite = pageSize - pageOffset;
        
        // 确保不超过请求的大小
        if(bytesToWrite > (size - bytesWritten)) {
            bytesToWrite = size - bytesWritten;
        }
        
        // 等待设备就绪
        uint32_t timeout = HAL_GetTick() + 20;
        while(HAL_I2C_IsDeviceReady(hi2c, AT24C02_ADDRESS, 3, 10) != HAL_OK) {
            if(HAL_GetTick() > timeout) return HAL_TIMEOUT;
        }
        
        // 创建包含地址和数据的缓冲区
        uint8_t buffer[bytesToWrite + 1];
        buffer[0] = (uint8_t)(memAddress & 0xFF);
        memcpy(&buffer[1], &data[bytesWritten], bytesToWrite);
        
        // 写入数据
        status = HAL_I2C_Master_Transmit(hi2c, AT24C02_ADDRESS, buffer, bytesToWrite + 1, 100);
        if(status != HAL_OK) return status;
        
        // 更新计数器和地址
        bytesWritten += bytesToWrite;
        memAddress += bytesToWrite;
        
        // 等待写入完成
        HAL_Delay(5);
    }
    
    return HAL_OK;
}

// 读取缓冲区
HAL_StatusTypeDef AT24C02_ReadBuffer(I2C_HandleTypeDef *hi2c, uint16_t memAddress, uint8_t *data, uint16_t size) {
    uint8_t addr = (uint8_t)(memAddress & 0xFF);
    HAL_StatusTypeDef status;
    
    // 发送要读取的起始地址
    status = HAL_I2C_Master_Transmit(hi2c, AT24C02_ADDRESS, &addr, 1, 100);
    if(status != HAL_OK) return status;
    
    // 读取数据
    return HAL_I2C_Master_Receive(hi2c, AT24C02_ADDRESS, data, size, 100);
}

/***********************/
/********************* AT24C02_Ext.c *************************************/


// CRC16 计算函数
static uint16_t crc16(const uint8_t *data, uint16_t length) {
    uint16_t crc = 0xFFFF;
    while(length--) {
        crc ^= *data++;
        for(uint8_t i=0; i<8; i++) 
            crc = (crc & 1) ? (crc >> 1) ^ 0xA001 : (crc >> 1);
    }
    return crc;
}

// 初始化 AT24C02
uint8_t AT24C02_Init(I2C_HandleTypeDef *hi2c) {
    // 初始化 I2C
    I2C_Init(hi2c);
    
    // 检查设备是否响应
    if(!AT24C02_IsDeviceReady(hi2c)) {
        return 0;
    }
    
    // 检查是否是首次运行
    uint8_t initFlag;
    if(AT24C02_ReadByte(hi2c, INIT_FLAG_ADDRESS, &initFlag) != HAL_OK) {
        return 0;
    }
    
    return (initFlag == 0xA5) ? 1 : 0;
}

// 加载阈值
uint8_t AT24C02_LoadThresholds(Thresholds_TypeDef *thresholds) {
    // 读取整个阈值结构体 + CRC
    uint8_t buffer[sizeof(Thresholds_TypeDef) + 2];
    
    if(AT24C02_ReadBuffer(hi2c_at24c02, THRESHOLDS_ADDRESS, buffer, sizeof(buffer)) != HAL_OK) {
        return 0;
    }
    
    // 提取 CRC 值
    uint16_t storedCrc = (buffer[sizeof(Thresholds_TypeDef)] << 8) | buffer[sizeof(Thresholds_TypeDef) + 1];
    
    // 计算数据的 CRC
    uint16_t calculatedCrc = crc16(buffer, sizeof(Thresholds_TypeDef));
    
    // 验证 CRC
    if(storedCrc != calculatedCrc) {
        return 0;
    }
    
    // 复制数据到结构体
    memcpy(thresholds, buffer, sizeof(Thresholds_TypeDef));
    return 1;
}

// 保存阈值
uint8_t AT24C02_SaveThresholds(Thresholds_TypeDef *thresholds) {
    // 创建包含数据和 CRC 的缓冲区
    uint8_t buffer[sizeof(Thresholds_TypeDef) + 2];
    
    // 复制阈值数据
    memcpy(buffer, thresholds, sizeof(Thresholds_TypeDef));
    
    // 计算并添加 CRC
    uint16_t crc = crc16(buffer, sizeof(Thresholds_TypeDef));
    buffer[sizeof(Thresholds_TypeDef)] = (crc >> 8) & 0xFF;
    buffer[sizeof(Thresholds_TypeDef) + 1] = crc & 0xFF;
    
    // 写入数据
    if(AT24C02_WritePage(hi2c_at24c02, THRESHOLDS_ADDRESS, buffer, sizeof(buffer)) != HAL_OK) {
        return 0;
    }
    
    // 设置初始化标志
    uint8_t initFlag = 0xA5;
    if(AT24C02_WriteByte(hi2c_at24c02, INIT_FLAG_ADDRESS, initFlag) != HAL_OK) {
        return 0;
    }
    return 1;
}

// 检查是否是首次运行
uint8_t AT24C02_IsFirstRun(void) {
    uint8_t initFlag;
    if(AT24C02_ReadByte(hi2c_at24c02, INIT_FLAG_ADDRESS, &initFlag) != HAL_OK) {
        return 1; // 读取失败，当作首次运行
    }
    return (initFlag == 0xA5) ? 0 : 1;
}
