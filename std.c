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
#include "main_UCI_func.h"
#include "std.h"
#include "model_emxutil.h"
#include "combineVectorElements.h"

/* Function Definitions */

/*
 *
 */
double b_std(const emxArray_real_T *x)
{
  double y;
  int n;
  emxArray_real_T *absdiff;
  double xbar;
  int kend;
  int k;
  double absxk;
  double t;
  n = x->size[0];
  if (x->size[0] == 0) {
    y = 0.0;
  } else if (x->size[0] == 1) {
    y = 0.0;
  } else {
    emxInit_real_T(&absdiff, 1);
    xbar = nestedIter(x, x->size[0]);
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

/* End of code generation (std.c) */
