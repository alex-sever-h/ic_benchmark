
#include <stdlib.h>
#include <string.h>
#include "stm32f10x.h"
#include "timer.h"
#include "usart.h"
#include "benchmark.h"


#define SMALLTIME 200


/* Procedure for the assignment of structures,          */
/* if the C compiler doesn't support this feature       */
#ifdef  NOSTRUCTASSIGN

memcpy (d, s, l)
register char   *d;
register char   *s;
register int    l;
{
  while (l--) *d++ = *s++;
}
#define structassign(d, s)      memcpy(&(d), &(s), sizeof(d))

#else

#define structassign(d, s)      d = s

#endif


typedef       enum    {Ident_1, Ident_2, Ident_3, Ident_4, Ident_5}
Enumeration;

#ifndef NULL
#define NULL 0
#endif
/* Value of a Null pointer */


#define true  1
#define false 0
/* Value for booleans */



/*********************************************************************
 ********* TYPEDEFS
 *********************************************************************/


typedef int     One_Thirty;
typedef int     One_Fifty;
typedef char    Capital_Letter;
typedef int     Boolean;
typedef char    Str_30 [31];
typedef int     Arr_1_Dim [50];
typedef int     Arr_2_Dim [50] [50];

typedef struct record
{
  struct record *Ptr_Comp;
  Enumeration    Discr;
  union {
    struct {
      Enumeration Enum_Comp;
      int         Int_Comp;
      char        Str_Comp [31];
    } var_1;
    struct {
      Enumeration E_Comp_2;
      char        Str_2_Comp [31];
    } var_2;
    struct {
      char        Ch_1_Comp;
      char        Ch_2_Comp;
    } var_3;
  } variant;
} Rec_Type, *Rec_Pointer;

int dhrystone (void);
void Proc_1 (Rec_Pointer Ptr_Val_Par);
void Proc_2 (One_Fifty *Int_Par_Ref);
void Proc_3 (Rec_Pointer *Ptr_Ref_Par);
void Proc_4 (void);
void Proc_5 (void);
void Proc_6 (Enumeration  Enum_Val_Par, Enumeration *Enum_Ref_Par);
void Proc_7 (One_Fifty Int_1_Par_Val,
    One_Fifty Int_2_Par_Val,
    One_Fifty *Int_Par_Ref);
void Proc_8 (Arr_1_Dim Arr_1_Par_Ref,
    Arr_2_Dim Arr_2_Par_Ref,
    int Int_1_Par_Val,
    int Int_2_Par_Val);

Enumeration Func_1 (Capital_Letter Ch_1_Par_Val, Capital_Letter Ch_2_Par_Val);
Boolean Func_2 (Str_30 Str_1_Par_Ref, Str_30 Str_2_Par_Ref);
Boolean Func_3 (Enumeration Enum_Par_Val);


/*********************************************************************
 ********* Global Variables:
 *********************************************************************/

Rec_Pointer     Ptr_Glob,
Next_Ptr_Glob;
int             Int_Glob;
Boolean         Bool_Glob;
char            Ch_1_Glob,
Ch_2_Glob;
int             Arr_1_Glob [50];
int             Arr_2_Glob [50] [50];

extern  int     Int_Glob;
extern  char    Ch_1_Glob;

#ifndef REG
Boolean Reg = false;
#define REG
/* REG becomes defined as empty */
/* i.e. no register variables   */
#else
Boolean Reg = true;
#endif


int int_to_a(char * str, int number)
{
  if(str == NULL)
    return 1;

  if (number > 0)
    {
      int i;
      int pos = 0;
      int digit;
      int digitfound = 0;
      const int units[] =
          { 1000000000,
              100000000,
              10000000,
              1000000,
              100000,
              10000,
              1000,
              100,
              10,
              1};
      int unit;



      for (i = 0; i < 10; ++i)
        {
          unit  = units[i];
          digit = 0;

          while (number >= unit)
            {
              digit++;
              number -= unit;
            }

          if (digit != 0) digitfound = 1;
          if (digitfound) str[pos++] = digit + '0' ;
        }
      str[pos] = '\0';
    }
  else if (number == 0)
    {
      str[0] = '0';
      str[1] = '\0';
    }
  else
    {
      str[0] = '-';
      int_to_a(str+1, -number);
    }

  return 0;
}



