/*
 * libgen.h
 *
 *  Created on: Jul 15, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_LIBGEN_H_
#define LIBC_LIBGEN_H_

/*@
requires path != \null ==> \valid(path);
assigns \result \from path[..];
ensures \valid(\result);
*/
char *basename(char *path);

/*@
requires path != \null ==> \valid(path);
assigns \result \from path[..];
ensures \valid(\result);
*/
char *dirname(char *path);

#endif /* LIBC_LIBGEN_H_ */
