format ELF64

section '.text'

extrn main
extrn sys_syscall1
public _start
_start:
    call main

    mov rdi, 60 
    mov rsi, 0
    call sys_syscall1
