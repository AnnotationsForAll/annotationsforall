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
    envz_add(&argz, &argz_len, anystring(), anystring());
}

void runFailure() {
    envz_add(NULL, anysize(), anystring(), anystring());
}

void runFailure1() {
    char* argz = "s";
    envz_add(&argz, anysize(), anystring(), anystring());
}

void runFailure2() {
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    envz_add(&argz, &argz_len, NULL, NULL);
}

int f;
void testValues() {
    f = 2;

    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    envz_add(&argz, &argz_len, anystring(), anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
