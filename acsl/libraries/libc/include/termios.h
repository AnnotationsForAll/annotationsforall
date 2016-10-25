/**************************************************************************/
/*                                                                        */
/*  This file is part of Frama-C.                                         */
/*                                                                        */
/*  Copyright (C) 2007-2015                                               */
/*    CEA (Commissariat à l'énergie atomique et aux énergies              */
/*         alternatives)                                                  */
/*                                                                        */
/*  you can redistribute it and/or modify it under the terms of the GNU   */
/*  Lesser General Public License as published by the Free Software       */
/*  Foundation, version 2.1.                                              */
/*                                                                        */
/*  It is distributed in the hope that it will be useful,                 */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         */
/*  GNU Lesser General Public License for more details.                   */
/*                                                                        */
/*  See the GNU Lesser General Public License version 2.1                 */
/*  for more details (enclosed in the file licenses/LGPLv2.1).            */
/*                                                                        */
/**************************************************************************/

#ifndef _TERMIOS_H
#define _TERMIOS_H

#include "__fc_define_pid_t.h"
#include "features.h"
#include "limits.h"

/* c_iflag bits */
#define IGNBRK  0000001
#define BRKINT  0000002
#define IGNPAR  0000004
#define PARMRK  0000010
#define INPCK   0000020
#define ISTRIP  0000040
#define INLCR   0000100
#define IGNCR   0000200
#define ICRNL   0000400
#define IUCLC   0001000
#define IXON    0002000
#define IXANY   0004000
#define IXOFF   0010000
#define IMAXBEL 0020000
#define IUTF8   0040000

/* c_oflag bits */
#define OPOST  0000001
#define OLCUC  0000002
#define ONLCR  0000004
#define OCRNL  0000010
#define ONOCR  0000020
#define ONLRET 0000040
#define OFILL  0000100
#define OFDEL  0000200
#define NLDLY  0000400
#define NL0    0000000
#define NL1    0000400
#define CRDLY  0003000
#define CR0    0000000
#define CR1    0001000
#define CR2    0002000
#define CR3    0003000
#define TABDLY 0014000
#define TAB0   0000000
#define TAB1   0004000
#define TAB2   0010000
#define TAB3   0014000
#define BSDLY  0020000
#define BS0    0000000
#define BS1    0020000
#define FFDLY  0100000
#define FF0    0000000
#define FF1    0100000

#define VTDLY 0040000
#define   VT0 0000000
#define   VT1 0040000

#define XTABS 0014000

/* c_cflag bit meaning */
#define B0         0000000
#define B50        0000001
#define B75        0000002
#define B110       0000003
#define B134       0000004
#define B150       0000005
#define B200       0000006
#define B300       0000007
#define B600       0000010
#define B1200      0000011
#define B1800      0000012
#define B2400      0000013
#define B4800      0000014
#define B9600      0000015
#define B19200     0000016
#define B38400     0000017
#define CSIZE      0000060
#define CS5        0000000
#define CS6        0000020
#define CS7        0000040
#define CS8        0000060
#define CSTOPB     0000100
#define CREAD      0000200
#define PARENB     0000400
#define PARODD     0001000
#define HUPCL      0002000
#define CLOCAL     0004000
#define CBAUDEX    0010000
#define B57600     0010001
#define B115200    0010002
#define B230400    0010003
#define B460800    0010004
#define B500000    0010005
#define B576000    0010006
#define B921600    0010007
#define B1000000   0010010
#define B1152000   0010011
#define B1500000   0010012
#define B2000000   0010013
#define B2500000   0010014
#define B3000000   0010015
#define B3500000   0010016
#define B4000000   0010017
#define CBAUD      0010017

#define EXTA       B19200
#define EXTB       B38400
#define __MAX_BAUD B4000000

#define CIBAUD  002003600000
#define CMSPAR  010000000000
#define CRTSCTS 020000000000

/* c_lflag bits */
#define ISIG    0000001
#define ICANON  0000002
#define XCASE   0000004
#define ECHO    0000010
#define ECHOE   0000020
#define ECHOK   0000040
#define ECHONL  0000100
#define NOFLSH  0000200
#define TOSTOP  0000400
#define ECHOCTL 0001000
#define ECHOPRT 0002000
#define ECHOKE  0004000
#define FLUSHO  0010000
#define PENDIN  0040000
#define IEXTEN  0001000
#define EXTPROC 0200000

