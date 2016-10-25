#include "../../test_common.h"
#include <wctype.h>
#include <wchar.h>


/*@
assigns \result;
*/
extern wchar_t anychar();
/*@
assigns \result;
ensures (wchar_t)\result != \result && \result != WEOF;
*/
extern wint_t invalid();

void runSuccess() {
    iswprint(WEOF);
    iswprint(anychar());
}

void runFailure() {
    iswprint(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = iswprint(anychar());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


