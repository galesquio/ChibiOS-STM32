/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,
                 2011 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _BOARD_H_
#define _BOARD_H_

/*
 * Setup for STMicroelectronics STM3220G-EVAL board.
 */

/*
 * Board identifier.
 */
#define BOARD_ST_STM3220G_EVAL
#define BOARD_NAME              "ST STM3220G-EVAL"

/*
 * Board frequencies.
 * NOTE: The HSE crystal is not fitted by default on the board.
 */
#define STM32_LSECLK            32768
#define STM32_HSECLK            25000000

/*
 * MCU type as defined in the ST header file stm32f2xx.h.
 */
#define STM32F2XX

/*
 * IO pins assignments.
 */

#define GPIOA_WAKEUP_BUTTON     0

#define GPIOB_ETHER_INT         14
#define GPIOB_NAND_INT          15

#define GPIOC_TAMPER_BUTTON     0
#define GPIOC_LED4              7

#define GPIOF_POT               9

#define GPIOG_LED1              6
#define GPIOG_LED2              8
#define GPIOG_USER_BUTTON       15

#define GPIOH_EXPANDER_INT      12
#define GPIOH_SD_DETECT         13

#define GPIOI_LED3              9

/*
 * I/O ports initial setup, this configuration is established soon after reset
 * in the initialization code.
 * Please refer to the STM32 Reference Manual for details.
 */
#define PIN_MODE_INPUT(n)           (0 << ((n) * 2))
#define PIN_MODE_OUTPUT(n)          (1 << ((n) * 2))
#define PIN_MODE_ALTERNATE(n)       (2 << ((n) * 2))
#define PIN_MODE_ANALOG(n)          (3 << ((n) * 2))
#define PIN_OTYPE_PUSHPULL(n)       (0 << (n))
#define PIN_OTYPE_OPENDRAIN(n)      (1 << (n))
#define PIN_OSPEED_2M(n)            (0 << ((n) * 2))
#define PIN_OSPEED_25M(n)           (1 << ((n) * 2))
#define PIN_OSPEED_50M(n)           (2 << ((n) * 2))
#define PIN_OSPEED_100M(n)          (3 << ((n) * 2))
#define PIN_PUDR_FLOATING(n)        (0 << ((n) * 2))
#define PIN_PUDR_PULLUP(n)          (1 << ((n) * 2))
#define PIN_PUDR_PULLDOWN(n)        (2 << ((n) * 2))
#define PIN_AFIO_AF0(n)             (0 << ((n % 8) * 4))
#define PIN_AFIO_AF1(n)             (1 << ((n % 8) * 4))
#define PIN_AFIO_AF2(n)             (2 << ((n % 8) * 4))
#define PIN_AFIO_AF3(n)             (3 << ((n % 8) * 4))
#define PIN_AFIO_AF4(n)             (4 << ((n % 8) * 4))
#define PIN_AFIO_AF5(n)             (5 << ((n % 8) * 4))
#define PIN_AFIO_AF6(n)             (6 << ((n % 8) * 4))
#define PIN_AFIO_AF7(n)             (7 << ((n % 8) * 4))
#define PIN_AFIO_AF8(n)             (8 << ((n % 8) * 4))
#define PIN_AFIO_AF9(n)             (9 << ((n % 8) * 4))
#define PIN_AFIO_AF10(n)            (10 << ((n % 8) * 4))
#define PIN_AFIO_AF11(n)            (11 << ((n % 8) * 4))
#define PIN_AFIO_AF12(n)            (12 << ((n % 8) * 4))
#define PIN_AFIO_AF13(n)            (13 << ((n % 8) * 4))
#define PIN_AFIO_AF14(n)            (14 << ((n % 8) * 4))
#define PIN_AFIO_AF15(n)            (15 << ((n % 8) * 4))

/*
 * Port A setup.
 * All input with pull-up except:
 * PA8  - MCO 1         (alternate 0).
 * PA13 - JTMS/SWDAT    (alternate 0).
 * PA14 - JTCK/SWCLK    (alternate 0).
 * PA15 - JTDI          (alternate 0).
 */
#define VAL_GPIOA_MODER             (PIN_MODE_ALTERNATE(8)    | \
                                     PIN_MODE_ALTERNATE(13)   | \
                                     PIN_MODE_ALTERNATE(14)   | \
                                     PIN_MODE_ALTERNATE(15))
#define VAL_GPIOA_OTYPER            0x00000000
#define VAL_GPIOA_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOA_PUPDR             (PIN_PUDR_FLOATING(13)    | \
                                     PIN_PUDR_FLOATING(14)    | \
                                     PIN_PUDR_FLOATING(15))
#define VAL_GPIOA_ODR               0xFFFFFFFF
#define VAL_GPIOA_AFRL				0x00000000
#define VAL_GPIOA_AFRH				0x00000000

