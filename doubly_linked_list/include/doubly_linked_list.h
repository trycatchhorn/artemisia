#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdbool.h>

typedef struct doubly_linked_list_element DoublyLinkedListElement;

typedef struct doubly_linked_list DoublyLinkedList;

typedef bool ( * is_equal_doubly_linked_list_elements ) ( DoublyLinkedListElement * elem1, DoublyLinkedListElement * elem2 );


DoublyLinkedListElement* create_doubly_linked_list_element( void *data, size_t data_size );

bool is_equal_doubly_linked_list( DoublyLinkedList *plist1, DoublyLinkedList *plist2, is_equal_doubly_linked_list_elements equal_func );





void* get_data_doubly_linked_list_element();

DoublyLinkedListElement* get_previous_doubly_linked_list_element();

DoublyLinkedListElement* get_next_doubly_linked_list_element();

DoublyLinkedList* create_doubly_linked_list();

size_t get_size_doubly_linked_list( DoublyLinkedList *plist );

DoublyLinkedListElement* get_head_doubly_linked_list( DoublyLinkedList *plist );

DoublyLinkedListElement* get_tail_doubly_linked_list( DoublyLinkedList *plist );

DoublyLinkedListElement* get_element_at_doubly_linked_list( DoublyLinkedList *plist, int index );


void print_doubly_linked_list_forward( DoublyLinkedList *plist, void ( * print_elem ) ( void * ) );

void print_doubly_linked_list_backward( DoublyLinkedList *plist, void ( * print_elem ) ( void * ) );

DoublyLinkedList* shallow_copy_doubly_linked_list( DoublyLinkedList *plist, size_t data_size );

int prepend_doubly_linked_list( DoublyLinkedList *plist, DoublyLinkedListElement *pelement, size_t data_size );

int append_doubly_linked_list( DoublyLinkedList *plist, DoublyLinkedListElement *pelement, size_t data_size );


void remove_element_doubly_linked_list( DoublyLinkedList* plist, DoublyLinkedListElement* pelement, is_equal_doubly_linked_list_elements equal_func );

void remove_element_at_doubly_linked_list( DoublyLinkedList *plist, int index );

#endif
