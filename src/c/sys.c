#include <types.h>
#include <sys/sys.h>
#include <io.h>
#include <string.h>

#define __BCTL(x) (*(long*)&x)
#define __BCTUI(x) (*(unsigned int *)&x)

inline void sys_exit(int code) {
    sys_syscall1(SYS_SCALL_EXIT, (long) code);
}

inline int sys_open(const char *const filename, const int flags, const mode_t mode) {
    long res = sys_syscall3(2, __BCTL(filename), __BCTL(flags), __BCTL(mode));
    int fd = *(int*)&res;
    return fd;
}

inline int sys_close(const int fd) {
    return (int) sys_syscall1(SYS_SCALL_CLOSE, __BCTL(fd));
}

inline unsigned int sys_write(unsigned int fd, const char *buf, size_t count) {
    long res = sys_syscall3(SYS_SCALL_WRITE, __BCTL(fd), __BCTL(buf), __BCTL(count));
    return __BCTUI(res);
}
