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
#include "main_UCI_func.h"
#include "obsIQini.h"
#include "model_emxutil.h"
#include "rdivide_helper.h"
#include "sum.h"
#include "rand.h"
#include "repmat.h"
#include "model_rtwutil.h"

/* Function Definitions */
void obsIQini(const emxArray_real_T *IQ, int numIQ, int numObsIQ, const
              emxArray_real_T *ProbXEst, emxArray_int32_T *newIC)
{
  emxArray_int32_T *Lim;
  double Pmax;
  int i10;
  int i11;
  int nx;
  emxArray_real_T *b_ProbXEst;
  int jj;
  emxArray_real_T *List;
  int i12;
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
  long long i13;
  unsigned int unnamed_idx_0;
  int u;
  int i14;
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
      i10 = (int)Pmax;
    } else {
      i10 = MIN_int32_T;
    }
  } else {
    i10 = MAX_int32_T;
  }

  i11 = Lim->size[0] * Lim->size[1];
  Lim->size[0] = 1;
  Lim->size[1] = ProbXEst->size[0];
  emxEnsureCapacity_int32_T(Lim, i11);
  nx = ProbXEst->size[0];
  for (i11 = 0; i11 < nx; i11++) {
    Lim->data[i11] = 0;
  }

  i11 = ProbXEst->size[0];
  emxInit_real_T(&b_ProbXEst, 1);
  for (jj = 0; jj < i11; jj++) {
    i12 = b_ProbXEst->size[0];
    b_ProbXEst->size[0] = jj + 1;
    emxEnsureCapacity_real_T(b_ProbXEst, i12);
    for (i12 = 0; i12 <= jj; i12++) {
      b_ProbXEst->data[i12] = ProbXEst->data[i12];
    }

    Pmax = c_sum(b_ProbXEst);
    Pmax = rt_roundd((double)i10 * Pmax);
    if (Pmax < 2.147483648E+9) {
      if (Pmax >= -2.147483648E+9) {
        i12 = (int)Pmax;
      } else {
        i12 = MIN_int32_T;
      }
    } else {
      i12 = MAX_int32_T;
    }

    Lim->data[jj] = (int)rt_roundd((double)i12 / 100.0);
  }

  emxInit_real_T(&List, 2);
  i11 = List->size[0] * List->size[1];
  List->size[0] = i10;
  List->size[1] = numObsIQ;
  emxEnsureCapacity_real_T(List, i11);
  loop_ub_tmp = i10 * numObsIQ;
  for (i11 = 0; i11 < loop_ub_tmp; i11++) {
    List->data[i11] = 0.0;
  }

  emxInit_real_T(&Obs, 2);
  repmat(List, numIQ, Obs);
  i11 = newIC->size[0] * newIC->size[1];
  newIC->size[0] = Obs->size[0];
  newIC->size[1] = Obs->size[1];
  emxEnsureCapacity_int32_T(newIC, i11);
  nx = Obs->size[0] * Obs->size[1];
  for (i11 = 0; i11 < nx; i11++) {
    Pmax = rt_roundd(Obs->data[i11]);
    if (Pmax < 2.147483648E+9) {
      if (Pmax >= -2.147483648E+9) {
        i12 = (int)Pmax;
      } else {
        i12 = MIN_int32_T;
      }
    } else {
      i12 = MAX_int32_T;
    }

    newIC->data[i11] = i12;
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

    i13 = (long long)jj * i10;
    if (i13 > 2147483647LL) {
      i13 = 2147483647LL;
    } else {
      if (i13 < -2147483648LL) {
        i13 = -2147483648LL;
      }
    }

    jj = (int)i13;
    if (jj > 2147483646) {
      jj = MAX_int32_T;
    } else {
      jj++;
    }

    i13 = (long long)b_k * i10;
    if (i13 > 2147483647LL) {
      i13 = 2147483647LL;
    } else {
      if (i13 < -2147483648LL) {
        i13 = -2147483648LL;
      }
    }

    i11 = (int)i13;
    if (jj > i11) {
      i12 = -1;
      i11 = -1;
    } else {
      i12 = jj - 2;
      i11--;
    }

    if (0 <= numObsIQ - 1) {
      unnamed_idx_0 = (unsigned int)(i11 - i12);
    }

    for (u = 0; u < numObsIQ; u++) {
      i14 = IQ->size[1];
      b_ii = Obs->size[0] * Obs->size[1];
      Obs->size[0] = (int)unnamed_idx_0;
      Obs->size[1] = i14;
      emxEnsureCapacity_real_T(Obs, b_ii);
      nx = (int)unnamed_idx_0 * i14;
      for (i14 = 0; i14 < nx; i14++) {
        Obs->data[i14] = 0.0;
      }

      nx = IQ->size[1];
      i14 = Qtem->size[0] * Qtem->size[1];
      Qtem->size[0] = i11 - i12;
      Qtem->size[1] = nx;
      emxEnsureCapacity_real_T(Qtem, i14);
      for (i14 = 0; i14 < nx; i14++) {
        jj = i11 - i12;
        for (b_ii = 0; b_ii < jj; b_ii++) {
          Qtem->data[b_ii + Qtem->size[0] * i14] = IQ->data[((i12 + b_ii) +
            IQ->size[0] * i14) + 1];
        }
      }

      for (b_i = 0; b_i < i10; b_i++) {
        if (b_i + 1 <= Lim->data[0]) {
          if (1 > Lim->data[0]) {
            nx = 0;
          } else {
            nx = Lim->data[0];
          }

          i14 = c_Qtem->size[0] * c_Qtem->size[1];
          c_Qtem->size[0] = 1;
          c_Qtem->size[1] = nx;
          emxEnsureCapacity_real_T(c_Qtem, i14);
          for (i14 = 0; i14 < nx; i14++) {
            c_Qtem->data[i14] = Qtem->data[b_i + Qtem->size[0] * i14];
          }

          Pmax = sum(c_Qtem);
          if (1 > Lim->data[0]) {
            nx = 0;
          } else {
            nx = Lim->data[0];
          }

          i14 = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = nx;
          emxEnsureCapacity_boolean_T(x, i14);
          for (i14 = 0; i14 < nx; i14++) {
            x->data[i14] = (Qtem->data[b_i + Qtem->size[0] * i14] != 0.0);
          }

          nx = x->size[1];
          b_idx = 0;
          i14 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(ii, i14);
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
            i14 = ii->size[0] * ii->size[1];
            ii->size[1] = b_idx;
            emxEnsureCapacity_int32_T(ii, i14);
          }

          i14 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = ii->size[1];
          emxEnsureCapacity_real_T(idx, i14);
          nx = ii->size[0] * ii->size[1];
          for (i14 = 0; i14 < nx; i14++) {
            idx->data[i14] = ii->data[i14];
          }

          i14 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = idx->size[1];
          emxEnsureCapacity_real_T(Qtem2, i14);
          nx = idx->size[1];
          for (i14 = 0; i14 < nx; i14++) {
            Qtem2->data[i14] = Qtem->data[b_i + Qtem->size[0] * ((int)idx->
              data[i14] - 1)];
          }
        } else if ((b_i + 1 > Lim->data[0]) && (b_i + 1 <= Lim->data[1])) {
          if (1 > Lim->data[1]) {
            nx = 0;
          } else {
            nx = Lim->data[1];
          }

          i14 = c_Qtem->size[0] * c_Qtem->size[1];
          c_Qtem->size[0] = 1;
          c_Qtem->size[1] = nx;
          emxEnsureCapacity_real_T(c_Qtem, i14);
          for (i14 = 0; i14 < nx; i14++) {
            c_Qtem->data[i14] = Qtem->data[b_i + Qtem->size[0] * i14];
          }

          Pmax = sum(c_Qtem);
          if (Lim->data[0] + 1 > Lim->data[1]) {
            i14 = 0;
            b_ii = 0;
          } else {
            i14 = Lim->data[0];
            b_ii = Lim->data[1];
          }

          jj = x->size[0] * x->size[1];
          x->size[0] = 1;
          nx = b_ii - i14;
          x->size[1] = nx;
          emxEnsureCapacity_boolean_T(x, jj);
          for (b_ii = 0; b_ii < nx; b_ii++) {
            x->data[b_ii] = (Qtem->data[b_i + Qtem->size[0] * (i14 + b_ii)] !=
                             0.0);
          }

          nx = x->size[1];
          b_idx = 0;
          i14 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(ii, i14);
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
            i14 = ii->size[0] * ii->size[1];
            ii->size[1] = b_idx;
            emxEnsureCapacity_int32_T(ii, i14);
          }

          i14 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = ii->size[1];
          emxEnsureCapacity_real_T(idx, i14);
          jj = Lim->data[0];
          nx = ii->size[0] * ii->size[1];
          for (i14 = 0; i14 < nx; i14++) {
            idx->data[i14] = ii->data[i14] + jj;
          }

          i14 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = idx->size[1];
          emxEnsureCapacity_real_T(Qtem2, i14);
          nx = idx->size[1];
          for (i14 = 0; i14 < nx; i14++) {
            Qtem2->data[i14] = Qtem->data[b_i + Qtem->size[0] * ((int)idx->
              data[i14] - 1)];
          }
        } else if ((b_i + 1 > Lim->data[1]) && (b_i + 1 <= Lim->data[2])) {
          if (1 > Lim->data[2]) {
            nx = 0;
          } else {
            nx = Lim->data[2];
          }

          i14 = c_Qtem->size[0] * c_Qtem->size[1];
          c_Qtem->size[0] = 1;
          c_Qtem->size[1] = nx;
          emxEnsureCapacity_real_T(c_Qtem, i14);
          for (i14 = 0; i14 < nx; i14++) {
            c_Qtem->data[i14] = Qtem->data[b_i + Qtem->size[0] * i14];
          }

          Pmax = sum(c_Qtem);
          if (Lim->data[1] + 1 > Lim->data[2]) {
            i14 = 0;
            b_ii = 0;
          } else {
            i14 = Lim->data[1];
            b_ii = Lim->data[2];
          }

          jj = x->size[0] * x->size[1];
          x->size[0] = 1;
          nx = b_ii - i14;
          x->size[1] = nx;
          emxEnsureCapacity_boolean_T(x, jj);
          for (b_ii = 0; b_ii < nx; b_ii++) {
            x->data[b_ii] = (Qtem->data[b_i + Qtem->size[0] * (i14 + b_ii)] !=
                             0.0);
          }

          nx = x->size[1];
          b_idx = 0;
          i14 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(ii, i14);
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
            i14 = ii->size[0] * ii->size[1];
            ii->size[1] = b_idx;
            emxEnsureCapacity_int32_T(ii, i14);
          }

          i14 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = ii->size[1];
          emxEnsureCapacity_real_T(idx, i14);
          jj = Lim->data[1];
          nx = ii->size[0] * ii->size[1];
          for (i14 = 0; i14 < nx; i14++) {
            idx->data[i14] = ii->data[i14] + jj;
          }

          i14 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = idx->size[1];
          emxEnsureCapacity_real_T(Qtem2, i14);
          nx = idx->size[1];
          for (i14 = 0; i14 < nx; i14++) {
            Qtem2->data[i14] = Qtem->data[b_i + Qtem->size[0] * ((int)idx->
              data[i14] - 1)];
          }
        } else if ((b_i + 1 > Lim->data[2]) && (b_i + 1 <= Lim->data[3])) {
          if (1 > Lim->data[3]) {
            nx = 0;
          } else {
            nx = Lim->data[3];
          }

          i14 = c_Qtem->size[0] * c_Qtem->size[1];
          c_Qtem->size[0] = 1;
          c_Qtem->size[1] = nx;
          emxEnsureCapacity_real_T(c_Qtem, i14);
          for (i14 = 0; i14 < nx; i14++) {
            c_Qtem->data[i14] = Qtem->data[b_i + Qtem->size[0] * i14];
          }

          Pmax = sum(c_Qtem);
          if (Lim->data[2] + 1 > Lim->data[3]) {
            i14 = 0;
            b_ii = 0;
          } else {
            i14 = Lim->data[2];
            b_ii = Lim->data[3];
          }

          jj = x->size[0] * x->size[1];
          x->size[0] = 1;
          nx = b_ii - i14;
          x->size[1] = nx;
          emxEnsureCapacity_boolean_T(x, jj);
          for (b_ii = 0; b_ii < nx; b_ii++) {
            x->data[b_ii] = (Qtem->data[b_i + Qtem->size[0] * (i14 + b_ii)] !=
                             0.0);
          }

          nx = x->size[1];
          b_idx = 0;
          i14 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(ii, i14);
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
            i14 = ii->size[0] * ii->size[1];
            ii->size[1] = b_idx;
            emxEnsureCapacity_int32_T(ii, i14);
          }

          i14 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = ii->size[1];
          emxEnsureCapacity_real_T(idx, i14);
          jj = Lim->data[2];
          nx = ii->size[0] * ii->size[1];
          for (i14 = 0; i14 < nx; i14++) {
            idx->data[i14] = ii->data[i14] + jj;
          }

          i14 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = idx->size[1];
          emxEnsureCapacity_real_T(Qtem2, i14);
          nx = idx->size[1];
          for (i14 = 0; i14 < nx; i14++) {
            Qtem2->data[i14] = Qtem->data[b_i + Qtem->size[0] * ((int)idx->
              data[i14] - 1)];
          }
        } else {
          /* if i>Lim(4) && i<=Lim(5) */
          Pmax = 1.0;
          if (Lim->data[3] + 1 > Qtem->size[1]) {
            i14 = 0;
            b_ii = 0;
          } else {
            i14 = Lim->data[3];
            b_ii = Qtem->size[1];
          }

          jj = x->size[0] * x->size[1];
          x->size[0] = 1;
          nx = b_ii - i14;
          x->size[1] = nx;
          emxEnsureCapacity_boolean_T(x, jj);
          for (b_ii = 0; b_ii < nx; b_ii++) {
            x->data[b_ii] = (Qtem->data[b_i + Qtem->size[0] * (i14 + b_ii)] !=
                             0.0);
          }

          nx = x->size[1];
          b_idx = 0;
          i14 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(ii, i14);
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
            i14 = ii->size[0] * ii->size[1];
            ii->size[1] = b_idx;
            emxEnsureCapacity_int32_T(ii, i14);
          }

          i14 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = ii->size[1];
          emxEnsureCapacity_real_T(idx, i14);
          jj = Lim->data[3];
          nx = ii->size[0] * ii->size[1];
          for (i14 = 0; i14 < nx; i14++) {
            idx->data[i14] = (double)ii->data[i14] + (double)jj;
          }

          i14 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = idx->size[1];
          emxEnsureCapacity_real_T(Qtem2, i14);
          nx = idx->size[1];
          for (i14 = 0; i14 < nx; i14++) {
            Qtem2->data[i14] = Qtem->data[b_i + Qtem->size[0] * ((int)idx->
              data[i14] - 1)];
          }
        }

        Pmax *= d_rand();
        jj = 1;
        exitg1 = false;
        while ((!exitg1) && (jj - 1 <= Qtem2->size[1] - 1)) {
          i14 = b_Qtem2->size[0] * b_Qtem2->size[1];
          b_Qtem2->size[0] = 1;
          b_Qtem2->size[1] = jj;
          emxEnsureCapacity_real_T(b_Qtem2, i14);
          for (i14 = 0; i14 < jj; i14++) {
            b_Qtem2->data[i14] = Qtem2->data[i14];
          }

          guard1 = false;
          if (sum(b_Qtem2) <= Pmax) {
            i14 = b_Qtem2->size[0] * b_Qtem2->size[1];
            b_Qtem2->size[0] = 1;
            b_Qtem2->size[1] = jj + 1;
            emxEnsureCapacity_real_T(b_Qtem2, i14);
            for (i14 = 0; i14 <= jj; i14++) {
              b_Qtem2->data[i14] = Qtem2->data[i14];
            }

            if (sum(b_Qtem2) > Pmax) {
              Obs->data[b_i + Obs->size[0] * ((int)idx->data[jj] - 1)] = 1.0;
              nx = Qtem->size[0];
              b_idx = (int)idx->data[jj];
              i14 = b_ProbXEst->size[0];
              b_ProbXEst->size[0] = nx;
              emxEnsureCapacity_real_T(b_ProbXEst, i14);
              for (i14 = 0; i14 < nx; i14++) {
                b_ProbXEst->data[i14] = 1.0 - Qtem->data[i14 + Qtem->size[0] *
                  (b_idx - 1)];
              }

              b_rdivide_helper(b_ProbXEst, b_Qtem);
              nx = Qtem->size[0];
              i14 = b_Qtem->size[0];
              b_Qtem->size[0] = nx;
              emxEnsureCapacity_real_T(b_Qtem, i14);
              for (i14 = 0; i14 < nx; i14++) {
                b_Qtem->data[i14] *= Qtem->data[i14];
              }

              i14 = Qtem->size[0] * Qtem->size[1];
              Qtem->size[0] = b_Qtem->size[0];
              Qtem->size[1] = 1;
              emxEnsureCapacity_real_T(Qtem, i14);
              nx = b_Qtem->size[0];
              for (i14 = 0; i14 < nx; i14++) {
                Qtem->data[i14] = b_Qtem->data[i14];
              }

              nx = b_Qtem->size[0];
              for (i14 = 0; i14 < nx; i14++) {
                Qtem->data[i14] = 0.0;
              }

              exitg1 = true;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            i14 = b_Qtem2->size[0] * b_Qtem2->size[1];
            b_Qtem2->size[0] = 1;
            b_Qtem2->size[1] = jj;
            emxEnsureCapacity_real_T(b_Qtem2, i14);
            for (i14 = 0; i14 < jj; i14++) {
              b_Qtem2->data[i14] = Qtem2->data[i14];
            }

            if (sum(b_Qtem2) > Pmax) {
              Obs->data[b_i + Obs->size[0] * ((int)idx->data[jj - 1] - 1)] = 1.0;
              nx = Qtem->size[0];
              b_idx = (int)idx->data[jj - 1];
              i14 = b_ProbXEst->size[0];
              b_ProbXEst->size[0] = nx;
              emxEnsureCapacity_real_T(b_ProbXEst, i14);
              for (i14 = 0; i14 < nx; i14++) {
                b_ProbXEst->data[i14] = 1.0 - Qtem->data[i14 + Qtem->size[0] *
                  (b_idx - 1)];
              }

              b_rdivide_helper(b_ProbXEst, b_Qtem);
              nx = Qtem->size[0];
              i14 = b_Qtem->size[0];
              b_Qtem->size[0] = nx;
              emxEnsureCapacity_real_T(b_Qtem, i14);
              for (i14 = 0; i14 < nx; i14++) {
                b_Qtem->data[i14] *= Qtem->data[i14];
              }

              i14 = Qtem->size[0] * Qtem->size[1];
              Qtem->size[0] = b_Qtem->size[0];
              Qtem->size[1] = 1;
              emxEnsureCapacity_real_T(Qtem, i14);
              nx = b_Qtem->size[0];
              for (i14 = 0; i14 < nx; i14++) {
                Qtem->data[i14] = b_Qtem->data[i14];
              }

              nx = b_Qtem->size[0];
              for (i14 = 0; i14 < nx; i14++) {
                Qtem->data[i14] = 0.0;
              }

              exitg1 = true;
            } else {
              jj++;
            }
          }
        }
      }

      i14 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = Obs->size[1];
      b_x->size[1] = Obs->size[0];
      emxEnsureCapacity_boolean_T(b_x, i14);
      nx = Obs->size[0];
      for (i14 = 0; i14 < nx; i14++) {
        jj = Obs->size[1];
        for (b_ii = 0; b_ii < jj; b_ii++) {
          b_x->data[b_ii + b_x->size[0] * i14] = (Obs->data[i14 + Obs->size[0] *
            b_ii] == 1.0);
        }
      }

      nx = b_x->size[0] * b_x->size[1];
      if (nx == 0) {
        i->size[0] = 0;
      } else {
        b_idx = 0;
        i14 = i->size[0];
        i->size[0] = nx;
        emxEnsureCapacity_int32_T(i, i14);
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
          i14 = i->size[0];
          if (1 > b_idx) {
            i->size[0] = 0;
          } else {
            i->size[0] = b_idx;
          }

          emxEnsureCapacity_int32_T(i, i14);
        }
      }

      nx = i->size[0];
      for (i14 = 0; i14 < nx; i14++) {
        List->data[i14 + List->size[0] * u] = i->data[i14];
      }
    }

    if (b_k < -2147483647) {
      jj = MIN_int32_T;
    } else {
      jj = b_k - 1;
    }

    i13 = (long long)jj * numObsIQ;
    if (i13 > 2147483647LL) {
      i13 = 2147483647LL;
    } else {
      if (i13 < -2147483648LL) {
        i13 = -2147483648LL;
      }
    }

    jj = (int)i13;
    if (jj > 2147483646) {
      jj = MAX_int32_T;
    } else {
      jj++;
    }

    i13 = (long long)b_k * numObsIQ;
    if (i13 > 2147483647LL) {
      i13 = 2147483647LL;
    } else {
      if (i13 < -2147483648LL) {
        i13 = -2147483648LL;
      }
    }

    if (jj > (int)i13) {
      i11 = 1;
    } else {
      i11 = jj;
    }

    nx = List->size[1];
    for (i12 = 0; i12 < nx; i12++) {
      jj = List->size[0];
      for (i14 = 0; i14 < jj; i14++) {
        newIC->data[i14 + newIC->size[0] * ((i11 + i12) - 1)] = (int)List->
          data[i14 + List->size[0] * i12];
      }
    }

    i11 = List->size[0] * List->size[1];
    List->size[0] = i10;
    List->size[1] = numObsIQ;
    emxEnsureCapacity_real_T(List, i11);
    for (i11 = 0; i11 < loop_ub_tmp; i11++) {
      List->data[i11] = 0.0;
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

/* End of code generation (obsIQini.c) */
