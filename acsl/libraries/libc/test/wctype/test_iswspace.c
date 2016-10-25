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
    iswspace(WEOF);
    iswspace(anychar());
}

void runFailure() {
    iswspace(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = iswspace(anychar());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


