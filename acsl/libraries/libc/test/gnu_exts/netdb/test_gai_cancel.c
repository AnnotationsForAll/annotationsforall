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
        gai_cancel(&g1);
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
        gai_cancel(NULL);
    }
}

void runFailure() {

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
        gai_cancel(&g1);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
