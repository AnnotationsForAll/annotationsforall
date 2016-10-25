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
    towlower(WEOF);
    towlower(anychar());
}

void runFailure() {
    towlower(invalid());
}

int f;
void testValues() {
    f = 2;
    wint_t result;
    
    result = towlower(anychar());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


