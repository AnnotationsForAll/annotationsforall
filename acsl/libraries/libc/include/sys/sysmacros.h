/*
 * sysmacros.h
 *
 *  Created on: Jul 18, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_SYSMACROS_H_
#define LIBC_SYS_SYSMACROS_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "../__fc_define_dev_t.h"

#define makedev gnu_dev_makedev
#define major gnu_dev_major
#define minor gnu_dev_minor

/*@
assigns \result;
ensures \result == (((maj) << 16) | ((min) & 0xffff));
*/
dev_t gnu_dev_makedev(unsigned int maj, unsigned int min);

/*@
assigns \result;
ensures \result == (unsigned int)(((dev) >> 16) & 0xffff);
*/
unsigned int gnu_dev_major(dev_t dev);

/*@
assigns \result;
ensures \result == (unsigned int)((dev) & 0xffff);
*/
unsigned int gnu_dev_minor(dev_t dev);


#endif /* LIBC_SYS_SYSMACROS_H_ */
