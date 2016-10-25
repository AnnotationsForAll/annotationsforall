#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char msg[10];
    int msglen = 0;
    ns_tcp_tsig_state state;

    ns_sign_tcp(msg, &msglen, 10, anyint(), &state, anyint());
}

void runFailure() {
    u_char msg[10];
    int msglen = 0;
    ns_tcp_tsig_state state;

    ns_sign_tcp(NULL, &msglen, 10, anyint(), &state, anyint());
}

void runFailure1() {
    u_char msg[10];
    int msglen = 0;
    ns_tcp_tsig_state state;

    ns_sign_tcp(msg, NULL, 10, anyint(), &state, anyint());
}

void runFailure2() {
    u_char msg[10];
    int msglen = 0;
    ns_tcp_tsig_state state;

    ns_sign_tcp(msg, &msglen, 20, anyint(), &state, anyint());
}

void runFailure3() {
    u_char msg[10];
    int msglen = 20;
    ns_tcp_tsig_state state;

    ns_sign_tcp(msg, &msglen, 10, anyint(), &state, anyint());
}

void runFailure4() {
    u_char msg[10];
    int msglen = 0;
    ns_tcp_tsig_state state;

    ns_sign_tcp(msg, &msglen, 10, anyint(), NULL, anyint());
}

int f;
void testValues() {
    f = 2;
    
    u_char msg[10];
    int msglen = 0;
    ns_tcp_tsig_state state;

    ns_sign_tcp(msg, &msglen, 10, anyint(), &state, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
