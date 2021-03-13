TARGET1 = $(BIN_DIR)/forkprog1
TARGET2 = $(BIN_DIR)/forkprog2
TARGET3 = $(BIN_DIR)/forkprog3
TARGET4 = $(BIN_DIR)/forkprog4
TARGET5 = $(BIN_DIR)/forkprog5
TARGET6 = $(BIN_DIR)/forkprog6
TARGET7 = $(BIN_DIR)/forkprog7
TARGET8 = $(BIN_DIR)/forkprog8
TARGET9 = $(BIN_DIR)/forkprog9
SRC_DIR = .
OBJ_DIR = ./obj
BIN_DIR = ./bin
OBJS1 = $(OBJ_DIR)/forkprog1.o
OBJS2 = $(OBJ_DIR)/forkprog2.o
OBJS3 = $(OBJ_DIR)/forkprog3.o
OBJS4 = $(OBJ_DIR)/forkprog4.o
OBJS5 = $(OBJ_DIR)/forkprog5.o
OBJS6 = $(OBJ_DIR)/forkprog6.o
OBJS7 = $(OBJ_DIR)/forkprog7.o
OBJS8 = $(OBJ_DIR)/forkprog8.o
OBJS9 = $(OBJ_DIR)/forkprog9.o
CFLAGS = -Wall

.PHONY : all
all : $(TARGET1) \
	  $(TARGET2) \
	  $(TARGET3) \
	  $(TARGET4) \
	  $(TARGET5) \
	  $(TARGET6) \
	  $(TARGET7) \
	  $(TARGET8) \
	  $(TARGET9)

.PHONY : forkprog1
forkprog1 : $(TARGET1)

.PHONY : forkprog2
forkprog2 : $(TARGET2)

.PHONY : forkprog3
forkprog3 : $(TARGET3)

.PHONY : forkprog4
forkprog4 : $(TARGET4)

.PHONY : forkprog5
forkprog5 : $(TARGET5)

.PHONY : forkprog6
forkprog6 : $(TARGET6)

.PHONY : forkprog7
forkprog7 : $(TARGET7)

.PHONY : forkprog8
forkprog8 : $(TARGET8)

.PHONY : forkprog9
forkprog9 : $(TARGET9)

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

$(TARGET5) : $(OBJS5)
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) $(OBJS5) -o $(TARGET5)

$(TARGET6) : $(OBJS6)
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) $(OBJS6) -o $(TARGET6)

$(TARGET7) : $(OBJS7)
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) $(OBJS7) -o $(TARGET7)

$(TARGET8) : $(OBJS8)
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) $(OBJS8) -o $(TARGET8)

$(TARGET9) : $(OBJS9)
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) $(OBJS9) -o $(TARGET9)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc -c $(CFLAGS) $< -o $@
