format ELF64

section '.text'

public sys_syscall0
public sys_syscall1
public sys_syscall2
public sys_syscall3
public sys_syscall4
public sys_syscall5
sys_syscall0:
sys_syscall1:
sys_syscall2:
sys_syscall3:
sys_syscall4:
sys_syscall5:
    mov rax, rdi
    mov rdi, rsi
    mov rsi, rdx
    mov rdx, rcx
    mov r10, r8
    mov r8, r9
    syscall
    ret

