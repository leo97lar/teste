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
void obsIQ(const emxArray_real_T *IQ, int numIQ, int numObsIQ, emxArray_int32_T *
           newIC)
{
  emxArray_int32_T *List;
  double r;
  int i9;
  int i10;
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
  long long i11;
  int i12;
  unsigned int unnamed_idx_0;
  int u;
  int i13;
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
      i9 = (int)r;
    } else {
      i9 = MIN_int32_T;
    }
  } else {
    i9 = MAX_int32_T;
  }

  i10 = List->size[0] * List->size[1];
  List->size[0] = i9;
  List->size[1] = numObsIQ;
  emxEnsureCapacity_int32_T(List, i10);
  loop_ub_tmp = i9 * numObsIQ;
  for (i10 = 0; i10 < loop_ub_tmp; i10++) {
    List->data[i10] = 0;
  }

  i10 = newIC->size[0] * newIC->size[1];
  newIC->size[0] = i9;
  newIC->size[1] = numObsIQ * numIQ;
  emxEnsureCapacity_int32_T(newIC, i10);
  for (jj = 0; jj < numIQ; jj++) {
    ibtile = jj * loop_ub_tmp;
    for (nx = 0; nx < numObsIQ; nx++) {
      ibmat = ibtile + nx * i9;
      for (k = 0; k < i9; k++) {
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
    i11 = (long long)k * i9;
    if (i11 > 2147483647LL) {
      i11 = 2147483647LL;
    } else {
      if (i11 < -2147483648LL) {
        i11 = -2147483648LL;
      }
    }

    jj = (int)i11;
    if (jj > 2147483646) {
      jj = MAX_int32_T;
    } else {
      jj++;
    }

    i11 = (long long)(k + 1) * i9;
    if (i11 > 2147483647LL) {
      i11 = 2147483647LL;
    } else {
      if (i11 < -2147483648LL) {
        i11 = -2147483648LL;
      }
    }

    i10 = (int)i11;
    if (jj > i10) {
      i12 = -1;
      i10 = -1;
    } else {
      i12 = jj - 2;
      i10--;
    }

    if (0 <= numObsIQ - 1) {
      unnamed_idx_0 = (unsigned int)(i10 - i12);
    }

    for (u = 0; u < numObsIQ; u++) {
      i13 = IQ->size[1];
      ibtile = Obs->size[0] * Obs->size[1];
      Obs->size[0] = (int)unnamed_idx_0;
      Obs->size[1] = i13;
      emxEnsureCapacity_int8_T(Obs, ibtile);
      nx = (int)unnamed_idx_0 * i13;
      for (i13 = 0; i13 < nx; i13++) {
        Obs->data[i13] = 0;
      }

      nx = IQ->size[1];
      i13 = Qtem->size[0] * Qtem->size[1];
      Qtem->size[0] = i10 - i12;
      Qtem->size[1] = nx;
      emxEnsureCapacity_real_T(Qtem, i13);
      for (i13 = 0; i13 < nx; i13++) {
        jj = i10 - i12;
        for (ibtile = 0; ibtile < jj; ibtile++) {
          Qtem->data[ibtile + Qtem->size[0] * i13] = IQ->data[((i12 + ibtile) +
            IQ->size[0] * i13) + 1];
        }
      }

      for (jj = 0; jj < i9; jj++) {
        nx = Qtem->size[1];
        i13 = x->size[0] * x->size[1];
        x->size[0] = 1;
        x->size[1] = nx;
        emxEnsureCapacity_boolean_T(x, i13);
        for (i13 = 0; i13 < nx; i13++) {
          x->data[i13] = (Qtem->data[jj + Qtem->size[0] * i13] != 0.0);
        }

        nx = x->size[1];
        c_idx = 0;
        i13 = ii->size[0] * ii->size[1];
        ii->size[0] = 1;
        ii->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(ii, i13);
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
          i13 = ii->size[0] * ii->size[1];
          ii->size[1] = c_idx;
          emxEnsureCapacity_int32_T(ii, i13);
        }

        i13 = idx->size[0] * idx->size[1];
        idx->size[0] = 1;
        idx->size[1] = ii->size[1];
        emxEnsureCapacity_uint32_T(idx, i13);
        nx = ii->size[0] * ii->size[1];
        for (i13 = 0; i13 < nx; i13++) {
          idx->data[i13] = (unsigned int)ii->data[i13];
        }

        i13 = Qtem2->size[0] * Qtem2->size[1];
        Qtem2->size[0] = 1;
        Qtem2->size[1] = idx->size[1];
        emxEnsureCapacity_real_T(Qtem2, i13);
        nx = idx->size[1];
        for (i13 = 0; i13 < nx; i13++) {
          Qtem2->data[i13] = Qtem->data[jj + Qtem->size[0] * ((int)idx->data[i13]
            - 1)];
        }

        r = b_rand();
        ibmat = 1;
        do {
          exitg2 = 0;
          i13 = b_idx->size[0];
          b_idx->size[0] = idx->size[1];
          emxEnsureCapacity_int32_T(b_idx, i13);
          nx = idx->size[1];
          for (i13 = 0; i13 < nx; i13++) {
            b_idx->data[i13] = (int)idx->data[i13];
          }

          if (ibmat - 1 <= b_idx->size[0] - 1) {
            i13 = b_idx->size[0];
            b_idx->size[0] = idx->size[1];
            emxEnsureCapacity_int32_T(b_idx, i13);
            nx = idx->size[1];
            for (i13 = 0; i13 < nx; i13++) {
              b_idx->data[i13] = (int)idx->data[i13];
            }

            i13 = b_Qtem2->size[0] * b_Qtem2->size[1];
            b_Qtem2->size[0] = 1;
            b_Qtem2->size[1] = ibmat;
            emxEnsureCapacity_real_T(b_Qtem2, i13);
            for (i13 = 0; i13 < ibmat; i13++) {
              b_Qtem2->data[i13] = Qtem2->data[i13];
            }

            if (b_sum(b_Qtem2) > r) {
              Obs->data[jj + Obs->size[0] * ((int)idx->data[ibmat - 1] - 1)] = 1;
              nx = Qtem->size[0];
              c_idx = (int)idx->data[ibmat - 1];
              i13 = r3->size[0];
              r3->size[0] = nx;
              emxEnsureCapacity_real_T(r3, i13);
              for (i13 = 0; i13 < nx; i13++) {
                r3->data[i13] = 1.0 - Qtem->data[i13 + Qtem->size[0] * (c_idx -
                  1)];
              }

              b_rdivide_helper(r3, r2);
              b_repmat(r2, Qtem->size[1], r1);
              i13 = Qtem->size[0] * Qtem->size[1];
              ibtile = Qtem->size[0] * Qtem->size[1];
              emxEnsureCapacity_real_T(Qtem, ibtile);
              nx = i13 - 1;
              for (i13 = 0; i13 <= nx; i13++) {
                Qtem->data[i13] *= r1->data[i13];
              }

              nx = Qtem->size[0];
              c_idx = (int)idx->data[ibmat - 1];
              for (i13 = 0; i13 < nx; i13++) {
                Qtem->data[i13 + Qtem->size[0] * (c_idx - 1)] = 0.0;
              }

              exitg2 = 1;
            } else {
              i13 = b_Qtem2->size[0] * b_Qtem2->size[1];
              b_Qtem2->size[0] = 1;
              b_Qtem2->size[1] = ibmat;
              emxEnsureCapacity_real_T(b_Qtem2, i13);
              for (i13 = 0; i13 < ibmat; i13++) {
                b_Qtem2->data[i13] = Qtem2->data[i13];
              }

              if (b_sum(b_Qtem2) <= r) {
                i13 = b_idx->size[0];
                b_idx->size[0] = idx->size[1];
                emxEnsureCapacity_int32_T(b_idx, i13);
                nx = idx->size[1];
                for (i13 = 0; i13 < nx; i13++) {
                  b_idx->data[i13] = (int)idx->data[i13];
                }

                i13 = b_Qtem2->size[0] * b_Qtem2->size[1];
                b_Qtem2->size[0] = 1;
                b_Qtem2->size[1] = ibmat + 1;
                emxEnsureCapacity_real_T(b_Qtem2, i13);
                for (i13 = 0; i13 <= ibmat; i13++) {
                  b_Qtem2->data[i13] = Qtem2->data[i13];
                }

                if (b_sum(b_Qtem2) > r) {
                  Obs->data[jj + Obs->size[0] * ((int)idx->data[ibmat] - 1)] = 1;
                  nx = Qtem->size[0];
                  c_idx = (int)idx->data[ibmat];
                  i13 = r3->size[0];
                  r3->size[0] = nx;
                  emxEnsureCapacity_real_T(r3, i13);
                  for (i13 = 0; i13 < nx; i13++) {
                    r3->data[i13] = 1.0 - Qtem->data[i13 + Qtem->size[0] *
                      (c_idx - 1)];
                  }

                  b_rdivide_helper(r3, r2);
                  b_repmat(r2, Qtem->size[1], r1);
                  i13 = Qtem->size[0] * Qtem->size[1];
                  ibtile = Qtem->size[0] * Qtem->size[1];
                  emxEnsureCapacity_real_T(Qtem, ibtile);
                  nx = i13 - 1;
                  for (i13 = 0; i13 <= nx; i13++) {
                    Qtem->data[i13] *= r1->data[i13];
                  }

                  nx = Qtem->size[0];
                  c_idx = (int)idx->data[ibmat];
                  for (i13 = 0; i13 < nx; i13++) {
                    Qtem->data[i13 + Qtem->size[0] * (c_idx - 1)] = 0.0;
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

      i13 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = Obs->size[1];
      b_x->size[1] = Obs->size[0];
      emxEnsureCapacity_boolean_T(b_x, i13);
      nx = Obs->size[0];
      for (i13 = 0; i13 < nx; i13++) {
        jj = Obs->size[1];
        for (ibtile = 0; ibtile < jj; ibtile++) {
          b_x->data[ibtile + b_x->size[0] * i13] = (Obs->data[i13 + Obs->size[0]
            * ibtile] == 1);
        }
      }

      nx = b_x->size[0] * b_x->size[1];
      if (nx == 0) {
        b_idx->size[0] = 0;
      } else {
        c_idx = 0;
        i13 = b_idx->size[0];
        b_idx->size[0] = nx;
        emxEnsureCapacity_int32_T(b_idx, i13);
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
          i13 = b_idx->size[0];
          if (1 > c_idx) {
            b_idx->size[0] = 0;
          } else {
            b_idx->size[0] = c_idx;
          }

          emxEnsureCapacity_int32_T(b_idx, i13);
        }
      }

      nx = b_idx->size[0];
      for (i13 = 0; i13 < nx; i13++) {
        List->data[i13 + List->size[0] * u] = b_idx->data[i13];
      }
    }

    i11 = (long long)k * numObsIQ;
    if (i11 > 2147483647LL) {
      i11 = 2147483647LL;
    } else {
      if (i11 < -2147483648LL) {
        i11 = -2147483648LL;
      }
    }

    jj = (int)i11;
    if (jj > 2147483646) {
      jj = MAX_int32_T;
    } else {
      jj++;
    }

    i11 = (long long)(k + 1) * numObsIQ;
    if (i11 > 2147483647LL) {
      i11 = 2147483647LL;
    } else {
      if (i11 < -2147483648LL) {
        i11 = -2147483648LL;
      }
    }

    if (jj > (int)i11) {
      i10 = 1;
    } else {
      i10 = jj;
    }

    nx = List->size[1];
    for (i12 = 0; i12 < nx; i12++) {
      jj = List->size[0];
      for (i13 = 0; i13 < jj; i13++) {
        newIC->data[i13 + newIC->size[0] * ((i10 + i12) - 1)] = List->data[i13 +
          List->size[0] * i12];
      }
    }

    i10 = List->size[0] * List->size[1];
    List->size[0] = i9;
    List->size[1] = numObsIQ;
    emxEnsureCapacity_int32_T(List, i10);
    for (i10 = 0; i10 < loop_ub_tmp; i10++) {
      List->data[i10] = 0;
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
