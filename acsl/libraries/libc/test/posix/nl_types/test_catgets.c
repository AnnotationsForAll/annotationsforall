#include "../../../test_common.h"
#include <nl_types.h>
#include <fcntl.h>

/*@
assigns \result;
ensures \valid((char*)\result);
*/
extern nl_catd anycatd();

void runSuccess() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    nl_catd catd = catopen(buf, FD_CLOEXEC);
    if (catd == (nl_catd)-1) {return;}
    
    catgets(catd, anyint(), anyint(), buf);
}

void runSuccess1() {
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    nl_catd catd = catopen(buf, FD_CLOEXEC);
    if (catd == (nl_catd)-1) {return;}

    catgets(catd, anyint(), anyint(), NULL);
}

void runFailure() {
    catgets(NULL, anyint(), anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    char* result;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    nl_catd catd = catopen(buf, FD_CLOEXEC);
    if (catd == (nl_catd)-1) {return;}
    
    result = catgets(catd, anyint(), anyint(), buf);
    //@ assert result == buf || \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
