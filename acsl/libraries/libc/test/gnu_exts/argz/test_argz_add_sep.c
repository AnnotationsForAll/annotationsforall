#include "../../../test_common.h"
#include <argz.h>

/*@
assigns \result \from \nothing;
ensures argz_valid(\result, size);
ensures argz_count(\result) == count;
*/
extern char* anyargz(size_t size, size_t count);

//@ assigns \result \from \nothing;
extern char anychar();

void runSuccess() {
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    argz_add_sep(&argz, &argz_len, anystring(), anychar());
}

void runFailure() {
    argz_add_sep(NULL, anysize(), anystring(), anychar());
}

void runFailure1() {
    char* argz = "s";
    argz_add_sep(argz, anysize(), anystring(), anychar());
}

void runFailure2() {
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    argz_add_sep(&argz, &argz_len, NULL, anychar());
}

void runFailure3() {
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    argz_add_sep(&argz, &argz_len, anystring(), 3000);
}

int f;
void testValues() {
    f = 2;

    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    argz_add_sep(&argz, &argz_len, anystring(), anychar());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
