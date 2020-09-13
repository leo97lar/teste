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

/*
 * function [ newIC ] = cc( IC,numIC,taxC,NumTOp)
 */
void cc(const emxArray_int32_T *IC, int numIC, double taxC, int NumTOp,
        emxArray_int32_T *newIC)
{
  int i33;
  int i34;
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
  i33 = newIC->size[0] * newIC->size[1];
  newIC->size[0] = NumTOp;
  newIC->size[1] = numIC;
  emxEnsureCapacity_int32_T(newIC, i33);
  for (i33 = 0; i33 < numIC; i33++) {
    for (i34 = 0; i34 < NumTOp; i34++) {
      newIC->data[i34 + newIC->size[0] * i33] = 0;
    }
  }

  /* 'cc:5' flag=false; */
  flag = false;

  /* 'cc:6' j=1; */
  j = 1;

  /*        SOMENTE OS PESOS E FUN��ES DE ATIVA��O CUJOS NEURONIOS ESTEJAM ATIVADOS SER�O ATUALIZADOS COM CROSSOVER. */
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
      /*  par�metros para o cruzamento */
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
      i33 = escolhido_1->size[0];
      escolhido_1->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(escolhido_1, i33);
      for (i33 = 0; i33 < loop_ub; i33++) {
        escolhido_1->data[i33] = IC->data[i33 + IC->size[0] * ((int)minval - 1)];
      }

      /*   1� indiv�duo escolhido */
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
      i33 = escolhido_2->size[0];
      escolhido_2->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(escolhido_2, i33);
      for (i33 = 0; i33 < loop_ub; i33++) {
        escolhido_2->data[i33] = IC->data[i33 + IC->size[0] * ((int)minval - 1)];
      }

      /*   2� indiv�duo escolhido */
      /* 'cc:18' if sum(escolhido_1==escolhido_2)~=NumTOp */
      i33 = b_escolhido_1->size[0];
      b_escolhido_1->size[0] = escolhido_1->size[0];
      emxEnsureCapacity_boolean_T(b_escolhido_1, i33);
      loop_ub = escolhido_1->size[0];
      for (i33 = 0; i33 < loop_ub; i33++) {
        b_escolhido_1->data[i33] = (escolhido_1->data[i33] == escolhido_2->
          data[i33]);
      }
    } while (!(g_sum(b_escolhido_1) != NumTOp));

    /* 'cc:24' cc=rand; */
    b_cc = d_rand();

    /* 'cc:27' if cc < taxC */
    if (b_cc < taxC) {
      /*  Cruzamiento */
      /* 'cc:31' mskReal = int32(round(rand(NumTOp,1))); */
      k_rand(NumTOp, x);
      i33 = x->size[0];
      for (k = 0; k < i33; k++) {
        x->data[k] = rt_roundd(x->data[k]);
      }

      i33 = mskReal->size[0];
      mskReal->size[0] = x->size[0];
      emxEnsureCapacity_int32_T(mskReal, i33);
      loop_ub = x->size[0];
      for (i33 = 0; i33 < loop_ub; i33++) {
        mskReal->data[i33] = (int)rt_roundd(x->data[i33]);
      }

      /*  quais par�metros reais ser�o alterados */
      /* 'cc:33' tempF1 = escolhido_1.*mskReal; */
      i33 = tempF1->size[0];
      tempF1->size[0] = escolhido_1->size[0];
      emxEnsureCapacity_int32_T(tempF1, i33);
      loop_ub = escolhido_1->size[0];
      for (i33 = 0; i33 < loop_ub; i33++) {
        tempF1->data[i33] = escolhido_1->data[i33] * mskReal->data[i33];
      }

      /* 'cc:34' tempF1(tempF1==0) = []; */
      i33 = b_escolhido_1->size[0];
      b_escolhido_1->size[0] = tempF1->size[0];
      emxEnsureCapacity_boolean_T(b_escolhido_1, i33);
      loop_ub = tempF1->size[0];
      for (i33 = 0; i33 < loop_ub; i33++) {
        b_escolhido_1->data[i33] = (tempF1->data[i33] == 0);
      }

      nullAssignment(tempF1, b_escolhido_1);

      /* 'cc:36' tempF2 = escolhido_2.*mskReal; */
      i33 = tempF2->size[0];
      tempF2->size[0] = escolhido_2->size[0];
      emxEnsureCapacity_int32_T(tempF2, i33);
      loop_ub = escolhido_2->size[0];
      for (i33 = 0; i33 < loop_ub; i33++) {
        tempF2->data[i33] = escolhido_2->data[i33] * mskReal->data[i33];
      }

      /* 'cc:37' tempF2(tempF2==0) = []; */
      i33 = b_escolhido_1->size[0];
      b_escolhido_1->size[0] = tempF2->size[0];
      emxEnsureCapacity_boolean_T(b_escolhido_1, i33);
      loop_ub = tempF2->size[0];
      for (i33 = 0; i33 < loop_ub; i33++) {
        b_escolhido_1->data[i33] = (tempF2->data[i33] == 0);
      }

      nullAssignment(tempF2, b_escolhido_1);

      /* 'cc:39' [~,idx2] = sort(escolhido_2,'ascend'); */
      i33 = b_x->size[0];
      b_x->size[0] = escolhido_2->size[0];
      emxEnsureCapacity_int32_T(b_x, i33);
      loop_ub = escolhido_2->size[0];
      for (i33 = 0; i33 < loop_ub; i33++) {
        b_x->data[i33] = escolhido_2->data[i33];
      }

      d_sort(b_x, iidx);
      i33 = idx2->size[0];
      idx2->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idx2, i33);
      loop_ub = iidx->size[0];
      for (i33 = 0; i33 < loop_ub; i33++) {
        idx2->data[i33] = iidx->data[i33];
      }

      /* 'cc:39' ~ */
      /* 'cc:40' [~,idx1] = sort(escolhido_1,'ascend'); */
      i33 = b_x->size[0];
      b_x->size[0] = escolhido_1->size[0];
      emxEnsureCapacity_int32_T(b_x, i33);
      loop_ub = escolhido_1->size[0];
      for (i33 = 0; i33 < loop_ub; i33++) {
        b_x->data[i33] = escolhido_1->data[i33];
      }

      d_sort(b_x, iidx);
      i33 = idx1->size[0];
      idx1->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idx1, i33);
      loop_ub = iidx->size[0];
      for (i33 = 0; i33 < loop_ub; i33++) {
        idx1->data[i33] = iidx->data[i33];
      }

      /* 'cc:40' ~ */
      /* 'cc:42' [~,idxx1] = sort(idx2(tempF1),'ascend'); */
      i33 = x->size[0];
      x->size[0] = tempF1->size[0];
      emxEnsureCapacity_real_T(x, i33);
      loop_ub = tempF1->size[0];
      for (i33 = 0; i33 < loop_ub; i33++) {
        x->data[i33] = idx2->data[tempF1->data[i33] - 1];
      }

      c_sort(x, iidx);
      i33 = idxx1->size[0];
      idxx1->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idxx1, i33);
      loop_ub = iidx->size[0];
      for (i33 = 0; i33 < loop_ub; i33++) {
        idxx1->data[i33] = iidx->data[i33];
      }

      /* 'cc:42' ~ */
      /* 'cc:43' [~,idxx2] = sort(idx1(tempF2),'ascend'); */
      i33 = x->size[0];
      x->size[0] = tempF2->size[0];
      emxEnsureCapacity_real_T(x, i33);
      loop_ub = tempF2->size[0];
      for (i33 = 0; i33 < loop_ub; i33++) {
        x->data[i33] = idx1->data[tempF2->data[i33] - 1];
      }

      c_sort(x, iidx);
      i33 = idxx2->size[0];
      idxx2->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idxx2, i33);
      loop_ub = iidx->size[0];
      for (i33 = 0; i33 < loop_ub; i33++) {
        idxx2->data[i33] = iidx->data[i33];
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
      i33 = b_x->size[0];
      b_x->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(b_x, i33);
      for (i33 = 0; i33 < loop_ub; i33++) {
        b_x->data[i33] = i33;
      }

      i33 = iidx->size[0];
      iidx->size[0] = 2;
      emxEnsureCapacity_int32_T(iidx, i33);
      iidx->data[0] = 0;
      iidx->data[1] = 1;
      i33 = c_escolhido_1->size[0] * c_escolhido_1->size[1];
      c_escolhido_1->size[0] = escolhido_1->size[0];
      c_escolhido_1->size[1] = 2;
      emxEnsureCapacity_int32_T(c_escolhido_1, i33);
      loop_ub = escolhido_1->size[0];
      for (i33 = 0; i33 < loop_ub; i33++) {
        c_escolhido_1->data[i33] = escolhido_1->data[i33];
      }

      loop_ub = escolhido_2->size[0];
      for (i33 = 0; i33 < loop_ub; i33++) {
        c_escolhido_1->data[i33 + c_escolhido_1->size[0]] = escolhido_2->
          data[i33];
      }

      partialTrueCount = b_x->size[0];
      for (i33 = 0; i33 < 2; i33++) {
        for (i34 = 0; i34 < partialTrueCount; i34++) {
          newIC->data[b_x->data[i34] + newIC->size[0] * iidx->data[i33]] =
            c_escolhido_1->data[i34 + partialTrueCount * i33];
        }
      }

      /* 'cc:51' j=j+1; */
      j = 2;
    } else {
      /* 'cc:52' else */
      /* 'cc:53' for k=1:(j-1)*2 */
      i33 = (j - 1) << 1;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k <= i33 - 1)) {
        /* 'cc:54' if sum(escolhido_1==newIC(:,k))==NumTOp || sum(escolhido_2==newIC(:,k))==NumTOp */
        i34 = b_escolhido_1->size[0];
        b_escolhido_1->size[0] = escolhido_1->size[0];
        emxEnsureCapacity_boolean_T(b_escolhido_1, i34);
        loop_ub = escolhido_1->size[0];
        for (i34 = 0; i34 < loop_ub; i34++) {
          b_escolhido_1->data[i34] = (escolhido_1->data[i34] == newIC->data[i34
            + newIC->size[0] * k]);
        }

        if (g_sum(b_escolhido_1) == NumTOp) {
          /* 'cc:55' flag=true; */
          flag = true;
          exitg1 = true;
        } else {
          i34 = b_escolhido_1->size[0];
          b_escolhido_1->size[0] = escolhido_2->size[0];
          emxEnsureCapacity_boolean_T(b_escolhido_1, i34);
          loop_ub = escolhido_2->size[0];
          for (i34 = 0; i34 < loop_ub; i34++) {
            b_escolhido_1->data[i34] = (escolhido_2->data[i34] == newIC->
              data[i34 + newIC->size[0] * k]);
          }

          if (g_sum(b_escolhido_1) == NumTOp) {
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
        i33 = (j + j) - 2;
        u16 = (unsigned int)j << 1;
        if ((unsigned int)(i33 + 1) > u16) {
          i33 = 0;
          i34 = 0;
        } else {
          i34 = (int)u16;
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
        loop_ub = i34 - i33;
        iidx->size[0] = loop_ub;
        emxEnsureCapacity_int32_T(iidx, partialTrueCount);
        for (i34 = 0; i34 < loop_ub; i34++) {
          iidx->data[i34] = i33 + i34;
        }

        i33 = c_escolhido_1->size[0] * c_escolhido_1->size[1];
        c_escolhido_1->size[0] = escolhido_1->size[0];
        c_escolhido_1->size[1] = 2;
        emxEnsureCapacity_int32_T(c_escolhido_1, i33);
        loop_ub = escolhido_1->size[0];
        for (i33 = 0; i33 < loop_ub; i33++) {
          c_escolhido_1->data[i33] = escolhido_1->data[i33];
        }

        loop_ub = escolhido_2->size[0];
        for (i33 = 0; i33 < loop_ub; i33++) {
          c_escolhido_1->data[i33 + c_escolhido_1->size[0]] = escolhido_2->
            data[i33];
        }

        partialTrueCount = b_x->size[0];
        loop_ub = iidx->size[0];
        for (i33 = 0; i33 < loop_ub; i33++) {
          for (i34 = 0; i34 < partialTrueCount; i34++) {
            newIC->data[b_x->data[i34] + newIC->size[0] * iidx->data[i33]] =
              c_escolhido_1->data[i34 + partialTrueCount * i33];
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

/* End of code generation (cc.c) */
