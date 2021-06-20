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
  SinglyLinkedListElement* prev = NULL;
  SinglyLinkedListElement* copy = NULL;
  SinglyLinkedListElement* head = NULL;
  SinglyLinkedList* list_copy = create_singly_linked_list();
  if ( !list_copy ) {
    return NULL;
  }
  
  head = plist->head;
    
  while ( head != NULL ) {
    copy = create_singly_linked_list_element( head->data );
    
    if ( !copy ) {
      free( copy );
    }

    if (prev == NULL) {
      prev = copy;
      list_copy->head = prev;
    }
    else {
      prev->next = copy;
      prev = prev->next;
    }

    head = head->next;
  }

  return list_copy;
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

void remove_element_singly_linked_list( SinglyLinkedList* plist, SinglyLinkedListElement* pelement ) {
  SinglyLinkedListElement *temp = plist->head;
  SinglyLinkedListElement *prev = temp;
  
  if ( temp != NULL && temp->data == pelement->data ) {
    /* deleting the head node */
    plist->head = temp->next;
    free( temp );
  }
  else {
    while ( temp != NULL ) {
      if ( temp->data == pelement->data ) {
	if ( temp == plist->tail ) {
	  plist->tail = prev;
	}
	prev->next = temp->next;
	free( temp );
	temp = NULL;
      }
      else {
	prev = temp;
	temp = temp->next;
      }
    }
  }
}

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
  plist = NULL;
}

