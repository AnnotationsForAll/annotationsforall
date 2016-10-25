#include "../../../test_common.h"
#include <dlfcn.h>

void runSuccess() {
    Dl_info info;
    struct link_map * data;
    dladdr1(anystring(), &info, &data, RTLD_DL_LINKMAP);
}

void runSuccess1() {
    Dl_info info;
    ElfW(Sym) * data;
    dladdr1(anystring(), &info, &data, RTLD_DL_SYMENT);
}

void runFailure() {
    Dl_info info;
    ElfW(Sym) * data;
    dladdr1(anystring(), NULL, &data, RTLD_DL_SYMENT);
}

void runFailure1() {
    Dl_info info;
    struct link_map * data;
    dladdr1(anystring(), &info, NULL, RTLD_DL_LINKMAP);
}

int f;
void testValues() {
    f = 2;
    
    Dl_info info;
    struct link_map * data;
    int result = dladdr1(anystring(), &info, &data, RTLD_DL_LINKMAP);
    //@ assert result != 0 ==> \valid(data);

    Dl_info info2;
    ElfW(Sym) * data2;
    int result2 = dladdr1(anystring(), &info2, &data2, RTLD_DL_SYMENT);
    //@ assert result2 != 0 ==> \valid(data2);

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
