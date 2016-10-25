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
    char buf[INET_ADDRSTRLEN];
    //@ assert \valid(buf+(0.. INET_ADDRSTRLEN-1));
    inet_ntop(AF_INET, anyptr(), buf, (socklen_t)INET_ADDRSTRLEN);
}

void runSuccess1() {
    char buf[1];
    //@ assert \valid(buf);
    inet_ntop(AF_INET, anyptr(), buf, (socklen_t)1);
}

void runSuccess2() {
    char buf[INET6_ADDRSTRLEN];
    //@ assert \valid(buf+(0.. INET6_ADDRSTRLEN-1));
    inet_ntop(anyint(), anyptr(), buf, (socklen_t)INET6_ADDRSTRLEN);
}

void runFailure() {
    char buf[INET_ADDRSTRLEN];
    //@ assert \valid(buf+(0.. INET_ADDRSTRLEN-1));
    inet_ntop(AF_INET, NULL, buf, (socklen_t)INET_ADDRSTRLEN);
}

void runFailure1() {
    inet_ntop(AF_INET, anyptr(), NULL, (socklen_t)INET_ADDRSTRLEN);
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    char buf[INET_ADDRSTRLEN];
    //@ assert \valid(buf+(0.. INET_ADDRSTRLEN-1));
    result = inet_ntop(AF_INET, anyptr(), buf, (socklen_t)INET_ADDRSTRLEN);
    //@ assert result != \null ==> \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

void testValues1() {
    f = 2;
    char* result;
    
    char buf[INET_ADDRSTRLEN];
    //@ assert \valid(buf+(0.. INET_ADDRSTRLEN-1));
    result = inet_ntop(invalid_af(), anyptr(), buf, (socklen_t)INET_ADDRSTRLEN);
    //@ assert result == \null;
    //@ assert errno != 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

void testValues2() {
    f = 2;
    char* result;
    
    char buf[1];
    result = inet_ntop(AF_INET, anyptr(), buf, (socklen_t)1);
    //@ assert result == \null;
    //@ assert errno != 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
