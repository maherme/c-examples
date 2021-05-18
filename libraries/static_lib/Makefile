TARGET_BIN = $(BIN_DIR)/calculator
TARGET_LIB = $(LIB_DIR)/libmylib.a
SRC_DIR = .
OBJ_DIR = ./obj
BIN_DIR = ./bin
LIB_DIR = ./lib
OBJS = $(OBJ_DIR)/main.o
OBJS_LIB = $(OBJ_DIR)/mymath.o \
		   $(OBJ_DIR)/mymath2.o
CFLAGS = -Wall

.PHONY : all
all: $(TARGET_LIB) \
	 $(TARGET_BIN)

.PHONY : calculator
calculator: $(TARGET_BIN)

.PHONY : clean_all
clean_all:
	@rm -r $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)

.PHONY : staticlib
staticlib: $(TARGET_LIB)

$(TARGET_LIB): $(OBJS_LIB)
	@mkdir -p $(LIB_DIR)
	@ar rcu $@ $+
	@ranlib $@

$(TARGET_BIN) : $(OBJS)
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) -L$(LIB_DIR) $(OBJS) -o $(TARGET_BIN) -lmylib -lm

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc -c $(CFLAGS) $< -o $@
