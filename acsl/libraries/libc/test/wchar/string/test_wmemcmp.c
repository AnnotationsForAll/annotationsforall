#include "../../../test_common.h"
#include <string.h>
#include <wchar.h>

void runSuccess() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L's'; s2[1] = L'2'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \valid(s2+(0..2));
    
    wmemcmp(s1, s2, 2);
}

void runSuccess1() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L's'; s2[1] = L'2'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \valid(s2+(0..2));
    
    wmemcmp(s1, s2, 1);
}

void runSuccess2() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    
    wmemcmp(s1, s1, 1);
}

void runFailure() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    
    wmemcmp(NULL, s1, 5);
}

void runFailure1() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    
    wmemcmp(s1, NULL, 5);
}

void runFailure2() {
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L's'; s2[1] = L'2'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \valid(s2+(0..2));
    
    wmemcmp(s1, s2, 97);
}

void testValues() {
    int result;
    
    wchar_t s1[3]; s1[0] = L'A'; s1[1] = L'A'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L'B'; s2[1] = L'B'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \valid(s2+(0..2));
    
    result = wmemcmp(s1, s2, 2);
    //@ assert result != 0;
    
    //@ assert vacuous: \false;
}

void testValues1() {
    int result;
    
    wchar_t s1[3]; s1[0] = L's'; s1[1] = L'1'; s1[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    
    result = wmemcmp(s1, s1, 1);
    //@ assert result == 0;
    
    //@ assert vacuous: \false;
}

void testValues2() {
    int result;
    
    wchar_t s1[3]; s1[0] = L'A'; s1[1] = L'B'; s1[2] = L'\0';
    wchar_t s2[3]; s2[0] = L'A'; s2[1] = L'A'; s2[2] = L'\0';
    //@ assert \valid(s1+(0..2));
    //@ assert \valid(s2+(0..2));
    
    result = wmemcmp(s1, s2, 2);
    //@ assert result != 0;
    
    //@ assert vacuous: \false;
}
