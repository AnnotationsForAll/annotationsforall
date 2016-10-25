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
    
    wcspbrk(s1, s2);
}

void runSuccess1() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    
    wcspbrk(s1, s1);
}

void runFailure() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    
    wcspbrk(NULL, s1);
}

void runFailure1() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    
    wcspbrk(s1, NULL);
}

void testValues() {
    wchar_t* result;
    
    wchar_t s1[6]; s1[0] = L'1'; s1[1] = L'2'; s1[2] = L'3'; s1[3] = L'4'; s1[4] = L'5'; s1[5] = L'\0';
    wchar_t s2[3]; s2[0] = L'1'; s2[1] = L'2'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..5));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..2));
    //@ assert \exists integer x; s2[x] == L'\0';
    
    result = wcspbrk(s1, s2);
    //@ assert result == 0 || \base_addr(s1) == \base_addr(result);
    // assert result == s1+2;
    
    //@ assert vacuous: \false;
}

void testValues1() {
    wchar_t* result;
    
    wchar_t s1[6]; s1[0] = L'1'; s1[1] = L'2'; s1[2] = L'3'; s1[3] = L'4'; s1[4] = L'5'; s1[5] = L'\0';
    wchar_t s2[4]; s2[0] = L'3'; s2[1] = L'4'; s2[2] = L'5'; s2[3] = L'\0';
    //@ assert \valid(s1+(0..5));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..3));
    //@ assert \exists integer x; s2[x] == L'\0';
    
    result = wcspbrk(s1, s2);
    //@ assert result == 0 || \base_addr(s1) == \base_addr(result);
    // assert result == s1+0;
    
    //@ assert vacuous: \false;
}

void testValues2() {
    wchar_t* result;
    
    wchar_t s1[6]; s1[0] = L'A'; s1[1] = L'B'; s1[2] = L'C'; s1[3] = L'\0'; s1[4] = L'\0'; s1[5] = L'\0';
    wchar_t s2[4]; s2[0] = L'A'; s2[1] = L'C'; s2[2] = L'B'; s2[3] = L'\0';
    //@ assert \valid(s1+(0..5));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..3));
    //@ assert \exists integer x; s2[x] == L'\0';
    
    result = wcspbrk(s1, s2);
    //@ assert result == 0 || \base_addr(s1) == \base_addr(result);
    // assert result == s1+3;
    
    //@ assert vacuous: \false;
}
