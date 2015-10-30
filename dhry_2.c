/*
 ****************************************************************************
 *
 *                   "DHRYSTONE" Benchmark Program
 *                   -----------------------------
 *                                                                            
 *  Version:    C, Version 2.1
 *                                                                            
 *  File:       dhry_2.c (part 3 of 3)
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
*/
#include "dhry.h"

#ifndef REG
#define REG
        /* REG becomes defined as empty */
        /* i.e. no register variables   */
#endif

extern  int           Int_Glob;
extern  char          Ch_1_Glob;

//#LIS# Start LIS Modification
//Proc_6
extern  Enumeration   Enum_Val_Par;
extern  Enumeration   *Enum_Ref_Par;

//Proc_7
extern  One_Fifty     Int_1_Par_Val_Proc7;
extern  One_Fifty     Int_2_Par_Val_Proc7;
extern  One_Fifty     *Int_Par_Ref_Proc7;
extern  One_Fifty     Int_Loc_Proc7;

//Proc_8
extern  int           Arr_1_Glob [50];
extern  int           Arr_2_Glob [50] [50];
extern  int           Int_1_Par_Val_Proc8;
extern  int           Int_2_Par_Val_Proc8;
extern  REG One_Fifty Int_Index_Proc8;
extern  REG One_Fifty Int_Loc_Proc8;

//#LIS# End LIS Modification

//#LIS# Start LIS Modification
//Proc_6 (Enum_Val_Par, Enum_Ref_Par)
Proc_6()
/*********************************/
    /* executed once */
    /* Enum_Val_Par == Ident_3, Enum_Ref_Par becomes Ident_2 */

//Enumeration  Enum_Val_Par;  //this has been made global
//Enumeration *Enum_Ref_Par;  //this has been made global
//#LIS# End LIS Modification
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
        /* then */
      *Enum_Ref_Par = Ident_1;
      else *Enum_Ref_Par = Ident_4;
      break;
    case Ident_3: /* executed */
      *Enum_Ref_Par = Ident_2;
      break;
    case Ident_4: break;
    case Ident_5: 
      *Enum_Ref_Par = Ident_3;
      break;
  } /* switch */
} /* Proc_6 */

//#LIS# Start LIS Modification
//Proc_7 (Int_1_Par_Val, Int_2_Par_Val, Int_Par_Ref)
Proc_7 (Int_Par_Ref)
/**********************************************/
    /* executed three times                                      */ 
    /* first call:      Int_1_Par_Val == 2, Int_2_Par_Val == 3,  */
    /*                  Int_Par_Ref becomes 7                    */
    /* second call:     Int_1_Par_Val == 10, Int_2_Par_Val == 5, */
    /*                  Int_Par_Ref becomes 17                   */
    /* third call:      Int_1_Par_Val == 6, Int_2_Par_Val == 10, */
    /*                  Int_Par_Ref becomes 18                   */
//One_Fifty       Int_1_Par_Val;    //this has been made global
//One_Fifty       Int_2_Par_Val;    //this has been made global
//One_Fifty      *Int_Par_Ref;      //this has been made global
//#LIS# End LIS Modification
{
  //#LIS# Start LIS Modification
  //One_Fifty Int_Loc_Proc7;        //this has been made global

  Int_Loc_Proc7 = Int_1_Par_Val_Proc7 + 2;
  *Int_Par_Ref_Proc7 = Int_2_Par_Val_Proc7 + Int_Loc_Proc7;
  //#LIS# End LIS Modification
} /* Proc_7 */


//#LIS# Start LIS Modification
//Proc_8 (Arr_1_Par_Ref, Arr_2_Par_Ref, Int_1_Par_Val, Int_2_Par_Val)
  Proc_8 ()
/*********************************************************************/
    /* executed once      */
    /* Int_Par_Val_1 == 3 */
    /* Int_Par_Val_2 == 7 */
//Arr_1_Dim       Arr_1_Par_Ref;  //this has been made global
//Arr_2_Dim       Arr_2_Par_Ref;  //this has been made global
//int             Int_1_Par_Val;
//int             Int_2_Par_Val;
//#LIS# End LIS Modification
{
  //#LIS# Start LIS Modification
  //REG One_Fifty Int_Index;      //this has been made global
  //REG One_Fifty Int_Loc;        //this has been made global
  //#LIS# End LIS Modification

  Int_Loc_Proc8 = Int_1_Par_Val_Proc8 + 5;
  Arr_1_Glob [Int_Loc_Proc8] = Int_2_Par_Val_Proc8;
  Arr_1_Glob [Int_Loc_Proc8+1] = Arr_1_Glob [Int_Loc_Proc8];
  Arr_1_Glob [Int_Loc_Proc8+30] = Int_Loc_Proc8;
  for (Int_Index_Proc8 = Int_Loc_Proc8; Int_Index_Proc8 <= Int_Loc_Proc8+1; ++Int_Index_Proc8)
    Arr_2_Glob [Int_Loc_Proc8] [Int_Index_Proc8] = Int_Loc_Proc8;
  Arr_2_Glob [Int_Loc_Proc8] [Int_Loc_Proc8-1] += 1;
  Arr_2_Glob [Int_Loc_Proc8+20] [Int_Loc_Proc8] = Arr_1_Glob [Int_Loc_Proc8];
  Int_Glob = 5;
} /* Proc_8 */


Enumeration Func_1 (Ch_1_Par_Val, Ch_2_Par_Val)
/*************************************************/
    /* executed three times                                         */
    /* first call:      Ch_1_Par_Val == 'H', Ch_2_Par_Val == 'R'    */
    /* second call:     Ch_1_Par_Val == 'A', Ch_2_Par_Val == 'C'    */
    /* third call:      Ch_1_Par_Val == 'B', Ch_2_Par_Val == 'C'    */

Capital_Letter   Ch_1_Par_Val;
Capital_Letter   Ch_2_Par_Val;
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


Boolean Func_2 (Str_1_Par_Ref, Str_2_Par_Ref)
/*************************************************/
    /* executed once */
    /* Str_1_Par_Ref == "DHRYSTONE PROGRAM, 1'ST STRING" */
    /* Str_2_Par_Ref == "DHRYSTONE PROGRAM, 2'ND STRING" */

Str_30  Str_1_Par_Ref;
Str_30  Str_2_Par_Ref;
{
  REG One_Thirty        Int_Loc;
      Capital_Letter    Ch_Loc;

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


Boolean Func_3 (Enum_Par_Val)
/***************************/
    /* executed once        */
    /* Enum_Par_Val == Ident_3 */
Enumeration Enum_Par_Val;
{
  Enumeration Enum_Loc;

  Enum_Loc = Enum_Par_Val;
  if (Enum_Loc == Ident_3)
    /* then, executed */
    return (true);
  else /* not executed */
    return (false);
} /* Func_3 */

