#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    char buf[] = "hi";
    //@ assert \valid((char*)buf);
    struct addrinfo ai;
    struct gaicb g1 = {
            .ar_name = buf,
            .ar_service = buf,
            .ar_request = &ai,
    };
    struct gaicb *list[] = {NULL, &g1};
    getaddrinfo_a(anyint(), list, 2, NULL);
}

void runSuccess1() {
    char buf[] = "hi";
    //@ assert \valid((char*)buf);
    struct addrinfo ai;
    struct gaicb g1 = {
            .ar_name = buf,
            .ar_service = NULL,
            .ar_request = NULL,
    };
    struct gaicb *list[] = {NULL, &g1};
    getaddrinfo_a(anyint(), list, 2, NULL);
}

void runSuccess2() {
    char buf[] = "hi";
    //@ assert \valid((char*)buf);
    struct addrinfo ai;
    struct gaicb g1 = {
            .ar_name = NULL,
            .ar_service = buf,
            .ar_request = NULL,
    };
    struct gaicb *list[] = {NULL, &g1};
    getaddrinfo_a(anyint(), list, 2, NULL);
}

void runFailure() {
    char buf[] = "hi";
    //@ assert \valid((char*)buf);
    struct addrinfo ai;
    struct gaicb g1 = {
            .ar_name = NULL,
            .ar_service = NULL,
            .ar_request = NULL,
    };
    struct gaicb *list[] = {NULL, &g1};
    getaddrinfo_a(anyint(), list, 2, NULL);
}

void runFailure1() {
    char buf[] = "hi";
    //@ assert \valid((char*)buf);
    struct addrinfo ai;
    struct gaicb g1 = {
            .ar_name = buf,
            .ar_service = buf,
            .ar_request = &ai,
    };
    struct gaicb *list[] = {NULL, &g1};
    getaddrinfo_a(anyint(), list, 20, NULL);
}

void runFailure2() {
    char buf[] = "hi";
    //@ assert \valid((char*)buf);
    struct addrinfo ai;
    struct gaicb g1 = {
            .ar_name = buf,
            .ar_service = buf,
            .ar_request = &ai,
    };
    struct gaicb *list[] = {NULL, &g1};
    getaddrinfo_a(anyint(), NULL, 2, NULL);
}

int f;
void testValues() {
    f = 2;
    
    char buf[] = "hi";
    //@ assert \valid((char*)buf);
    struct addrinfo ai;
    struct gaicb g1 = {
            .ar_name = buf,
            .ar_service = buf,
            .ar_request = &ai,
    };
    struct gaicb *list[] = {NULL, &g1};
    getaddrinfo_a(anyint(), list, 2, NULL);
    //@ assert g1.ar_name == (char*)buf;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
