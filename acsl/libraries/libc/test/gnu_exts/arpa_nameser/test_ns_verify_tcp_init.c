#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char query[10];
    int querylen = 10;
    void* k;
    ns_tcp_tsig_state state;

    ns_verify_tcp_init(k, query, querylen, &state);
}

void runFailure() {
    u_char query[10];
    int querylen = 10;
    void* k;
    ns_tcp_tsig_state state;

    ns_verify_tcp_init(k, NULL, querylen, &state);
}

void runFailure1() {
    u_char query[10];
    int querylen = 20;
    void* k;
    ns_tcp_tsig_state state;

    ns_verify_tcp_init(k, query, querylen, &state);
}

void runFailure2() {
    u_char query[10];
    int querylen = 10;
    void* k;
    ns_tcp_tsig_state state;

    ns_verify_tcp_init(k, query, querylen, NULL);
}

int f;
void testValues() {
    f = 2;
    
    u_char query[10];
    int querylen = 10;
    void* k;
    ns_tcp_tsig_state state;

    ns_verify_tcp_init(k, query, querylen, &state);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
