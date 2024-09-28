BITS 32

section .text
    ALIGN 4
    DD 0x1BADB002
    DD 0x00000000
    DD -(0x1BADB002 + 0x00000000)

global _start
extern kernel_main

_start:
    CLI
    MOV esp, stack_space
    CALL kernel_main
    CLI
    HLT
    JMP HaltKernel

HaltKernel:
    CLI
    HLT
    JMP HaltKernel

section .bss
RESB 8192
stack_space: