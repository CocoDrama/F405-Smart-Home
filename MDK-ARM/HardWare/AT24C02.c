/********************* I2C.c *************************************/
#include "AT24C02.h"

static I2C_HandleTypeDef *hi2c_at24c02 = NULL;

// ��ʼ�� I2C
void I2C_Init(I2C_HandleTypeDef *hi2c) {
    hi2c_at24c02 = hi2c;
}

// ����豸�Ƿ����
uint8_t AT24C02_IsDeviceReady(I2C_HandleTypeDef *hi2c) {
    return (HAL_I2C_IsDeviceReady(hi2c, AT24C02_ADDRESS, 3, 100) == HAL_OK);
}

// д�뵥���ֽ�
HAL_StatusTypeDef AT24C02_WriteByte(I2C_HandleTypeDef *hi2c, uint16_t memAddress, uint8_t data) {
    uint8_t buffer[2] = {(uint8_t)(memAddress & 0xFF), data};
    
    // �ȴ��豸����
    uint32_t timeout = HAL_GetTick() + 20;
    while(HAL_I2C_IsDeviceReady(hi2c, AT24C02_ADDRESS, 3, 10) != HAL_OK) {
        if(HAL_GetTick() > timeout) return HAL_TIMEOUT;
    }
    
    return HAL_I2C_Master_Transmit(hi2c, AT24C02_ADDRESS, buffer, 2, 100);
}

// ��ȡ�����ֽ�
HAL_StatusTypeDef AT24C02_ReadByte(I2C_HandleTypeDef *hi2c, uint16_t memAddress, uint8_t *data) {
    uint8_t addr = (uint8_t)(memAddress & 0xFF);
    HAL_StatusTypeDef status;
    
    // ����Ҫ��ȡ�ĵ�ַ
    status = HAL_I2C_Master_Transmit(hi2c, AT24C02_ADDRESS, &addr, 1, 100);
    if(status != HAL_OK) return status;
    
    // ��ȡ����
    return HAL_I2C_Master_Receive(hi2c, AT24C02_ADDRESS, data, 1, 100);
}

// ��ҳд�루�Զ�����ҳ�߽磩
HAL_StatusTypeDef AT24C02_WritePage(I2C_HandleTypeDef *hi2c, uint16_t memAddress, uint8_t *data, uint16_t size) {
    HAL_StatusTypeDef status;
    uint16_t bytesWritten = 0;
    uint16_t pageSize = 8; // AT24C02 ҳ��СΪ8�ֽ�
    
    while(bytesWritten < size) {
        // ���㵱ǰҳʣ��ռ�
        uint16_t pageOffset = memAddress % pageSize;
        uint16_t bytesToWrite = pageSize - pageOffset;
        
        // ȷ������������Ĵ�С
        if(bytesToWrite > (size - bytesWritten)) {
            bytesToWrite = size - bytesWritten;
        }
        
        // �ȴ��豸����
        uint32_t timeout = HAL_GetTick() + 20;
        while(HAL_I2C_IsDeviceReady(hi2c, AT24C02_ADDRESS, 3, 10) != HAL_OK) {
            if(HAL_GetTick() > timeout) return HAL_TIMEOUT;
        }
        
        // ����������ַ�����ݵĻ�����
        uint8_t buffer[bytesToWrite + 1];
        buffer[0] = (uint8_t)(memAddress & 0xFF);
        memcpy(&buffer[1], &data[bytesWritten], bytesToWrite);
        
        // д������
        status = HAL_I2C_Master_Transmit(hi2c, AT24C02_ADDRESS, buffer, bytesToWrite + 1, 100);
        if(status != HAL_OK) return status;
        
        // ���¼������͵�ַ
        bytesWritten += bytesToWrite;
        memAddress += bytesToWrite;
        
        // �ȴ�д�����
        HAL_Delay(5);
    }
    
    return HAL_OK;
}

