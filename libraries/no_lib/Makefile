TARGET = $(BIN_DIR)/calculator
SRC_DIR = .
OBJ_DIR = ./obj
BIN_DIR = ./bin
OBJS = $(OBJ_DIR)/main.o \
	   $(OBJ_DIR)/mymath.o \
       $(OBJ_DIR)/mymath2.o
CFLAGS = -Wall

.PHONY : all
all: $(TARGET)

.PHONY : clean
clean:
	@rm -r $(OBJ_DIR) $(BIN_DIR)

$(TARGET) : $(OBJS)
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc -c $(CFLAGS) $< -o $@
