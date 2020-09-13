/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: main_UCI_func.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "model_emxutil.h"
#include "toc.h"
#include "aevSPLap.h"
#include "favalia.h"
#include "casorandom.h"
#include "sort1.h"
#include "obsIQini.h"
#include "tic.h"
#include "model_rtwutil.h"
#include <stdio.h>

/* Function Definitions */

/*
 * function main_UCI_func(CP,RO,CPO,CPrO,CR,Data,Dia,DispMExD,MA,MAn,ME,S,TipoOp,NumEsp,NumTOp,NumSalOp,NumCPO,NumCPrO,NumCR,NumMedEsp,NumEspxE,NumAsist,NumAnest,...
 *     k0,k1,k2,k3,numIQ,numIC,taxC,taxE,taxEQ,ProbXEst,genToWidth,generations,keeppriority)
 * Arguments    : const emxArray_int32_T *CP
 *                const emxArray_int32_T *RO
 *                const emxArray_int32_T *CPO
 *                const emxArray_int32_T *CPrO
 *                const emxArray_int32_T *CR
 *                const emxArray_int32_T *Data
 *                const emxArray_int32_T *Dia
 *                const emxArray_int32_T *DispMExD
 *                const emxArray_int32_T *MA
 *                const emxArray_int32_T *MAn
 *                const emxArray_int32_T *ME
 *                const emxArray_int32_T *S
 *                int TipoOp
 *                int NumEsp
 *                int NumTOp
 *                int NumSalOp
 *                int NumCPO
 *                int NumCPrO
 *                int NumCR
 *                int NumMedEsp
 *                int NumEspxE
 *                int NumAsist
 *                int NumAnest
 *                double k0
 *                double k1
 *                double k2
 *                double k3
 *                int numIQ
 *                int numIC
 *                double taxC
 *                double taxE
 *                double taxEQ
 *                const emxArray_real_T *ProbXEst
 *                int genToWidth
 *                int generations
 *                boolean_T keeppriority
 * Return Type  : void
 */
