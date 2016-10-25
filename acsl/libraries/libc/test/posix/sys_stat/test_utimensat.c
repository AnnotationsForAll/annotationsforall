#include "../../../test_common.h"
#include <sys/stat.h>

/*@
assigns \result;
ensures \valid(\result+(0..1));
*/
extern const struct timespec * anyspec();

/*@
assigns \result;
ensures \valid(\result+(0..0));
*/
extern const struct timespec * shortspec();

void runSuccess() {
    char buf[] = "f";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    utimensat(anyint(), buf, anyspec(), anyint());
}

void runFailure() {
    char buf[] = "f";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    utimensat(anyint(), NULL, NULL, anyint());
}

void runFailure1() {
    char buf[] = "f";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    utimensat(anyint(), buf, shortspec(), anyint());
}

int f;
void testValues() {
    f = 2;
    int result;
    char buf[] = "f";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = utimensat(anyint(), buf, anyspec(), anyint());
    //@ assert result == 0 || result == -1;
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
