/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortIdx.c
 *
 * Code generation for function 'sortIdx'
 *
 */

/* Include files */
#include <string.h>
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
#include "sortIdx.h"
#include "model_emxutil.h"

/* Function Declarations */
static void b_merge(emxArray_int32_T *idx, emxArray_int32_T *x, int offset, int
                    np, int nq, emxArray_int32_T *iwork, emxArray_int32_T *xwork);
static void b_merge_block(emxArray_int32_T *idx, emxArray_int32_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_int32_T *xwork);
static void c_merge(int idx[2000], double x[2000], int offset, int np, int nq,
                    int iwork[2000], double xwork[2000]);
static void d_merge(emxArray_int32_T *idx, emxArray_int32_T *x, int offset, int
                    np, int nq, emxArray_int32_T *iwork, emxArray_int32_T *xwork);
static void e_merge(int idx_data[], int x_data[], int offset, int np, int nq,
                    int iwork_data[], int xwork_data[]);
static void e_merge_block(int idx_data[], int x_data[], int offset, int n, int
  preSortLevel, int iwork_data[], int xwork_data[]);
static void merge(emxArray_int32_T *idx, emxArray_real_T *x, int offset, int np,
                  int nq, emxArray_int32_T *iwork, emxArray_real_T *xwork);
static void merge_block(emxArray_int32_T *idx, emxArray_real_T *x, int offset,
  int n, int preSortLevel, emxArray_int32_T *iwork, emxArray_real_T *xwork);
static void merge_pow2_block(int idx_data[], int x_data[], int offset);

