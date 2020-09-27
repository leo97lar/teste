/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sort1.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
#include "pch.h"

#include <string.h>
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "sort1.h"
#include "sortIdx.h"
#include "model_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : emxArray_int32_T *x
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
void b_sort(emxArray_int32_T *x, emxArray_int32_T *idx)
{
  int dim;
  int i51;
  emxArray_int32_T *vwork;
  int vlen;
  int j;
  int vstride;
  int k;
  emxArray_int32_T *iidx;
  dim = 0;
  if (x->size[0] != 1) {
    dim = -1;
  }

  if (dim + 2 <= 1) {
    i51 = x->size[0];
  } else {
    i51 = 1;
  }

  emxInit_int32_T(&vwork, 1);
  vlen = i51 - 1;
  j = vwork->size[0];
  vwork->size[0] = i51;
  emxEnsureCapacity_int32_T(vwork, j);
  j = x->size[0];
  i51 = idx->size[0];
  idx->size[0] = j;
  emxEnsureCapacity_int32_T(idx, i51);
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    i51 = x->size[0];
    vstride *= i51;
  }

  emxInit_int32_T(&iidx, 1);
  for (j = 0; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork->data[k] = x->data[j + k * vstride];
    }

    b_sortIdx(vwork, iidx);
    for (k = 0; k <= vlen; k++) {
      i51 = j + k * vstride;
      x->data[i51] = vwork->data[k];
      idx->data[i51] = iidx->data[k];
    }
  }

  emxFree_int32_T(&iidx);
  emxFree_int32_T(&vwork);
}

/*
 * Arguments    : emxArray_real_T *x
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
void c_sort(emxArray_real_T *x, emxArray_int32_T *idx)
{
  int dim;
  int i55;
  emxArray_real_T *vwork;
  int vlen;
  int j;
  int vstride;
  int k;
  emxArray_int32_T *iidx;
  dim = 0;
  if (x->size[0] != 1) {
    dim = -1;
  }

  if (dim + 2 <= 1) {
    i55 = x->size[0];
  } else {
    i55 = 1;
  }

  emxInit_real_T(&vwork, 1);
  vlen = i55 - 1;
  j = vwork->size[0];
  vwork->size[0] = i55;
  emxEnsureCapacity_real_T(vwork, j);
  j = x->size[0];
  i55 = idx->size[0];
  idx->size[0] = j;
  emxEnsureCapacity_int32_T(idx, i55);
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    i55 = x->size[0];
    vstride *= i55;
  }

  emxInit_int32_T(&iidx, 1);
  for (j = 0; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork->data[k] = x->data[j + k * vstride];
    }

    c_sortIdx(vwork, iidx);
    for (k = 0; k <= vlen; k++) {
      i55 = j + k * vstride;
      x->data[i55] = vwork->data[k];
      idx->data[i55] = iidx->data[k];
    }
  }

  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
}

/*
 * Arguments    : emxArray_int32_T *x
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
void d_sort(emxArray_int32_T *x, emxArray_int32_T *idx)
{
  int dim;
  int i59;
  emxArray_int32_T *vwork;
  int vlen;
  int j;
  int vstride;
  int k;
  emxArray_int32_T *iidx;
  dim = 0;
  if (x->size[0] != 1) {
    dim = -1;
  }

  if (dim + 2 <= 1) {
    i59 = x->size[0];
  } else {
    i59 = 1;
  }

  emxInit_int32_T(&vwork, 1);
  vlen = i59 - 1;
  j = vwork->size[0];
  vwork->size[0] = i59;
  emxEnsureCapacity_int32_T(vwork, j);
  j = x->size[0];
  i59 = idx->size[0];
  idx->size[0] = j;
  emxEnsureCapacity_int32_T(idx, i59);
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    i59 = x->size[0];
    vstride *= i59;
  }

  emxInit_int32_T(&iidx, 1);
  for (j = 0; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork->data[k] = x->data[j + k * vstride];
    }

    d_sortIdx(vwork, iidx);
    for (k = 0; k <= vlen; k++) {
      i59 = j + k * vstride;
      x->data[i59] = vwork->data[k];
      idx->data[i59] = iidx->data[k];
    }
  }

  emxFree_int32_T(&iidx);
  emxFree_int32_T(&vwork);
}

/*
 * Arguments    : double x[2000]
 *                int idx[2000]
 * Return Type  : void
 */
