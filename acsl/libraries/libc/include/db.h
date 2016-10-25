/*
 * db.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_DB_H_
#define LIBC_DB_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.
// FIXME: Is this part of libdb, or its own interface? Either way, this header is deprecated under Linux.

#include "__gt_fc_define_alternative_types.h"
#include "__fc_define_size_t.h"
#include "__fc_string_axiomatic.h"
#include "errno.h"

#define DB_BTREE 0
#define DB_HASH  1
#define DB_RECNO 2

#define RET_ERROR    -1
#define RET_SUCCESS  0
#define RET_SPECIAL  1

#define R_CURSOR      (1 << 0)

#define R_IAFTER      (1 << 1)
#define R_IBEFORE     (1 << 2)
#define R_NOOVERWRITE (1 << 3)
#define R_SETCURSOR   (1 << 4)

#define R_FIRST       (1 << 1)
#define R_LAST        (1 << 2)
#define R_NEXT        (1 << 3)
#define R_PREV        (1 << 4)

#define R_RECNOSYNC   (1 << 0)

#define R_DUP         (1 << 0)

#define R_FIXEDLEN    (1 << 0)
#define R_NOKEY       (1 << 1)
#define R_SNAPSHOT    (1 << 2)

#define MAX_PAGE_NUMBER 0xffffffff
#define MAX_PAGE_OFFSET 65535
#define MAX_REC_NUMBER  0xffffffff

#define BTREEMAGIC   0x053162
#define BTREEVERSION 3

typedef int DBTYPE;
typedef uint32_t pgno_t;
typedef uint16_t indx_t;
typedef uint32_t recno_t;

typedef struct {
    void *data;
    size_t size;
} DBT;

typedef struct {
    unsigned long flags;
    unsigned int cachesize;
    int maxkeypage;
    int minkeypage;
    unsigned int psize;
    int (*compare)(const DBT *key1, const DBT *key2);
    size_t (*prefix)(const DBT *key1, const DBT *key2);
    int lorder;
} BTREEINFO;

typedef struct {
    unsigned int bsize;
    unsigned int ffactor;
    unsigned int nelem;
    unsigned int cachesize;
    uint32_t (*hash)(const void *, size_t);
    int lorder;
} HASHINFO;

typedef struct {
    unsigned long flags;
    unsigned int cachesize;
    unsigned int psize;
    int lorder;
    size_t reclen;
    unsigned char bval;
    char *bfname;
} RECNOINFO;

typedef struct DB DB;
struct DB {
    DBTYPE type;
    int (*close)(const DB *db);
    int (*del)(const DB *db, const DBT *key, unsigned int flags);
    int (*fd)(const DB *db);
    int (*get)(const DB *db, DBT *key, DBT *data, unsigned int flags);
    int (*put)(const DB *db, DBT *key, const DBT *data, unsigned int flags);
    int (*sync)(const DB *db, unsigned int flags);
    int (*seq)(const DB *db, DBT *key, DBT *data, unsigned int flags);
};

/*@
requires file != \null ==> valid_read_string(file);
requires type == DB_BTREE || type == DB_HASH || type == DB_RECNO;
ensures \result != \null ==> \valid(\result);
ensures \result == \null ? errno != 0 : errno == \old(errno);
behavior mode_btree:
    assumes type == DB_BTREE;
    requires openinfo != \null ==> \valid((BTREEINFO*)openinfo);
    assigns errno, \result \from file[0..strlen(file)], flags, mode, type, *((BTREEINFO*)openinfo);
    ensures \result != \null ==> \result->type == DB_BTREE;
behavior mode_hash:
    assumes type == DB_HASH;
    requires openinfo != \null ==> \valid((HASHINFO*)openinfo);
    assigns errno, \result \from file[0..strlen(file)], flags, mode, type, *((HASHINFO*)openinfo);
    ensures \result != \null ==> \result->type == DB_HASH;
behavior mode_recno:
    assumes type == DB_RECNO;
    requires openinfo != \null ==> \valid((RECNOINFO*)openinfo);
    assigns errno, \result \from file[0..strlen(file)], flags, mode, type, *((RECNOINFO*)openinfo);
    ensures \result != \null ==> \result->type == DB_RECNO;
complete behaviors; disjoint behaviors;
*/
DB *dbopen(const char *file, int flags, int mode, DBTYPE type, const void *openinfo);

#endif /* LIBC_DB_H_ */
