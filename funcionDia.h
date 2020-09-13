/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * funcionDia.h
 *
 * Code generation for function 'funcionDia'
 *
 */

#ifndef FUNCIONDIA_H
#define FUNCIONDIA_H

/* Include files */
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

/* End of code generation (funcionDia.h) */
