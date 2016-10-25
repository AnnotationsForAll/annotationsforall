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
    isgraph('a');
    isgraph('Z');
    isgraph('5');
    isgraph('\r');
    isgraph(EOF);
    isgraph(anychar());
}

void runFailure() {
    isgraph(invalid());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = isgraph('a');
    //@ assert result != 0;
    result = isgraph('5');
    //@ assert result != 0;
    result = isgraph('Z');
    //@ assert result != 0;
    result = isgraph(' ');
    //@ assert result == 0;
    result = isgraph('\t');
    //@ assert result == 0;
    result = isgraph('#');
    //@ assert result != 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


