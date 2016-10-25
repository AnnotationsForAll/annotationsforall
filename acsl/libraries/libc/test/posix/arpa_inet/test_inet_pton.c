#include "../../../test_common.h"
#include <arpa/inet.h>
#include <stdint.h>
#include <errno.h>

//TODO: should we add IPv6 support?

/*@
assigns \result;
ensures \valid((char*)\result+(0..15));
*/
extern void* anyptr();

/*@
assigns \result;
ensures \result != AF_INET && \result != AF_INET6;
*/
extern int invalid_af();

void runSuccess() {
    char buf[INET_ADDRSTRLEN]; buf[0] = '\0';
    //@ assert \valid(buf+(0.. INET_ADDRSTRLEN-1));
    //@ assert \exists integer x; buf[x] == '\0';
    inet_pton(AF_INET, buf, anyptr());
}

void runSuccess1() {
    char buf[INET6_ADDRSTRLEN]; buf[0] = '\0';
    //@ assert \valid(buf+(0.. INET6_ADDRSTRLEN-1));
    //@ assert \exists integer x; buf[x] == '\0';
    inet_pton(anyint(), buf, anyptr());
}

void runFailure() {
    char buf[INET_ADDRSTRLEN]; buf[0] = '\0';
    //@ assert \valid(buf+(0.. INET_ADDRSTRLEN-1));
    //@ assert \exists integer x; buf[x] == '\0';
    inet_pton(AF_INET, NULL, anyptr());
}

void runFailure1() {
    char buf[INET_ADDRSTRLEN]; buf[0] = '\0';
    //@ assert \valid(buf+(0.. INET_ADDRSTRLEN-1));
    //@ assert \exists integer x; buf[x] == '\0';
    inet_pton(AF_INET, buf, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    char buf[INET_ADDRSTRLEN]; buf[0] = '\0';
    //@ assert \valid(buf+(0.. INET_ADDRSTRLEN-1));
    //@ assert \exists integer x; buf[x] == '\0';
    result = inet_pton(AF_INET, buf, anyptr());
    //@ assert -1 <= result <= 1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

void testValues1() {
    f = 2;
    int result;
    
    char buf[INET_ADDRSTRLEN]; buf[0] = '\0';
    //@ assert \valid(buf+(0.. INET_ADDRSTRLEN-1));
    //@ assert \exists integer x; buf[x] == '\0';
    result = inet_pton(invalid_af(), buf, anyptr());
    //@ assert result == -1;
    //@ assert errno != 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
