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
#include "main_UCI_func.h"
#include "obsIQ.h"
#include "model_emxutil.h"
#include "repmat.h"
#include "rdivide_helper.h"
#include "sum.h"
#include "rand.h"
#include "obsIQini.h"
#include "model_rtwutil.h"

/* Function Definitions */
void obsIQ(const emxArray_real_T *IQ, int numIQ, int numObsIQ, emxArray_int32_T *
           newIC)
{
  emxArray_int32_T *List;
  double r;
  int i16;
  int i17;
  int loop_ub_tmp;
  int jj;
  emxArray_int8_T *Obs;
  int ibtile;
  emxArray_real_T *Qtem;
  int nx;
  emxArray_uint32_T *idx;
  emxArray_real_T *Qtem2;
  int ibmat;
  emxArray_real_T *r4;
  int k;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_boolean_T *b_x;
  emxArray_real_T *r5;
  emxArray_int32_T *b_idx;
  emxArray_real_T *b_Qtem2;
  emxArray_real_T *r6;
  long long i18;
  int i19;
  unsigned int unnamed_idx_0;
  int u;
  int i20;
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
      i16 = (int)r;
    } else {
      i16 = MIN_int32_T;
    }
  } else {
    i16 = MAX_int32_T;
  }

  i17 = List->size[0] * List->size[1];
  List->size[0] = i16;
  List->size[1] = numObsIQ;
  emxEnsureCapacity_int32_T(List, i17);
  loop_ub_tmp = i16 * numObsIQ;
  for (i17 = 0; i17 < loop_ub_tmp; i17++) {
    List->data[i17] = 0;
  }

  i17 = newIC->size[0] * newIC->size[1];
  newIC->size[0] = i16;
  newIC->size[1] = numObsIQ * numIQ;
  emxEnsureCapacity_int32_T(newIC, i17);
  for (jj = 0; jj < numIQ; jj++) {
    ibtile = jj * loop_ub_tmp;
    for (nx = 0; nx < numObsIQ; nx++) {
      ibmat = ibtile + nx * i16;
      for (k = 0; k < i16; k++) {
        newIC->data[ibmat + k] = 0;
      }
    }
  }

  emxInit_int8_T(&Obs, 2);
  emxInit_real_T(&Qtem, 2);
  emxInit_uint32_T(&idx, 2);
  emxInit_real_T(&Qtem2, 2);
  emxInit_real_T(&r4, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&ii, 2);
  emxInit_boolean_T(&b_x, 2);
  emxInit_real_T(&r5, 1);
  emxInit_int32_T(&b_idx, 1);
  emxInit_real_T(&b_Qtem2, 2);
  emxInit_real_T(&r6, 1);
  for (k = 0; k < numIQ; k++) {
    i18 = (long long)k * i16;
    if (i18 > 2147483647LL) {
      i18 = 2147483647LL;
    } else {
      if (i18 < -2147483648LL) {
        i18 = -2147483648LL;
      }
    }

    jj = (int)i18;
    if (jj > 2147483646) {
      jj = MAX_int32_T;
    } else {
      jj++;
    }

    i18 = (long long)(k + 1) * i16;
    if (i18 > 2147483647LL) {
      i18 = 2147483647LL;
    } else {
      if (i18 < -2147483648LL) {
        i18 = -2147483648LL;
      }
    }

    i17 = (int)i18;
    if (jj > i17) {
      i19 = -1;
      i17 = -1;
    } else {
      i19 = jj - 2;
      i17--;
    }

    if (0 <= numObsIQ - 1) {
      unnamed_idx_0 = (unsigned int)(i17 - i19);
    }

    for (u = 0; u < numObsIQ; u++) {
      i20 = IQ->size[1];
      ibtile = Obs->size[0] * Obs->size[1];
      Obs->size[0] = (int)unnamed_idx_0;
      Obs->size[1] = i20;
      emxEnsureCapacity_int8_T(Obs, ibtile);
      nx = (int)unnamed_idx_0 * i20;
      for (i20 = 0; i20 < nx; i20++) {
        Obs->data[i20] = 0;
      }

      nx = IQ->size[1];
      i20 = Qtem->size[0] * Qtem->size[1];
      Qtem->size[0] = i17 - i19;
      Qtem->size[1] = nx;
      emxEnsureCapacity_real_T(Qtem, i20);
      for (i20 = 0; i20 < nx; i20++) {
        jj = i17 - i19;
        for (ibtile = 0; ibtile < jj; ibtile++) {
          Qtem->data[ibtile + Qtem->size[0] * i20] = IQ->data[((i19 + ibtile) +
            IQ->size[0] * i20) + 1];
        }
      }

      for (jj = 0; jj < i16; jj++) {
        nx = Qtem->size[1];
        i20 = x->size[0] * x->size[1];
        x->size[0] = 1;
        x->size[1] = nx;
        emxEnsureCapacity_boolean_T(x, i20);
        for (i20 = 0; i20 < nx; i20++) {
          x->data[i20] = (Qtem->data[jj + Qtem->size[0] * i20] != 0.0);
        }

        nx = x->size[1];
        c_idx = 0;
        i20 = ii->size[0] * ii->size[1];
        ii->size[0] = 1;
        ii->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(ii, i20);
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
          i20 = ii->size[0] * ii->size[1];
          ii->size[1] = c_idx;
          emxEnsureCapacity_int32_T(ii, i20);
        }

        i20 = idx->size[0] * idx->size[1];
        idx->size[0] = 1;
        idx->size[1] = ii->size[1];
        emxEnsureCapacity_uint32_T(idx, i20);
        nx = ii->size[0] * ii->size[1];
        for (i20 = 0; i20 < nx; i20++) {
          idx->data[i20] = (unsigned int)ii->data[i20];
        }

        i20 = Qtem2->size[0] * Qtem2->size[1];
        Qtem2->size[0] = 1;
        Qtem2->size[1] = idx->size[1];
        emxEnsureCapacity_real_T(Qtem2, i20);
        nx = idx->size[1];
        for (i20 = 0; i20 < nx; i20++) {
          Qtem2->data[i20] = Qtem->data[jj + Qtem->size[0] * ((int)idx->data[i20]
            - 1)];
        }

        r = d_rand();
        ibmat = 1;
        do {
          exitg2 = 0;
          i20 = b_idx->size[0];
          b_idx->size[0] = idx->size[1];
          emxEnsureCapacity_int32_T(b_idx, i20);
          nx = idx->size[1];
          for (i20 = 0; i20 < nx; i20++) {
            b_idx->data[i20] = (int)idx->data[i20];
          }

          if (ibmat - 1 <= b_idx->size[0] - 1) {
            i20 = b_idx->size[0];
            b_idx->size[0] = idx->size[1];
            emxEnsureCapacity_int32_T(b_idx, i20);
            nx = idx->size[1];
            for (i20 = 0; i20 < nx; i20++) {
              b_idx->data[i20] = (int)idx->data[i20];
            }

            i20 = b_Qtem2->size[0] * b_Qtem2->size[1];
            b_Qtem2->size[0] = 1;
            b_Qtem2->size[1] = ibmat;
            emxEnsureCapacity_real_T(b_Qtem2, i20);
            for (i20 = 0; i20 < ibmat; i20++) {
              b_Qtem2->data[i20] = Qtem2->data[i20];
            }

            if (sum(b_Qtem2) > r) {
              Obs->data[jj + Obs->size[0] * ((int)idx->data[ibmat - 1] - 1)] = 1;
              nx = Qtem->size[0];
              c_idx = (int)idx->data[ibmat - 1];
              i20 = r6->size[0];
              r6->size[0] = nx;
              emxEnsureCapacity_real_T(r6, i20);
              for (i20 = 0; i20 < nx; i20++) {
                r6->data[i20] = 1.0 - Qtem->data[i20 + Qtem->size[0] * (c_idx -
                  1)];
              }

              b_rdivide_helper(r6, r5);
              b_repmat(r5, Qtem->size[1], r4);
              i20 = Qtem->size[0] * Qtem->size[1];
              ibtile = Qtem->size[0] * Qtem->size[1];
              emxEnsureCapacity_real_T(Qtem, ibtile);
              nx = i20 - 1;
              for (i20 = 0; i20 <= nx; i20++) {
                Qtem->data[i20] *= r4->data[i20];
              }

              nx = Qtem->size[0];
              c_idx = (int)idx->data[ibmat - 1];
              for (i20 = 0; i20 < nx; i20++) {
                Qtem->data[i20 + Qtem->size[0] * (c_idx - 1)] = 0.0;
              }

              exitg2 = 1;
            } else {
              i20 = b_Qtem2->size[0] * b_Qtem2->size[1];
              b_Qtem2->size[0] = 1;
              b_Qtem2->size[1] = ibmat;
              emxEnsureCapacity_real_T(b_Qtem2, i20);
              for (i20 = 0; i20 < ibmat; i20++) {
                b_Qtem2->data[i20] = Qtem2->data[i20];
              }

              if (sum(b_Qtem2) <= r) {
                i20 = b_idx->size[0];
                b_idx->size[0] = idx->size[1];
                emxEnsureCapacity_int32_T(b_idx, i20);
                nx = idx->size[1];
                for (i20 = 0; i20 < nx; i20++) {
                  b_idx->data[i20] = (int)idx->data[i20];
                }

                i20 = b_Qtem2->size[0] * b_Qtem2->size[1];
                b_Qtem2->size[0] = 1;
                b_Qtem2->size[1] = ibmat + 1;
                emxEnsureCapacity_real_T(b_Qtem2, i20);
                for (i20 = 0; i20 <= ibmat; i20++) {
                  b_Qtem2->data[i20] = Qtem2->data[i20];
                }

                if (sum(b_Qtem2) > r) {
                  Obs->data[jj + Obs->size[0] * ((int)idx->data[ibmat] - 1)] = 1;
                  nx = Qtem->size[0];
                  c_idx = (int)idx->data[ibmat];
                  i20 = r6->size[0];
                  r6->size[0] = nx;
                  emxEnsureCapacity_real_T(r6, i20);
                  for (i20 = 0; i20 < nx; i20++) {
                    r6->data[i20] = 1.0 - Qtem->data[i20 + Qtem->size[0] *
                      (c_idx - 1)];
                  }

                  b_rdivide_helper(r6, r5);
                  b_repmat(r5, Qtem->size[1], r4);
                  i20 = Qtem->size[0] * Qtem->size[1];
                  ibtile = Qtem->size[0] * Qtem->size[1];
                  emxEnsureCapacity_real_T(Qtem, ibtile);
                  nx = i20 - 1;
                  for (i20 = 0; i20 <= nx; i20++) {
                    Qtem->data[i20] *= r4->data[i20];
                  }

                  nx = Qtem->size[0];
                  c_idx = (int)idx->data[ibmat];
                  for (i20 = 0; i20 < nx; i20++) {
                    Qtem->data[i20 + Qtem->size[0] * (c_idx - 1)] = 0.0;
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

      i20 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = Obs->size[1];
      b_x->size[1] = Obs->size[0];
      emxEnsureCapacity_boolean_T(b_x, i20);
      nx = Obs->size[0];
      for (i20 = 0; i20 < nx; i20++) {
        jj = Obs->size[1];
        for (ibtile = 0; ibtile < jj; ibtile++) {
          b_x->data[ibtile + b_x->size[0] * i20] = (Obs->data[i20 + Obs->size[0]
            * ibtile] == 1);
        }
      }

      nx = b_x->size[0] * b_x->size[1];
      if (nx == 0) {
        b_idx->size[0] = 0;
      } else {
        c_idx = 0;
        i20 = b_idx->size[0];
        b_idx->size[0] = nx;
        emxEnsureCapacity_int32_T(b_idx, i20);
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
          i20 = b_idx->size[0];
          if (1 > c_idx) {
            b_idx->size[0] = 0;
          } else {
            b_idx->size[0] = c_idx;
          }

          emxEnsureCapacity_int32_T(b_idx, i20);
        }
      }

      nx = b_idx->size[0];
      for (i20 = 0; i20 < nx; i20++) {
        List->data[i20 + List->size[0] * u] = b_idx->data[i20];
      }
    }

    i18 = (long long)k * numObsIQ;
    if (i18 > 2147483647LL) {
      i18 = 2147483647LL;
    } else {
      if (i18 < -2147483648LL) {
        i18 = -2147483648LL;
      }
    }

    jj = (int)i18;
    if (jj > 2147483646) {
      jj = MAX_int32_T;
    } else {
      jj++;
    }

    i18 = (long long)(k + 1) * numObsIQ;
    if (i18 > 2147483647LL) {
      i18 = 2147483647LL;
    } else {
      if (i18 < -2147483648LL) {
        i18 = -2147483648LL;
      }
    }

    if (jj > (int)i18) {
      i17 = 1;
    } else {
      i17 = jj;
    }

    nx = List->size[1];
    for (i19 = 0; i19 < nx; i19++) {
      jj = List->size[0];
      for (i20 = 0; i20 < jj; i20++) {
        newIC->data[i20 + newIC->size[0] * ((i17 + i19) - 1)] = List->data[i20 +
          List->size[0] * i19];
      }
    }

    i17 = List->size[0] * List->size[1];
    List->size[0] = i16;
    List->size[1] = numObsIQ;
    emxEnsureCapacity_int32_T(List, i17);
    for (i17 = 0; i17 < loop_ub_tmp; i17++) {
      List->data[i17] = 0;
    }
  }

  emxFree_real_T(&r6);
  emxFree_real_T(&b_Qtem2);
  emxFree_int32_T(&b_idx);
  emxFree_real_T(&r5);
  emxFree_boolean_T(&b_x);
  emxFree_int32_T(&ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&r4);
  emxFree_real_T(&Qtem2);
  emxFree_uint32_T(&idx);
  emxFree_real_T(&Qtem);
  emxFree_int8_T(&Obs);
  emxFree_int32_T(&List);
}

/* End of code generation (obsIQ.c) */
