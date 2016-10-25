/*
 * cpio.h
 *
 *  Created on: Jul 15, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_CPIO_H_
#define LIBC_CPIO_H_

#define C_IRUSR 0400
#define C_IWUSR 0200
#define C_IXUSR 0100
#define C_IRGRP 040
#define C_IWGRP 020
#define C_IXGRP 010
#define C_IROTH 04
#define C_IWOTH 02
#define C_IXOTH 01
#define C_ISUID 04000
#define C_ISGID 02000
#define C_ISVTX 01000
#define C_ISDIR 040000
#define C_ISFIFO 010000
#define C_ISREG 0100000
#define C_ISBLK 060000
#define C_ISCHR 020000
#define C_ISCTG 0110000
#define C_ISLNK 0120000
#define C_ISSOCK 0140000

#define MAGIC "070707"

#endif /* LIBC_CPIO_H_ */
