/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: funcionDia.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "funcionDia.h"
#include "model_emxutil.h"

/* Function Definitions */

/*
 * function [contDia,tempUltPosRecXDia,DispME] = funcionDia( NumRec,PCPrO, Dia,UltPosRecXDia, TimeUsoCPrO, TimeUsoS,contDia,DispMExD)
 * NumCPrO: Numero de camas PreOperatorias.
 *  PCPrO: Posibles camas PreOperatorias para esa operacion.
 *  Dia: Matriz con el cosecutivo de dias y el dia de la semana. Ademas tiene
 *  los indices donde empieza y termina cada dia de la matriz Data(Ver main_UCI).
 *  UltPosRecXDia: Ultima posicion asignado del recurso por Dia.
 *  Time: El tiempo de uso de la Cama PrO mas el tiempo de operacion.
 *  contDia: Contador de dia.
 * Arguments    : const int NumRec[7]
 *                const emxArray_int32_T *PCPrO
 *                const emxArray_int32_T *Dia
 *                const emxArray_int32_T *UltPosRecXDia
 *                int TimeUsoCPrO
 *                int TimeUsoS
 *                int *contDia
 *                const emxArray_int32_T *DispMExD
 *                emxArray_int32_T *tempUltPosRecXDia
 *                emxArray_int32_T *DispME
 * Return Type  : void
 */
