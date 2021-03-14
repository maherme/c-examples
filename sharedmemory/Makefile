TARGET1 = $(BIN_DIR)/create
TARGET2 = $(BIN_DIR)/read
TARGET3 = $(BIN_DIR)/write
SRC_DIR = .
OBJ_DIR = ./obj
BIN_DIR = ./bin
OBJS1 = $(OBJ_DIR)/create.o
OBJS2 = $(OBJ_DIR)/read.o
OBJS3 = $(OBJ_DIR)/write.o
CFLAGS = -Wall -lrt

.PHONY : all
all : $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)

.PHONY : create
create : $(TARGET1)

.PHONY : read
read : $(TARGET2)

.PHONY : write
write : $(TARGET3)

.PHONY : clean
clean:
	@rm -r $(OBJ_DIR) $(BIN_DIR)

$(TARGET1) : $(OBJS1)
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) $(OBJS1) -o $(TARGET1)

$(TARGET2) : $(OBJS2)
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) $(OBJS2) -o $(TARGET2)

$(TARGET3) : $(OBJS3)
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) $(OBJS3) -o $(TARGET3)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc -c $(CFLAGS) $< -o $@
