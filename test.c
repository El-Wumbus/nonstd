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
    
    int fd = sys_open("oop.testfile", O_CREAT | O_TRUNC, 0644);
    string_from_int(buf, 16, fd);
    io_print("Got an FD and didn't crash (!!!!): ");
    io_println(buf);
    if (fd < 0) {
        io_println("Our fd was invalid :(");
        sys_exit(1);
    }

    sys_write(fd, hello, string_length(hello));
    
    sys_exit(0);
}
