#include "../../../test_common.h"
#include <string.h>
#include <wchar.h>

void runSuccess() {
    wchar_t buf[2]; buf[0] = L'A'; buf[1] = L'\0';
    wchar_t s1[2]; s1[0] = L'B'; s1[1] = L'\0';
    //@ assert \valid(buf+(0..1));
    //@ assert \exists integer x; buf[x] == L'\0';
    //@ assert \valid(s1+(0..1));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcscpy(buf, s1);
}

void runFailure() {
    wchar_t buf[2]; buf[0] = L'A'; buf[1] = L'\0';
    //@ assert \valid(buf+(0..1));
    //@ assert \exists integer x; buf[x] == L'\0';
    wcscpy(buf, NULL);
}

void runFailure1() {
    wchar_t s1[2]; s1[0] = L'B'; s1[1] = L'\0';
    //@ assert \valid(s1+(0..1));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcscpy(NULL, s1);
}

void runFailure2() {
    wchar_t buf[2]; buf[0] = L'A'; buf[1] = L'\0';
    wchar_t s1[3]; s1[0] = L'B'; s1[1] = L'B'; s1[2] = L'\0';
    //@ assert \valid(buf+(0..1));
    //@ assert \exists integer x; buf[x] == L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcscpy(buf, s1);
}

void runFailure3() {
    wchar_t buf[2]; buf[0] = L'A'; buf[1] = L'\0';
    //@ assert \valid(buf+(0..1));
    //@ assert \exists integer x; buf[x] == L'\0';
    wcscpy(buf, buf);
}

int f;
void testValues() {
    f = 2;
    wchar_t* result;
    
    wchar_t buf[4]; buf[0] = L'B'; buf[1] = L'B'; buf[2] = L'B'; buf[3] = L'\0';
    wchar_t s1[2]; s1[0] = L'A'; s1[1] = L'\0';
    //@ assert \valid(buf+(0..3));
    //@ assert \exists integer x; buf[x] == L'\0';
    //@ assert \valid(s1+(0..1));
    //@ assert \exists integer x; s1[x] == L'\0';
    
    result = wcscpy(buf, s1);
    //@ assert result == buf;
    
    int cmp = wmemcmp(buf, s1, 2);
    //@ assert cmp == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
