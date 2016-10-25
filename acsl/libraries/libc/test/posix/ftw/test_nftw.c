#include "../../../test_common.h"
#include <ftw.h>

static int nftw_helper(const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf) {
    return 0; // nftw continue
}

void runSuccess() {
    char path[] = "/";
    nftw(path, nftw_helper, 20, 0);
}

void runFailure() {
    nftw(NULL, NULL, 0, 0);
}

int f;
void testValues() {
    f = 2;
    int result;

    char path[] = "/";
    result = nftw(path, nftw_helper, 20, 0);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}


