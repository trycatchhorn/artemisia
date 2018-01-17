#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "doubly_linked_list.h"

void print_int( void *int_val ) {
  printf( "%d", *( int * ) int_val );
}

void print_float( void *float_val ) {
  printf( "%f", *( float * ) float_val );
}

void print_char( void *char_val ) {
  printf( "%c", *( char * ) char_val );
}

void print_element_int( DoublyLinkedListElement *elem ) {
  int elem_data = 0;
  int data_prev = 0;
  int data_next = 0;
  if ( NULL != elem ) {
    elem_data = *( int * ) get_data_doubly_linked_list_element( elem );
    DoublyLinkedListElement *elem_prev = get_previous_doubly_linked_list_element( elem );
    DoublyLinkedListElement *elem_next = get_next_doubly_linked_list_element( elem );
    if ( NULL != elem_prev ) {
      data_prev = *( int * ) get_data_doubly_linked_list_element( elem_prev );
    }
    if ( NULL != elem_next ) {
      data_next = *( int * ) get_data_doubly_linked_list_element( elem_next );
    }
    printf( "%s%d%s%d%s%d%s", "(data:", elem_data, ", prev:", data_prev, ", next:", data_next,")" );
  }
}

void print_element_float( DoublyLinkedListElement *elem ) {
  float elem_data = 0.0f;
  float data_prev = 0.0f;
  float data_next = 0.0f;
  if ( NULL != elem ) {
    elem_data = *( float * ) get_data_doubly_linked_list_element( elem );
    DoublyLinkedListElement *elem_prev = get_previous_doubly_linked_list_element( elem );
    DoublyLinkedListElement *elem_next = get_next_doubly_linked_list_element( elem );
    if ( NULL != elem_prev ) {
      data_prev = *( float * ) get_data_doubly_linked_list_element( elem_prev );
    }
    if ( NULL != elem_next ) {
      data_next = *( float * ) get_data_doubly_linked_list_element( elem_next );
    }
    printf( "%s%f%s%f%s%f%s", "(data:", elem_data, ", prev:", data_prev, ", next:", data_next,")" );
  }
}

void print_element_char( DoublyLinkedListElement *elem ) {
  char elem_data = 0;
  char data_prev = 0;
  char data_next = 0;
  if ( NULL != elem ) {
    elem_data = *( char * ) get_data_doubly_linked_list_element( elem );
    DoublyLinkedListElement *elem_prev = get_previous_doubly_linked_list_element( elem );
    DoublyLinkedListElement *elem_next = get_next_doubly_linked_list_element( elem );
    if ( NULL != elem_prev ) {
      data_prev = *( char * ) get_data_doubly_linked_list_element( elem_prev );
    }
    if ( NULL != elem_next ) {
      data_next = *( char * ) get_data_doubly_linked_list_element( elem_next );
    }
    printf( "%s%c%s%c%s%c%s", "(data:", elem_data, ", prev:", data_prev, ", next:", data_next,")" );
  }
}


void debug_helper( DoublyLinkedList *plist, void (* print_func )(void*) ) {
  int i;
  if ( NULL != plist ) {
    DoublyLinkedListElement *head = get_head_doubly_linked_list( plist );
    DoublyLinkedListElement *tail = get_tail_doubly_linked_list( plist );

    printf( "%s", "[" );
    DoublyLinkedListElement *current = head;
    for( i = 0; i < get_size_doubly_linked_list( plist ); ++i ) {

      if ( print_func == print_int ) {
        print_element_int( current );
      }

      if ( print_func == print_float ) {
        print_element_float( current );
      }

      if ( print_func == print_char ) {
        print_element_char( current );
      }

      if ( current != tail ) {
        printf( "%s", ", " );
      }

      current = get_next_doubly_linked_list_element( current );

    }
    printf( "%s\n", "]" );
  }
}

bool is_equal_int( DoublyLinkedListElement *elem1, DoublyLinkedListElement *elem2 ) {
  const int elem1_data = *( int * ) get_data_doubly_linked_list_element( elem1 );
  const int elem2_data = *( int * ) get_data_doubly_linked_list_element( elem2 );
  return ( elem1_data == elem2_data );
}

