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
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctype_t t = wctype(buf);
    if (t == 0) {return;}

    iswctype(anychar(),t);
}

void runSuccess1() {
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctype_t t = wctype(buf);
    if (t == 0) {return;}

    iswctype(WEOF,t);
}

void runFailure() {
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctype_t t = wctype(buf);
    if (t == 0) {return;}

    iswctype(invalid(),t);
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctype_t t = wctype(buf);
    if (t == 0) {return;}

    iswctype(L'\n',t);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


