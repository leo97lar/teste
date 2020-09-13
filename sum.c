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
double b_sum(const double x[2000])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 1999; k++) {
    y += x[k + 1];
  }

  return y;
}

double c_sum(const emxArray_real_T *x)
{
  return combineVectorElements(x);
}

double d_sum(const int x[7])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 6; k++) {
    y += (double)x[k + 1];
  }

  return y;
}

double e_sum(const int x[2])
{
  return (double)x[0] + (double)x[1];
}

double f_sum(const int x[3])
{
  return ((double)x[0] + (double)x[1]) + (double)x[2];
}

double g_sum(const emxArray_boolean_T *x)
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
      y += (double)x->data[k - 1];
    }
  }

  return y;
}

double h_sum(const int x[4])
{
  return (((double)x[0] + (double)x[1]) + (double)x[2]) + (double)x[3];
}

double i_sum(const int x[5])
{
  return ((((double)x[0] + (double)x[1]) + (double)x[2]) + (double)x[3]) +
    (double)x[4];
}

double j_sum(const int x[6])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 5; k++) {
    y += (double)x[k + 1];
  }

  return y;
}

void k_sum(const emxArray_int32_T *x, emxArray_real_T *y)
{
  int vlen;
  int npages;
  unsigned int sz_idx_1;
  int xpageoffset;
  int i;
  int k;
  vlen = x->size[0];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    sz_idx_1 = (unsigned int)x->size[1];
    xpageoffset = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)sz_idx_1;
    emxEnsureCapacity_real_T(y, xpageoffset);
    i = (int)sz_idx_1;
    for (xpageoffset = 0; xpageoffset < i; xpageoffset++) {
      y->data[xpageoffset] = 0.0;
    }
  } else {
    npages = x->size[1];
    xpageoffset = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = x->size[1];
    emxEnsureCapacity_real_T(y, xpageoffset);
    for (i = 0; i < npages; i++) {
      xpageoffset = i * x->size[0];
      y->data[i] = x->data[xpageoffset];
      for (k = 2; k <= vlen; k++) {
        y->data[i] += (double)x->data[(xpageoffset + k) - 1];
      }
    }
  }
}

double l_sum(const emxArray_int32_T *x)
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
      y += (double)x->data[k - 1];
    }
  }

  return y;
}

void m_sum(const emxArray_real_T *x, emxArray_real_T *y)
{
  int vlen;
  int npages;
  unsigned int sz_idx_1;
  int xpageoffset;
  int i;
  int k;
  vlen = x->size[0];
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    sz_idx_1 = (unsigned int)x->size[1];
    xpageoffset = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)sz_idx_1;
    emxEnsureCapacity_real_T(y, xpageoffset);
    i = (int)sz_idx_1;
    for (xpageoffset = 0; xpageoffset < i; xpageoffset++) {
      y->data[xpageoffset] = 0.0;
    }
  } else {
    npages = x->size[1];
    xpageoffset = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = x->size[1];
    emxEnsureCapacity_real_T(y, xpageoffset);
    for (i = 0; i < npages; i++) {
      xpageoffset = i * x->size[0];
      y->data[i] = x->data[xpageoffset];
      for (k = 2; k <= vlen; k++) {
        y->data[i] += x->data[(xpageoffset + k) - 1];
      }
    }
  }
}

double n_sum(const emxArray_boolean_T *x)
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
      y += (double)x->data[k - 1];
    }
  }

  return y;
}

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
      y += x->data[k - 1];
    }
  }

  return y;
}

/* End of code generation (sum.c) */
