CC := gcc
CFLAGS := -O2 -nostdlib -ffreestanding -no-pie -fno-stack-protector -Wall -Wextra -Werror -pedantic -std=c11 -I./include -Wno-strict-aliasing 

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

