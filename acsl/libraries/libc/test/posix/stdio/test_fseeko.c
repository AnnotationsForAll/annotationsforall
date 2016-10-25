#include "../../../stdio_common.h"

/*@
assigns \result;
*/
extern off_t anyoff();

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        fseeko(file, anyoff(), SEEK_SET);
    }
}

void runFailure() {
    fseeko(NULL, anyoff(), SEEK_CUR);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = fseeko(file, anyoff(), SEEK_SET);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