/* Function Definitions */
static void b_merge(emxArray_int32_T *idx, emxArray_int32_T *x, int offset, int
                    np, int nq, emxArray_int32_T *iwork, emxArray_int32_T *xwork)
{
  int n_tmp;
  int iout;
  int p;
  int i78;
  int q;
  int exitg1;
  if (nq != 0) {
    n_tmp = np + nq;
    for (iout = 0; iout < n_tmp; iout++) {
      i78 = offset + iout;
      iwork->data[iout] = idx->data[i78];
      xwork->data[iout] = x->data[i78];
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
            i78 = q + iout;
            idx->data[i78] = iwork->data[iout - 1];
            x->data[i78] = xwork->data[iout - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

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

static void c_merge(int idx[2000], double x[2000], int offset, int np, int nq,
                    int iwork[2000], double xwork[2000])
{
  int n_tmp;
  int iout;
  int p;
  int i79;
  int q;
  int exitg1;
  if (nq != 0) {
    n_tmp = np + nq;
    for (iout = 0; iout < n_tmp; iout++) {
      i79 = offset + iout;
      iwork[iout] = idx[i79];
      xwork[iout] = x[i79];
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
            i79 = q + iout;
            idx[i79] = iwork[iout - 1];
            x[i79] = xwork[iout - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void d_merge(emxArray_int32_T *idx, emxArray_int32_T *x, int offset, int
                    np, int nq, emxArray_int32_T *iwork, emxArray_int32_T *xwork)
{
  int n_tmp;
  int iout;
  int p;
  int i93;
  int q;
  int exitg1;
  if (nq != 0) {
    n_tmp = np + nq;
    for (iout = 0; iout < n_tmp; iout++) {
      i93 = offset + iout;
      iwork->data[iout] = idx->data[i93];
      xwork->data[iout] = x->data[i93];
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
            i93 = q + iout;
            idx->data[i93] = iwork->data[iout - 1];
            x->data[i93] = xwork->data[iout - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void e_merge(int idx_data[], int x_data[], int offset, int np, int nq,
                    int iwork_data[], int xwork_data[])
{
  int n_tmp;
  int iout;
  int p;
  int i96;
  int q;
  int exitg1;
  if (nq != 0) {
    n_tmp = np + nq;
    for (iout = 0; iout < n_tmp; iout++) {
      i96 = offset + iout;
      iwork_data[iout] = idx_data[i96];
      xwork_data[iout] = x_data[i96];
    }

    p = 0;
    q = np;
    iout = offset - 1;
    do {
      exitg1 = 0;
      iout++;
      if (xwork_data[p] >= xwork_data[q]) {
        idx_data[iout] = iwork_data[p];
        x_data[iout] = xwork_data[p];
        if (p + 1 < np) {
          p++;
        } else {
          exitg1 = 1;
        }
      } else {
        idx_data[iout] = iwork_data[q];
        x_data[iout] = xwork_data[q];
        if (q + 1 < n_tmp) {
          q++;
        } else {
          q = iout - p;
          for (iout = p + 1; iout <= np; iout++) {
            i96 = q + iout;
            idx_data[i96] = iwork_data[iout - 1];
            x_data[i96] = xwork_data[iout - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void e_merge_block(int idx_data[], int x_data[], int offset, int n, int
  preSortLevel, int iwork_data[], int xwork_data[])
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
        e_merge(idx_data, x_data, offset + tailOffset, bLen, nTail - bLen,
                iwork_data, xwork_data);
      }
    }

    tailOffset = bLen << 1;
    nPairs >>= 1;
    for (nTail = 0; nTail < nPairs; nTail++) {
      e_merge(idx_data, x_data, offset + nTail * tailOffset, bLen, bLen,
              iwork_data, xwork_data);
    }

    bLen = tailOffset;
  }

  if (n > bLen) {
    e_merge(idx_data, x_data, offset, bLen, n - bLen, iwork_data, xwork_data);
  }
}

static void merge(emxArray_int32_T *idx, emxArray_real_T *x, int offset, int np,
                  int nq, emxArray_int32_T *iwork, emxArray_real_T *xwork)
{
  int n_tmp;
  int iout;
  int p;
  int i74;
  int q;
  int exitg1;
  if (nq != 0) {
    n_tmp = np + nq;
    for (iout = 0; iout < n_tmp; iout++) {
      i74 = offset + iout;
      iwork->data[iout] = idx->data[i74];
      xwork->data[iout] = x->data[i74];
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
            i74 = q + iout;
            idx->data[i74] = iwork->data[iout - 1];
            x->data[i74] = xwork->data[iout - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

static void merge_block(emxArray_int32_T *idx, emxArray_real_T *x, int offset,
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

static void merge_pow2_block(int idx_data[], int x_data[], int offset)
{
  int b;
  int bLen;
  int bLen2;
  int nPairs;
  int k;
  int blockOffset;
  int j;
  int p;
  int iout;
  int q;
  int iwork[256];
  int xwork[256];
  int exitg1;
  for (b = 0; b < 6; b++) {
    bLen = 1 << (b + 2);
    bLen2 = bLen << 1;
    nPairs = 256 >> (b + 3);
    for (k = 0; k < nPairs; k++) {
      blockOffset = offset + k * bLen2;
      for (j = 0; j < bLen2; j++) {
        iout = blockOffset + j;
        iwork[j] = idx_data[iout];
        xwork[j] = x_data[iout];
      }

      p = 0;
      q = bLen;
      iout = blockOffset - 1;
      do {
        exitg1 = 0;
        iout++;
        if (xwork[p] >= xwork[q]) {
          idx_data[iout] = iwork[p];
          x_data[iout] = xwork[p];
          if (p + 1 < bLen) {
            p++;
          } else {
            exitg1 = 1;
          }
        } else {
          idx_data[iout] = iwork[q];
          x_data[iout] = xwork[q];
          if (q + 1 < bLen2) {
            q++;
          } else {
            iout -= p;
            for (j = p + 1; j <= bLen; j++) {
              q = iout + j;
              idx_data[q] = iwork[j - 1];
              x_data[q] = xwork[j - 1];
            }

            exitg1 = 1;
          }
        }
      } while (exitg1 == 0);
    }
  }
}

void b_sortIdx(emxArray_real_T *x, emxArray_int32_T *idx)
{
  int ib;
  int i73;
  int n;
  int b_n;
  double x4[4];
  int idx4[4];
  emxArray_int32_T *iwork;
  emxArray_real_T *xwork;
  int k;
  signed char perm[4];
  int i1;
  int b;
  int offset;
  int b_b;
  int i3;
  int i4;
  int bLen;
  int bLen2;
  double d24;
  int nPairs;
  double d25;
  int b_iwork[256];
  double b_xwork[256];
  int exitg1;
  ib = x->size[0];
  i73 = idx->size[0];
  idx->size[0] = ib;
  emxEnsureCapacity_int32_T(idx, i73);
  for (i73 = 0; i73 < ib; i73++) {
    idx->data[i73] = 0;
  }

  if (x->size[0] != 0) {
    n = x->size[0];
    b_n = x->size[0] - 1;
    x4[0] = 0.0;
    idx4[0] = 0;
    x4[1] = 0.0;
    idx4[1] = 0;
    x4[2] = 0.0;
    idx4[2] = 0;
    x4[3] = 0.0;
    idx4[3] = 0;
    emxInit_int32_T(&iwork, 1);
    i73 = iwork->size[0];
    iwork->size[0] = ib;
    emxEnsureCapacity_int32_T(iwork, i73);
    for (i73 = 0; i73 < ib; i73++) {
      iwork->data[i73] = 0;
    }

    emxInit_real_T(&xwork, 1);
    ib = x->size[0];
    i73 = xwork->size[0];
    xwork->size[0] = ib;
    emxEnsureCapacity_real_T(xwork, i73);
    for (i73 = 0; i73 < ib; i73++) {
      xwork->data[i73] = 0.0;
    }

    ib = -1;
    for (k = 0; k <= b_n; k++) {
      ib++;
      idx4[ib] = k + 1;
      x4[ib] = x->data[k];
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

        d24 = x4[i1 - 1];
        d25 = x4[i3 - 1];
        if (d24 <= d25) {
          d24 = x4[ib - 1];
          if (d24 <= d25) {
            perm[0] = (signed char)i1;
            perm[1] = (signed char)ib;
            perm[2] = (signed char)i3;
            perm[3] = (signed char)i4;
          } else if (d24 <= x4[i4 - 1]) {
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
          d25 = x4[i4 - 1];
          if (d24 <= d25) {
            if (x4[ib - 1] <= d25) {
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

        i73 = perm[0] - 1;
        idx->data[k - 3] = idx4[i73];
        ib = perm[1] - 1;
        idx->data[k - 2] = idx4[ib];
        i1 = perm[2] - 1;
        idx->data[k - 1] = idx4[i1];
        i3 = perm[3] - 1;
        idx->data[k] = idx4[i3];
        x->data[k - 3] = x4[i73];
        x->data[k - 2] = x4[ib];
        x->data[k - 1] = x4[i1];
        x->data[k] = x4[i3];
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
        i73 = (b_n - ib) + k;
        idx->data[i73] = idx4[perm[k] - 1];
        x->data[i73] = x4[perm[k] - 1];
      }
    }

    ib = 2;
    if (n > 1) {
      if (n >= 256) {
        b_n = n >> 8;
        for (b = 0; b < b_n; b++) {
          offset = b << 8;
          for (b_b = 0; b_b < 6; b_b++) {
            bLen = 1 << (b_b + 2);
            bLen2 = bLen << 1;
            nPairs = 256 >> (b_b + 3);
            for (k = 0; k < nPairs; k++) {
              i3 = offset + k * bLen2;
              for (i1 = 0; i1 < bLen2; i1++) {
                ib = i3 + i1;
                b_iwork[i1] = idx->data[ib];
                b_xwork[i1] = x->data[ib];
              }

              i4 = 0;
              i1 = bLen;
              ib = i3 - 1;
              do {
                exitg1 = 0;
                ib++;
                if (b_xwork[i4] <= b_xwork[i1]) {
                  idx->data[ib] = b_iwork[i4];
                  x->data[ib] = b_xwork[i4];
                  if (i4 + 1 < bLen) {
                    i4++;
                  } else {
                    exitg1 = 1;
                  }
                } else {
                  idx->data[ib] = b_iwork[i1];
                  x->data[ib] = b_xwork[i1];
                  if (i1 + 1 < bLen2) {
                    i1++;
                  } else {
                    ib -= i4;
                    for (i1 = i4 + 1; i1 <= bLen; i1++) {
                      i73 = ib + i1;
                      idx->data[i73] = b_iwork[i1 - 1];
                      x->data[i73] = b_xwork[i1 - 1];
                    }

                    exitg1 = 1;
                  }
                }
              } while (exitg1 == 0);
            }
          }
        }

        ib = b_n << 8;
        i1 = n - ib;
        if (i1 > 0) {
          merge_block(idx, x, ib, i1, 2, iwork, xwork);
        }

        ib = 8;
      }

      merge_block(idx, x, 0, n, ib, iwork, xwork);
    }

    emxFree_real_T(&xwork);
    emxFree_int32_T(&iwork);
  }
}

void c_merge_block(int idx[2000], double x[2000], int offset, int n, int
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

void c_sortIdx(emxArray_int32_T *x, emxArray_int32_T *idx)
{
  int i1;
  int i77;
  int n;
  int b_n;
  int x4[4];
  int idx4[4];
  emxArray_int32_T *iwork;
  emxArray_int32_T *xwork;
  int nQuartets;
  int j;
  int i3;
  int i;
  int i2;
  int k;
  signed char perm[4];
  int offset;
  int bLen;
  int bLen2;
  int nPairs;
  int i4;
  int b_iwork[256];
  int b_xwork[256];
  int exitg1;
  i1 = x->size[0];
  i77 = idx->size[0];
  idx->size[0] = i1;
  emxEnsureCapacity_int32_T(idx, i77);
  for (i77 = 0; i77 < i1; i77++) {
    idx->data[i77] = 0;
  }

  if (x->size[0] != 0) {
    n = x->size[0];
    b_n = x->size[0];
    x4[0] = 0;
    idx4[0] = 0;
    x4[1] = 0;
    idx4[1] = 0;
    x4[2] = 0;
    idx4[2] = 0;
    x4[3] = 0;
    idx4[3] = 0;
    emxInit_int32_T(&iwork, 1);
    i77 = iwork->size[0];
    iwork->size[0] = i1;
    emxEnsureCapacity_int32_T(iwork, i77);
    for (i77 = 0; i77 < i1; i77++) {
      iwork->data[i77] = 0;
    }

    emxInit_int32_T(&xwork, 1);
    i1 = x->size[0];
    i77 = xwork->size[0];
    xwork->size[0] = i1;
    emxEnsureCapacity_int32_T(xwork, i77);
    for (i77 = 0; i77 < i1; i77++) {
      xwork->data[i77] = 0;
    }

    nQuartets = x->size[0] >> 2;
    for (j = 0; j < nQuartets; j++) {
      i = j << 2;
      idx4[0] = i + 1;
      idx4[1] = i + 2;
      idx4[2] = i + 3;
      idx4[3] = i + 4;
      x4[0] = x->data[i];
      x4[1] = x->data[i + 1];
      x4[2] = x->data[i + 2];
      x4[3] = x->data[i + 3];
      if (x->data[i] <= x->data[i + 1]) {
        i1 = 1;
        i2 = 2;
      } else {
        i1 = 2;
        i2 = 1;
      }

      if (x->data[i + 2] <= x->data[i + 3]) {
        i3 = 3;
        i4 = 4;
      } else {
        i3 = 4;
        i4 = 3;
      }

      i77 = x4[i1 - 1];
      offset = x4[i3 - 1];
      if (i77 <= offset) {
        i77 = x4[i2 - 1];
        if (i77 <= offset) {
          perm[0] = (signed char)i1;
          perm[1] = (signed char)i2;
          perm[2] = (signed char)i3;
          perm[3] = (signed char)i4;
        } else if (i77 <= x4[i4 - 1]) {
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
        if (i77 <= offset) {
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

      i77 = perm[0] - 1;
      idx->data[i] = idx4[i77];
      offset = perm[1] - 1;
      idx->data[i + 1] = idx4[offset];
      i1 = perm[2] - 1;
      idx->data[i + 2] = idx4[i1];
      i2 = perm[3] - 1;
      idx->data[i + 3] = idx4[i2];
      x->data[i] = x4[i77];
      x->data[i + 1] = x4[offset];
      x->data[i + 2] = x4[i1];
      x->data[i + 3] = x4[i2];
    }

    i3 = nQuartets << 2;
    i2 = b_n - i3;
    if (i2 > 0) {
      for (k = 0; k < i2; k++) {
        i1 = i3 + k;
        idx4[k] = i1 + 1;
        x4[k] = x->data[i1];
      }

      perm[1] = 0;
      perm[2] = 0;
      perm[3] = 0;
      if (i2 == 1) {
        perm[0] = 1;
      } else if (i2 == 2) {
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

      for (k = 0; k < i2; k++) {
        i77 = i3 + k;
        idx->data[i77] = idx4[perm[k] - 1];
        x->data[i77] = x4[perm[k] - 1];
      }
    }

    i1 = 2;
    if (n > 1) {
      if (n >= 256) {
        nQuartets = n >> 8;
        for (i = 0; i < nQuartets; i++) {
          offset = i << 8;
          for (b_n = 0; b_n < 6; b_n++) {
            bLen = 1 << (b_n + 2);
            bLen2 = bLen << 1;
            nPairs = 256 >> (b_n + 3);
            for (k = 0; k < nPairs; k++) {
              i3 = offset + k * bLen2;
              for (j = 0; j < bLen2; j++) {
                i1 = i3 + j;
                b_iwork[j] = idx->data[i1];
                b_xwork[j] = x->data[i1];
              }

              i4 = 0;
              i2 = bLen;
              i1 = i3 - 1;
              do {
                exitg1 = 0;
                i1++;
                if (b_xwork[i4] <= b_xwork[i2]) {
                  idx->data[i1] = b_iwork[i4];
                  x->data[i1] = b_xwork[i4];
                  if (i4 + 1 < bLen) {
                    i4++;
                  } else {
                    exitg1 = 1;
                  }
                } else {
                  idx->data[i1] = b_iwork[i2];
                  x->data[i1] = b_xwork[i2];
                  if (i2 + 1 < bLen2) {
                    i2++;
                  } else {
                    i1 -= i4;
                    for (j = i4 + 1; j <= bLen; j++) {
                      i77 = i1 + j;
                      idx->data[i77] = b_iwork[j - 1];
                      x->data[i77] = b_xwork[j - 1];
                    }

                    exitg1 = 1;
                  }
                }
              } while (exitg1 == 0);
            }
          }
        }

        i1 = nQuartets << 8;
        i2 = n - i1;
        if (i2 > 0) {
          b_merge_block(idx, x, i1, i2, 2, iwork, xwork);
        }

        i1 = 8;
      }

      b_merge_block(idx, x, 0, n, i1, iwork, xwork);
    }

    emxFree_int32_T(&xwork);
    emxFree_int32_T(&iwork);
  }
}

void d_merge_block(emxArray_int32_T *idx, emxArray_int32_T *x, int offset, int n,
                   int preSortLevel, emxArray_int32_T *iwork, emxArray_int32_T
                   *xwork)
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

void d_sortIdx(int x_data[], int x_size[1], int idx_data[], int idx_size[1])
{
  short x_idx_0;
  int n;
  int x4[4];
  short idx4[4];
  int iwork_data[2000];
  int i3;
  int xwork_data[2000];
  int nQuartets;
  int j;
  int i4;
  int i;
  int nLeft;
  int k;
  signed char perm[4];
  int i1;
  int i2;
  x_idx_0 = (short)x_size[0];
  idx_size[0] = x_idx_0;
  if (0 <= x_idx_0 - 1) {
    memset(&idx_data[0], 0, (unsigned int)(x_idx_0 * (int)sizeof(int)));
  }

  n = x_size[0];
  x4[0] = 0;
  idx4[0] = 0;
  x4[1] = 0;
  idx4[1] = 0;
  x4[2] = 0;
  idx4[2] = 0;
  x4[3] = 0;
  idx4[3] = 0;
  if (0 <= x_idx_0 - 1) {
    memset(&iwork_data[0], 0, (unsigned int)(x_idx_0 * (int)sizeof(int)));
  }

  i3 = (short)x_size[0];
  if (0 <= i3 - 1) {
    memset(&xwork_data[0], 0, (unsigned int)(i3 * (int)sizeof(int)));
  }

  nQuartets = x_size[0] >> 2;
  for (j = 0; j < nQuartets; j++) {
    i = j << 2;
    idx4[0] = (short)(i + 1);
    idx4[1] = (short)(i + 2);
    idx4[2] = (short)(i + 3);
    idx4[3] = (short)(i + 4);
    x4[0] = x_data[i];
    i3 = x_data[i + 1];
    x4[1] = i3;
    i4 = x_data[i + 2];
    x4[2] = i4;
    nLeft = x_data[i + 3];
    x4[3] = nLeft;
    if (x_data[i] >= i3) {
      i1 = 1;
      i2 = 2;
    } else {
      i1 = 2;
      i2 = 1;
    }

    if (i4 >= nLeft) {
      i3 = 3;
      i4 = 4;
    } else {
      i3 = 4;
      i4 = 3;
    }

    nLeft = x4[i1 - 1];
    k = x4[i3 - 1];
    if (nLeft >= k) {
      nLeft = x4[i2 - 1];
      if (nLeft >= k) {
        perm[0] = (signed char)i1;
        perm[1] = (signed char)i2;
        perm[2] = (signed char)i3;
        perm[3] = (signed char)i4;
      } else if (nLeft >= x4[i4 - 1]) {
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
      k = x4[i4 - 1];
      if (nLeft >= k) {
        if (x4[i2 - 1] >= k) {
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

    i1 = perm[0] - 1;
    idx_data[i] = idx4[i1];
    i3 = perm[1] - 1;
    idx_data[i + 1] = idx4[i3];
    i4 = perm[2] - 1;
    idx_data[i + 2] = idx4[i4];
    nLeft = perm[3] - 1;
    idx_data[i + 3] = idx4[nLeft];
    x_data[i] = x4[i1];
    x_data[i + 1] = x4[i3];
    x_data[i + 2] = x4[i4];
    x_data[i + 3] = x4[nLeft];
  }

  i4 = nQuartets << 2;
  nLeft = x_size[0] - i4;
  if (nLeft > 0) {
    for (k = 0; k < nLeft; k++) {
      i3 = i4 + k;
      idx4[k] = (short)(i3 + 1);
      x4[k] = x_data[i3];
    }

    perm[1] = 0;
    perm[2] = 0;
    perm[3] = 0;
    if (nLeft == 1) {
      perm[0] = 1;
    } else if (nLeft == 2) {
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

    for (k = 0; k < nLeft; k++) {
      i1 = i4 + k;
      idx_data[i1] = idx4[perm[k] - 1];
      x_data[i1] = x4[perm[k] - 1];
    }
  }

  i3 = 2;
  if (n > 1) {
    if (n >= 256) {
      i3 = n >> 8;
      for (i4 = 0; i4 < i3; i4++) {
        merge_pow2_block(idx_data, x_data, i4 << 8);
      }

      i3 <<= 8;
      i4 = n - i3;
      if (i4 > 0) {
        e_merge_block(idx_data, x_data, i3, i4, 2, iwork_data, xwork_data);
      }

      i3 = 8;
    }

    e_merge_block(idx_data, x_data, 0, n, i3, iwork_data, xwork_data);
  }
}

void f_merge(int idx[21], double x[21], int offset, int np, int nq, int iwork[21],
             double xwork[21])
{
  int n_tmp;
  int iout;
  int p;
  int i97;
  int q;
  int exitg1;
  if (nq != 0) {
    n_tmp = np + nq;
    for (iout = 0; iout < n_tmp; iout++) {
      i97 = offset + iout;
      iwork[iout] = idx[i97];
      xwork[iout] = x[i97];
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
            i97 = q + iout;
            idx[i97] = iwork[iout - 1];
            x[i97] = xwork[iout - 1];
          }

          exitg1 = 1;
        }
      }
    } while (exitg1 == 0);
  }
}

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
  int i25;
  int i26;
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
        i25 = idx[q - 1];
        i26 = idx[p - 1];
        if (x[i26 - 1] <= x[i25 - 1]) {
          iwork[k] = i26;
          p++;
          if (p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork[k] = idx[q - 1];
              q++;
            }
          }
        } else {
          iwork[k] = i25;
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

/* End of code generation (sortIdx.c) */
