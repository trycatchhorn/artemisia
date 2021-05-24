#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "singly_linked_list.h"

int test_create_singly_linked_list() {
  SinglyLinkedList* list = create_singly_linked_list();
  if ( NULL == list ) {
    return -1;
  }
  free( list );
  return 0;
}

int test_get_head_singly_linked_list() {
  SinglyLinkedListElement* res;
  int result = 0;
  SinglyLinkedListElement* e1 = create_singly_linked_list_element( 1 );
  SinglyLinkedListElement* e2 = create_singly_linked_list_element( 2 );
  SinglyLinkedListElement* e3 = create_singly_linked_list_element( 3 );
  SinglyLinkedList* list = create_singly_linked_list();
  SinglyLinkedListElement* r1 = append_singly_linked_list( list, e1 );
  SinglyLinkedListElement* r2 = append_singly_linked_list( list, e2 );
  SinglyLinkedListElement* r3 = append_singly_linked_list( list, e3 );
  res = get_head_singly_linked_list( list );
  if ( get_data_singly_linked_list_element( e1 ) != get_data_singly_linked_list_element( res ) ) {
    result = -1;
  }
  free( e1 );
  free( e2 );
  free( e3 );
  free( r1 );
  free( r2 );
  free( r3 );
  free( list );
  return result;
}

int test_get_tail_singly_linked_list() {
  SinglyLinkedListElement* res;
  int result = 0;
  SinglyLinkedListElement* e1 = create_singly_linked_list_element( 1 );
  SinglyLinkedListElement* e2 = create_singly_linked_list_element( 2 );
  SinglyLinkedListElement* e3 = create_singly_linked_list_element( 3 );
  SinglyLinkedList* list = create_singly_linked_list();
  SinglyLinkedListElement* r1 = append_singly_linked_list( list, e1 );
  SinglyLinkedListElement* r2 = append_singly_linked_list( list, e2 );
  SinglyLinkedListElement* r3 = append_singly_linked_list( list, e3 );
  res = get_tail_singly_linked_list( list );
  if ( get_data_singly_linked_list_element( e3 ) != get_data_singly_linked_list_element( res ) ) {
    result = -1;
  }
  free( e1 );
  free( e2 );
  free( e3 );
  free( r1 );
  free( r2 );
  free( r3 );
  free( list );
  return result;
}

int test_get_element_at_singly_linked_list() {
  SinglyLinkedListElement* res1;
  SinglyLinkedListElement* res2;
  SinglyLinkedListElement* res3;
  int result = 0;
  SinglyLinkedListElement* e1 = create_singly_linked_list_element( 1 );
  SinglyLinkedListElement* e2 = create_singly_linked_list_element( 2 );
  SinglyLinkedListElement* e3 = create_singly_linked_list_element( 3 );
  SinglyLinkedList* list = create_singly_linked_list();
  SinglyLinkedListElement* r1 = append_singly_linked_list( list, e1 );
  SinglyLinkedListElement* r2 = append_singly_linked_list( list, e2 );
  SinglyLinkedListElement* r3 = append_singly_linked_list( list, e3 );
  res1 = get_element_at_singly_linked_list( list, 0 );
  if ( get_data_singly_linked_list_element( res1 ) != get_data_singly_linked_list_element( e1 ) ) {
    result = -1;
  }
  res2 = get_element_at_singly_linked_list( list, 1 );
  if ( get_data_singly_linked_list_element( res2 ) != get_data_singly_linked_list_element( e2 ) ) {
    result = -1;
  }
  res3 = get_element_at_singly_linked_list( list, 2 );
  if ( get_data_singly_linked_list_element( res3 ) != get_data_singly_linked_list_element( e3 ) ) {
    result = -1;
  }
  free( e1 );
  free( e2 );
  free( e3 );
  free( r1 );
  free( r2 );
  free( r3 );
  free( list );
  return result;
}