// ��ȡ������
HAL_StatusTypeDef AT24C02_ReadBuffer(I2C_HandleTypeDef *hi2c, uint16_t memAddress, uint8_t *data, uint16_t size) {
    uint8_t addr = (uint8_t)(memAddress & 0xFF);
    HAL_StatusTypeDef status;
    
    // ����Ҫ��ȡ����ʼ��ַ
    status = HAL_I2C_Master_Transmit(hi2c, AT24C02_ADDRESS, &addr, 1, 100);
    if(status != HAL_OK) return status;
    
    // ��ȡ����
    return HAL_I2C_Master_Receive(hi2c, AT24C02_ADDRESS, data, size, 100);
}

/***********************/
/********************* AT24C02_Ext.c *************************************/


// CRC16 ���㺯��
static uint16_t crc16(const uint8_t *data, uint16_t length) {
    uint16_t crc = 0xFFFF;
    while(length--) {
        crc ^= *data++;
        for(uint8_t i=0; i<8; i++) 
            crc = (crc & 1) ? (crc >> 1) ^ 0xA001 : (crc >> 1);
    }
    return crc;
}

// ��ʼ�� AT24C02
uint8_t AT24C02_Init(I2C_HandleTypeDef *hi2c) {
    // ��ʼ�� I2C
    I2C_Init(hi2c);
    
    // ����豸�Ƿ���Ӧ
    if(!AT24C02_IsDeviceReady(hi2c)) {
        return 0;
    }
    
    // ����Ƿ����״�����
    uint8_t initFlag;
    if(AT24C02_ReadByte(hi2c, INIT_FLAG_ADDRESS, &initFlag) != HAL_OK) {
        return 0;
    }
    
    return (initFlag == 0xA5) ? 1 : 0;
}

// ������ֵ
uint8_t AT24C02_LoadThresholds(Thresholds_TypeDef *thresholds) {
    // ��ȡ������ֵ�ṹ�� + CRC
    uint8_t buffer[sizeof(Thresholds_TypeDef) + 2];
    
    if(AT24C02_ReadBuffer(hi2c_at24c02, THRESHOLDS_ADDRESS, buffer, sizeof(buffer)) != HAL_OK) {
        return 0;
    }
    
    // ��ȡ CRC ֵ
    uint16_t storedCrc = (buffer[sizeof(Thresholds_TypeDef)] << 8) | buffer[sizeof(Thresholds_TypeDef) + 1];
    
    // �������ݵ� CRC
    uint16_t calculatedCrc = crc16(buffer, sizeof(Thresholds_TypeDef));
    
    // ��֤ CRC
    if(storedCrc != calculatedCrc) {
        return 0;
    }
    
    // �������ݵ��ṹ��
    memcpy(thresholds, buffer, sizeof(Thresholds_TypeDef));
    return 1;
}

// ������ֵ
uint8_t AT24C02_SaveThresholds(Thresholds_TypeDef *thresholds) {
    // �����������ݺ� CRC �Ļ�����
    uint8_t buffer[sizeof(Thresholds_TypeDef) + 2];
    
    // ������ֵ����
    memcpy(buffer, thresholds, sizeof(Thresholds_TypeDef));
    
    // ���㲢��� CRC
    uint16_t crc = crc16(buffer, sizeof(Thresholds_TypeDef));
    buffer[sizeof(Thresholds_TypeDef)] = (crc >> 8) & 0xFF;
    buffer[sizeof(Thresholds_TypeDef) + 1] = crc & 0xFF;
    
    // д������
    if(AT24C02_WritePage(hi2c_at24c02, THRESHOLDS_ADDRESS, buffer, sizeof(buffer)) != HAL_OK) {
        return 0;
    }
    
    // ���ó�ʼ����־
    uint8_t initFlag = 0xA5;
    if(AT24C02_WriteByte(hi2c_at24c02, INIT_FLAG_ADDRESS, initFlag) != HAL_OK) {
        return 0;
    }
    return 1;
}

// ����Ƿ����״�����
uint8_t AT24C02_IsFirstRun(void) {
    uint8_t initFlag;
    if(AT24C02_ReadByte(hi2c_at24c02, INIT_FLAG_ADDRESS, &initFlag) != HAL_OK) {
        return 1; // ��ȡʧ�ܣ������״�����
    }
    return (initFlag == 0xA5) ? 0 : 1;
}
