#include "../../../test_common.h"
#include <wchar.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern mbstate_t* anystate();

void runSuccess() {
    mbsinit(anystate());
    mbsinit(NULL);
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = mbsinit(NULL);
    //@ assert result != 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}