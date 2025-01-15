CC := gcc
CFLAGS := -O2 -nostdlib -ffreestanding -no-pie -Wall -Wextra -Werror -std=c11 -I./include

csrc := $(wildcard src/c/*.c)
asmsrc := $(wildcard src/asm/*.asm)
objects :=  $(asmsrc:.asm=.o)
objects += $(csrc:.c=.o)

test: test.c nonstd.a
	$(CC) $(CFLAGS) -o $@ $^

nonstd.a: $(objects)
	ar -rc $@ $^

%.o: %.asm
	fasm $< $@

.PHONY: clean
clean:
	rm -f nonstd.a $(objects) test

