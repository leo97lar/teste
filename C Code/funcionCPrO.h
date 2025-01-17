/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: funcionCPrO.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

#ifndef FUNCIONCPRO_H
#define FUNCIONCPRO_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void funcionCPrO(const int NumRec[7], const emxArray_int32_T *PCPrO,
  const emxArray_int32_T *PME, const emxArray_int32_T *PMA, const
  emxArray_int32_T *PMAn, const emxArray_int32_T *PS, const emxArray_int32_T
  *PCPO, const emxArray_int32_T *PCR, const emxArray_int32_T *H, const
  emxArray_int32_T *Dia, const emxArray_int32_T *UltPosRecXDia, int TimeUsoCPrO,
  int TimeUsoS, int TimeUsoCPO, int TimeUsoCR, int *contDia, emxArray_int32_T
  *tempUltPosRecXDia, const emxArray_int32_T *DispMExD, emxArray_int32_T *DispME,
  int *CPrOA, int *IniCPrOA, int *EndCPrOA, int *EndCPrOAxD, emxArray_int32_T
  *EA, emxArray_int32_T *AA, emxArray_int32_T *AnA, emxArray_int32_T *SA, int
  *IniSA, int *EndSA, int *EndRPxD, int *CPOA, int *IniCPOA, int *EndCPOA, int
  *CRA, int *IniCRA, int *EndCRA);

#endif

/*
 * File trailer for funcionCPrO.h
 *
 * [EOF]
 */
