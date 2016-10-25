/*
 * nameser.h
 *
 *  Created on: Jul 20, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_ARPA_NAMESER_H_
#define LIBC_ARPA_NAMESER_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#include "../__gt_fc_define_alternative_types.h"
#include "../__fc_define_size_t.h"
#include "../__fc_define_time_t.h"
#include "../__fc_string_axiomatic.h"

#define BIND_4_COMPAT

#define NS_PACKETSZ    512
#define NS_MAXDNAME    1025
#define NS_MAXMSG      65535
#define NS_MAXCDNAME   255
#define NS_MAXLABEL    63
#define NS_HFIXEDSZ    12
#define NS_QFIXEDSZ    4
#define NS_RRFIXEDSZ   10
#define NS_INT32SZ     4
#define NS_INT16SZ     2
#define NS_INT8SZ      1
#define NS_INADDRSZ    4
#define NS_IN6ADDRSZ   16
#define NS_CMPRSFLGS   0xc0
#define NS_DEFAULTPORT 53

#define NS_TSIG_FUDGE        300
#define NS_TSIG_TCP_COUNT    100
#define NS_TSIG_ALG_HMAC_MD5 "HMAC-MD5.SIG-ALG.REG.INT"

#define NS_TSIG_ERROR_NO_TSIG  -10
#define NS_TSIG_ERROR_NO_SPACE -11
#define NS_TSIG_ERROR_FORMERR  -12

#define NS_KEY_TYPEMASK          0xC000
#define NS_KEY_TYPE_AUTH_CONF    0x0000
#define NS_KEY_TYPE_CONF_ONLY    0x8000
#define NS_KEY_TYPE_AUTH_ONLY    0x4000
#define NS_KEY_TYPE_NO_KEY       0xC000
#define NS_KEY_NO_AUTH           0x8000
#define NS_KEY_NO_CONF           0x4000
#define NS_KEY_RESERVED2         0x2000
#define NS_KEY_EXTENDED_FLAGS    0x1000
#define NS_KEY_RESERVED4         0x0800
#define NS_KEY_RESERVED5         0x0400
#define NS_KEY_NAME_TYPE         0x0300
#define NS_KEY_NAME_USER         0x0000
#define NS_KEY_NAME_ENTITY       0x0200
#define NS_KEY_NAME_ZONE         0x0100
#define NS_KEY_NAME_RESERVED     0x0300
#define NS_KEY_RESERVED8         0x0080
#define NS_KEY_RESERVED9         0x0040
#define NS_KEY_RESERVED10        0x0020
#define NS_KEY_RESERVED11        0x0010
#define NS_KEY_SIGNATORYMASK     0x000F
#define NS_KEY_RESERVED_BITMASK  ( NS_KEY_RESERVED2 | NS_KEY_RESERVED4 | NS_KEY_RESERVED5 | NS_KEY_RESERVED8 | NS_KEY_RESERVED9 | NS_KEY_RESERVED10 | NS_KEY_RESERVED11 )
#define NS_KEY_RESERVED_BITMASK2 0xFFFF

#define NS_ALG_MD5RSA      1
#define NS_ALG_DH          2
#define NS_ALG_DSA         3
#define NS_ALG_DSS         NS_ALG_DSA
#define NS_ALG_EXPIRE_ONLY 253
#define NS_ALG_PRIVATE_OID 254

#define NS_KEY_PROT_TLS    1
#define NS_KEY_PROT_EMAIL  2
#define NS_KEY_PROT_DNSSEC 3
#define NS_KEY_PROT_IPSEC  4
#define NS_KEY_PROT_ANY    255

#define NS_MD5RSA_MIN_BITS   512
#define NS_MD5RSA_MAX_BITS   4096
#define NS_MD5RSA_MAX_BYTES  ((NS_MD5RSA_MAX_BITS+7/8)*2+3)
#define NS_MD5RSA_MAX_BASE64 (((NS_MD5RSA_MAX_BYTES+2)/3)*4)
#define NS_MD5RSA_MIN_SIZE   ((NS_MD5RSA_MIN_BITS+7)/8)
#define NS_MD5RSA_MAX_SIZE   ((NS_MD5RSA_MAX_BITS+7)/8)

#define NS_DSA_SIG_SIZE  41
#define NS_DSA_MIN_SIZE  213
#define NS_DSA_MAX_BYTES 405

#define NS_SIG_TYPE   0
#define NS_SIG_ALG    2
#define NS_SIG_LABELS 3
#define NS_SIG_OTTL   4
#define NS_SIG_EXPIR  8
#define NS_SIG_SIGNED 12
#define NS_SIG_FOOT   16
#define NS_SIG_SIGNER 18
#define NS_NXT_BITS   8
#define NS_NXT_MAX    127

#define NS_OPT_DNSSEC_OK 0x8000U
#define NS_OPT_NSID      3

#define NS_NXT_BIT_SET(n,p)   (p[(n)/NS_NXT_BITS] |=  (0x80>>((n)%NS_NXT_BITS)))
#define NS_NXT_BIT_CLEAR(n,p) (p[(n)/NS_NXT_BITS] &= ~(0x80>>((n)%NS_NXT_BITS)))
#define NS_NXT_BIT_ISSET(n,p) (p[(n)/NS_NXT_BITS] &   (0x80>>((n)%NS_NXT_BITS)))

#define ns_rr_name(rr)  (((rr).name[0] != '\0') ? (rr).name : ".")
#define ns_rr_type(rr)  ((ns_type)((rr).type + 0))
#define ns_rr_class(rr) ((ns_class)((rr).rr_class + 0))
#define ns_rr_ttl(rr)   ((rr).ttl + 0)
#define ns_rr_rdlen(rr) ((rr).rdlength + 0)
#define ns_rr_rdata(rr) ((rr).rdata + 0)

#define ns_t_qt_p(t)  (ns_t_xfr_p(t) || (t) == ns_t_any || (t) == ns_t_mailb || (t) == ns_t_maila)
#define ns_t_mrr_p(t) ((t) == ns_t_tsig || (t) == ns_t_opt)
#define ns_t_rr_p(t)  (!ns_t_qt_p(t) && !ns_t_mrr_p(t))
#define ns_t_udp_p(t) ((t) != ns_t_axfr && (t) != ns_t_zxfr)
#define ns_t_xfr_p(t) ((t) == ns_t_axfr || (t) == ns_t_ixfr || (t) == ns_t_zxfr)

#define NS_GET16(s, cp) do { \
    const u_char *t_cp = (const u_char *)(cp); \
    (s) = ((u_int16_t)t_cp[0] << 8) \
        | ((u_int16_t)t_cp[1]) \
        ; \
    (cp) += NS_INT16SZ; \
} while (0)

#define NS_GET32(l, cp) do { \
    const u_char *t_cp = (const u_char *)(cp); \
    (l) = ((u_int32_t)t_cp[0] << 24) \
        | ((u_int32_t)t_cp[1] << 16) \
        | ((u_int32_t)t_cp[2] << 8) \
        | ((u_int32_t)t_cp[3]) \
        ; \
    (cp) += NS_INT32SZ; \
} while (0)

#define NS_PUT16(s, cp) do { \
    u_int16_t t_s = (u_int16_t)(s); \
    u_char *t_cp = (u_char *)(cp); \
    *t_cp++ = t_s >> 8; \
    *t_cp   = t_s; \
    (cp) += NS_INT16SZ; \
} while (0)

#define NS_PUT32(l, cp) do { \
    u_int32_t t_l = (u_int32_t)(l); \
    u_char *t_cp = (u_char *)(cp); \
    *t_cp++ = t_l >> 24; \
    *t_cp++ = t_l >> 16; \
    *t_cp++ = t_l >> 8; \
    *t_cp   = t_l; \
    (cp) += NS_INT32SZ; \
} while (0)

typedef enum __ns_sect {
    ns_s_qd = 0,
    ns_s_zn = 0,
    ns_s_an = 1,
    ns_s_pr = 1,
    ns_s_ns = 2,
    ns_s_ud = 2,
    ns_s_ar = 3,
    ns_s_max = 4
} ns_sect;

typedef struct __ns_msg {
    void* __gt_fc_dummy;
} ns_msg;

typedef struct __ns_rr {
    char name[NS_MAXDNAME];
    u_int16_t type;
    u_int16_t rr_class;
    u_int32_t ttl;
    u_int16_t rdlength;
    const u_char * rdata;
} ns_rr;

typedef enum __ns_flag {
    ns_f_qr,
    ns_f_opcode,
    ns_f_aa,
    ns_f_tc,
    ns_f_rd,
    ns_f_ra,
    ns_f_z,
    ns_f_ad,
    ns_f_cd,
    ns_f_rcode,
    ns_f_max
} ns_flag;

typedef enum __ns_opcode {
    ns_o_query = 0,
    ns_o_iquery = 1,
    ns_o_status = 2,
    ns_o_notify = 4,
    ns_o_update = 5,
    ns_o_max = 6
} ns_opcode;

typedef enum __ns_rcode {
    ns_r_noerror = 0,
    ns_r_formerr = 1,
    ns_r_servfail = 2,
    ns_r_nxdomain = 3,
    ns_r_notimpl = 4,
    ns_r_refused = 5,
    ns_r_yxdomain = 6,
    ns_r_yxrrset = 7,
    ns_r_nxrrset = 8,
    ns_r_notauth = 9,
    ns_r_notzone = 10,
    ns_r_max = 11,
    ns_r_badvers = 16,
    ns_r_badsig = 16,
    ns_r_badkey = 17,
    ns_r_badtime = 18
} ns_rcode;

typedef enum __ns_update_operation {
    ns_uop_delete = 0,
    ns_uop_add = 1,
    ns_uop_max = 2
} ns_update_operation;

typedef struct ns_tsig_key {
    char name[NS_MAXDNAME], alg[NS_MAXDNAME];
    unsigned char *data;
    int len;
} ns_tsig_key;

typedef struct ns_tcp_tsig_state {
    int counter;
    struct dst_key *key;
    void *ctx;
    unsigned char sig[NS_PACKETSZ];
    int siglen;
} ns_tcp_tsig_state;

typedef enum __ns_type {
    ns_t_invalid = 0,
    ns_t_a = 1,
    ns_t_ns = 2,
    ns_t_md = 3,
    ns_t_mf = 4,
    ns_t_cname = 5,
    ns_t_soa = 6,
    ns_t_mb = 7,
    ns_t_mg = 8,
    ns_t_mr = 9,
    ns_t_null = 10,
    ns_t_wks = 11,
    ns_t_ptr = 12,
    ns_t_hinfo = 13,
    ns_t_minfo = 14,
    ns_t_mx = 15,
    ns_t_txt = 16,
    ns_t_rp = 17,
    ns_t_afsdb = 18,
    ns_t_x25 = 19,
    ns_t_isdn = 20,
    ns_t_rt = 21,
    ns_t_nsap = 22,
    ns_t_nsap_ptr = 23,
    ns_t_sig = 24,
    ns_t_key = 25,
    ns_t_px = 26,
    ns_t_gpos = 27,
    ns_t_aaaa = 28,
    ns_t_loc = 29,
    ns_t_nxt = 30,
    ns_t_eid = 31,
    ns_t_nimloc = 32,
    ns_t_srv = 33,
    ns_t_atma = 34,
    ns_t_naptr = 35,
    ns_t_kx = 36,
    ns_t_cert = 37,
    ns_t_a6 = 38,
    ns_t_dname = 39,
    ns_t_sink = 40,
    ns_t_opt = 41,
    ns_t_apl = 42,
    ns_t_tkey = 249,
    ns_t_tsig = 250,
    ns_t_ixfr = 251,
    ns_t_axfr = 252,
    ns_t_mailb = 253,
    ns_t_maila = 254,
    ns_t_any = 255,
    ns_t_zxfr = 256,
    ns_t_max = 65536
} ns_type;

typedef enum __ns_class {
    ns_c_invalid = 0,
    ns_c_in = 1,
    ns_c_2 = 2,
    ns_c_chaos = 3,
    ns_c_hs = 4,
    ns_c_none = 254,
    ns_c_any = 255,
    ns_c_max = 65536
} ns_class;

typedef enum __ns_key_types {
    ns_kt_rsa = 1,
    ns_kt_dh = 2,
    ns_kt_dsa = 3,
    ns_kt_private = 254
} ns_key_types;

typedef enum __ns_cert_types {
    cert_t_pkix = 1,
    cert_t_spki = 2,
    cert_t_pgp = 3,
    cert_t_url = 253,
    cert_t_oid = 254
} ns_cert_types;

/*
The following functions are undocumented, but partial documentation exists as part of this book:
http://docstore.mik.ua/orelly/networking_2ndEd/dns/ch15_02.htm
It describes the usage of these functions. It may not be complete documentation for the behavior of these functions, however.
*/

