/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rand.h
 *
 * Code generation for function 'rand'
 *
 */

#ifndef RAND_H
#define RAND_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void b_rand(double r[200]);
extern void c_rand(double r[2000]);
extern double d_rand(void);
extern void e_rand(double r[150]);
extern void f_rand(double r[225]);
extern void g_rand(double r[375]);
extern void h_rand(double r[450]);
extern void i_rand(int varargin_2, emxArray_real_T *r);
extern void j_rand(double r[2]);
extern void k_rand(int varargin_1, emxArray_real_T *r);

#endif

/* End of code generation (rand.h) */
