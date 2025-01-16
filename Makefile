CC := gcc
CFLAGS := -O2 -nostdlib -nostdinc -ffreestanding -no-pie -fno-stack-protector -Wall -Wextra -Werror -std=c11 -I./include -Wno-strict-aliasing -flto

csrc := $(shell find src/c -type f -name '*.c')
asmsrc := $(shell find src/asm -type f -name '*.asm')
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

