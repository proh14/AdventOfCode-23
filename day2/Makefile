CC := gcc
SRC_DIR := ./src
BUILD_DIR := ./build
CFLAGS := -MMD -MP -Wall -Wextra -g -pedantic -std=c99
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/src/%.o, $(SRCS))
DEPS := $(OBJS:.o=.d)
EXES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%, $(SRCS))

all: $(EXES)

$(shell mkdir -p $(BUILD_DIR)/src)

$(BUILD_DIR)/%: $(BUILD_DIR)/src/%.o
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/src/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)
