format ELF64

section '.text'

public __asm_syscall1
__asm_syscall1:
    mov rax, rdi
    mov rdi, rsi
    syscall
