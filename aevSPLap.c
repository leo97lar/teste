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
#include "randperm.h"
#include "combineVectorElements.h"
#include "std.h"
#include "sort1.h"
#include "toc.h"
#include "tic.h"
#include "rdivide_helper.h"
#include "rem.h"
#include "model_rtwutil.h"
#include <stdio.h>

/* Function Definitions */
void aevSPLap(int NumTOp, int numIC, int numIQ, double taxC, double taxE, double
              taxEQ, const int NumRec[7], const emxArray_int32_T *PCPrO, const
              emxArray_int32_T *PME, const emxArray_int32_T *PMA, const
              emxArray_int32_T *PMAn, const emxArray_int32_T *PS, const
              emxArray_int32_T *PCPO, const emxArray_int32_T *PCR, const
              emxArray_int32_T *Dia, const emxArray_int32_T *Data, const
              emxArray_int32_T *TimeUsoRec, const double ProbXEst[5], const
              double fitnessB[6], int generations, int genToWidth, const
              emxArray_int32_T *DispMExD, const emxArray_real_T *EP, double k0,
              double k1, double k2, double k3, boolean_T keeppriority,
              emxArray_int32_T *bestexperimento, emxArray_real_T *trace)
{
  emxArray_real_T *IQ;
  int numObsIQ;
  emxArray_int32_T *IC;
  int loop_ub;
  int i1;
  emxArray_int32_T *rank_classic;
  emxArray_real_T *bestFitness;
  int n;
  emxArray_int32_T *y;
  int yk;
  int k;
  emxArray_real_T *fitness;
  emxArray_int32_T *aux_classic_2;
  emxArray_real_T *aux_fitness_2;
  emxArray_real_T *tmpColumn;
  emxArray_real_T *IQtemp;
  cell_wrap_0 reshapes[2];
  emxArray_real_T *x;
  cell_wrap_0 b_reshapes[2];
  emxArray_int32_T *b_IC;
  emxArray_int32_T *b_rank_classic;
  emxArray_real_T *b_IQ;
  emxArray_int32_T *c_rank_classic;
  emxArray_real_T *b_fitness;
  emxArray_int32_T *b_PCPrO;
  emxArray_int32_T *b_PME;
  emxArray_int32_T *b_PMA;
  emxArray_int32_T *b_PMAn;
  emxArray_int32_T *b_PS;
  emxArray_int32_T *b_PCPO;
  emxArray_int32_T *b_PCR;
  emxArray_int32_T *b_TimeUsoRec;
  emxArray_real_T *b_EP;
  int g;
  double varargin_5;
  boolean_T empty_non_axis_sizes;
  signed char input_sizes_idx_1;
  int b_loop_ub;
  int i2;
  double d0;
  double d1;
  double d2;
  double d3;
  double d4;
  (void)taxEQ;
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
  loop_ub = IC->size[0];
  i1 = bestexperimento->size[0];
  bestexperimento->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(bestexperimento, i1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    bestexperimento->data[i1] = IC->data[i1];
  }

  emxInit_int32_T(&rank_classic, 2);
  i1 = rank_classic->size[0] * rank_classic->size[1];
  rank_classic->size[0] = NumTOp;
  rank_classic->size[1] = numIC;
  emxEnsureCapacity_int32_T(rank_classic, i1);
  loop_ub = NumTOp * numIC;
  for (i1 = 0; i1 < loop_ub; i1++) {
    rank_classic->data[i1] = 0;
  }

  emxInit_real_T(&bestFitness, 2);
  i1 = bestFitness->size[0] * bestFitness->size[1];
  bestFitness->size[0] = numIC;
  bestFitness->size[1] = 6;
  emxEnsureCapacity_real_T(bestFitness, i1);
  loop_ub = numIC * 6;
  for (i1 = 0; i1 < loop_ub; i1++) {
    bestFitness->data[i1] = 0.0;
  }

  if (NumTOp < 1) {
    n = 0;
  } else {
    n = NumTOp;
  }

  emxInit_int32_T(&y, 2);
  i1 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_int32_T(y, i1);
  if (n > 0) {
    y->data[0] = 1;
    yk = 1;
    for (k = 2; k <= n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }

  loop_ub = y->size[1];
  for (i1 = 0; i1 < loop_ub; i1++) {
    rank_classic->data[i1] = y->data[i1];
  }

  emxFree_int32_T(&y);
  for (i1 = 0; i1 < 6; i1++) {
    bestFitness->data[bestFitness->size[0] * i1] = fitnessB[i1];
  }

  /*  INICIALIZA LOOPING */
  i1 = trace->size[0] * trace->size[1];
  trace->size[0] = generations;
  trace->size[1] = 9;
  emxEnsureCapacity_real_T(trace, i1);
  emxInit_real_T(&fitness, 2);
  emxInit_int32_T(&aux_classic_2, 2);
  emxInit_real_T(&aux_fitness_2, 2);
  emxInit_real_T(&tmpColumn, 2);
  emxInit_real_T(&IQtemp, 2);
  emxInitMatrix_cell_wrap_0(reshapes);
  emxInit_real_T(&x, 1);
  emxInitMatrix_cell_wrap_0(b_reshapes);
  emxInit_int32_T(&b_IC, 1);
  emxInit_int32_T(&b_rank_classic, 2);
  emxInit_real_T(&b_IQ, 2);
  emxInit_int32_T(&c_rank_classic, 2);
  emxInit_real_T(&b_fitness, 2);
  emxInit_int32_T(&b_PCPrO, 2);
  emxInit_int32_T(&b_PME, 2);
  emxInit_int32_T(&b_PMA, 2);
  emxInit_int32_T(&b_PMAn, 2);
  emxInit_int32_T(&b_PS, 2);
  emxInit_int32_T(&b_PCPO, 2);
  emxInit_int32_T(&b_PCR, 2);
  emxInit_int32_T(&b_TimeUsoRec, 2);
  emxInit_real_T(&b_EP, 1);
  for (g = 0; g < generations; g++) {
    i1 = fitness->size[0] * fitness->size[1];
    fitness->size[0] = numIC;
    fitness->size[1] = 6;
    emxEnsureCapacity_real_T(fitness, i1);
    loop_ub = numIC * 6;
    for (i1 = 0; i1 < loop_ub; i1++) {
      fitness->data[i1] = 0.0;
    }

    /*  [fitness,NOFP,TmNOFP,NOE2,NOE3] */
    for (yk = 0; yk < numIC; yk++) {
      loop_ub = IC->size[0];
      i1 = b_IC->size[0];
      b_IC->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(b_IC, i1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_IC->data[i1] = IC->data[i1 + IC->size[0] * yk];
      }

      i1 = b_PCPrO->size[0] * b_PCPrO->size[1];
      b_PCPrO->size[0] = PCPrO->size[0];
      b_PCPrO->size[1] = PCPrO->size[1];
      emxEnsureCapacity_int32_T(b_PCPrO, i1);
      loop_ub = PCPrO->size[0] * PCPrO->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_PCPrO->data[i1] = PCPrO->data[i1];
      }

      i1 = b_PME->size[0] * b_PME->size[1];
      b_PME->size[0] = PME->size[0];
      b_PME->size[1] = PME->size[1];
      emxEnsureCapacity_int32_T(b_PME, i1);
      loop_ub = PME->size[0] * PME->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_PME->data[i1] = PME->data[i1];
      }

      i1 = b_PMA->size[0] * b_PMA->size[1];
      b_PMA->size[0] = PMA->size[0];
      b_PMA->size[1] = PMA->size[1];
      emxEnsureCapacity_int32_T(b_PMA, i1);
      loop_ub = PMA->size[0] * PMA->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_PMA->data[i1] = PMA->data[i1];
      }

      i1 = b_PMAn->size[0] * b_PMAn->size[1];
      b_PMAn->size[0] = PMAn->size[0];
      b_PMAn->size[1] = PMAn->size[1];
      emxEnsureCapacity_int32_T(b_PMAn, i1);
      loop_ub = PMAn->size[0] * PMAn->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_PMAn->data[i1] = PMAn->data[i1];
      }

      i1 = b_PS->size[0] * b_PS->size[1];
      b_PS->size[0] = PS->size[0];
      b_PS->size[1] = PS->size[1];
      emxEnsureCapacity_int32_T(b_PS, i1);
      loop_ub = PS->size[0] * PS->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_PS->data[i1] = PS->data[i1];
      }

      i1 = b_PCPO->size[0] * b_PCPO->size[1];
      b_PCPO->size[0] = PCPO->size[0];
      b_PCPO->size[1] = PCPO->size[1];
      emxEnsureCapacity_int32_T(b_PCPO, i1);
      loop_ub = PCPO->size[0] * PCPO->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_PCPO->data[i1] = PCPO->data[i1];
      }

      i1 = b_PCR->size[0] * b_PCR->size[1];
      b_PCR->size[0] = PCR->size[0];
      b_PCR->size[1] = PCR->size[1];
      emxEnsureCapacity_int32_T(b_PCR, i1);
      loop_ub = PCR->size[0] * PCR->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_PCR->data[i1] = PCR->data[i1];
      }

      i1 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
      b_TimeUsoRec->size[0] = TimeUsoRec->size[0];
      b_TimeUsoRec->size[1] = 7;
      emxEnsureCapacity_int32_T(b_TimeUsoRec, i1);
      loop_ub = TimeUsoRec->size[0] * TimeUsoRec->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_TimeUsoRec->data[i1] = TimeUsoRec->data[i1];
      }

      i1 = b_EP->size[0];
      b_EP->size[0] = EP->size[0];
      emxEnsureCapacity_real_T(b_EP, i1);
      loop_ub = EP->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_EP->data[i1] = EP->data[i1];
      }

      b_sch(NumTOp, b_IC, NumRec, b_PCPrO, b_PME, b_PMA, b_PMAn, b_PS, b_PCPO,
            b_PCR, Dia, Data, b_TimeUsoRec, DispMExD, b_EP, k0, k1, k2, k3, &d0,
            &varargin_5, &d1, &d2, &d3, &d4);
      fitness->data[yk] = d0;
      fitness->data[yk + fitness->size[0]] = varargin_5;
      fitness->data[yk + (fitness->size[0] << 1)] = d1;
      fitness->data[yk + fitness->size[0] * 3] = d2;
      fitness->data[yk + (fitness->size[0] << 2)] = d3;
      fitness->data[yk + fitness->size[0] * 5] = d4;
    }

    /*     save(strcat('fitness_', int2str(g),'.mat'),'fitness'); */
    /*     file = load(strcat('fitness_', int2str(g),'.mat')); */
    /*     fitness = file.fitness; */
    /* ATUALIZA POPULAÇÃO B(T) */
    if (1 + g == 1) {
      i1 = rank_classic->size[0];
      if (i1 != 0) {
        k = rank_classic->size[0];
      } else if ((IC->size[0] != 0) && (IC->size[1] != 0)) {
        k = IC->size[0];
      } else {
        i1 = rank_classic->size[0];
        if (i1 > 0) {
          k = rank_classic->size[0];
        } else {
          k = 0;
        }

        if (IC->size[0] > k) {
          k = IC->size[0];
        }
      }

      empty_non_axis_sizes = (k == 0);
      if (empty_non_axis_sizes) {
        input_sizes_idx_1 = 1;
      } else {
        i1 = rank_classic->size[0];
        if (i1 != 0) {
          input_sizes_idx_1 = 1;
        } else {
          input_sizes_idx_1 = 0;
        }
      }

      loop_ub = rank_classic->size[0];
      i1 = b_IC->size[0];
      b_IC->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(b_IC, i1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_IC->data[i1] = rank_classic->data[i1];
      }

      i1 = b_reshapes[0].f1->size[0] * b_reshapes[0].f1->size[1];
      b_reshapes[0].f1->size[0] = k;
      b_reshapes[0].f1->size[1] = input_sizes_idx_1;
      emxEnsureCapacity_int32_T(b_reshapes[0].f1, i1);
      loop_ub = k * input_sizes_idx_1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_reshapes[0].f1->data[i1] = b_IC->data[i1];
      }

      if (empty_non_axis_sizes || ((IC->size[0] != 0) && (IC->size[1] != 0))) {
        loop_ub = IC->size[1];
      } else {
        loop_ub = 0;
      }

      i1 = aux_classic_2->size[0] * aux_classic_2->size[1];
      aux_classic_2->size[0] = b_reshapes[0].f1->size[0];
      aux_classic_2->size[1] = b_reshapes[0].f1->size[1] + loop_ub;
      emxEnsureCapacity_int32_T(aux_classic_2, i1);
      b_loop_ub = b_reshapes[0].f1->size[1];
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        n = b_reshapes[0].f1->size[0];
        for (i2 = 0; i2 < n; i2++) {
          aux_classic_2->data[i2 + aux_classic_2->size[0] * i1] = b_reshapes[0].
            f1->data[i2 + b_reshapes[0].f1->size[0] * i1];
        }
      }

      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < k; i2++) {
          aux_classic_2->data[i2 + aux_classic_2->size[0] * (i1 + b_reshapes[0].
            f1->size[1])] = IC->data[i2 + k * i1];
        }
      }

      i1 = aux_fitness_2->size[0] * aux_fitness_2->size[1];
      aux_fitness_2->size[0] = 1 + fitness->size[0];
      aux_fitness_2->size[1] = 6;
      emxEnsureCapacity_real_T(aux_fitness_2, i1);
      for (i1 = 0; i1 < 6; i1++) {
        aux_fitness_2->data[aux_fitness_2->size[0] * i1] = bestFitness->
          data[bestFitness->size[0] * i1];
      }

      for (i1 = 0; i1 < 6; i1++) {
        loop_ub = fitness->size[0];
        for (i2 = 0; i2 < loop_ub; i2++) {
          aux_fitness_2->data[(i2 + aux_fitness_2->size[0] * i1) + 1] =
            fitness->data[i2 + fitness->size[0] * i1];
        }
      }

      loop_ub = aux_fitness_2->size[0];
      i1 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_real_T(x, i1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        x->data[i1] = aux_fitness_2->data[i1];
      }

      sort(x, b_IC);
      i1 = x->size[0];
      x->size[0] = b_IC->size[0];
      emxEnsureCapacity_real_T(x, i1);
      loop_ub = b_IC->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        x->data[i1] = b_IC->data[i1];
      }

      if (1 > numIC) {
        loop_ub = 0;
      } else {
        loop_ub = numIC;
      }

      i1 = fitness->size[0] * fitness->size[1];
      fitness->size[0] = x->size[0];
      fitness->size[1] = 6;
      emxEnsureCapacity_real_T(fitness, i1);
      for (i1 = 0; i1 < 6; i1++) {
        b_loop_ub = x->size[0];
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          fitness->data[i2 + fitness->size[0] * i1] = aux_fitness_2->data[((int)
            x->data[i2] + aux_fitness_2->size[0] * i1) - 1];
        }
      }

      i1 = b_fitness->size[0] * b_fitness->size[1];
      b_fitness->size[0] = loop_ub;
      b_fitness->size[1] = 6;
      emxEnsureCapacity_real_T(b_fitness, i1);
      for (i1 = 0; i1 < 6; i1++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_fitness->data[i2 + b_fitness->size[0] * i1] = fitness->data[i2 +
            fitness->size[0] * i1];
        }
      }

      i1 = fitness->size[0] * fitness->size[1];
      fitness->size[0] = b_fitness->size[0];
      fitness->size[1] = 6;
      emxEnsureCapacity_real_T(fitness, i1);
      for (i1 = 0; i1 < 6; i1++) {
        loop_ub = b_fitness->size[0];
        for (i2 = 0; i2 < loop_ub; i2++) {
          fitness->data[i2 + fitness->size[0] * i1] = b_fitness->data[i2 +
            b_fitness->size[0] * i1];
        }
      }

      if (1 > numIC) {
        loop_ub = 0;
      } else {
        loop_ub = numIC;
      }

      b_loop_ub = aux_classic_2->size[0] - 1;
      n = aux_classic_2->size[0];
      i1 = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[0] = n;
      rank_classic->size[1] = x->size[0];
      emxEnsureCapacity_int32_T(rank_classic, i1);
      yk = x->size[0];
      for (i1 = 0; i1 < yk; i1++) {
        for (i2 = 0; i2 < n; i2++) {
          rank_classic->data[i2 + rank_classic->size[0] * i1] =
            aux_classic_2->data[i2 + aux_classic_2->size[0] * ((int)x->data[i1]
            - 1)];
        }
      }

      i1 = IC->size[0] * IC->size[1];
      IC->size[0] = b_loop_ub + 1;
      IC->size[1] = loop_ub;
      emxEnsureCapacity_int32_T(IC, i1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 <= b_loop_ub; i2++) {
          IC->data[i2 + IC->size[0] * i1] = rank_classic->data[i2 +
            rank_classic->size[0] * i1];
        }
      }

      i1 = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[0] = IC->size[0];
      rank_classic->size[1] = IC->size[1];
      emxEnsureCapacity_int32_T(rank_classic, i1);
      loop_ub = IC->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = IC->size[0];
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          rank_classic->data[i2 + rank_classic->size[0] * i1] = IC->data[i2 +
            IC->size[0] * i1];
        }
      }
    } else {
      varargin_5 = rt_roundd((double)numIC * taxE);
      if (varargin_5 < 2.147483648E+9) {
        if (varargin_5 >= -2.147483648E+9) {
          i1 = (int)varargin_5;
        } else {
          i1 = MIN_int32_T;
        }
      } else {
        i1 = MAX_int32_T;
      }

      i1 = (int)rt_roundd((double)i1 / 100.0);
      if (1 > i1) {
        loop_ub = 0;
      } else {
        loop_ub = i1;
      }

      i1 = rank_classic->size[0];
      if ((i1 != 0) && (loop_ub != 0)) {
        k = rank_classic->size[0];
      } else if ((IC->size[0] != 0) && (IC->size[1] != 0)) {
        k = IC->size[0];
      } else {
        i1 = rank_classic->size[0];
        if (i1 > 0) {
          k = rank_classic->size[0];
        } else {
          k = 0;
        }

        if (IC->size[0] > k) {
          k = IC->size[0];
        }
      }

      empty_non_axis_sizes = (k == 0);
      if (empty_non_axis_sizes) {
        yk = loop_ub;
      } else {
        i1 = rank_classic->size[0];
        if ((i1 != 0) && (loop_ub != 0)) {
          yk = loop_ub;
        } else {
          yk = 0;
        }
      }

      b_loop_ub = rank_classic->size[0];
      i1 = b_rank_classic->size[0] * b_rank_classic->size[1];
      b_rank_classic->size[0] = b_loop_ub;
      b_rank_classic->size[1] = loop_ub;
      emxEnsureCapacity_int32_T(b_rank_classic, i1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          b_rank_classic->data[i2 + b_rank_classic->size[0] * i1] =
            rank_classic->data[i2 + rank_classic->size[0] * i1];
        }
      }

      i1 = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
      reshapes[0].f1->size[0] = k;
      reshapes[0].f1->size[1] = yk;
      emxEnsureCapacity_int32_T(reshapes[0].f1, i1);
      loop_ub = k * yk;
      for (i1 = 0; i1 < loop_ub; i1++) {
        reshapes[0].f1->data[i1] = b_rank_classic->data[i1];
      }

      if (empty_non_axis_sizes || ((IC->size[0] != 0) && (IC->size[1] != 0))) {
        loop_ub = IC->size[1];
      } else {
        loop_ub = 0;
      }

      i1 = aux_classic_2->size[0] * aux_classic_2->size[1];
      aux_classic_2->size[0] = reshapes[0].f1->size[0];
      aux_classic_2->size[1] = reshapes[0].f1->size[1] + loop_ub;
      emxEnsureCapacity_int32_T(aux_classic_2, i1);
      b_loop_ub = reshapes[0].f1->size[1];
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        n = reshapes[0].f1->size[0];
        for (i2 = 0; i2 < n; i2++) {
          aux_classic_2->data[i2 + aux_classic_2->size[0] * i1] = reshapes[0].
            f1->data[i2 + reshapes[0].f1->size[0] * i1];
        }
      }

      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 < k; i2++) {
          aux_classic_2->data[i2 + aux_classic_2->size[0] * (i1 + reshapes[0].
            f1->size[1])] = IC->data[i2 + k * i1];
        }
      }

      if (varargin_5 < 2.147483648E+9) {
        if (varargin_5 >= -2.147483648E+9) {
          i1 = (int)varargin_5;
        } else {
          i1 = MIN_int32_T;
        }
      } else {
        i1 = MAX_int32_T;
      }

      i1 = (int)rt_roundd((double)i1 / 100.0);
      if (1 > i1) {
        loop_ub = 0;
      } else {
        loop_ub = i1;
      }

      i1 = aux_fitness_2->size[0] * aux_fitness_2->size[1];
      aux_fitness_2->size[0] = loop_ub + fitness->size[0];
      aux_fitness_2->size[1] = 6;
      emxEnsureCapacity_real_T(aux_fitness_2, i1);
      for (i1 = 0; i1 < 6; i1++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          aux_fitness_2->data[i2 + aux_fitness_2->size[0] * i1] =
            bestFitness->data[i2 + bestFitness->size[0] * i1];
        }
      }

      for (i1 = 0; i1 < 6; i1++) {
        b_loop_ub = fitness->size[0];
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          aux_fitness_2->data[(i2 + loop_ub) + aux_fitness_2->size[0] * i1] =
            fitness->data[i2 + fitness->size[0] * i1];
        }
      }

      loop_ub = aux_fitness_2->size[0];
      i1 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_real_T(x, i1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        x->data[i1] = aux_fitness_2->data[i1];
      }

      sort(x, b_IC);
      i1 = x->size[0];
      x->size[0] = b_IC->size[0];
      emxEnsureCapacity_real_T(x, i1);
      loop_ub = b_IC->size[0];
      for (i1 = 0; i1 < loop_ub; i1++) {
        x->data[i1] = b_IC->data[i1];
      }

      if (1 > numIC) {
        loop_ub = 0;
      } else {
        loop_ub = numIC;
      }

      i1 = fitness->size[0] * fitness->size[1];
      fitness->size[0] = x->size[0];
      fitness->size[1] = 6;
      emxEnsureCapacity_real_T(fitness, i1);
      for (i1 = 0; i1 < 6; i1++) {
        b_loop_ub = x->size[0];
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          fitness->data[i2 + fitness->size[0] * i1] = aux_fitness_2->data[((int)
            x->data[i2] + aux_fitness_2->size[0] * i1) - 1];
        }
      }

      i1 = b_fitness->size[0] * b_fitness->size[1];
      b_fitness->size[0] = loop_ub;
      b_fitness->size[1] = 6;
      emxEnsureCapacity_real_T(b_fitness, i1);
      for (i1 = 0; i1 < 6; i1++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_fitness->data[i2 + b_fitness->size[0] * i1] = fitness->data[i2 +
            fitness->size[0] * i1];
        }
      }

      i1 = fitness->size[0] * fitness->size[1];
      fitness->size[0] = b_fitness->size[0];
      fitness->size[1] = 6;
      emxEnsureCapacity_real_T(fitness, i1);
      for (i1 = 0; i1 < 6; i1++) {
        loop_ub = b_fitness->size[0];
        for (i2 = 0; i2 < loop_ub; i2++) {
          fitness->data[i2 + fitness->size[0] * i1] = b_fitness->data[i2 +
            b_fitness->size[0] * i1];
        }
      }

      if (1 > numIC) {
        loop_ub = 0;
      } else {
        loop_ub = numIC;
      }

      b_loop_ub = aux_classic_2->size[0] - 1;
      n = aux_classic_2->size[0];
      i1 = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[0] = n;
      rank_classic->size[1] = x->size[0];
      emxEnsureCapacity_int32_T(rank_classic, i1);
      yk = x->size[0];
      for (i1 = 0; i1 < yk; i1++) {
        for (i2 = 0; i2 < n; i2++) {
          rank_classic->data[i2 + rank_classic->size[0] * i1] =
            aux_classic_2->data[i2 + aux_classic_2->size[0] * ((int)x->data[i1]
            - 1)];
        }
      }

      i1 = IC->size[0] * IC->size[1];
      IC->size[0] = b_loop_ub + 1;
      IC->size[1] = loop_ub;
      emxEnsureCapacity_int32_T(IC, i1);
      for (i1 = 0; i1 < loop_ub; i1++) {
        for (i2 = 0; i2 <= b_loop_ub; i2++) {
          IC->data[i2 + IC->size[0] * i1] = rank_classic->data[i2 +
            rank_classic->size[0] * i1];
        }
      }

      i1 = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[0] = IC->size[0];
      rank_classic->size[1] = IC->size[1];
      emxEnsureCapacity_int32_T(rank_classic, i1);
      loop_ub = IC->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = IC->size[0];
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          rank_classic->data[i2 + rank_classic->size[0] * i1] = IC->data[i2 +
            IC->size[0] * i1];
        }
      }
    }

    /* REMOVE INDIVÍDUOS MAIS FRACOS (EXCEDENTES) */
    i1 = bestFitness->size[0] * bestFitness->size[1];
    bestFitness->size[0] = fitness->size[0];
    bestFitness->size[1] = 6;
    emxEnsureCapacity_real_T(bestFitness, i1);
    loop_ub = fitness->size[0] * fitness->size[1];
    for (i1 = 0; i1 < loop_ub; i1++) {
      bestFitness->data[i1] = fitness->data[i1];
    }

    /*  GUARDA MELHOR INDIVÍDUO */
    loop_ub = rank_classic->size[0];
    i1 = bestexperimento->size[0];
    bestexperimento->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(bestexperimento, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      bestexperimento->data[i1] = rank_classic->data[i1];
    }

    /*  SALVA A GERAÇÃO, FITNESS do Melhor ind., a MÉDIA DO FITNESS e a STD DO FITNESS  */
    i1 = fitness->size[0];
    loop_ub = fitness->size[0];
    i2 = x->size[0];
    x->size[0] = loop_ub;
    emxEnsureCapacity_real_T(x, i2);
    for (i2 = 0; i2 < loop_ub; i2++) {
      x->data[i2] = fitness->data[i2];
    }

    loop_ub = fitness->size[0];
    i2 = b_EP->size[0];
    b_EP->size[0] = loop_ub;
    emxEnsureCapacity_real_T(b_EP, i2);
    for (i2 = 0; i2 < loop_ub; i2++) {
      b_EP->data[i2] = fitness->data[i2];
    }

    varargin_5 = combineVectorElements(x);
    d1 = b_std(b_EP);
    trace->data[g] = 1 + g;
    d2 = rt_roundd(fitness->data[0]);
    if (d2 < 2.147483648E+9) {
      if (d2 >= -2.147483648E+9) {
        i2 = (int)d2;
      } else {
        i2 = MIN_int32_T;
      }
    } else {
      i2 = MAX_int32_T;
    }

    trace->data[g + trace->size[0]] = i2;
    varargin_5 = rt_roundd(varargin_5 / (double)i1);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        i1 = (int)varargin_5;
      } else {
        i1 = MIN_int32_T;
      }
    } else {
      i1 = MAX_int32_T;
    }

    trace->data[g + (trace->size[0] << 1)] = i1;
    varargin_5 = rt_roundd(d1);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        i1 = (int)varargin_5;
      } else {
        i1 = MIN_int32_T;
      }
    } else {
      i1 = MAX_int32_T;
    }

    trace->data[g + trace->size[0] * 3] = i1;
    varargin_5 = rt_roundd(fitness->data[fitness->size[0]]);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        i1 = (int)varargin_5;
      } else {
        i1 = MIN_int32_T;
      }
    } else {
      i1 = MAX_int32_T;
    }

    trace->data[g + (trace->size[0] << 2)] = i1;
    varargin_5 = rt_roundd(fitness->data[fitness->size[0] << 1]);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        i1 = (int)varargin_5;
      } else {
        i1 = MIN_int32_T;
      }
    } else {
      i1 = MAX_int32_T;
    }

    trace->data[g + trace->size[0] * 5] = i1;
    varargin_5 = rt_roundd(fitness->data[fitness->size[0] * 3]);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        i1 = (int)varargin_5;
      } else {
        i1 = MIN_int32_T;
      }
    } else {
      i1 = MAX_int32_T;
    }

    trace->data[g + trace->size[0] * 6] = i1;
    varargin_5 = rt_roundd(fitness->data[fitness->size[0] << 2]);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        i1 = (int)varargin_5;
      } else {
        i1 = MIN_int32_T;
      }
    } else {
      i1 = MAX_int32_T;
    }

    trace->data[g + trace->size[0] * 7] = i1;
    varargin_5 = rt_roundd(fitness->data[fitness->size[0] * 5]);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        i1 = (int)varargin_5;
      } else {
        i1 = MIN_int32_T;
      }
    } else {
      i1 = MAX_int32_T;
    }

    trace->data[g + (trace->size[0] << 3)] = i1;

    /*  IMPRIME STATUS DA EVOLUÇÃO */
    loop_ub = fitness->size[0];
    i1 = x->size[0];
    x->size[0] = loop_ub;
    emxEnsureCapacity_real_T(x, i1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      x->data[i1] = fitness->data[i1];
    }

    varargin_5 = b_std(x);
    i1 = fitness->size[0];
    loop_ub = fitness->size[0];
    i2 = x->size[0];
    x->size[0] = loop_ub;
    emxEnsureCapacity_real_T(x, i2);
    for (i2 = 0; i2 < loop_ub; i2++) {
      x->data[i2] = fitness->data[i2];
    }

    printf("Ger: %d - \t Ini: %10.5f - \t Best: %10.5f - \t Mean: %10.5f - \t STD: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t "
           "NOE2: %10.5f - \t NOE3: %10.5f \n", 1 + g, fitnessB[0],
           fitness->data[0], combineVectorElements(x) / (double)i1, varargin_5,
           fitness->data[fitness->size[0]], fitness->data[fitness->size[0] << 1],
           fitness->data[fitness->size[0] * 3], fitness->data[fitness->size[0] <<
           2], fitness->data[fitness->size[0] * 5]);
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

      randperm(yk, tmpColumn);

      /* %%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%% */
      /*          maximo=0.02; */
      /*          minimo=0.002; */
      /*          taxAct = rand; */
      /*          taxAct = (maximo-minimo)*taxAct+minimo; */
      i1 = IQ->size[0] - NumTOp;
      if (1 > i1) {
        loop_ub = 0;
      } else {
        loop_ub = i1;
      }

      b_loop_ub = IQ->size[1];
      i1 = b_IQ->size[0] * b_IQ->size[1];
      b_IQ->size[0] = loop_ub;
      b_IQ->size[1] = b_loop_ub;
      emxEnsureCapacity_real_T(b_IQ, i1);
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_IQ->data[i2 + b_IQ->size[0] * i1] = IQ->data[i2 + IQ->size[0] * i1];
        }
      }

      loop_ub = rank_classic->size[0];
      i1 = c_rank_classic->size[0] * c_rank_classic->size[1];
      c_rank_classic->size[0] = loop_ub;
      c_rank_classic->size[1] = tmpColumn->size[1];
      emxEnsureCapacity_int32_T(c_rank_classic, i1);
      b_loop_ub = tmpColumn->size[1];
      for (i1 = 0; i1 < b_loop_ub; i1++) {
        for (i2 = 0; i2 < loop_ub; i2++) {
          c_rank_classic->data[i2 + c_rank_classic->size[0] * i1] =
            rank_classic->data[i2 + rank_classic->size[0] * ((int)
            tmpColumn->data[i1] - 1)];
        }
      }

      b_actIQ(b_IQ, c_rank_classic, IQtemp);

      /* %%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%% */
      loop_ub = IQtemp->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        b_loop_ub = IQtemp->size[0];
        for (i2 = 0; i2 < b_loop_ub; i2++) {
          IQ->data[i2 + IQ->size[0] * i1] = IQtemp->data[i2 + IQtemp->size[0] *
            i1];
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

  emxFree_real_T(&b_EP);
  emxFree_int32_T(&b_TimeUsoRec);
  emxFree_int32_T(&b_PCR);
  emxFree_int32_T(&b_PCPO);
  emxFree_int32_T(&b_PS);
  emxFree_int32_T(&b_PMAn);
  emxFree_int32_T(&b_PMA);
  emxFree_int32_T(&b_PME);
  emxFree_int32_T(&b_PCPrO);
  emxFree_real_T(&b_fitness);
  emxFree_int32_T(&c_rank_classic);
  emxFree_real_T(&b_IQ);
  emxFree_int32_T(&b_rank_classic);
  emxFree_int32_T(&b_IC);
  emxFreeMatrix_cell_wrap_0(b_reshapes);
  emxFree_real_T(&x);
  emxFreeMatrix_cell_wrap_0(reshapes);
  emxFree_real_T(&IQtemp);
  emxFree_real_T(&tmpColumn);
  emxFree_real_T(&aux_fitness_2);
  emxFree_int32_T(&aux_classic_2);
  emxFree_int32_T(&rank_classic);
  emxFree_real_T(&fitness);
  emxFree_real_T(&bestFitness);
  emxFree_int32_T(&IC);
  emxFree_real_T(&IQ);
}

