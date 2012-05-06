
#ifndef __TARGET_H 
#define __TARGET_H

/* System configuration: Fosc, Fcclk, Fcco, Fpclk must be defined */
/* Crystal frequence,10MHz~25MHz should be the same as actual status. */
#define Fosc	14745600UL

#define Fcclk	(Fosc * 4)

#define Fcco	(Fcclk * 4)

/* VPB clock frequence , must be 1/2/4 multiples of (Fcclk / 4). */
#define Fpclk	(Fcclk / 1)


#define PLLCFG_VAL 0x00000023
#define APBDIV_VAL 0x00000001


#endif /* end __TARGET_H */
/******************************************************************************
**                            End Of File
******************************************************************************/