/*@
axiomatic NameServer {
    logic boolean is_ns_handle_init(ns_msg handle);
    logic u_char* ns_handle_begin(ns_msg handle);
    logic size_t ns_handle_size(ns_msg handle);
    logic u_char* ns_handle_end(ns_msg handle) = ns_handle_begin(handle) + ns_handle_size(handle);
    logic u_int16_t ns_handle_flag(ns_msg handle, ns_flag flag);
    logic u_int16_t ns_handle_section_size(ns_msg handle, ns_sect sect);
    logic u_int ns_data_16(u_char* s) reads s[0..sizeof(u_int)-1];
    logic u_long ns_data_32(u_char* s) reads s[0..sizeof(u_long)-1];

    axiom validity_of_handle: \forall ns_msg handle; \valid(ns_handle_begin(handle)+(0..ns_handle_size(handle)-1));
    axiom base_addrs_of_handle: \forall ns_msg handle; \base_addr(ns_handle_begin(handle)) == \base_addr(ns_handle_end(handle));
    axiom comapre_of_handle: \forall ns_msg handle; ns_handle_begin(handle) < ns_handle_end(handle);
}
*/

// some documentation refers to a different spelling of some functions. We'll support both, just in case.
#define ns_msg_get_flag ns_msg_getflag

/*@
requires is_ns_handle_init(handle);
requires 0 <= flag < ns_f_max;
assigns \result \from handle, flag;
ensures \result == ns_handle_flag(handle, flag);
*/
u_int16_t ns_msg_getflag(ns_msg handle, ns_flag flag);

