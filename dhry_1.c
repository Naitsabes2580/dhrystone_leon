/*
 ****************************************************************************
 *
 *                   "DHRYSTONE" Benchmark Program
 *                   -----------------------------
 *                                                                            
 *  Version:    C, Version 2.1
 *                                                                            
 *  File:       dhry_1.c (part 2 of 3)
 *
 *  Date:       May 25, 1988
 *
 *  Author:     Reinhold P. Weicker
 *
 ****************************************************************************
 */
 /*
 *#LIS#
 *Modified by Sebastian Kroesche
 *Date: 30.10.2015
 *Description: Replaced local variables by global variables
 *Date: 02.11.2015
 *Description: Removed time measurement and printing of variable contents
 */

#include "dhry.h"

/* Global Variables: */

Rec_Pointer     Ptr_Glob,
                Next_Ptr_Glob;
int             Int_Glob;
Boolean         Bool_Glob;
char            Ch_1_Glob,
                Ch_2_Glob;
int             Arr_1_Glob [50];
int             Arr_2_Glob [50] [50];
//#LIS# Start LIS Modification
//extern char     *malloc ();
//#LIS# End LIS Modification

Enumeration     Func_1 ();
  /* forward declaration necessary since Enumeration may not simply be int */

#ifndef REG
        Boolean Reg = false;
#define REG
        /* REG becomes defined as empty */
        /* i.e. no register variables   */
#else
        Boolean Reg = true;
#endif

 //#LIS# Start Block - Additional define for number of iterations
 #define NUM_ITERATIONS   50000000
 //#LIS# End Block - Additional define for number of iterations

/* variables for time measurement: */
//#LIS# Start LIS Modification
/* #ifdef TIMES
struct tms      time_info;
//#LIS# Start LIS Modifcation
//extern  int     times ();
//#LIS# End LIS Modifcation
                /* see library function "times" */
/*#define Too_Small_Time (2*HZ)
                /* Measurements should last at least about 2 seconds */
/*#endif
#ifdef TIME
extern long     time();
                /* see library function "time"  */
/*#define Too_Small_Time 2
                /* Measurements should last at least 2 seconds */
/*#endif
#ifdef MSC_CLOCK
extern clock_t	clock();
#define Too_Small_Time (2*HZ)
#endif

long            Begin_Time,
                End_Time,
                User_Time;
float           Microseconds,
                Dhrystones_Per_Second;
//#LIS# End LIS Modification
/* end of variables for time measurement */

//#LIS# Start LIS Modification -- Local variables that are made global
      One_Fifty       Int_1_Loc;
REG   One_Fifty       Int_2_Loc;
      One_Fifty       Int_3_Loc;
REG   char            Ch_Index;
      Enumeration     Enum_Loc;
      Str_30          Str_1_Loc; 
      Str_30          Str_2_Loc;
REG   int             Run_Index;
REG   int             Number_Of_Runs;

//### this comes from Proc_1
REG   Rec_Pointer     Next_Record;

//### this comes from Proc_2
      One_Fifty       *Int_Par_Ref;
      One_Fifty       Int_Loc;  
      Enumeration     Enum_Loc_2;

//### this comes from Proc_3
      Rec_Pointer     *Ptr_Ref_Par;

//### this comes from Proc_4
      Boolean         Bool_Loc;

//### this comes from Proc_6
      Enumeration     Enum_Val_Par;
      Enumeration     *Enum_Ref_Par;

//### this comes from Proc_7
      One_Fifty       Int_1_Par_Val_Proc7;
      One_Fifty       Int_2_Par_Val_Proc7;
      One_Fifty       *Int_Par_Ref_Proc7;
      One_Fifty       Int_Loc_Proc7;

//### this comes from Proc_8
      int             Int_1_Par_Val_Proc8;
      REG One_Fifty   Int_Index_Proc8;
      REG One_Fifty   Int_Loc_Proc8;
      int             Int_2_Par_Val_Proc8;

//### this comes from Func_1
      Capital_Letter  Ch_1_Loc_Func1;
      Capital_Letter  Ch_2_Loc_Func1;

