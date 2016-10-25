/*
 * alloca.h
 *
 *  Created on: Jul 18, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_ALLOCA_H_
#define LIBC_ALLOCA_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "__fc_define_size_t.h"
#include "__gt_fc_heap_axiomatics.h"

/*@ allocates \result;
  @ assigns __fc_heap_status \from size, __fc_heap_status;
  @ assigns \result \from size, __fc_heap_status;
  @ behavior allocation:
  @   assumes is_allocable(size);
  @   assigns __fc_heap_status \from size, __fc_heap_status;
  @   assigns \result \from size, __fc_heap_status;
  @   ensures \fresh(\result,size);
  @ behavior no_allocation:
  @   assumes !is_allocable(size);
  @   assigns \result \from \nothing;
  @   allocates \nothing;
  @   ensures \result==\null;
  @ complete behaviors;
  @ disjoint behaviors;
  @*/
void * alloca (size_t size);

#endif /* LIBC_ALLOCA_H_ */
