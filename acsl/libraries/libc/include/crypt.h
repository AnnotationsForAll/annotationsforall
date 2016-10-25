/*
 * crypt.h
 *
 *  Created on: Jul 13, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_CRYPT_H_
#define LIBC_CRYPT_H_

#include "__fc_string_axiomatic.h"
#include "errno.h"

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

struct crypt_data {
    char keysched[16 * 8];
    char sb0[32768];
    char sb1[32768];
    char sb2[32768];
    char sb3[32768];
    char crypt_3_buf[14];
    char current_salt[2];
    long int current_saltbits;
    int direction, initialized;
};

/*@
requires \valid_read(key) && \valid_read(salt);
assigns \result, errno \from key[0..], salt[0..];
ensures \result != \null ==> valid_string(\result);
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
char *crypt(const char *key, const char *salt);

/*@
requires \valid(block+(0..63));
requires edflag== 0 || edflag == 1;
assigns errno, block[0..63] \from block[0..63], edflag;
*/
void encrypt(char block[64], int edflag);

/*@
requires \valid(key+(0..63));
assigns errno \from key[0..63];
*/
void setkey(const char *key);

/*@
axiomatic CryptData {
    logic boolean is_crypt_data_init(struct crypt_data * data) reads *data;
}
*/

/*@
requires valid_read_string(key) && valid_read_string(salt);
requires \valid(data);
requires data->initialized != 0 ==> is_crypt_data_init(data);
assigns \result, errno, *data \from key[0..], salt[0..], *data;
ensures is_crypt_data_init(data);
ensures data->initialized != 0;
ensures \result != \null ==> valid_string(\result);
ensures \result == \null ? errno != 0 : errno == \old(errno);
*/
char * crypt_r(const char *key, const char *salt, struct crypt_data * data);

/*@
requires \valid_read(key+(0..63));
requires \valid(data);
requires data->initialized != 0 ==> is_crypt_data_init(data);
assigns errno, *data \from key[0..63], *data;
ensures is_crypt_data_init(data);
ensures data->initialized != 0;
*/
void setkey_r(const char *key, struct crypt_data * data);

/*@
requires \valid(block+(0..63));
requires edflag== 0 || edflag == 1;
requires \valid(data);
requires data->initialized != 0 ==> is_crypt_data_init(data);
assigns errno, *data, block[0..63] \from block[0..63], edflag, *data;
ensures is_crypt_data_init(data);
ensures data->initialized != 0;
*/
void encrypt_r(char *block, int edflag, struct crypt_data * data);

#endif /* LIBC_CRYPT_H_ */
