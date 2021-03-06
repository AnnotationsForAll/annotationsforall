#include "../../../test_common.h"
#include <sys/time.h>

/*@
assigns \result;
ensures \valid(\result+(0..1));
*/
extern const struct timeval * anyspec();

/*@
assigns \result;
ensures \valid(\result+(0..0));
*/
extern const struct timeval * shortspec();

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    futimesat(anyint(), buf, anyspec());
}

void runFailure() {
    futimesat(anyint(), NULL, NULL);
}

void runFailure1() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    futimesat(anyint(), buf, shortspec());
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = futimesat(anyint(), buf, anyspec());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
