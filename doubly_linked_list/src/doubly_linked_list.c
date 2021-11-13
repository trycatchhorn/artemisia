#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/doubly_linked_list.h"

struct doubly_linked_list_element {
  void *data;
  struct doubly_linked_list_element *prev;
  struct doubly_linked_list_element *next;
};

struct doubly_linked_list {
  struct doubly_linked_list_element *head;
  struct doubly_linked_list_element *tail;
  size_t size;
};

/* Operations on elements/nodes in doubly linked list */

DoublyLinkedListElement* create_doubly_linked_list_element( void *data, size_t data_size ) {
  size_t off_set;
  DoublyLinkedListElement *new_element;
  new_element = malloc( sizeof( DoublyLinkedListElement ) );
  if ( NULL == new_element ) {
    return NULL;
  }
  else {
    new_element->data = malloc( data_size );
    if ( NULL == new_element->data ) {
      free( new_element );
      return NULL;
    }
    for ( off_set = 0; off_set < data_size; off_set++ ) {
      /* We need to cast to (char *), since arithmetic
       * on (void *) is not allowed when compiling with
       * the flag "-pedantic".
      */
      *( char * ) ( ( ( char * ) new_element->data ) + off_set ) = *( char * ) ( ( ( char * ) data ) + off_set );
    }
    new_element->prev = NULL;
    new_element->next = NULL;
    return new_element;
  }
}

void* get_data_doubly_linked_list_element( DoublyLinkedListElement *pelement ) {
  if ( NULL == pelement ) {
    return NULL;
  }
  return pelement->data;
}

DoublyLinkedListElement* get_previous_doubly_linked_list_element( DoublyLinkedListElement *pelement ) {
  if ( NULL == pelement ) {
    return NULL;
  }
  return pelement->prev;
}

DoublyLinkedListElement* get_next_doubly_linked_list_element( DoublyLinkedListElement *pelement ) {
  if ( NULL == pelement ) {
    return NULL;
  }
  return pelement->next;
}

/* Operations on doubly linked list */

