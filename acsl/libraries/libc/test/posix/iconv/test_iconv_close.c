#include "../../../test_common.h"
#include <iconv.h>
#include <errno.h>

void runSuccess() {
    char s1[] = "";
    char s2[] = "";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';

    iconv_t cd = iconv_open(s1, s2);
    if (cd == ((iconv_t)-1)) {return;}

    iconv_close(cd);
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    int result;
    
    char s1[] = "";
    char s2[] = "";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';

    iconv_t cd = iconv_open(s1, s2);
    if (cd == ((iconv_t)-1)) {return;}

    errno = 0;
    result = iconv_close(cd);
    //@ assert (result == 0 ==> errno == 0) && (result == -1 ==> errno != 0);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
