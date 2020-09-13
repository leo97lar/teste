/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "sum.h"
#include "combineVectorElements.h"
#include "model_emxutil.h"

/* Function Definitions */

/*
 *
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
 *
 */
void c_sum(const emxArray_int32_T *x, emxArray_real_T *y)
{
  int vlen;
  unsigned int sz_idx_1;
  int i9;
  int k;
  int b_k;
  vlen = x->size[0];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    sz_idx_1 = (unsigned int)x->size[1];
    i9 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)sz_idx_1;
    emxEnsureCapacity_real_T(y, i9);
    vlen = (int)sz_idx_1;
    for (i9 = 0; i9 < vlen; i9++) {
      y->data[i9] = 0.0;
    }
  } else {
    sz_idx_1 = (unsigned int)x->size[1];
    i9 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)sz_idx_1;
    emxEnsureCapacity_real_T(y, i9);
    i9 = x->size[1];
    for (k = 0; k < i9; k++) {
      y->data[k] = x->data[x->size[0] * k];
      for (b_k = 2; b_k <= vlen; b_k++) {
        if (vlen >= 2) {
          y->data[k] += (double)x->data[(b_k + x->size[0] * k) - 1];
        }
      }
    }
  }
}

/*
 *
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
 *
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

/* End of code generation (sum.c) */
