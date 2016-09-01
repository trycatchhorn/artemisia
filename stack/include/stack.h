#ifndef STACK_H
#define STACK_H

/*** Header file for the Stack implementation ***/

/*
 *   Brian Horn - trycatchhorn@gmail.com
 *
 *   This implementation avoids the maximum-size problem occuring
 *   in many array-based stack structures, where the client, before
 *   any elements have been added to the stack, has to know (guess)
 *   the maximum number of elements the stack should be able to hold
 *   throughout its usage.
 *
 *   In the approach used here these shortcomings are solved by
 *   simultaneously maintaining two copies of the structure, the
 *   currently active copy and a larger-sized structure, which is
 *   under construction. This strategy is know as maintaining a
 *   "shadow copy" of the original structure. The construction of
 *   the larger-sized structure is scheduled so it is finished and
 *   ready for use before the active copy reaches its maximum size.
 *   This is achieved by copying, in each operation (push/pop)
 *   performed on the old structure, a fixed number of elements from
 *   the old to the new structure. When the content of the old
 *   structure is completely copied into the new larger structure,
 *   the old structure is removed and the new structure is taken as
 *   the active structure and, when necessary, construction of an
 *   even larger copy is begun.
 */

/*** Definitions of stucture types ***/

/* The structure type for items in the Stack.
 *
 * item         - an element in the stack (here just an integer).
 *
 */
typedef struct item_t ItemType;

/* The structure type for a Stack.
 *
 * Items have the following pointers:
 * base         - a pointer to the base item.
 * copy         - a pointer to a copy of the base item.
 *
 * The remaining structure fields are:
 * size         - the size of the stack.
 * max_size     - the maximum allowed size of the stack.
 * copy_size    - the size of the copy.
 *
 */
typedef struct stack_tt StackType;

/*** Function prototypes ***/

/* create_item() - creates a new item with containing the specified
 * data.
 */
ItemType* create_item( int data );

/* get_item_data() - returns the data contained in the specified
 * item.
 */
int get_item_data( ItemType* itemElem );

/* create_stack() - creates a new stack with the size specified by size and returns a
 * pointer to the stack structure.
 */
StackType* create_stack( int size );

/* get_stack_base() - returns a pointer to the base item of the specified stack.
 *
 */
ItemType* get_stack_base( StackType* st );

/* get_stack_size() - returns the size of the specified stack.
 * The size specifies the number of items contained in the stack.
 */
int get_stack_size( StackType* st );

/* generate_random_stack() - creates a random stack with the number of elements specified
 * by the size argument and with elements in the interval [lowerLimit, higherLimit].
 * This function is mostly included as a debug routine.
 */
StackType* generate_random_stack( int size, int lowerLimit, int higherLimit );

/* push() - pushes an item onto the stack and adjustes the stack structure accordingly
 * by incrementing the size of the stack and maintaining the internal stack structure
 * members. This operation maintains a shadow copy, which make it possible to grow
 * and shrink the stack dynamically. The threshold when to start copying is when the
 * size of the stack is 0.75*size. In this situation the size of the new stack is
 * increased to twice the previous size and the number of items copied is four.
 */
void push( ItemType* item , StackType* st );

/* pop() - pops an item of the stack and adjustes the stack structure accordingly by
 * decrementing the size of the stack. The top stack item is returned and is not present
 * in the stack after the operation.
 */
ItemType* pop( StackType* st );

/* is_empty_stack() - check if the stack is empty. If the stack is empty 1 is returned
 * otherwise 0 is returned.
 */
int is_empty_stack( StackType* st );

/* top_stack() - returns the top item of the stack. The stack is not affected by this
 * operation.
 */
ItemType* top_stack( StackType* st );

/* print_stack() - prints the content of the stack to standard output. This function is
 * mostly included as a debug routine.
 */
void print_stack( StackType* st );

/* remove_stack() - performs cleanup of the allocated stack. Internal pointers in the
 * stack structure are freed and the size variables are reset.
 */
void remove_stack( StackType* st );

#endif
