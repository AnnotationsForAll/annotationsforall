#include "../../../test_common.h"
#include <netdb.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct addrinfo * anyai();

void runSuccess() {
    struct addrinfo * res;
    char s1[] = "node";
    char s2[] = "serv";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    getaddrinfo(s1, s2, anyai(), &res);
}

void runFailure() {
    getaddrinfo(NULL, NULL, NULL, NULL);
}

void runFailure1() {
    struct addrinfo * res;

    getaddrinfo(NULL, NULL, NULL, &res);
}

void runFailure2() {
    struct addrinfo * res;

    getaddrinfo(NULL, NULL, anyai(), &res);
}

int f;
void testValues() {
    f = 2;
    int result;
    struct addrinfo * res;
    char s1[] = "node";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
        
    result = getaddrinfo(s1, NULL, NULL, &res);
    //@ assert result == 0 ==> \valid(res);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
