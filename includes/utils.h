#ifndef _UTILS_H_
    #define _UTILS_H_

    #include<stdio.h>
    #include<stdlib.h>

    #include "bytebuffer.h"
    //utils file for functions that might feel out of place on other files

    void read_binary_file(const char* path, ByteBuffer_t* bb);


#endif //_UTILS_H_    