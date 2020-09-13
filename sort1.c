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
#include "sort1.h"
#include "model_emxutil.h"
#include "sortIdx.h"

/* Function Definitions */
void b_sort(emxArray_int32_T *x, emxArray_int32_T *idx)
{
  int dim;
  int i84;
  emxArray_int32_T *vwork;
  int vlen;
  int x_idx_0;
  int vstride;
  int k;
  emxArray_int32_T *iidx;
  dim = 0;
  if (x->size[0] != 1) {
    dim = -1;
  }

  if (dim + 2 <= 1) {
    i84 = x->size[0];
  } else {
    i84 = 1;
  }

  emxInit_int32_T(&vwork, 1);
  vlen = i84 - 1;
  x_idx_0 = vwork->size[0];
  vwork->size[0] = i84;
  emxEnsureCapacity_int32_T(vwork, x_idx_0);
  x_idx_0 = x->size[0];
  i84 = idx->size[0];
  idx->size[0] = x_idx_0;
  emxEnsureCapacity_int32_T(idx, i84);
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x->size[0];
  }

  emxInit_int32_T(&iidx, 1);
  for (x_idx_0 = 0; x_idx_0 < vstride; x_idx_0++) {
    for (k = 0; k <= vlen; k++) {
      vwork->data[k] = x->data[x_idx_0 + k * vstride];
    }

    c_sortIdx(vwork, iidx);
    for (k = 0; k <= vlen; k++) {
      i84 = x_idx_0 + k * vstride;
      x->data[i84] = vwork->data[k];
      idx->data[i84] = iidx->data[k];
    }
  }

  emxFree_int32_T(&iidx);
  emxFree_int32_T(&vwork);
}

