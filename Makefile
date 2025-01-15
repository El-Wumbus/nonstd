CC := gcc
CFLAGS := -nostdlib -ffreestanding -no-pie -Wall -Wextra -Werror -std=c11 -I./include

test: test.o nonstd.a
	$(CC) $(CFLAGS) -o $@ $^

nonstd.a: src/c/sys.o src/asm/sys.o
	ar -rc $@ $^

src/asm/sys.o: src/asm/sys.asm
	fasm $^ $@

.PHONY: clean

clean:
	rm -f src/asm/*.o src/c/*.o *.o *.a

