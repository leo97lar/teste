/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nullAssignment.c
 *
 * Code generation for function 'nullAssignment'
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
#include "nullAssignment.h"
#include "model_emxutil.h"

/* Function Definitions */
void b_nullAssignment(emxArray_real_T *x, const boolean_T idx_data[], const int
                      idx_size[1])
{
  int nrowx;
  int i;
  int j;
  int k;
  int nrows;
  emxArray_real_T *b_x;
  nrowx = x->size[0];
  i = 0;
  j = idx_size[0];
  for (k = 0; k < j; k++) {
    i += idx_data[k];
  }

  nrows = x->size[0] - i;
  i = 0;
  for (k = 0; k < nrowx; k++) {
    if ((k + 1 > idx_size[0]) || (!idx_data[k])) {
      for (j = 0; j < 5; j++) {
        x->data[i + x->size[0] * j] = x->data[k + x->size[0] * j];
      }

      i++;
    }
  }

  if (1 > nrows) {
    i = 0;
  } else {
    i = nrows;
  }

  emxInit_real_T(&b_x, 2);
  j = b_x->size[0] * b_x->size[1];
  b_x->size[0] = i;
  b_x->size[1] = 5;
  emxEnsureCapacity_real_T(b_x, j);
  for (j = 0; j < 5; j++) {
    for (nrows = 0; nrows < i; nrows++) {
      b_x->data[nrows + b_x->size[0] * j] = x->data[nrows + x->size[0] * j];
    }
  }

  j = x->size[0] * x->size[1];
  x->size[0] = b_x->size[0];
  x->size[1] = 5;
  emxEnsureCapacity_real_T(x, j);
  for (j = 0; j < 5; j++) {
    i = b_x->size[0];
    for (nrows = 0; nrows < i; nrows++) {
      x->data[nrows + x->size[0] * j] = b_x->data[nrows + b_x->size[0] * j];
    }
  }

  emxFree_real_T(&b_x);
}

void nullAssignment(emxArray_int32_T *x, const emxArray_boolean_T *idx)
{
  int nxin;
  int k0;
  int i75;
  int k;
  int nxout;
  nxin = x->size[0];
  k0 = 0;
  i75 = idx->size[0];
  for (k = 0; k < i75; k++) {
    k0 += idx->data[k];
  }

  nxout = x->size[0] - k0;
  k0 = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > idx->size[0]) || (!idx->data[k])) {
      k0++;
      x->data[k0] = x->data[k];
    }
  }

  if (1 > nxout) {
    x->size[0] = 0;
  } else {
    i75 = x->size[0];
    x->size[0] = nxout;
    emxEnsureCapacity_int32_T(x, i75);
  }
}

/* End of code generation (nullAssignment.c) */
