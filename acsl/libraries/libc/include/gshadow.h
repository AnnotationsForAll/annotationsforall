/*
 * gshadow.h
 *
 *  Created on: Jul 19, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_GSHADOW_H_
#define LIBC_GSHADOW_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "__fc_define_size_t.h"
#include "__fc_define_file.h"
#include "__fc_string_axiomatic.h"
#include "__gt_fc_file_axioms.h"
#include "paths.h"
#include "errno.h"

#define GSHADOW _PATH_GSHADOW

struct sgrp {
    char *sg_namp;
    char *sg_passwd;
    char **sg_adm;
    char **sg_mem;
};

/*@
assigns \nothing;
*/
void setsgent(void);

/*@
assigns \nothing;
*/
void endsgent(void);

/*@
assigns \result;
ensures \result != \null ==> \valid(\result);
*/
struct sgrp *getsgent(void);

/*@
requires valid_read_string(name);
assigns \result;
ensures \result != \null ==> \valid(\result);
*/
struct sgrp *getsgnam(const char *name);

/*@
requires valid_read_string(name);
assigns \result;
ensures \result != \null ==> \valid(\result);
*/
struct sgrp *sgetsgent(const char *name);

/*@
requires file_is_open(stream);
assigns \result \from stream;
ensures \result != \null ==> \valid(\result);
*/
struct sgrp *fgetsgent(FILE *stream);

/*@
requires file_is_open(stream);
requires \valid_read(p);
assigns errno, \result, *stream \from *p, *stream;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int putsgent(const struct sgrp *p, FILE *stream);

/*@
requires \valid(result_buf);
requires \valid(buffer+(0..buflen-1));
requires \valid(result);
assigns errno, \result, *result, *result_buf, buffer[0..buflen-1];
ensures \result != 0 ==> *result == \null;
ensures \result == 0 ==> *result == result_buf;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int getsgent_r(struct sgrp *result_buf, char *buffer, size_t buflen, struct sgrp **result);

/*@
requires valid_read_string(name);
requires \valid(result_buf);
requires \valid(buffer+(0..buflen-1));
requires \valid(result);
assigns errno, \result, *result, *result_buf, buffer[0..buflen-1];
ensures \result != 0 ==> *result == \null;
ensures \result == 0 ==> *result == result_buf;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int getsgnam_r(const char *name, struct sgrp *result_buf, char *buffer, size_t buflen, struct sgrp **result);

/*@
requires valid_read_string(name);
requires \valid(result_buf);
requires \valid(buffer+(0..buflen-1));
requires \valid(result);
assigns errno, \result, *result, *result_buf, buffer[0..buflen-1];
ensures \result != 0 ==> *result == \null;
ensures \result == 0 ==> *result == result_buf;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int sgetsgent_r(const char *name, struct sgrp *result_buf, char *buffer, size_t buflen, struct sgrp **result);

/*@
requires file_is_open(stream);
requires \valid(result_buf);
requires \valid(buffer+(0..buflen-1));
requires \valid(result);
assigns errno, \result, *result, *result_buf, buffer[0..buflen-1];
ensures \result != 0 ==> *result == \null;
ensures \result == 0 ==> *result == result_buf;
ensures \result != 0 ? errno != 0 : errno == \old(errno);
*/
int fgetsgent_r(FILE *stream, struct sgrp *result_buf, char *buffer, size_t buflen, struct sgrp **result);

#endif /* LIBC_GSHADOW_H_ */
