#include "../../../test_common.h"
#include <argz.h>

//@ assigns \result \from \nothing;
extern char anychar();

void runSuccess() {
    char argv[] = "s";
    char* argz; size_t argz_len;
    argz_create_sep(argv, anychar(), &argz, &argz_len);
}

void runFailure() {
    argz_create_sep(NULL, anychar(), NULL, NULL);
}

void runFailure1() {
    char* argz; size_t argz_len;
    argz_create_sep(NULL, anychar(), &argz, &argz_len);
}

void runFailure3() {
    char argv[] = "s";
    char* argz; size_t argz_len;
    argz_create_sep(argv, anychar(), NULL, NULL);
}

void runFailure4() {
    char argv[] = "s";
    char* argz; size_t argz_len;
    argz_create_sep(argv, 3000, &argz, &argz_len);
}

int f;
void testValues() {
    f = 2;
    char argv[] = "s";
    char* argz; size_t argz_len;
    argz_create_sep(argv, anychar(), &argz, &argz_len);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
