/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: aevSPLap.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

#ifndef AEVSPLAP_H
#define AEVSPLAP_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void aevSPLap(int NumTOp, int numIC, int numIQ, double taxC, double taxE,
                     const int NumRec[7], const emxArray_int32_T *PCPrO, const
                     emxArray_int32_T *PME, const emxArray_int32_T *PMA, const
                     emxArray_int32_T *PMAn, const emxArray_int32_T *PS, const
                     emxArray_int32_T *PCPO, const emxArray_int32_T *PCR, const
                     emxArray_int32_T *Dia, const emxArray_int32_T *Data, const
                     emxArray_int32_T *TimeUsoRec, const emxArray_real_T
                     *ProbXEst, const double fitnessB[6], int generations, int
                     genToWidth, const emxArray_int32_T *DispMExD, const
                     emxArray_int32_T *EP, double k0, double k1, double k2,
                     double k3, boolean_T keeppriority, emxArray_int32_T
                     *bestexperimento, emxArray_real_T *trace, char* schedule_path, char* results_path);

#endif

/*
 * File trailer for aevSPLap.h
 *
 * [EOF]
 */
