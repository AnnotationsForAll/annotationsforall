#include "../../../test_common.h"
#include <dirent.h>

/*@
assigns \result;
ensures \result != \null;
*/
extern int (*anysel())(const struct dirent *);

/*@
assigns \result;
ensures \result != \null;
*/
extern int (*anysort())(const struct dirent **, const struct dirent **);

void runSuccess() {
    struct dirent ** names;
    char dir[] = ".";
    //@ assert \valid(dir+(0..\block_length(dir)-1));
    //@ assert \exists integer x; dir[x] == '\0';
    
    scandir(dir, &names, NULL, alphasort);
}

void runSuccess1() {
    struct dirent ** names;
    char dir[] = ".";
    //@ assert \valid(dir+(0..\block_length(dir)-1));
    //@ assert \exists integer x; dir[x] == '\0';
    
    scandir(dir, &names, anysel(), anysort());
}

void runFailure() {
    struct dirent ** names;
    
    scandir(NULL, &names, NULL, alphasort);
}

void runFailure1() {
    char dir[] = ".";
    //@ assert \valid(dir+(0..\block_length(dir)-1));
    //@ assert \exists integer x; dir[x] == '\0';
    
    scandir(dir, NULL, NULL, alphasort);
}

void runFailure2() {
    struct dirent ** names;
    char dir[] = ".";
    //@ assert \valid(dir+(0..\block_length(dir)-1));
    //@ assert \exists integer x; dir[x] == '\0';
    
    scandir(dir, &names, NULL, NULL);
}

int f;
void testValues() {
    f = 2;
    int result;
    
    struct dirent ** names;
    char dir[] = ".";
    //@ assert \valid(dir+(0..\block_length(dir)-1));
    //@ assert \exists integer x; dir[x] == '\0';
    
    result = scandir(dir, &names, NULL, alphasort);
    //@ assert result != -1 ==> \valid(names+(0..result-1));
    
    //@ assert f == 2;
    //@ assert vacuous: \false;
}
