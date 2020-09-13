/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: funcionDia.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 18:10:16
 */

#ifndef FUNCIONDIA_H
#define FUNCIONDIA_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void funcionDia(const int NumRec[7], const emxArray_int32_T *PCPrO, const
  emxArray_int32_T *Dia, const emxArray_int32_T *UltPosRecXDia, int TimeUsoCPrO,
  int TimeUsoS, int *contDia, const emxArray_int32_T *DispMExD, emxArray_int32_T
  *tempUltPosRecXDia, emxArray_int32_T *DispME);

#endif

/*
 * File trailer for funcionDia.h
 *
 * [EOF]
 */