/*
 * Port B setup.
 * All input with pull-up except:
 * PB3  - JTDO          (alternate 0).
 * PB4  - JNTRST        (alternate 0).
 */
#define VAL_GPIOB_MODER             (PIN_MODE_ALTERNATE(3)    | \
                                     PIN_MODE_ALTERNATE(4))
#define VAL_GPIOB_OTYPER            0x00000000
#define VAL_GPIOB_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOB_PUPDR             (~(PIN_PUDR_FLOATING(3)   | \
                                       PIN_PUDR_FLOATING(4)))
#define VAL_GPIOB_ODR               0xFFFFFFFF
#define VAL_GPIOB_AFRL				0x00000000
#define VAL_GPIOB_AFRH				0x00000000

/*
 * Port C setup.
 * All input with pull-up except:
 * PC9  - MCO2          (alternate 0).
 * PC10 - USART3_TX     (alternate 7).
 * PC11 - USART3_RX     (alternate 7).
 * PC14 - OSC32_INT     (input floating).
 * PC15 - OSC32_OUT     (input floating).
 */
#define VAL_GPIOC_MODER             (PIN_MODE_ALTERNATE(9)    | \
                                    PIN_MODE_ALTERNATE(10)    | \
                                    PIN_MODE_ALTERNATE(11))
#define VAL_GPIOC_OTYPER            0x00000000
#define VAL_GPIOC_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOC_PUPDR             (~(PIN_PUDR_PULLUP(11)    | \
                                       PIN_PUDR_FLOATING(14)  | \
                                       PIN_PUDR_FLOATING(15)))
#define VAL_GPIOC_ODR               0xFFFFFFFF
#define VAL_GPIOC_AFRL				0x00000000
#define VAL_GPIOC_AFRH				(PIN_AFIO_AF7(10)         | \
                                     PIN_AFIO_AF7(11))

/*
 * Port D setup.
 * All input with pull-up.
 */
#define VAL_GPIOD_MODER             0x00000000
#define VAL_GPIOD_OTYPER            0x00000000
#define VAL_GPIOD_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOD_PUPDR             0xFFFFFFFF
#define VAL_GPIOD_ODR               0xFFFFFFFF
#define VAL_GPIOD_AFRL				0x00000000
#define VAL_GPIOD_AFRH				0x00000000

/*
 * Port E setup.
 * All input with pull-up.
 */
#define VAL_GPIOE_MODER             0x00000000
#define VAL_GPIOE_OTYPER            0x00000000
#define VAL_GPIOE_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOE_PUPDR             0xFFFFFFFF
#define VAL_GPIOE_ODR               0xFFFFFFFF
#define VAL_GPIOE_AFRL				0x00000000
#define VAL_GPIOE_AFRH				0x00000000

/*
 * Port F setup.
 * All input with pull-up.
 */
#define VAL_GPIOF_MODER             0x00000000
#define VAL_GPIOF_OTYPER            0x00000000
#define VAL_GPIOF_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOF_PUPDR             0xFFFFFFFF
#define VAL_GPIOF_ODR               0xFFFFFFFF
#define VAL_GPIOF_AFRL				0x00000000
#define VAL_GPIOF_AFRH				0x00000000

/*
 * Port G setup.
 * All input with pull-up.
 */
#define VAL_GPIOG_MODER             (PIN_MODE_OUTPUT(GPIOG_LED1))
#define VAL_GPIOG_OTYPER            0x00000000
#define VAL_GPIOG_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOG_PUPDR             (~(PIN_PUDR_FLOATING(GPIOG_LED1)))
#define VAL_GPIOG_ODR               0xFFFFFFBF
#define VAL_GPIOG_AFRL				0x00000000
#define VAL_GPIOG_AFRH				0x00000000

/*
 * Port H setup.
 * All input with pull-up.
 */
#define VAL_GPIOH_MODER             0x00000000
#define VAL_GPIOH_OTYPER            0x00000000
#define VAL_GPIOH_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOH_PUPDR             0xFFFFFFFF
#define VAL_GPIOH_ODR               0xFFFFFFFF
#define VAL_GPIOH_AFRL				0x00000000
#define VAL_GPIOH_AFRH				0x00000000

/*
 * Port I setup.
 * All input with pull-up.
 */
#define VAL_GPIOI_MODER             0x00000000
#define VAL_GPIOI_OTYPER            0x00000000
#define VAL_GPIOI_OSPEEDR           0xFFFFFFFF
#define VAL_GPIOI_PUPDR             0xFFFFFFFF
#define VAL_GPIOI_ODR               0xFFFFFFFF
#define VAL_GPIOI_AFRL				0x00000000
#define VAL_GPIOI_AFRH				0x00000000

#if !defined(_FROM_ASM_)
#ifdef __cplusplus
extern "C" {
#endif
  void boardInit(void);
#ifdef __cplusplus
}
#endif
#endif /* _FROM_ASM_ */

#endif /* _BOARD_H_ */
