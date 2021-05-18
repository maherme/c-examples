TARGET_BIN = $(BIN_DIR)/calculator
TARGET_LIB = $(LIB_DIR)/libmylib.so
SRC_DIR = .
OBJ_DIR = ./obj
BIN_DIR = ./bin
LIB_DIR = ./lib
OBJS = $(OBJ_DIR)/main.o
OBJS_LIB = $(OBJ_DIR)/mymath.o \
		   $(OBJ_DIR)/mymath2.o
CFLAGS = -Wall
CFLAGS_OBJ = -Wall -fPIC
LDFLAGS = -shared

.PHONY : all
all: $(TARGET_LIB) \
	 $(TARGET_BIN)

.PHONY : calculator
calculator: $(TARGET_BIN)

.PHONY : clean_all
clean_all:
	@rm -r $(OBJ_DIR) $(BIN_DIR) $(LIB_DIR)

.PHONY : export_path
export_path:
	export LD_LIBRARY_PATH=$(LIB_DIR)

.PHONY : dynamiclib
dynamiclib: $(TARGET_LIB)

$(TARGET_LIB): $(OBJS_LIB)
	@mkdir -p $(LIB_DIR)
	@gcc $(LDFLAGS) -o $@ $^

$(TARGET_BIN) : $(OBJS)
	@mkdir -p $(BIN_DIR)
	@gcc $(CFLAGS) -L$(LIB_DIR) -lmylib $(OBJS) -o $(TARGET_BIN)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc -c $(CFLAGS_OBJ) $< -o $@
