#include "../includes/utils.h"

void read_binary_file(const char *path, ByteBuffer_t *bb)
{
    FILE* file = fopen(path, "rb");
    if(!file){
        printf("Could not open file at '%s'\n", path);
        return;
    }
    
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    uint8_t buff[size];
    fread(buff, 1, size, file);
    fclose(file);

    for(int i = 0; i < size; i++){
        byteBuffer_write8(bb, buff[i]);
    }
}