format ELF64

section '.text'

extrn main
extrn __asm_syscall1
public _start
_start:
    call main

    mov rdi, 60 
    mov rsi, 0
    call __asm_syscall1
