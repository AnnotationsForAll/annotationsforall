#include "../../../test_common.h"
#include <sys/socket.h>
#include <netdb.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct sockaddr * anysock();

void runSuccess() {
    char s1[10];
    char s2[12];
    
    getnameinfo(anysock(), 1, s1, 10, s2, 12, anyint());
}

void runSuccess1() {
    getnameinfo(anysock(), 1, NULL, anyint(), NULL, anyint(), anyint());
}

void runFailure() {
    char s1[10];
    char s2[12];
    
    getnameinfo(anysock(), 1, s1, 20, s2, 22, anyint());
}

void runFailure1() {
    char s1[10];
    char s2[12];
    
    getnameinfo(NULL, 1, s1, 10, s2, 12, anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    char s1[10];
    char s2[12];
    
    getnameinfo(anysock(), 1, s1, 10, s2, 12, anyint());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
