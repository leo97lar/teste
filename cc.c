/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: cc.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 18:10:16
 */

/* Include Files */
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

/*
 * function [ newIC ] = cc( IC,numIC,taxC,NumTOp)
 * Arguments    : const emxArray_int32_T *IC
 *                int numIC
 *                double taxC
 *                int NumTOp
 *                emxArray_int32_T *newIC
 * Return Type  : void
 */
void cc(const emxArray_int32_T *IC, int numIC, double taxC, int NumTOp,
        emxArray_int32_T *newIC)
{
  int i31;
  int i32;
  boolean_T flag;
  int j;
  emxArray_int32_T *escolhido_1;
  emxArray_int32_T *escolhido_2;
  emxArray_int32_T *mskReal;
  emxArray_int32_T *tempF1;
  emxArray_int32_T *tempF2;
  emxArray_int32_T *idx2;
  emxArray_int32_T *idx1;
  emxArray_int32_T *idxx1;
  emxArray_int32_T *idxx2;
  emxArray_real_T *x;
  emxArray_int32_T *b_x;
  emxArray_int32_T *iidx;
  emxArray_boolean_T *b_escolhido_1;
  emxArray_int32_T *c_escolhido_1;
  double escolhidos[2];
  double minval;
  int loop_ub;
  double b_cc;
  int k;
  boolean_T exitg1;
  unsigned int u16;
  int partialTrueCount;

  /* 'cc:4' newIC = zeros(NumTOp,numIC, 'int32'); */
  i31 = newIC->size[0] * newIC->size[1];
  newIC->size[0] = NumTOp;
  newIC->size[1] = numIC;
  emxEnsureCapacity_int32_T(newIC, i31);
  for (i31 = 0; i31 < numIC; i31++) {
    for (i32 = 0; i32 < NumTOp; i32++) {
      newIC->data[i32 + newIC->size[0] * i31] = 0;
    }
  }

  /* 'cc:5' flag=false; */
  flag = false;

  /* 'cc:6' j=1; */
  j = 1;

  /*        SOMENTE OS PESOS E FUNÇÕES DE ATIVAÇÃO CUJOS NEURONIOS ESTEJAM ATIVADOS SERÃO ATUALIZADOS COM CROSSOVER. */
  /* 'cc:8' while j<=numIC/2 */
  emxInit_int32_T(&escolhido_1, 1);
  emxInit_int32_T(&escolhido_2, 1);
  emxInit_int32_T(&mskReal, 1);
  emxInit_int32_T(&tempF1, 1);
  emxInit_int32_T(&tempF2, 1);
  emxInit_int32_T(&idx2, 1);
  emxInit_int32_T(&idx1, 1);
  emxInit_int32_T(&idxx1, 1);
  emxInit_int32_T(&idxx2, 1);
  emxInit_real_T(&x, 1);
  emxInit_int32_T(&b_x, 1);
  emxInit_int32_T(&iidx, 1);
  emxInit_boolean_T(&b_escolhido_1, 1);
  emxInit_int32_T(&c_escolhido_1, 2);
  while (j <= (int)rt_roundd((double)numIC / 2.0)) {
    /* 'cc:10' while true */
    do {
      /*  parâmetros para o cruzamento */
      /* 'cc:12' escolhidos=randi(numIC,2,1); */
      j_rand(escolhidos);
      escolhidos[0] = 1.0 + floor(escolhidos[0] * (double)numIC);
      escolhidos[1] = 1.0 + floor(escolhidos[1] * (double)numIC);

      /* 'cc:13' escolhido_1 = int32(IC(:,min(escolhidos))); */
      if (escolhidos[0] > escolhidos[1]) {
        minval = escolhidos[1];
      } else {
        minval = escolhidos[0];
      }

      loop_ub = IC->size[0];
      i31 = escolhido_1->size[0];
      escolhido_1->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(escolhido_1, i31);
      for (i31 = 0; i31 < loop_ub; i31++) {
        escolhido_1->data[i31] = IC->data[i31 + IC->size[0] * ((int)minval - 1)];
      }

      /*   1º indivíduo escolhido */
      /* 'cc:16' escolhidos=randi(numIC,2,1); */
      j_rand(escolhidos);
      escolhidos[0] = 1.0 + floor(escolhidos[0] * (double)numIC);
      escolhidos[1] = 1.0 + floor(escolhidos[1] * (double)numIC);

      /* 'cc:17' escolhido_2 = int32(IC(:,min(escolhidos))); */
      if (escolhidos[0] > escolhidos[1]) {
        minval = escolhidos[1];
      } else {
        minval = escolhidos[0];
      }

      loop_ub = IC->size[0];
      i31 = escolhido_2->size[0];
      escolhido_2->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(escolhido_2, i31);
      for (i31 = 0; i31 < loop_ub; i31++) {
        escolhido_2->data[i31] = IC->data[i31 + IC->size[0] * ((int)minval - 1)];
      }

      /*   2º indivíduo escolhido */
      /* 'cc:18' if sum((escolhido_1==escolhido_2),1)~=NumTOp */
      i31 = b_escolhido_1->size[0];
      b_escolhido_1->size[0] = escolhido_1->size[0];
      emxEnsureCapacity_boolean_T(b_escolhido_1, i31);
      loop_ub = escolhido_1->size[0];
      for (i31 = 0; i31 < loop_ub; i31++) {
        b_escolhido_1->data[i31] = (escolhido_1->data[i31] == escolhido_2->
          data[i31]);
      }
    } while (!(d_sum(b_escolhido_1) != NumTOp));

    /* 'cc:24' cc=rand; */
    b_cc = d_rand();

    /* 'cc:27' if cc < taxC */
    if (b_cc < taxC) {
      /*  Cruzamiento */
      /* 'cc:31' mskReal = int32(round(rand(NumTOp,1))); */
      k_rand(NumTOp, x);
      i31 = x->size[0];
      for (k = 0; k < i31; k++) {
        x->data[k] = rt_roundd(x->data[k]);
      }

      i31 = mskReal->size[0];
      mskReal->size[0] = x->size[0];
      emxEnsureCapacity_int32_T(mskReal, i31);
      loop_ub = x->size[0];
      for (i31 = 0; i31 < loop_ub; i31++) {
        mskReal->data[i31] = (int)rt_roundd(x->data[i31]);
      }

      /*  quais parâmetros reais serão alterados */
      /* 'cc:33' tempF1 = escolhido_1.*mskReal; */
      i31 = tempF1->size[0];
      tempF1->size[0] = escolhido_1->size[0];
      emxEnsureCapacity_int32_T(tempF1, i31);
      loop_ub = escolhido_1->size[0];
      for (i31 = 0; i31 < loop_ub; i31++) {
        tempF1->data[i31] = escolhido_1->data[i31] * mskReal->data[i31];
      }

      /* 'cc:34' tempF1(tempF1==0) = []; */
      i31 = b_escolhido_1->size[0];
      b_escolhido_1->size[0] = tempF1->size[0];
      emxEnsureCapacity_boolean_T(b_escolhido_1, i31);
      loop_ub = tempF1->size[0];
      for (i31 = 0; i31 < loop_ub; i31++) {
        b_escolhido_1->data[i31] = (tempF1->data[i31] == 0);
      }

      nullAssignment(tempF1, b_escolhido_1);

      /* 'cc:36' tempF2 = escolhido_2.*mskReal; */
      i31 = tempF2->size[0];
      tempF2->size[0] = escolhido_2->size[0];
      emxEnsureCapacity_int32_T(tempF2, i31);
      loop_ub = escolhido_2->size[0];
      for (i31 = 0; i31 < loop_ub; i31++) {
        tempF2->data[i31] = escolhido_2->data[i31] * mskReal->data[i31];
      }

      /* 'cc:37' tempF2(tempF2==0) = []; */
      i31 = b_escolhido_1->size[0];
      b_escolhido_1->size[0] = tempF2->size[0];
      emxEnsureCapacity_boolean_T(b_escolhido_1, i31);
      loop_ub = tempF2->size[0];
      for (i31 = 0; i31 < loop_ub; i31++) {
        b_escolhido_1->data[i31] = (tempF2->data[i31] == 0);
      }

      nullAssignment(tempF2, b_escolhido_1);

      /* 'cc:39' [~,idx2] = sort(escolhido_2,'ascend'); */
      i31 = b_x->size[0];
      b_x->size[0] = escolhido_2->size[0];
      emxEnsureCapacity_int32_T(b_x, i31);
      loop_ub = escolhido_2->size[0];
      for (i31 = 0; i31 < loop_ub; i31++) {
        b_x->data[i31] = escolhido_2->data[i31];
      }

      d_sort(b_x, iidx);
      i31 = idx2->size[0];
      idx2->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idx2, i31);
      loop_ub = iidx->size[0];
      for (i31 = 0; i31 < loop_ub; i31++) {
        idx2->data[i31] = iidx->data[i31];
      }

      /* 'cc:39' ~ */
      /* 'cc:40' [~,idx1] = sort(escolhido_1,'ascend'); */
      i31 = b_x->size[0];
      b_x->size[0] = escolhido_1->size[0];
      emxEnsureCapacity_int32_T(b_x, i31);
      loop_ub = escolhido_1->size[0];
      for (i31 = 0; i31 < loop_ub; i31++) {
        b_x->data[i31] = escolhido_1->data[i31];
      }

      d_sort(b_x, iidx);
      i31 = idx1->size[0];
      idx1->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idx1, i31);
      loop_ub = iidx->size[0];
      for (i31 = 0; i31 < loop_ub; i31++) {
        idx1->data[i31] = iidx->data[i31];
      }

      /* 'cc:40' ~ */
      /* 'cc:42' [~,idxx1] = sort(idx2(tempF1),'ascend'); */
      i31 = x->size[0];
      x->size[0] = tempF1->size[0];
      emxEnsureCapacity_real_T(x, i31);
      loop_ub = tempF1->size[0];
      for (i31 = 0; i31 < loop_ub; i31++) {
        x->data[i31] = idx2->data[tempF1->data[i31] - 1];
      }

      c_sort(x, iidx);
      i31 = idxx1->size[0];
      idxx1->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idxx1, i31);
      loop_ub = iidx->size[0];
      for (i31 = 0; i31 < loop_ub; i31++) {
        idxx1->data[i31] = iidx->data[i31];
      }

      /* 'cc:42' ~ */
      /* 'cc:43' [~,idxx2] = sort(idx1(tempF2),'ascend'); */
      i31 = x->size[0];
      x->size[0] = tempF2->size[0];
      emxEnsureCapacity_real_T(x, i31);
      loop_ub = tempF2->size[0];
      for (i31 = 0; i31 < loop_ub; i31++) {
        x->data[i31] = idx1->data[tempF2->data[i31] - 1];
      }

      c_sort(x, iidx);
      i31 = idxx2->size[0];
      idxx2->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idxx2, i31);
      loop_ub = iidx->size[0];
      for (i31 = 0; i31 < loop_ub; i31++) {
        idxx2->data[i31] = iidx->data[i31];
      }

      /* 'cc:43' ~ */
      /* 'cc:45' escolhido_1(mskReal~=0)=tempF1(idxx1); */
      k = mskReal->size[0];
      partialTrueCount = 0;
      for (loop_ub = 0; loop_ub < k; loop_ub++) {
        if (mskReal->data[loop_ub] != 0) {
          escolhido_1->data[loop_ub] = tempF1->data[idxx1->data[partialTrueCount]
            - 1];
          partialTrueCount++;
        }
      }

      /* 'cc:46' escolhido_2(mskReal~=0)=tempF2(idxx2); */
      k = mskReal->size[0];
      partialTrueCount = 0;
      for (loop_ub = 0; loop_ub < k; loop_ub++) {
        if (mskReal->data[loop_ub] != 0) {
          escolhido_2->data[loop_ub] = tempF2->data[idxx2->data[partialTrueCount]
            - 1];
          partialTrueCount++;
        }
      }
    }

    /* 'cc:49' if j==1 */
    if (j == 1) {
      /* 'cc:50' newIC(:,j-1+j:2*j)=[escolhido_1,escolhido_2]; */
      loop_ub = newIC->size[0];
      i31 = b_x->size[0];
      b_x->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(b_x, i31);
      for (i31 = 0; i31 < loop_ub; i31++) {
        b_x->data[i31] = i31;
      }

      i31 = iidx->size[0];
      iidx->size[0] = 2;
      emxEnsureCapacity_int32_T(iidx, i31);
      iidx->data[0] = 0;
      iidx->data[1] = 1;
      i31 = c_escolhido_1->size[0] * c_escolhido_1->size[1];
      c_escolhido_1->size[0] = escolhido_1->size[0];
      c_escolhido_1->size[1] = 2;
      emxEnsureCapacity_int32_T(c_escolhido_1, i31);
      loop_ub = escolhido_1->size[0];
      for (i31 = 0; i31 < loop_ub; i31++) {
        c_escolhido_1->data[i31] = escolhido_1->data[i31];
      }

      loop_ub = escolhido_2->size[0];
      for (i31 = 0; i31 < loop_ub; i31++) {
        c_escolhido_1->data[i31 + c_escolhido_1->size[0]] = escolhido_2->
          data[i31];
      }

      partialTrueCount = b_x->size[0];
      for (i31 = 0; i31 < 2; i31++) {
        for (i32 = 0; i32 < partialTrueCount; i32++) {
          newIC->data[b_x->data[i32] + newIC->size[0] * iidx->data[i31]] =
            c_escolhido_1->data[i32 + partialTrueCount * i31];
        }
      }

      /* 'cc:51' j=j+1; */
      j = 2;
    } else {
      /* 'cc:52' else */
      /* 'cc:53' for k=1:(j-1)*2 */
      i31 = (j - 1) << 1;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= i31 - 1)) {
        /* 'cc:54' if sum((escolhido_1==newIC(:,k)),1)==NumTOp || sum((escolhido_2==newIC(:,k)),1)==NumTOp */
        i32 = b_escolhido_1->size[0];
        b_escolhido_1->size[0] = escolhido_1->size[0];
        emxEnsureCapacity_boolean_T(b_escolhido_1, i32);
        loop_ub = escolhido_1->size[0];
        for (i32 = 0; i32 < loop_ub; i32++) {
          b_escolhido_1->data[i32] = (escolhido_1->data[i32] == newIC->data[i32
            + newIC->size[0] * k]);
        }

        if (d_sum(b_escolhido_1) == NumTOp) {
          /* 'cc:55' flag=true; */
          flag = true;
          exitg1 = true;
        } else {
          i32 = b_escolhido_1->size[0];
          b_escolhido_1->size[0] = escolhido_2->size[0];
          emxEnsureCapacity_boolean_T(b_escolhido_1, i32);
          loop_ub = escolhido_2->size[0];
          for (i32 = 0; i32 < loop_ub; i32++) {
            b_escolhido_1->data[i32] = (escolhido_2->data[i32] == newIC->
              data[i32 + newIC->size[0] * k]);
          }

          if (d_sum(b_escolhido_1) == NumTOp) {
            /* 'cc:55' flag=true; */
            flag = true;
            exitg1 = true;
          } else {
            k++;
          }
        }
      }

      /* 'cc:59' if flag */
      if (flag) {
        /* 'cc:60' flag=false; */
        flag = false;
      } else {
        /* 'cc:61' else */
        /* 'cc:62' newIC(:,j-1+j:2*j)=[escolhido_1,escolhido_2]; */
        i31 = (j + j) - 2;
        u16 = (unsigned int)j << 1;
        if ((unsigned int)(i31 + 1) > u16) {
          i31 = 0;
          i32 = 0;
        } else {
          i32 = (int)u16;
        }

        loop_ub = newIC->size[0];
        partialTrueCount = b_x->size[0];
        b_x->size[0] = loop_ub;
        emxEnsureCapacity_int32_T(b_x, partialTrueCount);
        for (partialTrueCount = 0; partialTrueCount < loop_ub; partialTrueCount
             ++) {
          b_x->data[partialTrueCount] = partialTrueCount;
        }

        partialTrueCount = iidx->size[0];
        loop_ub = i32 - i31;
        iidx->size[0] = loop_ub;
        emxEnsureCapacity_int32_T(iidx, partialTrueCount);
        for (i32 = 0; i32 < loop_ub; i32++) {
          iidx->data[i32] = i31 + i32;
        }

        i31 = c_escolhido_1->size[0] * c_escolhido_1->size[1];
        c_escolhido_1->size[0] = escolhido_1->size[0];
        c_escolhido_1->size[1] = 2;
        emxEnsureCapacity_int32_T(c_escolhido_1, i31);
        loop_ub = escolhido_1->size[0];
        for (i31 = 0; i31 < loop_ub; i31++) {
          c_escolhido_1->data[i31] = escolhido_1->data[i31];
        }

        loop_ub = escolhido_2->size[0];
        for (i31 = 0; i31 < loop_ub; i31++) {
          c_escolhido_1->data[i31 + c_escolhido_1->size[0]] = escolhido_2->
            data[i31];
        }

        partialTrueCount = b_x->size[0];
        loop_ub = iidx->size[0];
        for (i31 = 0; i31 < loop_ub; i31++) {
          for (i32 = 0; i32 < partialTrueCount; i32++) {
            newIC->data[b_x->data[i32] + newIC->size[0] * iidx->data[i31]] =
              c_escolhido_1->data[i32 + partialTrueCount * i31];
          }
        }

        /* 'cc:63' j=j+1; */
        j++;
      }
    }
  }

  emxFree_int32_T(&c_escolhido_1);
  emxFree_boolean_T(&b_escolhido_1);
  emxFree_int32_T(&iidx);
  emxFree_int32_T(&b_x);
  emxFree_real_T(&x);
  emxFree_int32_T(&idxx2);
  emxFree_int32_T(&idxx1);
  emxFree_int32_T(&idx1);
  emxFree_int32_T(&idx2);
  emxFree_int32_T(&tempF2);
  emxFree_int32_T(&tempF1);
  emxFree_int32_T(&mskReal);
  emxFree_int32_T(&escolhido_2);
  emxFree_int32_T(&escolhido_1);
}

/*
 * File trailer for cc.c
 *
 * [EOF]
 */