void start_benchmark(void)
{
  dhrystone();
}



int dhrystone (void)
/*****/

/* main program, corresponds to procedures        */
/* Main and Proc_0 in the Ada version             */
{
  One_Fifty       Int_1_Loc;
  REG One_Fifty   Int_2_Loc;
  One_Fifty       Int_3_Loc;
  REG char        Ch_Index;
  Enumeration     Enum_Loc;
  Str_30          Str_1_Loc;
  Str_30          Str_2_Loc;
  REG int         Run_Index;
  REG int         loops;

  char buffer[15];
  unsigned int ms;

  /* Initializations */

  Next_Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));
  Ptr_Glob = (Rec_Pointer) malloc (sizeof (Rec_Type));

  Ptr_Glob->Ptr_Comp                    = Next_Ptr_Glob;
  Ptr_Glob->Discr                       = Ident_1;
  Ptr_Glob->variant.var_1.Enum_Comp     = Ident_3;
  Ptr_Glob->variant.var_1.Int_Comp      = 40;
  strcpy (Ptr_Glob->variant.var_1.Str_Comp,
      "DHRYSTONE PROGRAM, SOME STRING");
  strcpy (Str_1_Loc, "DHRYSTONE PROGRAM, 1'ST STRING");

  Arr_2_Glob [8][7] = 10;
  /* Was missing in published program. Without this statement,    */
  /* Arr_2_Glob [8][7] would have an undefined value.             */
  /* Warning: With 16-Bit processors and Number_Of_Runs > 32000,  */
  /* overflow may occur for this array element.                   */

  loops = 1000000;

  usart_puts ("\n");
  usart_puts ("Dhrystone Benchmark, Version 2.1 (Language: C)\n");
  usart_puts ("\n");




  /***************/
  /* Start timer */
  /***************/
  init_counter_ms();

  do
    {

      usart_puts ("The number of runs through the benchmark: ");
      int_to_a( buffer, loops );
      usart_puts( buffer );
      usart_puts ("\n");

      // RESET TIMER ***************************************************
      reset_counter();

      for (Run_Index = 1; Run_Index <= loops; ++Run_Index)
        {

          Proc_5();
          Proc_4();
          /* Ch_1_Glob == 'A', Ch_2_Glob == 'B', Bool_Glob == true */
          Int_1_Loc = 2;
          Int_2_Loc = 3;
          strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
          Enum_Loc = Ident_2;
          Bool_Glob = ! Func_2 (Str_1_Loc, Str_2_Loc);
          /* Bool_Glob == 1 */
          while (Int_1_Loc < Int_2_Loc)  /* loop body executed once */
            {
              Int_3_Loc = 5 * Int_1_Loc - Int_2_Loc;
              /* Int_3_Loc == 7 */
              Proc_7 (Int_1_Loc, Int_2_Loc, &Int_3_Loc);
              /* Int_3_Loc == 7 */
              Int_1_Loc += 1;
            } /* while */
          /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
          Proc_8 (Arr_1_Glob, Arr_2_Glob, Int_1_Loc, Int_3_Loc);
          /* Int_Glob == 5 */
          Proc_1 (Ptr_Glob);
          for (Ch_Index = 'A'; Ch_Index <= Ch_2_Glob; ++Ch_Index)
            /* loop body executed twice */
            {
              if (Enum_Loc == Func_1 (Ch_Index, 'C'))
                /* then, not executed */
                {
                  Proc_6 (Ident_1, &Enum_Loc);
                  strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 3'RD STRING");
                  Int_2_Loc = Run_Index;
                  Int_Glob = Run_Index;
                }
            }
          /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
          Int_2_Loc = Int_2_Loc * Int_1_Loc;
          Int_1_Loc = Int_2_Loc / Int_3_Loc;
          Int_2_Loc = 7 * (Int_2_Loc - Int_3_Loc) - Int_1_Loc;
          /* Int_1_Loc == 1, Int_2_Loc == 13, Int_3_Loc == 7 */
          Proc_2 (&Int_1_Loc);
          /* Int_1_Loc == 5 */

        } /* loop "for Run_Index" */

      // READ TIMER ***************************************************
      ms = read_counter();

      if(ms < SMALLTIME)
        {
          loops *= 2;
          Arr_2_Glob [8][7] = 10;
        }
    } while(ms < SMALLTIME);


