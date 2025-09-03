BUILD_DIR = builds
CC = gcc
SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_NAME = compiler
INCLUDE_PATHS = -Iinclude
COMPILER_FLAGS = -Wall -std=c99

b:
	$(CC) $(COMPILER_FLAGS) $(INCLUDE_PATHS) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)

r:
	./$(BUILD_DIR)/$(OBJ_NAME)

c:
	rm $(BUILD_DIR)/$(OBJ_NAME)

asm:
	make test.o
	ld -o $(BUILD_DIR)/test assembly/test.o -lSystem -syslibroot `xcrun -sdk macosx --show-sdk-path` -e _start -arch arm64

test.o: assembly/test.asm
	as -o assembly/test.o assembly/test.asm

ra:
	./builds/test

ca:
	rm assembly/test.o
	rm builds/test


ba: assembly/demo.o
	ld -o $(BUILD_DIR)/demo assembly/demo.o -lSystem -syslibroot `xcrun -sdk macosx --show-sdk-path` -e _start -arch arm64

demo.o: assembly/demo.asm
	as -o assembly/demo.o assembly/demo.asm