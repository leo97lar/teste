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
#include <string.h>
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
#include "rand.h"
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
              double k1, double k2, double k3, emxArray_int32_T *bestexperimento,
              emxArray_real_T *trace)
{
  emxArray_real_T *IQ;
  int numObsIQ;
  emxArray_int32_T *IC;
  int qEnd;
  int kEnd;
  emxArray_int32_T *best;
  emxArray_real_T *bestFitness;
  int n;
  emxArray_int32_T *idx;
  int yk;
  int k;
  emxArray_real_T *fitness;
  emxArray_int32_T *aux_classic;
  emxArray_real_T *aux_fitness;
  emxArray_int32_T *rank_classic;
  emxArray_real_T *tmpColumn;
  cell_wrap_0 reshapes[2];
  cell_wrap_0 b_reshapes[2];
  emxArray_real_T *x;
  emxArray_int32_T *iwork;
  emxArray_int32_T *b_IC;
  emxArray_int8_T *num2bin;
  emxArray_real_T *r0;
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
  int j;
  double varargin_5;
  int pEnd;
  boolean_T empty_non_axis_sizes;
  signed char input_sizes_idx_1;
  int p;
  int q;
  double d0;
  double d1;
  double d2;
  double d3;
  double d4;
  int i;
  (void)taxEQ;
  (void)ProbXEst;
  emxInit_real_T(&IQ, 2);

  /*  INICIALIZA POPULAÇÃO QUANTICA.  */
  CreaPoQunniforme(NumTOp, numIQ, IQ);

  /*  IQ uniforme */
  /*  INICIALIZA POPULAÇÃO CLÁSSICA. */
  if (b_rem(numIC, numIQ) == 0) {
    numObsIQ = rdivide_helper(numIC, numIQ);
  }

  emxInit_int32_T(&IC, 2);
  tic();

  /* [ IC ] = obsIQini( IQ,numIQ,numObsIQ,ProbXEst);        % Observaciones de los IQ garantizando que se mantengan en el rango Prioridad             */
  obsIQ(IQ, numIQ, numObsIQ, IC);

  /*  Observaciones de los IQ */
  toc();

  /*  PARÂMETROS DE INTERESSE */
  qEnd = IC->size[0];
  kEnd = bestexperimento->size[0];
  bestexperimento->size[0] = qEnd;
  emxEnsureCapacity_int32_T(bestexperimento, kEnd);
  for (kEnd = 0; kEnd < qEnd; kEnd++) {
    bestexperimento->data[kEnd] = IC->data[kEnd];
  }

  emxInit_int32_T(&best, 2);
  kEnd = best->size[0] * best->size[1];
  best->size[0] = NumTOp;
  best->size[1] = numIC;
  emxEnsureCapacity_int32_T(best, kEnd);
  qEnd = NumTOp * numIC;
  for (kEnd = 0; kEnd < qEnd; kEnd++) {
    best->data[kEnd] = 0;
  }

  emxInit_real_T(&bestFitness, 2);
  kEnd = bestFitness->size[0] * bestFitness->size[1];
  bestFitness->size[0] = numIC;
  bestFitness->size[1] = 6;
  emxEnsureCapacity_real_T(bestFitness, kEnd);
  qEnd = numIC * 6;
  for (kEnd = 0; kEnd < qEnd; kEnd++) {
    bestFitness->data[kEnd] = 0.0;
  }

  if (NumTOp < 1) {
    n = 0;
  } else {
    n = NumTOp;
  }

  emxInit_int32_T(&idx, 2);
  kEnd = idx->size[0] * idx->size[1];
  idx->size[0] = 1;
  idx->size[1] = n;
  emxEnsureCapacity_int32_T(idx, kEnd);
  if (n > 0) {
    idx->data[0] = 1;
    yk = 1;
    for (k = 2; k <= n; k++) {
      yk++;
      idx->data[k - 1] = yk;
    }
  }

  qEnd = idx->size[1];
  for (kEnd = 0; kEnd < qEnd; kEnd++) {
    best->data[kEnd] = idx->data[kEnd];
  }

  for (kEnd = 0; kEnd < 6; kEnd++) {
    bestFitness->data[bestFitness->size[0] * kEnd] = fitnessB[kEnd];
  }

  /*  INICIALIZA LOOPING */
  kEnd = trace->size[0] * trace->size[1];
  trace->size[0] = generations;
  trace->size[1] = 9;
  emxEnsureCapacity_real_T(trace, kEnd);
  emxInit_real_T(&fitness, 2);
  emxInit_int32_T(&aux_classic, 2);
  emxInit_real_T(&aux_fitness, 2);
  emxInit_int32_T(&rank_classic, 2);
  emxInit_real_T(&tmpColumn, 2);
  emxInitMatrix_cell_wrap_0(reshapes);
  emxInitMatrix_cell_wrap_0(b_reshapes);
  emxInit_real_T(&x, 1);
  emxInit_int32_T(&iwork, 1);
  emxInit_int32_T(&b_IC, 2);
  emxInit_int8_T(&num2bin, 2);
  emxInit_real_T(&r0, 2);
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
    kEnd = fitness->size[0] * fitness->size[1];
    fitness->size[0] = numIC;
    fitness->size[1] = 6;
    emxEnsureCapacity_real_T(fitness, kEnd);
    qEnd = numIC * 6;
    for (kEnd = 0; kEnd < qEnd; kEnd++) {
      fitness->data[kEnd] = 0.0;
    }

    /*  [fitness,NOFP,TmNOFP,NOE2,NOE3] */
    for (j = 0; j < numIC; j++) {
      qEnd = IC->size[0];
      kEnd = iwork->size[0];
      iwork->size[0] = qEnd;
      emxEnsureCapacity_int32_T(iwork, kEnd);
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        iwork->data[kEnd] = IC->data[kEnd + IC->size[0] * j];
      }

      kEnd = b_PCPrO->size[0] * b_PCPrO->size[1];
      b_PCPrO->size[0] = PCPrO->size[0];
      b_PCPrO->size[1] = PCPrO->size[1];
      emxEnsureCapacity_int32_T(b_PCPrO, kEnd);
      qEnd = PCPrO->size[0] * PCPrO->size[1];
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        b_PCPrO->data[kEnd] = PCPrO->data[kEnd];
      }

      kEnd = b_PME->size[0] * b_PME->size[1];
      b_PME->size[0] = PME->size[0];
      b_PME->size[1] = PME->size[1];
      emxEnsureCapacity_int32_T(b_PME, kEnd);
      qEnd = PME->size[0] * PME->size[1];
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        b_PME->data[kEnd] = PME->data[kEnd];
      }

      kEnd = b_PMA->size[0] * b_PMA->size[1];
      b_PMA->size[0] = PMA->size[0];
      b_PMA->size[1] = PMA->size[1];
      emxEnsureCapacity_int32_T(b_PMA, kEnd);
      qEnd = PMA->size[0] * PMA->size[1];
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        b_PMA->data[kEnd] = PMA->data[kEnd];
      }

      kEnd = b_PMAn->size[0] * b_PMAn->size[1];
      b_PMAn->size[0] = PMAn->size[0];
      b_PMAn->size[1] = PMAn->size[1];
      emxEnsureCapacity_int32_T(b_PMAn, kEnd);
      qEnd = PMAn->size[0] * PMAn->size[1];
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        b_PMAn->data[kEnd] = PMAn->data[kEnd];
      }

      kEnd = b_PS->size[0] * b_PS->size[1];
      b_PS->size[0] = PS->size[0];
      b_PS->size[1] = PS->size[1];
      emxEnsureCapacity_int32_T(b_PS, kEnd);
      qEnd = PS->size[0] * PS->size[1];
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        b_PS->data[kEnd] = PS->data[kEnd];
      }

      kEnd = b_PCPO->size[0] * b_PCPO->size[1];
      b_PCPO->size[0] = PCPO->size[0];
      b_PCPO->size[1] = PCPO->size[1];
      emxEnsureCapacity_int32_T(b_PCPO, kEnd);
      qEnd = PCPO->size[0] * PCPO->size[1];
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        b_PCPO->data[kEnd] = PCPO->data[kEnd];
      }

      kEnd = b_PCR->size[0] * b_PCR->size[1];
      b_PCR->size[0] = PCR->size[0];
      b_PCR->size[1] = PCR->size[1];
      emxEnsureCapacity_int32_T(b_PCR, kEnd);
      qEnd = PCR->size[0] * PCR->size[1];
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        b_PCR->data[kEnd] = PCR->data[kEnd];
      }

      kEnd = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
      b_TimeUsoRec->size[0] = TimeUsoRec->size[0];
      b_TimeUsoRec->size[1] = 7;
      emxEnsureCapacity_int32_T(b_TimeUsoRec, kEnd);
      qEnd = TimeUsoRec->size[0] * TimeUsoRec->size[1];
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        b_TimeUsoRec->data[kEnd] = TimeUsoRec->data[kEnd];
      }

      kEnd = b_EP->size[0];
      b_EP->size[0] = EP->size[0];
      emxEnsureCapacity_real_T(b_EP, kEnd);
      qEnd = EP->size[0];
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        b_EP->data[kEnd] = EP->data[kEnd];
      }

      b_sch(NumTOp, iwork, NumRec, b_PCPrO, b_PME, b_PMA, b_PMAn, b_PS, b_PCPO,
            b_PCR, Dia, Data, b_TimeUsoRec, DispMExD, b_EP, k0, k1, k2, k3, &d0,
            &varargin_5, &d1, &d2, &d3, &d4);
      fitness->data[j] = d0;
      fitness->data[j + fitness->size[0]] = varargin_5;
      fitness->data[j + (fitness->size[0] << 1)] = d1;
      fitness->data[j + fitness->size[0] * 3] = d2;
      fitness->data[j + (fitness->size[0] << 2)] = d3;
      fitness->data[j + fitness->size[0] * 5] = d4;
    }

    /* ATUALIZA POPULAÇÃO B(T) */
    if (1 + g == 1) {
      kEnd = best->size[0];
      if (kEnd != 0) {
        pEnd = best->size[0];
      } else if ((IC->size[0] != 0) && (IC->size[1] != 0)) {
        pEnd = IC->size[0];
      } else {
        kEnd = best->size[0];
        if (kEnd > 0) {
          pEnd = best->size[0];
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
        kEnd = best->size[0];
        if (kEnd != 0) {
          input_sizes_idx_1 = 1;
        } else {
          input_sizes_idx_1 = 0;
        }
      }

      qEnd = best->size[0];
      kEnd = iwork->size[0];
      iwork->size[0] = qEnd;
      emxEnsureCapacity_int32_T(iwork, kEnd);
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        iwork->data[kEnd] = best->data[kEnd];
      }

      kEnd = b_reshapes[0].f1->size[0] * b_reshapes[0].f1->size[1];
      b_reshapes[0].f1->size[0] = pEnd;
      b_reshapes[0].f1->size[1] = input_sizes_idx_1;
      emxEnsureCapacity_int32_T(b_reshapes[0].f1, kEnd);
      qEnd = pEnd * input_sizes_idx_1;
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        b_reshapes[0].f1->data[kEnd] = iwork->data[kEnd];
      }

      if (empty_non_axis_sizes || ((IC->size[0] != 0) && (IC->size[1] != 0))) {
        qEnd = IC->size[1];
      } else {
        qEnd = 0;
      }

      kEnd = aux_classic->size[0] * aux_classic->size[1];
      aux_classic->size[0] = b_reshapes[0].f1->size[0];
      aux_classic->size[1] = b_reshapes[0].f1->size[1] + qEnd;
      emxEnsureCapacity_int32_T(aux_classic, kEnd);
      p = b_reshapes[0].f1->size[1];
      for (kEnd = 0; kEnd < p; kEnd++) {
        yk = b_reshapes[0].f1->size[0];
        for (q = 0; q < yk; q++) {
          aux_classic->data[q + aux_classic->size[0] * kEnd] = b_reshapes[0].
            f1->data[q + b_reshapes[0].f1->size[0] * kEnd];
        }
      }

      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        for (q = 0; q < pEnd; q++) {
          aux_classic->data[q + aux_classic->size[0] * (kEnd + b_reshapes[0].
            f1->size[1])] = IC->data[q + pEnd * kEnd];
        }
      }

      kEnd = aux_fitness->size[0] * aux_fitness->size[1];
      aux_fitness->size[0] = 1 + fitness->size[0];
      aux_fitness->size[1] = 6;
      emxEnsureCapacity_real_T(aux_fitness, kEnd);
      for (kEnd = 0; kEnd < 6; kEnd++) {
        aux_fitness->data[aux_fitness->size[0] * kEnd] = bestFitness->
          data[bestFitness->size[0] * kEnd];
      }

      for (kEnd = 0; kEnd < 6; kEnd++) {
        qEnd = fitness->size[0];
        for (q = 0; q < qEnd; q++) {
          aux_fitness->data[(q + aux_fitness->size[0] * kEnd) + 1] =
            fitness->data[q + fitness->size[0] * kEnd];
        }
      }
    } else {
      varargin_5 = rt_roundd((double)numIC * taxE);
      if (varargin_5 < 2.147483648E+9) {
        if (varargin_5 >= -2.147483648E+9) {
          kEnd = (int)varargin_5;
        } else {
          kEnd = MIN_int32_T;
        }
      } else {
        kEnd = MAX_int32_T;
      }

      yk = (int)rt_roundd((double)kEnd / 100.0);
      kEnd = best->size[0];
      if (kEnd != 0) {
        pEnd = best->size[0];
      } else if ((IC->size[0] != 0) && (IC->size[1] != 0)) {
        pEnd = IC->size[0];
      } else {
        kEnd = best->size[0];
        if (kEnd > 0) {
          pEnd = best->size[0];
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
        kEnd = best->size[0];
        if (kEnd != 0) {
          input_sizes_idx_1 = 1;
        } else {
          input_sizes_idx_1 = 0;
        }
      }

      qEnd = best->size[0];
      kEnd = iwork->size[0];
      iwork->size[0] = qEnd;
      emxEnsureCapacity_int32_T(iwork, kEnd);
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        iwork->data[kEnd] = best->data[kEnd + best->size[0] * (yk - 1)];
      }

      kEnd = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
      reshapes[0].f1->size[0] = pEnd;
      reshapes[0].f1->size[1] = input_sizes_idx_1;
      emxEnsureCapacity_int32_T(reshapes[0].f1, kEnd);
      qEnd = pEnd * input_sizes_idx_1;
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        reshapes[0].f1->data[kEnd] = iwork->data[kEnd];
      }

      if (empty_non_axis_sizes || ((IC->size[0] != 0) && (IC->size[1] != 0))) {
        qEnd = IC->size[1];
      } else {
        qEnd = 0;
      }

      kEnd = aux_classic->size[0] * aux_classic->size[1];
      aux_classic->size[0] = reshapes[0].f1->size[0];
      aux_classic->size[1] = reshapes[0].f1->size[1] + qEnd;
      emxEnsureCapacity_int32_T(aux_classic, kEnd);
      p = reshapes[0].f1->size[1];
      for (kEnd = 0; kEnd < p; kEnd++) {
        yk = reshapes[0].f1->size[0];
        for (q = 0; q < yk; q++) {
          aux_classic->data[q + aux_classic->size[0] * kEnd] = reshapes[0]
            .f1->data[q + reshapes[0].f1->size[0] * kEnd];
        }
      }

      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        for (q = 0; q < pEnd; q++) {
          aux_classic->data[q + aux_classic->size[0] * (kEnd + reshapes[0]
            .f1->size[1])] = IC->data[q + pEnd * kEnd];
        }
      }

      if (varargin_5 < 2.147483648E+9) {
        if (varargin_5 >= -2.147483648E+9) {
          kEnd = (int)varargin_5;
        } else {
          kEnd = MIN_int32_T;
        }
      } else {
        kEnd = MAX_int32_T;
      }

      yk = (int)rt_roundd((double)kEnd / 100.0);
      kEnd = aux_fitness->size[0] * aux_fitness->size[1];
      aux_fitness->size[0] = 1 + fitness->size[0];
      aux_fitness->size[1] = 6;
      emxEnsureCapacity_real_T(aux_fitness, kEnd);
      for (kEnd = 0; kEnd < 6; kEnd++) {
        aux_fitness->data[aux_fitness->size[0] * kEnd] = bestFitness->data[(yk +
          bestFitness->size[0] * kEnd) - 1];
      }

      for (kEnd = 0; kEnd < 6; kEnd++) {
        qEnd = fitness->size[0];
        for (q = 0; q < qEnd; q++) {
          aux_fitness->data[(q + aux_fitness->size[0] * kEnd) + 1] =
            fitness->data[q + fitness->size[0] * kEnd];
        }
      }
    }

    qEnd = aux_fitness->size[0];
    kEnd = x->size[0];
    x->size[0] = qEnd;
    emxEnsureCapacity_real_T(x, kEnd);
    for (kEnd = 0; kEnd < qEnd; kEnd++) {
      x->data[kEnd] = aux_fitness->data[kEnd];
    }

    sort(x, iwork);
    kEnd = x->size[0];
    x->size[0] = iwork->size[0];
    emxEnsureCapacity_real_T(x, kEnd);
    qEnd = iwork->size[0];
    for (kEnd = 0; kEnd < qEnd; kEnd++) {
      x->data[kEnd] = iwork->data[kEnd];
    }

    kEnd = fitness->size[0] * fitness->size[1];
    fitness->size[0] = x->size[0];
    fitness->size[1] = 6;
    emxEnsureCapacity_real_T(fitness, kEnd);
    for (kEnd = 0; kEnd < 6; kEnd++) {
      qEnd = x->size[0];
      for (q = 0; q < qEnd; q++) {
        fitness->data[q + fitness->size[0] * kEnd] = aux_fitness->data[((int)
          x->data[q] + aux_fitness->size[0] * kEnd) - 1];
      }
    }

    qEnd = aux_classic->size[0];
    kEnd = rank_classic->size[0] * rank_classic->size[1];
    rank_classic->size[0] = qEnd;
    rank_classic->size[1] = x->size[0];
    emxEnsureCapacity_int32_T(rank_classic, kEnd);
    p = x->size[0];
    for (kEnd = 0; kEnd < p; kEnd++) {
      for (q = 0; q < qEnd; q++) {
        rank_classic->data[q + rank_classic->size[0] * kEnd] = aux_classic->
          data[q + aux_classic->size[0] * ((int)x->data[kEnd] - 1)];
      }
    }

    /* REMOVE INDIVÍDUOS MAIS FRACOS (EXCEDENTES) */
    if (1 > numIC) {
      qEnd = 0;
    } else {
      qEnd = numIC;
    }

    p = aux_classic->size[0] - 1;
    kEnd = best->size[0] * best->size[1];
    best->size[0] = p + 1;
    best->size[1] = qEnd;
    emxEnsureCapacity_int32_T(best, kEnd);
    for (kEnd = 0; kEnd < qEnd; kEnd++) {
      for (q = 0; q <= p; q++) {
        best->data[q + best->size[0] * kEnd] = rank_classic->data[q +
          rank_classic->size[0] * kEnd];
      }
    }

    if (1 > numIC) {
      p = -1;
    } else {
      p = numIC - 1;
    }

    kEnd = bestFitness->size[0] * bestFitness->size[1];
    bestFitness->size[0] = p + 1;
    bestFitness->size[1] = 6;
    emxEnsureCapacity_real_T(bestFitness, kEnd);
    for (kEnd = 0; kEnd < 6; kEnd++) {
      for (q = 0; q <= p; q++) {
        bestFitness->data[q + bestFitness->size[0] * kEnd] = fitness->data[q +
          fitness->size[0] * kEnd];
      }
    }

    /*  GUARDA MELHOR INDIVÍDUO */
    yk = aux_classic->size[0] - 1;
    kEnd = bestexperimento->size[0];
    bestexperimento->size[0] = yk + 1;
    emxEnsureCapacity_int32_T(bestexperimento, kEnd);
    for (kEnd = 0; kEnd <= yk; kEnd++) {
      bestexperimento->data[kEnd] = rank_classic->data[kEnd];
    }

    /*  SALVA A GERAÇÃO, FITNESS do Melhor ind., a MÉDIA DO FITNESS e a STD DO FITNESS  */
    kEnd = x->size[0];
    x->size[0] = p + 1;
    emxEnsureCapacity_real_T(x, kEnd);
    for (kEnd = 0; kEnd <= p; kEnd++) {
      x->data[kEnd] = fitness->data[kEnd];
    }

    kEnd = b_EP->size[0];
    b_EP->size[0] = p + 1;
    emxEnsureCapacity_real_T(b_EP, kEnd);
    for (kEnd = 0; kEnd <= p; kEnd++) {
      b_EP->data[kEnd] = fitness->data[kEnd];
    }

    varargin_5 = combineVectorElements(x);
    d1 = b_std(b_EP);
    trace->data[g] = 1 + g;
    d2 = rt_roundd(fitness->data[0]);
    if (d2 < 2.147483648E+9) {
      if (d2 >= -2.147483648E+9) {
        kEnd = (int)d2;
      } else {
        kEnd = MIN_int32_T;
      }
    } else {
      kEnd = MAX_int32_T;
    }

    trace->data[g + trace->size[0]] = kEnd;
    varargin_5 = rt_roundd(varargin_5 / (double)(p + 1));
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        kEnd = (int)varargin_5;
      } else {
        kEnd = MIN_int32_T;
      }
    } else {
      kEnd = MAX_int32_T;
    }

    trace->data[g + (trace->size[0] << 1)] = kEnd;
    varargin_5 = rt_roundd(d1);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        kEnd = (int)varargin_5;
      } else {
        kEnd = MIN_int32_T;
      }
    } else {
      kEnd = MAX_int32_T;
    }

    trace->data[g + trace->size[0] * 3] = kEnd;
    varargin_5 = rt_roundd(fitness->data[fitness->size[0]]);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        kEnd = (int)varargin_5;
      } else {
        kEnd = MIN_int32_T;
      }
    } else {
      kEnd = MAX_int32_T;
    }

    trace->data[g + (trace->size[0] << 2)] = kEnd;
    varargin_5 = rt_roundd(fitness->data[fitness->size[0] << 1]);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        kEnd = (int)varargin_5;
      } else {
        kEnd = MIN_int32_T;
      }
    } else {
      kEnd = MAX_int32_T;
    }

    trace->data[g + trace->size[0] * 5] = kEnd;
    varargin_5 = rt_roundd(fitness->data[fitness->size[0] * 3]);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        kEnd = (int)varargin_5;
      } else {
        kEnd = MIN_int32_T;
      }
    } else {
      kEnd = MAX_int32_T;
    }

    trace->data[g + trace->size[0] * 6] = kEnd;
    varargin_5 = rt_roundd(fitness->data[fitness->size[0] << 2]);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        kEnd = (int)varargin_5;
      } else {
        kEnd = MIN_int32_T;
      }
    } else {
      kEnd = MAX_int32_T;
    }

    trace->data[g + trace->size[0] * 7] = kEnd;
    varargin_5 = rt_roundd(fitness->data[fitness->size[0] * 5]);
    if (varargin_5 < 2.147483648E+9) {
      if (varargin_5 >= -2.147483648E+9) {
        kEnd = (int)varargin_5;
      } else {
        kEnd = MIN_int32_T;
      }
    } else {
      kEnd = MAX_int32_T;
    }

    trace->data[g + (trace->size[0] << 3)] = kEnd;

    /*  IMPRIME STATUS DA EVOLUÇÃO */
    kEnd = x->size[0];
    x->size[0] = p + 1;
    emxEnsureCapacity_real_T(x, kEnd);
    for (kEnd = 0; kEnd <= p; kEnd++) {
      x->data[kEnd] = fitness->data[kEnd];
    }

    varargin_5 = b_std(x);
    kEnd = x->size[0];
    x->size[0] = p + 1;
    emxEnsureCapacity_real_T(x, kEnd);
    for (kEnd = 0; kEnd <= p; kEnd++) {
      x->data[kEnd] = fitness->data[kEnd];
    }

    printf("Ger: %d - \t Ini: %10.5f - \t Best: %10.5f - \t Mean: %10.5f - \t STD: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t "
           "NOE2: %10.5f - \t NOE3: %10.5f \n", 1 + g, fitnessB[0],
           fitness->data[0], combineVectorElements(x) / (double)(p + 1),
           varargin_5, fitness->data[fitness->size[0]], fitness->data
           [fitness->size[0] << 1], fitness->data[fitness->size[0] * 3],
           fitness->data[fitness->size[0] << 2], fitness->data[fitness->size[0] *
           5]);
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

      c_rand(yk, tmpColumn);
      n = tmpColumn->size[1] + 1;
      kEnd = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = tmpColumn->size[1];
      emxEnsureCapacity_int32_T(idx, kEnd);
      qEnd = tmpColumn->size[1];
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        idx->data[kEnd] = 0;
      }

      if (tmpColumn->size[1] != 0) {
        kEnd = iwork->size[0];
        iwork->size[0] = tmpColumn->size[1];
        emxEnsureCapacity_int32_T(iwork, kEnd);
        kEnd = tmpColumn->size[1] - 1;
        for (k = 1; k <= kEnd; k += 2) {
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
      kEnd = tmpColumn->size[0] * tmpColumn->size[1];
      tmpColumn->size[0] = 1;
      tmpColumn->size[1] = pEnd;
      emxEnsureCapacity_real_T(tmpColumn, kEnd);
      qEnd = yk * pEnd;
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        tmpColumn->data[kEnd] = idx->data[kEnd];
      }

      /* %%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%% */
      /*          maximo=0.02; */
      /*          minimo=0.002; */
      /*          taxAct = rand; */
      /*          taxAct = (maximo-minimo)*taxAct+minimo; */
      kEnd = IQ->size[0] - NumTOp;
      if (1 > kEnd) {
        qEnd = 0;
      } else {
        qEnd = kEnd;
      }

      p = aux_classic->size[0] - 1;
      kEnd = b_IC->size[0] * b_IC->size[1];
      b_IC->size[0] = p + 1;
      b_IC->size[1] = tmpColumn->size[1];
      emxEnsureCapacity_int32_T(b_IC, kEnd);
      yk = tmpColumn->size[1];
      for (kEnd = 0; kEnd < yk; kEnd++) {
        for (q = 0; q <= p; q++) {
          b_IC->data[q + b_IC->size[0] * kEnd] = rank_classic->data[q +
            rank_classic->size[0] * ((int)tmpColumn->data[kEnd] - 1)];
        }
      }

      /* UNTITLED5 Summary of this function goes here */
      /*    Detailed explanation goes here */
      /* Convertir de numerico a representacion binaria. */
      kEnd = aux_classic->size[0];
      q = aux_classic->size[0];
      yk = iwork->size[0];
      iwork->size[0] = tmpColumn->size[1];
      emxEnsureCapacity_int32_T(iwork, yk);
      p = tmpColumn->size[1];
      for (yk = 0; yk < p; yk++) {
        iwork->data[yk] = (int)tmpColumn->data[yk];
      }

      yk = num2bin->size[0] * num2bin->size[1];
      num2bin->size[0] = (int)((double)kEnd * (double)iwork->size[0]);
      num2bin->size[1] = q;
      emxEnsureCapacity_int8_T(num2bin, yk);
      yk = iwork->size[0];
      iwork->size[0] = tmpColumn->size[1];
      emxEnsureCapacity_int32_T(iwork, yk);
      p = tmpColumn->size[1];
      for (yk = 0; yk < p; yk++) {
        iwork->data[yk] = (int)tmpColumn->data[yk];
      }

      p = (int)((double)kEnd * (double)iwork->size[0]) * q;
      for (kEnd = 0; kEnd < p; kEnd++) {
        num2bin->data[kEnd] = 0;
      }

      kEnd = aux_classic->size[0];
      q = iwork->size[0];
      iwork->size[0] = tmpColumn->size[1];
      emxEnsureCapacity_int32_T(iwork, q);
      p = tmpColumn->size[1];
      for (q = 0; q < p; q++) {
        iwork->data[q] = (int)tmpColumn->data[q];
      }

      kEnd = (int)((double)kEnd * (double)iwork->size[0]);
      for (i = 0; i < kEnd; i++) {
        num2bin->data[i + num2bin->size[0] * (b_IC->data[i] - 1)] = 1;
      }

      /* %%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%% */
      p = IQ->size[1] - 1;
      kEnd = r0->size[0] * r0->size[1];
      r0->size[0] = qEnd;
      r0->size[1] = p + 1;
      emxEnsureCapacity_real_T(r0, kEnd);
      for (kEnd = 0; kEnd <= p; kEnd++) {
        for (q = 0; q < qEnd; q++) {
          r0->data[q + r0->size[0] * kEnd] = 0.99999 * IQ->data[q + IQ->size[0] *
            kEnd] + 1.0E-5 * (double)num2bin->data[q + num2bin->size[0] * kEnd];
        }
      }

      qEnd = r0->size[1];
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        p = r0->size[0];
        for (q = 0; q < p; q++) {
          IQ->data[q + IQ->size[0] * kEnd] = r0->data[q + r0->size[0] * kEnd];
        }
      }

      /* %%%%%%%%%%%%% MODIFICADO %%%%%%%%%%%%%%%%% */
      /*  NEW CLASSIC POPULATION */
      /*         [ IC ] = obsIQini( IQ,numIQ,numObsIQ,ProbXEst); */
      obsIQ(IQ, numIQ, numObsIQ, IC);

      /*  Observaciones de los IQ */
      /*         best = best(:,1:(numIC*taxEQ)/100); */
      /*         bestFitness = bestFitness(1:(numIC*taxEQ)/100,:); */
    } else {
      /*  Crossover clasico          */
      p = aux_classic->size[0] - 1;
      kEnd = IC->size[0] * IC->size[1];
      IC->size[0] = p + 1;
      IC->size[1] = qEnd;
      emxEnsureCapacity_int32_T(IC, kEnd);
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        for (q = 0; q <= p; q++) {
          IC->data[q + IC->size[0] * kEnd] = rank_classic->data[q +
            rank_classic->size[0] * kEnd];
        }
      }

      kEnd = rank_classic->size[0] * rank_classic->size[1];
      rank_classic->size[0] = IC->size[0];
      rank_classic->size[1] = IC->size[1];
      emxEnsureCapacity_int32_T(rank_classic, kEnd);
      qEnd = IC->size[1];
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        p = IC->size[0];
        for (q = 0; q < p; q++) {
          rank_classic->data[q + rank_classic->size[0] * kEnd] = IC->data[q +
            IC->size[0] * kEnd];
        }
      }

      cc(rank_classic, numIC, taxC, NumTOp, IC);

      /*         best = best(:,1:(numIC*taxE)/100); */
      /*         bestFitness = bestFitness(1:(numIC*taxE)/100,:); */
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
  emxFree_real_T(&r0);
  emxFree_int8_T(&num2bin);
  emxFree_int32_T(&b_IC);
  emxFree_int32_T(&iwork);
  emxFree_int32_T(&idx);
  emxFree_real_T(&x);
  emxFreeMatrix_cell_wrap_0(b_reshapes);
  emxFreeMatrix_cell_wrap_0(reshapes);
  emxFree_real_T(&tmpColumn);
  emxFree_int32_T(&rank_classic);
  emxFree_real_T(&aux_fitness);
  emxFree_int32_T(&aux_classic);
  emxFree_real_T(&fitness);
  emxFree_real_T(&bestFitness);
  emxFree_int32_T(&best);
  emxFree_int32_T(&IC);
  emxFree_real_T(&IQ);
}

