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
#include "combineVectorElements.h"
#include "model_emxutil.h"

/* Function Definitions */
void colMajorFlatIter(const emxArray_int32_T *x, int vlen, emxArray_real_T *y)
{
  int npages;
  int i;
  int xpageoffset;
  int k;
  npages = x->size[1];
  i = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = x->size[1];
  emxEnsureCapacity_real_T(y, i);
  for (i = 0; i < npages; i++) {
    xpageoffset = i * x->size[0];
    y->data[i] = x->data[xpageoffset];
    for (k = 2; k <= vlen; k++) {
      y->data[i] += (double)x->data[(xpageoffset + k) - 1];
    }
  }
}

double combineVectorElements(const emxArray_real_T *x)
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
      y += x->data[k - 1];
    }
  }

  return y;
}

/* End of code generation (combineVectorElements.c) */
