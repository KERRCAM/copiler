BUILD_DIR = builds
CC = gcc
SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_NAME = compiler
INCLUDE_PATHS = -Iinclude
COMPILER_FLAGS = -Wall -std=c99

b:
	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(SRC_FILES) editor/levels.c editor/sectors.c editor/walls.c -o $(BUILD_DIR)/$(OBJ_NAME)

r:
	./$(BUILD_DIR)/$(OBJ_NAME)

c:
	rm $(BUILD_DIR)/$(OBJ_NAME)
