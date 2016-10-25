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
    isblank_l(' ', locale());
    isblank_l('\t', locale());
    isblank_l('q', locale());
    isblank_l(EOF, locale());
    isblank_l(anychar(), locale());
}

void runFailure() {
    isblank_l(invalid(), locale());
}

int f;
void testValues() {
    f = 2;
    int result;
    
    result = isblank_l(' ', locale());
    //@ assert result != 0;
    result = isblank_l('\t', locale());
    //@ assert result != 0;
    result = isblank_l('1', locale());
    //@ assert result == 0;
    result = isblank_l('j', locale());
    //@ assert result == 0;
    result = isblank_l('\n', locale());
    //@ assert result == 0;
    result = isblank_l('\0', locale());
    //@ assert result == 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