void funcionDia(const int NumRec[7], const emxArray_int32_T *PCPrO, const
                emxArray_int32_T *Dia, const emxArray_int32_T *UltPosRecXDia,
                int TimeUsoCPrO, int TimeUsoS, int *contDia, const
                emxArray_int32_T *DispMExD, emxArray_int32_T *tempUltPosRecXDia,
                emxArray_int32_T *DispME)
{
  int i49;
  int loop_ub;
  emxArray_int32_T *r26;
  emxArray_int32_T *r27;
  emxArray_boolean_T *x;
  emxArray_int32_T *jj;
  emxArray_int32_T *r28;
  emxArray_int32_T *b_jj;
  int exitg1;
  int exitg2;
  int i50;
  int idx;
  int c_jj;
  int minP;
  double y;
  double b_y;
  int b_Dia;
  unsigned int unnamed_idx_1;
  boolean_T exitg3;

  /* 'funcionDia:10' tempUltPosRecXDia = zeros(1,NumRec(1), 'int32'); */
  i49 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[1] = NumRec[0];
  tempUltPosRecXDia->size[0] = 1;
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i49);
  loop_ub = NumRec[0];
  for (i49 = 0; i49 < loop_ub; i49++) {
    tempUltPosRecXDia->data[i49] = 0;
  }

  /* 'funcionDia:11' flag=true; */
  /* 'funcionDia:12' while flag==true */
  emxInit_int32_T(&r26, 2);
  emxInit_int32_T(&r27, 1);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&jj, 2);
  emxInit_int32_T(&r28, 1);
  emxInit_int32_T(&b_jj, 2);
  do {
    exitg1 = 0;
    do {
      exitg2 = 0;

      /* 'funcionDia:13' if Dia(contDia,3)==0 */
      i49 = (*contDia - 1) << 2;
      i50 = 2 + i49;
      if (Dia->data[i50] == 0) {
        /* 'funcionDia:14' contDia = contDia + 1; */
        (*contDia)++;
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    /* 'funcionDia:15' else */
    /* 'funcionDia:16' auxUPxR = int32(UltPosRecXDia(contDia,1:NumRec(1))); */
    if (1 > NumRec[0]) {
      loop_ub = 0;
    } else {
      loop_ub = NumRec[0];
    }

    idx = r27->size[0];
    r27->size[0] = loop_ub;
    emxEnsureCapacity_int32_T(r27, idx);
    for (idx = 0; idx < loop_ub; idx++) {
      r27->data[idx] = UltPosRecXDia->data[idx + UltPosRecXDia->size[1] *
        (*contDia - 1)];
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden usar las camas. */
    /* 'funcionDia:17' minP = Dia(contDia,4)-Dia(contDia,3)+1-(TimeUsoCPrO+TimeUsoS); */
    c_jj = 3 + i49;
    minP = (((Dia->data[c_jj] - Dia->data[i50]) - TimeUsoCPrO) - TimeUsoS) + 1;

    /*  Posicion maxima a partir de la cual se puede colocar la Operacion */
    /* 'funcionDia:19' auxUPxS = UltPosRecXDia(contDia,sum(NumRec(1:2))+1:sum(NumRec(1:3))); */
    y = (double)NumRec[0] + (double)NumRec[1];
    b_y = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
    if (y + 1.0 > b_y) {
      i49 = -1;
      idx = 0;
    } else {
      i49 = (int)(y + 1.0) - 2;
      idx = (int)b_y;
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
    /* 'funcionDia:20' [~,c]=find(double(Dia(contDia,4))-double(Dia(contDia,3))+1-auxUPxS>=TimeUsoS); */
    b_Dia = Dia->data[c_jj] - Dia->data[i50];
    c_jj = (idx - i49) - 1;
    i50 = x->size[0] * x->size[1];
    x->size[1] = c_jj;
    x->size[0] = 1;
    emxEnsureCapacity_boolean_T(x, i50);
    for (i50 = 0; i50 < c_jj; i50++) {
      x->data[i50] = ((b_Dia - UltPosRecXDia->data[((i49 + i50) +
        UltPosRecXDia->size[1] * (*contDia - 1)) + 1]) + 1 >= TimeUsoS);
    }

    if (x->size[1] == 0) {
      jj->size[1] = 0;
    } else {
      idx = 0;
      unnamed_idx_1 = (unsigned int)x->size[1];
      i49 = jj->size[0] * jj->size[1];
      jj->size[1] = (int)unnamed_idx_1;
      jj->size[0] = 1;
      emxEnsureCapacity_int32_T(jj, i49);
      c_jj = 1;
      exitg3 = false;
      while ((!exitg3) && (c_jj <= x->size[1])) {
        if (x->data[c_jj - 1]) {
          idx++;
          jj->data[idx - 1] = c_jj;
          if (idx >= x->size[1]) {
            exitg3 = true;
          } else {
            c_jj++;
          }
        } else {
          c_jj++;
        }
      }

      if (x->size[1] == 1) {
        if (idx == 0) {
          jj->size[1] = 0;
        }
      } else {
        if (1 > idx) {
          idx = 0;
        }

        i49 = r28->size[0];
        r28->size[0] = idx;
        emxEnsureCapacity_int32_T(r28, i49);
        for (i49 = 0; i49 < idx; i49++) {
          r28->data[i49] = i49;
        }

        c_jj = r28->size[0];
        i49 = b_jj->size[0] * b_jj->size[1];
        b_jj->size[1] = c_jj;
        b_jj->size[0] = 1;
        emxEnsureCapacity_int32_T(b_jj, i49);
        for (i49 = 0; i49 < c_jj; i49++) {
          b_jj->data[i49] = jj->data[r28->data[i49]];
        }

        i49 = jj->size[0] * jj->size[1];
        jj->size[1] = b_jj->size[1];
        jj->size[0] = 1;
        emxEnsureCapacity_int32_T(jj, i49);
        idx = b_jj->size[1];
        for (i49 = 0; i49 < idx; i49++) {
          jj->data[i49] = b_jj->data[i49];
        }
      }
    }

    /* 'funcionDia:20' ~ */
    /* 'funcionDia:22' if sum((minP>=auxUPxR(PCPrO==1)),2)~=0 && ~isempty(c) */
    b_Dia = PCPrO->size[1] - 1;
    c_jj = 0;
    for (idx = 0; idx <= b_Dia; idx++) {
      if (PCPrO->data[idx] == 1) {
        c_jj++;
      }
    }

    i49 = r26->size[0] * r26->size[1];
    r26->size[1] = c_jj;
    r26->size[0] = 1;
    emxEnsureCapacity_int32_T(r26, i49);
    c_jj = 0;
    for (idx = 0; idx <= b_Dia; idx++) {
      if (PCPrO->data[idx] == 1) {
        r26->data[c_jj] = idx + 1;
        c_jj++;
      }
    }

    i49 = x->size[0] * x->size[1];
    x->size[1] = r26->size[1];
    x->size[0] = 1;
    emxEnsureCapacity_boolean_T(x, i49);
    idx = r26->size[1];
    for (i49 = 0; i49 < idx; i49++) {
      x->data[i49] = (minP >= r27->data[r26->data[i49] - 1]);
    }

    c_jj = x->size[1];
    if (x->size[1] == 0) {
      y = 0.0;
    } else {
      y = x->data[0];
      for (idx = 2; idx <= c_jj; idx++) {
        if (c_jj >= 2) {
          y += (double)x->data[idx - 1];
        }
      }
    }

    if ((y != 0.0) && (jj->size[1] != 0)) {
      exitg1 = 1;
    } else {
      /* 'funcionDia:25' else */
      /* 'funcionDia:26' contDia = contDia + 1; */
      (*contDia)++;
    }
  } while (exitg1 == 0);

  /*  Compruebo que cabe en alguna pocision de las posibles, si no cabe incremento el dia. */
  /* 'funcionDia:23' tempUltPosRecXDia = auxUPxR; */
  i49 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[1] = loop_ub;
  tempUltPosRecXDia->size[0] = 1;
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i49);
  for (i49 = 0; i49 < loop_ub; i49++) {
    tempUltPosRecXDia->data[i49] = r27->data[i49];
  }

  /* 'funcionDia:24' flag=false; */
  emxFree_int32_T(&b_jj);
  emxFree_int32_T(&r28);
  emxFree_int32_T(&jj);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&r27);
  emxFree_int32_T(&r26);

  /* 'funcionDia:33' DispME = zeros(1,size(DispMExD,2), 'int32'); */
  c_jj = DispMExD->size[1];
  i49 = DispME->size[0] * DispME->size[1];
  DispME->size[1] = c_jj;
  DispME->size[0] = 1;
  emxEnsureCapacity_int32_T(DispME, i49);
  for (i49 = 0; i49 < c_jj; i49++) {
    DispME->data[i49] = 0;
  }

  /* 'funcionDia:34' switch Dia(contDia,2) */
  switch (Dia->data[1 + ((*contDia - 1) << 2)]) {
   case 2:
    /* 'funcionDia:35' case 2 */
    /* 'funcionDia:36' DispME=int32(DispMExD(1,:)); */
    loop_ub = DispMExD->size[1];
    i49 = DispME->size[0] * DispME->size[1];
    DispME->size[1] = loop_ub;
    DispME->size[0] = 1;
    emxEnsureCapacity_int32_T(DispME, i49);
    for (i49 = 0; i49 < loop_ub; i49++) {
      DispME->data[i49] = DispMExD->data[i49];
    }
    break;

   case 3:
    /* 'funcionDia:37' case 3 */
    /* 'funcionDia:38' DispME=int32(DispMExD(2,:)); */
    loop_ub = DispMExD->size[1];
    i49 = DispME->size[0] * DispME->size[1];
    DispME->size[1] = loop_ub;
    DispME->size[0] = 1;
    emxEnsureCapacity_int32_T(DispME, i49);
    for (i49 = 0; i49 < loop_ub; i49++) {
      DispME->data[i49] = DispMExD->data[i49 + DispMExD->size[1]];
    }
    break;

   case 4:
    /* 'funcionDia:39' case 4 */
    /* 'funcionDia:40' DispME=int32(DispMExD(3,:)); */
    loop_ub = DispMExD->size[1];
    i49 = DispME->size[0] * DispME->size[1];
    DispME->size[1] = loop_ub;
    DispME->size[0] = 1;
    emxEnsureCapacity_int32_T(DispME, i49);
    for (i49 = 0; i49 < loop_ub; i49++) {
      DispME->data[i49] = DispMExD->data[i49 + (DispMExD->size[1] << 1)];
    }
    break;

   case 5:
    /* 'funcionDia:41' case 5 */
    /* 'funcionDia:42' DispME=int32(DispMExD(4,:)); */
    loop_ub = DispMExD->size[1];
    i49 = DispME->size[0] * DispME->size[1];
    DispME->size[1] = loop_ub;
    DispME->size[0] = 1;
    emxEnsureCapacity_int32_T(DispME, i49);
    for (i49 = 0; i49 < loop_ub; i49++) {
      DispME->data[i49] = DispMExD->data[i49 + DispMExD->size[1] * 3];
    }
    break;

   case 6:
    /* 'funcionDia:43' case 6 */
    /* 'funcionDia:44' DispME=int32(DispMExD(5,:)); */
    loop_ub = DispMExD->size[1];
    i49 = DispME->size[0] * DispME->size[1];
    DispME->size[1] = loop_ub;
    DispME->size[0] = 1;
    emxEnsureCapacity_int32_T(DispME, i49);
    for (i49 = 0; i49 < loop_ub; i49++) {
      DispME->data[i49] = DispMExD->data[i49 + (DispMExD->size[1] << 2)];
    }
    break;

   case 7:
    /* 'funcionDia:45' case 7 */
    /* 'funcionDia:46' DispME=int32(DispMExD(6,:)); */
    loop_ub = DispMExD->size[1];
    i49 = DispME->size[0] * DispME->size[1];
    DispME->size[1] = loop_ub;
    DispME->size[0] = 1;
    emxEnsureCapacity_int32_T(DispME, i49);
    for (i49 = 0; i49 < loop_ub; i49++) {
      DispME->data[i49] = DispMExD->data[i49 + DispMExD->size[1] * 5];
    }
    break;
  }
}

/*
 * File trailer for funcionDia.c
 *
 * [EOF]
 */
