/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cc.c
 *
 * Code generation for function 'cc'
 *
 */

/* Include files */
#include <math.h>
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
#include "sum.h"
#include "sort1.h"
#include "nullAssignment.h"
#include "round.h"
#include "rand.h"
#include "model_rtwutil.h"

/* Function Definitions */
void b_cc(const emxArray_int32_T *IC, emxArray_int32_T *newIC)
{
  int i52;
  boolean_T flag;
  int j;
  emxArray_int32_T *x;
  emxArray_int32_T *iidx;
  emxArray_int32_T *b_iidx;
  emxArray_real_T *b_x;
  emxArray_int32_T *escolhido_1;
  double escolhidos[2];
  double minval;
  int escolhido_1_data[2000];
  double b_minval;
  int escolhido_2_data[2000];
  int IC_size[1];
  emxArray_boolean_T IC_data;
  boolean_T b_IC_data[2000];
  double c_cc;
  int tempF1_size_idx_0;
  int loop_ub;
  boolean_T exitg1;
  int tempF2_size_idx_0;
  long long i53;
  int mskReal_data[2000];
  emxArray_boolean_T c_IC_data;
  int i;
  int tempF1_data[2000];
  emxArray_boolean_T d_IC_data;
  emxArray_boolean_T e_IC_data;
  int tempF2_data[2000];
  emxArray_boolean_T f_IC_data;
  int idxx1_data[2000];
  int idxx2_data[2000];
  i52 = newIC->size[0] * newIC->size[1];
  newIC->size[0] = 2000;
  newIC->size[1] = 20;
  emxEnsureCapacity_int32_T(newIC, i52);
  for (i52 = 0; i52 < 40000; i52++) {
    newIC->data[i52] = 0;
  }

  flag = false;
  j = 1;

  /*        SOMENTE OS PESOS E FUNÇÕES DE ATIVAÇÃO CUJOS NEURONIOS ESTEJAM ATIVADOS SERÃO ATUALIZADOS COM CROSSOVER. */
  emxInit_int32_T(&x, 1);
  emxInit_int32_T(&iidx, 1);
  emxInit_int32_T(&b_iidx, 1);
  emxInit_real_T(&b_x, 1);
  emxInit_int32_T(&escolhido_1, 2);
  while (j <= 10) {
    do {
      /*  parâmetros para o cruzamento */
      d_rand(escolhidos);
      escolhidos[0] = 1.0 + floor(escolhidos[0] * 20.0);
      escolhidos[1] = 1.0 + floor(escolhidos[1] * 20.0);
      if (escolhidos[0] > escolhidos[1]) {
        minval = escolhidos[1];
      } else {
        minval = escolhidos[0];
      }

      for (i52 = 0; i52 < 2000; i52++) {
        escolhido_1_data[i52] = IC->data[i52 + 2000 * ((int)minval - 1)];
      }

      /*   1º indivíduo escolhido */
      d_rand(escolhidos);
      escolhidos[0] = 1.0 + floor(escolhidos[0] * 20.0);
      escolhidos[1] = 1.0 + floor(escolhidos[1] * 20.0);
      if (escolhidos[0] > escolhidos[1]) {
        b_minval = escolhidos[1];
      } else {
        b_minval = escolhidos[0];
      }

      for (i52 = 0; i52 < 2000; i52++) {
        escolhido_2_data[i52] = IC->data[i52 + 2000 * ((int)b_minval - 1)];
      }

      /*   2º indivíduo escolhido */
      IC_size[0] = 2000;
      for (i52 = 0; i52 < 2000; i52++) {
        b_IC_data[i52] = (IC->data[i52 + 2000 * ((int)minval - 1)] == IC->
                          data[i52 + 2000 * ((int)b_minval - 1)]);
      }

      IC_data.data = &b_IC_data[0];
      IC_data.size = &IC_size[0];
      IC_data.allocatedSize = 2000;
      IC_data.numDimensions = 1;
      IC_data.canFreeData = false;
    } while (!(k_sum(&IC_data) != 2000.0));

    c_cc = b_rand();
    if (c_cc < 0.9) {
      /*  Cruzamiento */
      e_rand(2000, b_x);
      b_round(b_x);
      loop_ub = b_x->size[0];
      for (i52 = 0; i52 < loop_ub; i52++) {
        c_cc = rt_roundd(b_x->data[i52]);
        if (c_cc < 2.147483648E+9) {
          if (c_cc >= -2.147483648E+9) {
            tempF2_size_idx_0 = (int)c_cc;
          } else {
            tempF2_size_idx_0 = MIN_int32_T;
          }
        } else {
          tempF2_size_idx_0 = MAX_int32_T;
        }

        mskReal_data[i52] = tempF2_size_idx_0;
      }

      /*  quais parâmetros reais serão alterados */
      for (i52 = 0; i52 < 2000; i52++) {
        i53 = (long long)IC->data[i52 + 2000 * ((int)minval - 1)] *
          mskReal_data[i52];
        if (i53 > 2147483647LL) {
          i53 = 2147483647LL;
        } else {
          if (i53 < -2147483648LL) {
            i53 = -2147483648LL;
          }
        }

        tempF1_data[i52] = (int)i53;
      }

      i52 = x->size[0];
      x->size[0] = 2000;
      emxEnsureCapacity_int32_T(x, i52);
      for (i52 = 0; i52 < 2000; i52++) {
        x->data[i52] = tempF1_data[i52];
      }

      IC_size[0] = 2000;
      for (i52 = 0; i52 < 2000; i52++) {
        b_IC_data[i52] = (tempF1_data[i52] == 0);
      }

      d_IC_data.data = &b_IC_data[0];
      d_IC_data.size = &IC_size[0];
      d_IC_data.allocatedSize = 2000;
      d_IC_data.numDimensions = 1;
      d_IC_data.canFreeData = false;
      nullAssignment(x, &d_IC_data);
      tempF1_size_idx_0 = x->size[0];
      loop_ub = x->size[0];
      for (i52 = 0; i52 < loop_ub; i52++) {
        tempF1_data[i52] = x->data[i52];
      }

      for (i52 = 0; i52 < 2000; i52++) {
        i53 = (long long)IC->data[i52 + 2000 * ((int)b_minval - 1)] *
          mskReal_data[i52];
        if (i53 > 2147483647LL) {
          i53 = 2147483647LL;
        } else {
          if (i53 < -2147483648LL) {
            i53 = -2147483648LL;
          }
        }

        tempF2_data[i52] = (int)i53;
      }

      i52 = x->size[0];
      x->size[0] = 2000;
      emxEnsureCapacity_int32_T(x, i52);
      for (i52 = 0; i52 < 2000; i52++) {
        x->data[i52] = tempF2_data[i52];
      }

      IC_size[0] = 2000;
      for (i52 = 0; i52 < 2000; i52++) {
        b_IC_data[i52] = (tempF2_data[i52] == 0);
      }

      f_IC_data.data = &b_IC_data[0];
      f_IC_data.size = &IC_size[0];
      f_IC_data.allocatedSize = 2000;
      f_IC_data.numDimensions = 1;
      f_IC_data.canFreeData = false;
      nullAssignment(x, &f_IC_data);
      tempF2_size_idx_0 = x->size[0];
      loop_ub = x->size[0];
      for (i52 = 0; i52 < loop_ub; i52++) {
        tempF2_data[i52] = x->data[i52];
      }

      i52 = x->size[0];
      x->size[0] = 2000;
      emxEnsureCapacity_int32_T(x, i52);
      for (i52 = 0; i52 < 2000; i52++) {
        x->data[i52] = IC->data[i52 + 2000 * ((int)b_minval - 1)];
      }

      b_sort(x, iidx);
      i52 = x->size[0];
      x->size[0] = 2000;
      emxEnsureCapacity_int32_T(x, i52);
      for (i52 = 0; i52 < 2000; i52++) {
        x->data[i52] = IC->data[i52 + 2000 * ((int)minval - 1)];
      }

      b_sort(x, b_iidx);
      i52 = b_x->size[0];
      b_x->size[0] = tempF1_size_idx_0;
      emxEnsureCapacity_real_T(b_x, i52);
      for (i52 = 0; i52 < tempF1_size_idx_0; i52++) {
        b_x->data[i52] = iidx->data[tempF1_data[i52] - 1];
      }

      sort(b_x, iidx);
      loop_ub = iidx->size[0];
      for (i52 = 0; i52 < loop_ub; i52++) {
        idxx1_data[i52] = iidx->data[i52];
      }

      i52 = b_x->size[0];
      b_x->size[0] = tempF2_size_idx_0;
      emxEnsureCapacity_real_T(b_x, i52);
      for (i52 = 0; i52 < tempF2_size_idx_0; i52++) {
        b_x->data[i52] = b_iidx->data[tempF2_data[i52] - 1];
      }

      sort(b_x, b_iidx);
      loop_ub = b_iidx->size[0];
      for (i52 = 0; i52 < loop_ub; i52++) {
        idxx2_data[i52] = b_iidx->data[i52];
      }

      tempF1_size_idx_0 = 0;
      tempF2_size_idx_0 = 0;
      for (i = 0; i < 2000; i++) {
        if (mskReal_data[i] != 0) {
          escolhido_1_data[i] = tempF1_data[idxx1_data[tempF1_size_idx_0] - 1];
          tempF1_size_idx_0++;
        }

        if (mskReal_data[i] != 0) {
          escolhido_2_data[i] = tempF2_data[idxx2_data[tempF2_size_idx_0] - 1];
          tempF2_size_idx_0++;
        }
      }
    }

    if (j == 1) {
      for (i52 = 0; i52 < 2000; i52++) {
        newIC->data[i52] = escolhido_1_data[i52];
      }

      for (i52 = 0; i52 < 2000; i52++) {
        newIC->data[i52 + 2000] = escolhido_2_data[i52];
      }

      j = 2;
    } else {
      i52 = (j - 1) << 1;
      tempF1_size_idx_0 = 0;
      exitg1 = false;
      while ((!exitg1) && (tempF1_size_idx_0 <= i52 - 1)) {
        IC_size[0] = 2000;
        for (tempF2_size_idx_0 = 0; tempF2_size_idx_0 < 2000; tempF2_size_idx_0
             ++) {
          b_IC_data[tempF2_size_idx_0] = (escolhido_1_data[tempF2_size_idx_0] ==
            newIC->data[tempF2_size_idx_0 + 2000 * tempF1_size_idx_0]);
        }

        c_IC_data.data = &b_IC_data[0];
        c_IC_data.size = &IC_size[0];
        c_IC_data.allocatedSize = 2000;
        c_IC_data.numDimensions = 1;
        c_IC_data.canFreeData = false;
        if (k_sum(&c_IC_data) == 2000.0) {
          flag = true;
          exitg1 = true;
        } else {
          IC_size[0] = 2000;
          for (tempF2_size_idx_0 = 0; tempF2_size_idx_0 < 2000;
               tempF2_size_idx_0++) {
            b_IC_data[tempF2_size_idx_0] = (escolhido_2_data[tempF2_size_idx_0] ==
              newIC->data[tempF2_size_idx_0 + 2000 * tempF1_size_idx_0]);
          }

          e_IC_data.data = &b_IC_data[0];
          e_IC_data.size = &IC_size[0];
          e_IC_data.allocatedSize = 2000;
          e_IC_data.numDimensions = 1;
          e_IC_data.canFreeData = false;
          if (k_sum(&e_IC_data) == 2000.0) {
            flag = true;
            exitg1 = true;
          } else {
            tempF1_size_idx_0++;
          }
        }
      }

      if (flag) {
        flag = false;
      } else {
        i52 = (j + j) - 3;
        tempF2_size_idx_0 = j << 1;
        if (i52 + 2 > tempF2_size_idx_0) {
          i52 = -1;
          tempF2_size_idx_0 = 0;
        }

        i = escolhido_1->size[0] * escolhido_1->size[1];
        escolhido_1->size[0] = 2000;
        escolhido_1->size[1] = 2;
        emxEnsureCapacity_int32_T(escolhido_1, i);
        for (i = 0; i < 2000; i++) {
          escolhido_1->data[i] = escolhido_1_data[i];
        }

        for (i = 0; i < 2000; i++) {
          escolhido_1->data[i + escolhido_1->size[0]] = escolhido_2_data[i];
        }

        loop_ub = (tempF2_size_idx_0 - i52) - 1;
        for (tempF2_size_idx_0 = 0; tempF2_size_idx_0 < loop_ub;
             tempF2_size_idx_0++) {
          for (i = 0; i < 2000; i++) {
            newIC->data[i + 2000 * ((i52 + tempF2_size_idx_0) + 1)] =
              escolhido_1->data[i + 2000 * tempF2_size_idx_0];
          }
        }

        j++;
      }
    }
  }

  emxFree_int32_T(&escolhido_1);
  emxFree_real_T(&b_x);
  emxFree_int32_T(&b_iidx);
  emxFree_int32_T(&iidx);
  emxFree_int32_T(&x);
}

