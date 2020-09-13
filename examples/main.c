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
#include "Calendario.h"
#include "Codificacion_de_dias_func.h"
#include "CreaPoQunniforme.h"
#include "Edade.h"
#include "PLOTT_func.h"
#include "actIQ.h"
#include "aevSPLap.h"
#include "casorandom.h"
#include "cc.h"
#include "favalia.h"
#include "funcionC.h"
#include "funcionCPrO.h"
#include "funcionCR.h"
#include "funcionDia.h"
#include "funcionRP.h"
#include "main_UCI_func.h"
#include "obsIQ.h"
#include "obsIQini.h"
#include "sch.h"
#include "main.h"
#include "model_terminate.h"
#include "model_emxAPI.h"
#include "model_initialize.h"

/* Function Declarations */
static void argInit_1x6_real_T(double result[6]);
static void argInit_1x7_int32_T(int result[7]);
static emxArray_int32_T *argInit_1xUnbounded_int32_T(void);
static void argInit_5x1_real_T(double result[5]);
static emxArray_int32_T *argInit_6xUnbounded_int32_T(void);
static emxArray_int32_T *argInit_Unboundedx1_int32_T(void);
static emxArray_real_T *argInit_Unboundedx1_real_T(void);
static emxArray_int32_T *argInit_Unboundedx2_int32_T(void);
static emxArray_int32_T *argInit_Unboundedx4_int32_T(void);
static emxArray_int32_T *argInit_Unboundedx5_int32_T(void);
static emxArray_int32_T *argInit_Unboundedx7_int32_T(void);
static emxArray_real_T *argInit_Unboundedx9_real_T(void);
static int argInit_int32_T(void);
static double argInit_real_T(void);
static emxArray_int32_T *c_argInit_UnboundedxUnbounded_i(void);
static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void);
static void main_BDCreator_func(void);
static void main_Calendario(void);
static void main_Codificacion_de_dias_func(void);
static void main_CreaPoQunniforme(void);
static void main_Edade(void);
static void main_PLOTT_func(void);
static void main_actIQ(void);
static void main_aevSPLap(void);
static void main_casorandom(void);
static void main_cc(void);
static void main_favalia(void);
static void main_funcionC(void);
static void main_funcionCPrO(void);
static void main_funcionCR(void);
static void main_funcionDia(void);
static void main_funcionRP(void);
static void main_main_UCI_func(void);
static void main_obsIQ(void);
static void main_obsIQini(void);
static void main_sch(void);

/* Function Definitions */
static void argInit_1x6_real_T(double result[6])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 6; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

static void argInit_1x7_int32_T(int result[7])
{
  int idx1;

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 7; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx1] = argInit_int32_T();
  }
}

static emxArray_int32_T *argInit_1xUnbounded_int32_T(void)
{
  emxArray_int32_T *result;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_int32_T(1, 2);

  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx1] = argInit_int32_T();
  }

  return result;
}

static void argInit_5x1_real_T(double result[5])
{
  int idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 5; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

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

static emxArray_int32_T *argInit_Unboundedx1_int32_T(void)
{
  emxArray_int32_T *result;
  static int iv16[1] = { 2 };

  int idx0;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_int32_T(1, iv16);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0] = argInit_int32_T();
  }

  return result;
}

static emxArray_real_T *argInit_Unboundedx1_real_T(void)
{
  emxArray_real_T *result;
  static int iv15[1] = { 2 };

  int idx0;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreateND_real_T(1, iv15);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0] = argInit_real_T();
  }

  return result;
}

static emxArray_int32_T *argInit_Unboundedx2_int32_T(void)
{
  emxArray_int32_T *result;
  int idx0;
  int i68;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_int32_T(2, 2);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    i68 = argInit_int32_T();
    result->data[idx0] = i68;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0 + result->size[0]] = i68;
  }

  return result;
}

