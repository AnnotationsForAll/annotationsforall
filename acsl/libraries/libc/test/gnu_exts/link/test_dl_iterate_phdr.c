#include "../../../test_common.h"
#include <link.h>

/*@
assigns \result;
*/
int anycallback(struct dl_phdr_info *info, size_t size, void *data);

void runSuccess() {
    dl_iterate_phdr(anycallback, anystring());
}

void runFailure() {
    dl_iterate_phdr(NULL, anystring());
}

int f;
void testValues() {
    f = 2;
    
    dl_iterate_phdr(anycallback, anystring());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
