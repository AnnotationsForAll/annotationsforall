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
    argz_count(anyargz(argz_len, anysize()), argz_len);
}

void runFailure() {
    argz_count(NULL, anysize());
}

void runFailure1() {
    char argz[] = "s";
    argz_count(argz, anysize());
}

int f;
void testValues() {
    f = 2;

    size_t argz_len = anysize();
    size_t result = argz_count(anyargz(argz_len, 1), argz_len);
    //@ assert result == 1;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
