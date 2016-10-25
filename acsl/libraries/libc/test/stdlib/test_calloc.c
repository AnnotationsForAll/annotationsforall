#include "../../test_common.h"
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>

/*@
predicate clear(char* memory, size_t size) = \forall integer i; 0 <= i < size ==> memory[i] == 0;
*/

void runSuccess() {
    calloc(1,5);
    calloc(10,7);
    calloc(0,1);
    calloc(INT_MAX,0);
    calloc(anysize(),anysize());
}

void runFailure() {
    
}

int f;
void testValues() {
    f = 2;
    char* result;
    size_t x,y;
    
    result = calloc(10,sizeof(char));
    //@ assert result != \null ==> (\valid(result) && clear(result, (size_t)10));
    
    x = anysize();
    y = sizeof(char);
    result = calloc(x,y);
    //@ assert result != \null ==> (\valid(result+(0..x-1)) && clear(result, (size_t)(x*y)));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
