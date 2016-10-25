#include "../../../test_common.h"
#include <string.h>
#include <wchar.h>

void runSuccess() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L's'; s2[1] = L'2'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..2));
    //@ assert \exists integer x; s2[x] == L'\0';
    wcsstr(s1, s2);
}

void runSuccess1() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcsstr(s1, s1);
}

void runFailure() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcsstr(NULL, s1);
}

void runFailure1() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcsstr(s1, NULL);
}

void testValues() {
    wchar_t* result;
    
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L'1'; s2[1] = L'\0'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..2));
    //@ assert \exists integer x; s2[x] == L'\0';
    wchar_t needle[2] = L"e";
    
    result = wcsstr(s1, needle);
    //@ assert result != \null ==> (\base_addr(result) == \base_addr(s1));
    
    //@ assert vacuous: \false;
}
