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
#include "main_UCI_func.h"
#include "nullAssignment.h"
#include "model_emxutil.h"

/* Function Definitions */
void nullAssignment(emxArray_int32_T *x, const emxArray_boolean_T *idx)
{
  int nxin;
  int k0;
  int i58;
  int k;
  int nxout;
  nxin = x->size[0];
  k0 = 0;
  i58 = idx->size[0];
  for (k = 0; k < i58; k++) {
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
    i58 = x->size[0];
    x->size[0] = nxout;
    emxEnsureCapacity_int32_T(x, i58);
  }
}

/* End of code generation (nullAssignment.c) */
