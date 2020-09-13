/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sortIdx.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 18:10:16
 */

/* Include Files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "sortIdx.h"
#include "model_emxutil.h"

/* Function Declarations */
static void b_merge(emxArray_int32_T *idx, emxArray_int32_T *x, int offset, int
                    np, int nq, emxArray_int32_T *iwork, emxArray_int32_T *xwork);
static void b_merge_block(emxArray_int32_T *idx, emxArray_int32_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_int32_T *xwork);
static void c_merge(emxArray_int32_T *idx, emxArray_real_T *x, int offset, int
                    np, int nq, emxArray_int32_T *iwork, emxArray_real_T *xwork);
static void c_merge_block(emxArray_int32_T *idx, emxArray_real_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_real_T *xwork);
static void d_merge(emxArray_int32_T *idx, emxArray_int32_T *x, int offset, int
                    np, int nq, emxArray_int32_T *iwork, emxArray_int32_T *xwork);
static void d_merge_block(emxArray_int32_T *idx, emxArray_int32_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_int32_T *xwork);
static void merge(int idx[2000], double x[2000], int offset, int np, int nq, int
                  iwork[2000], double xwork[2000]);

/* Function Definitions */

/*
 * Arguments    : emxArray_int32_T *idx
 *                emxArray_int32_T *x
 *                int offset
 *                int np
 *                int nq
 *                emxArray_int32_T *iwork
 *                emxArray_int32_T *xwork
 * Return Type  : void
 */
