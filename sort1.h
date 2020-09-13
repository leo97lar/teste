/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sort1.h
 *
 * Code generation for function 'sort1'
 *
 */

#ifndef SORT1_H
#define SORT1_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void b_sort(emxArray_int32_T *x, emxArray_int32_T *idx);
extern void c_sort(double x[2000], int idx[2000]);
extern void d_sort(emxArray_int32_T *x, emxArray_int32_T *idx);
extern void e_sort(emxArray_int32_T *x, emxArray_int32_T *idx);
extern void sort(emxArray_real_T *x, emxArray_int32_T *idx);

#endif

/* End of code generation (sort1.h) */
