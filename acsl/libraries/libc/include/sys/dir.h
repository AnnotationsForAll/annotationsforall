/*
 * dir.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_DIR_H_
#define LIBC_SYS_DIR_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../dirent.h" // This header is the old name for <dirent.h>, so just include that header instead.

#define direct dirent

#endif /* LIBC_SYS_DIR_H_ */
