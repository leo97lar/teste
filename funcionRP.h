/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * funcionRP.h
 *
 * Code generation for function 'funcionRP'
 *
 */

#ifndef FUNCIONRP_H
#define FUNCIONRP_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void funcionRP(emxArray_int32_T *CPrOA, int *IniCPrOA, int *EndCPrOA, int
                      *EndCPrOAxD, emxArray_int32_T *SA, int *IniSA, int *EndSA,
                      emxArray_int32_T *CPOA, int *IniCPOA, int *EndCPOA,
                      emxArray_int32_T *CRA, int *IniCRA, int *EndCRA, const int
                      NumRec[7], const emxArray_int32_T *PCPrO, const
                      emxArray_int32_T *PME, const emxArray_int32_T *PMA, const
                      emxArray_int32_T *PMAn, const emxArray_int32_T *PS, const
                      emxArray_int32_T *PCPO, const emxArray_int32_T *PCR, const
                      emxArray_real_T *H, const emxArray_int32_T *Dia, const
                      emxArray_int32_T *UltPosRecXDia, int TimeUsoCPrO, int
                      TimeUsoS, int TimeUsoCPO, int TimeUsoCR, int *contDia,
                      const emxArray_int32_T *tempUltPosRecXDia, const
                      emxArray_int32_T *DispMExD, const emxArray_int32_T *DispME,
                      emxArray_int32_T *EA, emxArray_int32_T *AA,
                      emxArray_int32_T *AnA, int *EndRPxD);

#endif

/* End of code generation (funcionRP.h) */