void c_sort(double x[2000], int idx[2000])
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
  double d30;
  double d31;
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

      d30 = x4[ib - 1];
      d31 = x4[i3 - 1];
      if (d30 <= d31) {
        d30 = x4[i2 - 1];
        if (d30 <= d31) {
          perm[0] = (signed char)ib;
          perm[1] = (signed char)i2;
          perm[2] = (signed char)i3;
          perm[3] = (signed char)i4;
        } else if (d30 <= x4[i4 - 1]) {
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
        d31 = x4[i4 - 1];
        if (d30 <= d31) {
          if (x4[i2 - 1] <= d31) {
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
    offset = (b << 8) - 1;
    for (b_b = 0; b_b < 6; b_b++) {
      bLen = 1 << (b_b + 2);
      bLen2 = bLen << 1;
      nPairs = 256 >> (b_b + 3);
      for (k = 0; k < nPairs; k++) {
        i3 = (offset + k * bLen2) + 1;
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
  c_merge_block(idx, x, 1792, 208, 2, iwork, xwork);
  c_merge_block(idx, x, 0, 2000, 8, iwork, xwork);
}

void d_sort(emxArray_int32_T *x, emxArray_int32_T *idx)
{
  int i100;
  int i1;
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
  i100 = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = x->size[1];
  emxEnsureCapacity_int32_T(idx, i100);
  i1 = x->size[1];
  for (i100 = 0; i100 < i1; i100++) {
    idx->data[i100] = 0;
  }

  if (x->size[1] != 0) {
    n = x->size[1];
    b_n = x->size[1];
    x4[0] = 0;
    idx4[0] = 0;
    x4[1] = 0;
    idx4[1] = 0;
    x4[2] = 0;
    idx4[2] = 0;
    x4[3] = 0;
    idx4[3] = 0;
    emxInit_int32_T(&iwork, 1);
    i1 = x->size[1];
    i100 = iwork->size[0];
    iwork->size[0] = i1;
    emxEnsureCapacity_int32_T(iwork, i100);
    for (i100 = 0; i100 < i1; i100++) {
      iwork->data[i100] = 0;
    }

    emxInit_int32_T(&xwork, 1);
    i1 = x->size[1];
    i100 = xwork->size[0];
    xwork->size[0] = i1;
    emxEnsureCapacity_int32_T(xwork, i100);
    for (i100 = 0; i100 < i1; i100++) {
      xwork->data[i100] = 0;
    }

    nQuartets = x->size[1] >> 2;
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
      if (x->data[i] >= x->data[i + 1]) {
        i1 = 1;
        i2 = 2;
      } else {
        i1 = 2;
        i2 = 1;
      }

      if (x->data[i + 2] >= x->data[i + 3]) {
        i3 = 3;
        i4 = 4;
      } else {
        i3 = 4;
        i4 = 3;
      }

      i100 = x4[i1 - 1];
      offset = x4[i3 - 1];
      if (i100 >= offset) {
        i100 = x4[i2 - 1];
        if (i100 >= offset) {
          perm[0] = (signed char)i1;
          perm[1] = (signed char)i2;
          perm[2] = (signed char)i3;
          perm[3] = (signed char)i4;
        } else if (i100 >= x4[i4 - 1]) {
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
        if (i100 >= offset) {
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

      i100 = perm[0] - 1;
      idx->data[i] = idx4[i100];
      offset = perm[1] - 1;
      idx->data[i + 1] = idx4[offset];
      i1 = perm[2] - 1;
      idx->data[i + 2] = idx4[i1];
      i2 = perm[3] - 1;
      idx->data[i + 3] = idx4[i2];
      x->data[i] = x4[i100];
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

      for (k = 0; k < i2; k++) {
        i100 = i3 + k;
        idx->data[i100] = idx4[perm[k] - 1];
        x->data[i100] = x4[perm[k] - 1];
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
                if (b_xwork[i4] >= b_xwork[i2]) {
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
                      i100 = i1 + j;
                      idx->data[i100] = b_iwork[j - 1];
                      x->data[i100] = b_xwork[j - 1];
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
          d_merge_block(idx, x, i1, i2, 2, iwork, xwork);
        }

        i1 = 8;
      }

      d_merge_block(idx, x, 0, n, i1, iwork, xwork);
    }

    emxFree_int32_T(&xwork);
    emxFree_int32_T(&iwork);
  }
}

void e_sort(emxArray_int32_T *x, emxArray_int32_T *idx)
{
  int dim;
  int i102;
  emxArray_int32_T *vwork;
  int vlen;
  int x_idx_0;
  int vstride;
  int k;
  emxArray_int32_T *iidx;
  dim = 0;
  if (x->size[0] != 1) {
    dim = -1;
  }

  if (dim + 2 <= 1) {
    i102 = x->size[0];
  } else {
    i102 = 1;
  }

  emxInit_int32_T(&vwork, 1);
  vlen = i102 - 1;
  x_idx_0 = vwork->size[0];
  vwork->size[0] = i102;
  emxEnsureCapacity_int32_T(vwork, x_idx_0);
  x_idx_0 = x->size[0];
  i102 = idx->size[0];
  idx->size[0] = x_idx_0;
  emxEnsureCapacity_int32_T(idx, i102);
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x->size[0];
  }

  emxInit_int32_T(&iidx, 1);
  for (x_idx_0 = 0; x_idx_0 < vstride; x_idx_0++) {
    for (k = 0; k <= vlen; k++) {
      vwork->data[k] = x->data[x_idx_0 + k * vstride];
    }

    d_sortIdx(vwork, iidx);
    for (k = 0; k <= vlen; k++) {
      i102 = x_idx_0 + k * vstride;
      x->data[i102] = vwork->data[k];
      idx->data[i102] = iidx->data[k];
    }
  }

  emxFree_int32_T(&iidx);
  emxFree_int32_T(&vwork);
}

void sort(emxArray_real_T *x, emxArray_int32_T *idx)
{
  int dim;
  int i80;
  emxArray_real_T *vwork;
  int vlen;
  int x_idx_0;
  int vstride;
  int k;
  emxArray_int32_T *iidx;
  dim = 0;
  if (x->size[0] != 1) {
    dim = -1;
  }

  if (dim + 2 <= 1) {
    i80 = x->size[0];
  } else {
    i80 = 1;
  }

  emxInit_real_T(&vwork, 1);
  vlen = i80 - 1;
  x_idx_0 = vwork->size[0];
  vwork->size[0] = i80;
  emxEnsureCapacity_real_T(vwork, x_idx_0);
  x_idx_0 = x->size[0];
  i80 = idx->size[0];
  idx->size[0] = x_idx_0;
  emxEnsureCapacity_int32_T(idx, i80);
  vstride = 1;
  for (k = 0; k <= dim; k++) {
    vstride *= x->size[0];
  }

  emxInit_int32_T(&iidx, 1);
  for (x_idx_0 = 0; x_idx_0 < vstride; x_idx_0++) {
    for (k = 0; k <= vlen; k++) {
      vwork->data[k] = x->data[x_idx_0 + k * vstride];
    }

    b_sortIdx(vwork, iidx);
    for (k = 0; k <= vlen; k++) {
      i80 = x_idx_0 + k * vstride;
      x->data[i80] = vwork->data[k];
      idx->data[i80] = iidx->data[k];
    }
  }

  emxFree_int32_T(&iidx);
  emxFree_real_T(&vwork);
}

/* End of code generation (sort1.c) */
