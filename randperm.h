/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * randperm.h
 *
 * Code generation for function 'randperm'
 *
 */

#ifndef RANDPERM_H
#define RANDPERM_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void b_randperm(double p[2000]);
extern void c_randperm(int n, emxArray_real_T *p);
extern void randperm(double p[200]);

#endif

/* End of code generation (randperm.h) */
