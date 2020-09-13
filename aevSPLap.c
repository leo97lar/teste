/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: aevSPLap.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 18:10:16
 */

/* Include Files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "aevSPLap.h"
#include "model_emxutil.h"
#include "obsIQini.h"
#include "obsIQ.h"
#include "randperm.h"
#include "cc.h"
#include "mean.h"
#include "std.h"
#include "sort1.h"
#include "sch.h"
#include "toc.h"
#include "tic.h"
#include "rdivide_helper.h"
#include "rem.h"
#include "CreaPoQunniforme.h"
#include "model_rtwutil.h"
#include <stdio.h>

/* Function Definitions */

/*
 * function [bestexperimento, trace] = aevSPLap(NumTOp,numIC,numIQ,taxC,taxE,taxEQ,NumRec,PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,Dia,Data,...
 *     TimeUsoRec,ProbXEst,fitnessB,generations,genToWidth,DispMExD,EP,k0,k1,k2,k3,keeppriority)
 * INICIALIZA POPULAÇÃO QUANTICA.
 * Arguments    : int NumTOp
 *                int numIC
 *                int numIQ
 *                double taxC
 *                double taxE
 *                const int NumRec[7]
 *                const emxArray_int32_T *PCPrO
 *                const emxArray_int32_T *PME
 *                const emxArray_int32_T *PMA
 *                const emxArray_int32_T *PMAn
 *                const emxArray_int32_T *PS
 *                const emxArray_int32_T *PCPO
 *                const emxArray_int32_T *PCR
 *                const emxArray_int32_T *Dia
 *                const emxArray_int32_T *Data
 *                const emxArray_int32_T *TimeUsoRec
 *                const emxArray_real_T *ProbXEst
 *                const double fitnessB[6]
 *                int generations
 *                int genToWidth
 *                const emxArray_int32_T *DispMExD
 *                const emxArray_int32_T *EP
 *                double k0
 *                double k1
 *                double k2
 *                double k3
 *                boolean_T keeppriority
 *                emxArray_int32_T *bestexperimento
 *                emxArray_real_T *trace
 * Return Type  : void
 */
