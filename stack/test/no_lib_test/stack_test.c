#include <assert.h>
#include <stdlib.h>
#include "stack.h"

int test_create_stack() {
  int result = 0;
  ItemType* i1 = create_item( 10 );
  ItemType* i2 = create_item( 20 );
  ItemType* i3 = create_item( 30 );
  ItemType* i4 = create_item( 40 );
  ItemType* i5 = create_item( 50 );

  StackType* st = create_stack( 5 );
  push( i1, st );
  push( i2, st );
  push( i3, st );
  push( i4, st );
  push( i5, st );

  if ( get_stack_size( st ) != 5 ) {
    result = -1;
  }
  i1 = pop( st );
  if ( get_item_data( i1 ) != 50 ) {
    result = -1;
  }
  i2 = pop( st );
  if ( get_item_data( i2 ) != 40 ) {
    result = -1;
  }
  i3 = pop ( st );
  if ( get_item_data( i3 ) != 30 ) {
    result = -1;
  }
  i4 = pop ( st );
  if ( get_item_data( i4 ) != 20 ) {
    result = -1;
  }
  i5 = pop( st );
  if ( get_item_data( i5 ) != 10 ) {
    result = -1;
  }
  remove_stack( st );
  return result;
}

int test_push_stack() {
  int i;
  int size;
  int itemData1;
  int itemData2;
  ItemType* tmpItem1;
  ItemType* tmpItem2;
  int result = 0;
  StackType* st1 = create_stack( 5 );
  StackType* st2 = create_stack( 5 );

  ItemType* i11 = create_item( 10 );
  ItemType* i12 = create_item( 20 );
  ItemType* i13 = create_item( 30 );
  ItemType* i14 = create_item( 40 );
  ItemType* i15 = create_item( 50 );

  ItemType* i21 = create_item( 10 );
  ItemType* i22 = create_item( 20 );
  ItemType* i23 = create_item( 30 );
  ItemType* i24 = create_item( 40 );
  ItemType* i25 = create_item( 50 );

  push( i11, st1 );
  push( i12, st1 );
  push( i13, st1 );
  push( i14, st1 );
  push( i15, st1 );

  push( i21, st2 );
  push( i22, st2 );
  push( i23, st2 );
  push( i24, st2 );
  push( i25, st2 );

  if ( get_stack_size( st1 ) != get_stack_size( st2 ) ) {
    result = -1;
  }

  size = get_stack_size( st1 );

  for ( i = 0; i < size; ++i ) {
    tmpItem1 = (ItemType*) pop( st1 );
    tmpItem2 = (ItemType*) pop( st2 );
    itemData1 = (int) get_item_data( tmpItem1 );
    itemData2 = (int) get_item_data( tmpItem2 );
    if ( itemData1 != itemData2 ) {
      result = -1;
    }
  }
  remove_stack( st1 );
  remove_stack( st2 );
  return result;
}

int test_pop_stack() {
  ItemType* res1;
  ItemType* res2;
  ItemType* res3;
  int result = 0;

  ItemType* i1 = create_item( 10 );
  ItemType* i2 = create_item( 20 );
  ItemType* i3 = create_item( 30 );

  ItemType* ref1 = create_item( 30 );
  ItemType* ref2 = create_item( 20 );
  ItemType* ref3 = create_item( 10 );

  StackType* st1 = create_stack( 3 );

  push( i1, st1 );
  push( i2, st1 );
  push( i3, st1 );

  if ( get_stack_size( st1 ) != 3 ) {
    result = -1;
  }

  res1 = pop( st1 );
  if ( get_item_data( res1 ) != get_item_data( ref1 ) ) {
    result = -1;
  }
  res2 = pop( st1 );
  if ( get_item_data( res2 ) != get_item_data( ref2 ) ) {
    result = -1;
  }
  res3 = pop( st1 );
  if ( get_item_data( res3 ) != get_item_data( ref3 ) ) {
    result = -1;
  }
  if ( get_stack_size( st1 ) != 0 ) {
    result = -1;
  }
  remove_stack( st1 );
  free( ref1 );
  free( ref2 );
  free( ref3 );
  return result;
}

int test_is_empty_stack() {
  int result = 0;
  StackType* st = create_stack( 3 );
  if ( !is_empty_stack( st ) ) {
    return result;
  }
  remove_stack( st );
  return result;
}

