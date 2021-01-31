# Makefile for compiling termschem

# Source and build directories.
SRC_DIR 			:= src
OBJ_DIR 			:= obj
BIN_DIR 			:= bin

# Test framework directories.
BUILD_DIR 			:= build
TEST_DIR 			:= test
UNITY_DIR			:= $(TEST_DIR)/unity
RESULTS_DIR			:= $(BUILD_DIR)/results

# The build target executable, source, and object files.
EXE 				:= $(BIN_DIR)/termschem
SRC 				:= $(wildcard $(SRC_DIR)/*.c)
OBJ 				:= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compiler/linker options.
CC 					:= gcc
RM 					:= rm
CFLAGS 				:= -Wall
CPPFLAGS 			:= -Iinclude -MMD -MP	
LDFLAGS 			:= -Llib -lpthread -lpanel -lncurses -lverilogparser
LDLIBS 				:= -lm

.PHONY: all clean

all: $(EXE)

# Define target for building doxygen automatic documentation.
docs:
	@doxygen
	@sensible-browser doxydoc/html/index.html

# Define rule for building executable.
$(EXE) : $(OBJ) | $(BIN_DIR)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

# Define rule for build object files.
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -o $@ -c $< $(CPPFLAGS) $(CFLAGS)

# Create obj directory, if it doesn't exist.
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Define target for cleaning build artifacts.
clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR) # The @ disables echo.

# Automatic dependency generation.
-include $(OBJ:.o=.d)
