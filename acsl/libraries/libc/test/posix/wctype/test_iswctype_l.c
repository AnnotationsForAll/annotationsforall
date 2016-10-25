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
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctype_t t = wctype_l(buf, locale());
    if (t == 0) {return;}

    iswctype_l(anychar(), t, locale());
}

void runSuccess1() {
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctype_t t = wctype_l(buf, locale());
    if (t == 0) {return;}

    iswctype_l(WEOF, t, locale());
}

void runFailure() {
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctype_t t = wctype_l(buf, locale());
    if (t == 0) {return;}

    iswctype_l(invalid(), t, locale());
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctype_t t = wctype_l(buf, locale());
    if (t == 0) {return;}

    iswctype_l(L'\n', t, locale());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


