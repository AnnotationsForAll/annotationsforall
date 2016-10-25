/*
 * __gt_fc_define_ctermid.h
 *
 *  Created on: Jul 20, 2016
 *      Author: jrobbins
 */

#ifndef LIBC___GT_FC_DEFINE_CTERMID_H_
#define LIBC___GT_FC_DEFINE_CTERMID_H_

// This header exists because the XPG requires that ctermid be defined in both <stdio.h> and <unistd.h>.

#define L_ctermid 16

/*@
requires s != \null ==> \valid(s+(0.. L_ctermid-1));
assigns \result, s[0.. L_ctermid-1] \from s[..];
ensures \valid(\result);
ensures s != \null ==> \result == s;
*/
char *ctermid(char *s);

#endif /* LIBC___GT_FC_DEFINE_CTERMID_H_ */
