/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main_UCI_func.c
 *
 * Code generation for function 'main_UCI_func'
 *
 */

/* Include files */
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
  int i8;
  int loop_ub;
  emxArray_int32_T *UltPosRecXDia;
  int end;
  emxArray_int32_T *TimeUsoRec;
  emxArray_int32_T *iidx;
  emxArray_int32_T *varargin_1;
  boolean_T empty_non_axis_sizes;
  int input_sizes_idx_1;
  signed char sizes_idx_1;
  emxArray_int32_T *PME;
  emxArray_int32_T *PMA;
  emxArray_int32_T *PMAn;
  emxArray_boolean_T *idx;
  emxArray_int32_T *r2;
  emxArray_int32_T *r3;
  emxArray_int32_T *r4;
  int i;
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *PS;
  emxArray_int32_T *PCPO;
  emxArray_int32_T *PCR;
  emxArray_int32_T *EP;
  emxArray_int32_T *scheduleB;
  emxArray_int32_T *DiaOpB;
  emxArray_int32_T *EspMedOpB;
  double varargin_2;
  double varargin_3;
  double varargin_4;
  double varargin_5;
  double varargin_6;
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
  k = Data->size[0];
  i8 = H->size[0] * H->size[1];
  H->size[0] = k;
  loop_ub = (int)y;
  H->size[1] = loop_ub;
  emxEnsureCapacity_int8_T(H, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    for (end = 0; end < k; end++) {
      H->data[end + H->size[0] * i8] = 0;
    }
  }

  emxInit_int32_T(&UltPosRecXDia, 2);

  /*  Schedule completo */
  /* 'main_UCI_func:24' UltPosRecXDia = zeros(size(Dia,1),size(H,2), 'int32'); */
  k = Dia->size[0];
  i8 = UltPosRecXDia->size[0] * UltPosRecXDia->size[1];
  UltPosRecXDia->size[0] = k;
  UltPosRecXDia->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(UltPosRecXDia, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    for (end = 0; end < k; end++) {
      UltPosRecXDia->data[end + UltPosRecXDia->size[0] * i8] = 0;
    }
  }

  emxInit_int32_T(&TimeUsoRec, 2);

  /*  Ultima posicion asignado del recurso por Dia */
  /*     %% Matriz con el tiempo de uso necesario de todos los recursos */
  /* Cama Pre-OP,Sala de Operación, Medicos Especialistas, Medicos Asistentes, Medicos Anstesistas, Cama Post-OP, Cama Recuperacion.  */
  /* 'main_UCI_func:30' TimeUsoRec = zeros(NumTOp, 7, 'int32'); */
  i8 = TimeUsoRec->size[0] * TimeUsoRec->size[1];
  TimeUsoRec->size[0] = NumTOp;
  TimeUsoRec->size[1] = 7;
  emxEnsureCapacity_int32_T(TimeUsoRec, i8);
  for (i8 = 0; i8 < 7; i8++) {
    for (end = 0; end < NumTOp; end++) {
      TimeUsoRec->data[end + TimeUsoRec->size[0] * i8] = 0;
    }
  }

  /* 'main_UCI_func:31' TimeUsoRec(:,1) = CP(:,6); */
  loop_ub = CP->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    TimeUsoRec->data[i8] = CP->data[i8 + CP->size[0] * 5];
  }

  /*  Tiempo de uso cama Pre-Operatoria */
  /* 'main_UCI_func:32' TimeUsoRec(:,2) = RO(CP(:,4),4); */
  loop_ub = CP->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    TimeUsoRec->data[i8 + TimeUsoRec->size[0]] = RO->data[(CP->data[i8 +
      CP->size[0] * 3] + RO->size[0] * 3) - 1];
  }

  emxInit_int32_T(&iidx, 1);

  /*  Tiempo de uso Salon de operacion */
  /* 'main_UCI_func:33' TimeUsoRec(:,3) = TimeUsoRec(:,2); */
  loop_ub = TimeUsoRec->size[0] - 1;
  i8 = iidx->size[0];
  iidx->size[0] = loop_ub + 1;
  emxEnsureCapacity_int32_T(iidx, i8);
  for (i8 = 0; i8 <= loop_ub; i8++) {
    iidx->data[i8] = TimeUsoRec->data[i8 + TimeUsoRec->size[0]];
  }

  loop_ub = iidx->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    TimeUsoRec->data[i8 + (TimeUsoRec->size[0] << 1)] = iidx->data[i8];
  }

  /*  Tiempo de uso Medico Especialista */
  /* 'main_UCI_func:34' TimeUsoRec(:,4) = TimeUsoRec(:,2); */
  loop_ub = TimeUsoRec->size[0] - 1;
  i8 = iidx->size[0];
  iidx->size[0] = loop_ub + 1;
  emxEnsureCapacity_int32_T(iidx, i8);
  for (i8 = 0; i8 <= loop_ub; i8++) {
    iidx->data[i8] = TimeUsoRec->data[i8 + TimeUsoRec->size[0]];
  }

  loop_ub = iidx->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    TimeUsoRec->data[i8 + TimeUsoRec->size[0] * 3] = iidx->data[i8];
  }

  /*  Tiempo de uso Medico Asistente */
  /* 'main_UCI_func:35' TimeUsoRec(:,5) = TimeUsoRec(:,2); */
  loop_ub = TimeUsoRec->size[0] - 1;
  i8 = iidx->size[0];
  iidx->size[0] = loop_ub + 1;
  emxEnsureCapacity_int32_T(iidx, i8);
  for (i8 = 0; i8 <= loop_ub; i8++) {
    iidx->data[i8] = TimeUsoRec->data[i8 + TimeUsoRec->size[0]];
  }

  loop_ub = iidx->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    TimeUsoRec->data[i8 + (TimeUsoRec->size[0] << 2)] = iidx->data[i8];
  }

  /*  Tiempo de uso Medico Anestesista */
  /* 'main_UCI_func:36' TimeUsoRec(:,6:7) = CP(:,7:8); */
  loop_ub = CP->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    TimeUsoRec->data[i8 + TimeUsoRec->size[0] * 5] = CP->data[i8 + CP->size[0] *
      6];
  }

  for (i8 = 0; i8 < loop_ub; i8++) {
    TimeUsoRec->data[i8 + TimeUsoRec->size[0] * 6] = CP->data[i8 + CP->size[0] *
      7];
  }

  emxInit_int32_T(&varargin_1, 2);

  /*  Tiempo de uso cama Post-Operatoria y Recuperacion */
  /* 'main_UCI_func:38' PME = [ME(:,RO(CP(:,4),2))' RO(CP(:,4),5)]; */
  loop_ub = ME->size[0];
  k = CP->size[0];
  i8 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = k;
  varargin_1->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(varargin_1, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    for (end = 0; end < k; end++) {
      varargin_1->data[end + varargin_1->size[0] * i8] = ME->data[i8 + ME->size
        [0] * (RO->data[(CP->data[end + CP->size[0] * 3] + RO->size[0]) - 1] - 1)];
    }
  }

  loop_ub = CP->size[0];
  i8 = iidx->size[0];
  iidx->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(iidx, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    iidx->data[i8] = RO->data[(CP->data[i8 + CP->size[0] * 3] + (RO->size[0] <<
      2)) - 1];
  }

  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    k = varargin_1->size[0];
  } else {
    i8 = CP->size[0];
    if (i8 != 0) {
      k = CP->size[0];
    } else {
      k = varargin_1->size[0];
      if (k <= 0) {
        k = 0;
      }

      i8 = CP->size[0];
      if (i8 > k) {
        k = CP->size[0];
      }
    }
  }

  empty_non_axis_sizes = (k == 0);
  if (empty_non_axis_sizes || ((varargin_1->size[0] != 0) && (varargin_1->size[1]
        != 0))) {
    input_sizes_idx_1 = varargin_1->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }

  if (empty_non_axis_sizes) {
    sizes_idx_1 = 1;
  } else {
    i8 = CP->size[0];
    if (i8 != 0) {
      sizes_idx_1 = 1;
    } else {
      sizes_idx_1 = 0;
    }
  }

  emxInit_int32_T(&PME, 2);
  i8 = PME->size[0] * PME->size[1];
  PME->size[0] = k;
  PME->size[1] = input_sizes_idx_1 + sizes_idx_1;
  emxEnsureCapacity_int32_T(PME, i8);
  for (i8 = 0; i8 < input_sizes_idx_1; i8++) {
    for (end = 0; end < k; end++) {
      PME->data[end + PME->size[0] * i8] = varargin_1->data[end + k * i8];
    }
  }

  loop_ub = sizes_idx_1;
  for (i8 = 0; i8 < loop_ub; i8++) {
    for (end = 0; end < k; end++) {
      PME->data[end + PME->size[0] * input_sizes_idx_1] = iidx->data[end];
    }
  }

  /*  Posibles Medicos Especialistas X Operacion. | Cantidad necesaria de Medicos Especialistas */
  /* 'main_UCI_func:40' PMA = [MA(:,RO(CP(:,4),2))' RO(CP(:,4),6)]; */
  loop_ub = MA->size[0];
  k = CP->size[0];
  i8 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = k;
  varargin_1->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(varargin_1, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    for (end = 0; end < k; end++) {
      varargin_1->data[end + varargin_1->size[0] * i8] = MA->data[i8 + MA->size
        [0] * (RO->data[(CP->data[end + CP->size[0] * 3] + RO->size[0]) - 1] - 1)];
    }
  }

  loop_ub = CP->size[0];
  i8 = iidx->size[0];
  iidx->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(iidx, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    iidx->data[i8] = RO->data[(CP->data[i8 + CP->size[0] * 3] + RO->size[0] * 5)
      - 1];
  }

  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    k = varargin_1->size[0];
  } else {
    i8 = CP->size[0];
    if (i8 != 0) {
      k = CP->size[0];
    } else {
      k = varargin_1->size[0];
      if (k <= 0) {
        k = 0;
      }

      i8 = CP->size[0];
      if (i8 > k) {
        k = CP->size[0];
      }
    }
  }

  empty_non_axis_sizes = (k == 0);
  if (empty_non_axis_sizes || ((varargin_1->size[0] != 0) && (varargin_1->size[1]
        != 0))) {
    input_sizes_idx_1 = varargin_1->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }

  if (empty_non_axis_sizes) {
    sizes_idx_1 = 1;
  } else {
    i8 = CP->size[0];
    if (i8 != 0) {
      sizes_idx_1 = 1;
    } else {
      sizes_idx_1 = 0;
    }
  }

  emxInit_int32_T(&PMA, 2);
  i8 = PMA->size[0] * PMA->size[1];
  PMA->size[0] = k;
  PMA->size[1] = input_sizes_idx_1 + sizes_idx_1;
  emxEnsureCapacity_int32_T(PMA, i8);
  for (i8 = 0; i8 < input_sizes_idx_1; i8++) {
    for (end = 0; end < k; end++) {
      PMA->data[end + PMA->size[0] * i8] = varargin_1->data[end + k * i8];
    }
  }

  loop_ub = sizes_idx_1;
  for (i8 = 0; i8 < loop_ub; i8++) {
    for (end = 0; end < k; end++) {
      PMA->data[end + PMA->size[0] * input_sizes_idx_1] = iidx->data[end];
    }
  }

  /*  Posibles Medicos Asistentes X Operacion. | Cantidad necesaria de Medicos Asistentes */
  /* 'main_UCI_func:42' PMAn = [MAn(:,RO(CP(:,4),2))' RO(CP(:,4),7)]; */
  loop_ub = MAn->size[0];
  k = CP->size[0];
  i8 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = k;
  varargin_1->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(varargin_1, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    for (end = 0; end < k; end++) {
      varargin_1->data[end + varargin_1->size[0] * i8] = MAn->data[i8 +
        MAn->size[0] * (RO->data[(CP->data[end + CP->size[0] * 3] + RO->size[0])
                        - 1] - 1)];
    }
  }

  loop_ub = CP->size[0];
  i8 = iidx->size[0];
  iidx->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(iidx, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    iidx->data[i8] = RO->data[(CP->data[i8 + CP->size[0] * 3] + RO->size[0] * 6)
      - 1];
  }

  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    k = varargin_1->size[0];
  } else {
    i8 = CP->size[0];
    if (i8 != 0) {
      k = CP->size[0];
    } else {
      k = varargin_1->size[0];
      if (k <= 0) {
        k = 0;
      }

      i8 = CP->size[0];
      if (i8 > k) {
        k = CP->size[0];
      }
    }
  }

  empty_non_axis_sizes = (k == 0);
  if (empty_non_axis_sizes || ((varargin_1->size[0] != 0) && (varargin_1->size[1]
        != 0))) {
    input_sizes_idx_1 = varargin_1->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }

  if (empty_non_axis_sizes) {
    sizes_idx_1 = 1;
  } else {
    i8 = CP->size[0];
    if (i8 != 0) {
      sizes_idx_1 = 1;
    } else {
      sizes_idx_1 = 0;
    }
  }

  emxInit_int32_T(&PMAn, 2);
  i8 = PMAn->size[0] * PMAn->size[1];
  PMAn->size[0] = k;
  PMAn->size[1] = input_sizes_idx_1 + sizes_idx_1;
  emxEnsureCapacity_int32_T(PMAn, i8);
  for (i8 = 0; i8 < input_sizes_idx_1; i8++) {
    for (end = 0; end < k; end++) {
      PMAn->data[end + PMAn->size[0] * i8] = varargin_1->data[end + k * i8];
    }
  }

  loop_ub = sizes_idx_1;
  for (i8 = 0; i8 < loop_ub; i8++) {
    for (end = 0; end < k; end++) {
      PMAn->data[end + PMAn->size[0] * input_sizes_idx_1] = iidx->data[end];
    }
  }

  /*  Posibles Medicos Anestesistas X Operacion. | Cantidad necesaria de Medicos Anestesistas */
  /* 'main_UCI_func:44' CxO = RO(CP(:,4),3); */
  /*  Complejidad de la Operacion */
  /* 'main_UCI_func:46' for i=1:NumTOp */
  emxInit_boolean_T(&idx, 2);
  emxInit_int32_T(&r2, 2);
  emxInit_int32_T(&r3, 2);
  emxInit_int32_T(&r4, 2);
  for (i = 0; i < NumTOp; i++) {
    /* 'main_UCI_func:48' if CxO(i)==1 */
    if (RO->data[(CP->data[i + CP->size[0] * 3] + (RO->size[0] << 1)) - 1] == 1)
    {
      /*  Si la operacion es de alto riesgo quitar los Medicos de nivel 3 como opcion */
      /* 'main_UCI_func:50' idx= PME(i,1:end-1)==3; */
      if (1 > PME->size[1] - 1) {
        loop_ub = 0;
      } else {
        loop_ub = PME->size[1] - 1;
      }

      i8 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = loop_ub;
      emxEnsureCapacity_boolean_T(idx, i8);
      for (i8 = 0; i8 < loop_ub; i8++) {
        idx->data[i8] = (PME->data[i + PME->size[0] * i8] == 3);
      }

      /* 'main_UCI_func:51' PME(i,idx)=0; */
      end = idx->size[1] - 1;
      k = 0;
      for (input_sizes_idx_1 = 0; input_sizes_idx_1 <= end; input_sizes_idx_1++)
      {
        if (idx->data[input_sizes_idx_1]) {
          k++;
        }
      }

      i8 = r2->size[0] * r2->size[1];
      r2->size[0] = 1;
      r2->size[1] = k;
      emxEnsureCapacity_int32_T(r2, i8);
      k = 0;
      for (input_sizes_idx_1 = 0; input_sizes_idx_1 <= end; input_sizes_idx_1++)
      {
        if (idx->data[input_sizes_idx_1]) {
          r2->data[k] = input_sizes_idx_1 + 1;
          k++;
        }
      }

      k = r2->size[1];
      for (i8 = 0; i8 < k; i8++) {
        PME->data[i + PME->size[0] * (r2->data[i8] - 1)] = 0;
      }

      /* 'main_UCI_func:53' idx= PMA(i,1:end-1)==3; */
      if (1 > PMA->size[1] - 1) {
        loop_ub = 0;
      } else {
        loop_ub = PMA->size[1] - 1;
      }

      i8 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = loop_ub;
      emxEnsureCapacity_boolean_T(idx, i8);
      for (i8 = 0; i8 < loop_ub; i8++) {
        idx->data[i8] = (PMA->data[i + PMA->size[0] * i8] == 3);
      }

      /* 'main_UCI_func:54' PMA(i,idx)=0; */
      end = idx->size[1] - 1;
      k = 0;
      for (input_sizes_idx_1 = 0; input_sizes_idx_1 <= end; input_sizes_idx_1++)
      {
        if (idx->data[input_sizes_idx_1]) {
          k++;
        }
      }

      i8 = r3->size[0] * r3->size[1];
      r3->size[0] = 1;
      r3->size[1] = k;
      emxEnsureCapacity_int32_T(r3, i8);
      k = 0;
      for (input_sizes_idx_1 = 0; input_sizes_idx_1 <= end; input_sizes_idx_1++)
      {
        if (idx->data[input_sizes_idx_1]) {
          r3->data[k] = input_sizes_idx_1 + 1;
          k++;
        }
      }

      k = r3->size[1];
      for (i8 = 0; i8 < k; i8++) {
        PMA->data[i + PMA->size[0] * (r3->data[i8] - 1)] = 0;
      }

      /* 'main_UCI_func:56' idx=PMAn(i,1:end-1)==3; */
      if (1 > PMAn->size[1] - 1) {
        loop_ub = 0;
      } else {
        loop_ub = PMAn->size[1] - 1;
      }

      i8 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = loop_ub;
      emxEnsureCapacity_boolean_T(idx, i8);
      for (i8 = 0; i8 < loop_ub; i8++) {
        idx->data[i8] = (PMAn->data[i + PMAn->size[0] * i8] == 3);
      }

      /* 'main_UCI_func:57' PMAn(i,idx)=0; */
      end = idx->size[1] - 1;
      k = 0;
      for (input_sizes_idx_1 = 0; input_sizes_idx_1 <= end; input_sizes_idx_1++)
      {
        if (idx->data[input_sizes_idx_1]) {
          k++;
        }
      }

      i8 = r4->size[0] * r4->size[1];
      r4->size[0] = 1;
      r4->size[1] = k;
      emxEnsureCapacity_int32_T(r4, i8);
      k = 0;
      for (input_sizes_idx_1 = 0; input_sizes_idx_1 <= end; input_sizes_idx_1++)
      {
        if (idx->data[input_sizes_idx_1]) {
          r4->data[k] = input_sizes_idx_1 + 1;
          k++;
        }
      }

      k = r4->size[1];
      for (i8 = 0; i8 < k; i8++) {
        PMAn->data[i + PMAn->size[0] * (r4->data[i8] - 1)] = 0;
      }
    }
  }

  emxFree_int32_T(&r4);
  emxFree_int32_T(&r3);
  emxFree_int32_T(&r2);
  emxFree_boolean_T(&idx);
  emxInit_int32_T(&PCPrO, 2);

  /* 'main_UCI_func:64' PCPrO = CPrO(:,RO(CP(:,4),2))'; */
  loop_ub = CPrO->size[0];
  k = CP->size[0];
  i8 = PCPrO->size[0] * PCPrO->size[1];
  PCPrO->size[0] = k;
  PCPrO->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(PCPrO, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    for (end = 0; end < k; end++) {
      PCPrO->data[end + PCPrO->size[0] * i8] = CPrO->data[i8 + CPrO->size[0] *
        (RO->data[(CP->data[end + CP->size[0] * 3] + RO->size[0]) - 1] - 1)];
    }
  }

  emxInit_int32_T(&PS, 2);

  /*  Posibles Camas PreOperatorias X Operacion. */
  /* 'main_UCI_func:65' PS = S(:,RO(CP(:,4),2))'; */
  loop_ub = S->size[0];
  k = CP->size[0];
  i8 = PS->size[0] * PS->size[1];
  PS->size[0] = k;
  PS->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(PS, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    for (end = 0; end < k; end++) {
      PS->data[end + PS->size[0] * i8] = S->data[i8 + S->size[0] * (RO->data
        [(CP->data[end + CP->size[0] * 3] + RO->size[0]) - 1] - 1)];
    }
  }

  emxInit_int32_T(&PCPO, 2);

  /*  Posibles Salon X Operacion. */
  /* 'main_UCI_func:66' PCPO = CPO(:,RO(CP(:,4),2))'; */
  loop_ub = CPO->size[0];
  k = CP->size[0];
  i8 = PCPO->size[0] * PCPO->size[1];
  PCPO->size[0] = k;
  PCPO->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(PCPO, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    for (end = 0; end < k; end++) {
      PCPO->data[end + PCPO->size[0] * i8] = CPO->data[i8 + CPO->size[0] *
        (RO->data[(CP->data[end + CP->size[0] * 3] + RO->size[0]) - 1] - 1)];
    }
  }

  emxInit_int32_T(&PCR, 2);

  /*  Posibles Camas PostOperatorias X Operacion. */
  /* 'main_UCI_func:67' PCR = CR(:,RO(CP(:,4),2))'; */
  loop_ub = CR->size[0];
  k = CP->size[0];
  i8 = PCR->size[0] * PCR->size[1];
  PCR->size[0] = k;
  PCR->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(PCR, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    for (end = 0; end < k; end++) {
      PCR->data[end + PCR->size[0] * i8] = CR->data[i8 + CR->size[0] * (RO->
        data[(CP->data[end + CP->size[0] * 3] + RO->size[0]) - 1] - 1)];
    }
  }

  emxInit_int32_T(&EP, 1);

  /*  Posibles Camas de Recuperacion X Operacion. */
  /* 'main_UCI_func:69' EP = CP(:,3); */
  loop_ub = CP->size[0];
  i8 = EP->size[0];
  EP->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(EP, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    EP->data[i8] = CP->data[i8 + (CP->size[0] << 1)];
  }

  emxInit_int32_T(&scheduleB, 2);

  /*  Estado del paciente. */
  /*     %% Caso Base */
  /* 'main_UCI_func:72' [ scheduleB,DiaOpB,EspMedOpB ] = casorandom( NumTOp,H,NumRec,PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,Dia,UltPosRecXDia,TimeUsoRec,DispMExD); */
  i8 = scheduleB->size[0] * scheduleB->size[1];
  scheduleB->size[0] = H->size[0];
  scheduleB->size[1] = H->size[1];
  emxEnsureCapacity_int32_T(scheduleB, i8);
  loop_ub = H->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    k = H->size[0];
    for (end = 0; end < k; end++) {
      scheduleB->data[end + scheduleB->size[0] * i8] = H->data[end + H->size[0] *
        i8];
    }
  }

  i8 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = UltPosRecXDia->size[0];
  varargin_1->size[1] = UltPosRecXDia->size[1];
  emxEnsureCapacity_int32_T(varargin_1, i8);
  loop_ub = UltPosRecXDia->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    k = UltPosRecXDia->size[0];
    for (end = 0; end < k; end++) {
      varargin_1->data[end + varargin_1->size[0] * i8] = UltPosRecXDia->data[end
        + UltPosRecXDia->size[0] * i8];
    }
  }

  emxInit_int32_T(&DiaOpB, 1);
  emxInit_int32_T(&EspMedOpB, 2);
  casorandom(NumTOp, scheduleB, NumRec, PCPrO, PME, PMA, PMAn, PS, PCPO, PCR,
             Dia, varargin_1, TimeUsoRec, DispMExD, DiaOpB, EspMedOpB);

  /* 'main_UCI_func:74' [ fitnessB,TtB,NOFPB,TmNOFPB,NOE2B,NOE3B] = favalia(scheduleB,DiaOpB,EP,EspMedOpB,k0,k1,k2,k3); */
  favalia(scheduleB, DiaOpB, EP, EspMedOpB, k0, k1, k2, k3, &y, &varargin_2,
          &varargin_3, &varargin_4, &varargin_5, &varargin_6);

  /* 'main_UCI_func:76' fprintf('Fitness: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t NOE2: %10.5f - \t NOE3: %10.5f \n',fitnessB,TtB,NOFPB,TmNOFPB,NOE2B,NOE3B); */
  printf("Fitness: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t NOE2: %10.5f - \t NOE3: %10.5f \n",
         y, varargin_2, varargin_3, varargin_4, varargin_5, varargin_6);
  fflush(stdout);

  /* 'main_UCI_func:78' toc; */
  toc();

  /*     %% Reorganizando la lista de espera */
  /* 'main_UCI_func:81' NAWD = ((max(CP(:,2))-CP(:,2))+1).*(360./EP); */
  i8 = CP->size[0];
  end = iidx->size[0];
  iidx->size[0] = i8;
  emxEnsureCapacity_int32_T(iidx, end);
  emxFree_int32_T(&varargin_1);
  emxFree_int32_T(&EspMedOpB);
  emxFree_int32_T(&DiaOpB);
  emxFree_int32_T(&scheduleB);
  for (k = 0; k < i8; k++) {
    iidx->data[k] = (int)rt_roundd(360.0 / (double)CP->data[k + (CP->size[0] <<
      1)]);
  }

  input_sizes_idx_1 = CP->size[0];
  end = 0;
  i8 = CP->size[0];
  if (i8 >= 1) {
    end = CP->data[CP->size[0]];
    for (k = 2; k <= input_sizes_idx_1; k++) {
      if (end < CP->data[(k + CP->size[0]) - 1]) {
        end = CP->data[(k + CP->size[0]) - 1];
      }
    }
  }

  emxInit_int32_T(&NAWD, 1);
  loop_ub = CP->size[0];
  i8 = NAWD->size[0];
  NAWD->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(NAWD, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    NAWD->data[i8] = ((end - CP->data[i8 + CP->size[0]]) + 1) * iidx->data[i8];
  }

  emxInit_int32_T(&x, 1);

  /*  Ajuste de la lista de espera dependiente del estado del paciente y el tiempo de entrada a la lista. */
  /* 'main_UCI_func:83' [~,idx] = sort(NAWD(:,1),'descend'); */
  loop_ub = NAWD->size[0];
  i8 = x->size[0];
  x->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(x, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    x->data[i8] = NAWD->data[i8];
  }

  emxFree_int32_T(&NAWD);
  emxInit_int32_T(&b_idx, 1);
  b_sort(x, iidx);
  i8 = b_idx->size[0];
  b_idx->size[0] = iidx->size[0];
  emxEnsureCapacity_int32_T(b_idx, i8);
  loop_ub = iidx->size[0];
  emxFree_int32_T(&x);
  for (i8 = 0; i8 < loop_ub; i8++) {
    b_idx->data[i8] = iidx->data[i8];
  }

  emxFree_int32_T(&iidx);
  emxInit_int32_T(&NewTimeUsoRec, 2);

  /* 'main_UCI_func:83' ~ */
  /* 'main_UCI_func:85' NewCP = CP(idx,:); */
  /*  Organizo la Lista de Espera */
  /* 'main_UCI_func:87' NewTimeUsoRec = TimeUsoRec(idx,:); */
  i8 = NewTimeUsoRec->size[0] * NewTimeUsoRec->size[1];
  NewTimeUsoRec->size[0] = b_idx->size[0];
  NewTimeUsoRec->size[1] = 7;
  emxEnsureCapacity_int32_T(NewTimeUsoRec, i8);
  for (i8 = 0; i8 < 7; i8++) {
    loop_ub = b_idx->size[0];
    for (end = 0; end < loop_ub; end++) {
      NewTimeUsoRec->data[end + NewTimeUsoRec->size[0] * i8] = TimeUsoRec->data
        [(b_idx->data[end] + TimeUsoRec->size[0] * i8) - 1];
    }
  }

  emxFree_int32_T(&TimeUsoRec);
  emxInit_int32_T(&NewPME, 2);

  /* 'main_UCI_func:89' NewPME = PME(idx,:); */
  loop_ub = PME->size[1];
  i8 = NewPME->size[0] * NewPME->size[1];
  NewPME->size[0] = b_idx->size[0];
  NewPME->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(NewPME, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    k = b_idx->size[0];
    for (end = 0; end < k; end++) {
      NewPME->data[end + NewPME->size[0] * i8] = PME->data[(b_idx->data[end] +
        PME->size[0] * i8) - 1];
    }
  }

  emxFree_int32_T(&PME);
  emxInit_int32_T(&NewPMA, 2);

  /*  Posibles Medicos Especialistas X Operacion. */
  /* 'main_UCI_func:90' NewPMA = PMA(idx,:); */
  loop_ub = PMA->size[1];
  i8 = NewPMA->size[0] * NewPMA->size[1];
  NewPMA->size[0] = b_idx->size[0];
  NewPMA->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(NewPMA, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    k = b_idx->size[0];
    for (end = 0; end < k; end++) {
      NewPMA->data[end + NewPMA->size[0] * i8] = PMA->data[(b_idx->data[end] +
        PMA->size[0] * i8) - 1];
    }
  }

  emxFree_int32_T(&PMA);
  emxInit_int32_T(&NewPMAn, 2);

  /*  Posibles Medicos Asistentes X Operacion. */
  /* 'main_UCI_func:91' NewPMAn = PMAn(idx,:); */
  loop_ub = PMAn->size[1];
  i8 = NewPMAn->size[0] * NewPMAn->size[1];
  NewPMAn->size[0] = b_idx->size[0];
  NewPMAn->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(NewPMAn, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    k = b_idx->size[0];
    for (end = 0; end < k; end++) {
      NewPMAn->data[end + NewPMAn->size[0] * i8] = PMAn->data[(b_idx->data[end]
        + PMAn->size[0] * i8) - 1];
    }
  }

  emxFree_int32_T(&PMAn);
  emxInit_int32_T(&NewPCPrO, 2);

  /*  Posibles Medicos Anestesistas X Operacion. */
  /* 'main_UCI_func:93' NewPCPrO = PCPrO(idx,:); */
  loop_ub = PCPrO->size[1];
  i8 = NewPCPrO->size[0] * NewPCPrO->size[1];
  NewPCPrO->size[0] = b_idx->size[0];
  NewPCPrO->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(NewPCPrO, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    k = b_idx->size[0];
    for (end = 0; end < k; end++) {
      NewPCPrO->data[end + NewPCPrO->size[0] * i8] = PCPrO->data[(b_idx->
        data[end] + PCPrO->size[0] * i8) - 1];
    }
  }

  emxFree_int32_T(&PCPrO);
  emxInit_int32_T(&NewPS, 2);

  /*  Posibles Camas PreOperatorias X Operacion. */
  /* 'main_UCI_func:94' NewPS = PS(idx,:); */
  loop_ub = PS->size[1];
  i8 = NewPS->size[0] * NewPS->size[1];
  NewPS->size[0] = b_idx->size[0];
  NewPS->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(NewPS, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    k = b_idx->size[0];
    for (end = 0; end < k; end++) {
      NewPS->data[end + NewPS->size[0] * i8] = PS->data[(b_idx->data[end] +
        PS->size[0] * i8) - 1];
    }
  }

  emxFree_int32_T(&PS);
  emxInit_int32_T(&NewPCPO, 2);

  /*  Posibles Salon X Operacion. */
  /* 'main_UCI_func:95' NewPCPO = PCPO(idx,:); */
  loop_ub = PCPO->size[1];
  i8 = NewPCPO->size[0] * NewPCPO->size[1];
  NewPCPO->size[0] = b_idx->size[0];
  NewPCPO->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(NewPCPO, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    k = b_idx->size[0];
    for (end = 0; end < k; end++) {
      NewPCPO->data[end + NewPCPO->size[0] * i8] = PCPO->data[(b_idx->data[end]
        + PCPO->size[0] * i8) - 1];
    }
  }

  emxFree_int32_T(&PCPO);
  emxInit_int32_T(&NewPCR, 2);

  /*  Posibles Camas PostOperatorias X Operacion. */
  /* 'main_UCI_func:96' NewPCR = PCR(idx,:); */
  loop_ub = PCR->size[1];
  i8 = NewPCR->size[0] * NewPCR->size[1];
  NewPCR->size[0] = b_idx->size[0];
  NewPCR->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(NewPCR, i8);
  for (i8 = 0; i8 < loop_ub; i8++) {
    k = b_idx->size[0];
    for (end = 0; end < k; end++) {
      NewPCR->data[end + NewPCR->size[0] * i8] = PCR->data[(b_idx->data[end] +
        PCR->size[0] * i8) - 1];
    }
  }

  emxFree_int32_T(&PCR);
  emxInit_int32_T(&NewEP, 1);

  /*  Posibles Camas de Recuperacion X Operacion. */
  /* 'main_UCI_func:98' NewEP = EP(idx); */
  i8 = NewEP->size[0];
  NewEP->size[0] = b_idx->size[0];
  emxEnsureCapacity_int32_T(NewEP, i8);
  loop_ub = b_idx->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    NewEP->data[i8] = EP->data[b_idx->data[i8] - 1];
  }

  emxFree_int32_T(&b_idx);
  emxFree_int32_T(&EP);
  emxInit_int32_T(&schedule, 2);

  /*     %% Caso Base */
  /* 'main_UCI_func:102' [ schedule,DiaOp,EspMedOp ] = casorandom( NumTOp,H,NumRec,NewPCPrO,NewPME,NewPMA,NewPMAn,NewPS,NewPCPO,NewPCR,Dia,UltPosRecXDia,NewTimeUsoRec,DispMExD); */
  i8 = schedule->size[0] * schedule->size[1];
  schedule->size[0] = H->size[0];
  schedule->size[1] = H->size[1];
  emxEnsureCapacity_int32_T(schedule, i8);
  loop_ub = H->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    k = H->size[0];
    for (end = 0; end < k; end++) {
      schedule->data[end + schedule->size[0] * i8] = H->data[end + H->size[0] *
        i8];
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

/* End of code generation (main_UCI_func.c) */
