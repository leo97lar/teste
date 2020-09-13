/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: funcionDia.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 18:10:16
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
  int i45;
  int jj;
  emxArray_int32_T *auxUPxR;
  emxArray_int32_T *r12;
  emxArray_boolean_T *x;
  emxArray_int32_T *b_jj;
  int exitg1;
  int minP;
  double y;
  double b_y;
  int idx;
  int b_Dia;
  int i46;
  boolean_T exitg2;

  /* 'funcionDia:10' tempUltPosRecXDia = zeros(1,NumRec(1), 'int32'); */
  i45 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = NumRec[0];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i45);
  jj = NumRec[0];
  for (i45 = 0; i45 < jj; i45++) {
    tempUltPosRecXDia->data[i45] = 0;
  }

  /* 'funcionDia:11' flag=true; */
  /* 'funcionDia:12' while flag==true */
  emxInit_int32_T(&auxUPxR, 2);
  emxInit_int32_T(&r12, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&b_jj, 2);
  do {
    exitg1 = 0;
    while (Dia->data[(*contDia + (Dia->size[0] << 1)) - 1] == 0) {
      /* 'funcionDia:14' contDia = contDia + 1; */
      (*contDia)++;

      /* 'funcionDia:13' if Dia(contDia,3)==0 */
    }

    /* 'funcionDia:15' else */
    /* 'funcionDia:16' auxUPxR = int32(UltPosRecXDia(contDia,1:NumRec(1))); */
    if (1 > NumRec[0]) {
      jj = 0;
    } else {
      jj = NumRec[0];
    }

    i45 = auxUPxR->size[0] * auxUPxR->size[1];
    auxUPxR->size[0] = 1;
    auxUPxR->size[1] = jj;
    emxEnsureCapacity_int32_T(auxUPxR, i45);
    for (i45 = 0; i45 < jj; i45++) {
      auxUPxR->data[i45] = UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0]
        * i45) - 1];
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden usar las camas. */
    /* 'funcionDia:17' minP = Dia(contDia,4)-Dia(contDia,3)+1-(TimeUsoCPrO+TimeUsoS); */
    minP = (((Dia->data[(*contDia + Dia->size[0] * 3) - 1] - Dia->data[(*contDia
               + (Dia->size[0] << 1)) - 1]) - TimeUsoCPrO) - TimeUsoS) + 1;

    /*  Posicion maxima a partir de la cual se puede colocar la Operacion */
    /* 'funcionDia:19' auxUPxS = UltPosRecXDia(contDia,sum(NumRec(1:2))+1:sum(NumRec(1:3))); */
    y = (double)NumRec[0] + (double)NumRec[1];
    b_y = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
    if (y + 1.0 > b_y) {
      i45 = 0;
      idx = 0;
    } else {
      i45 = (int)(y + 1.0) - 1;
      idx = (int)b_y;
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
    /* 'funcionDia:20' [~,c]=find(double(Dia(contDia,4))-double(Dia(contDia,3))+1-auxUPxS>=TimeUsoS); */
    b_Dia = Dia->data[(*contDia + Dia->size[0] * 3) - 1] - Dia->data[(*contDia +
      (Dia->size[0] << 1)) - 1];
    i46 = x->size[0] * x->size[1];
    x->size[0] = 1;
    jj = idx - i45;
    x->size[1] = jj;
    emxEnsureCapacity_boolean_T(x, i46);
    for (idx = 0; idx < jj; idx++) {
      x->data[idx] = ((b_Dia - UltPosRecXDia->data[(*contDia +
        UltPosRecXDia->size[0] * (i45 + idx)) - 1]) + 1 >= TimeUsoS);
    }

    if (x->size[1] == 0) {
      b_jj->size[1] = 0;
    } else {
      idx = 0;
      i45 = b_jj->size[0] * b_jj->size[1];
      b_jj->size[0] = 1;
      b_jj->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(b_jj, i45);
      jj = 1;
      exitg2 = false;
      while ((!exitg2) && (jj <= x->size[1])) {
        if (x->data[jj - 1]) {
          idx++;
          b_jj->data[idx - 1] = jj;
          if (idx >= x->size[1]) {
            exitg2 = true;
          } else {
            jj++;
          }
        } else {
          jj++;
        }
      }

      if (x->size[1] == 1) {
        if (idx == 0) {
          b_jj->size[1] = 0;
        }
      } else {
        i45 = b_jj->size[0] * b_jj->size[1];
        if (1 > idx) {
          b_jj->size[1] = 0;
        } else {
          b_jj->size[1] = idx;
        }

        emxEnsureCapacity_int32_T(b_jj, i45);
      }
    }

    /* 'funcionDia:20' ~ */
    /* 'funcionDia:22' if sum((minP>=auxUPxR(PCPrO==1)),2)~=0 && ~isempty(c) */
    b_Dia = PCPrO->size[1] - 1;
    jj = 0;
    for (idx = 0; idx <= b_Dia; idx++) {
      if (PCPrO->data[idx] == 1) {
        jj++;
      }
    }

    i45 = r12->size[0] * r12->size[1];
    r12->size[0] = 1;
    r12->size[1] = jj;
    emxEnsureCapacity_int32_T(r12, i45);
    jj = 0;
    for (idx = 0; idx <= b_Dia; idx++) {
      if (PCPrO->data[idx] == 1) {
        r12->data[jj] = idx + 1;
        jj++;
      }
    }

    i45 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = r12->size[1];
    emxEnsureCapacity_boolean_T(x, i45);
    jj = r12->size[1];
    for (i45 = 0; i45 < jj; i45++) {
      x->data[i45] = (minP >= auxUPxR->data[r12->data[i45] - 1]);
    }

    jj = x->size[1];
    if (x->size[1] == 0) {
      y = 0.0;
    } else {
      y = x->data[0];
      for (idx = 2; idx <= jj; idx++) {
        if (jj >= 2) {
          y += (double)x->data[idx - 1];
        }
      }
    }

    if ((y != 0.0) && (b_jj->size[1] != 0)) {
      exitg1 = 1;
    } else {
      /* 'funcionDia:25' else */
      /* 'funcionDia:26' contDia = contDia + 1; */
      (*contDia)++;
    }
  } while (exitg1 == 0);

  /*  Compruebo que cabe en alguna pocision de las posibles, si no cabe incremento el dia. */
  /* 'funcionDia:23' tempUltPosRecXDia = auxUPxR; */
  i45 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = auxUPxR->size[1];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i45);
  jj = auxUPxR->size[1];
  for (i45 = 0; i45 < jj; i45++) {
    tempUltPosRecXDia->data[i45] = auxUPxR->data[i45];
  }

  /* 'funcionDia:24' flag=false; */
  emxFree_int32_T(&b_jj);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&r12);
  emxFree_int32_T(&auxUPxR);

  /* 'funcionDia:33' DispME = zeros(1,size(DispMExD,2), 'int32'); */
  jj = DispMExD->size[1];
  i45 = DispME->size[0] * DispME->size[1];
  DispME->size[0] = 1;
  DispME->size[1] = jj;
  emxEnsureCapacity_int32_T(DispME, i45);
  for (i45 = 0; i45 < jj; i45++) {
    DispME->data[i45] = 0;
  }

  /* 'funcionDia:34' switch Dia(contDia,2) */
  switch (Dia->data[(*contDia + Dia->size[0]) - 1]) {
   case 2:
    /* 'funcionDia:35' case 2 */
    /* 'funcionDia:36' DispME=int32(DispMExD(1,:)); */
    jj = DispMExD->size[1];
    i45 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i45);
    for (i45 = 0; i45 < jj; i45++) {
      DispME->data[i45] = DispMExD->data[6 * i45];
    }
    break;

   case 3:
    /* 'funcionDia:37' case 3 */
    /* 'funcionDia:38' DispME=int32(DispMExD(2,:)); */
    jj = DispMExD->size[1];
    i45 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i45);
    for (i45 = 0; i45 < jj; i45++) {
      DispME->data[i45] = DispMExD->data[1 + 6 * i45];
    }
    break;

   case 4:
    /* 'funcionDia:39' case 4 */
    /* 'funcionDia:40' DispME=int32(DispMExD(3,:)); */
    jj = DispMExD->size[1];
    i45 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i45);
    for (i45 = 0; i45 < jj; i45++) {
      DispME->data[i45] = DispMExD->data[2 + 6 * i45];
    }
    break;

   case 5:
    /* 'funcionDia:41' case 5 */
    /* 'funcionDia:42' DispME=int32(DispMExD(4,:)); */
    jj = DispMExD->size[1];
    i45 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i45);
    for (i45 = 0; i45 < jj; i45++) {
      DispME->data[i45] = DispMExD->data[3 + 6 * i45];
    }
    break;

   case 6:
    /* 'funcionDia:43' case 6 */
    /* 'funcionDia:44' DispME=int32(DispMExD(5,:)); */
    jj = DispMExD->size[1];
    i45 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i45);
    for (i45 = 0; i45 < jj; i45++) {
      DispME->data[i45] = DispMExD->data[4 + 6 * i45];
    }
    break;

   case 7:
    /* 'funcionDia:45' case 7 */
    /* 'funcionDia:46' DispME=int32(DispMExD(6,:)); */
    jj = DispMExD->size[1];
    i45 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i45);
    for (i45 = 0; i45 < jj; i45++) {
      DispME->data[i45] = DispMExD->data[5 + 6 * i45];
    }
    break;
  }
}

/*
 * File trailer for funcionDia.c
 *
 * [EOF]
 */