//### this comes from Func_2
      Str_30          Str_1_Par_Ref;
      Str_30          Str_2_Par_Ref;
      REG One_Thirty  Int_Loc_Func2;
      Capital_Letter  Ch_Loc_Func2;

//### this comes from Func_3
      Enumeration     Enum_Loc_Func3;

//#LIS# End LIS Modification -- Local variables that are made global


main ()
/*****/

  /* main program, corresponds to procedures        */
  /* Main and Proc_0 in the Ada version             */
{
  //#LIS# Start LIS Modification
        //One_Fifty       Int_1_Loc;
  
  //REG   One_Fifty       Int_2_Loc;
  //      One_Fifty       Int_3_Loc;
  //REG   char            Ch_Index;
  //      Enumeration     Enum_Loc;
  //      Str_30          Str_1_Loc;
  //      Str_30          Str_2_Loc;
  //REG   int             Run_Index;
  //REG   int             Number_Of_Runs;
  //#LIS# End LIS Modification
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

  //#LIS# Start LIS Modification -- Do not print anything on console
  /*printf ("\n");
  printf ("Dhrystone Benchmark, Version 2.1 (Language: C)\n");
  printf ("\n");
  if (Reg)
  {
    printf ("Program compiled with 'register' attribute\n");
    printf ("\n");
  }
  else
  {
    printf ("Program compiled without 'register' attribute\n");
    printf ("\n");
  }
  //#LIS# Start LIS Modification
  /*printf ("Please give the number of runs through the benchmark: ");
  {
    int n;
    scanf ("%d", &n);
    //Number_Of_Runs = n;
  }*/
  Number_Of_Runs = NUM_ITERATIONS;
  //#LIS# End LIS Modification
  /*printf ("\n");

  printf ("Execution starts, %d runs through Dhrystone\n", Number_Of_Runs);
  //#LIS# End LIS Modification -- Do not print anything on console
  /***************/
  /* Start timer */
  /***************/
//#LIS# Start LIS Modification
/*#ifdef TIMES
  times (&time_info);
  Begin_Time = (long) time_info.tms_utime;
#endif
#ifdef TIME
  Begin_Time = time ( (long *) 0);
#endif
#ifdef MSC_CLOCK
  Begin_Time = clock();
#endif*/
//#LIS# End LIS Modification

  for (Run_Index = 1; Run_Index <= Number_Of_Runs; ++Run_Index)
  {

    Proc_5();
    Proc_4();
      /* Ch_1_Glob == 'A', Ch_2_Glob == 'B', Bool_Glob == true */
    Int_1_Loc = 2;
    Int_2_Loc = 3;
    strcpy (Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
    Enum_Loc = Ident_2;
    //#LIS# Start LIS Modification
    strcpy(Str_1_Par_Ref, Str_1_Loc);
    strcpy(Str_2_Par_Ref, Str_2_Loc);
    //Bool_Glob = ! Func_2 (Str_1_Loc, Str_2_Loc);
    Bool_Glob = ! Func_2 ();
    //#LIS# End LIS Modification
      /* Bool_Glob == 1 */
    while (Int_1_Loc < Int_2_Loc)  /* loop body executed once */
    {
      Int_3_Loc = 5 * Int_1_Loc - Int_2_Loc;
        /* Int_3_Loc == 7 */
      //#LIS# Start LIS Modification
      //Proc_7 (Int_1_Loc, Int_2_Loc, &Int_3_Loc);
      Int_1_Par_Val_Proc7 = Int_1_Loc;
      Int_2_Par_Val_Proc7 = Int_2_Loc;
      Int_Par_Ref_Proc7 = &Int_3_Loc;
      Proc_7 ();
      //#LIS# End LIS Modification
        /* Int_3_Loc == 7 */
      Int_1_Loc += 1;
    } /* while */
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
    //#LIS# Start LIS Modification
    //Proc_8 (Arr_1_Glob, Arr_2_Glob, Int_1_Loc, Int_3_Loc);
    Int_1_Par_Val_Proc8 = Int_1_Loc;
    Int_2_Par_Val_Proc8 = Int_3_Loc;
    Proc_8 ();
    //#LIS# End LIS Modification
      /* Int_Glob == 5 */
    //#LIS# Start LIS Modification
    //Proc_1 (Ptr_Glob);
    Proc_1 ();
    //#LIS# End LIS Modification
    for (Ch_Index = 'A'; Ch_Index <= Ch_2_Glob; ++Ch_Index)
                             /* loop body executed twice */
    {      
      if (Enum_Loc == Func_1 (Ch_Index, 'C'))     
          /* then, not executed */
        {
        //#LIS# Start LIS Modification
        //Proc_6 (Ident_1, &Enum_Loc);
        Enum_Val_Par = Ident_1;
        Enum_Ref_Par = &Enum_Loc;
        Proc_6();
        //#LIS# End LIS Modification
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
    
    //#LIS# Start LIS Modification
    //Proc_2 (&Int_1_Loc);
    Int_Par_Ref = &Int_1_Loc;    
    Proc_2();
    //#LIS# End LIS Modification
      /* Int_1_Loc == 5 */

  } /* loop "for Run_Index" */

  /**************/
  /* Stop timer */
  /**************/
//#LIS# Start LIS Modification  
/*#ifdef TIMES
  times (&time_info);
  End_Time = (long) time_info.tms_utime;
#endif
#ifdef TIME
  End_Time = time ( (long *) 0);
#endif
#ifdef MSC_CLOCK
  End_Time = clock();
#endif*/

  printf ("Execution ends\n");
  printf ("\n");
  printf ("Final values of the variables used in the benchmark:\n");
  printf ("\n");
  printf ("Int_Glob:            %d\n", Int_Glob);
  printf ("        should be:   %d\n", 5);
  printf ("Bool_Glob:           %d\n", Bool_Glob);
  printf ("        should be:   %d\n", 1);
  printf ("Ch_1_Glob:           %c\n", Ch_1_Glob);
  printf ("        should be:   %c\n", 'A');
  printf ("Ch_2_Glob:           %c\n", Ch_2_Glob);
  printf ("        should be:   %c\n", 'B');
  printf ("Arr_1_Glob[8]:       %d\n", Arr_1_Glob[8]);
  printf ("        should be:   %d\n", 7);
  printf ("Arr_2_Glob[8][7]:    %d\n", Arr_2_Glob[8][7]);
  printf ("        should be:   Number_Of_Runs + 10\n");
  printf ("Ptr_Glob->\n");
  printf ("  Ptr_Comp:          %d\n", (int) Ptr_Glob->Ptr_Comp);
  printf ("        should be:   (implementation-dependent)\n");
  printf ("  Discr:             %d\n", Ptr_Glob->Discr);
  printf ("        should be:   %d\n", 0);
  printf ("  Enum_Comp:         %d\n", Ptr_Glob->variant.var_1.Enum_Comp);
  printf ("        should be:   %d\n", 2);
  printf ("  Int_Comp:          %d\n", Ptr_Glob->variant.var_1.Int_Comp);
  printf ("        should be:   %d\n", 17);
  printf ("  Str_Comp:          %s\n", Ptr_Glob->variant.var_1.Str_Comp);
  printf ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  printf ("Next_Ptr_Glob->\n");
  printf ("  Ptr_Comp:          %d\n", (int) Next_Ptr_Glob->Ptr_Comp);
  printf ("        should be:   (implementation-dependent), same as above\n");
  printf ("  Discr:             %d\n", Next_Ptr_Glob->Discr);
  printf ("        should be:   %d\n", 0);
  printf ("  Enum_Comp:         %d\n", Next_Ptr_Glob->variant.var_1.Enum_Comp);
  printf ("        should be:   %d\n", 1);
  printf ("  Int_Comp:          %d\n", Next_Ptr_Glob->variant.var_1.Int_Comp);
  printf ("        should be:   %d\n", 18);
  printf ("  Str_Comp:          %s\n",
                                Next_Ptr_Glob->variant.var_1.Str_Comp);
  printf ("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  printf ("Int_1_Loc:           %d\n", Int_1_Loc);
  printf ("        should be:   %d\n", 5);
  printf ("Int_2_Loc:           %d\n", Int_2_Loc);
  printf ("        should be:   %d\n", 13);
  printf ("Int_3_Loc:           %d\n", Int_3_Loc);
  printf ("        should be:   %d\n", 7);
  printf ("Enum_Loc:            %d\n", Enum_Loc);
  printf ("        should be:   %d\n", 1);
  printf ("Str_1_Loc:           %s\n", Str_1_Loc);
  printf ("        should be:   DHRYSTONE PROGRAM, 1'ST STRING\n");
  printf ("Str_2_Loc:           %s\n", Str_2_Loc);
  printf ("        should be:   DHRYSTONE PROGRAM, 2'ND STRING\n");
  printf ("\n");

  
  /*User_Time = End_Time - Begin_Time;

  if (User_Time < Too_Small_Time)
  {
    printf ("Measured time too small to obtain meaningful results\n");
    printf ("Please increase number of runs\n");
    printf ("\n");
  }
  else
  {
#ifdef TIME
    Microseconds = (float) User_Time * Mic_secs_Per_Second 
                        / (float) Number_Of_Runs;
    Dhrystones_Per_Second = (float) Number_Of_Runs / (float) User_Time;
#else
    Microseconds = (float) User_Time * Mic_secs_Per_Second 
                        / ((float) HZ * ((float) Number_Of_Runs));
    Dhrystones_Per_Second = ((float) HZ * (float) Number_Of_Runs)
                        / (float) User_Time;
#endif
    printf ("Microseconds for one run through Dhrystone: ");
    printf ("%6.1f \n", Microseconds);
    printf ("Dhrystones per Second:                      ");
    printf ("%6.1f \n", Dhrystones_Per_Second);
    printf ("\n");
  }*/
//#LIS# End LIS Modification  
}

//#LIS# Start LIS Modification
//Proc_1 (Ptr_Val_Par)
Proc_1 () //### no parameters, as only global variables are used

/******************/
//REG Rec_Pointer Ptr_Val_Par;  //###equivalent to Ptr_Glob
    /* executed once */
//#LIS# End LIS Modification
{
  //#LIS# Start LIS Modification
  //REG Rec_Pointer Next_Record = Ptr_Val_Par->Ptr_Comp;  
  Next_Record = Ptr_Glob->Ptr_Comp;  
  //#LIS# End LIS Modification
                                        /* == Ptr_Glob_Next */
  /* Local variable, initialized with Ptr_Val_Par->Ptr_Comp,    */
  /* corresponds to "rename" in Ada, "with" in Pascal           */
  
  //#LIS# Start LIS Modification
  //structassign (*Ptr_Val_Par->Ptr_Comp, *Ptr_Glob); 
  structassign (*Ptr_Glob->Ptr_Comp, *Ptr_Glob); 
  //#LIS# End LIS Modification
  //#LIS# Start LIS Modification
  //Ptr_Val_Par->variant.var_1.Int_Comp = 5;
  Ptr_Glob->variant.var_1.Int_Comp = 5;
  //#LIS# End LIS Modification
  //#LIS# Start LIS Modification
  //Next_Record->variant.var_1.Int_Comp = Ptr_Val_Par->variant.var_1.Int_Comp;
  Next_Record->variant.var_1.Int_Comp = Ptr_Glob->variant.var_1.Int_Comp;
  //#LIS# End LIS Modification
  //#LIS# Start LIS Modification
  //Next_Record->Ptr_Comp = Ptr_Val_Par->Ptr_Comp;
  Next_Record->Ptr_Comp = Ptr_Glob->Ptr_Comp;
  //#LIS# End LIS Modification
  //#LIS# Start LIS Modification
  //Proc_3 (&Next_Record->Ptr_Comp);
  Ptr_Ref_Par = &Next_Record->Ptr_Comp;
  Proc_3();
  //#LIS# End LIS Modification
    /* Ptr_Val_Par->Ptr_Comp->Ptr_Comp 
                        == Ptr_Glob->Ptr_Comp */
  if (Next_Record->Discr == Ident_1)
    /* then, executed */
  {
    Next_Record->variant.var_1.Int_Comp = 6;
    //#LIS# Start LIS Modification
    /* Proc_6 (Ptr_Val_Par->variant.var_1.Enum_Comp, 
           &Next_Record->variant.var_1.Enum_Comp); */
    /*Proc_6 (Ptr_Glob->variant.var_1.Enum_Comp, 
           &Next_Record->variant.var_1.Enum_Comp); */
    Enum_Val_Par = Ptr_Glob->variant.var_1.Enum_Comp;
    Enum_Ref_Par = &Next_Record->variant.var_1.Enum_Comp;
    Proc_6();
    //#LIS# End LIS Modification
    Next_Record->Ptr_Comp = Ptr_Glob->Ptr_Comp;
    //#LIS# Start LIS Modification
    /*Proc_7 (Next_Record->variant.var_1.Int_Comp, 10, 
           &Next_Record->variant.var_1.Int_Comp);*/
    Int_1_Par_Val_Proc7 = Next_Record->variant.var_1.Int_Comp;
    Int_2_Par_Val_Proc7 = 10;
    Int_Par_Ref_Proc7 = &Next_Record->variant.var_1.Int_Comp;    
    Proc_7();
    //#LIS# End LIS Modification
  }
  else /* not executed */
    //#LIS# Start LIS Modification
    //structassign (*Ptr_Val_Par, *Ptr_Val_Par->Ptr_Comp);
    structassign (*Ptr_Glob, *Ptr_Glob->Ptr_Comp);
    //#LIS# End LIS Modification
} /* Proc_1 */

//#LIS# Start LIS Modification
//Proc_2 (Int_Par_Ref)
Proc_2()
/******************/
    /* executed once */
    /* *Int_Par_Ref == 1, becomes 4 */

//One_Fifty   *Int_Par_Ref;   // this has been made global
//#LIS# End LIS Modification
{
  //#LIS# Start LIS Modification
  //One_Fifty     Int_Loc;  
  //Enumeration   Enum_Loc;
  //#LIS# End LIS Modification

  Int_Loc = *Int_Par_Ref + 10;
  do /* executed once */
    if (Ch_1_Glob == 'A')
      /* then, executed */
    {
      Int_Loc -= 1;
      *Int_Par_Ref = Int_Loc - Int_Glob;
      Enum_Loc_2 = Ident_1;
    } /* if */
  while (Enum_Loc_2 != Ident_1); /* true */
} /* Proc_2 */


//#LIS# Start LIS Modification
//Proc_3 (Ptr_Ref_Par)
Proc_3()
/******************/
    /* executed once */
    /* Ptr_Ref_Par becomes Ptr_Glob */

//Rec_Pointer *Ptr_Ref_Par;   // this has been made global
//#LIS# End LIS Modification
{
  if (Ptr_Glob != Null)
    /* then, executed */
    *Ptr_Ref_Par = Ptr_Glob->Ptr_Comp;
  //#LIS# Start LIS Modification
  //Proc_7 (10, Int_Glob, &Ptr_Glob->variant.var_1.Int_Comp);
  Int_1_Par_Val_Proc7 = 10;
  Int_2_Par_Val_Proc7 = Int_Glob;
  Int_Par_Ref_Proc7 = &Ptr_Glob->variant.var_1.Int_Comp;
  Proc_7();
  //#LIS# End LIS Modification
} /* Proc_3 */


Proc_4 () /* without parameters */
/*******/
    /* executed once */
{
  //#LIS# Start LIS Modification
  //Boolean Bool_Loc;   //this has been made global
  //#LIS# End LIS Modification

  Bool_Loc = Ch_1_Glob == 'A';
  Bool_Glob = Bool_Loc | Bool_Glob;
  Ch_2_Glob = 'B';
} /* Proc_4 */


Proc_5 () /* without parameters */
/*******/
    /* executed once */
{
  Ch_1_Glob = 'A';
  Bool_Glob = false;
} /* Proc_5 */


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
#endif


