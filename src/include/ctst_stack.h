#ifndef __CTST_STACK_H__
#define __CTST_STACK_H__
/*
  ctst - (c) 2007 Nicolas Lehuen
  This is released under the LGPL - see http://www.gnu.org/licenses/lgpl.html

  $Id: $

  This file defines a stack structure that is used by visitors and iterators.
*/
typedef struct struct_ctst_stack {
  ctst_node_ref* node_bottom;
  ctst_node_ref* node_top;
  size_t node_limit;
  
  char* bytes;
  size_t bytes_length;
  size_t* bytes_length_bottom;
  size_t* bytes_length_top;
  size_t bytes_length_limit;
} ctst_stack;

/* Allocation and deallocation */
ctst_stack* ctst_stack_alloc();
void ctst_stack_free(ctst_stack* stack);

/* Bytes function */
size_t ctst_stack_size(ctst_stack* stack);
void ctst_stack_push(ctst_stack* stack, ctst_node_ref node, char* bytes, size_t bytes_index, size_t bytes_length);
size_t ctst_stack_peek(ctst_stack* stack, ctst_node_ref* node, char** bytes, size_t* bytes_index, size_t* bytes_length);
size_t ctst_stack_pop(ctst_stack* stack, ctst_node_ref* node, char** bytes, size_t* bytes_index, size_t* bytes_length);

#endif