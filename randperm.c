/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * randperm.c
 *
 * Code generation for function 'randperm'
 *
 */

/* Include files */
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
#include "randperm.h"
#include "model_emxutil.h"
#include "rand.h"
#include "sortIdx.h"

/* Function Definitions */
void b_randperm(double p[200])
{
  int k;
  int i;
  int idx[200];
  int i31;
  int i2;
  int j;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
  int i32;
  int iwork[200];
  f_rand(p);
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
    i2 = i << 1;
    j = 1;
    for (pEnd = 1 + i; pEnd < 201; pEnd = qEnd + i) {
      b_p = j;
      q = pEnd;
      qEnd = j + i2;
      if (qEnd > 201) {
        qEnd = 201;
      }

      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        i31 = idx[q - 1];
        i32 = idx[b_p - 1];
        if (p[i32 - 1] <= p[i31 - 1]) {
          iwork[k] = i32;
          b_p++;
          if (b_p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork[k] = idx[q - 1];
              q++;
            }
          }
        } else {
          iwork[k] = i31;
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

    i = i2;
  }

  for (i31 = 0; i31 < 200; i31++) {
    p[i31] = idx[i31];
  }
}

void c_randperm(double p[2000])
{
  int iv1[2000];
  int i33;
  g_rand(p);
  sortIdx(p, iv1);
  for (i33 = 0; i33 < 2000; i33++) {
    p[i33] = iv1[i33];
  }
}

void randperm(int n, emxArray_real_T *p)
{
  emxArray_int32_T *idx;
  int b_n;
  int j;
  int i;
  emxArray_int32_T *iwork;
  int i2;
  int k;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
  emxInit_int32_T(&idx, 2);
  c_rand(n, p);
  b_n = p->size[1] + 1;
  j = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = p->size[1];
  emxEnsureCapacity_int32_T(idx, j);
  i = p->size[1];
  for (j = 0; j < i; j++) {
    idx->data[j] = 0;
  }

  if (p->size[1] != 0) {
    emxInit_int32_T(&iwork, 1);
    j = iwork->size[0];
    iwork->size[0] = p->size[1];
    emxEnsureCapacity_int32_T(iwork, j);
    j = p->size[1] - 1;
    for (k = 1; k <= j; k += 2) {
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

  i = p->size[0];
  i2 = p->size[1];
  j = p->size[0] * p->size[1];
  p->size[0] = 1;
  p->size[1] = i2;
  emxEnsureCapacity_real_T(p, j);
  i *= i2;
  for (j = 0; j < i; j++) {
    p->data[j] = idx->data[j];
  }

  emxFree_int32_T(&idx);
}

/* End of code generation (randperm.c) */
