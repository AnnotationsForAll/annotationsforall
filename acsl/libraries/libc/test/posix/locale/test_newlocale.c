#include "../../../test_common.h"
#include <locale.h>

/*@
assigns \result;
*/
extern locale_t locale();

void runSuccess() {
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    newlocale(anyint(), buf, locale());
}

void runFailure() {
    newlocale(anyint(), NULL, locale());
}

int f;
void testValues() {
    f = 2;
    locale_t result;
    char buf[] = "Hello";
    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';
    
    result = newlocale(anyint(), buf, locale());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
