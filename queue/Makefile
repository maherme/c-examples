TARGET1 = $(BIN_DIR)/pqueue_tx.c
TARGET2 = $(BIN_DIR)/pqueue_rx.c
TARGET3 = $(BIN_DIR)/queue_tx.c
TARGET4 = $(BIN_DIR)/queue_rx.c
SRC_DIR = .
OBJ_DIR = ./obj
BIN_DIR = ./bin
OBJS1 = $(OBJ_DIR)/pqueue_tx.o
OBJS2 = $(OBJ_DIR)/pqueue_rx.o
OBJS3 = $(OBJ_DIR)/queue_tx.o
OBJS4 = $(OBJ_DIR)/queue_rx.o
CFLAGS = -Wall -lrt

.PHONY : all
all : $(TARGET1) $(TARGET2)

.PHONY : pqueue_tx
pqueue_tx : $(TARGET1)

.PHONY : pqueue_rx
pqueue_rx : $(TARGET2)

.PHONY : queue_tx
queue_tx : $(TARGET3)

.PHONY : queue_rx
queue_rx : $(TARGET4)

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
