SRC_DIR=src
BUILD_DIR=bin
LIB_DIR=lib
INC_DIR=include

CC=gcc
CFLAGS=-Wall -Wextra -Wshadow -pedantic -std=c11 -g3 -I$(INC_DIR) -L$(LIB_DIR)

CFLAGS_COMMON=$(CFLAGS)
CFLAGS_HUB=$(CFLAGS) -I$(SRC_DIR) -L$(BUILD_DIR)
CFLAGS_PLAYER=$(CFLAGS) -I$(SRC_DIR) -L$(BUILD_DIR)

.PHONY: all
all: $(BUILD_DIR)/libpoker $(BUILD_DIR)/hub $(BUILD_DIR)/player

$(BUILD_DIR)/libpoker: $(SRC_DIR)/common/*.c
	$(CC) -c $? $(CFLAGS_COMMON)
	mv *.o $(BUILD_DIR)
	ar -cvq $@.a $(BUILD_DIR)/*.o
	ar -t $@.a

$(BUILD_DIR)/hub: $(SRC_DIR)/hub/*.c
	$(CC) $? $(CFLAGS_HUB) -o $@

$(BUILD_DIR)/player: $(SRC_DIR)/player/*.c
	$(CC) $? $(CFLAGS_PLAYER) -o $@

.PHONY: clean
clean:
	rm $(BUILD_DIR)/libpoker.a
	rm $(BUILD_DIR)/hub
	rm $(BUILD_DIR)/player
	rm $(BUILD_DIR)/*.o

