/*-------------------------------------*/
/* systbl.c                            */
/* Last change : 21. 3.95              */
/*-------------------------------------*/
#include "prcb.h"
/*#include "uart_access.h" */
#include "fault.h"
#include "faultret.h"
#include "memchnl.h"
#include "main.h"
/*#include "string_impl.h"*/
#include "stdio.h"
/* #include "stdio_impl.h" */
#include "systbl.h"
#include "time.h"
/*-------------------------------------*/

struct PRCB *sys_get_prcb()
{
  register struct PRCB *prcb = &ram_prcb;

  return(prcb);
  /*asm volatile("lda _ram_prcb, g0" : : ); */
}

  /* System Procedures Table. 
   */
SystemTbl systemTbl = {
 {0, 0, 0},				/* Reserved */
  svrStackPtr,				/* Supervisor Stack Pointer Base */
 {0, 0, 0, 0, 0, 0, 0, 0},		/* Preserved */
 {0, 0, 0, 0, 0,
  SP(sys_get_prcb + SUPERVISOR_SP), 
  0, 0,		                /* 6 - 7 */
  0, 0, 0, 0, 0, 0, 0, 0,                               /* 8 - 15 */
  0, 0,                                                 /* 16 - 17 */
  0,                     /* 18 */
  0,                    /* 19 */
  0,                    /* 20 */
  0,                      /* 21 */
  0, 0,                                                 /* 22 - 23 */
  0,         /* 24 */  
  0,                       /* 25 */
  0,                        /* 26 */
  0,                        /* 27 */
  0,                        /* 28 */
  0,                        /* 29 */
  0,                      /* 30 */
  0,                       /* 31 */
  0, 0, 0, 0, 0, 0, 0, 0,                               /* 32 - 39 */
  0,                      /* 40 */
  0,                      /* 41 */  
  0,                      /* 42 */  
  0,                      /* 43 */
  0,                      /* 44 */
  0,                     /* 45 */
  0,                     /* 46 */
  0,                                                    /* 47 */
  0, 0, 0, 0, 0, 0, 0, 0,                               /* 48 - 55 */
  0,                    /* 56 */
  0,                          /* 57 */
  0,                         /* 58 */
  0, 0, 0, 0, 0,                                        /* 59 - 63 */
  0,               /* 64 */
  0,              /* 65 */ 
  0, 0, 0, 0, 0, 0,                                     /* 66 - 71 */ 
  0,							/* 72 */ 
  0,							/* 73 */
  0, 							/* 74 */
  0,							/* 75 */
  0,							/* 76 */
  0,							/* 77 */
  0, 0,                                                 /* 78 - 79 */
  0,							/* 80 */
  0,							/* 81 */
  0, 0, 0, 0, 0, 0,                                     /* 82 - 87 */
  0,   /* 88 */ 
  0, 0, 0, 0, 0, 0, 0,                                  /* 89 - 95 */
  0,                  /* 96 */ 
  0,                     /* 97 */ 
  0, 0, 0, 0, 0, 0,                                     /* 98 - 103 */
  0,                 /* 104 */
  0,                 /* 105 */
  0,                      /* 106 */
  0,                      /* 107 */
  0,                      /* 108 */
  0,                    /* 109 */
  0, 0,                                                 /* 110 - 111 */
  0,                     /* 112 */
  0,                  /* 113 */
  0}							/* 114 */
};

/*-------------*/
/* End of file */
/*-------------*/