void b_aevSPLap(int NumTOp, const int NumRec[7], const emxArray_int32_T *PCPrO,
                const emxArray_int32_T *PME, const emxArray_int32_T *PMA, const
                emxArray_int32_T *PMAn, const emxArray_int32_T *PS, const
                emxArray_int32_T *PCPO, const emxArray_int32_T *PCR, const int
                Dia_data[], const int Dia_size[2], const int TimeUsoRec_data[],
                const double fitnessB[6], const int DispMExD_data[], const int
                DispMExD_size[2], const int EP_data[], int bestexperimento_data[],
                int bestexperimento_size[1], double trace[9])
{
  emxArray_real_T *IQ;
  int ibcol;
  int yk;
  emxArray_int32_T *IC;
  int ibmat;
  emxArray_int32_T *best;
  int itilerow;
  int k;
  double bestFitness[120];
  emxArray_int32_T *y;
  emxArray_int32_T *b_y;
  emxArray_int32_T *c_y;
  emxArray_int32_T *d_y;
  double fitness[120];
  emxArray_int32_T *b_PCPrO;
  emxArray_int32_T *b_PME;
  emxArray_int32_T *b_PMA;
  emxArray_int32_T *b_PMAn;
  emxArray_int32_T *b_PS;
  emxArray_int32_T *b_PCPO;
  emxArray_int32_T *b_PCR;
  int IC_data[2000];
  cell_wrap_0 reshapes[2];
  emxArray_int32_T *result;
  double x[21];
  double aux_fitness[126];
  int iidx[21];
  emxArray_int32_T *rank_classic;
  double b_fitness[126];
  static int b_TimeUsoRec_data[14000];
  int EP_size[1];
  int b_EP_data[2000];
  double b_aux_fitness[126];
  double e_y;
  double c_fitness[20];
  double aux_fitness_tmp;
  double c_aux_fitness[126];
  double d_aux_fitness[126];
  double e_aux_fitness[126];
  double f_aux_fitness[126];
  emxArray_int32_T *b_IC;
  emxInit_real_T(&IQ, 2);

  /*  INICIALIZA POPULAÇÃO QUANTICA.  */
  /* UNTITLED3 Summary of this function goes here */
  /*    Detailed explanation goes here */
  ibcol = IQ->size[0] * IQ->size[1];
  IQ->size[0] = 10000;
  IQ->size[1] = 2000;
  emxEnsureCapacity_real_T(IQ, ibcol);
  for (yk = 0; yk < 2000; yk++) {
    ibmat = yk * 10000;
    for (itilerow = 0; itilerow < 5; itilerow++) {
      ibcol = ibmat + itilerow * 2000;
      for (k = 0; k < 2000; k++) {
        IQ->data[ibcol + k] = 0.0005;
      }
    }
  }

  emxInit_int32_T(&IC, 2);
  emxInit_int32_T(&best, 2);

  /*  IQ uniforme */
  /*  INICIALIZA POPULAÇÃO CLÁSSICA. */
  tic();

  /* [ IC ] = obsIQini( IQ,numIQ,numObsIQ,ProbXEst);        % Observaciones de los IQ garantizando que se mantengan en el rango Prioridad             */
  b_obsIQ(IQ, IC);

  /*  Observaciones de los IQ */
  toc();

  /*  PARÂMETROS DE INTERESSE */
  ibcol = best->size[0] * best->size[1];
  best->size[0] = 2000;
  best->size[1] = 20;
  emxEnsureCapacity_int32_T(best, ibcol);
  emxFree_real_T(&IQ);
  for (ibcol = 0; ibcol < 40000; ibcol++) {
    best->data[ibcol] = 0;
  }

  memset(&bestFitness[0], 0, 120U * sizeof(double));
  if (NumTOp < 1) {
    ibmat = 0;
  } else {
    ibmat = NumTOp;
  }

  emxInit_int32_T(&y, 2);
  ibcol = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = ibmat;
  emxEnsureCapacity_int32_T(y, ibcol);
  if (ibmat > 0) {
    y->data[0] = 1;
    yk = 1;
    for (k = 2; k <= ibmat; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }

  emxInit_int32_T(&b_y, 2);
  ibcol = b_y->size[0] * b_y->size[1];
  b_y->size[0] = 1;
  b_y->size[1] = 2000;
  emxEnsureCapacity_int32_T(b_y, ibcol);
  b_y->data[0] = 1;
  yk = 1;
  for (k = 0; k < 1999; k++) {
    yk++;
    b_y->data[k + 1] = yk;
  }

  emxInit_int32_T(&c_y, 1);
  ibcol = c_y->size[0];
  c_y->size[0] = y->size[1];
  emxEnsureCapacity_int32_T(c_y, ibcol);
  ibmat = y->size[1];
  for (ibcol = 0; ibcol < ibmat; ibcol++) {
    c_y->data[ibcol] = y->data[ibcol];
  }

  emxFree_int32_T(&c_y);
  emxFree_int32_T(&y);
  emxInit_int32_T(&d_y, 1);
  ibcol = d_y->size[0];
  d_y->size[0] = b_y->size[1];
  emxEnsureCapacity_int32_T(d_y, ibcol);
  ibmat = b_y->size[1];
  for (ibcol = 0; ibcol < ibmat; ibcol++) {
    d_y->data[ibcol] = b_y->data[ibcol];
  }

  emxFree_int32_T(&b_y);
  for (ibcol = 0; ibcol < 2000; ibcol++) {
    best->data[ibcol] = d_y->data[ibcol];
  }

  emxFree_int32_T(&d_y);
  for (ibcol = 0; ibcol < 6; ibcol++) {
    bestFitness[20 * ibcol] = fitnessB[ibcol];
  }

  /*  INICIALIZA LOOPING */
  memset(&fitness[0], 0, 120U * sizeof(double));

  /*  [fitness,NOFP,TmNOFP,NOE2,NOE3] */
  emxInit_int32_T(&b_PCPrO, 2);
  emxInit_int32_T(&b_PME, 2);
  emxInit_int32_T(&b_PMA, 2);
  emxInit_int32_T(&b_PMAn, 2);
  emxInit_int32_T(&b_PS, 2);
  emxInit_int32_T(&b_PCPO, 2);
  emxInit_int32_T(&b_PCR, 2);
  for (yk = 0; yk < 20; yk++) {
    for (ibcol = 0; ibcol < 2000; ibcol++) {
      IC_data[ibcol] = IC->data[ibcol + 2000 * yk];
    }

    ibcol = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 2000;
    b_PCPrO->size[1] = 10;
    emxEnsureCapacity_int32_T(b_PCPrO, ibcol);
    for (ibcol = 0; ibcol < 20000; ibcol++) {
      b_PCPrO->data[ibcol] = PCPrO->data[ibcol];
    }

    ibcol = b_PME->size[0] * b_PME->size[1];
    b_PME->size[0] = 2000;
    b_PME->size[1] = PME->size[1];
    emxEnsureCapacity_int32_T(b_PME, ibcol);
    ibmat = PME->size[0] * PME->size[1];
    for (ibcol = 0; ibcol < ibmat; ibcol++) {
      b_PME->data[ibcol] = PME->data[ibcol];
    }

    ibcol = b_PMA->size[0] * b_PMA->size[1];
    b_PMA->size[0] = 2000;
    b_PMA->size[1] = PMA->size[1];
    emxEnsureCapacity_int32_T(b_PMA, ibcol);
    ibmat = PMA->size[0] * PMA->size[1];
    for (ibcol = 0; ibcol < ibmat; ibcol++) {
      b_PMA->data[ibcol] = PMA->data[ibcol];
    }

    ibcol = b_PMAn->size[0] * b_PMAn->size[1];
    b_PMAn->size[0] = 2000;
    b_PMAn->size[1] = PMAn->size[1];
    emxEnsureCapacity_int32_T(b_PMAn, ibcol);
    ibmat = PMAn->size[0] * PMAn->size[1];
    for (ibcol = 0; ibcol < ibmat; ibcol++) {
      b_PMAn->data[ibcol] = PMAn->data[ibcol];
    }

    ibcol = b_PS->size[0] * b_PS->size[1];
    b_PS->size[0] = 2000;
    b_PS->size[1] = 10;
    emxEnsureCapacity_int32_T(b_PS, ibcol);
    for (ibcol = 0; ibcol < 20000; ibcol++) {
      b_PS->data[ibcol] = PS->data[ibcol];
    }

    ibcol = b_PCPO->size[0] * b_PCPO->size[1];
    b_PCPO->size[0] = 2000;
    b_PCPO->size[1] = 15;
    emxEnsureCapacity_int32_T(b_PCPO, ibcol);
    for (ibcol = 0; ibcol < 30000; ibcol++) {
      b_PCPO->data[ibcol] = PCPO->data[ibcol];
    }

    ibcol = b_PCR->size[0] * b_PCR->size[1];
    b_PCR->size[0] = 2000;
    b_PCR->size[1] = 25;
    emxEnsureCapacity_int32_T(b_PCR, ibcol);
    for (ibcol = 0; ibcol < 50000; ibcol++) {
      b_PCR->data[ibcol] = PCR->data[ibcol];
    }

    memcpy(&b_TimeUsoRec_data[0], &TimeUsoRec_data[0], 14000U * sizeof(int));
    EP_size[0] = 2000;
    memcpy(&b_EP_data[0], &EP_data[0], 2000U * sizeof(int));
    c_sch(IC_data, NumRec, b_PCPrO, b_PME, b_PMA, b_PMAn, b_PS, b_PCPO, b_PCR,
          Dia_data, Dia_size, b_TimeUsoRec_data, DispMExD_data, DispMExD_size,
          b_EP_data, EP_size, &fitness[yk], &fitness[20 + yk], &fitness[40 + yk],
          &fitness[60 + yk], &fitness[80 + yk], &fitness[100 + yk]);
  }

  emxFree_int32_T(&b_PCR);
  emxFree_int32_T(&b_PCPO);
  emxFree_int32_T(&b_PS);
  emxFree_int32_T(&b_PMAn);
  emxFree_int32_T(&b_PMA);
  emxFree_int32_T(&b_PME);
  emxFree_int32_T(&b_PCPrO);

  /* ATUALIZA POPULAÇÃO B(T) */
  for (ibcol = 0; ibcol < 2000; ibcol++) {
    IC_data[ibcol] = best->data[ibcol];
  }

  emxFree_int32_T(&best);
  emxInitMatrix_cell_wrap_0(reshapes);
  ibcol = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
  reshapes[0].f1->size[0] = 2000;
  reshapes[0].f1->size[1] = 1;
  emxEnsureCapacity_int32_T(reshapes[0].f1, ibcol);
  for (ibcol = 0; ibcol < 2000; ibcol++) {
    reshapes[0].f1->data[ibcol] = IC_data[ibcol];
  }

  emxInit_int32_T(&result, 2);
  ibcol = result->size[0] * result->size[1];
  result->size[0] = reshapes[0].f1->size[0];
  result->size[1] = reshapes[0].f1->size[1] + 20;
  emxEnsureCapacity_int32_T(result, ibcol);
  ibmat = reshapes[0].f1->size[1];
  for (ibcol = 0; ibcol < ibmat; ibcol++) {
    yk = reshapes[0].f1->size[0];
    for (itilerow = 0; itilerow < yk; itilerow++) {
      result->data[itilerow + result->size[0] * ibcol] = reshapes[0].f1->
        data[itilerow + reshapes[0].f1->size[0] * ibcol];
    }
  }

  for (ibcol = 0; ibcol < 20; ibcol++) {
    for (itilerow = 0; itilerow < 2000; itilerow++) {
      result->data[itilerow + result->size[0] * (ibcol + reshapes[0].f1->size[1])]
        = IC->data[itilerow + 2000 * ibcol];
    }
  }

  emxFreeMatrix_cell_wrap_0(reshapes);
  for (ibcol = 0; ibcol < 6; ibcol++) {
    aux_fitness[21 * ibcol] = bestFitness[20 * ibcol];
    memcpy(&aux_fitness[ibcol * 21 + 1], &fitness[ibcol * 20], 20U * sizeof
           (double));
  }

  memcpy(&x[0], &aux_fitness[0], 21U * sizeof(double));
  f_sort(x, iidx);
  for (yk = 0; yk < 21; yk++) {
    x[yk] = iidx[yk];
  }

  for (ibcol = 0; ibcol < 6; ibcol++) {
    for (itilerow = 0; itilerow < 21; itilerow++) {
      b_fitness[itilerow + 21 * ibcol] = aux_fitness[((int)x[itilerow] + 21 *
        ibcol) - 1];
    }
  }

  emxInit_int32_T(&rank_classic, 2);
  ibcol = rank_classic->size[0] * rank_classic->size[1];
  rank_classic->size[0] = 2000;
  rank_classic->size[1] = 21;
  emxEnsureCapacity_int32_T(rank_classic, ibcol);
  for (ibcol = 0; ibcol < 21; ibcol++) {
    for (itilerow = 0; itilerow < 2000; itilerow++) {
      rank_classic->data[itilerow + 2000 * ibcol] = result->data[itilerow +
        result->size[0] * ((int)x[ibcol] - 1)];
    }
  }

  emxFree_int32_T(&result);

  /* REMOVE INDIVÍDUOS MAIS FRACOS (EXCEDENTES) */
  for (ibcol = 0; ibcol < 6; ibcol++) {
    for (itilerow = 0; itilerow < 21; itilerow++) {
      b_aux_fitness[itilerow + 21 * ibcol] = aux_fitness[((int)x[itilerow] + 21 *
        ibcol) - 1];
    }

    memcpy(&bestFitness[ibcol * 20], &b_aux_fitness[ibcol * 21], 20U * sizeof
           (double));
  }

  /*  GUARDA MELHOR INDIVÍDUO */
  bestexperimento_size[0] = 2000;
  for (ibcol = 0; ibcol < 2000; ibcol++) {
    bestexperimento_data[ibcol] = rank_classic->data[ibcol];
  }

  /*  SALVA A GERAÇÃO, FITNESS do Melhor ind., a MÉDIA DO FITNESS e a STD DO FITNESS  */
  e_y = bestFitness[0];
  for (k = 0; k < 19; k++) {
    e_y += bestFitness[k + 1];
  }

  memcpy(&c_fitness[0], &b_fitness[0], 20U * sizeof(double));
  trace[0] = 1.0;
  aux_fitness_tmp = rt_roundd(b_fitness[0]);
  if (aux_fitness_tmp < 2.147483648E+9) {
    if (aux_fitness_tmp >= -2.147483648E+9) {
      ibcol = (int)aux_fitness_tmp;
    } else {
      ibcol = MIN_int32_T;
    }
  } else {
    ibcol = MAX_int32_T;
  }

  trace[1] = ibcol;
  aux_fitness_tmp = rt_roundd(e_y / 20.0);
  if (aux_fitness_tmp < 2.147483648E+9) {
    if (aux_fitness_tmp >= -2.147483648E+9) {
      ibcol = (int)aux_fitness_tmp;
    } else {
      ibcol = MIN_int32_T;
    }
  } else {
    ibcol = MAX_int32_T;
  }

  trace[2] = ibcol;
  aux_fitness_tmp = rt_roundd(c_std(c_fitness));
  if (aux_fitness_tmp < 2.147483648E+9) {
    if (aux_fitness_tmp >= -2.147483648E+9) {
      ibcol = (int)aux_fitness_tmp;
    } else {
      ibcol = MIN_int32_T;
    }
  } else {
    ibcol = MAX_int32_T;
  }

  trace[3] = ibcol;
  aux_fitness_tmp = rt_roundd(b_fitness[21]);
  if (aux_fitness_tmp < 2.147483648E+9) {
    if (aux_fitness_tmp >= -2.147483648E+9) {
      ibcol = (int)aux_fitness_tmp;
    } else {
      ibcol = MIN_int32_T;
    }
  } else {
    ibcol = MAX_int32_T;
  }

  trace[4] = ibcol;
  aux_fitness_tmp = rt_roundd(b_fitness[42]);
  if (aux_fitness_tmp < 2.147483648E+9) {
    if (aux_fitness_tmp >= -2.147483648E+9) {
      ibcol = (int)aux_fitness_tmp;
    } else {
      ibcol = MIN_int32_T;
    }
  } else {
    ibcol = MAX_int32_T;
  }

  trace[5] = ibcol;
  aux_fitness_tmp = rt_roundd(b_fitness[63]);
  if (aux_fitness_tmp < 2.147483648E+9) {
    if (aux_fitness_tmp >= -2.147483648E+9) {
      ibcol = (int)aux_fitness_tmp;
    } else {
      ibcol = MIN_int32_T;
    }
  } else {
    ibcol = MAX_int32_T;
  }

  trace[6] = ibcol;
  aux_fitness_tmp = rt_roundd(b_fitness[84]);
  if (aux_fitness_tmp < 2.147483648E+9) {
    if (aux_fitness_tmp >= -2.147483648E+9) {
      ibcol = (int)aux_fitness_tmp;
    } else {
      ibcol = MIN_int32_T;
    }
  } else {
    ibcol = MAX_int32_T;
  }

  trace[7] = ibcol;
  aux_fitness_tmp = rt_roundd(b_fitness[105]);
  if (aux_fitness_tmp < 2.147483648E+9) {
    if (aux_fitness_tmp >= -2.147483648E+9) {
      ibcol = (int)aux_fitness_tmp;
    } else {
      ibcol = MIN_int32_T;
    }
  } else {
    ibcol = MAX_int32_T;
  }

  trace[8] = ibcol;

  /*  IMPRIME STATUS DA EVOLUÇÃO */
  e_y = bestFitness[0];
  for (k = 0; k < 19; k++) {
    e_y += bestFitness[k + 1];
  }

  for (ibcol = 0; ibcol < 6; ibcol++) {
    for (itilerow = 0; itilerow < 21; itilerow++) {
      aux_fitness_tmp = aux_fitness[((int)x[itilerow] + 21 * ibcol) - 1];
      yk = itilerow + 21 * ibcol;
      b_aux_fitness[yk] = aux_fitness_tmp;
      b_fitness[yk] = aux_fitness_tmp;
      c_aux_fitness[yk] = aux_fitness_tmp;
      d_aux_fitness[yk] = aux_fitness_tmp;
      e_aux_fitness[yk] = aux_fitness_tmp;
      f_aux_fitness[yk] = aux_fitness_tmp;
    }
  }

  printf("Ger: %d - \t Ini: %10.5f - \t Best: %10.5f - \t Mean: %10.5f - \t STD: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t "
         "NOE2: %10.5f - \t NOE3: %10.5f \n", 1, fitnessB[0], b_aux_fitness[0],
         e_y / 20.0, c_std(*(double (*)[20])&bestFitness[0]), b_fitness[21],
         c_aux_fitness[42], d_aux_fitness[63], e_aux_fitness[84], f_aux_fitness
         [105]);
  fflush(stdout);

  /*  REPOSICIONA PULSOS DE ACORDO COM MELHORES INDIVÍDUOS */
  /*  Crossover clasico          */
  ibcol = IC->size[0] * IC->size[1];
  IC->size[0] = 2000;
  IC->size[1] = 20;
  emxEnsureCapacity_int32_T(IC, ibcol);
  for (ibcol = 0; ibcol < 20; ibcol++) {
    for (itilerow = 0; itilerow < 2000; itilerow++) {
      yk = itilerow + 2000 * ibcol;
      IC->data[yk] = rank_classic->data[yk];
    }
  }

  emxFree_int32_T(&rank_classic);
  emxInit_int32_T(&b_IC, 2);
  b_cc(IC, b_IC);

  /*         best = best(:,1:(numIC*taxE)/100); */
  /*         bestFitness = bestFitness(1:(numIC*taxE)/100,:); */
  emxFree_int32_T(&b_IC);
  emxFree_int32_T(&IC);
}

/* End of code generation (aevSPLap.c) */
