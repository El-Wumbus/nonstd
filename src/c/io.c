#include <io.h>
#include <sys.h>
#include <string.h>

inline void io_print(const char *const s) {
    sys_write(STDOUT_FILENO, s, string_length(s));
}

inline void io_println(const char *const s) {
    io_print(s);
    sys_write(1, "\n", 1);    
}

inline void io_eprint(const char *const s) {
    sys_write(STDERR_FILENO, s, string_length(s));
}

inline void io_eprintln(const char *const s) {
    io_eprint(s);
    sys_write(1, "\n", 1);  
}
