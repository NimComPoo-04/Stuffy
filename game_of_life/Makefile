CC = gcc
CFLAGS = -Wall -Wextra -ggdb -std=c11 -O0

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, obj/%.o, $(SRC))

all: build gol

gol: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ -lm

obj/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -rf obj gol

build:
	mkdir -p obj
