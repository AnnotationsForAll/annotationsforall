/*
 * stab.h
 *
 *  Created on: Jul 19, 2016
 *      Author: jrobbins
 */

#ifndef STAB_H_
#define STAB_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#define N_GSYM   0x20
#define N_FNAME  0x22
#define N_FUN    0x24
#define N_STSYM  0x26
#define N_LCSYM  0x28
#define N_MAIN   0x2a
#define N_PC     0x30
#define N_NSYMS  0x32
#define N_NOMAP  0x34
#define N_OBJ    0x38
#define N_OPT    0x3c
#define N_RSYM   0x40
#define N_M2C    0x42
#define N_SLINE  0x44
#define N_DSLINE 0x46
#define N_BSLINE 0x48
#define N_BROWS  0x48
#define N_DEFD   0x4a
#define N_EHDECL 0x50
#define N_MOD2   0x50
#define N_CATCH  0x54
#define N_SSYM   0x60
#define N_SO     0x64
#define N_LSYM   0x80
#define N_BINCL  0x82
#define N_SOL    0x84
#define N_PSYM   0xa0
#define N_EINCL  0xa2
#define N_ENTRY  0xa4
#define N_LBRAC  0xc0
#define N_EXCL   0xc2
#define N_SCOPE  0xc4
#define N_RBRAC  0xe0
#define N_BCOMM  0xe2
#define N_ECOMM  0xe4
#define N_ECOML  0xe8
#define N_NBTEXT 0xf0
#define N_NBDATA 0xf2
#define N_NBBSS  0xf4
#define N_NBSTS  0xf6
#define N_NBLCS  0xf8
#define N_LENG   0xfe

#define LAST_UNUSED_STAB_CODE 0xff

#endif /* STAB_H_ */
