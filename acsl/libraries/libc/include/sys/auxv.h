/*
 * auxv.h
 *
 *  Created on: Jul 13, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_AUXV_H_
#define LIBC_SYS_AUXV_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../elf.h"
#include "../errno.h"

/*
This header allows you to grab the contents of the ELF auxiliary vector.
Most values are highly dependent on how a program was compiled, so it is unlikely this file will be fully annotated.
*/

/*@
assigns \result, errno \from type;
*/
unsigned long int getauxval (unsigned long int type);

#endif /* LIBC_SYS_AUXV_H_ */
