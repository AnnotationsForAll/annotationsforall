/*
 * __gt_fc_define_ifa_macros.h
 *
 *  Created on: Jul 20, 2016
 *      Author: jrobbins
 */

#ifndef LIBC___GT_FC_DEFINE_IFA_MACROS_H_
#define LIBC___GT_FC_DEFINE_IFA_MACROS_H_

// Both <net/if.h> and <ifaddrs.h> need to define these macros, so they are defined here instead.

#define ifa_broadaddr ifa_ifu.ifu_broadaddr
#define ifa_dstaddr   ifa_ifu.ifu_dstaddr

#endif /* LIBC___GT_FC_DEFINE_IFA_MACROS_H_ */
