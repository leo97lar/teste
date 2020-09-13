/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "repmat.h"
#include "model_emxutil.h"

/* Function Definitions */
void b_repmat(const emxArray_real_T *a, double varargin_2, emxArray_real_T *b)
{
  int outsize_idx_0;
  int jtilecol;
  int i21;
  int ibtile;
  int k;
  outsize_idx_0 = a->size[0];
  jtilecol = b->size[0] * b->size[1];
  b->size[0] = outsize_idx_0;
  i21 = (int)varargin_2;
  b->size[1] = i21;
  emxEnsureCapacity_real_T(b, jtilecol);
  outsize_idx_0 = a->size[0];
  for (jtilecol = 0; jtilecol < i21; jtilecol++) {
    ibtile = jtilecol * outsize_idx_0;
    for (k = 0; k < outsize_idx_0; k++) {
      b->data[ibtile + k] = a->data[k];
    }
  }
}

void repmat(const emxArray_real_T *a, int varargin_2, emxArray_real_T *b)
{
  int outsize_idx_0;
  int outsize_idx_1;
  int jtilecol;
  int ibtile;
  int jcol;
  int ibmat;
  int k;
  outsize_idx_0 = a->size[0];
  outsize_idx_1 = a->size[1] * varargin_2;
  jtilecol = b->size[0] * b->size[1];
  b->size[0] = outsize_idx_0;
  b->size[1] = outsize_idx_1;
  emxEnsureCapacity_real_T(b, jtilecol);
  outsize_idx_0 = a->size[0];
  outsize_idx_1 = a->size[1];
  for (jtilecol = 0; jtilecol < varargin_2; jtilecol++) {
    ibtile = jtilecol * (outsize_idx_0 * outsize_idx_1);
    for (jcol = 0; jcol < outsize_idx_1; jcol++) {
      ibmat = ibtile + jcol * outsize_idx_0;
      for (k = 0; k < outsize_idx_0; k++) {
        b->data[ibmat + k] = 0.0;
      }
    }
  }
}

/* End of code generation (repmat.c) */
