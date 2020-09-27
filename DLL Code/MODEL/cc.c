/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: cc.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
#include "pch.h"

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
  int i37;
  int i38;
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
  emxArray_int32_T *r22;
  emxArray_int32_T *r23;
  emxArray_int32_T *r24;
  emxArray_real_T *x;
  emxArray_int32_T *b_x;
  emxArray_int32_T *iidx;
  emxArray_int32_T *r25;
  emxArray_boolean_T *b_escolhido_1;
  double escolhidos[2];
  double minval;
  int loop_ub;
  double b_cc;
  int k;
  boolean_T exitg1;
  unsigned int u16;
  int partialTrueCount;
  int b_numIC[2];

  /* 'cc:4' newIC = zeros(NumTOp,numIC, 'int32'); */
  i37 = newIC->size[0] * newIC->size[1];
  newIC->size[1] = numIC;
  newIC->size[0] = NumTOp;
  emxEnsureCapacity_int32_T(newIC, i37);
  for (i37 = 0; i37 < NumTOp; i37++) {
    for (i38 = 0; i38 < numIC; i38++) {
      newIC->data[i38 + newIC->size[1] * i37] = 0;
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
  emxInit_int32_T(&r22, 2);
  emxInit_int32_T(&r23, 2);
  emxInit_int32_T(&r24, 2);
  emxInit_real_T(&x, 1);
  emxInit_int32_T(&b_x, 1);
  emxInit_int32_T(&iidx, 1);
  emxInit_int32_T(&r25, 2);
  emxInit_boolean_T(&b_escolhido_1, 1);
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
      i37 = r23->size[0] * r23->size[1];
      r23->size[1] = 1;
      r23->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(r23, i37);
      for (i37 = 0; i37 < loop_ub; i37++) {
        r23->data[i37] = IC->data[((int)minval + IC->size[1] * i37) - 1];
      }

      loop_ub = IC->size[0];
      i37 = escolhido_1->size[0];
      escolhido_1->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(escolhido_1, i37);
      for (i37 = 0; i37 < loop_ub; i37++) {
        escolhido_1->data[i37] = r23->data[i37];
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
      i37 = r24->size[0] * r24->size[1];
      r24->size[1] = 1;
      r24->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(r24, i37);
      for (i37 = 0; i37 < loop_ub; i37++) {
        r24->data[i37] = IC->data[((int)minval + IC->size[1] * i37) - 1];
      }

      loop_ub = IC->size[0];
      i37 = escolhido_2->size[0];
      escolhido_2->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(escolhido_2, i37);
      for (i37 = 0; i37 < loop_ub; i37++) {
        escolhido_2->data[i37] = r24->data[i37];
      }

      /*   2º indivíduo escolhido */
      /* 'cc:18' if sum((escolhido_1==escolhido_2),1)~=NumTOp */
      loop_ub = IC->size[0];
      i37 = b_escolhido_1->size[0];
      b_escolhido_1->size[0] = loop_ub;
      emxEnsureCapacity_boolean_T(b_escolhido_1, i37);
      for (i37 = 0; i37 < loop_ub; i37++) {
        b_escolhido_1->data[i37] = (r23->data[i37] == r24->data[i37]);
      }
    } while (!(d_sum(b_escolhido_1) != NumTOp));

    /* 'cc:24' cc=rand; */
    b_cc = d_rand();

    /* 'cc:27' if cc < taxC */
    if (b_cc < taxC) {
      /*  Cruzamiento */
      /* 'cc:31' mskReal = int32(round(rand(NumTOp,1))); */
      k_rand(NumTOp, x);
      i37 = x->size[0];
      for (k = 0; k < i37; k++) {
        x->data[k] = rt_roundd(x->data[k]);
      }

      i37 = mskReal->size[0];
      mskReal->size[0] = x->size[0];
      emxEnsureCapacity_int32_T(mskReal, i37);
      loop_ub = x->size[0];
      for (i37 = 0; i37 < loop_ub; i37++) {
        mskReal->data[i37] = (int)rt_roundd(x->data[i37]);
      }

      /*  quais parâmetros reais serão alterados */
      /* 'cc:33' tempF1 = escolhido_1.*mskReal; */
      loop_ub = IC->size[0];
      i37 = tempF1->size[0];
      tempF1->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(tempF1, i37);
      for (i37 = 0; i37 < loop_ub; i37++) {
        tempF1->data[i37] = r23->data[i37] * mskReal->data[i37];
      }

      /* 'cc:34' tempF1(tempF1==0) = []; */
      i37 = b_escolhido_1->size[0];
      b_escolhido_1->size[0] = tempF1->size[0];
      emxEnsureCapacity_boolean_T(b_escolhido_1, i37);
      loop_ub = tempF1->size[0];
      for (i37 = 0; i37 < loop_ub; i37++) {
        b_escolhido_1->data[i37] = (tempF1->data[i37] == 0);
      }

      nullAssignment(tempF1, b_escolhido_1);

      /* 'cc:36' tempF2 = escolhido_2.*mskReal; */
      loop_ub = IC->size[0];
      i37 = tempF2->size[0];
      tempF2->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(tempF2, i37);
      for (i37 = 0; i37 < loop_ub; i37++) {
        tempF2->data[i37] = r24->data[i37] * mskReal->data[i37];
      }

      /* 'cc:37' tempF2(tempF2==0) = []; */
      i37 = b_escolhido_1->size[0];
      b_escolhido_1->size[0] = tempF2->size[0];
      emxEnsureCapacity_boolean_T(b_escolhido_1, i37);
      loop_ub = tempF2->size[0];
      for (i37 = 0; i37 < loop_ub; i37++) {
        b_escolhido_1->data[i37] = (tempF2->data[i37] == 0);
      }

      nullAssignment(tempF2, b_escolhido_1);

      /* 'cc:39' [~,idx2] = sort(escolhido_2,'ascend'); */
      loop_ub = IC->size[0];
      i37 = b_x->size[0];
      b_x->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(b_x, i37);
      for (i37 = 0; i37 < loop_ub; i37++) {
        b_x->data[i37] = r24->data[i37];
      }

      d_sort(b_x, iidx);
      i37 = idx2->size[0];
      idx2->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idx2, i37);
      loop_ub = iidx->size[0];
      for (i37 = 0; i37 < loop_ub; i37++) {
        idx2->data[i37] = iidx->data[i37];
      }

      /* 'cc:39' ~ */
      /* 'cc:40' [~,idx1] = sort(escolhido_1,'ascend'); */
      loop_ub = IC->size[0];
      i37 = b_x->size[0];
      b_x->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(b_x, i37);
      for (i37 = 0; i37 < loop_ub; i37++) {
        b_x->data[i37] = r23->data[i37];
      }

      d_sort(b_x, iidx);
      i37 = idx1->size[0];
      idx1->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idx1, i37);
      loop_ub = iidx->size[0];
      for (i37 = 0; i37 < loop_ub; i37++) {
        idx1->data[i37] = iidx->data[i37];
      }

      /* 'cc:40' ~ */
      /* 'cc:42' [~,idxx1] = sort(idx2(tempF1),'ascend'); */
      i37 = x->size[0];
      x->size[0] = tempF1->size[0];
      emxEnsureCapacity_real_T(x, i37);
      loop_ub = tempF1->size[0];
      for (i37 = 0; i37 < loop_ub; i37++) {
        x->data[i37] = idx2->data[tempF1->data[i37] - 1];
      }

      c_sort(x, iidx);
      i37 = idxx1->size[0];
      idxx1->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idxx1, i37);
      loop_ub = iidx->size[0];
      for (i37 = 0; i37 < loop_ub; i37++) {
        idxx1->data[i37] = iidx->data[i37];
      }

      /* 'cc:42' ~ */
      /* 'cc:43' [~,idxx2] = sort(idx1(tempF2),'ascend'); */
      i37 = x->size[0];
      x->size[0] = tempF2->size[0];
      emxEnsureCapacity_real_T(x, i37);
      loop_ub = tempF2->size[0];
      for (i37 = 0; i37 < loop_ub; i37++) {
        x->data[i37] = idx1->data[tempF2->data[i37] - 1];
      }

      c_sort(x, iidx);
      i37 = idxx2->size[0];
      idxx2->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idxx2, i37);
      loop_ub = iidx->size[0];
      for (i37 = 0; i37 < loop_ub; i37++) {
        idxx2->data[i37] = iidx->data[i37];
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
      i37 = b_x->size[0];
      b_x->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(b_x, i37);
      for (i37 = 0; i37 < loop_ub; i37++) {
        b_x->data[i37] = i37;
      }

      i37 = iidx->size[0];
      iidx->size[0] = 2;
      emxEnsureCapacity_int32_T(iidx, i37);
      iidx->data[0] = 0;
      iidx->data[1] = 1;
      k = escolhido_1->size[0];
      partialTrueCount = escolhido_2->size[0];
      i37 = r22->size[0] * r22->size[1];
      r22->size[1] = 2;
      r22->size[0] = k;
      emxEnsureCapacity_int32_T(r22, i37);
      for (i37 = 0; i37 < k; i37++) {
        r22->data[i37 << 1] = escolhido_1->data[i37];
      }

      for (i37 = 0; i37 < partialTrueCount; i37++) {
        r22->data[1 + (i37 << 1)] = escolhido_2->data[i37];
      }

      b_numIC[0] = b_x->size[0];
      if (b_numIC[0] == r22->size[0]) {
        k = b_numIC[0];
        i37 = r25->size[0] * r25->size[1];
        r25->size[1] = 2;
        r25->size[0] = k;
        emxEnsureCapacity_int32_T(r25, i37);
        for (i37 = 0; i37 < k; i37++) {
          for (i38 = 0; i38 < 2; i38++) {
            r25->data[i38 + r25->size[1] * i37] = r22->data[i38 + 2 * i37];
          }
        }
      } else {
        i37 = 0;
        i38 = 0;
        k = 0;
        partialTrueCount = 0;
        loop_ub = r25->size[0] * r25->size[1];
        r25->size[1] = 2;
        r25->size[0] = b_numIC[0];
        emxEnsureCapacity_int32_T(r25, loop_ub);
        for (loop_ub = 0; loop_ub < (b_numIC[0] << 1); loop_ub++) {
          r25->data[i38 + r25->size[1] * i37] = r22->data[partialTrueCount + (k <<
            1)];
          i37++;
          k++;
          if (i37 > r25->size[0] - 1) {
            i37 = 0;
            i38++;
          }

          if (k > r22->size[0] - 1) {
            k = 0;
            partialTrueCount++;
          }
        }
      }

      loop_ub = r25->size[0];
      for (i37 = 0; i37 < loop_ub; i37++) {
        partialTrueCount = r25->size[1];
        for (i38 = 0; i38 < partialTrueCount; i38++) {
          newIC->data[iidx->data[i38] + newIC->size[1] * b_x->data[i37]] =
            r25->data[i38 + r25->size[1] * i37];
        }
      }

      /* 'cc:51' j=j+1; */
      j = 2;
    } else {
      /* 'cc:52' else */
      /* 'cc:53' for k=1:(j-1)*2 */
      i37 = (j - 1) << 1;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= i37 - 1)) {
        /* 'cc:54' if sum((escolhido_1==newIC(:,k)),1)==NumTOp || sum((escolhido_2==newIC(:,k)),1)==NumTOp */
        i38 = b_escolhido_1->size[0];
        b_escolhido_1->size[0] = escolhido_1->size[0];
        emxEnsureCapacity_boolean_T(b_escolhido_1, i38);
        loop_ub = escolhido_1->size[0];
        for (i38 = 0; i38 < loop_ub; i38++) {
          b_escolhido_1->data[i38] = (escolhido_1->data[i38] == newIC->data[k +
            newIC->size[1] * i38]);
        }

        if (d_sum(b_escolhido_1) == NumTOp) {
          /* 'cc:55' flag=true; */
          flag = true;
          exitg1 = true;
        } else {
          i38 = b_escolhido_1->size[0];
          b_escolhido_1->size[0] = escolhido_2->size[0];
          emxEnsureCapacity_boolean_T(b_escolhido_1, i38);
          loop_ub = escolhido_2->size[0];
          for (i38 = 0; i38 < loop_ub; i38++) {
            b_escolhido_1->data[i38] = (escolhido_2->data[i38] == newIC->data[k
              + newIC->size[1] * i38]);
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
        i37 = (j + j) - 2;
        u16 = (unsigned int)j << 1;
        if ((unsigned int)(i37 + 1) > u16) {
          i37 = 0;
          i38 = 0;
        } else {
          i38 = (int)u16;
        }

        loop_ub = newIC->size[0];
        k = b_x->size[0];
        b_x->size[0] = loop_ub;
        emxEnsureCapacity_int32_T(b_x, k);
        for (k = 0; k < loop_ub; k++) {
          b_x->data[k] = k;
        }

        k = iidx->size[0];
        loop_ub = i38 - i37;
        iidx->size[0] = loop_ub;
        emxEnsureCapacity_int32_T(iidx, k);
        for (i38 = 0; i38 < loop_ub; i38++) {
          iidx->data[i38] = i37 + i38;
        }

        k = escolhido_1->size[0];
        partialTrueCount = escolhido_2->size[0];
        i37 = r22->size[0] * r22->size[1];
        r22->size[1] = 2;
        r22->size[0] = k;
        emxEnsureCapacity_int32_T(r22, i37);
        for (i37 = 0; i37 < k; i37++) {
          r22->data[i37 << 1] = escolhido_1->data[i37];
        }

        for (i37 = 0; i37 < partialTrueCount; i37++) {
          r22->data[1 + (i37 << 1)] = escolhido_2->data[i37];
        }

        b_numIC[0] = b_x->size[0];
        b_numIC[1] = iidx->size[0];
        if ((b_numIC[1] == 2) && (b_numIC[0] == r22->size[0])) {
          k = b_numIC[0];
          i37 = r25->size[0] * r25->size[1];
          r25->size[1] = 2;
          r25->size[0] = k;
          emxEnsureCapacity_int32_T(r25, i37);
          for (i37 = 0; i37 < k; i37++) {
            for (i38 = 0; i38 < 2; i38++) {
              r25->data[i38 + r25->size[1] * i37] = r22->data[i38 + 2 * i37];
            }
          }
        } else {
          i37 = 0;
          i38 = 0;
          k = 0;
          partialTrueCount = 0;
          loop_ub = r25->size[0] * r25->size[1];
          r25->size[1] = b_numIC[1];
          r25->size[0] = b_numIC[0];
          emxEnsureCapacity_int32_T(r25, loop_ub);
          for (loop_ub = 0; loop_ub < b_numIC[0] * b_numIC[1]; loop_ub++) {
            r25->data[i38 + r25->size[1] * i37] = r22->data[partialTrueCount +
              (k << 1)];
            i37++;
            k++;
            if (i37 > r25->size[0] - 1) {
              i37 = 0;
              i38++;
            }

            if (k > r22->size[0] - 1) {
              k = 0;
              partialTrueCount++;
            }
          }
        }

        loop_ub = r25->size[0];
        for (i37 = 0; i37 < loop_ub; i37++) {
          partialTrueCount = r25->size[1];
          for (i38 = 0; i38 < partialTrueCount; i38++) {
            newIC->data[iidx->data[i38] + newIC->size[1] * b_x->data[i37]] =
              r25->data[i38 + r25->size[1] * i37];
          }
        }

        /* 'cc:63' j=j+1; */
        j++;
      }
    }
  }

  emxFree_boolean_T(&b_escolhido_1);
  emxFree_int32_T(&r25);
  emxFree_int32_T(&iidx);
  emxFree_int32_T(&b_x);
  emxFree_real_T(&x);
  emxFree_int32_T(&r24);
  emxFree_int32_T(&r23);
  emxFree_int32_T(&r22);
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
