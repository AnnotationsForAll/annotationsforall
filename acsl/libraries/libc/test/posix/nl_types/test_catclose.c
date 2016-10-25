#include "../../../test_common.h"
#include <nl_types.h>
#include <fcntl.h>
#include <errno.h>

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    nl_catd catd = catopen(buf, FD_CLOEXEC);
    if (catd == (nl_catd)-1) {return;}

    catclose(catd);
}

void runFailure() {
    catclose(NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    nl_catd catd = catopen(buf, FD_CLOEXEC);
    if (catd == (nl_catd)-1) {return;}
    
    errno = 0;
    result = catclose(catd);
    //@ assert result == 0 || result == -1;
    //@ assert result == -1 ==> errno != 0;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