//#define CHECK_RESULTS
#ifdef CHECK_RESULTS
  usart_puts ("Execution ends\n");
  usart_puts ("\n");
  usart_puts ("Final values of the variables used in the benchmark:\n");
  usart_puts ("\n");
  usart_puts ("Int_Glob:            %d\n");
  int_to_a(buffer, Int_Glob );
  usart_puts( buffer );
  usart_puts ("        should be:   %d\n");
  int_to_a(buffer, 5);
  usart_puts( buffer );
  usart_puts ("Bool_Glob:           %d\n");
  int_to_a(buffer, Bool_Glob);
  usart_puts( buffer );
  usart_puts ("        should be:   %d\n");
  int_to_a(buffer, 1);
  usart_puts( buffer );
  usart_puts ("Ch_1_Glob:           %c\n");
  int_to_a(buffer, Ch_1_Glob);
  usart_puts( buffer );
  usart_puts ("        should be:   %c\n");
  usart_puts( "A" );
  usart_puts ("Ch_2_Glob:           %c\n" );
  int_to_a(buffer, Ch_2_Glob);
  usart_puts( buffer );
  usart_puts ("        should be:   %c\n" );
  usart_puts( "B" );
  usart_puts ("Arr_1_Glob[8]:       %d\n");
  int_to_a(buffer, Arr_1_Glob[8]);
  usart_puts( buffer );
  usart_puts ("        should be:   %d\n");
  int_to_a(buffer, 7);
  usart_puts( buffer );
  usart_puts ("Arr_2_Glob[8][7]:    %d\n");
  int_to_a(buffer, Arr_2_Glob[8][7]);
  usart_puts( buffer );
  usart_puts ("        should be:   loops + 10\n");
  usart_puts ("Ptr_Glob->\n");
  usart_puts ("  Ptr_Comp:          %d\n");
  int_to_a(buffer, (int) Ptr_Glob->Ptr_Comp);
  usart_puts( buffer );
  usart_puts ("        should be:   (implementation-dependent)\n");
  usart_puts ("  Discr:             %d\n");
  int_to_a(buffer, Ptr_Glob->Discr);
  usart_puts( buffer );
  usart_puts ("        should be:   %d\n");
  usart_puts( "0" );
  usart_puts ("  Enum_Comp:         %d\n");
  int_to_a(buffer, Ptr_Glob->variant.var_1.Enum_Comp);
  usart_puts( buffer );
  usart_puts ("        should be:   %d\n");
  int_to_a(buffer, 2);
  usart_puts( buffer );
  usart_puts ("  Int_Comp:          %d\n");
  int_to_a(buffer,  Ptr_Glob->variant.var_1.Int_Comp);
  usart_puts( buffer );
  usart_puts ("        should be:   %d\n");
  int_to_a(buffer, 17);
  usart_puts( buffer );
  usart_puts ("  Str_Comp:          %s\n");
  usart_puts( Ptr_Glob->variant.var_1.Str_Comp );
  usart_puts ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  usart_puts ("Next_Ptr_Glob->\n");
  usart_puts ("  Ptr_Comp:          %d\n");
  int_to_a(buffer, (int) Next_Ptr_Glob->Ptr_Comp);
  usart_puts( buffer );
  usart_puts ("        should be:   (implementation-dependent), same as above\n");
  usart_puts ("  Discr:             %d\n");
  int_to_a(buffer, Next_Ptr_Glob->Discr);
  usart_puts( buffer );
  usart_puts ("        should be:   %d\n");
  int_to_a(buffer, 0);
  usart_puts( buffer );
  usart_puts ("  Enum_Comp:         %d\n");
  int_to_a(buffer, Next_Ptr_Glob->variant.var_1.Enum_Comp);
  usart_puts( buffer );
  usart_puts ("        should be:   %d\n");
  int_to_a(buffer, 1);
  usart_puts( buffer );
  usart_puts ("  Int_Comp:          %d\n");
  int_to_a(buffer, Next_Ptr_Glob->variant.var_1.Int_Comp);
  usart_puts( buffer );
  usart_puts ("        should be:   %d\n");
  int_to_a(buffer, 18);
  usart_puts( buffer );
  usart_puts ("  Str_Comp:          %s\n");
  usart_puts ( Next_Ptr_Glob->variant.var_1.Str_Comp);
  usart_puts ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  usart_puts ("Int_1_Loc:           %d\n");
  int_to_a(buffer, Int_1_Loc);
  usart_puts( buffer );
  usart_puts ("        should be:   %d\n");
  int_to_a(buffer, 5);
  usart_puts( buffer );
  usart_puts ("Int_2_Loc:           %d\n" );
  int_to_a(buffer, Int_2_Loc);
  usart_puts( buffer );
  usart_puts ("        should be:   %d\n");
  int_to_a(buffer, 13);
  usart_puts( buffer );
  usart_puts ("Int_3_Loc:           %d\n");
  int_to_a(buffer, Int_3_Loc);
  usart_puts( buffer );
  usart_puts ("        should be:   %d\n");
  int_to_a(buffer, 7);
  usart_puts( buffer );
  usart_puts ("Enum_Loc:            %d\n");
  int_to_a(buffer, Enum_Loc);
  usart_puts( buffer );
  usart_puts ("        should be:   %d\n");
  int_to_a(buffer, 1);
  usart_puts( buffer );
  usart_puts ("Str_1_Loc:           %s\n");
  usart_puts( Str_1_Loc );
  usart_puts ("        should be:   DHRYSTONE PROGRAM, 1'ST STRING\n");
  usart_puts ("Str_2_Loc:           %s\n");
  usart_puts( Str_2_Loc );
  usart_puts ("        should be:   DHRYSTONE PROGRAM, 2'ND STRING\n");
  usart_puts ("\n");
