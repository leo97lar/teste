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
#include "main_UCI_func.h"
#include "funcionDia.h"
#include "model_emxutil.h"
#include "sum.h"
#include "obsIQini.h"
#include "model_rtwutil.h"

/* Function Definitions */
void b_funcionDia(const int NumRec[7], const emxArray_int32_T *PCPrO, const
                  emxArray_int32_T *Dia, const emxArray_real_T *UltPosRecXDia,
                  int TimeUsoCPrO, int TimeUsoS, int *contDia, const
                  emxArray_int32_T *DispMExD, emxArray_int32_T
                  *tempUltPosRecXDia, emxArray_int32_T *DispME)
{
  int i52;
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
  i52 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = NumRec[0];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i52);
  jj = NumRec[0];
  for (i52 = 0; i52 < jj; i52++) {
    tempUltPosRecXDia->data[i52] = 0;
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

    i52 = auxUPxR->size[0] * auxUPxR->size[1];
    auxUPxR->size[0] = 1;
    auxUPxR->size[1] = jj;
    emxEnsureCapacity_int32_T(auxUPxR, i52);
    for (i52 = 0; i52 < jj; i52++) {
      b_Dia = rt_roundd(UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] *
        i52) - 1]);
      if (b_Dia < 2.147483648E+9) {
        if (b_Dia >= -2.147483648E+9) {
          idx = (int)b_Dia;
        } else {
          idx = MIN_int32_T;
        }
      } else {
        idx = MAX_int32_T;
      }

      auxUPxR->data[i52] = idx;
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
      i52 = 1;
      idx = 0;
    } else {
      i52 = (int)(y + 1.0);
      idx = (int)b_Dia;
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
    b_Dia = ((double)Dia->data[(*contDia + Dia->size[0] * 3) - 1] - (double)
             Dia->data[(*contDia + (Dia->size[0] << 1)) - 1]) + 1.0;
    end = x->size[0] * x->size[1];
    x->size[0] = 1;
    jj = idx - i52;
    x->size[1] = jj + 1;
    emxEnsureCapacity_boolean_T(x, end);
    for (idx = 0; idx <= jj; idx++) {
      x->data[idx] = (b_Dia - UltPosRecXDia->data[(*contDia +
        UltPosRecXDia->size[0] * ((i52 + idx) - 1)) - 1] >= TimeUsoS);
    }

    if (x->size[1] == 0) {
      j->size[1] = 0;
    } else {
      idx = 0;
      i52 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i52);
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
        i52 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i52);
      }
    }

    end = PCPrO->size[1] - 1;
    jj = 0;
    for (idx = 0; idx <= end; idx++) {
      if (PCPrO->data[idx] == 1) {
        jj++;
      }
    }

    i52 = r11->size[0] * r11->size[1];
    r11->size[0] = 1;
    r11->size[1] = jj;
    emxEnsureCapacity_int32_T(r11, i52);
    jj = 0;
    for (idx = 0; idx <= end; idx++) {
      if (PCPrO->data[idx] == 1) {
        r11->data[jj] = idx + 1;
        jj++;
      }
    }

    i52 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = r11->size[1];
    emxEnsureCapacity_boolean_T(x, i52);
    jj = r11->size[0] * r11->size[1];
    for (i52 = 0; i52 < jj; i52++) {
      x->data[i52] = (qY >= auxUPxR->data[r11->data[i52] - 1]);
    }

    if ((g_sum(x) != 0.0) && (j->size[1] != 0)) {
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
  i52 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = auxUPxR->size[1];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i52);
  jj = auxUPxR->size[0] * auxUPxR->size[1];
  for (i52 = 0; i52 < jj; i52++) {
    tempUltPosRecXDia->data[i52] = auxUPxR->data[i52];
  }

  emxFree_int32_T(&j);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&r11);
  emxFree_int32_T(&auxUPxR);
  i52 = DispME->size[0] * DispME->size[1];
  DispME->size[0] = 1;
  DispME->size[1] = DispMExD->size[1];
  emxEnsureCapacity_int32_T(DispME, i52);
  jj = DispMExD->size[1];
  for (i52 = 0; i52 < jj; i52++) {
    DispME->data[i52] = 0;
  }

  switch (Dia->data[(*contDia + Dia->size[0]) - 1]) {
   case 2:
    jj = DispMExD->size[1];
    i52 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i52);
    for (i52 = 0; i52 < jj; i52++) {
      DispME->data[i52] = DispMExD->data[6 * i52];
    }
    break;

   case 3:
    jj = DispMExD->size[1];
    i52 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i52);
    for (i52 = 0; i52 < jj; i52++) {
      DispME->data[i52] = DispMExD->data[1 + 6 * i52];
    }
    break;

   case 4:
    jj = DispMExD->size[1];
    i52 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i52);
    for (i52 = 0; i52 < jj; i52++) {
      DispME->data[i52] = DispMExD->data[2 + 6 * i52];
    }
    break;

   case 5:
    jj = DispMExD->size[1];
    i52 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i52);
    for (i52 = 0; i52 < jj; i52++) {
      DispME->data[i52] = DispMExD->data[3 + 6 * i52];
    }
    break;

   case 6:
    jj = DispMExD->size[1];
    i52 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i52);
    for (i52 = 0; i52 < jj; i52++) {
      DispME->data[i52] = DispMExD->data[4 + 6 * i52];
    }
    break;

   case 7:
    jj = DispMExD->size[1];
    i52 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = jj;
    emxEnsureCapacity_int32_T(DispME, i52);
    for (i52 = 0; i52 < jj; i52++) {
      DispME->data[i52] = DispMExD->data[5 + 6 * i52];
    }
    break;
  }
}

