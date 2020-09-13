/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * obsIQ.c
 *
 * Code generation for function 'obsIQ'
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
#include "model_emxutil.h"
#include "repmat.h"
#include "rdivide_helper.h"
#include "sum.h"
#include "rand.h"
#include "model_rtwutil.h"

/* Function Definitions */
void b_obsIQ(const emxArray_real_T *IQ, emxArray_int32_T *newIC)
{
  int i43;
  int jj;
  emxArray_int8_T *Obs;
  int ibtile;
  emxArray_real_T *Qtem;
  int idx;
  emxArray_real_T *r6;
  emxArray_boolean_T *x;
  int ibmat;
  emxArray_int16_T *ii;
  int k;
  emxArray_boolean_T *b_x;
  emxArray_int32_T *i;
  emxArray_real_T *r7;
  emxArray_real_T *r8;
  emxArray_real_T *r9;
  int unnamed_idx_0_tmp;
  int loop_ub;
  int u;
  int List_data[8000];
  int b_i;
  int b_ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  double r;
  double Qtem2_data[2000];
  int exitg2;
  int Qtem2_size[2];
  double b_Qtem2_data[2000];
  emxArray_real_T c_Qtem2_data;
  emxArray_real_T d_Qtem2_data;
  emxArray_real_T e_Qtem2_data;

  /* UNTITLED7 Summary of this function goes here */
  /*    Detailed explanation goes here, */
  i43 = newIC->size[0] * newIC->size[1];
  newIC->size[0] = 2000;
  newIC->size[1] = 20;
  emxEnsureCapacity_int32_T(newIC, i43);
  for (jj = 0; jj < 5; jj++) {
    ibtile = jj * 8000;
    for (idx = 0; idx < 4; idx++) {
      ibmat = ibtile + idx * 2000;
      for (k = 0; k < 2000; k++) {
        newIC->data[ibmat + k] = 0;
      }
    }
  }

  emxInit_int8_T(&Obs, 2);
  emxInit_real_T(&Qtem, 2);
  emxInit_real_T(&r6, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int16_T(&ii, 2);
  emxInit_boolean_T(&b_x, 2);
  emxInit_int32_T(&i, 1);
  emxInit_real_T(&r7, 1);
  emxInit_real_T(&r8, 2);
  emxInit_real_T(&r9, 1);
  for (k = 0; k < 5; k++) {
    i43 = k * 2000;
    jj = (1 + k) * 2000;
    if (i43 + 1 > jj) {
      i43 = 0;
      jj = 0;
    }

    unnamed_idx_0_tmp = jj - i43;
    loop_ub = (short)unnamed_idx_0_tmp * 2000;
    for (u = 0; u < 4; u++) {
      jj = Obs->size[0] * Obs->size[1];
      Obs->size[0] = (short)unnamed_idx_0_tmp;
      Obs->size[1] = 2000;
      emxEnsureCapacity_int8_T(Obs, jj);
      for (jj = 0; jj < loop_ub; jj++) {
        Obs->data[jj] = 0;
      }

      jj = Qtem->size[0] * Qtem->size[1];
      Qtem->size[0] = unnamed_idx_0_tmp;
      Qtem->size[1] = 2000;
      emxEnsureCapacity_real_T(Qtem, jj);
      for (jj = 0; jj < 2000; jj++) {
        for (ibtile = 0; ibtile < unnamed_idx_0_tmp; ibtile++) {
          Qtem->data[ibtile + Qtem->size[0] * jj] = IQ->data[(i43 + ibtile) +
            10000 * jj];
        }
      }

      for (b_i = 0; b_i < 2000; b_i++) {
        jj = x->size[0] * x->size[1];
        x->size[0] = 1;
        x->size[1] = 2000;
        emxEnsureCapacity_boolean_T(x, jj);
        for (jj = 0; jj < 2000; jj++) {
          x->data[jj] = (Qtem->data[b_i + Qtem->size[0] * jj] != 0.0);
        }

        idx = 0;
        jj = ii->size[0] * ii->size[1];
        ii->size[0] = 1;
        ii->size[1] = 2000;
        emxEnsureCapacity_int16_T(ii, jj);
        b_ii = 0;
        exitg1 = false;
        while ((!exitg1) && (b_ii <= 1999)) {
          if (x->data[b_ii]) {
            idx++;
            ii->data[idx - 1] = (short)(b_ii + 1);
            if (idx >= 2000) {
              exitg1 = true;
            } else {
              b_ii++;
            }
          } else {
            b_ii++;
          }
        }

        if (1 > idx) {
          ii->size[1] = 0;
        } else {
          jj = ii->size[0] * ii->size[1];
          ii->size[1] = idx;
          emxEnsureCapacity_int16_T(ii, jj);
        }

        ibmat = ii->size[1];
        for (jj = 0; jj < ibmat; jj++) {
          Qtem2_data[jj] = Qtem->data[b_i + Qtem->size[0] * (ii->data[jj] - 1)];
        }

        r = b_rand();
        idx = 1;
        do {
          exitg2 = 0;
          jj = ii->size[1];
          if (idx - 1 <= jj - 1) {
            Qtem2_size[0] = 1;
            Qtem2_size[1] = idx;
            if (0 <= idx - 1) {
              memcpy(&b_Qtem2_data[0], &Qtem2_data[0], (unsigned int)(idx * (int)
                      sizeof(double)));
            }

            c_Qtem2_data.data = &b_Qtem2_data[0];
            c_Qtem2_data.size = &Qtem2_size[0];
            c_Qtem2_data.allocatedSize = 2000;
            c_Qtem2_data.numDimensions = 2;
            c_Qtem2_data.canFreeData = false;
            if (sum(&c_Qtem2_data) > r) {
              Obs->data[b_i + Obs->size[0] * (ii->data[idx - 1] - 1)] = 1;
              ibmat = Qtem->size[0];
              b_ii = ii->data[idx - 1];
              jj = r9->size[0];
              r9->size[0] = ibmat;
              emxEnsureCapacity_real_T(r9, jj);
              for (jj = 0; jj < ibmat; jj++) {
                r9->data[jj] = 1.0 - Qtem->data[jj + Qtem->size[0] * (b_ii - 1)];
              }

              b_rdivide_helper(r9, r7);
              repmat(r7, 2000.0, r8);
              jj = r6->size[0] * r6->size[1];
              r6->size[0] = r8->size[0];
              r6->size[1] = r8->size[1];
              emxEnsureCapacity_real_T(r6, jj);
              ibmat = r8->size[0] * r8->size[1];
              for (jj = 0; jj < ibmat; jj++) {
                r6->data[jj] = r8->data[jj];
              }

              jj = Qtem->size[0] * Qtem->size[1];
              ibtile = Qtem->size[0] * Qtem->size[1];
              Qtem->size[1] = 2000;
              emxEnsureCapacity_real_T(Qtem, ibtile);
              ibmat = jj - 1;
              for (jj = 0; jj <= ibmat; jj++) {
                Qtem->data[jj] *= r6->data[jj];
              }

              ibmat = Qtem->size[0];
              b_ii = ii->data[idx - 1];
              for (jj = 0; jj < ibmat; jj++) {
                Qtem->data[jj + Qtem->size[0] * (b_ii - 1)] = 0.0;
              }

              exitg2 = 1;
            } else {
              Qtem2_size[0] = 1;
              Qtem2_size[1] = idx;
              if (0 <= idx - 1) {
                memcpy(&b_Qtem2_data[0], &Qtem2_data[0], (unsigned int)(idx *
                        (int)sizeof(double)));
              }

              d_Qtem2_data.data = &b_Qtem2_data[0];
              d_Qtem2_data.size = &Qtem2_size[0];
              d_Qtem2_data.allocatedSize = 2000;
              d_Qtem2_data.numDimensions = 2;
              d_Qtem2_data.canFreeData = false;
              if (sum(&d_Qtem2_data) <= r) {
                Qtem2_size[0] = 1;
                Qtem2_size[1] = idx + 1;
                if (0 <= idx) {
                  memcpy(&b_Qtem2_data[0], &Qtem2_data[0], (unsigned int)((idx +
                           1) * (int)sizeof(double)));
                }

                e_Qtem2_data.data = &b_Qtem2_data[0];
                e_Qtem2_data.size = &Qtem2_size[0];
                e_Qtem2_data.allocatedSize = 2000;
                e_Qtem2_data.numDimensions = 2;
                e_Qtem2_data.canFreeData = false;
                if (sum(&e_Qtem2_data) > r) {
                  Obs->data[b_i + Obs->size[0] * (ii->data[idx] - 1)] = 1;
                  ibmat = Qtem->size[0];
                  b_ii = ii->data[idx];
                  jj = r9->size[0];
                  r9->size[0] = ibmat;
                  emxEnsureCapacity_real_T(r9, jj);
                  for (jj = 0; jj < ibmat; jj++) {
                    r9->data[jj] = 1.0 - Qtem->data[jj + Qtem->size[0] * (b_ii -
                      1)];
                  }

                  b_rdivide_helper(r9, r7);
                  repmat(r7, 2000.0, r8);
                  jj = r6->size[0] * r6->size[1];
                  r6->size[0] = r8->size[0];
                  r6->size[1] = r8->size[1];
                  emxEnsureCapacity_real_T(r6, jj);
                  ibmat = r8->size[0] * r8->size[1];
                  for (jj = 0; jj < ibmat; jj++) {
                    r6->data[jj] = r8->data[jj];
                  }

                  jj = Qtem->size[0] * Qtem->size[1];
                  ibtile = Qtem->size[0] * Qtem->size[1];
                  Qtem->size[1] = 2000;
                  emxEnsureCapacity_real_T(Qtem, ibtile);
                  ibmat = jj - 1;
                  for (jj = 0; jj <= ibmat; jj++) {
                    Qtem->data[jj] *= r6->data[jj];
                  }

                  ibmat = Qtem->size[0];
                  b_ii = ii->data[idx];
                  for (jj = 0; jj < ibmat; jj++) {
                    Qtem->data[jj + Qtem->size[0] * (b_ii - 1)] = 0.0;
                  }

                  exitg2 = 1;
                } else {
                  idx++;
                }
              } else {
                idx++;
              }
            }
          } else {
            exitg2 = 1;
          }
        } while (exitg2 == 0);
      }

      jj = b_x->size[0] * b_x->size[1];
      b_x->size[0] = 2000;
      b_x->size[1] = Obs->size[0];
      emxEnsureCapacity_boolean_T(b_x, jj);
      ibmat = Obs->size[0];
      for (jj = 0; jj < ibmat; jj++) {
        for (ibtile = 0; ibtile < 2000; ibtile++) {
          b_x->data[ibtile + b_x->size[0] * jj] = (Obs->data[jj + Obs->size[0] *
            ibtile] == 1);
        }
      }

      ibtile = 2000 * b_x->size[1];
      if (ibtile == 0) {
        i->size[0] = 0;
      } else {
        idx = 0;
        jj = i->size[0];
        i->size[0] = ibtile;
        emxEnsureCapacity_int32_T(i, jj);
        b_ii = 1;
        jj = 1;
        exitg1 = false;
        while ((!exitg1) && (jj <= b_x->size[1])) {
          guard1 = false;
          if (b_x->data[(b_ii + b_x->size[0] * (jj - 1)) - 1]) {
            idx++;
            i->data[idx - 1] = b_ii;
            if (idx >= ibtile) {
              exitg1 = true;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            b_ii++;
            if (b_ii > 2000) {
              b_ii = 1;
              jj++;
            }
          }
        }

        if (ibtile == 1) {
          if (idx == 0) {
            i->size[0] = 0;
          }
        } else {
          jj = i->size[0];
          if (1 > idx) {
            i->size[0] = 0;
          } else {
            i->size[0] = idx;
          }

          emxEnsureCapacity_int32_T(i, jj);
        }
      }

      ibmat = i->size[0];
      for (jj = 0; jj < ibmat; jj++) {
        List_data[jj + 2000 * u] = i->data[jj];
      }
    }

    i43 = (k << 2) + 1;
    jj = (1 + k) << 2;
    if (i43 > jj) {
      i43 = 1;
      jj = 0;
    }

    loop_ub = (jj - i43) + 1;
    for (jj = 0; jj < loop_ub; jj++) {
      for (ibtile = 0; ibtile < 2000; ibtile++) {
        newIC->data[ibtile + 2000 * ((i43 + jj) - 1)] = List_data[ibtile + 2000 *
          jj];
      }
    }
  }

  emxFree_real_T(&r9);
  emxFree_real_T(&r8);
  emxFree_real_T(&r7);
  emxFree_int32_T(&i);
  emxFree_boolean_T(&b_x);
  emxFree_int16_T(&ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&r6);
  emxFree_real_T(&Qtem);
  emxFree_int8_T(&Obs);
}

void obsIQ(const emxArray_real_T *IQ, int numIQ, int numObsIQ, emxArray_int32_T *
           newIC)
{
  emxArray_int32_T *List;
  double r;
  int i1;
  int i2;
  int loop_ub_tmp;
  int jj;
  emxArray_int8_T *Obs;
  int ibtile;
  emxArray_real_T *Qtem;
  int nx;
  emxArray_uint32_T *idx;
  emxArray_real_T *Qtem2;
  int ibmat;
  emxArray_real_T *r1;
  int k;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_boolean_T *b_x;
  emxArray_real_T *r2;
  emxArray_int32_T *b_idx;
  emxArray_real_T *b_Qtem2;
  emxArray_real_T *r3;
  long long i3;
  int i4;
  unsigned int unnamed_idx_0;
  int u;
  int i5;
  int c_idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int exitg2;
  emxInit_int32_T(&List, 2);

  /* UNTITLED7 Summary of this function goes here */
  /*    Detailed explanation goes here, */
  r = rt_roundd((double)IQ->size[0] / (double)numIQ);
  if (r < 2.147483648E+9) {
    if (r >= -2.147483648E+9) {
      i1 = (int)r;
    } else {
      i1 = MIN_int32_T;
    }
  } else {
    i1 = MAX_int32_T;
  }

  i2 = List->size[0] * List->size[1];
  List->size[0] = i1;
  List->size[1] = numObsIQ;
  emxEnsureCapacity_int32_T(List, i2);
  loop_ub_tmp = i1 * numObsIQ;
  for (i2 = 0; i2 < loop_ub_tmp; i2++) {
    List->data[i2] = 0;
  }

  i2 = newIC->size[0] * newIC->size[1];
  newIC->size[0] = i1;
  newIC->size[1] = numObsIQ * numIQ;
  emxEnsureCapacity_int32_T(newIC, i2);
  for (jj = 0; jj < numIQ; jj++) {
    ibtile = jj * loop_ub_tmp;
    for (nx = 0; nx < numObsIQ; nx++) {
      ibmat = ibtile + nx * i1;
      for (k = 0; k < i1; k++) {
        newIC->data[ibmat + k] = 0;
      }
    }
  }

  emxInit_int8_T(&Obs, 2);
  emxInit_real_T(&Qtem, 2);
  emxInit_uint32_T(&idx, 2);
  emxInit_real_T(&Qtem2, 2);
  emxInit_real_T(&r1, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&ii, 2);
  emxInit_boolean_T(&b_x, 2);
  emxInit_real_T(&r2, 1);
  emxInit_int32_T(&b_idx, 1);
  emxInit_real_T(&b_Qtem2, 2);
  emxInit_real_T(&r3, 1);
  for (k = 0; k < numIQ; k++) {
    i3 = (long long)k * i1;
    if (i3 > 2147483647LL) {
      i3 = 2147483647LL;
    } else {
      if (i3 < -2147483648LL) {
        i3 = -2147483648LL;
      }
    }

    jj = (int)i3;
    if (jj > 2147483646) {
      jj = MAX_int32_T;
    } else {
      jj++;
    }

    i3 = (long long)(k + 1) * i1;
    if (i3 > 2147483647LL) {
      i3 = 2147483647LL;
    } else {
      if (i3 < -2147483648LL) {
        i3 = -2147483648LL;
      }
    }

    i2 = (int)i3;
    if (jj > i2) {
      i4 = -1;
      i2 = -1;
    } else {
      i4 = jj - 2;
      i2--;
    }

    if (0 <= numObsIQ - 1) {
      unnamed_idx_0 = (unsigned int)(i2 - i4);
    }

    for (u = 0; u < numObsIQ; u++) {
      i5 = IQ->size[1];
      ibtile = Obs->size[0] * Obs->size[1];
      Obs->size[0] = (int)unnamed_idx_0;
      Obs->size[1] = i5;
      emxEnsureCapacity_int8_T(Obs, ibtile);
      nx = (int)unnamed_idx_0 * i5;
      for (i5 = 0; i5 < nx; i5++) {
        Obs->data[i5] = 0;
      }

      nx = IQ->size[1];
      i5 = Qtem->size[0] * Qtem->size[1];
      Qtem->size[0] = i2 - i4;
      Qtem->size[1] = nx;
      emxEnsureCapacity_real_T(Qtem, i5);
      for (i5 = 0; i5 < nx; i5++) {
        jj = i2 - i4;
        for (ibtile = 0; ibtile < jj; ibtile++) {
          Qtem->data[ibtile + Qtem->size[0] * i5] = IQ->data[((i4 + ibtile) +
            IQ->size[0] * i5) + 1];
        }
      }

      for (jj = 0; jj < i1; jj++) {
        nx = Qtem->size[1];
        i5 = x->size[0] * x->size[1];
        x->size[0] = 1;
        x->size[1] = nx;
        emxEnsureCapacity_boolean_T(x, i5);
        for (i5 = 0; i5 < nx; i5++) {
          x->data[i5] = (Qtem->data[jj + Qtem->size[0] * i5] != 0.0);
        }

        nx = x->size[1];
        c_idx = 0;
        i5 = ii->size[0] * ii->size[1];
        ii->size[0] = 1;
        ii->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(ii, i5);
        ibtile = 0;
        exitg1 = false;
        while ((!exitg1) && (ibtile <= nx - 1)) {
          if (x->data[ibtile]) {
            c_idx++;
            ii->data[c_idx - 1] = ibtile + 1;
            if (c_idx >= nx) {
              exitg1 = true;
            } else {
              ibtile++;
            }
          } else {
            ibtile++;
          }
        }

        if (x->size[1] == 1) {
          if (c_idx == 0) {
            ii->size[0] = 1;
            ii->size[1] = 0;
          }
        } else if (1 > c_idx) {
          ii->size[1] = 0;
        } else {
          i5 = ii->size[0] * ii->size[1];
          ii->size[1] = c_idx;
          emxEnsureCapacity_int32_T(ii, i5);
        }

        i5 = idx->size[0] * idx->size[1];
        idx->size[0] = 1;
        idx->size[1] = ii->size[1];
        emxEnsureCapacity_uint32_T(idx, i5);
        nx = ii->size[0] * ii->size[1];
        for (i5 = 0; i5 < nx; i5++) {
          idx->data[i5] = (unsigned int)ii->data[i5];
        }

        i5 = Qtem2->size[0] * Qtem2->size[1];
        Qtem2->size[0] = 1;
        Qtem2->size[1] = idx->size[1];
        emxEnsureCapacity_real_T(Qtem2, i5);
        nx = idx->size[1];
        for (i5 = 0; i5 < nx; i5++) {
          Qtem2->data[i5] = Qtem->data[jj + Qtem->size[0] * ((int)idx->data[i5]
            - 1)];
        }

        r = b_rand();
        ibmat = 1;
        do {
          exitg2 = 0;
          i5 = b_idx->size[0];
          b_idx->size[0] = idx->size[1];
          emxEnsureCapacity_int32_T(b_idx, i5);
          nx = idx->size[1];
          for (i5 = 0; i5 < nx; i5++) {
            b_idx->data[i5] = (int)idx->data[i5];
          }

          if (ibmat - 1 <= b_idx->size[0] - 1) {
            i5 = b_idx->size[0];
            b_idx->size[0] = idx->size[1];
            emxEnsureCapacity_int32_T(b_idx, i5);
            nx = idx->size[1];
            for (i5 = 0; i5 < nx; i5++) {
              b_idx->data[i5] = (int)idx->data[i5];
            }

            i5 = b_Qtem2->size[0] * b_Qtem2->size[1];
            b_Qtem2->size[0] = 1;
            b_Qtem2->size[1] = ibmat;
            emxEnsureCapacity_real_T(b_Qtem2, i5);
            for (i5 = 0; i5 < ibmat; i5++) {
              b_Qtem2->data[i5] = Qtem2->data[i5];
            }

            if (sum(b_Qtem2) > r) {
              Obs->data[jj + Obs->size[0] * ((int)idx->data[ibmat - 1] - 1)] = 1;
              nx = Qtem->size[0];
              c_idx = (int)idx->data[ibmat - 1];
              i5 = r3->size[0];
              r3->size[0] = nx;
              emxEnsureCapacity_real_T(r3, i5);
              for (i5 = 0; i5 < nx; i5++) {
                r3->data[i5] = 1.0 - Qtem->data[i5 + Qtem->size[0] * (c_idx - 1)];
              }

              b_rdivide_helper(r3, r2);
              repmat(r2, Qtem->size[1], r1);
              i5 = Qtem->size[0] * Qtem->size[1];
              ibtile = Qtem->size[0] * Qtem->size[1];
              emxEnsureCapacity_real_T(Qtem, ibtile);
              nx = i5 - 1;
              for (i5 = 0; i5 <= nx; i5++) {
                Qtem->data[i5] *= r1->data[i5];
              }

              nx = Qtem->size[0];
              c_idx = (int)idx->data[ibmat - 1];
              for (i5 = 0; i5 < nx; i5++) {
                Qtem->data[i5 + Qtem->size[0] * (c_idx - 1)] = 0.0;
              }

              exitg2 = 1;
            } else {
              i5 = b_Qtem2->size[0] * b_Qtem2->size[1];
              b_Qtem2->size[0] = 1;
              b_Qtem2->size[1] = ibmat;
              emxEnsureCapacity_real_T(b_Qtem2, i5);
              for (i5 = 0; i5 < ibmat; i5++) {
                b_Qtem2->data[i5] = Qtem2->data[i5];
              }

              if (sum(b_Qtem2) <= r) {
                i5 = b_idx->size[0];
                b_idx->size[0] = idx->size[1];
                emxEnsureCapacity_int32_T(b_idx, i5);
                nx = idx->size[1];
                for (i5 = 0; i5 < nx; i5++) {
                  b_idx->data[i5] = (int)idx->data[i5];
                }

                i5 = b_Qtem2->size[0] * b_Qtem2->size[1];
                b_Qtem2->size[0] = 1;
                b_Qtem2->size[1] = ibmat + 1;
                emxEnsureCapacity_real_T(b_Qtem2, i5);
                for (i5 = 0; i5 <= ibmat; i5++) {
                  b_Qtem2->data[i5] = Qtem2->data[i5];
                }

                if (sum(b_Qtem2) > r) {
                  Obs->data[jj + Obs->size[0] * ((int)idx->data[ibmat] - 1)] = 1;
                  nx = Qtem->size[0];
                  c_idx = (int)idx->data[ibmat];
                  i5 = r3->size[0];
                  r3->size[0] = nx;
                  emxEnsureCapacity_real_T(r3, i5);
                  for (i5 = 0; i5 < nx; i5++) {
                    r3->data[i5] = 1.0 - Qtem->data[i5 + Qtem->size[0] * (c_idx
                      - 1)];
                  }

                  b_rdivide_helper(r3, r2);
                  repmat(r2, Qtem->size[1], r1);
                  i5 = Qtem->size[0] * Qtem->size[1];
                  ibtile = Qtem->size[0] * Qtem->size[1];
                  emxEnsureCapacity_real_T(Qtem, ibtile);
                  nx = i5 - 1;
                  for (i5 = 0; i5 <= nx; i5++) {
                    Qtem->data[i5] *= r1->data[i5];
                  }

                  nx = Qtem->size[0];
                  c_idx = (int)idx->data[ibmat];
                  for (i5 = 0; i5 < nx; i5++) {
                    Qtem->data[i5 + Qtem->size[0] * (c_idx - 1)] = 0.0;
                  }

                  exitg2 = 1;
                } else {
                  ibmat++;
                }
              } else {
                ibmat++;
              }
            }
          } else {
            exitg2 = 1;
          }
        } while (exitg2 == 0);
      }

      i5 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = Obs->size[1];
      b_x->size[1] = Obs->size[0];
      emxEnsureCapacity_boolean_T(b_x, i5);
      nx = Obs->size[0];
      for (i5 = 0; i5 < nx; i5++) {
        jj = Obs->size[1];
        for (ibtile = 0; ibtile < jj; ibtile++) {
          b_x->data[ibtile + b_x->size[0] * i5] = (Obs->data[i5 + Obs->size[0] *
            ibtile] == 1);
        }
      }

      nx = b_x->size[0] * b_x->size[1];
      if (nx == 0) {
        b_idx->size[0] = 0;
      } else {
        c_idx = 0;
        i5 = b_idx->size[0];
        b_idx->size[0] = nx;
        emxEnsureCapacity_int32_T(b_idx, i5);
        ibtile = 1;
        jj = 1;
        exitg1 = false;
        while ((!exitg1) && (jj <= b_x->size[1])) {
          guard1 = false;
          if (b_x->data[(ibtile + b_x->size[0] * (jj - 1)) - 1]) {
            c_idx++;
            b_idx->data[c_idx - 1] = ibtile;
            if (c_idx >= nx) {
              exitg1 = true;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            ibtile++;
            if (ibtile > b_x->size[0]) {
              ibtile = 1;
              jj++;
            }
          }
        }

        if (nx == 1) {
          if (c_idx == 0) {
            b_idx->size[0] = 0;
          }
        } else {
          i5 = b_idx->size[0];
          if (1 > c_idx) {
            b_idx->size[0] = 0;
          } else {
            b_idx->size[0] = c_idx;
          }

          emxEnsureCapacity_int32_T(b_idx, i5);
        }
      }

      nx = b_idx->size[0];
      for (i5 = 0; i5 < nx; i5++) {
        List->data[i5 + List->size[0] * u] = b_idx->data[i5];
      }
    }

    i3 = (long long)k * numObsIQ;
    if (i3 > 2147483647LL) {
      i3 = 2147483647LL;
    } else {
      if (i3 < -2147483648LL) {
        i3 = -2147483648LL;
      }
    }

    jj = (int)i3;
    if (jj > 2147483646) {
      jj = MAX_int32_T;
    } else {
      jj++;
    }

    i3 = (long long)(k + 1) * numObsIQ;
    if (i3 > 2147483647LL) {
      i3 = 2147483647LL;
    } else {
      if (i3 < -2147483648LL) {
        i3 = -2147483648LL;
      }
    }

    if (jj > (int)i3) {
      i2 = 1;
    } else {
      i2 = jj;
    }

    nx = List->size[1];
    for (i4 = 0; i4 < nx; i4++) {
      jj = List->size[0];
      for (i5 = 0; i5 < jj; i5++) {
        newIC->data[i5 + newIC->size[0] * ((i2 + i4) - 1)] = List->data[i5 +
          List->size[0] * i4];
      }
    }

    i2 = List->size[0] * List->size[1];
    List->size[0] = i1;
    List->size[1] = numObsIQ;
    emxEnsureCapacity_int32_T(List, i2);
    for (i2 = 0; i2 < loop_ub_tmp; i2++) {
      List->data[i2] = 0;
    }
  }

  emxFree_real_T(&r3);
  emxFree_real_T(&b_Qtem2);
  emxFree_int32_T(&b_idx);
  emxFree_real_T(&r2);
  emxFree_boolean_T(&b_x);
  emxFree_int32_T(&ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&r1);
  emxFree_real_T(&Qtem2);
  emxFree_uint32_T(&idx);
  emxFree_real_T(&Qtem);
  emxFree_int8_T(&Obs);
  emxFree_int32_T(&List);
}

/* End of code generation (obsIQ.c) */
