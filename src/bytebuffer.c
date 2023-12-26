#include "../includes/bytebuffer.h"

ByteBuffer_t *byteBuffer_create(int size)
{
    ByteBuffer_t* bb = (ByteBuffer_t*) malloc(sizeof(ByteBuffer_t));
    bb->buff = (uint8_t*) malloc(sizeof(uint8_t) * size);
    bb->ptr = 0;
    bb->size = size;
    return bb;
}

void byteBuffer_write8(ByteBuffer_t *bb, uint8_t data)
{
    if(bb->ptr >= bb->size){
        bb->size++;
        bb->buff = (uint8_t*) realloc(bb->buff, sizeof(uint8_t) * bb->size);
    }

    bb->buff[bb->ptr++] = data;
}

void byteBuffer_write16(ByteBuffer_t *bb, uint16_t data)
{
    byteBuffer_write8(bb, (data & 0xFF00) >> 8);
    byteBuffer_write8(bb, (data & 0x00FF));
}

void byteBuffer_write32(ByteBuffer_t *bb, uint32_t data)
{
    byteBuffer_write16(bb, (data & 0xFFFF0000) >> 16);
    byteBuffer_write16(bb, (data & 0x0000FFFF));
}

void byteBuffer_destroy(ByteBuffer_t *bb)
{
    free(bb->buff);
    free(bb);
}
