#include "../../../test_common.h"
#include <stropts.h>

void runSuccess() {
    int flags = anyint();

    getmsg(anyint(), NULL, NULL, &flags);
}

void runSuccess1() {
    char buf[] = "s";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    struct strbuf ctlbuf;
    ctlbuf.buf = buf;
    ctlbuf.maxlen = 2;

    int flags = anyint();

    getmsg(anyint(), &ctlbuf, NULL, &flags);
}

void runSuccess2() {
    char buf[] = "s";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    struct strbuf databuf;
    databuf.buf = buf;
    databuf.maxlen = 2;

    int flags = anyint();

    getmsg(anyint(), NULL, &databuf, &flags);
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
    databuf.maxlen = 2;

    struct strbuf ctlbuf;
    ctlbuf.buf = buf2;
    ctlbuf.maxlen = 2;

    int flags = anyint();

    getmsg(anyint(), &ctlbuf, &databuf, &flags);
}

void runFailure() {
    getmsg(anyint(), NULL, NULL, NULL);
}

void runFailure1() {
    char buf[] = "s";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    struct strbuf ctlbuf;
    ctlbuf.buf = buf;
    ctlbuf.maxlen = 9001;

    int flags = anyint();

    getmsg(anyint(), &ctlbuf, NULL, &flags);
}

void runFailure2() {
    char buf[] = "s";

    //@ assert \valid(buf+(0..\block_length(buf)-1));
    //@ assert \exists integer x; buf[x] == '\0';

    struct strbuf databuf;
    databuf.buf = buf;
    databuf.maxlen = 9001;

    int flags = anyint();

    getmsg(anyint(), NULL, &databuf, &flags);
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
    databuf.maxlen = 2;

    struct strbuf ctlbuf;
    ctlbuf.buf = buf2;
    ctlbuf.maxlen = 2;

    int flags = anyint();

    getmsg(anyint(), &ctlbuf, &databuf, &flags);

    //@ assert -1 <= ctlbuf.len <= ctlbuf.maxlen;
    //@ assert -1 <= databuf.len <= databuf.maxlen;

    //@ assert f == 2;
    //@ assert vacuous: \false;
}
