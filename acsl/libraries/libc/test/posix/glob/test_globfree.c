#include "../../../test_common.h"
#include <glob.h>

void runSuccess() {
    glob_t p;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    if (!glob(buf, anyint(), NULL, &p)) {return;}

    globfree(&p);
}

void runFailure() {
    globfree(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    glob_t p;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    if (!glob(buf, anyint(), NULL, &p)) {return;}

    globfree(&p);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
