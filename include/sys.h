#ifndef SYS_H
#define SYS_H

#include <types.h>

enum SYS_SYSCALL {
    SYS_SYSCALL_WRITE = 1L,
    SYS_SYSCALL_EXIT = 60L,
};


long sys_syscall1(long n, long a1);
long sys_syscall3(long n, long a1, long a2, long a3);

void sys_exit(int code);
unsigned int sys_write(unsigned int fd, const char *buf, size_t count);

#endif
