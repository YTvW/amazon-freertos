/*
 * Copyright 2020 Espressif Systems (Shanghai) Co., Ltd.
 * All rights reserved.
 *
 * You may not use this file except in compliance with the terms and
 * conditions set forth in the accompanying LICENSE.TXT file.
 *
 * THESE MATERIALS ARE PROVIDED ON AN "AS IS" BASIS. ESPRESSIF/AMAZON SPECIFICALLY
 * DISCLAIMS, WITH RESPECT TO THESE MATERIALS, ALL WARRANTIES, EXPRESS,
 * IMPLIED, OR STATUTORY, INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT.
 */

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"

#include "iot_test_common_io_internal.h"
#include "iot_i2c.h"

/* UART */
const uint8_t uartTestPort[ UART_TEST_SET ] = { 2 };
/* Following configurations are not being used for now. */
const uint32_t uartIotUartFlowControl[ UART_TEST_SET ] = { 0 };
const uint32_t uartIotUartParity[ UART_TEST_SET ] = { 0 };
const uint32_t uartIotUartWordLength[ UART_TEST_SET ] = { 0 };
const uint32_t uartIotUartStopBits[ UART_TEST_SET ] = { 0 };

void SET_TEST_IOT_UART_CONFIG( int testSet )
{
    uctestIotUartPort = uartTestPort[ testSet ];
}

/* I2C */
const uint8_t i2cTestSlaveAddr[ I2C_TEST_SET ] = { 0xD4 };
const uint8_t i2cTestDeviceRegister[ I2C_TEST_SET ] = { 0x73 };
const uint8_t i2cTestWriteVal[ I2C_TEST_SET ] = { 0b01101010 };
const uint8_t i2cTestInstanceIdx[ I2C_TEST_SET ] = { 0 };
const uint8_t i2cTestInstanceNum[ I2C_TEST_SET ] = { 1 };

/* Not used by tests in this code base. */
IotI2CHandle_t gIotI2cHandle[ 4 ] = { NULL, NULL, NULL, NULL };

void SET_TEST_IOT_I2C_CONFIG( int testSet )
{
    uctestIotI2CSlaveAddr = i2cTestSlaveAddr[ testSet ];
    uctestIotI2CDeviceRegister = i2cTestDeviceRegister[ testSet ];
    uctestIotI2CWriteVal = i2cTestWriteVal[ testSet ];
    uctestIotI2CInstanceIdx = i2cTestInstanceIdx[ testSet ];
    uctestIotI2CInstanceNum = i2cTestInstanceNum[ testSet ];
}

/* SPI */

const uint8_t spiTestPort[ SPI_TEST_SET ] = { 1 };
const uint32_t spiIotMode[ SPI_TEST_SET ] = { eSPIMode0 };
const uint32_t spiIotSpitBitOrder[ SPI_TEST_SET ] = { eSPIMSBFirst };
const uint32_t spiIotFrequency[ SPI_TEST_SET ] = { 500000U };
const uint32_t spiIotDummyValue[ SPI_TEST_SET ] = { 0 };

void SET_TEST_IOT_SPI_CONFIG(int testSet)
{
    ultestIotSpiInstance = spiTestPort[ testSet ] ;
    xtestIotSPIDefaultConfigMode = spiIotMode[ testSet ];
    xtestIotSPIDefaultconfigBitOrder = spiIotSpitBitOrder[ testSet ];
    ultestIotSPIFrequency = spiIotFrequency[ testSet ];
    ultestIotSPIDummyValue = spiIotDummyValue[ testSet ];
}
