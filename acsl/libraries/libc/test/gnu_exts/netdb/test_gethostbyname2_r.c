#include "../../../test_common.h"
#include <netdb.h>

void runSuccess() {
    struct hostent result_buf;
    char buf[] = "s";
    struct hostent * result;
    int h_errnop;
    gethostbyname2_r(anystring(), anyint(), &result_buf, &buf, 1, &result, &h_errnop);
}

void runFailure() {
    gethostbyname2_r(NULL, anyint(), NULL, NULL, anyint(), NULL, NULL);
}

void runFailure1() {
    struct hostent result_buf;
    char buf[] = "s";
    struct hostent * result;
    int h_errnop;
    gethostbyname2_r(anystring(), anyint(), &result_buf, &buf, 50, &result, &h_errnop);
}

int f;
void testValues() {
    f = 2;
    
    struct hostent result_buf;
    char buf[] = "s";
    struct hostent * result;
    int h_errnop;
    gethostbyname2_r(anystring(), anyint(), &result_buf, &buf, 1, &result, &h_errnop);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
