#
# Makefile for building the library test programs that uses the stack API compiled as a shared dynamic library and static link library.
#
# Author: Brian Horn
# Email: trycatchhorn@gmail.com
# Version: 1.0.0

STACK_SHARED_LIB_TEST = ./shared_lib_test
STACK_STATIC_LIB_TEST = ./static_lib_test

.PHONY: all debug release clean

all: 	debug release

debug:
	@cd $(STACK_SHARED_LIB_TEST) && $(MAKE) debug
	@cd $(STACK_STATIC_LIB_TEST) && $(MAKE) debug

release:
	@cd $(STACK_SHARED_LIB_TEST) && $(MAKE) release
	@cd $(STACK_STATIC_LIB_TEST) && $(MAKE) release

clean:
	@cd $(STACK_SHARED_LIB_TEST) && $(MAKE) clean
	@cd $(STACK_STATIC_LIB_TEST) && $(MAKE) clean


