TARGET1 = $(BIN_DIR)/execprog1
TARGET2 = $(BIN_DIR)/execprog2
SRC_DIR = .
OBJ_DIR = ./obj
BIN_DIR = ./bin
OBJS1 = $(OBJ_DIR)/execprog1.o
OBJS2 = $(OBJ_DIR)/execprog2.o
CFLAGS = -Wall

.PHONY : all
all : $(TARGET1) $(TARGET2)

.PHONY : execprog1
execprog1 : $(TARGET1)

.PHONY : execprog2
execprog2 : $(TARGET2)

.PHONY : clean
clean:
	@rm -r $(OBJ_DIR) $(BIN_DIR)

$(TARGET1) : $(OBJS1)
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) $(OBJS1) -o $(TARGET1)

$(TARGET2) : $(OBJS2)
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) $(OBJS2) -o $(TARGET2)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc -c $(CFLAGS) $< -o $@
