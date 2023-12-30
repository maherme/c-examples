TARGET1 = $(BIN_DIR)/mutex
TARGET2 = $(BIN_DIR)/semaphores
TARGET3 = $(BIN_DIR)/threads
TARGET4 = $(BIN_DIR)/counter
SRC_DIR = .
OBJ_DIR = ./obj
BIN_DIR = ./bin
OBJS1 = $(OBJ_DIR)/mutex.o
OBJS2 = $(OBJ_DIR)/semaphores.o
OBJS3 = $(OBJ_DIR)/threads.o
OBJS4 = $(OBJ_DIR)/counter.o
CFLAGS = -Wall -pthread

.PHONY : all
all : $(TARGET1) $(TARGET2) $(TARGET3) $(TARGET4)

.PHONY : mutex
mutex : $(TARGET1)

.PHONY : semaphores
semaphores : $(TARGET2)

.PHONY : threads
threads : $(TARGET3)

.PHONY : counter
counter : $(TARGET4)

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

$(TARGET4) : $(OBJS4)
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) $(OBJS4) -o $(TARGET4)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc -c $(CFLAGS) $< -o $@
