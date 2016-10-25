/*
 * ppc.h
 *
 *  Created on: Jul 13, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_PLATFORM_PPC_H_
#define LIBC_SYS_PLATFORM_PPC_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../../__gt_fc_define_alternative_types.h"


//@ ghost uint64_t __gt_fc_ppc_timebase;
//@ ghost uint64_t __gt_fc_ppc_timebase_freq;
//@ ghost uint64_t __gt_fc_ppc_usage_hint;
//@ ghost uint64_t __gt_fc_ppc_priority;

/*@
assigns \result, __gt_fc_ppc_timebase \from __gt_fc_ppc_timebase, __gt_fc_ppc_timebase_freq;
ensures \result == __gt_fc_ppc_timebase;
*/
uint64_t __ppc_get_timebase (void);

/*@
assigns \result \from __gt_fc_ppc_timebase_freq;
ensures \result == __gt_fc_ppc_timebase_freq;
*/
uint64_t __ppc_get_timebase_freq (void);

/*@
assigns __gt_fc_ppc_usage_hint \from \nothing;
*/
void __ppc_yield (void);

/*@
assigns __gt_fc_ppc_usage_hint \from \nothing;
*/
void __ppc_mdoio (void);

/*@
assigns __gt_fc_ppc_usage_hint \from \nothing;
*/
void __ppc_mdoom (void);

/*@
assigns __gt_fc_ppc_priority \from \nothing;
*/
void __ppc_set_ppr_med (void);

/*@
assigns __gt_fc_ppc_priority \from \nothing;
*/
void __ppc_set_ppr_low (void);

/*@
assigns __gt_fc_ppc_priority \from \nothing;
*/
void __ppc_set_ppr_med_low (void);

/*@
assigns __gt_fc_ppc_priority \from \nothing;
*/
void __ppc_set_ppr_very_low (void);

/*@
assigns __gt_fc_ppc_priority \from \nothing;
*/
void __ppc_set_ppr_med_high (void);

#endif /* LIBC_SYS_PLATFORM_PPC_H_ */
