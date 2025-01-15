#include <sys.h>

long __asm_syscall1(long n, long a1);

long __syscall1(long n, long a1) {
    return __asm_syscall1(n, a1);
}
