/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: obsIQini.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 18:10:16
 */

#ifndef OBSIQINI_H
#define OBSIQINI_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void obsIQini(const emxArray_real_T *IQ, int numIQ, int numObsIQ, const
                     emxArray_real_T *ProbXEst, emxArray_int32_T *newIC);

#endif

/*
 * File trailer for obsIQini.h
 *
 * [EOF]
 */
