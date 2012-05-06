
#ifndef __TARGET_H 
#define __TARGET_H



#define Fosc	14745600UL

#define Fcclk	(Fosc * 4)

#define Fcco	(Fcclk * 4)

#define PLLCFG_VAL 0x00000023




#define Fpclk	(Fcclk >> 0)

#define APBDIV_VAL 0x00000001


#endif /* end __TARGET_H */
/******************************************************************************
**                            End Of File
******************************************************************************/
