#include "../../test_common.h"
#include <wctype.h>
#include <wchar.h>

void runSuccess() {
    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctrans(buf);
}

void runFailure() {
    wctrans(NULL);
}

int f;
void testValues() {
    f = 2;
    wctrans_t result;

    char buf[] = "";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    wctrans(buf);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


