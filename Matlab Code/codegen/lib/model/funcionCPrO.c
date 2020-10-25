/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: funcionCPrO.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "funcionCPrO.h"
#include "funcionDia.h"
#include "model_emxutil.h"
#include "sum.h"

/* Function Definitions */

/*
 * function [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,AA,AnA,SA,IniSA,EndSA,EndRPxD,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,contDia] = ...
 *     funcionCPrO(NumRec, PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,H,Dia,UltPosRecXDia, TimeUsoCPrO, TimeUsoS,TimeUsoCPO,TimeUsoCR,contDia,...
 *     tempUltPosRecXDia,DispMExD,DispME)
 * Arguments    : const int NumRec[7]
 *                const emxArray_int32_T *PCPrO
 *                const emxArray_int32_T *PME
 *                const emxArray_int32_T *PMA
 *                const emxArray_int32_T *PMAn
 *                const emxArray_int32_T *PS
 *                const emxArray_int32_T *PCPO
 *                const emxArray_int32_T *PCR
 *                const emxArray_int32_T *H
 *                const emxArray_int32_T *Dia
 *                const emxArray_int32_T *UltPosRecXDia
 *                int TimeUsoCPrO
 *                int TimeUsoS
 *                int TimeUsoCPO
 *                int TimeUsoCR
 *                int *contDia
 *                emxArray_int32_T *tempUltPosRecXDia
 *                const emxArray_int32_T *DispMExD
 *                emxArray_int32_T *DispME
 *                int *CPrOA
 *                int *IniCPrOA
 *                int *EndCPrOA
 *                int *EndCPrOAxD
 *                emxArray_int32_T *EA
 *                emxArray_int32_T *AA
 *                emxArray_int32_T *AnA
 *                emxArray_int32_T *SA
 *                int *IniSA
 *                int *EndSA
 *                int *EndRPxD
 *                int *CPOA
 *                int *IniCPOA
 *                int *EndCPOA
 *                int *CRA
 *                int *IniCRA
 *                int *EndCRA
 * Return Type  : void
 */
