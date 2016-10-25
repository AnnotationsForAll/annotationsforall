#include "../../../test_common.h"
#include <arpa/nameser.h>

void runSuccess() {
    u_char msg[10];
    int msglen = 0;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_sign(msg, &msglen, 10, anyint(), k, query, querylen, sig, &siglen, anyint());
}

void runFailure() {
    u_char msg[10];
    int msglen = 0;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_sign(NULL, &msglen, 10, anyint(), k, query, querylen, sig, &siglen, anyint());
}

void runFailure1() {
    u_char msg[10];
    int msglen = 0;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_sign(msg, NULL, 10, anyint(), k, query, querylen, sig, &siglen, anyint());
}

void runFailure2() {
    u_char msg[10];
    int msglen = 0;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_sign(msg, &msglen, 10, anyint(), k, NULL, querylen, sig, &siglen, anyint());
}

void runFailure3() {
    u_char msg[10];
    int msglen = 0;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_sign(msg, &msglen, 10, anyint(), k, query, querylen, NULL, &siglen, anyint());
}

void runFailure4() {
    u_char msg[10];
    int msglen = 0;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_sign(msg, &msglen, 10, anyint(), k, query, querylen, sig, NULL, anyint());
}

void runFailure5() {
    u_char msg[10];
    int msglen = 0;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_sign(msg, &msglen, 20, anyint(), k, query, querylen, sig, &siglen, anyint());
}

void runFailure6() {
    u_char msg[10];
    int msglen = 20;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_sign(msg, &msglen, 10, anyint(), k, query, querylen, sig, &siglen, anyint());
}

void runFailure7() {
    u_char msg[10];
    int msglen = 0;
    u_char query[10];
    int querylen = 20;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_sign(msg, &msglen, 10, anyint(), k, query, querylen, sig, &siglen, anyint());
}

void runFailure8() {
    u_char msg[10];
    int msglen = 0;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 20;
    void* k;

    ns_sign(msg, &msglen, 10, anyint(), k, query, querylen, sig, &siglen, anyint());
}

int f;
void testValues() {
    f = 2;
    
    u_char msg[10];
    int msglen = 0;
    u_char query[10];
    int querylen = 10;
    u_char sig[10];
    int siglen = 10;
    void* k;

    ns_sign(msg, &msglen, 10, anyint(), k, query, querylen, sig, &siglen, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
