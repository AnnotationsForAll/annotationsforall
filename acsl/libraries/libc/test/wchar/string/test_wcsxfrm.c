#include "../../../test_common.h"
#include <string.h>
#include <wchar.h>

void runSuccess() {
    char buf[3]; buf[0] = 'A'; buf[1] = '\0'; buf[2] = '\0';
    wchar_t s1[2]; s1[0] = L'B'; s1[1] = L'\0';
    //@ assert \valid(buf+(0..2));
    //@ assert \exists integer x; buf[x] == L'\0';
    //@ assert \valid(s1+(0..1));
    //@ assert \exists integer x; s1[x] == L'\0';
    
    wcsxfrm(buf, s1, 1);
    wcsxfrm(NULL, s1, 0);
}

void runFailure() {
    wchar_t buf[3]; buf[0] = L'A'; buf[1] = L'\0'; buf[2] = L'\0';
    //@ assert \valid(buf+(0..2));
    //@ assert \exists integer x; buf[x] == L'\0';
    wcsxfrm(buf, buf, 1);
}

void runFailure1() {
    wchar_t s1[2]; s1[0] = L'B'; s1[1] = L'\0';
    //@ assert \valid(s1+(0..1));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcsxfrm(NULL, s1, 10);
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[3]; buf[0] = 'A'; buf[1] = '\0'; buf[2] = '\0';
    wchar_t s1[2]; s1[0] = L'B'; s1[1] = L'\0';
    //@ assert \valid(buf+(0..2));
    //@ assert \exists integer x; buf[x] == L'\0';
    //@ assert \valid(s1+(0..1));
    //@ assert \exists integer x; s1[x] == L'\0';
    
    wcsxfrm(buf, s1, 1);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
