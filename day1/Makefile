CC=gcc
TARGET_EXEC := game_of_life
BUILD_DIR := ./build
SRC_DIRS := ./src
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))
CFLAGS := $(INC_FLAGS) -MMD -MP -Wall -O3 -Wextra -pedantic -std=c99	

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)
	cp $(BUILD_DIR)/$(TARGET_EXEC) $(TARGET_EXEC)

$(BUILD_DIR)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(CFLAGS) -c $< -o $@ 

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

-include $(DEPS)
