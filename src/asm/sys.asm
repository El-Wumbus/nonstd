format ELF64

section '.text'

public __asm_syscall1
__asm_syscall1:
    mov rax, rdi ; call: rdi => rax
    mov rdi, rsi ; arg0: rsi => rdi
    syscall
    
    ret

public __asm_syscall3
__asm_syscall3:
    mov rax, rdi ; call: rdi => rax
    mov rdi, rsi ; arg0: rsi => rdi 
    mov rsi, rdx ; arg1: rdx => rsi
    mov rdx, rcx ; arg2: rcx => rdx
    syscall

    ret
