/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: repmat.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

#ifndef REPMAT_H
#define REPMAT_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void b_repmat(const emxArray_int32_T *a, int varargin_2, emxArray_int32_T
                     *b);
extern void c_repmat(const emxArray_real_T *a, double varargin_2,
                     emxArray_real_T *b);
extern void repmat(const emxArray_real_T *a, int varargin_2, emxArray_real_T *b);

#endif

/*
 * File trailer for repmat.h
 *
 * [EOF]
 */
