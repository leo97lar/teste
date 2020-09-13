/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortIdx.h
 *
 * Code generation for function 'sortIdx'
 *
 */

#ifndef SORTIDX_H
#define SORTIDX_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void b_sortIdx(emxArray_real_T *x, emxArray_int32_T *idx);
extern void c_merge_block(int idx[2000], double x[2000], int offset, int n, int
  preSortLevel, int iwork[2000], double xwork[2000]);
extern void c_sortIdx(emxArray_int32_T *x, emxArray_int32_T *idx);
extern void d_merge_block(emxArray_int32_T *idx, emxArray_int32_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_int32_T *xwork);
extern void d_sortIdx(emxArray_int32_T *x, emxArray_int32_T *idx);
extern void sortIdx(const double x[2000], int idx[2000]);

#endif

/* End of code generation (sortIdx.h) */
