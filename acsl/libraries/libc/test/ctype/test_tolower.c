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
    tolower('a');
    tolower('5');
    tolower('$');
    tolower('\0');
    tolower(EOF);
    tolower(anychar());
}

void runFailure() {
    tolower(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = tolower('a');
    //@ assert result == 'a';
    result = tolower('z');
    //@ assert result == 'z';
    result = tolower('%');
    //@ assert result == '%';
    result = tolower('\0');
    //@ assert result == '\0';
    result = tolower('Z');
    //@ assert result == 'z';
    result = tolower('A');
    //@ assert result == 'a';
    result = tolower('G');
    //@ assert result == 'g';

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


