#ifndef _CVM_H_
    #define _CVM_H_

    #include <stdint.h>
    #include <stdio.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <inttypes.h>
    #include <string.h>
    #include "../includes/bytebuffer.h"

    /**
     * @brief Size(in bytes) of a single vm memory page
    */
    #define _PAGE_SIZE_ 4096
    /**
     * @brief Amount of registers in the Cpu, set as a macro so it's scalable
    */
    #define _REG_COUNT_ 8 
    /**
     * @brief used for scaling if needed further
    */
    #define _VM_BIT_COUNT_ 32

    enum registers_enum {
        r0,
        r1,
        r2,
        r3,
        r4,
        r5,
        sp,
        bp,
    };

    enum Opcodes {
        Noop = 0,
        Mov,
        Push,
        Pop,
        Add,
        Sub,
        Mul,
        Inc,
        Dec,
        And,
        Or,
        Xor,
        Not, 
        Rsh,
        Lsh,
        Cmp,
        Jmp,
        Jnz,
        Jz,
        Jmsb,
        Jc,
        Jof,
        Jlsb,
        Call,
        Ret,
        Syscall,
        Hlt = 0x1F, 
    };

    /**
     * @brief post-decode Instruction structure
     */
    typedef struct _Instruction
    {   
        uint8_t opcode; 
        uint8_t dstReg;
        uint8_t srcReg;
        uint8_t srcType; // 1(immediate) or 0(reg)
        uint8_t isDstMem; // 1(True) or 0(false), tell the cpu vm where to read data from
        uint8_t isSrcMem; // 1(True) or 0(false), kinda wish I was using c++ for those tasty booleans
        uint8_t srcSize; // 0b00(source bits not used), 0b01(byte), 0b10(word), 0b11(dword), controls the immediate size that is read
        uint32_t imm;
        size_t InsSize;

    } Instruction_t;

    /**
     * @brief Vm's core structure, contains registers and necessary memory information
     */
    typedef struct _Cvm
    {
        uint32_t registers[_REG_COUNT_];
        uint32_t IP;
        uint32_t flags;
        uint8_t* codeBase;
        uint8_t* stackBase;
        size_t codeSize;
        size_t stackSize;
        size_t bytecodeSize;
        Instruction_t currIns;
    } cmv_t;

    /**
     * @brief vm initialization function, zeros out registers and allocates the CPU on the heap
     * @return initialized virtual machine
     */
    cmv_t* initVm();
    /**
    *   @brief loads program from ByteBuffer, allocates memory pages accordingly, and writes
    *   the program contained in the ByteBuffer into the code pages
    *   Also allocates memory for the stack
    *   @param prog pointer to the ByteBuffer containing the program
    *   @param vm pointer to the virtual machine
    *   @return 
    */
    int loadProgram(cmv_t *vm,ByteBuffer_t* prog);
    /**
    *   @brief Runs the program loaded on the machine
    *   @param prog pointer to the ByteBuffer containing the program
    *   @param vm pointer to the virtual machine
    *   @return exit code 
    */
    int runVm(cmv_t *vm);
    /**
     * @brief vm Deconstructor
     * @param vm pointer to the virtual machine
    
     */
    void destroyVm(cmv_t *vm);

#endif //_CVM_H_