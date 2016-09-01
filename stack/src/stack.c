#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/stack.h"

struct item_t {
  int item;
};

struct stack_tt {
  struct item_t *base;
  int size;
  int max_size;
  struct item_t *copy;
  int copy_size;
};

ItemType* create_item( int data ) {
  ItemType* it;
  it = ( ItemType * ) malloc( sizeof( ItemType ) );
  if ( NULL == it ) {
    return NULL;
  }
  it->item = data;
  return it;
}

int get_item_data( ItemType* itemElem ) {
  return itemElem->item;
}

StackType* create_stack( int size ) {
  StackType* st;
  st = ( StackType* ) malloc( sizeof( StackType ) );
  st->base = ( ItemType* ) malloc( size * sizeof( ItemType ) );
  if ( NULL == st || NULL == st->base ) {
    return NULL;
  }
  st->max_size = size;
  st->size = 0;
  st->copy = NULL;
  st->copy_size = 0;
  return st;
}

ItemType* get_stack_base( StackType* st ) {
  return st->base;
}

int get_stack_size( StackType* st ) {
  return st->size;
}

StackType* generate_random_stack( int size, int lowerLimit, int higherLimit ) {
  int i;
  StackType* st = create_stack( size );
  srand( time( NULL ) );

  for ( i = 0; i < size; ++i ) {
    ItemType* testItem = ( ItemType* ) malloc( sizeof( ItemType ) );
    testItem->item = ( rand() % ( higherLimit - lowerLimit + 1 ) ) + lowerLimit;
    push( testItem, st );
  }
  return st;
}

void push( ItemType* item, StackType* st ) {
  *( st->base + st->size ) = *item;
  st->size += 1;
  if ( st->copy != NULL || st->size >= 0.75 * st->max_size ) {
    int additional_copies = 4;
    if ( st->copy == NULL ) {
      st->copy = ( ItemType* ) malloc( 2 * st->max_size * sizeof( ItemType ) );
      while ( additional_copies > 0 && st->copy_size < st->size ) {
        *(st->copy + st->copy_size ) = *(st->base + st->copy_size);
        st->copy_size += 1;
        additional_copies -= 1;
      }
      if( st->copy_size == st->size ) {
        free( st->base );
        st->base = st->copy;
        st->max_size *= 2;
        st->copy = NULL;
        st->copy_size = 0;
      }
    }
  }
}

ItemType* pop( StackType* st ) {
  ItemType* item;
  st->size -= 1;
  item = ( st->base + st->size );
  if ( st->copy_size == st->size ) {
    /* TODO: find out why below fails if incommented. */
    /* free( st->base ); */
    st->base = st->copy;
    st->max_size *= 2;
    st->copy = NULL;
    st->copy_size = 0;
  }
  return item;
}

int is_empty_stack( StackType* st ) {
  return ( st->size == 0 );
}

ItemType* top_stack( StackType* st ) {
  return ( st->base + st->size - 1 );
}

void print_stack( StackType* st ) {
  if ( ! is_empty_stack( st ) ) {
    int i;
    ItemType topItem;
    int n = st->size;
    printf( "%s \n"   , "----------------------"  );
    printf( "%s %d \n", "Stack size: ", n         );
    printf( "%s \n\n" , "----------------------"  );
    printf( "\t\t %s \n"          , "----------------"         );
    for ( i = 1; i < n + 1; ++i ) {
      topItem = *(st->base + st->size - i);
      printf( "\t\t %s %d %s %d \n"  , "|\t", topItem.item, "\t|\t i = ", i );
      printf( "\t\t %s \n"        , "----------------"         );
    }
  }
}

void remove_stack( StackType* st ) {
  free( st->base );
  if ( st->copy != NULL ) {
    st->copy_size = 0;
    free( st->copy );
  }
  st->size = 0;
  st->max_size = 0;
  free( st );
}

