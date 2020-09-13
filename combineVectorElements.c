/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: combineVectorElements.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 18:10:16
 */

/* Include Files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "combineVectorElements.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 *                int vlen
 * Return Type  : double
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

/*
 * File trailer for combineVectorElements.c
 *
 * [EOF]
 */
