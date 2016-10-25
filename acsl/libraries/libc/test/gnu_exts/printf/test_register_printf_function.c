#include "../../../test_common.h"
#include <printf.h>

/*@
assigns \result;
*/
extern char anychar();
/*@
assigns \result;
ensures (char)\result != \result;
*/
extern int invalid();

int my_handler(FILE *stream, const struct printf_info *info, const void * const *args) {
    return anyint();
}

int my_arginfo(const struct printf_info *info, size_t n, int *argtypes) {
    return anyint();
}

void runSuccess() {
    register_printf_function(anychar(), my_handler, my_arginfo);
}

void runFailure() {
    register_printf_function(invalid(), my_handler, my_arginfo);
}

void runFailure1() {
    register_printf_function(anychar(), NULL, my_arginfo);
}

void runFailure2() {
    register_printf_function(anychar(),  my_handler, NULL);
}

int f;
void testValues() {
    f = 2;
    
    register_printf_function(anychar(), my_handler, my_arginfo);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