bool is_equal_char( DoublyLinkedListElement *elem1, DoublyLinkedListElement *elem2 ) {
  const char elem1_data = *( char * ) get_data_doubly_linked_list_element( elem1 );
  const char elem2_data = *( char * ) get_data_doubly_linked_list_element( elem2 );
  return ( elem1_data == elem2_data );
}

int test_create_doubly_linked_list_element_int() {
  int elem_value;
  int elem_value_ref;
  DoublyLinkedListElement *elem;
  int result = 0;
  elem_value = 10;
  elem_value_ref = 10;
  elem = create_doubly_linked_list_element( &elem_value, sizeof( int ) );
  void *elem_data = get_data_doubly_linked_list_element( elem );
  if ( elem_value_ref != *( ( int * ) elem_data ) ) {
    result = -1;
  }
  free( elem );
  return result;
}

int test_create_doubly_linked_list_element_float() {
  float elem_value;
  float elem_value_ref;
  DoublyLinkedListElement *elem;
  int result = 0;
  elem_value = 10.0f;
  elem_value_ref = 10.0f;
  elem = create_doubly_linked_list_element( &elem_value, sizeof( float ) );
  void *elem_data = get_data_doubly_linked_list_element( elem );
  if ( elem_value_ref != *( ( float * ) elem_data ) ) {
    result = -1;
  }
  free( elem );
  return result;
}

int test_create_doubly_linked_list_element_char() {
  char elem_value;
  char elem_value_ref;
  DoublyLinkedListElement *elem;
  int result = 0;
  elem_value = 'a';
  elem_value_ref = 'a';
  elem = create_doubly_linked_list_element( &elem_value, sizeof( char ) );
  void *elem_data = get_data_doubly_linked_list_element( elem );
  if ( elem_value_ref != *( ( char * ) elem_data ) ) {
    result = -1;
  }
  free( elem );
  return result;
}

int test_create_doubly_linked_list_empty() {
  DoublyLinkedList *list;
  list = create_doubly_linked_list();
  if ( NULL == list ) {
    return -1;
  }
  free( list );
  return 0;
}

int test_create_doubly_linked_list_char() {
  DoublyLinkedListElement *tmp;
  char elem_head_value_ref;
  char elem_head_value_res;
  int result = 0;
  char c1 = 'a';
  char c2 = 'b';
  char c3 = 'c';
  elem_head_value_ref = 'a';
  DoublyLinkedListElement *e1 = create_doubly_linked_list_element( &c1, sizeof( char ) );
  DoublyLinkedListElement *e2 = create_doubly_linked_list_element( &c2, sizeof( char ) );
  DoublyLinkedListElement *e3 = create_doubly_linked_list_element( &c3, sizeof( char ) );
  DoublyLinkedList *list = create_doubly_linked_list();
  prepend_doubly_linked_list( list, e3, sizeof( char ) );
  prepend_doubly_linked_list( list, e2, sizeof( char ) );
  prepend_doubly_linked_list( list, e1, sizeof( char ) );
  if ( get_size_doubly_linked_list( list ) != 3 ) {
    result = -1;
  }
  /*print_doubly_linked_list( list, print_char );*/
  debug_helper( list, print_char );
  free( e1 );
  free( e2 );
  free( e3 );
  free( list );
  return result;
}


