/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortIdx.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 18:10:16
 */

#ifndef SORTIDX_H
#define SORTIDX_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void b_sortIdx(emxArray_int32_T *x, emxArray_int32_T *idx);
extern void c_sortIdx(emxArray_real_T *x, emxArray_int32_T *idx);
extern void d_sortIdx(emxArray_int32_T *x, emxArray_int32_T *idx);
extern void merge_block(int idx[2000], double x[2000], int offset, int n, int
  preSortLevel, int iwork[2000], double xwork[2000]);
extern void sortIdx(const double x[2000], int idx[2000]);

#endif

/*
 * File trailer for sortIdx.h
 *
 * [EOF]
 */
