/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sch.h
 *
 * Code generation for function 'sch'
 *
 */

#ifndef SCH_H
#define SCH_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void b_sch(int NumTOp, const emxArray_int32_T *list, const int NumRec[7],
                  emxArray_int32_T *PCPrO, emxArray_int32_T *PME,
                  emxArray_int32_T *PMA, emxArray_int32_T *PMAn,
                  emxArray_int32_T *PS, emxArray_int32_T *PCPO, emxArray_int32_T
                  *PCR, const emxArray_int32_T *Dia, const emxArray_int32_T
                  *Data, emxArray_int32_T *TimeUsoRec, const emxArray_int32_T
                  *DispMExD, emxArray_real_T *EP, double k0, double k1, double
                  k2, double k3, double *fitness, double *Tt, double *NOFP,
                  double *TmNOFP, double *NOE2, double *NOE3);
extern void c_sch(const int list_data[], const int NumRec[7], emxArray_int32_T
                  *PCPrO, emxArray_int32_T *PME, emxArray_int32_T *PMA,
                  emxArray_int32_T *PMAn, emxArray_int32_T *PS, emxArray_int32_T
                  *PCPO, emxArray_int32_T *PCR, const int Dia_data[], const int
                  Dia_size[2], int TimeUsoRec_data[], const int DispMExD_data[],
                  const int DispMExD_size[2], int EP_data[], int EP_size[1],
                  double *fitness, double *Tt, double *NOFP, double *TmNOFP,
                  double *NOE2, double *NOE3);
extern void sch(int NumTOp, const emxArray_int32_T *list, const int NumRec[7],
                emxArray_int32_T *PCPrO, emxArray_int32_T *PME, emxArray_int32_T
                *PMA, emxArray_int32_T *PMAn, emxArray_int32_T *PS,
                emxArray_int32_T *PCPO, emxArray_int32_T *PCR, const
                emxArray_int32_T *Dia, const emxArray_int32_T *Data,
                emxArray_int32_T *TimeUsoRec, const emxArray_int32_T *DispMExD,
                emxArray_int32_T *EP, double k0, double k1, double k2, double k3,
                double *fitness, double *Tt, double *NOFP, double *TmNOFP,
                double *NOE2, double *NOE3);

#endif

/* End of code generation (sch.h) */
