#
# Makefile for building the stack libraries - static link library
# and dynamic shared library.
#
# Targets:
#
# stack_static_lib: builds a static link library including the stack API.
# stack_shared_lib: builds a dynamic shared library including the stack API.
#
# Author: Brian Horn
# Email: trycatchhorn@gmail.com
# Version: 1.0.0

STACK_LIB_STATIC = ./static_lib
STACK_LIB_SHARED = ./shared_lib

.PHONY: all stack_static_lib stack_shared_lib clean

all:	stack_static_lib stack_shared_lib

stack_static_lib:
	@cd $(STACK_LIB_STATIC) && $(MAKE)

stack_shared_lib:
	@cd $(STACK_LIB_SHARED) && $(MAKE)

clean:
	@cd $(STACK_LIB_STATIC) && $(MAKE) clean
	@cd $(STACK_LIB_SHARED) && $(MAKE) clean
