/*
 * resolv.h
 *
 *  Created on: Jul 19, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_RESOLV_H_
#define LIBC_RESOLV_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#define MAXNS            3
#define MAXDFLSRCH       3
#define MAXDNSRCH        6
#define LOCALDOMAINPARTS 2

#define RES_TIMEOUT      5
#define MAXRESOLVSORT    10
#define RES_MAXNDOTS     15
#define RES_MAXRETRANS   30
#define RES_MAXRETRY     5
#define RES_DFLRETRY     2
#define RES_MAXTIME      65535

#define RES_F_VC       (1 << 0)
#define RES_F_CONN     (1 << 1)
#define RES_F_EDNS0ERR (1 << 2)

#define RES_EXHAUSTIVE (1 << 0)

#define RES_INIT        (1 << 0)
#define RES_DEBUG       (1 << 1)
#define RES_AAONLY      (1 << 2)
#define RES_USEVC       (1 << 3)
#define RES_PRIMARY     (1 << 4)
#define RES_IGNTC       (1 << 5)
#define RES_RECURSE     (1 << 6)
#define RES_DEFNAMES    (1 << 7)
#define RES_STAYOPEN    (1 << 8)
#define RES_DNSRCH      (1 << 9)
#define RES_INSECURE1   (1 << 10)
#define RES_INSECURE2   (1 << 11)
#define RES_NOALIASES   (1 << 12)
#define RES_USE_INET6   (1 << 13)
#define RES_ROTATE      (1 << 14)
#define RES_NOCHECKNAME (1 << 15)
#define RES_KEEPTSIG    (1 << 16)
#define RES_BLAST       (1 << 17)
#define RES_USEBSTRING  (1 << 18)
#define RES_NOIP6DOTINT (1 << 19)
#define RES_USE_EDNS0   (1 << 20)
#define RES_SNGLKUP     (1 << 21)
#define RES_SNGLKUPREOP (1 << 22)
#define RES_USE_DNSSEC  (1 << 23)
#define RES_NOTLDQUERY  (1 << 24)
#define RES_DEFAULT     (RES_RECURSE|RES_DEFNAMES|RES_DNSRCH|RES_NOIP6DOTINT)

#define RES_PRF_STATS  (1 << 0)
#define RES_PRF_UPDATE (1 << 1)
#define RES_PRF_CLASS  (1 << 2)
#define RES_PRF_CMD    (1 << 3)
#define RES_PRF_QUES   (1 << 4)
#define RES_PRF_ANS    (1 << 5)
#define RES_PRF_AUTH   (1 << 6)
#define RES_PRF_ADD    (1 << 7)
#define RES_PRF_HEAD1  (1 << 8)
#define RES_PRF_HEAD2  (1 << 9)
#define RES_PRF_TTLID  (1 << 10)
#define RES_PRF_HEADX  (1 << 11)
#define RES_PRF_QUERY  (1 << 12)
#define RES_PRF_REPLY  (1 << 13)
#define RES_PRF_INIT   (1 << 14)

typedef enum {
    res_goahead,
    res_nextns,
    res_modified,
    res_done,
    res_error
} res_sendhookact;

struct res_sym {
    int number;
    char * name;
    char * humanname;
};

typedef void* res_state; //FIXME: is this supposed to be opaque? It references a probably-internal struct in glibc.

typedef res_sendhookact (*res_send_qhook)(struct sockaddr_in * const *__ns, const u_char **__query, int *__querylen, u_char *__ans, int __anssiz, int *__resplen);
typedef res_sendhookact (*res_send_rhook)(const struct sockaddr_in *__ns, const u_char *__query, int __querylen, u_char *__ans, int __anssiz, int *__resplen);

void fp_nquery(const u_char *, int, FILE *);
void fp_query(const u_char *, FILE *);
const char * hostalias(const char *);
void p_query(const u_char *);
void res_close(void);
int res_init(void);
int res_isourserver(const struct sockaddr_in *);
int res_mkquery(int, const char *, int, int, const u_char *, int, const u_char *, u_char *, int);
int res_query(const char *, int, int, u_char *, int);
int res_querydomain(const char *, const char *, int, int, u_char *, int);
int res_search(const char *, int, int, u_char *, int);
int res_send(const u_char *, int, u_char *, int);
int res_hnok(const char *);
int res_ownok(const char *);
int res_mailok(const char *);
int res_dnok(const char *);
int sym_ston(const struct res_sym *, const char *, int *);
const char * sym_ntos(const struct res_sym *, int, int *);
const char * sym_ntop(const struct res_sym *, int, int *);
int b64_ntop(u_char const *, size_t, char *, size_t);
int b64_pton(char const *, u_char *, size_t);
int loc_aton(const char *__ascii, u_char *__binary);
const char * loc_ntoa(const u_char *__binary, char *__ascii);
int dn_skipname(const u_char *, const u_char *);
void putlong(u_int32_t, u_char *);
void putshort(u_int16_t, u_char *);
const char * p_class(int);
const char * p_time(u_int32_t);
const char * p_type(int);
const char * p_rcode(int);
const u_char * p_cdnname(const u_char *, const u_char *, int, FILE *);
const u_char * p_cdname(const u_char *, const u_char *, FILE *);
const u_char * p_fqnname(const u_char *__cp, const u_char *__msg, int, char *, int);
const u_char * p_fqname(const u_char *, const u_char *, FILE *);
const char * p_option(u_long __option);
char * p_secstodate(u_long);
int dn_count_labels(const char *);
int dn_comp(const char *, u_char *, int, u_char **, u_char **);
int dn_expand(const u_char *, const u_char *, const u_char *, char *, int);
u_int res_randomid(void);
int res_nameinquery(const char *, int, int, const u_char *, const u_char *);
int res_queriesmatch(const u_char *, const u_char *, const u_char *, const u_char *);
const char * p_section(int __section, int __opcode);
int res_ninit(res_state);
int res_nisourserver(const res_state, const struct sockaddr_in *);
void fp_resstat(const res_state, FILE *);
void res_npquery(const res_state, const u_char *, int, FILE *);
const char * res_hostalias(const res_state, const char *, char *, size_t);
int res_nquery(res_state, const char *, int, int, u_char *, int);
int res_nsearch(res_state, const char *, int, int, u_char *, int);
int res_nquerydomain(res_state, const char *, const char *, int, int, u_char *, int);
int res_nmkquery(res_state, int, const char *, int, int, const u_char *, int, const u_char *, u_char *, int);
int res_nsend(res_state, const u_char *, int, u_char *, int);
void res_nclose(res_state);

#endif /* LIBC_RESOLV_H_ */