#endif

  usart_puts("Test runned successfully !!!\n");

  usart_puts ("LOOPS: ");
  int_to_a( buffer, loops );
  usart_puts( buffer );
  usart_puts ("\n");

  usart_puts ("TIME : ");
  int_to_a( buffer, ms );
  usart_puts( buffer );
  usart_puts ("\n");

  return 0;
}


void Proc_1 (Rec_Pointer Ptr_Val_Par)
/******************/
/* executed once */
{
  REG Rec_Pointer Next_Record = Ptr_Val_Par->Ptr_Comp;
  /* == Ptr_Glob_Next */
  /* Local variable, initialized with Ptr_Val_Par->Ptr_Comp,    */
  /* corresponds to "rename" in Ada, "with" in Pascal           */

  structassign (*Ptr_Val_Par->Ptr_Comp, *Ptr_Glob);
  Ptr_Val_Par->variant.var_1.Int_Comp = 5;
  Next_Record->variant.var_1.Int_Comp = Ptr_Val_Par->variant.var_1.Int_Comp;
  Next_Record->Ptr_Comp = Ptr_Val_Par->Ptr_Comp;
  Proc_3 (&Next_Record->Ptr_Comp);
  /* Ptr_Val_Par->Ptr_Comp->Ptr_Comp == Ptr_Glob->Ptr_Comp */
  if (Next_Record->Discr == Ident_1)
    /* then, executed */
    {
      Next_Record->variant.var_1.Int_Comp = 6;
      Proc_6 (Ptr_Val_Par->variant.var_1.Enum_Comp,
          &Next_Record->variant.var_1.Enum_Comp);
      Next_Record->Ptr_Comp = Ptr_Glob->Ptr_Comp;
      Proc_7 (Next_Record->variant.var_1.Int_Comp, 10,
          &Next_Record->variant.var_1.Int_Comp);
    }
  else /* not executed */
    structassign (*Ptr_Val_Par, *Ptr_Val_Par->Ptr_Comp);
} /* Proc_1 */


