/*
 * __gt_fc_argv_axiomatic.h
 *
 *  Created on: Aug 1, 2016
 *      Author: jrobbins
 */

#ifndef LIBC___GT_FC_ARGV_AXIOMATIC_H_
#define LIBC___GT_FC_ARGV_AXIOMATIC_H_

#include "__fc_define_size_t.h"

/*@
axiomatic ArgV {
    logic size_t argv_count(char** argv) reads *argv;
    logic boolean argv_count_pred(char** argv, size_t i) reads *argv;

    axiom argv_count_pred_axiom: \forall char** argv; \forall size_t i; argv_count_pred(argv, i) <==> (\valid(argv+(0..i)) && argv[i] == \null && (\forall size_t j; j < i ==> \valid(argv[j])));
    axiom argv_count_axiom: \forall char** argv; \forall size_t i; argv_count(argv) == i <==> argv_count_pred(argv, i);
}
*/

#endif /* LIBC___GT_FC_ARGV_AXIOMATIC_H_ */
