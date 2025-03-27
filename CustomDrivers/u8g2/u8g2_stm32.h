/*
 * u8g2_stm32.h
 *
 *  Created on: Mar 21, 2025
 *      Author: lex
 */

#ifndef U8G2_U8G2_STM32_H_
#define U8G2_U8G2_STM32_H_

#include "stm32f4xx_hal.h"
#include "u8g2.h"

#ifdef __cplusplus
extern "C" {
#endif

uint8_t u8x8_byte_i2c_dma(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

uint8_t u8x8_byte_hw_spi(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

uint8_t u8x8_gpio_and_delay_stm32(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);

#ifdef __cplusplus
}
#endif

#endif /* U8G2_U8G2_STM32_H_ */
