#
# Master makefile for building the artemesia project.
#
# Targets:
#
# singly_linked_list_project: builds the singly linked list project.
# stack_project: builds the stack project.
#

DOUBLY_LINKED_LIST_DIR = ./doubly_linked_list
SINGLY_LINKED_LIST_DIR = ./singly_linked_list
STACK_DIR = ./stack

all:	doubly_linked_list_project singly_linked_list_project stack_project 

doubly_linked_list_project:
	@cd $(DOUBLY_LINKED_LIST_DIR) && $(MAKE)

singly_linked_list_project:
	@cd $(SINGLY_LINKED_LIST_DIR) && $(MAKE)

stack_project:
	@cd $(STACK_DIR) && $(MAKE)

clean:
	@cd $(DOUBLY_LINKED_LIST_DIR) && $(MAKE) clean
	@cd $(SINGLY_LINKED_LIST_DIR) && $(MAKE) clean
	@cd $(STACK_DIR) && $(MAKE) clean