void b_aevSPLap(int NumTOp, int numIC, int numIQ, double taxC, double taxE,
                const int NumRec[7], const emxArray_int32_T *PCPrO, const
                emxArray_int32_T *PME, const emxArray_int32_T *PMA, const
                emxArray_int32_T *PMAn, const emxArray_int32_T *PS, const
                emxArray_int32_T *PCPO, const emxArray_int32_T *PCR, const
                emxArray_int32_T *Dia, const emxArray_int32_T *Data, const
                emxArray_int32_T *TimeUsoRec, const emxArray_real_T *ProbXEst,
                const double fitnessB[6], int generations, int genToWidth, const
                emxArray_int32_T *DispMExD, const emxArray_int32_T *EP, double
                k0, double k1, double k2, double k3, boolean_T keeppriority,
                emxArray_int32_T *bestexperimento, emxArray_real_T *trace)
{
  emxArray_real_T *IQ;
  int numObsIQ;
  emxArray_int32_T *IC;
  int loop_ub;
  int i52;
  emxArray_int32_T *rank_classic;
  emxArray_real_T *bestFitness;
  int n;
  emxArray_int32_T *y;
  int yk;
  int k;
  emxArray_real_T *fitness;
  emxArray_int32_T *aux_classic_2;
  emxArray_real_T *aux_fitness_2;
  emxArray_real_T *tmpColumn;
  emxArray_real_T *IQtemp;
  cell_wrap_0 reshapes[2];
  emxArray_real_T *x;
  cell_wrap_0 b_reshapes[2];
  emxArray_int32_T *b_IC;
  emxArray_int32_T *b_rank_classic;
  emxArray_real_T *b_fitness;
  emxArray_real_T *b_IQ;
  emxArray_int32_T *c_rank_classic;
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
  double varargin_5;
  boolean_T empty_non_axis_sizes;
  signed char input_sizes_idx_1;
  int b_loop_ub;
  int i53;
  double d11;
  double d12;
  double d13;
  double d14;
  double d15;
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
    b_obsIQini(IQ, numIQ, numObsIQ, ProbXEst, IC);

    /*  Observaciones de los IQ garantizando que se mantengan en el rango Prioridad             */
  } else {
    obsIQ(IQ, numIQ, numObsIQ, IC);

    /*  Observaciones de los IQ */
  }

  toc();

  /*  PARÂMETROS DE INTERESSE */
  loop_ub = IC->size[0];
  i52 = bestexperimento->size[0];
  bestexperimento->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(bestexperimento, i52);
  for (i52 = 0; i52 < loop_ub; i52++) {
    bestexperimento->data[i52] = IC->data[i52];
  }

  emxInit_int32_T(&rank_classic, 2);
  i52 = rank_classic->size[0] * rank_classic->size[1];
  rank_classic->size[0] = NumTOp;
  rank_classic->size[1] = numIC;
  emxEnsureCapacity_int32_T(rank_classic, i52);
  loop_ub = NumTOp * numIC;
  for (i52 = 0; i52 < loop_ub; i52++) {
    rank_classic->data[i52] = 0;
  }

  emxInit_real_T(&bestFitness, 2);
  i52 = bestFitness->size[0] * bestFitness->size[1];
  bestFitness->size[0] = numIC;
  bestFitness->size[1] = 6;
  emxEnsureCapacity_real_T(bestFitness, i52);
  loop_ub = numIC * 6;
  for (i52 = 0; i52 < loop_ub; i52++) {
    bestFitness->data[i52] = 0.0;
  }

  if (NumTOp < 1) {
    n = 0;
  } else {
    n = NumTOp;
  }

  emxInit_int32_T(&y, 2);
  i52 = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_int32_T(y, i52);
  if (n > 0) {
    y->data[0] = 1;
    yk = 1;
    for (k = 2; k <= n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }

  loop_ub = y->size[1];
  for (i52 = 0; i52 < loop_ub; i52++) {
    rank_classic->data[i52] = y->data[i52];
  }

  emxFree_int32_T(&y);
  for (i52 = 0; i52 < 6; i52++) {
    bestFitness->data[bestFitness->size[0] * i52] = fitnessB[i52];
  }

  /*  INICIALIZA LOOPING */
  i52 = trace->size[0] * trace->size[1];
  trace->size[0] = generations;
  trace->size[1] = 9;
  emxEnsureCapacity_real_T(trace, i52);
  emxInit_real_T(&fitness, 2);
  emxInit_int32_T(&aux_classic_2, 2);
  emxInit_real_T(&aux_fitness_2, 2);
  emxInit_real_T(&tmpColumn, 2);
  emxInit_real_T(&IQtemp, 2);
  emxInitMatrix_cell_wrap_0(reshapes);
  emxInit_real_T(&x, 1);
  emxInitMatrix_cell_wrap_0(b_reshapes);
  emxInit_int32_T(&b_IC, 1);
  emxInit_int32_T(&b_rank_classic, 2);
  emxInit_real_T(&b_fitness, 1);
  emxInit_real_T(&b_IQ, 2);
  emxInit_int32_T(&c_rank_classic, 2);
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
    i52 = fitness->size[0] * fitness->size[1];
    fitness->size[0] = numIC;
    fitness->size[1] = 6;
    emxEnsureCapacity_real_T(fitness, i52);
    loop_ub = numIC * 6;
    for (i52 = 0; i52 < loop_ub; i52++) {
      fitness->data[i52] = 0.0;
    }

    /*  [fitness,NOFP,TmNOFP,NOE2,NOE3] */
    for (yk = 0; yk < numIC; yk++) {
      loop_ub = IC->size[0];
      i52 = b_IC->size[0];
      b_IC->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(b_IC, i52);
      for (i52 = 0; i52 < loop_ub; i52++) {
        b_IC->data[i52] = IC->data[i52 + IC->size[0] * yk];
      }

      i52 = b_PCPrO->size[0] * b_PCPrO->size[1];
      b_PCPrO->size[0] = PCPrO->size[0];
      b_PCPrO->size[1] = PCPrO->size[1];
      emxEnsureCapacity_int32_T(b_PCPrO, i52);
      loop_ub = PCPrO->size[0] * PCPrO->size[1];
      for (i52 = 0; i52 < loop_ub; i52++) {
        b_PCPrO->data[i52] = PCPrO->data[i52];
      }

      i52 = b_PME->size[0] * b_PME->size[1];
      b_PME->size[0] = PME->size[0];
      b_PME->size[1] = PME->size[1];
      emxEnsureCapacity_int32_T(b_PME, i52);
      loop_ub = PME->size[0] * PME->size[1];
      for (i52 = 0; i52 < loop_ub; i52++) {
        b_PME->data[i52] = PME->data[i52];
      }

      i52 = b_PMA->size[0] * b_PMA->size[1];
      b_PMA->size[0] = PMA->size[0];
      b_PMA->size[1] = PMA->size[1];
      emxEnsureCapacity_int32_T(b_PMA, i52);
      loop_ub = PMA->size[0] * PMA->size[1];
      for (i52 = 0; i52 < loop_ub; i52++) {
        b_PMA->data[i52] = PMA->data[i52];
      }

      i52 = b_PMAn->size[0] * b_PMAn->size[1];
      b_PMAn->size[0] = PMAn->size[0];
      b_PMAn->size[1] = PMAn->size[1];
      emxEnsureCapacity_int32_T(b_PMAn, i52);
      loop_ub = PMAn->size[0] * PMAn->size[1];
      for (i52 = 0; i52 < loop_ub; i52++) {
        b_PMAn->data[i52] = PMAn->data[i52];
      }

      i52 = b_PS->size[0] * b_PS->size[1];
      b_PS->size[0] = PS->size[0];
      b_PS->size[1] = PS->size[1];
      emxEnsureCapacity_int32_T(b_PS, i52);
      loop_ub = PS->size[0] * PS->size[1];
      for (i52 = 0; i52 < loop_ub; i52++) {
        b_PS->data[i52] = PS->data[i52];
      }

      i52 = b_PCPO->size[0] * b_PCPO->size[1];
      b_PCPO->size[0] = PCPO->size[0];
      b_PCPO->size[1] = PCPO->size[1];
      emxEnsureCapacity_int32_T(b_PCPO, i52);
      loop_ub = PCPO->size[0] * PCPO->size[1];
      for (i52 = 0; i52 < loop_ub; i52++) {
        b_PCPO->data[i52] = PCPO->data[i52];
      }

      i52 = b_PCR->size[0] * b_PCR->size[1];
      b_PCR->size[0] = PCR->size[0];
      b_PCR->size[1] = PCR->size[1];
      emxEnsureCapacity_int32_T(b_PCR, i52);
      loop_ub = PCR->size[0] * PCR->size[1];
      for (i52 = 0; i52 < loop_ub; i52++) {
        b_PCR->data[i52] = PCR->data[i52];
      }

      i52 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
      b_TimeUsoRec->size[0] = TimeUsoRec->size[0];
      b_TimeUsoRec->size[1] = 7;
      emxEnsureCapacity_int32_T(b_TimeUsoRec, i52);
      loop_ub = TimeUsoRec->size[0] * TimeUsoRec->size[1];
      for (i52 = 0; i52 < loop_ub; i52++) {
        b_TimeUsoRec->data[i52] = TimeUsoRec->data[i52];
      }

      i52 = b_EP->size[0];
      b_EP->size[0] = EP->size[0];
      emxEnsureCapacity_int32_T(b_EP, i52);
      loop_ub = EP->size[0];
      for (i52 = 0; i52 < loop_ub; i52++) {
        b_EP->data[i52] = EP->data[i52];
      }

      c_sch(NumTOp, b_IC, NumRec, b_PCPrO, b_PME, b_PMA, b_PMAn, b_PS, b_PCPO,
            b_PCR, Dia, Data, b_TimeUsoRec, DispMExD, b_EP, k0, k1, k2, k3, &d11,
            &varargin_5, &d12, &d13, &d14, &d15);
      fitness->data[yk] = d11;
      fitness->data[yk + fitness->size[0]] = varargin_5;
      fitness->data[yk + (fitness->size[0] << 1)] = d12;
      fitness->data[yk + fitness->size[0] * 3] = d13;
      fitness->data[yk + (fitness->size[0] << 2)] = d14;
      fitness->data[yk + fitness->size[0] * 5] = d15;
    }

    /*     save(strcat('fitness_', int2str(g),'.mat'),'fitness'); */
    /*     file = load(strcat('fitness_', int2str(g),'.mat')); */
    /*     fitness = file.fitness; */
    /* ATUALIZA POPULAÇÃO B(T) */
    if (1 + g == 1) {
      i52 = rank_classic->size[0];
      if (i52 != 0) {
        k = rank_classic->size[0];
      } else if ((IC->size[0] != 0) && (IC->size[1] != 0)) {
        k = IC->size[0];
      } else {
        i52 = rank_classic->size[0];
        if (i52 > 0) {
          k = rank_classic->size[0];
        } else {
          k = 0;
        }

        if (IC->size[0] > k) {
          k = IC->size[0];
        }
      }

      empty_non_axis_sizes = (k == 0);
      if (empty_non_axis_sizes) {
        input_sizes_idx_1 = 1;
      } else {
        i52 = rank_classic->size[0];
        if (i52 != 0) {
          input_sizes_idx_1 = 1;
        } else {
          input_sizes_idx_1 = 0;
        }
      }

      loop_ub = rank_classic->size[0];
      i52 = b_IC->size[0];
      b_IC->size[0] = loop_ub;
      emxEnsureCapacity_int32_T(b_IC, i52);
      for (i52 = 0; i52 < loop_ub; i52++) {
        b_IC->data[i52] = rank_classic->data[i52];
      }

      i52 = b_reshapes[0].f1->size[0] * b_reshapes[0].f1->size[1];
      b_reshapes[0].f1->size[0] = k;
      b_reshapes[0].f1->size[1] = input_sizes_idx_1;
      emxEnsureCapacity_int32_T(b_reshapes[0].f1, i52);
      loop_ub = k * input_sizes_idx_1;
      for (i52 = 0; i52 < loop_ub; i52++) {
        b_reshapes[0].f1->data[i52] = b_IC->data[i52];
      }

      if (empty_non_axis_sizes || ((IC->size[0] != 0) && (IC->size[1] != 0))) {
        loop_ub = IC->size[1];
      } else {
        loop_ub = 0;
      }

      i52 = aux_classic_2->size[0] * aux_classic_2->size[1];
      aux_classic_2->size[0] = b_reshapes[0].f1->size[0];
      aux_classic_2->size[1] = b_reshapes[0].f1->size[1] + loop_ub;
      emxEnsureCapacity_int32_T(aux_classic_2, i52);
      b_loop_ub = b_reshapes[0].f1->size[1];
      for (i52 = 0; i52 < b_loop_ub; i52++) {
        n = b_reshapes[0].f1->size[0];
        for (i53 = 0; i53 < n; i53++) {
          aux_classic_2->data[i53 + aux_classic_2->size[0] * i52] = b_reshapes[0]
            .f1->data[i53 + b_reshapes[0].f1->size[0] * i52];
        }
      }

      for (i52 = 0; i52 < loop_ub; i52++) {
        for (i53 = 0; i53 < k; i53++) {
          aux_classic_2->data[i53 + aux_classic_2->size[0] * (i52 + b_reshapes[0]
            .f1->size[1])] = IC->data[i53 + k * i52];
        }
      }

      i52 = aux_fitness_2->size[0] * aux_fitness_2->size[1];
      aux_fitness_2->size[0] = 1 + fitness->size[0];
      aux_fitness_2->size[1] = 6;
      emxEnsureCapacity_real_T(aux_fitness_2, i52);
      for (i52 = 0; i52 < 6; i52++) {
        aux_fitness_2->data[aux_fitness_2->size[0] * i52] = bestFitness->
          data[bestFitness->size[0] * i52];
      }

      for (i52 = 0; i52 < 6; i52++) {
        loop_ub = fitness->size[0];
        for (i53 = 0; i53 < loop_ub; i53++) {
          aux_fitness_2->data[(i53 + aux_fitness_2->size[0] * i52) + 1] =
            fitness->data[i53 + fitness->size[0] * i52];
        }
      }

      loop_ub = aux_fitness_2->size[0];
      i52 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_real_T(x, i52);
      for (i52 = 0; i52 < loop_ub; i52++) {
        x->data[i52] = aux_fitness_2->data[i52];
      }

      sort(x, b_IC);
      i52 = x->size[0];
      x->size[0] = b_IC->size[0];
      emxEnsureCapacity_real_T(x, i52);
      loop_ub = b_IC->size[0];
      for (i52 = 0; i52 < loop_ub; i52++) {
        x->data[i52] = b_IC->data[i52];
      }

      if (1 > numIC) {
        loop_ub = 0;
      } else {
        loop_ub = numIC;
      }

      i52 = fitness->size[0] * fitness->size[1];
      fitness->size[0] = x->size[0];
      fitness->size[1] = 6;
      emxEnsureCapacity_real_T(fitness, i52);
      for (i52 = 0; i52 < 6; i52++) {
        b_loop_ub = x->size[0];
        for (i53 = 0; i53 < b_loop_ub; i53++) {
          fitness->data[i53 + fitness->size[0] * i52] = aux_fitness_2->data
            [((int)x->data[i53] + aux_fitness_2->size[0] * i52) - 1];
        }
      }

      i52 = c_fitness->size[0] * c_fitness->size[1];
      c_fitness->size[0] = loop_ub;
      c_fitness->size[1] = 6;
      emxEnsureCapacity_real_T(c_fitness, i52);
      for (i52 = 0; i52 < 6; i52++) {
        for (i53 = 0; i53 < loop_ub; i53++) {
          c_fitness->data[i53 + c_fitness->size[0] * i52] = fitness->data[i53 +
            fitness->size[0] * i52];
        }
      }

      i52 = fitness->size[0] * fitness->size[1];
      fitness->size[0] = c_fitness->size[0];
      fitness->size[1] = 6;
      emxEnsureCapacity_real_T(fitness, i52);
      for (i52 = 0; i52 < 6; i52++) {
        loop_ub = c_fitness->size[0];
        for (i53 = 0; i53 < loop_ub; i53++) {
          fitness->data[i53 + fitness->size[0] * i52] = c_fitness->data[i53 +
            c_fitness->size[0] * i52];
        }
      }

      if (1 > numIC) {
        loop_ub = 0;
      } else {
        loop_ub = numIC;
      }

      b_loop_ub = aux_classic_2->size[0] - 1;
      n = aux_classic_2->size[0];
      i52 = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[0] = n;
      rank_classic->size[1] = x->size[0];
      emxEnsureCapacity_int32_T(rank_classic, i52);
      yk = x->size[0];
      for (i52 = 0; i52 < yk; i52++) {
        for (i53 = 0; i53 < n; i53++) {
          rank_classic->data[i53 + rank_classic->size[0] * i52] =
            aux_classic_2->data[i53 + aux_classic_2->size[0] * ((int)x->data[i52]
            - 1)];
        }
      }

      i52 = IC->size[0] * IC->size[1];
      IC->size[0] = b_loop_ub + 1;
      IC->size[1] = loop_ub;
      emxEnsureCapacity_int32_T(IC, i52);
      for (i52 = 0; i52 < loop_ub; i52++) {
        for (i53 = 0; i53 <= b_loop_ub; i53++) {
          IC->data[i53 + IC->size[0] * i52] = rank_classic->data[i53 +
            rank_classic->size[0] * i52];
        }
      }

      i52 = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[0] = IC->size[0];
      rank_classic->size[1] = IC->size[1];
      emxEnsureCapacity_int32_T(rank_classic, i52);
      loop_ub = IC->size[1];
      for (i52 = 0; i52 < loop_ub; i52++) {
        b_loop_ub = IC->size[0];
        for (i53 = 0; i53 < b_loop_ub; i53++) {
          rank_classic->data[i53 + rank_classic->size[0] * i52] = IC->data[i53 +
            IC->size[0] * i52];
        }
      }
    } else {
      varargin_5 = rt_roundd((double)numIC * taxE);
      if (varargin_5 < 2.147483648E+9) {
        if (varargin_5 >= -2.147483648E+9) {
          i52 = (int)varargin_5;
        } else {
          i52 = MIN_int32_T;
        }
      } else {
        i52 = MAX_int32_T;
      }

      i52 = (int)rt_roundd((double)i52 / 100.0);
      if (1 > i52) {
        loop_ub = 0;
      } else {
        loop_ub = i52;
      }

      i52 = rank_classic->size[0];
      if ((i52 != 0) && (loop_ub != 0)) {
        k = rank_classic->size[0];
      } else if ((IC->size[0] != 0) && (IC->size[1] != 0)) {
        k = IC->size[0];
      } else {
        i52 = rank_classic->size[0];
        if (i52 > 0) {
          k = rank_classic->size[0];
        } else {
          k = 0;
        }

        if (IC->size[0] > k) {
          k = IC->size[0];
        }
      }

      empty_non_axis_sizes = (k == 0);
      if (empty_non_axis_sizes) {
        yk = loop_ub;
      } else {
        i52 = rank_classic->size[0];
        if ((i52 != 0) && (loop_ub != 0)) {
          yk = loop_ub;
        } else {
          yk = 0;
        }
      }

      b_loop_ub = rank_classic->size[0];
      i52 = b_rank_classic->size[0] * b_rank_classic->size[1];
      b_rank_classic->size[0] = b_loop_ub;
      b_rank_classic->size[1] = loop_ub;
      emxEnsureCapacity_int32_T(b_rank_classic, i52);
      for (i52 = 0; i52 < loop_ub; i52++) {
        for (i53 = 0; i53 < b_loop_ub; i53++) {
          b_rank_classic->data[i53 + b_rank_classic->size[0] * i52] =
            rank_classic->data[i53 + rank_classic->size[0] * i52];
        }
      }

      i52 = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
      reshapes[0].f1->size[0] = k;
      reshapes[0].f1->size[1] = yk;
      emxEnsureCapacity_int32_T(reshapes[0].f1, i52);
      loop_ub = k * yk;
      for (i52 = 0; i52 < loop_ub; i52++) {
        reshapes[0].f1->data[i52] = b_rank_classic->data[i52];
      }

      if (empty_non_axis_sizes || ((IC->size[0] != 0) && (IC->size[1] != 0))) {
        loop_ub = IC->size[1];
      } else {
        loop_ub = 0;
      }

      i52 = aux_classic_2->size[0] * aux_classic_2->size[1];
      aux_classic_2->size[0] = reshapes[0].f1->size[0];
      aux_classic_2->size[1] = reshapes[0].f1->size[1] + loop_ub;
      emxEnsureCapacity_int32_T(aux_classic_2, i52);
      b_loop_ub = reshapes[0].f1->size[1];
      for (i52 = 0; i52 < b_loop_ub; i52++) {
        n = reshapes[0].f1->size[0];
        for (i53 = 0; i53 < n; i53++) {
          aux_classic_2->data[i53 + aux_classic_2->size[0] * i52] = reshapes[0].
            f1->data[i53 + reshapes[0].f1->size[0] * i52];
        }
      }

      for (i52 = 0; i52 < loop_ub; i52++) {
        for (i53 = 0; i53 < k; i53++) {
          aux_classic_2->data[i53 + aux_classic_2->size[0] * (i52 + reshapes[0].
            f1->size[1])] = IC->data[i53 + k * i52];
        }
      }

      if (varargin_5 < 2.147483648E+9) {
        if (varargin_5 >= -2.147483648E+9) {
          i52 = (int)varargin_5;
        } else {
          i52 = MIN_int32_T;
        }
      } else {
        i52 = MAX_int32_T;
      }

      i52 = (int)rt_roundd((double)i52 / 100.0);
      if (1 > i52) {
        loop_ub = 0;
      } else {
        loop_ub = i52;
      }

      i52 = aux_fitness_2->size[0] * aux_fitness_2->size[1];
      aux_fitness_2->size[0] = loop_ub + fitness->size[0];
      aux_fitness_2->size[1] = 6;
      emxEnsureCapacity_real_T(aux_fitness_2, i52);
      for (i52 = 0; i52 < 6; i52++) {
        for (i53 = 0; i53 < loop_ub; i53++) {
          aux_fitness_2->data[i53 + aux_fitness_2->size[0] * i52] =
            bestFitness->data[i53 + bestFitness->size[0] * i52];
        }
      }

      for (i52 = 0; i52 < 6; i52++) {
        b_loop_ub = fitness->size[0];
        for (i53 = 0; i53 < b_loop_ub; i53++) {
          aux_fitness_2->data[(i53 + loop_ub) + aux_fitness_2->size[0] * i52] =
            fitness->data[i53 + fitness->size[0] * i52];
        }
      }

      loop_ub = aux_fitness_2->size[0];
      i52 = x->size[0];
      x->size[0] = loop_ub;
      emxEnsureCapacity_real_T(x, i52);
      for (i52 = 0; i52 < loop_ub; i52++) {
        x->data[i52] = aux_fitness_2->data[i52];
      }

      sort(x, b_IC);
      i52 = x->size[0];
      x->size[0] = b_IC->size[0];
      emxEnsureCapacity_real_T(x, i52);
      loop_ub = b_IC->size[0];
      for (i52 = 0; i52 < loop_ub; i52++) {
        x->data[i52] = b_IC->data[i52];
      }

      if (1 > numIC) {
        loop_ub = 0;
      } else {
        loop_ub = numIC;
      }

      i52 = fitness->size[0] * fitness->size[1];
      fitness->size[0] = x->size[0];
      fitness->size[1] = 6;
      emxEnsureCapacity_real_T(fitness, i52);
      for (i52 = 0; i52 < 6; i52++) {
        b_loop_ub = x->size[0];
        for (i53 = 0; i53 < b_loop_ub; i53++) {
          fitness->data[i53 + fitness->size[0] * i52] = aux_fitness_2->data
            [((int)x->data[i53] + aux_fitness_2->size[0] * i52) - 1];
        }
      }

      i52 = c_fitness->size[0] * c_fitness->size[1];
      c_fitness->size[0] = loop_ub;
      c_fitness->size[1] = 6;
      emxEnsureCapacity_real_T(c_fitness, i52);
      for (i52 = 0; i52 < 6; i52++) {
        for (i53 = 0; i53 < loop_ub; i53++) {
          c_fitness->data[i53 + c_fitness->size[0] * i52] = fitness->data[i53 +
            fitness->size[0] * i52];
        }
      }

      i52 = fitness->size[0] * fitness->size[1];
      fitness->size[0] = c_fitness->size[0];
      fitness->size[1] = 6;
      emxEnsureCapacity_real_T(fitness, i52);
      for (i52 = 0; i52 < 6; i52++) {
        loop_ub = c_fitness->size[0];
        for (i53 = 0; i53 < loop_ub; i53++) {
          fitness->data[i53 + fitness->size[0] * i52] = c_fitness->data[i53 +
            c_fitness->size[0] * i52];
        }
      }

      if (1 > numIC) {
        loop_ub = 0;
      } else {
        loop_ub = numIC;
      }

      b_loop_ub = aux_classic_2->size[0] - 1;
      n = aux_classic_2->size[0];
      i52 = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[0] = n;
      rank_classic->size[1] = x->size[0];
      emxEnsureCapacity_int32_T(rank_classic, i52);
      yk = x->size[0];
      for (i52 = 0; i52 < yk; i52++) {
        for (i53 = 0; i53 < n; i53++) {
          rank_classic->data[i53 + rank_classic->size[0] * i52] =
            aux_classic_2->data[i53 + aux_classic_2->size[0] * ((int)x->data[i52]
            - 1)];
        }
      }

      i52 = IC->size[0] * IC->size[1];
      IC->size[0] = b_loop_ub + 1;
      IC->size[1] = loop_ub;
      emxEnsureCapacity_int32_T(IC, i52);
      for (i52 = 0; i52 < loop_ub; i52++) {
        for (i53 = 0; i53 <= b_loop_ub; i53++) {
          IC->data[i53 + IC->size[0] * i52] = rank_classic->data[i53 +
            rank_classic->size[0] * i52];
        }
      }

      i52 = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[0] = IC->size[0];
      rank_classic->size[1] = IC->size[1];
      emxEnsureCapacity_int32_T(rank_classic, i52);
      loop_ub = IC->size[1];
      for (i52 = 0; i52 < loop_ub; i52++) {
        b_loop_ub = IC->size[0];
        for (i53 = 0; i53 < b_loop_ub; i53++) {
          rank_classic->data[i53 + rank_classic->size[0] * i52] = IC->data[i53 +
            IC->size[0] * i52];
        }
      }
    }

    /* REMOVE INDIVÍDUOS MAIS FRACOS (EXCEDENTES) */
    i52 = bestFitness->size[0] * bestFitness->size[1];
    bestFitness->size[0] = fitness->size[0];
    bestFitness->size[1] = 6;
    emxEnsureCapacity_real_T(bestFitness, i52);
    loop_ub = fitness->size[0] * fitness->size[1];
    for (i52 = 0; i52 < loop_ub; i52++) {
      bestFitness->data[i52] = fitness->data[i52];
    }

    /*  GUARDA MELHOR INDIVÍDUO */
    loop_ub = rank_classic->size[0];
    i52 = bestexperimento->size[0];
    bestexperimento->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(bestexperimento, i52);
    for (i52 = 0; i52 < loop_ub; i52++) {
      bestexperimento->data[i52] = rank_classic->data[i52];
    }

    /*  SALVA A GERAÇÃO, FITNESS do Melhor ind., a MÉDIA DO FITNESS e a STD DO FITNESS  */
    i52 = fitness->size[0];
    loop_ub = fitness->size[0];
    i53 = x->size[0];
    x->size[0] = loop_ub;
    emxEnsureCapacity_real_T(x, i53);
    for (i53 = 0; i53 < loop_ub; i53++) {
      x->data[i53] = fitness->data[i53];
    }

    loop_ub = fitness->size[0];
    i53 = b_fitness->size[0];
    b_fitness->size[0] = loop_ub;
    emxEnsureCapacity_real_T(b_fitness, i53);
    for (i53 = 0; i53 < loop_ub; i53++) {
      b_fitness->data[i53] = fitness->data[i53];
    }

    varargin_5 = combineVectorElements(x);
    d12 = b_std(b_fitness);
    trace->data[g] = 1 + g;
    d13 = rt_roundd(fitness->data[0]);
    if (d13 < 2.147483648E+9) {
      if (d13 >= -2.147483648E+9) {
        i53 = (int)d13;
      } else {
        i53 = MIN_int32_T;
      }
    } else {
      i53 = MAX_int32_T;
    }

    trace->data[g + trace->size[0]] = i53;
    varargin_5 = rt_roundd(varargin_5 / (double)i52);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        i52 = (int)varargin_5;
      } else {
        i52 = MIN_int32_T;
      }
    } else {
      i52 = MAX_int32_T;
    }

    trace->data[g + (trace->size[0] << 1)] = i52;
    varargin_5 = rt_roundd(d12);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        i52 = (int)varargin_5;
      } else {
        i52 = MIN_int32_T;
      }
    } else {
      i52 = MAX_int32_T;
    }

    trace->data[g + trace->size[0] * 3] = i52;
    varargin_5 = rt_roundd(fitness->data[fitness->size[0]]);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        i52 = (int)varargin_5;
      } else {
        i52 = MIN_int32_T;
      }
    } else {
      i52 = MAX_int32_T;
    }

    trace->data[g + (trace->size[0] << 2)] = i52;
    varargin_5 = rt_roundd(fitness->data[fitness->size[0] << 1]);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        i52 = (int)varargin_5;
      } else {
        i52 = MIN_int32_T;
      }
    } else {
      i52 = MAX_int32_T;
    }

    trace->data[g + trace->size[0] * 5] = i52;
    varargin_5 = rt_roundd(fitness->data[fitness->size[0] * 3]);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        i52 = (int)varargin_5;
      } else {
        i52 = MIN_int32_T;
      }
    } else {
      i52 = MAX_int32_T;
    }

    trace->data[g + trace->size[0] * 6] = i52;
    varargin_5 = rt_roundd(fitness->data[fitness->size[0] << 2]);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        i52 = (int)varargin_5;
      } else {
        i52 = MIN_int32_T;
      }
    } else {
      i52 = MAX_int32_T;
    }

    trace->data[g + trace->size[0] * 7] = i52;
    varargin_5 = rt_roundd(fitness->data[fitness->size[0] * 5]);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        i52 = (int)varargin_5;
      } else {
        i52 = MIN_int32_T;
      }
    } else {
      i52 = MAX_int32_T;
    }

    trace->data[g + (trace->size[0] << 3)] = i52;

    /*  IMPRIME STATUS DA EVOLUÇÃO */
    loop_ub = fitness->size[0];
    i52 = x->size[0];
    x->size[0] = loop_ub;
    emxEnsureCapacity_real_T(x, i52);
    for (i52 = 0; i52 < loop_ub; i52++) {
      x->data[i52] = fitness->data[i52];
    }

    varargin_5 = b_std(x);
    i52 = fitness->size[0];
    loop_ub = fitness->size[0];
    i53 = x->size[0];
    x->size[0] = loop_ub;
    emxEnsureCapacity_real_T(x, i53);
    for (i53 = 0; i53 < loop_ub; i53++) {
      x->data[i53] = fitness->data[i53];
    }

    printf("Ger: %d - \t Ini: %10.5f - \t Best: %10.5f - \t Mean: %10.5f - \t STD: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t "
           "NOE2: %10.5f - \t NOE3: %10.5f \n", 1 + g, fitnessB[0],
           fitness->data[0], combineVectorElements(x) / (double)i52, varargin_5,
           fitness->data[fitness->size[0]], fitness->data[fitness->size[0] << 1],
           fitness->data[fitness->size[0] * 3], fitness->data[fitness->size[0] <<
           2], fitness->data[fitness->size[0] * 5]);
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

      randperm(yk, tmpColumn);

      /* %%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%% */
      /*          maximo=0.02; */
      /*          minimo=0.002; */
      /*          taxAct = rand; */
      /*          taxAct = (maximo-minimo)*taxAct+minimo; */
      varargin_5 = (double)IQ->size[0] - (double)NumTOp;
      if (varargin_5 < 2.147483648E+9) {
        if (varargin_5 >= -2.147483648E+9) {
          i52 = (int)varargin_5;
        } else {
          i52 = MIN_int32_T;
        }
      } else {
        i52 = MAX_int32_T;
      }

      if (1 > i52) {
        loop_ub = 0;
      } else {
        loop_ub = i52;
      }

      b_loop_ub = IQ->size[1];
      i52 = b_IQ->size[0] * b_IQ->size[1];
      b_IQ->size[0] = loop_ub;
      b_IQ->size[1] = b_loop_ub;
      emxEnsureCapacity_real_T(b_IQ, i52);
      for (i52 = 0; i52 < b_loop_ub; i52++) {
        for (i53 = 0; i53 < loop_ub; i53++) {
          b_IQ->data[i53 + b_IQ->size[0] * i52] = IQ->data[i53 + IQ->size[0] *
            i52];
        }
      }

      loop_ub = rank_classic->size[0];
      i52 = c_rank_classic->size[0] * c_rank_classic->size[1];
      c_rank_classic->size[0] = loop_ub;
      c_rank_classic->size[1] = tmpColumn->size[1];
      emxEnsureCapacity_int32_T(c_rank_classic, i52);
      b_loop_ub = tmpColumn->size[1];
      for (i52 = 0; i52 < b_loop_ub; i52++) {
        for (i53 = 0; i53 < loop_ub; i53++) {
          c_rank_classic->data[i53 + c_rank_classic->size[0] * i52] =
            rank_classic->data[i53 + rank_classic->size[0] * ((int)
            tmpColumn->data[i52] - 1)];
        }
      }

      b_actIQ(b_IQ, c_rank_classic, IQtemp);

      /* %%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%% */
      loop_ub = IQtemp->size[1];
      for (i52 = 0; i52 < loop_ub; i52++) {
        b_loop_ub = IQtemp->size[0];
        for (i53 = 0; i53 < b_loop_ub; i53++) {
          IQ->data[i53 + IQ->size[0] * i52] = IQtemp->data[i53 + IQtemp->size[0]
            * i52];
        }
      }

      /* %%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%% */
      /*  NEW CLASSIC POPULATION */
      if (keeppriority) {
        b_obsIQini(IQ, numIQ, numObsIQ, ProbXEst, IC);

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
  emxFree_int32_T(&c_rank_classic);
  emxFree_real_T(&b_IQ);
  emxFree_real_T(&b_fitness);
  emxFree_int32_T(&b_rank_classic);
  emxFree_int32_T(&b_IC);
  emxFreeMatrix_cell_wrap_0(b_reshapes);
  emxFree_real_T(&x);
  emxFreeMatrix_cell_wrap_0(reshapes);
  emxFree_real_T(&IQtemp);
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
