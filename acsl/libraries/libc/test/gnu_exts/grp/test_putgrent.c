#include "../../../stdio_common.h"
#include <grp.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct group p;
        p.gr_name = "name";
        p.gr_passwd = "pass";
        p.gr_mem = NULL;
        putgrent(&p, file);
    }
}

void runFailure() {
    struct group p;
    p.gr_name = "name";
    p.gr_passwd = "pass";
    p.gr_mem = NULL;
    putgrent(&p, NULL);
}

void runFailure1() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct group p;
        p.gr_name = "name";
        p.gr_passwd = "pass";
        p.gr_mem = NULL;
        putgrent(NULL, file);
    }
}

int f;
void testValues() {
    f = 2;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        struct group p;
        p.gr_name = "name";
        p.gr_passwd = "pass";
        p.gr_mem = NULL;
        putgrent(&p, file);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
