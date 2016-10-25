/*
 * stropts.h
 *
 *  Created on: Jun 30, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_STROPTS_H_
#define LIBC_STROPTS_H_

// This POSIX header is marked obselescent. Do not use for new work.

#include "stdint.h"
#include "unistd.h"
#include "errno.h"

#define I_ATMARK    1
#define I_CANPUT    2
#define I_CKBAND    3
#define I_FDINSERT  4
#define I_FIND      5
#define I_FLUSH     6
#define I_FLUSHBAND 7
#define I_GETBAND   8
#define I_GETCLTIME 9
#define I_GETSIG    10
#define I_GRDOPT    11
#define I_LINK      12
#define I_LIST      13
#define I_LOOK      14
#define I_NREAD     15
#define I_PEEK      16
#define I_PLINK     17
#define I_POP       18
#define I_PUNLINK   19
#define I_PUSH      20
#define I_RECVFD    21
#define I_SENDFD    22
#define I_SETCLTIME 23
#define I_SETSIG    24
#define I_SRDOPT    25
#define I_STR       26
#define I_SWROPT    27
#define I_UNLINK    28

#define FMNAMESZ 8 //arbitrary value

#define FLUSHR    1
#define FLUSHRW   2
#define FLUSHW    3
#define FLUSHBAND 4

#define S_BANDURG 1
#define S_ERROR   2
#define S_HANGUP  3
#define S_HIPRI   4
#define S_INPUT   5
#define S_MSG     6
#define S_OUTPUT  7
#define S_RDBAND  8
#define S_RDNORM  9
#define S_WRBAND  10
#define S_WRNORM  11

#define RS_HIPRI 1

#define RMSGD     1
#define RMSGN     2
#define RNMORN    3
#define RPROTDAT  4
#define RPROTDIS  5
#define RPROTNORM 6

#define SNDZERO 1
#define SNDPIPE 2

#define ANYMARK  1
#define LASTMARK 2

#define MORECTL   1
#define MOREDATA  2
#define MSG_ANY   1
#define MSG_BAND  2
#define MSG_HIPRI 4

#define MUXID_ALL (-1)

typedef int32_t t_scalar_t;
typedef uint32_t t_uscalar_t;

struct bandinfo {
    int bi_flag;
    unsigned char bi_pri;
};

struct strbuf {
    char* buf;
    int len;
    int maxlen;
};

struct strpeek {
    struct strbuf ctlbuf;
    struct strbuf databuf;
    t_uscalar_t flags;
};

struct strfdinsert {
    struct strbuf ctlbuf;
    struct strbuf databuf;
    int fildes;
    t_uscalar_t flags;
    int offset;
};

struct strioctl {
    int ic_cmd;
    char* ic_dp;
    int ic_len;
    int ic_timeout;
};

struct strrecvfd {
    int fd;
    gid_t gid;
    uid_t uid;
};

struct str_list {
    struct str_mlist* sl_modlist;
    int sl_nmods;
};

struct str_mlist {
    char l_name[FMNAMESZ+1];
};

/*@
requires valid_read_string(path);
assigns \result, errno \from fildes, path[0..];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int fattach(int fildes, const char* path);

/*@
requires valid_read_string(path);
assigns \result, errno \from path[0..];
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int fdetach(const char* path);

/*@
requires \valid(flagsp);
requires ctlptr != \null ==> \valid(ctlptr);
requires dataptr != \null ==> \valid(dataptr);
requires ctlptr != \null ==> ctlptr->maxlen >= -1;
requires dataptr != \null ==> dataptr->maxlen >= -1;
requires ctlptr != \null ==> ctlptr->maxlen != -1 ==> \valid(ctlptr->buf+(0..ctlptr->maxlen-1));
requires dataptr != \null ==> dataptr->maxlen != -1 ==> \valid(dataptr->buf+(0..dataptr->maxlen-1));
assigns \result, errno, ctlptr->len, ctlptr->buf[0..ctlptr->maxlen-1], dataptr->len, dataptr->buf[0..dataptr->maxlen-1], *flagsp \from fildes, ctlptr->maxlen, dataptr->maxlen, *flagsp;
ensures ctlptr != \null ==> (-1 <= ctlptr->len <= ctlptr->maxlen);
ensures dataptr != \null ==> (-1 <= dataptr->len <= dataptr->maxlen);
ensures \result == -1 || \result == 0 || \result == MORECTL || \result == MOREDATA || \result == (MORECTL | MOREDATA);
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int getmsg(int fildes, struct strbuf* restrict ctlptr, struct strbuf* restrict dataptr, int* restrict flagsp);

/*@
requires \valid(flagsp);
requires \valid(bandp);
requires ctlptr != \null ==> \valid(ctlptr);
requires dataptr != \null ==> \valid(dataptr);
requires ctlptr != \null ==> ctlptr->maxlen >= -1;
requires dataptr != \null ==> dataptr->maxlen >= -1;
requires ctlptr != \null ==> ctlptr->maxlen != -1 ==> \valid(ctlptr->buf+(0..ctlptr->maxlen-1));
requires dataptr != \null ==> dataptr->maxlen != -1 ==> \valid(dataptr->buf+(0..dataptr->maxlen-1));
assigns \result, errno, ctlptr->len, ctlptr->buf[0..ctlptr->maxlen-1], dataptr->len, dataptr->buf[0..dataptr->maxlen-1], *bandp, *flagsp \from fildes, ctlptr->maxlen, dataptr->maxlen, *bandp, *flagsp;
ensures ctlptr != \null ==> (-1 <= ctlptr->len <= ctlptr->maxlen);
ensures dataptr != \null ==> (-1 <= dataptr->len <= dataptr->maxlen);
ensures \result == -1 || \result == 0 || \result == MORECTL || \result == MOREDATA || \result == (MORECTL | MOREDATA);
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int getpmsg(int fildes, struct strbuf* restrict ctlptr, struct strbuf* restrict dataptr, int* restrict bandp, int* restrict flagsp);

/*@
assigns \result, errno \from fildes, request;
ensures \result >= -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int ioctl(int fildes, int request, ...);

/*@
assigns \result, errno \from fildes;
ensures -1 <= \result <= 1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int isastream(int fildes);

/*@
requires ctlptr != \null ==> \valid_read(ctlptr);
requires dataptr != \null ==> \valid_read(dataptr);
requires ctlptr != \null ==> ctlptr->len >= -1;
requires dataptr != \null ==> dataptr->len >= -1;
requires ctlptr != \null ==> ctlptr->len != -1 ==> \valid_read(ctlptr->buf+(0..ctlptr->len-1));
requires dataptr != \null ==> dataptr->len != -1 ==> \valid_read(dataptr->buf+(0..dataptr->len-1));
assigns \result, errno \from fildes, ctlptr->buf[0..ctlptr->len-1], ctlptr->len, dataptr->buf[0..dataptr->len-1], dataptr->len, flags;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int putmsg(int fildes, const struct strbuf* ctlptr, const struct strbuf* dataptr, int flags);

/*@
requires ctlptr != \null ==> \valid_read(ctlptr);
requires dataptr != \null ==> \valid_read(dataptr);
requires ctlptr != \null ==> ctlptr->len >= -1;
requires dataptr != \null ==> dataptr->len >= -1;
requires ctlptr != \null ==> ctlptr->len != -1 ==> \valid_read(ctlptr->buf+(0..ctlptr->len-1));
requires dataptr != \null ==> dataptr->len != -1 ==> \valid_read(dataptr->buf+(0..dataptr->len-1));
assigns \result, errno \from fildes, ctlptr->buf[0..ctlptr->len-1], ctlptr->len, dataptr->buf[0..dataptr->len-1], dataptr->len, band, flags;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int putpmsg(int fildes, const struct strbuf* ctlptr, const struct strbuf* dataptr, int band, int flags);

#endif /* LIBC_STROPTS_H_ */
