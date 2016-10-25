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
    futimes(anyint(), anyspec());
}

void runFailure() {
    futimes(anyint(), NULL);
}

void runFailure1() {
    futimes(anyint(), shortspec());
}

int f;
void testValues() {
    f = 2;
    
    int result = futimes(anyint(), anyspec());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