int test_is_not_empty_stack() {
  int result = 0;
  ItemType* i1 = create_item( 10 );
  ItemType* i2 = create_item( 20 );
  ItemType* i3 = create_item( 30 );
  StackType* st = create_stack( 3 );
  push( i1, st );
  push( i2, st );
  push( i3, st );
  if ( is_empty_stack( st ) ) {
    result = -1;
  }
  if ( get_stack_size( st ) != 3 ) {
    result = -1;
  }
  remove_stack( st );
  return result;
}

int test_top_stack() {
  ItemType* top;
  int result = 0;
  StackType* st = create_stack( 5 );
  ItemType* i1 = create_item( 10 );
  ItemType* i2 = create_item( 20 );
  ItemType* i3 = create_item( 30 );
  ItemType* i4 = create_item( 40 );
  ItemType* i5 = create_item( 50 );
  push( i1, st );
  push( i2, st );
  push( i3, st );
  push( i4, st );
  push( i5, st );
  top = top_stack( st );
  if ( get_item_data( i5 ) != get_item_data( top ) ) {
    result = -1;
  }
  if ( get_stack_size( st ) != 5 ) {
    result = -1;
  }
  remove_stack( st );
  return result;
}

int test_remove_stack() {
  int result = 0;
  StackType* st = create_stack( 5 );
  ItemType* i1 = create_item( 10 );
  ItemType* i2 = create_item( 20 );
  ItemType* i3 = create_item( 30 );
  ItemType* i4 = create_item( 40 );
  ItemType* i5 = create_item( 50 );
  push( i1, st );
  push( i2, st );
  push( i3, st );
  push( i4, st );
  push( i5, st );
  remove_stack( st );
  free( i1 );
  free( i2 );
  free( i3 );
  free( i4 );
  free( i5 );
  return result;
}

int test_generate_random_stack() {
  int result = 0;
  int low_limit = 1;
  int high_limit = 99;
  StackType* st = generate_random_stack( 10, low_limit, high_limit );
  print_stack( st );
  if ( is_empty_stack( st ) ) {
    result = -1;
  }
  ItemType* i1 = pop( st );
  if ( get_item_data( i1 ) < low_limit || get_item_data( i1 ) > high_limit ) {
    result = -1;
  }
  ItemType* i2 = pop( st );
  if ( get_item_data( i2 ) < low_limit || get_item_data( i2 ) > high_limit ) {
    result = -1;
  }
  ItemType* i3 = pop( st );
  if ( get_item_data( i3 ) < low_limit || get_item_data( i3 ) > high_limit ) {
    result = -1;
  }
  ItemType* i4 = pop( st );
  if ( get_item_data( i4 ) < low_limit || get_item_data( i4 ) > high_limit ) {
    result = -1;
  }
  ItemType* i5 = pop( st );
  if ( get_item_data( i5 ) < low_limit || get_item_data( i5 ) > high_limit ) {
    result = -1;
  }
  ItemType* i6 = pop( st );
  if ( get_item_data( i6 ) < low_limit || get_item_data( i6 ) > high_limit ) {
    result = -1;
  }
  ItemType* i7 = pop( st );
  if ( get_item_data( i7 ) < low_limit || get_item_data( i7 ) > high_limit ) {
    result = -1;
  }
  ItemType* i8 = pop( st );
  if ( get_item_data( i8 ) < low_limit || get_item_data( i8 ) > high_limit ) {
    result = -1;
  }
  ItemType* i9 = pop( st );
  if ( get_item_data( i9 ) < low_limit || get_item_data( i9 ) > high_limit ) {
    result = -1;
  }
  ItemType* i10 = pop( st );
  if ( get_item_data( i10 ) < low_limit || get_item_data( i10 ) > high_limit ) {
    result = -1;
  }
  if ( get_stack_size( st ) != 0 ) {
    result = -1;
  }
  return result;
}

int main() {
  assert( test_create_stack() == 0 );
  assert( test_push_stack() == 0 );
  assert( test_pop_stack() == 0 );
  assert( test_is_empty_stack() == 0 );
  assert( test_is_not_empty_stack() == 0 );
  assert( test_top_stack() == 0 );
  assert( test_remove_stack() == 0 );
  assert( test_generate_random_stack() == 0);
  return 0;
}
