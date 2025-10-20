/*
 * macLOG.c
 *
 *  Created on: Jun 19, 2025
 *      Author: Administrator
 */

#include "macLOG.h"

#if USE_MY_LOG

/**
 * @brief STM32 log function
 *
 * @param level The log level
 * @param tag The log tag
 * @param format The log format string
 * @param ... The log arguments
 */
void STM32_LOG(stm32_log_level_t level, const char *tag, const char *format, ...)
{
    char log_buffer[256];  // Adjust the buffer size as needed
    va_list args;

    va_start(args, format);
    rt_vsnprintf(log_buffer, sizeof(log_buffer), format, args);
    va_end(args);

    switch (level)
    {
        case STM32_LOG_NONE:
            // No log output
            break;
        case STM32_LOG_ERROR:
            rt_kprintf("E/%s: %s\n", tag, log_buffer);
            break;
        case STM32_LOG_WARN:
            rt_kprintf("W/%s: %s\n", tag, log_buffer);
            break;
        case STM32_LOG_INFO:
            rt_kprintf("I/%s: %s\n", tag, log_buffer);
            break;
        case STM32_LOG_DEBUG:
            rt_kprintf("D/%s: %s\n", tag, log_buffer);
            break;
        case STM32_LOG_VERBOSE:
            rt_kprintf("V/%s: %s\n", tag, log_buffer);
            break;
        default:
            // Unknown log level
            rt_kprintf("U/%s: %s\n", tag, log_buffer);
            break;
    }
}
#endif