void aevSPLap(int NumTOp, int numIC, int numIQ, double taxC, double taxE, const
              int NumRec[7], const emxArray_int32_T *PCPrO, const
              emxArray_int32_T *PME, const emxArray_int32_T *PMA, const
              emxArray_int32_T *PMAn, const emxArray_int32_T *PS, const
              emxArray_int32_T *PCPO, const emxArray_int32_T *PCR, const
              emxArray_int32_T *Dia, const emxArray_int32_T *Data, const
              emxArray_int32_T *TimeUsoRec, const emxArray_real_T *ProbXEst,
              const double fitnessB[6], int generations, int genToWidth, const
              emxArray_int32_T *DispMExD, const emxArray_int32_T *EP, double k0,
              double k1, double k2, double k3, boolean_T keeppriority,
              emxArray_int32_T *bestexperimento, emxArray_real_T *trace)
{
  emxArray_real_T *IQ;
  int numObsIQ;
  emxArray_int32_T *IC;
  int loop_ub;
  int i11;
  emxArray_int32_T *best;
  emxArray_real_T *bestFitness;
  int i12;
  int n;
  emxArray_int32_T *y;
  int yk;
  int input_sizes_idx_1;
  emxArray_real_T *fitness;
  emxArray_int32_T *aux_classic_1;
  emxArray_real_T *aux_fitness_1;
  emxArray_int32_T *rank_classic;
  emxArray_int32_T *aux_classic_2;
  emxArray_real_T *aux_fitness_2;
  emxArray_real_T *tmpColumn;
  emxArray_int32_T *idx_1;
  emxArray_int32_T *idx_2;
  emxArray_real_T *x;
  emxArray_int32_T *iidx;
  emxArray_int8_T *num2bin;
  emxArray_real_T *b_aux_fitness_2;
  emxArray_real_T *b_fitness;
  emxArray_real_T *r5;
  emxArray_int32_T *b_PCPrO;
  emxArray_int32_T *b_PME;
  emxArray_int32_T *b_PMA;
  emxArray_int32_T *b_PMAn;
  emxArray_int32_T *b_PS;
  emxArray_int32_T *b_PCPO;
  emxArray_int32_T *b_PCR;
  emxArray_int32_T *b_TimeUsoRec;
  emxArray_int32_T *b_EP;
  int g;
  int j;
  boolean_T empty_non_axis_sizes;
  signed char b_input_sizes_idx_1;
  int b_loop_ub;
  int i13;
  double d0;
  double varargin_5;
  double d1;
  double d2;
  double d3;
  double d4;
  int i;
  emxInit_real_T(&IQ, 2);

  /* 'aevSPLap:7' [ IQ ] = CreaPoQunniforme(NumTOp,numIQ); */
  CreaPoQunniforme(NumTOp, numIQ, IQ);

  /*  IQ uniforme */
  /*  INICIALIZA POPULAÇÃO CLÁSSICA. */
  /* 'aevSPLap:11' if (rem(numIC, numIQ) ~= 0) */
  if (b_rem(numIC, numIQ) == 0) {
    /* 'aevSPLap:15' else */
    /* 'aevSPLap:16' numObsIQ = numIC/numIQ; */
    numObsIQ = rdivide_helper(numIC, numIQ);
  } else {
    /* 'aevSPLap:13' error('O número de indivíduos clássicos deve ser múltiplo do número de individuos quânticos'); */
  }

  /* 'aevSPLap:19' tic; */
  tic();

  /* 'aevSPLap:21' if (keeppriority == true) */
  emxInit_int32_T(&IC, 2);
  if (keeppriority) {
    /* 'aevSPLap:22' [ IC ] = obsIQini( IQ,numIQ,numObsIQ,ProbXEst); */
    obsIQini(IQ, numIQ, numObsIQ, ProbXEst, IC);

    /*  Observaciones de los IQ garantizando que se mantengan en el rango Prioridad             */
  } else {
    /* 'aevSPLap:23' else */
    /* 'aevSPLap:24' [ IC ] = obsIQ( IQ,numIQ,numObsIQ); */
    obsIQ(IQ, numIQ, numObsIQ, IC);

    /*  Observaciones de los IQ */
  }

  /* 'aevSPLap:27' toc; */
  toc();

  /*  PARÂMETROS DE INTERESSE */
  /* 'aevSPLap:31' bestexperimento = IC(:,1); */
  loop_ub = IC->size[0];
  i11 = bestexperimento->size[0];
  bestexperimento->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(bestexperimento, i11);
  for (i11 = 0; i11 < loop_ub; i11++) {
    bestexperimento->data[i11] = IC->data[i11];
  }

  emxInit_int32_T(&best, 2);

  /* 'aevSPLap:33' best = zeros(NumTOp,numIC, 'int32'); */
  i11 = best->size[0] * best->size[1];
  best->size[0] = NumTOp;
  best->size[1] = numIC;
  emxEnsureCapacity_int32_T(best, i11);
  for (i11 = 0; i11 < numIC; i11++) {
    for (i12 = 0; i12 < NumTOp; i12++) {
      best->data[i12 + best->size[0] * i11] = 0;
    }
  }

  emxInit_real_T(&bestFitness, 2);

  /* 'aevSPLap:34' bestFitness = zeros(numIC,6); */
  i11 = bestFitness->size[0] * bestFitness->size[1];
  bestFitness->size[0] = numIC;
  bestFitness->size[1] = 6;
  emxEnsureCapacity_real_T(bestFitness, i11);
  for (i11 = 0; i11 < 6; i11++) {
    for (i12 = 0; i12 < numIC; i12++) {
      bestFitness->data[i12 + bestFitness->size[0] * i11] = 0.0;
    }
  }

  /* 'aevSPLap:36' best(:,1) = int32(1:NumTOp)'; */
  if (NumTOp < 1) {
    n = 0;
  } else {
    n = NumTOp;
  }

  emxInit_int32_T(&y, 2);
  i11 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_int32_T(y, i11);
  if (n > 0) {
    y->data[0] = 1;
    yk = 1;
    for (input_sizes_idx_1 = 2; input_sizes_idx_1 <= n; input_sizes_idx_1++) {
      yk++;
      y->data[input_sizes_idx_1 - 1] = yk;
    }
  }

  loop_ub = y->size[1];
  for (i11 = 0; i11 < loop_ub; i11++) {
    best->data[i11] = y->data[i11];
  }

  emxFree_int32_T(&y);

  /* 'aevSPLap:37' bestFitness(1,:) = fitnessB; */
  for (i11 = 0; i11 < 6; i11++) {
    bestFitness->data[bestFitness->size[0] * i11] = fitnessB[i11];
  }

  /* 'aevSPLap:39' trace = zeros(generations,9); */
  /*  INICIALIZA LOOPING */
  /* 'aevSPLap:44' for g = 1:generations */
  i11 = trace->size[0] * trace->size[1];
  trace->size[0] = generations;
  trace->size[1] = 9;
  emxEnsureCapacity_real_T(trace, i11);
  emxInit_real_T(&fitness, 2);
  emxInit_int32_T(&aux_classic_1, 2);
  emxInit_real_T(&aux_fitness_1, 2);
  emxInit_int32_T(&rank_classic, 2);
  emxInit_int32_T(&aux_classic_2, 2);
  emxInit_real_T(&aux_fitness_2, 2);
  emxInit_real_T(&tmpColumn, 2);
  emxInit_int32_T(&idx_1, 1);
  emxInit_int32_T(&idx_2, 1);
  emxInit_real_T(&x, 1);
  emxInit_int32_T(&iidx, 1);
  emxInit_int8_T(&num2bin, 2);
  emxInit_real_T(&b_aux_fitness_2, 2);
  emxInit_real_T(&b_fitness, 1);
  emxInit_real_T(&r5, 2);
  emxInit_int32_T(&b_PCPrO, 2);
  emxInit_int32_T(&b_PME, 2);
  emxInit_int32_T(&b_PMA, 2);
  emxInit_int32_T(&b_PMAn, 2);
  emxInit_int32_T(&b_PS, 2);
  emxInit_int32_T(&b_PCPO, 2);
  emxInit_int32_T(&b_PCR, 2);
  emxInit_int32_T(&b_TimeUsoRec, 2);
  emxInit_int32_T(&b_EP, 1);
  for (g = 0; g < generations; g++) {
    /* 'aevSPLap:47' fitness=zeros(numIC,6); */
    i11 = fitness->size[0] * fitness->size[1];
    fitness->size[0] = numIC;
    fitness->size[1] = 6;
    emxEnsureCapacity_real_T(fitness, i11);
    for (i11 = 0; i11 < 6; i11++) {
      for (i12 = 0; i12 < numIC; i12++) {
        fitness->data[i12 + fitness->size[0] * i11] = 0.0;
      }
    }

    /*  [fitness,NOFP,TmNOFP,NOE2,NOE3] */
    /* 'aevSPLap:49' for j=1:numIC */
    for (j = 0; j < numIC; j++) {
      /* 'aevSPLap:51' [ fitness(j,1),fitness(j,2),fitness(j,3),fitness(j,4),fitness(j,5),fitness(j,6)] = sch(NumTOp,IC(:,j),NumRec,PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,Dia,Data,TimeUsoRec,DispMExD,EP,k0,k1,k2,k3); */
      loop_ub = IC->size[0];
      i11 = iidx->size[0];
      iidx->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(iidx, i11);
      for (i11 = 0; i11 < loop_ub; i11++) {
        iidx->data[i11] = IC->data[i11 + IC->size[0] * j];
      }

      i11 = b_PCPrO->size[0] * b_PCPrO->size[1];
      b_PCPrO->size[0] = PCPrO->size[0];
      b_PCPrO->size[1] = PCPrO->size[1];
      emxEnsureCapacity_int32_T(b_PCPrO, i11);
      loop_ub = PCPrO->size[1];
      for (i11 = 0; i11 < loop_ub; i11++) {
        b_loop_ub = PCPrO->size[0];
        for (i12 = 0; i12 < b_loop_ub; i12++) {
          b_PCPrO->data[i12 + b_PCPrO->size[0] * i11] = PCPrO->data[i12 +
            PCPrO->size[0] * i11];
        }
      }

      i11 = b_PME->size[0] * b_PME->size[1];
      b_PME->size[0] = PME->size[0];
      b_PME->size[1] = PME->size[1];
      emxEnsureCapacity_int32_T(b_PME, i11);
      loop_ub = PME->size[1];
      for (i11 = 0; i11 < loop_ub; i11++) {
        b_loop_ub = PME->size[0];
        for (i12 = 0; i12 < b_loop_ub; i12++) {
          b_PME->data[i12 + b_PME->size[0] * i11] = PME->data[i12 + PME->size[0]
            * i11];
        }
      }

      i11 = b_PMA->size[0] * b_PMA->size[1];
      b_PMA->size[0] = PMA->size[0];
      b_PMA->size[1] = PMA->size[1];
      emxEnsureCapacity_int32_T(b_PMA, i11);
      loop_ub = PMA->size[1];
      for (i11 = 0; i11 < loop_ub; i11++) {
        b_loop_ub = PMA->size[0];
        for (i12 = 0; i12 < b_loop_ub; i12++) {
          b_PMA->data[i12 + b_PMA->size[0] * i11] = PMA->data[i12 + PMA->size[0]
            * i11];
        }
      }

      i11 = b_PMAn->size[0] * b_PMAn->size[1];
      b_PMAn->size[0] = PMAn->size[0];
      b_PMAn->size[1] = PMAn->size[1];
      emxEnsureCapacity_int32_T(b_PMAn, i11);
      loop_ub = PMAn->size[1];
      for (i11 = 0; i11 < loop_ub; i11++) {
        b_loop_ub = PMAn->size[0];
        for (i12 = 0; i12 < b_loop_ub; i12++) {
          b_PMAn->data[i12 + b_PMAn->size[0] * i11] = PMAn->data[i12 +
            PMAn->size[0] * i11];
        }
      }

      i11 = b_PS->size[0] * b_PS->size[1];
      b_PS->size[0] = PS->size[0];
      b_PS->size[1] = PS->size[1];
      emxEnsureCapacity_int32_T(b_PS, i11);
      loop_ub = PS->size[1];
      for (i11 = 0; i11 < loop_ub; i11++) {
        b_loop_ub = PS->size[0];
        for (i12 = 0; i12 < b_loop_ub; i12++) {
          b_PS->data[i12 + b_PS->size[0] * i11] = PS->data[i12 + PS->size[0] *
            i11];
        }
      }

      i11 = b_PCPO->size[0] * b_PCPO->size[1];
      b_PCPO->size[0] = PCPO->size[0];
      b_PCPO->size[1] = PCPO->size[1];
      emxEnsureCapacity_int32_T(b_PCPO, i11);
      loop_ub = PCPO->size[1];
      for (i11 = 0; i11 < loop_ub; i11++) {
        b_loop_ub = PCPO->size[0];
        for (i12 = 0; i12 < b_loop_ub; i12++) {
          b_PCPO->data[i12 + b_PCPO->size[0] * i11] = PCPO->data[i12 +
            PCPO->size[0] * i11];
        }
      }

      i11 = b_PCR->size[0] * b_PCR->size[1];
      b_PCR->size[0] = PCR->size[0];
      b_PCR->size[1] = PCR->size[1];
      emxEnsureCapacity_int32_T(b_PCR, i11);
      loop_ub = PCR->size[1];
      for (i11 = 0; i11 < loop_ub; i11++) {
        b_loop_ub = PCR->size[0];
        for (i12 = 0; i12 < b_loop_ub; i12++) {
          b_PCR->data[i12 + b_PCR->size[0] * i11] = PCR->data[i12 + PCR->size[0]
            * i11];
        }
      }

      i11 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
      b_TimeUsoRec->size[0] = TimeUsoRec->size[0];
      b_TimeUsoRec->size[1] = 7;
      emxEnsureCapacity_int32_T(b_TimeUsoRec, i11);
      for (i11 = 0; i11 < 7; i11++) {
        loop_ub = TimeUsoRec->size[0];
        for (i12 = 0; i12 < loop_ub; i12++) {
          b_TimeUsoRec->data[i12 + b_TimeUsoRec->size[0] * i11] =
            TimeUsoRec->data[i12 + TimeUsoRec->size[0] * i11];
        }
      }

      i11 = b_EP->size[0];
      b_EP->size[0] = EP->size[0];
      emxEnsureCapacity_int32_T(b_EP, i11);
      loop_ub = EP->size[0];
      for (i11 = 0; i11 < loop_ub; i11++) {
        b_EP->data[i11] = EP->data[i11];
      }

      sch(NumTOp, iidx, NumRec, b_PCPrO, b_PME, b_PMA, b_PMAn, b_PS, b_PCPO,
          b_PCR, Dia, Data, b_TimeUsoRec, DispMExD, b_EP, k0, k1, k2, k3, &d0,
          &varargin_5, &d1, &d2, &d3, &d4);
      fitness->data[j] = d0;
      fitness->data[j + fitness->size[0]] = varargin_5;
      fitness->data[j + (fitness->size[0] << 1)] = d1;
      fitness->data[j + fitness->size[0] * 3] = d2;
      fitness->data[j + (fitness->size[0] << 2)] = d3;
      fitness->data[j + fitness->size[0] * 5] = d4;
    }

    /*     save(strcat('fitness_', int2str(g),'.mat'),'fitness'); */
    /*     file = load(strcat('fitness_', int2str(g),'.mat')); */
    /*     fitness = file.fitness; */
    /* ATUALIZA POPULAÇÃO B(T) */
    /* 'aevSPLap:60' if (g == 1) */
    if (1 + g == 1) {
      /* 'aevSPLap:61' aux_classic_1 = [best(:,1), IC]; */
      i11 = best->size[0];
      if (i11 != 0) {
        yk = best->size[0];
      } else if ((IC->size[0] != 0) && (IC->size[1] != 0)) {
        yk = IC->size[0];
      } else {
        i11 = best->size[0];
        if (i11 > 0) {
          yk = best->size[0];
        } else {
          yk = 0;
        }

        if (IC->size[0] > yk) {
          yk = IC->size[0];
        }
      }

      empty_non_axis_sizes = (yk == 0);
      if (empty_non_axis_sizes) {
        b_input_sizes_idx_1 = 1;
      } else {
        i11 = best->size[0];
        if (i11 != 0) {
          b_input_sizes_idx_1 = 1;
        } else {
          b_input_sizes_idx_1 = 0;
        }
      }

      if (empty_non_axis_sizes || ((IC->size[0] != 0) && (IC->size[1] != 0))) {
        input_sizes_idx_1 = IC->size[1];
      } else {
        input_sizes_idx_1 = 0;
      }

      loop_ub = best->size[0];
      i11 = iidx->size[0];
      iidx->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(iidx, i11);
      for (i11 = 0; i11 < loop_ub; i11++) {
        iidx->data[i11] = best->data[i11];
      }

      i11 = aux_classic_1->size[0] * aux_classic_1->size[1];
      aux_classic_1->size[0] = yk;
      aux_classic_1->size[1] = b_input_sizes_idx_1 + input_sizes_idx_1;
      emxEnsureCapacity_int32_T(aux_classic_1, i11);
      loop_ub = b_input_sizes_idx_1;
      for (i11 = 0; i11 < loop_ub; i11++) {
        for (i12 = 0; i12 < yk; i12++) {
          aux_classic_1->data[i12] = iidx->data[i12];
        }
      }

      for (i11 = 0; i11 < input_sizes_idx_1; i11++) {
        for (i12 = 0; i12 < yk; i12++) {
          aux_classic_1->data[i12 + aux_classic_1->size[0] * (i11 +
            b_input_sizes_idx_1)] = IC->data[i12 + yk * i11];
        }
      }

      /* 'aevSPLap:62' aux_fitness_1 = [bestFitness(1,:); fitness]; */
      i11 = aux_fitness_1->size[0] * aux_fitness_1->size[1];
      aux_fitness_1->size[0] = 1 + fitness->size[0];
      aux_fitness_1->size[1] = 6;
      emxEnsureCapacity_real_T(aux_fitness_1, i11);
      for (i11 = 0; i11 < 6; i11++) {
        aux_fitness_1->data[aux_fitness_1->size[0] * i11] = bestFitness->
          data[bestFitness->size[0] * i11];
      }

      for (i11 = 0; i11 < 6; i11++) {
        loop_ub = fitness->size[0];
        for (i12 = 0; i12 < loop_ub; i12++) {
          aux_fitness_1->data[(i12 + aux_fitness_1->size[0] * i11) + 1] =
            fitness->data[i12 + fitness->size[0] * i11];
        }
      }

      /* 'aevSPLap:63' [~,idx_1] = sort(aux_fitness_1(:,1),'ascend'); */
      loop_ub = aux_fitness_1->size[0];
      i11 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_real_T(x, i11);
      for (i11 = 0; i11 < loop_ub; i11++) {
        x->data[i11] = aux_fitness_1->data[i11];
      }

      c_sort(x, iidx);
      i11 = idx_1->size[0];
      idx_1->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idx_1, i11);
      loop_ub = iidx->size[0];
      for (i11 = 0; i11 < loop_ub; i11++) {
        idx_1->data[i11] = iidx->data[i11];
      }

      /* 'aevSPLap:63' ~ */
      /* 'aevSPLap:64' fitness_1 = aux_fitness_1(idx_1,:); */
      /* 'aevSPLap:65' rank_classic_1 = aux_classic_1(:,idx_1); */
      /* 'aevSPLap:67' fitness = fitness_1(1:numIC,:); */
      if (1 > numIC) {
        loop_ub = 0;
      } else {
        loop_ub = numIC;
      }

      i11 = b_aux_fitness_2->size[0] * b_aux_fitness_2->size[1];
      b_aux_fitness_2->size[0] = idx_1->size[0];
      b_aux_fitness_2->size[1] = 6;
      emxEnsureCapacity_real_T(b_aux_fitness_2, i11);
      for (i11 = 0; i11 < 6; i11++) {
        b_loop_ub = idx_1->size[0];
        for (i12 = 0; i12 < b_loop_ub; i12++) {
          b_aux_fitness_2->data[i12 + b_aux_fitness_2->size[0] * i11] =
            aux_fitness_1->data[(idx_1->data[i12] + aux_fitness_1->size[0] * i11)
            - 1];
        }
      }

      i11 = fitness->size[0] * fitness->size[1];
      fitness->size[0] = loop_ub;
      fitness->size[1] = 6;
      emxEnsureCapacity_real_T(fitness, i11);
      for (i11 = 0; i11 < 6; i11++) {
        for (i12 = 0; i12 < loop_ub; i12++) {
          fitness->data[i12 + fitness->size[0] * i11] = b_aux_fitness_2->
            data[i12 + b_aux_fitness_2->size[0] * i11];
        }
      }

      /* 'aevSPLap:68' rank_classic = rank_classic_1(:,1:numIC); */
      if (1 > numIC) {
        loop_ub = 0;
      } else {
        loop_ub = numIC;
      }

      b_loop_ub = aux_classic_1->size[0] - 1;
      yk = aux_classic_1->size[0];
      i11 = b_PCPrO->size[0] * b_PCPrO->size[1];
      b_PCPrO->size[0] = yk;
      b_PCPrO->size[1] = idx_1->size[0];
      emxEnsureCapacity_int32_T(b_PCPrO, i11);
      input_sizes_idx_1 = idx_1->size[0];
      for (i11 = 0; i11 < input_sizes_idx_1; i11++) {
        for (i12 = 0; i12 < yk; i12++) {
          b_PCPrO->data[i12 + b_PCPrO->size[0] * i11] = aux_classic_1->data[i12
            + aux_classic_1->size[0] * (idx_1->data[i11] - 1)];
        }
      }

      i11 = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[0] = b_loop_ub + 1;
      rank_classic->size[1] = loop_ub;
      emxEnsureCapacity_int32_T(rank_classic, i11);
      for (i11 = 0; i11 < loop_ub; i11++) {
        for (i12 = 0; i12 <= b_loop_ub; i12++) {
          rank_classic->data[i12 + rank_classic->size[0] * i11] = b_PCPrO->
            data[i12 + b_PCPrO->size[0] * i11];
        }
      }
    } else {
      /* 'aevSPLap:69' else */
      /* 'aevSPLap:70' aux_classic_2 = [best(:,1:(numIC*taxE)/100), IC]; */
      i11 = (int)rt_roundd((double)(int)rt_roundd((double)numIC * taxE) / 100.0);
      if (1 > i11) {
        loop_ub = 0;
      } else {
        loop_ub = i11;
      }

      i12 = best->size[0];
      if ((i12 != 0) && (loop_ub != 0)) {
        yk = best->size[0];
      } else if ((IC->size[0] != 0) && (IC->size[1] != 0)) {
        yk = IC->size[0];
      } else {
        i12 = best->size[0];
        if (i12 > 0) {
          yk = best->size[0];
        } else {
          yk = 0;
        }

        if (IC->size[0] > yk) {
          yk = IC->size[0];
        }
      }

      empty_non_axis_sizes = (yk == 0);
      if (empty_non_axis_sizes) {
        input_sizes_idx_1 = loop_ub;
      } else {
        i12 = best->size[0];
        if ((i12 != 0) && (loop_ub != 0)) {
          input_sizes_idx_1 = loop_ub;
        } else {
          input_sizes_idx_1 = 0;
        }
      }

      if (empty_non_axis_sizes || ((IC->size[0] != 0) && (IC->size[1] != 0))) {
        n = IC->size[1];
      } else {
        n = 0;
      }

      b_loop_ub = best->size[0] - 1;
      i12 = b_PCPrO->size[0] * b_PCPrO->size[1];
      b_PCPrO->size[0] = b_loop_ub + 1;
      b_PCPrO->size[1] = loop_ub;
      emxEnsureCapacity_int32_T(b_PCPrO, i12);
      for (i12 = 0; i12 < loop_ub; i12++) {
        for (i13 = 0; i13 <= b_loop_ub; i13++) {
          b_PCPrO->data[i13 + b_PCPrO->size[0] * i12] = best->data[i13 +
            best->size[0] * i12];
        }
      }

      i12 = best->size[0] * best->size[1];
      best->size[0] = b_PCPrO->size[0];
      best->size[1] = b_PCPrO->size[1];
      emxEnsureCapacity_int32_T(best, i12);
      loop_ub = b_PCPrO->size[1];
      for (i12 = 0; i12 < loop_ub; i12++) {
        b_loop_ub = b_PCPrO->size[0];
        for (i13 = 0; i13 < b_loop_ub; i13++) {
          best->data[i13 + best->size[0] * i12] = b_PCPrO->data[i13 +
            b_PCPrO->size[0] * i12];
        }
      }

      i12 = aux_classic_2->size[0] * aux_classic_2->size[1];
      aux_classic_2->size[0] = yk;
      aux_classic_2->size[1] = input_sizes_idx_1 + n;
      emxEnsureCapacity_int32_T(aux_classic_2, i12);
      for (i12 = 0; i12 < input_sizes_idx_1; i12++) {
        for (i13 = 0; i13 < yk; i13++) {
          aux_classic_2->data[i13 + aux_classic_2->size[0] * i12] = best->
            data[i13 + yk * i12];
        }
      }

      for (i12 = 0; i12 < n; i12++) {
        for (i13 = 0; i13 < yk; i13++) {
          aux_classic_2->data[i13 + aux_classic_2->size[0] * (i12 +
            input_sizes_idx_1)] = IC->data[i13 + yk * i12];
        }
      }

      /* 'aevSPLap:71' aux_fitness_2 = [bestFitness(1:(numIC*taxE)/100,:); fitness]; */
      if (1 > i11) {
        loop_ub = 0;
      } else {
        loop_ub = i11;
      }

      i11 = aux_fitness_2->size[0] * aux_fitness_2->size[1];
      aux_fitness_2->size[0] = loop_ub + fitness->size[0];
      aux_fitness_2->size[1] = 6;
      emxEnsureCapacity_real_T(aux_fitness_2, i11);
      for (i11 = 0; i11 < 6; i11++) {
        for (i12 = 0; i12 < loop_ub; i12++) {
          aux_fitness_2->data[i12 + aux_fitness_2->size[0] * i11] =
            bestFitness->data[i12 + bestFitness->size[0] * i11];
        }
      }

      for (i11 = 0; i11 < 6; i11++) {
        b_loop_ub = fitness->size[0];
        for (i12 = 0; i12 < b_loop_ub; i12++) {
          aux_fitness_2->data[(i12 + loop_ub) + aux_fitness_2->size[0] * i11] =
            fitness->data[i12 + fitness->size[0] * i11];
        }
      }

      /* 'aevSPLap:72' [~,idx_2] = sort(aux_fitness_2(:,1),'ascend'); */
      loop_ub = aux_fitness_2->size[0];
      i11 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_real_T(x, i11);
      for (i11 = 0; i11 < loop_ub; i11++) {
        x->data[i11] = aux_fitness_2->data[i11];
      }

      c_sort(x, iidx);
      i11 = idx_2->size[0];
      idx_2->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idx_2, i11);
      loop_ub = iidx->size[0];
      for (i11 = 0; i11 < loop_ub; i11++) {
        idx_2->data[i11] = iidx->data[i11];
      }

      /* 'aevSPLap:72' ~ */
      /* 'aevSPLap:73' fitness_2 = aux_fitness_2(idx_2,:); */
      /* 'aevSPLap:74' rank_classic_2 = aux_classic_2(:,idx_2); */
      /* 'aevSPLap:76' fitness = fitness_2(1:numIC,:); */
      if (1 > numIC) {
        loop_ub = 0;
      } else {
        loop_ub = numIC;
      }

      i11 = b_aux_fitness_2->size[0] * b_aux_fitness_2->size[1];
      b_aux_fitness_2->size[0] = idx_2->size[0];
      b_aux_fitness_2->size[1] = 6;
      emxEnsureCapacity_real_T(b_aux_fitness_2, i11);
      for (i11 = 0; i11 < 6; i11++) {
        b_loop_ub = idx_2->size[0];
        for (i12 = 0; i12 < b_loop_ub; i12++) {
          b_aux_fitness_2->data[i12 + b_aux_fitness_2->size[0] * i11] =
            aux_fitness_2->data[(idx_2->data[i12] + aux_fitness_2->size[0] * i11)
            - 1];
        }
      }

      i11 = fitness->size[0] * fitness->size[1];
      fitness->size[0] = loop_ub;
      fitness->size[1] = 6;
      emxEnsureCapacity_real_T(fitness, i11);
      for (i11 = 0; i11 < 6; i11++) {
        for (i12 = 0; i12 < loop_ub; i12++) {
          fitness->data[i12 + fitness->size[0] * i11] = b_aux_fitness_2->
            data[i12 + b_aux_fitness_2->size[0] * i11];
        }
      }

      /* 'aevSPLap:77' rank_classic = rank_classic_2(:,1:numIC); */
      if (1 > numIC) {
        loop_ub = 0;
      } else {
        loop_ub = numIC;
      }

      b_loop_ub = aux_classic_2->size[0] - 1;
      yk = aux_classic_2->size[0];
      i11 = b_PCPrO->size[0] * b_PCPrO->size[1];
      b_PCPrO->size[0] = yk;
      b_PCPrO->size[1] = idx_2->size[0];
      emxEnsureCapacity_int32_T(b_PCPrO, i11);
      input_sizes_idx_1 = idx_2->size[0];
      for (i11 = 0; i11 < input_sizes_idx_1; i11++) {
        for (i12 = 0; i12 < yk; i12++) {
          b_PCPrO->data[i12 + b_PCPrO->size[0] * i11] = aux_classic_2->data[i12
            + aux_classic_2->size[0] * (idx_2->data[i11] - 1)];
        }
      }

      i11 = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[0] = b_loop_ub + 1;
      rank_classic->size[1] = loop_ub;
      emxEnsureCapacity_int32_T(rank_classic, i11);
      for (i11 = 0; i11 < loop_ub; i11++) {
        for (i12 = 0; i12 <= b_loop_ub; i12++) {
          rank_classic->data[i12 + rank_classic->size[0] * i11] = b_PCPrO->
            data[i12 + b_PCPrO->size[0] * i11];
        }
      }
    }

    /* REMOVE INDIVÍDUOS MAIS FRACOS (EXCEDENTES) */
    /* 'aevSPLap:83' IC = rank_classic; */
    /* 'aevSPLap:84' best = IC; */
    i11 = best->size[0] * best->size[1];
    best->size[0] = rank_classic->size[0];
    best->size[1] = rank_classic->size[1];
    emxEnsureCapacity_int32_T(best, i11);
    loop_ub = rank_classic->size[1];
    for (i11 = 0; i11 < loop_ub; i11++) {
      b_loop_ub = rank_classic->size[0];
      for (i12 = 0; i12 < b_loop_ub; i12++) {
        best->data[i12 + best->size[0] * i11] = rank_classic->data[i12 +
          rank_classic->size[0] * i11];
      }
    }

    /* 'aevSPLap:85' bestFitness = fitness; */
    i11 = bestFitness->size[0] * bestFitness->size[1];
    bestFitness->size[0] = fitness->size[0];
    bestFitness->size[1] = 6;
    emxEnsureCapacity_real_T(bestFitness, i11);
    for (i11 = 0; i11 < 6; i11++) {
      loop_ub = fitness->size[0];
      for (i12 = 0; i12 < loop_ub; i12++) {
        bestFitness->data[i12 + bestFitness->size[0] * i11] = fitness->data[i12
          + fitness->size[0] * i11];
      }
    }

    /*  GUARDA MELHOR INDIVÍDUO */
    /* 'aevSPLap:89' bestexperimento = IC(:,1); */
    loop_ub = rank_classic->size[0];
    i11 = bestexperimento->size[0];
    bestexperimento->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(bestexperimento, i11);
    for (i11 = 0; i11 < loop_ub; i11++) {
      bestexperimento->data[i11] = rank_classic->data[i11];
    }

    /*  SALVA A GERAÇÃO, FITNESS do Melhor ind., a MÉDIA DO FITNESS e a STD DO FITNESS  */
    /* 'aevSPLap:93' trace(g,:) = [g,bestFitness(1,1),mean(bestFitness(:,1),1),std(bestFitness(:,1),1),bestFitness(1,2),bestFitness(1,3),bestFitness(1,4),bestFitness(1,5),bestFitness(1,6)]; */
    loop_ub = fitness->size[0];
    i11 = x->size[0];
    x->size[0] = loop_ub;
    emxEnsureCapacity_real_T(x, i11);
    for (i11 = 0; i11 < loop_ub; i11++) {
      x->data[i11] = fitness->data[i11];
    }

    loop_ub = fitness->size[0];
    i11 = b_fitness->size[0];
    b_fitness->size[0] = loop_ub;
    emxEnsureCapacity_real_T(b_fitness, i11);
    for (i11 = 0; i11 < loop_ub; i11++) {
      b_fitness->data[i11] = fitness->data[i11];
    }

    varargin_5 = mean(x);
    d1 = b_std(b_fitness);
    trace->data[g] = 1 + g;
    trace->data[g + trace->size[0]] = (int)rt_roundd(fitness->data[0]);
    trace->data[g + (trace->size[0] << 1)] = (int)rt_roundd(varargin_5);
    trace->data[g + trace->size[0] * 3] = (int)rt_roundd(d1);
    trace->data[g + (trace->size[0] << 2)] = (int)rt_roundd(fitness->
      data[fitness->size[0]]);
    trace->data[g + trace->size[0] * 5] = (int)rt_roundd(fitness->data
      [fitness->size[0] << 1]);
    trace->data[g + trace->size[0] * 6] = (int)rt_roundd(fitness->data
      [fitness->size[0] * 3]);
    trace->data[g + trace->size[0] * 7] = (int)rt_roundd(fitness->data
      [fitness->size[0] << 2]);
    trace->data[g + (trace->size[0] << 3)] = (int)rt_roundd(fitness->
      data[fitness->size[0] * 5]);

    /*  IMPRIME STATUS DA EVOLUÇÃO */
    /* 'aevSPLap:97' fprintf('Ger: %d - \t Ini: %10.5f - \t Best: %10.5f - \t Mean: %10.5f - \t STD: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t NOE2: %10.5f - \t NOE3: %10.5f \n',... */
    /* 'aevSPLap:98'                g,         fitnessB(1,1),      bestFitness(1,1),mean(bestFitness(:,1),1),std(bestFitness(:,1),1),bestFitness(1,2),bestFitness(1,3),bestFitness(1,4),bestFitness(1,5),bestFitness(1,6)); */
    loop_ub = fitness->size[0];
    i11 = x->size[0];
    x->size[0] = loop_ub;
    emxEnsureCapacity_real_T(x, i11);
    for (i11 = 0; i11 < loop_ub; i11++) {
      x->data[i11] = fitness->data[i11];
    }

    varargin_5 = b_std(x);
    loop_ub = fitness->size[0];
    i11 = x->size[0];
    x->size[0] = loop_ub;
    emxEnsureCapacity_real_T(x, i11);
    for (i11 = 0; i11 < loop_ub; i11++) {
      x->data[i11] = fitness->data[i11];
    }

    printf("Ger: %d - \t Ini: %10.5f - \t Best: %10.5f - \t Mean: %10.5f - \t STD: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t "
           "NOE2: %10.5f - \t NOE3: %10.5f \n", 1 + g, fitnessB[0],
           fitness->data[0], mean(x), varargin_5, fitness->data[fitness->size[0]],
           fitness->data[fitness->size[0] << 1], fitness->data[fitness->size[0] *
           3], fitness->data[fitness->size[0] << 2], fitness->data[fitness->
           size[0] * 5]);
    fflush(stdout);

    /*  REPOSICIONA PULSOS DE ACORDO COM MELHORES INDIVÍDUOS */
    /* 'aevSPLap:102' if (rem(g, genToWidth) == 0) */
    if (genToWidth == 0) {
      yk = 0;
    } else {
      yk = (g - genToWidth * div_s32(1 + g, genToWidth)) + 1;
    }

    if (yk == 0) {
      /*  QUANTUM UPDATE */
      /* 'aevSPLap:106' tmpColumn = randperm(numIQ-1); */
      c_randperm(numIQ - 1, tmpColumn);

      /* %%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%% */
      /*          maximo=0.02; */
      /*          minimo=0.002; */
      /*          taxAct = rand; */
      /*          taxAct = (maximo-minimo)*taxAct+minimo; */
      /* 'aevSPLap:112' taxAct = 0.00001; */
      /* 'aevSPLap:114' [ IQtemp ] = actIQ(IQ(1:end-NumTOp,:),IC(:,tmpColumn),taxAct); */
      i11 = IQ->size[0] - NumTOp;
      if (1 > i11) {
        loop_ub = 0;
      } else {
        loop_ub = i11;
      }

      b_loop_ub = rank_classic->size[0];
      i11 = IC->size[0] * IC->size[1];
      IC->size[0] = b_loop_ub;
      IC->size[1] = tmpColumn->size[1];
      emxEnsureCapacity_int32_T(IC, i11);
      yk = tmpColumn->size[1];
      for (i11 = 0; i11 < yk; i11++) {
        for (i12 = 0; i12 < b_loop_ub; i12++) {
          IC->data[i12 + IC->size[0] * i11] = rank_classic->data[i12 +
            rank_classic->size[0] * ((int)tmpColumn->data[i11] - 1)];
        }
      }

      /* UNTITLED5 Summary of this function goes here */
      /*    Detailed explanation goes here */
      /* Convertir de numerico a representacion binaria. */
      /* 'actIQ:7' num2bin = zeros(size(IC,1)*size(IC,2),size(IC,1)); */
      i11 = rank_classic->size[0];
      b_loop_ub = rank_classic->size[0];
      i12 = x->size[0];
      x->size[0] = tmpColumn->size[1];
      emxEnsureCapacity_real_T(x, i12);
      yk = tmpColumn->size[1];
      for (i12 = 0; i12 < yk; i12++) {
        x->data[i12] = tmpColumn->data[i12];
      }

      yk = (int)((double)i11 * (double)x->size[0]);
      i11 = num2bin->size[0] * num2bin->size[1];
      num2bin->size[0] = yk;
      num2bin->size[1] = b_loop_ub;
      emxEnsureCapacity_int8_T(num2bin, i11);
      for (i11 = 0; i11 < b_loop_ub; i11++) {
        for (i12 = 0; i12 < yk; i12++) {
          num2bin->data[i12 + num2bin->size[0] * i11] = 0;
        }
      }

      /* 'actIQ:9' for i=1:size(num2bin,1) */
      i11 = rank_classic->size[0];
      i12 = x->size[0];
      x->size[0] = tmpColumn->size[1];
      emxEnsureCapacity_real_T(x, i12);
      b_loop_ub = tmpColumn->size[1];
      for (i12 = 0; i12 < b_loop_ub; i12++) {
        x->data[i12] = tmpColumn->data[i12];
      }

      i11 = (int)((double)i11 * (double)x->size[0]);
      for (i = 0; i < i11; i++) {
        /* 'actIQ:10' num2bin(i,IC(i))=1; */
        num2bin->data[i + num2bin->size[0] * (IC->data[i] - 1)] = 1;
      }

      /* 'actIQ:13' IQact = (1-taxAct)*IQ+taxAct*num2bin; */
      /* %%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%% */
      /* 'aevSPLap:115' IQ(1:end-NumTOp,:)=IQtemp; */
      b_loop_ub = IQ->size[1] - 1;
      i11 = r5->size[0] * r5->size[1];
      r5->size[0] = loop_ub;
      r5->size[1] = b_loop_ub + 1;
      emxEnsureCapacity_real_T(r5, i11);
      for (i11 = 0; i11 <= b_loop_ub; i11++) {
        for (i12 = 0; i12 < loop_ub; i12++) {
          r5->data[i12 + r5->size[0] * i11] = 0.99999 * IQ->data[i12 + IQ->size
            [0] * i11] + 1.0E-5 * (double)num2bin->data[i12 + num2bin->size[0] *
            i11];
        }
      }

      loop_ub = r5->size[1];
      for (i11 = 0; i11 < loop_ub; i11++) {
        b_loop_ub = r5->size[0];
        for (i12 = 0; i12 < b_loop_ub; i12++) {
          IQ->data[i12 + IQ->size[0] * i11] = r5->data[i12 + r5->size[0] * i11];
        }
      }

      /* %%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%% */
      /*  NEW CLASSIC POPULATION */
      /* 'aevSPLap:119' if (keeppriority == true) */
      if (keeppriority) {
        /* 'aevSPLap:120' [ IC ] = obsIQini( IQ,numIQ,numObsIQ,ProbXEst); */
        obsIQini(IQ, numIQ, numObsIQ, ProbXEst, IC);

        /*  Observaciones de los IQ garantizando que se mantengan en el rango Prioridad             */
      } else {
        /* 'aevSPLap:121' else */
        /* 'aevSPLap:122' [ IC ] = obsIQ( IQ,numIQ,numObsIQ); */
        obsIQ(IQ, numIQ, numObsIQ, IC);

        /*  Observaciones de los IQ */
      }
    } else {
      /* 'aevSPLap:125' else */
      /*  Crossover clasico          */
      /* 'aevSPLap:128' [ IC ] = cc( IC,numIC,taxC,NumTOp); */
      cc(rank_classic, numIC, taxC, NumTOp, IC);
    }
  }

  emxFree_int32_T(&b_EP);
  emxFree_int32_T(&b_TimeUsoRec);
  emxFree_int32_T(&b_PCR);
  emxFree_int32_T(&b_PCPO);
  emxFree_int32_T(&b_PS);
  emxFree_int32_T(&b_PMAn);
  emxFree_int32_T(&b_PMA);
  emxFree_int32_T(&b_PME);
  emxFree_int32_T(&b_PCPrO);
  emxFree_real_T(&r5);
  emxFree_real_T(&b_fitness);
  emxFree_real_T(&b_aux_fitness_2);
  emxFree_int8_T(&num2bin);
  emxFree_int32_T(&iidx);
  emxFree_real_T(&x);
  emxFree_int32_T(&idx_2);
  emxFree_int32_T(&idx_1);
  emxFree_real_T(&tmpColumn);
  emxFree_real_T(&aux_fitness_2);
  emxFree_int32_T(&aux_classic_2);
  emxFree_int32_T(&rank_classic);
  emxFree_real_T(&aux_fitness_1);
  emxFree_int32_T(&aux_classic_1);
  emxFree_real_T(&fitness);
  emxFree_real_T(&bestFitness);
  emxFree_int32_T(&best);
  emxFree_int32_T(&IC);
  emxFree_real_T(&IQ);
}

/*
 * File trailer for aevSPLap.c
 *
 * [EOF]
 */