int test_is_equal_singly_linked_list() {
  int result = 0;
  SinglyLinkedListElement* a1 = create_singly_linked_list_element( 1 );
  SinglyLinkedListElement* a2 = create_singly_linked_list_element( 2 );
  SinglyLinkedListElement* a3 = create_singly_linked_list_element( 3 );
  SinglyLinkedListElement* b1 = create_singly_linked_list_element( 1 );
  SinglyLinkedListElement* b2 = create_singly_linked_list_element( 2 );
  SinglyLinkedListElement* b3 = create_singly_linked_list_element( 3 );
  SinglyLinkedList* list1 = create_singly_linked_list();
  SinglyLinkedList* list2 = create_singly_linked_list();
  SinglyLinkedListElement* ra1 = append_singly_linked_list( list1, a1 );
  SinglyLinkedListElement* ra2 = append_singly_linked_list( list1, a2 );
  SinglyLinkedListElement* ra3 = append_singly_linked_list( list1, a3 );
  SinglyLinkedListElement* rb1 = append_singly_linked_list( list2, b1 );
  SinglyLinkedListElement* rb2 = append_singly_linked_list( list2, b2 );
  SinglyLinkedListElement* rb3 = append_singly_linked_list( list2, b3 );
  if ( is_equal_singly_linked_list( list1, list2 ) == -1 ) {
    result = -1;
  }
  free( a1 );
  free( a2 );
  free( a3 );
  free( b1 );
  free( b2 );
  free( b3 );
  free( ra1 );
  free( ra2 );
  free( ra3 );
  free( rb1 );
  free( rb2 );
  free( rb3 );
  free( list1 );
  free( list2 );
  return result;
}

int test_shallow_copy_singly_linked_list() {
  SinglyLinkedList* list_copy;
  int result = 0;
  SinglyLinkedListElement* a1 = create_singly_linked_list_element( 1 );
  SinglyLinkedListElement* a2 = create_singly_linked_list_element( 2 );
  SinglyLinkedListElement* a3 = create_singly_linked_list_element( 3 );
  SinglyLinkedList* list = create_singly_linked_list();
  SinglyLinkedListElement* r1 = append_singly_linked_list( list, a1 );
  SinglyLinkedListElement* r2 = append_singly_linked_list( list, a2 );
  SinglyLinkedListElement* r3 = append_singly_linked_list( list, a3 );
  list_copy = shallow_copy_singly_linked_list( list );
  if ( is_equal_singly_linked_list( list, list_copy ) == -1 ) {
    result = -1;
  }
  free( a1 );
  free( a2 );
  free( a3 );
  free( r1 );
  free( r2 );
  free( r3 );
  free( list );
  free( list_copy );
  return result;
}

int test_prepend_singly_linked_list() {
  int result = 0;
  SinglyLinkedListElement* e1 = create_singly_linked_list_element( 1 );
  SinglyLinkedListElement* e2 = create_singly_linked_list_element( 2 );
  SinglyLinkedListElement* e3 = create_singly_linked_list_element( 3 );
  SinglyLinkedList* list = create_singly_linked_list();
  SinglyLinkedListElement* r1 = prepend_singly_linked_list( list, e3 );
  SinglyLinkedListElement* r2 = prepend_singly_linked_list( list, e2 );
  SinglyLinkedListElement* r3 = prepend_singly_linked_list( list, e1 );
  if ( get_size_singly_linked_list( list ) != 3 ) {
    result = -1;
  }
  free( e1 );
  free( e2 );
  free( e3 );
  free( r1 );
  free( r2 );
  free( r3 );
  free( list );
  return result;
}

int test_append_singly_linked_list() {
  int result = 0;
  SinglyLinkedListElement* e1 = create_singly_linked_list_element( 1 );
  SinglyLinkedListElement* e2 = create_singly_linked_list_element( 2 );
  SinglyLinkedListElement* e3 = create_singly_linked_list_element( 3 );
  SinglyLinkedList* list = create_singly_linked_list();
  SinglyLinkedListElement* r1 = append_singly_linked_list( list, e1 );
  SinglyLinkedListElement* r2 = append_singly_linked_list( list, e2 );
  SinglyLinkedListElement* r3 = append_singly_linked_list( list, e3 );
  if ( get_size_singly_linked_list( list ) != 3 ) {
    result = -1;
  }
  free( e1 );
  free( e2 );
  free( e3 );
  free( r1 );
  free( r2 );
  free( r3 );
  free( list );
  return result;
}

