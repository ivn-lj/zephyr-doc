/*
 * Copyright (c) 2016 RnDity Sp. z o.o.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _STM32F3X_FLASH_REGISTERS_H_
#define _STM32F3X_FLASH_REGISTERS_H_

#include <stdint.h>

/**
 * @brief
 *
 * Based on reference manual:
 *   STM32F101xx, STM32F102xx, STM32F103xx, STM32F105xx and STM32F107xx
 *   advanced ARM ® -based 32-bit MCUs
 *   &
 *   STM32F334xx advanced ARM ® -based 32-bit MCUs
 *
 * Chapter 3.3.3: Embedded Flash Memory
 */

enum {
	STM32_FLASH_LATENCY_0 = 0x0,
	STM32_FLASH_LATENCY_1 = 0x1,
	STM32_FLASH_LATENCY_2 = 0x2,
};

/* 3.3.3 FLASH_ACR */
union ef_acr {
	uint32_t val;
	struct {
		uint32_t latency :3 __packed;
		uint32_t hlfcya :1 __packed;
		uint32_t prftbe :1 __packed;
		uint32_t prftbs :1 __packed;
		uint32_t rsvd__6_31 :26 __packed;
	} bit;
};

/* 3.3.3 Embedded flash registers */
struct stm32_flash {
	union ef_acr acr;
	uint32_t keyr;
	uint32_t optkeyr;
	uint32_t sr;
	uint32_t cr;
	uint32_t ar;
	uint32_t rsvd;
	uint32_t obr;
	uint32_t wrpr;
};

/* list of device commands */
enum stm32_embedded_flash_cmd {
	STM32_FLASH_CMD_LATENCY_FOR_CLOCK_SET,
};

#endif /* _STM32F3X_FLASH_REGISTERS_H_ */
