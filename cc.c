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
#include "main_UCI_func.h"
#include "cc.h"
#include "model_emxutil.h"
#include "sum.h"
#include "sort1.h"
#include "nullAssignment.h"
#include "obsIQini.h"
#include "rand.h"
#include "model_rtwutil.h"

/* Function Definitions */
void cc(const emxArray_int32_T *IC, int numIC, double taxC, int NumTOp,
        emxArray_int32_T *newIC)
{
  int i32;
  int loop_ub;
  boolean_T flag;
  int j;
  emxArray_int32_T *escolhido_1;
  emxArray_int32_T *escolhido_2;
  emxArray_int32_T *mskReal;
  emxArray_int32_T *tempF1;
  emxArray_int32_T *tempF2;
  emxArray_int32_T *idx2;
  emxArray_real_T *x;
  emxArray_int32_T *b_x;
  emxArray_int32_T *iidx;
  emxArray_boolean_T *b_IC;
  emxArray_int32_T *b_escolhido_1;
  double escolhidos[2];
  double minval;
  double b_minval;
  double b_cc;
  int nx;
  int k;
  boolean_T exitg1;
  int i33;
  int i;
  unsigned int u0;
  long long i34;
  i32 = newIC->size[0] * newIC->size[1];
  newIC->size[0] = NumTOp;
  newIC->size[1] = numIC;
  emxEnsureCapacity_int32_T(newIC, i32);
  loop_ub = NumTOp * numIC;
  for (i32 = 0; i32 < loop_ub; i32++) {
    newIC->data[i32] = 0;
  }

  flag = false;
  j = 1;

  /*        SOMENTE OS PESOS E FUNÇÕES DE ATIVAÇÃO CUJOS NEURONIOS ESTEJAM ATIVADOS SERÃO ATUALIZADOS COM CROSSOVER. */
  emxInit_int32_T(&escolhido_1, 1);
  emxInit_int32_T(&escolhido_2, 1);
  emxInit_int32_T(&mskReal, 1);
  emxInit_int32_T(&tempF1, 1);
  emxInit_int32_T(&tempF2, 1);
  emxInit_int32_T(&idx2, 1);
  emxInit_real_T(&x, 1);
  emxInit_int32_T(&b_x, 1);
  emxInit_int32_T(&iidx, 1);
  emxInit_boolean_T(&b_IC, 1);
  emxInit_int32_T(&b_escolhido_1, 2);
  while (j <= (int)rt_roundd((double)numIC / 2.0)) {
    do {
      /*  parâmetros para o cruzamento */
      j_rand(escolhidos);
      escolhidos[0] = 1.0 + floor(escolhidos[0] * (double)numIC);
      escolhidos[1] = 1.0 + floor(escolhidos[1] * (double)numIC);
      if (escolhidos[0] > escolhidos[1]) {
        minval = escolhidos[1];
      } else {
        minval = escolhidos[0];
      }

      loop_ub = IC->size[0];
      i32 = escolhido_1->size[0];
      escolhido_1->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(escolhido_1, i32);
      for (i32 = 0; i32 < loop_ub; i32++) {
        escolhido_1->data[i32] = IC->data[i32 + IC->size[0] * ((int)minval - 1)];
      }

      /*   1º indivíduo escolhido */
      j_rand(escolhidos);
      escolhidos[0] = 1.0 + floor(escolhidos[0] * (double)numIC);
      escolhidos[1] = 1.0 + floor(escolhidos[1] * (double)numIC);
      if (escolhidos[0] > escolhidos[1]) {
        b_minval = escolhidos[1];
      } else {
        b_minval = escolhidos[0];
      }

      loop_ub = IC->size[0];
      i32 = escolhido_2->size[0];
      escolhido_2->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(escolhido_2, i32);
      for (i32 = 0; i32 < loop_ub; i32++) {
        escolhido_2->data[i32] = IC->data[i32 + IC->size[0] * ((int)b_minval - 1)];
      }

      /*   2º indivíduo escolhido */
      loop_ub = IC->size[0];
      i32 = b_IC->size[0];
      b_IC->size[0] = loop_ub;
      emxEnsureCapacity_boolean_T(b_IC, i32);
      for (i32 = 0; i32 < loop_ub; i32++) {
        b_IC->data[i32] = (IC->data[i32 + IC->size[0] * ((int)minval - 1)] ==
                           IC->data[i32 + IC->size[0] * ((int)b_minval - 1)]);
      }
    } while (!(n_sum(b_IC) != NumTOp));

    b_cc = d_rand();
    if (b_cc < taxC) {
      /*  Cruzamiento */
      k_rand(NumTOp, x);
      nx = x->size[0];
      for (k = 0; k < nx; k++) {
        x->data[k] = rt_roundd(x->data[k]);
      }

      i32 = mskReal->size[0];
      mskReal->size[0] = x->size[0];
      emxEnsureCapacity_int32_T(mskReal, i32);
      loop_ub = x->size[0];
      for (i32 = 0; i32 < loop_ub; i32++) {
        b_cc = rt_roundd(x->data[i32]);
        if (b_cc < 2.147483648E+9) {
          if (b_cc >= -2.147483648E+9) {
            i33 = (int)b_cc;
          } else {
            i33 = MIN_int32_T;
          }
        } else {
          i33 = MAX_int32_T;
        }

        mskReal->data[i32] = i33;
      }

      /*  quais parâmetros reais serão alterados */
      loop_ub = IC->size[0];
      i32 = tempF1->size[0];
      tempF1->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(tempF1, i32);
      for (i32 = 0; i32 < loop_ub; i32++) {
        i34 = (long long)IC->data[i32 + IC->size[0] * ((int)minval - 1)] *
          mskReal->data[i32];
        if (i34 > 2147483647LL) {
          i34 = 2147483647LL;
        } else {
          if (i34 < -2147483648LL) {
            i34 = -2147483648LL;
          }
        }

        tempF1->data[i32] = (int)i34;
      }

      i32 = b_IC->size[0];
      b_IC->size[0] = tempF1->size[0];
      emxEnsureCapacity_boolean_T(b_IC, i32);
      loop_ub = tempF1->size[0];
      for (i32 = 0; i32 < loop_ub; i32++) {
        b_IC->data[i32] = (tempF1->data[i32] == 0);
      }

      nullAssignment(tempF1, b_IC);
      loop_ub = IC->size[0];
      i32 = tempF2->size[0];
      tempF2->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(tempF2, i32);
      for (i32 = 0; i32 < loop_ub; i32++) {
        i34 = (long long)IC->data[i32 + IC->size[0] * ((int)b_minval - 1)] *
          mskReal->data[i32];
        if (i34 > 2147483647LL) {
          i34 = 2147483647LL;
        } else {
          if (i34 < -2147483648LL) {
            i34 = -2147483648LL;
          }
        }

        tempF2->data[i32] = (int)i34;
      }

      i32 = b_IC->size[0];
      b_IC->size[0] = tempF2->size[0];
      emxEnsureCapacity_boolean_T(b_IC, i32);
      loop_ub = tempF2->size[0];
      for (i32 = 0; i32 < loop_ub; i32++) {
        b_IC->data[i32] = (tempF2->data[i32] == 0);
      }

      nullAssignment(tempF2, b_IC);
      loop_ub = IC->size[0];
      i32 = b_x->size[0];
      b_x->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(b_x, i32);
      for (i32 = 0; i32 < loop_ub; i32++) {
        b_x->data[i32] = IC->data[i32 + IC->size[0] * ((int)b_minval - 1)];
      }

      d_sort(b_x, iidx);
      i32 = idx2->size[0];
      idx2->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idx2, i32);
      loop_ub = iidx->size[0];
      for (i32 = 0; i32 < loop_ub; i32++) {
        idx2->data[i32] = iidx->data[i32];
      }

      loop_ub = IC->size[0];
      i32 = b_x->size[0];
      b_x->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(b_x, i32);
      for (i32 = 0; i32 < loop_ub; i32++) {
        b_x->data[i32] = IC->data[i32 + IC->size[0] * ((int)minval - 1)];
      }

      d_sort(b_x, iidx);
      i32 = b_x->size[0];
      b_x->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(b_x, i32);
      loop_ub = iidx->size[0];
      for (i32 = 0; i32 < loop_ub; i32++) {
        b_x->data[i32] = iidx->data[i32];
      }

      i32 = x->size[0];
      x->size[0] = tempF1->size[0];
      emxEnsureCapacity_real_T(x, i32);
      loop_ub = tempF1->size[0];
      for (i32 = 0; i32 < loop_ub; i32++) {
        x->data[i32] = idx2->data[tempF1->data[i32] - 1];
      }

      c_sort(x, iidx);
      i32 = x->size[0];
      x->size[0] = tempF2->size[0];
      emxEnsureCapacity_real_T(x, i32);
      loop_ub = tempF2->size[0];
      for (i32 = 0; i32 < loop_ub; i32++) {
        x->data[i32] = b_x->data[tempF2->data[i32] - 1];
      }

      c_sort(x, b_x);
      i32 = idx2->size[0];
      idx2->size[0] = b_x->size[0];
      emxEnsureCapacity_int32_T(idx2, i32);
      loop_ub = b_x->size[0];
      for (i32 = 0; i32 < loop_ub; i32++) {
        idx2->data[i32] = b_x->data[i32];
      }

      nx = mskReal->size[0];
      k = 0;
      for (i = 0; i < nx; i++) {
        if (mskReal->data[i] != 0) {
          escolhido_1->data[i] = tempF1->data[iidx->data[k] - 1];
          k++;
        }
      }

      nx = mskReal->size[0];
      k = 0;
      for (i = 0; i < nx; i++) {
        if (mskReal->data[i] != 0) {
          escolhido_2->data[i] = tempF2->data[idx2->data[k] - 1];
          k++;
        }
      }
    }

    if (j == 1) {
      loop_ub = newIC->size[0];
      i32 = b_escolhido_1->size[0] * b_escolhido_1->size[1];
      b_escolhido_1->size[0] = escolhido_1->size[0];
      b_escolhido_1->size[1] = 2;
      emxEnsureCapacity_int32_T(b_escolhido_1, i32);
      i = escolhido_1->size[0];
      for (i32 = 0; i32 < i; i32++) {
        b_escolhido_1->data[i32] = escolhido_1->data[i32];
      }

      i = escolhido_2->size[0];
      for (i32 = 0; i32 < i; i32++) {
        b_escolhido_1->data[i32 + b_escolhido_1->size[0]] = escolhido_2->
          data[i32];
      }

      for (i32 = 0; i32 < loop_ub; i32++) {
        newIC->data[i32] = b_escolhido_1->data[i32];
      }

      for (i32 = 0; i32 < loop_ub; i32++) {
        newIC->data[i32 + newIC->size[0]] = b_escolhido_1->data[i32 +
          b_escolhido_1->size[0]];
      }

      j = 2;
    } else {
      i32 = (j - 1) << 1;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= i32 - 1)) {
        i33 = b_IC->size[0];
        b_IC->size[0] = escolhido_1->size[0];
        emxEnsureCapacity_boolean_T(b_IC, i33);
        loop_ub = escolhido_1->size[0];
        for (i33 = 0; i33 < loop_ub; i33++) {
          b_IC->data[i33] = (escolhido_1->data[i33] == newIC->data[i33 +
                             newIC->size[0] * k]);
        }

        if (n_sum(b_IC) == NumTOp) {
          flag = true;
          exitg1 = true;
        } else {
          i33 = b_IC->size[0];
          b_IC->size[0] = escolhido_2->size[0];
          emxEnsureCapacity_boolean_T(b_IC, i33);
          loop_ub = escolhido_2->size[0];
          for (i33 = 0; i33 < loop_ub; i33++) {
            b_IC->data[i33] = (escolhido_2->data[i33] == newIC->data[i33 +
                               newIC->size[0] * k]);
          }

          if (n_sum(b_IC) == NumTOp) {
            flag = true;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      if (flag) {
        flag = false;
      } else {
        i32 = (j + j) - 3;
        u0 = (unsigned int)j << 1;
        if ((unsigned int)(i32 + 2) > u0) {
          i32 = -1;
          i33 = 0;
        } else {
          i33 = (int)u0;
        }

        loop_ub = newIC->size[0];
        nx = b_escolhido_1->size[0] * b_escolhido_1->size[1];
        b_escolhido_1->size[0] = escolhido_1->size[0];
        b_escolhido_1->size[1] = 2;
        emxEnsureCapacity_int32_T(b_escolhido_1, nx);
        i = escolhido_1->size[0];
        for (nx = 0; nx < i; nx++) {
          b_escolhido_1->data[nx] = escolhido_1->data[nx];
        }

        i = escolhido_2->size[0];
        for (nx = 0; nx < i; nx++) {
          b_escolhido_1->data[nx + b_escolhido_1->size[0]] = escolhido_2->
            data[nx];
        }

        i = (i33 - i32) - 1;
        for (i33 = 0; i33 < i; i33++) {
          for (nx = 0; nx < loop_ub; nx++) {
            newIC->data[nx + newIC->size[0] * ((i32 + i33) + 1)] =
              b_escolhido_1->data[nx + loop_ub * i33];
          }
        }

        j++;
      }
    }
  }

  emxFree_int32_T(&b_escolhido_1);
  emxFree_boolean_T(&b_IC);
  emxFree_int32_T(&iidx);
  emxFree_int32_T(&b_x);
  emxFree_real_T(&x);
  emxFree_int32_T(&idx2);
  emxFree_int32_T(&tempF2);
  emxFree_int32_T(&tempF1);
  emxFree_int32_T(&mskReal);
  emxFree_int32_T(&escolhido_2);
  emxFree_int32_T(&escolhido_1);
}

/* End of code generation (cc.c) */