/**
 *
 Before remove:
      _____________      _____________      _____________      _____________      _____________
     |      |      |    |      |      |    |      |      |    |      |      |    |      |      |
o--->|  21  |      |--->|  32  |      |--->|  16  |      |--->|  12  |      |--->|  14  |      |---o
     |______|______|    |______|______|    |______|______|    |______|______|    |______|______|

 After remove:
      _____________      _____________      _____________      _____________
     |      |      |    |      |      |    |      |      |    |      |      |
o--->|  32  |      |--->|  16  |      |--->|  12  |      |--->|  14  |      |---o
     |______|______|    |______|______|    |______|______|    |______|______|
*/

int test_remove_head_singly_linked_list() {
  int result = 0;
  SinglyLinkedListElement* new_head;
  SinglyLinkedListElement* e1 = create_singly_linked_list_element( 21 );
  SinglyLinkedListElement* e2 = create_singly_linked_list_element( 32 );
  SinglyLinkedListElement* e3 = create_singly_linked_list_element( 16 );
  SinglyLinkedListElement* e4 = create_singly_linked_list_element( 12 );
  SinglyLinkedListElement* e5 = create_singly_linked_list_element( 14 );
  SinglyLinkedList* list = create_singly_linked_list();
  SinglyLinkedListElement* r1 = append_singly_linked_list( list, e1 );
  SinglyLinkedListElement* r2 = append_singly_linked_list( list, e2 );
  SinglyLinkedListElement* r3 = append_singly_linked_list( list, e3 );
  SinglyLinkedListElement* r4 = append_singly_linked_list( list, e4 );
  SinglyLinkedListElement* r5 = append_singly_linked_list( list, e5 );
  remove_element_singly_linked_list( list, e1 );
  new_head = get_head_singly_linked_list( list );
  if ( get_data_singly_linked_list_element( new_head ) != get_data_singly_linked_list_element( e2 ) ) {
    result = -1;
  }
  if ( -1 == result ) {
    free( r1 );
  }
  free( e1);
  free( e2 );
  free( e3 );
  free( e4 );
  free( e5 );
  free( r2 );
  free( r3 );
  free( r4 );
  free( r5 );
  free( list );
  return result;
}

/**
 *
 Before remove:
      _____________      _____________      _____________      _____________      _____________
     |      |      |    |      |      |    |      |      |    |      |      |    |      |      |
o--->|  21  |      |--->|  32  |      |--->|  16  |      |--->|  12  |      |--->|  14  |      |---o
     |______|______|    |______|______|    |______|______|    |______|______|    |______|______|

 After remove:
      _____________      _____________      _____________      _____________
     |      |      |    |      |      |    |      |      |    |      |      |
o--->|  21  |      |--->|  32  |      |--->|  12  |      |--->|  14  |      |---o
     |______|______|    |______|______|    |______|______|    |______|______|
*/

int test_remove_middle_singly_linked_list() {
  int result = 0;
  SinglyLinkedListElement* e1 = create_singly_linked_list_element( 21 );
  SinglyLinkedListElement* e2 = create_singly_linked_list_element( 32 );
  SinglyLinkedListElement* e3 = create_singly_linked_list_element( 16 );
  SinglyLinkedListElement* e4 = create_singly_linked_list_element( 12 );
  SinglyLinkedListElement* e5 = create_singly_linked_list_element( 14 );
  SinglyLinkedList* list = create_singly_linked_list();
  SinglyLinkedListElement* r1 = append_singly_linked_list( list, e1 );
  SinglyLinkedListElement* r2 = append_singly_linked_list( list, e2 );
  SinglyLinkedListElement* r3 = append_singly_linked_list( list, e3 );
  SinglyLinkedListElement* r4 = append_singly_linked_list( list, e4 );
  SinglyLinkedListElement* r5 = append_singly_linked_list( list, e5 );
  remove_element_singly_linked_list( list, e3 );
  if ( get_size_singly_linked_list( list ) != 4 ) {
    result = -1;
  }
  if ( -1 == result ) {
    free( r3 );
  }
  free( e1 );
  free( e2 );
  free( e3 );
  free( e4 );
  free( e5 );
  free( r1 );
  free( r2 );
  free( r4 );
  free( r5 );
  free( list );
  return result;
}

