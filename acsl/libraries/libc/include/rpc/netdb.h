/*
 * netdb.h
 *
 *  Created on: Jul 19, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_RPC_NETDB_H_
#define LIBC_RPC_NETDB_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

struct rpcent {
    char *r_name;
    char **r_aliases;
    long r_number;
};

struct rpcent *getrpcent(void);
struct rpcent *getrpcbyname(const char *name);
struct rpcent *getrpcbynumber(int number);
void setrpcent(int stayopen);
void endrpcent(void);

#endif /* LIBC_RPC_NETDB_H_ */
