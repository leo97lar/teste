/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sort1.c
 *
 * Code generation for function 'sort1'
 *
 */

/* Include files */
#include <string.h>
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "sort1.h"
#include "sortIdx.h"
#include "model_emxutil.h"

/* Function Definitions */

/*
 *
 */
void b_sort(emxArray_int32_T *x, emxArray_int32_T *idx)
{
  int dim;
  int i49;
  emxArray_int32_T *vwork;
  int vlen;
  int j;
  unsigned int unnamed_idx_0;
  int vstride;
  int k;
  emxArray_int32_T *iidx;
  dim = 0;
  if (x->size[0] != 1) {
    dim = -1;
  }

  if (dim + 2 <= 1) {
    i49 = x->size[0];
  } else {
    i49 = 1;
  }

  emxInit_int32_T(&vwork, 1);
  vlen = i49 - 1;
  j = vwork->size[0];
  vwork->size[0] = i49;
  emxEnsureCapacity_int32_T(vwork, j);
  unnamed_idx_0 = (unsigned int)x->size[0];
  i49 = idx->size[0];
  idx->size[0] = (int)unnamed_idx_0;
  emxEnsureCapacity_int32_T(idx, i49);
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    i49 = x->size[0];
    vstride *= i49;
  }

  emxInit_int32_T(&iidx, 1);
  for (j = 0; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork->data[k] = x->data[j + k * vstride];
    }

    b_sortIdx(vwork, iidx);
    for (k = 0; k <= vlen; k++) {
      i49 = j + k * vstride;
      x->data[i49] = vwork->data[k];
      idx->data[i49] = iidx->data[k];
    }
  }

  emxFree_int32_T(&iidx);
  emxFree_int32_T(&vwork);
}

/*
 *
 */
void c_sort(emxArray_real_T *x, emxArray_int32_T *idx)
{
  int dim;
  int i54;
  emxArray_real_T *vwork;
  int vlen;
  int j;
  unsigned int unnamed_idx_0;
  int vstride;
  int k;
  emxArray_int32_T *iidx;
  dim = 0;
  if (x->size[0] != 1) {
    dim = -1;
  }

  if (dim + 2 <= 1) {
    i54 = x->size[0];
  } else {
    i54 = 1;
  }

  emxInit_real_T(&vwork, 1);
  vlen = i54 - 1;
  j = vwork->size[0];
  vwork->size[0] = i54;
  emxEnsureCapacity_real_T(vwork, j);
  unnamed_idx_0 = (unsigned int)x->size[0];
  i54 = idx->size[0];
  idx->size[0] = (int)unnamed_idx_0;
  emxEnsureCapacity_int32_T(idx, i54);
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    i54 = x->size[0];
    vstride *= i54;
  }

  emxInit_int32_T(&iidx, 1);
  for (j = 0; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork->data[k] = x->data[j + k * vstride];
    }

    c_sortIdx(vwork, iidx);
    for (k = 0; k <= vlen; k++) {
      i54 = j + k * vstride;
      x->data[i54] = vwork->data[k];
      idx->data[i54] = iidx->data[k];
    }
  }

  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
}

/*
 *
 */
void d_sort(emxArray_int32_T *x, emxArray_int32_T *idx)
{
  int dim;
  int i58;
  emxArray_int32_T *vwork;
  int vlen;
  int j;
  unsigned int unnamed_idx_0;
  int vstride;
  int k;
  emxArray_int32_T *iidx;
  dim = 0;
  if (x->size[0] != 1) {
    dim = -1;
  }

  if (dim + 2 <= 1) {
    i58 = x->size[0];
  } else {
    i58 = 1;
  }

  emxInit_int32_T(&vwork, 1);
  vlen = i58 - 1;
  j = vwork->size[0];
  vwork->size[0] = i58;
  emxEnsureCapacity_int32_T(vwork, j);
  unnamed_idx_0 = (unsigned int)x->size[0];
  i58 = idx->size[0];
  idx->size[0] = (int)unnamed_idx_0;
  emxEnsureCapacity_int32_T(idx, i58);
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    i58 = x->size[0];
    vstride *= i58;
  }

  emxInit_int32_T(&iidx, 1);
  for (j = 0; j < vstride; j++) {
    for (k = 0; k <= vlen; k++) {
      vwork->data[k] = x->data[j + k * vstride];
    }

    d_sortIdx(vwork, iidx);
    for (k = 0; k <= vlen; k++) {
      i58 = j + k * vstride;
      x->data[i58] = vwork->data[k];
      idx->data[i58] = iidx->data[k];
    }
  }

  emxFree_int32_T(&iidx);
  emxFree_int32_T(&vwork);
}

/*
 *
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
  double d10;
  double d11;
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

      d10 = x4[ib - 1];
      d11 = x4[i3 - 1];
      if (d10 <= d11) {
        d10 = x4[i2 - 1];
        if (d10 <= d11) {
          perm[0] = (signed char)ib;
          perm[1] = (signed char)i2;
          perm[2] = (signed char)i3;
          perm[3] = (signed char)i4;
        } else if (d10 <= x4[i4 - 1]) {
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
        d11 = x4[i4 - 1];
        if (d10 <= d11) {
          if (x4[i2 - 1] <= d11) {
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

/* End of code generation (sort1.c) */
