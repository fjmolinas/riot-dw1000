/**
 * Copyright 2017 Decawave Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @defgroup    boards_nrf52840_dw1000 Nordic NRF52840
 *              and Decawave DW1000 board
 * @ingroup     boards
 * @brief       Support for the Nordic NRF52840 and Decawave DW1000
 *              board
 * @{
 *
 * @file
 * @brief       Board specific definitions for the Nordic NRF52840
 *              board and Decawave DW1000 board
 *
 * @author      shreeharsha.i <shreeharsha.i@pathpartnertech.com>
 */

#ifndef DW1000_BOARD_H
#define DW1000_BOARD_H

#include <periph/spi.h>
#include <periph/rtt.h>
#include "dw1000_port.h"

#ifdef RIOT_MULTI_THREADED_APP
#include <semaphore.h>
#endif

#ifdef __cplusplus
extern "c" {
#endif

/**
 * @brief DW1000 SPI Instance Configuration
 */
#define DW1000_SPI_CFG_INSTANCE         (0U)

/**
 * @brief DW1000 Reset Configuration
 */
#define DW1000_RSTn                     GPIO_PIN(0, 21)

/**
 * @brief DW1000 Interrupt Configuration
 */
#define DECAIRQ                         (19U)

/**
 * @brief SPI Configuration for Mode, Clock, Chip Select and SPI Instance
 * @{
 */
#define DW1000_SPI_MODE                 SPI_MODE_0
#define DW1000_SPI_HIGH                 SPI_CLK_5MHZ
#define DW1000_SPI_LOW                  SPI_CLK_1MHZ
#define DW1000_SPI_CS                   (17U)
#define DW1000_SPI_DEV                  DW1000_SPI_CFG_INSTANCE
/** @} */

/**
 * @brief Configures RTT tick value for 1msec on NRF52840 Board
 */
#define RTT_TICKS_TO_WAIT               (50U)

/**
 * @brief Configures RTT Initial Counter Value
 */
#define RTT_INIT_COUNTER_VAL            (0x0U)

/**
 * @brief Configures External irq on NRF52840 Board
 */
#define EXT_IRQ                         GPIOTE_IRQn

#ifdef RIOT_MULTI_THREADED_APP
/**
 * @brief Configures Timer tick value for 1msec on NRF52840 Board
 */
#define TIMER_TICKS_TO_WAIT              (16000U)

/**
 * @brief Configures TIMER Frequency as 16MHz
 */
#define TIMER_FREQ                       (16000000U)

/**
 * @brief TIMER Channel Configuration
 */
#define TIMER_CFG_CHANNEL               (0U)

/**
 * @brief TIMER Instance Configuration
 */
#define TIMER_CFG_INSTANCE              (2U)

/**
 * Semaphore variable to notify the timer thread
 *
 * @note
 * This is valid only for dw1000_multithreaded_app
 */
extern sem_t sem;

/**
 * @brief  Timer ISR function
 *
 * @param  arg   Pointer to the arg variable
 * @param  ch    Channel number
 *
 * @return void
 *
 * @note
 * This is valid only for dw1000_multithreaded_app
 */
void dw1000_timer_isr(void *arg, int ch);
#endif

/**
 * @brief  DW1000 Interrupt handler
 *
 * @param  No arguments
 *
 * @return void
 */
void process_deca_irq(void);

/**
 * @brief  This function handles RTT Handler
 *
 * @param  arg Pointer to the arg variable
 *
 * @return void
 */
void dw1000_cb(void *arg);

/**
 * @brief  Initialize decawave DW1000 board specific hardware for the
 *         peripherals GPIO, SPI and External Interrupt configuration
 *
 * @param  No arguments
 *
 * @return void
 */
void dw1000_board_init(void);

/**
 * @brief  Initializes and Enables a GPIO pin for External Interrupt usage
 *
 * @param  No arguments
 *
 * @return Void
 */
void dw1000_interrupt_init(void);

/**
 * @brief  This function does basic SPI initialization and configures pin
 *         configuration for MISO, MOSI, and CLK pins
 *
 * @param  No arguments
 *
 * @return void
 */
void dw1000_spi_init(void);

/**
 * @brief  Initializes and configures GPIO's for decawave DW1000 Board
 *
 * @param  No arguments
 *
 * @return void
 */
void dw1000_gpio_init(void);

/**
 * @brief  Intialize RTC as counter
 *
 * @param  No arguments
 *
 * @return void
 */
void dw1000_rtt_init(void);


#ifdef RIOT_MULTI_THREADED_APP
/**
 * @brief  Initializes timer for software interrupt
 *
 * @param  No arguments
 *
 * @return void
 *
 * @note
 * This is valid only for dw1000_multithreaded_app
 */
void dw1000_timer_init(void);
#endif

#ifdef __cplusplus
}
#endif

#endif /* DW1000_BOARD_H */
/** @} */