int test_get_head_doubly_linked_list() {
  DoublyLinkedListElement *tmp;
  char elem_head_value_ref;
  char elem_head_value_res;
  int result = 0;
  char c1 = 'a';
  char c2 = 'b';
  char c3 = 'c';
  elem_head_value_ref = 'a';
  DoublyLinkedListElement *e1 = create_doubly_linked_list_element( &c1, sizeof( char ) );
  DoublyLinkedListElement *e2 = create_doubly_linked_list_element( &c2, sizeof( char ) );
  DoublyLinkedListElement *e3 = create_doubly_linked_list_element( &c3, sizeof( char ) );
  DoublyLinkedList *list = create_doubly_linked_list();
  prepend_doubly_linked_list( list, e3, sizeof( char ) );
  prepend_doubly_linked_list( list, e2, sizeof( char ) );
  prepend_doubly_linked_list( list, e1, sizeof( char ) );
  if ( get_size_doubly_linked_list( list ) != 3 ) {
    result = -1;
  }
  tmp = get_head_doubly_linked_list( list );
  elem_head_value_res = *( ( char *) get_data_doubly_linked_list_element( tmp ) );
  if ( elem_head_value_res != elem_head_value_ref ) {
    result = -1;
  }
  /*print_doubly_linked_list( list, print_char );*/
  debug_helper( list, print_char );
  free( e1 );
  free( e2 );
  free( e3 );
  free( list );
  return result;
}

int test_get_tail_doubly_linked_list() {
  DoublyLinkedListElement* tmp;
  char elem_head_value_ref;
  char elem_head_value_res;
  int result = 0;
  char c1 = 'a';
  char c2 = 'b';
  char c3 = 'c';
  elem_head_value_ref = 'c';
  DoublyLinkedListElement *e1 = create_doubly_linked_list_element( &c1, sizeof( char ) );
  DoublyLinkedListElement *e2 = create_doubly_linked_list_element( &c2, sizeof( char ) );
  DoublyLinkedListElement *e3 = create_doubly_linked_list_element( &c3, sizeof( char ) );
  DoublyLinkedList *list = create_doubly_linked_list();
  prepend_doubly_linked_list( list, e3, sizeof( char ) );
  prepend_doubly_linked_list( list, e2, sizeof( char ) );
  prepend_doubly_linked_list( list, e1, sizeof( char ) );
  if ( get_size_doubly_linked_list( list ) != 3 ) {
    result = -1;
  }
  tmp = get_tail_doubly_linked_list( list );
  elem_head_value_res = *( ( char *) get_data_doubly_linked_list_element( tmp ) );
  if ( elem_head_value_res != elem_head_value_ref ) {
    result = -1;
  }
  /*print_doubly_linked_list( list, print_char );*/
  free( e1 );
  free( e2 );
  free( e3 );
  free( list );
  return result;
}

int test_get_element_at_doubly_linked_list() {
  DoublyLinkedListElement *res1;
  DoublyLinkedListElement *res2;
  DoublyLinkedListElement *res3;
  int result = 0;
  char c1 = 'a';
  char c2 = 'b';
  char c3 = 'c';
  DoublyLinkedListElement *e1 = create_doubly_linked_list_element( &c1, sizeof( char ) );
  DoublyLinkedListElement *e2 = create_doubly_linked_list_element( &c2, sizeof( char ) );
  DoublyLinkedListElement *e3 = create_doubly_linked_list_element( &c3, sizeof( char ) );
  DoublyLinkedList *list = create_doubly_linked_list();
  append_doubly_linked_list( list, e1, sizeof( char ) );
  append_doubly_linked_list( list, e2, sizeof( char ) );
  append_doubly_linked_list( list, e3, sizeof( char ) );
  res1 = get_element_at_doubly_linked_list( list, 0 );
  if ( !is_equal_char( res1, e1 ) ) {
    result = -1;
  }
  res2 = get_element_at_doubly_linked_list( list, 1 );
  if ( !is_equal_char( res2, e2 ) ) {
    result = -1;
  }
  res3 = get_element_at_doubly_linked_list( list, 2 );
  if ( !is_equal_char( res3, e3 ) ) {
    result = -1;
  }
  return result;
}