DoublyLinkedList* create_doubly_linked_list() {
  DoublyLinkedList* list;
  list = malloc( sizeof( DoublyLinkedListElement ) );
  if ( NULL == list ) {
    return NULL;
  }
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

bool is_equal_doubly_linked_list( DoublyLinkedList *plist1, DoublyLinkedList *plist2, is_equal_doubly_linked_list_elements equal_func ) {
  DoublyLinkedListElement* current1;
  DoublyLinkedListElement* current2;
  if ( get_size_doubly_linked_list( plist1 ) != get_size_doubly_linked_list( plist2 ) ) {
    return false;
  }
  current1 = plist1->head;
  current2 = plist2->head;
  while ( current1 != NULL && current2 != NULL ) {
    if ( !equal_func( current1, current2 ) ) {
      return false;
    }
    current1 = current1->next;
    current2 = current2->next;
  }
  return true;
}

DoublyLinkedListElement* get_head_doubly_linked_list( DoublyLinkedList *plist ) {
  if ( plist == NULL ) {
    return NULL;
  }
  return plist->head;
}

DoublyLinkedListElement* get_tail_doubly_linked_list( DoublyLinkedList *plist ) {
  if ( plist == NULL ) {
    return NULL;
  }
  return plist->tail;
}

size_t get_size_doubly_linked_list( DoublyLinkedList *plist ) {
  if ( plist == NULL ) {
    return 0;
  }
  return plist->size;
}

DoublyLinkedListElement* get_element_at_doubly_linked_list( DoublyLinkedList *plist, int index ) {
  int count = 0;
  int min_index = 0;
  int max_index = get_size_doubly_linked_list( plist ) - 1;
  DoublyLinkedListElement *current = plist->head;
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

void print_doubly_linked_list_forward( DoublyLinkedList *plist, void (* print_elem )(void*) ) {
  int i;
  DoublyLinkedListElement *current;
  current = plist->head;
  if ( NULL == current ) {
    printf( "%s \n", "[ ]" );
    return;
  }
  else {
    printf( "%s", "[" );
    for ( i = 0; i < plist->size; ++i ) {
      (* print_elem )( current->data );
      if ( NULL != current->next && plist->tail != current ) {
        printf( "%s", " <-> " );
      }
      current = current->next;
    }
    printf( "%s \n", "]" );
  }
}

void print_doubly_linked_list_backward( DoublyLinkedList *plist, void (* print_elem )(void*) ) {
  int i;
  DoublyLinkedListElement *current;
  current = plist->tail;
  if ( NULL == current ) {
    printf( "%s \n", "[ ]" );
    return;
  }
  else {
    printf( "%s", "[" );
    for ( i = plist->size - 1; i >= 0; --i ) {
      (* print_elem )( current->data );
      if ( NULL != current->prev && plist->head != current ) {
        printf( "%s", " <-> " );
      }
      current = current->prev;
    }
    printf( "%s \n", "]" );
  }
}

DoublyLinkedList* shallow_copy_doubly_linked_list( DoublyLinkedList *plist, size_t data_size ) {
  DoublyLinkedListElement *current;
  DoublyLinkedList *list = create_doubly_linked_list();
  current = plist->head;
  while ( current != NULL ) {
    append_doubly_linked_list( list, current, data_size );
    current = current->next;
  }
  return list;
}

DoublyLinkedListElement* prepend_doubly_linked_list( DoublyLinkedList *plist, DoublyLinkedListElement *pelement, size_t data_size ) {
  size_t off_set;
  /* 1. allocate new element */
  DoublyLinkedListElement *new_element = malloc( sizeof ( DoublyLinkedListElement ) );
  if ( NULL == new_element || NULL == plist || NULL == pelement ) {
    return NULL;
  }
  /* 2. allocate data for new element */
  new_element->data = malloc( sizeof( data_size ) );
  /* 3. put data into new element */
  for ( off_set = 0; off_set < data_size; off_set++ ) {
    *( char * ) ( ( ( char * ) new_element->data ) + off_set ) = *( char * ) ( ( ( char * ) pelement->data ) + off_set );
  }
  /* 4. set 'prev' field of new element to NULL */
  new_element->prev = NULL;
  /* 5. handle things differently if the list is empty */
  if ( plist->size == 0 ) {
    /* 6. set 'head' pointer of list to new element */
    plist->head = new_element;
    /* 7. set 'tail' pointer of list to new element */
    plist->tail = new_element;
    /* 8. set 'next' field of new element to NULL */
    new_element->next = NULL;
  }
  /* 9. the list contains elements */
  else {
    /* 10. set 'next' field of new element to head of list */
    new_element->next = plist->head;
    /* 11. set 'prev' field of head element to new element */
    plist->head->prev = new_element;
    /* 12. set head of list to new element */
    plist->head = new_element;
  }
  /* 13. update size of list */
  ++plist->size;
  return new_element;
}

DoublyLinkedListElement* append_doubly_linked_list( DoublyLinkedList *plist, DoublyLinkedListElement *pelement, size_t data_size ) {
  size_t off_set;
  /* 1. allocate new element */
  DoublyLinkedListElement *new_element = malloc( sizeof ( DoublyLinkedListElement ) );
  if ( NULL == new_element || NULL == plist || NULL == pelement ) {
    return NULL;
  }
  /* 2. allocate data for new element */
  new_element->data = malloc( sizeof( data_size ) );
  /* 3. put data into new element */
  for ( off_set = 0; off_set < data_size; off_set++ ) {
    *( char * ) ( ( ( char * ) new_element->data ) + off_set ) = *( char * ) ( ( ( char * ) pelement->data ) + off_set );
  }
  /* 4. set 'next' field of new element to NULL */
  new_element->next = NULL;
  /* 5. handle things differently if the list is empty */
  if ( 0 == plist->size ) {
    /* 6. set 'head' pointer of list to new element */
    plist->head = new_element;
    /* 7. set 'tail' pointer of list to new element */
    plist->tail = new_element;
    /* 8. set 'prev' field of new element to NULL */
    new_element->prev = NULL;
  }
  /* 9. the list contains elements */
  else {
    /* 10. set 'prev' field of new element to tail of list */
    new_element->prev = plist->tail;
    /* 11. set 'next' field of tail element to new element */
    plist->tail->next = new_element;
    /* 12. set tail of list to new element */
    plist->tail = new_element;
  }
  /* 13. update size of list */
  ++plist->size;
  return new_element;
}

void remove_element_doubly_linked_list( DoublyLinkedList *plist, DoublyLinkedListElement *pelement, is_equal_doubly_linked_list_elements equal_func ) {
  DoublyLinkedListElement *tmp;
  DoublyLinkedListElement *previous = NULL;
  DoublyLinkedListElement *current = plist->head;

  while ( NULL != current ) {
    if ( equal_func( current, pelement ) ) {

      if ( plist->head == current ) {
        /* remove the head element */
        plist->head = current->next;
      }
      if ( plist->tail == current ) {
        /* remove the tail element */
        plist->tail = previous;
      }
      if ( NULL != previous ) {
        previous->next = current->next;
      }
      /* update 'size' field of doubly linked list */
      --plist->size;
      tmp = current;
      free( tmp->data );
      free( tmp );
      return;
    }
    previous = current;
    current = current->next;
  }
}

void remove_element_doubly_linked_list_better( DoublyLinkedList* plist, DoublyLinkedListElement* pelement, is_equal_doubly_linked_list_elements equal_func ) {
  DoublyLinkedListElement *temp = plist->head;
  /* deleting the head node */
  if ( temp != NULL && equal_func( temp, pelement ) ) {
    plist->head = temp->next;
    plist->head->prev = NULL;
    free( temp->data );
    free( temp );
    --plist->size;
    return;
  }
  while ( temp != NULL ) {
    /* deleting the tail node */
    if ( temp == plist->tail && equal_func( temp, pelement ) ) {
      plist->tail = temp->prev;
      plist->tail->next = NULL;
      free( temp->data );
      free( temp );
      temp = NULL;
      --plist->size;
      return;
    }
    if ( equal_func( temp, pelement ) ) {
      temp->prev->next = temp->next;
      temp->next->prev = temp->prev;
      free( temp->data );
      free( temp );
      temp = NULL;
      --plist->size;
      return;
    }
    temp = temp->next;
  }
}

void remove_all_doubly_linked_list( DoublyLinkedList* plist ) {
  DoublyLinkedListElement* head;
  DoublyLinkedListElement* tmp;
  if ( NULL == plist || !plist->size ) {
    return;
  }

  head = plist->head;
  while ( NULL != head ) {
    tmp = head->next;
    free( head->data );
    free( head );
    head = tmp;
    --plist->size;
    
  }
  plist->head = NULL;
  plist->tail = NULL;
  plist = NULL;
}

bool remove_element( DoublyLinkedList *plist, DoublyLinkedListElement *element ) {
  bool do_free = true;
  DoublyLinkedListElement *head_ref = plist->head;
  DoublyLinkedListElement *tail_ref = plist->tail;

  /* Base case - we do nothing */
  if ( NULL == head_ref || NULL == element ) {
    do_free = false;;
  }

  /* If element to be removed is the head element */
  if ( head_ref == element ) {
    plist->head = element->next;
  }

  /* If element to be removed is the tail element */
  if ( tail_ref == element ) {
    plist->tail = element->prev;
  }

  /* Change next field only if the element to be removed is NOT the last element */
  if ( NULL != element->next ) {
    element->next->prev = element->prev;
  }

  /* Change prev field only if the element to be removed is NOT the first element */
  if ( NULL != element->prev ) {
    element->prev->next = element->next;
  }

  if (do_free) {
    /* Free the memory occupied by element data */
    free( element->data );

    /* Free the element */
    free( element );
    element = NULL;
  }
  return do_free;
}

bool remove_element_at_doubly_linked_list( DoublyLinkedList *plist, int index ) {
  int i;
  int min_index = 0;
  int max_index = get_size_doubly_linked_list( plist );
  bool was_removed = false;
  bool do_remove = true;

  /* Store head element - index 0 */
  DoublyLinkedListElement *current = plist->head;

  if ( NULL == plist ) {
    do_remove = false;
  }

  /* Make sure we are searching within range of list */
  if ( index < min_index || index > max_index ) {
    do_remove = false;
  }

  /* Find previous node of the node to be removed */
  for( i = 0; current != NULL && i < index; i++ ) {
    current = current->next;
  }

  if ( NULL == current ) {
    do_remove = false;
  }

  if ( do_remove ) {
    was_removed = remove_element( plist, current );
    if ( was_removed ) {
      --plist->size;
    }
  }
  return was_removed;
}

void traverse( DoublyLinkedList *plist, element_operation do_func ) {
  int i;
  DoublyLinkedListElement *current = plist->head;
  for ( i = 0; i < plist->size; i++ ) {
    do_func( current->data );
    current = current->next;
  }
}

