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
#include "Calendario.h"
#include "Codificacion_de_dias_func.h"
#include "CreaPoQunniforme.h"
#include "Edade.h"
#include "PLOTT_func.h"
#include "actIQ.h"
#include "aevSPLap.h"
#include "casorandom.h"
#include "cc.h"
#include "favalia.h"
#include "funcionC.h"
#include "funcionCPrO.h"
#include "funcionCR.h"
#include "funcionDia.h"
#include "funcionRP.h"
#include "main_UCI_func.h"
#include "obsIQ.h"
#include "obsIQini.h"
#include "sch.h"
#include "sum.h"
#include "model_emxutil.h"
#include "combineVectorElements.h"

/* Function Definitions */
double b_sum(const int x[7])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 6; k++) {
    y += (double)x[k + 1];
  }

  return y;
}

double c_sum(const int x[2])
{
  return (double)x[0] + (double)x[1];
}

double d_sum(const int x[3])
{
  return ((double)x[0] + (double)x[1]) + (double)x[2];
}

double e_sum(const emxArray_boolean_T *x)
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

double f_sum(const int x[4])
{
  return (((double)x[0] + (double)x[1]) + (double)x[2]) + (double)x[3];
}

double g_sum(const int x[5])
{
  return ((((double)x[0] + (double)x[1]) + (double)x[2]) + (double)x[3]) +
    (double)x[4];
}

double h_sum(const int x[6])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 5; k++) {
    y += (double)x[k + 1];
  }

  return y;
}

void i_sum(const emxArray_real_T *x, emxArray_real_T *y)
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

double j_sum(const emxArray_int32_T *x)
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

double k_sum(const emxArray_boolean_T *x)
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

double l_sum(const double x[2000])
{
  double y;
  int k;
  y = x[0];
  for (k = 0; k < 1999; k++) {
    y += x[k + 1];
  }

  return y;
}

double m_sum(const double x_data[], const int x_size[1])
{
  emxArray_real_T b_x_data;
  b_x_data.data = (double *)&x_data[0];
  b_x_data.size = (int *)&x_size[0];
  b_x_data.allocatedSize = -1;
  b_x_data.numDimensions = 1;
  b_x_data.canFreeData = false;
  return combineVectorElements(&b_x_data);
}

void n_sum(const emxArray_int32_T *x, emxArray_real_T *y)
{
  unsigned int sz_idx_1;
  int i35;
  int loop_ub;
  if ((x->size[0] == 0) || (x->size[1] == 0)) {
    sz_idx_1 = (unsigned int)x->size[1];
    i35 = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)sz_idx_1;
    emxEnsureCapacity_real_T(y, i35);
    loop_ub = (int)sz_idx_1;
    for (i35 = 0; i35 < loop_ub; i35++) {
      y->data[i35] = 0.0;
    }
  } else {
    colMajorFlatIter(x, x->size[0], y);
  }
}

double sum(const emxArray_real_T *x)
{
  double y;
  int vlen;
  int k;
  vlen = x->size[1];
  y = x->data[0];
  for (k = 2; k <= vlen; k++) {
    y += x->data[k - 1];
  }

  return y;
}

/* End of code generation (sum.c) */
