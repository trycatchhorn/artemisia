#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

/*** Header file for the SinglyLinkedList implementation ***/

/*
 *   Brian Horn - trycatchhorn@gmail.com
 */

/*** Definitions of stucture types ***/

/* The structure type for elements in the singly linked list.
 *
 * data         - the data in the singly linked list (here data is int).
 * next         - pointer to the next element in the singly linked list.
 *
 */
typedef struct singly_linked_list_element SinglyLinkedListElement;

/* The structure type for a singly linked list.
 *
 * head         - pointer to the head of the linked list.
 * tail         - pointer to the tail of the linked list.
 *
 */
typedef struct singly_linked_list SinglyLinkedList;

/*** Function prototypes for SinglyLinkedListElement ***/

/** create_singly_linked_list_element() - create a new singly
 *  linked list element and a returns a pointer to the created
 *  element.
 */
SinglyLinkedListElement* create_singly_linked_list_element( int data );

/** get_data_singly_linked_list_element - returns the data contained
 *  in the singly linked list element structure.
 */
int get_data_singly_linked_list_element();

/** print_singly_linked_list_element() - prints the specified singly
 *  linked list element to standard output.
 */
void print_singly_linked_list_element( SinglyLinkedListElement* pelement );

/*** Function prototypes for SinglyLinkedList ***/

/** create_singly_linked_list() - creates a new singly linked list
 *  and returns a pointer to the created list.
 */
SinglyLinkedList* create_singly_linked_list();

/** get_size_singly_linked_list() - returns the size of the singly
 *  linked list by counting the number of elements in the list.
 */
int get_size_singly_linked_list( SinglyLinkedList* plist );

/** get_head_singly_linked_list() - returns a pointer to the head
 *  element of the specified singly linked list.
 */
SinglyLinkedListElement* get_head_singly_linked_list( SinglyLinkedList* plist );

/** get_tail_singly_linked_list() - returns a pointer to the tail
 *  element of the specified singly linked list.
 */
SinglyLinkedListElement* get_tail_singly_linked_list( SinglyLinkedList* plist );

/** get_element_at_singly_linked_list() - returns a pointer to the
 *  element at the specified index in the specified singly linked list.
 */
SinglyLinkedListElement* get_element_at_singly_linked_list( SinglyLinkedList* plist, int index );

/** print_singly_linked_list() - print the content of the specified
 *  singly linked list to standard output.
 */
void print_singly_linked_list( SinglyLinkedList* plist );

/** is_equal_singly_linked_list() - compares the two specified singly
 *  linked lists for equality. If the two lists are equal true is
 *  return otherwise false is returned.
 */
int is_equal_singly_linked_list( SinglyLinkedList* plist1, SinglyLinkedList* plist2 );

/** shallow_copy_singly_linked_list() - performs a shallow copy of the specified
 *  singly linked list, where all elements in the specified list are copied to
 *  a new singly linked list, which is returned.
 */
SinglyLinkedList* shallow_copy_singly_linked_list( SinglyLinkedList* plist );

/** prepend_singly_linked_list() - inserts the specified element into the
 *  specified singly linked list. The element is inserted in front of the
 *  singly_linked_list.
 */
SinglyLinkedListElement* prepend_singly_linked_list( SinglyLinkedList* plist, SinglyLinkedListElement* pelement );

/** append_singly_linked_list() - inserts the specified element into the
 *  specified singly linked list. The element is inserted in the back of
 *  the singly_linked_list.
 */
SinglyLinkedListElement* append_singly_linked_list( SinglyLinkedList* plist, SinglyLinkedListElement* pelement );

/** remove_singly_linked_list() - removes, if present, the specified element
 *  from the specified singly linked list.
 */
void remove_singly_linked_list( SinglyLinkedList* plist, SinglyLinkedListElement* pelement );

void delete_node( SinglyLinkedList* plist, SinglyLinkedListElement* pelement );

/** remove_all_singly_linked_list() - removes all elements contained in
 *  the specified singly linked list, making the list empty after the
 *  operation.
 */
void remove_all_singly_linked_list( SinglyLinkedList* plist );

#endif


