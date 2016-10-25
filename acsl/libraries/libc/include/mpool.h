/*
 * mpool.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_MPOOL_H_
#define LIBC_MPOOL_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.
// FIXME: Is this part of libdb, or its own interface? Either way, this header is deprecated under Linux.

#include "db.h"
#include "sys/queue.h"
#include "errno.h"

#define MPOOL_DIRTY  (1 << 0)
#define MPOOL_PINNED (1 << 1)

#define HASHSIZE      128
#define HASHKEY(pgno) ((pgno - 1) % HASHSIZE)

typedef struct MPOOL {
    CIRCLEQ_HEAD(_lqh, _bkt) lqh;
    CIRCLEQ_HEAD(_hqh, _bkt) hqh[HASHSIZE];
    pgno_t curcache;
    pgno_t maxcache;
    pgno_t npages;
    u_long pagesize;
    int fd;
    void (*pgin)(void *, pgno_t, void *);
    void (*pgout)(void *, pgno_t, void *);
    void *pgcookie;

    u_long  cachehit;
    u_long  cachemiss;
    u_long  pagealloc;
    u_long  pageflush;
    u_long  pageget;
    u_long  pagenew;
    u_long  pageput;
    u_long  pageread;
    u_long  pagewrite;
} MPOOL;

typedef struct _bkt {
    CIRCLEQ_ENTRY(_bkt) hq;
    CIRCLEQ_ENTRY(_bkt) q;
    void *page;
    pgno_t pgno;
    u_int8_t flags;
} BKT;

/*@
axiomatic MPool {
    logic boolean is_mpool_open(MPOOL* mp) reads *mp;
    logic boolean mpool_page_addr(pgno_t pgno, void* page);

    axiom unique_page_addr: \forall pgno_t p1; \forall pgno_t p2; \forall void* x1; \forall void* x2; mpool_page_addr(p1, x1) || mpool_page_addr(p2, x2) ==> p1 == p2 && x1 == x2;
}
*/

/*@
requires key != \null ==> \valid_read(((char*)(key->data))+(0..key->size-1));
assigns errno, \result;
ensures \result != \null ==> \valid(\result);
ensures \result != \null ==> is_mpool_open(\result);
ensures \result != \null ==> \result->pagesize == pagesize;
ensures \result != \null ==> \result->maxcache == maxcache;
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
MPOOL *mpool_open(DBT *key, int fd, pgno_t pagesize, pgno_t maxcache);

/*@
requires \valid(mp);
requires is_mpool_open(mp);
assigns errno, mp->pgin, mp->pgout, mp->pgcookie;
ensures is_mpool_open(mp);
ensures mp->pgin == pgin;
ensures mp->pgout == pgout;
ensures mp->pgcookie == pgcookie;
*/
void mpool_filter(MPOOL *mp, void (*pgin)(void *, pgno_t, void *), void (*pgout)(void *, pgno_t, void *), void *pgcookie);

/*@
requires \valid(mp);
requires is_mpool_open(mp);
requires \valid(pgnoaddr);
assigns errno, \result, *mp, *pgnoaddr;
ensures is_mpool_open(mp);
ensures \result != \null ==> \valid(((char*)\result)+(0..mp->pagesize-1));
ensures \result != \null ==> mpool_page_addr(*pgnoaddr, \result);
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
void *mpool_new(MPOOL *mp, pgno_t *pgnoaddr);

/*@
requires \valid(mp);
requires is_mpool_open(mp);
requires \exists void* x; mpool_page_addr(pgno, x);
assigns errno, \result, *mp;
ensures is_mpool_open(mp);
ensures \result != \null ==> \valid(((char*)\result)+(0..mp->pagesize-1));
ensures \result != \null ==> mpool_page_addr(pgno, \result);
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
void *mpool_get(MPOOL *mp, pgno_t pgno, unsigned int flags);

/*@
requires \valid(mp);
requires is_mpool_open(mp);
requires \exists pgno_t x; mpool_page_addr(x, pgaddr);
assigns errno, \result, *mp;
ensures is_mpool_open(mp);
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mpool_put(MPOOL *mp, void *pgaddr, unsigned int flags);

/*@
requires \valid(mp);
requires is_mpool_open(mp);
assigns errno, \result, *mp;
ensures is_mpool_open(mp);
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mpool_sync(MPOOL *mp);

/*@
requires \valid(mp);
requires is_mpool_open(mp);
assigns errno, \result, *mp;
ensures !is_mpool_open(mp);
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int mpool_close(MPOOL *mp);

/*@
requires \valid(mp);
requires is_mpool_open(mp);
assigns errno, *mp;
ensures is_mpool_open(mp);
*/
void mpool_stat(MPOOL *mp);

#endif /* LIBC_MPOOL_H_ */