int test_is_equal_doubly_linked_list() {
  int result = 0;
  char c1 = 'a';
  char c2 = 'b';
  char c3 = 'c';
  char c4 = 'a';
  char c5 = 'b';
  char c6 = 'c';
  DoublyLinkedListElement *e1 = create_doubly_linked_list_element( &c1, sizeof( char ) );
  DoublyLinkedListElement *e2 = create_doubly_linked_list_element( &c2, sizeof( char ) );
  DoublyLinkedListElement *e3 = create_doubly_linked_list_element( &c3, sizeof( char ) );
  DoublyLinkedListElement *e4 = create_doubly_linked_list_element( &c4, sizeof( char ) );
  DoublyLinkedListElement *e5 = create_doubly_linked_list_element( &c5, sizeof( char ) );
  DoublyLinkedListElement *e6 = create_doubly_linked_list_element( &c6, sizeof( char ) );
  DoublyLinkedList *list1 = create_doubly_linked_list();
  DoublyLinkedList *list2 = create_doubly_linked_list();
  prepend_doubly_linked_list( list1, e3, sizeof( char ) );
  prepend_doubly_linked_list( list1, e2, sizeof( char ) );
  prepend_doubly_linked_list( list1, e1, sizeof( char ) );
  prepend_doubly_linked_list( list2, e6, sizeof( char ) );
  prepend_doubly_linked_list( list2, e5, sizeof( char ) );
  prepend_doubly_linked_list( list2, e4, sizeof( char ) );

  /*print_doubly_linked_list( list1, print_char );*/
  /*print_doubly_linked_list( list2, print_char );*/

  if ( ! is_equal_doubly_linked_list( list1, list2, is_equal_char ) ) {
    result = -1;
  }
  free( e1 );
  free( e2 );
  free( e3 );
  free( e4 );
  free( e5 );
  free( e6 );
  free( list1 );
  free( list2 );
  return result;
}

int test_get_size_doubly_linked_list() {
  int result = 0;
  DoublyLinkedList *list;
  list = create_doubly_linked_list();
  if ( get_size_doubly_linked_list( list ) != 0 ) {
    result = -1;
  }
  free( list );
  return result;
}

int test_shallow_copy_doubly_linked_list() {
  int result = 0;
  int i1 = 1;
  int i2 = 2;
  int i3 = 3;
  DoublyLinkedList *list_copy;
  DoublyLinkedListElement *e1 = create_doubly_linked_list_element( &i1, sizeof( int ) );
  DoublyLinkedListElement *e2 = create_doubly_linked_list_element( &i2, sizeof( int ) );
  DoublyLinkedListElement *e3 = create_doubly_linked_list_element( &i3, sizeof( int ) );
  DoublyLinkedList *list = create_doubly_linked_list();
  append_doubly_linked_list( list, e1, sizeof( int ) );
  append_doubly_linked_list( list, e2, sizeof( int ) );
  append_doubly_linked_list( list, e3, sizeof( int ) );
  list_copy = shallow_copy_doubly_linked_list( list, sizeof( int ) );
  if ( ! is_equal_doubly_linked_list( list, list_copy, is_equal_int ) ) {
    result = -1;
  }
  free( e1 );
  free( e2 );
  free( e3 );
  free( list );
  free( list_copy );
  return result;
}

int test_prepend_doubly_linked_list() {
  int result = 0;
  int i1 = 1;
  int i2 = 2;
  int i3 = 3;
  DoublyLinkedListElement *e1 = create_doubly_linked_list_element( &i1, sizeof( int ) );
  DoublyLinkedListElement *e2 = create_doubly_linked_list_element( &i2, sizeof( int ) );
  DoublyLinkedListElement *e3 = create_doubly_linked_list_element( &i3, sizeof( int ) );
  DoublyLinkedList *list = create_doubly_linked_list();
  prepend_doubly_linked_list( list, e3, sizeof( int ) );
  prepend_doubly_linked_list( list, e2, sizeof( int ) );
  prepend_doubly_linked_list( list, e1, sizeof( int ) );
  if ( get_size_doubly_linked_list( list ) != 3 ) {
    result = -1;
  }
  /* print_doubly_linked_list( list, print_int ); */
  /* debug_helper( list, print_int ); */
  free( e1 );
  free( e2 );
  free( e3 );
  free( list );
  return result;
}

