#include "bitfield.h"

Bitfield *bitfield_create(size_t size)
{
    Bitfield *bf = (Bitfield *)malloc(sizeof(Bitfield));
    bf->size = size;
    bf->occm = (size % 8) ? size / 8 + 1 : size / 8;
    bf->arr = (uint8_t *)calloc(0, bf->occm);
    return bf;
}

void bitfield_set(size_t index, _Bool value, Bitfield *bf)
{
    if (value)
    {
        bf->arr[index / 8] |= (1 << 7 - index % 8);
    }
    else
    {
        bf->arr[index / 8] &= ~(1 << 7 - index % 8);
    }
}

void bitfield_clear(Bitfield *bf)
{
    memset(bf->arr, 0, bf->occm);
}

uint8_t bitfield_get(size_t index, Bitfield *bf)
{
    return bf->arr[index / 8] >> (7 - index % 8) & 1;
}