/*
 * aio.h
 *
 *  Created on: Jul 16, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_AIO_H_
#define LIBC_AIO_H_

#include "__fc_define_timespec.h"
#include "sys/types.h"
#include "signal.h"
#include "errno.h"

struct aiocb {
    int             aio_fildes;     //File descriptor. 
    off_t           aio_offset;     //File offset. 
    volatile void  *aio_buf;        //Location of buffer. 
    size_t          aio_nbytes;     //Length of transfer. 
    int             aio_reqprio;    //Request priority offset. 
    struct sigevent aio_sigevent;   //Signal number and value. 
    int             aio_lio_opcode; //Operation to be performed. 
};

#define AIO_ALLDONE 0
#define AIO_CANCELLED 1
#define AIO_NOTCANCELED 2

#define LIO_NOP 0
#define LIO_NOWAIT 1
#define LIO_READ 2
#define LIO_WAIT 3
#define LIO_WRITE 4

/*@
requires aiocbp != \null ==> \valid(aiocbp);
assigns \result, *aiocbp, errno \from fildes, *aiocbp;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int aio_cancel(int fildes, struct aiocb *aiocbp);

/*@
requires \valid(aiocbp);
assigns \result, errno \from *aiocbp;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int aio_error(const struct aiocb *aiocbp);

/*@
requires \valid(aiocbp);
assigns \result, errno \from *aiocbp;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int aio_read(struct aiocb *aiocbp);

/*@
requires \valid(aiocbp);
assigns \result, errno \from *aiocbp;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t aio_return(struct aiocb *aiocbp);

/*@
requires \valid(list+(0..nent-1));
requires timeout != \null ==> \valid(timeout);
assigns \result, errno \from list[0..nent-1], nent, *timeout;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int aio_suspend(const struct aiocb *const list[], int nent, const struct timespec *timeout);

/*@
requires \valid(aiocbp);
assigns \result, errno \from *aiocbp;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int aio_write(struct aiocb *aiocbp);

/*@
requires \valid(list+(0..nent-1));
requires \valid(sig);
assigns \result, errno \from list[0..nent-1], nent, *sig, mode;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int lio_listio(int mode, struct aiocb *restrict const list[restrict], int nent, struct sigevent *restrict sig);

/* GNU Extensions */

struct aioinit {
    int aio_threads;
    int aio_num;
    int aio_locks;
    int aio_usedba;
    int aio_debug;
    int aio_numusers;
    int aio_reserved[2];
};

/*@
requires \valid(aiocbp);
assigns \result, errno \from *aiocbp, op;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int aio_fsync (int op, struct aiocb *aiocbp);

/*@
requires \valid(init);
assigns errno \from *init;
*/
void aio_init (const struct aioinit *init);

struct aiocb64 {
    int             aio_fildes;     //File descriptor.
    off64_t           aio_offset;     //File offset.
    volatile void  *aio_buf;        //Location of buffer.
    size_t          aio_nbytes;     //Length of transfer.
    int             aio_reqprio;    //Request priority offset.
    struct sigevent aio_sigevent;   //Signal number and value.
    int             aio_lio_opcode; //Operation to be performed.
};

/*@
requires aiocbp != \null ==> \valid(aiocbp);
assigns \result, *aiocbp, errno \from fildes, *aiocbp;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int aio_cancel64(int fildes, struct aiocb64 *aiocbp);

/*@
requires \valid(aiocbp);
assigns \result, errno \from *aiocbp;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int aio_error64(const struct aiocb64 *aiocbp);

/*@
requires \valid(aiocbp);
assigns \result, errno \from *aiocbp;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int aio_read64(struct aiocb64 *aiocbp);

/*@
requires \valid(aiocbp);
assigns \result, errno \from *aiocbp;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
ssize_t aio_return64(struct aiocb64 *aiocbp);

/*@
requires \valid(list+(0..nent-1));
requires timeout != \null ==> \valid(timeout);
assigns \result, errno \from list[0..nent-1], nent, *timeout;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int aio_suspend64(const struct aiocb64 *const list[], int nent, const struct timespec *timeout);

/*@
requires \valid(aiocbp);
assigns \result, errno \from *aiocbp;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int aio_write64(struct aiocb64 *aiocbp);

/*@
requires \valid(list+(0..nent-1));
requires \valid(sig);
assigns \result, errno \from list[0..nent-1], nent, *sig, mode;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int lio_listio64(int mode, struct aiocb64 *restrict const list[restrict], int nent, struct sigevent *restrict sig);

/*@
requires \valid(aiocbp);
assigns \result, errno \from *aiocbp, op;
ensures \result == 0 || \result == -1;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int aio_fsync64(int op, struct aiocb64 *aiocbp);


#endif /* LIBC_AIO_H_ */
