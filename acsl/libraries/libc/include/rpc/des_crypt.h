/*
 * des_crypt.h
 *
 *  Created on: Jul 13, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_RPC_DES_CRYPT_H_
#define LIBC_RPC_DES_CRYPT_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#define DES_FAILED(err) ((err) < 0)

#define DES_ENCRYPT 1
#define DES_DECRYPT 2
#define DES_HW      4
#define DES_SW      8

#define DESERR_NONE       0
#define DESERR_NOHWDEVICE -1
#define DESERR_HWERROR    -2
#define DESERR_BADPARAM   -3

#define DES_DEVMASK (1 << 1)
#define DES_HW      (0*DES_DEVMASK)
#define DES_SW      (1*DES_DEVMASK)

/*@
requires \valid(key+(0..7));
requires \valid(blocks+(0..len-1));
requires len % 8 == 0;
assigns blocks[0..len-1] \from key[0..7], mode;
ensures \result == DESERR_NONE || DES_FAILED(\result);
*/
int ecb_crypt (char *key, char *blocks, unsigned len, unsigned mode);

/*@
requires \valid(key+(0..7));
requires \valid(blocks+(0..len-1));
requires \valid(ivec+(0..7));
requires len % 8 == 0;
assigns blocks[0..len-1], ivec[0..7] \from key[0..7], mode, ivec[0..7];
ensures \result == DESERR_NONE || DES_FAILED(\result);
*/
int cbc_crypt (char *key, char *blocks, unsigned len, unsigned mode, char *ivec);

/*@
requires \valid(key+(0..7));
assigns key[0..7] \from key[0..7];
ensures \forall int i; 0 <= i <= 7 ==> (key[i] == (0x6996 >> ((\old(key[i]) ^ (\old(key[i]) >> 4)) & 0xf)));
*/
void des_setparity (char *key);

// FIXME: glibc gives you these functions for use, but doesn't declare them first.
// Users have to declare them manually, then call them.
// In this case, Frama-C should not error if the declarations are the same, which they should be.

void passwd2des(char *passwd, char *key);
int xencrypt(char *secret, char *passwd);
int xdecrypt(char *secret, char *passwd);

#endif /* LIBC_RPC_DES_CRYPT_H_ */
