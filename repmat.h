/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.h
 *
 * Code generation for function 'repmat'
 *
 */

#ifndef REPMAT_H
#define REPMAT_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void b_repmat(double b[8760]);
extern void c_repmat(double b[8760]);
extern void d_repmat(double b[17520]);
extern void e_repmat(double b[735]);
extern void f_repmat(double b[17520]);
extern void g_repmat(double b[17520]);
extern void h_repmat(double b[17520]);
extern void repmat(const emxArray_real_T *a, double varargin_2, emxArray_real_T *
                   b);

#endif

/* End of code generation (repmat.h) */
