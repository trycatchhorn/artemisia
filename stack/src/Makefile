#
# Makefile for building the stack source.
#
# NOTE: Only the object (stack.o) file is build.
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
	C_DEBUG_FLAGS = -g -Wall -O0 -ansi -pedantic -Qunused-arguments
	C_RELEASE_FLAGS = -Wall -O2 -Os -ansi -pedantic -Qunused-arguments
else
	C_DEBUG_FLAGS = -g -Wall -O0 -ansi -pedantic -fPIC
	C_RELEASE_FLAGS = -Wall -O2 -Os -ansi -pedantic -fPIC
endif

# Directory structure
BUILD_DIR = ./build
DEBUG_DIR = $(BUILD_DIR)/debug/
RELEASE_DIR = $(BUILD_DIR)/release/

# List of source file(s).
C_FILES = stack.c 

# List of object files.
O_FILES_DEBUG = stackd.o
O_FILES_RELEASE = stack.o

DEBUG_LIST = $(addprefix $(DEBUG_DIR), $(O_FILES_DEBUG))
RELEASE_LIST = $(addprefix $(RELEASE_DIR), $(O_FILES_RELEASE))

# Paths for make to search.
VPATH = $(DEBUG_DIR) $(RELEASE_DIR)

# Backup files.
H_BACKUP_FILES = *.h~
C_BACKUP_FILES = *.c~

.PHONY: all debug release clean

all:	debug release

debug:	
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(DEBUG_DIR)
	$(CC) -c $(C_FILES) $(C_DEBUG_FLAGS) $< -o $(DEBUG_LIST)

release:
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(RELEASE_DIR)
	$(CC) -c $(C_FILES) $(C_RELEASE_FLAGS) $< -o $(RELEASE_LIST)

clean:
	@rm -rf $(BUILD_DIR)
	@rm -f $(H_BACKUP_FILES)
	@rm -f $(C_BACKUP_FILES)
