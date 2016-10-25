#include "../../../test_common.h"
#include <argp.h>

void runSuccess() {
    argp_parse(NULL, 0, NULL, 0, NULL, NULL);
}

void runSuccess1() {
    char* args[] = {anystring()};
    argp_parse(NULL, 1, args, 0, NULL, NULL);
}

void runSuccess2() {
    char* args[] = {anystring(),anystring()};
    argp_parse(NULL, 2, args, 0, NULL, NULL);
}

void runSuccess3() {
    int arg_index; void* input;
    char* args[] = {anystring(),anystring()};
    argp_parse(NULL, 2, args, 0, &arg_index, &input);
}

void runSuccess4() {
    int arg_index;
    char* args[] = {anystring(),anystring()};
    argp_parse(NULL, 2, args, 0, &arg_index, &arg_index);
}

void runFailure() {
    argp_parse(NULL, 1, NULL, 0, NULL, NULL);
}

void runFailure1() {
    char* args[] = {anystring(),anystring()};
    argp_parse(NULL, 3, NULL, 0, NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    
    char* args[] = {anystring(),anystring()};
    argp_parse(NULL, 2, args, 0, NULL, NULL);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
