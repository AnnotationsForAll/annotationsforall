#include "../../../test_common.h"
#include <argz.h>

//@ assigns \result \from \nothing;
extern char anychar();

/*@
assigns \result \from \nothing;
ensures argz_valid(\result, size);
ensures argz_count(\result) == count;
*/
extern char* anyargz(size_t size, size_t count);

void runSuccess() {
    size_t argz_len = anysize();
    argz_stringify(anyargz(argz_len, anysize()), argz_len, anychar());
}

void runFailure() {
    argz_stringify(NULL, anysize(), anychar());
}

void runFailure1() {
    char* argz = "s";
    argz_stringify(argz, anysize(), anychar());
}

void runFailure2() {
    size_t argz_len = anysize();
    argz_stringify(anyargz(argz_len, anysize()), argz_len, 3000);
}

int f;
void testValues() {
    f = 2;

    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    argz_stringify(argz, argz_len, anychar());
    //@ assert \valid(argz);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
