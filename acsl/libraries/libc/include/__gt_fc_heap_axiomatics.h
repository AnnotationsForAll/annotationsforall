/*
 * __gt_fc_heap_axiomatics.h
 *
 *  Created on: Jul 25, 2016
 *      Author: jrobbins
 */

#ifndef LIBC___GT_FC_HEAP_AXIOMATICS_H_
#define LIBC___GT_FC_HEAP_AXIOMATICS_H_

/*@ ghost extern int __fc_heap_status; */
/*@ axiomatic dynamic_allocation {
  @ predicate is_allocable(size_t n) // Can a block of n bytes be allocated?
  @ reads __fc_heap_status;
  @ }
*/

#endif /* LIBC___GT_FC_HEAP_AXIOMATICS_H_ */
