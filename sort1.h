/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sort1.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 18:10:16
 */

#ifndef SORT1_H
#define SORT1_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void b_sort(emxArray_int32_T *x, emxArray_int32_T *idx);
extern void c_sort(emxArray_real_T *x, emxArray_int32_T *idx);
extern void d_sort(emxArray_int32_T *x, emxArray_int32_T *idx);
extern void sort(double x[2000], int idx[2000]);

#endif

/*
 * File trailer for sort1.h
 *
 * [EOF]
 */
