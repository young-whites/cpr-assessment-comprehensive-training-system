/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-24     Administrator       the first version
 */

#include <23lc1024_sram_tlsf.h>


/*! 定义 SRAM 地址空间和缓存 */
#define SRAM_HEAP_SIZE (128u * 1024u)  // 128KB
#define SRAM_HEAP_START 0x00000u       // 23LC1024 堆栈起始地址

/*! 定义伪地址类型 */
typedef uint32_t sram_ptr_t;

static tlsf_t sram_tlsf = NULL;

/*! 控制结构体放在内部 RAM(TLSF 本身很小) */
static uint8_t sram_tlsf_control[1024] __attribute__((aligned(4)));



/* ----------------------------------------------------------
 * SPI 模拟内存访问：读写 SRAM 的指定偏移
 * ----------------------------------------------------------*/
static void spi_memcpy_to_sram(uint32_t offset, const void *src, size_t len)
{
    sram_write_sequence(SRAM_HEAP_START + offset, (const uint8_t *)src, len);
}

static void spi_memcpy_from_sram(void *dst, uint32_t offset, size_t len)
{
    sram_read_sequence(SRAM_HEAP_START + offset, (uint8_t *)dst, len);
}


/* ----------------------------------------------------------
 * TLSF 需要的“虚拟内存”接口
 * ----------------------------------------------------------*/
static void *sram_tlsf_block_ptr(uint32_t offset)
{
    /* 将 offset 伪装成指针返回 */
    return (void *)(uintptr_t)(offset + 1); /* +1 避免 NULL */
}

static uint32_t sram_tlsf_block_offset(const void *ptr)
{
    return (uint32_t)(uintptr_t)ptr - 1;
}


/* ----------------------------------------------------------
 * 初始化
 * ----------------------------------------------------------*/
void sram_tlsf_init(void)
{
    /* 1. 创建 TLSF 控制结构 */
    sram_tlsf = tlsf_create_with_pool(sram_tlsf_control, sizeof(sram_tlsf_control));
    if (!sram_tlsf) {
        /* 错误处理：可在这里加打印 */
        return;
    }

    /* 2. 添加“虚拟”内存池：地址范围是 SRAM 偏移 */
    tlsf_add_pool(sram_tlsf, (void *)SRAM_HEAP_START, SRAM_HEAP_SIZE);
}



/* ----------------------------------------------------------
 * 内存分配 / 释放
 * ----------------------------------------------------------*/
void *sram_malloc(size_t size)
{
    if (!sram_tlsf) return NULL;
    uint32_t offset = (uint32_t)(uintptr_t)tlsf_malloc(sram_tlsf, size);
    return offset ? sram_tlsf_block_ptr(offset) : NULL;
}

void sram_free(void *ptr)
{
    if (!ptr || !sram_tlsf) return;
    tlsf_free(sram_tlsf, (void *)sram_tlsf_block_offset(ptr));
}

void *sram_realloc(void *ptr, size_t new_size)
{
    if (!sram_tlsf) return NULL;
    uint32_t old_offset = ptr ? sram_tlsf_block_offset(ptr) : 0;
    uint32_t new_offset = (uint32_t)(uintptr_t)
        tlsf_realloc(sram_tlsf, (void *)old_offset, new_size);
    return new_offset ? sram_tlsf_block_ptr(new_offset) : NULL;
}

/* ----------------------------------------------------------
 * 调试：打印堆信息
 * ----------------------------------------------------------*/
static void sram_tlsf_walk(void *ptr, size_t size, int used, void *user)
{
    (void)user;
    rt_kprintf("[0x%05X] %s %5u bytes\n",
               (unsigned)(uintptr_t)ptr - 1,
               used ? "used" : "free",
               (unsigned)size);
}

void sram_tlsf_dump(void)
{
    if (!sram_tlsf) return;
    pool_t pool = tlsf_get_pool(sram_tlsf);
    rt_kprintf("--- SRAM TLSF Dump ---\n");
    tlsf_walk_pool(pool, sram_tlsf_walk, NULL);
}




