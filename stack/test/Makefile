#
# Makefile for building the stack test programs.
#
# Targets:
#
# stack_no_lib_test_debug: builds a test program that uses the stack API - compiled in debug mode.
# stack_no_lib_test_release: builds a test program that uses the stack API - compiled in release mode.
# stack_lib_test_debug: builds a test program that uses the stack API as libraries - compiled in debug mode.
# stack_lib_test_release: builds a test program that uses the stack API as libraries - compiled in release mode.
#
# Author: Brian Horn
# Email: trycatchhorn@gmail.com
# Version: 1.0.0

STACK_NO_LIB_TEST = ./no_lib_test
STACK_LIB_TEST = ./lib_test

.PHONY: all debug release clean

all:	debug release

debug:
	@cd $(STACK_NO_LIB_TEST) && $(MAKE) debug 
	@cd $(STACK_LIB_TEST) && $(MAKE) debug 

release:
	@cd $(STACK_NO_LIB_TEST) && $(MAKE) release 
	@cd $(STACK_LIB_TEST) && $(MAKE) release

clean:
	@cd $(STACK_NO_LIB_TEST) && $(MAKE) clean
	@cd $(STACK_LIB_TEST) && $(MAKE) clean
