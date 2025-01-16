#include <string.h>

size_t string_length(const char *const s) {
    const char* s2 = s;
    for (char ch = *s2; ch != '\0'; ch = *++s2);
    return s2-s;
}

void string_reverse(char *const s, const size_t length) {
    size_t j = length - 1;
    char c;
    for (size_t i = 0; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void string_from_int(char *const buf, const size_t buf_length, const long int n) {
    size_t i = 0;
    int sign;
    unsigned int n2;

    if ((sign = n) < 0) {
        n2 = -n;
    }
    else {
        n2 = n;
    }

    do {
        buf[i++] = (n2 % 10) + '0';
    }
    while ((n2 /= 10) > 0 && i < buf_length);
    if (sign < 0 &&  i < buf_length) {
        buf[i++] = '-';
    }
    buf[i] = '\0';
    
    string_reverse(buf, string_length(buf));
}
