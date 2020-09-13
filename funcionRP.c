/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * funcionRP.c
 *
 * Code generation for function 'funcionRP'
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
#include "sort1.h"
#include "sum.h"

/* Function Definitions */
void funcionRP(emxArray_int32_T *CPrOA, int *IniCPrOA, int *EndCPrOA, int
               *EndCPrOAxD, emxArray_int32_T *SA, int *IniSA, int *EndSA,
               emxArray_int32_T *CPOA, int *IniCPOA, int *EndCPOA,
               emxArray_int32_T *CRA, int *IniCRA, int *EndCRA, const int
               NumRec[7], const emxArray_int32_T *PCPrO, const emxArray_int32_T *
               PME, const emxArray_int32_T *PMA, const emxArray_int32_T *PMAn,
               const emxArray_int32_T *PS, const emxArray_int32_T *PCPO, const
               emxArray_int32_T *PCR, const emxArray_real_T *H, const
               emxArray_int32_T *Dia, const emxArray_int32_T *UltPosRecXDia, int
               TimeUsoCPrO, int TimeUsoS, int TimeUsoCPO, int TimeUsoCR, int
               *contDia, const emxArray_int32_T *tempUltPosRecXDia, const
               emxArray_int32_T *DispMExD, const emxArray_int32_T *DispME,
               emxArray_int32_T *EA, emxArray_int32_T *AA, emxArray_int32_T *AnA,
               int *EndRPxD)
{
  int i96;
  emxArray_int32_T *sortA;
  emxArray_int32_T *AnDisp;
  emxArray_int32_T *allAn;
  emxArray_int32_T *An;
  emxArray_boolean_T *x;
  emxArray_int32_T *j;
  emxArray_int32_T *iidx;
  emxArray_int32_T *b_DispME;
  double y;
  double d34;
  int exitg1;
  int loop_ub;
  int i97;
  int idx;
  int jj;
  boolean_T exitg2;
  int b_CRA;
  emxArray_int32_T *ADisp;

  /*  funcionRP: Funcion recursos paralelos. */
  /*  Asigna los recursos paralelos a utilizar en la Operacion (ME,MA,MAN,S). */
  i96 = EA->size[0] * EA->size[1];
  EA->size[0] = 1;
  EA->size[1] = 1;
  emxEnsureCapacity_int32_T(EA, i96);
  EA->data[0] = 0;
  i96 = SA->size[0] * SA->size[1];
  SA->size[0] = 1;
  SA->size[1] = 1;
  emxEnsureCapacity_int32_T(SA, i96);
  SA->data[0] = 0;
  emxInit_int32_T(&sortA, 2);
  emxInit_int32_T(&AnDisp, 2);
  emxInit_int32_T(&allAn, 2);
  emxInit_int32_T(&An, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&j, 2);
  emxInit_int32_T(&iidx, 2);
  emxInit_int32_T(&b_DispME, 2);
  y = e_sum(*(int (*)[3])&NumRec[0]) + 1.0;
  d34 = g_sum(*(int (*)[4])&NumRec[0]);
  if (y > d34) {
    i96 = -1;
  } else {
    i96 = (int)y - 2;
  }

  do {
    exitg1 = 0;

    /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los A. */
    if (1 > PMA->size[1] - 1) {
      loop_ub = 0;
    } else {
      loop_ub = PMA->size[1] - 1;
    }

    i97 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = loop_ub;
    emxEnsureCapacity_boolean_T(x, i97);
    for (i97 = 0; i97 < loop_ub; i97++) {
      x->data[i97] = (PMA->data[i97] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      idx = 0;
      i97 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i97);
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
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > idx) {
        j->size[1] = 0;
      } else {
        i97 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i97);
      }
    }

    i97 = sortA->size[0] * sortA->size[1];
    sortA->size[0] = 1;
    sortA->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(sortA, i97);
    loop_ub = j->size[0] * j->size[1];
    for (i97 = 0; i97 < loop_ub; i97++) {
      sortA->data[i97] = j->data[i97];
    }

    /*  Busco los posibles Asistentes a usar. */
    i97 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = sortA->size[1];
    emxEnsureCapacity_boolean_T(x, i97);
    loop_ub = sortA->size[1];
    for (i97 = 0; i97 < loop_ub; i97++) {
      x->data[i97] = (UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] *
        (i96 + sortA->data[i97])) - 1] <= *EndCPrOAxD);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      idx = 0;
      i97 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i97);
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
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > idx) {
        j->size[1] = 0;
      } else {
        i97 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i97);
      }
    }

    i97 = AnDisp->size[0] * AnDisp->size[1];
    AnDisp->size[0] = 1;
    AnDisp->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(AnDisp, i97);
    loop_ub = j->size[0] * j->size[1];
    for (i97 = 0; i97 < loop_ub; i97++) {
      AnDisp->data[i97] = j->data[i97];
    }

    /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
    y = (((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) + (double)
      NumRec[3];
    if (y + 1.0 > ((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2])
                   + (double)NumRec[3]) + (double)NumRec[4]) {
      i97 = -1;
    } else {
      i97 = (int)(y + 1.0) - 2;
    }

    /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los An. */
    if (1 > PMAn->size[1] - 1) {
      loop_ub = 0;
    } else {
      loop_ub = PMAn->size[1] - 1;
    }

    b_CRA = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = loop_ub;
    emxEnsureCapacity_boolean_T(x, b_CRA);
    for (b_CRA = 0; b_CRA < loop_ub; b_CRA++) {
      x->data[b_CRA] = (PMAn->data[b_CRA] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      idx = 0;
      b_CRA = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, b_CRA);
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
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > idx) {
        j->size[1] = 0;
      } else {
        b_CRA = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, b_CRA);
      }
    }

    b_CRA = allAn->size[0] * allAn->size[1];
    allAn->size[0] = 1;
    allAn->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(allAn, b_CRA);
    loop_ub = j->size[0] * j->size[1];
    for (b_CRA = 0; b_CRA < loop_ub; b_CRA++) {
      allAn->data[b_CRA] = j->data[b_CRA];
    }

    /*  Busco los posibles Anestesistas a usar. */
    b_CRA = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = allAn->size[1];
    emxEnsureCapacity_boolean_T(x, b_CRA);
    loop_ub = allAn->size[1];
    for (b_CRA = 0; b_CRA < loop_ub; b_CRA++) {
      x->data[b_CRA] = (UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] *
        (i97 + allAn->data[b_CRA])) - 1] <= *EndCPrOAxD);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      idx = 0;
      b_CRA = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, b_CRA);
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
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > idx) {
        j->size[1] = 0;
      } else {
        b_CRA = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, b_CRA);
      }
    }

    b_CRA = An->size[0] * An->size[1];
    An->size[0] = 1;
    An->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(An, b_CRA);
    loop_ub = j->size[0] * j->size[1];
    for (b_CRA = 0; b_CRA < loop_ub; b_CRA++) {
      An->data[b_CRA] = j->data[b_CRA];
    }

    /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
    if ((AnDisp->size[1] < PMA->data[PMA->size[1] - 1]) || (An->size[1] <
         PMAn->data[PMAn->size[1] - 1])) {
      i97 = iidx->size[0] * iidx->size[1];
      iidx->size[0] = 1;
      iidx->size[1] = tempUltPosRecXDia->size[1];
      emxEnsureCapacity_int32_T(iidx, i97);
      loop_ub = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
      for (i97 = 0; i97 < loop_ub; i97++) {
        iidx->data[i97] = tempUltPosRecXDia->data[i97];
      }

      i97 = b_DispME->size[0] * b_DispME->size[1];
      b_DispME->size[0] = 1;
      b_DispME->size[1] = DispME->size[1];
      emxEnsureCapacity_int32_T(b_DispME, i97);
      loop_ub = DispME->size[0] * DispME->size[1];
      for (i97 = 0; i97 < loop_ub; i97++) {
        b_DispME->data[i97] = DispME->data[i97];
      }

      d_funcionCPrO(NumRec, PCPrO, PME, PMA, PMAn, PS, PCPO, PCR, H, Dia,
                    UltPosRecXDia, TimeUsoCPrO, TimeUsoS, TimeUsoCPO, TimeUsoCR,
                    contDia, iidx, DispMExD, b_DispME, &idx, IniCPrOA, EndCPrOA,
                    EndCPrOAxD, EA, AA, AnA, SA, IniSA, EndSA, &jj, &loop_ub,
                    IniCPOA, EndCPOA, &b_CRA, IniCRA, EndCRA);
      i97 = CPrOA->size[0] * CPrOA->size[1];
      CPrOA->size[0] = 1;
      CPrOA->size[1] = 1;
      emxEnsureCapacity_int32_T(CPrOA, i97);
      CPrOA->data[0] = idx;
      i97 = CPOA->size[0] * CPOA->size[1];
      CPOA->size[0] = 1;
      CPOA->size[1] = 1;
      emxEnsureCapacity_int32_T(CPOA, i97);
      CPOA->data[0] = loop_ub;
      i97 = CRA->size[0] * CRA->size[1];
      CRA->size[0] = 1;
      CRA->size[1] = 1;
      emxEnsureCapacity_int32_T(CRA, i97);
      CRA->data[0] = b_CRA;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  emxFree_int32_T(&b_DispME);
  emxFree_boolean_T(&x);
  emxInit_int32_T(&ADisp, 2);
  b_CRA = ADisp->size[0] * ADisp->size[1];
  ADisp->size[0] = 1;
  ADisp->size[1] = AnDisp->size[1];
  emxEnsureCapacity_int32_T(ADisp, b_CRA);
  loop_ub = AnDisp->size[0] * AnDisp->size[1];
  for (b_CRA = 0; b_CRA < loop_ub; b_CRA++) {
    ADisp->data[b_CRA] = sortA->data[AnDisp->data[b_CRA] - 1];
  }

  b_CRA = j->size[0] * j->size[1];
  j->size[0] = 1;
  j->size[1] = ADisp->size[1];
  emxEnsureCapacity_int32_T(j, b_CRA);
  loop_ub = ADisp->size[1];
  for (b_CRA = 0; b_CRA < loop_ub; b_CRA++) {
    jj = *EndCPrOAxD;
    idx = UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] * (i96 +
      ADisp->data[b_CRA])) - 1];
    if ((jj >= 0) && (idx < jj - MAX_int32_T)) {
      jj = MAX_int32_T;
    } else if ((jj < 0) && (idx > jj - MIN_int32_T)) {
      jj = MIN_int32_T;
    } else {
      jj -= idx;
    }

    j->data[b_CRA] = jj;
  }

  d_sort(j, iidx);
  i96 = sortA->size[0] * sortA->size[1];
  sortA->size[0] = 1;
  sortA->size[1] = iidx->size[1];
  emxEnsureCapacity_int32_T(sortA, i96);
  loop_ub = iidx->size[0] * iidx->size[1];
  for (i96 = 0; i96 < loop_ub; i96++) {
    sortA->data[i96] = ADisp->data[iidx->data[i96] - 1];
  }

  emxFree_int32_T(&ADisp);
  if (1 > PMA->data[PMA->size[1] - 1]) {
    loop_ub = 0;
  } else {
    loop_ub = PMA->data[PMA->size[1] - 1];
  }

  i96 = AA->size[0] * AA->size[1];
  AA->size[0] = 1;
  AA->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(AA, i96);
  for (i96 = 0; i96 < loop_ub; i96++) {
    AA->data[i96] = sortA->data[i96];
  }

  i96 = AnDisp->size[0] * AnDisp->size[1];
  AnDisp->size[0] = 1;
  AnDisp->size[1] = An->size[1];
  emxEnsureCapacity_int32_T(AnDisp, i96);
  loop_ub = An->size[0] * An->size[1];
  for (i96 = 0; i96 < loop_ub; i96++) {
    AnDisp->data[i96] = allAn->data[An->data[i96] - 1];
  }

  emxFree_int32_T(&An);
  emxFree_int32_T(&allAn);
  i96 = j->size[0] * j->size[1];
  j->size[0] = 1;
  j->size[1] = AnDisp->size[1];
  emxEnsureCapacity_int32_T(j, i96);
  loop_ub = AnDisp->size[1];
  for (i96 = 0; i96 < loop_ub; i96++) {
    jj = *EndCPrOAxD;
    idx = UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] * (i97 +
      AnDisp->data[i96])) - 1];
    if ((jj >= 0) && (idx < jj - MAX_int32_T)) {
      jj = MAX_int32_T;
    } else if ((jj < 0) && (idx > jj - MIN_int32_T)) {
      jj = MIN_int32_T;
    } else {
      jj -= idx;
    }

    j->data[i96] = jj;
  }

  d_sort(j, iidx);
  i96 = sortA->size[0] * sortA->size[1];
  sortA->size[0] = 1;
  sortA->size[1] = iidx->size[1];
  emxEnsureCapacity_int32_T(sortA, i96);
  loop_ub = iidx->size[0] * iidx->size[1];
  emxFree_int32_T(&j);
  for (i96 = 0; i96 < loop_ub; i96++) {
    sortA->data[i96] = AnDisp->data[iidx->data[i96] - 1];
  }

  emxFree_int32_T(&iidx);
  emxFree_int32_T(&AnDisp);
  if (1 > PME->data[PME->size[1] - 1]) {
    loop_ub = 0;
  } else {
    loop_ub = PME->data[PME->size[1] - 1];
  }

  i96 = AnA->size[0] * AnA->size[1];
  AnA->size[0] = 1;
  AnA->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(AnA, i96);
  for (i96 = 0; i96 < loop_ub; i96++) {
    AnA->data[i96] = sortA->data[i96];
  }

  emxFree_int32_T(&sortA);
  jj = *EndCPrOAxD;
  if ((jj < 0) && (TimeUsoS < MIN_int32_T - jj)) {
    jj = MIN_int32_T;
  } else if ((jj > 0) && (TimeUsoS > MAX_int32_T - jj)) {
    jj = MAX_int32_T;
  } else {
    jj += TimeUsoS;
  }

  *EndRPxD = jj;
}

/* End of code generation (funcionRP.c) */