void Proc_2 (One_Fifty *Int_Par_Ref)
/******************/
/* executed once */
/* *Int_Par_Ref == 1, becomes 4 */
{
  One_Fifty  Int_Loc;
  Enumeration   Enum_Loc;

  Int_Loc = *Int_Par_Ref + 10;
  do /* executed once */
    if (Ch_1_Glob == 'A')
      /* then, executed */
      {
        Int_Loc -= 1;
        *Int_Par_Ref = Int_Loc - Int_Glob;
        Enum_Loc = Ident_1;
      } /* if */
  while (Enum_Loc != Ident_1); /* true */
} /* Proc_2 */


void Proc_3 (Rec_Pointer *Ptr_Ref_Par)
/******************/
/* executed once */
/* Ptr_Ref_Par becomes Ptr_Glob */
{
  if (Ptr_Glob != NULL)
    /* then, executed */
    *Ptr_Ref_Par = Ptr_Glob->Ptr_Comp;
  Proc_7 (10, Int_Glob, &Ptr_Glob->variant.var_1.Int_Comp);
} /* Proc_3 */


void Proc_4 (void) /* without parameters */
/*******/
/* executed once */
{
  Boolean Bool_Loc;

  Bool_Loc = Ch_1_Glob == 'A';
  Bool_Glob = Bool_Loc | Bool_Glob;
  Ch_2_Glob = 'B';
} /* Proc_4 */


void Proc_5 (void) /* without parameters */
/*******/
/* executed once */
{
  Ch_1_Glob = 'A';
  Bool_Glob = false;
} /* Proc_5 */


void Proc_6 (Enumeration Enum_Val_Par, Enumeration *Enum_Ref_Par)
/*********************************/
/* executed once */
/* Enum_Val_Par == Ident_3, Enum_Ref_Par becomes Ident_2 */
{
  *Enum_Ref_Par = Enum_Val_Par;
  if (! Func_3 (Enum_Val_Par))
    /* then, not executed */
    *Enum_Ref_Par = Ident_4;
  switch (Enum_Val_Par)
  {
  case Ident_1:
    *Enum_Ref_Par = Ident_1;
    break;
  case Ident_2:
    if (Int_Glob > 100)
      *Enum_Ref_Par = Ident_1;
    else
      *Enum_Ref_Par = Ident_4;
    break;
  case Ident_3: /* executed */
    *Enum_Ref_Par = Ident_2;
    break;
  case Ident_4:
    break;
  case Ident_5:
    *Enum_Ref_Par = Ident_3;
    break;
  } /* switch */
} /* Proc_6 */


void Proc_7 (One_Fifty Int_1_Par_Val,
    One_Fifty Int_2_Par_Val,
    One_Fifty *Int_Par_Ref )
/**********************************************/
/* executed three times                                      */
/* first call:      Int_1_Par_Val == 2, Int_2_Par_Val == 3,  */
/*                  Int_Par_Ref becomes 7                    */
/* second call:     Int_1_Par_Val == 10, Int_2_Par_Val == 5, */
/*                  Int_Par_Ref becomes 17                   */
/* third call:      Int_1_Par_Val == 6, Int_2_Par_Val == 10, */
/*                  Int_Par_Ref becomes 18                   */
{
  One_Fifty Int_Loc;

  Int_Loc = Int_1_Par_Val + 2;
  *Int_Par_Ref = Int_2_Par_Val + Int_Loc;
} /* Proc_7 */


