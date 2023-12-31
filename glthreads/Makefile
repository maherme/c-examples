BIN_DIR = ./bin
CFLAGS = -Wall -Werror

all: main

main: main.c glthreads.c glthreads.h
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) $^ -o $(BIN_DIR)/$@

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)
