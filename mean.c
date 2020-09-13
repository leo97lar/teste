/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "mean.h"
#include "combineVectorElements.h"

/* Function Definitions */
double mean(const emxArray_real_T *x)
{
  return combineVectorElements(x) / (double)x->size[0];
}

/* End of code generation (mean.c) */