int test_append_doubly_linked_list() {
  int result = 0;
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
  if ( get_size_doubly_linked_list( list ) != 3 ) {
    result = -1;
  }
  print_doubly_linked_list( list, print_int );
  debug_helper( list, print_int );
  free( e1 );
  free( e2 );
  free( e3 );
  free( list );
  return result;
}



int test_remove_element_head_doubly_linked_list() {
  int result = 0;
  int i1 = 21;
  int i2 = 32;
  int i3 = 16;
  int i4 = 12;
  int i5 = 14;
  DoublyLinkedListElement *new_head;
  DoublyLinkedListElement *e1 = create_doubly_linked_list_element( &i1, sizeof( int ) );
  DoublyLinkedListElement *e2 = create_doubly_linked_list_element( &i2, sizeof( int ) );
  DoublyLinkedListElement *e3 = create_doubly_linked_list_element( &i3, sizeof( int ) );
  DoublyLinkedListElement *e4 = create_doubly_linked_list_element( &i4, sizeof( int ) );
  DoublyLinkedListElement *e5 = create_doubly_linked_list_element( &i5, sizeof( int ) );
  DoublyLinkedList *list = create_doubly_linked_list();
  append_doubly_linked_list( list, e1, sizeof( int ) );
  append_doubly_linked_list( list, e2, sizeof( int ) );
  append_doubly_linked_list( list, e3, sizeof( int ) );
  append_doubly_linked_list( list, e4, sizeof( int ) );
  append_doubly_linked_list( list, e5, sizeof( int ) );
  remove_element_doubly_linked_list( list, e1, is_equal_int );
  new_head = get_head_doubly_linked_list( list );
  if ( !is_equal_int( new_head, e2 ) ) {
    result = -1;
  }
  if ( -1 == result ) {
    free( e1 );
  }
  free( e2 );
  free( e3 );
  free( e4 );
  free( e5 );
  free( list );
  return result;
}

int test_remove_element_middle_doubly_linked_list() {
  int result = 0;
  int i1 = 21;
  int i2 = 32;
  int i3 = 16;
  int i4 = 12;
  int i5 = 14;
  DoublyLinkedListElement *new_head;
  DoublyLinkedListElement *e1 = create_doubly_linked_list_element( &i1, sizeof( int ) );
  DoublyLinkedListElement *e2 = create_doubly_linked_list_element( &i2, sizeof( int ) );
  DoublyLinkedListElement *e3 = create_doubly_linked_list_element( &i3, sizeof( int ) );
  DoublyLinkedListElement *e4 = create_doubly_linked_list_element( &i4, sizeof( int ) );
  DoublyLinkedListElement *e5 = create_doubly_linked_list_element( &i5, sizeof( int ) );
  DoublyLinkedList *list = create_doubly_linked_list();
  append_doubly_linked_list( list, e1, sizeof( int ) );
  append_doubly_linked_list( list, e2, sizeof( int ) );
  append_doubly_linked_list( list, e3, sizeof( int ) );
  append_doubly_linked_list( list, e4, sizeof( int ) );
  append_doubly_linked_list( list, e5, sizeof( int ) );
  remove_element_doubly_linked_list( list, e3, is_equal_int );
  new_head = get_head_doubly_linked_list( list );
  if ( get_size_doubly_linked_list( list ) != 4 ) {
    result = -1;
  }
  if ( -1 == result ) {
    free( e1 );
  }
  free( e2 );
  free( e3 );
  free( e4 );
  free( e5 );
  free( list );
  return result;
}

