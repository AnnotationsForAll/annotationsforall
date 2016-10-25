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
    toupper('a');
    toupper('5');
    toupper('$');
    toupper('\0');
    toupper(EOF);
    toupper(anychar());
}

void runFailure() {
    toupper(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = toupper('Z');
    //@ assert result == 'Z';
    result = toupper('A');
    //@ assert result == 'A';
    result = toupper('%');
    //@ assert result == '%';
    result = toupper('\0');
    //@ assert result == '\0';
    result = toupper('a');
    //@ assert result == 'A';
    result = toupper('z');
    //@ assert result == 'Z';
    result = toupper('G');
    //@ assert result == 'G';

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


