#
# Makefile for building the singly linked list libraries - static link library
# and dynamic shared library.
#
# Targets:
#
# singly_linked_list_static_lib: builds a static link library including the singly linked list API.
# singly_linked_list_shared_lib: builds a dynamic shared library including the singly linked list API.
#
# Author: Brian Horn
# Email: trycatchhorn@gmail.com
# Version: 1.0.0

SINGLY_LINKED_LIST_LIB_STATIC = ./static_lib
SINGLY_LINKED_LIST_LIB_SHARED = ./shared_lib

.PHONY: all singly_linked_list_static_lib singly_linked_list_shared_lib clean

all:	singly_linked_list_static_lib singly_linked_list_shared_lib

singly_linked_list_static_lib:
	@cd $(SINGLY_LINKED_LIST_LIB_STATIC) && $(MAKE)

singly_linked_list_shared_lib:
	@cd $(SINGLY_LINKED_LIST_LIB_SHARED) && $(MAKE)

clean:
	@cd $(SINGLY_LINKED_LIST_LIB_STATIC) && $(MAKE) clean
	@cd $(SINGLY_LINKED_LIST_LIB_SHARED) && $(MAKE) clean
