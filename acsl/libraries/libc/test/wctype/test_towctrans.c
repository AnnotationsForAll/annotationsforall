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
    wctrans_t t = wctrans(buf);
    if (t == 0) {return;}

    towctrans(anychar(), t);
}

void runSuccess1() {
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctrans_t t = wctrans(buf);
    if (t == 0) {return;}

    towctrans(WEOF, t);
}

void runFailure() {
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctrans_t t = wctrans(buf);
    if (t == 0) {return;}

    towctrans(invalid(), t);
}

int f;
void testValues() {
    f = 2;
    wint_t result;

    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctrans_t t = wctrans(buf);
    if (t == 0) {return;}

    towctrans(anychar(), t);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


