# Makefile for building the test program that uses the singly linked list API - compiled as a static link library.
#
# Author: Brian Horn
# Email: trycatchhorn@gmail.com
# Version: 1.0.0

# Name of compiler
CC = gcc

# Get info about operating system.
ifneq ($(strip $(shell gcc -v 2>&1 | grep "darwin")),)
  MACOSX = true
endif

ifneq ($(strip $(shell gcc -v 2>&1 | grep "linux")),)
  LINUX = true
endif

# Compiler flags for building the static library.
ifeq ($(MACOSX), true)
	C_DEBUG_FLAGS = -g -Wall -O0 -ansi -pedantic -Qunused-arguments
	C_RELEASE_FLAGS = -Wall -O2 -Os -ansi -pedantic -Qunused-arguments
else
	C_DEBUG_FLAGS = -g -Wall -O0 -ansi -pedantic
	C_RELEASE_FLAGS = -Wall -O2 -Os -ansi -pedantic
endif

# Directory structure for the build.
BUILD_DIR = ./build
DEBUG_DIR = $(BUILD_DIR)/debug
RELEASE_DIR = $(BUILD_DIR)/release

# List of source file(s).
C_FILES = singly_linked_list_test_static_lib.c 

# List of object files.
O_FILE_DIR = ../../../src/build
O_FILE_DEBUG = $(O_FILE_DIR)/debug/singly_linked_listd.o
O_FILE_RELEASE = $(O_FILE_DIR)/release/singly_linked_list.o
O_FILE_TEST_STATIC_DEBUG = $(DEBUG_DIR)/singly_linked_list_test_static_libd.o
O_FILE_TEST_STATIC_RELEASE = $(RELEASE_DIR)/singly_linked_list_test_static_lib.o
O_FILES_DEBUG = $(O_FILE_DEBUG) $(O_FILE_TEST_STATIC_DEBUG)
O_FILES_RELEASE = $(O_FILE_RELEASE) $(O_FILE_TEST_STATIC_RELEASE)

# The name of the executables to build.
PROGRAM_DEBUG = singly_linked_list_test_static_libd
PROGRAM_RELEASE = singly_linked_list_test_static_lib

# Path to include directory.
INCLUDE_DIR = ../../../include/

# Paths to libraries.
LIB_DIR = ../../../lib/static_lib
LIB_BUILD_DIR = $(LIB_DIR)/build
LIB_DEBUG_DIR = $(LIB_BUILD_DIR)/debug
LIB_RELEASE_DIR = $(LIB_BUILD_DIR)/release

# Name of libraries.
LIB_DEBUG = $(LIB_DEBUG_DIR)/libsingly_linked_listd.a
LIB_RELEASE = $(LIB_RELEASE_DIR)/libsingly_linked_list.a

# Include flags.
INCLUDE_FLAGS = -I$(INCLUDE_DIR)

# Linker flags.
LINKER_FLAGS_DEBUG = -L$(LIB_DEBUG_DIR)
LINKER_FLAGS_RELEASE = -L$(LIB_RELEASE_DIR)

# Backup files
H_BACKUP_FILES = *.h~
C_BACKUP_FILES = *.c~

SRC = ../../../src

.PHONY: all init debug release clean

all: 	init debug release

init:
	if [ ! -f $(O_FILE_DEBUG) ]; \
	then cd $(SRC) && $(MAKE) debug; \
	fi

	if [ ! -f $(O_FILE_RELEASE) ]; \
	then cd $(SRC) && $(MAKE) release; \
	fi

	if [ ! -f $(LIB_DEBUG) ]; \
	then cd $(LIB_DIR) && $(MAKE) debug; \
	fi

	if [ ! -f $(LIB_RELEASE) ]; \
	then cd $(LIB_DIR) && $(MAKE) release; \
	fi

singly_linked_list_test_static_libd.o:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(DEBUG_DIR)
	$(CC) -c $(C_FILES) $(C_FLAGS_DEBUG) $(INCLUDE_FLAGS) -o $(O_FILE_TEST_STATIC_DEBUG)

singly_linked_list_test_static_lib.o:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(RELEASE_DIR)
	$(CC) -c $(C_FILES) $(C_FLAGS_RELEASE) $(INCLUDE_FLAGS) -o $(O_FILE_TEST_STATIC_RELEASE)

debug:	singly_linked_list_test_static_libd.o
	@ranlib $(LIB_DEBUG)
	$(CC) $(O_FILES_DEBUG) $(INCLUDE_FLAGS) $(LINKER_FLAGS_DEBUG) -lsingly_linked_listd -o $(DEBUG_DIR)/$(PROGRAM_DEBUG)

release: singly_linked_list_test_static_lib.o
	@ranlib $(LIB_RELEASE)
	$(CC) $(O_FILES_RELEASE) $(INCLUDE_FLAGS) $(LINKER_FLAGS_RELEASE) -lsingly_linked_list -o $(RELEASE_DIR)/$(PROGRAM_RELEASE)

clean:
	@rm -rf $(BUILD_DIR)
	@rm -f $(H_BACKUP_FILES)
	@rm -f $(C_BACKUP_FILES)
