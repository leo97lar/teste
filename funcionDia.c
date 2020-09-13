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
  int i77;
  int jj;
  emxArray_int32_T *auxUPxR;
  emxArray_int32_T *r11;
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
  i77 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = NumRec[0];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i77);
  jj = NumRec[0];
  for (i77 = 0; i77 < jj; i77++) {
    tempUltPosRecXDia->data[i77] = 0;
  }

  emxInit_int32_T(&auxUPxR, 2);
  emxInit_int32_T(&r11, 2);
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

    i77 = auxUPxR->size[0] * auxUPxR->size[1];
    auxUPxR->size[0] = 1;
    auxUPxR->size[1] = jj;
    emxEnsureCapacity_int32_T(auxUPxR, i77);
    for (i77 = 0; i77 < jj; i77++) {
      b_Dia = rt_roundd(UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] *
        i77) - 1]);
      if (b_Dia < 2.147483648E+9) {
        if (b_Dia >= -2.147483648E+9) {
          idx = (int)b_Dia;
        } else {
          idx = MIN_int32_T;
        }
      } else {
        idx = MAX_int32_T;
      }

      auxUPxR->data[i77] = idx;
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
      i77 = 1;
      idx = 0;
    } else {
      i77 = (int)(y + 1.0);
      idx = (int)b_Dia;
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
    b_Dia = ((double)Dia->data[(*contDia + Dia->size[0] * 3) - 1] - (double)
             Dia->data[(*contDia + (Dia->size[0] << 1)) - 1]) + 1.0;
    end = x->size[0] * x->size[1];
    x->size[0] = 1;
    jj = idx - i77;
    x->size[1] = jj + 1;
    emxEnsureCapacity_boolean_T(x, end);
    for (idx = 0; idx <= jj; idx++) {
      x->data[idx] = (b_Dia - UltPosRecXDia->data[(*contDia +
        UltPosRecXDia->size[0] * ((i77 + idx) - 1)) - 1] >= TimeUsoS);
    }

    if (x->size[1] == 0) {
      j->size[1] = 0;
    } else {
      idx = 0;
      i77 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i77);
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
        i77 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i77);
      }
    }

    end = PCPrO->size[1] - 1;
    jj = 0;
    for (idx = 0; idx <= end; idx++) {
      if (PCPrO->data[idx] == 1) {
        jj++;
      }
    }

    i77 = r11->size[0] * r11->size[1];
    r11->size[0] = 1;
    r11->size[1] = jj;
    emxEnsureCapacity_int32_T(r11, i77);
    jj = 0;
    for (idx = 0; idx <= end; idx++) {
      if (PCPrO->data[idx] == 1) {
        r11->data[jj] = idx + 1;
        jj++;
      }
    }

    i77 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = r11->size[1];
    emxEnsureCapacity_boolean_T(x, i77);
    jj = r11->size[0] * r11->size[1];
    for (i77 = 0; i77 < jj; i77++) {
      x->data[i77] = (qY >= auxUPxR->data[r11->data[i77] - 1]);
    }

    if ((f_sum(x) != 0.0) && (j->size[1] != 0)) {
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
  i77 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = auxUPxR->size[1];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i77);
  jj = auxUPxR->size[0] * auxUPxR->size[1];
  for (i77 = 0; i77 < jj; i77++) {
    tempUltPosRecXDia->data[i77] = auxUPxR->data[i77];
  }

  emxFree_int32_T(&j);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&r11);
  emxFree_int32_T(&auxUPxR);
  i77 = DispME->size[0] * DispME->size[1];
  DispME->size[0] = 1;
  DispME->size[1] = DispMExD->size[1];
  emxEnsureCapacity_int32_T(DispME, i77);
  jj = DispMExD->size[1];
  for (i77 = 0; i77 < jj; i77++) {
    DispME->data[i77] = 0;
  }

  switch (Dia->data[(*contDia + Dia->size[0]) - 1]) {
   case 2:
    jj = DispMExD->size[1];
    i77 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i77);
    for (i77 = 0; i77 < jj; i77++) {
      DispME->data[i77] = DispMExD->data[6 * i77];
    }
    break;

   case 3:
    jj = DispMExD->size[1];
    i77 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i77);
    for (i77 = 0; i77 < jj; i77++) {
      DispME->data[i77] = DispMExD->data[1 + 6 * i77];
    }
    break;

   case 4:
    jj = DispMExD->size[1];
    i77 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i77);
    for (i77 = 0; i77 < jj; i77++) {
      DispME->data[i77] = DispMExD->data[2 + 6 * i77];
    }
    break;

   case 5:
    jj = DispMExD->size[1];
    i77 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i77);
    for (i77 = 0; i77 < jj; i77++) {
      DispME->data[i77] = DispMExD->data[3 + 6 * i77];
    }
    break;

   case 6:
    jj = DispMExD->size[1];
    i77 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i77);
    for (i77 = 0; i77 < jj; i77++) {
      DispME->data[i77] = DispMExD->data[4 + 6 * i77];
    }
    break;

   case 7:
    jj = DispMExD->size[1];
    i77 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i77);
    for (i77 = 0; i77 < jj; i77++) {
      DispME->data[i77] = DispMExD->data[5 + 6 * i77];
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
  int i88;
  int loop_ub;
  emxArray_int32_T *r13;
  emxArray_boolean_T *x;
  emxArray_int32_T *j;
  int exitg1;
  int jj;
  int idx;
  int qY;
  double y;
  double d32;
  int b_loop_ub;
  boolean_T exitg2;

  /*  NumCPrO: Numero de camas PreOperatorias. */
  /*  PCPrO: Posibles camas PreOperatorias para esa operacion. */
  /*  Dia: Matriz con el cosecutivo de dias y el dia de la semana. Ademas tiene */
  /*  los indices donde empieza y termina cada dia de la matriz Data(Ver main_UCI). */
  /*  UltPosRecXDia: Ultima posicion asignado del recurso por Dia. */
  /*  Time: El tiempo de uso de la Cama PrO mas el tiempo de operacion. */
  /*  contDia: Contador de dia. */
  i88 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = NumRec[0];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i88);
  loop_ub = NumRec[0];
  for (i88 = 0; i88 < loop_ub; i88++) {
    tempUltPosRecXDia->data[i88] = 0;
  }

  emxInit_int32_T(&r13, 2);
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
    d32 = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
    if (y + 1.0 > d32) {
      i88 = 1;
      jj = 0;
    } else {
      i88 = (int)(y + 1.0);
      jj = (int)d32;
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
    y = ((double)Dia->data[(*contDia + Dia->size[0] * 3) - 1] - (double)
         Dia->data[(*contDia + (Dia->size[0] << 1)) - 1]) + 1.0;
    idx = x->size[0] * x->size[1];
    x->size[0] = 1;
    b_loop_ub = jj - i88;
    x->size[1] = b_loop_ub + 1;
    emxEnsureCapacity_boolean_T(x, idx);
    for (jj = 0; jj <= b_loop_ub; jj++) {
      d32 = y - (double)UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] *
        ((i88 + jj) - 1)) - 1];
      if (d32 < 2.147483648E+9) {
        if (d32 >= -2.147483648E+9) {
          idx = (int)d32;
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
      i88 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i88);
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
        i88 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i88);
      }
    }

    b_loop_ub = PCPrO->size[1] - 1;
    jj = 0;
    for (idx = 0; idx <= b_loop_ub; idx++) {
      if (PCPrO->data[idx] == 1) {
        jj++;
      }
    }

    i88 = r13->size[0] * r13->size[1];
    r13->size[0] = 1;
    r13->size[1] = jj;
    emxEnsureCapacity_int32_T(r13, i88);
    jj = 0;
    for (idx = 0; idx <= b_loop_ub; idx++) {
      if (PCPrO->data[idx] == 1) {
        r13->data[jj] = idx + 1;
        jj++;
      }
    }

    i88 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = r13->size[1];
    emxEnsureCapacity_boolean_T(x, i88);
    b_loop_ub = r13->size[1];
    for (i88 = 0; i88 < b_loop_ub; i88++) {
      x->data[i88] = (qY >= UltPosRecXDia->data[(*contDia + UltPosRecXDia->size
        [0] * (r13->data[i88] - 1)) - 1]);
    }

    if ((f_sum(x) != 0.0) && (j->size[1] != 0)) {
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
  i88 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i88);
  for (i88 = 0; i88 < loop_ub; i88++) {
    tempUltPosRecXDia->data[i88] = UltPosRecXDia->data[(*contDia +
      UltPosRecXDia->size[0] * i88) - 1];
  }

  emxFree_int32_T(&j);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&r13);
  i88 = DispME->size[0] * DispME->size[1];
  DispME->size[0] = 1;
  DispME->size[1] = DispMExD->size[1];
  emxEnsureCapacity_int32_T(DispME, i88);
  loop_ub = DispMExD->size[1];
  for (i88 = 0; i88 < loop_ub; i88++) {
    DispME->data[i88] = 0;
  }

  switch (Dia->data[(*contDia + Dia->size[0]) - 1]) {
   case 2:
    loop_ub = DispMExD->size[1];
    i88 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i88);
    for (i88 = 0; i88 < loop_ub; i88++) {
      DispME->data[i88] = DispMExD->data[6 * i88];
    }
    break;

   case 3:
    loop_ub = DispMExD->size[1];
    i88 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i88);
    for (i88 = 0; i88 < loop_ub; i88++) {
      DispME->data[i88] = DispMExD->data[1 + 6 * i88];
    }
    break;

   case 4:
    loop_ub = DispMExD->size[1];
    i88 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i88);
    for (i88 = 0; i88 < loop_ub; i88++) {
      DispME->data[i88] = DispMExD->data[2 + 6 * i88];
    }
    break;

   case 5:
    loop_ub = DispMExD->size[1];
    i88 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i88);
    for (i88 = 0; i88 < loop_ub; i88++) {
      DispME->data[i88] = DispMExD->data[3 + 6 * i88];
    }
    break;

   case 6:
    loop_ub = DispMExD->size[1];
    i88 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i88);
    for (i88 = 0; i88 < loop_ub; i88++) {
      DispME->data[i88] = DispMExD->data[4 + 6 * i88];
    }
    break;

   case 7:
    loop_ub = DispMExD->size[1];
    i88 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i88);
    for (i88 = 0; i88 < loop_ub; i88++) {
      DispME->data[i88] = DispMExD->data[5 + 6 * i88];
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
  int i105;
  int jj;
  emxArray_int32_T *auxUPxR;
  emxArray_int32_T *r18;
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
  i105 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = NumRec[0];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i105);
  jj = NumRec[0];
  for (i105 = 0; i105 < jj; i105++) {
    tempUltPosRecXDia->data[i105] = 0;
  }

  emxInit_int32_T(&auxUPxR, 2);
  emxInit_int32_T(&r18, 2);
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

    i105 = auxUPxR->size[0] * auxUPxR->size[1];
    auxUPxR->size[0] = 1;
    auxUPxR->size[1] = jj;
    emxEnsureCapacity_int32_T(auxUPxR, i105);
    for (i105 = 0; i105 < jj; i105++) {
      b_Dia = rt_roundd(UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] *
        i105) - 1]);
      if (b_Dia < 2.147483648E+9) {
        if (b_Dia >= -2.147483648E+9) {
          idx = (int)b_Dia;
        } else {
          idx = MIN_int32_T;
        }
      } else {
        idx = MAX_int32_T;
      }

      auxUPxR->data[i105] = idx;
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
      i105 = 1;
      idx = 0;
    } else {
      i105 = (int)(y + 1.0);
      idx = (int)b_Dia;
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
    b_Dia = ((double)Dia->data[(*contDia + Dia->size[0] * 3) - 1] - (double)
             Dia->data[(*contDia + (Dia->size[0] << 1)) - 1]) + 1.0;
    end = x->size[0] * x->size[1];
    x->size[0] = 1;
    jj = idx - i105;
    x->size[1] = jj + 1;
    emxEnsureCapacity_boolean_T(x, end);
    for (idx = 0; idx <= jj; idx++) {
      x->data[idx] = (b_Dia - UltPosRecXDia->data[(*contDia +
        UltPosRecXDia->size[0] * ((i105 + idx) - 1)) - 1] >= TimeUsoS);
    }

    if (x->size[1] == 0) {
      j->size[1] = 0;
    } else {
      idx = 0;
      i105 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i105);
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
        i105 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i105);
      }
    }

    end = PCPrO->size[1] - 1;
    jj = 0;
    for (idx = 0; idx <= end; idx++) {
      if (PCPrO->data[idx] == 1) {
        jj++;
      }
    }

    i105 = r18->size[0] * r18->size[1];
    r18->size[0] = 1;
    r18->size[1] = jj;
    emxEnsureCapacity_int32_T(r18, i105);
    jj = 0;
    for (idx = 0; idx <= end; idx++) {
      if (PCPrO->data[idx] == 1) {
        r18->data[jj] = idx + 1;
        jj++;
      }
    }

    i105 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = r18->size[1];
    emxEnsureCapacity_boolean_T(x, i105);
    jj = r18->size[0] * r18->size[1];
    for (i105 = 0; i105 < jj; i105++) {
      x->data[i105] = (qY >= auxUPxR->data[r18->data[i105] - 1]);
    }

    if ((f_sum(x) != 0.0) && (j->size[1] != 0)) {
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
  i105 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = auxUPxR->size[1];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i105);
  jj = auxUPxR->size[0] * auxUPxR->size[1];
  for (i105 = 0; i105 < jj; i105++) {
    tempUltPosRecXDia->data[i105] = auxUPxR->data[i105];
  }

  emxFree_int32_T(&j);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&r18);
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
  int i95;
  int loop_ub;
  emxArray_int32_T *r16;
  emxArray_boolean_T *x;
  emxArray_int32_T *j;
  int exitg1;
  int jj;
  int idx;
  int qY;
  double y;
  double d33;
  int b_loop_ub;
  boolean_T exitg2;

  /*  NumCPrO: Numero de camas PreOperatorias. */
  /*  PCPrO: Posibles camas PreOperatorias para esa operacion. */
  /*  Dia: Matriz con el cosecutivo de dias y el dia de la semana. Ademas tiene */
  /*  los indices donde empieza y termina cada dia de la matriz Data(Ver main_UCI). */
  /*  UltPosRecXDia: Ultima posicion asignado del recurso por Dia. */
  /*  Time: El tiempo de uso de la Cama PrO mas el tiempo de operacion. */
  /*  contDia: Contador de dia. */
  i95 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = NumRec[0];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i95);
  loop_ub = NumRec[0];
  for (i95 = 0; i95 < loop_ub; i95++) {
    tempUltPosRecXDia->data[i95] = 0;
  }

  emxInit_int32_T(&r16, 2);
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
    d33 = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
    if (y + 1.0 > d33) {
      i95 = 1;
      jj = 0;
    } else {
      i95 = (int)(y + 1.0);
      jj = (int)d33;
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
    y = ((double)Dia->data[(*contDia + Dia->size[0] * 3) - 1] - (double)
         Dia->data[(*contDia + (Dia->size[0] << 1)) - 1]) + 1.0;
    idx = x->size[0] * x->size[1];
    x->size[0] = 1;
    b_loop_ub = jj - i95;
    x->size[1] = b_loop_ub + 1;
    emxEnsureCapacity_boolean_T(x, idx);
    for (jj = 0; jj <= b_loop_ub; jj++) {
      d33 = y - (double)UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] *
        ((i95 + jj) - 1)) - 1];
      if (d33 < 2.147483648E+9) {
        if (d33 >= -2.147483648E+9) {
          idx = (int)d33;
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
      i95 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i95);
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
        i95 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i95);
      }
    }

    b_loop_ub = PCPrO->size[1] - 1;
    jj = 0;
    for (idx = 0; idx <= b_loop_ub; idx++) {
      if (PCPrO->data[idx] == 1) {
        jj++;
      }
    }

    i95 = r16->size[0] * r16->size[1];
    r16->size[0] = 1;
    r16->size[1] = jj;
    emxEnsureCapacity_int32_T(r16, i95);
    jj = 0;
    for (idx = 0; idx <= b_loop_ub; idx++) {
      if (PCPrO->data[idx] == 1) {
        r16->data[jj] = idx + 1;
        jj++;
      }
    }

    i95 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = r16->size[1];
    emxEnsureCapacity_boolean_T(x, i95);
    b_loop_ub = r16->size[1];
    for (i95 = 0; i95 < b_loop_ub; i95++) {
      x->data[i95] = (qY >= UltPosRecXDia->data[(*contDia + UltPosRecXDia->size
        [0] * (r16->data[i95] - 1)) - 1]);
    }

    if ((f_sum(x) != 0.0) && (j->size[1] != 0)) {
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
  i95 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i95);
  for (i95 = 0; i95 < loop_ub; i95++) {
    tempUltPosRecXDia->data[i95] = UltPosRecXDia->data[(*contDia +
      UltPosRecXDia->size[0] * i95) - 1];
  }

  emxFree_int32_T(&j);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&r16);
  i95 = DispME->size[0] * DispME->size[1];
  DispME->size[0] = 1;
  DispME->size[1] = DispMExD->size[1];
  emxEnsureCapacity_int32_T(DispME, i95);
  loop_ub = DispMExD->size[1];
  for (i95 = 0; i95 < loop_ub; i95++) {
    DispME->data[i95] = 0;
  }

  switch (Dia->data[(*contDia + Dia->size[0]) - 1]) {
   case 2:
    loop_ub = DispMExD->size[1];
    i95 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i95);
    for (i95 = 0; i95 < loop_ub; i95++) {
      DispME->data[i95] = DispMExD->data[6 * i95];
    }
    break;

   case 3:
    loop_ub = DispMExD->size[1];
    i95 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i95);
    for (i95 = 0; i95 < loop_ub; i95++) {
      DispME->data[i95] = DispMExD->data[1 + 6 * i95];
    }
    break;

   case 4:
    loop_ub = DispMExD->size[1];
    i95 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i95);
    for (i95 = 0; i95 < loop_ub; i95++) {
      DispME->data[i95] = DispMExD->data[2 + 6 * i95];
    }
    break;

   case 5:
    loop_ub = DispMExD->size[1];
    i95 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i95);
    for (i95 = 0; i95 < loop_ub; i95++) {
      DispME->data[i95] = DispMExD->data[3 + 6 * i95];
    }
    break;

   case 6:
    loop_ub = DispMExD->size[1];
    i95 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i95);
    for (i95 = 0; i95 < loop_ub; i95++) {
      DispME->data[i95] = DispMExD->data[4 + 6 * i95];
    }
    break;

   case 7:
    loop_ub = DispMExD->size[1];
    i95 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i95);
    for (i95 = 0; i95 < loop_ub; i95++) {
      DispME->data[i95] = DispMExD->data[5 + 6 * i95];
    }
    break;
  }
}

/* End of code generation (funcionDia.c) */
