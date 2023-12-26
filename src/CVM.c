#include "../includes/CVM.h"

static bool fetch(cmv_t *vm)
{
    return false;
}

cmv_t *initVm()
{  
    printf("sex\n");
    cmv_t *vm = (cmv_t*) malloc(sizeof(cmv_t));
    memset(vm->registers, 0x00, sizeof(vm->registers));
    return vm;
}

int loadProgram(cmv_t *vm,ByteBuffer_t *prog)
{
    vm->codeSize = (_PAGE_SIZE_ * (1 + (prog->size/_PAGE_SIZE_)));
    vm->stackSize = _PAGE_SIZE_;

    vm->codeBase = (uint8_t*)malloc(vm->stackSize + 10 + vm->codeSize);

    for(int i = 0; i < prog->size; i++){
        *(vm->codeBase + i) = prog->buff[i];
    }

    vm->bytecodeSize = prog->size;
    vm->stackBase = vm->codeBase + vm->codeSize;

    memset(vm->stackBase, 0x00, vm->stackSize + 10);
    vm->registers[sp] = vm->codeSize;
    vm->registers[bp] = vm->registers[sp];
    vm->IP = 0;
}
void destroyVm(cmv_t *vm)
{  
    if(vm->codeBase){
        free(vm->codeBase);
    }
    free(vm);;
}
