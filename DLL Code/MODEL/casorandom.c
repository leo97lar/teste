/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: casorandom.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
#include "pch.h"

#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "casorandom.h"
#include "model_emxutil.h"
#include "funcionCPrO.h"
#include "funcionDia.h"

/* Function Definitions */

/*
 * function [ schedule,DiaOp,EspMedOp ] = casorandom(NumTOp,H,NumRec,PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,Dia,UltPosRecXDia,TimeUsoRec,DispMExD)
 * UNTITLED4 Summary of this function goes here
 *    Detailed explanation goes here
 *     NCPrO  |    NME    |     NS    |     NA    |     NAn    |    NCPO     |   NCR
 *   Col 1-20 | Col 21-50 | Col 51-62 | Col 63-87 | Col 88-112 | Col 113-132 | Col 133-172
 * Arguments    : int NumTOp
 *                emxArray_int32_T *H
 *                const int NumRec[7]
 *                const emxArray_int32_T *PCPrO
 *                const emxArray_int32_T *PME
 *                const emxArray_int32_T *PMA
 *                const emxArray_int32_T *PMAn
 *                const emxArray_int32_T *PS
 *                const emxArray_int32_T *PCPO
 *                const emxArray_int32_T *PCR
 *                const emxArray_int32_T *Dia
 *                emxArray_int32_T *UltPosRecXDia
 *                const emxArray_int32_T *TimeUsoRec
 *                const emxArray_int32_T *DispMExD
 *                emxArray_int32_T *DiaOp
 *                emxArray_int32_T *EspMedOp
 * Return Type  : void
 */
