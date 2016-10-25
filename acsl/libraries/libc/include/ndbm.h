/*
 * ndbm.h
 *
 *  Created on: Jul 15, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_NDBM_H_
#define LIBC_NDBM_H_

#include "__fc_define_size_t.h"
#include "__fc_define_mode_t.h"

typedef struct datum {
    void *dptr;
    size_t dsize;
} datum;

typedef struct DBM {
    char dummy;
} DBM;

#define DBM_INSERT 0
#define DBM_REPLACE 1

/*@
axiomatic IsDbmOpen {
    logic boolean is_dbm_open{L}(DBM* db) reads *db;
}
*/

/*@
requires is_dbm_open(db);
assigns \result, *db \from *db;
*/
int dbm_clearerr(DBM *db);

/*@
requires is_dbm_open(db);
assigns *db \from *db;
ensures !is_dbm_open(db);
*/
void dbm_close(DBM *db);

/*@
requires is_dbm_open(db);
assigns \result, *db \from *db, key;
ensures \result <= 0;
*/
int dbm_delete(DBM *db, datum key);

/*@
requires is_dbm_open(db);
assigns \result \from *db;
*/
int dbm_error(DBM *db);

/*@
requires is_dbm_open(db);
assigns \result \from *db, key;
ensures \result.dptr != \null ==> \valid((char*)(\result.dptr));
*/
datum dbm_fetch(DBM *db, datum key);

/*@
requires is_dbm_open(db);
assigns \result \from *db;
ensures \result.dptr != \null ==> \valid((char*)(\result.dptr));
*/
datum dbm_firstkey(DBM *db);

/*@
requires is_dbm_open(db);
assigns \result \from *db;
ensures \result.dptr != \null ==> \valid((char*)(\result.dptr));
*/
datum dbm_nextkey(DBM *db);

/*@
requires \valid(file);
assigns \result \from file[..], open_flags, file_mode;
ensures \result != \null ==> (\valid(\result) && is_dbm_open(\result));
*/
DBM *dbm_open(const char *file, int open_flags, mode_t file_mode);

/*@
requires is_dbm_open(db);
assigns \result, *db \from *db, key, content, store_mode;
ensures \result <= 0;
*/
int dbm_store(DBM *db, datum key, datum content, int store_mode);

#endif /* LIBC_NDBM_H_ */
