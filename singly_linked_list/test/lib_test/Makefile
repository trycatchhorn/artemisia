#
# Makefile for building the library test programs that uses the singly linked list API compiled as a shared dynamic library and static link library.
#
# Author: Brian Horn
# Email: trycatchhorn@gmail.com
# Version: 1.0.0

SHARED_LIB_TEST = ./shared_lib_test
STATIC_LIB_TEST = ./static_lib_test

.PHONY: all debug release clean

all: 	debug release

debug:
	@cd $(SHARED_LIB_TEST) && $(MAKE) debug
	@cd $(STATIC_LIB_TEST) && $(MAKE) debug

release:
	@cd $(SHARED_LIB_TEST) && $(MAKE) release
	@cd $(STATIC_LIB_TEST) && $(MAKE) release

clean:
	@cd $(SHARED_LIB_TEST) && $(MAKE) clean
	@cd $(STATIC_LIB_TEST) && $(MAKE) clean


