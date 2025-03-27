/*
 * u8g2_stm32.c
 *
 *  Created on: Mar 21, 2025
 *      Author: lex
 */


#include "u8g2_stm32.h"
#include <string.h>

#define kI2cBufferSize 25
#define kI2cBuffersCount 50

extern I2C_HandleTypeDef hi2c3;

typedef struct {
	uint8_t buffer[kI2cBufferSize];
	uint8_t bufferCounter;
} I2cBuffer;

static I2cBuffer i2cBuffers[kI2cBuffersCount];
static uint8_t i2cBuffersProducerPtr = 0;
static uint8_t i2cBuffersConsumerPtr = 0;

uint8_t sendI2cBuffer() {
	if (i2cBuffersConsumerPtr != i2cBuffersProducerPtr) {
		return HAL_OK == HAL_I2C_Master_Transmit_DMA(&hi2c3, (0x3C << 1), (uint8_t*)i2cBuffers[i2cBuffersConsumerPtr].buffer, i2cBuffers[i2cBuffersConsumerPtr].bufferCounter);
	}

	return 0;
}

uint8_t u8x8_byte_i2c_dma(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
    switch (msg) {
        case U8X8_MSG_BYTE_INIT:
            break;
        case U8X8_MSG_BYTE_SEND:

        	memcpy(i2cBuffers[i2cBuffersProducerPtr].buffer + i2cBuffers[i2cBuffersProducerPtr].bufferCounter, arg_ptr, arg_int);
        	i2cBuffers[i2cBuffersProducerPtr].bufferCounter += arg_int;
        	break;
        case U8X8_MSG_BYTE_SET_DC:

        	break;
        case U8X8_MSG_BYTE_START_TRANSFER:
        	++i2cBuffersProducerPtr;
        	if (kI2cBuffersCount <= i2cBuffersProducerPtr) {
        		i2cBuffersProducerPtr = 0;
        	}

        	if (i2cBuffersProducerPtr == i2cBuffersConsumerPtr) {
        		return 0;
        	}

        	i2cBuffers[i2cBuffersProducerPtr].bufferCounter = 0;
        	break;
        case U8X8_MSG_BYTE_END_TRANSFER:
        	return sendI2cBuffer();
 //       	while (HAL_I2C_GetState(&hi2c3) != HAL_I2C_STATE_READY);
        	break;
        default:
        	return 0;
    }

    return 1;
}

uint8_t u8x8_byte_hw_spi(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
    switch (msg) {
        case U8X8_MSG_BYTE_SEND:
//            HAL_SPI_Transmit(&hspi1, (uint8_t*)arg_ptr, arg_int, HAL_MAX_DELAY);
        	break;
    }

    return 1;
}

uint8_t u8x8_gpio_and_delay_stm32(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
    switch (msg) {
    	case U8X8_MSG_GPIO_AND_DELAY_INIT:
    		break;
        case U8X8_MSG_DELAY_MILLI:
            HAL_Delay(arg_int);
            break;
        case U8X8_MSG_DELAY_NANO:
        case U8X8_MSG_DELAY_100NANO:
            __NOP();
            break;
    }

    return 1;
}

void HAL_I2C_MasterTxCpltCallback(I2C_HandleTypeDef *hi2c) {
    if (hi2c->Instance == I2C3) {
    	++i2cBuffersConsumerPtr;
    	if (kI2cBuffersCount <= i2cBuffersConsumerPtr) {
    		i2cBuffersConsumerPtr = 0;
    	}

    	sendI2cBuffer();
    }
}

void HAL_I2C_ErrorCallback(I2C_HandleTypeDef *hi2c) {
    if (hi2c->ErrorCode != HAL_I2C_ERROR_NONE) {
        //
    }
}

