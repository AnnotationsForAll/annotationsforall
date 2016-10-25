#include "../../test_common.h"
#include <stdlib.h>

/*@
ensures \result != \null;
*/
extern int(*anyfunc())(const void*, const void*);

void runSuccess() {
    char buf[] = "ABC";
    char key = 'A';
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    bsearch(&key,buf,3,sizeof(char),anyfunc());
}

void runFailure() {
    char buf[] = "ABC";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    bsearch(NULL,buf,3,sizeof(char),anyfunc());
}

void runFailure1() {
    char key = 'A';
    bsearch(&key,NULL,3,sizeof(char),anyfunc());
}

void runFailure2() {
    char buf[] = "ABC";
    char key = 'A';
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    bsearch(&key,buf,3,sizeof(char),NULL);
}

int f;
void testValues() {
    f = 2;
    void* result;
    char buf[] = "ABC";
    char key = 'A';
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    
    result = bsearch(&key,buf,3,sizeof(char),anyfunc());
    //@ assert result != \null ==> (void*)buf <= result <= (void*)buf+2;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

