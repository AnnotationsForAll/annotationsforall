/*
 * io.h
 *
 *  Created on: Jul 15, 2016
 *      Author: jrobbins
 */

#ifndef LIBC_SYS_IO_H_
#define LIBC_SYS_IO_H_

// This header is a GNU extension. Do not use for strictly POSIX-compliant work.

#include "../errno.h"

/*
TODO: Some of this might be public, kernel-independent interface, and some might be kernel-dependent.
The kernel-dependent bits need to be enumerated, sorted out, and made machdep-specific.
*/

// If a user tries to use a port they have not allowed access on, this will cause a crash.
// Therefore, IO permissions have to be required by annotations.

//@ ghost int __gt_fc_sys_io_port_open[65536];

/*@
requires __gt_fc_sys_io_port_open[port];
assigns \result;
*/
unsigned char inb(unsigned short int port);

/*@
requires __gt_fc_sys_io_port_open[port];
assigns \result;
*/
unsigned char inb_p(unsigned short int port);

/*@
requires __gt_fc_sys_io_port_open[port];
assigns \result;
*/
unsigned short int inw(unsigned short int port);

/*@
requires __gt_fc_sys_io_port_open[port];
assigns \result;
*/
unsigned short int inw_p(unsigned short int port);

/*@
requires __gt_fc_sys_io_port_open[port];
assigns \result;
*/
unsigned int inl(unsigned short int port);

/*@
requires __gt_fc_sys_io_port_open[port];
assigns \result;
*/
unsigned int inl_p(unsigned short int port);

/*@
requires __gt_fc_sys_io_port_open[port];
assigns \nothing;
*/
void outb(unsigned char value, unsigned short int port);

/*@
requires __gt_fc_sys_io_port_open[port];
assigns \nothing;
*/
void outb_p(unsigned char value, unsigned short int port);

/*@
requires __gt_fc_sys_io_port_open[port];
assigns \nothing;
*/
void outw(unsigned short int value, unsigned short int port);

/*@
requires __gt_fc_sys_io_port_open[port];
assigns \nothing;
*/
void outw_p(unsigned short int value, unsigned short int port);

/*@
requires __gt_fc_sys_io_port_open[port];
assigns \nothing;
*/
void outl(unsigned int value, unsigned short int port);

/*@
requires __gt_fc_sys_io_port_open[port];
assigns \nothing;
*/
void outl_p(unsigned int value, unsigned short int port);

/*@
requires \valid(((unsigned char*)addr)+(0..count-1));
requires __gt_fc_sys_io_port_open[port];
assigns ((unsigned char*)addr)[0..count-1];
*/
void insb(unsigned short int port, void *addr, unsigned long int count);

/*@
requires \valid(((unsigned short*)addr)+(0..count-1));
requires __gt_fc_sys_io_port_open[port];
assigns ((unsigned short*)addr)[0..count-1];
*/
void insw(unsigned short int port, void *addr, unsigned long int count);

/*@
requires \valid(((unsigned int*)addr)+(0..count-1));
requires __gt_fc_sys_io_port_open[port];
assigns ((unsigned int*)addr)[0..count-1];
*/
void insl(unsigned short int port, void *addr, unsigned long int count);

/*@
requires \valid_read(((unsigned char*)addr)+(0..count-1));
requires __gt_fc_sys_io_port_open[port];
assigns \nothing;
*/
void outsb(unsigned short int port, const void *addr, unsigned long int count);

/*@
requires \valid_read(((unsigned short*)addr)+(0..count-1));
requires __gt_fc_sys_io_port_open[port];
assigns \nothing;
*/
void outsw(unsigned short int port, const void *addr, unsigned long int count);

/*@
requires \valid_read(((unsigned int*)addr)+(0..count-1));
requires __gt_fc_sys_io_port_open[port];
assigns \nothing;
*/
void outsl(unsigned short int port, const void *addr, unsigned long int count);

/*@
assigns \result, errno, __gt_fc_sys_io_port_open[from..from+num-1];
ensures \result != -1 ==> \forall unsigned long i; from <= i < num ==> __gt_fc_sys_io_port_open[i] == turn_on;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int ioperm(unsigned long from, unsigned long num, int turn_on);

/*@
//FIXME: What do the privilege levels do?
assigns \result, errno, __gt_fc_sys_io_port_open[0..65535];
ensures \result != -1 ==> \forall unsigned long i; __gt_fc_sys_io_port_open[i] != 0;
ensures \result == -1 || \result == 0;
ensures \result == -1 ? errno != 0 : errno == \old(errno);
*/
int iopl(int level);

#endif /* LIBC_SYS_IO_H_ */
