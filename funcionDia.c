/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * funcionDia.c
 *
 * Code generation for function 'funcionDia'
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
#include "sum.h"
#include "model_rtwutil.h"

/* Function Definitions */
void b_funcionDia(const int NumRec[7], const emxArray_int32_T *PCPrO, const
                  emxArray_int32_T *Dia, const emxArray_real_T *UltPosRecXDia,
                  int TimeUsoCPrO, int TimeUsoS, int *contDia, const
                  emxArray_int32_T *DispMExD, emxArray_int32_T
                  *tempUltPosRecXDia, emxArray_int32_T *DispME)
{
  int i69;
  int jj;
  emxArray_int32_T *auxUPxR;
  emxArray_int32_T *r12;
  emxArray_boolean_T *x;
  emxArray_int32_T *j;
  int exitg1;
  double b_Dia;
  int idx;
  int qY;
  double y;
  int end;
  boolean_T exitg2;

  /*  NumCPrO: Numero de camas PreOperatorias. */
  /*  PCPrO: Posibles camas PreOperatorias para esa operacion. */
  /*  Dia: Matriz con el cosecutivo de dias y el dia de la semana. Ademas tiene */
  /*  los indices donde empieza y termina cada dia de la matriz Data(Ver main_UCI). */
  /*  UltPosRecXDia: Ultima posicion asignado del recurso por Dia. */
  /*  Time: El tiempo de uso de la Cama PrO mas el tiempo de operacion. */
  /*  contDia: Contador de dia. */
  i69 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = NumRec[0];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i69);
  jj = NumRec[0];
  for (i69 = 0; i69 < jj; i69++) {
    tempUltPosRecXDia->data[i69] = 0;
  }

  emxInit_int32_T(&auxUPxR, 2);
  emxInit_int32_T(&r12, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&j, 2);
  do {
    exitg1 = 0;
    while (Dia->data[(*contDia + (Dia->size[0] << 1)) - 1] == 0) {
      jj = *contDia;
      if (jj > 2147483646) {
        *contDia = MAX_int32_T;
      } else {
        *contDia = jj + 1;
      }
    }

    if (1 > NumRec[0]) {
      jj = 0;
    } else {
      jj = NumRec[0];
    }

    i69 = auxUPxR->size[0] * auxUPxR->size[1];
    auxUPxR->size[0] = 1;
    auxUPxR->size[1] = jj;
    emxEnsureCapacity_int32_T(auxUPxR, i69);
    for (i69 = 0; i69 < jj; i69++) {
      b_Dia = rt_roundd(UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] *
        i69) - 1]);
      if (b_Dia < 2.147483648E+9) {
        if (b_Dia >= -2.147483648E+9) {
          idx = (int)b_Dia;
        } else {
          idx = MIN_int32_T;
        }
      } else {
        idx = MAX_int32_T;
      }

      auxUPxR->data[i69] = idx;
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden usar las camas. */
    jj = Dia->data[(*contDia + Dia->size[0] * 3) - 1];
    idx = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
    if ((jj >= 0) && (idx < jj - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((jj < 0) && (idx > jj - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY = jj - idx;
    }

    if (qY > 2147483646) {
      qY = MAX_int32_T;
    } else {
      qY++;
    }

    if ((TimeUsoCPrO < 0) && (TimeUsoS < MIN_int32_T - TimeUsoCPrO)) {
      jj = MIN_int32_T;
    } else if ((TimeUsoCPrO > 0) && (TimeUsoS > MAX_int32_T - TimeUsoCPrO)) {
      jj = MAX_int32_T;
    } else {
      jj = TimeUsoCPrO + TimeUsoS;
    }

    if ((qY >= 0) && (jj < qY - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((qY < 0) && (jj > qY - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY -= jj;
    }

    /*  Posicion maxima a partir de la cual se puede colocar la Operacion */
    y = (double)NumRec[0] + (double)NumRec[1];
    b_Dia = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
    if (y + 1.0 > b_Dia) {
      i69 = 1;
      idx = 0;
    } else {
      i69 = (int)(y + 1.0);
      idx = (int)b_Dia;
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
    b_Dia = ((double)Dia->data[(*contDia + Dia->size[0] * 3) - 1] - (double)
             Dia->data[(*contDia + (Dia->size[0] << 1)) - 1]) + 1.0;
    end = x->size[0] * x->size[1];
    x->size[0] = 1;
    jj = idx - i69;
    x->size[1] = jj + 1;
    emxEnsureCapacity_boolean_T(x, end);
    for (idx = 0; idx <= jj; idx++) {
      x->data[idx] = (b_Dia - UltPosRecXDia->data[(*contDia +
        UltPosRecXDia->size[0] * ((i69 + idx) - 1)) - 1] >= TimeUsoS);
    }

    if (x->size[1] == 0) {
      j->size[1] = 0;
    } else {
      idx = 0;
      i69 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i69);
      jj = 1;
      exitg2 = false;
      while ((!exitg2) && (jj <= x->size[1])) {
        if (x->data[jj - 1]) {
          idx++;
          j->data[idx - 1] = jj;
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
          j->size[1] = 0;
        }
      } else if (1 > idx) {
        j->size[1] = 0;
      } else {
        i69 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i69);
      }
    }

    end = PCPrO->size[1] - 1;
    jj = 0;
    for (idx = 0; idx <= end; idx++) {
      if (PCPrO->data[idx] == 1) {
        jj++;
      }
    }

    i69 = r12->size[0] * r12->size[1];
    r12->size[0] = 1;
    r12->size[1] = jj;
    emxEnsureCapacity_int32_T(r12, i69);
    jj = 0;
    for (idx = 0; idx <= end; idx++) {
      if (PCPrO->data[idx] == 1) {
        r12->data[jj] = idx + 1;
        jj++;
      }
    }

    i69 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = r12->size[1];
    emxEnsureCapacity_boolean_T(x, i69);
    jj = r12->size[0] * r12->size[1];
    for (i69 = 0; i69 < jj; i69++) {
      x->data[i69] = (qY >= auxUPxR->data[r12->data[i69] - 1]);
    }

    if ((e_sum(x) != 0.0) && (j->size[1] != 0)) {
      exitg1 = 1;
    } else {
      jj = *contDia;
      if (jj > 2147483646) {
        *contDia = MAX_int32_T;
      } else {
        *contDia = jj + 1;
      }
    }
  } while (exitg1 == 0);

  /*  Compruebo que cabe en alguna pocision de las posibles, si no cabe incremento el dia. */
  i69 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = auxUPxR->size[1];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i69);
  jj = auxUPxR->size[0] * auxUPxR->size[1];
  for (i69 = 0; i69 < jj; i69++) {
    tempUltPosRecXDia->data[i69] = auxUPxR->data[i69];
  }

  emxFree_int32_T(&j);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&r12);
  emxFree_int32_T(&auxUPxR);
  i69 = DispME->size[0] * DispME->size[1];
  DispME->size[0] = 1;
  DispME->size[1] = DispMExD->size[1];
  emxEnsureCapacity_int32_T(DispME, i69);
  jj = DispMExD->size[1];
  for (i69 = 0; i69 < jj; i69++) {
    DispME->data[i69] = 0;
  }

  switch (Dia->data[(*contDia + Dia->size[0]) - 1]) {
   case 2:
    jj = DispMExD->size[1];
    i69 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i69);
    for (i69 = 0; i69 < jj; i69++) {
      DispME->data[i69] = DispMExD->data[6 * i69];
    }
    break;

   case 3:
    jj = DispMExD->size[1];
    i69 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i69);
    for (i69 = 0; i69 < jj; i69++) {
      DispME->data[i69] = DispMExD->data[1 + 6 * i69];
    }
    break;

   case 4:
    jj = DispMExD->size[1];
    i69 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i69);
    for (i69 = 0; i69 < jj; i69++) {
      DispME->data[i69] = DispMExD->data[2 + 6 * i69];
    }
    break;

   case 5:
    jj = DispMExD->size[1];
    i69 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i69);
    for (i69 = 0; i69 < jj; i69++) {
      DispME->data[i69] = DispMExD->data[3 + 6 * i69];
    }
    break;

   case 6:
    jj = DispMExD->size[1];
    i69 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i69);
    for (i69 = 0; i69 < jj; i69++) {
      DispME->data[i69] = DispMExD->data[4 + 6 * i69];
    }
    break;

   case 7:
    jj = DispMExD->size[1];
    i69 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i69);
    for (i69 = 0; i69 < jj; i69++) {
      DispME->data[i69] = DispMExD->data[5 + 6 * i69];
    }
    break;
  }
}

