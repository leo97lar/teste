/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sch.c
 *
 * Code generation for function 'sch'
 *
 */

/* Include files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "sch.h"
#include "model_emxutil.h"
#include "favalia.h"
#include "funcionCPrO.h"
#include "funcionDia.h"

/* Function Definitions */

/*
 * function [ fitness,Tt,NOFP,TmNOFP,NOE2,NOE3 ] = sch(NumTOp,list,NumRec,PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,Dia,Data,TimeUsoRec,DispMExD,EP,k0,k1,k2,k3)
 */
void sch(int NumTOp, const emxArray_int32_T *list, const int NumRec[7],
         emxArray_int32_T *PCPrO, emxArray_int32_T *PME, emxArray_int32_T *PMA,
         emxArray_int32_T *PMAn, emxArray_int32_T *PS, emxArray_int32_T *PCPO,
         emxArray_int32_T *PCR, const emxArray_int32_T *Dia, const
         emxArray_int32_T *Data, emxArray_int32_T *TimeUsoRec, const
         emxArray_int32_T *DispMExD, emxArray_int32_T *EP, double k0, double k1,
         double k2, double k3, double *fitness, double *Tt, double *NOFP, double
         *TmNOFP, double *NOE2, double *NOE3)
{
  double y;
  int k;
  emxArray_real_T *H;
  int Data_idx_0;
  int i21;
  int loop_ub;
  emxArray_real_T *UltPosRecXDia;
  int i22;
  emxArray_real_T *EspMedOp;
  emxArray_int32_T *b_TimeUsoRec;
  emxArray_int32_T *b_PME;
  emxArray_int32_T *b_EP;
  emxArray_int32_T *DiaOp;
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *DispME;
  emxArray_int32_T *EA;
  emxArray_int32_T *AA;
  emxArray_int32_T *AnA;
  emxArray_int32_T *SA;
  emxArray_int32_T *b_PCPrO;
  emxArray_int32_T *c_PME;
  emxArray_int32_T *b_PMA;
  emxArray_int32_T *b_PMAn;
  emxArray_int32_T *b_PS;
  emxArray_int32_T *b_PCPO;
  emxArray_int32_T *b_PCR;
  int i;
  int contDia;
  double d4;
  double d5;
  double d6;
  double d7;
  double d8;
  double d9;
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
  int NumRec_tmp;
  int i23;
  int j;
  int i24;
  int i25;
  int i26;
  int i27;
  int i28;
  int i29;

  /* UNTITLED4 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*     NCPrO  |    NME    |     NS    |     NA    |     NAn    |    NCPO     |   NCR */
  /*   Col 1-20 | Col 21-50 | Col 51-62 | Col 63-87 | Col 88-112 | Col 113-132 | Col 133-152 */
  /* 'sch:7' H = zeros(size(Data,1),sum(NumRec)); */
  y = NumRec[0];
  for (k = 0; k < 6; k++) {
    y += (double)NumRec[k + 1];
  }

  emxInit_real_T(&H, 2);
  Data_idx_0 = Data->size[0];
  i21 = H->size[0] * H->size[1];
  H->size[0] = Data_idx_0;
  loop_ub = (int)y;
  H->size[1] = loop_ub;
  emxEnsureCapacity_real_T(H, i21);
  for (i21 = 0; i21 < loop_ub; i21++) {
    for (i22 = 0; i22 < Data_idx_0; i22++) {
      H->data[i22 + H->size[0] * i21] = 0.0;
    }
  }

  emxInit_real_T(&UltPosRecXDia, 2);

  /*  Schedule completo */
  /* 'sch:8' UltPosRecXDia = zeros(size(Dia,1),size(H,2)); */
  Data_idx_0 = Dia->size[0];
  i21 = UltPosRecXDia->size[0] * UltPosRecXDia->size[1];
  UltPosRecXDia->size[0] = Data_idx_0;
  UltPosRecXDia->size[1] = loop_ub;
  emxEnsureCapacity_real_T(UltPosRecXDia, i21);
  for (i21 = 0; i21 < loop_ub; i21++) {
    for (i22 = 0; i22 < Data_idx_0; i22++) {
      UltPosRecXDia->data[i22 + UltPosRecXDia->size[0] * i21] = 0.0;
    }
  }

  emxInit_real_T(&EspMedOp, 2);

  /*  Ultima posicion asignado del recurso por Dia */
  /* 'sch:10' DiaOp = zeros(NumTOp,1, 'int32'); */
  /* 'sch:11' EspMedOp = zeros(NumTOp,2); */
  i21 = EspMedOp->size[0] * EspMedOp->size[1];
  EspMedOp->size[0] = NumTOp;
  EspMedOp->size[1] = 2;
  emxEnsureCapacity_real_T(EspMedOp, i21);
  for (i21 = 0; i21 < NumTOp; i21++) {
    EspMedOp->data[i21] = 0.0;
  }

  for (i21 = 0; i21 < NumTOp; i21++) {
    EspMedOp->data[i21 + EspMedOp->size[0]] = 0.0;
  }

  emxInit_int32_T(&b_TimeUsoRec, 2);

  /* 'sch:13' TimeUsoRec=TimeUsoRec(list,:); */
  i21 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[0] = list->size[0];
  b_TimeUsoRec->size[1] = 7;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i21);
  for (i21 = 0; i21 < 7; i21++) {
    loop_ub = list->size[0];
    for (i22 = 0; i22 < loop_ub; i22++) {
      b_TimeUsoRec->data[i22 + b_TimeUsoRec->size[0] * i21] = TimeUsoRec->data
        [(list->data[i22] + TimeUsoRec->size[0] * i21) - 1];
    }
  }

  i21 = TimeUsoRec->size[0] * TimeUsoRec->size[1];
  TimeUsoRec->size[0] = b_TimeUsoRec->size[0];
  TimeUsoRec->size[1] = 7;
  emxEnsureCapacity_int32_T(TimeUsoRec, i21);
  for (i21 = 0; i21 < 7; i21++) {
    loop_ub = b_TimeUsoRec->size[0];
    for (i22 = 0; i22 < loop_ub; i22++) {
      TimeUsoRec->data[i22 + TimeUsoRec->size[0] * i21] = b_TimeUsoRec->data[i22
        + b_TimeUsoRec->size[0] * i21];
    }
  }

  emxFree_int32_T(&b_TimeUsoRec);
  emxInit_int32_T(&b_PME, 2);

  /* 'sch:15' PME=PME(list,:); */
  loop_ub = PME->size[1] - 1;
  i21 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i21);
  for (i21 = 0; i21 <= loop_ub; i21++) {
    k = list->size[0];
    for (i22 = 0; i22 < k; i22++) {
      b_PME->data[i22 + b_PME->size[0] * i21] = PME->data[(list->data[i22] +
        PME->size[0] * i21) - 1];
    }
  }

  i21 = PME->size[0] * PME->size[1];
  PME->size[0] = b_PME->size[0];
  PME->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PME, i21);
  loop_ub = b_PME->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    k = b_PME->size[0];
    for (i22 = 0; i22 < k; i22++) {
      PME->data[i22 + PME->size[0] * i21] = b_PME->data[i22 + b_PME->size[0] *
        i21];
    }
  }

  /* 'sch:16' PMA=PMA(list,:); */
  loop_ub = PMA->size[1] - 1;
  i21 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i21);
  for (i21 = 0; i21 <= loop_ub; i21++) {
    k = list->size[0];
    for (i22 = 0; i22 < k; i22++) {
      b_PME->data[i22 + b_PME->size[0] * i21] = PMA->data[(list->data[i22] +
        PMA->size[0] * i21) - 1];
    }
  }

  i21 = PMA->size[0] * PMA->size[1];
  PMA->size[0] = b_PME->size[0];
  PMA->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PMA, i21);
  loop_ub = b_PME->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    k = b_PME->size[0];
    for (i22 = 0; i22 < k; i22++) {
      PMA->data[i22 + PMA->size[0] * i21] = b_PME->data[i22 + b_PME->size[0] *
        i21];
    }
  }

  /* 'sch:17' PMAn=PMAn(list,:); */
  loop_ub = PMAn->size[1] - 1;
  i21 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i21);
  for (i21 = 0; i21 <= loop_ub; i21++) {
    k = list->size[0];
    for (i22 = 0; i22 < k; i22++) {
      b_PME->data[i22 + b_PME->size[0] * i21] = PMAn->data[(list->data[i22] +
        PMAn->size[0] * i21) - 1];
    }
  }

  i21 = PMAn->size[0] * PMAn->size[1];
  PMAn->size[0] = b_PME->size[0];
  PMAn->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PMAn, i21);
  loop_ub = b_PME->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    k = b_PME->size[0];
    for (i22 = 0; i22 < k; i22++) {
      PMAn->data[i22 + PMAn->size[0] * i21] = b_PME->data[i22 + b_PME->size[0] *
        i21];
    }
  }

  /* 'sch:19' PCPrO=PCPrO(list,:); */
  loop_ub = PCPrO->size[1] - 1;
  i21 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i21);
  for (i21 = 0; i21 <= loop_ub; i21++) {
    k = list->size[0];
    for (i22 = 0; i22 < k; i22++) {
      b_PME->data[i22 + b_PME->size[0] * i21] = PCPrO->data[(list->data[i22] +
        PCPrO->size[0] * i21) - 1];
    }
  }

  i21 = PCPrO->size[0] * PCPrO->size[1];
  PCPrO->size[0] = b_PME->size[0];
  PCPrO->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCPrO, i21);
  loop_ub = b_PME->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    k = b_PME->size[0];
    for (i22 = 0; i22 < k; i22++) {
      PCPrO->data[i22 + PCPrO->size[0] * i21] = b_PME->data[i22 + b_PME->size[0]
        * i21];
    }
  }

  /* 'sch:20' PS=PS(list,:); */
  loop_ub = PS->size[1] - 1;
  i21 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i21);
  for (i21 = 0; i21 <= loop_ub; i21++) {
    k = list->size[0];
    for (i22 = 0; i22 < k; i22++) {
      b_PME->data[i22 + b_PME->size[0] * i21] = PS->data[(list->data[i22] +
        PS->size[0] * i21) - 1];
    }
  }

  i21 = PS->size[0] * PS->size[1];
  PS->size[0] = b_PME->size[0];
  PS->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PS, i21);
  loop_ub = b_PME->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    k = b_PME->size[0];
    for (i22 = 0; i22 < k; i22++) {
      PS->data[i22 + PS->size[0] * i21] = b_PME->data[i22 + b_PME->size[0] * i21];
    }
  }

  /* 'sch:21' PCPO=PCPO(list,:); */
  loop_ub = PCPO->size[1] - 1;
  i21 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i21);
  for (i21 = 0; i21 <= loop_ub; i21++) {
    k = list->size[0];
    for (i22 = 0; i22 < k; i22++) {
      b_PME->data[i22 + b_PME->size[0] * i21] = PCPO->data[(list->data[i22] +
        PCPO->size[0] * i21) - 1];
    }
  }

  i21 = PCPO->size[0] * PCPO->size[1];
  PCPO->size[0] = b_PME->size[0];
  PCPO->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCPO, i21);
  loop_ub = b_PME->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    k = b_PME->size[0];
    for (i22 = 0; i22 < k; i22++) {
      PCPO->data[i22 + PCPO->size[0] * i21] = b_PME->data[i22 + b_PME->size[0] *
        i21];
    }
  }

  /* 'sch:22' PCR=PCR(list,:); */
  loop_ub = PCR->size[1] - 1;
  i21 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i21);
  for (i21 = 0; i21 <= loop_ub; i21++) {
    k = list->size[0];
    for (i22 = 0; i22 < k; i22++) {
      b_PME->data[i22 + b_PME->size[0] * i21] = PCR->data[(list->data[i22] +
        PCR->size[0] * i21) - 1];
    }
  }

  i21 = PCR->size[0] * PCR->size[1];
  PCR->size[0] = b_PME->size[0];
  PCR->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCR, i21);
  loop_ub = b_PME->size[1];
  for (i21 = 0; i21 < loop_ub; i21++) {
    k = b_PME->size[0];
    for (i22 = 0; i22 < k; i22++) {
      PCR->data[i22 + PCR->size[0] * i21] = b_PME->data[i22 + b_PME->size[0] *
        i21];
    }
  }

  emxFree_int32_T(&b_PME);
  emxInit_int32_T(&b_EP, 1);

  /* 'sch:24' EP=EP(list,:); */
  i21 = b_EP->size[0];
  b_EP->size[0] = list->size[0];
  emxEnsureCapacity_int32_T(b_EP, i21);
  loop_ub = list->size[0];
  for (i21 = 0; i21 < loop_ub; i21++) {
    b_EP->data[i21] = EP->data[list->data[i21] - 1];
  }

  i21 = EP->size[0];
  EP->size[0] = b_EP->size[0];
  emxEnsureCapacity_int32_T(EP, i21);
  loop_ub = b_EP->size[0];
  for (i21 = 0; i21 < loop_ub; i21++) {
    EP->data[i21] = b_EP->data[i21];
  }

  emxInit_int32_T(&DiaOp, 1);

  /* 'sch:26' for i=1:NumTOp */
  i21 = DiaOp->size[0];
  DiaOp->size[0] = NumTOp;
  emxEnsureCapacity_int32_T(DiaOp, i21);
  emxInit_int32_T(&tempUltPosRecXDia, 2);
  emxInit_int32_T(&DispME, 2);
  emxInit_int32_T(&EA, 2);
  emxInit_int32_T(&AA, 2);
  emxInit_int32_T(&AnA, 2);
  emxInit_int32_T(&SA, 2);
  emxInit_int32_T(&b_PCPrO, 2);
  emxInit_int32_T(&c_PME, 2);
  emxInit_int32_T(&b_PMA, 2);
  emxInit_int32_T(&b_PMAn, 2);
  emxInit_int32_T(&b_PS, 2);
  emxInit_int32_T(&b_PCPO, 2);
  emxInit_int32_T(&b_PCR, 2);
  for (i = 0; i < NumTOp; i++) {
    /* 'sch:28' contDia = int32(2); */
    /* 'sch:30' [contDia,tempUltPosRecXDia,DispME] = funcionDia( NumRec,PCPrO(i,:), Dia,UltPosRecXDia,... */
    /* 'sch:31'         TimeUsoRec(i,1),TimeUsoRec(i,2),contDia,DispMExD); */
    contDia = 2;
    loop_ub = PCPrO->size[1];
    i21 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPrO, i21);
    for (i21 = 0; i21 < loop_ub; i21++) {
      b_PCPrO->data[i21] = PCPrO->data[i + PCPrO->size[0] * i21];
    }

    b_funcionDia(NumRec, b_PCPrO, Dia, UltPosRecXDia, TimeUsoRec->data[i],
                 TimeUsoRec->data[i + TimeUsoRec->size[0]], &contDia, DispMExD,
                 tempUltPosRecXDia, DispME);

    /* 'sch:33' [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,AA,AnA,SA,IniSA,EndSA,EndRPxD,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,contDia] = ... */
    /* 'sch:34'         funcionCPrO( NumRec,PCPrO(i,:), PME(i,:),PMA(i,:),PMAn(i,:),PS(i,:),PCPO(i,:),PCR(i,:),H,Dia, UltPosRecXDia,... */
    /* 'sch:35'         TimeUsoRec(i,1), TimeUsoRec(i,2),TimeUsoRec(i,6),TimeUsoRec(i,7),contDia,tempUltPosRecXDia,DispMExD,DispME); */
    loop_ub = PCPrO->size[1];
    i21 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPrO, i21);
    for (i21 = 0; i21 < loop_ub; i21++) {
      b_PCPrO->data[i21] = PCPrO->data[i + PCPrO->size[0] * i21];
    }

    loop_ub = PME->size[1];
    i21 = c_PME->size[0] * c_PME->size[1];
    c_PME->size[0] = 1;
    c_PME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(c_PME, i21);
    for (i21 = 0; i21 < loop_ub; i21++) {
      c_PME->data[i21] = PME->data[i + PME->size[0] * i21];
    }

    loop_ub = PMA->size[1];
    i21 = b_PMA->size[0] * b_PMA->size[1];
    b_PMA->size[0] = 1;
    b_PMA->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PMA, i21);
    for (i21 = 0; i21 < loop_ub; i21++) {
      b_PMA->data[i21] = PMA->data[i + PMA->size[0] * i21];
    }

    loop_ub = PMAn->size[1];
    i21 = b_PMAn->size[0] * b_PMAn->size[1];
    b_PMAn->size[0] = 1;
    b_PMAn->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PMAn, i21);
    for (i21 = 0; i21 < loop_ub; i21++) {
      b_PMAn->data[i21] = PMAn->data[i + PMAn->size[0] * i21];
    }

    loop_ub = PS->size[1];
    i21 = b_PS->size[0] * b_PS->size[1];
    b_PS->size[0] = 1;
    b_PS->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PS, i21);
    for (i21 = 0; i21 < loop_ub; i21++) {
      b_PS->data[i21] = PS->data[i + PS->size[0] * i21];
    }

    loop_ub = PCPO->size[1];
    i21 = b_PCPO->size[0] * b_PCPO->size[1];
    b_PCPO->size[0] = 1;
    b_PCPO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPO, i21);
    for (i21 = 0; i21 < loop_ub; i21++) {
      b_PCPO->data[i21] = PCPO->data[i + PCPO->size[0] * i21];
    }

    loop_ub = PCR->size[1];
    i21 = b_PCR->size[0] * b_PCR->size[1];
    b_PCR->size[0] = 1;
    b_PCR->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCR, i21);
    for (i21 = 0; i21 < loop_ub; i21++) {
      b_PCR->data[i21] = PCR->data[i + PCR->size[0] * i21];
    }

    b_funcionCPrO(NumRec, b_PCPrO, c_PME, b_PMA, b_PMAn, b_PS, b_PCPO, b_PCR, H,
                  Dia, UltPosRecXDia, TimeUsoRec->data[i], TimeUsoRec->data[i +
                  TimeUsoRec->size[0]], TimeUsoRec->data[i + TimeUsoRec->size[0]
                  * 5], TimeUsoRec->data[i + TimeUsoRec->size[0] * 6], &contDia,
                  tempUltPosRecXDia, DispMExD, DispME, &CPrOA, &IniCPrOA,
                  &EndCPrOA, &EndCPrOAxD, EA, AA, AnA, SA, &IniSA, &EndSA,
                  &EndRPxD, &CPOA, &IniCPOA, &EndCPOA, &CRA, &IniCRA, &EndCRA);

    /* 'sch:37' DiaOp(i)=contDia; */
    DiaOp->data[i] = contDia;

    /* 'sch:39' H(IniCPrOA:EndCPrOA,CPrOA)=i; */
    if (IniCPrOA > EndCPrOA) {
      i21 = 0;
      i22 = 0;
    } else {
      i21 = IniCPrOA - 1;
      i22 = EndCPrOA;
    }

    loop_ub = i22 - i21;
    for (i22 = 0; i22 < loop_ub; i22++) {
      H->data[(i21 + i22) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
    }

    /* 'sch:40' UltPosRecXDia(contDia,CPrOA)=EndCPrOAxD; */
    UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (CPrOA - 1)) - 1] =
      EndCPrOAxD;

    /* 'sch:42' H(IniSA:EndSA,NumRec(1)+NumRec(2)+int32(SA))=i; */
    if (IniSA > EndSA) {
      i21 = 0;
      i22 = 0;
    } else {
      i21 = IniSA - 1;
      i22 = EndSA;
    }

    NumRec_tmp = NumRec[0] + NumRec[1];
    i23 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = SA->size[1];
    emxEnsureCapacity_int32_T(b_PCPrO, i23);
    loop_ub = SA->size[1];
    for (i23 = 0; i23 < loop_ub; i23++) {
      b_PCPrO->data[i23] = SA->data[i23] + NumRec_tmp;
    }

    i23 = b_EP->size[0];
    b_EP->size[0] = b_PCPrO->size[1];
    emxEnsureCapacity_int32_T(b_EP, i23);
    loop_ub = b_PCPrO->size[1];
    for (i23 = 0; i23 < loop_ub; i23++) {
      b_EP->data[i23] = b_PCPrO->data[i23];
    }

    Data_idx_0 = i22 - i21;
    k = b_EP->size[0];
    for (i22 = 0; i22 < k; i22++) {
      for (i23 = 0; i23 < Data_idx_0; i23++) {
        H->data[(i21 + i23) + H->size[0] * (b_EP->data[i22] - 1)] = (unsigned
          int)(i + 1);
      }
    }

    /* 'sch:43' UltPosRecXDia(contDia,NumRec(1)+NumRec(2)+int32(SA))=EndRPxD; */
    k = b_EP->size[0];
    for (i21 = 0; i21 < k; i21++) {
      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (b_EP->data[i21] -
        1)) - 1] = EndRPxD;
    }

    /* 'sch:45' for j=1:size(EA,2) */
    i21 = EA->size[1];
    if (0 <= i21 - 1) {
      if (IniSA > EndSA) {
        i24 = 0;
        i25 = 0;
      } else {
        i24 = IniSA - 1;
        i25 = EndSA;
      }
    }

    for (j = 0; j < i21; j++) {
      /* 'sch:47' H(IniSA:EndSA,NumRec(1)+EA(j))=i; */
      k = NumRec[0] + EA->data[j];
      loop_ub = i25 - i24;
      for (i22 = 0; i22 < loop_ub; i22++) {
        H->data[(i24 + i22) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
      }

      /* 'sch:48' UltPosRecXDia(contDia,NumRec(1)+EA(j))=EndRPxD; */
      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * ((NumRec[0] +
        EA->data[j]) - 1)) - 1] = EndRPxD;

      /* 'sch:50' EspMedOp(i,j)=PME(i,EA(j)); */
      EspMedOp->data[i + EspMedOp->size[0] * j] = PME->data[i + PME->size[0] *
        (EA->data[j] - 1)];
    }

    /* 'sch:54' for j=1:size(AA,2) */
    i21 = AA->size[1];
    if (0 <= i21 - 1) {
      if (IniSA > EndSA) {
        i26 = 0;
        i27 = 0;
      } else {
        i26 = IniSA - 1;
        i27 = EndSA;
      }
    }

    for (j = 0; j < i21; j++) {
      /* 'sch:56' H(IniSA:EndSA,NumRec(1)+NumRec(2)+NumRec(3)+AA(j))=i; */
      k = (NumRec_tmp + NumRec[2]) + AA->data[j];
      loop_ub = i27 - i26;
      for (i22 = 0; i22 < loop_ub; i22++) {
        H->data[(i26 + i22) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
      }

      /* 'sch:57' UltPosRecXDia(contDia,NumRec(1)+NumRec(2)+NumRec(3)+AA(j))=EndRPxD; */
      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * ((((NumRec[0] +
        NumRec[1]) + NumRec[2]) + AA->data[j]) - 1)) - 1] = EndRPxD;
    }

    /* 'sch:61' for j=1:size(AnA,2) */
    i21 = AnA->size[1];
    if (0 <= i21 - 1) {
      if (IniSA > EndSA) {
        i28 = 0;
        i29 = 0;
      } else {
        i28 = IniSA - 1;
        i29 = EndSA;
      }
    }

    for (j = 0; j < i21; j++) {
      /* 'sch:63' H(IniSA:EndSA,NumRec(1)+NumRec(2)+NumRec(3)+NumRec(4)+AnA(j))=i; */
      k = (((NumRec[0] + NumRec[1]) + NumRec[2]) + NumRec[3]) + AnA->data[j];
      loop_ub = i29 - i28;
      for (i22 = 0; i22 < loop_ub; i22++) {
        H->data[(i28 + i22) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
      }

      /* 'sch:64' UltPosRecXDia(contDia,NumRec(1)+NumRec(2)+NumRec(3)+NumRec(4)+AnA(j))=EndRPxD; */
      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (((((NumRec[0] +
        NumRec[1]) + NumRec[2]) + NumRec[3]) + AnA->data[j]) - 1)) - 1] =
        EndRPxD;
    }

    /* 'sch:68' if IniCPOA == 0 */
    if (IniCPOA == 0) {
      /* 'sch:69' H(IniCRA:EndCRA,sum(NumRec(1:6))+CRA)=i; */
      if (IniCRA > EndCRA) {
        i21 = 0;
        i22 = 0;
      } else {
        i21 = IniCRA - 1;
        i22 = EndCRA;
      }

      y = NumRec[0];
      for (k = 0; k < 5; k++) {
        y += (double)NumRec[k + 1];
      }

      k = (int)(y + (double)CRA);
      loop_ub = i22 - i21;
      for (i22 = 0; i22 < loop_ub; i22++) {
        H->data[(i21 + i22) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
      }
    } else {
      /* 'sch:70' else */
      /* 'sch:71' H(IniCPOA:EndCPOA,sum(NumRec(1:5))+CPOA)=i; */
      if (IniCPOA > EndCPOA) {
        i21 = 0;
        i22 = 0;
      } else {
        i21 = IniCPOA - 1;
        i22 = EndCPOA;
      }

      k = (int)((((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2])
                  + (double)NumRec[3]) + (double)NumRec[4]) + (double)CPOA);
      loop_ub = i22 - i21;
      for (i22 = 0; i22 < loop_ub; i22++) {
        H->data[(i21 + i22) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
      }

      /* 'sch:72' H(IniCRA:EndCRA,sum(NumRec(1:6))+CRA)=i; */
      if (IniCRA > EndCRA) {
        i21 = 0;
        i22 = 0;
      } else {
        i21 = IniCRA - 1;
        i22 = EndCRA;
      }

      y = NumRec[0];
      for (k = 0; k < 5; k++) {
        y += (double)NumRec[k + 1];
      }

      k = (int)(y + (double)CRA);
      loop_ub = i22 - i21;
      for (i22 = 0; i22 < loop_ub; i22++) {
        H->data[(i21 + i22) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
      }
    }
  }

  emxFree_int32_T(&b_PCR);
  emxFree_int32_T(&b_PCPO);
  emxFree_int32_T(&b_PS);
  emxFree_int32_T(&b_PMAn);
  emxFree_int32_T(&b_PMA);
  emxFree_int32_T(&c_PME);
  emxFree_int32_T(&b_PCPrO);
  emxFree_int32_T(&b_EP);
  emxFree_int32_T(&SA);
  emxFree_int32_T(&AnA);
  emxFree_int32_T(&AA);
  emxFree_int32_T(&EA);
  emxFree_int32_T(&DispME);
  emxFree_int32_T(&tempUltPosRecXDia);
  emxFree_real_T(&UltPosRecXDia);

  /* 'sch:77' schedule=H; */
  /* 'sch:79' [ fitness,Tt,NOFP,TmNOFP,NOE2,NOE3] = favalia( schedule,DiaOp,int32(EP),EspMedOp,k0,k1,k2,k3 ); */
  b_favalia(H, DiaOp, EP, EspMedOp, k0, k1, k2, k3, &d4, &d5, &d6, &d7, &d8, &d9);
  *NOE3 = d9;
  *NOE2 = d8;
  *TmNOFP = d7;
  *NOFP = d6;
  *Tt = d5;
  *fitness = d4;
  emxFree_real_T(&EspMedOp);
  emxFree_int32_T(&DiaOp);
  emxFree_real_T(&H);
}

/* End of code generation (sch.c) */
