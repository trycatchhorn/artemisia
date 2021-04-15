#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

void print_int( void *int_val ) {
  printf( "%d", *( int * ) int_val );
}

int main() {
  int i1 = 1;
  int i2 = 2;
  int i3 = 3;
  DoublyLinkedListElement *e1 = create_doubly_linked_list_element( &i1, sizeof( int ) );
  DoublyLinkedListElement *e2 = create_doubly_linked_list_element( &i2, sizeof( int ) );
  DoublyLinkedListElement *e3 = create_doubly_linked_list_element( &i3, sizeof( int ) );
  DoublyLinkedList *list = create_doubly_linked_list();

  append_doubly_linked_list( list, e1, sizeof( int ) );
  append_doubly_linked_list( list, e2, sizeof( int ) );
  append_doubly_linked_list( list, e3, sizeof( int ) );
  
  print_doubly_linked_list_forward( list, print_int );

  free( e1 );
  free( e2 );
  free( e3 );
  free( list );
  return 0;
}
