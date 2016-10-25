/*
 * tcp.h
 *
 *  Created on: Jul 21, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_NETINET_TCP_H_
#define LIBC_NETINET_TCP_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../endian.h"

#define TCP_NODELAY              1
#define TCP_MAXSEG               2
#define TCP_CORK                 3
#define TCP_KEEPIDLE             4
#define TCP_KEEPINTVL            5
#define TCP_KEEPCNT              6
#define TCP_SYNCNT               7
#define TCP_LINGER2              8
#define TCP_DEFER_ACCEPT         9
#define TCP_WINDOW_CLAMP         10
#define TCP_INFO                 11
#define TCP_QUICKACK             12
#define TCP_CONGESTION           13
#define TCP_MD5SIG               14
#define TCP_COOKIE_TRANSACTIONS  15
#define TCP_THIN_LINEAR_TIMEOUTS 16
#define TCP_THIN_DUPACK          17
#define TCP_USER_TIMEOUT         18
#define TCP_REPAIR               19
#define TCP_REPAIR_QUEUE         20
#define TCP_QUEUE_SEQ            21
#define TCP_REPAIR_OPTIONS       22
#define TCP_FASTOPEN             23
#define TCP_TIMESTAMP            24
#define TCP_NOTSENT_LOWAT        25
#define TCP_CC_INFO              26
#define TCP_SAVE_SYN             27
#define TCP_SAVED_SYN            28

#define TCP_ESTABLISHED 1
#define TCP_SYN_SENT    2
#define TCP_SYN_RECV    3
#define TCP_FIN_WAIT1   4
#define TCP_FIN_WAIT2   5
#define TCP_TIME_WAIT   6
#define TCP_CLOSE       7
#define TCP_CLOSE_WAI,  8
#define TCP_LAST_ACK    9
#define TCP_LISTEN      10
#define TCP_CLOSING     11

#define TCPOPT_EOL             0
#define TCPOPT_NOP             1
#define TCPOPT_MAXSEG          2
#define TCPOLEN_MAXSEG         4
#define TCPOPT_WINDOW          3
#define TCPOLEN_WINDOW         3
#define TCPOPT_SACK_PERMITTED  4
#define TCPOLEN_SACK_PERMITTED 2
#define TCPOPT_SACK            5
#define TCPOPT_TIMESTAMP       8
#define TCPOLEN_TIMESTAMP      10
#define TCPOLEN_TSTAMP_APPA    (TCPOLEN_TIMESTAMP+2)

#define TCPOPT_TSTAMP_HDR (TCPOPT_NOP<<24|TCPOPT_NOP<<16|TCPOPT_TIMESTAMP<<8|TCPOLEN_TIMESTAMP)

#define TCP_MSS 512

#define TCP_MAXWIN 65535

#define TCP_MAX_WINSHIFT 14

#define SOL_TCP 6

#define TCPI_OPT_TIMESTAMPS 1
#define TCPI_OPT_SACK       2
#define TCPI_OPT_WSCALE     4
#define TCPI_OPT_ECN        8
#define TCPI_OPT_ECN_SEEN   16
#define TCPI_OPT_SYN_DATA   32

#define TCP_MD5SIG_MAXKEYLEN 80

#define TCP_NO_QUEUE   0
#define TCP_RECV_QUEUE 1
#define TCP_SEND_QUEUE 2
#define TCP_QUEUES_NR  3

#define TCP_COOKIE_MIN       8
#define TCP_COOKIE_MAX       16
#define TCP_COOKIE_PAIR_SIZE (2*TCP_COOKIE_MAX)

#define TCP_COOKIE_IN_ALWAYS (1 << 0)
#define TCP_COOKIE_OUT_NEVER (1 << 1)
#define TCP_S_DATA_IN        (1 << 2)
#define TCP_S_DATA_OUT       (1 << 3)

#define TCP_MSS_DEFAULT  536U
#define TCP_MSS_DESIRED 1220U

# define TH_FIN  0x01
# define TH_SYN  0x02
# define TH_RST  0x04
# define TH_PUSH 0x08
# define TH_ACK  0x10
# define TH_URG  0x20

typedef u_int32_t tcp_seq;

enum tcp_ca_state {
    TCP_CA_Open = 0,
    TCP_CA_Disorder = 1,
    TCP_CA_CWR = 2,
    TCP_CA_Recovery = 3,
    TCP_CA_Loss = 4
};

struct tcphdr {
    union {
        struct {
            u_int16_t th_sport;
            u_int16_t th_dport;
            tcp_seq th_seq;
            tcp_seq th_ack;
#if BYTE_ORDER == LITTLE_ENDIAN
            u_int8_t th_x2 :4;
            u_int8_t th_off :4;
#else
            u_int8_t th_off:4;
            u_int8_t th_x2:4;
#endif
            u_int8_t th_flags;
            u_int16_t th_win;
            u_int16_t th_sum;
            u_int16_t th_urp;
        };
        struct {
            u_int16_t source;
            u_int16_t dest;
            u_int32_t seq;
            u_int32_t ack_seq;
#if BYTE_ORDER == LITTLE_ENDIAN
            u_int16_t res1 :4;
            u_int16_t doff :4;
            u_int16_t fin :1;
            u_int16_t syn :1;
            u_int16_t rst :1;
            u_int16_t psh :1;
            u_int16_t ack :1;
            u_int16_t urg :1;
            u_int16_t res2 :2;
#else
            u_int16_t doff:4;
            u_int16_t res1:4;
            u_int16_t res2:2;
            u_int16_t urg:1;
            u_int16_t ack:1;
            u_int16_t psh:1;
            u_int16_t rst:1;
            u_int16_t syn:1;
            u_int16_t fin:1;
#endif
            u_int16_t window;
            u_int16_t check;
            u_int16_t urg_ptr;
        };
    };
};

struct tcp_info {
    u_int8_t tcpi_state;
    u_int8_t tcpi_ca_state;
    u_int8_t tcpi_retransmits;
    u_int8_t tcpi_probes;
    u_int8_t tcpi_backoff;
    u_int8_t tcpi_options;
    u_int8_t tcpi_snd_wscale :4, tcpi_rcv_wscale :4;
    u_int32_t tcpi_rto;
    u_int32_t tcpi_ato;
    u_int32_t tcpi_snd_mss;
    u_int32_t tcpi_rcv_mss;
    u_int32_t tcpi_unacked;
    u_int32_t tcpi_sacked;
    u_int32_t tcpi_lost;
    u_int32_t tcpi_retrans;
    u_int32_t tcpi_fackets;
    u_int32_t tcpi_last_data_sent;
    u_int32_t tcpi_last_ack_sent;
    u_int32_t tcpi_last_data_recv;
    u_int32_t tcpi_last_ack_recv;
    u_int32_t tcpi_pmtu;
    u_int32_t tcpi_rcv_ssthresh;
    u_int32_t tcpi_rtt;
    u_int32_t tcpi_rttvar;
    u_int32_t tcpi_snd_ssthresh;
    u_int32_t tcpi_snd_cwnd;
    u_int32_t tcpi_advmss;
    u_int32_t tcpi_reordering;
    u_int32_t tcpi_rcv_rtt;
    u_int32_t tcpi_rcv_space;
    u_int32_t tcpi_total_retrans;
};

struct tcp_md5sig {
    struct sockaddr_storage tcpm_addr;
    u_int16_t __tcpm_pad1;
    u_int16_t tcpm_keylen;
    u_int32_t __tcpm_pad2;
    u_int8_t tcpm_key[TCP_MD5SIG_MAXKEYLEN];
};

/* For socket repair options.  */
struct tcp_repair_opt {
    u_int32_t opt_code;
    u_int32_t opt_val;
};

struct tcp_cookie_transactions {
    u_int16_t tcpct_flags;
    u_int8_t __tcpct_pad1;
    u_int8_t tcpct_cookie_desired;
    u_int16_t tcpct_s_data_desired;
    u_int16_t tcpct_used;
    u_int8_t tcpct_value[TCP_MSS_DEFAULT];
};

#endif /* LIBC_NETINET_TCP_H_ */