static void b_merge(emxArray_int32_T *idx, emxArray_int32_T *x, int offset, int
                    np, int nq, emxArray_int32_T *iwork, emxArray_int32_T *xwork)
{
  int n_tmp;
  int iout;
  int p;
  int i50;
  int q;
  int exitg1;
  if ((np == 0) || (nq == 0)) {
  } else {
    n_tmp = np + nq;
    for (iout = 0; iout < n_tmp; iout++) {
      i50 = offset + iout;
      iwork->data[iout] = idx->data[i50];
      xwork->data[iout] = x->data[i50];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork->data[p] >= xwork->data[q]) {
        idx->data[iout] = iwork->data[p];
        x->data[iout] = xwork->data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx->data[iout] = iwork->data[q];
        x->data[iout] = xwork->data[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          for (iout = p + 1; iout <= np; iout++) {
            i50 = q + iout;
            idx->data[i50] = iwork->data[iout - 1];
            x->data[i50] = xwork->data[iout - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/*
 * Arguments    : emxArray_int32_T *idx
 *                emxArray_int32_T *x
 *                int offset
 *                int n
 *                int preSortLevel
 *                emxArray_int32_T *iwork
 *                emxArray_int32_T *xwork
 * Return Type  : void
 */
static void b_merge_block(emxArray_int32_T *idx, emxArray_int32_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_int32_T *xwork)
{
  int nPairs;
  int bLen;
  int tailOffset;
  int nTail;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        b_merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      b_merge(idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    b_merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

/*
 * Arguments    : emxArray_int32_T *idx
 *                emxArray_real_T *x
 *                int offset
 *                int np
 *                int nq
 *                emxArray_int32_T *iwork
 *                emxArray_real_T *xwork
 * Return Type  : void
 */
static void c_merge(emxArray_int32_T *idx, emxArray_real_T *x, int offset, int
                    np, int nq, emxArray_int32_T *iwork, emxArray_real_T *xwork)
{
  int n_tmp;
  int iout;
  int p;
  int i54;
  int q;
  int exitg1;
  if ((np == 0) || (nq == 0)) {
  } else {
    n_tmp = np + nq;
    for (iout = 0; iout < n_tmp; iout++) {
      i54 = offset + iout;
      iwork->data[iout] = idx->data[i54];
      xwork->data[iout] = x->data[i54];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork->data[p] <= xwork->data[q]) {
        idx->data[iout] = iwork->data[p];
        x->data[iout] = xwork->data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx->data[iout] = iwork->data[q];
        x->data[iout] = xwork->data[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          for (iout = p + 1; iout <= np; iout++) {
            i54 = q + iout;
            idx->data[i54] = iwork->data[iout - 1];
            x->data[i54] = xwork->data[iout - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/*
 * Arguments    : emxArray_int32_T *idx
 *                emxArray_real_T *x
 *                int offset
 *                int n
 *                int preSortLevel
 *                emxArray_int32_T *iwork
 *                emxArray_real_T *xwork
 * Return Type  : void
 */
static void c_merge_block(emxArray_int32_T *idx, emxArray_real_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_real_T *xwork)
{
  int nPairs;
  int bLen;
  int tailOffset;
  int nTail;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        c_merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      c_merge(idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    c_merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

/*
 * Arguments    : emxArray_int32_T *idx
 *                emxArray_int32_T *x
 *                int offset
 *                int np
 *                int nq
 *                emxArray_int32_T *iwork
 *                emxArray_int32_T *xwork
 * Return Type  : void
 */
static void d_merge(emxArray_int32_T *idx, emxArray_int32_T *x, int offset, int
                    np, int nq, emxArray_int32_T *iwork, emxArray_int32_T *xwork)
{
  int n_tmp;
  int iout;
  int p;
  int i58;
  int q;
  int exitg1;
  if ((np == 0) || (nq == 0)) {
  } else {
    n_tmp = np + nq;
    for (iout = 0; iout < n_tmp; iout++) {
      i58 = offset + iout;
      iwork->data[iout] = idx->data[i58];
      xwork->data[iout] = x->data[i58];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork->data[p] <= xwork->data[q]) {
        idx->data[iout] = iwork->data[p];
        x->data[iout] = xwork->data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx->data[iout] = iwork->data[q];
        x->data[iout] = xwork->data[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          for (iout = p + 1; iout <= np; iout++) {
            i58 = q + iout;
            idx->data[i58] = iwork->data[iout - 1];
            x->data[i58] = xwork->data[iout - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/*
 * Arguments    : emxArray_int32_T *idx
 *                emxArray_int32_T *x
 *                int offset
 *                int n
 *                int preSortLevel
 *                emxArray_int32_T *iwork
 *                emxArray_int32_T *xwork
 * Return Type  : void
 */
static void d_merge_block(emxArray_int32_T *idx, emxArray_int32_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_int32_T *xwork)
{
  int nPairs;
  int bLen;
  int tailOffset;
  int nTail;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        d_merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      d_merge(idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    d_merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

/*
 * Arguments    : int idx[2000]
 *                double x[2000]
 *                int offset
 *                int np
 *                int nq
 *                int iwork[2000]
 *                double xwork[2000]
 * Return Type  : void
 */
static void merge(int idx[2000], double x[2000], int offset, int np, int nq, int
                  iwork[2000], double xwork[2000])
{
  int n_tmp;
  int iout;
  int p;
  int i35;
  int q;
  int exitg1;
  if ((np == 0) || (nq == 0)) {
  } else {
    n_tmp = np + nq;
    for (iout = 0; iout < n_tmp; iout++) {
      i35 = offset + iout;
      iwork[iout] = idx[i35];
      xwork[iout] = x[i35];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork[p] <= xwork[q]) {
        idx[iout] = iwork[p];
        x[iout] = xwork[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx[iout] = iwork[q];
        x[iout] = xwork[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          for (iout = p + 1; iout <= np; iout++) {
            i35 = q + iout;
            idx[i35] = iwork[iout - 1];
            x[i35] = xwork[iout - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

/*
 * Arguments    : emxArray_int32_T *x
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
void b_sortIdx(emxArray_int32_T *x, emxArray_int32_T *idx)
{
  unsigned int unnamed_idx_0;
  int i48;
  int i1;
  emxArray_int32_T *b_idx;
  emxArray_int32_T *b_x;
  int x4[4];
  int idx4[4];
  emxArray_int32_T *iwork;
  int i49;
  emxArray_int32_T *xwork;
  int nQuartets;
  int j;
  int i2;
  int i;
  int i3;
  int k;
  signed char perm[4];
  int offset;
  int b;
  int bLen;
  int bLen2;
  int i4;
  int nPairs;
  int b_iwork[256];
  int b_xwork[256];
  int exitg1;
  unnamed_idx_0 = (unsigned int)x->size[0];
  i48 = idx->size[0];
  idx->size[0] = (int)unnamed_idx_0;
  emxEnsureCapacity_int32_T(idx, i48);
  i1 = (int)unnamed_idx_0;
  for (i48 = 0; i48 < i1; i48++) {
    idx->data[i48] = 0;
  }

  if (x->size[0] != 0) {
    emxInit_int32_T(&b_idx, 1);
    i1 = (int)unnamed_idx_0;
    i48 = b_idx->size[0];
    b_idx->size[0] = (int)unnamed_idx_0;
    emxEnsureCapacity_int32_T(b_idx, i48);
    for (i48 = 0; i48 < i1; i48++) {
      b_idx->data[i48] = 0;
    }

    emxInit_int32_T(&b_x, 1);
    i1 = x->size[0];
    i48 = b_x->size[0];
    b_x->size[0] = i1;
    emxEnsureCapacity_int32_T(b_x, i48);
    for (i48 = 0; i48 < i1; i48++) {
      b_x->data[i48] = x->data[i48];
    }

    i48 = x->size[0];
    x4[0] = 0;
    idx4[0] = 0;
    x4[1] = 0;
    idx4[1] = 0;
    x4[2] = 0;
    idx4[2] = 0;
    x4[3] = 0;
    idx4[3] = 0;
    emxInit_int32_T(&iwork, 1);
    i49 = iwork->size[0];
    iwork->size[0] = (int)unnamed_idx_0;
    emxEnsureCapacity_int32_T(iwork, i49);
    i1 = (int)unnamed_idx_0;
    for (i49 = 0; i49 < i1; i49++) {
      iwork->data[i49] = 0;
    }

    emxInit_int32_T(&xwork, 1);
    i1 = x->size[0];
    i49 = xwork->size[0];
    xwork->size[0] = i1;
    emxEnsureCapacity_int32_T(xwork, i49);
    for (i49 = 0; i49 < i1; i49++) {
      xwork->data[i49] = 0;
    }

    i49 = x->size[0];
    nQuartets = i49 >> 2;
    for (j = 0; j < nQuartets; j++) {
      i = j << 2;
      idx4[0] = i + 1;
      idx4[1] = i + 2;
      idx4[2] = i + 3;
      idx4[3] = i + 4;
      x4[0] = b_x->data[i];
      x4[1] = b_x->data[i + 1];
      x4[2] = b_x->data[i + 2];
      x4[3] = b_x->data[i + 3];
      if (b_x->data[i] >= b_x->data[i + 1]) {
        i1 = 1;
        i2 = 2;
      } else {
        i1 = 2;
        i2 = 1;
      }

      if (b_x->data[i + 2] >= b_x->data[i + 3]) {
        i3 = 3;
        i4 = 4;
      } else {
        i3 = 4;
        i4 = 3;
      }

      i49 = x4[i1 - 1];
      offset = x4[i3 - 1];
      if (i49 >= offset) {
        i49 = x4[i2 - 1];
        if (i49 >= offset) {
          perm[0] = (signed char)i1;
          perm[1] = (signed char)i2;
          perm[2] = (signed char)i3;
          perm[3] = (signed char)i4;
        } else if (i49 >= x4[i4 - 1]) {
          perm[0] = (signed char)i1;
          perm[1] = (signed char)i3;
          perm[2] = (signed char)i2;
          perm[3] = (signed char)i4;
        } else {
          perm[0] = (signed char)i1;
          perm[1] = (signed char)i3;
          perm[2] = (signed char)i4;
          perm[3] = (signed char)i2;
        }
      } else {
        offset = x4[i4 - 1];
        if (i49 >= offset) {
          if (x4[i2 - 1] >= offset) {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)i1;
            perm[2] = (signed char)i2;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)i1;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)i2;
          }
        } else {
          perm[0] = (signed char)i3;
          perm[1] = (signed char)i4;
          perm[2] = (signed char)i1;
          perm[3] = (signed char)i2;
        }
      }

      i49 = perm[0] - 1;
      b_idx->data[i] = idx4[i49];
      offset = perm[1] - 1;
      b_idx->data[i + 1] = idx4[offset];
      i1 = perm[2] - 1;
      b_idx->data[i + 2] = idx4[i1];
      i2 = perm[3] - 1;
      b_idx->data[i + 3] = idx4[i2];
      b_x->data[i] = x4[i49];
      b_x->data[i + 1] = x4[offset];
      b_x->data[i + 2] = x4[i1];
      b_x->data[i + 3] = x4[i2];
    }

    i2 = nQuartets << 2;
    i49 = x->size[0];
    i3 = i49 - i2;
    if (i3 > 0) {
      for (k = 0; k < i3; k++) {
        i1 = i2 + k;
        idx4[k] = i1 + 1;
        x4[k] = b_x->data[i1];
      }

      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (i3 == 1) {
        perm[0] = 1;
      } else if (i3 == 2) {
        if (x4[0] >= x4[1]) {
          perm[0] = 1;
          perm[1] = 2;
        } else {
          perm[0] = 2;
          perm[1] = 1;
        }
      } else if (x4[0] >= x4[1]) {
        if (x4[1] >= x4[2]) {
          perm[0] = 1;
          perm[1] = 2;
          perm[2] = 3;
        } else if (x4[0] >= x4[2]) {
          perm[0] = 1;
          perm[1] = 3;
          perm[2] = 2;
        } else {
          perm[0] = 3;
          perm[1] = 1;
          perm[2] = 2;
        }
      } else if (x4[0] >= x4[2]) {
        perm[0] = 2;
        perm[1] = 1;
        perm[2] = 3;
      } else if (x4[1] >= x4[2]) {
        perm[0] = 2;
        perm[1] = 3;
        perm[2] = 1;
      } else {
        perm[0] = 3;
        perm[1] = 2;
        perm[2] = 1;
      }

      for (k = 0; k < i3; k++) {
        i49 = i2 + k;
        b_idx->data[i49] = idx4[perm[k] - 1];
        b_x->data[i49] = x4[perm[k] - 1];
      }
    }

    i1 = 2;
    if (i48 > 1) {
      if (i48 >= 256) {
        nQuartets = i48 >> 8;
        for (i = 0; i < nQuartets; i++) {
          offset = i << 8;
          for (b = 0; b < 6; b++) {
            bLen = 1 << (b + 2);
            bLen2 = bLen << 1;
            nPairs = 256 >> (b + 3);
            for (k = 0; k < nPairs; k++) {
              i3 = offset + k * bLen2;
              for (j = 0; j < bLen2; j++) {
                i1 = i3 + j;
                b_iwork[j] = b_idx->data[i1];
                b_xwork[j] = b_x->data[i1];
              }

              i4 = 0;
              i2 = bLen;
              i1 = i3 - 1;
              do {
                exitg1 = 0;
                i1++;
                if (b_xwork[i4] >= b_xwork[i2]) {
                  b_idx->data[i1] = b_iwork[i4];
                  b_x->data[i1] = b_xwork[i4];
                  if (i4 + 1 < bLen) {
                    i4++;
                  } else {
                    exitg1 = 1;
                  }
                } else {
                  b_idx->data[i1] = b_iwork[i2];
                  b_x->data[i1] = b_xwork[i2];
                  if (i2 + 1 < bLen2) {
                    i2++;
                  } else {
                    i1 -= i4;
                    for (j = i4 + 1; j <= bLen; j++) {
                      i49 = i1 + j;
                      b_idx->data[i49] = b_iwork[j - 1];
                      b_x->data[i49] = b_xwork[j - 1];
                    }

                    exitg1 = 1;
                  }
                }
              } while (exitg1 == 0);
            }
          }
        }

        i1 = nQuartets << 8;
        i2 = i48 - i1;
        if (i2 > 0) {
          b_merge_block(b_idx, b_x, i1, i2, 2, iwork, xwork);
        }

        i1 = 8;
      }

      b_merge_block(b_idx, b_x, 0, i48, i1, iwork, xwork);
    }

    emxFree_int32_T(&xwork);
    emxFree_int32_T(&iwork);
    i1 = b_idx->size[0];
    for (i48 = 0; i48 < i1; i48++) {
      idx->data[i48] = b_idx->data[i48];
    }

    emxFree_int32_T(&b_idx);
    i1 = b_x->size[0];
    for (i48 = 0; i48 < i1; i48++) {
      x->data[i48] = b_x->data[i48];
    }

    emxFree_int32_T(&b_x);
  }
}

/*
 * Arguments    : emxArray_real_T *x
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
void c_sortIdx(emxArray_real_T *x, emxArray_int32_T *idx)
{
  unsigned int unnamed_idx_0;
  int i52;
  int ib;
  emxArray_int32_T *b_idx;
  emxArray_real_T *b_x;
  int i53;
  double x4[4];
  int idx4[4];
  emxArray_int32_T *iwork;
  int i4;
  emxArray_real_T *xwork;
  int k;
  signed char perm[4];
  int nBlocks;
  int i1;
  int b;
  int offset;
  int b_b;
  int i3;
  int bLen;
  int bLen2;
  double d13;
  int nPairs;
  double d14;
  int b_iwork[256];
  double b_xwork[256];
  int exitg1;
  unnamed_idx_0 = (unsigned int)x->size[0];
  i52 = idx->size[0];
  idx->size[0] = (int)unnamed_idx_0;
  emxEnsureCapacity_int32_T(idx, i52);
  ib = (int)unnamed_idx_0;
  for (i52 = 0; i52 < ib; i52++) {
    idx->data[i52] = 0;
  }

  if (x->size[0] != 0) {
    emxInit_int32_T(&b_idx, 1);
    ib = (int)unnamed_idx_0;
    i52 = b_idx->size[0];
    b_idx->size[0] = (int)unnamed_idx_0;
    emxEnsureCapacity_int32_T(b_idx, i52);
    for (i52 = 0; i52 < ib; i52++) {
      b_idx->data[i52] = 0;
    }

    emxInit_real_T(&b_x, 1);
    ib = x->size[0];
    i52 = b_x->size[0];
    b_x->size[0] = ib;
    emxEnsureCapacity_real_T(b_x, i52);
    for (i52 = 0; i52 < ib; i52++) {
      b_x->data[i52] = x->data[i52];
    }

    i52 = x->size[0];
    i53 = x->size[0] - 1;
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    emxInit_int32_T(&iwork, 1);
    i4 = iwork->size[0];
    iwork->size[0] = (int)unnamed_idx_0;
    emxEnsureCapacity_int32_T(iwork, i4);
    ib = (int)unnamed_idx_0;
    for (i4 = 0; i4 < ib; i4++) {
      iwork->data[i4] = 0;
    }

    emxInit_real_T(&xwork, 1);
    ib = x->size[0];
    i4 = xwork->size[0];
    xwork->size[0] = ib;
    emxEnsureCapacity_real_T(xwork, i4);
    for (i4 = 0; i4 < ib; i4++) {
      xwork->data[i4] = 0.0;
    }

    ib = -1;
    for (k = 0; k <= i53; k++) {
      ib++;
      idx4[ib] = k + 1;
      x4[ib] = b_x->data[k];
      if (ib + 1 == 4) {
        if (x4[0] <= x4[1]) {
          i1 = 1;
          ib = 2;
        } else {
          i1 = 2;
          ib = 1;
        }

        if (x4[2] <= x4[3]) {
          i3 = 3;
          i4 = 4;
        } else {
          i3 = 4;
          i4 = 3;
        }

        d13 = x4[i1 - 1];
        d14 = x4[i3 - 1];
        if (d13 <= d14) {
          d13 = x4[ib - 1];
          if (d13 <= d14) {
            perm[0] = (signed char)i1;
            perm[1] = (signed char)ib;
            perm[2] = (signed char)i3;
            perm[3] = (signed char)i4;
          } else if (d13 <= x4[i4 - 1]) {
            perm[0] = (signed char)i1;
            perm[1] = (signed char)i3;
            perm[2] = (signed char)ib;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)i1;
            perm[1] = (signed char)i3;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)ib;
          }
        } else {
          d14 = x4[i4 - 1];
          if (d13 <= d14) {
            if (x4[ib - 1] <= d14) {
              perm[0] = (signed char)i3;
              perm[1] = (signed char)i1;
              perm[2] = (signed char)ib;
              perm[3] = (signed char)i4;
            } else {
              perm[0] = (signed char)i3;
              perm[1] = (signed char)i1;
              perm[2] = (signed char)i4;
              perm[3] = (signed char)ib;
            }
          } else {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)i4;
            perm[2] = (signed char)i1;
            perm[3] = (signed char)ib;
          }
        }

        i4 = perm[0] - 1;
        b_idx->data[k - 3] = idx4[i4];
        ib = perm[1] - 1;
        b_idx->data[k - 2] = idx4[ib];
        i1 = perm[2] - 1;
        b_idx->data[k - 1] = idx4[i1];
        i3 = perm[3] - 1;
        b_idx->data[k] = idx4[i3];
        b_x->data[k - 3] = x4[i4];
        b_x->data[k - 2] = x4[ib];
        b_x->data[k - 1] = x4[i1];
        b_x->data[k] = x4[i3];
        ib = -1;
      }
    }

    if (ib + 1 > 0) {
      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (ib + 1 == 1) {
        perm[0] = 1;
      } else if (ib + 1 == 2) {
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

      for (k = 0; k <= ib; k++) {
        i4 = (i53 - ib) + k;
        b_idx->data[i4] = idx4[perm[k] - 1];
        b_x->data[i4] = x4[perm[k] - 1];
      }
    }

    ib = 2;
    if (i52 > 1) {
      if (i52 >= 256) {
        nBlocks = i52 >> 8;
        for (b = 0; b < nBlocks; b++) {
          offset = b << 8;
          for (b_b = 0; b_b < 6; b_b++) {
            bLen = 1 << (b_b + 2);
            bLen2 = bLen << 1;
            nPairs = 256 >> (b_b + 3);
            for (k = 0; k < nPairs; k++) {
              i3 = offset + k * bLen2;
              for (i1 = 0; i1 < bLen2; i1++) {
                ib = i3 + i1;
                b_iwork[i1] = b_idx->data[ib];
                b_xwork[i1] = b_x->data[ib];
              }

              i4 = 0;
              i1 = bLen;
              ib = i3 - 1;
              do {
                exitg1 = 0;
                ib++;
                if (b_xwork[i4] <= b_xwork[i1]) {
                  b_idx->data[ib] = b_iwork[i4];
                  b_x->data[ib] = b_xwork[i4];
                  if (i4 + 1 < bLen) {
                    i4++;
                  } else {
                    exitg1 = 1;
                  }
                } else {
                  b_idx->data[ib] = b_iwork[i1];
                  b_x->data[ib] = b_xwork[i1];
                  if (i1 + 1 < bLen2) {
                    i1++;
                  } else {
                    ib -= i4;
                    for (i1 = i4 + 1; i1 <= bLen; i1++) {
                      i53 = ib + i1;
                      b_idx->data[i53] = b_iwork[i1 - 1];
                      b_x->data[i53] = b_xwork[i1 - 1];
                    }

                    exitg1 = 1;
                  }
                }
              } while (exitg1 == 0);
            }
          }
        }

        ib = nBlocks << 8;
        i1 = i52 - ib;
        if (i1 > 0) {
          c_merge_block(b_idx, b_x, ib, i1, 2, iwork, xwork);
        }

        ib = 8;
      }

      c_merge_block(b_idx, b_x, 0, i52, ib, iwork, xwork);
    }

    emxFree_real_T(&xwork);
    emxFree_int32_T(&iwork);
    ib = b_idx->size[0];
    for (i52 = 0; i52 < ib; i52++) {
      idx->data[i52] = b_idx->data[i52];
    }

    emxFree_int32_T(&b_idx);
    ib = b_x->size[0];
    for (i52 = 0; i52 < ib; i52++) {
      x->data[i52] = b_x->data[i52];
    }

    emxFree_real_T(&b_x);
  }
}

/*
 * Arguments    : emxArray_int32_T *x
 *                emxArray_int32_T *idx
 * Return Type  : void
 */
void d_sortIdx(emxArray_int32_T *x, emxArray_int32_T *idx)
{
  unsigned int unnamed_idx_0;
  int i56;
  int i1;
  emxArray_int32_T *b_idx;
  emxArray_int32_T *b_x;
  int x4[4];
  int idx4[4];
  emxArray_int32_T *iwork;
  int i57;
  emxArray_int32_T *xwork;
  int nQuartets;
  int j;
  int i2;
  int i;
  int i3;
  int k;
  signed char perm[4];
  int offset;
  int b;
  int bLen;
  int bLen2;
  int i4;
  int nPairs;
  int b_iwork[256];
  int b_xwork[256];
  int exitg1;
  unnamed_idx_0 = (unsigned int)x->size[0];
  i56 = idx->size[0];
  idx->size[0] = (int)unnamed_idx_0;
  emxEnsureCapacity_int32_T(idx, i56);
  i1 = (int)unnamed_idx_0;
  for (i56 = 0; i56 < i1; i56++) {
    idx->data[i56] = 0;
  }

  if (x->size[0] != 0) {
    emxInit_int32_T(&b_idx, 1);
    i1 = (int)unnamed_idx_0;
    i56 = b_idx->size[0];
    b_idx->size[0] = (int)unnamed_idx_0;
    emxEnsureCapacity_int32_T(b_idx, i56);
    for (i56 = 0; i56 < i1; i56++) {
      b_idx->data[i56] = 0;
    }

    emxInit_int32_T(&b_x, 1);
    i1 = x->size[0];
    i56 = b_x->size[0];
    b_x->size[0] = i1;
    emxEnsureCapacity_int32_T(b_x, i56);
    for (i56 = 0; i56 < i1; i56++) {
      b_x->data[i56] = x->data[i56];
    }

    i56 = x->size[0];
    x4[0] = 0;
    idx4[0] = 0;
    x4[1] = 0;
    idx4[1] = 0;
    x4[2] = 0;
    idx4[2] = 0;
    x4[3] = 0;
    idx4[3] = 0;
    emxInit_int32_T(&iwork, 1);
    i57 = iwork->size[0];
    iwork->size[0] = (int)unnamed_idx_0;
    emxEnsureCapacity_int32_T(iwork, i57);
    i1 = (int)unnamed_idx_0;
    for (i57 = 0; i57 < i1; i57++) {
      iwork->data[i57] = 0;
    }

    emxInit_int32_T(&xwork, 1);
    i1 = x->size[0];
    i57 = xwork->size[0];
    xwork->size[0] = i1;
    emxEnsureCapacity_int32_T(xwork, i57);
    for (i57 = 0; i57 < i1; i57++) {
      xwork->data[i57] = 0;
    }

    i57 = x->size[0];
    nQuartets = i57 >> 2;
    for (j = 0; j < nQuartets; j++) {
      i = j << 2;
      idx4[0] = i + 1;
      idx4[1] = i + 2;
      idx4[2] = i + 3;
      idx4[3] = i + 4;
      x4[0] = b_x->data[i];
      x4[1] = b_x->data[i + 1];
      x4[2] = b_x->data[i + 2];
      x4[3] = b_x->data[i + 3];
      if (b_x->data[i] <= b_x->data[i + 1]) {
        i1 = 1;
        i2 = 2;
      } else {
        i1 = 2;
        i2 = 1;
      }

      if (b_x->data[i + 2] <= b_x->data[i + 3]) {
        i3 = 3;
        i4 = 4;
      } else {
        i3 = 4;
        i4 = 3;
      }

      i57 = x4[i1 - 1];
      offset = x4[i3 - 1];
      if (i57 <= offset) {
        i57 = x4[i2 - 1];
        if (i57 <= offset) {
          perm[0] = (signed char)i1;
          perm[1] = (signed char)i2;
          perm[2] = (signed char)i3;
          perm[3] = (signed char)i4;
        } else if (i57 <= x4[i4 - 1]) {
          perm[0] = (signed char)i1;
          perm[1] = (signed char)i3;
          perm[2] = (signed char)i2;
          perm[3] = (signed char)i4;
        } else {
          perm[0] = (signed char)i1;
          perm[1] = (signed char)i3;
          perm[2] = (signed char)i4;
          perm[3] = (signed char)i2;
        }
      } else {
        offset = x4[i4 - 1];
        if (i57 <= offset) {
          if (x4[i2 - 1] <= offset) {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)i1;
            perm[2] = (signed char)i2;
            perm[3] = (signed char)i4;
          } else {
            perm[0] = (signed char)i3;
            perm[1] = (signed char)i1;
            perm[2] = (signed char)i4;
            perm[3] = (signed char)i2;
          }
        } else {
          perm[0] = (signed char)i3;
          perm[1] = (signed char)i4;
          perm[2] = (signed char)i1;
          perm[3] = (signed char)i2;
        }
      }

      i57 = perm[0] - 1;
      b_idx->data[i] = idx4[i57];
      offset = perm[1] - 1;
      b_idx->data[i + 1] = idx4[offset];
      i1 = perm[2] - 1;
      b_idx->data[i + 2] = idx4[i1];
      i2 = perm[3] - 1;
      b_idx->data[i + 3] = idx4[i2];
      b_x->data[i] = x4[i57];
      b_x->data[i + 1] = x4[offset];
      b_x->data[i + 2] = x4[i1];
      b_x->data[i + 3] = x4[i2];
    }

    i2 = nQuartets << 2;
    i57 = x->size[0];
    i3 = i57 - i2;
    if (i3 > 0) {
      for (k = 0; k < i3; k++) {
        i1 = i2 + k;
        idx4[k] = i1 + 1;
        x4[k] = b_x->data[i1];
      }

      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (i3 == 1) {
        perm[0] = 1;
      } else if (i3 == 2) {
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

      for (k = 0; k < i3; k++) {
        i57 = i2 + k;
        b_idx->data[i57] = idx4[perm[k] - 1];
        b_x->data[i57] = x4[perm[k] - 1];
      }
    }

    i1 = 2;
    if (i56 > 1) {
      if (i56 >= 256) {
        nQuartets = i56 >> 8;
        for (i = 0; i < nQuartets; i++) {
          offset = i << 8;
          for (b = 0; b < 6; b++) {
            bLen = 1 << (b + 2);
            bLen2 = bLen << 1;
            nPairs = 256 >> (b + 3);
            for (k = 0; k < nPairs; k++) {
              i3 = offset + k * bLen2;
              for (j = 0; j < bLen2; j++) {
                i1 = i3 + j;
                b_iwork[j] = b_idx->data[i1];
                b_xwork[j] = b_x->data[i1];
              }

              i4 = 0;
              i2 = bLen;
              i1 = i3 - 1;
              do {
                exitg1 = 0;
                i1++;
                if (b_xwork[i4] <= b_xwork[i2]) {
                  b_idx->data[i1] = b_iwork[i4];
                  b_x->data[i1] = b_xwork[i4];
                  if (i4 + 1 < bLen) {
                    i4++;
                  } else {
                    exitg1 = 1;
                  }
                } else {
                  b_idx->data[i1] = b_iwork[i2];
                  b_x->data[i1] = b_xwork[i2];
                  if (i2 + 1 < bLen2) {
                    i2++;
                  } else {
                    i1 -= i4;
                    for (j = i4 + 1; j <= bLen; j++) {
                      i57 = i1 + j;
                      b_idx->data[i57] = b_iwork[j - 1];
                      b_x->data[i57] = b_xwork[j - 1];
                    }

                    exitg1 = 1;
                  }
                }
              } while (exitg1 == 0);
            }
          }
        }

        i1 = nQuartets << 8;
        i2 = i56 - i1;
        if (i2 > 0) {
          d_merge_block(b_idx, b_x, i1, i2, 2, iwork, xwork);
        }

        i1 = 8;
      }

      d_merge_block(b_idx, b_x, 0, i56, i1, iwork, xwork);
    }

    emxFree_int32_T(&xwork);
    emxFree_int32_T(&iwork);
    i1 = b_idx->size[0];
    for (i56 = 0; i56 < i1; i56++) {
      idx->data[i56] = b_idx->data[i56];
    }

    emxFree_int32_T(&b_idx);
    i1 = b_x->size[0];
    for (i56 = 0; i56 < i1; i56++) {
      x->data[i56] = b_x->data[i56];
    }

    emxFree_int32_T(&b_x);
  }
}

/*
 * Arguments    : int idx[2000]
 *                double x[2000]
 *                int offset
 *                int n
 *                int preSortLevel
 *                int iwork[2000]
 *                double xwork[2000]
 * Return Type  : void
 */
void merge_block(int idx[2000], double x[2000], int offset, int n, int
                 preSortLevel, int iwork[2000], double xwork[2000])
{
  int nPairs;
  int bLen;
  int tailOffset;
  int nTail;
  nPairs = n >> preSortLevel;
  bLen = 1 << preSortLevel;
  while (nPairs > 1) {
    if ((nPairs & 1) != 0) {
      nPairs--;
      tailOffset = bLen * nPairs;
      nTail = n - tailOffset;
      if (nTail > bLen) {
        merge(idx, x, offset + tailOffset, bLen, nTail - bLen, iwork, xwork);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      merge(idx, x, offset + nTail * tailOffset, bLen, bLen, iwork, xwork);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    merge(idx, x, offset, bLen, n - bLen, iwork, xwork);
  }
}

/*
 * Arguments    : const double x[2000]
 *                int idx[2000]
 * Return Type  : void
 */
void sortIdx(const double x[2000], int idx[2000])
{
  int k;
  int i;
  int i2;
  int j;
  int pEnd;
  int p;
  int q;
  int qEnd;
  int kEnd;
  int i6;
  int i7;
  int iwork[2000];
  for (k = 0; k <= 1998; k += 2) {
    if (x[k] <= x[k + 1]) {
      idx[k] = k + 1;
      idx[k + 1] = k + 2;
    } else {
      idx[k] = k + 2;
      idx[k + 1] = k + 1;
    }
  }

  i = 2;
  while (i < 2000) {
    i2 = i << 1;
    j = 1;
    for (pEnd = 1 + i; pEnd < 2001; pEnd = qEnd + i) {
      p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > 2001) {
        qEnd = 2001;
      }

      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        i6 = idx[q - 1];
        i7 = idx[p - 1];
        if (x[i7 - 1] <= x[i6 - 1]) {
          iwork[k] = i7;
          p++;
          if (p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork[k] = idx[q - 1];
              q++;
            }
          }
        } else {
          iwork[k] = i6;
          q++;
          if (q == qEnd) {
            while (p < pEnd) {
              k++;
              iwork[k] = idx[p - 1];
              p++;
            }
          }
        }

        k++;
      }

      for (k = 0; k < kEnd; k++) {
        idx[(j + k) - 1] = iwork[k];
      }

      j = qEnd;
    }

    i = i2;
  }
}

/*
 * File trailer for sortIdx.c
 *
 * [EOF]
 */
