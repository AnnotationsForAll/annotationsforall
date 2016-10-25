#include "../../../stdio_common.h"

/*@
assigns \result;
*/
extern unsigned char anychar();

/*@
assigns \result;
ensures (unsigned char)\result == \result;
*/
extern int invalid();

void runSuccess() {
    size_t len = 4;
    char buf[4];
    char *bufp = buf;
    //@ assert \valid(bufp+(0..(3)));
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        getdelim(&bufp, &len, anychar(), file);
    }
}

void runFailure() {
    size_t len = anysize();
    FILE* file = VALID_FILE;
    if (file != NULL) {
        getdelim(NULL, &len, anychar(), file);
    }
}

void runFailure1() {
    size_t len = anysize();
    char* buf = malloc(len);
    
    if (buf != NULL) {
        FILE* file = VALID_FILE;
        if (file != NULL) {
            getdelim(&buf, NULL, anychar(), file);
        }
    }
}

void runFailure2() {
    size_t len = anysize();
    char* buf = malloc(len);
    
    if (buf != NULL) {
        FILE* file = VALID_FILE;
        if (file != NULL) {
            getdelim(&buf, &len, invalid(), file);
        }
    }
}

void runFailure3() {
    size_t len = anysize();
    char* buf = malloc(len);
    
    if (buf != NULL) {
        getdelim(&buf, &len, anychar(), NULL);
    }
}

int f;
void testValues() {
    f = 2;
    ssize_t result;
    size_t len = anysize();
    char* buf = malloc(len);
    
    if (buf != NULL) {
        FILE* file = VALID_FILE;
        if (file != NULL) {
            result = getdelim(&buf, &len, anychar(), file);
            //@ assert result >= -1;
        }
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
