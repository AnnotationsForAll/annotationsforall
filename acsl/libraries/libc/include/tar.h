/*
 * tar.h
 *
 *  Created on: Jul 16, 2015
 *      Author: jrobbins
 */

#ifndef LIBC_TAR_H_
#define LIBC_TAR_H_

#define TMAGIC "ustar"  
#define TMAGLEN 6   
#define TVERSION "00"   
#define TVERSLEN 2  
#define REGTYPE '0' 
#define AREGTYPE '\0'   
#define LNKTYPE '1' 
#define SYMTYPE '2' 
#define CHRTYPE '3' 
#define BLKTYPE '4' 
#define DIRTYPE '5' 
#define FIFOTYPE '6'    
#define CONTTYPE '7'    
#define TSUID 04000  
#define TSGID 02000  
#define TSVTX 01000 
#define TUREAD 0400  
#define TUWRITE 0200 
#define TUEXEC 0100  
#define TGREAD 040   
#define TGWRITE 020  
#define TGEXEC 010   
#define TOREAD 04    
#define TOWRITE 02   
#define TOEXEC 01    


#endif /* LIBC_TAR_H_ */
