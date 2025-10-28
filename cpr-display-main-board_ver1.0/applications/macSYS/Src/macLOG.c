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
/* 真正干活的函数：前面加颜色，尾部加复位码 */
void STM32_LOG_COLOR(stm32_log_level_t level,
                     const char *tag,
                     const char *format, ...)
{
    char log_buf[256];
    va_list args;

    va_start(args, format);
    rt_vsnprintf(log_buf, sizeof(log_buf), format, args);
    va_end(args);

    switch (level)
    {
        case STM32_LOG_ERROR:
            rt_kprintf(COL_RED "E/%s: %s" COL_RST "\n", tag, log_buf);
            break;
        case STM32_LOG_WARN:
            rt_kprintf(COL_YEL "W/%s: %s" COL_RST "\n", tag, log_buf);
            break;
        case STM32_LOG_INFO:
            rt_kprintf(COL_GRN "I/%s: %s" COL_RST "\n", tag, log_buf);
            break;
        case STM32_LOG_DEBUG:
            rt_kprintf(COL_BLU "D/%s: %s" COL_RST "\n", tag, log_buf);
            break;
        case STM32_LOG_VERBOSE:
            rt_kprintf(COL_WHT "V/%s: %s" COL_RST "\n", tag, log_buf);
            break;
        default:
            rt_kprintf("U/%s: %s\n", tag, log_buf);
            break;
    }
}
#endif













