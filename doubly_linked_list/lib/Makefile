#
# Makefile for building the doubly linked list libraries - static link library
# and dynamic shared library.
#
# Targets:
#
# doubly_linked_list_static_lib: builds a static link library including the doubly linked list API.
# doubly_linked_list_shared_lib: builds a dynamic shared library including the doubly linked list API.
#
# Author: Brian Horn
# Email: trycatchhorn@gmail.com
# Version: 1.0.0

DOUBLY_LINKED_LIST_LIB_STATIC = ./static_lib
DOUBLY_LINKED_LIST_LIB_SHARED = ./shared_lib

.PHONY: all doubly_linked_list_static_lib doubly_linked_list_shared_lib clean

all:	doubly_linked_list_static_lib doubly_linked_list_shared_lib

doubly_linked_list_static_lib:
	@cd $(DOUBLY_LINKED_LIST_LIB_STATIC) && $(MAKE)

doubly_linked_list_shared_lib:
	@cd $(DOUBLY_LINKED_LIST_LIB_SHARED) && $(MAKE)

clean:
	@cd $(DOUBLY_LINKED_LIST_LIB_STATIC) && $(MAKE) clean
	@cd $(DOUBLY_LINKED_LIST_LIB_SHARED) && $(MAKE) clean