void main_UCI_func(const emxArray_int32_T *CP, const emxArray_int32_T *RO, const
                   emxArray_int32_T *CPO, const emxArray_int32_T *CPrO, const
                   emxArray_int32_T *CR, const emxArray_int32_T *Data, const
                   emxArray_int32_T *Dia, const emxArray_int32_T *DispMExD,
                   const emxArray_int32_T *MA, const emxArray_int32_T *MAn,
                   const emxArray_int32_T *ME, const emxArray_int32_T *S, int
                   TipoOp, int NumEsp, int NumTOp, int NumSalOp, int NumCPO, int
                   NumCPrO, int NumCR, int NumMedEsp, int NumEspxE, int NumAsist,
                   int NumAnest, double k0, double k1, double k2, double k3, int
                   numIQ, int numIC, double taxC, double taxE, double taxEQ,
                   const emxArray_real_T *ProbXEst, int genToWidth, int
                   generations, boolean_T keeppriority)
{
  int NumRec[7];
  double y;
  int k;
  emxArray_int8_T *H;
  int N;
  int i12;
  emxArray_int32_T *UltPosRecXDia;
  int i13;
  emxArray_int32_T *TimeUsoRec;
  emxArray_int32_T *b_TimeUsoRec;
  emxArray_int32_T *r4;
  emxArray_int32_T *varargin_1;
  int u0;
  boolean_T empty_non_axis_sizes;
  int input_sizes[2];
  int b_input_sizes[2];
  cell_wrap_0 reshapes[2];
  int end;
  signed char sizes_idx_1;
  emxArray_int32_T *PME;
  int input_sizes_idx_1;
  cell_wrap_0 b_reshapes[2];
  emxArray_int32_T *PMA;
  cell_wrap_0 c_reshapes[2];
  emxArray_int32_T *PMAn;
  emxArray_boolean_T *idx;
  emxArray_int32_T *r5;
  emxArray_int32_T *r6;
  emxArray_int32_T *r7;
  emxArray_int32_T *r8;
  int i;
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *PS;
  emxArray_int32_T *PCPO;
  emxArray_int32_T *PCR;
  emxArray_int32_T *scheduleB;
  emxArray_int32_T *DiaOpB;
  emxArray_int32_T *EspMedOpB;
  emxArray_int32_T c_TimeUsoRec;
  int iv1[1];
  double varargin_2;
  double varargin_3;
  double varargin_4;
  double varargin_5;
  double varargin_6;
  unsigned int iidx_idx_0;
  emxArray_int32_T *iidx;
  emxArray_int32_T *NAWD;
  emxArray_int32_T *x;
  emxArray_int32_T *b_idx;
  emxArray_int32_T *NewTimeUsoRec;
  emxArray_int32_T *NewPME;
  emxArray_int32_T *NewPMA;
  emxArray_int32_T *NewPMAn;
  emxArray_int32_T *NewPCPrO;
  emxArray_int32_T *NewPS;
  emxArray_int32_T *NewPCPO;
  emxArray_int32_T *NewPCR;
  emxArray_int32_T *NewEP;
  emxArray_int32_T *schedule;
  emxArray_int32_T *DiaOp;
  emxArray_int32_T *EspMedOp;
  emxArray_int32_T *bestexperimento;
  emxArray_real_T *trace;
  double fitness;
  double Tt;
  double NOFP;
  double TmNOFP;
  double NOE2;
  double NOE3;
  double b_fitness[6];
  (void)TipoOp;
  (void)NumEsp;
  (void)NumEspxE;
  (void)taxEQ;

  /* 'main_UCI_func:3' tic; */
  tic();

  /* 'main_UCI_func:6' coder.varsize('CP',        [inf 8],    [1 0]) */
  /* 'main_UCI_func:7' coder.varsize('RO',        [inf 7],    [1 0]) */
  /* 'main_UCI_func:8' coder.varsize('CPO',       [inf inf],  [1 1]) */
  /* 'main_UCI_func:9' coder.varsize('CPrO',      [inf inf],  [1 1]) */
  /* 'main_UCI_func:10' coder.varsize('CR',        [inf inf],  [1 1]) */
  /* 'main_UCI_func:11' coder.varsize('Data',      [inf 5],    [1 0]) */
  /* 'main_UCI_func:12' coder.varsize('Dia',       [inf 4],    [1 0]) */
  /* 'main_UCI_func:13' coder.varsize('DispMExD',  [6 inf],    [0 1]) */
  /* 'main_UCI_func:14' coder.varsize('MA',        [inf inf],  [1 1]) */
  /* 'main_UCI_func:15' coder.varsize('MAn',       [inf inf],  [1 1]) */
  /* 'main_UCI_func:16' coder.varsize('ME',        [inf inf],  [1 1]) */
  /* 'main_UCI_func:17' coder.varsize('S',         [inf inf],  [1 1]) */
  /*     %% Matriz de Horario. En las filas los dias */
  /* 'main_UCI_func:22' NumRec = [NumCPrO NumMedEsp NumSalOp NumAsist NumAnest NumCPO NumCR]; */
  NumRec[0] = NumCPrO;
  NumRec[1] = NumMedEsp;
  NumRec[2] = NumSalOp;
  NumRec[3] = NumAsist;
  NumRec[4] = NumAnest;
  NumRec[5] = NumCPO;
  NumRec[6] = NumCR;

  /*  Numero de recursos */
  /* 'main_UCI_func:23' H = zeros(size(Data,1),sum(NumRec), 'int32'); */
  y = NumCPrO;
  for (k = 0; k < 6; k++) {
    y += (double)NumRec[k + 1];
  }

  emxInit_int8_T(&H, 2);
  N = Data->size[0];
  i12 = H->size[0] * H->size[1];
  k = (int)y;
  H->size[1] = k;
  H->size[0] = N;
  emxEnsureCapacity_int8_T(H, i12);
  for (i12 = 0; i12 < N; i12++) {
    for (i13 = 0; i13 < k; i13++) {
      H->data[i13 + H->size[1] * i12] = 0;
    }
  }

  emxInit_int32_T(&UltPosRecXDia, 2);

  /*  Schedule completo */
  /* 'main_UCI_func:24' UltPosRecXDia = zeros(size(Dia,1),size(H,2), 'int32'); */
  N = Dia->size[0];
  i12 = UltPosRecXDia->size[0] * UltPosRecXDia->size[1];
  UltPosRecXDia->size[1] = k;
  UltPosRecXDia->size[0] = N;
  emxEnsureCapacity_int32_T(UltPosRecXDia, i12);
  for (i12 = 0; i12 < N; i12++) {
    for (i13 = 0; i13 < k; i13++) {
      UltPosRecXDia->data[i13 + UltPosRecXDia->size[1] * i12] = 0;
    }
  }

  emxInit_int32_T(&TimeUsoRec, 2);

  /*  Ultima posicion asignado del recurso por Dia */
  /*     %% Matriz con el tiempo de uso necesario de todos los recursos */
  /* Cama Pre-OP,Sala de Operación, Medicos Especialistas, Medicos Asistentes, Medicos Anstesistas, Cama Post-OP, Cama Recuperacion.  */
  /* 'main_UCI_func:30' TimeUsoRec = zeros(NumTOp, 7, 'int32'); */
  i12 = TimeUsoRec->size[0] * TimeUsoRec->size[1];
  TimeUsoRec->size[1] = 7;
  TimeUsoRec->size[0] = NumTOp;
  emxEnsureCapacity_int32_T(TimeUsoRec, i12);
  for (i12 = 0; i12 < NumTOp; i12++) {
    for (i13 = 0; i13 < 7; i13++) {
      TimeUsoRec->data[i13 + 7 * i12] = 0;
    }
  }

  /* 'main_UCI_func:31' TimeUsoRec(:,1) = CP(:,6); */
  k = CP->size[0];
  for (i12 = 0; i12 < k; i12++) {
    TimeUsoRec->data[7 * i12] = CP->data[5 + (i12 << 3)];
  }

  emxInit_int32_T(&b_TimeUsoRec, 2);

  /*  Tiempo de uso cama Pre-Operatoria */
  /* 'main_UCI_func:32' TimeUsoRec(:,2) = RO(CP(:,4),4); */
  k = CP->size[0];
  i12 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[1] = 1;
  b_TimeUsoRec->size[0] = k;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i12);
  for (i12 = 0; i12 < k; i12++) {
    b_TimeUsoRec->data[i12] = RO->data[3 + 7 * (CP->data[3 + (i12 << 3)] - 1)];
  }

  k = CP->size[0];
  for (i12 = 0; i12 < k; i12++) {
    TimeUsoRec->data[1 + 7 * i12] = b_TimeUsoRec->data[i12];
  }

  /*  Tiempo de uso Salon de operacion */
  /* 'main_UCI_func:33' TimeUsoRec(:,3) = TimeUsoRec(:,2); */
  k = TimeUsoRec->size[0];
  i12 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[1] = 1;
  b_TimeUsoRec->size[0] = k;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i12);
  for (i12 = 0; i12 < k; i12++) {
    b_TimeUsoRec->data[i12] = TimeUsoRec->data[1 + 7 * i12];
  }

  k = b_TimeUsoRec->size[0];
  for (i12 = 0; i12 < k; i12++) {
    TimeUsoRec->data[2 + 7 * i12] = b_TimeUsoRec->data[i12];
  }

  /*  Tiempo de uso Medico Especialista */
  /* 'main_UCI_func:34' TimeUsoRec(:,4) = TimeUsoRec(:,2); */
  k = TimeUsoRec->size[0];
  i12 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[1] = 1;
  b_TimeUsoRec->size[0] = k;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i12);
  for (i12 = 0; i12 < k; i12++) {
    b_TimeUsoRec->data[i12] = TimeUsoRec->data[1 + 7 * i12];
  }

  k = b_TimeUsoRec->size[0];
  for (i12 = 0; i12 < k; i12++) {
    TimeUsoRec->data[3 + 7 * i12] = b_TimeUsoRec->data[i12];
  }

  /*  Tiempo de uso Medico Asistente */
  /* 'main_UCI_func:35' TimeUsoRec(:,5) = TimeUsoRec(:,2); */
  k = TimeUsoRec->size[0];
  i12 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[1] = 1;
  b_TimeUsoRec->size[0] = k;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i12);
  for (i12 = 0; i12 < k; i12++) {
    b_TimeUsoRec->data[i12] = TimeUsoRec->data[1 + 7 * i12];
  }

  k = b_TimeUsoRec->size[0];
  for (i12 = 0; i12 < k; i12++) {
    TimeUsoRec->data[4 + 7 * i12] = b_TimeUsoRec->data[i12];
  }

  /*  Tiempo de uso Medico Anestesista */
  /* 'main_UCI_func:36' TimeUsoRec(:,6:7) = CP(:,7:8); */
  k = CP->size[0];
  for (i12 = 0; i12 < k; i12++) {
    i13 = i12 << 3;
    TimeUsoRec->data[7 * i12 + 5] = CP->data[i13 + 6];
    TimeUsoRec->data[7 * i12 + 6] = CP->data[i13 + 7];
  }

  /*  Tiempo de uso cama Post-Operatoria y Recuperacion */
  /* 'main_UCI_func:38' PME = [ME(:,RO(CP(:,4),2))' RO(CP(:,4),5)]; */
  k = CP->size[0];
  i12 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[1] = 1;
  b_TimeUsoRec->size[0] = k;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i12);
  for (i12 = 0; i12 < k; i12++) {
    b_TimeUsoRec->data[i12] = CP->data[3 + (i12 << 3)];
  }

  emxInit_int32_T(&r4, 2);
  k = CP->size[0];
  i12 = r4->size[0] * r4->size[1];
  r4->size[1] = 1;
  r4->size[0] = k;
  emxEnsureCapacity_int32_T(r4, i12);
  for (i12 = 0; i12 < k; i12++) {
    r4->data[i12] = CP->data[3 + (i12 << 3)];
  }

  emxInit_int32_T(&varargin_1, 2);
  k = CP->size[0];
  N = ME->size[0];
  i12 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[1] = N;
  varargin_1->size[0] = k;
  emxEnsureCapacity_int32_T(varargin_1, i12);
  for (i12 = 0; i12 < k; i12++) {
    for (i13 = 0; i13 < N; i13++) {
      varargin_1->data[i13 + varargin_1->size[1] * i12] = ME->data[(RO->data[1 +
        7 * (b_TimeUsoRec->data[i12] - 1)] + ME->size[1] * i13) - 1];
    }
  }

  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    u0 = varargin_1->size[0];
  } else {
    i12 = CP->size[0];
    if (i12 != 0) {
      u0 = CP->size[0];
    } else {
      u0 = varargin_1->size[0];
      if (u0 <= 0) {
        u0 = 0;
      }

      i12 = CP->size[0];
      if (i12 > u0) {
        u0 = CP->size[0];
      }
    }
  }

  empty_non_axis_sizes = (u0 == 0);
  if (empty_non_axis_sizes || ((varargin_1->size[0] != 0) && (varargin_1->size[1]
        != 0))) {
    input_sizes[1] = varargin_1->size[1];
  } else {
    input_sizes[1] = 0;
  }

  b_input_sizes[0] = u0;
  b_input_sizes[1] = input_sizes[1];
  emxInitMatrix_cell_wrap_0(reshapes);
  if ((input_sizes[1] == varargin_1->size[1]) && (u0 == varargin_1->size[0])) {
    N = input_sizes[1];
    i12 = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
    reshapes[0].f1->size[1] = input_sizes[1];
    reshapes[0].f1->size[0] = u0;
    emxEnsureCapacity_int32_T(reshapes[0].f1, i12);
    for (i12 = 0; i12 < u0; i12++) {
      for (i13 = 0; i13 < N; i13++) {
        reshapes[0].f1->data[i13 + reshapes[0].f1->size[1] * i12] =
          varargin_1->data[i13 + N * i12];
      }
    }
  } else {
    i12 = 0;
    i13 = 0;
    N = 0;
    k = 0;
    end = reshapes[0].f1->size[0] * reshapes[0].f1->size[1];
    reshapes[0].f1->size[1] = input_sizes[1];
    reshapes[0].f1->size[0] = u0;
    emxEnsureCapacity_int32_T(reshapes[0].f1, end);
    for (end = 0; end < b_input_sizes[0] * b_input_sizes[1]; end++) {
      reshapes[0].f1->data[i13 + reshapes[0].f1->size[1] * i12] =
        varargin_1->data[k + varargin_1->size[1] * N];
      i12++;
      N++;
      if (i12 > reshapes[0].f1->size[0] - 1) {
        i12 = 0;
        i13++;
      }

      if (N > varargin_1->size[0] - 1) {
        N = 0;
        k++;
      }
    }
  }

  if (empty_non_axis_sizes) {
    sizes_idx_1 = 1;
  } else {
    i12 = CP->size[0];
    if (i12 != 0) {
      sizes_idx_1 = 1;
    } else {
      sizes_idx_1 = 0;
    }
  }

  input_sizes[0] = u0;
  input_sizes[1] = sizes_idx_1;
  i12 = 0;
  i13 = 0;
  N = 0;
  k = reshapes[1].f1->size[0] * reshapes[1].f1->size[1];
  reshapes[1].f1->size[1] = sizes_idx_1;
  reshapes[1].f1->size[0] = u0;
  emxEnsureCapacity_int32_T(reshapes[1].f1, k);
  for (k = 0; k < input_sizes[0] * input_sizes[1]; k++) {
    reshapes[1].f1->data[i13 + reshapes[1].f1->size[1] * i12] = RO->data[4 + 7 *
      (r4->data[N] - 1)];
    i12++;
    N++;
    if (i12 > reshapes[1].f1->size[0] - 1) {
      i12 = 0;
      i13++;
    }
  }

  emxInit_int32_T(&PME, 2);
  i12 = PME->size[0] * PME->size[1];
  PME->size[1] = reshapes[0].f1->size[1] + reshapes[1].f1->size[1];
  PME->size[0] = reshapes[0].f1->size[0];
  emxEnsureCapacity_int32_T(PME, i12);
  k = reshapes[0].f1->size[0];
  for (i12 = 0; i12 < k; i12++) {
    N = reshapes[0].f1->size[1];
    for (i13 = 0; i13 < N; i13++) {
      PME->data[i13 + PME->size[1] * i12] = reshapes[0].f1->data[i13 + reshapes
        [0].f1->size[1] * i12];
    }
  }

  k = reshapes[1].f1->size[0];
  for (i12 = 0; i12 < k; i12++) {
    N = reshapes[1].f1->size[1];
    for (i13 = 0; i13 < N; i13++) {
      PME->data[(i13 + reshapes[0].f1->size[1]) + PME->size[1] * i12] =
        reshapes[1].f1->data[i13 + reshapes[1].f1->size[1] * i12];
    }
  }

  emxFreeMatrix_cell_wrap_0(reshapes);

  /*  Posibles Medicos Especialistas X Operacion. | Cantidad necesaria de Medicos Especialistas */
  /* 'main_UCI_func:40' PMA = [MA(:,RO(CP(:,4),2))' RO(CP(:,4),6)]; */
  k = CP->size[0];
  i12 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[1] = 1;
  b_TimeUsoRec->size[0] = k;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i12);
  for (i12 = 0; i12 < k; i12++) {
    b_TimeUsoRec->data[i12] = CP->data[3 + (i12 << 3)];
  }

  k = CP->size[0];
  i12 = r4->size[0] * r4->size[1];
  r4->size[1] = 1;
  r4->size[0] = k;
  emxEnsureCapacity_int32_T(r4, i12);
  for (i12 = 0; i12 < k; i12++) {
    r4->data[i12] = CP->data[3 + (i12 << 3)];
  }

  k = CP->size[0];
  N = MA->size[0];
  i12 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[1] = N;
  varargin_1->size[0] = k;
  emxEnsureCapacity_int32_T(varargin_1, i12);
  for (i12 = 0; i12 < k; i12++) {
    for (i13 = 0; i13 < N; i13++) {
      varargin_1->data[i13 + varargin_1->size[1] * i12] = MA->data[(RO->data[1 +
        7 * (b_TimeUsoRec->data[i12] - 1)] + MA->size[1] * i13) - 1];
    }
  }

  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    u0 = varargin_1->size[0];
  } else {
    i12 = CP->size[0];
    if (i12 != 0) {
      u0 = CP->size[0];
    } else {
      u0 = varargin_1->size[0];
      if (u0 <= 0) {
        u0 = 0;
      }

      i12 = CP->size[0];
      if (i12 > u0) {
        u0 = CP->size[0];
      }
    }
  }

  empty_non_axis_sizes = (u0 == 0);
  if (empty_non_axis_sizes || ((varargin_1->size[0] != 0) && (varargin_1->size[1]
        != 0))) {
    input_sizes_idx_1 = varargin_1->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }

  input_sizes[0] = u0;
  input_sizes[1] = input_sizes_idx_1;
  emxInitMatrix_cell_wrap_0(b_reshapes);
  if ((input_sizes_idx_1 == varargin_1->size[1]) && (u0 == varargin_1->size[0]))
  {
    i12 = b_reshapes[0].f1->size[0] * b_reshapes[0].f1->size[1];
    b_reshapes[0].f1->size[1] = input_sizes_idx_1;
    b_reshapes[0].f1->size[0] = u0;
    emxEnsureCapacity_int32_T(b_reshapes[0].f1, i12);
    for (i12 = 0; i12 < u0; i12++) {
      for (i13 = 0; i13 < input_sizes_idx_1; i13++) {
        b_reshapes[0].f1->data[i13 + b_reshapes[0].f1->size[1] * i12] =
          varargin_1->data[i13 + input_sizes_idx_1 * i12];
      }
    }
  } else {
    i12 = 0;
    i13 = 0;
    N = 0;
    k = 0;
    end = b_reshapes[0].f1->size[0] * b_reshapes[0].f1->size[1];
    b_reshapes[0].f1->size[1] = input_sizes_idx_1;
    b_reshapes[0].f1->size[0] = u0;
    emxEnsureCapacity_int32_T(b_reshapes[0].f1, end);
    for (end = 0; end < input_sizes[0] * input_sizes[1]; end++) {
      b_reshapes[0].f1->data[i13 + b_reshapes[0].f1->size[1] * i12] =
        varargin_1->data[k + varargin_1->size[1] * N];
      i12++;
      N++;
      if (i12 > b_reshapes[0].f1->size[0] - 1) {
        i12 = 0;
        i13++;
      }

      if (N > varargin_1->size[0] - 1) {
        N = 0;
        k++;
      }
    }
  }

  if (empty_non_axis_sizes) {
    sizes_idx_1 = 1;
  } else {
    i12 = CP->size[0];
    if (i12 != 0) {
      sizes_idx_1 = 1;
    } else {
      sizes_idx_1 = 0;
    }
  }

  input_sizes[0] = u0;
  input_sizes[1] = sizes_idx_1;
  i12 = 0;
  i13 = 0;
  N = 0;
  k = b_reshapes[1].f1->size[0] * b_reshapes[1].f1->size[1];
  b_reshapes[1].f1->size[1] = sizes_idx_1;
  b_reshapes[1].f1->size[0] = u0;
  emxEnsureCapacity_int32_T(b_reshapes[1].f1, k);
  for (k = 0; k < input_sizes[0] * input_sizes[1]; k++) {
    b_reshapes[1].f1->data[i13 + b_reshapes[1].f1->size[1] * i12] = RO->data[5 +
      7 * (r4->data[N] - 1)];
    i12++;
    N++;
    if (i12 > b_reshapes[1].f1->size[0] - 1) {
      i12 = 0;
      i13++;
    }
  }

  emxInit_int32_T(&PMA, 2);
  i12 = PMA->size[0] * PMA->size[1];
  PMA->size[1] = b_reshapes[0].f1->size[1] + b_reshapes[1].f1->size[1];
  PMA->size[0] = b_reshapes[0].f1->size[0];
  emxEnsureCapacity_int32_T(PMA, i12);
  k = b_reshapes[0].f1->size[0];
  for (i12 = 0; i12 < k; i12++) {
    N = b_reshapes[0].f1->size[1];
    for (i13 = 0; i13 < N; i13++) {
      PMA->data[i13 + PMA->size[1] * i12] = b_reshapes[0].f1->data[i13 +
        b_reshapes[0].f1->size[1] * i12];
    }
  }

  k = b_reshapes[1].f1->size[0];
  for (i12 = 0; i12 < k; i12++) {
    N = b_reshapes[1].f1->size[1];
    for (i13 = 0; i13 < N; i13++) {
      PMA->data[(i13 + b_reshapes[0].f1->size[1]) + PMA->size[1] * i12] =
        b_reshapes[1].f1->data[i13 + b_reshapes[1].f1->size[1] * i12];
    }
  }

  emxFreeMatrix_cell_wrap_0(b_reshapes);

  /*  Posibles Medicos Asistentes X Operacion. | Cantidad necesaria de Medicos Asistentes */
  /* 'main_UCI_func:42' PMAn = [MAn(:,RO(CP(:,4),2))' RO(CP(:,4),7)]; */
  k = CP->size[0];
  i12 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[1] = 1;
  b_TimeUsoRec->size[0] = k;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i12);
  for (i12 = 0; i12 < k; i12++) {
    b_TimeUsoRec->data[i12] = CP->data[3 + (i12 << 3)];
  }

  k = CP->size[0];
  i12 = r4->size[0] * r4->size[1];
  r4->size[1] = 1;
  r4->size[0] = k;
  emxEnsureCapacity_int32_T(r4, i12);
  for (i12 = 0; i12 < k; i12++) {
    r4->data[i12] = CP->data[3 + (i12 << 3)];
  }

  k = CP->size[0];
  N = MAn->size[0];
  i12 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[1] = N;
  varargin_1->size[0] = k;
  emxEnsureCapacity_int32_T(varargin_1, i12);
  for (i12 = 0; i12 < k; i12++) {
    for (i13 = 0; i13 < N; i13++) {
      varargin_1->data[i13 + varargin_1->size[1] * i12] = MAn->data[(RO->data[1
        + 7 * (b_TimeUsoRec->data[i12] - 1)] + MAn->size[1] * i13) - 1];
    }
  }

  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    u0 = varargin_1->size[0];
  } else {
    i12 = CP->size[0];
    if (i12 != 0) {
      u0 = CP->size[0];
    } else {
      u0 = varargin_1->size[0];
      if (u0 <= 0) {
        u0 = 0;
      }

      i12 = CP->size[0];
      if (i12 > u0) {
        u0 = CP->size[0];
      }
    }
  }

  empty_non_axis_sizes = (u0 == 0);
  if (empty_non_axis_sizes || ((varargin_1->size[0] != 0) && (varargin_1->size[1]
        != 0))) {
    input_sizes_idx_1 = varargin_1->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }

  input_sizes[0] = u0;
  input_sizes[1] = input_sizes_idx_1;
  emxInitMatrix_cell_wrap_0(c_reshapes);
  if ((input_sizes_idx_1 == varargin_1->size[1]) && (u0 == varargin_1->size[0]))
  {
    i12 = c_reshapes[0].f1->size[0] * c_reshapes[0].f1->size[1];
    c_reshapes[0].f1->size[1] = input_sizes_idx_1;
    c_reshapes[0].f1->size[0] = u0;
    emxEnsureCapacity_int32_T(c_reshapes[0].f1, i12);
    for (i12 = 0; i12 < u0; i12++) {
      for (i13 = 0; i13 < input_sizes_idx_1; i13++) {
        c_reshapes[0].f1->data[i13 + c_reshapes[0].f1->size[1] * i12] =
          varargin_1->data[i13 + input_sizes_idx_1 * i12];
      }
    }
  } else {
    i12 = 0;
    i13 = 0;
    N = 0;
    k = 0;
    end = c_reshapes[0].f1->size[0] * c_reshapes[0].f1->size[1];
    c_reshapes[0].f1->size[1] = input_sizes_idx_1;
    c_reshapes[0].f1->size[0] = u0;
    emxEnsureCapacity_int32_T(c_reshapes[0].f1, end);
    for (end = 0; end < input_sizes[0] * input_sizes[1]; end++) {
      c_reshapes[0].f1->data[i13 + c_reshapes[0].f1->size[1] * i12] =
        varargin_1->data[k + varargin_1->size[1] * N];
      i12++;
      N++;
      if (i12 > c_reshapes[0].f1->size[0] - 1) {
        i12 = 0;
        i13++;
      }

      if (N > varargin_1->size[0] - 1) {
        N = 0;
        k++;
      }
    }
  }

  if (empty_non_axis_sizes) {
    sizes_idx_1 = 1;
  } else {
    i12 = CP->size[0];
    if (i12 != 0) {
      sizes_idx_1 = 1;
    } else {
      sizes_idx_1 = 0;
    }
  }

  input_sizes[0] = u0;
  input_sizes[1] = sizes_idx_1;
  i12 = 0;
  i13 = 0;
  N = 0;
  k = c_reshapes[1].f1->size[0] * c_reshapes[1].f1->size[1];
  c_reshapes[1].f1->size[1] = sizes_idx_1;
  c_reshapes[1].f1->size[0] = u0;
  emxEnsureCapacity_int32_T(c_reshapes[1].f1, k);
  for (k = 0; k < input_sizes[0] * input_sizes[1]; k++) {
    c_reshapes[1].f1->data[i13 + c_reshapes[1].f1->size[1] * i12] = RO->data[6 +
      7 * (r4->data[N] - 1)];
    i12++;
    N++;
    if (i12 > c_reshapes[1].f1->size[0] - 1) {
      i12 = 0;
      i13++;
    }
  }

  emxFree_int32_T(&r4);
  emxInit_int32_T(&PMAn, 2);
  i12 = PMAn->size[0] * PMAn->size[1];
  PMAn->size[1] = c_reshapes[0].f1->size[1] + c_reshapes[1].f1->size[1];
  PMAn->size[0] = c_reshapes[0].f1->size[0];
  emxEnsureCapacity_int32_T(PMAn, i12);
  k = c_reshapes[0].f1->size[0];
  for (i12 = 0; i12 < k; i12++) {
    N = c_reshapes[0].f1->size[1];
    for (i13 = 0; i13 < N; i13++) {
      PMAn->data[i13 + PMAn->size[1] * i12] = c_reshapes[0].f1->data[i13 +
        c_reshapes[0].f1->size[1] * i12];
    }
  }

  k = c_reshapes[1].f1->size[0];
  for (i12 = 0; i12 < k; i12++) {
    N = c_reshapes[1].f1->size[1];
    for (i13 = 0; i13 < N; i13++) {
      PMAn->data[(i13 + c_reshapes[0].f1->size[1]) + PMAn->size[1] * i12] =
        c_reshapes[1].f1->data[i13 + c_reshapes[1].f1->size[1] * i12];
    }
  }

  emxFreeMatrix_cell_wrap_0(c_reshapes);

  /*  Posibles Medicos Anestesistas X Operacion. | Cantidad necesaria de Medicos Anestesistas */
  /* 'main_UCI_func:44' CxO = RO(CP(:,4),3); */
  k = CP->size[0];
  i12 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[1] = 1;
  b_TimeUsoRec->size[0] = k;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i12);
  for (i12 = 0; i12 < k; i12++) {
    b_TimeUsoRec->data[i12] = CP->data[3 + (i12 << 3)];
  }

  /*  Complejidad de la Operacion */
  /* 'main_UCI_func:46' for i=1:NumTOp */
  emxInit_boolean_T(&idx, 2);
  emxInit_int32_T(&r5, 2);
  emxInit_int32_T(&r6, 2);
  emxInit_int32_T(&r7, 2);
  emxInit_int32_T(&r8, 2);
  for (i = 0; i < NumTOp; i++) {
    /* 'main_UCI_func:48' if CxO(i)==1 */
    if (RO->data[2 + 7 * (b_TimeUsoRec->data[i] - 1)] == 1) {
      /*  Si la operacion es de alto riesgo quitar los Medicos de nivel 3 como opcion */
      /* 'main_UCI_func:50' idx= PME(i,1:end-1)==3; */
      if (1 > PME->size[1] - 1) {
        k = 0;
      } else {
        k = PME->size[1] - 1;
      }

      i12 = idx->size[0] * idx->size[1];
      idx->size[1] = k;
      idx->size[0] = 1;
      emxEnsureCapacity_boolean_T(idx, i12);
      for (i12 = 0; i12 < k; i12++) {
        idx->data[i12] = (PME->data[i12 + PME->size[1] * i] == 3);
      }

      /* 'main_UCI_func:51' PME(i,idx)=0; */
      end = idx->size[1] - 1;
      N = 0;
      for (k = 0; k <= end; k++) {
        if (idx->data[k]) {
          N++;
        }
      }

      i12 = r5->size[0] * r5->size[1];
      r5->size[1] = N;
      r5->size[0] = 1;
      emxEnsureCapacity_int32_T(r5, i12);
      N = 0;
      for (k = 0; k <= end; k++) {
        if (idx->data[k]) {
          r5->data[N] = k + 1;
          N++;
        }
      }

      i12 = r8->size[0] * r8->size[1];
      r8->size[1] = r5->size[1];
      r8->size[0] = 1;
      emxEnsureCapacity_int32_T(r8, i12);
      k = r5->size[1];
      for (i12 = 0; i12 < k; i12++) {
        r8->data[i12] = r5->data[i12] - 1;
      }

      N = r5->size[1];
      for (i12 = 0; i12 < N; i12++) {
        PME->data[r8->data[i12] + PME->size[1] * i] = 0;
      }

      /* 'main_UCI_func:53' idx= PMA(i,1:end-1)==3; */
      if (1 > PMA->size[1] - 1) {
        k = 0;
      } else {
        k = PMA->size[1] - 1;
      }

      i12 = idx->size[0] * idx->size[1];
      idx->size[1] = k;
      idx->size[0] = 1;
      emxEnsureCapacity_boolean_T(idx, i12);
      for (i12 = 0; i12 < k; i12++) {
        idx->data[i12] = (PMA->data[i12 + PMA->size[1] * i] == 3);
      }

      /* 'main_UCI_func:54' PMA(i,idx)=0; */
      end = idx->size[1] - 1;
      N = 0;
      for (k = 0; k <= end; k++) {
        if (idx->data[k]) {
          N++;
        }
      }

      i12 = r6->size[0] * r6->size[1];
      r6->size[1] = N;
      r6->size[0] = 1;
      emxEnsureCapacity_int32_T(r6, i12);
      N = 0;
      for (k = 0; k <= end; k++) {
        if (idx->data[k]) {
          r6->data[N] = k + 1;
          N++;
        }
      }

      i12 = r8->size[0] * r8->size[1];
      r8->size[1] = r6->size[1];
      r8->size[0] = 1;
      emxEnsureCapacity_int32_T(r8, i12);
      k = r6->size[1];
      for (i12 = 0; i12 < k; i12++) {
        r8->data[i12] = r6->data[i12] - 1;
      }

      N = r6->size[1];
      for (i12 = 0; i12 < N; i12++) {
        PMA->data[r8->data[i12] + PMA->size[1] * i] = 0;
      }

      /* 'main_UCI_func:56' idx=PMAn(i,1:end-1)==3; */
      if (1 > PMAn->size[1] - 1) {
        k = 0;
      } else {
        k = PMAn->size[1] - 1;
      }

      i12 = idx->size[0] * idx->size[1];
      idx->size[1] = k;
      idx->size[0] = 1;
      emxEnsureCapacity_boolean_T(idx, i12);
      for (i12 = 0; i12 < k; i12++) {
        idx->data[i12] = (PMAn->data[i12 + PMAn->size[1] * i] == 3);
      }

      /* 'main_UCI_func:57' PMAn(i,idx)=0; */
      end = idx->size[1] - 1;
      N = 0;
      for (k = 0; k <= end; k++) {
        if (idx->data[k]) {
          N++;
        }
      }

      i12 = r7->size[0] * r7->size[1];
      r7->size[1] = N;
      r7->size[0] = 1;
      emxEnsureCapacity_int32_T(r7, i12);
      N = 0;
      for (k = 0; k <= end; k++) {
        if (idx->data[k]) {
          r7->data[N] = k + 1;
          N++;
        }
      }

      i12 = r8->size[0] * r8->size[1];
      r8->size[1] = r7->size[1];
      r8->size[0] = 1;
      emxEnsureCapacity_int32_T(r8, i12);
      k = r7->size[1];
      for (i12 = 0; i12 < k; i12++) {
        r8->data[i12] = r7->data[i12] - 1;
      }

      N = r7->size[1];
      for (i12 = 0; i12 < N; i12++) {
        PMAn->data[r8->data[i12] + PMAn->size[1] * i] = 0;
      }
    }
  }

  emxFree_int32_T(&r8);
  emxFree_int32_T(&r7);
  emxFree_int32_T(&r6);
  emxFree_int32_T(&r5);
  emxFree_boolean_T(&idx);

  /* 'main_UCI_func:64' PCPrO = CPrO(:,RO(CP(:,4),2))'; */
  k = CP->size[0];
  i12 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[1] = 1;
  b_TimeUsoRec->size[0] = k;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i12);
  for (i12 = 0; i12 < k; i12++) {
    b_TimeUsoRec->data[i12] = CP->data[3 + (i12 << 3)];
  }

  emxInit_int32_T(&PCPrO, 2);
  k = CP->size[0];
  N = CPrO->size[0];
  i12 = PCPrO->size[0] * PCPrO->size[1];
  PCPrO->size[1] = N;
  PCPrO->size[0] = k;
  emxEnsureCapacity_int32_T(PCPrO, i12);
  for (i12 = 0; i12 < k; i12++) {
    for (i13 = 0; i13 < N; i13++) {
      PCPrO->data[i13 + PCPrO->size[1] * i12] = CPrO->data[(RO->data[1 + 7 *
        (b_TimeUsoRec->data[i12] - 1)] + CPrO->size[1] * i13) - 1];
    }
  }

  /*  Posibles Camas PreOperatorias X Operacion. */
  /* 'main_UCI_func:65' PS = S(:,RO(CP(:,4),2))'; */
  k = CP->size[0];
  i12 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[1] = 1;
  b_TimeUsoRec->size[0] = k;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i12);
  for (i12 = 0; i12 < k; i12++) {
    b_TimeUsoRec->data[i12] = CP->data[3 + (i12 << 3)];
  }

  emxInit_int32_T(&PS, 2);
  k = CP->size[0];
  N = S->size[0];
  i12 = PS->size[0] * PS->size[1];
  PS->size[1] = N;
  PS->size[0] = k;
  emxEnsureCapacity_int32_T(PS, i12);
  for (i12 = 0; i12 < k; i12++) {
    for (i13 = 0; i13 < N; i13++) {
      PS->data[i13 + PS->size[1] * i12] = S->data[(RO->data[1 + 7 *
        (b_TimeUsoRec->data[i12] - 1)] + S->size[1] * i13) - 1];
    }
  }

  /*  Posibles Salon X Operacion. */
  /* 'main_UCI_func:66' PCPO = CPO(:,RO(CP(:,4),2))'; */
  k = CP->size[0];
  i12 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[1] = 1;
  b_TimeUsoRec->size[0] = k;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i12);
  for (i12 = 0; i12 < k; i12++) {
    b_TimeUsoRec->data[i12] = CP->data[3 + (i12 << 3)];
  }

  emxInit_int32_T(&PCPO, 2);
  k = CP->size[0];
  N = CPO->size[0];
  i12 = PCPO->size[0] * PCPO->size[1];
  PCPO->size[1] = N;
  PCPO->size[0] = k;
  emxEnsureCapacity_int32_T(PCPO, i12);
  for (i12 = 0; i12 < k; i12++) {
    for (i13 = 0; i13 < N; i13++) {
      PCPO->data[i13 + PCPO->size[1] * i12] = CPO->data[(RO->data[1 + 7 *
        (b_TimeUsoRec->data[i12] - 1)] + CPO->size[1] * i13) - 1];
    }
  }

  /*  Posibles Camas PostOperatorias X Operacion. */
  /* 'main_UCI_func:67' PCR = CR(:,RO(CP(:,4),2))'; */
  k = CP->size[0];
  i12 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[1] = 1;
  b_TimeUsoRec->size[0] = k;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i12);
  for (i12 = 0; i12 < k; i12++) {
    b_TimeUsoRec->data[i12] = CP->data[3 + (i12 << 3)];
  }

  emxInit_int32_T(&PCR, 2);
  k = CP->size[0];
  N = CR->size[0];
  i12 = PCR->size[0] * PCR->size[1];
  PCR->size[1] = N;
  PCR->size[0] = k;
  emxEnsureCapacity_int32_T(PCR, i12);
  for (i12 = 0; i12 < k; i12++) {
    for (i13 = 0; i13 < N; i13++) {
      PCR->data[i13 + PCR->size[1] * i12] = CR->data[(RO->data[1 + 7 *
        (b_TimeUsoRec->data[i12] - 1)] + CR->size[1] * i13) - 1];
    }
  }

  /*  Posibles Camas de Recuperacion X Operacion. */
  /* 'main_UCI_func:69' EP = CP(:,3); */
  k = CP->size[0];
  i12 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[1] = 1;
  b_TimeUsoRec->size[0] = k;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i12);
  for (i12 = 0; i12 < k; i12++) {
    b_TimeUsoRec->data[i12] = CP->data[2 + (i12 << 3)];
  }

  emxInit_int32_T(&scheduleB, 2);

  /*  Estado del paciente. */
  /*     %% Caso Base */
  /* 'main_UCI_func:72' [ scheduleB,DiaOpB,EspMedOpB ] = casorandom( NumTOp,H,NumRec,PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,Dia,UltPosRecXDia,TimeUsoRec,DispMExD); */
  i12 = scheduleB->size[0] * scheduleB->size[1];
  scheduleB->size[1] = H->size[1];
  scheduleB->size[0] = H->size[0];
  emxEnsureCapacity_int32_T(scheduleB, i12);
  k = H->size[0];
  for (i12 = 0; i12 < k; i12++) {
    N = H->size[1];
    for (i13 = 0; i13 < N; i13++) {
      scheduleB->data[i13 + scheduleB->size[1] * i12] = H->data[i13 + H->size[1]
        * i12];
    }
  }

  i12 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[1] = UltPosRecXDia->size[1];
  varargin_1->size[0] = UltPosRecXDia->size[0];
  emxEnsureCapacity_int32_T(varargin_1, i12);
  k = UltPosRecXDia->size[0];
  for (i12 = 0; i12 < k; i12++) {
    N = UltPosRecXDia->size[1];
    for (i13 = 0; i13 < N; i13++) {
      varargin_1->data[i13 + varargin_1->size[1] * i12] = UltPosRecXDia->
        data[i13 + UltPosRecXDia->size[1] * i12];
    }
  }

  emxInit_int32_T(&DiaOpB, 1);
  emxInit_int32_T(&EspMedOpB, 2);
  casorandom(NumTOp, scheduleB, NumRec, PCPrO, PME, PMA, PMAn, PS, PCPO, PCR,
             Dia, varargin_1, TimeUsoRec, DispMExD, DiaOpB, EspMedOpB);

  /* 'main_UCI_func:74' [ fitnessB,TtB,NOFPB,TmNOFPB,NOE2B,NOE3B] = favalia(scheduleB,DiaOpB,EP,EspMedOpB,k0,k1,k2,k3); */
  i12 = CP->size[0];
  c_TimeUsoRec = *b_TimeUsoRec;
  iv1[0] = i12;
  c_TimeUsoRec.size = &iv1[0];
  c_TimeUsoRec.numDimensions = 1;
  favalia(scheduleB, DiaOpB, &c_TimeUsoRec, EspMedOpB, k0, k1, k2, k3, &y,
          &varargin_2, &varargin_3, &varargin_4, &varargin_5, &varargin_6);

  /* 'main_UCI_func:76' fprintf('Fitness: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t NOE2: %10.5f - \t NOE3: %10.5f \n',fitnessB,TtB,NOFPB,TmNOFPB,NOE2B,NOE3B); */
  printf("Fitness: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t NOE2: %10.5f - \t NOE3: %10.5f \n",
         y, varargin_2, varargin_3, varargin_4, varargin_5, varargin_6);
  fflush(stdout);

  /* 'main_UCI_func:78' toc; */
  toc();

  /*     %% Reorganizando la lista de espera */
  /* 'main_UCI_func:81' NAWD = ((max(CP(:,2),[],1)-CP(:,2))+1).*(360./EP); */
  i12 = CP->size[0];
  iidx_idx_0 = (unsigned int)i12;
  emxFree_int32_T(&varargin_1);
  emxFree_int32_T(&EspMedOpB);
  emxFree_int32_T(&DiaOpB);
  emxFree_int32_T(&scheduleB);
  emxInit_int32_T(&iidx, 1);
  i12 = iidx->size[0];
  iidx->size[0] = (int)iidx_idx_0;
  emxEnsureCapacity_int32_T(iidx, i12);
  N = (int)iidx_idx_0;
  for (k = 0; k < N; k++) {
    iidx->data[k] = (int)rt_roundd(360.0 / (double)b_TimeUsoRec->data[k]);
  }

  N = CP->size[0];
  end = 0;
  i12 = CP->size[0];
  if (i12 >= 1) {
    end = CP->data[1];
    for (k = 2; k <= N; k++) {
      i12 = 1 + ((k - 1) << 3);
      if (end < CP->data[i12]) {
        end = CP->data[i12];
      }
    }
  }

  emxInit_int32_T(&NAWD, 1);
  k = CP->size[0];
  i12 = NAWD->size[0];
  NAWD->size[0] = k;
  emxEnsureCapacity_int32_T(NAWD, i12);
  for (i12 = 0; i12 < k; i12++) {
    NAWD->data[i12] = ((end - CP->data[1 + (i12 << 3)]) + 1) * iidx->data[i12];
  }

  emxInit_int32_T(&x, 1);

  /*  Ajuste de la lista de espera dependiente del estado del paciente y el tiempo de entrada a la lista. */
  /* 'main_UCI_func:83' [~,idx] = sort(NAWD(:,1),'descend'); */
  k = NAWD->size[0];
  i12 = x->size[0];
  x->size[0] = k;
  emxEnsureCapacity_int32_T(x, i12);
  for (i12 = 0; i12 < k; i12++) {
    x->data[i12] = NAWD->data[i12];
  }

  emxFree_int32_T(&NAWD);
  emxInit_int32_T(&b_idx, 1);
  b_sort(x, iidx);
  i12 = b_idx->size[0];
  b_idx->size[0] = iidx->size[0];
  emxEnsureCapacity_int32_T(b_idx, i12);
  k = iidx->size[0];
  emxFree_int32_T(&x);
  for (i12 = 0; i12 < k; i12++) {
    b_idx->data[i12] = iidx->data[i12];
  }

  emxFree_int32_T(&iidx);
  emxInit_int32_T(&NewTimeUsoRec, 2);

  /* 'main_UCI_func:83' ~ */
  /* 'main_UCI_func:85' NewCP = CP(idx,:); */
  /*  Organizo la Lista de Espera */
  /* 'main_UCI_func:87' NewTimeUsoRec = TimeUsoRec(idx,:); */
  i12 = NewTimeUsoRec->size[0] * NewTimeUsoRec->size[1];
  NewTimeUsoRec->size[1] = 7;
  NewTimeUsoRec->size[0] = b_idx->size[0];
  emxEnsureCapacity_int32_T(NewTimeUsoRec, i12);
  k = b_idx->size[0];
  for (i12 = 0; i12 < k; i12++) {
    for (i13 = 0; i13 < 7; i13++) {
      NewTimeUsoRec->data[i13 + 7 * i12] = TimeUsoRec->data[i13 + 7 *
        (b_idx->data[i12] - 1)];
    }
  }

  emxFree_int32_T(&TimeUsoRec);
  emxInit_int32_T(&NewPME, 2);

  /* 'main_UCI_func:89' NewPME = PME(idx,:); */
  k = PME->size[1];
  i12 = NewPME->size[0] * NewPME->size[1];
  NewPME->size[1] = k;
  NewPME->size[0] = b_idx->size[0];
  emxEnsureCapacity_int32_T(NewPME, i12);
  N = b_idx->size[0];
  for (i12 = 0; i12 < N; i12++) {
    for (i13 = 0; i13 < k; i13++) {
      NewPME->data[i13 + NewPME->size[1] * i12] = PME->data[i13 + PME->size[1] *
        (b_idx->data[i12] - 1)];
    }
  }

  emxFree_int32_T(&PME);
  emxInit_int32_T(&NewPMA, 2);

  /*  Posibles Medicos Especialistas X Operacion. */
  /* 'main_UCI_func:90' NewPMA = PMA(idx,:); */
  k = PMA->size[1];
  i12 = NewPMA->size[0] * NewPMA->size[1];
  NewPMA->size[1] = k;
  NewPMA->size[0] = b_idx->size[0];
  emxEnsureCapacity_int32_T(NewPMA, i12);
  N = b_idx->size[0];
  for (i12 = 0; i12 < N; i12++) {
    for (i13 = 0; i13 < k; i13++) {
      NewPMA->data[i13 + NewPMA->size[1] * i12] = PMA->data[i13 + PMA->size[1] *
        (b_idx->data[i12] - 1)];
    }
  }

  emxFree_int32_T(&PMA);
  emxInit_int32_T(&NewPMAn, 2);

  /*  Posibles Medicos Asistentes X Operacion. */
  /* 'main_UCI_func:91' NewPMAn = PMAn(idx,:); */
  k = PMAn->size[1];
  i12 = NewPMAn->size[0] * NewPMAn->size[1];
  NewPMAn->size[1] = k;
  NewPMAn->size[0] = b_idx->size[0];
  emxEnsureCapacity_int32_T(NewPMAn, i12);
  N = b_idx->size[0];
  for (i12 = 0; i12 < N; i12++) {
    for (i13 = 0; i13 < k; i13++) {
      NewPMAn->data[i13 + NewPMAn->size[1] * i12] = PMAn->data[i13 + PMAn->size
        [1] * (b_idx->data[i12] - 1)];
    }
  }

  emxFree_int32_T(&PMAn);
  emxInit_int32_T(&NewPCPrO, 2);

  /*  Posibles Medicos Anestesistas X Operacion. */
  /* 'main_UCI_func:93' NewPCPrO = PCPrO(idx,:); */
  k = PCPrO->size[1];
  i12 = NewPCPrO->size[0] * NewPCPrO->size[1];
  NewPCPrO->size[1] = k;
  NewPCPrO->size[0] = b_idx->size[0];
  emxEnsureCapacity_int32_T(NewPCPrO, i12);
  N = b_idx->size[0];
  for (i12 = 0; i12 < N; i12++) {
    for (i13 = 0; i13 < k; i13++) {
      NewPCPrO->data[i13 + NewPCPrO->size[1] * i12] = PCPrO->data[i13 +
        PCPrO->size[1] * (b_idx->data[i12] - 1)];
    }
  }

  emxFree_int32_T(&PCPrO);
  emxInit_int32_T(&NewPS, 2);

  /*  Posibles Camas PreOperatorias X Operacion. */
  /* 'main_UCI_func:94' NewPS = PS(idx,:); */
  k = PS->size[1];
  i12 = NewPS->size[0] * NewPS->size[1];
  NewPS->size[1] = k;
  NewPS->size[0] = b_idx->size[0];
  emxEnsureCapacity_int32_T(NewPS, i12);
  N = b_idx->size[0];
  for (i12 = 0; i12 < N; i12++) {
    for (i13 = 0; i13 < k; i13++) {
      NewPS->data[i13 + NewPS->size[1] * i12] = PS->data[i13 + PS->size[1] *
        (b_idx->data[i12] - 1)];
    }
  }

  emxFree_int32_T(&PS);
  emxInit_int32_T(&NewPCPO, 2);

  /*  Posibles Salon X Operacion. */
  /* 'main_UCI_func:95' NewPCPO = PCPO(idx,:); */
  k = PCPO->size[1];
  i12 = NewPCPO->size[0] * NewPCPO->size[1];
  NewPCPO->size[1] = k;
  NewPCPO->size[0] = b_idx->size[0];
  emxEnsureCapacity_int32_T(NewPCPO, i12);
  N = b_idx->size[0];
  for (i12 = 0; i12 < N; i12++) {
    for (i13 = 0; i13 < k; i13++) {
      NewPCPO->data[i13 + NewPCPO->size[1] * i12] = PCPO->data[i13 + PCPO->size
        [1] * (b_idx->data[i12] - 1)];
    }
  }

  emxFree_int32_T(&PCPO);
  emxInit_int32_T(&NewPCR, 2);

  /*  Posibles Camas PostOperatorias X Operacion. */
  /* 'main_UCI_func:96' NewPCR = PCR(idx,:); */
  k = PCR->size[1];
  i12 = NewPCR->size[0] * NewPCR->size[1];
  NewPCR->size[1] = k;
  NewPCR->size[0] = b_idx->size[0];
  emxEnsureCapacity_int32_T(NewPCR, i12);
  N = b_idx->size[0];
  for (i12 = 0; i12 < N; i12++) {
    for (i13 = 0; i13 < k; i13++) {
      NewPCR->data[i13 + NewPCR->size[1] * i12] = PCR->data[i13 + PCR->size[1] *
        (b_idx->data[i12] - 1)];
    }
  }

  emxFree_int32_T(&PCR);
  emxInit_int32_T(&NewEP, 1);

  /*  Posibles Camas de Recuperacion X Operacion. */
  /* 'main_UCI_func:98' NewEP = EP(idx); */
  i12 = NewEP->size[0];
  NewEP->size[0] = b_idx->size[0];
  emxEnsureCapacity_int32_T(NewEP, i12);
  k = b_idx->size[0];
  for (i12 = 0; i12 < k; i12++) {
    NewEP->data[i12] = b_TimeUsoRec->data[b_idx->data[i12] - 1];
  }

  emxFree_int32_T(&b_TimeUsoRec);
  emxFree_int32_T(&b_idx);
  emxInit_int32_T(&schedule, 2);

  /*     %% Caso Base */
  /* 'main_UCI_func:102' [ schedule,DiaOp,EspMedOp ] = casorandom( NumTOp,H,NumRec,NewPCPrO,NewPME,NewPMA,NewPMAn,NewPS,NewPCPO,NewPCR,Dia,UltPosRecXDia,NewTimeUsoRec,DispMExD); */
  i12 = schedule->size[0] * schedule->size[1];
  schedule->size[1] = H->size[1];
  schedule->size[0] = H->size[0];
  emxEnsureCapacity_int32_T(schedule, i12);
  k = H->size[0];
  for (i12 = 0; i12 < k; i12++) {
    N = H->size[1];
    for (i13 = 0; i13 < N; i13++) {
      schedule->data[i13 + schedule->size[1] * i12] = H->data[i13 + H->size[1] *
        i12];
    }
  }

  emxFree_int8_T(&H);
  emxInit_int32_T(&DiaOp, 1);
  emxInit_int32_T(&EspMedOp, 2);
  emxInit_int32_T(&bestexperimento, 1);
  emxInit_real_T(&trace, 2);
  casorandom(NumTOp, schedule, NumRec, NewPCPrO, NewPME, NewPMA, NewPMAn, NewPS,
             NewPCPO, NewPCR, Dia, UltPosRecXDia, NewTimeUsoRec, DispMExD, DiaOp,
             EspMedOp);

  /* 'main_UCI_func:104' [fitness,Tt,NOFP,TmNOFP,NOE2,NOE3] = favalia( schedule,DiaOp,NewEP,EspMedOp,k0,k1,k2,k3 ); */
  favalia(schedule, DiaOp, NewEP, EspMedOp, k0, k1, k2, k3, &fitness, &Tt, &NOFP,
          &TmNOFP, &NOE2, &NOE3);

  /* 'main_UCI_func:106' fprintf('Fitness: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t NOE2: %10.5f - \t NOE3: %10.5f \n',fitness,Tt,NOFP,TmNOFP,NOE2,NOE3); */
  printf("Fitness: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t NOE2: %10.5f - \t NOE3: %10.5f \n",
         fitness, Tt, NOFP, TmNOFP, NOE2, NOE3);
  fflush(stdout);

  /* 'main_UCI_func:108' toc; */
  toc();

  /*     %% AE */
  /* 'main_UCI_func:111' allfitness = [fitness,Tt,NOFP,TmNOFP,NOE2,NOE3]; */
  /* 'main_UCI_func:113' [bestexperimento, trace] = aevSPLap(NumTOp,numIC,numIQ,taxC,taxE,taxEQ,NumRec,NewPCPrO,NewPME,NewPMA,NewPMAn,NewPS,NewPCPO,NewPCR,Dia,Data,... */
  /* 'main_UCI_func:114'         NewTimeUsoRec,ProbXEst,allfitness,generations,genToWidth,DispMExD,NewEP,k0,k1,k2,k3,keeppriority); */
  b_fitness[0] = fitness;
  b_fitness[1] = Tt;
  b_fitness[2] = NOFP;
  b_fitness[3] = TmNOFP;
  b_fitness[4] = NOE2;
  b_fitness[5] = NOE3;
  aevSPLap(NumTOp, numIC, numIQ, taxC, taxE, NumRec, NewPCPrO, NewPME, NewPMA,
           NewPMAn, NewPS, NewPCPO, NewPCR, Dia, Data, NewTimeUsoRec, ProbXEst,
           b_fitness, generations, genToWidth, DispMExD, NewEP, k0, k1, k2, k3,
           keeppriority, bestexperimento, trace);

  /* 'main_UCI_func:116' toc; */
  toc();

  /* 'main_UCI_func:118' PLOTT_func(trace, bestexperimento) */
  /* figure */
  /* hold on */
  /* plot(1:100,trace(:,3),'O') */
  /* errorbar(1:100,trace(:,3),trace(:,4),'.') */
  /* 'PLOTT_func:7' figure */
  /* 'PLOTT_func:9' plot(trace(:,1),trace(:,2)); */
  /* 'PLOTT_func:10' hold on */
  /* 'PLOTT_func:11' plot(trace(:,1),trace(:,2),'.'); */
  /* 'PLOTT_func:12' set(gca, 'fontsize', 18)  */
  /* 'PLOTT_func:13' xlabel('Generations','FontName','Arial','FontSize', 28); */
  /* 'PLOTT_func:14' ylabel('# surgeries out of term','FontName','Arial','FontSize', 28); */
  /* 'PLOTT_func:15' fprintf('ignore: %2d, %2d', bestexperimento(3), bestexperimento(5)); */
  printf("ignore: %2d, %2d", bestexperimento->data[2], bestexperimento->data[4]);
  fflush(stdout);
  emxFree_real_T(&trace);
  emxFree_int32_T(&bestexperimento);
  emxFree_int32_T(&EspMedOp);
  emxFree_int32_T(&DiaOp);
  emxFree_int32_T(&schedule);
  emxFree_int32_T(&NewEP);
  emxFree_int32_T(&NewPCR);
  emxFree_int32_T(&NewPCPO);
  emxFree_int32_T(&NewPS);
  emxFree_int32_T(&NewPCPrO);
  emxFree_int32_T(&NewPMAn);
  emxFree_int32_T(&NewPMA);
  emxFree_int32_T(&NewPME);
  emxFree_int32_T(&NewTimeUsoRec);
  emxFree_int32_T(&UltPosRecXDia);
}

/*
 * File trailer for main_UCI_func.c
 *
 * [EOF]
 */