/**
 *
 Before remove:
      _____________      _____________      _____________      _____________      _____________
     |      |      |    |      |      |    |      |      |    |      |      |    |      |      |
o--->|  21  |      |--->|  32  |      |--->|  16  |      |--->|  12  |      |--->|  14  |      |---o
     |______|______|    |______|______|    |______|______|    |______|______|    |______|______|

 After remove:
      _____________      _____________      _____________      _____________
     |      |      |    |      |      |    |      |      |    |      |      |
o--->|  21  |      |--->|  32  |      |--->|  16  |      |--->|  12  |      |---o
     |______|______|    |______|______|    |______|______|    |______|______|
*/

int test_remove_tail_singly_linked_list() {
  int result = 0;
  SinglyLinkedListElement* new_tail;
  SinglyLinkedListElement* e1 = create_singly_linked_list_element( 21 );
  SinglyLinkedListElement* e2 = create_singly_linked_list_element( 32 );
  SinglyLinkedListElement* e3 = create_singly_linked_list_element( 16 );
  SinglyLinkedListElement* e4 = create_singly_linked_list_element( 12 );
  SinglyLinkedListElement* e5 = create_singly_linked_list_element( 14 );
  SinglyLinkedList* list = create_singly_linked_list();
  SinglyLinkedListElement* r1 = append_singly_linked_list( list, e1 );
  SinglyLinkedListElement* r2 = append_singly_linked_list( list, e2 );
  SinglyLinkedListElement* r3 = append_singly_linked_list( list, e3 );
  SinglyLinkedListElement* r4 = append_singly_linked_list( list, e4 );
  SinglyLinkedListElement* r5 = append_singly_linked_list( list, e5 );
  remove_element_singly_linked_list( list, e5 );
  new_tail = get_tail_singly_linked_list( list );
  if ( get_data_singly_linked_list_element( new_tail ) != get_data_singly_linked_list_element( e4 ) ) {
    result = -1;
  }
  if ( -1 == result ) {
    free( r5 );
  }
  free( e1 );
  free( e2 );
  free( e3 );
  free( e4 );
  free( e5 );
  free( r1 );
  free( r2 );
  free( r3 );
  free( r4 );
  free( list );
  return result;
}

/**
 *
 Before remove:
      _____________      _____________      _____________      _____________      _____________
     |      |      |    |      |      |    |      |      |    |      |      |    |      |      |
o--->|  21  |      |--->|  32  |      |--->|  16  |      |--->|  12  |      |--->|  14  |      |---o
     |______|______|    |______|______|    |______|______|    |______|______|    |______|______|

 After remove:
      _____________      _____________      _____________      _____________      _____________
     |      |      |    |      |      |    |      |      |    |      |      |    |      |      |
o--->|  21  |      |--->|  32  |      |--->|  16  |      |--->|  12  |      |--->|  14  |      |---o
     |______|______|    |______|______|    |______|______|    |______|______|    |______|______|
*/

