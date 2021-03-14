TARGET1 = $(BIN_DIR)/mmap
SRC_DIR = .
OBJ_DIR = ./obj
BIN_DIR = ./bin
OBJS1 = $(OBJ_DIR)/mmap.o
CFLAGS = -Wall

.PHONY : all
all : $(TARGET1)

.PHONY : mmap
mmap : $(TARGET1)

.PHONY : clean
clean:
	@rm -r $(OBJ_DIR) $(BIN_DIR)

$(TARGET1) : $(OBJS1)
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) $(OBJS1) -o $(TARGET1)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc -c $(CFLAGS) $< -o $@