static emxArray_int32_T *argInit_Unboundedx4_int32_T(void)
{
  emxArray_int32_T *result;
  int idx0;
  int i67;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_int32_T(2, 4);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    i67 = argInit_int32_T();
    result->data[idx0] = i67;

    /* Set the value of the array element.
       Change this value to the value that the application requires. */
    result->data[idx0 + result->size[0]] = i67;

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

static emxArray_real_T *argInit_Unboundedx9_real_T(void)
{
  emxArray_real_T *result;
  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_real_T(2, 9);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < 9; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
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

static emxArray_real_T *c_argInit_UnboundedxUnbounded_r(void)
{
  emxArray_real_T *result;
  int idx0;
  int idx1;

  /* Set the size of the array.
     Change this size to the value that the application requires. */
  result = emxCreate_real_T(2, 2);

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < result->size[0U]; idx0++) {
    for (idx1 = 0; idx1 < result->size[1U]; idx1++) {
      /* Set the value of the array element.
         Change this value to the value that the application requires. */
      result->data[idx0 + result->size[0] * idx1] = argInit_real_T();
    }
  }

  return result;
}

static void main_BDCreator_func(void)
{
  /* Call the entry-point 'BDCreator_func'. */
  BDCreator_func();
}

static void main_Calendario(void)
{
  static double Data[87600];
  double Dia[2920];

  /* Call the entry-point 'Calendario'. */
  Calendario(Data, Dia);
}

static void main_Codificacion_de_dias_func(void)
{
  /* Call the entry-point 'Codificacion_de_dias_func'. */
  Codificacion_de_dias_func();
}

static void main_CreaPoQunniforme(void)
{
  emxArray_real_T *IQ;
  emxInitArray_real_T(&IQ, 2);

  /* Initialize function 'CreaPoQunniforme' input arguments. */
  /* Call the entry-point 'CreaPoQunniforme'. */
  CreaPoQunniforme(argInit_int32_T(), argInit_int32_T(), IQ);
  emxDestroyArray_real_T(IQ);
}

static void main_Edade(void)
{
  emxArray_real_T *c_Edade;
  emxInitArray_real_T(&c_Edade, 1);

  /* Initialize function 'Edade' input arguments. */
  /* Call the entry-point 'Edade'. */
  Edade(argInit_int32_T(), argInit_int32_T(), argInit_int32_T(), c_Edade);
  emxDestroyArray_real_T(c_Edade);
}

static void main_PLOTT_func(void)
{
  emxArray_real_T *trace;

  /* Initialize function 'PLOTT_func' input arguments. */
  /* Initialize function input argument 'trace'. */
  trace = argInit_Unboundedx9_real_T();

  /* Call the entry-point 'PLOTT_func'. */
  PLOTT_func(trace);
  emxDestroyArray_real_T(trace);
}

static void main_actIQ(void)
{
  emxArray_real_T *IQact;
  emxArray_real_T *IQ;
  emxArray_int32_T *IC;
  emxInitArray_real_T(&IQact, 2);

  /* Initialize function 'actIQ' input arguments. */
  /* Initialize function input argument 'IQ'. */
  IQ = c_argInit_UnboundedxUnbounded_r();

  /* Initialize function input argument 'IC'. */
  IC = c_argInit_UnboundedxUnbounded_i();

  /* Call the entry-point 'actIQ'. */
  actIQ(IQ, IC, argInit_real_T(), IQact);
  emxDestroyArray_real_T(IQact);
  emxDestroyArray_int32_T(IC);
  emxDestroyArray_real_T(IQ);
}

static void main_aevSPLap(void)
{
  emxArray_int32_T *bestexperimento;
  emxArray_real_T *trace;
  int NumTOp_tmp;
  int numIQ;
  double taxC_tmp;
  double taxEQ;
  int NumRec[7];
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *PME;
  emxArray_int32_T *PMA;
  emxArray_int32_T *PMAn;
  emxArray_int32_T *PS;
  emxArray_int32_T *PCPO;
  emxArray_int32_T *PCR;
  emxArray_int32_T *Dia;
  emxArray_int32_T *Data;
  emxArray_int32_T *TimeUsoRec;
  double ProbXEst[5];
  double fitnessB[6];
  int generations;
  int genToWidth;
  emxArray_int32_T *DispMExD;
  emxArray_real_T *EP;
  emxInitArray_int32_T(&bestexperimento, 1);
  emxInitArray_real_T(&trace, 2);

  /* Initialize function 'aevSPLap' input arguments. */
  NumTOp_tmp = argInit_int32_T();
  numIQ = argInit_int32_T();
  taxC_tmp = argInit_real_T();
  taxEQ = argInit_real_T();

  /* Initialize function input argument 'NumRec'. */
  argInit_1x7_int32_T(NumRec);

  /* Initialize function input argument 'PCPrO'. */
  PCPrO = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PME'. */
  PME = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PMA'. */
  PMA = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PMAn'. */
  PMAn = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PS'. */
  PS = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PCPO'. */
  PCPO = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PCR'. */
  PCR = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'Dia'. */
  Dia = argInit_Unboundedx4_int32_T();

  /* Initialize function input argument 'Data'. */
  Data = argInit_Unboundedx5_int32_T();

  /* Initialize function input argument 'TimeUsoRec'. */
  TimeUsoRec = argInit_Unboundedx7_int32_T();

  /* Initialize function input argument 'ProbXEst'. */
  argInit_5x1_real_T(ProbXEst);

  /* Initialize function input argument 'fitnessB'. */
  argInit_1x6_real_T(fitnessB);
  generations = argInit_int32_T();
  genToWidth = argInit_int32_T();

  /* Initialize function input argument 'DispMExD'. */
  DispMExD = argInit_6xUnbounded_int32_T();

  /* Initialize function input argument 'EP'. */
  EP = argInit_Unboundedx1_real_T();

  /* Call the entry-point 'aevSPLap'. */
  aevSPLap(NumTOp_tmp, NumTOp_tmp, numIQ, taxC_tmp, taxC_tmp, taxEQ, NumRec,
           PCPrO, PME, PMA, PMAn, PS, PCPO, PCR, Dia, Data, TimeUsoRec, ProbXEst,
           fitnessB, generations, genToWidth, DispMExD, EP, argInit_real_T(),
           argInit_real_T(), argInit_real_T(), argInit_real_T(), bestexperimento,
           trace);
  emxDestroyArray_real_T(trace);
  emxDestroyArray_int32_T(bestexperimento);
  emxDestroyArray_real_T(EP);
  emxDestroyArray_int32_T(DispMExD);
  emxDestroyArray_int32_T(TimeUsoRec);
  emxDestroyArray_int32_T(Data);
  emxDestroyArray_int32_T(Dia);
  emxDestroyArray_int32_T(PCR);
  emxDestroyArray_int32_T(PCPO);
  emxDestroyArray_int32_T(PS);
  emxDestroyArray_int32_T(PMAn);
  emxDestroyArray_int32_T(PMA);
  emxDestroyArray_int32_T(PME);
  emxDestroyArray_int32_T(PCPrO);
}

static void main_casorandom(void)
{
  emxArray_int32_T *schedule;
  emxArray_int32_T *DiaOp;
  emxArray_int32_T *EspMedOp;
  int NumTOp;
  emxArray_int32_T *H;
  int NumRec[7];
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *PME;
  emxArray_int32_T *PMA;
  emxArray_int32_T *PMAn;
  emxArray_int32_T *PS;
  emxArray_int32_T *PCPO;
  emxArray_int32_T *PCR;
  emxArray_int32_T *Dia;
  emxArray_int32_T *UltPosRecXDia;
  emxArray_int32_T *TimeUsoRec;
  emxArray_int32_T *DispMExD;
  emxInitArray_int32_T(&schedule, 2);
  emxInitArray_int32_T(&DiaOp, 1);
  emxInitArray_int32_T(&EspMedOp, 2);

  /* Initialize function 'casorandom' input arguments. */
  NumTOp = argInit_int32_T();

  /* Initialize function input argument 'H'. */
  H = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'NumRec'. */
  argInit_1x7_int32_T(NumRec);

  /* Initialize function input argument 'PCPrO'. */
  PCPrO = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PME'. */
  PME = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PMA'. */
  PMA = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PMAn'. */
  PMAn = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PS'. */
  PS = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PCPO'. */
  PCPO = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PCR'. */
  PCR = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'Dia'. */
  Dia = argInit_Unboundedx4_int32_T();

  /* Initialize function input argument 'UltPosRecXDia'. */
  UltPosRecXDia = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'TimeUsoRec'. */
  TimeUsoRec = argInit_Unboundedx7_int32_T();

  /* Initialize function input argument 'DispMExD'. */
  DispMExD = argInit_6xUnbounded_int32_T();

  /* Call the entry-point 'casorandom'. */
  casorandom(NumTOp, H, NumRec, PCPrO, PME, PMA, PMAn, PS, PCPO, PCR, Dia,
             UltPosRecXDia, TimeUsoRec, DispMExD, schedule, DiaOp, EspMedOp);
  emxDestroyArray_int32_T(EspMedOp);
  emxDestroyArray_int32_T(DiaOp);
  emxDestroyArray_int32_T(schedule);
  emxDestroyArray_int32_T(DispMExD);
  emxDestroyArray_int32_T(TimeUsoRec);
  emxDestroyArray_int32_T(UltPosRecXDia);
  emxDestroyArray_int32_T(Dia);
  emxDestroyArray_int32_T(PCR);
  emxDestroyArray_int32_T(PCPO);
  emxDestroyArray_int32_T(PS);
  emxDestroyArray_int32_T(PMAn);
  emxDestroyArray_int32_T(PMA);
  emxDestroyArray_int32_T(PME);
  emxDestroyArray_int32_T(PCPrO);
  emxDestroyArray_int32_T(H);
}

static void main_cc(void)
{
  emxArray_int32_T *newIC;
  emxArray_int32_T *IC;
  emxInitArray_int32_T(&newIC, 2);

  /* Initialize function 'cc' input arguments. */
  /* Initialize function input argument 'IC'. */
  IC = c_argInit_UnboundedxUnbounded_i();

  /* Call the entry-point 'cc'. */
  cc(IC, argInit_int32_T(), argInit_real_T(), argInit_int32_T(), newIC);
  emxDestroyArray_int32_T(newIC);
  emxDestroyArray_int32_T(IC);
}

static void main_favalia(void)
{
  emxArray_int32_T *schedule;
  emxArray_int32_T *DiaOp;
  emxArray_int32_T *EP;
  emxArray_int32_T *EspMedOp;
  double fitness;
  double Tt;
  double NOFP;
  double TmNOFP;
  double NOE2;
  double NOE3;

  /* Initialize function 'favalia' input arguments. */
  /* Initialize function input argument 'schedule'. */
  schedule = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'DiaOp'. */
  DiaOp = argInit_Unboundedx1_int32_T();

  /* Initialize function input argument 'EP'. */
  EP = argInit_Unboundedx1_int32_T();

  /* Initialize function input argument 'EspMedOp'. */
  EspMedOp = argInit_Unboundedx2_int32_T();

  /* Call the entry-point 'favalia'. */
  favalia(schedule, DiaOp, EP, EspMedOp, argInit_real_T(), argInit_real_T(),
          argInit_real_T(), argInit_real_T(), &fitness, &Tt, &NOFP, &TmNOFP,
          &NOE2, &NOE3);
  emxDestroyArray_int32_T(EspMedOp);
  emxDestroyArray_int32_T(EP);
  emxDestroyArray_int32_T(DiaOp);
  emxDestroyArray_int32_T(schedule);
}

static void main_funcionC(void)
{
  emxArray_int32_T *PCPO;
  emxArray_int32_T *PCR;
  emxArray_int32_T *H;
  int EndRP_tmp;
  int TimeUsoCR;
  emxArray_int32_T *PME;
  emxArray_int32_T *PMA;
  emxArray_int32_T *PMAn;
  emxArray_int32_T *PS;
  int CPrOA;
  int IniCPrOA;
  int EndCPrOA;
  int EndCPrOAxD;
  int NumRec[7];
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *Dia;
  emxArray_int32_T *UltPosRecXDia;
  int TimeUsoCPrO;
  int TimeUsoS;
  int contDia;
  emxArray_int32_T *filCPrO;
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *EA;
  emxArray_int32_T *SA;
  emxArray_int32_T *AA;
  emxArray_int32_T *AnA;
  int IniRP;
  int EndRPxD;
  emxArray_int32_T *DispMExD;
  emxArray_int32_T *DispME;
  emxArray_int32_T *uCPrODisp;
  double CPOA;
  int IniCPO;
  int EndCPO;
  double CRA;
  int IniCR;
  int EndCR;

  /* Initialize function 'funcionC' input arguments. */
  /* Initialize function input argument 'PCPO'. */
  PCPO = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'PCR'. */
  PCR = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'H'. */
  H = c_argInit_UnboundedxUnbounded_i();
  EndRP_tmp = argInit_int32_T();
  TimeUsoCR = argInit_int32_T();

  /* Initialize function input argument 'PME'. */
  PME = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'PMA'. */
  PMA = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'PMAn'. */
  PMAn = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'PS'. */
  PS = argInit_1xUnbounded_int32_T();
  CPrOA = argInit_int32_T();
  IniCPrOA = argInit_int32_T();
  EndCPrOA = argInit_int32_T();
  EndCPrOAxD = argInit_int32_T();

  /* Initialize function input argument 'NumRec'. */
  argInit_1x7_int32_T(NumRec);

  /* Initialize function input argument 'PCPrO'. */
  PCPrO = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'Dia'. */
  Dia = argInit_Unboundedx4_int32_T();

  /* Initialize function input argument 'UltPosRecXDia'. */
  UltPosRecXDia = c_argInit_UnboundedxUnbounded_i();
  TimeUsoCPrO = argInit_int32_T();
  TimeUsoS = argInit_int32_T();
  contDia = argInit_int32_T();

  /* Initialize function input argument 'filCPrO'. */
  filCPrO = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'tempUltPosRecXDia'. */
  tempUltPosRecXDia = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'EA'. */
  EA = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'SA'. */
  SA = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'AA'. */
  AA = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'AnA'. */
  AnA = argInit_1xUnbounded_int32_T();
  IniRP = argInit_int32_T();
  EndRPxD = argInit_int32_T();

  /* Initialize function input argument 'DispMExD'. */
  DispMExD = argInit_6xUnbounded_int32_T();

  /* Initialize function input argument 'DispME'. */
  DispME = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'uCPrODisp'. */
  uCPrODisp = argInit_1xUnbounded_int32_T();

  /* Call the entry-point 'funcionC'. */
  funcionC(PCPO, PCR, H, &EndRP_tmp, EndRP_tmp, TimeUsoCR, PME, PMA, PMAn, PS,
           &CPrOA, &IniCPrOA, &EndCPrOA, &EndCPrOAxD, NumRec, PCPrO, Dia,
           UltPosRecXDia, TimeUsoCPrO, TimeUsoS, &contDia, filCPrO,
           tempUltPosRecXDia, EA, SA, AA, AnA, &IniRP, &EndRPxD, DispMExD,
           DispME, uCPrODisp, &CPOA, &IniCPO, &EndCPO, &CRA, &IniCR, &EndCR);
  emxDestroyArray_int32_T(uCPrODisp);
  emxDestroyArray_int32_T(DispME);
  emxDestroyArray_int32_T(DispMExD);
  emxDestroyArray_int32_T(AnA);
  emxDestroyArray_int32_T(AA);
  emxDestroyArray_int32_T(SA);
  emxDestroyArray_int32_T(EA);
  emxDestroyArray_int32_T(tempUltPosRecXDia);
  emxDestroyArray_int32_T(filCPrO);
  emxDestroyArray_int32_T(UltPosRecXDia);
  emxDestroyArray_int32_T(Dia);
  emxDestroyArray_int32_T(PCPrO);
  emxDestroyArray_int32_T(PS);
  emxDestroyArray_int32_T(PMAn);
  emxDestroyArray_int32_T(PMA);
  emxDestroyArray_int32_T(PME);
  emxDestroyArray_int32_T(H);
  emxDestroyArray_int32_T(PCR);
  emxDestroyArray_int32_T(PCPO);
}

static void main_funcionCPrO(void)
{
  emxArray_int32_T *EA;
  emxArray_int32_T *AA;
  emxArray_int32_T *AnA;
  emxArray_int32_T *SA;
  int NumRec[7];
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *PME;
  emxArray_int32_T *PMA;
  emxArray_int32_T *PMAn;
  emxArray_int32_T *PS;
  emxArray_int32_T *PCPO;
  emxArray_int32_T *PCR;
  emxArray_int32_T *H;
  emxArray_int32_T *Dia;
  emxArray_int32_T *UltPosRecXDia;
  int TimeUsoCPrO_tmp;
  int TimeUsoCPO;
  int TimeUsoCR;
  int contDia;
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *DispMExD;
  emxArray_int32_T *DispME;
  int CPrOA;
  int IniCPrOA;
  int EndCPrOA;
  int EndCPrOAxD;
  int IniSA;
  int EndSA;
  int EndRPxD;
  int CPOA;
  int IniCPOA;
  int EndCPOA;
  int CRA;
  int IniCRA;
  int EndCRA;
  emxInitArray_int32_T(&EA, 2);
  emxInitArray_int32_T(&AA, 2);
  emxInitArray_int32_T(&AnA, 2);
  emxInitArray_int32_T(&SA, 2);

  /* Initialize function 'funcionCPrO' input arguments. */
  /* Initialize function input argument 'NumRec'. */
  argInit_1x7_int32_T(NumRec);

  /* Initialize function input argument 'PCPrO'. */
  PCPrO = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'PME'. */
  PME = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'PMA'. */
  PMA = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'PMAn'. */
  PMAn = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'PS'. */
  PS = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'PCPO'. */
  PCPO = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'PCR'. */
  PCR = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'H'. */
  H = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'Dia'. */
  Dia = argInit_Unboundedx4_int32_T();

  /* Initialize function input argument 'UltPosRecXDia'. */
  UltPosRecXDia = c_argInit_UnboundedxUnbounded_i();
  TimeUsoCPrO_tmp = argInit_int32_T();
  TimeUsoCPO = argInit_int32_T();
  TimeUsoCR = argInit_int32_T();
  contDia = argInit_int32_T();

  /* Initialize function input argument 'tempUltPosRecXDia'. */
  tempUltPosRecXDia = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'DispMExD'. */
  DispMExD = argInit_6xUnbounded_int32_T();

  /* Initialize function input argument 'DispME'. */
  DispME = argInit_1xUnbounded_int32_T();

  /* Call the entry-point 'funcionCPrO'. */
  funcionCPrO(NumRec, PCPrO, PME, PMA, PMAn, PS, PCPO, PCR, H, Dia,
              UltPosRecXDia, TimeUsoCPrO_tmp, TimeUsoCPrO_tmp, TimeUsoCPO,
              TimeUsoCR, &contDia, tempUltPosRecXDia, DispMExD, DispME, &CPrOA,
              &IniCPrOA, &EndCPrOA, &EndCPrOAxD, EA, AA, AnA, SA, &IniSA, &EndSA,
              &EndRPxD, &CPOA, &IniCPOA, &EndCPOA, &CRA, &IniCRA, &EndCRA);
  emxDestroyArray_int32_T(SA);
  emxDestroyArray_int32_T(AnA);
  emxDestroyArray_int32_T(AA);
  emxDestroyArray_int32_T(EA);
  emxDestroyArray_int32_T(DispME);
  emxDestroyArray_int32_T(DispMExD);
  emxDestroyArray_int32_T(tempUltPosRecXDia);
  emxDestroyArray_int32_T(UltPosRecXDia);
  emxDestroyArray_int32_T(Dia);
  emxDestroyArray_int32_T(H);
  emxDestroyArray_int32_T(PCR);
  emxDestroyArray_int32_T(PCPO);
  emxDestroyArray_int32_T(PS);
  emxDestroyArray_int32_T(PMAn);
  emxDestroyArray_int32_T(PMA);
  emxDestroyArray_int32_T(PME);
  emxDestroyArray_int32_T(PCPrO);
}

static void main_funcionCR(void)
{
  /* Call the entry-point 'funcionCR'. */
  funcionCR();
}

static void main_funcionDia(void)
{
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *DispME;
  int NumRec[7];
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *Dia;
  emxArray_int32_T *UltPosRecXDia;
  int TimeUsoCPrO_tmp;
  int contDia;
  emxArray_int32_T *DispMExD;
  emxInitArray_int32_T(&tempUltPosRecXDia, 2);
  emxInitArray_int32_T(&DispME, 2);

  /* Initialize function 'funcionDia' input arguments. */
  /* Initialize function input argument 'NumRec'. */
  argInit_1x7_int32_T(NumRec);

  /* Initialize function input argument 'PCPrO'. */
  PCPrO = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'Dia'. */
  Dia = argInit_Unboundedx4_int32_T();

  /* Initialize function input argument 'UltPosRecXDia'. */
  UltPosRecXDia = c_argInit_UnboundedxUnbounded_i();
  TimeUsoCPrO_tmp = argInit_int32_T();
  contDia = argInit_int32_T();

  /* Initialize function input argument 'DispMExD'. */
  DispMExD = argInit_6xUnbounded_int32_T();

  /* Call the entry-point 'funcionDia'. */
  funcionDia(NumRec, PCPrO, Dia, UltPosRecXDia, TimeUsoCPrO_tmp, TimeUsoCPrO_tmp,
             &contDia, DispMExD, tempUltPosRecXDia, DispME);
  emxDestroyArray_int32_T(DispME);
  emxDestroyArray_int32_T(tempUltPosRecXDia);
  emxDestroyArray_int32_T(DispMExD);
  emxDestroyArray_int32_T(UltPosRecXDia);
  emxDestroyArray_int32_T(Dia);
  emxDestroyArray_int32_T(PCPrO);
}

static void main_funcionRP(void)
{
  emxArray_int32_T *EA;
  emxArray_int32_T *AA;
  emxArray_int32_T *AnA;
  emxArray_int32_T *CPrOA;
  int IniCPrOA_tmp;
  int EndCPrOAxD;
  emxArray_int32_T *SA;
  int IniSA;
  int EndSA;
  emxArray_int32_T *CPOA;
  int IniCPOA;
  int EndCPOA;
  emxArray_int32_T *CRA;
  int IniCRA;
  int EndCRA;
  int NumRec[7];
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *PME;
  emxArray_int32_T *PMA;
  emxArray_int32_T *PMAn;
  emxArray_int32_T *PS;
  emxArray_int32_T *PCPO;
  emxArray_int32_T *PCR;
  emxArray_real_T *H;
  emxArray_int32_T *Dia;
  emxArray_int32_T *UltPosRecXDia;
  int TimeUsoCPrO;
  int TimeUsoS;
  int TimeUsoCPO;
  int TimeUsoCR;
  int contDia;
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *DispMExD;
  emxArray_int32_T *DispME;
  int EndCPrOA;
  int EndRPxD;
  emxInitArray_int32_T(&EA, 2);
  emxInitArray_int32_T(&AA, 2);
  emxInitArray_int32_T(&AnA, 2);

  /* Initialize function 'funcionRP' input arguments. */
  /* Initialize function input argument 'CPrOA'. */
  CPrOA = argInit_1xUnbounded_int32_T();
  IniCPrOA_tmp = argInit_int32_T();
  EndCPrOAxD = argInit_int32_T();

  /* Initialize function input argument 'SA'. */
  SA = argInit_1xUnbounded_int32_T();
  IniSA = argInit_int32_T();
  EndSA = argInit_int32_T();

  /* Initialize function input argument 'CPOA'. */
  CPOA = argInit_1xUnbounded_int32_T();
  IniCPOA = argInit_int32_T();
  EndCPOA = argInit_int32_T();

  /* Initialize function input argument 'CRA'. */
  CRA = argInit_1xUnbounded_int32_T();
  IniCRA = argInit_int32_T();
  EndCRA = argInit_int32_T();

  /* Initialize function input argument 'NumRec'. */
  argInit_1x7_int32_T(NumRec);

  /* Initialize function input argument 'PCPrO'. */
  PCPrO = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'PME'. */
  PME = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'PMA'. */
  PMA = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'PMAn'. */
  PMAn = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'PS'. */
  PS = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'PCPO'. */
  PCPO = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'PCR'. */
  PCR = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'H'. */
  H = c_argInit_UnboundedxUnbounded_r();

  /* Initialize function input argument 'Dia'. */
  Dia = argInit_Unboundedx4_int32_T();

  /* Initialize function input argument 'UltPosRecXDia'. */
  UltPosRecXDia = c_argInit_UnboundedxUnbounded_i();
  TimeUsoCPrO = argInit_int32_T();
  TimeUsoS = argInit_int32_T();
  TimeUsoCPO = argInit_int32_T();
  TimeUsoCR = argInit_int32_T();
  contDia = argInit_int32_T();

  /* Initialize function input argument 'tempUltPosRecXDia'. */
  tempUltPosRecXDia = argInit_1xUnbounded_int32_T();

  /* Initialize function input argument 'DispMExD'. */
  DispMExD = argInit_6xUnbounded_int32_T();

  /* Initialize function input argument 'DispME'. */
  DispME = argInit_1xUnbounded_int32_T();

  /* Call the entry-point 'funcionRP'. */
  EndCPrOA = IniCPrOA_tmp;
  funcionRP(CPrOA, &IniCPrOA_tmp, &EndCPrOA, &EndCPrOAxD, SA, &IniSA, &EndSA,
            CPOA, &IniCPOA, &EndCPOA, CRA, &IniCRA, &EndCRA, NumRec, PCPrO, PME,
            PMA, PMAn, PS, PCPO, PCR, H, Dia, UltPosRecXDia, TimeUsoCPrO,
            TimeUsoS, TimeUsoCPO, TimeUsoCR, &contDia, tempUltPosRecXDia,
            DispMExD, DispME, EA, AA, AnA, &EndRPxD);
  emxDestroyArray_int32_T(AnA);
  emxDestroyArray_int32_T(AA);
  emxDestroyArray_int32_T(EA);
  emxDestroyArray_int32_T(DispME);
  emxDestroyArray_int32_T(DispMExD);
  emxDestroyArray_int32_T(tempUltPosRecXDia);
  emxDestroyArray_int32_T(UltPosRecXDia);
  emxDestroyArray_int32_T(Dia);
  emxDestroyArray_real_T(H);
  emxDestroyArray_int32_T(PCR);
  emxDestroyArray_int32_T(PCPO);
  emxDestroyArray_int32_T(PS);
  emxDestroyArray_int32_T(PMAn);
  emxDestroyArray_int32_T(PMA);
  emxDestroyArray_int32_T(PME);
  emxDestroyArray_int32_T(PCPrO);
  emxDestroyArray_int32_T(CRA);
  emxDestroyArray_int32_T(CPOA);
  emxDestroyArray_int32_T(SA);
  emxDestroyArray_int32_T(CPrOA);
}

static void main_main_UCI_func(void)
{
  /* Call the entry-point 'main_UCI_func'. */
  main_UCI_func();
}

static void main_obsIQ(void)
{
  emxArray_int32_T *newIC;
  emxArray_real_T *IQ;
  emxInitArray_int32_T(&newIC, 2);

  /* Initialize function 'obsIQ' input arguments. */
  /* Initialize function input argument 'IQ'. */
  IQ = c_argInit_UnboundedxUnbounded_r();

  /* Call the entry-point 'obsIQ'. */
  obsIQ(IQ, argInit_int32_T(), argInit_int32_T(), newIC);
  emxDestroyArray_int32_T(newIC);
  emxDestroyArray_real_T(IQ);
}

static void main_obsIQini(void)
{
  emxArray_real_T *newIC;
  emxArray_real_T *IQ;
  double dv7[5];
  emxInitArray_real_T(&newIC, 2);

  /* Initialize function 'obsIQini' input arguments. */
  /* Initialize function input argument 'IQ'. */
  IQ = c_argInit_UnboundedxUnbounded_r();

  /* Initialize function input argument 'ProbXEst'. */
  /* Call the entry-point 'obsIQini'. */
  argInit_5x1_real_T(dv7);
  obsIQini(IQ, argInit_int32_T(), argInit_int32_T(), dv7, newIC);
  emxDestroyArray_real_T(newIC);
  emxDestroyArray_real_T(IQ);
}

static void main_sch(void)
{
  int NumTOp;
  emxArray_int32_T *list;
  int NumRec[7];
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *PME;
  emxArray_int32_T *PMA;
  emxArray_int32_T *PMAn;
  emxArray_int32_T *PS;
  emxArray_int32_T *PCPO;
  emxArray_int32_T *PCR;
  emxArray_int32_T *Dia;
  emxArray_int32_T *Data;
  emxArray_int32_T *TimeUsoRec;
  emxArray_int32_T *DispMExD;
  emxArray_int32_T *EP;
  double fitness;
  double Tt;
  double NOFP;
  double TmNOFP;
  double NOE2;
  double NOE3;

  /* Initialize function 'sch' input arguments. */
  NumTOp = argInit_int32_T();

  /* Initialize function input argument 'list'. */
  list = argInit_Unboundedx1_int32_T();

  /* Initialize function input argument 'NumRec'. */
  argInit_1x7_int32_T(NumRec);

  /* Initialize function input argument 'PCPrO'. */
  PCPrO = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PME'. */
  PME = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PMA'. */
  PMA = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PMAn'. */
  PMAn = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PS'. */
  PS = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PCPO'. */
  PCPO = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'PCR'. */
  PCR = c_argInit_UnboundedxUnbounded_i();

  /* Initialize function input argument 'Dia'. */
  Dia = argInit_Unboundedx4_int32_T();

  /* Initialize function input argument 'Data'. */
  Data = argInit_Unboundedx5_int32_T();

  /* Initialize function input argument 'TimeUsoRec'. */
  TimeUsoRec = argInit_Unboundedx7_int32_T();

  /* Initialize function input argument 'DispMExD'. */
  DispMExD = argInit_Unboundedx1_int32_T();

  /* Initialize function input argument 'EP'. */
  EP = argInit_Unboundedx1_int32_T();

  /* Call the entry-point 'sch'. */
  sch(NumTOp, list, NumRec, PCPrO, PME, PMA, PMAn, PS, PCPO, PCR, Dia, Data,
      TimeUsoRec, DispMExD, EP, argInit_real_T(), argInit_real_T(),
      argInit_real_T(), argInit_real_T(), &fitness, &Tt, &NOFP, &TmNOFP, &NOE2,
      &NOE3);
  emxDestroyArray_int32_T(EP);
  emxDestroyArray_int32_T(DispMExD);
  emxDestroyArray_int32_T(TimeUsoRec);
  emxDestroyArray_int32_T(Data);
  emxDestroyArray_int32_T(Dia);
  emxDestroyArray_int32_T(PCR);
  emxDestroyArray_int32_T(PCPO);
  emxDestroyArray_int32_T(PS);
  emxDestroyArray_int32_T(PMAn);
  emxDestroyArray_int32_T(PMA);
  emxDestroyArray_int32_T(PME);
  emxDestroyArray_int32_T(PCPrO);
  emxDestroyArray_int32_T(list);
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
  //main_actIQ();
  //main_aevSPLap();
  //main_BDCreator_func();
  //main_Calendario();
  //main_casorandom();
  //main_cc();
  //main_Codificacion_de_dias_func();
  //main_CreaPoQunniforme();
  //main_Edade();
  //main_favalia();
  //main_funcionC();
  //main_funcionCPrO();
  //main_funcionCR();
  //main_funcionDia();
  //main_funcionRP();
  main_main_UCI_func();
  //main_obsIQ();
  //main_obsIQini();
  //main_PLOTT_func();
  //main_sch();

  /* Terminate the application.
     You do not need to do this more than one time. */
  model_terminate();
  return 0;
}

/* End of code generation (main.c) */
