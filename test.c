#include <sys.h>

void _start(void) {
    __syscall1(60, 69);
    while (1) {}
}
