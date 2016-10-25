/*
 * mcheck.h
 *
 *  Created on: Jul 6, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_MCHECK_H_
#define LIBC_MCHECK_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

enum mcheck_status {
    MCHECK_DISABLED,
    MCHECK_OK,
    MCHECK_HEAD,
    MCHECK_TAIL,
    MCHECK_FREE
};

/*@
assigns \result \from abortfn;
ensures \result == -1 || \result == 0;
*/
int mcheck(void (*abortfn)(enum mcheck_status status));

/*@
requires \valid((char*)pointer);
assigns \result \from pointer;
*/
enum mcheck_status mprobe(void *pointer);

/*@
assigns \nothing;
*/
void mtrace (void);

/*@
assigns \nothing;
*/
void muntrace (void);

/*@
assigns \result \from abortfn;
ensures \result == -1 || \result == 0;
*/
int mcheck_pedantic(void (*abortfn)(enum mcheck_status status));

/*@
assigns \nothing;
*/
void mcheck_check_all(void);

#endif /* LIBC_MCHECK_H_ */
