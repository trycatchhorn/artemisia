#include <stdio.h>
#include <stdlib.h>
#include "../../../include/stack.h"

int main() {
  StackType* st;
  ItemType* i1;
  ItemType* i2;
  ItemType* i3;
  int i1_data;
  int i2_data;
  int i3_data;
  int is_empty;
  st = generate_random_stack( 3, 0, 9 );
  is_empty = is_empty_stack( st );
  printf( "%d \n", is_empty );
  print_stack( st );
  i1 = top_stack( st );
  i2 = pop( st );
  i3 = create_item( 111 );
  push( i3, st );
  i1_data = get_item_data( i1 );
  i2_data = get_item_data( i2 );
  i3_data = get_item_data( i3 );
  printf( "%d \n", i1_data );
  printf( "%d \n", i2_data );
  printf( "%d \n", i3_data );
  print_stack( st );
  return 1;
}
