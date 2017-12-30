#
# Master makefile for building the doubly linked list project.
#
# Targets:
#
# doubly_linked_list_src: builds the doubly linked list object file.
# doubly_linked_list_lib: builds a static link library including the doubly linked list API.
# doubly_linked_list_no_lib_test: builds an executable testing the doubly linked list source.
# doubly_linked_list_lib_test: builds an executable testing the static link library.
#

DOUBLY_LINKED_LIST_SRC = ./src
DOUBLY_LINKED_LIST_LIB = ./lib
DOUBLY_LINKED_LIST_NO_LIB_TEST = ./test/no_lib_test
DOUBLY_LINKED_LIST_LIB_TEST = ./test/lib_test 

.PHONY: init all doubly_linked_list_src doubly_linked_list_lib doubly_linked_list_no_lib_test doubly_linked_list_lib_test dist clean

init:
	@echo "Building the doubly linked list..." && $(MAKE) all	

#all:	doubly_linked_list_src doubly_linked_list_lib doubly_linked_list_no_lib_test doubly_linked_list_lib_test
all:	doubly_linked_list_src doubly_linked_list_no_lib_test

doubly_linked_list_src:
	@cd $(DOUBLY_LINKED_LIST_SRC) && $(MAKE)

doubly_linked_list_lib:
	@cd $(DOUBLY_LINKED_LIST_LIB) && $(MAKE)

doubly_linked_list_no_lib_test:
	@cd $(DOUBLY_LINKED_LIST_NO_LIB_TEST) && $(MAKE)

doubly_linked_list_lib_test:
	@cd $(DOUBLY_LINKED_LIST_LIB_TEST) && $(MAKE)

clean:
	@cd $(DOUBLY_LINKED_LIST_SRC) && $(MAKE) clean
	@cd $(DOUBLY_LINKED_LIST_LIB) && $(MAKE) clean
	@cd $(DOUBLY_LINKED_LIST_NO_LIB_TEST) && $(MAKE) clean
	@cd $(DOUBLY_LINKED_LIST_LIB_TEST) && $(MAKE) clean 