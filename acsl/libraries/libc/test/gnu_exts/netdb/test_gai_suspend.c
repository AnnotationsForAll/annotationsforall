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
    if (!getaddrinfo_a(anyint(), list, 2, NULL)) {
        gai_suspend(list, 2, NULL);
    }
}

void runSuccess1() {
    char buf[] = "hi";
    //@ assert \valid((char*)buf);
    struct addrinfo ai;
    struct gaicb g1 = {
            .ar_name = buf,
            .ar_service = buf,
            .ar_request = &ai,
    };
    struct gaicb *list[] = {NULL, &g1};
    if (!getaddrinfo_a(anyint(), list, 2, NULL)) {
        struct timespec timespec;
        gai_suspend(list, 2, &timespec);
    }
}

void runFailure() {
    gai_suspend(NULL, 2, NULL);
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
    if (!getaddrinfo_a(anyint(), list, 2, NULL)) {
        gai_suspend(list, 20, NULL);
    }
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
    if (!getaddrinfo_a(anyint(), list, 2, NULL)) {
        gai_suspend(list, 2, NULL);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
