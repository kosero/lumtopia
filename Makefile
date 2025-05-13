CC = clang
CFLAGS = -lraylib -std=c11 -pedantic -Wall -Wextra -O3  -Iinc
SRC_DIR = src
INC_DIR = inc
BUILD_DIR = build

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
TARGET = $(BUILD_DIR)/main

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

.PHONY: all clean

all: $(TARGET)

clean:
	rm -rf $(BUILD_DIR)

