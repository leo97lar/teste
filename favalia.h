/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * favalia.h
 *
 * Code generation for function 'favalia'
 *
 */

#ifndef FAVALIA_H
#define FAVALIA_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void favalia(const emxArray_int32_T *schedule, const emxArray_int32_T
                    *DiaOp, const emxArray_int32_T *EP, emxArray_int32_T
                    *EspMedOp, double k0, double k1, double k2, double k3,
                    double *fitness, double *Tt, double *NOFP, double *TmNOFP,
                    double *NOE2, double *NOE3);

#endif

/* End of code generation (favalia.h) */
