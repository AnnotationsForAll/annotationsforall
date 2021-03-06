#include "../../../test_common.h"
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

/*@
assigns \result;
*/
extern locale_t locale();

void runSuccess() {
    towlower_l(WEOF, locale());
    towlower_l(anychar(), locale());
}

void runFailure() {
    towlower_l(invalid(), locale());
}

int f;
void testValues() {
    f = 2;
    wint_t result;
    
    result = towlower_l(anychar(), locale());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


