#ifndef IO_H
#define IO_H

#include <types.h>
#include <sys.h>

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

// TODO: Lock std streams with mutexes

void io_print(const char *const s);
void io_println(const char *const s);
void io_eprint(const char *const s);
void io_eprintln(const char *const s);

#endif
