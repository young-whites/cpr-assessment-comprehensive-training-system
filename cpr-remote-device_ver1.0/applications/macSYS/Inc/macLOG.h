/*
 * macLOG.h
 *
 *  Created on: Jun 19, 2025
 *      Author: Administrator
 */

#ifndef MACSYS_INC_MACLOG_H_
#define MACSYS_INC_MACLOG_H_

#include "bsp_sys.h"

#define USE_MY_LOG  0
#if USE_MY_LOG

/**
 * @brief Log level
 *
 */
typedef enum {
    STM32_LOG_NONE,       /*!< No log output */
	STM32_LOG_ERROR,      /*!< Critical errors, software module can not recover on its own */
	STM32_LOG_WARN,       /*!< Error conditions from which recovery measures have been taken */
	STM32_LOG_INFO,       /*!< Information messages which describe normal flow of events */
	STM32_LOG_DEBUG,      /*!< Extra information which is not necessary for normal use (values, pointers, sizes, etc). */
	STM32_LOG_VERBOSE     /*!< Bigger chunks of debugging information, or frequent messages which can potentially flood the output. */
} stm32_log_level_t;


#define STM32_LOGI(tag, format, ...) STM32_LOG(STM32_LOG_INFO, tag, format, ##__VA_ARGS__)
#define STM32_LOGW(tag, format, ...) STM32_LOG(STM32_LOG_WARN, tag, format, ##__VA_ARGS__)
#define STM32_LOGE(tag, format, ...) STM32_LOG(STM32_LOG_ERROR, tag, format, ##__VA_ARGS__)

#endif



#endif /* MACSYS_INC_MACLOG_H_ */
