#include <nonstd.h>


void main(void) {
    char hello[] = "Hello, World!";
    char buf[16] = {0};
    io_println(hello);
    string_reverse(hello, string_length(hello));
    io_println(hello);

    string_from_int(buf, 16, 420);
    io_println(buf);
    
    string_from_int(buf, 16, -69);
    io_println(buf);
    sys_exit(0);
}
