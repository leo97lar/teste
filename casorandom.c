/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * casorandom.c
 *
 * Code generation for function 'casorandom'
 *
 */

/* Include files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "casorandom.h"
#include "model_emxutil.h"
#include "funcionCPrO.h"
#include "funcionDia.h"

/* Function Definitions */

/*
 * function [ schedule,DiaOp,EspMedOp ] = casorandom(NumTOp,H,NumRec,PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,Dia,UltPosRecXDia,TimeUsoRec,DispMExD)
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
  int i38;
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *DispME;
  emxArray_int32_T *EA;
  emxArray_int32_T *AA;
  emxArray_int32_T *AnA;
  emxArray_int32_T *SA;
  emxArray_int32_T *r11;
  emxArray_int32_T *b_PCPrO;
  emxArray_int32_T *b_PME;
  emxArray_int32_T *b_PMA;
  emxArray_int32_T *b_PMAn;
  emxArray_int32_T *b_PS;
  emxArray_int32_T *b_PCPO;
  emxArray_int32_T *b_PCR;
  int i;
  int contDia;
  int loop_ub;
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
  int i39;
  int NumRec_tmp;
  int i40;
  int k;
  int j;
  int i41;
  int i42;
  int i43;
  int i44;
  int i45;
  int i46;
  double y;

  /* UNTITLED4 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*     NCPrO  |    NME    |     NS    |     NA    |     NAn    |    NCPO     |   NCR */
  /*   Col 1-20 | Col 21-50 | Col 51-62 | Col 63-87 | Col 88-112 | Col 113-132 | Col 133-172 */
  /* 'casorandom:7' DiaOp = zeros(NumTOp,1, 'int32'); */
  /* 'casorandom:8' EspMedOp = zeros(NumTOp,2, 'int32'); */
  i38 = EspMedOp->size[0] * EspMedOp->size[1];
  EspMedOp->size[0] = NumTOp;
  EspMedOp->size[1] = 2;
  emxEnsureCapacity_int32_T(EspMedOp, i38);
  for (i38 = 0; i38 < NumTOp; i38++) {
    EspMedOp->data[i38] = 0;
  }

  for (i38 = 0; i38 < NumTOp; i38++) {
    EspMedOp->data[i38 + EspMedOp->size[0]] = 0;
  }

  /* 'casorandom:10' for i=1:NumTOp */
  i38 = DiaOp->size[0];
  DiaOp->size[0] = NumTOp;
  emxEnsureCapacity_int32_T(DiaOp, i38);
  emxInit_int32_T(&tempUltPosRecXDia, 2);
  emxInit_int32_T(&DispME, 2);
  emxInit_int32_T(&EA, 2);
  emxInit_int32_T(&AA, 2);
  emxInit_int32_T(&AnA, 2);
  emxInit_int32_T(&SA, 2);
  emxInit_int32_T(&r11, 1);
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
    loop_ub = PCPrO->size[1];
    i38 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPrO, i38);
    for (i38 = 0; i38 < loop_ub; i38++) {
      b_PCPrO->data[i38] = PCPrO->data[i + PCPrO->size[0] * i38];
    }

    funcionDia(NumRec, b_PCPrO, Dia, UltPosRecXDia, TimeUsoRec->data[i],
               TimeUsoRec->data[i + TimeUsoRec->size[0]], &contDia, DispMExD,
               tempUltPosRecXDia, DispME);

    /* 'casorandom:17' [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,AA,AnA,SA,IniSA,EndSA,EndRPxD,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,contDia] = ... */
    /* 'casorandom:18'         funcionCPrO( NumRec,PCPrO(i,:), PME(i,:),PMA(i,:),PMAn(i,:),PS(i,:),PCPO(i,:),PCR(i,:),H,Dia, UltPosRecXDia,... */
    /* 'casorandom:19'         TimeUsoRec(i,1), TimeUsoRec(i,2),TimeUsoRec(i,6),TimeUsoRec(i,7),contDia,tempUltPosRecXDia,DispMExD,DispME); */
    loop_ub = PCPrO->size[1];
    i38 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPrO, i38);
    for (i38 = 0; i38 < loop_ub; i38++) {
      b_PCPrO->data[i38] = PCPrO->data[i + PCPrO->size[0] * i38];
    }

    loop_ub = PME->size[1];
    i38 = b_PME->size[0] * b_PME->size[1];
    b_PME->size[0] = 1;
    b_PME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PME, i38);
    for (i38 = 0; i38 < loop_ub; i38++) {
      b_PME->data[i38] = PME->data[i + PME->size[0] * i38];
    }

    loop_ub = PMA->size[1];
    i38 = b_PMA->size[0] * b_PMA->size[1];
    b_PMA->size[0] = 1;
    b_PMA->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PMA, i38);
    for (i38 = 0; i38 < loop_ub; i38++) {
      b_PMA->data[i38] = PMA->data[i + PMA->size[0] * i38];
    }

    loop_ub = PMAn->size[1];
    i38 = b_PMAn->size[0] * b_PMAn->size[1];
    b_PMAn->size[0] = 1;
    b_PMAn->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PMAn, i38);
    for (i38 = 0; i38 < loop_ub; i38++) {
      b_PMAn->data[i38] = PMAn->data[i + PMAn->size[0] * i38];
    }

    loop_ub = PS->size[1];
    i38 = b_PS->size[0] * b_PS->size[1];
    b_PS->size[0] = 1;
    b_PS->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PS, i38);
    for (i38 = 0; i38 < loop_ub; i38++) {
      b_PS->data[i38] = PS->data[i + PS->size[0] * i38];
    }

    loop_ub = PCPO->size[1];
    i38 = b_PCPO->size[0] * b_PCPO->size[1];
    b_PCPO->size[0] = 1;
    b_PCPO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPO, i38);
    for (i38 = 0; i38 < loop_ub; i38++) {
      b_PCPO->data[i38] = PCPO->data[i + PCPO->size[0] * i38];
    }

    loop_ub = PCR->size[1];
    i38 = b_PCR->size[0] * b_PCR->size[1];
    b_PCR->size[0] = 1;
    b_PCR->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCR, i38);
    for (i38 = 0; i38 < loop_ub; i38++) {
      b_PCR->data[i38] = PCR->data[i + PCR->size[0] * i38];
    }

    funcionCPrO(NumRec, b_PCPrO, b_PME, b_PMA, b_PMAn, b_PS, b_PCPO, b_PCR, H,
                Dia, UltPosRecXDia, TimeUsoRec->data[i], TimeUsoRec->data[i +
                TimeUsoRec->size[0]], TimeUsoRec->data[i + TimeUsoRec->size[0] *
                5], TimeUsoRec->data[i + TimeUsoRec->size[0] * 6], &contDia,
                tempUltPosRecXDia, DispMExD, DispME, &CPrOA, &IniCPrOA,
                &EndCPrOA, &EndCPrOAxD, EA, AA, AnA, SA, &IniSA, &EndSA,
                &EndRPxD, &CPOA, &IniCPOA, &EndCPOA, &CRA, &IniCRA, &EndCRA);

    /* 'casorandom:21' DiaOp(i)=contDia; */
    DiaOp->data[i] = contDia;

    /* 'casorandom:23' H(IniCPrOA:EndCPrOA,CPrOA)=i; */
    if (IniCPrOA > EndCPrOA) {
      i38 = 0;
      i39 = 0;
    } else {
      i38 = IniCPrOA - 1;
      i39 = EndCPrOA;
    }

    loop_ub = i39 - i38;
    for (i39 = 0; i39 < loop_ub; i39++) {
      H->data[(i38 + i39) + H->size[0] * (CPrOA - 1)] = i + 1;
    }

    /* 'casorandom:24' UltPosRecXDia(contDia,CPrOA)=EndCPrOAxD; */
    UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (CPrOA - 1)) - 1] =
      EndCPrOAxD;

    /* 'casorandom:26' H(IniSA:EndSA,NumRec(1)+NumRec(2)+int32(SA))=i; */
    if (IniSA > EndSA) {
      i38 = 0;
      i39 = 0;
    } else {
      i38 = IniSA - 1;
      i39 = EndSA;
    }

    NumRec_tmp = NumRec[0] + NumRec[1];
    i40 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = SA->size[1];
    emxEnsureCapacity_int32_T(b_PCPrO, i40);
    loop_ub = SA->size[1];
    for (i40 = 0; i40 < loop_ub; i40++) {
      b_PCPrO->data[i40] = SA->data[i40] + NumRec_tmp;
    }

    i40 = r11->size[0];
    r11->size[0] = b_PCPrO->size[1];
    emxEnsureCapacity_int32_T(r11, i40);
    loop_ub = b_PCPrO->size[1];
    for (i40 = 0; i40 < loop_ub; i40++) {
      r11->data[i40] = b_PCPrO->data[i40];
    }

    k = i39 - i38;
    loop_ub = r11->size[0];
    for (i39 = 0; i39 < loop_ub; i39++) {
      for (i40 = 0; i40 < k; i40++) {
        H->data[(i38 + i40) + H->size[0] * (r11->data[i39] - 1)] = i + 1;
      }
    }

    /* 'casorandom:27' UltPosRecXDia(contDia,NumRec(1)+NumRec(2)+int32(SA))=EndRPxD; */
    loop_ub = r11->size[0];
    for (i38 = 0; i38 < loop_ub; i38++) {
      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (r11->data[i38] -
        1)) - 1] = EndRPxD;
    }

    /* 'casorandom:29' for j=1:size(EA,2) */
    i38 = EA->size[1];
    if (0 <= i38 - 1) {
      if (IniSA > EndSA) {
        i41 = 0;
        i42 = 0;
      } else {
        i41 = IniSA - 1;
        i42 = EndSA;
      }
    }

    for (j = 0; j < i38; j++) {
      /* 'casorandom:31' H(IniSA:EndSA,NumRec(1)+EA(j))=i; */
      k = NumRec[0] + EA->data[j];
      loop_ub = i42 - i41;
      for (i39 = 0; i39 < loop_ub; i39++) {
        H->data[(i41 + i39) + H->size[0] * (k - 1)] = i + 1;
      }

      /* 'casorandom:32' UltPosRecXDia(contDia,NumRec(1)+EA(j))=EndRPxD; */
      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * ((NumRec[0] +
        EA->data[j]) - 1)) - 1] = EndRPxD;

      /* 'casorandom:34' EspMedOp(i,j)=PME(i,EA(j)); */
      EspMedOp->data[i + EspMedOp->size[0] * j] = PME->data[i + PME->size[0] *
        (EA->data[j] - 1)];
    }

    /* 'casorandom:38' for j=1:size(AA,2) */
    i38 = AA->size[1];
    if (0 <= i38 - 1) {
      if (IniSA > EndSA) {
        i43 = 0;
        i44 = 0;
      } else {
        i43 = IniSA - 1;
        i44 = EndSA;
      }
    }

    for (j = 0; j < i38; j++) {
      /* 'casorandom:40' H(IniSA:EndSA,NumRec(1)+NumRec(2)+NumRec(3)+AA(j))=i; */
      k = (NumRec_tmp + NumRec[2]) + AA->data[j];
      loop_ub = i44 - i43;
      for (i39 = 0; i39 < loop_ub; i39++) {
        H->data[(i43 + i39) + H->size[0] * (k - 1)] = i + 1;
      }

      /* 'casorandom:41' UltPosRecXDia(contDia,NumRec(1)+NumRec(2)+NumRec(3)+AA(j))=EndRPxD; */
      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * ((((NumRec[0] +
        NumRec[1]) + NumRec[2]) + AA->data[j]) - 1)) - 1] = EndRPxD;
    }

    /* 'casorandom:45' for j=1:size(AnA,2) */
    i38 = AnA->size[1];
    if (0 <= i38 - 1) {
      if (IniSA > EndSA) {
        i45 = 0;
        i46 = 0;
      } else {
        i45 = IniSA - 1;
        i46 = EndSA;
      }
    }

    for (j = 0; j < i38; j++) {
      /* 'casorandom:47' H(IniSA:EndSA,NumRec(1)+NumRec(2)+NumRec(3)+NumRec(4)+AnA(j))=i; */
      k = (((NumRec[0] + NumRec[1]) + NumRec[2]) + NumRec[3]) + AnA->data[j];
      loop_ub = i46 - i45;
      for (i39 = 0; i39 < loop_ub; i39++) {
        H->data[(i45 + i39) + H->size[0] * (k - 1)] = i + 1;
      }

      /* 'casorandom:48' UltPosRecXDia(contDia,NumRec(1)+NumRec(2)+NumRec(3)+NumRec(4)+AnA(j))=EndRPxD; */
      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (((((NumRec[0] +
        NumRec[1]) + NumRec[2]) + NumRec[3]) + AnA->data[j]) - 1)) - 1] =
        EndRPxD;
    }

    /* 'casorandom:52' if IniCPOA == 0 */
    if (IniCPOA == 0) {
      /* 'casorandom:53' H(IniCRA:EndCRA,sum(NumRec(1:6))+CRA)=i; */
      if (IniCRA > EndCRA) {
        i38 = 0;
        i39 = 0;
      } else {
        i38 = IniCRA - 1;
        i39 = EndCRA;
      }

      y = NumRec[0];
      for (k = 0; k < 5; k++) {
        y += (double)NumRec[k + 1];
      }

      k = (int)(y + (double)CRA);
      loop_ub = i39 - i38;
      for (i39 = 0; i39 < loop_ub; i39++) {
        H->data[(i38 + i39) + H->size[0] * (k - 1)] = i + 1;
      }
    } else {
      /* 'casorandom:54' else */
      /* 'casorandom:55' H(IniCPOA:EndCPOA,sum(NumRec(1:5))+CPOA)=i; */
      if (IniCPOA > EndCPOA) {
        i38 = 0;
        i39 = 0;
      } else {
        i38 = IniCPOA - 1;
        i39 = EndCPOA;
      }

      k = (int)((((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2])
                  + (double)NumRec[3]) + (double)NumRec[4]) + (double)CPOA);
      loop_ub = i39 - i38;
      for (i39 = 0; i39 < loop_ub; i39++) {
        H->data[(i38 + i39) + H->size[0] * (k - 1)] = i + 1;
      }

      /* 'casorandom:56' H(IniCRA:EndCRA,sum(NumRec(1:6))+CRA)=i; */
      if (IniCRA > EndCRA) {
        i38 = 0;
        i39 = 0;
      } else {
        i38 = IniCRA - 1;
        i39 = EndCRA;
      }

      y = NumRec[0];
      for (k = 0; k < 5; k++) {
        y += (double)NumRec[k + 1];
      }

      k = (int)(y + (double)CRA);
      loop_ub = i39 - i38;
      for (i39 = 0; i39 < loop_ub; i39++) {
        H->data[(i38 + i39) + H->size[0] * (k - 1)] = i + 1;
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
  emxFree_int32_T(&r11);
  emxFree_int32_T(&SA);
  emxFree_int32_T(&AnA);
  emxFree_int32_T(&AA);
  emxFree_int32_T(&EA);
  emxFree_int32_T(&DispME);
  emxFree_int32_T(&tempUltPosRecXDia);

  /* 'casorandom:62' schedule=H; */
}

/* End of code generation (casorandom.c) */
