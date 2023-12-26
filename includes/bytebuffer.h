#ifndef _BYTEBUFFER_H_
    #define _BYTEBUFFER_H_

    #include<stdlib.h>
    #include<stdint.h>

    typedef struct _ByteBuffer
    {
        uint8_t* buff;
        int ptr;
        int size;

    } ByteBuffer_t;

    ByteBuffer_t* byteBuffer_create(int size);
    void byteBuffer_write8(ByteBuffer_t* bb, uint8_t data);
    void byteBuffer_write16(ByteBuffer_t* bb, uint16_t data);
    void byteBuffer_write32(ByteBuffer_t* bb, uint32_t data);
    void byteBuffer_destroy(ByteBuffer_t* bb);


#endif