/*@
requires \valid(cp+(0..sizeof(u_int)-1));
assigns \result \from cp[0..sizeof(u_int)-1];
ensures \result == ns_data_16(cp);
*/
u_int ns_get16(const u_char * cp);

/*@
requires \valid(cp+(0..sizeof(u_long)-1));
assigns \result \from cp[0..sizeof(u_long)-1];
ensures \result == ns_data_32(cp);
*/
u_long ns_get32(const u_char * cp);

/*@
requires \valid(cp+(0..sizeof(u_int)-1));
assigns cp[0..sizeof(u_int)-1] \from s;
ensures ns_data_16(cp) == s;
*/
void ns_put16(u_int s, u_char * cp);

/*@
requires \valid(cp+(0..sizeof(u_long)-1));
assigns cp[0..sizeof(u_long)-1] \from s;
ensures ns_data_32(cp) == s;
*/
void ns_put32(u_long s, u_char * cp);

/*@
requires \valid(handle);
requires \valid(msg+(0..len-1));
assigns \result, *handle \from msg, len;
ensures \result == 0 || \result == -1;
ensures is_ns_handle_init(*handle);
*/
int ns_initparse(const u_char * msg, int len, ns_msg * handle);

/*@
requires \valid(handle);
requires is_ns_handle_init(*handle);
requires 0 <= rrnum < ns_handle_section_size(*handle, section);
requires \valid(rr);
requires 0 <= section < ns_s_max;
assigns \result, *rr \from *handle, section, rrnum;
ensures \result == 0 || \result == -1;
ensures \result == 0 ==> valid_string((char*)(rr->name));
ensures \result == 0 ==> \valid(rr->rdata+(0..rr->rdlength-1));
*/
int ns_parserr(ns_msg *handle, ns_sect section, int rrnum,  ns_rr *rr);

