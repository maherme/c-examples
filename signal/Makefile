TARGET = $(BIN_DIR)/signal
SRC_DIR = .
OBJ_DIR = ./obj
BIN_DIR = ./bin
OBJS = $(OBJ_DIR)/signal.o
CFLAGS = -Wall

$(TARGET) : $(OBJS)
	@mkdir -p $(BIN_DIR)
	gcc $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	gcc -c $(CFLAGS) $< -o $@

.PHONY : clean
clean:
	@rm -r $(OBJ_DIR) $(BIN_DIR)
