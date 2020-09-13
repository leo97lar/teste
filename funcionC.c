/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * funcionC.c
 *
 * Code generation for function 'funcionC'
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

/* Function Definitions */
void funcionC(const emxArray_int32_T *PCPO, const emxArray_int32_T *PCR, const
              emxArray_int32_T *H, const int *EndRP, int TimeUsoCPO, int
              TimeUsoCR, const emxArray_int32_T *PME, const emxArray_int32_T
              *PMA, const emxArray_int32_T *PMAn, const emxArray_int32_T *PS,
              const int *CPrOA, const int *IniCPrOA, const int *EndCPrOA, const
              int *EndCPrOAxD, const int NumRec[7], const emxArray_int32_T
              *PCPrO, const emxArray_int32_T *Dia, const emxArray_int32_T
              *UltPosRecXDia, int TimeUsoCPrO, int TimeUsoS, const int *contDia,
              const emxArray_int32_T *filCPrO, const emxArray_int32_T
              *tempUltPosRecXDia, const emxArray_int32_T *EA, const
              emxArray_int32_T *SA, const emxArray_int32_T *AA, const
              emxArray_int32_T *AnA, const int *IniRP, const int *EndRPxD, const
              emxArray_int32_T *DispMExD, const emxArray_int32_T *DispME, const
              emxArray_int32_T *uCPrODisp, double *CPOA, int *IniCPO, int
              *EndCPO, double *CRA, int *IniCR, int *EndCR)
{
  emxArray_int32_T *auxH;
  emxArray_int32_T *C;
  emxArray_int32_T *auxC;
  emxArray_int32_T *R;
  emxArray_real_T *auxR;
  emxArray_boolean_T *x;
  emxArray_int32_T *j;
  int i83;
  int loop_ub;
  int idx;
  int jj;
  boolean_T exitg1;
  int i84;
  double y;
  (void)PME;
  (void)PMA;
  (void)PMAn;
  (void)PS;
  (void)CPrOA;
  (void)IniCPrOA;
  (void)EndCPrOA;
  (void)EndCPrOAxD;
  (void)PCPrO;
  (void)Dia;
  (void)UltPosRecXDia;
  (void)TimeUsoCPrO;
  (void)TimeUsoS;
  (void)contDia;
  (void)filCPrO;
  (void)tempUltPosRecXDia;
  (void)EA;
  (void)SA;
  (void)AA;
  (void)AnA;
  (void)IniRP;
  (void)EndRPxD;
  (void)DispMExD;
  (void)DispME;
  (void)uCPrODisp;
  emxInit_int32_T(&auxH, 2);
  emxInit_int32_T(&C, 2);
  emxInit_int32_T(&auxC, 2);
  emxInit_int32_T(&R, 2);
  emxInit_real_T(&auxR, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&j, 2);
  do {
    i83 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = PCPO->size[1];
    emxEnsureCapacity_boolean_T(x, i83);
    loop_ub = PCPO->size[0] * PCPO->size[1];
    for (i83 = 0; i83 < loop_ub; i83++) {
      x->data[i83] = (PCPO->data[i83] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      idx = 0;
      i83 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i83);
      jj = 1;
      exitg1 = false;
      while ((!exitg1) && (jj <= x->size[1])) {
        if (x->data[jj - 1]) {
          idx++;
          j->data[idx - 1] = jj;
          if (idx >= x->size[1]) {
            exitg1 = true;
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
        i83 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i83);
      }
    }

    i83 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(C, i83);
    loop_ub = j->size[0] * j->size[1];
    for (i83 = 0; i83 < loop_ub; i83++) {
      C->data[i83] = j->data[i83];
    }

    /*  Posibles camas a usar */
    jj = *EndRP;
    if (jj > 2147483646) {
      *IniCPO = MAX_int32_T;
    } else {
      *IniCPO = jj + 1;
    }

    if ((jj < 0) && (TimeUsoCPO < MIN_int32_T - jj)) {
      *EndCPO = MIN_int32_T;
    } else if ((jj > 0) && (TimeUsoCPO > MAX_int32_T - jj)) {
      *EndCPO = MAX_int32_T;
    } else {
      *EndCPO = jj + TimeUsoCPO;
    }

    if (*IniCPO > *EndCPO) {
      i83 = 1;
      i84 = 0;
    } else {
      i83 = *IniCPO;
      i84 = *EndCPO;
    }

    y = ((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) + (double)
         NumRec[3]) + (double)NumRec[4];
    jj = auxH->size[0] * auxH->size[1];
    loop_ub = i84 - i83;
    auxH->size[0] = loop_ub + 1;
    auxH->size[1] = C->size[1];
    emxEnsureCapacity_int32_T(auxH, jj);
    idx = C->size[1];
    for (i84 = 0; i84 < idx; i84++) {
      for (jj = 0; jj <= loop_ub; jj++) {
        auxH->data[jj + auxH->size[0] * i84] = H->data[((i83 + jj) + H->size[0] *
          ((int)(y + (double)C->data[i84]) - 1)) - 1];
      }
    }

    n_sum(auxH, auxR);
    i83 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = auxR->size[1];
    emxEnsureCapacity_boolean_T(x, i83);
    loop_ub = auxR->size[0] * auxR->size[1];
    for (i83 = 0; i83 < loop_ub; i83++) {
      x->data[i83] = (auxR->data[i83] == 0.0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      idx = 0;
      i83 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i83);
      jj = 1;
      exitg1 = false;
      while ((!exitg1) && (jj <= x->size[1])) {
        if (x->data[jj - 1]) {
          idx++;
          j->data[idx - 1] = jj;
          if (idx >= x->size[1]) {
            exitg1 = true;
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
        i83 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i83);
      }
    }

    i83 = auxC->size[0] * auxC->size[1];
    auxC->size[0] = 1;
    auxC->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(auxC, i83);
    loop_ub = j->size[0] * j->size[1];
    for (i83 = 0; i83 < loop_ub; i83++) {
      auxC->data[i83] = j->data[i83];
    }

    i83 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = PCR->size[1];
    emxEnsureCapacity_boolean_T(x, i83);
    loop_ub = PCR->size[0] * PCR->size[1];
    for (i83 = 0; i83 < loop_ub; i83++) {
      x->data[i83] = (PCR->data[i83] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      idx = 0;
      i83 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i83);
      jj = 1;
      exitg1 = false;
      while ((!exitg1) && (jj <= x->size[1])) {
        if (x->data[jj - 1]) {
          idx++;
          j->data[idx - 1] = jj;
          if (idx >= x->size[1]) {
            exitg1 = true;
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
        i83 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i83);
      }
    }

    i83 = R->size[0] * R->size[1];
    R->size[0] = 1;
    R->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(R, i83);
    loop_ub = j->size[0] * j->size[1];
    for (i83 = 0; i83 < loop_ub; i83++) {
      R->data[i83] = j->data[i83];
    }

    /*  Posibles camas a usar */
    y = NumRec[0];
    for (jj = 0; jj < 5; jj++) {
      y += (double)NumRec[jj + 1];
    }

    i83 = auxH->size[0] * auxH->size[1];
    auxH->size[0] = TimeUsoCR;
    auxH->size[1] = R->size[1];
    emxEnsureCapacity_int32_T(auxH, i83);
    loop_ub = R->size[1];
    for (i83 = 0; i83 < loop_ub; i83++) {
      for (i84 = 0; i84 < TimeUsoCR; i84++) {
        jj = 1 + i84;
        if ((*EndCPO < 0) && (jj < MIN_int32_T - *EndCPO)) {
          jj = MIN_int32_T;
        } else if ((*EndCPO > 0) && (jj > MAX_int32_T - *EndCPO)) {
          jj = MAX_int32_T;
        } else {
          jj += *EndCPO;
        }

        auxH->data[i84 + auxH->size[0] * i83] = H->data[(jj + H->size[0] * ((int)
          (y + (double)R->data[i83]) - 1)) - 1];
      }
    }

    n_sum(auxH, auxR);
    i83 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = auxR->size[1];
    emxEnsureCapacity_boolean_T(x, i83);
    loop_ub = auxR->size[0] * auxR->size[1];
    for (i83 = 0; i83 < loop_ub; i83++) {
      x->data[i83] = (auxR->data[i83] == 0.0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      idx = 0;
      i83 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i83);
      jj = 1;
      exitg1 = false;
      while ((!exitg1) && (jj <= x->size[1])) {
        if (x->data[jj - 1]) {
          idx++;
          j->data[idx - 1] = jj;
          if (idx >= x->size[1]) {
            exitg1 = true;
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
        i83 = j->size[0] * j->size[1];
        j->size[1] = idx;
        emxEnsureCapacity_int32_T(j, i83);
      }
    }

    i83 = auxR->size[0] * auxR->size[1];
    auxR->size[0] = 1;
    auxR->size[1] = j->size[1];
    emxEnsureCapacity_real_T(auxR, i83);
    loop_ub = j->size[0] * j->size[1];
    for (i83 = 0; i83 < loop_ub; i83++) {
      auxR->data[i83] = j->data[i83];
    }

    /*             [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,AA,AnA,SA,IniSA,EndSA,EndRPxD,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,contDia ] = ... */
    /*                 funcionCPrO(NumRec,PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,H,Dia,UltPosRecXDia, ... */
    /*                 TimeUsoCPrO, TimeUsoS,TimeUsoCPO,TimeUsoCR,contDia,tempUltPosRecXDia,DispMExD,DispME); */
    /*             [ EA,SA,AA,AnA,IniRP,EndRP,EndRPxD,CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,contDia,filCPrO] = ... */
    /*                 funcionRP( CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,SA,IniSA,EndSA,CPOA,IniCPOA,EndCPOA,CRA, ... */
    /*                 IniCRA,EndCRA,NumRec,PCPrO,PME, PMA,PMAn,PS,PCPO,PCR,Dia,UltPosRecXDia,TimeUsoCPrO, ... */
    /*                 TimeUsoS,TimeUsoCPO,TimeUsoCR,contDia,tempUltPosRecXDia,uCPrODisp); */
  } while ((auxC->size[1] == 0) || (auxR->size[1] == 0));

  emxFree_int32_T(&j);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&auxH);
  *CPOA = C->data[auxC->data[0] - 1];
  *CRA = R->data[(int)auxR->data[0] - 1];
  if (*EndCPO > 2147483646) {
    *IniCR = MAX_int32_T;
  } else {
    *IniCR = *EndCPO + 1;
  }

  if ((*EndCPO < 0) && (TimeUsoCR < MIN_int32_T - *EndCPO)) {
    *EndCR = MIN_int32_T;
  } else if ((*EndCPO > 0) && (TimeUsoCR > MAX_int32_T - *EndCPO)) {
    *EndCR = MAX_int32_T;
  } else {
    *EndCR = *EndCPO + TimeUsoCR;
  }

  emxFree_real_T(&auxR);
  emxFree_int32_T(&R);
  emxFree_int32_T(&auxC);
  emxFree_int32_T(&C);
}

/* End of code generation (funcionC.c) */
