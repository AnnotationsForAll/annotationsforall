#include "../../test_common.h"
#include <stdlib.h>

char str[MB_CUR_MAX];

/*@
assigns \result;
*/
extern wchar_t anywc();

void runSuccess() {
   wctomb(str, anywc());
   wctomb(NULL, anywc());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = wctomb(str, anywc());
    //@ assert result <= MB_CUR_MAX;
    // If str not null, result is -1, or result is number of bytes contained in wc
    //@ assert (result != -1) ==> (0 <= result < (MB_CUR_MAX * sizeof(char)));

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
