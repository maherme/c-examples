BIN_DIR = ./bin
CFLAGS = -Wall -Werror -pthread

%: %.c
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) $< -o $(BIN_DIR)/$@

.PHONY: clean
clean:
	@rm -rf $(BIN_DIR)
