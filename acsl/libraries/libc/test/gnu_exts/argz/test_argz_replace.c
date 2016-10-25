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
    argz_replace(&argz, &argz_len, anystring(), anystring(), NULL);
}

void runSuccess1() {
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    unsigned int count;
    argz_replace(&argz, &argz_len, anystring(), anystring(), &count);
}

void runFailure() {
    argz_replace(NULL, NULL, NULL, NULL, NULL);
}

void runFailure1() {
    unsigned int count;
    argz_replace(NULL, NULL, anystring(), anystring(), &count);
}

void runFailure2() {
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    argz_replace(&argz, &argz_len, NULL, NULL, NULL);
}

void runFailure3() {
    size_t argz_len = anysize();
    char argz[] = "s";
    unsigned int count;
    argz_replace(&argz, &argz_len, anystring(), anystring(), &count);
}

int f;
void testValues() {
    f = 2;

    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    unsigned int count;
    argz_replace(&argz, &argz_len, anystring(), anystring(), &count);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
