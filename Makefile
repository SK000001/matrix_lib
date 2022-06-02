SRC_DIR = src
BUILD_DIR = build/debug
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_NAME = matrix

all:
	$(CC) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME) && ./$(BUILD_DIR)/$(OBJ_NAME)