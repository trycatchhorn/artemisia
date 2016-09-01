#
# Makefile for creating a static link library of the singly linked list API.
#
# Author: Brian Horn
# Email: trycatchhorn@gmail.com
# Version: 1.0.0

# Library names
LIB_RELEASE = libsingly_linked_list.a
LIB_DEBUG = libsingly_linked_listd.a

# Directory structure
BUILD_DIR = ./build
RELEASE_DIR = $(BUILD_DIR)/release/
DEBUG_DIR = $(BUILD_DIR)/debug/

# List of object files.
O_FILES_DEBUG = ../../src/build/debug/singly_linked_listd.o
O_FILES_RELEASE = ../../src/build/release/singly_linked_list.o

.PHONY: all debug release clean

all: debug release

debug:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(DEBUG_DIR)
	@$(AR) -c -r $(LIB_DEBUG) $(O_FILES_DEBUG)
	@install -m 755 $(LIB_DEBUG) $(DEBUG_DIR)
	@rm -f $(LIB_DEBUG)

release:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(RELEASE_DIR)
	@$(AR) -c -r $(LIB_RELEASE) $(O_FILES_RELEASE)
	@install -m 755 $(LIB_RELEASE) $(RELEASE_DIR)
	@rm -f $(LIB_RELEASE)

clean:
	@rm -rf $(BUILD_DIR)
