#include "../../../unistd_common.h"
#include <unistd.h>

void runSuccess() {
    get_avphys_pages();
}

void runFailure() {

}

int f;
void testValues() {
    f = 2;
    
    long int result = get_avphys_pages();
    //@ assert result >= 0;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
