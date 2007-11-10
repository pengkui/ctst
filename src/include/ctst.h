#ifndef __CTST_CTST_H__
#define __CTST_CTST_H__
/*
  ctst - (c) 2007 Nicolas Lehuen
  This is released under the LGPL - see http://www.gnu.org/licenses/lgpl.html

  $Id: $

  This file contains general definitions
*/

#include <stdlib.h>

#define CTST_STORAGE_TYPE_MALLOC_STORAGE

#ifdef CTST_STORAGE_TYPE_MALLOC_STORAGE
  #include "malloc_storage.h"
#endif

#ifdef CTST_STORAGE_TYPE_COMPACT_STORAGE
  #include "compact_storage.h"
#endif

#include "storage.h"

typedef struct struct_ctst_ctst ctst_ctst;

/* ctst allocation / deallocation */
ctst_ctst* ctst_alloc(ctst_storage* storage);
void ctst_free(ctst_ctst* ctst);

/* A few statistics about the ctst */
size_t ctst_get_size(ctst_ctst* ctst);
size_t ctst_get_total_key_length(ctst_ctst* ctst);
size_t ctst_get_node_count(ctst_ctst* ctst);
size_t ctst_get_memory_usage(ctst_ctst* ctst);
float ctst_get_ratio(ctst_ctst* ctst);

/* Basic accessors : get and set */
ctst_data ctst_get(ctst_ctst* ctst, char* bytes, size_t bytes_index, size_t bytes_length);
ctst_data ctst_set(ctst_ctst* ctst, char* bytes, size_t bytes_index, size_t bytes_length,ctst_data data);
ctst_data ctst_remove(ctst_ctst* ctst, char* bytes, size_t bytes_index, size_t bytes_length);

#endif
