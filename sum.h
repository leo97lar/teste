/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.h
 *
 * Code generation for function 'sum'
 *
 */

#ifndef SUM_H
#define SUM_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern double b_sum(const emxArray_real_T *x);
extern double c_sum(const emxArray_boolean_T *x);
extern void d_sum(const emxArray_int32_T *x, emxArray_real_T *y);
extern double e_sum(const emxArray_int32_T *x);
extern void f_sum(const emxArray_real_T *x, emxArray_real_T *y);
extern double g_sum(const emxArray_boolean_T *x);
extern double sum(const emxArray_real_T *x);

#endif

/* End of code generation (sum.h) */
