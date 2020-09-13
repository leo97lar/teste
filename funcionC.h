/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * funcionC.h
 *
 * Code generation for function 'funcionC'
 *
 */

#ifndef FUNCIONC_H
#define FUNCIONC_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void funcionC(const emxArray_int32_T *PCPO, const emxArray_int32_T *PCR,
                     const emxArray_int32_T *H, const int *EndRP, int TimeUsoCPO,
                     int TimeUsoCR, const emxArray_int32_T *PME, const
                     emxArray_int32_T *PMA, const emxArray_int32_T *PMAn, const
                     emxArray_int32_T *PS, const int *CPrOA, const int *IniCPrOA,
                     const int *EndCPrOA, const int *EndCPrOAxD, const int
                     NumRec[7], const emxArray_int32_T *PCPrO, const
                     emxArray_int32_T *Dia, const emxArray_int32_T
                     *UltPosRecXDia, int TimeUsoCPrO, int TimeUsoS, const int
                     *contDia, const emxArray_int32_T *filCPrO, const
                     emxArray_int32_T *tempUltPosRecXDia, const emxArray_int32_T
                     *EA, const emxArray_int32_T *SA, const emxArray_int32_T *AA,
                     const emxArray_int32_T *AnA, const int *IniRP, const int
                     *EndRPxD, const emxArray_int32_T *DispMExD, const
                     emxArray_int32_T *DispME, const emxArray_int32_T *uCPrODisp,
                     double *CPOA, int *IniCPO, int *EndCPO, double *CRA, int
                     *IniCR, int *EndCR);

#endif

/* End of code generation (funcionC.h) */
