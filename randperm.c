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
#include "main_UCI_func.h"
#include "randperm.h"
#include "sortIdx.h"
#include "rand.h"

/* Function Definitions */
void b_randperm(double p[2000])
{
  int iv0[2000];
  int i3;
  c_rand(p);
  sortIdx(p, iv0);
  for (i3 = 0; i3 < 2000; i3++) {
    p[i3] = iv0[i3];
  }
}

void randperm(double p[200])
{
  int k;
  int i;
  int idx[200];
  int i1;
  int i2;
  int j;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
  int b_i2;
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
        i1 = idx[q - 1];
        b_i2 = idx[b_p - 1];
        if (p[b_i2 - 1] <= p[i1 - 1]) {
          iwork[k] = b_i2;
          b_p++;
          if (b_p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork[k] = idx[q - 1];
              q++;
            }
          }
        } else {
          iwork[k] = i1;
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

  for (i1 = 0; i1 < 200; i1++) {
    p[i1] = idx[i1];
  }
}

/* End of code generation (randperm.c) */
