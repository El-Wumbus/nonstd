#include <types.h>
#include <sys.h>

#define __BCTL(x) (*(long*)&x)
#define __BCTUI(x) (*(unsigned int *)&x)

long __asm_syscall1(long n, long a1);
long __asm_syscall3(long n, long a1, long a2, long a3);

#define sys_syscall1 __asm_syscall1
#define sys_syscall3 __asm_syscall3

inline void sys_exit(int code) {
    sys_syscall1(SYS_SYSCALL_EXIT, (long) code);
}

inline unsigned int sys_write(unsigned int fd, const char *buf, size_t count) {
    long res = sys_syscall3(SYS_SYSCALL_WRITE, (long) fd, __BCTL(buf), __BCTL(count));
    return __BCTUI(res);
}
