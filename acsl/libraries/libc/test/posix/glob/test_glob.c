#include "../../../test_common.h"
#include <glob.h>

/*@
assigns \result;
ensures \result != \null;
*/
extern int (*anyfunc())(const char*, int);

void runSuccess() {
    glob_t p;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    glob(buf, anyint(), anyfunc(), &p);
}

void runSuccess1() {
    glob_t p;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    glob(buf, anyint(), NULL, &p);
}

void runFailure() {
    glob_t p;
    glob(NULL, anyint(), anyfunc(), &p);
}

void runFailure1() {
    glob_t p;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    glob(buf, anyint(), anyfunc(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    glob_t p;
    char buf[] = "name";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    glob(buf, anyint(), NULL, &p);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
