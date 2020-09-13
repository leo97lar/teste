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

/*
 *
 */
double mean(const emxArray_real_T *x)
{
  double y;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = nestedIter(x, x->size[0]);
  }

  y /= (double)x->size[0];
  return y;
}

/* End of code generation (mean.c) */
