/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: randperm.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 18:10:16
 */

/* Include Files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "randperm.h"
#include "sortIdx.h"
#include "rand.h"
#include "model_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : double p[2000]
 * Return Type  : void
 */
void b_randperm(double p[2000])
{
  int iv0[2000];
  int i5;
  c_rand(p);
  sortIdx(p, iv0);
  for (i5 = 0; i5 < 2000; i5++) {
    p[i5] = iv0[i5];
  }
}

/*
 * Arguments    : int n
 *                emxArray_real_T *p
 * Return Type  : void
 */
void c_randperm(int n, emxArray_real_T *p)
{
  emxArray_int32_T *idx;
  int b_n;
  int i;
  int i2;
  emxArray_int32_T *iwork;
  int k;
  int j;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
  emxInit_int32_T(&idx, 2);
  i_rand(n, p);
  b_n = p->size[1] + 1;
  i = p->size[1];
  i2 = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = i;
  emxEnsureCapacity_int32_T(idx, i2);
  for (i2 = 0; i2 < i; i2++) {
    idx->data[i2] = 0;
  }

  if (p->size[1] != 0) {
    emxInit_int32_T(&iwork, 1);
    i2 = iwork->size[0];
    iwork->size[0] = p->size[1];
    emxEnsureCapacity_int32_T(iwork, i2);
    i2 = p->size[1] - 1;
    for (k = 1; k <= i2; k += 2) {
      if (p->data[k - 1] <= p->data[k]) {
        idx->data[k - 1] = k;
        idx->data[k] = k + 1;
      } else {
        idx->data[k - 1] = k + 1;
        idx->data[k] = k;
      }
    }

    if ((p->size[1] & 1) != 0) {
      idx->data[p->size[1] - 1] = p->size[1];
    }

    i = 2;
    while (i < b_n - 1) {
      i2 = i << 1;
      j = 1;
      for (pEnd = 1 + i; pEnd < b_n; pEnd = qEnd + i) {
        b_p = j;
        q = pEnd;
        qEnd = j + i2;
        if (qEnd > b_n) {
          qEnd = b_n;
        }

        k = 0;
        kEnd = qEnd - j;
        while (k + 1 <= kEnd) {
          if (p->data[idx->data[b_p - 1] - 1] <= p->data[idx->data[q - 1] - 1])
          {
            iwork->data[k] = idx->data[b_p - 1];
            b_p++;
            if (b_p == pEnd) {
              while (q < qEnd) {
                k++;
                iwork->data[k] = idx->data[q - 1];
                q++;
              }
            }
          } else {
            iwork->data[k] = idx->data[q - 1];
            q++;
            if (q == qEnd) {
              while (b_p < pEnd) {
                k++;
                iwork->data[k] = idx->data[b_p - 1];
                b_p++;
              }
            }
          }

          k++;
        }

        for (k = 0; k < kEnd; k++) {
          idx->data[(j + k) - 1] = iwork->data[k];
        }

        j = qEnd;
      }

      i = i2;
    }

    emxFree_int32_T(&iwork);
  }

  i = p->size[1];
  i2 = p->size[0] * p->size[1];
  p->size[0] = 1;
  p->size[1] = i;
  emxEnsureCapacity_real_T(p, i2);
  for (i2 = 0; i2 < i; i2++) {
    p->data[i2] = idx->data[i2];
  }

  emxFree_int32_T(&idx);
}

/*
 * Arguments    : double p[200]
 * Return Type  : void
 */
void randperm(double p[200])
{
  int k;
  int i;
  int idx[200];
  int i2;
  int b_i2;
  int j;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
  int i3;
  int iwork[200];
  b_rand(p);
  for (k = 0; k <= 198; k += 2) {
    if (p[k] <= p[k + 1]) {
      idx[k] = k + 1;
      idx[k + 1] = k + 2;
    } else {
      idx[k] = k + 2;
      idx[k + 1] = k + 1;
    }
  }

  i = 2;
  while (i < 200) {
    b_i2 = i << 1;
    j = 1;
    for (pEnd = 1 + i; pEnd < 201; pEnd = qEnd + i) {
      b_p = j;
      q = pEnd;
      qEnd = j + b_i2;
      if (qEnd > 201) {
        qEnd = 201;
      }

      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        i2 = idx[q - 1];
        i3 = idx[b_p - 1];
        if (p[i3 - 1] <= p[i2 - 1]) {
          iwork[k] = i3;
          b_p++;
          if (b_p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork[k] = idx[q - 1];
              q++;
            }
          }
        } else {
          iwork[k] = i2;
          q++;
          if (q == qEnd) {
            while (b_p < pEnd) {
              k++;
              iwork[k] = idx[b_p - 1];
              b_p++;
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

    i = b_i2;
  }

  for (i2 = 0; i2 < 200; i2++) {
    p[i2] = idx[i2];
  }
}

/*
 * File trailer for randperm.c
 *
 * [EOF]
 */
