/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sum.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "sum.h"
#include "combineVectorElements.h"
#include "model_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double b_sum(const emxArray_real_T *x)
{
  double y;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = nestedIter(x, x->size[0]);
  }

  return y;
}

/*
 * Arguments    : const emxArray_int32_T *x
 *                emxArray_real_T *y
 * Return Type  : void
 */
void c_sum(const emxArray_int32_T *x, emxArray_real_T *y)
{
  int vlen;
  unsigned int sz_idx_1;
  int i14;
  int k;
  int b_k;
  vlen = x->size[0];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    sz_idx_1 = (unsigned int)x->size[1];
    i14 = y->size[0] * y->size[1];
    y->size[1] = (int)sz_idx_1;
    y->size[0] = 1;
    emxEnsureCapacity_real_T(y, i14);
    vlen = (int)sz_idx_1;
    for (i14 = 0; i14 < vlen; i14++) {
      y->data[i14] = 0.0;
    }
  } else {
    sz_idx_1 = (unsigned int)x->size[1];
    i14 = y->size[0] * y->size[1];
    y->size[1] = (int)sz_idx_1;
    y->size[0] = 1;
    emxEnsureCapacity_real_T(y, i14);
    i14 = x->size[1];
    for (k = 0; k < i14; k++) {
      y->data[k] = x->data[k];
    }

    for (k = 2; k <= vlen; k++) {
      i14 = x->size[1];
      for (b_k = 0; b_k < i14; b_k++) {
        if (vlen >= 2) {
          y->data[b_k] += (double)x->data[b_k + x->size[1] * (k - 1)];
        }
      }
    }
  }
}

/*
 * Arguments    : const emxArray_boolean_T *x
 * Return Type  : double
 */
double d_sum(const emxArray_boolean_T *x)
{
  double y;
  int vlen;
  int k;
  vlen = x->size[0];
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    for (k = 2; k <= vlen; k++) {
      if (vlen >= 2) {
        y += (double)x->data[k - 1];
      }
    }
  }

  return y;
}

/*
 * Arguments    : const emxArray_real_T *x
 * Return Type  : double
 */
double sum(const emxArray_real_T *x)
{
  double y;
  int vlen;
  int k;
  vlen = x->size[1];
  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    y = x->data[0];
    for (k = 2; k <= vlen; k++) {
      if (vlen >= 2) {
        y += x->data[k - 1];
      }
    }
  }

  return y;
}

/*
 * File trailer for sum.c
 *
 * [EOF]
 */
