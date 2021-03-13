TARGET1 = $(BIN_DIR)/reader_fifo
TARGET2 = $(BIN_DIR)/writer_fifo
SRC_DIR = .
OBJ_DIR = ./obj
BIN_DIR = ./bin
OBJS1 = $(OBJ_DIR)/reader_fifo.o
OBJS2 = $(OBJ_DIR)/writer_fifo.o
CFLAGS = -Wall

.PHONY : all
all : $(TARGET1) $(TARGET2)

.PHONY : reader_fifo
reader_fifo : $(TARGET1)

.PHONY : writer_fifo
writer_fifo : $(TARGET2)

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
