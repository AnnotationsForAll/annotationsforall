#include "../../../test_common.h"
#include <wchar.h>

/*@
assigns \result;
ensures \valid(\result);
*/
extern mbstate_t* anystate();

void runSuccess() {
    wchar_t str[MB_CUR_MAX];
    //@ assert \valid(str+(0.. MB_CUR_MAX-1));
    char s1[] = "AAA";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    mbsrtowcs(str, s1, 3, anystate());
}

void runFailure() {
    mbsrtowcs(NULL, NULL, anysize(), anystate());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    wchar_t str[MB_CUR_MAX];
    //@ assert \valid(str+(0.. MB_CUR_MAX-1));
    char s1[] = "AAA";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    mbsrtowcs(str, s1, 3, anystate());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
