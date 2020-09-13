/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * combineVectorElements.c
 *
 * Code generation for function 'combineVectorElements'
 *
 */

/* Include files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "combineVectorElements.h"

/* Function Definitions */

/*
 *
 */
double nestedIter(const emxArray_real_T *x, int vlen)
{
  double y;
  int k;
  y = x->data[0];
  for (k = 2; k <= vlen; k++) {
    if (vlen >= 2) {
      y += x->data[k - 1];
    }
  }

  return y;
}

/* End of code generation (combineVectorElements.c) */
