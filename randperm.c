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
#include "sortIdx.h"
#include "rand.h"

/* Function Definitions */
void b_randperm(double p[2000])
{
  int iv1[2000];
  int i24;
  g_rand(p);
  sortIdx(p, iv1);
  for (i24 = 0; i24 < 2000; i24++) {
    p[i24] = iv1[i24];
  }
}

void randperm(double p[200])
{
  int k;
  int i;
  int idx[200];
  int i22;
  int i2;
  int j;
  int pEnd;
  int b_p;
  int q;
  int qEnd;
  int kEnd;
  int i23;
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
        i22 = idx[q - 1];
        i23 = idx[b_p - 1];
        if (p[i23 - 1] <= p[i22 - 1]) {
          iwork[k] = i23;
          b_p++;
          if (b_p == pEnd) {
            while (q < qEnd) {
              k++;
              iwork[k] = idx[q - 1];
              q++;
            }
          }
        } else {
          iwork[k] = i22;
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

  for (i22 = 0; i22 < 200; i22++) {
    p[i22] = idx[i22];
  }
}

/* End of code generation (randperm.c) */
