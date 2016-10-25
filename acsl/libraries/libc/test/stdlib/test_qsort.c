#include "../../test_common.h"
#include <stdlib.h>

/*@
ensures \result != \null;
*/
extern int(*anyfunc())(const void*, const void*);

void runSuccess() {
    char buf[] = "ABC";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    qsort(buf,3,sizeof(char),anyfunc());
}

void runFailure() {
    qsort(NULL,3,sizeof(char),anyfunc());
}

void runFailure1() {
    char buf[] = "ABC";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    qsort(buf,3,sizeof(char),NULL);
}

int f;
void testValues() {
    f = 2;
    char buf[] = "ABC";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    
    qsort(buf,3,sizeof(char),anyfunc());
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

