/*
 * endian.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_ENDIAN_H_
#define LIBC_ENDIAN_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "__fc_machdep.h"
#include "__gt_fc_define_alternative_types.h"
#include "byteswap.h"

#define LITTLE_ENDIAN __LITTLE_ENDIAN
#define BIG_ENDIAN    __BIG_ENDIAN
#define PDP_ENDIAN    __PDP_ENDIAN

#define BYTE_ORDER       __FC_BYTE_ORDER
#define FLOAT_WORD_ORDER __FC_BYTE_ORDER //FIXME: make this depend on the correct machdep

// TODO: PDP endianess must be considered, as unlikely as it is. Do modern systems support it?

/*@
assigns \result \from host;
ensures BYTE_ORDER == LITTLE_ENDIAN ==> \result == bswap_16(host);
ensures BYTE_ORDER == BIG_ENDIAN ==> \result == host;
*/
uint16_t htobe16(uint16_t host);

/*@
assigns \result \from host;
ensures BYTE_ORDER == BIG_ENDIAN ==> \result == bswap_16(host);
ensures BYTE_ORDER == LITTLE_ENDIAN ==> \result == host;
*/
uint16_t htole16(uint16_t host);

/*@
assigns \result \from be;
ensures BYTE_ORDER == LITTLE_ENDIAN ==> \result == bswap_16(be);
ensures BYTE_ORDER == BIG_ENDIAN ==> \result == be;
*/
uint16_t be16toh(uint16_t be);

/*@
assigns \result \from le;
ensures BYTE_ORDER == BIG_ENDIAN ==> \result == bswap_16(le);
ensures BYTE_ORDER == LITTLE_ENDIAN ==> \result == le;
*/
uint16_t le16toh(uint16_t le);



/*@
assigns \result \from host;
ensures BYTE_ORDER == LITTLE_ENDIAN ==> \result == bswap_32(host);
ensures BYTE_ORDER == BIG_ENDIAN ==> \result == host;
*/
uint32_t htobe32(uint32_t host);

/*@
assigns \result \from host;
ensures BYTE_ORDER == BIG_ENDIAN ==> \result == bswap_32(host);
ensures BYTE_ORDER == LITTLE_ENDIAN ==> \result == host;
*/
uint32_t htole32(uint32_t host);

/*@
assigns \result \from be;
ensures BYTE_ORDER == LITTLE_ENDIAN ==> \result == bswap_32(be);
ensures BYTE_ORDER == BIG_ENDIAN ==> \result == be;
*/
uint32_t be32toh(uint32_t be);

/*@
assigns \result \from le;
ensures BYTE_ORDER == BIG_ENDIAN ==> \result == bswap_32(le);
ensures BYTE_ORDER == LITTLE_ENDIAN ==> \result == le;
*/
uint32_t le32toh(uint32_t le);



/*@
assigns \result \from host;
ensures BYTE_ORDER == LITTLE_ENDIAN ==> \result == bswap_64(host);
ensures BYTE_ORDER == BIG_ENDIAN ==> \result == host;
*/
uint64_t htobe64(uint64_t host);

/*@
assigns \result \from host;
ensures BYTE_ORDER == BIG_ENDIAN ==> \result == bswap_64(host);
ensures BYTE_ORDER == LITTLE_ENDIAN ==> \result == host;
*/
uint64_t htole64(uint64_t host);

/*@
assigns \result \from be;
ensures BYTE_ORDER == LITTLE_ENDIAN ==> \result == bswap_64(be);
ensures BYTE_ORDER == BIG_ENDIAN ==> \result == be;
*/
uint64_t be64toh(uint64_t be);

/*@
assigns \result \from le;
ensures BYTE_ORDER == BIG_ENDIAN ==> \result == bswap_64(le);
ensures BYTE_ORDER == LITTLE_ENDIAN ==> \result == le;
*/
uint64_t le64toh(uint64_t le);

// Also include the equivalent BSD version of these functions
#define betoh16 be16toh
#define letoh16 le16toh
#define betoh32 be32toh
#define letoh32 le32toh
#define betoh64 be64toh
#define letoh64 le64toh

#endif /* LIBC_ENDIAN_H_ */
