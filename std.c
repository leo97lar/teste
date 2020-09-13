/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * std.c
 *
 * Code generation for function 'std'
 *
 */

/* Include files */
#include <math.h>
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
#include "std.h"
#include "model_emxutil.h"

/* Function Definitions */
double b_std(const emxArray_real_T *x)
{
  double y;
  int n;
  double xbar;
  int k;
  emxArray_real_T *absdiff;
  int kend;
  double absxk;
  double t;
  n = x->size[0];
  if (x->size[0] == 0) {
    y = 0.0;
  } else if (x->size[0] == 1) {
    y = 0.0;
  } else {
    xbar = x->data[0];
    for (k = 2; k <= n; k++) {
      xbar += x->data[k - 1];
    }

    emxInit_real_T(&absdiff, 1);
    xbar /= (double)x->size[0];
    kend = absdiff->size[0];
    absdiff->size[0] = x->size[0];
    emxEnsureCapacity_real_T(absdiff, kend);
    for (k = 0; k < n; k++) {
      absdiff->data[k] = fabs(x->data[k] - xbar);
    }

    y = 0.0;
    xbar = 3.3121686421112381E-170;
    kend = x->size[0];
    for (k = 0; k < kend; k++) {
      absxk = absdiff->data[k];
      if (absxk > xbar) {
        t = xbar / absxk;
        y = 1.0 + y * t * t;
        xbar = absxk;
      } else {
        t = absxk / xbar;
        y += t * t;
      }
    }

    emxFree_real_T(&absdiff);
    y = xbar * sqrt(y);
    y /= sqrt((double)x->size[0] - 1.0);
  }

  return y;
}

double c_std(const double x[20])
{
  double y;
  double xbar;
  int k;
  double scale;
  double d17;
  double t;
  xbar = x[0];
  for (k = 0; k < 19; k++) {
    xbar += x[k + 1];
  }

  xbar /= 20.0;
  y = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 20; k++) {
    d17 = fabs(x[k] - xbar);
    if (d17 > scale) {
      t = scale / d17;
      y = 1.0 + y * t * t;
      scale = d17;
    } else {
      t = d17 / scale;
      y += t * t;
    }
  }

  y = scale * sqrt(y);
  y /= 4.358898943540674;
  return y;
}

/* End of code generation (std.c) */
