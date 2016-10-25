#include "../../test_common.h"
#include <ctype.h>
#include <stdio.h>


/*@
assigns \result;
*/
extern unsigned char anychar();
/*@
assigns \result;
ensures (unsigned char)\result != \result && \result != EOF;
*/
extern int invalid();

void runSuccess() {
    isspace('a');
    isspace('\t');
    isspace(EOF);
    isspace(anychar());
}

void runFailure() {
    isspace(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = isspace('z');
    //@ assert result == 0;
    result = isspace(' ');
    //@ assert result != 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


