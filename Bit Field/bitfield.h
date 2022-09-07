#ifndef BITFIELD_H
#define BITFIELD_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR(msg) \
    (fprintf(stderr, msg, __FILE__, __LINE__), exit(-1))

struct bitfield
{
    size_t size;    // Size entered by user
    size_t occm;    // Occupied memory size in bytes
    uint8_t *arr;   // The bitfield itself
}
typedef Bitfield;

Bitfield *bitfield_create(size_t size);
void bitfield_set(size_t index, _Bool value, Bitfield *bf);
void bitfield_clear(Bitfield *bf);
uint8_t bitfield_get(size_t index, Bitfield *bf);

#endif