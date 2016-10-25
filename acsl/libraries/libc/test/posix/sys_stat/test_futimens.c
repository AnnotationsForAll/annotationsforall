#include "../../../test_common.h"
#include <sys/stat.h>

/*@
assigns \result;
ensures \valid(\result+(0..1));
*/
extern const struct timespec * anyspec();

/*@
assigns \result;
ensures \valid(\result+(0..0));
*/
extern const struct timespec * shortspec();

void runSuccess() {
    futimens(anyint(), anyspec());
}

void runFailure() {
    futimens(anyint(), NULL);
}

void runFailure1() {
    futimens(anyint(), shortspec());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = futimens(anyint(), anyspec());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
