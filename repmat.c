/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: repmat.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 18:10:16
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
  int i19;
  int offset;
  int k;
  int na;
  int b_k;
  outsize_idx_0 = a->size[0];
  outsize_idx_1 = a->size[1] * varargin_2;
  i19 = b->size[0] * b->size[1];
  b->size[0] = outsize_idx_0;
  b->size[1] = outsize_idx_1;
  emxEnsureCapacity_int32_T(b, i19);
  if ((b->size[0] != 0) && (b->size[1] != 0)) {
    outsize_idx_0 = a->size[1];
    i19 = varargin_2 - 1;
    for (outsize_idx_1 = 0; outsize_idx_1 <= i19; outsize_idx_1++) {
      offset = outsize_idx_1 * outsize_idx_0;
      for (k = 0; k < outsize_idx_0; k++) {
        na = a->size[0];
        for (b_k = 0; b_k < na; b_k++) {
          b->data[b_k + b->size[0] * (offset + k)] = a->data[b_k + a->size[0] *
            k];
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
  int i20;
  int na;
  int k;
  outsize_idx_0 = a->size[0];
  i20 = b->size[0] * b->size[1];
  b->size[0] = outsize_idx_0;
  outsize_idx_0 = (int)varargin_2;
  b->size[1] = outsize_idx_0;
  emxEnsureCapacity_real_T(b, i20);
  if ((b->size[0] != 0) && (b->size[1] != 0)) {
    i20 = outsize_idx_0 - 1;
    for (outsize_idx_0 = 0; outsize_idx_0 <= i20; outsize_idx_0++) {
      na = a->size[0];
      for (k = 0; k < na; k++) {
        b->data[k + b->size[0] * outsize_idx_0] = a->data[k];
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
  int i16;
  int offset;
  int k;
  int na;
  int b_k;
  outsize_idx_0 = a->size[0];
  outsize_idx_1 = a->size[1] * varargin_2;
  i16 = b->size[0] * b->size[1];
  b->size[0] = outsize_idx_0;
  b->size[1] = outsize_idx_1;
  emxEnsureCapacity_real_T(b, i16);
  if ((b->size[0] != 0) && (b->size[1] != 0)) {
    outsize_idx_0 = a->size[1];
    i16 = varargin_2 - 1;
    for (outsize_idx_1 = 0; outsize_idx_1 <= i16; outsize_idx_1++) {
      offset = outsize_idx_1 * outsize_idx_0;
      for (k = 0; k < outsize_idx_0; k++) {
        na = a->size[0];
        for (b_k = 0; b_k < na; b_k++) {
          b->data[b_k + b->size[0] * (offset + k)] = a->data[b_k + a->size[0] *
            k];
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
