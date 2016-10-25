#include "../../../test_common.h"
#include <string.h>
#include <wchar.h>

void runSuccess() {
    wchar_t buf[3]; buf[0] = L'A'; buf[1] = L'\0'; buf[2] = L'\0';
    wchar_t s1[2]; s1[0] = L'B'; s1[1] = L'\0';
    //@ assert \valid(buf+(0..2));
    //@ assert \exists integer x; buf[x] == L'\0';
    //@ assert \valid(s1+(0..1));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcscat(buf, s1);
}

void runFailure() {
    wchar_t buf[3]; buf[0] = L'A'; buf[1] = L'\0'; buf[2] = L'\0';
    //@ assert \valid(buf+(0..2));
    //@ assert \exists integer x; buf[x] == L'\0';
    wcscat(buf, NULL);
}

void runFailure1() {
    wchar_t s1[2]; s1[0] = L'B'; s1[1] = L'\0';
    //@ assert \valid(s1+(0..1));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcscat(NULL, s1);
}

void runFailure3() {
    wchar_t buf[3]; buf[0] = L'A'; buf[1] = L'\0'; buf[2] = L'\0';
    //@ assert \valid(buf+(0..2));
    //@ assert \exists integer x; buf[x] == L'\0';
    wcscat(buf, buf);
}

int f;
void testValues() {
    f = 2;
    wchar_t* result;
    wchar_t buf[3]; buf[0] = L'A'; buf[1] = L'\0'; buf[2] = L'\0';
    wchar_t s1[2]; s1[0] = L'B'; s1[1] = L'\0';
    //@ assert \valid(buf+(0..2));
    //@ assert \exists integer x; buf[x] == L'\0';
    //@ assert \valid(s1+(0..1));
    //@ assert \exists integer x; s1[x] == L'\0';
    
    result = wcscat(buf, s1);
    //@ assert result == buf;

    int cmp = wcslen(result);
    //@ assert cmp == 2;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
