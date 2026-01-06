/*
 * Data Slot stubs for Analogue Pocket
 *
 * With auto-loading, data is loaded by APF before firmware runs.
 * These stub functions exist for compatibility with file.c/memtest.c
 * but return errors since manual loading is not supported.
 */

#include "dataslot.h"
#include <stdint.h>
#include <stddef.h>

int dataslot_wait_ready(void) {
    /* With auto-loading, data is already loaded when firmware starts */
    return 0;
}

int dataslot_get_size(uint16_t slot_id, uint32_t *size) {
    (void)slot_id;
    if (size) *size = 0;
    return -1;  /* Not implemented with auto-loading */
}

int dataslot_read(uint16_t slot_id, uint32_t offset, void *buffer, uint32_t length) {
    (void)slot_id;
    (void)offset;
    (void)buffer;
    (void)length;
    return -1;  /* Not implemented with auto-loading */
}

int32_t dataslot_load(uint16_t slot_id, void *dest) {
    (void)slot_id;
    (void)dest;
    return -1;  /* Not implemented with auto-loading */
}

int32_t dataslot_load_to_addr(uint16_t slot_id, uint32_t sdram_addr) {
    (void)slot_id;
    (void)sdram_addr;
    return -1;  /* Not implemented with auto-loading */
}
