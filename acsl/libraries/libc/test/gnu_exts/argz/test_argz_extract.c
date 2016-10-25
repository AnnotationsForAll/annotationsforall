#include "../../../test_common.h"
#include <argz.h>

/*@
assigns \result \from \nothing;
ensures argz_valid(\result, size);
ensures argz_count(\result) == count;
*/
extern char* anyargz(size_t size, size_t count);

void runSuccess() {
    char* argv[] = {anystring()};
    size_t argz_len = anysize();
    argz_extract(anyargz(argz_len, 0), argz_len, argv);
}

void runSuccess1() {
    char* argv[] = {anystring(),anystring()};
    size_t argz_len = anysize();
    argz_extract(anyargz(argz_len, 1), argz_len, argv);
}

void runFailure() {
    argz_extract(NULL, anysize(), NULL);
}

void runFailure1() {
    char* argv[] = {anystring(), anystring()};
    char argz[] = "s";
    argz_extract(argz, anysize(), argv);
}

void runFailure2() {
    char* argv[] = {anystring(),anystring()};
    size_t argz_len = anysize();
    argz_extract(anyargz(argz_len, 5), argz_len, argv);
}

int f;
void testValues() {
    f = 2;

    char* argv[] = {anystring()};
    size_t argz_len = anysize();
    argz_extract(anyargz(argz_len, 0), argz_len, argv);

    char* argv2[] = {anystring(),anystring()};
    size_t argz_len2 = anysize();
    argz_extract(anyargz(argz_len2, 1), argz_len2, argv2);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