int test_remove_element_tail_doubly_linked_list() {
  int result = 0;
  int i1 = 21;
  int i2 = 32;
  int i3 = 16;
  int i4 = 12;
  int i5 = 14;
  DoublyLinkedListElement *new_tail;
  DoublyLinkedListElement *e1 = create_doubly_linked_list_element( &i1, sizeof( int ) );
  DoublyLinkedListElement *e2 = create_doubly_linked_list_element( &i2, sizeof( int ) );
  DoublyLinkedListElement *e3 = create_doubly_linked_list_element( &i3, sizeof( int ) );
  DoublyLinkedListElement *e4 = create_doubly_linked_list_element( &i4, sizeof( int ) );
  DoublyLinkedListElement *e5 = create_doubly_linked_list_element( &i5, sizeof( int ) );
  DoublyLinkedList *list = create_doubly_linked_list();
  append_doubly_linked_list( list, e1, sizeof( int ) );
  append_doubly_linked_list( list, e2, sizeof( int ) );
  append_doubly_linked_list( list, e3, sizeof( int ) );
  append_doubly_linked_list( list, e4, sizeof( int ) );
  append_doubly_linked_list( list, e5, sizeof( int ) );
  /*print_doubly_linked_list( list, print_int );*/
  remove_element_doubly_linked_list( list, e5, is_equal_int );
  new_tail = get_tail_doubly_linked_list( list );
  /*print_doubly_linked_list( list, print_int );*/
  if ( !is_equal_int( new_tail, e4 ) ) {
    result = -1;
  }
  if ( -1 == result ) {
    free( e1 );
  }
  free( e2 );
  free( e3 );
  free( e4 );
  free( e5 );
  free( list );
  return result;
}

int test_remove_element_none_doubly_linked_list() {
  printf( "%s \n", "test_remove_none_doubly_linked_list() --- NOT YET IMPLEMENTED" );
  return 0;
}

int test_remove_element_from_empty_doubly_linked_list() {
  printf( "%s \n", "test_remove_from_empty_doubly_linked_list() --- NOT YET IMPLEMENTED" );
  return 0;
}

int test_remove_all_doubly_linked_list() {
  printf( "%s \n", "test_remove_all_doubly_linked_list() --- NOT YET IMPLEMENTED" );
  return 0;
}

int test_remove_element_at_doubly_linked_list_one() {
  int result = 0;
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

  /* here we should verify that the doubly linked list is valid,
     which means that all elements have valid fields: data, prev,
     and next.
  */


  /* debug_helper( list, print_int ); */
  remove_element_at_doubly_linked_list( list, 1 );
  /* debug_helper( list, print_int ); */

  return 0;
}


int test_remove_element_at_doubly_linked_list_two() {
  int result = 0;
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

  /* here we should verify that the doubly linked list is valid,
     which means that all elements have valid fields: data, prev,
     and next.
  */


  /* debug_helper( list, print_int ); */
  remove_element_at_doubly_linked_list( list, 2 );
  /* debug_helper( list, print_int ); */

  return 0;
}

int main() {
  assert( test_create_doubly_linked_list_element_int() == 0 );
  assert( test_create_doubly_linked_list_element_float() == 0 );
  assert( test_create_doubly_linked_list_element_char() == 0 );
  assert( test_create_doubly_linked_list_empty() == 0 );
  assert( test_create_doubly_linked_list_char() == 0 );
  assert( test_get_head_doubly_linked_list() == 0 );
  assert( test_get_tail_doubly_linked_list() == 0 );
  assert( test_get_element_at_doubly_linked_list() == 0 );
  assert( test_is_equal_doubly_linked_list() == 0 );
  assert( test_get_size_doubly_linked_list() == 0 );
  assert( test_shallow_copy_doubly_linked_list() == 0 );
  assert( test_prepend_doubly_linked_list() == 0 );
  assert( test_append_doubly_linked_list() == 0 );

  assert( test_remove_element_head_doubly_linked_list() == 0 );
  assert( test_remove_element_middle_doubly_linked_list() == 0 );
  assert( test_remove_element_tail_doubly_linked_list() == 0 );

  /*
  assert( test_remove_element_none_doubly_linked_list() == 0 );
  assert( test_remove_element_from_empty_doubly_linked_list() == 0 );
  assert( test_remove_all_doubly_linked_list() == 0 );
  */
  assert( test_remove_element_at_doubly_linked_list_one() == 0 );
  assert( test_remove_element_at_doubly_linked_list_two() == 0 );


  return 0;
}
