/*
 * tftp.h
 *
 *  Created on: Jul 20, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_ARPA_TFTP_H_
#define LIBC_ARPA_TFTP_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#define SEGSIZE     512

#define RRQ   01
#define WRQ   02
#define DATA  03
#define ACK   04
#define ERROR 05

#define th_block th_u1.th_u2.th_u3.tu_block
#define th_code  th_u1.th_u2.th_u3.tu_code
#define th_stuff th_u1.tu_stuff
#define th_data  th_u1.th_u2.tu_data
#define th_msg   th_u1.th_u2.tu_data

#define EUNDEF    0
#define ENOTFOUND 1
#define EACCESS   2
#define ENOSPACE  3
#define EBADOP    4
#define EBADID    5
#define EEXISTS   6
#define ENOUSER   7

struct tftphdr {
    short th_opcode;
    union {
        char tu_padding[3];
        struct {
            union {
                unsigned short tu_block;
                short tu_code;
            } th_u3;
            char tu_data[0];
        } th_u2;
        char tu_stuff[0];
    } th_u1;
};

#endif /* LIBC_ARPA_TFTP_H_ */
