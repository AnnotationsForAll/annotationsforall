#include "../../../test_common.h"
#include <iconv.h>

void runSuccess() {
    char s1[] = "";
    char s2[] = "";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';

    iconv_t cd = iconv_open(s1, s2);
    if (cd == ((iconv_t)-1)) {return;}

    char buf[10];
    size_t size = 10;
    iconv(cd, NULL, NULL, &buf, &size);
}

void runSuccess1() {
    char s1[] = "";
    char s2[] = "";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';

    iconv_t cd = iconv_open(s1, s2);
    if (cd == ((iconv_t)-1)) {return;}

    char buf[10];
    size_t size = 10;
    size_t size2 = 1;
    iconv(cd, NULL, &size2, &buf, &size);
}

void runSuccess2() {
    char s1[] = "";
    char s2[] = "";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';

    iconv_t cd = iconv_open(s1, s2);
    if (cd == ((iconv_t)-1)) {return;}

    char buf[10];
    char buf2[5];
    size_t size = 10;
    size_t size2 = 5;
    iconv(cd, &buf2, &size2, &buf, &size);
}

void runSuccess3() {
    char s1[] = "";
    char s2[] = "";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';

    iconv_t cd = iconv_open(s1, s2);
    if (cd == ((iconv_t)-1)) {return;}

    char buf2[5];
    size_t size2 = 5;
    iconv(cd, &buf2, &size2, NULL, NULL);
}

void runSuccess4() {
    char s1[] = "";
    char s2[] = "";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';

    iconv_t cd = iconv_open(s1, s2);
    if (cd == ((iconv_t)-1)) {return;}

    char buf2[5];
    size_t size2 = 5;
    iconv(cd, NULL, NULL, NULL, NULL);
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

    char buf[10];
    size_t size = 10;
    iconv(cd, NULL, NULL, &buf, &size);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