void casorandom(int NumTOp, emxArray_int32_T *H, const int NumRec[7], const
                emxArray_int32_T *PCPrO, const emxArray_int32_T *PME, const
                emxArray_int32_T *PMA, const emxArray_int32_T *PMAn, const
                emxArray_int32_T *PS, const emxArray_int32_T *PCPO, const
                emxArray_int32_T *PCR, const emxArray_int32_T *Dia,
                emxArray_int32_T *UltPosRecXDia, const emxArray_int32_T
                *TimeUsoRec, const emxArray_int32_T *DispMExD, emxArray_int32_T *
                DiaOp, emxArray_int32_T *EspMedOp)
{
  int i42;
  int loop_ub;
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *DispME;
  emxArray_int32_T *EA;
  emxArray_int32_T *AA;
  emxArray_int32_T *AnA;
  emxArray_int32_T *SA;
  emxArray_int32_T *b_PCPrO;
  emxArray_int32_T *b_PME;
  emxArray_int32_T *b_PMA;
  emxArray_int32_T *b_PMAn;
  emxArray_int32_T *b_PS;
  emxArray_int32_T *b_PCPO;
  emxArray_int32_T *b_PCR;
  int i;
  int contDia;
  int b_loop_ub;
  int k;
  int c_loop_ub;
  int d_loop_ub;
  int e_loop_ub;
  int f_loop_ub;
  int CPrOA;
  int IniCPrOA;
  int EndCPrOA;
  int EndCPrOAxD;
  int IniSA;
  int EndSA;
  int EndRPxD;
  int CPOA;
  int IniCPOA;
  int EndCPOA;
  int CRA;
  int IniCRA;
  int EndCRA;
  int j;
  int i43;
  int i44;
  int i45;
  int i46;
  int i47;
  int i48;
  double y;

  /* 'casorandom:7' DiaOp = zeros(NumTOp,1, 'int32'); */
  /* 'casorandom:8' EspMedOp = zeros(NumTOp,2, 'int32'); */
  i42 = EspMedOp->size[0] * EspMedOp->size[1];
  EspMedOp->size[1] = 2;
  EspMedOp->size[0] = NumTOp;
  emxEnsureCapacity_int32_T(EspMedOp, i42);
  for (i42 = 0; i42 < NumTOp; i42++) {
    loop_ub = i42 << 1;
    EspMedOp->data[loop_ub] = 0;
    EspMedOp->data[1 + loop_ub] = 0;
  }

  /* 'casorandom:10' for i=1:NumTOp */
  i42 = DiaOp->size[0];
  DiaOp->size[0] = NumTOp;
  emxEnsureCapacity_int32_T(DiaOp, i42);
  emxInit_int32_T(&tempUltPosRecXDia, 2);
  emxInit_int32_T(&DispME, 2);
  emxInit_int32_T(&EA, 2);
  emxInit_int32_T(&AA, 2);
  emxInit_int32_T(&AnA, 2);
  emxInit_int32_T(&SA, 2);
  emxInit_int32_T(&b_PCPrO, 2);
  emxInit_int32_T(&b_PME, 2);
  emxInit_int32_T(&b_PMA, 2);
  emxInit_int32_T(&b_PMAn, 2);
  emxInit_int32_T(&b_PS, 2);
  emxInit_int32_T(&b_PCPO, 2);
  emxInit_int32_T(&b_PCR, 2);
  for (i = 0; i < NumTOp; i++) {
    /* 'casorandom:12' contDia = int32(2); */
    /* 'casorandom:14' [contDia,tempUltPosRecXDia,DispME] = funcionDia( NumRec,PCPrO(i,:), Dia,UltPosRecXDia,... */
    /* 'casorandom:15'         TimeUsoRec(i,1),TimeUsoRec(i,2),contDia,DispMExD); */
    contDia = 2;
    b_loop_ub = PCPrO->size[1];
    i42 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[1] = b_loop_ub;
    b_PCPrO->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PCPrO, i42);
    for (i42 = 0; i42 < b_loop_ub; i42++) {
      b_PCPrO->data[i42] = PCPrO->data[i42 + PCPrO->size[1] * i];
    }

    funcionDia(NumRec, b_PCPrO, Dia, UltPosRecXDia, TimeUsoRec->data[7 * i],
               TimeUsoRec->data[1 + 7 * i], &contDia, DispMExD,
               tempUltPosRecXDia, DispME);

    /* 'casorandom:17' [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,AA,AnA,SA,IniSA,EndSA,EndRPxD,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,contDia] = ... */
    /* 'casorandom:18'         funcionCPrO( NumRec,PCPrO(i,:), PME(i,:),PMA(i,:),PMAn(i,:),PS(i,:),PCPO(i,:),PCR(i,:),H,Dia, UltPosRecXDia,... */
    /* 'casorandom:19'         TimeUsoRec(i,1), TimeUsoRec(i,2),TimeUsoRec(i,6),TimeUsoRec(i,7),contDia,tempUltPosRecXDia,DispMExD,DispME); */
    b_loop_ub = PCPrO->size[1];
    k = PME->size[1];
    c_loop_ub = PMA->size[1];
    d_loop_ub = PMAn->size[1];
    loop_ub = PS->size[1];
    e_loop_ub = PCPO->size[1];
    f_loop_ub = PCR->size[1];
    i42 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[1] = b_loop_ub;
    b_PCPrO->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PCPrO, i42);
    for (i42 = 0; i42 < b_loop_ub; i42++) {
      b_PCPrO->data[i42] = PCPrO->data[i42 + PCPrO->size[1] * i];
    }

    i42 = b_PME->size[0] * b_PME->size[1];
    b_PME->size[1] = k;
    b_PME->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PME, i42);
    for (i42 = 0; i42 < k; i42++) {
      b_PME->data[i42] = PME->data[i42 + PME->size[1] * i];
    }

    i42 = b_PMA->size[0] * b_PMA->size[1];
    b_PMA->size[1] = c_loop_ub;
    b_PMA->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PMA, i42);
    for (i42 = 0; i42 < c_loop_ub; i42++) {
      b_PMA->data[i42] = PMA->data[i42 + PMA->size[1] * i];
    }

    i42 = b_PMAn->size[0] * b_PMAn->size[1];
    b_PMAn->size[1] = d_loop_ub;
    b_PMAn->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PMAn, i42);
    for (i42 = 0; i42 < d_loop_ub; i42++) {
      b_PMAn->data[i42] = PMAn->data[i42 + PMAn->size[1] * i];
    }

    i42 = b_PS->size[0] * b_PS->size[1];
    b_PS->size[1] = loop_ub;
    b_PS->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PS, i42);
    for (i42 = 0; i42 < loop_ub; i42++) {
      b_PS->data[i42] = PS->data[i42 + PS->size[1] * i];
    }

    i42 = b_PCPO->size[0] * b_PCPO->size[1];
    b_PCPO->size[1] = e_loop_ub;
    b_PCPO->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PCPO, i42);
    for (i42 = 0; i42 < e_loop_ub; i42++) {
      b_PCPO->data[i42] = PCPO->data[i42 + PCPO->size[1] * i];
    }

    i42 = b_PCR->size[0] * b_PCR->size[1];
    b_PCR->size[1] = f_loop_ub;
    b_PCR->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PCR, i42);
    for (i42 = 0; i42 < f_loop_ub; i42++) {
      b_PCR->data[i42] = PCR->data[i42 + PCR->size[1] * i];
    }

    funcionCPrO(NumRec, b_PCPrO, b_PME, b_PMA, b_PMAn, b_PS, b_PCPO, b_PCR, H,
                Dia, UltPosRecXDia, TimeUsoRec->data[7 * i], TimeUsoRec->data[1
                + 7 * i], TimeUsoRec->data[5 + 7 * i], TimeUsoRec->data[6 + 7 *
                i], &contDia, tempUltPosRecXDia, DispMExD, DispME, &CPrOA,
                &IniCPrOA, &EndCPrOA, &EndCPrOAxD, EA, AA, AnA, SA, &IniSA,
                &EndSA, &EndRPxD, &CPOA, &IniCPOA, &EndCPOA, &CRA, &IniCRA,
                &EndCRA);

    /* 'casorandom:21' DiaOp(i)=contDia; */
    DiaOp->data[i] = contDia;

    /* 'casorandom:23' H(IniCPrOA:EndCPrOA,CPrOA)=i; */
    if (IniCPrOA > EndCPrOA) {
      i42 = 0;
      loop_ub = 0;
    } else {
      i42 = IniCPrOA - 1;
      loop_ub = EndCPrOA;
    }

    b_loop_ub = loop_ub - i42;
    for (loop_ub = 0; loop_ub < b_loop_ub; loop_ub++) {
      H->data[(CPrOA + H->size[1] * (i42 + loop_ub)) - 1] = i + 1;
    }

    /* 'casorandom:24' UltPosRecXDia(contDia,CPrOA)=EndCPrOAxD; */
    UltPosRecXDia->data[(CPrOA + UltPosRecXDia->size[1] * (contDia - 1)) - 1] =
      EndCPrOAxD;

    /* 'casorandom:26' H(IniSA:EndSA,NumRec(1)+NumRec(2)+int32(SA))=i; */
    if (IniSA > EndSA) {
      i42 = 0;
      loop_ub = 0;
    } else {
      i42 = IniSA - 1;
      loop_ub = EndSA;
    }

    d_loop_ub = NumRec[0] + NumRec[1];
    k = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[1] = SA->size[1];
    b_PCPrO->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PCPrO, k);
    b_loop_ub = SA->size[1];
    for (k = 0; k < b_loop_ub; k++) {
      b_PCPrO->data[k] = SA->data[k] + d_loop_ub;
    }

    c_loop_ub = b_PCPrO->size[1];
    b_loop_ub = loop_ub - i42;
    for (loop_ub = 0; loop_ub < b_loop_ub; loop_ub++) {
      for (k = 0; k < c_loop_ub; k++) {
        H->data[(b_PCPrO->data[k] + H->size[1] * (i42 + loop_ub)) - 1] = i + 1;
      }
    }

    /* 'casorandom:27' UltPosRecXDia(contDia,NumRec(1)+NumRec(2)+int32(SA))=EndRPxD; */
    c_loop_ub = b_PCPrO->size[1];
    for (i42 = 0; i42 < c_loop_ub; i42++) {
      UltPosRecXDia->data[(b_PCPrO->data[i42] + UltPosRecXDia->size[1] *
                           (contDia - 1)) - 1] = EndRPxD;
    }

    /* 'casorandom:29' for j=1:size(EA,2) */
    i42 = EA->size[1];
    if (0 <= i42 - 1) {
      if (IniSA > EndSA) {
        i43 = 0;
        i44 = 0;
      } else {
        i43 = IniSA - 1;
        i44 = EndSA;
      }
    }

    for (j = 0; j < i42; j++) {
      /* 'casorandom:31' H(IniSA:EndSA,NumRec(1)+EA(j))=i; */
      k = NumRec[0] + EA->data[j];
      b_loop_ub = i44 - i43;
      for (loop_ub = 0; loop_ub < b_loop_ub; loop_ub++) {
        H->data[(k + H->size[1] * (i43 + loop_ub)) - 1] = i + 1;
      }

      /* 'casorandom:32' UltPosRecXDia(contDia,NumRec(1)+EA(j))=EndRPxD; */
      UltPosRecXDia->data[((NumRec[0] + EA->data[j]) + UltPosRecXDia->size[1] *
                           (contDia - 1)) - 1] = EndRPxD;

      /* 'casorandom:34' EspMedOp(i,j)=PME(i,EA(j)); */
      EspMedOp->data[j + (i << 1)] = PME->data[(EA->data[j] + PME->size[1] * i)
        - 1];
    }

    /* 'casorandom:38' for j=1:size(AA,2) */
    i42 = AA->size[1];
    if (0 <= i42 - 1) {
      if (IniSA > EndSA) {
        i45 = 0;
        i46 = 0;
      } else {
        i45 = IniSA - 1;
        i46 = EndSA;
      }
    }

    for (j = 0; j < i42; j++) {
      /* 'casorandom:40' H(IniSA:EndSA,NumRec(1)+NumRec(2)+NumRec(3)+AA(j))=i; */
      k = (d_loop_ub + NumRec[2]) + AA->data[j];
      b_loop_ub = i46 - i45;
      for (loop_ub = 0; loop_ub < b_loop_ub; loop_ub++) {
        H->data[(k + H->size[1] * (i45 + loop_ub)) - 1] = i + 1;
      }

      /* 'casorandom:41' UltPosRecXDia(contDia,NumRec(1)+NumRec(2)+NumRec(3)+AA(j))=EndRPxD; */
      UltPosRecXDia->data[((((NumRec[0] + NumRec[1]) + NumRec[2]) + AA->data[j])
                           + UltPosRecXDia->size[1] * (contDia - 1)) - 1] =
        EndRPxD;
    }

    /* 'casorandom:45' for j=1:size(AnA,2) */
    i42 = AnA->size[1];
    if (0 <= i42 - 1) {
      if (IniSA > EndSA) {
        i47 = 0;
        i48 = 0;
      } else {
        i47 = IniSA - 1;
        i48 = EndSA;
      }
    }

    for (j = 0; j < i42; j++) {
      /* 'casorandom:47' H(IniSA:EndSA,NumRec(1)+NumRec(2)+NumRec(3)+NumRec(4)+AnA(j))=i; */
      k = (((NumRec[0] + NumRec[1]) + NumRec[2]) + NumRec[3]) + AnA->data[j];
      b_loop_ub = i48 - i47;
      for (loop_ub = 0; loop_ub < b_loop_ub; loop_ub++) {
        H->data[(k + H->size[1] * (i47 + loop_ub)) - 1] = i + 1;
      }

      /* 'casorandom:48' UltPosRecXDia(contDia,NumRec(1)+NumRec(2)+NumRec(3)+NumRec(4)+AnA(j))=EndRPxD; */
      UltPosRecXDia->data[(((((NumRec[0] + NumRec[1]) + NumRec[2]) + NumRec[3])
                            + AnA->data[j]) + UltPosRecXDia->size[1] * (contDia
        - 1)) - 1] = EndRPxD;
    }

    /* 'casorandom:52' if IniCPOA == 0 */
    if (IniCPOA == 0) {
      /* 'casorandom:53' H(IniCRA:EndCRA,sum(NumRec(1:6))+CRA)=i; */
      if (IniCRA > EndCRA) {
        i42 = 0;
        loop_ub = 0;
      } else {
        i42 = IniCRA - 1;
        loop_ub = EndCRA;
      }

      y = NumRec[0];
      for (k = 0; k < 5; k++) {
        y += (double)NumRec[k + 1];
      }

      k = (int)(y + (double)CRA);
      b_loop_ub = loop_ub - i42;
      for (loop_ub = 0; loop_ub < b_loop_ub; loop_ub++) {
        H->data[(k + H->size[1] * (i42 + loop_ub)) - 1] = i + 1;
      }
    } else {
      /* 'casorandom:54' else */
      /* 'casorandom:55' H(IniCPOA:EndCPOA,sum(NumRec(1:5))+CPOA)=i; */
      if (IniCPOA > EndCPOA) {
        i42 = 0;
        loop_ub = 0;
      } else {
        i42 = IniCPOA - 1;
        loop_ub = EndCPOA;
      }

      k = (int)((((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2])
                  + (double)NumRec[3]) + (double)NumRec[4]) + (double)CPOA);
      b_loop_ub = loop_ub - i42;
      for (loop_ub = 0; loop_ub < b_loop_ub; loop_ub++) {
        H->data[(k + H->size[1] * (i42 + loop_ub)) - 1] = i + 1;
      }

      /* 'casorandom:56' H(IniCRA:EndCRA,sum(NumRec(1:6))+CRA)=i; */
      if (IniCRA > EndCRA) {
        i42 = 0;
        loop_ub = 0;
      } else {
        i42 = IniCRA - 1;
        loop_ub = EndCRA;
      }

      y = NumRec[0];
      for (k = 0; k < 5; k++) {
        y += (double)NumRec[k + 1];
      }

      k = (int)(y + (double)CRA);
      b_loop_ub = loop_ub - i42;
      for (loop_ub = 0; loop_ub < b_loop_ub; loop_ub++) {
        H->data[(k + H->size[1] * (i42 + loop_ub)) - 1] = i + 1;
      }
    }
  }

  emxFree_int32_T(&b_PCR);
  emxFree_int32_T(&b_PCPO);
  emxFree_int32_T(&b_PS);
  emxFree_int32_T(&b_PMAn);
  emxFree_int32_T(&b_PMA);
  emxFree_int32_T(&b_PME);
  emxFree_int32_T(&b_PCPrO);
  emxFree_int32_T(&SA);
  emxFree_int32_T(&AnA);
  emxFree_int32_T(&AA);
  emxFree_int32_T(&EA);
  emxFree_int32_T(&DispME);
  emxFree_int32_T(&tempUltPosRecXDia);

  /* 'casorandom:62' schedule=H; */
}

/*
 * File trailer for casorandom.c
 *
 * [EOF]
 */
