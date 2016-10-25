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
    isblank(' ');
    isblank('\t');
    isblank('q');
    isblank(EOF);
    isblank(anychar());
}

void runFailure() {
    isblank(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = isblank(' ');
    //@ assert result != 0;
    result = isblank('\t');
    //@ assert result != 0;
    result = isblank('1');
    //@ assert result == 0;
    result = isblank('j');
    //@ assert result == 0;
    result = isblank('\n');
    //@ assert result == 0;
    result = isblank('\0');
    //@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


