CC=gcc
CFLAGS=-Wall -Werror -std=c99 -c
INC=-I./inc
LFLAGS=-ljansson -g
SRC=$(wildcard src/*.c)
OBJ=$(addprefix obj/,$(notdir $(SRC:.c=.o)))

all: bin/json

bin/json: $(OBJ)
	$(CC) $^ -o $@ $(LFLAGS)

obj/%.o: src/%.c
	$(CC) $(CFLAGS) $(INC) $< -o $@ -g

clean:
	rm -rf bin/*
	rm -rf obj/*