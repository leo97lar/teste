/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main_UCI_func.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 18:10:16
 */

#ifndef MAIN_UCI_FUNC_H
#define MAIN_UCI_FUNC_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void main_UCI_func(const emxArray_int32_T *CP, const emxArray_int32_T *RO,
  const emxArray_int32_T *CPO, const emxArray_int32_T *CPrO, const
  emxArray_int32_T *CR, const emxArray_int32_T *Data, const emxArray_int32_T
  *Dia, const emxArray_int32_T *DispMExD, const emxArray_int32_T *MA, const
  emxArray_int32_T *MAn, const emxArray_int32_T *ME, const emxArray_int32_T *S,
  int TipoOp, int NumEsp, int NumTOp, int NumSalOp, int NumCPO, int NumCPrO, int
  NumCR, int NumMedEsp, int NumEspxE, int NumAsist, int NumAnest, double k0,
  double k1, double k2, double k3, int numIQ, int numIC, double taxC, double
  taxE, double taxEQ, const emxArray_real_T *ProbXEst, int genToWidth, int
  generations, boolean_T keeppriority);

#endif

/*
 * File trailer for main_UCI_func.h
 *
 * [EOF]
 */
