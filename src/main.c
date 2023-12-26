#include <stdio.h>
#include "../includes/CVM.h"

int main(int argc, char** argv){
    cmv_t *vm = initVm();
    ByteBuffer_t *bb = byteBuffer_create(0); //
    loadProgram(vm, bb);
    destroyVm(vm);
}