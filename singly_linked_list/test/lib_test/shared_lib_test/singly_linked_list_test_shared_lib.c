#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"

int main() {
  SinglyLinkedList* list = create_singly_linked_list();
  SinglyLinkedListElement* e1 = create_singly_linked_list_element( 1 );
  SinglyLinkedListElement* e2 = create_singly_linked_list_element( 2 );
  SinglyLinkedListElement* e3 = create_singly_linked_list_element( 3 );
  append_singly_linked_list( list, e1 );
  append_singly_linked_list( list, e2 );
  append_singly_linked_list( list, e3 );
  print_singly_linked_list( list );
  free( e1 );
  free( e2 );
  free( e3 );
  free( list );
  return 0;
}
