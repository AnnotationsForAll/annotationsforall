#include "../../../test_common.h"
#include <argz.h>

void runSuccess() {
    char* argv[] = {NULL};
    //@ assert \exists size_t i; (argv[i] == \null);
    char* argz; size_t argz_len;
    argz_create(argv, &argz, &argz_len);
}

void runSuccess1() {
    char* argv[] = {anystring(), anystring(), NULL};
    //@ assert \exists size_t i; (argv[i] == \null);
    char* argz; size_t argz_len;
    argz_create(argv, &argz, &argz_len);
}

void runFailure() {
    argz_create(NULL, NULL, NULL);
}

void runFailure1() {
    char* argz; size_t argz_len;
    argz_create(NULL, &argz, &argz_len);
}

void runFailure2() {
    char* argv[] = {anystring(), anystring()};
    char* argz; size_t argz_len;
    argz_create(argv, &argz, &argz_len);
}

void runFailure3() {
    char* argv[] = {anystring(), anystring(), NULL};
    //@ assert \exists size_t i; (argv[i] == \null);
    char* argz; size_t argz_len;
    argz_create(argv, NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    char* argv[] = {anystring(), NULL};
    //@ assert \exists size_t i; (argv[i] == \null);
    char* argz; size_t argz_len;
    argz_create(argv, &argz, &argz_len);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
