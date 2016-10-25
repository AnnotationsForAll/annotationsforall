#include "../../../test_common.h"
#include <argz.h>

/*@
assigns \result \from \nothing;
ensures argz_valid(\result, size);
ensures argz_count(\result) == count;
*/
extern char* anyargz(size_t size, size_t count);

void runSuccess() {
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    argz_insert(&argz, &argz_len, argz, anystring());
}

void runSuccess1() {
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    char* elem = argz_next(argz, argz_len, argz);
    if (elem) {
        argz_insert(&argz, &argz_len, elem, anystring());
    }
}

void runSuccess2() {
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    char* elem = argz_next(argz, argz_len, argz);
    if (elem) {
        elem = argz_next(argz, argz_len, elem);
        if (elem) {
            argz_insert(&argz, &argz_len, elem, anystring());
        }
    }
}

void runFailure() {
    argz_insert(NULL, anysize(), NULL, NULL);
}

void runFailure1() {
    char argz[] = "s";
    argz_insert(argz, anysize(), argz, anystring());
}

void runFailure2() {
    size_t argz_len = anysize();
     char* argz = anyargz(argz_len, anysize());
     argz_insert(&argz, &argz_len, NULL, anystring());
}

void runFailure3() {
    size_t argz_len = anysize();
     char* argz = anyargz(argz_len, anysize());
     argz_insert(&argz, &argz_len, anystring(), anystring());
}

void runFailure4() {
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    argz_insert(&argz, &argz_len, argz, NULL);
}

int f;
void testValues() {
    f = 2;

    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    char* elem = argz_next(argz, argz_len, argz);
    if (elem) {
        argz_insert(&argz, &argz_len, elem, anystring());
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
