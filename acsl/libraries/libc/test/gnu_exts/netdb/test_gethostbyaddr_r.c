#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    struct hostent result_buf;
    char buf[] = "s";
    struct hostent * result;
    int h_errnop;
    char addr[] = "s";
    gethostbyaddr_r(addr, 1, anyint(), &result_buf, &buf, 1, &result, &h_errnop);
}

void runSuccess1() {
    struct hostent result_buf;
    char buf[] = "s";
    struct hostent * result;
    int h_errnop;
    char addr[] = "s";
    gethostbyaddr_r(addr, 0, anyint(), &result_buf, &buf, 1, &result, &h_errnop);
}

void runFailure() {
    struct hostent result_buf;
    char buf[] = "s";
    struct hostent * result;
    int h_errnop;
    gethostbyaddr_r(NULL, anyint(), anyint(), &result_buf, &buf, 1, &result, &h_errnop);
}

void runFailure1() {
    struct hostent result_buf;
    char buf[] = "s";
    struct hostent * result;
    int h_errnop;
    char addr[] = "s";
    gethostbyaddr_r(addr, 50, anyint(), &result_buf, &buf, 1, &result, &h_errnop);
}

void runFailure2() {
    gethostbyaddr_r(NULL, anyint(), anyint(), NULL, NULL, anyine(), NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    
    struct hostent result_buf;
    char buf[] = "s";
    struct hostent * result;
    int h_errnop;
    char addr[] = "s";
    gethostbyaddr_r(addr, 1, anyint(), &result_buf, &buf, 1, &result, &h_errnop);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
