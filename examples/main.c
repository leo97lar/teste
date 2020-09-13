/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/
/* Include files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "main.h"
#include "model_terminate.h"
#include "model_emxAPI.h"
#include "model_initialize.h"

/* Function Declarations */
static emxArray_int32_T *argInit_6xUnbounded_int32_T(void);
static emxArray_real_T *argInit_Unboundedx1_real_T(void);
static emxArray_int32_T *argInit_Unboundedx4_int32_T(void);
static emxArray_int32_T *argInit_Unboundedx5_int32_T(void);
static emxArray_int32_T *argInit_Unboundedx7_int32_T(void);
static emxArray_int32_T *argInit_Unboundedx8_int32_T(void);
static boolean_T argInit_boolean_T(void);
static int argInit_int32_T(void);
static double argInit_real_T(void);
static emxArray_int32_T *c_argInit_UnboundedxUnbounded_i(void);
static void main_BDCreator_func(void);
static void main_main_UCI_func(void);

/* Function Definitions */
static emxArray_int32_T *argInit_6xUnbounded_int32_T(void)
{
  emxArray_int32_T *result;
  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_int32_T(6, 2);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 6; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + 6 * idx1] = argInit_int32_T();
    }
  }

  return result;
}

static emxArray_real_T *argInit_Unboundedx1_real_T(void)
{
  emxArray_real_T *result;
  static int iv1[1] = { 2 };

  int idx0;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, iv1);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0] = argInit_real_T();
  }

  return result;
}

static emxArray_int32_T *argInit_Unboundedx4_int32_T(void)
{
  emxArray_int32_T *result;
  int idx0;
  int i36;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_int32_T(2, 4);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    i36 = argInit_int32_T();
    result->data[idx0] = i36;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0 + result->size[0]] = i36;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0 + (result->size[0] << 1)] = argInit_int32_T();

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0 + result->size[0] * 3] = argInit_int32_T();
  }

  return result;
}

static emxArray_int32_T *argInit_Unboundedx5_int32_T(void)
{
  emxArray_int32_T *result;
  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_int32_T(2, 5);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < 5; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_int32_T();
    }
  }

  return result;
}

static emxArray_int32_T *argInit_Unboundedx7_int32_T(void)
{
  emxArray_int32_T *result;
  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_int32_T(2, 7);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < 7; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_int32_T();
    }
  }

  return result;
}

static emxArray_int32_T *argInit_Unboundedx8_int32_T(void)
{
  emxArray_int32_T *result;
  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_int32_T(2, 8);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < 8; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_int32_T();
    }
  }

  return result;
}

static boolean_T argInit_boolean_T(void)
{
  return false;
}

static int argInit_int32_T(void)
{
  return 0;
}

static double argInit_real_T(void)
{
  return 0.0;
}

static emxArray_int32_T *c_argInit_UnboundedxUnbounded_i(void)
{
  emxArray_int32_T *result;
  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_int32_T(2, 2);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_int32_T();
    }
  }

  return result;
}

static void main_BDCreator_func(void)
{
  /* Call the entry-point 'BDCreator_func'. */
  BDCreator_func();
}

static void main_main_UCI_func(void)
{
  emxArray_int32_T *CP;
  emxArray_int32_T *RO;
  emxArray_int32_T *CPO;
  emxArray_int32_T *CPrO;
  emxArray_int32_T *CR;
  emxArray_int32_T *Data;
  emxArray_int32_T *Dia;
  emxArray_int32_T *DispMExD;
  emxArray_int32_T *MA;
  emxArray_int32_T *MAn;
  emxArray_int32_T *ME;
  emxArray_int32_T *S;
  int TipoOp_tmp;
  int NumTOp;
  int NumSalOp;
  int NumCPO;
  int NumCPrO;
  int NumCR;
  int NumMedEsp;
  int NumEspxE;
  int NumAsist;
  int NumAnest;
  double k0_tmp;
  double k2;
  double k3;
  int numIQ;
  int numIC;
  double taxC;
  double taxE;
  double taxEQ;
  emxArray_real_T *ProbXEst;

  /* Initialize function 'main_UCI_func' input arguments. */
  /* Initialize function input argument 'CP'. */
  CP = argInit_Unboundedx8_int32_T();

  /* Initialize function input argument 'RO'. */
  RO = argInit_Unboundedx7_int32_T();

  /* Initialize function input argument 'CPO'. */
  CPO = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'CPrO'. */
  CPrO = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'CR'. */
  CR = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'Data'. */
  Data = argInit_Unboundedx5_int32_T();

  /* Initialize function input argument 'Dia'. */
  Dia = argInit_Unboundedx4_int32_T();

  /* Initialize function input argument 'DispMExD'. */
  DispMExD = argInit_6xUnbounded_int32_T();

  /* Initialize function input argument 'MA'. */
  MA = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'MAn'. */
  MAn = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'ME'. */
  ME = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'S'. */
  S = c_argInit_UnboundedxUnbounded_i();
  TipoOp_tmp = argInit_int32_T();
  NumTOp = argInit_int32_T();
  NumSalOp = argInit_int32_T();
  NumCPO = argInit_int32_T();
  NumCPrO = argInit_int32_T();
  NumCR = argInit_int32_T();
  NumMedEsp = argInit_int32_T();
  NumEspxE = argInit_int32_T();
  NumAsist = argInit_int32_T();
  NumAnest = argInit_int32_T();
  k0_tmp = argInit_real_T();
  k2 = argInit_real_T();
  k3 = argInit_real_T();
  numIQ = argInit_int32_T();
  numIC = argInit_int32_T();
  taxC = argInit_real_T();
  taxE = argInit_real_T();
  taxEQ = argInit_real_T();

  /* Initialize function input argument 'ProbXEst'. */
  ProbXEst = argInit_Unboundedx1_real_T();

  /* Call the entry-point 'main_UCI_func'. */
  main_UCI_func(CP, RO, CPO, CPrO, CR, Data, Dia, DispMExD, MA, MAn, ME, S,
                TipoOp_tmp, TipoOp_tmp, NumTOp, NumSalOp, NumCPO, NumCPrO, NumCR,
                NumMedEsp, NumEspxE, NumAsist, NumAnest, k0_tmp, k0_tmp, k2, k3,
                numIQ, numIC, taxC, taxE, taxEQ, ProbXEst, argInit_int32_T(),
                argInit_int32_T(), argInit_boolean_T());
  emxDestroyArray_real_T(ProbXEst);
  emxDestroyArray_int32_T(S);
  emxDestroyArray_int32_T(ME);
  emxDestroyArray_int32_T(MAn);
  emxDestroyArray_int32_T(MA);
  emxDestroyArray_int32_T(DispMExD);
  emxDestroyArray_int32_T(Dia);
  emxDestroyArray_int32_T(Data);
  emxDestroyArray_int32_T(CR);
  emxDestroyArray_int32_T(CPrO);
  emxDestroyArray_int32_T(CPO);
  emxDestroyArray_int32_T(RO);
  emxDestroyArray_int32_T(CP);
}

int main(int argc, const char * const argv[])
{
  (void)argc;
  (void)argv;

  /* Initialize the application.
     You do not need to do this more than one time. */
  model_initialize();

  /* Invoke the entry-point functions.
     You can call entry-point functions multiple times. */
  main_BDCreator_func();
  main_main_UCI_func();

  /* Terminate the application.
     You do not need to do this more than one time. */
  model_terminate();
  return 0;
}

/* End of code generation (main.c) */
