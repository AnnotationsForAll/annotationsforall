#include "../../../test_common.h"
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

/*@
assigns \result;
*/
extern locale_t locale();

void runSuccess() {
    isgraph_l('a', locale());
    isgraph_l('Z', locale());
    isgraph_l('5', locale());
    isgraph_l('\r', locale());
    isgraph_l(EOF, locale());
    isgraph_l(anychar(), locale());
}

void runFailure() {
    isgraph_l(invalid(), locale());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = isgraph_l('a', locale());
    //@ assert result != 0;
    result = isgraph_l('5', locale());
    //@ assert result != 0;
    result = isgraph_l('Z', locale());
    //@ assert result != 0;
    result = isgraph_l(' ', locale());
    //@ assert result == 0;
    result = isgraph_l('\t', locale());
    //@ assert result == 0;
    result = isgraph_l('#', locale());
    //@ assert result != 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


