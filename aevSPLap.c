/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * aevSPLap.c
 *
 * Code generation for function 'aevSPLap'
 *
 */

/* Include files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "aevSPLap.h"
#include "model_emxutil.h"
#include "obsIQini.h"
#include "obsIQ.h"
#include "rand.h"
#include "cc.h"
#include "std.h"
#include "mean.h"
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
  int kEnd;
  int i9;
  emxArray_int32_T *rank_classic;
  emxArray_real_T *bestFitness;
  int n;
  emxArray_int32_T *idx;
  int yk;
  int k;
  emxArray_real_T *fitness;
  emxArray_int32_T *aux_classic_2;
  emxArray_real_T *aux_fitness_2;
  emxArray_real_T *tmpColumn;
  cell_wrap_0 reshapes[2];
  emxArray_real_T *x;
  cell_wrap_0 b_reshapes[2];
  emxArray_int32_T *iwork;
  emxArray_int32_T *b_IC;
  emxArray_int8_T *num2bin;
  emxArray_int32_T *b_rank_classic;
  emxArray_real_T *b_fitness;
  emxArray_real_T *r3;
  emxArray_real_T *c_fitness;
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
  double varargin_4;
  int pEnd;
  boolean_T empty_non_axis_sizes;
  signed char input_sizes_idx_1;
  int q;
  int qEnd;
  int p;
  double d0;
  double varargin_5;
  double d1;
  double d2;
  double d3;
  int i;
  emxInit_real_T(&IQ, 2);

  /*  INICIALIZA POPULAÇÃO QUANTICA.  */
  CreaPoQunniforme(NumTOp, numIQ, IQ);

  /*  IQ uniforme */
  /*  INICIALIZA POPULAÇÃO CLÁSSICA. */
  if (b_rem(numIC, numIQ) == 0) {
    numObsIQ = rdivide_helper(numIC, numIQ);
  }

  tic();
  emxInit_int32_T(&IC, 2);
  if (keeppriority) {
    obsIQini(IQ, numIQ, numObsIQ, ProbXEst, IC);

    /*  Observaciones de los IQ garantizando que se mantengan en el rango Prioridad             */
  } else {
    obsIQ(IQ, numIQ, numObsIQ, IC);

    /*  Observaciones de los IQ */
  }

  toc();

  /*  PARÂMETROS DE INTERESSE */
  kEnd = IC->size[0];
  i9 = bestexperimento->size[0];
  bestexperimento->size[0] = kEnd;
  emxEnsureCapacity_int32_T(bestexperimento, i9);
  for (i9 = 0; i9 < kEnd; i9++) {
    bestexperimento->data[i9] = IC->data[i9];
  }

  emxInit_int32_T(&rank_classic, 2);
  i9 = rank_classic->size[0] * rank_classic->size[1];
  rank_classic->size[0] = NumTOp;
  rank_classic->size[1] = numIC;
  emxEnsureCapacity_int32_T(rank_classic, i9);
  kEnd = NumTOp * numIC;
  for (i9 = 0; i9 < kEnd; i9++) {
    rank_classic->data[i9] = 0;
  }

  emxInit_real_T(&bestFitness, 2);
  i9 = bestFitness->size[0] * bestFitness->size[1];
  bestFitness->size[0] = numIC;
  bestFitness->size[1] = 6;
  emxEnsureCapacity_real_T(bestFitness, i9);
  kEnd = numIC * 6;
  for (i9 = 0; i9 < kEnd; i9++) {
    bestFitness->data[i9] = 0.0;
  }

  if (NumTOp < 1) {
    n = 0;
  } else {
    n = NumTOp;
  }

  emxInit_int32_T(&idx, 2);
  i9 = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = n;
  emxEnsureCapacity_int32_T(idx, i9);
  if (n > 0) {
    idx->data[0] = 1;
    yk = 1;
    for (k = 2; k <= n; k++) {
      yk++;
      idx->data[k - 1] = yk;
    }
  }

  kEnd = idx->size[1];
  for (i9 = 0; i9 < kEnd; i9++) {
    rank_classic->data[i9] = idx->data[i9];
  }

  for (i9 = 0; i9 < 6; i9++) {
    bestFitness->data[bestFitness->size[0] * i9] = fitnessB[i9];
  }

  /*  INICIALIZA LOOPING */
  i9 = trace->size[0] * trace->size[1];
  trace->size[0] = generations;
  trace->size[1] = 9;
  emxEnsureCapacity_real_T(trace, i9);
  emxInit_real_T(&fitness, 2);
  emxInit_int32_T(&aux_classic_2, 2);
  emxInit_real_T(&aux_fitness_2, 2);
  emxInit_real_T(&tmpColumn, 2);
  emxInitMatrix_cell_wrap_0(reshapes);
  emxInit_real_T(&x, 1);
  emxInitMatrix_cell_wrap_0(b_reshapes);
  emxInit_int32_T(&iwork, 1);
  emxInit_int32_T(&b_IC, 2);
  emxInit_int8_T(&num2bin, 2);
  emxInit_int32_T(&b_rank_classic, 2);
  emxInit_real_T(&b_fitness, 1);
  emxInit_real_T(&r3, 2);
  emxInit_real_T(&c_fitness, 2);
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
    i9 = fitness->size[0] * fitness->size[1];
    fitness->size[0] = numIC;
    fitness->size[1] = 6;
    emxEnsureCapacity_real_T(fitness, i9);
    kEnd = numIC * 6;
    for (i9 = 0; i9 < kEnd; i9++) {
      fitness->data[i9] = 0.0;
    }

    /*  [fitness,NOFP,TmNOFP,NOE2,NOE3] */
    for (j = 0; j < numIC; j++) {
      kEnd = IC->size[0];
      i9 = iwork->size[0];
      iwork->size[0] = kEnd;
      emxEnsureCapacity_int32_T(iwork, i9);
      for (i9 = 0; i9 < kEnd; i9++) {
        iwork->data[i9] = IC->data[i9 + IC->size[0] * j];
      }

      i9 = b_PCPrO->size[0] * b_PCPrO->size[1];
      b_PCPrO->size[0] = PCPrO->size[0];
      b_PCPrO->size[1] = PCPrO->size[1];
      emxEnsureCapacity_int32_T(b_PCPrO, i9);
      kEnd = PCPrO->size[0] * PCPrO->size[1];
      for (i9 = 0; i9 < kEnd; i9++) {
        b_PCPrO->data[i9] = PCPrO->data[i9];
      }

      i9 = b_PME->size[0] * b_PME->size[1];
      b_PME->size[0] = PME->size[0];
      b_PME->size[1] = PME->size[1];
      emxEnsureCapacity_int32_T(b_PME, i9);
      kEnd = PME->size[0] * PME->size[1];
      for (i9 = 0; i9 < kEnd; i9++) {
        b_PME->data[i9] = PME->data[i9];
      }

      i9 = b_PMA->size[0] * b_PMA->size[1];
      b_PMA->size[0] = PMA->size[0];
      b_PMA->size[1] = PMA->size[1];
      emxEnsureCapacity_int32_T(b_PMA, i9);
      kEnd = PMA->size[0] * PMA->size[1];
      for (i9 = 0; i9 < kEnd; i9++) {
        b_PMA->data[i9] = PMA->data[i9];
      }

      i9 = b_PMAn->size[0] * b_PMAn->size[1];
      b_PMAn->size[0] = PMAn->size[0];
      b_PMAn->size[1] = PMAn->size[1];
      emxEnsureCapacity_int32_T(b_PMAn, i9);
      kEnd = PMAn->size[0] * PMAn->size[1];
      for (i9 = 0; i9 < kEnd; i9++) {
        b_PMAn->data[i9] = PMAn->data[i9];
      }

      i9 = b_PS->size[0] * b_PS->size[1];
      b_PS->size[0] = PS->size[0];
      b_PS->size[1] = PS->size[1];
      emxEnsureCapacity_int32_T(b_PS, i9);
      kEnd = PS->size[0] * PS->size[1];
      for (i9 = 0; i9 < kEnd; i9++) {
        b_PS->data[i9] = PS->data[i9];
      }

      i9 = b_PCPO->size[0] * b_PCPO->size[1];
      b_PCPO->size[0] = PCPO->size[0];
      b_PCPO->size[1] = PCPO->size[1];
      emxEnsureCapacity_int32_T(b_PCPO, i9);
      kEnd = PCPO->size[0] * PCPO->size[1];
      for (i9 = 0; i9 < kEnd; i9++) {
        b_PCPO->data[i9] = PCPO->data[i9];
      }

      i9 = b_PCR->size[0] * b_PCR->size[1];
      b_PCR->size[0] = PCR->size[0];
      b_PCR->size[1] = PCR->size[1];
      emxEnsureCapacity_int32_T(b_PCR, i9);
      kEnd = PCR->size[0] * PCR->size[1];
      for (i9 = 0; i9 < kEnd; i9++) {
        b_PCR->data[i9] = PCR->data[i9];
      }

      i9 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
      b_TimeUsoRec->size[0] = TimeUsoRec->size[0];
      b_TimeUsoRec->size[1] = 7;
      emxEnsureCapacity_int32_T(b_TimeUsoRec, i9);
      kEnd = TimeUsoRec->size[0] * TimeUsoRec->size[1];
      for (i9 = 0; i9 < kEnd; i9++) {
        b_TimeUsoRec->data[i9] = TimeUsoRec->data[i9];
      }

      i9 = b_EP->size[0];
      b_EP->size[0] = EP->size[0];
      emxEnsureCapacity_int32_T(b_EP, i9);
      kEnd = EP->size[0];
      for (i9 = 0; i9 < kEnd; i9++) {
        b_EP->data[i9] = EP->data[i9];
      }

      sch(NumTOp, iwork, NumRec, b_PCPrO, b_PME, b_PMA, b_PMAn, b_PS, b_PCPO,
          b_PCR, Dia, Data, b_TimeUsoRec, DispMExD, b_EP, k0, k1, k2, k3, &d0,
          &varargin_4, &varargin_5, &d1, &d2, &d3);
      fitness->data[j] = d0;
      fitness->data[j + fitness->size[0]] = varargin_4;
      fitness->data[j + (fitness->size[0] << 1)] = varargin_5;
      fitness->data[j + fitness->size[0] * 3] = d1;
      fitness->data[j + (fitness->size[0] << 2)] = d2;
      fitness->data[j + fitness->size[0] * 5] = d3;
    }

    /*     save(strcat('fitness_', int2str(g),'.mat'),'fitness'); */
    /*     file = load(strcat('fitness_', int2str(g),'.mat')); */
    /*     fitness = file.fitness; */
    /* ATUALIZA POPULAÇÃO B(T) */
    if (1 + g == 1) {
      i9 = rank_classic->size[0];
      if (i9 != 0) {
        pEnd = rank_classic->size[0];
      } else if ((IC->size[0] != 0) && (IC->size[1] != 0)) {
        pEnd = IC->size[0];
      } else {
        i9 = rank_classic->size[0];
        if (i9 > 0) {
          pEnd = rank_classic->size[0];
        } else {
          pEnd = 0;
        }

        if (IC->size[0] > pEnd) {
          pEnd = IC->size[0];
        }
      }

      empty_non_axis_sizes = (pEnd == 0);
      if (empty_non_axis_sizes) {
        input_sizes_idx_1 = 1;
      } else {
        i9 = rank_classic->size[0];
        if (i9 != 0) {
          input_sizes_idx_1 = 1;
        } else {
          input_sizes_idx_1 = 0;
        }
      }

      kEnd = rank_classic->size[0];
      i9 = iwork->size[0];
      iwork->size[0] = kEnd;
      emxEnsureCapacity_int32_T(iwork, i9);
      for (i9 = 0; i9 < kEnd; i9++) {
        iwork->data[i9] = rank_classic->data[i9];
      }

      i9 = b_reshapes[0].f1->size[0] * b_reshapes[0].f1->size[1];
      b_reshapes[0].f1->size[0] = pEnd;
      b_reshapes[0].f1->size[1] = input_sizes_idx_1;
      emxEnsureCapacity_int32_T(b_reshapes[0].f1, i9);
      kEnd = pEnd * input_sizes_idx_1;
      for (i9 = 0; i9 < kEnd; i9++) {
        b_reshapes[0].f1->data[i9] = iwork->data[i9];
      }

      if (empty_non_axis_sizes || ((IC->size[0] != 0) && (IC->size[1] != 0))) {
        kEnd = IC->size[1];
      } else {
        kEnd = 0;
      }

      i9 = aux_classic_2->size[0] * aux_classic_2->size[1];
      aux_classic_2->size[0] = b_reshapes[0].f1->size[0];
      aux_classic_2->size[1] = b_reshapes[0].f1->size[1] + kEnd;
      emxEnsureCapacity_int32_T(aux_classic_2, i9);
      q = b_reshapes[0].f1->size[1];
      for (i9 = 0; i9 < q; i9++) {
        p = b_reshapes[0].f1->size[0];
        for (qEnd = 0; qEnd < p; qEnd++) {
          aux_classic_2->data[qEnd + aux_classic_2->size[0] * i9] = b_reshapes[0]
            .f1->data[qEnd + b_reshapes[0].f1->size[0] * i9];
        }
      }

      for (i9 = 0; i9 < kEnd; i9++) {
        for (qEnd = 0; qEnd < pEnd; qEnd++) {
          aux_classic_2->data[qEnd + aux_classic_2->size[0] * (i9 + b_reshapes[0]
            .f1->size[1])] = IC->data[qEnd + pEnd * i9];
        }
      }

      i9 = aux_fitness_2->size[0] * aux_fitness_2->size[1];
      aux_fitness_2->size[0] = 1 + fitness->size[0];
      aux_fitness_2->size[1] = 6;
      emxEnsureCapacity_real_T(aux_fitness_2, i9);
      for (i9 = 0; i9 < 6; i9++) {
        aux_fitness_2->data[aux_fitness_2->size[0] * i9] = bestFitness->
          data[bestFitness->size[0] * i9];
      }

      for (i9 = 0; i9 < 6; i9++) {
        kEnd = fitness->size[0];
        for (qEnd = 0; qEnd < kEnd; qEnd++) {
          aux_fitness_2->data[(qEnd + aux_fitness_2->size[0] * i9) + 1] =
            fitness->data[qEnd + fitness->size[0] * i9];
        }
      }

      kEnd = aux_fitness_2->size[0];
      i9 = x->size[0];
      x->size[0] = kEnd;
      emxEnsureCapacity_real_T(x, i9);
      for (i9 = 0; i9 < kEnd; i9++) {
        x->data[i9] = aux_fitness_2->data[i9];
      }

      c_sort(x, iwork);
      i9 = x->size[0];
      x->size[0] = iwork->size[0];
      emxEnsureCapacity_real_T(x, i9);
      kEnd = iwork->size[0];
      for (i9 = 0; i9 < kEnd; i9++) {
        x->data[i9] = iwork->data[i9];
      }

      if (1 > numIC) {
        kEnd = 0;
      } else {
        kEnd = numIC;
      }

      i9 = fitness->size[0] * fitness->size[1];
      fitness->size[0] = x->size[0];
      fitness->size[1] = 6;
      emxEnsureCapacity_real_T(fitness, i9);
      for (i9 = 0; i9 < 6; i9++) {
        q = x->size[0];
        for (qEnd = 0; qEnd < q; qEnd++) {
          fitness->data[qEnd + fitness->size[0] * i9] = aux_fitness_2->data
            [((int)x->data[qEnd] + aux_fitness_2->size[0] * i9) - 1];
        }
      }

      i9 = c_fitness->size[0] * c_fitness->size[1];
      c_fitness->size[0] = kEnd;
      c_fitness->size[1] = 6;
      emxEnsureCapacity_real_T(c_fitness, i9);
      for (i9 = 0; i9 < 6; i9++) {
        for (qEnd = 0; qEnd < kEnd; qEnd++) {
          c_fitness->data[qEnd + c_fitness->size[0] * i9] = fitness->data[qEnd +
            fitness->size[0] * i9];
        }
      }

      i9 = fitness->size[0] * fitness->size[1];
      fitness->size[0] = c_fitness->size[0];
      fitness->size[1] = 6;
      emxEnsureCapacity_real_T(fitness, i9);
      for (i9 = 0; i9 < 6; i9++) {
        kEnd = c_fitness->size[0];
        for (qEnd = 0; qEnd < kEnd; qEnd++) {
          fitness->data[qEnd + fitness->size[0] * i9] = c_fitness->data[qEnd +
            c_fitness->size[0] * i9];
        }
      }

      if (1 > numIC) {
        kEnd = 0;
      } else {
        kEnd = numIC;
      }

      q = aux_classic_2->size[0] - 1;
      p = aux_classic_2->size[0];
      i9 = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[0] = p;
      rank_classic->size[1] = x->size[0];
      emxEnsureCapacity_int32_T(rank_classic, i9);
      yk = x->size[0];
      for (i9 = 0; i9 < yk; i9++) {
        for (qEnd = 0; qEnd < p; qEnd++) {
          rank_classic->data[qEnd + rank_classic->size[0] * i9] =
            aux_classic_2->data[qEnd + aux_classic_2->size[0] * ((int)x->data[i9]
            - 1)];
        }
      }

      i9 = IC->size[0] * IC->size[1];
      IC->size[0] = q + 1;
      IC->size[1] = kEnd;
      emxEnsureCapacity_int32_T(IC, i9);
      for (i9 = 0; i9 < kEnd; i9++) {
        for (qEnd = 0; qEnd <= q; qEnd++) {
          IC->data[qEnd + IC->size[0] * i9] = rank_classic->data[qEnd +
            rank_classic->size[0] * i9];
        }
      }

      i9 = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[0] = IC->size[0];
      rank_classic->size[1] = IC->size[1];
      emxEnsureCapacity_int32_T(rank_classic, i9);
      kEnd = IC->size[1];
      for (i9 = 0; i9 < kEnd; i9++) {
        q = IC->size[0];
        for (qEnd = 0; qEnd < q; qEnd++) {
          rank_classic->data[qEnd + rank_classic->size[0] * i9] = IC->data[qEnd
            + IC->size[0] * i9];
        }
      }
    } else {
      varargin_4 = rt_roundd((double)numIC * taxE);
      if (varargin_4 < 2.147483648E+9) {
        if (varargin_4 >= -2.147483648E+9) {
          i9 = (int)varargin_4;
        } else {
          i9 = MIN_int32_T;
        }
      } else {
        i9 = MAX_int32_T;
      }

      i9 = (int)rt_roundd((double)i9 / 100.0);
      if (1 > i9) {
        kEnd = 0;
      } else {
        kEnd = i9;
      }

      i9 = rank_classic->size[0];
      if ((i9 != 0) && (kEnd != 0)) {
        pEnd = rank_classic->size[0];
      } else if ((IC->size[0] != 0) && (IC->size[1] != 0)) {
        pEnd = IC->size[0];
      } else {
        i9 = rank_classic->size[0];
        if (i9 > 0) {
          pEnd = rank_classic->size[0];
        } else {
          pEnd = 0;
        }

        if (IC->size[0] > pEnd) {
          pEnd = IC->size[0];
        }
      }

      empty_non_axis_sizes = (pEnd == 0);
      if (empty_non_axis_sizes) {
        yk = kEnd;
      } else {
        i9 = rank_classic->size[0];
        if ((i9 != 0) && (kEnd != 0)) {
          yk = kEnd;
        } else {
          yk = 0;
        }
      }

      q = rank_classic->size[0];
      i9 = b_rank_classic->size[0] * b_rank_classic->size[1];
      b_rank_classic->size[0] = q;
      b_rank_classic->size[1] = kEnd;
      emxEnsureCapacity_int32_T(b_rank_classic, i9);
      for (i9 = 0; i9 < kEnd; i9++) {
        for (qEnd = 0; qEnd < q; qEnd++) {
          b_rank_classic->data[qEnd + b_rank_classic->size[0] * i9] =
            rank_classic->data[qEnd + rank_classic->size[0] * i9];
        }
      }

      i9 = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
      reshapes[0].f1->size[0] = pEnd;
      reshapes[0].f1->size[1] = yk;
      emxEnsureCapacity_int32_T(reshapes[0].f1, i9);
      kEnd = pEnd * yk;
      for (i9 = 0; i9 < kEnd; i9++) {
        reshapes[0].f1->data[i9] = b_rank_classic->data[i9];
      }

      if (empty_non_axis_sizes || ((IC->size[0] != 0) && (IC->size[1] != 0))) {
        kEnd = IC->size[1];
      } else {
        kEnd = 0;
      }

      i9 = aux_classic_2->size[0] * aux_classic_2->size[1];
      aux_classic_2->size[0] = reshapes[0].f1->size[0];
      aux_classic_2->size[1] = reshapes[0].f1->size[1] + kEnd;
      emxEnsureCapacity_int32_T(aux_classic_2, i9);
      q = reshapes[0].f1->size[1];
      for (i9 = 0; i9 < q; i9++) {
        p = reshapes[0].f1->size[0];
        for (qEnd = 0; qEnd < p; qEnd++) {
          aux_classic_2->data[qEnd + aux_classic_2->size[0] * i9] = reshapes[0].
            f1->data[qEnd + reshapes[0].f1->size[0] * i9];
        }
      }

      for (i9 = 0; i9 < kEnd; i9++) {
        for (qEnd = 0; qEnd < pEnd; qEnd++) {
          aux_classic_2->data[qEnd + aux_classic_2->size[0] * (i9 + reshapes[0].
            f1->size[1])] = IC->data[qEnd + pEnd * i9];
        }
      }

      if (varargin_4 < 2.147483648E+9) {
        if (varargin_4 >= -2.147483648E+9) {
          i9 = (int)varargin_4;
        } else {
          i9 = MIN_int32_T;
        }
      } else {
        i9 = MAX_int32_T;
      }

      i9 = (int)rt_roundd((double)i9 / 100.0);
      if (1 > i9) {
        kEnd = 0;
      } else {
        kEnd = i9;
      }

      i9 = aux_fitness_2->size[0] * aux_fitness_2->size[1];
      aux_fitness_2->size[0] = kEnd + fitness->size[0];
      aux_fitness_2->size[1] = 6;
      emxEnsureCapacity_real_T(aux_fitness_2, i9);
      for (i9 = 0; i9 < 6; i9++) {
        for (qEnd = 0; qEnd < kEnd; qEnd++) {
          aux_fitness_2->data[qEnd + aux_fitness_2->size[0] * i9] =
            bestFitness->data[qEnd + bestFitness->size[0] * i9];
        }
      }

      for (i9 = 0; i9 < 6; i9++) {
        q = fitness->size[0];
        for (qEnd = 0; qEnd < q; qEnd++) {
          aux_fitness_2->data[(qEnd + kEnd) + aux_fitness_2->size[0] * i9] =
            fitness->data[qEnd + fitness->size[0] * i9];
        }
      }

      kEnd = aux_fitness_2->size[0];
      i9 = x->size[0];
      x->size[0] = kEnd;
      emxEnsureCapacity_real_T(x, i9);
      for (i9 = 0; i9 < kEnd; i9++) {
        x->data[i9] = aux_fitness_2->data[i9];
      }

      c_sort(x, iwork);
      i9 = x->size[0];
      x->size[0] = iwork->size[0];
      emxEnsureCapacity_real_T(x, i9);
      kEnd = iwork->size[0];
      for (i9 = 0; i9 < kEnd; i9++) {
        x->data[i9] = iwork->data[i9];
      }

      if (1 > numIC) {
        kEnd = 0;
      } else {
        kEnd = numIC;
      }

      i9 = fitness->size[0] * fitness->size[1];
      fitness->size[0] = x->size[0];
      fitness->size[1] = 6;
      emxEnsureCapacity_real_T(fitness, i9);
      for (i9 = 0; i9 < 6; i9++) {
        q = x->size[0];
        for (qEnd = 0; qEnd < q; qEnd++) {
          fitness->data[qEnd + fitness->size[0] * i9] = aux_fitness_2->data
            [((int)x->data[qEnd] + aux_fitness_2->size[0] * i9) - 1];
        }
      }

      i9 = c_fitness->size[0] * c_fitness->size[1];
      c_fitness->size[0] = kEnd;
      c_fitness->size[1] = 6;
      emxEnsureCapacity_real_T(c_fitness, i9);
      for (i9 = 0; i9 < 6; i9++) {
        for (qEnd = 0; qEnd < kEnd; qEnd++) {
          c_fitness->data[qEnd + c_fitness->size[0] * i9] = fitness->data[qEnd +
            fitness->size[0] * i9];
        }
      }

      i9 = fitness->size[0] * fitness->size[1];
      fitness->size[0] = c_fitness->size[0];
      fitness->size[1] = 6;
      emxEnsureCapacity_real_T(fitness, i9);
      for (i9 = 0; i9 < 6; i9++) {
        kEnd = c_fitness->size[0];
        for (qEnd = 0; qEnd < kEnd; qEnd++) {
          fitness->data[qEnd + fitness->size[0] * i9] = c_fitness->data[qEnd +
            c_fitness->size[0] * i9];
        }
      }

      if (1 > numIC) {
        kEnd = 0;
      } else {
        kEnd = numIC;
      }

      q = aux_classic_2->size[0] - 1;
      p = aux_classic_2->size[0];
      i9 = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[0] = p;
      rank_classic->size[1] = x->size[0];
      emxEnsureCapacity_int32_T(rank_classic, i9);
      yk = x->size[0];
      for (i9 = 0; i9 < yk; i9++) {
        for (qEnd = 0; qEnd < p; qEnd++) {
          rank_classic->data[qEnd + rank_classic->size[0] * i9] =
            aux_classic_2->data[qEnd + aux_classic_2->size[0] * ((int)x->data[i9]
            - 1)];
        }
      }

      i9 = IC->size[0] * IC->size[1];
      IC->size[0] = q + 1;
      IC->size[1] = kEnd;
      emxEnsureCapacity_int32_T(IC, i9);
      for (i9 = 0; i9 < kEnd; i9++) {
        for (qEnd = 0; qEnd <= q; qEnd++) {
          IC->data[qEnd + IC->size[0] * i9] = rank_classic->data[qEnd +
            rank_classic->size[0] * i9];
        }
      }

      i9 = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[0] = IC->size[0];
      rank_classic->size[1] = IC->size[1];
      emxEnsureCapacity_int32_T(rank_classic, i9);
      kEnd = IC->size[1];
      for (i9 = 0; i9 < kEnd; i9++) {
        q = IC->size[0];
        for (qEnd = 0; qEnd < q; qEnd++) {
          rank_classic->data[qEnd + rank_classic->size[0] * i9] = IC->data[qEnd
            + IC->size[0] * i9];
        }
      }
    }

    /* REMOVE INDIVÍDUOS MAIS FRACOS (EXCEDENTES) */
    i9 = bestFitness->size[0] * bestFitness->size[1];
    bestFitness->size[0] = fitness->size[0];
    bestFitness->size[1] = 6;
    emxEnsureCapacity_real_T(bestFitness, i9);
    kEnd = fitness->size[0] * fitness->size[1];
    for (i9 = 0; i9 < kEnd; i9++) {
      bestFitness->data[i9] = fitness->data[i9];
    }

    /*  GUARDA MELHOR INDIVÍDUO */
    kEnd = rank_classic->size[0];
    i9 = bestexperimento->size[0];
    bestexperimento->size[0] = kEnd;
    emxEnsureCapacity_int32_T(bestexperimento, i9);
    for (i9 = 0; i9 < kEnd; i9++) {
      bestexperimento->data[i9] = rank_classic->data[i9];
    }

    /*  SALVA A GERAÇÃO, FITNESS do Melhor ind., a MÉDIA DO FITNESS e a STD DO FITNESS  */
    kEnd = fitness->size[0];
    i9 = x->size[0];
    x->size[0] = kEnd;
    emxEnsureCapacity_real_T(x, i9);
    for (i9 = 0; i9 < kEnd; i9++) {
      x->data[i9] = fitness->data[i9];
    }

    kEnd = fitness->size[0];
    i9 = b_fitness->size[0];
    b_fitness->size[0] = kEnd;
    emxEnsureCapacity_real_T(b_fitness, i9);
    for (i9 = 0; i9 < kEnd; i9++) {
      b_fitness->data[i9] = fitness->data[i9];
    }

    varargin_4 = mean(x);
    varargin_5 = b_std(b_fitness);
    trace->data[g] = 1 + g;
    d1 = rt_roundd(fitness->data[0]);
    if (d1 < 2.147483648E+9) {
      if (d1 >= -2.147483648E+9) {
        i9 = (int)d1;
      } else {
        i9 = MIN_int32_T;
      }
    } else {
      i9 = MAX_int32_T;
    }

    trace->data[g + trace->size[0]] = i9;
    varargin_4 = rt_roundd(varargin_4);
    if (varargin_4 < 2.147483648E+9) {
      if (varargin_4 >= -2.147483648E+9) {
        i9 = (int)varargin_4;
      } else {
        i9 = MIN_int32_T;
      }
    } else {
      i9 = MAX_int32_T;
    }

    trace->data[g + (trace->size[0] << 1)] = i9;
    varargin_4 = rt_roundd(varargin_5);
    if (varargin_4 < 2.147483648E+9) {
      if (varargin_4 >= -2.147483648E+9) {
        i9 = (int)varargin_4;
      } else {
        i9 = MIN_int32_T;
      }
    } else {
      i9 = MAX_int32_T;
    }

    trace->data[g + trace->size[0] * 3] = i9;
    varargin_4 = rt_roundd(fitness->data[fitness->size[0]]);
    if (varargin_4 < 2.147483648E+9) {
      if (varargin_4 >= -2.147483648E+9) {
        i9 = (int)varargin_4;
      } else {
        i9 = MIN_int32_T;
      }
    } else {
      i9 = MAX_int32_T;
    }

    trace->data[g + (trace->size[0] << 2)] = i9;
    varargin_4 = rt_roundd(fitness->data[fitness->size[0] << 1]);
    if (varargin_4 < 2.147483648E+9) {
      if (varargin_4 >= -2.147483648E+9) {
        i9 = (int)varargin_4;
      } else {
        i9 = MIN_int32_T;
      }
    } else {
      i9 = MAX_int32_T;
    }

    trace->data[g + trace->size[0] * 5] = i9;
    varargin_4 = rt_roundd(fitness->data[fitness->size[0] * 3]);
    if (varargin_4 < 2.147483648E+9) {
      if (varargin_4 >= -2.147483648E+9) {
        i9 = (int)varargin_4;
      } else {
        i9 = MIN_int32_T;
      }
    } else {
      i9 = MAX_int32_T;
    }

    trace->data[g + trace->size[0] * 6] = i9;
    varargin_4 = rt_roundd(fitness->data[fitness->size[0] << 2]);
    if (varargin_4 < 2.147483648E+9) {
      if (varargin_4 >= -2.147483648E+9) {
        i9 = (int)varargin_4;
      } else {
        i9 = MIN_int32_T;
      }
    } else {
      i9 = MAX_int32_T;
    }

    trace->data[g + trace->size[0] * 7] = i9;
    varargin_4 = rt_roundd(fitness->data[fitness->size[0] * 5]);
    if (varargin_4 < 2.147483648E+9) {
      if (varargin_4 >= -2.147483648E+9) {
        i9 = (int)varargin_4;
      } else {
        i9 = MIN_int32_T;
      }
    } else {
      i9 = MAX_int32_T;
    }

    trace->data[g + (trace->size[0] << 3)] = i9;

    /*  IMPRIME STATUS DA EVOLUÇÃO */
    kEnd = fitness->size[0];
    i9 = x->size[0];
    x->size[0] = kEnd;
    emxEnsureCapacity_real_T(x, i9);
    for (i9 = 0; i9 < kEnd; i9++) {
      x->data[i9] = fitness->data[i9];
    }

    varargin_4 = mean(x);
    kEnd = fitness->size[0];
    i9 = x->size[0];
    x->size[0] = kEnd;
    emxEnsureCapacity_real_T(x, i9);
    for (i9 = 0; i9 < kEnd; i9++) {
      x->data[i9] = fitness->data[i9];
    }

    varargin_5 = b_std(x);
    printf("Ger: %d - \t Ini: %10.5f - \t Best: %10.5f - \t Mean: %10.5f - \t STD: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t "
           "NOE2: %10.5f - \t NOE3: %10.5f \n", 1 + g, fitnessB[0],
           fitness->data[0], varargin_4, varargin_5, fitness->data[fitness->
           size[0]], fitness->data[fitness->size[0] << 1], fitness->data
           [fitness->size[0] * 3], fitness->data[fitness->size[0] << 2],
           fitness->data[fitness->size[0] * 5]);
    fflush(stdout);

    /*  REPOSICIONA PULSOS DE ACORDO COM MELHORES INDIVÍDUOS */
    if (genToWidth == 0) {
      yk = 0;
    } else {
      yk = (g - genToWidth * div_s32(1 + g, genToWidth)) + 1;
    }

    if (yk == 0) {
      /*  QUANTUM UPDATE */
      if (numIQ < -2147483647) {
        yk = MIN_int32_T;
      } else {
        yk = numIQ - 1;
      }

      i_rand(yk, tmpColumn);
      n = tmpColumn->size[1] + 1;
      i9 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = tmpColumn->size[1];
      emxEnsureCapacity_int32_T(idx, i9);
      kEnd = tmpColumn->size[1];
      for (i9 = 0; i9 < kEnd; i9++) {
        idx->data[i9] = 0;
      }

      if (tmpColumn->size[1] != 0) {
        i9 = iwork->size[0];
        iwork->size[0] = tmpColumn->size[1];
        emxEnsureCapacity_int32_T(iwork, i9);
        i9 = tmpColumn->size[1] - 1;
        for (k = 1; k <= i9; k += 2) {
          if (tmpColumn->data[k - 1] <= tmpColumn->data[k]) {
            idx->data[k - 1] = k;
            idx->data[k] = k + 1;
          } else {
            idx->data[k - 1] = k + 1;
            idx->data[k] = k;
          }
        }

        if ((tmpColumn->size[1] & 1) != 0) {
          idx->data[tmpColumn->size[1] - 1] = tmpColumn->size[1];
        }

        i = 2;
        while (i < n - 1) {
          yk = i << 1;
          j = 1;
          for (pEnd = 1 + i; pEnd < n; pEnd = qEnd + i) {
            p = j;
            q = pEnd;
            qEnd = j + yk;
            if (qEnd > n) {
              qEnd = n;
            }

            k = 0;
            kEnd = qEnd - j;
            while (k + 1 <= kEnd) {
              if (tmpColumn->data[idx->data[p - 1] - 1] <= tmpColumn->data
                  [idx->data[q - 1] - 1]) {
                iwork->data[k] = idx->data[p - 1];
                p++;
                if (p == pEnd) {
                  while (q < qEnd) {
                    k++;
                    iwork->data[k] = idx->data[q - 1];
                    q++;
                  }
                }
              } else {
                iwork->data[k] = idx->data[q - 1];
                q++;
                if (q == qEnd) {
                  while (p < pEnd) {
                    k++;
                    iwork->data[k] = idx->data[p - 1];
                    p++;
                  }
                }
              }

              k++;
            }

            for (k = 0; k < kEnd; k++) {
              idx->data[(j + k) - 1] = iwork->data[k];
            }

            j = qEnd;
          }

          i = yk;
        }
      }

      yk = tmpColumn->size[0];
      pEnd = tmpColumn->size[1];
      i9 = tmpColumn->size[0] * tmpColumn->size[1];
      tmpColumn->size[0] = 1;
      tmpColumn->size[1] = pEnd;
      emxEnsureCapacity_real_T(tmpColumn, i9);
      kEnd = yk * pEnd;
      for (i9 = 0; i9 < kEnd; i9++) {
        tmpColumn->data[i9] = idx->data[i9];
      }

      /* %%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%% */
      /*          maximo=0.02; */
      /*          minimo=0.002; */
      /*          taxAct = rand; */
      /*          taxAct = (maximo-minimo)*taxAct+minimo; */
      varargin_4 = (double)IQ->size[0] - (double)NumTOp;
      if (varargin_4 < 2.147483648E+9) {
        if (varargin_4 >= -2.147483648E+9) {
          i9 = (int)varargin_4;
        } else {
          i9 = MIN_int32_T;
        }
      } else {
        i9 = MAX_int32_T;
      }

      if (1 > i9) {
        kEnd = 0;
      } else {
        kEnd = i9;
      }

      q = rank_classic->size[0];
      i9 = b_IC->size[0] * b_IC->size[1];
      b_IC->size[0] = q;
      b_IC->size[1] = tmpColumn->size[1];
      emxEnsureCapacity_int32_T(b_IC, i9);
      p = tmpColumn->size[1];
      for (i9 = 0; i9 < p; i9++) {
        for (qEnd = 0; qEnd < q; qEnd++) {
          b_IC->data[qEnd + b_IC->size[0] * i9] = rank_classic->data[qEnd +
            rank_classic->size[0] * ((int)tmpColumn->data[i9] - 1)];
        }
      }

      /* UNTITLED5 Summary of this function goes here */
      /*    Detailed explanation goes here */
      /* Convertir de numerico a representacion binaria. */
      i9 = rank_classic->size[0];
      qEnd = rank_classic->size[0];
      yk = iwork->size[0];
      iwork->size[0] = tmpColumn->size[1];
      emxEnsureCapacity_int32_T(iwork, yk);
      q = tmpColumn->size[1];
      for (yk = 0; yk < q; yk++) {
        iwork->data[yk] = (int)tmpColumn->data[yk];
      }

      yk = num2bin->size[0] * num2bin->size[1];
      num2bin->size[0] = (int)((double)i9 * (double)iwork->size[0]);
      num2bin->size[1] = qEnd;
      emxEnsureCapacity_int8_T(num2bin, yk);
      yk = iwork->size[0];
      iwork->size[0] = tmpColumn->size[1];
      emxEnsureCapacity_int32_T(iwork, yk);
      q = tmpColumn->size[1];
      for (yk = 0; yk < q; yk++) {
        iwork->data[yk] = (int)tmpColumn->data[yk];
      }

      q = (int)((double)i9 * (double)iwork->size[0]) * qEnd;
      for (i9 = 0; i9 < q; i9++) {
        num2bin->data[i9] = 0;
      }

      i9 = rank_classic->size[0];
      qEnd = iwork->size[0];
      iwork->size[0] = tmpColumn->size[1];
      emxEnsureCapacity_int32_T(iwork, qEnd);
      q = tmpColumn->size[1];
      for (qEnd = 0; qEnd < q; qEnd++) {
        iwork->data[qEnd] = (int)tmpColumn->data[qEnd];
      }

      i9 = (int)((double)i9 * (double)iwork->size[0]);
      for (i = 0; i < i9; i++) {
        num2bin->data[i + num2bin->size[0] * (b_IC->data[i] - 1)] = 1;
      }

      /* %%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%% */
      q = IQ->size[1] - 1;
      i9 = r3->size[0] * r3->size[1];
      r3->size[0] = kEnd;
      r3->size[1] = q + 1;
      emxEnsureCapacity_real_T(r3, i9);
      for (i9 = 0; i9 <= q; i9++) {
        for (qEnd = 0; qEnd < kEnd; qEnd++) {
          r3->data[qEnd + r3->size[0] * i9] = 0.99999 * IQ->data[qEnd + IQ->
            size[0] * i9] + 1.0E-5 * (double)num2bin->data[qEnd + num2bin->size
            [0] * i9];
        }
      }

      kEnd = r3->size[1];
      for (i9 = 0; i9 < kEnd; i9++) {
        q = r3->size[0];
        for (qEnd = 0; qEnd < q; qEnd++) {
          IQ->data[qEnd + IQ->size[0] * i9] = r3->data[qEnd + r3->size[0] * i9];
        }
      }

      /* %%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%% */
      /*  NEW CLASSIC POPULATION */
      if (keeppriority) {
        obsIQini(IQ, numIQ, numObsIQ, ProbXEst, IC);

        /*  Observaciones de los IQ garantizando que se mantengan en el rango Prioridad             */
      } else {
        obsIQ(IQ, numIQ, numObsIQ, IC);

        /*  Observaciones de los IQ */
      }
    } else {
      /*  Crossover clasico          */
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
  emxFree_real_T(&c_fitness);
  emxFree_real_T(&r3);
  emxFree_real_T(&b_fitness);
  emxFree_int32_T(&b_rank_classic);
  emxFree_int8_T(&num2bin);
  emxFree_int32_T(&b_IC);
  emxFree_int32_T(&iwork);
  emxFree_int32_T(&idx);
  emxFreeMatrix_cell_wrap_0(b_reshapes);
  emxFree_real_T(&x);
  emxFreeMatrix_cell_wrap_0(reshapes);
  emxFree_real_T(&tmpColumn);
  emxFree_real_T(&aux_fitness_2);
  emxFree_int32_T(&aux_classic_2);
  emxFree_int32_T(&rank_classic);
  emxFree_real_T(&fitness);
  emxFree_real_T(&bestFitness);
  emxFree_int32_T(&IC);
  emxFree_real_T(&IQ);
}

/* End of code generation (aevSPLap.c) */
