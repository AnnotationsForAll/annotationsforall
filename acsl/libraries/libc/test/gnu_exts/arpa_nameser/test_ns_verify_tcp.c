#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char msg[10];
    int msglen = 10;
    ns_tcp_tsig_state state;

    ns_verify_tcp(msg, &msglen, &state, anyint());
}

void runFailure() {
    u_char msg[10];
    int msglen = 10;
    ns_tcp_tsig_state state;

    ns_verify_tcp(NULL, &msglen, &state, anyint());
}

void runFailure1() {
    u_char msg[10];
    int msglen = 10;
    ns_tcp_tsig_state state;

    ns_verify_tcp(msg, NULL, &state, anyint());
}

void runFailure2() {
    u_char msg[10];
    int msglen = 20;
    ns_tcp_tsig_state state;

    ns_verify_tcp(msg, &msglen, &state, anyint());
}

void runFailure3() {
    u_char msg[10];
    int msglen = 10;
    ns_tcp_tsig_state state;

    ns_verify_tcp(msg, &msglen, NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    u_char msg[10];
    int msglen = 10;
    ns_tcp_tsig_state state;

    ns_verify_tcp(msg, &msglen, &state, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
