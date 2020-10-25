/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: repmat.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "repmat.h"
#include "model_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_int32_T *a
 *                int varargin_2
 *                emxArray_int32_T *b
 * Return Type  : void
 */
void b_repmat(const emxArray_int32_T *a, int varargin_2, emxArray_int32_T *b)
{
  int outsize_idx_0;
  int outsize_idx_1;
  int i26;
  int na;
  int t;
  int offset;
  int k;
  outsize_idx_0 = a->size[0];
  outsize_idx_1 = a->size[1] * varargin_2;
  i26 = b->size[0] * b->size[1];
  b->size[1] = outsize_idx_1;
  b->size[0] = outsize_idx_0;
  emxEnsureCapacity_int32_T(b, i26);
  if ((b->size[0] != 0) && (b->size[1] != 0)) {
    outsize_idx_0 = a->size[0];
    for (outsize_idx_1 = 0; outsize_idx_1 < outsize_idx_0; outsize_idx_1++) {
      na = a->size[1];
      i26 = varargin_2 - 1;
      for (t = 0; t <= i26; t++) {
        offset = t * na;
        for (k = 0; k < na; k++) {
          b->data[(offset + k) + b->size[1] * outsize_idx_1] = a->data[k +
            a->size[1] * outsize_idx_1];
        }
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *a
 *                double varargin_2
 *                emxArray_real_T *b
 * Return Type  : void
 */
void c_repmat(const emxArray_real_T *a, double varargin_2, emxArray_real_T *b)
{
  int outsize_idx_0;
  int i27;
  int i28;
  int k;
  int t;
  outsize_idx_0 = a->size[0];
  i27 = b->size[0] * b->size[1];
  i28 = (int)varargin_2;
  b->size[1] = i28;
  b->size[0] = outsize_idx_0;
  emxEnsureCapacity_real_T(b, i27);
  if ((b->size[0] != 0) && (b->size[1] != 0)) {
    outsize_idx_0 = a->size[0];
    for (k = 0; k < outsize_idx_0; k++) {
      i27 = i28 - 1;
      for (t = 0; t <= i27; t++) {
        b->data[t + b->size[1] * k] = a->data[k];
      }
    }
  }
}

/*
 * Arguments    : const emxArray_real_T *a
 *                int varargin_2
 *                emxArray_real_T *b
 * Return Type  : void
 */
void repmat(const emxArray_real_T *a, int varargin_2, emxArray_real_T *b)
{
  int outsize_idx_0;
  int outsize_idx_1;
  int i23;
  int na;
  int t;
  int offset;
  int k;
  outsize_idx_0 = a->size[0];
  outsize_idx_1 = a->size[1] * varargin_2;
  i23 = b->size[0] * b->size[1];
  b->size[1] = outsize_idx_1;
  b->size[0] = outsize_idx_0;
  emxEnsureCapacity_real_T(b, i23);
  if ((b->size[0] != 0) && (b->size[1] != 0)) {
    outsize_idx_0 = a->size[0];
    for (outsize_idx_1 = 0; outsize_idx_1 < outsize_idx_0; outsize_idx_1++) {
      na = a->size[1];
      i23 = varargin_2 - 1;
      for (t = 0; t <= i23; t++) {
        offset = t * na;
        for (k = 0; k < na; k++) {
          b->data[(offset + k) + b->size[1] * outsize_idx_1] = a->data[k +
            a->size[1] * outsize_idx_1];
        }
      }
    }
  }
}

/*
 * File trailer for repmat.c
 *
 * [EOF]
 */