int test_remove_none_singly_linked_list() {
  int result = 0;
  SinglyLinkedListElement* e1 = create_singly_linked_list_element( 21 );
  SinglyLinkedListElement* e2 = create_singly_linked_list_element( 32 );
  SinglyLinkedListElement* e3 = create_singly_linked_list_element( 16 );
  SinglyLinkedListElement* e4 = create_singly_linked_list_element( 12 );
  SinglyLinkedListElement* e5 = create_singly_linked_list_element( 14 );
  SinglyLinkedListElement* e6 = create_singly_linked_list_element( 17 );
  SinglyLinkedList* list = create_singly_linked_list();
  SinglyLinkedListElement* r1 = append_singly_linked_list( list, e1 );
  SinglyLinkedListElement* r2 = append_singly_linked_list( list, e2 );
  SinglyLinkedListElement* r3 = append_singly_linked_list( list, e3 );
  SinglyLinkedListElement* r4 = append_singly_linked_list( list, e4 );
  SinglyLinkedListElement* r5 = append_singly_linked_list( list, e5 );
  remove_element_singly_linked_list( list, e6 );
  if ( get_size_singly_linked_list( list ) != 5 ) {
    result = -1;
  }
  free( e1 );
  free( e2 );
  free( e3 );
  free( e4 );
  free( e5 );
  free( e6 );
  free( r1 );
  free( r2 );
  free( r3 );
  free( r4 );
  free( r5 );
  free( list );
  return result;
}

/**
 *
 Before remove:

o---o

 After remove:

o---o

*/

int test_remove_from_empty_singly_linked_list() {
  int result = 0;
  SinglyLinkedListElement* e1 = create_singly_linked_list_element( 21 );
  SinglyLinkedList* list = create_singly_linked_list();
  remove_element_singly_linked_list( list, e1 );
  if ( get_size_singly_linked_list( list ) != 0 ) {
    result = -1;
  }
  if ( NULL != get_head_singly_linked_list( list ) ) {
    result = -1;
  }
  if ( NULL != get_tail_singly_linked_list( list ) ) {
    result = -1;
  }
  free( e1 );
  free( list );
  return result;
}

int test_remove_all_singly_linked_list() {
  int result = 0;
  SinglyLinkedListElement* e1 = create_singly_linked_list_element( 1 );
  SinglyLinkedListElement* e2 = create_singly_linked_list_element( 2 );
  SinglyLinkedListElement* e3 = create_singly_linked_list_element( 3 );
  SinglyLinkedListElement* e4 = create_singly_linked_list_element( 4 );
  SinglyLinkedListElement* e5 = create_singly_linked_list_element( 5 );
  SinglyLinkedList* list = create_singly_linked_list();
  append_singly_linked_list( list, e1 );
  append_singly_linked_list( list, e2 );
  append_singly_linked_list( list, e3 );
  append_singly_linked_list( list, e4 );
  append_singly_linked_list( list, e5 );
  remove_all_singly_linked_list( list );
  if ( get_size_singly_linked_list( list ) != 0 ) {
    result = -1;
  }
  if ( NULL != get_head_singly_linked_list( list ) ) {
    result = -1;
  }
  if ( NULL != get_tail_singly_linked_list( list ) ) {
    result = -1;
  }
  free( e1 );
  free( e2 );
  free( e3 );
  free( e4 );
  free( e5 );
  free( list );
  return result;
}

int main() {
  assert( test_create_singly_linked_list() == 0 );
  assert( test_get_head_singly_linked_list() == 0 );
  assert( test_get_tail_singly_linked_list() == 0 );
  assert( test_get_element_at_singly_linked_list() == 0 );
  assert( test_is_equal_singly_linked_list() == 0 );
  /* assert( test_shallow_copy_singly_linked_list() == 0 ); */
  assert( test_prepend_singly_linked_list() == 0 );
  assert( test_append_singly_linked_list() == 0 );
  assert( test_remove_head_singly_linked_list() ==  0 );
  assert( test_remove_middle_singly_linked_list() == 0 );
  assert( test_remove_tail_singly_linked_list() == 0 );
  assert( test_remove_none_singly_linked_list() == 0 );
  assert( test_remove_from_empty_singly_linked_list() == 0 );
  
  /* assert( test_remove_all_singly_linked_list() == 0 ); */
  return 0;
}