void c_funcionDia(const int NumRec[7], const emxArray_int32_T *PCPrO, const
                  emxArray_int32_T *Dia, const emxArray_int32_T *UltPosRecXDia,
                  int TimeUsoCPrO, int TimeUsoS, int *contDia, const
                  emxArray_int32_T *DispMExD, emxArray_int32_T
                  *tempUltPosRecXDia, emxArray_int32_T *DispME)
{
  int i80;
  int loop_ub;
  emxArray_int32_T *r14;
  emxArray_boolean_T *x;
  emxArray_int32_T *j;
  int exitg1;
  int jj;
  int idx;
  int qY;
  double y;
  double d28;
  int b_loop_ub;
  boolean_T exitg2;

  /*  NumCPrO: Numero de camas PreOperatorias. */
  /*  PCPrO: Posibles camas PreOperatorias para esa operacion. */
  /*  Dia: Matriz con el cosecutivo de dias y el dia de la semana. Ademas tiene */
  /*  los indices donde empieza y termina cada dia de la matriz Data(Ver main_UCI). */
  /*  UltPosRecXDia: Ultima posicion asignado del recurso por Dia. */
  /*  Time: El tiempo de uso de la Cama PrO mas el tiempo de operacion. */
  /*  contDia: Contador de dia. */
  i80 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = NumRec[0];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i80);
  loop_ub = NumRec[0];
  for (i80 = 0; i80 < loop_ub; i80++) {
    tempUltPosRecXDia->data[i80] = 0;
  }

  emxInit_int32_T(&r14, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&j, 2);
  do {
    exitg1 = 0;
    while (Dia->data[(*contDia + (Dia->size[0] << 1)) - 1] == 0) {
      jj = *contDia;
      if (jj > 2147483646) {
        *contDia = MAX_int32_T;
      } else {
        *contDia = jj + 1;
      }
    }

    if (1 > NumRec[0]) {
      loop_ub = 0;
    } else {
      loop_ub = NumRec[0];
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden usar las camas. */
    jj = Dia->data[(*contDia + Dia->size[0] * 3) - 1];
    idx = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
    if ((jj >= 0) && (idx < jj - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((jj < 0) && (idx > jj - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY = jj - idx;
    }

    if (qY > 2147483646) {
      qY = MAX_int32_T;
    } else {
      qY++;
    }

    if ((TimeUsoCPrO < 0) && (TimeUsoS < MIN_int32_T - TimeUsoCPrO)) {
      jj = MIN_int32_T;
    } else if ((TimeUsoCPrO > 0) && (TimeUsoS > MAX_int32_T - TimeUsoCPrO)) {
      jj = MAX_int32_T;
    } else {
      jj = TimeUsoCPrO + TimeUsoS;
    }

    if ((qY >= 0) && (jj < qY - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((qY < 0) && (jj > qY - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY -= jj;
    }

    /*  Posicion maxima a partir de la cual se puede colocar la Operacion */
    y = (double)NumRec[0] + (double)NumRec[1];
    d28 = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
    if (y + 1.0 > d28) {
      i80 = 1;
      jj = 0;
    } else {
      i80 = (int)(y + 1.0);
      jj = (int)d28;
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
    y = ((double)Dia->data[(*contDia + Dia->size[0] * 3) - 1] - (double)
         Dia->data[(*contDia + (Dia->size[0] << 1)) - 1]) + 1.0;
    idx = x->size[0] * x->size[1];
    x->size[0] = 1;
    b_loop_ub = jj - i80;
    x->size[1] = b_loop_ub + 1;
    emxEnsureCapacity_boolean_T(x, idx);
    for (jj = 0; jj <= b_loop_ub; jj++) {
      d28 = y - (double)UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] *
        ((i80 + jj) - 1)) - 1];
      if (d28 < 2.147483648E+9) {
        if (d28 >= -2.147483648E+9) {
          idx = (int)d28;
        } else {
          idx = MIN_int32_T;
        }
      } else {
        idx = MAX_int32_T;
      }

      x->data[jj] = (idx >= TimeUsoS);
    }

    if (x->size[1] == 0) {
      j->size[1] = 0;
    } else {
      idx = 0;
      i80 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i80);
      jj = 1;
      exitg2 = false;
      while ((!exitg2) && (jj <= x->size[1])) {
        if (x->data[jj - 1]) {
          idx++;
          j->data[idx - 1] = jj;
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
          j->size[1] = 0;
        }
      } else if (1 > idx) {
        j->size[1] = 0;
      } else {
        i80 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i80);
      }
    }

    b_loop_ub = PCPrO->size[1] - 1;
    jj = 0;
    for (idx = 0; idx <= b_loop_ub; idx++) {
      if (PCPrO->data[idx] == 1) {
        jj++;
      }
    }

    i80 = r14->size[0] * r14->size[1];
    r14->size[0] = 1;
    r14->size[1] = jj;
    emxEnsureCapacity_int32_T(r14, i80);
    jj = 0;
    for (idx = 0; idx <= b_loop_ub; idx++) {
      if (PCPrO->data[idx] == 1) {
        r14->data[jj] = idx + 1;
        jj++;
      }
    }

    i80 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = r14->size[1];
    emxEnsureCapacity_boolean_T(x, i80);
    b_loop_ub = r14->size[1];
    for (i80 = 0; i80 < b_loop_ub; i80++) {
      x->data[i80] = (qY >= UltPosRecXDia->data[(*contDia + UltPosRecXDia->size
        [0] * (r14->data[i80] - 1)) - 1]);
    }

    if ((e_sum(x) != 0.0) && (j->size[1] != 0)) {
      exitg1 = 1;
    } else {
      jj = *contDia;
      if (jj > 2147483646) {
        *contDia = MAX_int32_T;
      } else {
        *contDia = jj + 1;
      }
    }
  } while (exitg1 == 0);

  /*  Compruebo que cabe en alguna pocision de las posibles, si no cabe incremento el dia. */
  i80 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i80);
  for (i80 = 0; i80 < loop_ub; i80++) {
    tempUltPosRecXDia->data[i80] = UltPosRecXDia->data[(*contDia +
      UltPosRecXDia->size[0] * i80) - 1];
  }

  emxFree_int32_T(&j);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&r14);
  i80 = DispME->size[0] * DispME->size[1];
  DispME->size[0] = 1;
  DispME->size[1] = DispMExD->size[1];
  emxEnsureCapacity_int32_T(DispME, i80);
  loop_ub = DispMExD->size[1];
  for (i80 = 0; i80 < loop_ub; i80++) {
    DispME->data[i80] = 0;
  }

  switch (Dia->data[(*contDia + Dia->size[0]) - 1]) {
   case 2:
    loop_ub = DispMExD->size[1];
    i80 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i80);
    for (i80 = 0; i80 < loop_ub; i80++) {
      DispME->data[i80] = DispMExD->data[6 * i80];
    }
    break;

   case 3:
    loop_ub = DispMExD->size[1];
    i80 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i80);
    for (i80 = 0; i80 < loop_ub; i80++) {
      DispME->data[i80] = DispMExD->data[1 + 6 * i80];
    }
    break;

   case 4:
    loop_ub = DispMExD->size[1];
    i80 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i80);
    for (i80 = 0; i80 < loop_ub; i80++) {
      DispME->data[i80] = DispMExD->data[2 + 6 * i80];
    }
    break;

   case 5:
    loop_ub = DispMExD->size[1];
    i80 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i80);
    for (i80 = 0; i80 < loop_ub; i80++) {
      DispME->data[i80] = DispMExD->data[3 + 6 * i80];
    }
    break;

   case 6:
    loop_ub = DispMExD->size[1];
    i80 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i80);
    for (i80 = 0; i80 < loop_ub; i80++) {
      DispME->data[i80] = DispMExD->data[4 + 6 * i80];
    }
    break;

   case 7:
    loop_ub = DispMExD->size[1];
    i80 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i80);
    for (i80 = 0; i80 < loop_ub; i80++) {
      DispME->data[i80] = DispMExD->data[5 + 6 * i80];
    }
    break;
  }
}

