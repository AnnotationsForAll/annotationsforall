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
    isdigit('1');
    isdigit('9');
    isdigit('0');
    isdigit('q');
    isdigit('*');
    isdigit(EOF);
    isdigit(anychar());
}

void runFailure() {
    isdigit(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    result = isdigit('1');
    //@ assert result != 0;
    result = isdigit('0');
    //@ assert result != 0;
    result = isdigit('9');
    //@ assert result != 0;
    result = isdigit(' ');
    //@ assert result == 0;
    result = isdigit('A');
    //@ assert result == 0;
    result = isdigit('z');
    //@ assert result == 0;
    result = isdigit('\t');
    //@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


