#include "../../../test_common.h"
#include <stropts.h>

void runSuccess() {
    putmsg(anyint(), NULL, NULL, anyint());
}

void runSuccess1() {
    char buf[] = "s";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    struct strbuf ctlbuf;
    ctlbuf.buf = buf;
    ctlbuf.len = 2;

    putmsg(anyint(), &ctlbuf, NULL, anyint());
}

void runSuccess2() {
    char buf[] = "s";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    struct strbuf databuf;
    databuf.buf = buf;
    databuf.len = 2;

    putmsg(anyint(), NULL, &databuf, anyint());
}

void runSuccess3() {
    char buf1[] = "1";

    //@ assert \valid(buf1+(0..\block_length(buf1)-1));
    //@ assert \exists integer x; buf1[x] == '\0';

    char buf2[] = "2";

    //@ assert \valid(buf2+(0..\block_length(buf2)-1));
    //@ assert \exists integer x; buf2[x] == '\0';

    struct strbuf databuf;
    databuf.buf = buf1;
    databuf.len = 2;

    struct strbuf ctlbuf;
    ctlbuf.buf = buf2;
    ctlbuf.len = 2;

    putmsg(anyint(), &ctlbuf, &databuf, anyint());
}

void runFailure() {
    char buf[] = "s";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    struct strbuf ctlbuf;
    ctlbuf.buf = buf;
    ctlbuf.len = 9001;

    putmsg(anyint(), &ctlbuf, NULL, anyint());
}

void runFailure1() {
    char buf[] = "s";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    struct strbuf databuf;
    databuf.buf = buf;
    databuf.len = 9001;

    putmsg(anyint(), NULL, &databuf, anyint());
}

int f;
void testValues() {
    f = 2;

    char buf1[] = "1";

    //@ assert \valid(buf1+(0..\block_length(buf1)-1));
    //@ assert \exists integer x; buf1[x] == '\0';

    char buf2[] = "2";

    //@ assert \valid(buf2+(0..\block_length(buf2)-1));
    //@ assert \exists integer x; buf2[x] == '\0';

    struct strbuf databuf;
    databuf.buf = buf1;
    databuf.len = 2;

    struct strbuf ctlbuf;
    ctlbuf.buf = buf2;
    ctlbuf.len = 2;

    putmsg(anyint(), &ctlbuf, &databuf, anyint());

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
