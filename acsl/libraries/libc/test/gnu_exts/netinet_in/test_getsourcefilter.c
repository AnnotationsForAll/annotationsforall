#include "../../../test_common.h"
#include <netinet/in.h>

void runSuccess() {
    struct in_addr addr;
    uint32_t mode;
    struct sockaddr_storage store;
    struct sockaddr_storage buf[] = {
            store,
            store,
            store
    };
    struct sockaddr memb;
    struct sockaddr groups[] = {
            memb,
            memb
    };
    uint32_t len = 3;
    getsourcefilter(anyint(), anyint(), groups, 2, &mode, &len, buf);
}

void runFailure() {
    struct in_addr addr;
    uint32_t mode;
    struct sockaddr_storage store;
    struct sockaddr_storage buf[] = {
            store,
            store,
            store
    };
    struct sockaddr memb;
    struct sockaddr groups[] = {
            memb,
            memb
    };
    uint32_t len = 3;
    getsourcefilter(anyint(), anyint(), NULL, 2, &mode, &len, buf);
}

void runFailure1() {
    struct in_addr addr;
    uint32_t mode;
    struct sockaddr_storage store;
    struct sockaddr_storage buf[] = {
            store,
            store,
            store
    };
    struct sockaddr memb;
    struct sockaddr groups[] = {
            memb,
            memb
    };
    uint32_t len = 3;
    getsourcefilter(anyint(), anyint(), groups, 2, NULL, &len, buf);
}

void runFailure2() {
    struct in_addr addr;
    uint32_t mode;
    struct sockaddr_storage store;
    struct sockaddr_storage buf[] = {
            store,
            store,
            store
    };
    struct sockaddr memb;
    struct sockaddr groups[] = {
            memb,
            memb
    };
    uint32_t len = 3;
    getsourcefilter(anyint(), anyint(), groups, 2, &mode, NULL, buf);
}

void runFailure3() {
    struct in_addr addr;
    uint32_t mode;
    struct sockaddr_storage store;
    struct sockaddr_storage buf[] = {
            store,
            store,
            store
    };
    struct sockaddr memb;
    struct sockaddr groups[] = {
            memb,
            memb
    };
    uint32_t len = 3;
    getsourcefilter(anyint(), anyint(), groups, 2, &mode, &len, NULL);
}

void runFailure4() {
    struct in_addr addr;
    uint32_t mode;
    struct sockaddr_storage store;
    struct sockaddr_storage buf[] = {
            store,
            store,
            store
    };
    struct sockaddr memb;
    struct sockaddr groups[] = {
            memb,
            memb
    };
    uint32_t len = 3;
    getsourcefilter(anyint(), anyint(), groups, 20, &mode, &len, buf);
}

void runFailure5() {
    struct in_addr addr;
    uint32_t mode;
    struct sockaddr_storage store;
    struct sockaddr_storage buf[] = {
            store,
            store,
            store
    };
    struct sockaddr memb;
    struct sockaddr groups[] = {
            memb,
            memb
    };
    uint32_t len = 30;
    getsourcefilter(anyint(), anyint(), groups, 2, &mode, &len, buf);
}

int f;
void testValues() {
    f = 2;
    
    struct in_addr addr;
    uint32_t mode;
    struct sockaddr_storage store;
    struct sockaddr_storage buf[] = {
            store,
            store,
            store
    };
    struct sockaddr memb;
    struct sockaddr groups[] = {
            memb,
            memb
    };
    uint32_t len = 3;
    getsourcefilter(anyint(), anyint(), groups, 2, &mode, &len, buf);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
