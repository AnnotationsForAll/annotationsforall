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
    argz_delete(&argz, &argz_len, argz);
}

void runSuccess1() {
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    char* elem = argz_next(argz, argz_len, argz);
    if (elem) {
        argz_delete(&argz, &argz_len, elem);
    }
}

void runSuccess2() {
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    char* elem = argz_next(argz, argz_len, argz);
    if (elem) {
        elem = argz_next(argz, argz_len, elem);
        if (elem) {
            argz_delete(&argz, &argz_len, elem);
        }
    }
}

void runFailure() {
    argz_delete(NULL, anysize(), NULL);
}

void runFailure1() {
    char argz[] = "s";
    argz_delete(argz, anysize(), argz);
}

void runFailure2() {
    size_t argz_len = anysize();
     char* argz = anyargz(argz_len, anysize());
     argz_delete(&argz, &argz_len, NULL);
}

void runFailure3() {
    size_t argz_len = anysize();
     char* argz = anyargz(argz_len, anysize());
     argz_delete(&argz, &argz_len, anystring());
}

int f;
void testValues() {
    f = 2;

    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    char* elem = argz_next(argz, argz_len, argz);
    if (elem) {
        argz_delete(&argz, &argz_len, elem);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
