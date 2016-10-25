#include "../../../test_common.h"
#include <iconv.h>

void runSuccess() {
   char s1[] = "code1";
   char s2[] = "code2";
   //@ assert \valid(s1+(0..\block_length(s1)-1));
   //@ assert \exists integer x; s1[x] == '\0';
   //@ assert \valid(s2+(0..\block_length(s2)-1));
   //@ assert \exists integer x; s2[x] == '\0';
   
   iconv_open(s1, s2);
}
void runFailure() {
    iconv_open(NULL, NULL); 
}

int f;
void testValues() {
    f = 2;
    iconv_t result;
    
    char s1[] = "code1";
    char s2[] = "code2";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    result = iconv_open(s1, s2);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
