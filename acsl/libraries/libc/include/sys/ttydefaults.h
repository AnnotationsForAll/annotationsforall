/*
 * ttydefaults.h
 *
 *  Created on: Jul 22, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_TTYDEFAULTS_H_
#define LIBC_SYS_TTYDEFAULTS_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "../limits.h"
#include "../termios.h"

#define TTYDEF_IFLAG (BRKINT | ISTRIP | ICRNL | IMAXBEL | IXON | IXANY)
#define TTYDEF_OFLAG (OPOST | ONLCR | XTABS)
#define TTYDEF_LFLAG (ECHO | ICANON | ISIG | IEXTEN | ECHOE|ECHOKE|ECHOCTL)
#define TTYDEF_CFLAG (CREAD | CS7 | PARENB | HUPCL)
#define TTYDEF_SPEED (B9600)

#define CTRL(x)  (x&037)
#define CEOF     CTRL('d')
# define CEOL    _POSIX_VDISABLE
#define CERASE   0177
#define CINTR    CTRL('c')
# define CSTATUS _POSIX_VDISABLE
#define CKILL    CTRL('u')
#define CMIN     1
#define CQUIT    034
#define CSUSP    CTRL('z')
#define CTIME    0
#define CDSUSP   CTRL('y')
#define CSTART   CTRL('q')
#define CSTOP    CTRL('s')
#define CLNEXT   CTRL('v')
#define CDISCARD CTRL('o')
#define CWERASE  CTRL('w')
#define CREPRINT CTRL('r')
#define CEOT     CEOF
#define CBRK     CEOL
#define CRPRNT   CREPRINT
#define CFLUSH   CDISCARD

cc_t ttydefchars[NCCS] = {
    CEOF, CEOL, CEOL, CERASE, CWERASE, CKILL, CREPRINT,
    _POSIX_VDISABLE, CINTR, CQUIT, CSUSP, CDSUSP, CSTART, CSTOP, CLNEXT,
    CDISCARD, CMIN, CTIME, CSTATUS, _POSIX_VDISABLE
};

#endif /* LIBC_SYS_TTYDEFAULTS_H_ */
