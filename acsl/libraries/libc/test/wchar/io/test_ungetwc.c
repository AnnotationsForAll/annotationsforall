#include "../../../stdio_common.h"
#include <wchar.h>

/*@
assigns \result;
*/
extern wint_t anywint();

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        ungetwc(L'a', file);
    }
}

void runSuccess1() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        ungetwc(anywint(), file);
    }
}

void runFailure() {
    ungetwc(anywint(), NULL);
}

int f;
void testValues() {
    f = 2;
    wint_t result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = ungetwc(L'a', file);
        result = ungetwc(L'a', file);
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

/* Too difficult - see ungetc
void testValues2() {
    f = 2;
    int result;

    // 7.24.3.10
    // One wide character of pushback is guaranteed
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = ungetwc('a', file);
        //@ assert result == 'a';
        wgetc(file);
        result = ungetwc('a', file);
        //@ assert result == 'a';
    }


    //@ assert f == 2;
    //@ assert vacuous: \false;
}
*/

/* Frama-c specific implementation
void testValues3() {
    f = 2;
    int result;

    // 7.24.3.10
    // A successful call to the ungetwc function clears the end-of-file indicator for the stream
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = ungetwc('a', file);
        //@ assert (result == 'a') ==> (file->__fc_eof == 0);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}

void testValues4() {
    f = 2;
    wint_t result;

    // 7.24.3.10
    /* The value of the file position indicator for the stream after reading or discarding all
     * pushed-back wide characters is the same as it was before the wide characters were pushed
     * back.
     * NOTE: position indicator is undefined until all pushed-back characters are read/discarded
     * /
    FILE* file = VALID_FILE;
    if (file != NULL) {
        //@ ghost fpos_t pos = file->__fc_position;
        result = ungetwc('a', file);
        getcw(file);
        //@ assert (result == 'a') ==> (file->__fc_position == pos);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
*/

