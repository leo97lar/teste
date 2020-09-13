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
#include "combineVectorElements.h"
#include "model_rtwutil.h"

/* Function Definitions */
void obsIQini(const emxArray_real_T *IQ, int numIQ, int numObsIQ, const double
              ProbXEst[5], emxArray_real_T *newIC)
{
  double Pmax;
  int i54;
  int jj;
  emxArray_int32_T *List;
  int ProbXEst_size[1];
  int i55;
  emxArray_real_T ProbXEst_data;
  double b_ProbXEst_data[5];
  int loop_ub_tmp;
  int Lim[5];
  emxArray_int8_T *Obs;
  int ibtile;
  emxArray_real_T *Qtem;
  int nx;
  emxArray_real_T *idx;
  emxArray_real_T *Qtem2;
  int ibmat;
  emxArray_real_T *b_Qtem;
  int k;
  emxArray_boolean_T *x;
  emxArray_int32_T *ii;
  emxArray_boolean_T *b_x;
  emxArray_int32_T *i;
  emxArray_real_T *c_Qtem;
  emxArray_real_T *b_Qtem2;
  emxArray_real_T *r10;
  long long i56;
  int i57;
  unsigned int unnamed_idx_0;
  int u;
  int i58;
  int loop_ub;
  int b_i;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T exitg1;
  boolean_T b_guard1 = false;

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

  for (jj = 0; jj < 5; jj++) {
    ProbXEst_size[0] = jj + 1;
    for (i55 = 0; i55 <= jj; i55++) {
      b_ProbXEst_data[i55] = ProbXEst[i55];
    }

    ProbXEst_data.data = &b_ProbXEst_data[0];
    ProbXEst_data.size = &ProbXEst_size[0];
    ProbXEst_data.allocatedSize = 5;
    ProbXEst_data.numDimensions = 1;
    ProbXEst_data.canFreeData = false;
    Pmax = rt_roundd((double)i54 * combineVectorElements(&ProbXEst_data));
    if (Pmax < 2.147483648E+9) {
      if (Pmax >= -2.147483648E+9) {
        i55 = (int)Pmax;
      } else {
        i55 = MIN_int32_T;
      }
    } else {
      i55 = MAX_int32_T;
    }

    Lim[jj] = (int)rt_roundd((double)i55 / 100.0);
  }

  emxInit_int32_T(&List, 2);
  i55 = List->size[0] * List->size[1];
  List->size[0] = i54;
  List->size[1] = numObsIQ;
  emxEnsureCapacity_int32_T(List, i55);
  loop_ub_tmp = i54 * numObsIQ;
  for (i55 = 0; i55 < loop_ub_tmp; i55++) {
    List->data[i55] = 0;
  }

  i55 = newIC->size[0] * newIC->size[1];
  newIC->size[0] = i54;
  newIC->size[1] = numObsIQ * numIQ;
  emxEnsureCapacity_real_T(newIC, i55);
  for (jj = 0; jj < numIQ; jj++) {
    ibtile = jj * loop_ub_tmp;
    for (nx = 0; nx < numObsIQ; nx++) {
      ibmat = ibtile + nx * i54;
      for (k = 0; k < i54; k++) {
        newIC->data[ibmat + k] = 0.0;
      }
    }
  }

  emxInit_int8_T(&Obs, 2);
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
  emxInit_real_T(&r10, 1);
  for (k = 0; k < numIQ; k++) {
    i56 = (long long)k * i54;
    if (i56 > 2147483647LL) {
      i56 = 2147483647LL;
    } else {
      if (i56 < -2147483648LL) {
        i56 = -2147483648LL;
      }
    }

    jj = (int)i56;
    if (jj > 2147483646) {
      jj = MAX_int32_T;
    } else {
      jj++;
    }

    i56 = (long long)(k + 1) * i54;
    if (i56 > 2147483647LL) {
      i56 = 2147483647LL;
    } else {
      if (i56 < -2147483648LL) {
        i56 = -2147483648LL;
      }
    }

    i55 = (int)i56;
    if (jj > i55) {
      i57 = -1;
      i55 = -1;
    } else {
      i57 = jj - 2;
      i55--;
    }

    if (0 <= numObsIQ - 1) {
      unnamed_idx_0 = (unsigned int)(i55 - i57);
    }

    for (u = 0; u < numObsIQ; u++) {
      i58 = IQ->size[1];
      nx = Obs->size[0] * Obs->size[1];
      Obs->size[0] = (int)unnamed_idx_0;
      Obs->size[1] = i58;
      emxEnsureCapacity_int8_T(Obs, nx);
      loop_ub = (int)unnamed_idx_0 * i58;
      for (i58 = 0; i58 < loop_ub; i58++) {
        Obs->data[i58] = 0;
      }

      loop_ub = IQ->size[1];
      i58 = Qtem->size[0] * Qtem->size[1];
      Qtem->size[0] = i55 - i57;
      Qtem->size[1] = loop_ub;
      emxEnsureCapacity_real_T(Qtem, i58);
      for (i58 = 0; i58 < loop_ub; i58++) {
        jj = i55 - i57;
        for (nx = 0; nx < jj; nx++) {
          Qtem->data[nx + Qtem->size[0] * i58] = IQ->data[((i57 + nx) + IQ->
            size[0] * i58) + 1];
        }
      }

      for (b_i = 0; b_i < i54; b_i++) {
        loop_ub = Lim[0];
        if (b_i + 1 <= Lim[0]) {
          i58 = c_Qtem->size[0] * c_Qtem->size[1];
          c_Qtem->size[0] = 1;
          c_Qtem->size[1] = Lim[0];
          emxEnsureCapacity_real_T(c_Qtem, i58);
          for (i58 = 0; i58 < loop_ub; i58++) {
            c_Qtem->data[i58] = Qtem->data[b_i + Qtem->size[0] * i58];
          }

          Pmax = sum(c_Qtem);
          loop_ub = Lim[0];
          i58 = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = Lim[0];
          emxEnsureCapacity_boolean_T(x, i58);
          for (i58 = 0; i58 < loop_ub; i58++) {
            x->data[i58] = (Qtem->data[b_i + Qtem->size[0] * i58] != 0.0);
          }

          nx = x->size[1];
          ibmat = 0;
          i58 = ii->size[0] * ii->size[1];
          ii->size[0] = 1;
          ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(ii, i58);
          ibtile = 0;
          exitg1 = false;
          while ((!exitg1) && (ibtile <= nx - 1)) {
            if (x->data[ibtile]) {
              ibmat++;
              ii->data[ibmat - 1] = ibtile + 1;
              if (ibmat >= nx) {
                exitg1 = true;
              } else {
                ibtile++;
              }
            } else {
              ibtile++;
            }
          }

          if (x->size[1] == 1) {
            if (ibmat == 0) {
              ii->size[0] = 1;
              ii->size[1] = 0;
            }
          } else if (1 > ibmat) {
            ii->size[1] = 0;
          } else {
            i58 = ii->size[0] * ii->size[1];
            ii->size[1] = ibmat;
            emxEnsureCapacity_int32_T(ii, i58);
          }

          i58 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = ii->size[1];
          emxEnsureCapacity_real_T(idx, i58);
          loop_ub = ii->size[0] * ii->size[1];
          for (i58 = 0; i58 < loop_ub; i58++) {
            idx->data[i58] = ii->data[i58];
          }

          i58 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = idx->size[1];
          emxEnsureCapacity_real_T(Qtem2, i58);
          loop_ub = idx->size[1];
          for (i58 = 0; i58 < loop_ub; i58++) {
            Qtem2->data[i58] = Qtem->data[b_i + Qtem->size[0] * ((int)idx->
              data[i58] - 1)];
          }
        } else {
          guard1 = false;
          guard2 = false;
          guard3 = false;
          if (b_i + 1 > Lim[0]) {
            loop_ub = Lim[1];
            if (b_i + 1 <= Lim[1]) {
              i58 = c_Qtem->size[0] * c_Qtem->size[1];
              c_Qtem->size[0] = 1;
              c_Qtem->size[1] = Lim[1];
              emxEnsureCapacity_real_T(c_Qtem, i58);
              for (i58 = 0; i58 < loop_ub; i58++) {
                c_Qtem->data[i58] = Qtem->data[b_i + Qtem->size[0] * i58];
              }

              Pmax = sum(c_Qtem);
              if (Lim[0] + 1 > Lim[1]) {
                i58 = 0;
                nx = 0;
              } else {
                i58 = Lim[0];
                nx = Lim[1];
              }

              ibtile = x->size[0] * x->size[1];
              x->size[0] = 1;
              loop_ub = nx - i58;
              x->size[1] = loop_ub;
              emxEnsureCapacity_boolean_T(x, ibtile);
              for (nx = 0; nx < loop_ub; nx++) {
                x->data[nx] = (Qtem->data[b_i + Qtem->size[0] * (i58 + nx)] !=
                               0.0);
              }

              nx = x->size[1];
              ibmat = 0;
              i58 = ii->size[0] * ii->size[1];
              ii->size[0] = 1;
              ii->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(ii, i58);
              ibtile = 0;
              exitg1 = false;
              while ((!exitg1) && (ibtile <= nx - 1)) {
                if (x->data[ibtile]) {
                  ibmat++;
                  ii->data[ibmat - 1] = ibtile + 1;
                  if (ibmat >= nx) {
                    exitg1 = true;
                  } else {
                    ibtile++;
                  }
                } else {
                  ibtile++;
                }
              }

              if (x->size[1] == 1) {
                if (ibmat == 0) {
                  ii->size[0] = 1;
                  ii->size[1] = 0;
                }
              } else if (1 > ibmat) {
                ii->size[1] = 0;
              } else {
                i58 = ii->size[0] * ii->size[1];
                ii->size[1] = ibmat;
                emxEnsureCapacity_int32_T(ii, i58);
              }

              i58 = idx->size[0] * idx->size[1];
              idx->size[0] = 1;
              idx->size[1] = ii->size[1];
              emxEnsureCapacity_real_T(idx, i58);
              loop_ub = ii->size[0] * ii->size[1];
              for (i58 = 0; i58 < loop_ub; i58++) {
                idx->data[i58] = ii->data[i58] + Lim[0];
              }

              i58 = Qtem2->size[0] * Qtem2->size[1];
              Qtem2->size[0] = 1;
              Qtem2->size[1] = idx->size[1];
              emxEnsureCapacity_real_T(Qtem2, i58);
              loop_ub = idx->size[1];
              for (i58 = 0; i58 < loop_ub; i58++) {
                Qtem2->data[i58] = Qtem->data[b_i + Qtem->size[0] * ((int)
                  idx->data[i58] - 1)];
              }
            } else {
              guard3 = true;
            }
          } else {
            guard3 = true;
          }

          if (guard3) {
            if (b_i + 1 > Lim[1]) {
              loop_ub = Lim[2];
              if (b_i + 1 <= Lim[2]) {
                i58 = c_Qtem->size[0] * c_Qtem->size[1];
                c_Qtem->size[0] = 1;
                c_Qtem->size[1] = Lim[2];
                emxEnsureCapacity_real_T(c_Qtem, i58);
                for (i58 = 0; i58 < loop_ub; i58++) {
                  c_Qtem->data[i58] = Qtem->data[b_i + Qtem->size[0] * i58];
                }

                Pmax = sum(c_Qtem);
                if (Lim[1] + 1 > Lim[2]) {
                  i58 = 0;
                  nx = 0;
                } else {
                  i58 = Lim[1];
                  nx = Lim[2];
                }

                ibtile = x->size[0] * x->size[1];
                x->size[0] = 1;
                loop_ub = nx - i58;
                x->size[1] = loop_ub;
                emxEnsureCapacity_boolean_T(x, ibtile);
                for (nx = 0; nx < loop_ub; nx++) {
                  x->data[nx] = (Qtem->data[b_i + Qtem->size[0] * (i58 + nx)] !=
                                 0.0);
                }

                nx = x->size[1];
                ibmat = 0;
                i58 = ii->size[0] * ii->size[1];
                ii->size[0] = 1;
                ii->size[1] = x->size[1];
                emxEnsureCapacity_int32_T(ii, i58);
                ibtile = 0;
                exitg1 = false;
                while ((!exitg1) && (ibtile <= nx - 1)) {
                  if (x->data[ibtile]) {
                    ibmat++;
                    ii->data[ibmat - 1] = ibtile + 1;
                    if (ibmat >= nx) {
                      exitg1 = true;
                    } else {
                      ibtile++;
                    }
                  } else {
                    ibtile++;
                  }
                }

                if (x->size[1] == 1) {
                  if (ibmat == 0) {
                    ii->size[0] = 1;
                    ii->size[1] = 0;
                  }
                } else if (1 > ibmat) {
                  ii->size[1] = 0;
                } else {
                  i58 = ii->size[0] * ii->size[1];
                  ii->size[1] = ibmat;
                  emxEnsureCapacity_int32_T(ii, i58);
                }

                i58 = idx->size[0] * idx->size[1];
                idx->size[0] = 1;
                idx->size[1] = ii->size[1];
                emxEnsureCapacity_real_T(idx, i58);
                loop_ub = ii->size[0] * ii->size[1];
                for (i58 = 0; i58 < loop_ub; i58++) {
                  idx->data[i58] = ii->data[i58] + Lim[1];
                }

                i58 = Qtem2->size[0] * Qtem2->size[1];
                Qtem2->size[0] = 1;
                Qtem2->size[1] = idx->size[1];
                emxEnsureCapacity_real_T(Qtem2, i58);
                loop_ub = idx->size[1];
                for (i58 = 0; i58 < loop_ub; i58++) {
                  Qtem2->data[i58] = Qtem->data[b_i + Qtem->size[0] * ((int)
                    idx->data[i58] - 1)];
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
              loop_ub = Lim[3];
              if (b_i + 1 <= Lim[3]) {
                i58 = c_Qtem->size[0] * c_Qtem->size[1];
                c_Qtem->size[0] = 1;
                c_Qtem->size[1] = Lim[3];
                emxEnsureCapacity_real_T(c_Qtem, i58);
                for (i58 = 0; i58 < loop_ub; i58++) {
                  c_Qtem->data[i58] = Qtem->data[b_i + Qtem->size[0] * i58];
                }

                Pmax = sum(c_Qtem);
                if (Lim[2] + 1 > Lim[3]) {
                  i58 = 0;
                  nx = 0;
                } else {
                  i58 = Lim[2];
                  nx = Lim[3];
                }

                ibtile = x->size[0] * x->size[1];
                x->size[0] = 1;
                loop_ub = nx - i58;
                x->size[1] = loop_ub;
                emxEnsureCapacity_boolean_T(x, ibtile);
                for (nx = 0; nx < loop_ub; nx++) {
                  x->data[nx] = (Qtem->data[b_i + Qtem->size[0] * (i58 + nx)] !=
                                 0.0);
                }

                nx = x->size[1];
                ibmat = 0;
                i58 = ii->size[0] * ii->size[1];
                ii->size[0] = 1;
                ii->size[1] = x->size[1];
                emxEnsureCapacity_int32_T(ii, i58);
                ibtile = 0;
                exitg1 = false;
                while ((!exitg1) && (ibtile <= nx - 1)) {
                  if (x->data[ibtile]) {
                    ibmat++;
                    ii->data[ibmat - 1] = ibtile + 1;
                    if (ibmat >= nx) {
                      exitg1 = true;
                    } else {
                      ibtile++;
                    }
                  } else {
                    ibtile++;
                  }
                }

                if (x->size[1] == 1) {
                  if (ibmat == 0) {
                    ii->size[0] = 1;
                    ii->size[1] = 0;
                  }
                } else if (1 > ibmat) {
                  ii->size[1] = 0;
                } else {
                  i58 = ii->size[0] * ii->size[1];
                  ii->size[1] = ibmat;
                  emxEnsureCapacity_int32_T(ii, i58);
                }

                i58 = idx->size[0] * idx->size[1];
                idx->size[0] = 1;
                idx->size[1] = ii->size[1];
                emxEnsureCapacity_real_T(idx, i58);
                loop_ub = ii->size[0] * ii->size[1];
                for (i58 = 0; i58 < loop_ub; i58++) {
                  idx->data[i58] = ii->data[i58] + Lim[2];
                }

                i58 = Qtem2->size[0] * Qtem2->size[1];
                Qtem2->size[0] = 1;
                Qtem2->size[1] = idx->size[1];
                emxEnsureCapacity_real_T(Qtem2, i58);
                loop_ub = idx->size[1];
                for (i58 = 0; i58 < loop_ub; i58++) {
                  Qtem2->data[i58] = Qtem->data[b_i + Qtem->size[0] * ((int)
                    idx->data[i58] - 1)];
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
              i58 = 0;
              nx = 0;
            } else {
              i58 = Lim[3];
              nx = Qtem->size[1];
            }

            ibtile = x->size[0] * x->size[1];
            x->size[0] = 1;
            loop_ub = nx - i58;
            x->size[1] = loop_ub;
            emxEnsureCapacity_boolean_T(x, ibtile);
            for (nx = 0; nx < loop_ub; nx++) {
              x->data[nx] = (Qtem->data[b_i + Qtem->size[0] * (i58 + nx)] != 0.0);
            }

            nx = x->size[1];
            ibmat = 0;
            i58 = ii->size[0] * ii->size[1];
            ii->size[0] = 1;
            ii->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(ii, i58);
            ibtile = 0;
            exitg1 = false;
            while ((!exitg1) && (ibtile <= nx - 1)) {
              if (x->data[ibtile]) {
                ibmat++;
                ii->data[ibmat - 1] = ibtile + 1;
                if (ibmat >= nx) {
                  exitg1 = true;
                } else {
                  ibtile++;
                }
              } else {
                ibtile++;
              }
            }

            if (x->size[1] == 1) {
              if (ibmat == 0) {
                ii->size[0] = 1;
                ii->size[1] = 0;
              }
            } else if (1 > ibmat) {
              ii->size[1] = 0;
            } else {
              i58 = ii->size[0] * ii->size[1];
              ii->size[1] = ibmat;
              emxEnsureCapacity_int32_T(ii, i58);
            }

            i58 = idx->size[0] * idx->size[1];
            idx->size[0] = 1;
            idx->size[1] = ii->size[1];
            emxEnsureCapacity_real_T(idx, i58);
            loop_ub = ii->size[0] * ii->size[1];
            for (i58 = 0; i58 < loop_ub; i58++) {
              idx->data[i58] = (double)ii->data[i58] + (double)Lim[3];
            }

            i58 = Qtem2->size[0] * Qtem2->size[1];
            Qtem2->size[0] = 1;
            Qtem2->size[1] = idx->size[1];
            emxEnsureCapacity_real_T(Qtem2, i58);
            loop_ub = idx->size[1];
            for (i58 = 0; i58 < loop_ub; i58++) {
              Qtem2->data[i58] = Qtem->data[b_i + Qtem->size[0] * ((int)
                idx->data[i58] - 1)];
            }
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

          b_guard1 = false;
          if (sum(b_Qtem2) <= Pmax) {
            i58 = b_Qtem2->size[0] * b_Qtem2->size[1];
            b_Qtem2->size[0] = 1;
            b_Qtem2->size[1] = jj + 1;
            emxEnsureCapacity_real_T(b_Qtem2, i58);
            for (i58 = 0; i58 <= jj; i58++) {
              b_Qtem2->data[i58] = Qtem2->data[i58];
            }

            if (sum(b_Qtem2) > Pmax) {
              Obs->data[b_i + Obs->size[0] * ((int)idx->data[jj] - 1)] = 1;
              loop_ub = Qtem->size[0];
              ibmat = (int)idx->data[jj];
              i58 = r10->size[0];
              r10->size[0] = loop_ub;
              emxEnsureCapacity_real_T(r10, i58);
              for (i58 = 0; i58 < loop_ub; i58++) {
                r10->data[i58] = 1.0 - Qtem->data[i58 + Qtem->size[0] * (ibmat -
                  1)];
              }

              b_rdivide_helper(r10, b_Qtem);
              loop_ub = Qtem->size[0];
              i58 = b_Qtem->size[0];
              b_Qtem->size[0] = loop_ub;
              emxEnsureCapacity_real_T(b_Qtem, i58);
              for (i58 = 0; i58 < loop_ub; i58++) {
                b_Qtem->data[i58] *= Qtem->data[i58];
              }

              i58 = Qtem->size[0] * Qtem->size[1];
              Qtem->size[0] = b_Qtem->size[0];
              Qtem->size[1] = 1;
              emxEnsureCapacity_real_T(Qtem, i58);
              loop_ub = b_Qtem->size[0];
              for (i58 = 0; i58 < loop_ub; i58++) {
                Qtem->data[i58] = b_Qtem->data[i58];
              }

              loop_ub = b_Qtem->size[0];
              for (i58 = 0; i58 < loop_ub; i58++) {
                Qtem->data[i58] = 0.0;
              }

              exitg1 = true;
            } else {
              b_guard1 = true;
            }
          } else {
            b_guard1 = true;
          }

          if (b_guard1) {
            i58 = b_Qtem2->size[0] * b_Qtem2->size[1];
            b_Qtem2->size[0] = 1;
            b_Qtem2->size[1] = jj;
            emxEnsureCapacity_real_T(b_Qtem2, i58);
            for (i58 = 0; i58 < jj; i58++) {
              b_Qtem2->data[i58] = Qtem2->data[i58];
            }

            if (sum(b_Qtem2) > Pmax) {
              Obs->data[b_i + Obs->size[0] * ((int)idx->data[jj - 1] - 1)] = 1;
              loop_ub = Qtem->size[0];
              ibmat = (int)idx->data[jj - 1];
              i58 = r10->size[0];
              r10->size[0] = loop_ub;
              emxEnsureCapacity_real_T(r10, i58);
              for (i58 = 0; i58 < loop_ub; i58++) {
                r10->data[i58] = 1.0 - Qtem->data[i58 + Qtem->size[0] * (ibmat -
                  1)];
              }

              b_rdivide_helper(r10, b_Qtem);
              loop_ub = Qtem->size[0];
              i58 = b_Qtem->size[0];
              b_Qtem->size[0] = loop_ub;
              emxEnsureCapacity_real_T(b_Qtem, i58);
              for (i58 = 0; i58 < loop_ub; i58++) {
                b_Qtem->data[i58] *= Qtem->data[i58];
              }

              i58 = Qtem->size[0] * Qtem->size[1];
              Qtem->size[0] = b_Qtem->size[0];
              Qtem->size[1] = 1;
              emxEnsureCapacity_real_T(Qtem, i58);
              loop_ub = b_Qtem->size[0];
              for (i58 = 0; i58 < loop_ub; i58++) {
                Qtem->data[i58] = b_Qtem->data[i58];
              }

              loop_ub = b_Qtem->size[0];
              for (i58 = 0; i58 < loop_ub; i58++) {
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
      loop_ub = Obs->size[0];
      for (i58 = 0; i58 < loop_ub; i58++) {
        jj = Obs->size[1];
        for (nx = 0; nx < jj; nx++) {
          b_x->data[nx + b_x->size[0] * i58] = (Obs->data[i58 + Obs->size[0] *
            nx] == 1);
        }
      }

      nx = b_x->size[0] * b_x->size[1];
      if (nx == 0) {
        i->size[0] = 0;
      } else {
        ibmat = 0;
        i58 = i->size[0];
        i->size[0] = nx;
        emxEnsureCapacity_int32_T(i, i58);
        ibtile = 1;
        jj = 1;
        exitg1 = false;
        while ((!exitg1) && (jj <= b_x->size[1])) {
          b_guard1 = false;
          if (b_x->data[(ibtile + b_x->size[0] * (jj - 1)) - 1]) {
            ibmat++;
            i->data[ibmat - 1] = ibtile;
            if (ibmat >= nx) {
              exitg1 = true;
            } else {
              b_guard1 = true;
            }
          } else {
            b_guard1 = true;
          }

          if (b_guard1) {
            ibtile++;
            if (ibtile > b_x->size[0]) {
              ibtile = 1;
              jj++;
            }
          }
        }

        if (nx == 1) {
          if (ibmat == 0) {
            i->size[0] = 0;
          }
        } else {
          i58 = i->size[0];
          if (1 > ibmat) {
            i->size[0] = 0;
          } else {
            i->size[0] = ibmat;
          }

          emxEnsureCapacity_int32_T(i, i58);
        }
      }

      loop_ub = i->size[0];
      for (i58 = 0; i58 < loop_ub; i58++) {
        List->data[i58 + List->size[0] * u] = i->data[i58];
      }
    }

    i56 = (long long)k * numObsIQ;
    if (i56 > 2147483647LL) {
      i56 = 2147483647LL;
    } else {
      if (i56 < -2147483648LL) {
        i56 = -2147483648LL;
      }
    }

    jj = (int)i56;
    if (jj > 2147483646) {
      jj = MAX_int32_T;
    } else {
      jj++;
    }

    i56 = (long long)(k + 1) * numObsIQ;
    if (i56 > 2147483647LL) {
      i56 = 2147483647LL;
    } else {
      if (i56 < -2147483648LL) {
        i56 = -2147483648LL;
      }
    }

    if (jj > (int)i56) {
      i55 = 1;
    } else {
      i55 = jj;
    }

    loop_ub = List->size[1];
    for (i57 = 0; i57 < loop_ub; i57++) {
      jj = List->size[0];
      for (i58 = 0; i58 < jj; i58++) {
        newIC->data[i58 + newIC->size[0] * ((i55 + i57) - 1)] = List->data[i58 +
          List->size[0] * i57];
      }
    }

    i55 = List->size[0] * List->size[1];
    List->size[0] = i54;
    List->size[1] = numObsIQ;
    emxEnsureCapacity_int32_T(List, i55);
    for (i55 = 0; i55 < loop_ub_tmp; i55++) {
      List->data[i55] = 0;
    }
  }

  emxFree_real_T(&r10);
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
  emxFree_int8_T(&Obs);
  emxFree_int32_T(&List);
}

/* End of code generation (obsIQini.c) */
