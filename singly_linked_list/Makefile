#
# Master makefile for building the singly linked list project.
#
# Targets:
#
# singly_linked_list_src: builds the linkedlist object file.
# singly_linked_list_lib: builds a static link library including the linkedlist API.
# singly_linked_list_no_lib_test: builds an executable testing the linkedlist source.
# singly_linked_list_lib_test: builds an executable testing the static link library.
#

SINGLY_LINKED_LIST_SRC = ./src
SINGLY_LINKED_LIST_LIB = ./lib
SINGLY_LINKED_LIST_NO_LIB_TEST = ./test/no_lib_test
SINGLY_LINKED_LIST_LIB_TEST = ./test/lib_test 

.PHONY: init all singly_linked_list_src singly_linked_list_lib singly_linked_list_no_lib_test singly_linked_list_lib_test dist clean

init:
	@echo "Building the singly linked list..." && $(MAKE) all	

all:	singly_linked_list_src singly_linked_list_lib singly_linked_list_no_lib_test singly_linked_list_lib_test

singly_linked_list_src:
	@cd $(SINGLY_LINKED_LIST_SRC) && $(MAKE)

singly_linked_list_lib:
	@cd $(SINGLY_LINKED_LIST_LIB) && $(MAKE)

singly_linked_list_no_lib_test:
	@cd $(SINGLY_LINKED_LIST_NO_LIB_TEST) && $(MAKE)

singly_linked_list_lib_test:
	@cd $(SINGLY_LINKED_LIST_LIB_TEST) && $(MAKE)

clean:
	@cd $(SINGLY_LINKED_LIST_SRC) && $(MAKE) clean
	@cd $(SINGLY_LINKED_LIST_LIB) && $(MAKE) clean
	@cd $(SINGLY_LINKED_LIST_NO_LIB_TEST) && $(MAKE) clean
	@cd $(SINGLY_LINKED_LIST_LIB_TEST) && $(MAKE) clean 