void Proc_8 (Arr_1_Dim Arr_1_Par_Ref,
    Arr_2_Dim Arr_2_Par_Ref,
    int Int_1_Par_Val,
    int Int_2_Par_Val)
/*********************************************************************/
/* executed once      */
/* Int_Par_Val_1 == 3 */
/* Int_Par_Val_2 == 7 */
{
  REG One_Fifty Int_Index;
  REG One_Fifty Int_Loc;

  Int_Loc = Int_1_Par_Val + 5;
  Arr_1_Par_Ref [Int_Loc] = Int_2_Par_Val;
  Arr_1_Par_Ref [Int_Loc+1] = Arr_1_Par_Ref [Int_Loc];
  Arr_1_Par_Ref [Int_Loc+30] = Int_Loc;
  for (Int_Index = Int_Loc; Int_Index <= Int_Loc+1; ++Int_Index)
    Arr_2_Par_Ref [Int_Loc] [Int_Index] = Int_Loc;
  Arr_2_Par_Ref [Int_Loc] [Int_Loc-1] += 1;
  Arr_2_Par_Ref [Int_Loc+20] [Int_Loc] = Arr_1_Par_Ref [Int_Loc];
  Int_Glob = 5;
} /* Proc_8 */


Enumeration Func_1 (Capital_Letter Ch_1_Par_Val, Capital_Letter Ch_2_Par_Val)
/*************************************************/
/* executed three times                                         */
/* first call:      Ch_1_Par_Val == 'H', Ch_2_Par_Val == 'R'    */
/* second call:     Ch_1_Par_Val == 'A', Ch_2_Par_Val == 'C'    */
/* third call:      Ch_1_Par_Val == 'B', Ch_2_Par_Val == 'C'    */
{
  Capital_Letter        Ch_1_Loc;
  Capital_Letter        Ch_2_Loc;

  Ch_1_Loc = Ch_1_Par_Val;
  Ch_2_Loc = Ch_1_Loc;
  if (Ch_2_Loc != Ch_2_Par_Val)
    /* then, executed */
    return (Ident_1);
  else  /* not executed */
    {
      Ch_1_Glob = Ch_1_Loc;
      return (Ident_2);
    }
} /* Func_1 */


Boolean Func_2 (Str_30  Str_1_Par_Ref, Str_30  Str_2_Par_Ref)
/*************************************************/
/* executed once */
/* Str_1_Par_Ref == "DHRYSTONE PROGRAM, 1'ST STRING" */
/* Str_2_Par_Ref == "DHRYSTONE PROGRAM, 2'ND STRING" */
{
  REG One_Thirty      Int_Loc;
  Capital_Letter      Ch_Loc;

  Int_Loc = 2;
  while (Int_Loc <= 2) /* loop body executed once */
    if (Func_1 (Str_1_Par_Ref[Int_Loc],
        Str_2_Par_Ref[Int_Loc+1]) == Ident_1)
      /* then, executed */
      {
        Ch_Loc = 'A';
        Int_Loc += 1;
      } /* if, while */

  if (Ch_Loc >= 'W' && Ch_Loc < 'Z')
    /* then, not executed */
    Int_Loc = 7;
  if (Ch_Loc == 'R')
    /* then, not executed */
    return (true);
  else /* executed */
    {
      if (strcmp (Str_1_Par_Ref, Str_2_Par_Ref) > 0)
        /* then, not executed */
        {
          Int_Loc += 7;
          Int_Glob = Int_Loc;
          return (true);
        }
      else /* executed */
        return (false);
    } /* if Ch_Loc */
} /* Func_2 */


Boolean Func_3 (Enumeration Enum_Par_Val)
/***************************/
/* executed once        */
/* Enum_Par_Val == Ident_3 */
{
  Enumeration Enum_Loc;

  Enum_Loc = Enum_Par_Val;
  if (Enum_Loc == Ident_3)
    /* then, executed */
    return (true);
  else /* not executed */
    return (false);
} /* Func_3 */






