/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sch.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

#ifndef SCH_H
#define SCH_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void sch(int NumTOp, const emxArray_int32_T *list, const int NumRec[7],
                emxArray_int32_T *PCPrO, emxArray_int32_T *PME, emxArray_int32_T
                *PMA, emxArray_int32_T *PMAn, emxArray_int32_T *PS,
                emxArray_int32_T *PCPO, emxArray_int32_T *PCR, const
                emxArray_int32_T *Dia, const emxArray_int32_T *Data,
                emxArray_int32_T *TimeUsoRec, const emxArray_int32_T *DispMExD,
                emxArray_int32_T *EP, double k0, double k1, double k2, double k3,
                double *fitness, double *Tt, double *NOFP, double *TmNOFP,
                double *NOE2, double *NOE3, bool printSchedule);

#endif

/*
 * File trailer for sch.h
 *
 * [EOF]
 */
