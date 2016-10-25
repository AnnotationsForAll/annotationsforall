#include "../../../test_common.h"
#include <envz.h>

/*@
assigns \result \from \nothing;
ensures argz_valid(\result, size);
ensures argz_count(\result) == count;
*/
extern char* anyargz(size_t size, size_t count);

void runSuccess() {
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    size_t argz2_len = anysize();
    char* argz2 = anyargz(argz2_len, anysize());
    envz_merge(&argz, &argz_len, argz2, argz2_len, anyint());
}

void runFailure() {
    envz_merge(NULL, anysize(), NULL, anysize(), anyint());
}

void runFailure1() {
    char* argz = "s";
    envz_merge(&argz, anysize(), argz, anysize(), anyint());
}

void runFailure2() {
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    envz_merge(&argz, &argz_len, NULL, NULL, anyint());
}

int f;
void testValues() {
    f = 2;

    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    size_t argz2_len = anysize();
    char* argz2 = anyargz(argz2_len, anysize());
    envz_merge(&argz, &argz_len, argz2, argz2_len, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
