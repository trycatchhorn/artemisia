#
# Master makefile for building the artemesia project.
#
# Targets:
#
# singly_linked_list_project: builds the singly linked list project.
# stack_project: builds the stack project.
#

SINGLY_LINKED_LIST_DIR = ./singly_linked_list
STACK_DIR = ./stack

all:	singly_linked_list_project stack_project

singly_linked_list_project:
	@cd $(SINGLY_LINKED_LIST_DIR) && $(MAKE)

stack_project:
	@cd $(STACK_DIR) && $(MAKE)

clean:
	@cd $(SINGLY_LINKED_LIST_DIR) && $(MAKE) clean
	@cd $(STACK_DIR) && $(MAKE) clean
