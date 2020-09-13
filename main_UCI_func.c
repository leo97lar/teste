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
#include "toc.h"
#include "sort1.h"
#include "sum.h"
#include "tic.h"
#include "model_rtwutil.h"
#include <stdio.h>

/* Function Definitions */
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
  emxArray_int32_T *H;
  int NumRec[7];
  int i50;
  int end;
  int loop_ub;
  emxArray_int32_T *UltPosRecXDia;
  emxArray_int32_T *TimeUsoRec;
  emxArray_int32_T *b_TimeUsoRec;
  emxArray_int32_T *varargin_1;
  int b_loop_ub;
  boolean_T empty_non_axis_sizes;
  int input_sizes_idx_1;
  signed char sizes_idx_1;
  emxArray_int32_T *PME;
  emxArray_int32_T *PMA;
  emxArray_int32_T *PMAn;
  emxArray_boolean_T *idx;
  emxArray_int32_T *r6;
  emxArray_int32_T *r7;
  emxArray_int32_T *r8;
  int i;
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *PS;
  emxArray_int32_T *PCPO;
  emxArray_int32_T *PCR;
  emxArray_int32_T *b_H;
  emxArray_int32_T *b_UltPosRecXDia;
  emxArray_int32_T *NAWD;
  emxArray_int32_T *EspMedOpB;
  double b_varargin_1;
  double varargin_2;
  double varargin_3;
  double varargin_4;
  double varargin_5;
  double varargin_6;
  emxArray_int32_T *NewEP;
  long long i51;
  emxArray_int32_T *NewTimeUsoRec;
  emxArray_int32_T *NewPME;
  emxArray_int32_T *NewPMA;
  emxArray_int32_T *NewPMAn;
  emxArray_int32_T *NewPCPrO;
  emxArray_real_T *trace;
  double fitness[6];
  (void)TipoOp;
  (void)NumEsp;
  (void)NumEspxE;
  (void)taxEQ;
  emxInit_int32_T(&H, 2);
  tic();

  /*     %% Matriz de Horario. En las filas los dias */
  NumRec[0] = NumCPrO;
  NumRec[1] = NumMedEsp;
  NumRec[2] = NumSalOp;
  NumRec[3] = NumAsist;
  NumRec[4] = NumAnest;
  NumRec[5] = NumCPO;
  NumRec[6] = NumCR;

  /*  Numero de recursos */
  i50 = H->size[0] * H->size[1];
  H->size[0] = Data->size[0];
  end = (int)c_sum(NumRec);
  H->size[1] = end;
  emxEnsureCapacity_int32_T(H, i50);
  loop_ub = Data->size[0] * end;
  for (i50 = 0; i50 < loop_ub; i50++) {
    H->data[i50] = 0;
  }

  emxInit_int32_T(&UltPosRecXDia, 2);

  /*  Schedule completo */
  i50 = UltPosRecXDia->size[0] * UltPosRecXDia->size[1];
  UltPosRecXDia->size[0] = Dia->size[0];
  UltPosRecXDia->size[1] = end;
  emxEnsureCapacity_int32_T(UltPosRecXDia, i50);
  loop_ub = Dia->size[0] * end;
  for (i50 = 0; i50 < loop_ub; i50++) {
    UltPosRecXDia->data[i50] = 0;
  }

  emxInit_int32_T(&TimeUsoRec, 2);

  /*  Ultima posicion asignado del recurso por Dia */
  /*     %% Matriz con el tiempo de uso necesario de todos los recursos */
  /* Cama Pre-OP,Sala de Operación, Medicos Especialistas, Medicos Asistentes, Medicos Anstesistas, Cama Post-OP, Cama Recuperacion.  */
  i50 = TimeUsoRec->size[0] * TimeUsoRec->size[1];
  TimeUsoRec->size[0] = NumTOp;
  TimeUsoRec->size[1] = 7;
  emxEnsureCapacity_int32_T(TimeUsoRec, i50);
  loop_ub = NumTOp * 7;
  for (i50 = 0; i50 < loop_ub; i50++) {
    TimeUsoRec->data[i50] = 0;
  }

  loop_ub = CP->size[0];
  for (i50 = 0; i50 < loop_ub; i50++) {
    TimeUsoRec->data[i50] = CP->data[i50 + CP->size[0] * 5];
  }

  /*  Tiempo de uso cama Pre-Operatoria */
  loop_ub = CP->size[0];
  for (i50 = 0; i50 < loop_ub; i50++) {
    TimeUsoRec->data[i50 + TimeUsoRec->size[0]] = RO->data[(CP->data[i50 +
      CP->size[0] * 3] + RO->size[0] * 3) - 1];
  }

  emxInit_int32_T(&b_TimeUsoRec, 1);

  /*  Tiempo de uso Salon de operacion */
  loop_ub = TimeUsoRec->size[0] - 1;
  i50 = b_TimeUsoRec->size[0];
  b_TimeUsoRec->size[0] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i50);
  for (i50 = 0; i50 <= loop_ub; i50++) {
    b_TimeUsoRec->data[i50] = TimeUsoRec->data[i50 + TimeUsoRec->size[0]];
  }

  loop_ub = b_TimeUsoRec->size[0];
  for (i50 = 0; i50 < loop_ub; i50++) {
    TimeUsoRec->data[i50 + (TimeUsoRec->size[0] << 1)] = b_TimeUsoRec->data[i50];
  }

  /*  Tiempo de uso Medico Especialista */
  loop_ub = TimeUsoRec->size[0] - 1;
  i50 = b_TimeUsoRec->size[0];
  b_TimeUsoRec->size[0] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i50);
  for (i50 = 0; i50 <= loop_ub; i50++) {
    b_TimeUsoRec->data[i50] = TimeUsoRec->data[i50 + TimeUsoRec->size[0]];
  }

  loop_ub = b_TimeUsoRec->size[0];
  for (i50 = 0; i50 < loop_ub; i50++) {
    TimeUsoRec->data[i50 + TimeUsoRec->size[0] * 3] = b_TimeUsoRec->data[i50];
  }

  /*  Tiempo de uso Medico Asistente */
  loop_ub = TimeUsoRec->size[0] - 1;
  i50 = b_TimeUsoRec->size[0];
  b_TimeUsoRec->size[0] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i50);
  for (i50 = 0; i50 <= loop_ub; i50++) {
    b_TimeUsoRec->data[i50] = TimeUsoRec->data[i50 + TimeUsoRec->size[0]];
  }

  loop_ub = b_TimeUsoRec->size[0];
  for (i50 = 0; i50 < loop_ub; i50++) {
    TimeUsoRec->data[i50 + (TimeUsoRec->size[0] << 2)] = b_TimeUsoRec->data[i50];
  }

  /*  Tiempo de uso Medico Anestesista */
  loop_ub = CP->size[0];
  for (i50 = 0; i50 < loop_ub; i50++) {
    TimeUsoRec->data[i50 + TimeUsoRec->size[0] * 5] = CP->data[i50 + CP->size[0]
      * 6];
  }

  for (i50 = 0; i50 < loop_ub; i50++) {
    TimeUsoRec->data[i50 + TimeUsoRec->size[0] * 6] = CP->data[i50 + CP->size[0]
      * 7];
  }

  emxInit_int32_T(&varargin_1, 2);

  /*  Tiempo de uso cama Post-Operatoria y Recuperacion */
  loop_ub = ME->size[0];
  b_loop_ub = CP->size[0];
  i50 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = b_loop_ub;
  varargin_1->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(varargin_1, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    for (end = 0; end < b_loop_ub; end++) {
      varargin_1->data[end + varargin_1->size[0] * i50] = ME->data[i50 +
        ME->size[0] * (RO->data[(CP->data[end + CP->size[0] * 3] + RO->size[0])
                       - 1] - 1)];
    }
  }

  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    b_loop_ub = varargin_1->size[0];
  } else {
    i50 = CP->size[0];
    if (i50 != 0) {
      b_loop_ub = CP->size[0];
    } else {
      b_loop_ub = varargin_1->size[0];
      if (b_loop_ub <= 0) {
        b_loop_ub = 0;
      }

      i50 = CP->size[0];
      if (i50 > b_loop_ub) {
        b_loop_ub = CP->size[0];
      }
    }
  }

  empty_non_axis_sizes = (b_loop_ub == 0);
  if (empty_non_axis_sizes || ((varargin_1->size[0] != 0) && (varargin_1->size[1]
        != 0))) {
    input_sizes_idx_1 = varargin_1->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }

  if (empty_non_axis_sizes) {
    sizes_idx_1 = 1;
  } else {
    i50 = CP->size[0];
    if (i50 != 0) {
      sizes_idx_1 = 1;
    } else {
      sizes_idx_1 = 0;
    }
  }

  loop_ub = CP->size[0];
  i50 = b_TimeUsoRec->size[0];
  b_TimeUsoRec->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    b_TimeUsoRec->data[i50] = RO->data[(CP->data[i50 + CP->size[0] * 3] +
      (RO->size[0] << 2)) - 1];
  }

  emxInit_int32_T(&PME, 2);
  i50 = PME->size[0] * PME->size[1];
  PME->size[0] = b_loop_ub;
  PME->size[1] = input_sizes_idx_1 + sizes_idx_1;
  emxEnsureCapacity_int32_T(PME, i50);
  for (i50 = 0; i50 < input_sizes_idx_1; i50++) {
    for (end = 0; end < b_loop_ub; end++) {
      PME->data[end + PME->size[0] * i50] = varargin_1->data[end + b_loop_ub *
        i50];
    }
  }

  loop_ub = sizes_idx_1;
  for (i50 = 0; i50 < loop_ub; i50++) {
    for (end = 0; end < b_loop_ub; end++) {
      PME->data[end + PME->size[0] * input_sizes_idx_1] = b_TimeUsoRec->data[end];
    }
  }

  /*  Posibles Medicos Especialistas X Operacion. | Cantidad necesaria de Medicos Especialistas */
  loop_ub = MA->size[0];
  b_loop_ub = CP->size[0];
  i50 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = b_loop_ub;
  varargin_1->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(varargin_1, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    for (end = 0; end < b_loop_ub; end++) {
      varargin_1->data[end + varargin_1->size[0] * i50] = MA->data[i50 +
        MA->size[0] * (RO->data[(CP->data[end + CP->size[0] * 3] + RO->size[0])
                       - 1] - 1)];
    }
  }

  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    b_loop_ub = varargin_1->size[0];
  } else {
    i50 = CP->size[0];
    if (i50 != 0) {
      b_loop_ub = CP->size[0];
    } else {
      b_loop_ub = varargin_1->size[0];
      if (b_loop_ub <= 0) {
        b_loop_ub = 0;
      }

      i50 = CP->size[0];
      if (i50 > b_loop_ub) {
        b_loop_ub = CP->size[0];
      }
    }
  }

  empty_non_axis_sizes = (b_loop_ub == 0);
  if (empty_non_axis_sizes || ((varargin_1->size[0] != 0) && (varargin_1->size[1]
        != 0))) {
    input_sizes_idx_1 = varargin_1->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }

  if (empty_non_axis_sizes) {
    sizes_idx_1 = 1;
  } else {
    i50 = CP->size[0];
    if (i50 != 0) {
      sizes_idx_1 = 1;
    } else {
      sizes_idx_1 = 0;
    }
  }

  loop_ub = CP->size[0];
  i50 = b_TimeUsoRec->size[0];
  b_TimeUsoRec->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    b_TimeUsoRec->data[i50] = RO->data[(CP->data[i50 + CP->size[0] * 3] +
      RO->size[0] * 5) - 1];
  }

  emxInit_int32_T(&PMA, 2);
  i50 = PMA->size[0] * PMA->size[1];
  PMA->size[0] = b_loop_ub;
  PMA->size[1] = input_sizes_idx_1 + sizes_idx_1;
  emxEnsureCapacity_int32_T(PMA, i50);
  for (i50 = 0; i50 < input_sizes_idx_1; i50++) {
    for (end = 0; end < b_loop_ub; end++) {
      PMA->data[end + PMA->size[0] * i50] = varargin_1->data[end + b_loop_ub *
        i50];
    }
  }

  loop_ub = sizes_idx_1;
  for (i50 = 0; i50 < loop_ub; i50++) {
    for (end = 0; end < b_loop_ub; end++) {
      PMA->data[end + PMA->size[0] * input_sizes_idx_1] = b_TimeUsoRec->data[end];
    }
  }

  /*  Posibles Medicos Asistentes X Operacion. | Cantidad necesaria de Medicos Asistentes */
  loop_ub = MAn->size[0];
  b_loop_ub = CP->size[0];
  i50 = varargin_1->size[0] * varargin_1->size[1];
  varargin_1->size[0] = b_loop_ub;
  varargin_1->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(varargin_1, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    for (end = 0; end < b_loop_ub; end++) {
      varargin_1->data[end + varargin_1->size[0] * i50] = MAn->data[i50 +
        MAn->size[0] * (RO->data[(CP->data[end + CP->size[0] * 3] + RO->size[0])
                        - 1] - 1)];
    }
  }

  if ((varargin_1->size[0] != 0) && (varargin_1->size[1] != 0)) {
    b_loop_ub = varargin_1->size[0];
  } else {
    i50 = CP->size[0];
    if (i50 != 0) {
      b_loop_ub = CP->size[0];
    } else {
      b_loop_ub = varargin_1->size[0];
      if (b_loop_ub <= 0) {
        b_loop_ub = 0;
      }

      i50 = CP->size[0];
      if (i50 > b_loop_ub) {
        b_loop_ub = CP->size[0];
      }
    }
  }

  empty_non_axis_sizes = (b_loop_ub == 0);
  if (empty_non_axis_sizes || ((varargin_1->size[0] != 0) && (varargin_1->size[1]
        != 0))) {
    input_sizes_idx_1 = varargin_1->size[1];
  } else {
    input_sizes_idx_1 = 0;
  }

  if (empty_non_axis_sizes) {
    sizes_idx_1 = 1;
  } else {
    i50 = CP->size[0];
    if (i50 != 0) {
      sizes_idx_1 = 1;
    } else {
      sizes_idx_1 = 0;
    }
  }

  loop_ub = CP->size[0];
  i50 = b_TimeUsoRec->size[0];
  b_TimeUsoRec->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    b_TimeUsoRec->data[i50] = RO->data[(CP->data[i50 + CP->size[0] * 3] +
      RO->size[0] * 6) - 1];
  }

  emxInit_int32_T(&PMAn, 2);
  i50 = PMAn->size[0] * PMAn->size[1];
  PMAn->size[0] = b_loop_ub;
  PMAn->size[1] = input_sizes_idx_1 + sizes_idx_1;
  emxEnsureCapacity_int32_T(PMAn, i50);
  for (i50 = 0; i50 < input_sizes_idx_1; i50++) {
    for (end = 0; end < b_loop_ub; end++) {
      PMAn->data[end + PMAn->size[0] * i50] = varargin_1->data[end + b_loop_ub *
        i50];
    }
  }

  loop_ub = sizes_idx_1;
  for (i50 = 0; i50 < loop_ub; i50++) {
    for (end = 0; end < b_loop_ub; end++) {
      PMAn->data[end + PMAn->size[0] * input_sizes_idx_1] = b_TimeUsoRec->
        data[end];
    }
  }

  /*  Posibles Medicos Anestesistas X Operacion. | Cantidad necesaria de Medicos Anestesistas */
  /*  Complejidad de la Operacion */
  emxInit_boolean_T(&idx, 2);
  emxInit_int32_T(&r6, 2);
  emxInit_int32_T(&r7, 2);
  emxInit_int32_T(&r8, 2);
  for (i = 0; i < NumTOp; i++) {
    if (RO->data[(CP->data[i + CP->size[0] * 3] + (RO->size[0] << 1)) - 1] == 1)
    {
      /*  Si la operacion es de alto riesgo quitar los Medicos de nivel 3 como opcion */
      if (1 > PME->size[1] - 1) {
        loop_ub = 0;
      } else {
        loop_ub = PME->size[1] - 1;
      }

      i50 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = loop_ub;
      emxEnsureCapacity_boolean_T(idx, i50);
      for (i50 = 0; i50 < loop_ub; i50++) {
        idx->data[i50] = (PME->data[i + PME->size[0] * i50] == 3);
      }

      end = idx->size[1] - 1;
      b_loop_ub = 0;
      for (input_sizes_idx_1 = 0; input_sizes_idx_1 <= end; input_sizes_idx_1++)
      {
        if (idx->data[input_sizes_idx_1]) {
          b_loop_ub++;
        }
      }

      i50 = r6->size[0] * r6->size[1];
      r6->size[0] = 1;
      r6->size[1] = b_loop_ub;
      emxEnsureCapacity_int32_T(r6, i50);
      b_loop_ub = 0;
      for (input_sizes_idx_1 = 0; input_sizes_idx_1 <= end; input_sizes_idx_1++)
      {
        if (idx->data[input_sizes_idx_1]) {
          r6->data[b_loop_ub] = input_sizes_idx_1 + 1;
          b_loop_ub++;
        }
      }

      input_sizes_idx_1 = r6->size[1];
      for (i50 = 0; i50 < input_sizes_idx_1; i50++) {
        PME->data[i + PME->size[0] * (r6->data[i50] - 1)] = 0;
      }

      if (1 > PMA->size[1] - 1) {
        loop_ub = 0;
      } else {
        loop_ub = PMA->size[1] - 1;
      }

      i50 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = loop_ub;
      emxEnsureCapacity_boolean_T(idx, i50);
      for (i50 = 0; i50 < loop_ub; i50++) {
        idx->data[i50] = (PMA->data[i + PMA->size[0] * i50] == 3);
      }

      end = idx->size[1] - 1;
      b_loop_ub = 0;
      for (input_sizes_idx_1 = 0; input_sizes_idx_1 <= end; input_sizes_idx_1++)
      {
        if (idx->data[input_sizes_idx_1]) {
          b_loop_ub++;
        }
      }

      i50 = r7->size[0] * r7->size[1];
      r7->size[0] = 1;
      r7->size[1] = b_loop_ub;
      emxEnsureCapacity_int32_T(r7, i50);
      b_loop_ub = 0;
      for (input_sizes_idx_1 = 0; input_sizes_idx_1 <= end; input_sizes_idx_1++)
      {
        if (idx->data[input_sizes_idx_1]) {
          r7->data[b_loop_ub] = input_sizes_idx_1 + 1;
          b_loop_ub++;
        }
      }

      input_sizes_idx_1 = r7->size[1];
      for (i50 = 0; i50 < input_sizes_idx_1; i50++) {
        PMA->data[i + PMA->size[0] * (r7->data[i50] - 1)] = 0;
      }

      if (1 > PMAn->size[1] - 1) {
        loop_ub = 0;
      } else {
        loop_ub = PMAn->size[1] - 1;
      }

      i50 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = loop_ub;
      emxEnsureCapacity_boolean_T(idx, i50);
      for (i50 = 0; i50 < loop_ub; i50++) {
        idx->data[i50] = (PMAn->data[i + PMAn->size[0] * i50] == 3);
      }

      end = idx->size[1] - 1;
      b_loop_ub = 0;
      for (input_sizes_idx_1 = 0; input_sizes_idx_1 <= end; input_sizes_idx_1++)
      {
        if (idx->data[input_sizes_idx_1]) {
          b_loop_ub++;
        }
      }

      i50 = r8->size[0] * r8->size[1];
      r8->size[0] = 1;
      r8->size[1] = b_loop_ub;
      emxEnsureCapacity_int32_T(r8, i50);
      b_loop_ub = 0;
      for (input_sizes_idx_1 = 0; input_sizes_idx_1 <= end; input_sizes_idx_1++)
      {
        if (idx->data[input_sizes_idx_1]) {
          r8->data[b_loop_ub] = input_sizes_idx_1 + 1;
          b_loop_ub++;
        }
      }

      input_sizes_idx_1 = r8->size[1];
      for (i50 = 0; i50 < input_sizes_idx_1; i50++) {
        PMAn->data[i + PMAn->size[0] * (r8->data[i50] - 1)] = 0;
      }
    }
  }

  emxFree_int32_T(&r8);
  emxFree_int32_T(&r7);
  emxFree_int32_T(&r6);
  emxFree_boolean_T(&idx);
  emxInit_int32_T(&PCPrO, 2);
  loop_ub = CPrO->size[0];
  b_loop_ub = CP->size[0];
  i50 = PCPrO->size[0] * PCPrO->size[1];
  PCPrO->size[0] = b_loop_ub;
  PCPrO->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(PCPrO, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    for (end = 0; end < b_loop_ub; end++) {
      PCPrO->data[end + PCPrO->size[0] * i50] = CPrO->data[i50 + CPrO->size[0] *
        (RO->data[(CP->data[end + CP->size[0] * 3] + RO->size[0]) - 1] - 1)];
    }
  }

  emxInit_int32_T(&PS, 2);

  /*  Posibles Camas PreOperatorias X Operacion. */
  loop_ub = S->size[0];
  b_loop_ub = CP->size[0];
  i50 = PS->size[0] * PS->size[1];
  PS->size[0] = b_loop_ub;
  PS->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(PS, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    for (end = 0; end < b_loop_ub; end++) {
      PS->data[end + PS->size[0] * i50] = S->data[i50 + S->size[0] * (RO->data
        [(CP->data[end + CP->size[0] * 3] + RO->size[0]) - 1] - 1)];
    }
  }

  emxInit_int32_T(&PCPO, 2);

  /*  Posibles Salon X Operacion. */
  loop_ub = CPO->size[0];
  b_loop_ub = CP->size[0];
  i50 = PCPO->size[0] * PCPO->size[1];
  PCPO->size[0] = b_loop_ub;
  PCPO->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(PCPO, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    for (end = 0; end < b_loop_ub; end++) {
      PCPO->data[end + PCPO->size[0] * i50] = CPO->data[i50 + CPO->size[0] *
        (RO->data[(CP->data[end + CP->size[0] * 3] + RO->size[0]) - 1] - 1)];
    }
  }

  emxInit_int32_T(&PCR, 2);

  /*  Posibles Camas PostOperatorias X Operacion. */
  loop_ub = CR->size[0];
  b_loop_ub = CP->size[0];
  i50 = PCR->size[0] * PCR->size[1];
  PCR->size[0] = b_loop_ub;
  PCR->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(PCR, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    for (end = 0; end < b_loop_ub; end++) {
      PCR->data[end + PCR->size[0] * i50] = CR->data[i50 + CR->size[0] *
        (RO->data[(CP->data[end + CP->size[0] * 3] + RO->size[0]) - 1] - 1)];
    }
  }

  emxInit_int32_T(&b_H, 2);

  /*  Posibles Camas de Recuperacion X Operacion. */
  /*  Estado del paciente. */
  /*     %% Caso Base */
  i50 = b_H->size[0] * b_H->size[1];
  b_H->size[0] = H->size[0];
  b_H->size[1] = H->size[1];
  emxEnsureCapacity_int32_T(b_H, i50);
  loop_ub = H->size[0] * H->size[1];
  for (i50 = 0; i50 < loop_ub; i50++) {
    b_H->data[i50] = H->data[i50];
  }

  emxInit_int32_T(&b_UltPosRecXDia, 2);
  i50 = b_UltPosRecXDia->size[0] * b_UltPosRecXDia->size[1];
  b_UltPosRecXDia->size[0] = UltPosRecXDia->size[0];
  b_UltPosRecXDia->size[1] = UltPosRecXDia->size[1];
  emxEnsureCapacity_int32_T(b_UltPosRecXDia, i50);
  loop_ub = UltPosRecXDia->size[0] * UltPosRecXDia->size[1];
  for (i50 = 0; i50 < loop_ub; i50++) {
    b_UltPosRecXDia->data[i50] = UltPosRecXDia->data[i50];
  }

  emxInit_int32_T(&NAWD, 1);
  emxInit_int32_T(&EspMedOpB, 2);
  casorandom(NumTOp, b_H, NumRec, PCPrO, PME, PMA, PMAn, PS, PCPO, PCR, Dia,
             b_UltPosRecXDia, TimeUsoRec, DispMExD, varargin_1, NAWD, EspMedOpB);
  loop_ub = CP->size[0];
  i50 = b_TimeUsoRec->size[0];
  b_TimeUsoRec->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i50);
  emxFree_int32_T(&b_UltPosRecXDia);
  emxFree_int32_T(&b_H);
  for (i50 = 0; i50 < loop_ub; i50++) {
    b_TimeUsoRec->data[i50] = CP->data[i50 + (CP->size[0] << 1)];
  }

  favalia(varargin_1, NAWD, b_TimeUsoRec, EspMedOpB, k0, k1, k2, k3,
          &b_varargin_1, &varargin_2, &varargin_3, &varargin_4, &varargin_5,
          &varargin_6);
  printf("Fitness: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t NOE2: %10.5f - \t NOE3: %10.5f \n",
         b_varargin_1, varargin_2, varargin_3, varargin_4, varargin_5,
         varargin_6);
  fflush(stdout);
  toc();

  /*     %% Reorganizando la lista de espera */
  i50 = CP->size[0];
  end = NAWD->size[0];
  NAWD->size[0] = i50;
  emxEnsureCapacity_int32_T(NAWD, end);
  i50 = CP->size[0];
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < i50; input_sizes_idx_1++) {
    b_varargin_1 = rt_roundd(360.0 / (double)CP->data[input_sizes_idx_1 +
      (CP->size[0] << 1)]);
    if (b_varargin_1 < 2.147483648E+9) {
      if (b_varargin_1 >= -2.147483648E+9) {
        end = (int)b_varargin_1;
      } else {
        end = MIN_int32_T;
      }
    } else {
      end = MAX_int32_T;
    }

    NAWD->data[input_sizes_idx_1] = end;
  }

  b_loop_ub = CP->size[0];
  end = CP->data[CP->size[0]];
  for (input_sizes_idx_1 = 2; input_sizes_idx_1 <= b_loop_ub; input_sizes_idx_1
       ++) {
    if (end < CP->data[(input_sizes_idx_1 + CP->size[0]) - 1]) {
      end = CP->data[(input_sizes_idx_1 + CP->size[0]) - 1];
    }
  }

  loop_ub = CP->size[0];
  i50 = NAWD->size[0];
  NAWD->size[0] = loop_ub;
  emxEnsureCapacity_int32_T(NAWD, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    b_loop_ub = CP->data[i50 + CP->size[0]];
    if ((end >= 0) && (b_loop_ub < end - MAX_int32_T)) {
      b_loop_ub = MAX_int32_T;
    } else if ((end < 0) && (b_loop_ub > end - MIN_int32_T)) {
      b_loop_ub = MIN_int32_T;
    } else {
      b_loop_ub = end - b_loop_ub;
    }

    if (b_loop_ub > 2147483646) {
      b_loop_ub = MAX_int32_T;
    } else {
      b_loop_ub++;
    }

    i51 = (long long)b_loop_ub * NAWD->data[i50];
    if (i51 > 2147483647LL) {
      i51 = 2147483647LL;
    } else {
      if (i51 < -2147483648LL) {
        i51 = -2147483648LL;
      }
    }

    NAWD->data[i50] = (int)i51;
  }

  emxInit_int32_T(&NewEP, 1);

  /*  Ajuste de la lista de espera dependiente del estado del paciente y el tiempo de entrada a la lista. */
  loop_ub = NAWD->size[0] - 1;
  i50 = NewEP->size[0];
  NewEP->size[0] = loop_ub + 1;
  emxEnsureCapacity_int32_T(NewEP, i50);
  for (i50 = 0; i50 <= loop_ub; i50++) {
    NewEP->data[i50] = NAWD->data[i50];
  }

  i50 = NAWD->size[0];
  NAWD->size[0] = NewEP->size[0];
  emxEnsureCapacity_int32_T(NAWD, i50);
  loop_ub = NewEP->size[0];
  for (i50 = 0; i50 < loop_ub; i50++) {
    NAWD->data[i50] = NewEP->data[i50];
  }

  e_sort(NAWD, NewEP);
  i50 = b_TimeUsoRec->size[0];
  b_TimeUsoRec->size[0] = NewEP->size[0];
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i50);
  loop_ub = NewEP->size[0];
  for (i50 = 0; i50 < loop_ub; i50++) {
    b_TimeUsoRec->data[i50] = NewEP->data[i50];
  }

  emxInit_int32_T(&NewTimeUsoRec, 2);

  /*  Organizo la Lista de Espera */
  i50 = NewTimeUsoRec->size[0] * NewTimeUsoRec->size[1];
  NewTimeUsoRec->size[0] = b_TimeUsoRec->size[0];
  NewTimeUsoRec->size[1] = 7;
  emxEnsureCapacity_int32_T(NewTimeUsoRec, i50);
  for (i50 = 0; i50 < 7; i50++) {
    loop_ub = b_TimeUsoRec->size[0];
    for (end = 0; end < loop_ub; end++) {
      NewTimeUsoRec->data[end + NewTimeUsoRec->size[0] * i50] = TimeUsoRec->
        data[(b_TimeUsoRec->data[end] + TimeUsoRec->size[0] * i50) - 1];
    }
  }

  emxFree_int32_T(&TimeUsoRec);
  emxInit_int32_T(&NewPME, 2);
  loop_ub = PME->size[1];
  i50 = NewPME->size[0] * NewPME->size[1];
  NewPME->size[0] = b_TimeUsoRec->size[0];
  NewPME->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(NewPME, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    b_loop_ub = b_TimeUsoRec->size[0];
    for (end = 0; end < b_loop_ub; end++) {
      NewPME->data[end + NewPME->size[0] * i50] = PME->data[(b_TimeUsoRec->
        data[end] + PME->size[0] * i50) - 1];
    }
  }

  emxInit_int32_T(&NewPMA, 2);

  /*  Posibles Medicos Especialistas X Operacion. */
  loop_ub = PMA->size[1];
  i50 = NewPMA->size[0] * NewPMA->size[1];
  NewPMA->size[0] = b_TimeUsoRec->size[0];
  NewPMA->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(NewPMA, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    b_loop_ub = b_TimeUsoRec->size[0];
    for (end = 0; end < b_loop_ub; end++) {
      NewPMA->data[end + NewPMA->size[0] * i50] = PMA->data[(b_TimeUsoRec->
        data[end] + PMA->size[0] * i50) - 1];
    }
  }

  emxInit_int32_T(&NewPMAn, 2);

  /*  Posibles Medicos Asistentes X Operacion. */
  loop_ub = PMAn->size[1];
  i50 = NewPMAn->size[0] * NewPMAn->size[1];
  NewPMAn->size[0] = b_TimeUsoRec->size[0];
  NewPMAn->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(NewPMAn, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    b_loop_ub = b_TimeUsoRec->size[0];
    for (end = 0; end < b_loop_ub; end++) {
      NewPMAn->data[end + NewPMAn->size[0] * i50] = PMAn->data
        [(b_TimeUsoRec->data[end] + PMAn->size[0] * i50) - 1];
    }
  }

  emxInit_int32_T(&NewPCPrO, 2);

  /*  Posibles Medicos Anestesistas X Operacion. */
  loop_ub = PCPrO->size[1];
  i50 = NewPCPrO->size[0] * NewPCPrO->size[1];
  NewPCPrO->size[0] = b_TimeUsoRec->size[0];
  NewPCPrO->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(NewPCPrO, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    b_loop_ub = b_TimeUsoRec->size[0];
    for (end = 0; end < b_loop_ub; end++) {
      NewPCPrO->data[end + NewPCPrO->size[0] * i50] = PCPrO->data
        [(b_TimeUsoRec->data[end] + PCPrO->size[0] * i50) - 1];
    }
  }

  emxFree_int32_T(&PCPrO);

  /*  Posibles Camas PreOperatorias X Operacion. */
  loop_ub = PS->size[1];
  i50 = PMAn->size[0] * PMAn->size[1];
  PMAn->size[0] = b_TimeUsoRec->size[0];
  PMAn->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(PMAn, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    b_loop_ub = b_TimeUsoRec->size[0];
    for (end = 0; end < b_loop_ub; end++) {
      PMAn->data[end + PMAn->size[0] * i50] = PS->data[(b_TimeUsoRec->data[end]
        + PS->size[0] * i50) - 1];
    }
  }

  emxFree_int32_T(&PS);

  /*  Posibles Salon X Operacion. */
  loop_ub = PCPO->size[1];
  i50 = PMA->size[0] * PMA->size[1];
  PMA->size[0] = b_TimeUsoRec->size[0];
  PMA->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(PMA, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    b_loop_ub = b_TimeUsoRec->size[0];
    for (end = 0; end < b_loop_ub; end++) {
      PMA->data[end + PMA->size[0] * i50] = PCPO->data[(b_TimeUsoRec->data[end]
        + PCPO->size[0] * i50) - 1];
    }
  }

  emxFree_int32_T(&PCPO);

  /*  Posibles Camas PostOperatorias X Operacion. */
  loop_ub = PCR->size[1];
  i50 = PME->size[0] * PME->size[1];
  PME->size[0] = b_TimeUsoRec->size[0];
  PME->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(PME, i50);
  for (i50 = 0; i50 < loop_ub; i50++) {
    b_loop_ub = b_TimeUsoRec->size[0];
    for (end = 0; end < b_loop_ub; end++) {
      PME->data[end + PME->size[0] * i50] = PCR->data[(b_TimeUsoRec->data[end] +
        PCR->size[0] * i50) - 1];
    }
  }

  emxFree_int32_T(&PCR);

  /*  Posibles Camas de Recuperacion X Operacion. */
  i50 = NewEP->size[0];
  NewEP->size[0] = b_TimeUsoRec->size[0];
  emxEnsureCapacity_int32_T(NewEP, i50);
  loop_ub = b_TimeUsoRec->size[0];
  for (i50 = 0; i50 < loop_ub; i50++) {
    NewEP->data[i50] = CP->data[(b_TimeUsoRec->data[i50] + (CP->size[0] << 1)) -
      1];
  }

  emxFree_int32_T(&b_TimeUsoRec);
  emxInit_real_T(&trace, 2);

  /*     %% Caso Base */
  casorandom(NumTOp, H, NumRec, NewPCPrO, NewPME, NewPMA, NewPMAn, PMAn, PMA,
             PME, Dia, UltPosRecXDia, NewTimeUsoRec, DispMExD, varargin_1, NAWD,
             EspMedOpB);
  favalia(varargin_1, NAWD, NewEP, EspMedOpB, k0, k1, k2, k3, &b_varargin_1,
          &varargin_2, &varargin_3, &varargin_4, &varargin_5, &varargin_6);
  printf("Fitness: %10.5f - \t Tt: %10.5f - \t NOFP: %10.5f - \t TmOFP: %10.5f - \t NOE2: %10.5f - \t NOE3: %10.5f \n",
         b_varargin_1, varargin_2, varargin_3, varargin_4, varargin_5,
         varargin_6);
  fflush(stdout);
  toc();

  /*     %% AE */
  fitness[0] = b_varargin_1;
  fitness[1] = varargin_2;
  fitness[2] = varargin_3;
  fitness[3] = varargin_4;
  fitness[4] = varargin_5;
  fitness[5] = varargin_6;
  b_aevSPLap(NumTOp, numIC, numIQ, taxC, taxE, NumRec, NewPCPrO, NewPME, NewPMA,
             NewPMAn, PMAn, PMA, PME, Dia, Data, NewTimeUsoRec, ProbXEst,
             fitness, generations, genToWidth, DispMExD, NewEP, k0, k1, k2, k3,
             keeppriority, NAWD, trace);
  toc();
  PLOTT_func(trace, NAWD);
  emxFree_int32_T(&varargin_1);
  emxFree_real_T(&trace);
  emxFree_int32_T(&EspMedOpB);
  emxFree_int32_T(&NewEP);
  emxFree_int32_T(&NewPCPrO);
  emxFree_int32_T(&NewPMAn);
  emxFree_int32_T(&NewPMA);
  emxFree_int32_T(&NewPME);
  emxFree_int32_T(&NewTimeUsoRec);
  emxFree_int32_T(&NAWD);
  emxFree_int32_T(&PMAn);
  emxFree_int32_T(&PMA);
  emxFree_int32_T(&PME);
  emxFree_int32_T(&UltPosRecXDia);
  emxFree_int32_T(&H);
}

/* End of code generation (main_UCI_func.c) */