/*@
requires \base_addr(msg) == \base_addr(eomorig);
requires eomorig > msg;
requires \valid(msg+(0..eomorig-msg-1));
requires \base_addr(msg) == \base_addr(comp_dn);
requires msg <= comp_dn < eomorig;
requires \valid(exp_dn+(0..length-1));
assigns exp_dn[0..length-1] \from msg[0..eomorig-msg-1], length;
ensures \result >= -1;
ensures \result != -1 ==> valid_string(exp_dn);
*/
int ns_name_uncompress(const u_char *msg, const u_char *eomorig, const u_char *comp_dn, char *exp_dn, size_t length);

/*@
requires valid_read_string(exp_dn);
requires \valid(comp_dn+(0..length-1));
requires \base_addr(dnptrs) == \base_addr(lastdnptr);
requires lastdnptr > dnptrs;
requires \valid(dnptrs+(0..lastdnptr-dnptrs-1));
requires \exists size_t i; dnptrs <= dnptrs+i < lastdnptr ==> dnptrs[i] == \null && (\forall size_t j; dnptrs <= dnptrs+j < dnptrs+i ==> \valid(dnptrs[j]));
assigns \result, comp_dn[0..length-1], dnptrs[0..lastdnptr-dnptrs-1] \from exp_dn[0..strlen(exp_dn)], length, dnptrs[0..lastdnptr-dnptrs-1], lastdnptr;
ensures \exists size_t i; dnptrs <= dnptrs+i < lastdnptr ==> dnptrs[i] == \null && (\forall size_t j; dnptrs <= dnptrs+j < dnptrs+i ==> \valid(dnptrs[j]));
ensures \result >= -1;
*/
int ns_name_compress(const char *exp_dn, u_char *comp_dn, size_t length, const u_char **dnptrs, const u_char **lastdnptr);

