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
    iswdigit(WEOF);
    iswdigit(anychar());
}

void runFailure() {
    iswdigit(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    result = iswdigit(anychar());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


