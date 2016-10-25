/*
 * utsname.h
 *
 *  Created on: Jul 16, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_UTSNAME_H_
#define LIBC_SYS_UTSNAME_H_

struct utsname {
    char* sysname;
    char* nodename;
    char* release;
    char* version;
    char* machine;
    /* GNU Exntension Members */
    char* domainname;
};

/*@
requires \valid(name);
assigns \result, *name \from \nothing;
ensures \result >= -1;
*/
int uname(struct utsname *name);

#endif /* LIBC_SYS_UTSNAME_H_ */