void funcionDia(const int NumRec[7], const emxArray_int32_T *PCPrO, const
                emxArray_int32_T *Dia, const emxArray_int32_T *UltPosRecXDia,
                int TimeUsoCPrO, int TimeUsoS, int *contDia, const
                emxArray_int32_T *DispMExD, emxArray_int32_T *tempUltPosRecXDia,
                emxArray_int32_T *DispME)
{
  int i46;
  int loop_ub;
  emxArray_int32_T *r9;
  emxArray_boolean_T *x;
  emxArray_int32_T *j;
  int exitg1;
  int jj;
  int idx;
  int qY;
  double y;
  double d12;
  int b_loop_ub;
  boolean_T exitg2;

  /*  NumCPrO: Numero de camas PreOperatorias. */
  /*  PCPrO: Posibles camas PreOperatorias para esa operacion. */
  /*  Dia: Matriz con el cosecutivo de dias y el dia de la semana. Ademas tiene */
  /*  los indices donde empieza y termina cada dia de la matriz Data(Ver main_UCI). */
  /*  UltPosRecXDia: Ultima posicion asignado del recurso por Dia. */
  /*  Time: El tiempo de uso de la Cama PrO mas el tiempo de operacion. */
  /*  contDia: Contador de dia. */
  i46 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = NumRec[0];
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i46);
  loop_ub = NumRec[0];
  for (i46 = 0; i46 < loop_ub; i46++) {
    tempUltPosRecXDia->data[i46] = 0;
  }

  emxInit_int32_T(&r9, 2);
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
    d12 = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
    if (y + 1.0 > d12) {
      i46 = 1;
      jj = 0;
    } else {
      i46 = (int)(y + 1.0);
      jj = (int)d12;
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
    y = ((double)Dia->data[(*contDia + Dia->size[0] * 3) - 1] - (double)
         Dia->data[(*contDia + (Dia->size[0] << 1)) - 1]) + 1.0;
    idx = x->size[0] * x->size[1];
    x->size[0] = 1;
    b_loop_ub = jj - i46;
    x->size[1] = b_loop_ub + 1;
    emxEnsureCapacity_boolean_T(x, idx);
    for (jj = 0; jj <= b_loop_ub; jj++) {
      d12 = y - (double)UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] *
        ((i46 + jj) - 1)) - 1];
      if (d12 < 2.147483648E+9) {
        if (d12 >= -2.147483648E+9) {
          idx = (int)d12;
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
      i46 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i46);
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
        i46 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i46);
      }
    }

    b_loop_ub = PCPrO->size[1] - 1;
    jj = 0;
    for (idx = 0; idx <= b_loop_ub; idx++) {
      if (PCPrO->data[idx] == 1) {
        jj++;
      }
    }

    i46 = r9->size[0] * r9->size[1];
    r9->size[0] = 1;
    r9->size[1] = jj;
    emxEnsureCapacity_int32_T(r9, i46);
    jj = 0;
    for (idx = 0; idx <= b_loop_ub; idx++) {
      if (PCPrO->data[idx] == 1) {
        r9->data[jj] = idx + 1;
        jj++;
      }
    }

    i46 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = r9->size[1];
    emxEnsureCapacity_boolean_T(x, i46);
    b_loop_ub = r9->size[1];
    for (i46 = 0; i46 < b_loop_ub; i46++) {
      x->data[i46] = (qY >= UltPosRecXDia->data[(*contDia + UltPosRecXDia->size
        [0] * (r9->data[i46] - 1)) - 1]);
    }

    if ((g_sum(x) != 0.0) && (j->size[1] != 0)) {
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
  i46 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
  tempUltPosRecXDia->size[0] = 1;
  tempUltPosRecXDia->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(tempUltPosRecXDia, i46);
  for (i46 = 0; i46 < loop_ub; i46++) {
    tempUltPosRecXDia->data[i46] = UltPosRecXDia->data[(*contDia +
      UltPosRecXDia->size[0] * i46) - 1];
  }

  emxFree_int32_T(&j);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&r9);
  i46 = DispME->size[0] * DispME->size[1];
  DispME->size[0] = 1;
  DispME->size[1] = DispMExD->size[1];
  emxEnsureCapacity_int32_T(DispME, i46);
  loop_ub = DispMExD->size[1];
  for (i46 = 0; i46 < loop_ub; i46++) {
    DispME->data[i46] = 0;
  }

  switch (Dia->data[(*contDia + Dia->size[0]) - 1]) {
   case 2:
    loop_ub = DispMExD->size[1];
    i46 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i46);
    for (i46 = 0; i46 < loop_ub; i46++) {
      DispME->data[i46] = DispMExD->data[6 * i46];
    }
    break;

   case 3:
    loop_ub = DispMExD->size[1];
    i46 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i46);
    for (i46 = 0; i46 < loop_ub; i46++) {
      DispME->data[i46] = DispMExD->data[1 + 6 * i46];
    }
    break;

   case 4:
    loop_ub = DispMExD->size[1];
    i46 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i46);
    for (i46 = 0; i46 < loop_ub; i46++) {
      DispME->data[i46] = DispMExD->data[2 + 6 * i46];
    }
    break;

   case 5:
    loop_ub = DispMExD->size[1];
    i46 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i46);
    for (i46 = 0; i46 < loop_ub; i46++) {
      DispME->data[i46] = DispMExD->data[3 + 6 * i46];
    }
    break;

   case 6:
    loop_ub = DispMExD->size[1];
    i46 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i46);
    for (i46 = 0; i46 < loop_ub; i46++) {
      DispME->data[i46] = DispMExD->data[4 + 6 * i46];
    }
    break;

   case 7:
    loop_ub = DispMExD->size[1];
    i46 = DispME->size[0] * DispME->size[1];
    DispME->size[0] = 1;
    DispME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(DispME, i46);
    for (i46 = 0; i46 < loop_ub; i46++) {
      DispME->data[i46] = DispMExD->data[5 + 6 * i46];
    }
    break;
  }
}

/* End of code generation (funcionDia.c) */