/*@
requires \valid(ptrptr);
requires \base_addr(eom) == \base_addr(*ptrptr);
requires eom > *ptrptr;
requires \valid((*ptrptr)+(0..eom-(*ptrptr)-1));
assigns \result, *ptrptr \from (*ptrptr)[0..eom-(*ptrptr)-1];
ensures \result == 0 || \result == -1;
ensures \base_addr(*ptrptr) == \base_addr(\old(*ptrptr));
ensures *ptrptr >= \old(*ptrptr);
ensures \result == -1 ==> *ptrptr == \old(*ptrptr);
*/
int ns_name_skip(const u_char **ptrptr, const u_char *eom);

/*@
requires is_ns_handle_init(handle);
assigns \result \from handle;
ensures \result == ns_handle_begin(handle);
*/
const u_char *ns_msg_base(ns_msg handle);

/*@
requires is_ns_handle_init(handle);
assigns \result \from handle;
ensures \result == ns_handle_end(handle);
*/
const u_char *ns_msg_end(ns_msg handle);

/*@
requires is_ns_handle_init(handle);
assigns \result \from handle;
ensures \result == ns_handle_size(handle);
*/
int ns_msg_size(ns_msg handle);

/*@
requires is_ns_handle_init(handle);
assigns \result \from handle;
*/
u_int16_t ns_msg_id(ns_msg handle);

/*@
requires is_ns_handle_init(handle);
requires 0 <= section < ns_s_max;
assigns \result \from handle, section;
ensures \result == ns_handle_section_size(handle, section);
*/
u_int16_t ns_msg_count(ns_msg handle, ns_sect section);

// The following functions are documented in the Solaris man pages. Any differences between Solaris behavior and standard behavior are unknown.

/*@
requires \valid(msg+(0..msgsize-1));
requires \valid(msglen);
requires 0 <= *msglen <= msgsize;
requires \valid_read(querysig+(0..querysiglen-1));
requires \valid(siglen);
requires \valid(sig+(0..*siglen-1));
assigns \result, msg[0..msgsize-1], sig[0..*siglen-1], *msglen, *siglen;
ensures \result <= 0;
ensures \result == 0 ==> *msglen >= \old(*msglen);
ensures \result != 0 ==> *msglen == \old(*msglen);
ensures \result == 0 ==> *siglen >= \old(*siglen);
ensures \result != 0 ==> *siglen == \old(*siglen);
ensures 0 <= *msglen <= msgsize;
*/
int ns_sign(u_char *msg, int *msglen, int msgsize, int error, void * k, const u_char *querysig, int querysiglen, u_char *sig, int *siglen, time_t in_timesigned);

