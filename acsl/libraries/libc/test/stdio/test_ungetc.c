#include "../../stdio_common.h"
#include <stdio.h>

void runSuccess() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        ungetc('a', file);
    }
}

void runSuccess1() {
    FILE* file = VALID_FILE;
    if (file != NULL) {
        ungetc(anyint(), file);
    }
}

void runFailure() {
    ungetc(anyint(), NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = ungetc('a', file);
        result = ungetc('a', file);
        //@ assert result == EOF || result == 'a';
    }
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}

/* Too difficult
void testValues2() {
    f = 2;
    int result;

    // 7.19.7.11
    // One character of pushback is guaranteed
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = ungetc('a', file);
        //@ assert result == 'a';
        getc(file);
        result = ungetc('a', file);
        //@ assert result == 'a';
    }


    //@ assert f == 2;
    //@ assert vacuous: \false;
}
*/

void testValues3() {
    f = 2;
    int result;

    // 7.19.7.11
    // A successful call to the ungetc function clears the end-of-file indicator for the stream
    FILE* file = VALID_FILE;
    if (file != NULL) {
        result = ungetc('a', file);
        int is_eof = feof(file);
        //@ assert (result == 'a') ==> (is_eof == 0);
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}

// Too difficult
//void testValues4() {
//    f = 2;
//    int result;
//
//    // 7.19.7.11
//    /* The value of the file position indicator for the stream after reading or discarding all
//     * pushed-back characters shall be the same as it was before the characters were pushed
//     * back
//     * NOTE: position indicator is undefined until all pushed-back characters are read/discarded
//     */
//    FILE* file = VALID_FILE;
//    if (file != NULL) {
//        fpos_t pos1;
//        if (!fgetpos(file, &pos1)) {
//            result = ungetc('a', file);
//            getc(file);
//            fpos_t pos2;
//            if (!fgetpos(file, &pos2)) {
//                //@ assert pos1 == pos2;
//            }
//        }
//    }
//
//    //@ assert f == 2;
//    //@ assert vacuous: \false;
//}