void d_funcionDia(const int NumRec[7], const emxArray_int32_T *PCPrO, const
                  emxArray_int32_T *Dia, const emxArray_real_T *UltPosRecXDia,
                  int TimeUsoCPrO, int TimeUsoS, int *contDia, const
                  emxArray_int32_T *DispMExD, emxArray_int32_T
                  *tempUltPosRecXDia, int *DispME)
{
  int i98;
  int jj;
  emxArray_int32_T *auxUPxR;
  emxArray_int32_T *r19;
  emxArray_boolean_T *x;
  emxArray_int32_T *j;
  int exitg1;
  double b_Dia;
  int idx;
  int qY;
  double y;
  int end;
  boolean_T exitg2;

  /*  NumCPrO: Numero de camas PreOperatorias. */
  /*  PCPrO: Posibles camas PreOperatorias para esa operacion. */
  /*  Dia: Matriz con el cosecutivo de dias y el dia de la semana. Ademas tiene */
  /*  los indices donde empieza y termina cada dia de la matriz Data(Ver main_UCI). */
  /*  UltPosRecXDia: Ultima posicion asignado del recurso por Dia. */
  /*  Time: El tiempo de uso de la Cama PrO mas el tiempo de operacion. */
  /*  contDia: Contador de dia. */
  i98 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = NumRec[0];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i98);
  jj = NumRec[0];
  for (i98 = 0; i98 < jj; i98++) {
    tempUltPosRecXDia->data[i98] = 0;
  }

  emxInit_int32_T(&auxUPxR, 2);
  emxInit_int32_T(&r19, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&j, 2);
  do {
    exitg1 = 0;
    while (Dia->data[(*contDia + (Dia->size[0] << 1)) - 1] == 0) {
      jj = *contDia;
      if (jj > 2147483646) {
        *contDia = MAX_int32_T;
      } else {
        *contDia = jj + 1;
      }
    }

    if (1 > NumRec[0]) {
      jj = 0;
    } else {
      jj = NumRec[0];
    }

    i98 = auxUPxR->size[0] * auxUPxR->size[1];
    auxUPxR->size[0] = 1;
    auxUPxR->size[1] = jj;
    emxEnsureCapacity_int32_T(auxUPxR, i98);
    for (i98 = 0; i98 < jj; i98++) {
      b_Dia = rt_roundd(UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] *
        i98) - 1]);
      if (b_Dia < 2.147483648E+9) {
        if (b_Dia >= -2.147483648E+9) {
          idx = (int)b_Dia;
        } else {
          idx = MIN_int32_T;
        }
      } else {
        idx = MAX_int32_T;
      }

      auxUPxR->data[i98] = idx;
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden usar las camas. */
    jj = Dia->data[(*contDia + Dia->size[0] * 3) - 1];
    idx = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
    if ((jj >= 0) && (idx < jj - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((jj < 0) && (idx > jj - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY = jj - idx;
    }

    if (qY > 2147483646) {
      qY = MAX_int32_T;
    } else {
      qY++;
    }

    if ((TimeUsoCPrO < 0) && (TimeUsoS < MIN_int32_T - TimeUsoCPrO)) {
      jj = MIN_int32_T;
    } else if ((TimeUsoCPrO > 0) && (TimeUsoS > MAX_int32_T - TimeUsoCPrO)) {
      jj = MAX_int32_T;
    } else {
      jj = TimeUsoCPrO + TimeUsoS;
    }

    if ((qY >= 0) && (jj < qY - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((qY < 0) && (jj > qY - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY -= jj;
    }

    /*  Posicion maxima a partir de la cual se puede colocar la Operacion */
    y = (double)NumRec[0] + (double)NumRec[1];
    b_Dia = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
    if (y + 1.0 > b_Dia) {
      i98 = 1;
      idx = 0;
    } else {
      i98 = (int)(y + 1.0);
      idx = (int)b_Dia;
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
    b_Dia = ((double)Dia->data[(*contDia + Dia->size[0] * 3) - 1] - (double)
             Dia->data[(*contDia + (Dia->size[0] << 1)) - 1]) + 1.0;
    end = x->size[0] * x->size[1];
    x->size[0] = 1;
    jj = idx - i98;
    x->size[1] = jj + 1;
    emxEnsureCapacity_boolean_T(x, end);
    for (idx = 0; idx <= jj; idx++) {
      x->data[idx] = (b_Dia - UltPosRecXDia->data[(*contDia +
        UltPosRecXDia->size[0] * ((i98 + idx) - 1)) - 1] >= TimeUsoS);
    }

    if (x->size[1] == 0) {
      j->size[1] = 0;
    } else {
      idx = 0;
      i98 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i98);
      jj = 1;
      exitg2 = false;
      while ((!exitg2) && (jj <= x->size[1])) {
        if (x->data[jj - 1]) {
          idx++;
          j->data[idx - 1] = jj;
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
          j->size[1] = 0;
        }
      } else if (1 > idx) {
        j->size[1] = 0;
      } else {
        i98 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i98);
      }
    }

    end = PCPrO->size[1] - 1;
    jj = 0;
    for (idx = 0; idx <= end; idx++) {
      if (PCPrO->data[idx] == 1) {
        jj++;
      }
    }

    i98 = r19->size[0] * r19->size[1];
    r19->size[0] = 1;
    r19->size[1] = jj;
    emxEnsureCapacity_int32_T(r19, i98);
    jj = 0;
    for (idx = 0; idx <= end; idx++) {
      if (PCPrO->data[idx] == 1) {
        r19->data[jj] = idx + 1;
        jj++;
      }
    }

    i98 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = r19->size[1];
    emxEnsureCapacity_boolean_T(x, i98);
    jj = r19->size[0] * r19->size[1];
    for (i98 = 0; i98 < jj; i98++) {
      x->data[i98] = (qY >= auxUPxR->data[r19->data[i98] - 1]);
    }

    if ((e_sum(x) != 0.0) && (j->size[1] != 0)) {
      exitg1 = 1;
    } else {
      jj = *contDia;
      if (jj > 2147483646) {
        *contDia = MAX_int32_T;
      } else {
        *contDia = jj + 1;
      }
    }
  } while (exitg1 == 0);

  /*  Compruebo que cabe en alguna pocision de las posibles, si no cabe incremento el dia. */
  i98 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = auxUPxR->size[1];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i98);
  jj = auxUPxR->size[0] * auxUPxR->size[1];
  for (i98 = 0; i98 < jj; i98++) {
    tempUltPosRecXDia->data[i98] = auxUPxR->data[i98];
  }

  emxFree_int32_T(&j);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&r19);
  emxFree_int32_T(&auxUPxR);
  jj = 0;
  switch (Dia->data[(*contDia + Dia->size[0]) - 1]) {
   case 2:
    jj = DispMExD->data[0];
    break;

   case 3:
    jj = DispMExD->data[1];
    break;

   case 4:
    jj = DispMExD->data[2];
    break;

   case 5:
    jj = DispMExD->data[3];
    break;

   case 6:
    jj = DispMExD->data[4];
    break;

   case 7:
    jj = DispMExD->data[5];
    break;
  }

  *DispME = jj;
}

void funcionDia(const int NumRec[7], const emxArray_int32_T *PCPrO, const
                emxArray_int32_T *Dia, const emxArray_int32_T *UltPosRecXDia,
                int TimeUsoCPrO, int TimeUsoS, int *contDia, const
                emxArray_int32_T *DispMExD, emxArray_int32_T *tempUltPosRecXDia,
                emxArray_int32_T *DispME)
{
  int i87;
  int loop_ub;
  emxArray_int32_T *r17;
  emxArray_boolean_T *x;
  emxArray_int32_T *j;
  int exitg1;
  int jj;
  int idx;
  int qY;
  double y;
  double d29;
  int b_loop_ub;
  boolean_T exitg2;

  /*  NumCPrO: Numero de camas PreOperatorias. */
  /*  PCPrO: Posibles camas PreOperatorias para esa operacion. */
  /*  Dia: Matriz con el cosecutivo de dias y el dia de la semana. Ademas tiene */
  /*  los indices donde empieza y termina cada dia de la matriz Data(Ver main_UCI). */
  /*  UltPosRecXDia: Ultima posicion asignado del recurso por Dia. */
  /*  Time: El tiempo de uso de la Cama PrO mas el tiempo de operacion. */
  /*  contDia: Contador de dia. */
  i87 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = NumRec[0];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i87);
  loop_ub = NumRec[0];
  for (i87 = 0; i87 < loop_ub; i87++) {
    tempUltPosRecXDia->data[i87] = 0;
  }

  emxInit_int32_T(&r17, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&j, 2);
  do {
    exitg1 = 0;
    while (Dia->data[(*contDia + (Dia->size[0] << 1)) - 1] == 0) {
      jj = *contDia;
      if (jj > 2147483646) {
        *contDia = MAX_int32_T;
      } else {
        *contDia = jj + 1;
      }
    }

    if (1 > NumRec[0]) {
      loop_ub = 0;
    } else {
      loop_ub = NumRec[0];
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden usar las camas. */
    jj = Dia->data[(*contDia + Dia->size[0] * 3) - 1];
    idx = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
    if ((jj >= 0) && (idx < jj - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((jj < 0) && (idx > jj - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY = jj - idx;
    }

    if (qY > 2147483646) {
      qY = MAX_int32_T;
    } else {
      qY++;
    }

    if ((TimeUsoCPrO < 0) && (TimeUsoS < MIN_int32_T - TimeUsoCPrO)) {
      jj = MIN_int32_T;
    } else if ((TimeUsoCPrO > 0) && (TimeUsoS > MAX_int32_T - TimeUsoCPrO)) {
      jj = MAX_int32_T;
    } else {
      jj = TimeUsoCPrO + TimeUsoS;
    }

    if ((qY >= 0) && (jj < qY - MAX_int32_T)) {
      qY = MAX_int32_T;
    } else if ((qY < 0) && (jj > qY - MIN_int32_T)) {
      qY = MIN_int32_T;
    } else {
      qY -= jj;
    }

    /*  Posicion maxima a partir de la cual se puede colocar la Operacion */
    y = (double)NumRec[0] + (double)NumRec[1];
    d29 = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
    if (y + 1.0 > d29) {
      i87 = 1;
      jj = 0;
    } else {
      i87 = (int)(y + 1.0);
      jj = (int)d29;
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
    y = ((double)Dia->data[(*contDia + Dia->size[0] * 3) - 1] - (double)
         Dia->data[(*contDia + (Dia->size[0] << 1)) - 1]) + 1.0;
    idx = x->size[0] * x->size[1];
    x->size[0] = 1;
    b_loop_ub = jj - i87;
    x->size[1] = b_loop_ub + 1;
    emxEnsureCapacity_boolean_T(x, idx);
    for (jj = 0; jj <= b_loop_ub; jj++) {
      d29 = y - (double)UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] *
        ((i87 + jj) - 1)) - 1];
      if (d29 < 2.147483648E+9) {
        if (d29 >= -2.147483648E+9) {
          idx = (int)d29;
        } else {
          idx = MIN_int32_T;
        }
      } else {
        idx = MAX_int32_T;
      }

      x->data[jj] = (idx >= TimeUsoS);
    }

    if (x->size[1] == 0) {
      j->size[1] = 0;
    } else {
      idx = 0;
      i87 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i87);
      jj = 1;
      exitg2 = false;
      while ((!exitg2) && (jj <= x->size[1])) {
        if (x->data[jj - 1]) {
          idx++;
          j->data[idx - 1] = jj;
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
          j->size[1] = 0;
        }
      } else if (1 > idx) {
        j->size[1] = 0;
      } else {
        i87 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i87);
      }
    }

    b_loop_ub = PCPrO->size[1] - 1;
    jj = 0;
    for (idx = 0; idx <= b_loop_ub; idx++) {
      if (PCPrO->data[idx] == 1) {
        jj++;
      }
    }

    i87 = r17->size[0] * r17->size[1];
    r17->size[0] = 1;
    r17->size[1] = jj;
    emxEnsureCapacity_int32_T(r17, i87);
    jj = 0;
    for (idx = 0; idx <= b_loop_ub; idx++) {
      if (PCPrO->data[idx] == 1) {
        r17->data[jj] = idx + 1;
        jj++;
      }
    }

    i87 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = r17->size[1];
    emxEnsureCapacity_boolean_T(x, i87);
    b_loop_ub = r17->size[1];
    for (i87 = 0; i87 < b_loop_ub; i87++) {
      x->data[i87] = (qY >= UltPosRecXDia->data[(*contDia + UltPosRecXDia->size
        [0] * (r17->data[i87] - 1)) - 1]);
    }

    if ((e_sum(x) != 0.0) && (j->size[1] != 0)) {
      exitg1 = 1;
    } else {
      jj = *contDia;
      if (jj > 2147483646) {
        *contDia = MAX_int32_T;
      } else {
        *contDia = jj + 1;
      }
    }
  } while (exitg1 == 0);

  /*  Compruebo que cabe en alguna pocision de las posibles, si no cabe incremento el dia. */
  i87 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i87);
  for (i87 = 0; i87 < loop_ub; i87++) {
    tempUltPosRecXDia->data[i87] = UltPosRecXDia->data[(*contDia +
      UltPosRecXDia->size[0] * i87) - 1];
  }

  emxFree_int32_T(&j);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&r17);
  i87 = DispME->size[0] * DispME->size[1];
  DispME->size[0] = 1;
  DispME->size[1] = DispMExD->size[1];
  emxEnsureCapacity_int32_T(DispME, i87);
  loop_ub = DispMExD->size[1];
  for (i87 = 0; i87 < loop_ub; i87++) {
    DispME->data[i87] = 0;
  }

  switch (Dia->data[(*contDia + Dia->size[0]) - 1]) {
   case 2:
    loop_ub = DispMExD->size[1];
    i87 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i87);
    for (i87 = 0; i87 < loop_ub; i87++) {
      DispME->data[i87] = DispMExD->data[6 * i87];
    }
    break;

   case 3:
    loop_ub = DispMExD->size[1];
    i87 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i87);
    for (i87 = 0; i87 < loop_ub; i87++) {
      DispME->data[i87] = DispMExD->data[1 + 6 * i87];
    }
    break;

   case 4:
    loop_ub = DispMExD->size[1];
    i87 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i87);
    for (i87 = 0; i87 < loop_ub; i87++) {
      DispME->data[i87] = DispMExD->data[2 + 6 * i87];
    }
    break;

   case 5:
    loop_ub = DispMExD->size[1];
    i87 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i87);
    for (i87 = 0; i87 < loop_ub; i87++) {
      DispME->data[i87] = DispMExD->data[3 + 6 * i87];
    }
    break;

   case 6:
    loop_ub = DispMExD->size[1];
    i87 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i87);
    for (i87 = 0; i87 < loop_ub; i87++) {
      DispME->data[i87] = DispMExD->data[4 + 6 * i87];
    }
    break;

   case 7:
    loop_ub = DispMExD->size[1];
    i87 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i87);
    for (i87 = 0; i87 < loop_ub; i87++) {
      DispME->data[i87] = DispMExD->data[5 + 6 * i87];
    }
    break;
  }
}

/* End of code generation (funcionDia.c) */
