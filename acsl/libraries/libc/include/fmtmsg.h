/*
 * fmtmsg.h
 *
 *  Created on: Jul 15, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_FMTMSG_H_
#define LIBC_FMTMSG_H_

#define MM_NULLMC 1
#define MM_SOFT 2
#define MM_HARD 4
#define MM_FIRM 8
#define MM_APPL 16
#define MM_UTIL 32
#define MM_OPSYS 64
#define MM_PRINT 128
#define MM_CONSOLE 256
#define MM_RECOVER 512
#define MM_NRECOV 1024

#define MM_HALT 1
#define MM_ERROR 2
#define MM_WARNING 4
#define MM_INFO 8
#define MM_NOSEV 16

#define MM_OK 1
#define MM_NOTOK 2
#define MM_NOMSG 4
#define MM_NOCON 8

#define MM_NULLLBL ((char*)0)
#define MM_NULLSEV (0)
#define MM_NULLMC (0L)
#define MM_NULLTXT ((char*)0)
#define MM_NULLACT ((char*)0)
#define MM_NULLTAG ((char*)0)

/*@
requires label != \null ==> \valid(label);
requires label != \null ==> \valid(text);
requires label != \null ==> \valid(action);
requires label != \null ==> \valid(tag);
assigns \result \from classification, label[..], severity, text[..], action[..], tag[..];
ensures \result == MM_OK || \result == MM_NOTOK || \result == MM_NOMSG || \result == MM_NOCON;
*/
int fmtmsg(long classification, const char *label, int severity, const char *text, const char *action, const char *tag);

/* SVID Extensions */

/*@
requires string != \null ==> \valid(string);
assigns \result \from severity, string[0..];
ensures \result == MM_OK || \result == MM_NOTOK;
*/
int addseverity (int severity, const char *string);

#endif /* LIBC_FMTMSG_H_ */
