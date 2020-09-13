/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * aevSPLap.h
 *
 * Code generation for function 'aevSPLap'
 *
 */

#ifndef AEVSPLAP_H
#define AEVSPLAP_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void aevSPLap(int NumTOp, int numIC, int numIQ, double taxC, double taxE,
                     double taxEQ, const int NumRec[7], const emxArray_int32_T
                     *PCPrO, const emxArray_int32_T *PME, const emxArray_int32_T
                     *PMA, const emxArray_int32_T *PMAn, const emxArray_int32_T *
                     PS, const emxArray_int32_T *PCPO, const emxArray_int32_T
                     *PCR, const emxArray_int32_T *Dia, const emxArray_int32_T
                     *Data, const emxArray_int32_T *TimeUsoRec, const double
                     ProbXEst[5], const double fitnessB[6], int generations, int
                     genToWidth, const emxArray_int32_T *DispMExD, const
                     emxArray_real_T *EP, double k0, double k1, double k2,
                     double k3, emxArray_int32_T *bestexperimento,
                     emxArray_real_T *trace);
extern void b_aevSPLap(int NumTOp, const int NumRec[7], const emxArray_int32_T
  *PCPrO, const emxArray_int32_T *PME, const emxArray_int32_T *PMA, const
  emxArray_int32_T *PMAn, const emxArray_int32_T *PS, const emxArray_int32_T
  *PCPO, const emxArray_int32_T *PCR, const int Dia_data[], const int Dia_size[2],
  const int TimeUsoRec_data[], const double fitnessB[6], const int
  DispMExD_data[], const int DispMExD_size[2], const int EP_data[], int
  bestexperimento_data[], int bestexperimento_size[1], double trace[9]);

#endif

/* End of code generation (aevSPLap.h) */