void cc(const emxArray_int32_T *IC, int numIC, double taxC, int NumTOp,
        emxArray_int32_T *newIC)
{
  int i;
  int loop_ub;
  boolean_T flag;
  int j;
  emxArray_int32_T *escolhido_1;
  emxArray_int32_T *escolhido_2;
  emxArray_int32_T *mskReal;
  emxArray_int32_T *tempF1;
  emxArray_int32_T *tempF2;
  emxArray_real_T *idx2;
  emxArray_int32_T *x;
  emxArray_int32_T *iidx;
  emxArray_real_T *b_x;
  emxArray_boolean_T *b_IC;
  emxArray_int32_T *b_escolhido_1;
  double escolhidos[2];
  double minval;
  double b_minval;
  double c_cc;
  int end;
  boolean_T exitg1;
  int i18;
  int partialTrueCount;
  unsigned int u0;
  long long i19;
  i = newIC->size[0] * newIC->size[1];
  newIC->size[0] = NumTOp;
  newIC->size[1] = numIC;
  emxEnsureCapacity_int32_T(newIC, i);
  loop_ub = NumTOp * numIC;
  for (i = 0; i < loop_ub; i++) {
    newIC->data[i] = 0;
  }

  flag = false;
  j = 1;

  /*        SOMENTE OS PESOS E FUNÇÕES DE ATIVAÇÃO CUJOS NEURONIOS ESTEJAM ATIVADOS SERÃO ATUALIZADOS COM CROSSOVER. */
  emxInit_int32_T(&escolhido_1, 1);
  emxInit_int32_T(&escolhido_2, 1);
  emxInit_int32_T(&mskReal, 1);
  emxInit_int32_T(&tempF1, 1);
  emxInit_int32_T(&tempF2, 1);
  emxInit_real_T(&idx2, 1);
  emxInit_int32_T(&x, 1);
  emxInit_int32_T(&iidx, 1);
  emxInit_real_T(&b_x, 1);
  emxInit_boolean_T(&b_IC, 1);
  emxInit_int32_T(&b_escolhido_1, 2);
  while (j <= (int)rt_roundd((double)numIC / 2.0)) {
    do {
      /*  parâmetros para o cruzamento */
      d_rand(escolhidos);
      escolhidos[0] = 1.0 + floor(escolhidos[0] * (double)numIC);
      escolhidos[1] = 1.0 + floor(escolhidos[1] * (double)numIC);
      if (escolhidos[0] > escolhidos[1]) {
        minval = escolhidos[1];
      } else {
        minval = escolhidos[0];
      }

      loop_ub = IC->size[0];
      i = escolhido_1->size[0];
      escolhido_1->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(escolhido_1, i);
      for (i = 0; i < loop_ub; i++) {
        escolhido_1->data[i] = IC->data[i + IC->size[0] * ((int)minval - 1)];
      }

      /*   1º indivíduo escolhido */
      d_rand(escolhidos);
      escolhidos[0] = 1.0 + floor(escolhidos[0] * (double)numIC);
      escolhidos[1] = 1.0 + floor(escolhidos[1] * (double)numIC);
      if (escolhidos[0] > escolhidos[1]) {
        b_minval = escolhidos[1];
      } else {
        b_minval = escolhidos[0];
      }

      loop_ub = IC->size[0];
      i = escolhido_2->size[0];
      escolhido_2->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(escolhido_2, i);
      for (i = 0; i < loop_ub; i++) {
        escolhido_2->data[i] = IC->data[i + IC->size[0] * ((int)b_minval - 1)];
      }

      /*   2º indivíduo escolhido */
      loop_ub = IC->size[0];
      i = b_IC->size[0];
      b_IC->size[0] = loop_ub;
      emxEnsureCapacity_boolean_T(b_IC, i);
      for (i = 0; i < loop_ub; i++) {
        b_IC->data[i] = (IC->data[i + IC->size[0] * ((int)minval - 1)] ==
                         IC->data[i + IC->size[0] * ((int)b_minval - 1)]);
      }
    } while (!(k_sum(b_IC) != NumTOp));

    c_cc = b_rand();
    if (c_cc < taxC) {
      /*  Cruzamiento */
      e_rand(NumTOp, idx2);
      b_round(idx2);
      i = mskReal->size[0];
      mskReal->size[0] = idx2->size[0];
      emxEnsureCapacity_int32_T(mskReal, i);
      loop_ub = idx2->size[0];
      for (i = 0; i < loop_ub; i++) {
        c_cc = rt_roundd(idx2->data[i]);
        if (c_cc < 2.147483648E+9) {
          if (c_cc >= -2.147483648E+9) {
            i18 = (int)c_cc;
          } else {
            i18 = MIN_int32_T;
          }
        } else {
          i18 = MAX_int32_T;
        }

        mskReal->data[i] = i18;
      }

      /*  quais parâmetros reais serão alterados */
      loop_ub = IC->size[0];
      i = tempF1->size[0];
      tempF1->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(tempF1, i);
      for (i = 0; i < loop_ub; i++) {
        i19 = (long long)IC->data[i + IC->size[0] * ((int)minval - 1)] *
          mskReal->data[i];
        if (i19 > 2147483647LL) {
          i19 = 2147483647LL;
        } else {
          if (i19 < -2147483648LL) {
            i19 = -2147483648LL;
          }
        }

        tempF1->data[i] = (int)i19;
      }

      i = b_IC->size[0];
      b_IC->size[0] = tempF1->size[0];
      emxEnsureCapacity_boolean_T(b_IC, i);
      loop_ub = tempF1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_IC->data[i] = (tempF1->data[i] == 0);
      }

      nullAssignment(tempF1, b_IC);
      loop_ub = IC->size[0];
      i = tempF2->size[0];
      tempF2->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(tempF2, i);
      for (i = 0; i < loop_ub; i++) {
        i19 = (long long)IC->data[i + IC->size[0] * ((int)b_minval - 1)] *
          mskReal->data[i];
        if (i19 > 2147483647LL) {
          i19 = 2147483647LL;
        } else {
          if (i19 < -2147483648LL) {
            i19 = -2147483648LL;
          }
        }

        tempF2->data[i] = (int)i19;
      }

      i = b_IC->size[0];
      b_IC->size[0] = tempF2->size[0];
      emxEnsureCapacity_boolean_T(b_IC, i);
      loop_ub = tempF2->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_IC->data[i] = (tempF2->data[i] == 0);
      }

      nullAssignment(tempF2, b_IC);
      loop_ub = IC->size[0];
      i = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(x, i);
      for (i = 0; i < loop_ub; i++) {
        x->data[i] = IC->data[i + IC->size[0] * ((int)b_minval - 1)];
      }

      b_sort(x, iidx);
      i = idx2->size[0];
      idx2->size[0] = iidx->size[0];
      emxEnsureCapacity_real_T(idx2, i);
      loop_ub = iidx->size[0];
      for (i = 0; i < loop_ub; i++) {
        idx2->data[i] = iidx->data[i];
      }

      loop_ub = IC->size[0];
      i = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(x, i);
      for (i = 0; i < loop_ub; i++) {
        x->data[i] = IC->data[i + IC->size[0] * ((int)minval - 1)];
      }

      b_sort(x, iidx);
      i = x->size[0];
      x->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(x, i);
      loop_ub = iidx->size[0];
      for (i = 0; i < loop_ub; i++) {
        x->data[i] = iidx->data[i];
      }

      i = b_x->size[0];
      b_x->size[0] = tempF1->size[0];
      emxEnsureCapacity_real_T(b_x, i);
      loop_ub = tempF1->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_x->data[i] = idx2->data[tempF1->data[i] - 1];
      }

      sort(b_x, iidx);
      i = b_x->size[0];
      b_x->size[0] = tempF2->size[0];
      emxEnsureCapacity_real_T(b_x, i);
      loop_ub = tempF2->size[0];
      for (i = 0; i < loop_ub; i++) {
        b_x->data[i] = x->data[tempF2->data[i] - 1];
      }

      sort(b_x, x);
      i = idx2->size[0];
      idx2->size[0] = x->size[0];
      emxEnsureCapacity_real_T(idx2, i);
      loop_ub = x->size[0];
      for (i = 0; i < loop_ub; i++) {
        idx2->data[i] = x->data[i];
      }

      end = mskReal->size[0];
      partialTrueCount = 0;
      for (i = 0; i < end; i++) {
        if (mskReal->data[i] != 0) {
          escolhido_1->data[i] = tempF1->data[iidx->data[partialTrueCount] - 1];
          partialTrueCount++;
        }
      }

      end = mskReal->size[0];
      partialTrueCount = 0;
      for (i = 0; i < end; i++) {
        if (mskReal->data[i] != 0) {
          escolhido_2->data[i] = tempF2->data[(int)idx2->data[partialTrueCount]
            - 1];
          partialTrueCount++;
        }
      }
    }

    if (j == 1) {
      loop_ub = newIC->size[0];
      i = b_escolhido_1->size[0] * b_escolhido_1->size[1];
      b_escolhido_1->size[0] = escolhido_1->size[0];
      b_escolhido_1->size[1] = 2;
      emxEnsureCapacity_int32_T(b_escolhido_1, i);
      partialTrueCount = escolhido_1->size[0];
      for (i = 0; i < partialTrueCount; i++) {
        b_escolhido_1->data[i] = escolhido_1->data[i];
      }

      partialTrueCount = escolhido_2->size[0];
      for (i = 0; i < partialTrueCount; i++) {
        b_escolhido_1->data[i + b_escolhido_1->size[0]] = escolhido_2->data[i];
      }

      for (i = 0; i < loop_ub; i++) {
        newIC->data[i] = b_escolhido_1->data[i];
      }

      for (i = 0; i < loop_ub; i++) {
        newIC->data[i + newIC->size[0]] = b_escolhido_1->data[i +
          b_escolhido_1->size[0]];
      }

      j = 2;
    } else {
      i = (j - 1) << 1;
      end = 0;
      exitg1 = false;
      while ((!exitg1) && (end <= i - 1)) {
        i18 = b_IC->size[0];
        b_IC->size[0] = escolhido_1->size[0];
        emxEnsureCapacity_boolean_T(b_IC, i18);
        loop_ub = escolhido_1->size[0];
        for (i18 = 0; i18 < loop_ub; i18++) {
          b_IC->data[i18] = (escolhido_1->data[i18] == newIC->data[i18 +
                             newIC->size[0] * end]);
        }

        if (k_sum(b_IC) == NumTOp) {
          flag = true;
          exitg1 = true;
        } else {
          i18 = b_IC->size[0];
          b_IC->size[0] = escolhido_2->size[0];
          emxEnsureCapacity_boolean_T(b_IC, i18);
          loop_ub = escolhido_2->size[0];
          for (i18 = 0; i18 < loop_ub; i18++) {
            b_IC->data[i18] = (escolhido_2->data[i18] == newIC->data[i18 +
                               newIC->size[0] * end]);
          }

          if (k_sum(b_IC) == NumTOp) {
            flag = true;
            exitg1 = true;
          } else {
            end++;
          }
        }
      }

      if (flag) {
        flag = false;
      } else {
        i = (j + j) - 3;
        u0 = (unsigned int)j << 1;
        if ((unsigned int)(i + 2) > u0) {
          i = -1;
          i18 = 0;
        } else {
          i18 = (int)u0;
        }

        loop_ub = newIC->size[0];
        end = b_escolhido_1->size[0] * b_escolhido_1->size[1];
        b_escolhido_1->size[0] = escolhido_1->size[0];
        b_escolhido_1->size[1] = 2;
        emxEnsureCapacity_int32_T(b_escolhido_1, end);
        partialTrueCount = escolhido_1->size[0];
        for (end = 0; end < partialTrueCount; end++) {
          b_escolhido_1->data[end] = escolhido_1->data[end];
        }

        partialTrueCount = escolhido_2->size[0];
        for (end = 0; end < partialTrueCount; end++) {
          b_escolhido_1->data[end + b_escolhido_1->size[0]] = escolhido_2->
            data[end];
        }

        partialTrueCount = (i18 - i) - 1;
        for (i18 = 0; i18 < partialTrueCount; i18++) {
          for (end = 0; end < loop_ub; end++) {
            newIC->data[end + newIC->size[0] * ((i + i18) + 1)] =
              b_escolhido_1->data[end + loop_ub * i18];
          }
        }

        j++;
      }
    }
  }

  emxFree_int32_T(&b_escolhido_1);
  emxFree_boolean_T(&b_IC);
  emxFree_real_T(&b_x);
  emxFree_int32_T(&iidx);
  emxFree_int32_T(&x);
  emxFree_real_T(&idx2);
  emxFree_int32_T(&tempF2);
  emxFree_int32_T(&tempF1);
  emxFree_int32_T(&mskReal);
  emxFree_int32_T(&escolhido_2);
  emxFree_int32_T(&escolhido_1);
}

/* End of code generation (cc.c) */