void sort(double x[2000], int idx[2000])
{
  double x4[4];
  short idx4[4];
  int ib;
  int k;
  signed char perm[4];
  int b;
  int iwork[2000];
  int offset;
  double xwork[2000];
  int b_b;
  int i2;
  int bLen;
  int bLen2;
  int nPairs;
  int idx_tmp;
  int i3;
  int i4;
  double d11;
  double d12;
  short b_iwork[256];
  double b_xwork[256];
  int exitg1;
  memset(&idx[0], 0, 2000U * sizeof(int));
  x4[0] = 0.0;
  idx4[0] = 0;
  x4[1] = 0.0;
  idx4[1] = 0;
  x4[2] = 0.0;
  idx4[2] = 0;
  x4[3] = 0.0;
  idx4[3] = 0;
  ib = 0;
  for (k = 0; k < 2000; k++) {
    ib++;
    idx4[ib - 1] = (short)(k + 1);
    x4[ib - 1] = x[k];
    if (ib == 4) {
      if (x4[0] <= x4[1]) {
        ib = 1;
        i2 = 2;
      } else {
        ib = 2;
        i2 = 1;
      }

      if (x4[2] <= x4[3]) {
        i3 = 3;
        i4 = 4;
      } else {
        i3 = 4;
        i4 = 3;
      }

      d11 = x4[ib - 1];
      d12 = x4[i3 - 1];
      if (d11 <= d12) {
        d11 = x4[i2 - 1];
        if (d11 <= d12) {
          perm[0] = (signed char)ib;
          perm[1] = (signed char)i2;
          perm[2] = (signed char)i3;
          perm[3] = (signed char)i4;
        } else if (d11 <= x4[i4 - 1]) {
          perm[0] = (signed char)ib;
          perm[1] = (signed char)i3;
          perm[2] = (signed char)i2;
          perm[3] = (signed char)i4;
        } else {
          perm[0] = (signed char)ib;
          perm[1] = (signed char)i3;
          perm[2] = (signed char)i4;
          perm[3] = (signed char)i2;
        }
      } else {
        d12 = x4[i4 - 1];
        if (d11 <= d12) {
          if (x4[i2 - 1] <= d12) {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)ib;
            perm[2] = (signed char)i2;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)ib;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)i2;
          }
        } else {
          perm[0] = (signed char)i3;
          perm[1] = (signed char)i4;
          perm[2] = (signed char)ib;
          perm[3] = (signed char)i2;
        }
      }

      idx_tmp = perm[0] - 1;
      idx[k - 3] = idx4[idx_tmp];
      ib = perm[1] - 1;
      idx[k - 2] = idx4[ib];
      i2 = perm[2] - 1;
      idx[k - 1] = idx4[i2];
      i3 = perm[3] - 1;
      idx[k] = idx4[i3];
      x[k - 3] = x4[idx_tmp];
      x[k - 2] = x4[ib];
      x[k - 1] = x4[i2];
      x[k] = x4[i3];
      ib = 0;
    }
  }

  if (ib > 0) {
    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (ib == 1) {
      perm[0] = 1;
    } else if (ib == 2) {
      if (x4[0] <= x4[1]) {
        perm[0] = 1;
        perm[1] = 2;
      } else {
        perm[0] = 2;
        perm[1] = 1;
      }
    } else if (x4[0] <= x4[1]) {
      if (x4[1] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 2;
        perm[2] = 3;
      } else if (x4[0] <= x4[2]) {
        perm[0] = 1;
        perm[1] = 3;
        perm[2] = 2;
      } else {
        perm[0] = 3;
        perm[1] = 1;
        perm[2] = 2;
      }
    } else if (x4[0] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 1;
      perm[2] = 3;
    } else if (x4[1] <= x4[2]) {
      perm[0] = 2;
      perm[1] = 3;
      perm[2] = 1;
    } else {
      perm[0] = 3;
      perm[1] = 2;
      perm[2] = 1;
    }

    for (k = 0; k < ib; k++) {
      idx_tmp = (k - ib) + 2000;
      idx[idx_tmp] = idx4[perm[k] - 1];
      x[idx_tmp] = x4[perm[k] - 1];
    }
  }

  for (b = 0; b < 7; b++) {
    offset = b << 8;
    for (b_b = 0; b_b < 6; b_b++) {
      bLen = 1 << (b_b + 2);
      bLen2 = bLen << 1;
      nPairs = 256 >> (b_b + 3);
      for (k = 0; k < nPairs; k++) {
        i3 = offset + k * bLen2;
        for (i2 = 0; i2 < bLen2; i2++) {
          ib = i3 + i2;
          b_iwork[i2] = (short)idx[ib];
          b_xwork[i2] = x[ib];
        }

        i4 = 0;
        i2 = bLen;
        ib = i3 - 1;
        do {
          exitg1 = 0;
          ib++;
          if (b_xwork[i4] <= b_xwork[i2]) {
            idx[ib] = b_iwork[i4];
            x[ib] = b_xwork[i4];
            if (i4 + 1 < bLen) {
              i4++;
            } else {
              exitg1 = 1;
            }
          } else {
            idx[ib] = b_iwork[i2];
            x[ib] = b_xwork[i2];
            if (i2 + 1 < bLen2) {
              i2++;
            } else {
              ib -= i4;
              for (i2 = i4 + 1; i2 <= bLen; i2++) {
                idx_tmp = ib + i2;
                idx[idx_tmp] = b_iwork[i2 - 1];
                x[idx_tmp] = b_xwork[i2 - 1];
              }

              exitg1 = 1;
            }
          }
        } while (exitg1 == 0);
      }
    }
  }

  memset(&iwork[0], 0, 2000U * sizeof(int));
  memset(&xwork[0], 0, 2000U * sizeof(double));
  merge_block(idx, x, 1792, 208, 2, iwork, xwork);
  merge_block(idx, x, 0, 2000, 8, iwork, xwork);
}

/*
 * File trailer for sort1.c
 *
 * [EOF]
 */
