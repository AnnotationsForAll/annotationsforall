#include "../../../test_common.h"
#include <arpa/inet.h>
#include <stdint.h>

/*@
assigns \result;
*/
extern struct in_addr anyaddr();

void runSuccess() {
    inet_ntoa(anyaddr());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    char* result;
    
    result = inet_ntoa(anyaddr());
    //@ assert \valid(result);
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
