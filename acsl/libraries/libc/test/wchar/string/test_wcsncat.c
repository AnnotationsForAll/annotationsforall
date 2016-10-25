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
    wcsncat(buf, s1, 1);
}

void runFailure() {
    wchar_t buf[3]; buf[0] = L'A'; buf[1] = L'\0'; buf[2] = L'\0';
    //@ assert \valid(buf+(0..2));
    //@ assert \exists integer x; buf[x] == L'\0';
    wcsncat(buf, NULL, anysize());
}

void runFailure1() {
    wchar_t s1[2]; s1[0] = L'B'; s1[1] = L'\0';
    //@ assert \valid(s1+(0..1));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcsncat(NULL, s1, 30);
}

void runFailure2() {
    wchar_t buf[3]; buf[0] = L'A'; buf[1] = L'\0'; buf[2] = L'\0';
    wchar_t s1[3]; s1[0] = L'B'; s1[1] = L'B'; s1[2] = L'\0';
    //@ assert \valid(buf+(0..2));
    //@ assert \exists integer x; buf[x] == L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcsncat(buf, s1, 30);
}

void runFailure3() {
    wchar_t buf[3]; buf[0] = L'A'; buf[1] = L'\0'; buf[2] = L'\0';
    //@ assert \valid(buf+(0..2));
    //@ assert \exists integer x; buf[x] == L'\0';
    wcsncat(buf, buf, 2);
}

int f;
void testValues() {
    f = 2;
    wchar_t* result;
    
    wchar_t buf[3]; buf[0] = L'B'; buf[1] = L'\0'; buf[2] = L'\0';
    wchar_t s1[2]; s1[0] = L'A'; s1[1] = L'\0';
    //@ assert \valid(buf+(0..2));
    //@ assert \exists integer x; buf[x] == L'\0';
    //@ assert \valid(s1+(0..1));
    //@ assert \exists integer x; s1[x] == L'\0';
    
    result = wcsncat(buf, s1, 1);
    //@ assert result == buf;
    // assert result[0] == L'A';
    // assert result[1] == L'B';
    // assert result[2] == L'\0';
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
