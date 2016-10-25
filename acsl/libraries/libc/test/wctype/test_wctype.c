#include "../../test_common.h"
#include <wctype.h>
#include <wchar.h>

/*@
assigns \result;
*/
extern wctype_t anytype();

void runSuccess() {
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctype(buf);
}

void runFailure() {
    wctype(NULL);
}

int f;
void testValues() {
    f = 2;
    wctype_t result;

    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctype(buf);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
