#include "../../../test_common.h"
#include <string.h>
#include <wchar.h>

void runSuccess() {
    wchar_t buf[3]; buf[0] = L'A'; buf[1] = L'\0'; buf[2] = L'\0';
    //@ assert \valid(buf+(0..2));
    wmemchr(buf, L'?', 1);
    wmemchr(buf, L'\0', 1);
}

void runFailure() {
    wmemchr(NULL, L'H', 30); 
}

int f;
void testValues() {
    f = 2;
    wchar_t* result;
    
    wchar_t buf[3]; buf[0] = L'A'; buf[1] = L't'; buf[2] = L'\0';
    //@ assert \valid(buf+(0..2));
    
    result = wmemchr(buf, L't', 3);
    //@ assert result != \null ==> (\base_addr(result) == \base_addr(buf));
    //@ assert result != \null ==> *result == L't';
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
