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

/*
 *
 */
void nullAssignment(emxArray_int32_T *x, const emxArray_boolean_T *idx)
{
  int nxin;
  int nxout;
  int k0;
  int k;
  emxArray_int32_T *b_x;
  nxin = x->size[0];
  nxout = 0;
  k0 = idx->size[0];
  for (k = 0; k < k0; k++) {
    nxout += idx->data[k];
  }

  nxout = x->size[0] - nxout;
  k0 = -1;
  for (k = 0; k < nxin; k++) {
    if ((k + 1 > idx->size[0]) || (!idx->data[k])) {
      k0++;
      x->data[k0] = x->data[k];
    }
  }

  if (1 > nxout) {
    nxout = 0;
  }

  emxInit_int32_T(&b_x, 1);
  k0 = b_x->size[0];
  b_x->size[0] = nxout;
  emxEnsureCapacity_int32_T(b_x, k0);
  for (k0 = 0; k0 < nxout; k0++) {
    b_x->data[k0] = x->data[k0];
  }

  k0 = x->size[0];
  x->size[0] = b_x->size[0];
  emxEnsureCapacity_int32_T(x, k0);
  nxout = b_x->size[0];
  for (k0 = 0; k0 < nxout; k0++) {
    x->data[k0] = b_x->data[k0];
  }

  emxFree_int32_T(&b_x);
}

/* End of code generation (nullAssignment.c) */
