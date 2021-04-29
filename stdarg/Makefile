TARGET1 = $(BIN_DIR)/print_example
TARGET2 = $(BIN_DIR)/my_printf
SRC_DIR = .
OBJ_DIR = ./obj
BIN_DIR = ./bin
OBJS1 = $(OBJ_DIR)/print_example.o
OBJS2 = $(OBJ_DIR)/my_printf.o
CFLAGS = -Wall

.PHONY : all
all : $(TARGET1) \
	  $(TARGET2)

.PHONY : print_example
print_example : $(TARGET1)

.PHONY : my_printf
my_printf : $(TARGET2)

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
