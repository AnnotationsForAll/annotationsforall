#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char msg[10];
    int msglen = 10;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_verify(msg, &msglen, k, query, querylen, sig, &siglen, anyint(), anyint());
}

void runFailure() {
    u_char msg[10];
    int msglen = 10;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_verify(NULL, &msglen, k, query, querylen, sig, &siglen, anyint(), anyint());
}

void runFailure1() {
    u_char msg[10];
    int msglen = 10;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_verify(msg, NULL, k, query, querylen, sig, &siglen, anyint(), anyint());
}

void runFailure2() {
    u_char msg[10];
    int msglen = 10;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_verify(msg, &msglen, k, NULL, querylen, sig, &siglen, anyint(), anyint());
}

void runFailure3() {
    u_char msg[10];
    int msglen = 10;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_verify(msg, &msglen, k, query, querylen, NULL, &siglen, anyint(), anyint());
}

void runFailure4() {
    u_char msg[10];
    int msglen = 10;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_verify(msg, &msglen, k, query, querylen, sig, NULL, anyint(), anyint());
}

void runFailure5() {
    u_char msg[10];
    int msglen = 20;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_verify(msg, &msglen, k, query, querylen, sig, &siglen, anyint(), anyint());
}

void runFailure6() {
    u_char msg[10];
    int msglen = 10;
    u_char query[10];
    int querylen = 20;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_verify(msg, &msglen, k, query, querylen, sig, &siglen, anyint(), anyint());
}

void runFailure7() {
    u_char msg[10];
    int msglen = 10;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 20;
    void* k;

    ns_verify(msg, &msglen, k, query, querylen, sig, &siglen, anyint(), anyint());
}

int f;
void testValues() {
    f = 2;
    
    u_char msg[10];
    int msglen = 10;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_verify(msg, &msglen, k, query, querylen, sig, &siglen, anyint(), anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
