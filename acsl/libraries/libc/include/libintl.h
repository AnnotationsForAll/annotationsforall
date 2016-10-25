/**************************************************************************/
/*                                                                        */
/*  This file is part of Frama-C.                                         */
/*                                                                        */
/*  Copyright (C) 2007-2015                                               */
/*    CEA (Commissariat à l'énergie atomique et aux énergies              */
/*         alternatives)                                                  */
/*                                                                        */
/*  you can redistribute it and/or modify it under the terms of the GNU   */
/*  Lesser General Public License as published by the Free Software       */
/*  Foundation, version 2.1.                                              */
/*                                                                        */
/*  It is distributed in the hope that it will be useful,                 */
/*  but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         */
/*  GNU Lesser General Public License for more details.                   */
/*                                                                        */
/*  See the GNU Lesser General Public License version 2.1                 */
/*  for more details (enclosed in the file licenses/LGPLv2.1).            */
/*                                                                        */
/**************************************************************************/

#ifndef __FC_LIBINTL_H
#define __FC_LIBINTL_H

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

/*@
requires \valid(msgid);
assigns \result \from msgid[0..];
ensures \valid(\result);
*/
char * gettext (const char *msgid);

/*@
requires domainname != \null ==> \valid(domainname);
requires \valid(msgid);
assigns \result \from domainname[0..], msgid[0..];
ensures \valid(\result);
*/
char * dgettext (const char *domainname, const char *msgid);

/*@
requires domainname != \null ==> \valid(domainname);
requires \valid(msgid);
assigns \result \from domainname[0..], msgid[0..], category;
ensures \valid(\result);
*/
char * dcgettext (const char *domainname, const char *msgid, int category);

/*@
requires domainname != \null ==> \valid(domainname);
assigns \result \from domainname[0..];
ensures \result != \null ==> \valid(\result);
*/
char * textdomain (const char *domainname);

/*@
requires \valid(domainname);
requires dirname != \null ==> \valid(dirname);
assigns \result \from dirname[0..], domainname[0..];
ensures \result != \null ==> \valid(\result);
*/
char * bindtextdomain (const char *domainname, const char *dirname);

/*@
requires \valid(msgid);
requires \valid(msgid2);
assigns \result \from msgid[0..], msgid2[0..], n;
ensures \valid(\result);
*/
char * ngettext (const char *msgid, const char *msgid2, unsigned long int n);

/*@
requires domainname != \null ==> \valid(domainname);
requires \valid(msgid);
requires \valid(msgid2);
assigns \result \from domainname[0..], msgid[0..], msgid2[0..], n;
ensures \valid(\result);
*/
char * dngettext (const char *domainname, const char *msgid, const char *msgid2, unsigned long int n);

/*@
requires domainname != \null ==> \valid(domainname);
requires \valid(msgid);
requires \valid(msgid2);
assigns \result \from domainname[0..], msgid[0..], msgid2[0..], n, category;
ensures \valid(\result);
*/
char * dcngettext (const char *domainname, const char *msgid, const char *msgid2, unsigned long int n, int category);

/*@
requires \valid(domainname);
requires codeset != \null ==> \valid(codeset);
assigns \result \from codeset[0..], domainname[0..];
ensures \result != \null ==> \valid(\result);
*/
char * bind_textdomain_codeset (const char *domainname, const char *codeset);

#endif
