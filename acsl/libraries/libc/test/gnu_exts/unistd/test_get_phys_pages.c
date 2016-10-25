#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    get_phys_pages();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    long int result = get_phys_pages();
    //@ assert result >= 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
