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
    islower('a');
    islower('j');
    islower('z');
    islower('Z');
    islower('1');
    islower('#');
    islower(EOF);
    islower(anychar());
}

void runFailure() {
    islower(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = islower('z');
    //@ assert result != 0;
    result = islower('a');
    //@ assert result != 0;
    result = islower('h');
    //@ assert result != 0;
    result = islower(' ');
    //@ assert result == 0;
    result = islower('A');
    //@ assert result == 0;
    result = islower('Z');
    //@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


