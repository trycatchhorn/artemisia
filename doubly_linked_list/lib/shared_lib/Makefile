#
# Makefile for creating a shared dynamic library of the doubly linked list API.
#
# NOTE: otool -L <libname> shows library dependencies and version information.
#
# Author: Brian Horn
# Email: trycatchhorn@gmail.com
# Version: 1.0.0

# Name of compiler.
CC = gcc

# Get info about operating system.
ifneq ($(strip $(shell gcc -v 2>&1 | grep "darwin")),)
  MACOSX = true
endif

ifneq ($(strip $(shell gcc -v 2>&1 | grep "linux")),)
  LINUX = true
endif

# Library version information.
LIB_VERSION = 1.0.0
LIB_COMPATIBILITY_VERSION = 1.0.0

# Compiler flags for building the shared library.
ifeq ($(MACOSX), true)
	C_DEBUG_FLAGS = -g -Wall -O0 -dynamic -pedantic -fPIC -dynamiclib -nostartfiles -compatibility_version $(LIB_COMPATIBILITY_VERSION) -current_version $(LIB_VERSION)
	C_RELEASE_FLAGS = -Wall -O2 -Os -dynamic -pedantic -fPIC -dynamiclib -nostartfiles -compatibility_version $(LIB_COMPATIBILITY_VERSION) -current_version $(LIB_VERSION)
else
	C_DEBUG_FLAGS = -g -Wall -O0 -shared -ansi -pedantic -fPIC -dynamiclib -nostartfiles
	C_RELEASE_FLAGS = -Wall -O2 -Os -shared -ansi -pedantic -fPIC -dynamiclib -nostartfiles
endif

# Library names.
ifeq ($(MACOSX), true)
	LIB_DEBUG = libdoubly_linked_listd.dylib
	LIB_RELEASE = libdoubly_linked_list.dylib
else
	LIB_DEBUG = libdoubly_linked_listd.so
	LIB_RELEASE = libdoubly_linked_list.so
endif

# Directory structure.
BUILD_DIR = ./build
DEBUG_DIR = $(BUILD_DIR)/debug
RELEASE_DIR = $(BUILD_DIR)/release

# List of object files.
O_FILES_DEBUG = ../../src/build/debug/doubly_linked_listd.o
O_FILES_RELEASE = ../../src/build/release/doubly_linked_list.o

.PHONY: all debug release clean

all: debug release

debug:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(DEBUG_DIR)
	$(CC) $(C_DEBUG_FLAGS) -o $(DEBUG_DIR)/$(LIB_DEBUG) $(O_FILES_DEBUG)

release:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(RELEASE_DIR)
	$(CC) $(C_RELEASE_FLAGS) -o $(RELEASE_DIR)/$(LIB_RELEASE) $(O_FILES_RELEASE)

clean:
	@rm -rf $(BUILD_DIR)

