/*
 * Data Slot definitions for Analogue Pocket
 *
 * APF automatically loads data slots to SDRAM based on addresses in data.json.
 * The CPU just needs to wait for SYS_STATUS bit 1 (DATASLOT_COMPLETE).
 *
 * Memory layout (from data.json):
 *   Bridge 0x00000000 -> CPU 0x10000000 (Model - slot 0)
 *   Bridge 0x02000000 -> CPU 0x12000000 (Tokenizer - slot 1)
 */

#ifndef DATASLOT_H
#define DATASLOT_H

#include <stdint.h>
#include <stddef.h>

/* Data slot IDs (for reference) */
#define SLOT_MODEL      0
#define SLOT_TOKENIZER  1

/* Stub functions for compatibility with file.c/memtest.c */
int dataslot_wait_ready(void);
int dataslot_get_size(uint16_t slot_id, uint32_t *size);
int dataslot_read(uint16_t slot_id, uint32_t offset, void *buffer, uint32_t length);
int32_t dataslot_load(uint16_t slot_id, void *dest);
int32_t dataslot_load_to_addr(uint16_t slot_id, uint32_t sdram_addr);

#endif /* DATASLOT_H */
