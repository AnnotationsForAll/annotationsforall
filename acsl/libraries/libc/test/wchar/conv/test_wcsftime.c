#include "../../../test_common.h"
#include <time.h>
#include <wchar.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern struct tm * anytm();

void runSuccess() {
    wchar_t buf[30];
    //@ assert \valid(buf+(0..29));
    wcsftime(buf, 30, L"!%c!", anytm());
}

void runFailure() {
    wchar_t buf[30];
    //@ assert \valid(buf+(0..29));
    wcsftime(NULL, 30, L"!%c!", anytm());
}

int f;
void testValues() {
    f = 2;
    size_t result;
    wchar_t buf[30];
    //@ assert \valid(buf+(0..29));
    result = wcsftime(buf, 30, L"%c", anytm());
    //@ assert result != 0 ==> \valid_read(buf+(0..29));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
