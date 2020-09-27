/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: aevSPLap.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
#include "pch.h"

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
  int i17;
  emxArray_int32_T *best;
  emxArray_real_T *bestFitness;
  int i18;
  int n;
  emxArray_int32_T *r10;
  int yk;
  int k;
  emxArray_real_T *fitness;
  emxArray_int32_T *aux_classic_1;
  emxArray_real_T *aux_fitness_1;
  emxArray_int32_T *rank_classic;
  emxArray_int32_T *aux_classic_2;
  emxArray_real_T *aux_fitness_2;
  emxArray_real_T *tmpColumn;
  emxArray_int32_T *idx_1;
  emxArray_int32_T *idx_2;
  emxArray_int32_T *r11;
  cell_wrap_0 reshapes[2];
  emxArray_real_T *x;
  emxArray_int32_T *iidx;
  cell_wrap_0 b_reshapes[2];
  emxArray_int8_T *num2bin;
  emxArray_real_T *b_aux_fitness_2;
  emxArray_real_T *b_fitness;
  emxArray_real_T *r12;
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
  int result;
  boolean_T empty_non_axis_sizes;
  int input_sizes[2];
  signed char i19;
  int i20;
  double d0;
  double varargin_5;
  double d1;
  double d2;
  double d3;
  double d4;
  int b_g[9];
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
  i17 = bestexperimento->size[0];
  bestexperimento->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(bestexperimento, i17);
  for (i17 = 0; i17 < loop_ub; i17++) {
    bestexperimento->data[i17] = IC->data[IC->size[1] * i17];
  }

  emxInit_int32_T(&best, 2);

  /* 'aevSPLap:33' best = zeros(NumTOp,numIC, 'int32'); */
  i17 = best->size[0] * best->size[1];
  best->size[1] = numIC;
  best->size[0] = NumTOp;
  emxEnsureCapacity_int32_T(best, i17);
  for (i17 = 0; i17 < NumTOp; i17++) {
    for (i18 = 0; i18 < numIC; i18++) {
      best->data[i18 + best->size[1] * i17] = 0;
    }
  }

  emxInit_real_T(&bestFitness, 2);

  /* 'aevSPLap:34' bestFitness = zeros(numIC,6); */
  i17 = bestFitness->size[0] * bestFitness->size[1];
  bestFitness->size[1] = 6;
  bestFitness->size[0] = numIC;
  emxEnsureCapacity_real_T(bestFitness, i17);
  for (i17 = 0; i17 < numIC; i17++) {
    for (i18 = 0; i18 < 6; i18++) {
      bestFitness->data[i18 + 6 * i17] = 0.0;
    }
  }

  /* 'aevSPLap:36' best(:,1) = int32(1:NumTOp)'; */
  if (NumTOp < 1) {
    n = 0;
  } else {
    n = NumTOp;
  }

  emxInit_int32_T(&r10, 2);
  i17 = r10->size[0] * r10->size[1];
  r10->size[1] = n;
  r10->size[0] = 1;
  emxEnsureCapacity_int32_T(r10, i17);
  if (n > 0) {
    r10->data[0] = 1;
    yk = 1;
    for (k = 2; k <= n; k++) {
      yk++;
      r10->data[k - 1] = yk;
    }
  }

  yk = r10->size[1];
  for (i17 = 0; i17 < yk; i17++) {
    best->data[best->size[1] * i17] = r10->data[i17];
  }

  emxFree_int32_T(&r10);

  /* 'aevSPLap:37' bestFitness(1,:) = fitnessB; */
  for (i17 = 0; i17 < 6; i17++) {
    bestFitness->data[i17] = fitnessB[i17];
  }

  /* 'aevSPLap:39' trace = zeros(generations,9); */
  /*  INICIALIZA LOOPING */
  /* 'aevSPLap:44' for g = 1:generations */
  i17 = trace->size[0] * trace->size[1];
  trace->size[1] = 9;
  trace->size[0] = generations;
  emxEnsureCapacity_real_T(trace, i17);
  emxInit_real_T(&fitness, 2);
  emxInit_int32_T(&aux_classic_1, 2);
  emxInit_real_T(&aux_fitness_1, 2);
  emxInit_int32_T(&rank_classic, 2);
  emxInit_int32_T(&aux_classic_2, 2);
  emxInit_real_T(&aux_fitness_2, 2);
  emxInit_real_T(&tmpColumn, 2);
  emxInit_int32_T(&idx_1, 1);
  emxInit_int32_T(&idx_2, 1);
  emxInit_int32_T(&r11, 2);
  emxInitMatrix_cell_wrap_0(reshapes);
  emxInit_real_T(&x, 1);
  emxInit_int32_T(&iidx, 1);
  emxInitMatrix_cell_wrap_0(b_reshapes);
  emxInit_int8_T(&num2bin, 2);
  emxInit_real_T(&b_aux_fitness_2, 2);
  emxInit_real_T(&b_fitness, 1);
  emxInit_real_T(&r12, 2);
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
    i17 = fitness->size[0] * fitness->size[1];
    fitness->size[1] = 6;
    fitness->size[0] = numIC;
    emxEnsureCapacity_real_T(fitness, i17);
    for (i17 = 0; i17 < numIC; i17++) {
      for (i18 = 0; i18 < 6; i18++) {
        fitness->data[i18 + 6 * i17] = 0.0;
      }
    }

    /*  [fitness,NOFP,TmNOFP,NOE2,NOE3] */
    /* 'aevSPLap:49' for j=1:numIC */
    for (j = 0; j < numIC; j++) {
      /* 'aevSPLap:51' [ fitness(j,1),fitness(j,2),fitness(j,3),fitness(j,4),fitness(j,5),fitness(j,6)] = sch(NumTOp,IC(:,j),NumRec,PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,Dia,Data,TimeUsoRec,DispMExD,EP,k0,k1,k2,k3); */
      loop_ub = IC->size[0];
      i17 = iidx->size[0];
      iidx->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(iidx, i17);
      for (i17 = 0; i17 < loop_ub; i17++) {
        iidx->data[i17] = IC->data[j + IC->size[1] * i17];
      }

      i17 = b_PCPrO->size[0] * b_PCPrO->size[1];
      b_PCPrO->size[1] = PCPrO->size[1];
      b_PCPrO->size[0] = PCPrO->size[0];
      emxEnsureCapacity_int32_T(b_PCPrO, i17);
      loop_ub = PCPrO->size[0];
      for (i17 = 0; i17 < loop_ub; i17++) {
        n = PCPrO->size[1];
        for (i18 = 0; i18 < n; i18++) {
          b_PCPrO->data[i18 + b_PCPrO->size[1] * i17] = PCPrO->data[i18 +
            PCPrO->size[1] * i17];
        }
      }

      i17 = b_PME->size[0] * b_PME->size[1];
      b_PME->size[1] = PME->size[1];
      b_PME->size[0] = PME->size[0];
      emxEnsureCapacity_int32_T(b_PME, i17);
      loop_ub = PME->size[0];
      for (i17 = 0; i17 < loop_ub; i17++) {
        n = PME->size[1];
        for (i18 = 0; i18 < n; i18++) {
          b_PME->data[i18 + b_PME->size[1] * i17] = PME->data[i18 + PME->size[1]
            * i17];
        }
      }

      i17 = b_PMA->size[0] * b_PMA->size[1];
      b_PMA->size[1] = PMA->size[1];
      b_PMA->size[0] = PMA->size[0];
      emxEnsureCapacity_int32_T(b_PMA, i17);
      loop_ub = PMA->size[0];
      for (i17 = 0; i17 < loop_ub; i17++) {
        n = PMA->size[1];
        for (i18 = 0; i18 < n; i18++) {
          b_PMA->data[i18 + b_PMA->size[1] * i17] = PMA->data[i18 + PMA->size[1]
            * i17];
        }
      }

      i17 = b_PMAn->size[0] * b_PMAn->size[1];
      b_PMAn->size[1] = PMAn->size[1];
      b_PMAn->size[0] = PMAn->size[0];
      emxEnsureCapacity_int32_T(b_PMAn, i17);
      loop_ub = PMAn->size[0];
      for (i17 = 0; i17 < loop_ub; i17++) {
        n = PMAn->size[1];
        for (i18 = 0; i18 < n; i18++) {
          b_PMAn->data[i18 + b_PMAn->size[1] * i17] = PMAn->data[i18 +
            PMAn->size[1] * i17];
        }
      }

      i17 = b_PS->size[0] * b_PS->size[1];
      b_PS->size[1] = PS->size[1];
      b_PS->size[0] = PS->size[0];
      emxEnsureCapacity_int32_T(b_PS, i17);
      loop_ub = PS->size[0];
      for (i17 = 0; i17 < loop_ub; i17++) {
        n = PS->size[1];
        for (i18 = 0; i18 < n; i18++) {
          b_PS->data[i18 + b_PS->size[1] * i17] = PS->data[i18 + PS->size[1] *
            i17];
        }
      }

      i17 = b_PCPO->size[0] * b_PCPO->size[1];
      b_PCPO->size[1] = PCPO->size[1];
      b_PCPO->size[0] = PCPO->size[0];
      emxEnsureCapacity_int32_T(b_PCPO, i17);
      loop_ub = PCPO->size[0];
      for (i17 = 0; i17 < loop_ub; i17++) {
        n = PCPO->size[1];
        for (i18 = 0; i18 < n; i18++) {
          b_PCPO->data[i18 + b_PCPO->size[1] * i17] = PCPO->data[i18 +
            PCPO->size[1] * i17];
        }
      }

      i17 = b_PCR->size[0] * b_PCR->size[1];
      b_PCR->size[1] = PCR->size[1];
      b_PCR->size[0] = PCR->size[0];
      emxEnsureCapacity_int32_T(b_PCR, i17);
      loop_ub = PCR->size[0];
      for (i17 = 0; i17 < loop_ub; i17++) {
        n = PCR->size[1];
        for (i18 = 0; i18 < n; i18++) {
          b_PCR->data[i18 + b_PCR->size[1] * i17] = PCR->data[i18 + PCR->size[1]
            * i17];
        }
      }

      i17 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
      b_TimeUsoRec->size[1] = 7;
      b_TimeUsoRec->size[0] = TimeUsoRec->size[0];
      emxEnsureCapacity_int32_T(b_TimeUsoRec, i17);
      loop_ub = TimeUsoRec->size[0];
      for (i17 = 0; i17 < loop_ub; i17++) {
        for (i18 = 0; i18 < 7; i18++) {
          i20 = i18 + 7 * i17;
          b_TimeUsoRec->data[i20] = TimeUsoRec->data[i20];
        }
      }

      i17 = b_EP->size[0];
      b_EP->size[0] = EP->size[0];
      emxEnsureCapacity_int32_T(b_EP, i17);
      loop_ub = EP->size[0];
      for (i17 = 0; i17 < loop_ub; i17++) {
        b_EP->data[i17] = EP->data[i17];
      }

      sch(NumTOp, iidx, NumRec, b_PCPrO, b_PME, b_PMA, b_PMAn, b_PS, b_PCPO,
          b_PCR, Dia, Data, b_TimeUsoRec, DispMExD, b_EP, k0, k1, k2, k3, &d0,
          &varargin_5, &d1, &d2, &d3, &d4);
      fitness->data[6 * j] = d0;
      fitness->data[1 + 6 * j] = varargin_5;
      fitness->data[2 + 6 * j] = d1;
      fitness->data[3 + 6 * j] = d2;
      fitness->data[4 + 6 * j] = d3;
      fitness->data[5 + 6 * j] = d4;
    }

    /*     save(strcat('fitness_', int2str(g),'.mat'),'fitness'); */
    /*     file = load(strcat('fitness_', int2str(g),'.mat')); */
    /*     fitness = file.fitness; */
    /* ATUALIZA POPULAÇÃO B(T) */
    /* 'aevSPLap:60' if (g == 1) */
    if (1 + g == 1) {
      /* 'aevSPLap:61' aux_classic_1 = [best(:,1), IC]; */
      loop_ub = best->size[0];
      i17 = r11->size[0] * r11->size[1];
      r11->size[1] = 1;
      r11->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(r11, i17);
      for (i17 = 0; i17 < loop_ub; i17++) {
        r11->data[i17] = best->data[best->size[1] * i17];
      }

      i17 = best->size[0];
      if (i17 != 0) {
        result = best->size[0];
      } else if ((IC->size[0] != 0) && (IC->size[1] != 0)) {
        result = IC->size[0];
      } else {
        i17 = best->size[0];
        if (i17 > 0) {
          result = best->size[0];
        } else {
          result = 0;
        }

        if (IC->size[0] > result) {
          result = IC->size[0];
        }
      }

      empty_non_axis_sizes = (result == 0);
      if (empty_non_axis_sizes) {
        i19 = 1;
      } else {
        i17 = best->size[0];
        if (i17 != 0) {
          i19 = 1;
        } else {
          i19 = 0;
        }
      }

      input_sizes[0] = result;
      input_sizes[1] = i19;
      i17 = 0;
      i18 = 0;
      i20 = 0;
      k = b_reshapes[0].f1->size[0] * b_reshapes[0].f1->size[1];
      b_reshapes[0].f1->size[1] = i19;
      b_reshapes[0].f1->size[0] = result;
      emxEnsureCapacity_int32_T(b_reshapes[0].f1, k);
      for (k = 0; k < input_sizes[0] * input_sizes[1]; k++) {
        b_reshapes[0].f1->data[i18 + b_reshapes[0].f1->size[1] * i17] =
          r11->data[i20];
        i17++;
        i20++;
        if (i17 > b_reshapes[0].f1->size[0] - 1) {
          i17 = 0;
          i18++;
        }
      }

      if (empty_non_axis_sizes || ((IC->size[0] != 0) && (IC->size[1] != 0))) {
        yk = IC->size[1];
      } else {
        yk = 0;
      }

      input_sizes[0] = result;
      input_sizes[1] = yk;
      if ((yk == IC->size[1]) && (result == IC->size[0])) {
        i17 = b_reshapes[1].f1->size[0] * b_reshapes[1].f1->size[1];
        b_reshapes[1].f1->size[1] = yk;
        b_reshapes[1].f1->size[0] = result;
        emxEnsureCapacity_int32_T(b_reshapes[1].f1, i17);
        for (i17 = 0; i17 < result; i17++) {
          for (i18 = 0; i18 < yk; i18++) {
            b_reshapes[1].f1->data[i18 + b_reshapes[1].f1->size[1] * i17] =
              IC->data[i18 + yk * i17];
          }
        }
      } else {
        i17 = 0;
        i18 = 0;
        i20 = 0;
        k = 0;
        n = b_reshapes[1].f1->size[0] * b_reshapes[1].f1->size[1];
        b_reshapes[1].f1->size[1] = yk;
        b_reshapes[1].f1->size[0] = result;
        emxEnsureCapacity_int32_T(b_reshapes[1].f1, n);
        for (n = 0; n < input_sizes[0] * input_sizes[1]; n++) {
          b_reshapes[1].f1->data[i18 + b_reshapes[1].f1->size[1] * i17] =
            IC->data[k + IC->size[1] * i20];
          i17++;
          i20++;
          if (i17 > b_reshapes[1].f1->size[0] - 1) {
            i17 = 0;
            i18++;
          }

          if (i20 > IC->size[0] - 1) {
            i20 = 0;
            k++;
          }
        }
      }

      i17 = aux_classic_1->size[0] * aux_classic_1->size[1];
      aux_classic_1->size[1] = b_reshapes[0].f1->size[1] + b_reshapes[1]
        .f1->size[1];
      aux_classic_1->size[0] = b_reshapes[0].f1->size[0];
      emxEnsureCapacity_int32_T(aux_classic_1, i17);
      loop_ub = b_reshapes[0].f1->size[0];
      for (i17 = 0; i17 < loop_ub; i17++) {
        n = b_reshapes[0].f1->size[1];
        for (i18 = 0; i18 < n; i18++) {
          aux_classic_1->data[i18 + aux_classic_1->size[1] * i17] = b_reshapes[0]
            .f1->data[i18 + b_reshapes[0].f1->size[1] * i17];
        }
      }

      loop_ub = b_reshapes[1].f1->size[0];
      for (i17 = 0; i17 < loop_ub; i17++) {
        n = b_reshapes[1].f1->size[1];
        for (i18 = 0; i18 < n; i18++) {
          aux_classic_1->data[(i18 + b_reshapes[0].f1->size[1]) +
            aux_classic_1->size[1] * i17] = b_reshapes[1].f1->data[i18 +
            b_reshapes[1].f1->size[1] * i17];
        }
      }

      /* 'aevSPLap:62' aux_fitness_1 = [bestFitness(1,:); fitness]; */
      i17 = aux_fitness_1->size[0] * aux_fitness_1->size[1];
      aux_fitness_1->size[1] = 6;
      aux_fitness_1->size[0] = 1 + fitness->size[0];
      emxEnsureCapacity_real_T(aux_fitness_1, i17);
      for (i17 = 0; i17 < 6; i17++) {
        aux_fitness_1->data[i17] = bestFitness->data[i17];
      }

      loop_ub = fitness->size[0];
      for (i17 = 0; i17 < loop_ub; i17++) {
        for (i18 = 0; i18 < 6; i18++) {
          aux_fitness_1->data[i18 + 6 * (i17 + 1)] = fitness->data[i18 + 6 * i17];
        }
      }

      /* 'aevSPLap:63' [~,idx_1] = sort(aux_fitness_1(:,1),'ascend'); */
      loop_ub = aux_fitness_1->size[0];
      i17 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_real_T(x, i17);
      for (i17 = 0; i17 < loop_ub; i17++) {
        x->data[i17] = aux_fitness_1->data[6 * i17];
      }

      c_sort(x, iidx);
      i17 = idx_1->size[0];
      idx_1->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idx_1, i17);
      loop_ub = iidx->size[0];
      for (i17 = 0; i17 < loop_ub; i17++) {
        idx_1->data[i17] = iidx->data[i17];
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

      i17 = b_aux_fitness_2->size[0] * b_aux_fitness_2->size[1];
      b_aux_fitness_2->size[1] = 6;
      b_aux_fitness_2->size[0] = idx_1->size[0];
      emxEnsureCapacity_real_T(b_aux_fitness_2, i17);
      n = idx_1->size[0];
      for (i17 = 0; i17 < n; i17++) {
        for (i18 = 0; i18 < 6; i18++) {
          b_aux_fitness_2->data[i18 + 6 * i17] = aux_fitness_1->data[i18 + 6 *
            (idx_1->data[i17] - 1)];
        }
      }

      i17 = fitness->size[0] * fitness->size[1];
      fitness->size[1] = 6;
      fitness->size[0] = loop_ub;
      emxEnsureCapacity_real_T(fitness, i17);
      for (i17 = 0; i17 < loop_ub; i17++) {
        for (i18 = 0; i18 < 6; i18++) {
          i20 = i18 + 6 * i17;
          fitness->data[i20] = b_aux_fitness_2->data[i20];
        }
      }

      /* 'aevSPLap:68' rank_classic = rank_classic_1(:,1:numIC); */
      if (1 > numIC) {
        loop_ub = 0;
      } else {
        loop_ub = numIC;
      }

      n = aux_classic_1->size[0] - 1;
      yk = aux_classic_1->size[0];
      i17 = b_PCPrO->size[0] * b_PCPrO->size[1];
      b_PCPrO->size[1] = idx_1->size[0];
      b_PCPrO->size[0] = yk;
      emxEnsureCapacity_int32_T(b_PCPrO, i17);
      for (i17 = 0; i17 < yk; i17++) {
        k = idx_1->size[0];
        for (i18 = 0; i18 < k; i18++) {
          b_PCPrO->data[i18 + b_PCPrO->size[1] * i17] = aux_classic_1->data
            [(idx_1->data[i18] + aux_classic_1->size[1] * i17) - 1];
        }
      }

      i17 = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[1] = loop_ub;
      rank_classic->size[0] = n + 1;
      emxEnsureCapacity_int32_T(rank_classic, i17);
      for (i17 = 0; i17 <= n; i17++) {
        for (i18 = 0; i18 < loop_ub; i18++) {
          rank_classic->data[i18 + rank_classic->size[1] * i17] = b_PCPrO->
            data[i18 + b_PCPrO->size[1] * i17];
        }
      }
    } else {
      /* 'aevSPLap:69' else */
      /* 'aevSPLap:70' aux_classic_2 = [best(:,1:(numIC*taxE)/100), IC]; */
      i17 = (int)rt_roundd((double)(int)rt_roundd((double)numIC * taxE) / 100.0);
      if (1 > i17) {
        loop_ub = 0;
      } else {
        loop_ub = i17;
      }

      i18 = best->size[0];
      if ((i18 != 0) && (loop_ub != 0)) {
        result = best->size[0];
      } else if ((IC->size[0] != 0) && (IC->size[1] != 0)) {
        result = IC->size[0];
      } else {
        i18 = best->size[0];
        if (i18 > 0) {
          result = best->size[0];
        } else {
          result = 0;
        }

        if (IC->size[0] > result) {
          result = IC->size[0];
        }
      }

      empty_non_axis_sizes = (result == 0);
      if (empty_non_axis_sizes) {
        yk = loop_ub;
      } else {
        i18 = best->size[0];
        if ((i18 != 0) && (loop_ub != 0)) {
          yk = loop_ub;
        } else {
          yk = 0;
        }
      }

      input_sizes[0] = result;
      input_sizes[1] = yk;
      i18 = best->size[0];
      if ((yk == loop_ub) && (result == i18)) {
        n = best->size[0] - 1;
        i18 = b_PCPrO->size[0] * b_PCPrO->size[1];
        b_PCPrO->size[1] = loop_ub;
        b_PCPrO->size[0] = n + 1;
        emxEnsureCapacity_int32_T(b_PCPrO, i18);
        for (i18 = 0; i18 <= n; i18++) {
          for (i20 = 0; i20 < loop_ub; i20++) {
            b_PCPrO->data[i20 + b_PCPrO->size[1] * i18] = best->data[i20 +
              best->size[1] * i18];
          }
        }

        i18 = best->size[0] * best->size[1];
        best->size[1] = b_PCPrO->size[1];
        best->size[0] = b_PCPrO->size[0];
        emxEnsureCapacity_int32_T(best, i18);
        loop_ub = b_PCPrO->size[0];
        for (i18 = 0; i18 < loop_ub; i18++) {
          n = b_PCPrO->size[1];
          for (i20 = 0; i20 < n; i20++) {
            best->data[i20 + best->size[1] * i18] = b_PCPrO->data[i20 +
              b_PCPrO->size[1] * i18];
          }
        }

        i18 = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
        reshapes[0].f1->size[1] = yk;
        reshapes[0].f1->size[0] = result;
        emxEnsureCapacity_int32_T(reshapes[0].f1, i18);
        for (i18 = 0; i18 < result; i18++) {
          for (i20 = 0; i20 < yk; i20++) {
            reshapes[0].f1->data[i20 + reshapes[0].f1->size[1] * i18] =
              best->data[i20 + yk * i18];
          }
        }
      } else {
        i18 = 0;
        i20 = 0;
        k = 0;
        n = 0;
        loop_ub = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
        reshapes[0].f1->size[1] = yk;
        reshapes[0].f1->size[0] = result;
        emxEnsureCapacity_int32_T(reshapes[0].f1, loop_ub);
        for (loop_ub = 0; loop_ub < input_sizes[0] * input_sizes[1]; loop_ub++)
        {
          reshapes[0].f1->data[i20 + reshapes[0].f1->size[1] * i18] = best->
            data[n + best->size[1] * k];
          i18++;
          k++;
          if (i18 > reshapes[0].f1->size[0] - 1) {
            i18 = 0;
            i20++;
          }

          yk = best->size[0] - 1;
          if (k > yk) {
            k = 0;
            n++;
          }
        }
      }

      if (empty_non_axis_sizes || ((IC->size[0] != 0) && (IC->size[1] != 0))) {
        yk = IC->size[1];
      } else {
        yk = 0;
      }

      input_sizes[0] = result;
      input_sizes[1] = yk;
      if ((yk == IC->size[1]) && (result == IC->size[0])) {
        i18 = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
        reshapes[1].f1->size[1] = yk;
        reshapes[1].f1->size[0] = result;
        emxEnsureCapacity_int32_T(reshapes[1].f1, i18);
        for (i18 = 0; i18 < result; i18++) {
          for (i20 = 0; i20 < yk; i20++) {
            reshapes[1].f1->data[i20 + reshapes[1].f1->size[1] * i18] = IC->
              data[i20 + yk * i18];
          }
        }
      } else {
        i18 = 0;
        i20 = 0;
        k = 0;
        n = 0;
        loop_ub = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
        reshapes[1].f1->size[1] = yk;
        reshapes[1].f1->size[0] = result;
        emxEnsureCapacity_int32_T(reshapes[1].f1, loop_ub);
        for (loop_ub = 0; loop_ub < input_sizes[0] * input_sizes[1]; loop_ub++)
        {
          reshapes[1].f1->data[i20 + reshapes[1].f1->size[1] * i18] = IC->data[n
            + IC->size[1] * k];
          i18++;
          k++;
          if (i18 > reshapes[1].f1->size[0] - 1) {
            i18 = 0;
            i20++;
          }

          if (k > IC->size[0] - 1) {
            k = 0;
            n++;
          }
        }
      }

      i18 = aux_classic_2->size[0] * aux_classic_2->size[1];
      aux_classic_2->size[1] = reshapes[0].f1->size[1] + reshapes[1].f1->size[1];
      aux_classic_2->size[0] = reshapes[0].f1->size[0];
      emxEnsureCapacity_int32_T(aux_classic_2, i18);
      loop_ub = reshapes[0].f1->size[0];
      for (i18 = 0; i18 < loop_ub; i18++) {
        n = reshapes[0].f1->size[1];
        for (i20 = 0; i20 < n; i20++) {
          aux_classic_2->data[i20 + aux_classic_2->size[1] * i18] = reshapes[0].
            f1->data[i20 + reshapes[0].f1->size[1] * i18];
        }
      }

      loop_ub = reshapes[1].f1->size[0];
      for (i18 = 0; i18 < loop_ub; i18++) {
        n = reshapes[1].f1->size[1];
        for (i20 = 0; i20 < n; i20++) {
          aux_classic_2->data[(i20 + reshapes[0].f1->size[1]) +
            aux_classic_2->size[1] * i18] = reshapes[1].f1->data[i20 + reshapes
            [1].f1->size[1] * i18];
        }
      }

      /* 'aevSPLap:71' aux_fitness_2 = [bestFitness(1:(numIC*taxE)/100,:); fitness]; */
      if (1 > i17) {
        loop_ub = 0;
      } else {
        loop_ub = i17;
      }

      i17 = aux_fitness_2->size[0] * aux_fitness_2->size[1];
      aux_fitness_2->size[1] = 6;
      aux_fitness_2->size[0] = loop_ub + fitness->size[0];
      emxEnsureCapacity_real_T(aux_fitness_2, i17);
      for (i17 = 0; i17 < loop_ub; i17++) {
        for (i18 = 0; i18 < 6; i18++) {
          i20 = i18 + 6 * i17;
          aux_fitness_2->data[i20] = bestFitness->data[i20];
        }
      }

      n = fitness->size[0];
      for (i17 = 0; i17 < n; i17++) {
        for (i18 = 0; i18 < 6; i18++) {
          aux_fitness_2->data[i18 + 6 * (i17 + loop_ub)] = fitness->data[i18 + 6
            * i17];
        }
      }

      /* 'aevSPLap:72' [~,idx_2] = sort(aux_fitness_2(:,1),'ascend'); */
      loop_ub = aux_fitness_2->size[0];
      i17 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_real_T(x, i17);
      for (i17 = 0; i17 < loop_ub; i17++) {
        x->data[i17] = aux_fitness_2->data[6 * i17];
      }

      c_sort(x, iidx);
      i17 = idx_2->size[0];
      idx_2->size[0] = iidx->size[0];
      emxEnsureCapacity_int32_T(idx_2, i17);
      loop_ub = iidx->size[0];
      for (i17 = 0; i17 < loop_ub; i17++) {
        idx_2->data[i17] = iidx->data[i17];
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

      i17 = b_aux_fitness_2->size[0] * b_aux_fitness_2->size[1];
      b_aux_fitness_2->size[1] = 6;
      b_aux_fitness_2->size[0] = idx_2->size[0];
      emxEnsureCapacity_real_T(b_aux_fitness_2, i17);
      n = idx_2->size[0];
      for (i17 = 0; i17 < n; i17++) {
        for (i18 = 0; i18 < 6; i18++) {
          b_aux_fitness_2->data[i18 + 6 * i17] = aux_fitness_2->data[i18 + 6 *
            (idx_2->data[i17] - 1)];
        }
      }

      i17 = fitness->size[0] * fitness->size[1];
      fitness->size[1] = 6;
      fitness->size[0] = loop_ub;
      emxEnsureCapacity_real_T(fitness, i17);
      for (i17 = 0; i17 < loop_ub; i17++) {
        for (i18 = 0; i18 < 6; i18++) {
          i20 = i18 + 6 * i17;
          fitness->data[i20] = b_aux_fitness_2->data[i20];
        }
      }

      /* 'aevSPLap:77' rank_classic = rank_classic_2(:,1:numIC); */
      if (1 > numIC) {
        loop_ub = 0;
      } else {
        loop_ub = numIC;
      }

      n = aux_classic_2->size[0] - 1;
      yk = aux_classic_2->size[0];
      i17 = b_PCPrO->size[0] * b_PCPrO->size[1];
      b_PCPrO->size[1] = idx_2->size[0];
      b_PCPrO->size[0] = yk;
      emxEnsureCapacity_int32_T(b_PCPrO, i17);
      for (i17 = 0; i17 < yk; i17++) {
        k = idx_2->size[0];
        for (i18 = 0; i18 < k; i18++) {
          b_PCPrO->data[i18 + b_PCPrO->size[1] * i17] = aux_classic_2->data
            [(idx_2->data[i18] + aux_classic_2->size[1] * i17) - 1];
        }
      }

      i17 = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[1] = loop_ub;
      rank_classic->size[0] = n + 1;
      emxEnsureCapacity_int32_T(rank_classic, i17);
      for (i17 = 0; i17 <= n; i17++) {
        for (i18 = 0; i18 < loop_ub; i18++) {
          rank_classic->data[i18 + rank_classic->size[1] * i17] = b_PCPrO->
            data[i18 + b_PCPrO->size[1] * i17];
        }
      }
    }

    /* REMOVE INDIVÍDUOS MAIS FRACOS (EXCEDENTES) */
    /* 'aevSPLap:83' IC = rank_classic; */
    /* 'aevSPLap:84' best = IC; */
    i17 = best->size[0] * best->size[1];
    best->size[1] = rank_classic->size[1];
    best->size[0] = rank_classic->size[0];
    emxEnsureCapacity_int32_T(best, i17);
    loop_ub = rank_classic->size[0];
    for (i17 = 0; i17 < loop_ub; i17++) {
      n = rank_classic->size[1];
      for (i18 = 0; i18 < n; i18++) {
        best->data[i18 + best->size[1] * i17] = rank_classic->data[i18 +
          rank_classic->size[1] * i17];
      }
    }

    /* 'aevSPLap:85' bestFitness = fitness; */
    i17 = bestFitness->size[0] * bestFitness->size[1];
    bestFitness->size[1] = 6;
    bestFitness->size[0] = fitness->size[0];
    emxEnsureCapacity_real_T(bestFitness, i17);
    loop_ub = fitness->size[0];
    for (i17 = 0; i17 < loop_ub; i17++) {
      for (i18 = 0; i18 < 6; i18++) {
        i20 = i18 + 6 * i17;
        bestFitness->data[i20] = fitness->data[i20];
      }
    }

    /*  GUARDA MELHOR INDIVÍDUO */
    /* 'aevSPLap:89' bestexperimento = IC(:,1); */
    loop_ub = rank_classic->size[0];
    i17 = bestexperimento->size[0];
    bestexperimento->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(bestexperimento, i17);
    for (i17 = 0; i17 < loop_ub; i17++) {
      bestexperimento->data[i17] = rank_classic->data[rank_classic->size[1] *
        i17];
    }

    /*  SALVA A GERAÇÃO, FITNESS do Melhor ind., a MÉDIA DO FITNESS e a STD DO FITNESS  */
    /* 'aevSPLap:93' trace(g,:) = [g,bestFitness(1,1),mean(bestFitness(:,1),1),std(bestFitness(:,1),1),bestFitness(1,2),bestFitness(1,3),bestFitness(1,4),bestFitness(1,5),bestFitness(1,6)]; */
    loop_ub = fitness->size[0];
    n = fitness->size[0];
    i17 = x->size[0];
    x->size[0] = loop_ub;
    emxEnsureCapacity_real_T(x, i17);
    for (i17 = 0; i17 < loop_ub; i17++) {
      x->data[i17] = fitness->data[6 * i17];
    }

    i17 = b_fitness->size[0];
    b_fitness->size[0] = n;
    emxEnsureCapacity_real_T(b_fitness, i17);
    for (i17 = 0; i17 < n; i17++) {
      b_fitness->data[i17] = fitness->data[6 * i17];
    }

    varargin_5 = mean(x);
    d1 = b_std(b_fitness);
    b_g[0] = 1 + g;
    b_g[1] = (int)rt_roundd(fitness->data[0]);
    b_g[2] = (int)rt_roundd(varargin_5);
    b_g[3] = (int)rt_roundd(d1);
    b_g[4] = (int)rt_roundd(fitness->data[1]);
    b_g[5] = (int)rt_roundd(fitness->data[2]);
    b_g[6] = (int)rt_roundd(fitness->data[3]);
    b_g[7] = (int)rt_roundd(fitness->data[4]);
    b_g[8] = (int)rt_roundd(fitness->data[5]);
    for (i17 = 0; i17 < 9; i17++) {
      trace->data[i17 + 9 * g] = b_g[i17];
    }

    /*  IMPRIME STATUS DA EVOLUÇÃO */
    /* 'aevSPLap:97' fprintf('Ger: %d - \t Ini: %10.5f - \t Best: %10.5f - \t Mean: %10.5f - \t STD: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t NOE2: %10.5f - \t NOE3: %10.5f \n',... */
    /* 'aevSPLap:98'                g,         fitnessB(1,1),      bestFitness(1,1),mean(bestFitness(:,1),1),std(bestFitness(:,1),1),bestFitness(1,2),bestFitness(1,3),bestFitness(1,4),bestFitness(1,5),bestFitness(1,6)); */
    loop_ub = fitness->size[0];
    i17 = x->size[0];
    x->size[0] = loop_ub;
    emxEnsureCapacity_real_T(x, i17);
    for (i17 = 0; i17 < loop_ub; i17++) {
      x->data[i17] = fitness->data[6 * i17];
    }

    varargin_5 = b_std(x);
    loop_ub = fitness->size[0];
    i17 = x->size[0];
    x->size[0] = loop_ub;
    emxEnsureCapacity_real_T(x, i17);
    for (i17 = 0; i17 < loop_ub; i17++) {
      x->data[i17] = fitness->data[6 * i17];
    }

    printf("Ger: %d - \t Ini: %10.5f - \t Best: %10.5f - \t Mean: %10.5f - \t STD: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t "
           "NOE2: %10.5f - \t NOE3: %10.5f \n", 1 + g, fitnessB[0],
           fitness->data[0], mean(x), varargin_5, fitness->data[1],
           fitness->data[2], fitness->data[3], fitness->data[4], fitness->data[5]);
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
      i17 = IQ->size[0] - NumTOp;
      if (1 > i17) {
        loop_ub = 0;
      } else {
        loop_ub = i17;
      }

      yk = tmpColumn->size[1];
      n = rank_classic->size[0];
      i17 = IC->size[0] * IC->size[1];
      IC->size[1] = yk;
      IC->size[0] = n;
      emxEnsureCapacity_int32_T(IC, i17);
      for (i17 = 0; i17 < n; i17++) {
        for (i18 = 0; i18 < yk; i18++) {
          IC->data[i18 + IC->size[1] * i17] = rank_classic->data[((int)
            tmpColumn->data[i18] + rank_classic->size[1] * i17) - 1];
        }
      }

      /* UNTITLED5 Summary of this function goes here */
      /*    Detailed explanation goes here */
      /* Convertir de numerico a representacion binaria. */
      /* 'actIQ:7' num2bin = zeros(size(IC,1)*size(IC,2),size(IC,1)); */
      n = rank_classic->size[0];
      i17 = rank_classic->size[0];
      result = (int)((double)i17 * (double)tmpColumn->size[1]);
      i17 = num2bin->size[0] * num2bin->size[1];
      num2bin->size[1] = n;
      num2bin->size[0] = result;
      emxEnsureCapacity_int8_T(num2bin, i17);
      for (i17 = 0; i17 < result; i17++) {
        for (i18 = 0; i18 < n; i18++) {
          num2bin->data[i18 + num2bin->size[1] * i17] = 0;
        }
      }

      /* 'actIQ:9' for i=1:size(num2bin,1) */
      i17 = rank_classic->size[0];
      i17 = (int)((double)i17 * (double)tmpColumn->size[1]);
      for (i = 0; i < i17; i++) {
        /* 'actIQ:10' num2bin(i,IC(i))=1; */
        i18 = rank_classic->size[0];
        i20 = tmpColumn->size[1];
        num2bin->data[(IC->data[i % i18 * i20 + i / i18] + num2bin->size[1] * i)
          - 1] = 1;
      }

      /* 'actIQ:13' IQact = (1-taxAct)*IQ+taxAct*num2bin; */
      /* %%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%% */
      /* 'aevSPLap:115' IQ(1:end-NumTOp,:)=IQtemp; */
      n = IQ->size[1] - 1;
      i17 = r12->size[0] * r12->size[1];
      r12->size[1] = n + 1;
      r12->size[0] = loop_ub;
      emxEnsureCapacity_real_T(r12, i17);
      for (i17 = 0; i17 < loop_ub; i17++) {
        for (i18 = 0; i18 <= n; i18++) {
          r12->data[i18 + r12->size[1] * i17] = 0.99999 * IQ->data[i18 +
            IQ->size[1] * i17] + 1.0E-5 * (double)num2bin->data[i18 +
            num2bin->size[1] * i17];
        }
      }

      loop_ub = r12->size[0];
      for (i17 = 0; i17 < loop_ub; i17++) {
        n = r12->size[1];
        for (i18 = 0; i18 < n; i18++) {
          IQ->data[i18 + IQ->size[1] * i17] = r12->data[i18 + r12->size[1] * i17];
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
  emxFree_real_T(&r12);
  emxFree_real_T(&b_fitness);
  emxFree_real_T(&b_aux_fitness_2);
  emxFree_int8_T(&num2bin);
  emxFreeMatrix_cell_wrap_0(b_reshapes);
  emxFree_int32_T(&iidx);
  emxFree_real_T(&x);
  emxFreeMatrix_cell_wrap_0(reshapes);
  emxFree_int32_T(&r11);
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
