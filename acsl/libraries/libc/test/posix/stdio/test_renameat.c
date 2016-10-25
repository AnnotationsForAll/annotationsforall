#include "../../../unistd_common.h"

void runSuccess() {
    char s1[] = "old";
    char s2[] = "new";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    int fd1 = VALID_FD;
    if (fd1 != -1) {
        int fd2 = VALID_FD;
        if (fd2 != -1) {
            renameat(fd1, s1, fd2, s2);
        }
    }
}

void runFailure() {
    char s2[] = "new";
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    int fd1 = VALID_FD;
    if (fd1 != -1) {
        int fd2 = VALID_FD;
        if (fd2 != -1) {
            renameat(fd1, NULL, fd2, s2);
        }
    }
}

void runFailure1() {
    char s1[] = "old";
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    
    int fd1 = VALID_FD;
    if (fd1 != -1) {
        int fd2 = VALID_FD;
        if (fd2 != -1) {
            renameat(fd1, s1, fd2, NULL);
        }
    }
}

void runFailure2() {
    int fd1 = VALID_FD;
    if (fd1 != -1) {
        int fd2 = VALID_FD;
        if (fd2 != -1) {
            renameat(fd1, NULL, fd2, NULL);
        }
    }
}

int f;
void testValues() {
    f = 2;
    int result;
    
    char s1[] = "old";
    char s2[] = "new";
    
    //@ assert \valid(s1+(0..\block_length(s1)-1));
    //@ assert \exists integer x; s1[x] == '\0';
    //@ assert \valid(s2+(0..\block_length(s2)-1));
    //@ assert \exists integer x; s2[x] == '\0';
    
    int fd1 = VALID_FD;
    if (fd1 != -1) {
        int fd2 = VALID_FD;
        if (fd2 != -1) {
            result = renameat(fd1, s1, fd2, s2);
            //@ assert result == 0 || result == -1;
        }
    }

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
