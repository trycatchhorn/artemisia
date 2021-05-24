#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/singly_linked_list.h"

struct singly_linked_list_element {
  int data;
  struct singly_linked_list_element *next;
};

struct singly_linked_list {
  struct singly_linked_list_element *head;
  struct singly_linked_list_element *tail;
};

SinglyLinkedListElement* create_singly_linked_list_element( int data ) {
  SinglyLinkedListElement* new_element = ( SinglyLinkedListElement* ) malloc( sizeof( SinglyLinkedListElement ) );
  if ( NULL == new_element ) {
    return NULL;
  }
  else {
    new_element->data = data;
    new_element->next = NULL;
    return new_element;
  }
}

int get_data_singly_linked_list_element( SinglyLinkedListElement* pelement ) {
  return pelement->data;
}

SinglyLinkedList* create_singly_linked_list() {
  SinglyLinkedList* list;
  list = ( SinglyLinkedList* ) malloc( sizeof( SinglyLinkedListElement ) );
  if ( NULL == list ) {
    return NULL;
  }
  list->head = NULL;
  list->tail = NULL;
  return list;
}

int get_size_singly_linked_list( SinglyLinkedList* plist ) {
  int count = 0;
  SinglyLinkedListElement* current = plist->head;
  while ( NULL != current ) {
    current = current->next;
    ++count;
  }
  return count;
}

SinglyLinkedListElement* get_head_singly_linked_list( SinglyLinkedList* plist ) {
  return plist->head;
}

SinglyLinkedListElement* get_tail_singly_linked_list( SinglyLinkedList* plist ) {
  return plist->tail;
}

SinglyLinkedListElement* get_element_at_singly_linked_list( SinglyLinkedList* plist, int index ) {
  int count = 0;
  int min_index = 0;
  int max_index = get_size_singly_linked_list( plist ) - 1;
  SinglyLinkedListElement* current = plist->head;
  if ( NULL == plist ) {
    return NULL;
  }
  if ( index < min_index || index > max_index ) {
    return NULL;
  }
  while ( NULL != current ) {
    if ( count == index ) {
      return current;
    }
    current = current->next;
    ++count;
  }
  return current;
}

void print_singly_linked_list_element( SinglyLinkedListElement* pelement ) {
  if ( NULL != pelement->next ) {
    printf( "%d %s", pelement->data, " -> " );
  }
  else {
    printf( "%d", pelement->data );
  }
}

void print_singly_linked_list( SinglyLinkedList* plist ) {
  SinglyLinkedListElement* current = plist->head;
  if ( NULL == current ) {
    printf( "[ ]\n" );
    return;
  }
  else {
    printf( "[" );
    while ( current != NULL) {
      print_singly_linked_list_element( current );
      current = current->next;
    }
    printf( "]\n" );
  }
}

int is_equal_singly_linked_list( SinglyLinkedList* plist1, SinglyLinkedList* plist2 ) {
  SinglyLinkedListElement* current1;
  SinglyLinkedListElement* current2;
  if ( get_size_singly_linked_list( plist1 ) != get_size_singly_linked_list( plist2 ) ) {
    return -1;
  }
  current1 = plist1->head;
  current2 = plist2->head;
  while ( current1 != NULL && current2 != NULL ) {
    if ( current1->data != current2->data ) {
      return -1;
    }
    current1 = current1->next;
    current2 = current2->next;
  }
  return 1;
}

SinglyLinkedList* shallow_copy_singly_linked_list( SinglyLinkedList* plist ) {
  SinglyLinkedListElement* current;
  SinglyLinkedList* list = create_singly_linked_list();
  current = plist->head;
  while ( current != NULL ) {
    append_singly_linked_list( list, current );
    current = current->next;
  }
  return list;
}

SinglyLinkedListElement* prepend_singly_linked_list( SinglyLinkedList* plist, SinglyLinkedListElement* pelement ) {
  SinglyLinkedListElement* new_node = ( SinglyLinkedListElement* ) malloc( sizeof ( SinglyLinkedListElement ) );
  if ( NULL == new_node || NULL == plist || NULL == pelement ) {
    return NULL;
  }
  new_node->data = pelement->data;
  new_node->next = plist->head;
  plist->head = new_node;
  if ( NULL == plist->tail ) {
    plist->tail = new_node;
  }
  return new_node;
}

SinglyLinkedListElement* append_singly_linked_list( SinglyLinkedList* plist, SinglyLinkedListElement* pelement ) {
  SinglyLinkedListElement* new_node = ( SinglyLinkedListElement* ) malloc( sizeof ( SinglyLinkedListElement ) );
  if ( NULL == new_node || NULL == plist || NULL == pelement ) {
    return NULL;
  }
  new_node->data = pelement->data;
  new_node->next = NULL;
  if ( plist->head == NULL ) {
    plist->head = plist->tail = new_node;
  }
  else {
    plist->tail->next = new_node;
    plist->tail = new_node;
  }
  return new_node;
}

void remove_singly_linked_list( SinglyLinkedList* plist, SinglyLinkedListElement* pelement ) {
  SinglyLinkedListElement* previous = NULL;
  SinglyLinkedListElement* current = plist->head;

  while ( NULL != current ) {
    if ( current->data == pelement->data ) {
      if ( plist->head == current ) {
        plist->head = current->next;
      }
      if ( plist->tail == current ) {
        plist->tail = previous;
      }
      if ( NULL != previous ) {
        previous->next = current->next;
      }
      free( current );
      return;
    }
    previous = current;
    current = current->next;
  }
}

void delete_node( SinglyLinkedList* plist, SinglyLinkedListElement* pelement ) {
  /* 
     see: for fixing mem leaks in linked list:

     https://github.com/vivekbhadra/misc/blob/master/linked_list_no_mleak.c
     https://techfortalk.co.uk/2018/01/30/how-to-detect-memory-leak-in-c-program-using-valgrind/

   */
  int a;
  int b;
  int c;
  SinglyLinkedListElement* tmp;
  SinglyLinkedListElement* prev  = NULL;
  SinglyLinkedListElement* phead = plist->head;
  tmp = phead;
  printf( "::0::\n" );
  printf( "::1::\n" );
  a = 100;
  printf( "a: %d\n", a );
  b = phead->data;
  printf( "b: %d\n", b );
  c = pelement->data;
  printf( "c: %d\n", c );

  if ( phead != NULL && phead->data == pelement->data ) {
    phead = tmp->next;
    plist->head = phead;
    free( tmp );
    return;
  }
  
  while ( ( phead ) && ( phead->data != pelement->data ) ) {
    printf( "::2::\n" );
    prev = phead;
    printf( "::3::\n" );
    phead = phead->next;
    printf( "::4::\n" );
  }
  printf( "::5::\n" );
  prev->next = phead->next;
  printf( "::6::\n" );
  free( phead );
  printf( "::7::\n" );
  return;
}

/*
void deleteNode(struct Node** head_ref, int key)
{
    // Store head node
    struct Node *temp = *head_ref, *prev;
 
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changed head
        free(temp); // free old head
        return;
    }
 
    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
    
    free(temp); // Free memory
}
*/


void remove_all_singly_linked_list( SinglyLinkedList* plist ) {
  SinglyLinkedListElement* head = plist->head;
  SinglyLinkedListElement* tmp;
  while ( NULL != head ) {
    tmp = head->next;
    free( head );
    head = tmp;
  }

  plist->head = NULL;
  plist->tail = NULL;
  /*  free( plist ); */
  plist = NULL;
}

