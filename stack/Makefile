#
# Master makefile for building the stack project.
#
# Targets:
#
# stack_src: builds the stack object file.
# stack_lib: builds a static link library including the stack API.
# no_lib_test: builds an executable testing the stack source.
# lib_test: builds an executables testing the libraries.
# dist: wraps everything nicely in a tar.gz.
#
# Author: Brian Horn
# Email: trycatchhorn@gmail.com
# Version: 1.0.0

STACK_SRC = ./src
STACK_LIB = ./lib
STACK_INCLUDE = ./include
STACK_TEST = ./test
STACK_NO_LIB_TEST = ./test/no_lib_test
STACK_LIB_TEST = ./test/lib_test 
STACK_DIST = ./dist
STACK_DIST_NAME = stack.tar.gz

.PHONY: init all stack_src stack_lib stack_no_lib_tst stack_lib_test dist clean

init:
	@echo "Building the stack..." && $(MAKE) all	

all:	stack_src stack_lib stack_no_lib_test stack_lib_test

stack_src:
	@cd $(STACK_SRC) && $(MAKE)

stack_lib:
	@cd $(STACK_LIB) && $(MAKE)

stack_no_lib_test:
	@cd $(STACK_NO_LIB_TEST) && $(MAKE)

stack_lib_test:
	@cd $(STACK_LIB_TEST) && $(MAKE)

dist:
	@$(MAKE) clean
	@echo "Creating distribution for stack..."
	@svn export -q . $(STACK_DIST)
	@tar -zcf $(STACK_DIST_NAME) $(STACK_DIST)
	@rm -rf $(STACK_DIST)

clean:
	@cd $(STACK_SRC) && $(MAKE) clean
	@cd $(STACK_LIB) && $(MAKE) clean
	@cd $(STACK_NO_LIB_TEST) && $(MAKE) clean
	@cd $(STACK_LIB_TEST) && $(MAKE) clean
	@rm -rf $(STACK_DIST)
	@rm -f $(STACK_DIST_NAME)