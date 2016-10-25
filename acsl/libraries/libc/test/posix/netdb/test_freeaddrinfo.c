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
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    if (getaddrinfo(s1, NULL, NULL, &res)) {return;}

    freeaddrinfo(res);
}

void runFailure() {
    freeaddrinfo(NULL);
}

int f;
void testValues() {
    f = 2;
    struct addrinfo * res;
    char s1[] = "node";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    if (getaddrinfo(s1, NULL, NULL, &res)) {return;}
    
    freeaddrinfo(res);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
