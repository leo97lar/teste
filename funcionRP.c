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
  int i88;
  emxArray_int32_T *sortA;
  emxArray_int32_T *AnDisp;
  emxArray_int32_T *allAn;
  emxArray_int32_T *An;
  emxArray_boolean_T *x;
  emxArray_int32_T *j;
  emxArray_int32_T *iidx;
  emxArray_int32_T *b_DispME;
  double y;
  double d30;
  int exitg1;
  int loop_ub;
  int i89;
  int idx;
  int jj;
  boolean_T exitg2;
  int b_CRA;
  emxArray_int32_T *ADisp;

  /*  funcionRP: Funcion recursos paralelos. */
  /*  Asigna los recursos paralelos a utilizar en la Operacion (ME,MA,MAN,S). */
  i88 = EA->size[0] * EA->size[1];
  EA->size[0] = 1;
  EA->size[1] = 1;
  emxEnsureCapacity_int32_T(EA, i88);
  EA->data[0] = 0;
  i88 = SA->size[0] * SA->size[1];
  SA->size[0] = 1;
  SA->size[1] = 1;
  emxEnsureCapacity_int32_T(SA, i88);
  SA->data[0] = 0;
  emxInit_int32_T(&sortA, 2);
  emxInit_int32_T(&AnDisp, 2);
  emxInit_int32_T(&allAn, 2);
  emxInit_int32_T(&An, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&j, 2);
  emxInit_int32_T(&iidx, 2);
  emxInit_int32_T(&b_DispME, 2);
  y = d_sum(*(int (*)[3])&NumRec[0]) + 1.0;
  d30 = f_sum(*(int (*)[4])&NumRec[0]);
  if (y > d30) {
    i88 = -1;
  } else {
    i88 = (int)y - 2;
  }

  do {
    exitg1 = 0;

    /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los A. */
    if (1 > PMA->size[1] - 1) {
      loop_ub = 0;
    } else {
      loop_ub = PMA->size[1] - 1;
    }

    i89 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = loop_ub;
    emxEnsureCapacity_boolean_T(x, i89);
    for (i89 = 0; i89 < loop_ub; i89++) {
      x->data[i89] = (PMA->data[i89] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      idx = 0;
      i89 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i89);
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
        i89 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i89);
      }
    }

    i89 = sortA->size[0] * sortA->size[1];
    sortA->size[0] = 1;
    sortA->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(sortA, i89);
    loop_ub = j->size[0] * j->size[1];
    for (i89 = 0; i89 < loop_ub; i89++) {
      sortA->data[i89] = j->data[i89];
    }

    /*  Busco los posibles Asistentes a usar. */
    i89 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = sortA->size[1];
    emxEnsureCapacity_boolean_T(x, i89);
    loop_ub = sortA->size[1];
    for (i89 = 0; i89 < loop_ub; i89++) {
      x->data[i89] = (UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] *
        (i88 + sortA->data[i89])) - 1] <= *EndCPrOAxD);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      idx = 0;
      i89 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i89);
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
        i89 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i89);
      }
    }

    i89 = AnDisp->size[0] * AnDisp->size[1];
    AnDisp->size[0] = 1;
    AnDisp->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(AnDisp, i89);
    loop_ub = j->size[0] * j->size[1];
    for (i89 = 0; i89 < loop_ub; i89++) {
      AnDisp->data[i89] = j->data[i89];
    }

    /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
    y = (((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) + (double)
      NumRec[3];
    if (y + 1.0 > ((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2])
                   + (double)NumRec[3]) + (double)NumRec[4]) {
      i89 = -1;
    } else {
      i89 = (int)(y + 1.0) - 2;
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
        (i89 + allAn->data[b_CRA])) - 1] <= *EndCPrOAxD);
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
      i89 = iidx->size[0] * iidx->size[1];
      iidx->size[0] = 1;
      iidx->size[1] = tempUltPosRecXDia->size[1];
      emxEnsureCapacity_int32_T(iidx, i89);
      loop_ub = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
      for (i89 = 0; i89 < loop_ub; i89++) {
        iidx->data[i89] = tempUltPosRecXDia->data[i89];
      }

      i89 = b_DispME->size[0] * b_DispME->size[1];
      b_DispME->size[0] = 1;
      b_DispME->size[1] = DispME->size[1];
      emxEnsureCapacity_int32_T(b_DispME, i89);
      loop_ub = DispME->size[0] * DispME->size[1];
      for (i89 = 0; i89 < loop_ub; i89++) {
        b_DispME->data[i89] = DispME->data[i89];
      }

      d_funcionCPrO(NumRec, PCPrO, PME, PMA, PMAn, PS, PCPO, PCR, H, Dia,
                    UltPosRecXDia, TimeUsoCPrO, TimeUsoS, TimeUsoCPO, TimeUsoCR,
                    contDia, iidx, DispMExD, b_DispME, &idx, IniCPrOA, EndCPrOA,
                    EndCPrOAxD, EA, AA, AnA, SA, IniSA, EndSA, &jj, &loop_ub,
                    IniCPOA, EndCPOA, &b_CRA, IniCRA, EndCRA);
      i89 = CPrOA->size[0] * CPrOA->size[1];
      CPrOA->size[0] = 1;
      CPrOA->size[1] = 1;
      emxEnsureCapacity_int32_T(CPrOA, i89);
      CPrOA->data[0] = idx;
      i89 = CPOA->size[0] * CPOA->size[1];
      CPOA->size[0] = 1;
      CPOA->size[1] = 1;
      emxEnsureCapacity_int32_T(CPOA, i89);
      CPOA->data[0] = loop_ub;
      i89 = CRA->size[0] * CRA->size[1];
      CRA->size[0] = 1;
      CRA->size[1] = 1;
      emxEnsureCapacity_int32_T(CRA, i89);
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
    idx = UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] * (i88 +
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
  i88 = sortA->size[0] * sortA->size[1];
  sortA->size[0] = 1;
  sortA->size[1] = iidx->size[1];
  emxEnsureCapacity_int32_T(sortA, i88);
  loop_ub = iidx->size[0] * iidx->size[1];
  for (i88 = 0; i88 < loop_ub; i88++) {
    sortA->data[i88] = ADisp->data[iidx->data[i88] - 1];
  }

  emxFree_int32_T(&ADisp);
  if (1 > PMA->data[PMA->size[1] - 1]) {
    loop_ub = 0;
  } else {
    loop_ub = PMA->data[PMA->size[1] - 1];
  }

  i88 = AA->size[0] * AA->size[1];
  AA->size[0] = 1;
  AA->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(AA, i88);
  for (i88 = 0; i88 < loop_ub; i88++) {
    AA->data[i88] = sortA->data[i88];
  }

  i88 = AnDisp->size[0] * AnDisp->size[1];
  AnDisp->size[0] = 1;
  AnDisp->size[1] = An->size[1];
  emxEnsureCapacity_int32_T(AnDisp, i88);
  loop_ub = An->size[0] * An->size[1];
  for (i88 = 0; i88 < loop_ub; i88++) {
    AnDisp->data[i88] = allAn->data[An->data[i88] - 1];
  }

  emxFree_int32_T(&An);
  emxFree_int32_T(&allAn);
  i88 = j->size[0] * j->size[1];
  j->size[0] = 1;
  j->size[1] = AnDisp->size[1];
  emxEnsureCapacity_int32_T(j, i88);
  loop_ub = AnDisp->size[1];
  for (i88 = 0; i88 < loop_ub; i88++) {
    jj = *EndCPrOAxD;
    idx = UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0] * (i89 +
      AnDisp->data[i88])) - 1];
    if ((jj >= 0) && (idx < jj - MAX_int32_T)) {
      jj = MAX_int32_T;
    } else if ((jj < 0) && (idx > jj - MIN_int32_T)) {
      jj = MIN_int32_T;
    } else {
      jj -= idx;
    }

    j->data[i88] = jj;
  }

  d_sort(j, iidx);
  i88 = sortA->size[0] * sortA->size[1];
  sortA->size[0] = 1;
  sortA->size[1] = iidx->size[1];
  emxEnsureCapacity_int32_T(sortA, i88);
  loop_ub = iidx->size[0] * iidx->size[1];
  emxFree_int32_T(&j);
  for (i88 = 0; i88 < loop_ub; i88++) {
    sortA->data[i88] = AnDisp->data[iidx->data[i88] - 1];
  }

  emxFree_int32_T(&iidx);
  emxFree_int32_T(&AnDisp);
  if (1 > PME->data[PME->size[1] - 1]) {
    loop_ub = 0;
  } else {
    loop_ub = PME->data[PME->size[1] - 1];
  }

  i88 = AnA->size[0] * AnA->size[1];
  AnA->size[0] = 1;
  AnA->size[1] = loop_ub;
  emxEnsureCapacity_int32_T(AnA, i88);
  for (i88 = 0; i88 < loop_ub; i88++) {
    AnA->data[i88] = sortA->data[i88];
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
