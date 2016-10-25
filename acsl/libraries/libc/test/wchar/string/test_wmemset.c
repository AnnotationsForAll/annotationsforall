#include "../../../test_common.h"
#include <string.h>
#include <wchar.h>

void runSuccess() {
    wchar_t buf[3]; buf[0] = L'A'; buf[1] = L'\0'; buf[2] = L'\0';
    //@ assert \valid(buf+(0..2));
    
    wmemset(buf, L'a', 3);
    wmemset(buf, L'\0', 2);
}

void runFailure() {
    wmemset(NULL, L'x', 4);
}

int f;
void testValues() {
    f = 2;
    wchar_t* result;
    
    wchar_t buf[3]; buf[0] = L'A'; buf[1] = L'A'; buf[2] = L'\0';
    //@ assert \valid(buf+(0..2));
    
    result = wmemset(buf, L'!', 1);
    //@ assert result == buf;
    //@ assert result[0] == L'!';
    //@ assert result[1] == L'A';
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
