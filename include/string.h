#ifndef STRING_H
#define STRING_H

#include <types.h>

size_t string_length(const char *const s);
void string_reverse(char *const s, const size_t length);
void string_from_int(char *const buffer, const size_t buffer_len, const long int n);

#endif
