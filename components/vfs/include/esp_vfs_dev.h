/*
 * SPDX-FileCopyrightText: 2015-2023 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include "esp_vfs.h"
#include "esp_vfs_common.h"

#ifdef __cplusplus
extern "C" {
#endif

void esp_vfs_dev_uart_register(void) __attribute__((deprecated("Please use uart_vfs_dev_register() instead")));

void esp_vfs_dev_uart_use_nonblocking(int uart_num) __attribute__((deprecated("Please use uart_vfs_dev_use_nonblocking() instead")));

void esp_vfs_dev_uart_use_driver(int uart_num) __attribute__((deprecated("Please use uart_vfs_dev_use_driver() instead")));

int esp_vfs_dev_uart_port_set_rx_line_endings(int uart_num, esp_line_endings_t mode) __attribute__((deprecated("Please use uart_vfs_dev_port_set_rx_line_endings() instead")));

int esp_vfs_dev_uart_port_set_tx_line_endings(int uart_num, esp_line_endings_t mode) __attribute__((deprecated("Please use uart_vfs_dev_port_set_tx_line_endings() instead")));

/**
 * @brief Set the line endings expected to be received on UART
 *
 * This specifies the conversion between line endings received on UART and
 * newlines ('\n', LF) passed into stdin:
 *
 * - ESP_LINE_ENDINGS_CRLF: convert CRLF to LF
 * - ESP_LINE_ENDINGS_CR: convert CR to LF
 * - ESP_LINE_ENDINGS_LF: no modification
 *
 * @note this function is not thread safe w.r.t. reading from UART
 *
 * @param mode line endings expected on UART
 */
void esp_vfs_dev_uart_set_rx_line_endings(esp_line_endings_t mode) __attribute__((deprecated("Please use uart_vfs_dev_port_set_rx_line_endings() instead")));

/**
 * @brief Set the line endings to sent to UART
 *
 * This specifies the conversion between newlines ('\n', LF) on stdout and line
 * endings sent over UART:
 *
 * - ESP_LINE_ENDINGS_CRLF: convert LF to CRLF
 * - ESP_LINE_ENDINGS_CR: convert LF to CR
 * - ESP_LINE_ENDINGS_LF: no modification
 *
 * @note this function is not thread safe w.r.t. writing to UART
 *
 * @param mode line endings to send to UART
 */
void esp_vfs_dev_uart_set_tx_line_endings(esp_line_endings_t mode) __attribute__((deprecated("Please use uart_vfs_dev_port_set_tx_line_endings() instead")));

/**
 * @brief set VFS to use USB-SERIAL-JTAG driver for reading and writing
 * @note application must configure USB-SERIAL-JTAG driver before calling these functions
 * With these functions, read and write are blocking and interrupt-driven.
 */
void esp_vfs_usb_serial_jtag_use_driver(void);

/**
 * @brief set VFS to use simple functions for reading and writing UART
 * Read is non-blocking, write is busy waiting until TX FIFO has enough space.
 * These functions are used by default.
 */
void esp_vfs_usb_serial_jtag_use_nonblocking(void);

#ifdef __cplusplus
}
#endif