/*@
requires \valid(msg+(0..msgsize-1));
requires \valid(msglen);
requires 0 <= *msglen <= msgsize;
requires \valid(state);
assigns \result, msg[0..msgsize-1], *state, *msglen;
ensures \result <= 0;
ensures \result == 0 ==> *msglen >= \old(*msglen);
ensures \result != 0 ==> *msglen == \old(*msglen);
ensures 0 <= *msglen <= msgsize;
*/
int ns_sign_tcp(u_char *msg, int *msglen, int msgsize, int error, ns_tcp_tsig_state *state, int done);

/*@
requires \valid_read(querysig+(0..querysiglen-1));
requires \valid(state);
assigns \result, *state;
*/
int ns_sign_tcp_init(void *k, const u_char *querysig, int querysiglen, ns_tcp_tsig_state *state);

/*@
requires \valid(msg+(0..*msglen-1));
requires \valid(msglen);
requires 0 <= *msglen;
requires \valid_read(querysig+(0..querysiglen-1));
requires \valid(siglen);
requires \valid(sig+(0..*siglen-1));
assigns \result, msg[0..*msglen-1], sig[0..*siglen-1], *msglen, *siglen;
ensures \result <= 0;
ensures \result == 0 ==> *msglen >= \old(*msglen);
ensures \result != 0 ==> *msglen == \old(*msglen);
ensures \result == 0 ==> *siglen >= \old(*siglen);
ensures \result != 0 ==> *siglen == \old(*siglen);
ensures 0 <= *msglen;
*/
int ns_verify(u_char *msg, int *msglen, void *k, const u_char *querysig, int querysiglen, u_char *sig, int *siglen, time_t in_timesigned, int nostrip);

/*@
requires \valid(msg+(0..*msglen-1));
requires \valid(msglen);
requires 0 <= *msglen;
requires \valid(state);
assigns \result, msg[0..*msglen-1], *state, *msglen;
ensures \result <= 0;
ensures \result == 0 ==> *msglen >= \old(*msglen);
ensures \result != 0 ==> *msglen == \old(*msglen);
ensures 0 <= *msglen;
*/
int ns_verify_tcp(u_char *msg, int *msglen, ns_tcp_tsig_state *state, int required);

/*@
requires \valid_read(querysig+(0..querysiglen-1));
requires \valid(state);
assigns \result, *state;
*/
int ns_verify_tcp_init(void *k, const u_char *querysig, int querysiglen, ns_tcp_tsig_state *state);

/*@
requires \base_addr(msg) == \base_addr(eom);
requires eom > msg;
requires \valid_read(msg+(0..eom-msg-1));
assigns \result \from msg[0..eom-msg-1];
ensures \result != \null ==> \base_addr(\result) == \base_addr(msg);
ensures \result != \null ==> msg <= \result < eom;
*/
u_char *ns_find_tsig(u_char *msg, u_char *eom);

// The following functions are undocumented, but are used by some applications.

int ns_skiprr(const u_char *, const u_char *, ns_sect, int);
int ns_sprintrr(const ns_msg *, const ns_rr *, const char *, const char *, char *, size_t);
int ns_sprintrrf(const u_char *, size_t, const char *, ns_class, ns_type, u_long, const u_char *, size_t, const char *, const char *, char *, size_t);
int ns_format_ttl(u_long, char *, size_t);
int ns_parse_ttl(const char *, u_long *);
u_int32_t ns_datetosecs(const char *, int *);
int ns_name_ntol(const u_char *, u_char *, size_t);
int ns_name_ntop(const u_char *, char *, size_t);
int ns_name_pton(const char *, u_char *, size_t);
int ns_name_unpack(const u_char *, const u_char *, const u_char *, u_char *, size_t);
int ns_name_pack(const u_char *, u_char *, int, const u_char **, const u_char **);
void ns_name_rollback(const u_char *, const u_char **, const u_char **);
int ns_sign2(u_char *, int *, int, int, void *, const u_char *, int, u_char *, int *, time_t, u_char **, u_char **);
int ns_sign_tcp2(u_char *, int *, int, int, ns_tcp_tsig_state *, int, u_char **, u_char **);
int ns_samedomain(const char *, const char *);
int ns_subdomain(const char *, const char *);
int ns_makecanon(const char *, char *, size_t);
int ns_samename(const char *, const char *);

#include "nameser_compat.h" // Include compat after this, if the user didn't include this header from <nameser_compat.h> itself.

#endif /* LIBC_ARPA_NAMESER_H_ */