void funcionCPrO(const int NumRec[7], const emxArray_int32_T *PCPrO, const
                 emxArray_int32_T *PME, const emxArray_int32_T *PMA, const
                 emxArray_int32_T *PMAn, const emxArray_int32_T *PS, const
                 emxArray_int32_T *PCPO, const emxArray_int32_T *PCR, const
                 emxArray_int32_T *H, const emxArray_int32_T *Dia, const
                 emxArray_int32_T *UltPosRecXDia, int TimeUsoCPrO, int TimeUsoS,
                 int TimeUsoCPO, int TimeUsoCR, int *contDia, emxArray_int32_T
                 *tempUltPosRecXDia, const emxArray_int32_T *DispMExD,
                 emxArray_int32_T *DispME, int *CPrOA, int *IniCPrOA, int
                 *EndCPrOA, int *EndCPrOAxD, emxArray_int32_T *EA,
                 emxArray_int32_T *AA, emxArray_int32_T *AnA, emxArray_int32_T
                 *SA, int *IniSA, int *EndSA, int *EndRPxD, int *CPOA, int
                 *IniCPOA, int *EndCPOA, int *CRA, int *IniCRA, int *EndCRA)
{
  int b_tmp;
  int n;
  unsigned int nm1;
  emxArray_int32_T *jj;
  int q;
  emxArray_int32_T *E;
  int yk;
  int k;
  int idx;
  double y_tmp;
  double y;
  emxArray_real_T *r29;
  emxArray_int32_T *S;
  double ndbl;
  emxArray_real_T *r30;
  emxArray_int32_T *A;
  emxArray_real_T *r31;
  emxArray_int32_T *An;
  emxArray_int32_T *CPO;
  emxArray_int32_T *CR;
  int b_CPrOA;
  int b_CPOA;
  int b_CRA;
  int b_IniCPrOA;
  int b_EndCPrOA;
  int b_IniSA;
  int b_EndSA;
  int b_IniCPOA;
  int b_EndCPOA;
  int b_IniCRA;
  int b_EndCRA;
  int b_EndCPrOAxD;
  int b_EndRPxD;
  emxArray_int32_T *EA_double;
  emxArray_int32_T *AA_double;
  emxArray_int32_T *AnA_double;
  emxArray_int32_T *SA_double;
  boolean_T flag;
  emxArray_uint32_T *uCPrODisp;
  emxArray_int32_T *C;
  emxArray_int32_T *allC;
  emxArray_int32_T *u;
  emxArray_int32_T *allE;
  emxArray_int32_T *allA;
  emxArray_int32_T *allAn;
  emxArray_int32_T *allS;
  emxArray_int32_T *allCPO;
  emxArray_int32_T *allCR;
  emxArray_uint32_T *r32;
  emxArray_int32_T *r33;
  emxArray_int32_T *r34;
  emxArray_int32_T *r35;
  emxArray_int32_T *r36;
  emxArray_boolean_T *x;
  emxArray_int32_T *b;
  emxArray_int32_T *b_idx;
  emxArray_int32_T *iwork;
  emxArray_int32_T *b_H;
  boolean_T exitg1;
  int minP_tmp;
  int minP;
  int na;
  int nb;
  int j;
  int p;
  int qEnd;
  int kEnd;
  int temCPrO;
  boolean_T exitg2;
  int IniCPO;
  int EndCPO;
  int IniCR;

  /* 'funcionCPrO:5' E = 1:size(NumRec(1)+1:sum(NumRec(1:2)),2); */
  b_tmp = NumRec[0] + NumRec[1];
  if (b_tmp < NumRec[0] + 1) {
    n = 0;
  } else {
    if ((NumRec[0] + 1 < 0) && (b_tmp >= 0)) {
      nm1 = ((unsigned int)b_tmp - NumRec[0]) - 1U;
    } else {
      nm1 = (unsigned int)((b_tmp - NumRec[0]) - 1);
    }

    n = (int)nm1 + 1;
  }

  emxInit_int32_T(&jj, 2);
  q = jj->size[0] * jj->size[1];
  jj->size[1] = n;
  jj->size[0] = 1;
  emxEnsureCapacity_int32_T(jj, q);
  if (n > 0) {
    jj->data[0] = NumRec[0] + 1;
    yk = NumRec[0] + 1;
    for (k = 2; k <= n; k++) {
      yk++;
      jj->data[k - 1] = yk;
    }
  }

  emxInit_int32_T(&E, 2);
  if (jj->size[1] < 1) {
    E->size[1] = 0;
    E->size[0] = 1;
  } else {
    idx = jj->size[1];
    q = E->size[0] * E->size[1];
    E->size[1] = idx;
    E->size[0] = 1;
    emxEnsureCapacity_int32_T(E, q);
    for (q = 0; q < idx; q++) {
      E->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:6' S = 1:size(sum(NumRec(1:2))+1:sum(NumRec(1:3)),2); */
  y_tmp = (double)NumRec[0] + (double)NumRec[1];
  y = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
  emxInit_real_T(&r29, 2);
  if (y < y_tmp + 1.0) {
    q = r29->size[0] * r29->size[1];
    r29->size[1] = 0;
    emxEnsureCapacity_real_T(r29, q);
  } else {
    q = r29->size[0] * r29->size[1];
    r29->size[1] = (int)(y - (y_tmp + 1.0)) + 1;
    emxEnsureCapacity_real_T(r29, q);
  }

  emxInit_int32_T(&S, 2);
  if (r29->size[1] < 1) {
    S->size[1] = 0;
    S->size[0] = 1;
  } else {
    idx = r29->size[1];
    q = S->size[0] * S->size[1];
    S->size[1] = idx;
    S->size[0] = 1;
    emxEnsureCapacity_int32_T(S, q);
    for (q = 0; q < idx; q++) {
      S->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:7' A = 1:size(sum(NumRec(1:3))+1:sum(NumRec(1:4)),2); */
  y = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
  ndbl = (((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) + (double)
    NumRec[3];
  emxInit_real_T(&r30, 2);
  if (ndbl < y + 1.0) {
    q = r30->size[0] * r30->size[1];
    r30->size[1] = 0;
    emxEnsureCapacity_real_T(r30, q);
  } else {
    q = r30->size[0] * r30->size[1];
    r30->size[1] = (int)(ndbl - (y + 1.0)) + 1;
    emxEnsureCapacity_real_T(r30, q);
  }

  emxInit_int32_T(&A, 2);
  if (r30->size[1] < 1) {
    A->size[1] = 0;
    A->size[0] = 1;
  } else {
    idx = r30->size[1];
    q = A->size[0] * A->size[1];
    A->size[1] = idx;
    A->size[0] = 1;
    emxEnsureCapacity_int32_T(A, q);
    for (q = 0; q < idx; q++) {
      A->data[q] = 1 + q;
    }
  }

  emxFree_real_T(&r30);

  /* 'funcionCPrO:8' An = 1:size(sum(NumRec(1:4))+1:sum(NumRec(1:5)),2); */
  y = (((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) + (double)
    NumRec[3];
  ndbl = ((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
          (double)NumRec[3]) + (double)NumRec[4];
  emxInit_real_T(&r31, 2);
  if (ndbl < y + 1.0) {
    q = r31->size[0] * r31->size[1];
    r31->size[1] = 0;
    emxEnsureCapacity_real_T(r31, q);
  } else {
    q = r31->size[0] * r31->size[1];
    r31->size[1] = (int)(ndbl - (y + 1.0)) + 1;
    emxEnsureCapacity_real_T(r31, q);
  }

  emxInit_int32_T(&An, 2);
  if (r31->size[1] < 1) {
    An->size[1] = 0;
    An->size[0] = 1;
  } else {
    idx = r31->size[1];
    q = An->size[0] * An->size[1];
    An->size[1] = idx;
    An->size[0] = 1;
    emxEnsureCapacity_int32_T(An, q);
    for (q = 0; q < idx; q++) {
      An->data[q] = 1 + q;
    }
  }

  emxFree_real_T(&r31);

  /* 'funcionCPrO:9' CPO = 1:size(PCPO, 2); */
  emxInit_int32_T(&CPO, 2);
  if (PCPO->size[1] < 1) {
    CPO->size[1] = 0;
    CPO->size[0] = 1;
  } else {
    idx = PCPO->size[1];
    q = CPO->size[0] * CPO->size[1];
    CPO->size[1] = idx;
    CPO->size[0] = 1;
    emxEnsureCapacity_int32_T(CPO, q);
    for (q = 0; q < idx; q++) {
      CPO->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:10' CR = 1:size(PCR, 2); */
  emxInit_int32_T(&CR, 2);
  if (PCR->size[1] < 1) {
    CR->size[1] = 0;
    CR->size[0] = 1;
  } else {
    idx = PCR->size[1];
    q = CR->size[0] * CR->size[1];
    CR->size[1] = idx;
    CR->size[0] = 1;
    emxEnsureCapacity_int32_T(CR, q);
    for (q = 0; q < idx; q++) {
      CR->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:11' CPrOA = int32(0); */
  b_CPrOA = 0;

  /* 'funcionCPrO:12' CPOA = int32(0); */
  b_CPOA = 0;

  /* 'funcionCPrO:13' CRA = int32(0); */
  b_CRA = 0;

  /* 'funcionCPrO:14' IniCPrOA = int32(0); */
  b_IniCPrOA = 0;

  /* 'funcionCPrO:15' EndCPrOA = int32(0); */
  b_EndCPrOA = 1;

  /* 'funcionCPrO:16' IniSA = int32(0); */
  b_IniSA = 0;

  /* 'funcionCPrO:17' EndSA = int32(0); */
  b_EndSA = 0;

  /* 'funcionCPrO:18' IniCPOA = int32(0); */
  b_IniCPOA = -1;

  /* 'funcionCPrO:19' EndCPOA = int32(0); */
  b_EndCPOA = 0;

  /* 'funcionCPrO:20' IniCRA = int32(0); */
  b_IniCRA = -1;

  /* 'funcionCPrO:21' EndCRA = int32(0); */
  b_EndCRA = 0;

  /* 'funcionCPrO:22' EndCPrOAxD = int32(0); */
  b_EndCPrOAxD = 0;

  /* 'funcionCPrO:23' EndRPxD = int32(0); */
  b_EndRPxD = 0;

  /* 'funcionCPrO:24' EA_double = 1:size(PME,2)-1; */
  emxInit_int32_T(&EA_double, 2);
  if (PME->size[1] - 1 < 1) {
    EA_double->size[1] = 0;
    EA_double->size[0] = 1;
  } else {
    idx = PME->size[1] - 1;
    q = EA_double->size[0] * EA_double->size[1];
    EA_double->size[1] = idx;
    EA_double->size[0] = 1;
    emxEnsureCapacity_int32_T(EA_double, q);
    for (q = 0; q < idx; q++) {
      EA_double->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:25' AA_double = 1:size(PMA,2)-1; */
  emxInit_int32_T(&AA_double, 2);
  if (PMA->size[1] - 1 < 1) {
    AA_double->size[1] = 0;
    AA_double->size[0] = 1;
  } else {
    idx = PMA->size[1] - 1;
    q = AA_double->size[0] * AA_double->size[1];
    AA_double->size[1] = idx;
    AA_double->size[0] = 1;
    emxEnsureCapacity_int32_T(AA_double, q);
    for (q = 0; q < idx; q++) {
      AA_double->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:26' AnA_double = 1:size(PMAn,2)-1; */
  emxInit_int32_T(&AnA_double, 2);
  if (PMAn->size[1] - 1 < 1) {
    AnA_double->size[1] = 0;
    AnA_double->size[0] = 1;
  } else {
    idx = PMAn->size[1] - 1;
    q = AnA_double->size[0] * AnA_double->size[1];
    AnA_double->size[1] = idx;
    AnA_double->size[0] = 1;
    emxEnsureCapacity_int32_T(AnA_double, q);
    for (q = 0; q < idx; q++) {
      AnA_double->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:27' SA_double = 1:size(PS,2)-1; */
  emxInit_int32_T(&SA_double, 2);
  if (PS->size[1] - 1 < 1) {
    SA_double->size[1] = 0;
    SA_double->size[0] = 1;
  } else {
    idx = PS->size[1] - 1;
    q = SA_double->size[0] * SA_double->size[1];
    SA_double->size[1] = idx;
    SA_double->size[0] = 1;
    emxEnsureCapacity_int32_T(SA_double, q);
    for (q = 0; q < idx; q++) {
      SA_double->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:29' flag = true; */
  flag = true;

  /* 'funcionCPrO:30' while flag */
  emxInit_uint32_T(&uCPrODisp, 2);
  emxInit_int32_T(&C, 2);
  emxInit_int32_T(&allC, 2);
  emxInit_int32_T(&u, 1);
  emxInit_int32_T(&allE, 2);
  emxInit_int32_T(&allA, 2);
  emxInit_int32_T(&allAn, 2);
  emxInit_int32_T(&allS, 2);
  emxInit_int32_T(&allCPO, 2);
  emxInit_int32_T(&allCR, 2);
  emxInit_uint32_T(&r32, 1);
  emxInit_int32_T(&r33, 1);
  emxInit_int32_T(&r34, 1);
  emxInit_int32_T(&r35, 1);
  emxInit_int32_T(&r36, 1);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&b, 2);
  emxInit_int32_T(&b_idx, 2);
  emxInit_int32_T(&iwork, 1);
  emxInit_int32_T(&b_H, 2);
  while (flag) {
    /* 'funcionCPrO:32' auxUPxR = tempUltPosRecXDia; */
    /*  Selecciono los ultimas posiciones a partir de donde se pueden usar las camas. */
    /* 'funcionCPrO:33' [~,C]=find(PCPrO~=0); */
    q = x->size[0] * x->size[1];
    x->size[1] = PCPrO->size[1];
    x->size[0] = 1;
    emxEnsureCapacity_boolean_T(x, q);
    idx = PCPrO->size[1];
    for (q = 0; q < idx; q++) {
      x->data[q] = (PCPrO->data[q] != 0);
    }

    if (x->size[1] == 0) {
      jj->size[1] = 0;
      jj->size[0] = 1;
    } else {
      idx = 0;
      nm1 = (unsigned int)x->size[1];
      q = jj->size[0] * jj->size[1];
      jj->size[1] = (int)nm1;
      jj->size[0] = 1;
      emxEnsureCapacity_int32_T(jj, q);
      yk = 1;
      exitg1 = false;
      while ((!exitg1) && (yk <= x->size[1])) {
        if (x->data[yk - 1]) {
          idx++;
          jj->data[idx - 1] = yk;
          if (idx >= x->size[1]) {
            exitg1 = true;
          } else {
            yk++;
          }
        } else {
          yk++;
        }
      }

      if (x->size[1] == 1) {
        if (idx == 0) {
          jj->size[1] = 0;
          jj->size[0] = 1;
        }
      } else {
        if (1 > idx) {
          idx = 0;
        }

        q = iwork->size[0];
        iwork->size[0] = idx;
        emxEnsureCapacity_int32_T(iwork, q);
        for (q = 0; q < idx; q++) {
          iwork->data[q] = q;
        }

        yk = iwork->size[0];
        q = b_idx->size[0] * b_idx->size[1];
        b_idx->size[1] = yk;
        b_idx->size[0] = 1;
        emxEnsureCapacity_int32_T(b_idx, q);
        for (q = 0; q < yk; q++) {
          b_idx->data[q] = jj->data[iwork->data[q]];
        }

        q = jj->size[0] * jj->size[1];
        jj->size[1] = b_idx->size[1];
        jj->size[0] = 1;
        emxEnsureCapacity_int32_T(jj, q);
        idx = b_idx->size[1];
        for (q = 0; q < idx; q++) {
          jj->data[q] = b_idx->data[q];
        }
      }
    }

    q = C->size[0] * C->size[1];
    C->size[1] = jj->size[1];
    C->size[0] = 1;
    emxEnsureCapacity_int32_T(C, q);
    idx = jj->size[1];
    for (q = 0; q < idx; q++) {
      C->data[q] = jj->data[q];
    }

    /* 'funcionCPrO:33' ~ */
    /*  Busco las posibles camas a usar. */
    /* 'funcionCPrO:34' minP = Dia(contDia,4)-Dia(contDia,3)+1-(TimeUsoCPrO+TimeUsoS); */
    yk = (*contDia - 1) << 2;
    minP_tmp = 2 + yk;
    minP = (((Dia->data[3 + yk] - Dia->data[minP_tmp]) - TimeUsoCPrO) - TimeUsoS)
      + 1;

    /*  Posicion maxima a partir de la cual se puede colocar la Operacion. */
    /* 'funcionCPrO:35' [~,allC]=find(auxUPxR(C)<=minP); */
    q = x->size[0] * x->size[1];
    x->size[1] = C->size[1];
    x->size[0] = 1;
    emxEnsureCapacity_boolean_T(x, q);
    idx = C->size[1];
    for (q = 0; q < idx; q++) {
      x->data[q] = (tempUltPosRecXDia->data[C->data[q] - 1] <= minP);
    }

    if (x->size[1] == 0) {
      jj->size[1] = 0;
      jj->size[0] = 1;
    } else {
      idx = 0;
      nm1 = (unsigned int)x->size[1];
      q = jj->size[0] * jj->size[1];
      jj->size[1] = (int)nm1;
      jj->size[0] = 1;
      emxEnsureCapacity_int32_T(jj, q);
      yk = 1;
      exitg1 = false;
      while ((!exitg1) && (yk <= x->size[1])) {
        if (x->data[yk - 1]) {
          idx++;
          jj->data[idx - 1] = yk;
          if (idx >= x->size[1]) {
            exitg1 = true;
          } else {
            yk++;
          }
        } else {
          yk++;
        }
      }

      if (x->size[1] == 1) {
        if (idx == 0) {
          jj->size[1] = 0;
          jj->size[0] = 1;
        }
      } else {
        if (1 > idx) {
          idx = 0;
        }

        q = iwork->size[0];
        iwork->size[0] = idx;
        emxEnsureCapacity_int32_T(iwork, q);
        for (q = 0; q < idx; q++) {
          iwork->data[q] = q;
        }

        yk = iwork->size[0];
        q = b_idx->size[0] * b_idx->size[1];
        b_idx->size[1] = yk;
        b_idx->size[0] = 1;
        emxEnsureCapacity_int32_T(b_idx, q);
        for (q = 0; q < yk; q++) {
          b_idx->data[q] = jj->data[iwork->data[q]];
        }

        q = jj->size[0] * jj->size[1];
        jj->size[1] = b_idx->size[1];
        jj->size[0] = 1;
        emxEnsureCapacity_int32_T(jj, q);
        idx = b_idx->size[1];
        for (q = 0; q < idx; q++) {
          jj->data[q] = b_idx->data[q];
        }
      }
    }

    q = allC->size[0] * allC->size[1];
    allC->size[1] = jj->size[1];
    allC->size[0] = 1;
    emxEnsureCapacity_int32_T(allC, q);
    idx = jj->size[1];
    for (q = 0; q < idx; q++) {
      allC->data[q] = jj->data[q];
    }

    /* 'funcionCPrO:35' ~ */
    /*  Veo en cuales es posible asignar la operacion. */
    /* 'funcionCPrO:37' if isempty(allC) */
    if (allC->size[1] == 0) {
      /*  Si no es posible asignar ninguna cama incremento el contDia e llamo a funcionDia */
      /* 'funcionCPrO:38' contDia = contDia + 1; */
      (*contDia)++;

      /* 'funcionCPrO:39' [contDia,tempUltPosRecXDia,DispME] = funcionDia(NumRec, PCPrO, Dia,UltPosRecXDia, TimeUsoCPrO, TimeUsoS, contDia, DispMExD); */
      funcionDia(NumRec, PCPrO, Dia, UltPosRecXDia, TimeUsoCPrO, TimeUsoS,
                 contDia, DispMExD, tempUltPosRecXDia, DispME);
    } else {
      /* 'funcionCPrO:40' else */
      /* 'funcionCPrO:41' [~,u]=unique(auxUPxR(C(allC))); */
      q = jj->size[0] * jj->size[1];
      jj->size[1] = allC->size[1];
      jj->size[0] = 1;
      emxEnsureCapacity_int32_T(jj, q);
      idx = allC->size[1];
      for (q = 0; q < idx; q++) {
        jj->data[q] = tempUltPosRecXDia->data[C->data[allC->data[q] - 1] - 1];
      }

      na = allC->size[1];
      n = allC->size[1] + 1;
      yk = allC->size[1];
      q = b_idx->size[0] * b_idx->size[1];
      b_idx->size[1] = yk;
      b_idx->size[0] = 1;
      emxEnsureCapacity_int32_T(b_idx, q);
      for (q = 0; q < yk; q++) {
        b_idx->data[q] = 0;
      }

      q = iwork->size[0];
      iwork->size[0] = allC->size[1];
      emxEnsureCapacity_int32_T(iwork, q);
      q = allC->size[1] - 1;
      for (k = 1; k <= q; k += 2) {
        if (jj->data[k - 1] <= jj->data[k]) {
          b_idx->data[k - 1] = k;
          b_idx->data[k] = k + 1;
        } else {
          b_idx->data[k - 1] = k + 1;
          b_idx->data[k] = k;
        }
      }

      if ((allC->size[1] & 1) != 0) {
        b_idx->data[allC->size[1] - 1] = allC->size[1];
      }

      yk = 2;
      while (yk < n - 1) {
        nb = yk << 1;
        j = 1;
        for (idx = 1 + yk; idx < n; idx = qEnd + yk) {
          p = j;
          q = idx;
          qEnd = j + nb;
          if (qEnd > n) {
            qEnd = n;
          }

          k = 0;
          kEnd = qEnd - j;
          while (k + 1 <= kEnd) {
            if (jj->data[b_idx->data[p - 1] - 1] <= jj->data[b_idx->data[q - 1]
                - 1]) {
              iwork->data[k] = b_idx->data[p - 1];
              p++;
              if (p == idx) {
                while (q < qEnd) {
                  k++;
                  iwork->data[k] = b_idx->data[q - 1];
                  q++;
                }
              }
            } else {
              iwork->data[k] = b_idx->data[q - 1];
              q++;
              if (q == qEnd) {
                while (p < idx) {
                  k++;
                  iwork->data[k] = b_idx->data[p - 1];
                  p++;
                }
              }
            }

            k++;
          }

          for (k = 0; k < kEnd; k++) {
            b_idx->data[(j + k) - 1] = iwork->data[k];
          }

          j = qEnd;
        }

        yk = nb;
      }

      nm1 = (unsigned int)allC->size[1];
      q = b->size[0] * b->size[1];
      b->size[1] = (int)nm1;
      b->size[0] = 1;
      emxEnsureCapacity_int32_T(b, q);
      for (k = 0; k < na; k++) {
        b->data[k] = jj->data[b_idx->data[k] - 1];
      }

      nb = -1;
      k = 0;
      while (k + 1 <= na) {
        yk = b->data[k];
        idx = k;
        do {
          k++;
        } while (!((k + 1 > na) || (b->data[k] != yk)));

        nb++;
        b->data[nb] = yk;
        b_idx->data[nb] = b_idx->data[idx];
      }

      q = iwork->size[0];
      iwork->size[0] = nb + 1;
      emxEnsureCapacity_int32_T(iwork, q);
      for (k = 0; k <= nb; k++) {
        iwork->data[k] = b_idx->data[k];
      }

      q = u->size[0];
      u->size[0] = iwork->size[0];
      emxEnsureCapacity_int32_T(u, q);
      idx = iwork->size[0];
      for (q = 0; q < idx; q++) {
        u->data[q] = iwork->data[q];
      }

      /* 'funcionCPrO:41' ~ */
      /* 'funcionCPrO:42' uCPrODisp=C(allC(u)); */
      q = r32->size[0];
      r32->size[0] = u->size[0];
      emxEnsureCapacity_uint32_T(r32, q);
      idx = u->size[0];
      for (q = 0; q < idx; q++) {
        r32->data[q] = (unsigned int)allC->data[u->data[q] - 1];
      }

      yk = u->size[0];
      q = uCPrODisp->size[0] * uCPrODisp->size[1];
      uCPrODisp->size[1] = yk;
      uCPrODisp->size[0] = 1;
      emxEnsureCapacity_uint32_T(uCPrODisp, q);
      for (q = 0; q < yk; q++) {
        uCPrODisp->data[q] = (unsigned int)C->data[(int)r32->data[q] - 1];
      }

      /* 'funcionCPrO:46' auxUPxE = UltPosRecXDia(contDia,NumRec(1)+1:sum(NumRec(1:2))); */
      if (NumRec[0] + 1 > b_tmp) {
        q = 0;
        p = 0;
      } else {
        q = NumRec[0];
        p = b_tmp;
      }

      yk = iwork->size[0];
      idx = p - q;
      iwork->size[0] = idx;
      emxEnsureCapacity_int32_T(iwork, yk);
      for (p = 0; p < idx; p++) {
        iwork->data[p] = UltPosRecXDia->data[(q + p) + UltPosRecXDia->size[1] *
          (*contDia - 1)];
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los ME. */
      /* 'funcionCPrO:47' auxPME=PME(1:end-1).*DispME; */
      if (1 > PME->size[1] - 1) {
        idx = 0;
      } else {
        idx = PME->size[1] - 1;
      }

      q = r33->size[0];
      r33->size[0] = idx;
      emxEnsureCapacity_int32_T(r33, q);
      for (q = 0; q < idx; q++) {
        r33->data[q] = q;
      }

      /* 'funcionCPrO:48' [~,allE]=find(auxPME~=0); */
      yk = r33->size[0];
      q = x->size[0] * x->size[1];
      x->size[1] = yk;
      x->size[0] = 1;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < yk; q++) {
        x->data[q] = (PME->data[r33->data[q]] * DispME->data[q] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[1] = 0;
        jj->size[0] = 1;
      } else {
        idx = 0;
        yk = x->size[1];
        q = jj->size[0] * jj->size[1];
        jj->size[1] = yk;
        jj->size[0] = 1;
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            idx++;
            jj->data[idx - 1] = yk;
            if (idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (idx == 0) {
            jj->size[1] = 0;
            jj->size[0] = 1;
          }
        } else {
          if (1 > idx) {
            idx = 0;
          }

          q = r33->size[0];
          r33->size[0] = idx;
          emxEnsureCapacity_int32_T(r33, q);
          for (q = 0; q < idx; q++) {
            r33->data[q] = q;
          }

          yk = r33->size[0];
          q = b_idx->size[0] * b_idx->size[1];
          b_idx->size[1] = yk;
          b_idx->size[0] = 1;
          emxEnsureCapacity_int32_T(b_idx, q);
          for (q = 0; q < yk; q++) {
            b_idx->data[q] = jj->data[r33->data[q]];
          }

          q = jj->size[0] * jj->size[1];
          jj->size[1] = b_idx->size[1];
          jj->size[0] = 1;
          emxEnsureCapacity_int32_T(jj, q);
          idx = b_idx->size[1];
          for (q = 0; q < idx; q++) {
            jj->data[q] = b_idx->data[q];
          }
        }
      }

      q = allE->size[0] * allE->size[1];
      allE->size[1] = jj->size[1];
      allE->size[0] = 1;
      emxEnsureCapacity_int32_T(allE, q);
      idx = jj->size[1];
      for (q = 0; q < idx; q++) {
        allE->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:48' ~ */
      /*  Busco los posibles Especialistas a usar. */
      /* 'funcionCPrO:50' auxUPxA = UltPosRecXDia(contDia,sum(NumRec(1:3))+1:sum(NumRec(1:4))); */
      y = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
      ndbl = (((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
        (double)NumRec[3];
      if (y + 1.0 > ndbl) {
        q = 1;
        p = 0;
      } else {
        q = (int)(y + 1.0);
        p = (int)ndbl;
      }

      yk = r33->size[0];
      idx = p - q;
      r33->size[0] = idx + 1;
      emxEnsureCapacity_int32_T(r33, yk);
      for (p = 0; p <= idx; p++) {
        r33->data[p] = UltPosRecXDia->data[((q + p) + UltPosRecXDia->size[1] * (*
          contDia - 1)) - 1];
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los A. */
      /* 'funcionCPrO:51' [~,allA]=find(PMA(1:end-1)~=0); */
      if (1 > PMA->size[1] - 1) {
        idx = 0;
      } else {
        idx = PMA->size[1] - 1;
      }

      q = r34->size[0];
      r34->size[0] = idx;
      emxEnsureCapacity_int32_T(r34, q);
      for (q = 0; q < idx; q++) {
        r34->data[q] = q;
      }

      yk = r34->size[0];
      q = x->size[0] * x->size[1];
      x->size[1] = yk;
      x->size[0] = 1;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < yk; q++) {
        x->data[q] = (PMA->data[r34->data[q]] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[1] = 0;
        jj->size[0] = 1;
      } else {
        idx = 0;
        yk = x->size[1];
        q = jj->size[0] * jj->size[1];
        jj->size[1] = yk;
        jj->size[0] = 1;
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            idx++;
            jj->data[idx - 1] = yk;
            if (idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (idx == 0) {
            jj->size[1] = 0;
            jj->size[0] = 1;
          }
        } else {
          if (1 > idx) {
            idx = 0;
          }

          q = r34->size[0];
          r34->size[0] = idx;
          emxEnsureCapacity_int32_T(r34, q);
          for (q = 0; q < idx; q++) {
            r34->data[q] = q;
          }

          yk = r34->size[0];
          q = b_idx->size[0] * b_idx->size[1];
          b_idx->size[1] = yk;
          b_idx->size[0] = 1;
          emxEnsureCapacity_int32_T(b_idx, q);
          for (q = 0; q < yk; q++) {
            b_idx->data[q] = jj->data[r34->data[q]];
          }

          q = jj->size[0] * jj->size[1];
          jj->size[1] = b_idx->size[1];
          jj->size[0] = 1;
          emxEnsureCapacity_int32_T(jj, q);
          idx = b_idx->size[1];
          for (q = 0; q < idx; q++) {
            jj->data[q] = b_idx->data[q];
          }
        }
      }

      q = allA->size[0] * allA->size[1];
      allA->size[1] = jj->size[1];
      allA->size[0] = 1;
      emxEnsureCapacity_int32_T(allA, q);
      idx = jj->size[1];
      for (q = 0; q < idx; q++) {
        allA->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:51' ~ */
      /*  Busco los posibles Asistentes a usar. */
      /* 'funcionCPrO:53' auxUPxAn = UltPosRecXDia(contDia,sum(NumRec(1:4))+1:sum(NumRec(1:5))); */
      y = (((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
        (double)NumRec[3];
      ndbl = ((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
              (double)NumRec[3]) + (double)NumRec[4];
      if (y + 1.0 > ndbl) {
        q = 1;
        p = 0;
      } else {
        q = (int)(y + 1.0);
        p = (int)ndbl;
      }

      yk = r34->size[0];
      idx = p - q;
      r34->size[0] = idx + 1;
      emxEnsureCapacity_int32_T(r34, yk);
      for (p = 0; p <= idx; p++) {
        r34->data[p] = UltPosRecXDia->data[((q + p) + UltPosRecXDia->size[1] * (*
          contDia - 1)) - 1];
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los An. */
      /* 'funcionCPrO:54' [~,allAn]=find(PMAn(1:end-1)~=0); */
      if (1 > PMAn->size[1] - 1) {
        idx = 0;
      } else {
        idx = PMAn->size[1] - 1;
      }

      q = r35->size[0];
      r35->size[0] = idx;
      emxEnsureCapacity_int32_T(r35, q);
      for (q = 0; q < idx; q++) {
        r35->data[q] = q;
      }

      yk = r35->size[0];
      q = x->size[0] * x->size[1];
      x->size[1] = yk;
      x->size[0] = 1;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < yk; q++) {
        x->data[q] = (PMAn->data[r35->data[q]] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[1] = 0;
        jj->size[0] = 1;
      } else {
        idx = 0;
        yk = x->size[1];
        q = jj->size[0] * jj->size[1];
        jj->size[1] = yk;
        jj->size[0] = 1;
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            idx++;
            jj->data[idx - 1] = yk;
            if (idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (idx == 0) {
            jj->size[1] = 0;
            jj->size[0] = 1;
          }
        } else {
          if (1 > idx) {
            idx = 0;
          }

          q = r35->size[0];
          r35->size[0] = idx;
          emxEnsureCapacity_int32_T(r35, q);
          for (q = 0; q < idx; q++) {
            r35->data[q] = q;
          }

          yk = r35->size[0];
          q = b_idx->size[0] * b_idx->size[1];
          b_idx->size[1] = yk;
          b_idx->size[0] = 1;
          emxEnsureCapacity_int32_T(b_idx, q);
          for (q = 0; q < yk; q++) {
            b_idx->data[q] = jj->data[r35->data[q]];
          }

          q = jj->size[0] * jj->size[1];
          jj->size[1] = b_idx->size[1];
          jj->size[0] = 1;
          emxEnsureCapacity_int32_T(jj, q);
          idx = b_idx->size[1];
          for (q = 0; q < idx; q++) {
            jj->data[q] = b_idx->data[q];
          }
        }
      }

      q = allAn->size[0] * allAn->size[1];
      allAn->size[1] = jj->size[1];
      allAn->size[0] = 1;
      emxEnsureCapacity_int32_T(allAn, q);
      idx = jj->size[1];
      for (q = 0; q < idx; q++) {
        allAn->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:54' ~ */
      /*  Busco los posibles Anestesistas a usar. */
      /* 'funcionCPrO:56' auxUPxS = UltPosRecXDia(contDia,sum(NumRec(1:2))+1:sum(NumRec(1:3))); */
      y = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
      if (y_tmp + 1.0 > y) {
        q = 1;
        p = 0;
      } else {
        q = (int)(y_tmp + 1.0);
        p = (int)y;
      }

      yk = r35->size[0];
      idx = p - q;
      r35->size[0] = idx + 1;
      emxEnsureCapacity_int32_T(r35, yk);
      for (p = 0; p <= idx; p++) {
        r35->data[p] = UltPosRecXDia->data[((q + p) + UltPosRecXDia->size[1] * (*
          contDia - 1)) - 1];
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
      /* 'funcionCPrO:57' [~,allS]=find(PS(1:end)~=0); */
      if (1 > PS->size[1]) {
        idx = 0;
      } else {
        idx = PS->size[1];
      }

      q = r36->size[0];
      r36->size[0] = idx;
      emxEnsureCapacity_int32_T(r36, q);
      for (q = 0; q < idx; q++) {
        r36->data[q] = q;
      }

      yk = r36->size[0];
      q = x->size[0] * x->size[1];
      x->size[1] = yk;
      x->size[0] = 1;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < yk; q++) {
        x->data[q] = (PS->data[r36->data[q]] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[1] = 0;
        jj->size[0] = 1;
      } else {
        idx = 0;
        nm1 = (unsigned int)x->size[1];
        q = jj->size[0] * jj->size[1];
        jj->size[1] = (int)nm1;
        jj->size[0] = 1;
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            idx++;
            jj->data[idx - 1] = yk;
            if (idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (idx == 0) {
            jj->size[1] = 0;
            jj->size[0] = 1;
          }
        } else {
          if (1 > idx) {
            idx = 0;
          }

          q = r36->size[0];
          r36->size[0] = idx;
          emxEnsureCapacity_int32_T(r36, q);
          for (q = 0; q < idx; q++) {
            r36->data[q] = q;
          }

          yk = r36->size[0];
          q = b_idx->size[0] * b_idx->size[1];
          b_idx->size[1] = yk;
          b_idx->size[0] = 1;
          emxEnsureCapacity_int32_T(b_idx, q);
          for (q = 0; q < yk; q++) {
            b_idx->data[q] = jj->data[r36->data[q]];
          }

          q = jj->size[0] * jj->size[1];
          jj->size[1] = b_idx->size[1];
          jj->size[0] = 1;
          emxEnsureCapacity_int32_T(jj, q);
          idx = b_idx->size[1];
          for (q = 0; q < idx; q++) {
            jj->data[q] = b_idx->data[q];
          }
        }
      }

      q = allS->size[0] * allS->size[1];
      allS->size[1] = jj->size[1];
      allS->size[0] = 1;
      emxEnsureCapacity_int32_T(allS, q);
      idx = jj->size[1];
      for (q = 0; q < idx; q++) {
        allS->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:57' ~ */
      /*  Busco los posibles Salones a usar. */
      /* auxUPxCPO = UltPosRecXDia(contDia,NumRec(1:5)+1:sum(NumRec(1:6)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los ME. */
      /* 'funcionCPrO:60' [~,allCPO]=find(PCPO(1:end)~=0); */
      if (1 > PCPO->size[1]) {
        idx = 0;
      } else {
        idx = PCPO->size[1];
      }

      q = r36->size[0];
      r36->size[0] = idx;
      emxEnsureCapacity_int32_T(r36, q);
      for (q = 0; q < idx; q++) {
        r36->data[q] = q;
      }

      yk = r36->size[0];
      q = x->size[0] * x->size[1];
      x->size[1] = yk;
      x->size[0] = 1;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < yk; q++) {
        x->data[q] = (PCPO->data[r36->data[q]] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[1] = 0;
        jj->size[0] = 1;
      } else {
        idx = 0;
        nm1 = (unsigned int)x->size[1];
        q = jj->size[0] * jj->size[1];
        jj->size[1] = (int)nm1;
        jj->size[0] = 1;
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            idx++;
            jj->data[idx - 1] = yk;
            if (idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (idx == 0) {
            jj->size[1] = 0;
            jj->size[0] = 1;
          }
        } else {
          if (1 > idx) {
            idx = 0;
          }

          q = r36->size[0];
          r36->size[0] = idx;
          emxEnsureCapacity_int32_T(r36, q);
          for (q = 0; q < idx; q++) {
            r36->data[q] = q;
          }

          yk = r36->size[0];
          q = b_idx->size[0] * b_idx->size[1];
          b_idx->size[1] = yk;
          b_idx->size[0] = 1;
          emxEnsureCapacity_int32_T(b_idx, q);
          for (q = 0; q < yk; q++) {
            b_idx->data[q] = jj->data[r36->data[q]];
          }

          q = jj->size[0] * jj->size[1];
          jj->size[1] = b_idx->size[1];
          jj->size[0] = 1;
          emxEnsureCapacity_int32_T(jj, q);
          idx = b_idx->size[1];
          for (q = 0; q < idx; q++) {
            jj->data[q] = b_idx->data[q];
          }
        }
      }

      q = allCPO->size[0] * allCPO->size[1];
      allCPO->size[1] = jj->size[1];
      allCPO->size[0] = 1;
      emxEnsureCapacity_int32_T(allCPO, q);
      idx = jj->size[1];
      for (q = 0; q < idx; q++) {
        allCPO->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:60' ~ */
      /*  Busco los posibles Especialistas a usar. */
      /* auxUPxCR = UltPosRecXDia(contDia,sum(NumRec(1:6))+1:sum(NumRec(1:7)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
      /* 'funcionCPrO:63' [~,allCR]=find(PCR(1:end)~=0); */
      if (1 > PCR->size[1]) {
        idx = 0;
      } else {
        idx = PCR->size[1];
      }

      q = r36->size[0];
      r36->size[0] = idx;
      emxEnsureCapacity_int32_T(r36, q);
      for (q = 0; q < idx; q++) {
        r36->data[q] = q;
      }

      yk = r36->size[0];
      q = x->size[0] * x->size[1];
      x->size[1] = yk;
      x->size[0] = 1;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < yk; q++) {
        x->data[q] = (PCR->data[r36->data[q]] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[1] = 0;
        jj->size[0] = 1;
      } else {
        idx = 0;
        nm1 = (unsigned int)x->size[1];
        q = jj->size[0] * jj->size[1];
        jj->size[1] = (int)nm1;
        jj->size[0] = 1;
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            idx++;
            jj->data[idx - 1] = yk;
            if (idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (idx == 0) {
            jj->size[1] = 0;
            jj->size[0] = 1;
          }
        } else {
          if (1 > idx) {
            idx = 0;
          }

          q = r36->size[0];
          r36->size[0] = idx;
          emxEnsureCapacity_int32_T(r36, q);
          for (q = 0; q < idx; q++) {
            r36->data[q] = q;
          }

          yk = r36->size[0];
          q = b_idx->size[0] * b_idx->size[1];
          b_idx->size[1] = yk;
          b_idx->size[0] = 1;
          emxEnsureCapacity_int32_T(b_idx, q);
          for (q = 0; q < yk; q++) {
            b_idx->data[q] = jj->data[r36->data[q]];
          }

          q = jj->size[0] * jj->size[1];
          jj->size[1] = b_idx->size[1];
          jj->size[0] = 1;
          emxEnsureCapacity_int32_T(jj, q);
          idx = b_idx->size[1];
          for (q = 0; q < idx; q++) {
            jj->data[q] = b_idx->data[q];
          }
        }
      }

      q = allCR->size[0] * allCR->size[1];
      allCR->size[1] = jj->size[1];
      allCR->size[0] = 1;
      emxEnsureCapacity_int32_T(allCR, q);
      idx = jj->size[1];
      for (q = 0; q < idx; q++) {
        allCR->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:63' ~ */
      /*  Busco los posibles Salones a usar. */
      /* 'funcionCPrO:64' temCPrO=-1; */
      temCPrO = -1;

      /* 'funcionCPrO:66' for j=1:length(uCPrODisp) */
      j = 0;
      exitg1 = false;
      while ((!exitg1) && (j <= u->size[0] - 1)) {
        /* 'funcionCPrO:68' EndCPrOAxD = auxUPxR(uCPrODisp(j))+TimeUsoCPrO; */
        b_EndCPrOAxD = tempUltPosRecXDia->data[(int)uCPrODisp->data[j] - 1] +
          TimeUsoCPrO;

        /* 'funcionCPrO:69' EndRPxD = EndCPrOAxD+TimeUsoS; */
        b_EndRPxD = b_EndCPrOAxD + TimeUsoS;

        /* 'funcionCPrO:71' [~,E]=find(auxUPxE(allE)<=EndCPrOAxD); */
        q = x->size[0] * x->size[1];
        x->size[1] = allE->size[1];
        x->size[0] = 1;
        emxEnsureCapacity_boolean_T(x, q);
        idx = allE->size[1];
        for (q = 0; q < idx; q++) {
          x->data[q] = (iwork->data[allE->data[q] - 1] <= b_EndCPrOAxD);
        }

        if (x->size[1] == 0) {
          jj->size[1] = 0;
          jj->size[0] = 1;
        } else {
          idx = 0;
          nm1 = (unsigned int)x->size[1];
          q = jj->size[0] * jj->size[1];
          jj->size[1] = (int)nm1;
          jj->size[0] = 1;
          emxEnsureCapacity_int32_T(jj, q);
          yk = 1;
          exitg2 = false;
          while ((!exitg2) && (yk <= x->size[1])) {
            if (x->data[yk - 1]) {
              idx++;
              jj->data[idx - 1] = yk;
              if (idx >= x->size[1]) {
                exitg2 = true;
              } else {
                yk++;
              }
            } else {
              yk++;
            }
          }

          if (x->size[1] == 1) {
            if (idx == 0) {
              jj->size[1] = 0;
              jj->size[0] = 1;
            }
          } else {
            if (1 > idx) {
              idx = 0;
            }

            q = r36->size[0];
            r36->size[0] = idx;
            emxEnsureCapacity_int32_T(r36, q);
            for (q = 0; q < idx; q++) {
              r36->data[q] = q;
            }

            yk = r36->size[0];
            q = b_idx->size[0] * b_idx->size[1];
            b_idx->size[1] = yk;
            b_idx->size[0] = 1;
            emxEnsureCapacity_int32_T(b_idx, q);
            for (q = 0; q < yk; q++) {
              b_idx->data[q] = jj->data[r36->data[q]];
            }

            q = jj->size[0] * jj->size[1];
            jj->size[1] = b_idx->size[1];
            jj->size[0] = 1;
            emxEnsureCapacity_int32_T(jj, q);
            idx = b_idx->size[1];
            for (q = 0; q < idx; q++) {
              jj->data[q] = b_idx->data[q];
            }
          }
        }

        q = E->size[0] * E->size[1];
        E->size[1] = jj->size[1];
        E->size[0] = 1;
        emxEnsureCapacity_int32_T(E, q);
        idx = jj->size[1];
        for (q = 0; q < idx; q++) {
          E->data[q] = jj->data[q];
        }

        /* 'funcionCPrO:71' ~ */
        /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
        /* 'funcionCPrO:72' [~,A]=find(auxUPxA(allA)<=EndCPrOAxD); */
        q = x->size[0] * x->size[1];
        x->size[1] = allA->size[1];
        x->size[0] = 1;
        emxEnsureCapacity_boolean_T(x, q);
        idx = allA->size[1];
        for (q = 0; q < idx; q++) {
          x->data[q] = (r33->data[allA->data[q] - 1] <= b_EndCPrOAxD);
        }

        if (x->size[1] == 0) {
          jj->size[1] = 0;
          jj->size[0] = 1;
        } else {
          idx = 0;
          nm1 = (unsigned int)x->size[1];
          q = jj->size[0] * jj->size[1];
          jj->size[1] = (int)nm1;
          jj->size[0] = 1;
          emxEnsureCapacity_int32_T(jj, q);
          yk = 1;
          exitg2 = false;
          while ((!exitg2) && (yk <= x->size[1])) {
            if (x->data[yk - 1]) {
              idx++;
              jj->data[idx - 1] = yk;
              if (idx >= x->size[1]) {
                exitg2 = true;
              } else {
                yk++;
              }
            } else {
              yk++;
            }
          }

          if (x->size[1] == 1) {
            if (idx == 0) {
              jj->size[1] = 0;
              jj->size[0] = 1;
            }
          } else {
            if (1 > idx) {
              idx = 0;
            }

            q = r36->size[0];
            r36->size[0] = idx;
            emxEnsureCapacity_int32_T(r36, q);
            for (q = 0; q < idx; q++) {
              r36->data[q] = q;
            }

            yk = r36->size[0];
            q = b_idx->size[0] * b_idx->size[1];
            b_idx->size[1] = yk;
            b_idx->size[0] = 1;
            emxEnsureCapacity_int32_T(b_idx, q);
            for (q = 0; q < yk; q++) {
              b_idx->data[q] = jj->data[r36->data[q]];
            }

            q = jj->size[0] * jj->size[1];
            jj->size[1] = b_idx->size[1];
            jj->size[0] = 1;
            emxEnsureCapacity_int32_T(jj, q);
            idx = b_idx->size[1];
            for (q = 0; q < idx; q++) {
              jj->data[q] = b_idx->data[q];
            }
          }
        }

        q = A->size[0] * A->size[1];
        A->size[1] = jj->size[1];
        A->size[0] = 1;
        emxEnsureCapacity_int32_T(A, q);
        idx = jj->size[1];
        for (q = 0; q < idx; q++) {
          A->data[q] = jj->data[q];
        }

        /* 'funcionCPrO:72' ~ */
        /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
        /* 'funcionCPrO:73' [~,An]=find(auxUPxAn(allAn)<=EndCPrOAxD); */
        q = x->size[0] * x->size[1];
        x->size[1] = allAn->size[1];
        x->size[0] = 1;
        emxEnsureCapacity_boolean_T(x, q);
        idx = allAn->size[1];
        for (q = 0; q < idx; q++) {
          x->data[q] = (r34->data[allAn->data[q] - 1] <= b_EndCPrOAxD);
        }

        if (x->size[1] == 0) {
          jj->size[1] = 0;
          jj->size[0] = 1;
        } else {
          idx = 0;
          nm1 = (unsigned int)x->size[1];
          q = jj->size[0] * jj->size[1];
          jj->size[1] = (int)nm1;
          jj->size[0] = 1;
          emxEnsureCapacity_int32_T(jj, q);
          yk = 1;
          exitg2 = false;
          while ((!exitg2) && (yk <= x->size[1])) {
            if (x->data[yk - 1]) {
              idx++;
              jj->data[idx - 1] = yk;
              if (idx >= x->size[1]) {
                exitg2 = true;
              } else {
                yk++;
              }
            } else {
              yk++;
            }
          }

          if (x->size[1] == 1) {
            if (idx == 0) {
              jj->size[1] = 0;
              jj->size[0] = 1;
            }
          } else {
            if (1 > idx) {
              idx = 0;
            }

            q = r36->size[0];
            r36->size[0] = idx;
            emxEnsureCapacity_int32_T(r36, q);
            for (q = 0; q < idx; q++) {
              r36->data[q] = q;
            }

            yk = r36->size[0];
            q = b_idx->size[0] * b_idx->size[1];
            b_idx->size[1] = yk;
            b_idx->size[0] = 1;
            emxEnsureCapacity_int32_T(b_idx, q);
            for (q = 0; q < yk; q++) {
              b_idx->data[q] = jj->data[r36->data[q]];
            }

            q = jj->size[0] * jj->size[1];
            jj->size[1] = b_idx->size[1];
            jj->size[0] = 1;
            emxEnsureCapacity_int32_T(jj, q);
            idx = b_idx->size[1];
            for (q = 0; q < idx; q++) {
              jj->data[q] = b_idx->data[q];
            }
          }
        }

        q = An->size[0] * An->size[1];
        An->size[1] = jj->size[1];
        An->size[0] = 1;
        emxEnsureCapacity_int32_T(An, q);
        idx = jj->size[1];
        for (q = 0; q < idx; q++) {
          An->data[q] = jj->data[q];
        }

        /* 'funcionCPrO:73' ~ */
        /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
        /* 'funcionCPrO:74' [~,S]=find(auxUPxS(allS)<=EndCPrOAxD); */
        q = x->size[0] * x->size[1];
        x->size[1] = allS->size[1];
        x->size[0] = 1;
        emxEnsureCapacity_boolean_T(x, q);
        idx = allS->size[1];
        for (q = 0; q < idx; q++) {
          x->data[q] = (r35->data[allS->data[q] - 1] <= b_EndCPrOAxD);
        }

        if (x->size[1] == 0) {
          jj->size[1] = 0;
          jj->size[0] = 1;
        } else {
          idx = 0;
          nm1 = (unsigned int)x->size[1];
          q = jj->size[0] * jj->size[1];
          jj->size[1] = (int)nm1;
          jj->size[0] = 1;
          emxEnsureCapacity_int32_T(jj, q);
          yk = 1;
          exitg2 = false;
          while ((!exitg2) && (yk <= x->size[1])) {
            if (x->data[yk - 1]) {
              idx++;
              jj->data[idx - 1] = yk;
              if (idx >= x->size[1]) {
                exitg2 = true;
              } else {
                yk++;
              }
            } else {
              yk++;
            }
          }

          if (x->size[1] == 1) {
            if (idx == 0) {
              jj->size[1] = 0;
              jj->size[0] = 1;
            }
          } else {
            if (1 > idx) {
              idx = 0;
            }

            q = r36->size[0];
            r36->size[0] = idx;
            emxEnsureCapacity_int32_T(r36, q);
            for (q = 0; q < idx; q++) {
              r36->data[q] = q;
            }

            yk = r36->size[0];
            q = b_idx->size[0] * b_idx->size[1];
            b_idx->size[1] = yk;
            b_idx->size[0] = 1;
            emxEnsureCapacity_int32_T(b_idx, q);
            for (q = 0; q < yk; q++) {
              b_idx->data[q] = jj->data[r36->data[q]];
            }

            q = jj->size[0] * jj->size[1];
            jj->size[1] = b_idx->size[1];
            jj->size[0] = 1;
            emxEnsureCapacity_int32_T(jj, q);
            idx = b_idx->size[1];
            for (q = 0; q < idx; q++) {
              jj->data[q] = b_idx->data[q];
            }
          }
        }

        q = S->size[0] * S->size[1];
        S->size[1] = jj->size[1];
        S->size[0] = 1;
        emxEnsureCapacity_int32_T(S, q);
        idx = jj->size[1];
        for (q = 0; q < idx; q++) {
          S->data[q] = jj->data[q];
        }

        /* 'funcionCPrO:74' ~ */
        /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo.         */
        /* 'funcionCPrO:76' if TimeUsoCPO == 0 */
        if (TimeUsoCPO == 0) {
          /* 'funcionCPrO:77' CPO=0; */
          q = CPO->size[0] * CPO->size[1];
          CPO->size[1] = 1;
          CPO->size[0] = 1;
          emxEnsureCapacity_int32_T(CPO, q);
          CPO->data[0] = 0;

          /* 'funcionCPrO:78' IniCR=Dia(contDia,3)+EndCPrOAxD+TimeUsoS; */
          IniCR = ((Dia->data[minP_tmp] + b_EndCPrOAxD) + TimeUsoS) - 1;

          /* 'funcionCPrO:79' [~,CR]=find(sum(H(IniCR:IniCR+TimeUsoCR-1,sum(NumRec(1:6))+allCR))==0); */
          q = IniCR + TimeUsoCR;
          if (IniCR + 1 > q) {
            p = 0;
            q = 0;
          } else {
            p = IniCR;
          }

          y = NumRec[0];
          for (k = 0; k < 5; k++) {
            y += (double)NumRec[k + 1];
          }

          yk = r29->size[0] * r29->size[1];
          r29->size[1] = allCR->size[1];
          r29->size[0] = 1;
          emxEnsureCapacity_real_T(r29, yk);
          idx = allCR->size[1];
          for (yk = 0; yk < idx; yk++) {
            r29->data[yk] = y + (double)allCR->data[yk];
          }

          idx = r29->size[1];
          yk = b_H->size[0] * b_H->size[1];
          b_H->size[1] = idx;
          nb = q - p;
          b_H->size[0] = nb;
          emxEnsureCapacity_int32_T(b_H, yk);
          for (q = 0; q < nb; q++) {
            for (yk = 0; yk < idx; yk++) {
              b_H->data[yk + b_H->size[1] * q] = H->data[((int)r29->data[yk] +
                H->size[1] * (p + q)) - 1];
            }
          }

          c_sum(b_H, r29);
          q = x->size[0] * x->size[1];
          x->size[1] = r29->size[1];
          x->size[0] = 1;
          emxEnsureCapacity_boolean_T(x, q);
          idx = r29->size[1];
          for (q = 0; q < idx; q++) {
            x->data[q] = (r29->data[q] == 0.0);
          }

          if (x->size[1] == 0) {
            jj->size[1] = 0;
            jj->size[0] = 1;
          } else {
            idx = 0;
            nm1 = (unsigned int)x->size[1];
            q = jj->size[0] * jj->size[1];
            jj->size[1] = (int)nm1;
            jj->size[0] = 1;
            emxEnsureCapacity_int32_T(jj, q);
            yk = 1;
            exitg2 = false;
            while ((!exitg2) && (yk <= x->size[1])) {
              if (x->data[yk - 1]) {
                idx++;
                jj->data[idx - 1] = yk;
                if (idx >= x->size[1]) {
                  exitg2 = true;
                } else {
                  yk++;
                }
              } else {
                yk++;
              }
            }

            if (x->size[1] == 1) {
              if (idx == 0) {
                jj->size[1] = 0;
                jj->size[0] = 1;
              }
            } else {
              if (1 > idx) {
                idx = 0;
              }

              q = r36->size[0];
              r36->size[0] = idx;
              emxEnsureCapacity_int32_T(r36, q);
              for (q = 0; q < idx; q++) {
                r36->data[q] = q;
              }

              yk = r36->size[0];
              q = b_idx->size[0] * b_idx->size[1];
              b_idx->size[1] = yk;
              b_idx->size[0] = 1;
              emxEnsureCapacity_int32_T(b_idx, q);
              for (q = 0; q < yk; q++) {
                b_idx->data[q] = jj->data[r36->data[q]];
              }

              q = jj->size[0] * jj->size[1];
              jj->size[1] = b_idx->size[1];
              jj->size[0] = 1;
              emxEnsureCapacity_int32_T(jj, q);
              idx = b_idx->size[1];
              for (q = 0; q < idx; q++) {
                jj->data[q] = b_idx->data[q];
              }
            }
          }

          q = CR->size[0] * CR->size[1];
          CR->size[1] = jj->size[1];
          CR->size[0] = 1;
          emxEnsureCapacity_int32_T(CR, q);
          idx = jj->size[1];
          for (q = 0; q < idx; q++) {
            CR->data[q] = jj->data[q];
          }

          /* 'funcionCPrO:79' ~ */
        } else {
          /* 'funcionCPrO:80' else */
          /* 'funcionCPrO:81' IniCPO=Dia(contDia,3)+EndCPrOAxD+TimeUsoS; */
          IniCPO = ((Dia->data[minP_tmp] + b_EndCPrOAxD) + TimeUsoS) - 1;

          /* 'funcionCPrO:82' EndCPO=IniCPO+TimeUsoCPO-1; */
          EndCPO = (IniCPO + TimeUsoCPO) - 1;

          /* 'funcionCPrO:83' [~,CPO]=find(sum(H(IniCPO:EndCPO,sum(NumRec(1:5))+allCPO))==0); */
          if (IniCPO + 1 > EndCPO + 1) {
            q = 0;
            p = -1;
          } else {
            q = IniCPO;
            p = EndCPO;
          }

          y = ((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
               (double)NumRec[3]) + (double)NumRec[4];
          yk = r29->size[0] * r29->size[1];
          r29->size[1] = allCPO->size[1];
          r29->size[0] = 1;
          emxEnsureCapacity_real_T(r29, yk);
          idx = allCPO->size[1];
          for (yk = 0; yk < idx; yk++) {
            r29->data[yk] = y + (double)allCPO->data[yk];
          }

          idx = r29->size[1];
          yk = b_H->size[0] * b_H->size[1];
          b_H->size[1] = idx;
          nb = p - q;
          b_H->size[0] = nb + 1;
          emxEnsureCapacity_int32_T(b_H, yk);
          for (p = 0; p <= nb; p++) {
            for (yk = 0; yk < idx; yk++) {
              b_H->data[yk + b_H->size[1] * p] = H->data[((int)r29->data[yk] +
                H->size[1] * (q + p)) - 1];
            }
          }

          c_sum(b_H, r29);
          q = x->size[0] * x->size[1];
          x->size[1] = r29->size[1];
          x->size[0] = 1;
          emxEnsureCapacity_boolean_T(x, q);
          idx = r29->size[1];
          for (q = 0; q < idx; q++) {
            x->data[q] = (r29->data[q] == 0.0);
          }

          if (x->size[1] == 0) {
            jj->size[1] = 0;
            jj->size[0] = 1;
          } else {
            idx = 0;
            nm1 = (unsigned int)x->size[1];
            q = jj->size[0] * jj->size[1];
            jj->size[1] = (int)nm1;
            jj->size[0] = 1;
            emxEnsureCapacity_int32_T(jj, q);
            yk = 1;
            exitg2 = false;
            while ((!exitg2) && (yk <= x->size[1])) {
              if (x->data[yk - 1]) {
                idx++;
                jj->data[idx - 1] = yk;
                if (idx >= x->size[1]) {
                  exitg2 = true;
                } else {
                  yk++;
                }
              } else {
                yk++;
              }
            }

            if (x->size[1] == 1) {
              if (idx == 0) {
                jj->size[1] = 0;
                jj->size[0] = 1;
              }
            } else {
              if (1 > idx) {
                idx = 0;
              }

              q = r36->size[0];
              r36->size[0] = idx;
              emxEnsureCapacity_int32_T(r36, q);
              for (q = 0; q < idx; q++) {
                r36->data[q] = q;
              }

              yk = r36->size[0];
              q = b_idx->size[0] * b_idx->size[1];
              b_idx->size[1] = yk;
              b_idx->size[0] = 1;
              emxEnsureCapacity_int32_T(b_idx, q);
              for (q = 0; q < yk; q++) {
                b_idx->data[q] = jj->data[r36->data[q]];
              }

              q = jj->size[0] * jj->size[1];
              jj->size[1] = b_idx->size[1];
              jj->size[0] = 1;
              emxEnsureCapacity_int32_T(jj, q);
              idx = b_idx->size[1];
              for (q = 0; q < idx; q++) {
                jj->data[q] = b_idx->data[q];
              }
            }
          }

          q = CPO->size[0] * CPO->size[1];
          CPO->size[1] = jj->size[1];
          CPO->size[0] = 1;
          emxEnsureCapacity_int32_T(CPO, q);
          idx = jj->size[1];
          for (q = 0; q < idx; q++) {
            CPO->data[q] = jj->data[q];
          }

          /* 'funcionCPrO:83' ~ */
          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
          /* 'funcionCPrO:84' [~,CR]=find(sum(H(EndCPO+1:EndCPO+TimeUsoCR,sum(NumRec(1:6))+allCR))==0); */
          y = NumRec[0];
          for (k = 0; k < 5; k++) {
            y += (double)NumRec[k + 1];
          }

          q = r29->size[0] * r29->size[1];
          r29->size[1] = allCR->size[1];
          r29->size[0] = 1;
          emxEnsureCapacity_real_T(r29, q);
          idx = allCR->size[1];
          for (q = 0; q < idx; q++) {
            r29->data[q] = y + (double)allCR->data[q];
          }

          idx = r29->size[1];
          q = b_H->size[0] * b_H->size[1];
          b_H->size[1] = idx;
          b_H->size[0] = TimeUsoCR;
          emxEnsureCapacity_int32_T(b_H, q);
          for (q = 0; q < TimeUsoCR; q++) {
            for (p = 0; p < idx; p++) {
              b_H->data[p + b_H->size[1] * q] = H->data[((int)r29->data[p] +
                H->size[1] * ((q + EndCPO) + 1)) - 1];
            }
          }

          c_sum(b_H, r29);
          q = x->size[0] * x->size[1];
          x->size[1] = r29->size[1];
          x->size[0] = 1;
          emxEnsureCapacity_boolean_T(x, q);
          idx = r29->size[1];
          for (q = 0; q < idx; q++) {
            x->data[q] = (r29->data[q] == 0.0);
          }

          if (x->size[1] == 0) {
            jj->size[1] = 0;
            jj->size[0] = 1;
          } else {
            idx = 0;
            nm1 = (unsigned int)x->size[1];
            q = jj->size[0] * jj->size[1];
            jj->size[1] = (int)nm1;
            jj->size[0] = 1;
            emxEnsureCapacity_int32_T(jj, q);
            yk = 1;
            exitg2 = false;
            while ((!exitg2) && (yk <= x->size[1])) {
              if (x->data[yk - 1]) {
                idx++;
                jj->data[idx - 1] = yk;
                if (idx >= x->size[1]) {
                  exitg2 = true;
                } else {
                  yk++;
                }
              } else {
                yk++;
              }
            }

            if (x->size[1] == 1) {
              if (idx == 0) {
                jj->size[1] = 0;
                jj->size[0] = 1;
              }
            } else {
              if (1 > idx) {
                idx = 0;
              }

              q = r36->size[0];
              r36->size[0] = idx;
              emxEnsureCapacity_int32_T(r36, q);
              for (q = 0; q < idx; q++) {
                r36->data[q] = q;
              }

              yk = r36->size[0];
              q = b_idx->size[0] * b_idx->size[1];
              b_idx->size[1] = yk;
              b_idx->size[0] = 1;
              emxEnsureCapacity_int32_T(b_idx, q);
              for (q = 0; q < yk; q++) {
                b_idx->data[q] = jj->data[r36->data[q]];
              }

              q = jj->size[0] * jj->size[1];
              jj->size[1] = b_idx->size[1];
              jj->size[0] = 1;
              emxEnsureCapacity_int32_T(jj, q);
              idx = b_idx->size[1];
              for (q = 0; q < idx; q++) {
                jj->data[q] = b_idx->data[q];
              }
            }
          }

          q = CR->size[0] * CR->size[1];
          CR->size[1] = jj->size[1];
          CR->size[0] = 1;
          emxEnsureCapacity_int32_T(CR, q);
          idx = jj->size[1];
          for (q = 0; q < idx; q++) {
            CR->data[q] = jj->data[q];
          }

          /* 'funcionCPrO:84' ~ */
        }

        /* 'funcionCPrO:88' if ~isempty(CPO)&&~isempty(CR)&&~isempty(S)&&size(E,2)>=PME(end)&&size(A,2)>=PMA(end)&&size(An,2)>=PMAn(end) */
        if ((CPO->size[1] != 0) && (CR->size[1] != 0) && (S->size[1] != 0) &&
            (E->size[1] >= PME->data[PME->size[1] - 1]) && (A->size[1] >=
             PMA->data[PMA->size[1] - 1]) && (An->size[1] >= PMAn->data
             [PMAn->size[1] - 1])) {
          /* 'funcionCPrO:89' temCPrO = uCPrODisp(j); */
          temCPrO = (int)uCPrODisp->data[j];
          exitg1 = true;
        } else {
          j++;
        }
      }

      /* 'funcionCPrO:95' if temCPrO == -1 */
      if (temCPrO == -1) {
        /* 'funcionCPrO:97' tempUltPosRecXDia = tempUltPosRecXDia+1; */
        q = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        tempUltPosRecXDia->size[0] = 1;
        emxEnsureCapacity_int32_T(tempUltPosRecXDia, q);
        idx = tempUltPosRecXDia->size[1];
        for (q = 0; q < idx; q++) {
          tempUltPosRecXDia->data[q]++;
        }
      } else {
        /* 'funcionCPrO:99' else */
        /* 'funcionCPrO:101' CPrOA = int32(temCPrO); */
        b_CPrOA = temCPrO;

        /* 'funcionCPrO:102' IniCPrOA = Dia(contDia,3)+int32(auxUPxR(CPrOA)); */
        b_IniCPrOA = Dia->data[minP_tmp] + tempUltPosRecXDia->data[temCPrO - 1];

        /* 'funcionCPrO:103' EndCPrOA = IniCPrOA + TimeUsoCPrO-1; */
        b_EndCPrOA = b_IniCPrOA + TimeUsoCPrO;

        /* 'funcionCPrO:105' SA_double = allS(S(1)); */
        q = SA_double->size[0] * SA_double->size[1];
        SA_double->size[1] = 1;
        SA_double->size[0] = 1;
        emxEnsureCapacity_int32_T(SA_double, q);
        SA_double->data[0] = allS->data[S->data[0] - 1];

        /* 'funcionCPrO:106' IniSA = EndCPrOA+1; */
        b_IniSA = b_EndCPrOA;

        /* 'funcionCPrO:107' EndSA = IniSA+TimeUsoS-1; */
        b_EndSA = (b_EndCPrOA + TimeUsoS) - 1;

        /* 'funcionCPrO:109' EA_double = allE(E(1:PME(end))); */
        if (1 > PME->data[PME->size[1] - 1]) {
          idx = 0;
        } else {
          idx = PME->data[PME->size[1] - 1];
        }

        q = iwork->size[0];
        iwork->size[0] = idx;
        emxEnsureCapacity_int32_T(iwork, q);
        for (q = 0; q < idx; q++) {
          iwork->data[q] = q;
        }

        yk = iwork->size[0];
        q = EA_double->size[0] * EA_double->size[1];
        EA_double->size[1] = yk;
        EA_double->size[0] = 1;
        emxEnsureCapacity_int32_T(EA_double, q);
        for (q = 0; q < yk; q++) {
          EA_double->data[q] = allE->data[E->data[iwork->data[q]] - 1];
        }

        /* 'funcionCPrO:111' AA_double = allA(A(1:PMA(end))); */
        if (1 > PMA->data[PMA->size[1] - 1]) {
          idx = 0;
        } else {
          idx = PMA->data[PMA->size[1] - 1];
        }

        q = iwork->size[0];
        iwork->size[0] = idx;
        emxEnsureCapacity_int32_T(iwork, q);
        for (q = 0; q < idx; q++) {
          iwork->data[q] = q;
        }

        yk = iwork->size[0];
        q = AA_double->size[0] * AA_double->size[1];
        AA_double->size[1] = yk;
        AA_double->size[0] = 1;
        emxEnsureCapacity_int32_T(AA_double, q);
        for (q = 0; q < yk; q++) {
          AA_double->data[q] = allA->data[A->data[iwork->data[q]] - 1];
        }

        /* 'funcionCPrO:113' AnA_double = allAn(An(1:PMAn(end))); */
        if (1 > PMAn->data[PMAn->size[1] - 1]) {
          idx = 0;
        } else {
          idx = PMAn->data[PMAn->size[1] - 1];
        }

        q = iwork->size[0];
        iwork->size[0] = idx;
        emxEnsureCapacity_int32_T(iwork, q);
        for (q = 0; q < idx; q++) {
          iwork->data[q] = q;
        }

        yk = iwork->size[0];
        q = AnA_double->size[0] * AnA_double->size[1];
        AnA_double->size[1] = yk;
        AnA_double->size[0] = 1;
        emxEnsureCapacity_int32_T(AnA_double, q);
        for (q = 0; q < yk; q++) {
          AnA_double->data[q] = allAn->data[An->data[iwork->data[q]] - 1];
        }

        /* 'funcionCPrO:115' if TimeUsoCPO==0 */
        if (TimeUsoCPO == 0) {
          /* 'funcionCPrO:116' CPOA = int32(0); */
          b_CPOA = 0;

          /* 'funcionCPrO:117' IniCPOA = int32(0); */
          b_IniCPOA = -1;

          /* 'funcionCPrO:118' EndCPOA = int32(0); */
          b_EndCPOA = 0;

          /* 'funcionCPrO:120' CRA = int32(allCR(CR(1))); */
          b_CRA = allCR->data[CR->data[0] - 1];

          /* 'funcionCPrO:121' IniCRA = EndSA+1; */
          b_IniCRA = b_EndSA;

          /* 'funcionCPrO:122' EndCRA = IniCRA + TimeUsoCR-1; */
          b_EndCRA = b_EndSA + TimeUsoCR;
        } else {
          /* 'funcionCPrO:123' else */
          /* 'funcionCPrO:124' CPOA = int32(allCPO(CPO(1))); */
          b_CPOA = allCPO->data[CPO->data[0] - 1];

          /* 'funcionCPrO:125' IniCPOA = EndSA+1; */
          b_IniCPOA = b_EndSA;

          /* 'funcionCPrO:126' EndCPOA = IniCPOA + TimeUsoCPO-1; */
          b_EndCPOA = b_EndSA + TimeUsoCPO;

          /* 'funcionCPrO:128' CRA = int32(allCR(CR(1))); */
          b_CRA = allCR->data[CR->data[0] - 1];

          /* 'funcionCPrO:129' IniCRA = EndCPOA+1; */
          b_IniCRA = b_EndCPOA;

          /* 'funcionCPrO:130' EndCRA = IniCRA + TimeUsoCR-1; */
          b_EndCRA = b_EndCPOA + TimeUsoCR;
        }

        /* 'funcionCPrO:133' flag = false; */
        flag = false;
      }
    }
  }

  emxFree_int32_T(&b_H);
  emxFree_int32_T(&iwork);
  emxFree_int32_T(&b_idx);
  emxFree_int32_T(&b);
  emxFree_int32_T(&jj);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&r36);
  emxFree_int32_T(&r35);
  emxFree_int32_T(&r34);
  emxFree_int32_T(&r33);
  emxFree_uint32_T(&r32);
  emxFree_real_T(&r29);
  emxFree_int32_T(&allCR);
  emxFree_int32_T(&allCPO);
  emxFree_int32_T(&allS);
  emxFree_int32_T(&allAn);
  emxFree_int32_T(&allA);
  emxFree_int32_T(&allE);
  emxFree_int32_T(&u);
  emxFree_int32_T(&allC);
  emxFree_int32_T(&C);
  emxFree_uint32_T(&uCPrODisp);
  emxFree_int32_T(&CR);
  emxFree_int32_T(&CPO);
  emxFree_int32_T(&An);
  emxFree_int32_T(&A);
  emxFree_int32_T(&S);
  emxFree_int32_T(&E);

  /* 'funcionCPrO:140' EA = int32(EA_double); */
  q = EA->size[0] * EA->size[1];
  EA->size[1] = EA_double->size[1];
  EA->size[0] = 1;
  emxEnsureCapacity_int32_T(EA, q);
  idx = EA_double->size[1];
  for (q = 0; q < idx; q++) {
    EA->data[q] = EA_double->data[q];
  }

  emxFree_int32_T(&EA_double);

  /* 'funcionCPrO:141' AA = int32(AA_double); */
  q = AA->size[0] * AA->size[1];
  AA->size[1] = AA_double->size[1];
  AA->size[0] = 1;
  emxEnsureCapacity_int32_T(AA, q);
  idx = AA_double->size[1];
  for (q = 0; q < idx; q++) {
    AA->data[q] = AA_double->data[q];
  }

  emxFree_int32_T(&AA_double);

  /* 'funcionCPrO:142' AnA = int32(AnA_double); */
  q = AnA->size[0] * AnA->size[1];
  AnA->size[1] = AnA_double->size[1];
  AnA->size[0] = 1;
  emxEnsureCapacity_int32_T(AnA, q);
  idx = AnA_double->size[1];
  for (q = 0; q < idx; q++) {
    AnA->data[q] = AnA_double->data[q];
  }

  emxFree_int32_T(&AnA_double);

  /* 'funcionCPrO:143' SA = int32(SA_double); */
  q = SA->size[0] * SA->size[1];
  SA->size[1] = SA_double->size[1];
  SA->size[0] = 1;
  emxEnsureCapacity_int32_T(SA, q);
  idx = SA_double->size[1];
  for (q = 0; q < idx; q++) {
    SA->data[q] = SA_double->data[q];
  }

  emxFree_int32_T(&SA_double);
  *CPrOA = b_CPrOA;
  *IniCPrOA = b_IniCPrOA;
  *EndCPrOA = b_EndCPrOA - 1;
  *EndCPrOAxD = b_EndCPrOAxD;
  *IniSA = b_IniSA;
  *EndSA = b_EndSA;
  *EndRPxD = b_EndRPxD;
  *CPOA = b_CPOA;
  *IniCPOA = b_IniCPOA + 1;
  *EndCPOA = b_EndCPOA;
  *CRA = b_CRA;
  *IniCRA = b_IniCRA + 1;
  *EndCRA = b_EndCRA;
}

/*
 * File trailer for funcionCPrO.c
 *
 * [EOF]
 */
