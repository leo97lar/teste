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
extern double b_sum(const double x[2000]);
extern double c_sum(const emxArray_real_T *x);
extern double d_sum(const int x[7]);
extern double e_sum(const int x[2]);
extern double f_sum(const int x[3]);
extern double g_sum(const emxArray_boolean_T *x);
extern double h_sum(const int x[4]);
extern double i_sum(const int x[5]);
extern double j_sum(const int x[6]);
extern void k_sum(const emxArray_int32_T *x, emxArray_real_T *y);
extern double l_sum(const emxArray_int32_T *x);
extern void m_sum(const emxArray_real_T *x, emxArray_real_T *y);
extern double n_sum(const emxArray_boolean_T *x);
extern double sum(const emxArray_real_T *x);

#endif

/* End of code generation (sum.h) */
