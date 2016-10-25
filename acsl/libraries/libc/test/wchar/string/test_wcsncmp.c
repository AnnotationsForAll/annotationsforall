#include "../../../test_common.h"
#include <wchar.h>

void runSuccess() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L's'; s2[1] = L'2'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..2));
    //@ assert \exists integer x; s2[x] == L'\0';
    wcsncmp(s1, s2, 1);
    wcsncmp(s1, s1, 2);
}

void runFailure() {
    wchar_t s2[3]; s2[0] = L's'; s2[1] = L'2'; s2[2] = L'\0';
    //@ assert \valid(s2+(0..2));
    //@ assert \exists integer x; s2[x] == L'\0';
    wcsncmp(NULL, s2, 5);
}

void runFailure1() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    wcsncmp(s1, NULL, 5);
}

void testValues() {
    wchar_t s1[3]; s1[0] = L'A'; s1[1] = L'A'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L'B'; s2[1] = L'B'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..2));
    //@ assert \exists integer x; s2[x] == L'\0';
    
    int result = wcsncmp(s1, s2, 2);
    //@ assert result != 0;
    
    //@ assert vacuous: \false;
}

void testValues1() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    
    int result = wcsncmp(s1, s1, 2);
    //@ assert result == 0;
    
    //@ assert vacuous: \false;
}

void testValues2() {
    wchar_t s1[3]; s1[0] = L'A'; s1[1] = L'B'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L'A'; s2[1] = L'A'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..2));
    //@ assert \exists integer x; s2[x] == L'\0';
    
    int result = wcsncmp(s1, s2, 2);
    //@ assert result != 0;
    
    //@ assert vacuous: \false;
}

void testValues3() {
    wchar_t s1[3]; s1[0] = L'A'; s1[1] = L'\0'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L'A'; s2[1] = L'A'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..2));
    //@ assert \exists integer x; s2[x] == L'\0';
    
    int result = wcsncmp(s1, s2, 2);
    //@ assert result != 0;
    
    //@ assert vacuous: \false;
}

void testValues4() {
    wchar_t s1[3]; s1[0] = L'A'; s1[1] = L'A'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L'A'; s2[1] = L'\0'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..2));
    //@ assert \exists integer x; s2[x] == L'\0';
    
    int result = wcsncmp(s1, s2, 2);
    //@ assert result != 0;
    
    //@ assert vacuous: \false;
}

void testValues5() {
    wchar_t s1[3]; s1[0] = L'A'; s1[1] = L'\0'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L'A'; s2[1] = L'A'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \exists integer x; s1[x] == L'\0';
    //@ assert \valid(s2+(0..2));
    //@ assert \exists integer x; s2[x] == L'\0';
    
    int result = wcsncmp(s1, s2, 1);
    //@ assert result == 0;
    
    //@ assert vacuous: \false;
}
