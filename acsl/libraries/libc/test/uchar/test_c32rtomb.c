#include "../../test_common.h"
#include <uchar.h>
#include <stdlib.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern mbstate_t* anystate();

/*@
assigns \result;
*/
extern char32_t anychar();

void runSuccess() {
    char s1[MB_CUR_MAX]; s1[0] = 'A'; s1[1] = '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    c32rtomb(s1,L'a',anystate());
    c32rtomb(NULL,L'?',anystate());
    c32rtomb(s1,anychar(),anystate());
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    size_t result;
    
    char s1[MB_CUR_MAX]; s1[0] = 'A'; s1[1] = '\0';
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    result = c32rtomb(s1, L'a', anystate());
    //@ assert result == (size_t)(-1) ==> errno != 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
