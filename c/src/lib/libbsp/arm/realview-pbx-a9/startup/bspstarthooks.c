/*
 * Copyright (c) 2013 embedded brains GmbH.  All rights reserved.
 *
 *  embedded brains GmbH
 *  Dornierstr. 4
 *  82178 Puchheim
 *  Germany
 *  <info@embedded-brains.de>
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rtems.com/license/LICENSE.
 */

#include <bsp.h>
#include <bsp/start.h>
#include <bsp/arm-cp15-start.h>
#include <bsp/linker-symbols.h>

BSP_START_TEXT_SECTION void bsp_start_hook_0(void)
{
  /* Do nothing */
}

BSP_START_DATA_SECTION static const arm_cp15_start_section_config
rvpbxa9_mmu_config_table[] = {
  {
    .begin = (uint32_t) bsp_section_fast_text_begin,
    .end = (uint32_t) bsp_section_fast_text_end,
    .flags = BSP_ARM_MMU_CODE
  }, {
    .begin = (uint32_t) bsp_section_fast_data_begin,
    .end = (uint32_t) bsp_section_fast_data_end,
    .flags = BSP_ARM_MMU_READ_WRITE_DATA
  }, {
    .begin = (uint32_t) bsp_section_start_begin,
    .end = (uint32_t) bsp_section_start_end,
    .flags = BSP_ARM_MMU_CODE
  }, {
    .begin = (uint32_t) bsp_section_vector_begin,
    .end = (uint32_t) bsp_section_vector_end,
    .flags = BSP_ARM_MMU_READ_WRITE_CACHED
  }, {
    .begin = (uint32_t) bsp_section_text_begin,
    .end = (uint32_t) bsp_section_text_end,
    .flags = BSP_ARM_MMU_CODE
  }, {
    .begin = (uint32_t) bsp_section_rodata_begin,
    .end = (uint32_t) bsp_section_rodata_end,
    .flags = BSP_ARM_MMU_READ_ONLY_DATA
  }, {
    .begin = (uint32_t) bsp_section_data_begin,
    .end = (uint32_t) bsp_section_data_end,
    .flags = BSP_ARM_MMU_READ_WRITE_DATA
  }, {
    .begin = (uint32_t) bsp_section_bss_begin,
    .end = (uint32_t) bsp_section_bss_end,
    .flags = BSP_ARM_MMU_READ_WRITE_DATA
  }, {
    .begin = (uint32_t) bsp_section_work_begin,
    .end = (uint32_t) bsp_section_work_end,
    .flags = BSP_ARM_MMU_READ_WRITE_DATA
  }, {
    .begin = (uint32_t) bsp_section_stack_begin,
    .end = (uint32_t) bsp_section_stack_end,
    .flags = BSP_ARM_MMU_READ_WRITE_DATA
  }, {
    .begin = 0x10000000U,
    .end = 0x10020000U,
    .flags = BSP_ARM_MMU_READ_WRITE
  }, {
    .begin = 0x1f000000U,
    .end = 0x20000000U,
    .flags = BSP_ARM_MMU_READ_WRITE
  }
};

BSP_START_TEXT_SECTION static void setup_mmu_and_cache(void)
{
  uint32_t ctrl = arm_cp15_start_setup_mmu_and_cache(
    0,
    ARM_CP15_CTRL_AFE | ARM_CP15_CTRL_Z
  );

  arm_cp15_start_setup_translation_table_and_enable_mmu(
    ctrl,
    (uint32_t *) bsp_translation_table_base,
    BSP_ARM_MMU_CLIENT_DOMAIN,
    &rvpbxa9_mmu_config_table[0],
    RTEMS_ARRAY_SIZE(rvpbxa9_mmu_config_table)
  );
}

BSP_START_TEXT_SECTION void bsp_start_hook_1(void)
{
  bsp_start_copy_sections();
  setup_mmu_and_cache();
  bsp_start_clear_bss();
}
