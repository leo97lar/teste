/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * actIQ.c
 *
 * Code generation for function 'actIQ'
 *
 */

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
#include "model_emxutil.h"

/* Function Definitions */
void actIQ(const emxArray_real_T *IQ, const emxArray_int32_T *IC, double taxAct,
           emxArray_real_T *IQact)
{
  int i0;
  int loop_ub;

  /* UNTITLED5 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /* Convertir de numerico a representacion binaria. */
  i0 = IQact->size[0] * IQact->size[1];
  IQact->size[0] = (int)((double)IC->size[0] * (double)IC->size[1]);
  IQact->size[1] = IC->size[0];
  emxEnsureCapacity_real_T(IQact, i0);
  loop_ub = (int)((double)IC->size[0] * (double)IC->size[1]) * IC->size[0];
  for (i0 = 0; i0 < loop_ub; i0++) {
    IQact->data[i0] = 0.0;
  }

  i0 = (int)((double)IC->size[0] * (double)IC->size[1]);
  for (loop_ub = 0; loop_ub < i0; loop_ub++) {
    IQact->data[loop_ub + IQact->size[0] * (IC->data[loop_ub] - 1)] = 1.0;
  }

  i0 = IQ->size[0] * IQ->size[1];
  loop_ub = IQact->size[0] * IQact->size[1];
  IQact->size[0] = IQ->size[0];
  IQact->size[1] = IQ->size[1];
  emxEnsureCapacity_real_T(IQact, loop_ub);
  loop_ub = i0 - 1;
  for (i0 = 0; i0 <= loop_ub; i0++) {
    IQact->data[i0] = (1.0 - taxAct) * IQ->data[i0] + taxAct * IQact->data[i0];
  }
}

void b_actIQ(const emxArray_real_T *IQ, const emxArray_int32_T *IC,
             emxArray_real_T *IQact)
{
  int i25;
  int loop_ub;

  /* UNTITLED5 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /* Convertir de numerico a representacion binaria. */
  i25 = IQact->size[0] * IQact->size[1];
  IQact->size[0] = (int)((double)IC->size[0] * (double)IC->size[1]);
  IQact->size[1] = IC->size[0];
  emxEnsureCapacity_real_T(IQact, i25);
  loop_ub = (int)((double)IC->size[0] * (double)IC->size[1]) * IC->size[0];
  for (i25 = 0; i25 < loop_ub; i25++) {
    IQact->data[i25] = 0.0;
  }

  i25 = (int)((double)IC->size[0] * (double)IC->size[1]);
  for (loop_ub = 0; loop_ub < i25; loop_ub++) {
    IQact->data[loop_ub + IQact->size[0] * (IC->data[loop_ub] - 1)] = 1.0;
  }

  i25 = IQ->size[0] * IQ->size[1];
  loop_ub = IQact->size[0] * IQact->size[1];
  IQact->size[0] = IQ->size[0];
  IQact->size[1] = IQ->size[1];
  emxEnsureCapacity_real_T(IQact, loop_ub);
  loop_ub = i25 - 1;
  for (i25 = 0; i25 <= loop_ub; i25++) {
    IQact->data[i25] = 0.99999 * IQ->data[i25] + 1.0E-5 * IQact->data[i25];
  }
}

/* End of code generation (actIQ.c) */
