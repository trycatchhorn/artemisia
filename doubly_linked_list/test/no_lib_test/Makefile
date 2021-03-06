#
# Makefile for building the test program using the doubly linked list API.
#
# Author: Brian Horn
# Email: trycatchhorn@gmail.com
# Version: 1.0.0

# Name of compiler and standard compiler flags.
CC = gcc

# Get info about operating system.
ifneq ($(strip $(shell gcc -v 2>&1 | grep "darwin")),)
  MACOSX = true
endif

ifneq ($(strip $(shell gcc -v 2>&1 | grep "linux")),)
  LINUX = true
endif

# Compiler flags for building.
ifeq ($(MACOSX), true)
	C_FLAGS_DEBUG = -DDEBUG -g -Wall -O0 -ansi -pedantic -Qunused-arguments
	C_FLAGS_RELEASE = -Wall -O2 -Os -ansi -pedantic -Qunused-arguments
else
	C_FLAGS_DEBUG = -DDEBUG -g -Wall -O0 -ansi -pedantic
	C_FLAGS_RELEASE = -Wall -O2 -Os -ansi -pedantic
endif

# Directory structure for the build.
BUILD_DIR = ./build
DEBUG_DIR = $(BUILD_DIR)/debug
RELEASE_DIR = $(BUILD_DIR)/release

# List of source file(s).
C_FILES = doubly_linked_list_test.c

# List of object files.
O_FILE_DIR = ../../src/build
O_FILE_DEBUG = $(O_FILE_DIR)/debug/doubly_linked_listd.o
O_FILE_RELEASE = $(O_FILE_DIR)/release/doubly_linked_list.o
O_FILE_TEST_DEBUG = $(DEBUG_DIR)/doubly_linked_list_testd.o
O_FILE_TEST_RELEASE = $(RELEASE_DIR)/doubly_linked_list_test.o
O_FILES_DEBUG = $(O_FILE_DEBUG) $(O_FILE_TEST_DEBUG)
O_FILES_RELEASE = $(O_FILE_RELEASE) $(O_FILE_TEST_RELEASE)

# The name of the executables to build.
PROGRAM_DEBUG = doubly_linked_list_testd
PROGRAM_RELEASE = doubly_linked_list_test

# Path to include directory.
INCLUDE_DIR = ../../include/

# Libraries.
LIB_DIR = ../../src/lib

# Include flags.
INCLUDE_FLAGS = -I$(INCLUDE_DIR)

# Linker flags.
LINKER_FLAGS = -L$(LIB_DIR)

# Backup files.
H_BACKUP_FILES = *.h~
C_BACKUP_FILES = *.c~

SRC = ../../src

.PHONY: all init debug release clean

all: debug release

init:
	if [ ! -f $(O_FILE_DEBUG) ]; \
	then cd $(SRC) && $(MAKE) debug; \
	fi

	if [ ! -f $(O_FILE_RELEASE) ]; \
	then cd $(SRC) && $(MAKE) release; \
	fi

doubly_linked_list_testd.o:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(DEBUG_DIR)
	$(CC) -c $(C_FILES) $(C_FLAGS_DEBUG) $(INCLUDE_FLAGS) -o $(O_FILE_TEST_DEBUG)

doubly_linked_list_test.o:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(RELEASE_DIR)
	$(CC) -c $(C_FILES) $(C_FLAGS_RELEASE) $(INCLUDE_FLAGS) -o $(O_FILE_TEST_RELEASE)	

debug:	doubly_linked_list_testd.o
	$(CC) $(O_FILES_DEBUG) -o $(DEBUG_DIR)/$(PROGRAM_DEBUG)

release: doubly_linked_list_test.o
	$(CC) $(O_FILES_RELEASE) -o $(RELEASE_DIR)/$(PROGRAM_RELEASE)

run_valgrind: debug
	valgrind -v --leak-check=yes --show-reachable=yes --tool=memcheck ./$(DEBUG_DIR)/$(PROGRAM_DEBUG)


clean:
	@rm -f $(H_BACKUP_FILES)
	@rm -f $(C_BACKUP_FILES)
	@rm -rf $(BUILD_DIR)
