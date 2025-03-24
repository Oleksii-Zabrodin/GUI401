/*
 * u8g2_stm32.c
 *
 *  Created on: Mar 21, 2025
 *      Author: lex
 */


#include "u8g2_stm32.h"

extern I2C_HandleTypeDef hi2c3;

static uint8_t u8g2Buffer[10] = {0};
static uint8_t u8g2BufferCounter = 0;

uint8_t u8x8_byte_hw_i2c(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr) {
    switch (msg) {
        case U8X8_MSG_BYTE_INIT:
            break;
        case U8X8_MSG_BYTE_SEND:
        	u8g2Buffer[u8g2BufferCounter] = *((uint8_t*)arg_ptr);
        	++u8g2BufferCounter;
//        	HAL_StatusTypeDef result = HAL_I2C_Mem_Write(&hi2c3, (0x3C << 1), 0x00, I2C_MEMADD_SIZE_8BIT, (uint8_t*)arg_ptr, arg_int, HAL_MAX_DELAY);
        	break;
        case U8X8_MSG_BYTE_SET_DC:

        	break;
        case U8X8_MSG_BYTE_START_TRANSFER:
        	u8g2BufferCounter = 0;
        	break;
        case U8X8_MSG_BYTE_END_TRANSFER:
        	HAL_StatusTypeDef result = HAL_I2C_Master_Transmit(&hi2c3, (0x3C << 1), (uint8_t*)u8g2Buffer, u8g2BufferCounter, HAL_MAX_DELAY);
//          	HAL_StatusTypeDef result = HAL_I2C_Mem_Write(&hi2c3, (0x3C << 1), 0x00, I2C_MEMADD_SIZE_8BIT, &(u8g2Buffer[1]), 1, HAL_MAX_DELAY);
//          	if (2 < u8g2BufferCounter) {
//          		result = HAL_I2C_Mem_Write(&hi2c3, (0x3C << 1), 0x40, I2C_MEMADD_SIZE_8BIT, &(u8g2Buffer[2]), 1, HAL_MAX_DELAY);
//          	}

          	return  HAL_OK == result;
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