/* tcflow() and TCXONC use these */
#define TCOOFF 0
#define TCOON  1
#define TCIOFF 2
#define TCION  3

/* tcflush() and TCFLSH use these */
#define TCIFLUSH  0
#define TCOFLUSH  1
#define TCIOFLUSH 2

/* tcsetattr uses these */
#define TCSANOW   0
#define TCSADRAIN 1
#define TCSAFLUSH 2

/* number of c_cc characters */
#define NCCS 32

/* c_cc characters */
#define VINTR    0
#define VQUIT    1
#define VERASE   2
#define VKILL    3
#define VEOF     4
#define VTIME    5
#define VMIN     6
#define VSWTC    7
#define VSTART   8
#define VSTOP    9
#define VSUSP    10
#define VEOL     11
#define VREPRINT 12
#define VDISCARD 13
#define VWERASE  14
#define VLNEXT   15
#define VEOL2    16

typedef unsigned int tcflag_t;
typedef unsigned char cc_t;
typedef unsigned int speed_t;

struct termios {
    tcflag_t c_iflag;
    tcflag_t c_oflag;
    tcflag_t c_cflag;
    tcflag_t c_lflag;
    cc_t c_line;
    cc_t c_cc[NCCS];
    speed_t c_ispeed;
    speed_t c_ospeed;
};

/*@
requires \valid(termios_p);
assigns \result \from *termios_p;
*/
speed_t cfgetispeed(const struct termios *termios_p);

/*@
requires \valid(termios_p);
assigns \result \from *termios_p;
*/
speed_t cfgetospeed(const struct termios *termios_p);

/*@
requires \valid(termios_p);
assigns \result, *termios_p \from speed;
ensures \result == -1 || \result == 0;
*/
int cfsetispeed(struct termios *termios_p, speed_t speed);

/*@
requires \valid(termios_p);
assigns \result, *termios_p \from speed;
ensures \result == -1 || \result == 0;
*/
int cfsetospeed(struct termios *termios_p, speed_t speed);

/*@
assigns \result \from fildes;
ensures \result == -1 || \result == 0;
*/
int tcdrain(int fildes);

/*@
assigns \result \from fildes, action;
ensures \result == -1 || \result == 0;
*/
int tcflow(int fildes, int action);

/*@
assigns \result \from fildes, queue_selector;
ensures \result == -1 || \result == 0;
*/
int tcflush(int fildes, int queue_selector);

/*@
requires \valid(termios_p);
assigns \result, *termios_p \from fildes;
ensures \result == -1 || \result == 0;
*/
int tcgetattr(int fildes, struct termios *termios_p);

/*@
assigns \result \from fildes;
*/
pid_t tcgetsid(int fildes);

/*@
assigns \result \from fildes, duration;
ensures \result == -1 || \result == 0;
*/
int tcsendbreak(int fildes, int duration);

/*@
requires \valid(termios_p);
assigns \result \from fildes, optional_actions, *termios_p;
ensures \result == -1 || \result == 0;
*/
int tcsetattr(int fildes, int optional_actions, const struct termios *termios_p);

/* GNU Extensions */

#define OXTABS 0000400
#define ONOEOT 0001000

#define CCTS_OFLOW 0010000
#define CCTS_IFLOW 0020000
#define MDMBUF 0040000
#define CIGNORE 0100000

#define ECHOPRT 0002000
#define ECHOKE 0004000
#define ALTWERASE 0020000
#define NOKERNINFO 0100000

#define VDSUSP 17
#define VSTATUS 18

#define CCEQ(val, c) ((c) == (val) && (val) != _POSIX_VDISABLE)

/*@
requires \valid(termios_p);
assigns *termios_p \from \nothing;
ensures termios_p->c_iflag == (\old(termios_p->c_iflag) & ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON));
ensures termios_p->c_oflag == (\old(termios_p->c_oflag) & ~OPOST);
ensures termios_p->c_lflag == (\old(termios_p->c_lflag) & ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN));
ensures termios_p->c_cflag == ((\old(termios_p->c_cflag) & ~(CSIZE|PARENB)) | CS8);
*/
void cfmakeraw (struct termios *termios_p);

/*@
requires \valid(termios_p);
assigns \result, *termios_p \from speed;
ensures \result == -1 || \result == 0;
*/
int cfsetspeed (struct termios *termios_p, speed_t speed);

#endif
