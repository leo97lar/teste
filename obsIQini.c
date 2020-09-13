/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * obsIQini.c
 *
 * Code generation for function 'obsIQini'
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
#include "model_emxutil.h"
#include "rdivide_helper.h"
#include "sum.h"
#include "rand.h"
#include "repmat.h"
#include "model_rtwutil.h"

/* Function Definitions */
void b_obsIQini(const emxArray_real_T *IQ, int numIQ, int numObsIQ, const
                emxArray_real_T *ProbXEst, emxArray_int32_T *newIC)
{
  emxArray_int32_T *Lim;
  double Pmax;
  int i54;
  int i55;
  int nx;
  emxArray_real_T *b_ProbXEst;
  int jj;
  emxArray_real_T *List;
  int i56;
  int loop_ub_tmp;
  emxArray_real_T *Obs;
  emxArray_real_T *Qtem;
  emxArray_real_T *idx;
  emxArray_real_T *Qtem2;
  emxArray_real_T *b_Qtem;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_boolean_T *b_x;
  emxArray_int32_T *i;
  emxArray_real_T *c_Qtem;
  emxArray_real_T *b_Qtem2;
  int k;
  int b_k;
  long long i57;
  unsigned int unnamed_idx_0;
  int u;
  int i58;
  int b_ii;
  int b_i;
  int b_idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxInit_int32_T(&Lim, 2);

  /* UNTITLED7 Summary of this function goes here */
  /*    Detailed explanation goes here, */
  Pmax = rt_roundd((double)IQ->size[0] / (double)numIQ);
  if (Pmax < 2.147483648E+9) {
    if (Pmax >= -2.147483648E+9) {
      i54 = (int)Pmax;
    } else {
      i54 = MIN_int32_T;
    }
  } else {
    i54 = MAX_int32_T;
  }

  i55 = Lim->size[0] * Lim->size[1];
  Lim->size[0] = 1;
  Lim->size[1] = ProbXEst->size[0];
  emxEnsureCapacity_int32_T(Lim, i55);
  nx = ProbXEst->size[0];
  for (i55 = 0; i55 < nx; i55++) {
    Lim->data[i55] = 0;
  }

  i55 = ProbXEst->size[0];
  emxInit_real_T(&b_ProbXEst, 1);
  for (jj = 0; jj < i55; jj++) {
    i56 = b_ProbXEst->size[0];
    b_ProbXEst->size[0] = jj + 1;
    emxEnsureCapacity_real_T(b_ProbXEst, i56);
    for (i56 = 0; i56 <= jj; i56++) {
      b_ProbXEst->data[i56] = ProbXEst->data[i56];
    }

    Pmax = sum(b_ProbXEst);
    Pmax = rt_roundd((double)i54 * Pmax);
    if (Pmax < 2.147483648E+9) {
      if (Pmax >= -2.147483648E+9) {
        i56 = (int)Pmax;
      } else {
        i56 = MIN_int32_T;
      }
    } else {
      i56 = MAX_int32_T;
    }

    Lim->data[jj] = (int)rt_roundd((double)i56 / 100.0);
  }

  emxInit_real_T(&List, 2);
  i55 = List->size[0] * List->size[1];
  List->size[0] = i54;
  List->size[1] = numObsIQ;
  emxEnsureCapacity_real_T(List, i55);
  loop_ub_tmp = i54 * numObsIQ;
  for (i55 = 0; i55 < loop_ub_tmp; i55++) {
    List->data[i55] = 0.0;
  }

  emxInit_real_T(&Obs, 2);
  repmat(List, numIQ, Obs);
  i55 = newIC->size[0] * newIC->size[1];
  newIC->size[0] = Obs->size[0];
  newIC->size[1] = Obs->size[1];
  emxEnsureCapacity_int32_T(newIC, i55);
  nx = Obs->size[0] * Obs->size[1];
  for (i55 = 0; i55 < nx; i55++) {
    Pmax = rt_roundd(Obs->data[i55]);
    if (Pmax < 2.147483648E+9) {
      if (Pmax >= -2.147483648E+9) {
        i56 = (int)Pmax;
      } else {
        i56 = MIN_int32_T;
      }
    } else {
      i56 = MAX_int32_T;
    }

    newIC->data[i55] = i56;
  }

  emxInit_real_T(&Qtem, 2);
  emxInit_real_T(&idx, 2);
  emxInit_real_T(&Qtem2, 2);
  emxInit_real_T(&b_Qtem, 1);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&ii, 2);
  emxInit_boolean_T(&b_x, 2);
  emxInit_int32_T(&i, 1);
  emxInit_real_T(&c_Qtem, 2);
  emxInit_real_T(&b_Qtem2, 2);
  for (k = 0; k < numIQ; k++) {
    b_k = 1 + k;
    if (b_k < -2147483647) {
      jj = MIN_int32_T;
    } else {
      jj = b_k - 1;
    }

    i57 = (long long)jj * i54;
    if (i57 > 2147483647LL) {
      i57 = 2147483647LL;
    } else {
      if (i57 < -2147483648LL) {
        i57 = -2147483648LL;
      }
    }

    jj = (int)i57;
    if (jj > 2147483646) {
      jj = MAX_int32_T;
    } else {
      jj++;
    }

    i57 = (long long)b_k * i54;
    if (i57 > 2147483647LL) {
      i57 = 2147483647LL;
    } else {
      if (i57 < -2147483648LL) {
        i57 = -2147483648LL;
      }
    }

    i55 = (int)i57;
    if (jj > i55) {
      i56 = -1;
      i55 = -1;
    } else {
      i56 = jj - 2;
      i55--;
    }

    if (0 <= numObsIQ - 1) {
      unnamed_idx_0 = (unsigned int)(i55 - i56);
    }

    for (u = 0; u < numObsIQ; u++) {
      i58 = IQ->size[1];
      b_ii = Obs->size[0] * Obs->size[1];
      Obs->size[0] = (int)unnamed_idx_0;
      Obs->size[1] = i58;
      emxEnsureCapacity_real_T(Obs, b_ii);
      nx = (int)unnamed_idx_0 * i58;
      for (i58 = 0; i58 < nx; i58++) {
        Obs->data[i58] = 0.0;
      }

      nx = IQ->size[1];
      i58 = Qtem->size[0] * Qtem->size[1];
      Qtem->size[0] = i55 - i56;
      Qtem->size[1] = nx;
      emxEnsureCapacity_real_T(Qtem, i58);
      for (i58 = 0; i58 < nx; i58++) {
        jj = i55 - i56;
        for (b_ii = 0; b_ii < jj; b_ii++) {
          Qtem->data[b_ii + Qtem->size[0] * i58] = IQ->data[((i56 + b_ii) +
            IQ->size[0] * i58) + 1];
        }
      }

      for (b_i = 0; b_i < i54; b_i++) {
        if (b_i + 1 <= Lim->data[0]) {
          if (1 > Lim->data[0]) {
            nx = 0;
          } else {
            nx = Lim->data[0];
          }

          i58 = c_Qtem->size[0] * c_Qtem->size[1];
          c_Qtem->size[0] = 1;
          c_Qtem->size[1] = nx;
          emxEnsureCapacity_real_T(c_Qtem, i58);
          for (i58 = 0; i58 < nx; i58++) {
            c_Qtem->data[i58] = Qtem->data[b_i + Qtem->size[0] * i58];
          }

          Pmax = b_sum(c_Qtem);
          if (1 > Lim->data[0]) {
            nx = 0;
          } else {
            nx = Lim->data[0];
          }

          i58 = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = nx;
          emxEnsureCapacity_boolean_T(x, i58);
          for (i58 = 0; i58 < nx; i58++) {
            x->data[i58] = (Qtem->data[b_i + Qtem->size[0] * i58] != 0.0);
          }

          nx = x->size[1];
          b_idx = 0;
          i58 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(ii, i58);
          b_ii = 0;
          exitg1 = false;
          while ((!exitg1) && (b_ii <= nx - 1)) {
            if (x->data[b_ii]) {
              b_idx++;
              ii->data[b_idx - 1] = b_ii + 1;
              if (b_idx >= nx) {
                exitg1 = true;
              } else {
                b_ii++;
              }
            } else {
              b_ii++;
            }
          }

          if (x->size[1] == 1) {
            if (b_idx == 0) {
              ii->size[0] = 1;
              ii->size[1] = 0;
            }
          } else if (1 > b_idx) {
            ii->size[1] = 0;
          } else {
            i58 = ii->size[0] * ii->size[1];
            ii->size[1] = b_idx;
            emxEnsureCapacity_int32_T(ii, i58);
          }

          i58 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = ii->size[1];
          emxEnsureCapacity_real_T(idx, i58);
          nx = ii->size[0] * ii->size[1];
          for (i58 = 0; i58 < nx; i58++) {
            idx->data[i58] = ii->data[i58];
          }

          i58 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = idx->size[1];
          emxEnsureCapacity_real_T(Qtem2, i58);
          nx = idx->size[1];
          for (i58 = 0; i58 < nx; i58++) {
            Qtem2->data[i58] = Qtem->data[b_i + Qtem->size[0] * ((int)idx->
              data[i58] - 1)];
          }
        } else if ((b_i + 1 > Lim->data[0]) && (b_i + 1 <= Lim->data[1])) {
          if (1 > Lim->data[1]) {
            nx = 0;
          } else {
            nx = Lim->data[1];
          }

          i58 = c_Qtem->size[0] * c_Qtem->size[1];
          c_Qtem->size[0] = 1;
          c_Qtem->size[1] = nx;
          emxEnsureCapacity_real_T(c_Qtem, i58);
          for (i58 = 0; i58 < nx; i58++) {
            c_Qtem->data[i58] = Qtem->data[b_i + Qtem->size[0] * i58];
          }

          Pmax = b_sum(c_Qtem);
          if (Lim->data[0] + 1 > Lim->data[1]) {
            i58 = 0;
            b_ii = 0;
          } else {
            i58 = Lim->data[0];
            b_ii = Lim->data[1];
          }

          jj = x->size[0] * x->size[1];
          x->size[0] = 1;
          nx = b_ii - i58;
          x->size[1] = nx;
          emxEnsureCapacity_boolean_T(x, jj);
          for (b_ii = 0; b_ii < nx; b_ii++) {
            x->data[b_ii] = (Qtem->data[b_i + Qtem->size[0] * (i58 + b_ii)] !=
                             0.0);
          }

          nx = x->size[1];
          b_idx = 0;
          i58 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(ii, i58);
          b_ii = 0;
          exitg1 = false;
          while ((!exitg1) && (b_ii <= nx - 1)) {
            if (x->data[b_ii]) {
              b_idx++;
              ii->data[b_idx - 1] = b_ii + 1;
              if (b_idx >= nx) {
                exitg1 = true;
              } else {
                b_ii++;
              }
            } else {
              b_ii++;
            }
          }

          if (x->size[1] == 1) {
            if (b_idx == 0) {
              ii->size[0] = 1;
              ii->size[1] = 0;
            }
          } else if (1 > b_idx) {
            ii->size[1] = 0;
          } else {
            i58 = ii->size[0] * ii->size[1];
            ii->size[1] = b_idx;
            emxEnsureCapacity_int32_T(ii, i58);
          }

          i58 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = ii->size[1];
          emxEnsureCapacity_real_T(idx, i58);
          jj = Lim->data[0];
          nx = ii->size[0] * ii->size[1];
          for (i58 = 0; i58 < nx; i58++) {
            idx->data[i58] = ii->data[i58] + jj;
          }

          i58 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = idx->size[1];
          emxEnsureCapacity_real_T(Qtem2, i58);
          nx = idx->size[1];
          for (i58 = 0; i58 < nx; i58++) {
            Qtem2->data[i58] = Qtem->data[b_i + Qtem->size[0] * ((int)idx->
              data[i58] - 1)];
          }
        } else if ((b_i + 1 > Lim->data[1]) && (b_i + 1 <= Lim->data[2])) {
          if (1 > Lim->data[2]) {
            nx = 0;
          } else {
            nx = Lim->data[2];
          }

          i58 = c_Qtem->size[0] * c_Qtem->size[1];
          c_Qtem->size[0] = 1;
          c_Qtem->size[1] = nx;
          emxEnsureCapacity_real_T(c_Qtem, i58);
          for (i58 = 0; i58 < nx; i58++) {
            c_Qtem->data[i58] = Qtem->data[b_i + Qtem->size[0] * i58];
          }

          Pmax = b_sum(c_Qtem);
          if (Lim->data[1] + 1 > Lim->data[2]) {
            i58 = 0;
            b_ii = 0;
          } else {
            i58 = Lim->data[1];
            b_ii = Lim->data[2];
          }

          jj = x->size[0] * x->size[1];
          x->size[0] = 1;
          nx = b_ii - i58;
          x->size[1] = nx;
          emxEnsureCapacity_boolean_T(x, jj);
          for (b_ii = 0; b_ii < nx; b_ii++) {
            x->data[b_ii] = (Qtem->data[b_i + Qtem->size[0] * (i58 + b_ii)] !=
                             0.0);
          }

          nx = x->size[1];
          b_idx = 0;
          i58 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(ii, i58);
          b_ii = 0;
          exitg1 = false;
          while ((!exitg1) && (b_ii <= nx - 1)) {
            if (x->data[b_ii]) {
              b_idx++;
              ii->data[b_idx - 1] = b_ii + 1;
              if (b_idx >= nx) {
                exitg1 = true;
              } else {
                b_ii++;
              }
            } else {
              b_ii++;
            }
          }

          if (x->size[1] == 1) {
            if (b_idx == 0) {
              ii->size[0] = 1;
              ii->size[1] = 0;
            }
          } else if (1 > b_idx) {
            ii->size[1] = 0;
          } else {
            i58 = ii->size[0] * ii->size[1];
            ii->size[1] = b_idx;
            emxEnsureCapacity_int32_T(ii, i58);
          }

          i58 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = ii->size[1];
          emxEnsureCapacity_real_T(idx, i58);
          jj = Lim->data[1];
          nx = ii->size[0] * ii->size[1];
          for (i58 = 0; i58 < nx; i58++) {
            idx->data[i58] = ii->data[i58] + jj;
          }

          i58 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = idx->size[1];
          emxEnsureCapacity_real_T(Qtem2, i58);
          nx = idx->size[1];
          for (i58 = 0; i58 < nx; i58++) {
            Qtem2->data[i58] = Qtem->data[b_i + Qtem->size[0] * ((int)idx->
              data[i58] - 1)];
          }
        } else if ((b_i + 1 > Lim->data[2]) && (b_i + 1 <= Lim->data[3])) {
          if (1 > Lim->data[3]) {
            nx = 0;
          } else {
            nx = Lim->data[3];
          }

          i58 = c_Qtem->size[0] * c_Qtem->size[1];
          c_Qtem->size[0] = 1;
          c_Qtem->size[1] = nx;
          emxEnsureCapacity_real_T(c_Qtem, i58);
          for (i58 = 0; i58 < nx; i58++) {
            c_Qtem->data[i58] = Qtem->data[b_i + Qtem->size[0] * i58];
          }

          Pmax = b_sum(c_Qtem);
          if (Lim->data[2] + 1 > Lim->data[3]) {
            i58 = 0;
            b_ii = 0;
          } else {
            i58 = Lim->data[2];
            b_ii = Lim->data[3];
          }

          jj = x->size[0] * x->size[1];
          x->size[0] = 1;
          nx = b_ii - i58;
          x->size[1] = nx;
          emxEnsureCapacity_boolean_T(x, jj);
          for (b_ii = 0; b_ii < nx; b_ii++) {
            x->data[b_ii] = (Qtem->data[b_i + Qtem->size[0] * (i58 + b_ii)] !=
                             0.0);
          }

          nx = x->size[1];
          b_idx = 0;
          i58 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(ii, i58);
          b_ii = 0;
          exitg1 = false;
          while ((!exitg1) && (b_ii <= nx - 1)) {
            if (x->data[b_ii]) {
              b_idx++;
              ii->data[b_idx - 1] = b_ii + 1;
              if (b_idx >= nx) {
                exitg1 = true;
              } else {
                b_ii++;
              }
            } else {
              b_ii++;
            }
          }

          if (x->size[1] == 1) {
            if (b_idx == 0) {
              ii->size[0] = 1;
              ii->size[1] = 0;
            }
          } else if (1 > b_idx) {
            ii->size[1] = 0;
          } else {
            i58 = ii->size[0] * ii->size[1];
            ii->size[1] = b_idx;
            emxEnsureCapacity_int32_T(ii, i58);
          }

          i58 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = ii->size[1];
          emxEnsureCapacity_real_T(idx, i58);
          jj = Lim->data[2];
          nx = ii->size[0] * ii->size[1];
          for (i58 = 0; i58 < nx; i58++) {
            idx->data[i58] = ii->data[i58] + jj;
          }

          i58 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = idx->size[1];
          emxEnsureCapacity_real_T(Qtem2, i58);
          nx = idx->size[1];
          for (i58 = 0; i58 < nx; i58++) {
            Qtem2->data[i58] = Qtem->data[b_i + Qtem->size[0] * ((int)idx->
              data[i58] - 1)];
          }
        } else {
          /* if i>Lim(4) && i<=Lim(5) */
          Pmax = 1.0;
          if (Lim->data[3] + 1 > Qtem->size[1]) {
            i58 = 0;
            b_ii = 0;
          } else {
            i58 = Lim->data[3];
            b_ii = Qtem->size[1];
          }

          jj = x->size[0] * x->size[1];
          x->size[0] = 1;
          nx = b_ii - i58;
          x->size[1] = nx;
          emxEnsureCapacity_boolean_T(x, jj);
          for (b_ii = 0; b_ii < nx; b_ii++) {
            x->data[b_ii] = (Qtem->data[b_i + Qtem->size[0] * (i58 + b_ii)] !=
                             0.0);
          }

          nx = x->size[1];
          b_idx = 0;
          i58 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(ii, i58);
          b_ii = 0;
          exitg1 = false;
          while ((!exitg1) && (b_ii <= nx - 1)) {
            if (x->data[b_ii]) {
              b_idx++;
              ii->data[b_idx - 1] = b_ii + 1;
              if (b_idx >= nx) {
                exitg1 = true;
              } else {
                b_ii++;
              }
            } else {
              b_ii++;
            }
          }

          if (x->size[1] == 1) {
            if (b_idx == 0) {
              ii->size[0] = 1;
              ii->size[1] = 0;
            }
          } else if (1 > b_idx) {
            ii->size[1] = 0;
          } else {
            i58 = ii->size[0] * ii->size[1];
            ii->size[1] = b_idx;
            emxEnsureCapacity_int32_T(ii, i58);
          }

          i58 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = ii->size[1];
          emxEnsureCapacity_real_T(idx, i58);
          jj = Lim->data[3];
          nx = ii->size[0] * ii->size[1];
          for (i58 = 0; i58 < nx; i58++) {
            idx->data[i58] = (double)ii->data[i58] + (double)jj;
          }

          i58 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = idx->size[1];
          emxEnsureCapacity_real_T(Qtem2, i58);
          nx = idx->size[1];
          for (i58 = 0; i58 < nx; i58++) {
            Qtem2->data[i58] = Qtem->data[b_i + Qtem->size[0] * ((int)idx->
              data[i58] - 1)];
          }
        }

        Pmax *= b_rand();
        jj = 1;
        exitg1 = false;
        while ((!exitg1) && (jj - 1 <= Qtem2->size[1] - 1)) {
          i58 = b_Qtem2->size[0] * b_Qtem2->size[1];
          b_Qtem2->size[0] = 1;
          b_Qtem2->size[1] = jj;
          emxEnsureCapacity_real_T(b_Qtem2, i58);
          for (i58 = 0; i58 < jj; i58++) {
            b_Qtem2->data[i58] = Qtem2->data[i58];
          }

          guard1 = false;
          if (b_sum(b_Qtem2) <= Pmax) {
            i58 = b_Qtem2->size[0] * b_Qtem2->size[1];
            b_Qtem2->size[0] = 1;
            b_Qtem2->size[1] = jj + 1;
            emxEnsureCapacity_real_T(b_Qtem2, i58);
            for (i58 = 0; i58 <= jj; i58++) {
              b_Qtem2->data[i58] = Qtem2->data[i58];
            }

            if (b_sum(b_Qtem2) > Pmax) {
              Obs->data[b_i + Obs->size[0] * ((int)idx->data[jj] - 1)] = 1.0;
              nx = Qtem->size[0];
              b_idx = (int)idx->data[jj];
              i58 = b_ProbXEst->size[0];
              b_ProbXEst->size[0] = nx;
              emxEnsureCapacity_real_T(b_ProbXEst, i58);
              for (i58 = 0; i58 < nx; i58++) {
                b_ProbXEst->data[i58] = 1.0 - Qtem->data[i58 + Qtem->size[0] *
                  (b_idx - 1)];
              }

              b_rdivide_helper(b_ProbXEst, b_Qtem);
              nx = Qtem->size[0];
              i58 = b_Qtem->size[0];
              b_Qtem->size[0] = nx;
              emxEnsureCapacity_real_T(b_Qtem, i58);
              for (i58 = 0; i58 < nx; i58++) {
                b_Qtem->data[i58] *= Qtem->data[i58];
              }

              i58 = Qtem->size[0] * Qtem->size[1];
              Qtem->size[0] = b_Qtem->size[0];
              Qtem->size[1] = 1;
              emxEnsureCapacity_real_T(Qtem, i58);
              nx = b_Qtem->size[0];
              for (i58 = 0; i58 < nx; i58++) {
                Qtem->data[i58] = b_Qtem->data[i58];
              }

              nx = b_Qtem->size[0];
              for (i58 = 0; i58 < nx; i58++) {
                Qtem->data[i58] = 0.0;
              }

              exitg1 = true;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            i58 = b_Qtem2->size[0] * b_Qtem2->size[1];
            b_Qtem2->size[0] = 1;
            b_Qtem2->size[1] = jj;
            emxEnsureCapacity_real_T(b_Qtem2, i58);
            for (i58 = 0; i58 < jj; i58++) {
              b_Qtem2->data[i58] = Qtem2->data[i58];
            }

            if (b_sum(b_Qtem2) > Pmax) {
              Obs->data[b_i + Obs->size[0] * ((int)idx->data[jj - 1] - 1)] = 1.0;
              nx = Qtem->size[0];
              b_idx = (int)idx->data[jj - 1];
              i58 = b_ProbXEst->size[0];
              b_ProbXEst->size[0] = nx;
              emxEnsureCapacity_real_T(b_ProbXEst, i58);
              for (i58 = 0; i58 < nx; i58++) {
                b_ProbXEst->data[i58] = 1.0 - Qtem->data[i58 + Qtem->size[0] *
                  (b_idx - 1)];
              }

              b_rdivide_helper(b_ProbXEst, b_Qtem);
              nx = Qtem->size[0];
              i58 = b_Qtem->size[0];
              b_Qtem->size[0] = nx;
              emxEnsureCapacity_real_T(b_Qtem, i58);
              for (i58 = 0; i58 < nx; i58++) {
                b_Qtem->data[i58] *= Qtem->data[i58];
              }

              i58 = Qtem->size[0] * Qtem->size[1];
              Qtem->size[0] = b_Qtem->size[0];
              Qtem->size[1] = 1;
              emxEnsureCapacity_real_T(Qtem, i58);
              nx = b_Qtem->size[0];
              for (i58 = 0; i58 < nx; i58++) {
                Qtem->data[i58] = b_Qtem->data[i58];
              }

              nx = b_Qtem->size[0];
              for (i58 = 0; i58 < nx; i58++) {
                Qtem->data[i58] = 0.0;
              }

              exitg1 = true;
            } else {
              jj++;
            }
          }
        }
      }

      i58 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = Obs->size[1];
      b_x->size[1] = Obs->size[0];
      emxEnsureCapacity_boolean_T(b_x, i58);
      nx = Obs->size[0];
      for (i58 = 0; i58 < nx; i58++) {
        jj = Obs->size[1];
        for (b_ii = 0; b_ii < jj; b_ii++) {
          b_x->data[b_ii + b_x->size[0] * i58] = (Obs->data[i58 + Obs->size[0] *
            b_ii] == 1.0);
        }
      }

      nx = b_x->size[0] * b_x->size[1];
      if (nx == 0) {
        i->size[0] = 0;
      } else {
        b_idx = 0;
        i58 = i->size[0];
        i->size[0] = nx;
        emxEnsureCapacity_int32_T(i, i58);
        b_ii = 1;
        jj = 1;
        exitg1 = false;
        while ((!exitg1) && (jj <= b_x->size[1])) {
          guard1 = false;
          if (b_x->data[(b_ii + b_x->size[0] * (jj - 1)) - 1]) {
            b_idx++;
            i->data[b_idx - 1] = b_ii;
            if (b_idx >= nx) {
              exitg1 = true;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            b_ii++;
            if (b_ii > b_x->size[0]) {
              b_ii = 1;
              jj++;
            }
          }
        }

        if (nx == 1) {
          if (b_idx == 0) {
            i->size[0] = 0;
          }
        } else {
          i58 = i->size[0];
          if (1 > b_idx) {
            i->size[0] = 0;
          } else {
            i->size[0] = b_idx;
          }

          emxEnsureCapacity_int32_T(i, i58);
        }
      }

      nx = i->size[0];
      for (i58 = 0; i58 < nx; i58++) {
        List->data[i58 + List->size[0] * u] = i->data[i58];
      }
    }

    if (b_k < -2147483647) {
      jj = MIN_int32_T;
    } else {
      jj = b_k - 1;
    }

    i57 = (long long)jj * numObsIQ;
    if (i57 > 2147483647LL) {
      i57 = 2147483647LL;
    } else {
      if (i57 < -2147483648LL) {
        i57 = -2147483648LL;
      }
    }

    jj = (int)i57;
    if (jj > 2147483646) {
      jj = MAX_int32_T;
    } else {
      jj++;
    }

    i57 = (long long)b_k * numObsIQ;
    if (i57 > 2147483647LL) {
      i57 = 2147483647LL;
    } else {
      if (i57 < -2147483648LL) {
        i57 = -2147483648LL;
      }
    }

    if (jj > (int)i57) {
      i55 = 1;
    } else {
      i55 = jj;
    }

    nx = List->size[1];
    for (i56 = 0; i56 < nx; i56++) {
      jj = List->size[0];
      for (i58 = 0; i58 < jj; i58++) {
        newIC->data[i58 + newIC->size[0] * ((i55 + i56) - 1)] = (int)List->
          data[i58 + List->size[0] * i56];
      }
    }

    i55 = List->size[0] * List->size[1];
    List->size[0] = i54;
    List->size[1] = numObsIQ;
    emxEnsureCapacity_real_T(List, i55);
    for (i55 = 0; i55 < loop_ub_tmp; i55++) {
      List->data[i55] = 0.0;
    }
  }

  emxFree_real_T(&b_Qtem2);
  emxFree_real_T(&c_Qtem);
  emxFree_real_T(&b_ProbXEst);
  emxFree_int32_T(&i);
  emxFree_boolean_T(&b_x);
  emxFree_int32_T(&ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&b_Qtem);
  emxFree_real_T(&Qtem2);
  emxFree_real_T(&idx);
  emxFree_real_T(&Qtem);
  emxFree_real_T(&Obs);
  emxFree_real_T(&List);
  emxFree_int32_T(&Lim);
}

void obsIQini(const emxArray_real_T *IQ, int numIQ, int numObsIQ, const double
              ProbXEst[5], emxArray_int32_T *newIC)
{
  double Pmax;
  int i3;
  int jj;
  emxArray_real_T *List;
  int ProbXEst_size[1];
  int i4;
  emxArray_real_T ProbXEst_data;
  double b_ProbXEst_data[5];
  int loop_ub_tmp;
  emxArray_real_T *Obs;
  int Lim[5];
  int nx;
  emxArray_real_T *Qtem;
  emxArray_real_T *idx;
  emxArray_real_T *Qtem2;
  int i5;
  emxArray_real_T *b_Qtem;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_boolean_T *b_x;
  emxArray_int32_T *i;
  emxArray_real_T *c_Qtem;
  emxArray_real_T *b_Qtem2;
  emxArray_real_T *r0;
  int k;
  int b_k;
  long long i6;
  unsigned int unnamed_idx_0;
  int u;
  int i7;
  int b_ii;
  int b_i;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  int b_idx;
  boolean_T exitg1;
  boolean_T b_guard1 = false;

  /* UNTITLED7 Summary of this function goes here */
  /*    Detailed explanation goes here, */
  Pmax = rt_roundd((double)IQ->size[0] / (double)numIQ);
  if (Pmax < 2.147483648E+9) {
    if (Pmax >= -2.147483648E+9) {
      i3 = (int)Pmax;
    } else {
      i3 = MIN_int32_T;
    }
  } else {
    i3 = MAX_int32_T;
  }

  for (jj = 0; jj < 5; jj++) {
    ProbXEst_size[0] = jj + 1;
    for (i4 = 0; i4 <= jj; i4++) {
      b_ProbXEst_data[i4] = ProbXEst[i4];
    }

    ProbXEst_data.data = &b_ProbXEst_data[0];
    ProbXEst_data.size = &ProbXEst_size[0];
    ProbXEst_data.allocatedSize = 5;
    ProbXEst_data.numDimensions = 1;
    ProbXEst_data.canFreeData = false;
    Pmax = sum(&ProbXEst_data);
    Pmax = rt_roundd((double)i3 * Pmax);
    if (Pmax < 2.147483648E+9) {
      if (Pmax >= -2.147483648E+9) {
        i4 = (int)Pmax;
      } else {
        i4 = MIN_int32_T;
      }
    } else {
      i4 = MAX_int32_T;
    }

    Lim[jj] = (int)rt_roundd((double)i4 / 100.0);
  }

  emxInit_real_T(&List, 2);
  i4 = List->size[0] * List->size[1];
  List->size[0] = i3;
  List->size[1] = numObsIQ;
  emxEnsureCapacity_real_T(List, i4);
  loop_ub_tmp = i3 * numObsIQ;
  for (i4 = 0; i4 < loop_ub_tmp; i4++) {
    List->data[i4] = 0.0;
  }

  emxInit_real_T(&Obs, 2);
  repmat(List, numIQ, Obs);
  i4 = newIC->size[0] * newIC->size[1];
  newIC->size[0] = Obs->size[0];
  newIC->size[1] = Obs->size[1];
  emxEnsureCapacity_int32_T(newIC, i4);
  nx = Obs->size[0] * Obs->size[1];
  for (i4 = 0; i4 < nx; i4++) {
    Pmax = rt_roundd(Obs->data[i4]);
    if (Pmax < 2.147483648E+9) {
      if (Pmax >= -2.147483648E+9) {
        i5 = (int)Pmax;
      } else {
        i5 = MIN_int32_T;
      }
    } else {
      i5 = MAX_int32_T;
    }

    newIC->data[i4] = i5;
  }

  emxInit_real_T(&Qtem, 2);
  emxInit_real_T(&idx, 2);
  emxInit_real_T(&Qtem2, 2);
  emxInit_real_T(&b_Qtem, 1);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&ii, 2);
  emxInit_boolean_T(&b_x, 2);
  emxInit_int32_T(&i, 1);
  emxInit_real_T(&c_Qtem, 2);
  emxInit_real_T(&b_Qtem2, 2);
  emxInit_real_T(&r0, 1);
  for (k = 0; k < numIQ; k++) {
    b_k = 1 + k;
    if (b_k < -2147483647) {
      jj = MIN_int32_T;
    } else {
      jj = b_k - 1;
    }

    i6 = (long long)jj * i3;
    if (i6 > 2147483647LL) {
      i6 = 2147483647LL;
    } else {
      if (i6 < -2147483648LL) {
        i6 = -2147483648LL;
      }
    }

    jj = (int)i6;
    if (jj > 2147483646) {
      jj = MAX_int32_T;
    } else {
      jj++;
    }

    i6 = (long long)b_k * i3;
    if (i6 > 2147483647LL) {
      i6 = 2147483647LL;
    } else {
      if (i6 < -2147483648LL) {
        i6 = -2147483648LL;
      }
    }

    i4 = (int)i6;
    if (jj > i4) {
      i5 = -1;
      i4 = -1;
    } else {
      i5 = jj - 2;
      i4--;
    }

    if (0 <= numObsIQ - 1) {
      unnamed_idx_0 = (unsigned int)(i4 - i5);
    }

    for (u = 0; u < numObsIQ; u++) {
      i7 = IQ->size[1];
      b_ii = Obs->size[0] * Obs->size[1];
      Obs->size[0] = (int)unnamed_idx_0;
      Obs->size[1] = i7;
      emxEnsureCapacity_real_T(Obs, b_ii);
      nx = (int)unnamed_idx_0 * i7;
      for (i7 = 0; i7 < nx; i7++) {
        Obs->data[i7] = 0.0;
      }

      nx = IQ->size[1];
      i7 = Qtem->size[0] * Qtem->size[1];
      Qtem->size[0] = i4 - i5;
      Qtem->size[1] = nx;
      emxEnsureCapacity_real_T(Qtem, i7);
      for (i7 = 0; i7 < nx; i7++) {
        jj = i4 - i5;
        for (b_ii = 0; b_ii < jj; b_ii++) {
          Qtem->data[b_ii + Qtem->size[0] * i7] = IQ->data[((i5 + b_ii) +
            IQ->size[0] * i7) + 1];
        }
      }

      for (b_i = 0; b_i < i3; b_i++) {
        nx = Lim[0];
        if (b_i + 1 <= Lim[0]) {
          i7 = c_Qtem->size[0] * c_Qtem->size[1];
          c_Qtem->size[0] = 1;
          c_Qtem->size[1] = Lim[0];
          emxEnsureCapacity_real_T(c_Qtem, i7);
          for (i7 = 0; i7 < nx; i7++) {
            c_Qtem->data[i7] = Qtem->data[b_i + Qtem->size[0] * i7];
          }

          Pmax = b_sum(c_Qtem);
          nx = Lim[0];
          i7 = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = Lim[0];
          emxEnsureCapacity_boolean_T(x, i7);
          for (i7 = 0; i7 < nx; i7++) {
            x->data[i7] = (Qtem->data[b_i + Qtem->size[0] * i7] != 0.0);
          }

          nx = x->size[1];
          b_idx = 0;
          i7 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(ii, i7);
          b_ii = 0;
          exitg1 = false;
          while ((!exitg1) && (b_ii <= nx - 1)) {
            if (x->data[b_ii]) {
              b_idx++;
              ii->data[b_idx - 1] = b_ii + 1;
              if (b_idx >= nx) {
                exitg1 = true;
              } else {
                b_ii++;
              }
            } else {
              b_ii++;
            }
          }

          if (x->size[1] == 1) {
            if (b_idx == 0) {
              ii->size[0] = 1;
              ii->size[1] = 0;
            }
          } else if (1 > b_idx) {
            ii->size[1] = 0;
          } else {
            i7 = ii->size[0] * ii->size[1];
            ii->size[1] = b_idx;
            emxEnsureCapacity_int32_T(ii, i7);
          }

          i7 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = ii->size[1];
          emxEnsureCapacity_real_T(idx, i7);
          nx = ii->size[0] * ii->size[1];
          for (i7 = 0; i7 < nx; i7++) {
            idx->data[i7] = ii->data[i7];
          }

          i7 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = idx->size[1];
          emxEnsureCapacity_real_T(Qtem2, i7);
          nx = idx->size[1];
          for (i7 = 0; i7 < nx; i7++) {
            Qtem2->data[i7] = Qtem->data[b_i + Qtem->size[0] * ((int)idx->
              data[i7] - 1)];
          }
        } else {
          guard1 = false;
          guard2 = false;
          guard3 = false;
          if (b_i + 1 > Lim[0]) {
            nx = Lim[1];
            if (b_i + 1 <= Lim[1]) {
              i7 = c_Qtem->size[0] * c_Qtem->size[1];
              c_Qtem->size[0] = 1;
              c_Qtem->size[1] = Lim[1];
              emxEnsureCapacity_real_T(c_Qtem, i7);
              for (i7 = 0; i7 < nx; i7++) {
                c_Qtem->data[i7] = Qtem->data[b_i + Qtem->size[0] * i7];
              }

              Pmax = b_sum(c_Qtem);
              if (Lim[0] + 1 > Lim[1]) {
                i7 = 0;
                b_ii = 0;
              } else {
                i7 = Lim[0];
                b_ii = Lim[1];
              }

              jj = x->size[0] * x->size[1];
              x->size[0] = 1;
              nx = b_ii - i7;
              x->size[1] = nx;
              emxEnsureCapacity_boolean_T(x, jj);
              for (b_ii = 0; b_ii < nx; b_ii++) {
                x->data[b_ii] = (Qtem->data[b_i + Qtem->size[0] * (i7 + b_ii)]
                                 != 0.0);
              }

              nx = x->size[1];
              b_idx = 0;
              i7 = ii->size[0] * ii->size[1];
              ii->size[0] = 1;
              ii->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(ii, i7);
              b_ii = 0;
              exitg1 = false;
              while ((!exitg1) && (b_ii <= nx - 1)) {
                if (x->data[b_ii]) {
                  b_idx++;
                  ii->data[b_idx - 1] = b_ii + 1;
                  if (b_idx >= nx) {
                    exitg1 = true;
                  } else {
                    b_ii++;
                  }
                } else {
                  b_ii++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  ii->size[0] = 1;
                  ii->size[1] = 0;
                }
              } else if (1 > b_idx) {
                ii->size[1] = 0;
              } else {
                i7 = ii->size[0] * ii->size[1];
                ii->size[1] = b_idx;
                emxEnsureCapacity_int32_T(ii, i7);
              }

              i7 = idx->size[0] * idx->size[1];
              idx->size[0] = 1;
              idx->size[1] = ii->size[1];
              emxEnsureCapacity_real_T(idx, i7);
              nx = ii->size[0] * ii->size[1];
              for (i7 = 0; i7 < nx; i7++) {
                idx->data[i7] = ii->data[i7] + Lim[0];
              }

              i7 = Qtem2->size[0] * Qtem2->size[1];
              Qtem2->size[0] = 1;
              Qtem2->size[1] = idx->size[1];
              emxEnsureCapacity_real_T(Qtem2, i7);
              nx = idx->size[1];
              for (i7 = 0; i7 < nx; i7++) {
                Qtem2->data[i7] = Qtem->data[b_i + Qtem->size[0] * ((int)
                  idx->data[i7] - 1)];
              }
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }

          if (guard3) {
            if (b_i + 1 > Lim[1]) {
              nx = Lim[2];
              if (b_i + 1 <= Lim[2]) {
                i7 = c_Qtem->size[0] * c_Qtem->size[1];
                c_Qtem->size[0] = 1;
                c_Qtem->size[1] = Lim[2];
                emxEnsureCapacity_real_T(c_Qtem, i7);
                for (i7 = 0; i7 < nx; i7++) {
                  c_Qtem->data[i7] = Qtem->data[b_i + Qtem->size[0] * i7];
                }

                Pmax = b_sum(c_Qtem);
                if (Lim[1] + 1 > Lim[2]) {
                  i7 = 0;
                  b_ii = 0;
                } else {
                  i7 = Lim[1];
                  b_ii = Lim[2];
                }

                jj = x->size[0] * x->size[1];
                x->size[0] = 1;
                nx = b_ii - i7;
                x->size[1] = nx;
                emxEnsureCapacity_boolean_T(x, jj);
                for (b_ii = 0; b_ii < nx; b_ii++) {
                  x->data[b_ii] = (Qtem->data[b_i + Qtem->size[0] * (i7 + b_ii)]
                                   != 0.0);
                }

                nx = x->size[1];
                b_idx = 0;
                i7 = ii->size[0] * ii->size[1];
                ii->size[0] = 1;
                ii->size[1] = x->size[1];
                emxEnsureCapacity_int32_T(ii, i7);
                b_ii = 0;
                exitg1 = false;
                while ((!exitg1) && (b_ii <= nx - 1)) {
                  if (x->data[b_ii]) {
                    b_idx++;
                    ii->data[b_idx - 1] = b_ii + 1;
                    if (b_idx >= nx) {
                      exitg1 = true;
                    } else {
                      b_ii++;
                    }
                  } else {
                    b_ii++;
                  }
                }

                if (x->size[1] == 1) {
                  if (b_idx == 0) {
                    ii->size[0] = 1;
                    ii->size[1] = 0;
                  }
                } else if (1 > b_idx) {
                  ii->size[1] = 0;
                } else {
                  i7 = ii->size[0] * ii->size[1];
                  ii->size[1] = b_idx;
                  emxEnsureCapacity_int32_T(ii, i7);
                }

                i7 = idx->size[0] * idx->size[1];
                idx->size[0] = 1;
                idx->size[1] = ii->size[1];
                emxEnsureCapacity_real_T(idx, i7);
                nx = ii->size[0] * ii->size[1];
                for (i7 = 0; i7 < nx; i7++) {
                  idx->data[i7] = ii->data[i7] + Lim[1];
                }

                i7 = Qtem2->size[0] * Qtem2->size[1];
                Qtem2->size[0] = 1;
                Qtem2->size[1] = idx->size[1];
                emxEnsureCapacity_real_T(Qtem2, i7);
                nx = idx->size[1];
                for (i7 = 0; i7 < nx; i7++) {
                  Qtem2->data[i7] = Qtem->data[b_i + Qtem->size[0] * ((int)
                    idx->data[i7] - 1)];
                }
              } else {
                guard2 = true;
              }
            } else {
              guard2 = true;
            }
          }

          if (guard2) {
            if (b_i + 1 > Lim[2]) {
              nx = Lim[3];
              if (b_i + 1 <= Lim[3]) {
                i7 = c_Qtem->size[0] * c_Qtem->size[1];
                c_Qtem->size[0] = 1;
                c_Qtem->size[1] = Lim[3];
                emxEnsureCapacity_real_T(c_Qtem, i7);
                for (i7 = 0; i7 < nx; i7++) {
                  c_Qtem->data[i7] = Qtem->data[b_i + Qtem->size[0] * i7];
                }

                Pmax = b_sum(c_Qtem);
                if (Lim[2] + 1 > Lim[3]) {
                  i7 = 0;
                  b_ii = 0;
                } else {
                  i7 = Lim[2];
                  b_ii = Lim[3];
                }

                jj = x->size[0] * x->size[1];
                x->size[0] = 1;
                nx = b_ii - i7;
                x->size[1] = nx;
                emxEnsureCapacity_boolean_T(x, jj);
                for (b_ii = 0; b_ii < nx; b_ii++) {
                  x->data[b_ii] = (Qtem->data[b_i + Qtem->size[0] * (i7 + b_ii)]
                                   != 0.0);
                }

                nx = x->size[1];
                b_idx = 0;
                i7 = ii->size[0] * ii->size[1];
                ii->size[0] = 1;
                ii->size[1] = x->size[1];
                emxEnsureCapacity_int32_T(ii, i7);
                b_ii = 0;
                exitg1 = false;
                while ((!exitg1) && (b_ii <= nx - 1)) {
                  if (x->data[b_ii]) {
                    b_idx++;
                    ii->data[b_idx - 1] = b_ii + 1;
                    if (b_idx >= nx) {
                      exitg1 = true;
                    } else {
                      b_ii++;
                    }
                  } else {
                    b_ii++;
                  }
                }

                if (x->size[1] == 1) {
                  if (b_idx == 0) {
                    ii->size[0] = 1;
                    ii->size[1] = 0;
                  }
                } else if (1 > b_idx) {
                  ii->size[1] = 0;
                } else {
                  i7 = ii->size[0] * ii->size[1];
                  ii->size[1] = b_idx;
                  emxEnsureCapacity_int32_T(ii, i7);
                }

                i7 = idx->size[0] * idx->size[1];
                idx->size[0] = 1;
                idx->size[1] = ii->size[1];
                emxEnsureCapacity_real_T(idx, i7);
                nx = ii->size[0] * ii->size[1];
                for (i7 = 0; i7 < nx; i7++) {
                  idx->data[i7] = ii->data[i7] + Lim[2];
                }

                i7 = Qtem2->size[0] * Qtem2->size[1];
                Qtem2->size[0] = 1;
                Qtem2->size[1] = idx->size[1];
                emxEnsureCapacity_real_T(Qtem2, i7);
                nx = idx->size[1];
                for (i7 = 0; i7 < nx; i7++) {
                  Qtem2->data[i7] = Qtem->data[b_i + Qtem->size[0] * ((int)
                    idx->data[i7] - 1)];
                }
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }
          }

          if (guard1) {
            /* if i>Lim(4) && i<=Lim(5) */
            Pmax = 1.0;
            if (Lim[3] + 1 > Qtem->size[1]) {
              i7 = 0;
              b_ii = 0;
            } else {
              i7 = Lim[3];
              b_ii = Qtem->size[1];
            }

            jj = x->size[0] * x->size[1];
            x->size[0] = 1;
            nx = b_ii - i7;
            x->size[1] = nx;
            emxEnsureCapacity_boolean_T(x, jj);
            for (b_ii = 0; b_ii < nx; b_ii++) {
              x->data[b_ii] = (Qtem->data[b_i + Qtem->size[0] * (i7 + b_ii)] !=
                               0.0);
            }

            nx = x->size[1];
            b_idx = 0;
            i7 = ii->size[0] * ii->size[1];
            ii->size[0] = 1;
            ii->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(ii, i7);
            b_ii = 0;
            exitg1 = false;
            while ((!exitg1) && (b_ii <= nx - 1)) {
              if (x->data[b_ii]) {
                b_idx++;
                ii->data[b_idx - 1] = b_ii + 1;
                if (b_idx >= nx) {
                  exitg1 = true;
                } else {
                  b_ii++;
                }
              } else {
                b_ii++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                ii->size[0] = 1;
                ii->size[1] = 0;
              }
            } else if (1 > b_idx) {
              ii->size[1] = 0;
            } else {
              i7 = ii->size[0] * ii->size[1];
              ii->size[1] = b_idx;
              emxEnsureCapacity_int32_T(ii, i7);
            }

            i7 = idx->size[0] * idx->size[1];
            idx->size[0] = 1;
            idx->size[1] = ii->size[1];
            emxEnsureCapacity_real_T(idx, i7);
            nx = ii->size[0] * ii->size[1];
            for (i7 = 0; i7 < nx; i7++) {
              idx->data[i7] = (double)ii->data[i7] + (double)Lim[3];
            }

            i7 = Qtem2->size[0] * Qtem2->size[1];
            Qtem2->size[0] = 1;
            Qtem2->size[1] = idx->size[1];
            emxEnsureCapacity_real_T(Qtem2, i7);
            nx = idx->size[1];
            for (i7 = 0; i7 < nx; i7++) {
              Qtem2->data[i7] = Qtem->data[b_i + Qtem->size[0] * ((int)idx->
                data[i7] - 1)];
            }
          }
        }

        Pmax *= b_rand();
        jj = 1;
        exitg1 = false;
        while ((!exitg1) && (jj - 1 <= Qtem2->size[1] - 1)) {
          i7 = b_Qtem2->size[0] * b_Qtem2->size[1];
          b_Qtem2->size[0] = 1;
          b_Qtem2->size[1] = jj;
          emxEnsureCapacity_real_T(b_Qtem2, i7);
          for (i7 = 0; i7 < jj; i7++) {
            b_Qtem2->data[i7] = Qtem2->data[i7];
          }

          b_guard1 = false;
          if (b_sum(b_Qtem2) <= Pmax) {
            i7 = b_Qtem2->size[0] * b_Qtem2->size[1];
            b_Qtem2->size[0] = 1;
            b_Qtem2->size[1] = jj + 1;
            emxEnsureCapacity_real_T(b_Qtem2, i7);
            for (i7 = 0; i7 <= jj; i7++) {
              b_Qtem2->data[i7] = Qtem2->data[i7];
            }

            if (b_sum(b_Qtem2) > Pmax) {
              Obs->data[b_i + Obs->size[0] * ((int)idx->data[jj] - 1)] = 1.0;
              nx = Qtem->size[0];
              b_idx = (int)idx->data[jj];
              i7 = r0->size[0];
              r0->size[0] = nx;
              emxEnsureCapacity_real_T(r0, i7);
              for (i7 = 0; i7 < nx; i7++) {
                r0->data[i7] = 1.0 - Qtem->data[i7 + Qtem->size[0] * (b_idx - 1)];
              }

              b_rdivide_helper(r0, b_Qtem);
              nx = Qtem->size[0];
              i7 = b_Qtem->size[0];
              b_Qtem->size[0] = nx;
              emxEnsureCapacity_real_T(b_Qtem, i7);
              for (i7 = 0; i7 < nx; i7++) {
                b_Qtem->data[i7] *= Qtem->data[i7];
              }

              i7 = Qtem->size[0] * Qtem->size[1];
              Qtem->size[0] = b_Qtem->size[0];
              Qtem->size[1] = 1;
              emxEnsureCapacity_real_T(Qtem, i7);
              nx = b_Qtem->size[0];
              for (i7 = 0; i7 < nx; i7++) {
                Qtem->data[i7] = b_Qtem->data[i7];
              }

              nx = b_Qtem->size[0];
              for (i7 = 0; i7 < nx; i7++) {
                Qtem->data[i7] = 0.0;
              }

              exitg1 = true;
            } else {
              b_guard1 = true;
            }
          } else {
            b_guard1 = true;
          }

          if (b_guard1) {
            i7 = b_Qtem2->size[0] * b_Qtem2->size[1];
            b_Qtem2->size[0] = 1;
            b_Qtem2->size[1] = jj;
            emxEnsureCapacity_real_T(b_Qtem2, i7);
            for (i7 = 0; i7 < jj; i7++) {
              b_Qtem2->data[i7] = Qtem2->data[i7];
            }

            if (b_sum(b_Qtem2) > Pmax) {
              Obs->data[b_i + Obs->size[0] * ((int)idx->data[jj - 1] - 1)] = 1.0;
              nx = Qtem->size[0];
              b_idx = (int)idx->data[jj - 1];
              i7 = r0->size[0];
              r0->size[0] = nx;
              emxEnsureCapacity_real_T(r0, i7);
              for (i7 = 0; i7 < nx; i7++) {
                r0->data[i7] = 1.0 - Qtem->data[i7 + Qtem->size[0] * (b_idx - 1)];
              }

              b_rdivide_helper(r0, b_Qtem);
              nx = Qtem->size[0];
              i7 = b_Qtem->size[0];
              b_Qtem->size[0] = nx;
              emxEnsureCapacity_real_T(b_Qtem, i7);
              for (i7 = 0; i7 < nx; i7++) {
                b_Qtem->data[i7] *= Qtem->data[i7];
              }

              i7 = Qtem->size[0] * Qtem->size[1];
              Qtem->size[0] = b_Qtem->size[0];
              Qtem->size[1] = 1;
              emxEnsureCapacity_real_T(Qtem, i7);
              nx = b_Qtem->size[0];
              for (i7 = 0; i7 < nx; i7++) {
                Qtem->data[i7] = b_Qtem->data[i7];
              }

              nx = b_Qtem->size[0];
              for (i7 = 0; i7 < nx; i7++) {
                Qtem->data[i7] = 0.0;
              }

              exitg1 = true;
            } else {
              jj++;
            }
          }
        }
      }

      i7 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = Obs->size[1];
      b_x->size[1] = Obs->size[0];
      emxEnsureCapacity_boolean_T(b_x, i7);
      nx = Obs->size[0];
      for (i7 = 0; i7 < nx; i7++) {
        jj = Obs->size[1];
        for (b_ii = 0; b_ii < jj; b_ii++) {
          b_x->data[b_ii + b_x->size[0] * i7] = (Obs->data[i7 + Obs->size[0] *
            b_ii] == 1.0);
        }
      }

      nx = b_x->size[0] * b_x->size[1];
      if (nx == 0) {
        i->size[0] = 0;
      } else {
        b_idx = 0;
        i7 = i->size[0];
        i->size[0] = nx;
        emxEnsureCapacity_int32_T(i, i7);
        b_ii = 1;
        jj = 1;
        exitg1 = false;
        while ((!exitg1) && (jj <= b_x->size[1])) {
          b_guard1 = false;
          if (b_x->data[(b_ii + b_x->size[0] * (jj - 1)) - 1]) {
            b_idx++;
            i->data[b_idx - 1] = b_ii;
            if (b_idx >= nx) {
              exitg1 = true;
            } else {
              b_guard1 = true;
            }
          } else {
            b_guard1 = true;
          }

          if (b_guard1) {
            b_ii++;
            if (b_ii > b_x->size[0]) {
              b_ii = 1;
              jj++;
            }
          }
        }

        if (nx == 1) {
          if (b_idx == 0) {
            i->size[0] = 0;
          }
        } else {
          i7 = i->size[0];
          if (1 > b_idx) {
            i->size[0] = 0;
          } else {
            i->size[0] = b_idx;
          }

          emxEnsureCapacity_int32_T(i, i7);
        }
      }

      nx = i->size[0];
      for (i7 = 0; i7 < nx; i7++) {
        List->data[i7 + List->size[0] * u] = i->data[i7];
      }
    }

    if (b_k < -2147483647) {
      jj = MIN_int32_T;
    } else {
      jj = b_k - 1;
    }

    i6 = (long long)jj * numObsIQ;
    if (i6 > 2147483647LL) {
      i6 = 2147483647LL;
    } else {
      if (i6 < -2147483648LL) {
        i6 = -2147483648LL;
      }
    }

    jj = (int)i6;
    if (jj > 2147483646) {
      jj = MAX_int32_T;
    } else {
      jj++;
    }

    i6 = (long long)b_k * numObsIQ;
    if (i6 > 2147483647LL) {
      i6 = 2147483647LL;
    } else {
      if (i6 < -2147483648LL) {
        i6 = -2147483648LL;
      }
    }

    if (jj > (int)i6) {
      i4 = 1;
    } else {
      i4 = jj;
    }

    nx = List->size[1];
    for (i5 = 0; i5 < nx; i5++) {
      jj = List->size[0];
      for (i7 = 0; i7 < jj; i7++) {
        newIC->data[i7 + newIC->size[0] * ((i4 + i5) - 1)] = (int)List->data[i7
          + List->size[0] * i5];
      }
    }

    i4 = List->size[0] * List->size[1];
    List->size[0] = i3;
    List->size[1] = numObsIQ;
    emxEnsureCapacity_real_T(List, i4);
    for (i4 = 0; i4 < loop_ub_tmp; i4++) {
      List->data[i4] = 0.0;
    }
  }

  emxFree_real_T(&r0);
  emxFree_real_T(&b_Qtem2);
  emxFree_real_T(&c_Qtem);
  emxFree_int32_T(&i);
  emxFree_boolean_T(&b_x);
  emxFree_int32_T(&ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&b_Qtem);
  emxFree_real_T(&Qtem2);
  emxFree_real_T(&idx);
  emxFree_real_T(&Qtem);
  emxFree_real_T(&Obs);
  emxFree_real_T(&List);
}

/* End of code generation (obsIQini.c) */
