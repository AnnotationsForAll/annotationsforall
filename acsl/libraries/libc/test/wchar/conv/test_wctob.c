#include "../../../test_common.h"
#include <wchar.h>

/*@
assigns \result;
*/
extern wint_t anywint();

void runSuccess() {
    wctob(L'a');
    wctob(42);
    wctob(WEOF);
    wctob(anywint());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = wctob(anywint());
    //@ assert result == EOF || (unsigned char)result == result;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
