/*
 * paths.h
 *
 *  Created on: Jul 20, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_PATHS_H_
#define LIBC_PATHS_H_

// This header is a BSD extension. Do not use for strictly POSIX-compliant work.

#define _PATH_DEFPATH "/usr/bin:/bin"
#define _PATH_STDPATH "/usr/bin:/bin:/usr/sbin:/sbin"

#define _PATH_BSHELL   "/bin/sh"
#define _PATH_CONSOLE  "/dev/console"
#define _PATH_CSHELL   "/bin/csh"
#define _PATH_DEVDB    "/var/run/dev.db"
#define _PATH_DEVNULL  "/dev/null"
#define _PATH_DRUM     "/dev/drum"
#define _PATH_FSTAB    "/etc/fstab"
#define _PATH_GSHADOW  "/etc/gshadow"
#define _PATH_KLOG     "/proc/kmsg"
#define _PATH_KMEM     "/dev/kmem"
#define _PATH_LASTLOG  "/var/log/lastlog"
#define _PATH_MAILDIR  "/var/mail"
#define _PATH_MAN      "/usr/share/man"
#define _PATH_MEM      "/dev/mem"
#define _PATH_MNTTAB   "/etc/fstab"
#define _PATH_MOUNTED  "/etc/mtab"
#define _PATH_NOLOGIN  "/etc/nologin"
#define _PATH_PRESERVE "/var/lib"
#define _PATH_RWHODIR  "/var/spool/rwho"
#define _PATH_SENDMAIL "/usr/sbin/sendmail"
#define _PATH_SHADOW   "/etc/shadow"
#define _PATH_SHELLS   "/etc/shells"
#define _PATH_TTY      "/dev/tty"
#define _PATH_UNIX     "/boot/vmlinux"
#define _PATH_UTMP     "/var/run/utmp"
#define _PATH_VI       "/usr/bin/vi"
#define _PATH_WTMP     "/var/log/wtmp"

#define _PATH_UTMPX _PATH_UTMP
#define _PATH_WTMPX _PATH_WTMP

#define _PATH_DEV    "/dev/"
#define _PATH_TMP    "/tmp/"
#define _PATH_VARDB  "/var/lib/misc/"
#define _PATH_VARRUN "/var/run/"
#define _PATH_VARTMP "/var/tmp/"

#endif /* LIBC_PATHS_H_ */
