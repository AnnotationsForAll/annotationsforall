#include "../../../test_common.h"
#include <argz.h>

/*@
assigns \result \from \nothing;
ensures argz_valid(\result, size);
ensures argz_count(\result) == count;
*/
extern char* anyargz(size_t size, size_t count);

void runSuccess() {
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    argz_append(&argz, &argz_len, buf, 3);
}

void runFailure() {
    argz_append(NULL, anysize(), NULL, anysize());
}

void runFailure1() {
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    char* argz = "s";
    argz_append(argz, anysize(), buf, 3);
}

void runFailure2() {
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    argz_append(&argz, &argz_len, NULL, anysize());
}

void runFailure3() {
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    argz_append(&argz, &argz_len, buf, 3000);
}

int f;
void testValues() {
    f = 2;

    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    size_t argz_len = anysize();
    char* argz = anyargz(argz_len, anysize());
    argz_append(&argz, &argz_len, buf, 3);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
