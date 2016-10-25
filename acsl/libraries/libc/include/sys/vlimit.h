/*
 * vlimit.h
 *
 *  Created on: Jul 12, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_VLIMIT_H_
#define LIBC_SYS_VLIMIT_H_

#include "../errno.h"

#define LIM_CPU     0
#define LIM_FSIZE   1
#define LIM_DATA    2
#define LIM_STACK   3
#define LIM_CORE    4
#define LIM_MAXRSS  5
#define LIM_NORAISE 6

/*@
requires LIM_CPU <= resource <= LIM_MAXRSS;
assigns \result \from resource, limit;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int vlimit (int resource, int limit);

#endif /* LIBC_SYS_VLIMIT_H_ */
