/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: sch.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
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
 * UNTITLED4 Summary of this function goes here
 *    Detailed explanation goes here
 *     NCPrO  |    NME    |     NS    |     NA    |     NAn    |    NCPO     |   NCR
 *   Col 1-20 | Col 21-50 | Col 51-62 | Col 63-87 | Col 88-112 | Col 113-132 | Col 133-152
 * Arguments    : int NumTOp
 *                const emxArray_int32_T *list
 *                const int NumRec[7]
 *                emxArray_int32_T *PCPrO
 *                emxArray_int32_T *PME
 *                emxArray_int32_T *PMA
 *                emxArray_int32_T *PMAn
 *                emxArray_int32_T *PS
 *                emxArray_int32_T *PCPO
 *                emxArray_int32_T *PCR
 *                const emxArray_int32_T *Dia
 *                const emxArray_int32_T *Data
 *                emxArray_int32_T *TimeUsoRec
 *                const emxArray_int32_T *DispMExD
 *                emxArray_int32_T *EP
 *                double k0
 *                double k1
 *                double k2
 *                double k3
 *                double *fitness
 *                double *Tt
 *                double *NOFP
 *                double *TmNOFP
 *                double *NOE2
 *                double *NOE3
 * Return Type  : void
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
  emxArray_int32_T *H;
  int i29;
  int loop_ub;
  emxArray_int32_T *UltPosRecXDia;
  int b_loop_ub;
  emxArray_int32_T *EspMedOp;
  emxArray_int32_T *b_TimeUsoRec;
  emxArray_int32_T *b_PME;
  int c_loop_ub;
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
  double d5;
  double d6;
  double d7;
  double d8;
  double d9;
  double d10;
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
  int i30;
  int i31;
  int i32;
  int i33;
  int i34;
  int i35;

  /* 'sch:7' H = zeros(size(Data,1),sum(NumRec), 'int32'); */
  y = NumRec[0];
  for (k = 0; k < 6; k++) {
    y += (double)NumRec[k + 1];
  }

  emxInit_int32_T(&H, 2);
  k = Data->size[0];
  i29 = H->size[0] * H->size[1];
  loop_ub = (int)y;
  H->size[1] = loop_ub;
  H->size[0] = k;
  emxEnsureCapacity_int32_T(H, i29);
  for (i29 = 0; i29 < k; i29++) {
    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      H->data[b_loop_ub + H->size[1] * i29] = 0;
    }
  }

  emxInit_int32_T(&UltPosRecXDia, 2);

  /*  Schedule completo */
  /* 'sch:8' UltPosRecXDia = zeros(size(Dia,1),size(H,2), 'int32'); */
  k = Dia->size[0];
  i29 = UltPosRecXDia->size[0] * UltPosRecXDia->size[1];
  UltPosRecXDia->size[1] = loop_ub;
  UltPosRecXDia->size[0] = k;
  emxEnsureCapacity_int32_T(UltPosRecXDia, i29);
  for (i29 = 0; i29 < k; i29++) {
    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      UltPosRecXDia->data[b_loop_ub + UltPosRecXDia->size[1] * i29] = 0;
    }
  }

  emxInit_int32_T(&EspMedOp, 2);

  /*  Ultima posicion asignado del recurso por Dia */
  /* 'sch:10' DiaOp = zeros(NumTOp,1, 'int32'); */
  /* 'sch:11' EspMedOp = zeros(NumTOp,2, 'int32'); */
  i29 = EspMedOp->size[0] * EspMedOp->size[1];
  EspMedOp->size[1] = 2;
  EspMedOp->size[0] = NumTOp;
  emxEnsureCapacity_int32_T(EspMedOp, i29);
  for (i29 = 0; i29 < NumTOp; i29++) {
    b_loop_ub = i29 << 1;
    EspMedOp->data[b_loop_ub] = 0;
    EspMedOp->data[1 + b_loop_ub] = 0;
  }

  emxInit_int32_T(&b_TimeUsoRec, 2);

  /* 'sch:13' TimeUsoRec=TimeUsoRec(list,:); */
  i29 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[1] = 7;
  b_TimeUsoRec->size[0] = list->size[0];
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i29);
  loop_ub = list->size[0];
  for (i29 = 0; i29 < loop_ub; i29++) {
    for (b_loop_ub = 0; b_loop_ub < 7; b_loop_ub++) {
      b_TimeUsoRec->data[b_loop_ub + 7 * i29] = TimeUsoRec->data[b_loop_ub + 7 *
        (list->data[i29] - 1)];
    }
  }

  i29 = TimeUsoRec->size[0] * TimeUsoRec->size[1];
  TimeUsoRec->size[1] = 7;
  TimeUsoRec->size[0] = b_TimeUsoRec->size[0];
  emxEnsureCapacity_int32_T(TimeUsoRec, i29);
  loop_ub = b_TimeUsoRec->size[0];
  for (i29 = 0; i29 < loop_ub; i29++) {
    for (b_loop_ub = 0; b_loop_ub < 7; b_loop_ub++) {
      k = b_loop_ub + 7 * i29;
      TimeUsoRec->data[k] = b_TimeUsoRec->data[k];
    }
  }

  emxFree_int32_T(&b_TimeUsoRec);
  emxInit_int32_T(&b_PME, 2);

  /* 'sch:15' PME=PME(list,:); */
  loop_ub = PME->size[1] - 1;
  i29 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[1] = loop_ub + 1;
  b_PME->size[0] = list->size[0];
  emxEnsureCapacity_int32_T(b_PME, i29);
  c_loop_ub = list->size[0];
  for (i29 = 0; i29 < c_loop_ub; i29++) {
    for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
      b_PME->data[b_loop_ub + b_PME->size[1] * i29] = PME->data[b_loop_ub +
        PME->size[1] * (list->data[i29] - 1)];
    }
  }

  i29 = PME->size[0] * PME->size[1];
  PME->size[1] = b_PME->size[1];
  PME->size[0] = b_PME->size[0];
  emxEnsureCapacity_int32_T(PME, i29);
  loop_ub = b_PME->size[0];
  for (i29 = 0; i29 < loop_ub; i29++) {
    c_loop_ub = b_PME->size[1];
    for (b_loop_ub = 0; b_loop_ub < c_loop_ub; b_loop_ub++) {
      PME->data[b_loop_ub + PME->size[1] * i29] = b_PME->data[b_loop_ub +
        b_PME->size[1] * i29];
    }
  }

  /* 'sch:16' PMA=PMA(list,:); */
  loop_ub = PMA->size[1] - 1;
  i29 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[1] = loop_ub + 1;
  b_PME->size[0] = list->size[0];
  emxEnsureCapacity_int32_T(b_PME, i29);
  c_loop_ub = list->size[0];
  for (i29 = 0; i29 < c_loop_ub; i29++) {
    for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
      b_PME->data[b_loop_ub + b_PME->size[1] * i29] = PMA->data[b_loop_ub +
        PMA->size[1] * (list->data[i29] - 1)];
    }
  }

  i29 = PMA->size[0] * PMA->size[1];
  PMA->size[1] = b_PME->size[1];
  PMA->size[0] = b_PME->size[0];
  emxEnsureCapacity_int32_T(PMA, i29);
  loop_ub = b_PME->size[0];
  for (i29 = 0; i29 < loop_ub; i29++) {
    c_loop_ub = b_PME->size[1];
    for (b_loop_ub = 0; b_loop_ub < c_loop_ub; b_loop_ub++) {
      PMA->data[b_loop_ub + PMA->size[1] * i29] = b_PME->data[b_loop_ub +
        b_PME->size[1] * i29];
    }
  }

  /* 'sch:17' PMAn=PMAn(list,:); */
  loop_ub = PMAn->size[1] - 1;
  i29 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[1] = loop_ub + 1;
  b_PME->size[0] = list->size[0];
  emxEnsureCapacity_int32_T(b_PME, i29);
  c_loop_ub = list->size[0];
  for (i29 = 0; i29 < c_loop_ub; i29++) {
    for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
      b_PME->data[b_loop_ub + b_PME->size[1] * i29] = PMAn->data[b_loop_ub +
        PMAn->size[1] * (list->data[i29] - 1)];
    }
  }

  i29 = PMAn->size[0] * PMAn->size[1];
  PMAn->size[1] = b_PME->size[1];
  PMAn->size[0] = b_PME->size[0];
  emxEnsureCapacity_int32_T(PMAn, i29);
  loop_ub = b_PME->size[0];
  for (i29 = 0; i29 < loop_ub; i29++) {
    c_loop_ub = b_PME->size[1];
    for (b_loop_ub = 0; b_loop_ub < c_loop_ub; b_loop_ub++) {
      PMAn->data[b_loop_ub + PMAn->size[1] * i29] = b_PME->data[b_loop_ub +
        b_PME->size[1] * i29];
    }
  }

  /* 'sch:19' PCPrO=PCPrO(list,:); */
  loop_ub = PCPrO->size[1] - 1;
  i29 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[1] = loop_ub + 1;
  b_PME->size[0] = list->size[0];
  emxEnsureCapacity_int32_T(b_PME, i29);
  c_loop_ub = list->size[0];
  for (i29 = 0; i29 < c_loop_ub; i29++) {
    for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
      b_PME->data[b_loop_ub + b_PME->size[1] * i29] = PCPrO->data[b_loop_ub +
        PCPrO->size[1] * (list->data[i29] - 1)];
    }
  }

  i29 = PCPrO->size[0] * PCPrO->size[1];
  PCPrO->size[1] = b_PME->size[1];
  PCPrO->size[0] = b_PME->size[0];
  emxEnsureCapacity_int32_T(PCPrO, i29);
  loop_ub = b_PME->size[0];
  for (i29 = 0; i29 < loop_ub; i29++) {
    c_loop_ub = b_PME->size[1];
    for (b_loop_ub = 0; b_loop_ub < c_loop_ub; b_loop_ub++) {
      PCPrO->data[b_loop_ub + PCPrO->size[1] * i29] = b_PME->data[b_loop_ub +
        b_PME->size[1] * i29];
    }
  }

  /* 'sch:20' PS=PS(list,:); */
  loop_ub = PS->size[1] - 1;
  i29 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[1] = loop_ub + 1;
  b_PME->size[0] = list->size[0];
  emxEnsureCapacity_int32_T(b_PME, i29);
  c_loop_ub = list->size[0];
  for (i29 = 0; i29 < c_loop_ub; i29++) {
    for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
      b_PME->data[b_loop_ub + b_PME->size[1] * i29] = PS->data[b_loop_ub +
        PS->size[1] * (list->data[i29] - 1)];
    }
  }

  i29 = PS->size[0] * PS->size[1];
  PS->size[1] = b_PME->size[1];
  PS->size[0] = b_PME->size[0];
  emxEnsureCapacity_int32_T(PS, i29);
  loop_ub = b_PME->size[0];
  for (i29 = 0; i29 < loop_ub; i29++) {
    c_loop_ub = b_PME->size[1];
    for (b_loop_ub = 0; b_loop_ub < c_loop_ub; b_loop_ub++) {
      PS->data[b_loop_ub + PS->size[1] * i29] = b_PME->data[b_loop_ub +
        b_PME->size[1] * i29];
    }
  }

  /* 'sch:21' PCPO=PCPO(list,:); */
  loop_ub = PCPO->size[1] - 1;
  i29 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[1] = loop_ub + 1;
  b_PME->size[0] = list->size[0];
  emxEnsureCapacity_int32_T(b_PME, i29);
  c_loop_ub = list->size[0];
  for (i29 = 0; i29 < c_loop_ub; i29++) {
    for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
      b_PME->data[b_loop_ub + b_PME->size[1] * i29] = PCPO->data[b_loop_ub +
        PCPO->size[1] * (list->data[i29] - 1)];
    }
  }

  i29 = PCPO->size[0] * PCPO->size[1];
  PCPO->size[1] = b_PME->size[1];
  PCPO->size[0] = b_PME->size[0];
  emxEnsureCapacity_int32_T(PCPO, i29);
  loop_ub = b_PME->size[0];
  for (i29 = 0; i29 < loop_ub; i29++) {
    c_loop_ub = b_PME->size[1];
    for (b_loop_ub = 0; b_loop_ub < c_loop_ub; b_loop_ub++) {
      PCPO->data[b_loop_ub + PCPO->size[1] * i29] = b_PME->data[b_loop_ub +
        b_PME->size[1] * i29];
    }
  }

  /* 'sch:22' PCR=PCR(list,:); */
  loop_ub = PCR->size[1] - 1;
  i29 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[1] = loop_ub + 1;
  b_PME->size[0] = list->size[0];
  emxEnsureCapacity_int32_T(b_PME, i29);
  c_loop_ub = list->size[0];
  for (i29 = 0; i29 < c_loop_ub; i29++) {
    for (b_loop_ub = 0; b_loop_ub <= loop_ub; b_loop_ub++) {
      b_PME->data[b_loop_ub + b_PME->size[1] * i29] = PCR->data[b_loop_ub +
        PCR->size[1] * (list->data[i29] - 1)];
    }
  }

  i29 = PCR->size[0] * PCR->size[1];
  PCR->size[1] = b_PME->size[1];
  PCR->size[0] = b_PME->size[0];
  emxEnsureCapacity_int32_T(PCR, i29);
  loop_ub = b_PME->size[0];
  for (i29 = 0; i29 < loop_ub; i29++) {
    c_loop_ub = b_PME->size[1];
    for (b_loop_ub = 0; b_loop_ub < c_loop_ub; b_loop_ub++) {
      PCR->data[b_loop_ub + PCR->size[1] * i29] = b_PME->data[b_loop_ub +
        b_PME->size[1] * i29];
    }
  }

  emxFree_int32_T(&b_PME);
  emxInit_int32_T(&b_EP, 1);

  /* 'sch:24' EP=EP(list,:); */
  i29 = b_EP->size[0];
  b_EP->size[0] = list->size[0];
  emxEnsureCapacity_int32_T(b_EP, i29);
  loop_ub = list->size[0];
  for (i29 = 0; i29 < loop_ub; i29++) {
    b_EP->data[i29] = EP->data[list->data[i29] - 1];
  }

  i29 = EP->size[0];
  EP->size[0] = b_EP->size[0];
  emxEnsureCapacity_int32_T(EP, i29);
  loop_ub = b_EP->size[0];
  for (i29 = 0; i29 < loop_ub; i29++) {
    EP->data[i29] = b_EP->data[i29];
  }

  emxFree_int32_T(&b_EP);
  emxInit_int32_T(&DiaOp, 1);

  /* 'sch:26' for i=1:NumTOp */
  i29 = DiaOp->size[0];
  DiaOp->size[0] = NumTOp;
  emxEnsureCapacity_int32_T(DiaOp, i29);
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
    i29 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[1] = loop_ub;
    b_PCPrO->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PCPrO, i29);
    for (i29 = 0; i29 < loop_ub; i29++) {
      b_PCPrO->data[i29] = PCPrO->data[i29 + PCPrO->size[1] * i];
    }

    funcionDia(NumRec, b_PCPrO, Dia, UltPosRecXDia, TimeUsoRec->data[7 * i],
               TimeUsoRec->data[1 + 7 * i], &contDia, DispMExD,
               tempUltPosRecXDia, DispME);

    /* 'sch:33' [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,AA,AnA,SA,IniSA,EndSA,EndRPxD,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,contDia] = ... */
    /* 'sch:34'         funcionCPrO( NumRec,PCPrO(i,:), PME(i,:),PMA(i,:),PMAn(i,:),PS(i,:),PCPO(i,:),PCR(i,:),H,Dia, UltPosRecXDia,... */
    /* 'sch:35'         TimeUsoRec(i,1), TimeUsoRec(i,2),TimeUsoRec(i,6),TimeUsoRec(i,7),contDia,tempUltPosRecXDia,DispMExD,DispME); */
    loop_ub = PCPrO->size[1];
    c_loop_ub = PME->size[1];
    k = PMA->size[1];
    d_loop_ub = PMAn->size[1];
    e_loop_ub = PS->size[1];
    b_loop_ub = PCPO->size[1];
    f_loop_ub = PCR->size[1];
    i29 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[1] = loop_ub;
    b_PCPrO->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PCPrO, i29);
    for (i29 = 0; i29 < loop_ub; i29++) {
      b_PCPrO->data[i29] = PCPrO->data[i29 + PCPrO->size[1] * i];
    }

    i29 = c_PME->size[0] * c_PME->size[1];
    c_PME->size[1] = c_loop_ub;
    c_PME->size[0] = 1;
    emxEnsureCapacity_int32_T(c_PME, i29);
    for (i29 = 0; i29 < c_loop_ub; i29++) {
      c_PME->data[i29] = PME->data[i29 + PME->size[1] * i];
    }

    i29 = b_PMA->size[0] * b_PMA->size[1];
    b_PMA->size[1] = k;
    b_PMA->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PMA, i29);
    for (i29 = 0; i29 < k; i29++) {
      b_PMA->data[i29] = PMA->data[i29 + PMA->size[1] * i];
    }

    i29 = b_PMAn->size[0] * b_PMAn->size[1];
    b_PMAn->size[1] = d_loop_ub;
    b_PMAn->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PMAn, i29);
    for (i29 = 0; i29 < d_loop_ub; i29++) {
      b_PMAn->data[i29] = PMAn->data[i29 + PMAn->size[1] * i];
    }

    i29 = b_PS->size[0] * b_PS->size[1];
    b_PS->size[1] = e_loop_ub;
    b_PS->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PS, i29);
    for (i29 = 0; i29 < e_loop_ub; i29++) {
      b_PS->data[i29] = PS->data[i29 + PS->size[1] * i];
    }

    i29 = b_PCPO->size[0] * b_PCPO->size[1];
    b_PCPO->size[1] = b_loop_ub;
    b_PCPO->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PCPO, i29);
    for (i29 = 0; i29 < b_loop_ub; i29++) {
      b_PCPO->data[i29] = PCPO->data[i29 + PCPO->size[1] * i];
    }

    i29 = b_PCR->size[0] * b_PCR->size[1];
    b_PCR->size[1] = f_loop_ub;
    b_PCR->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PCR, i29);
    for (i29 = 0; i29 < f_loop_ub; i29++) {
      b_PCR->data[i29] = PCR->data[i29 + PCR->size[1] * i];
    }

    funcionCPrO(NumRec, b_PCPrO, c_PME, b_PMA, b_PMAn, b_PS, b_PCPO, b_PCR, H,
                Dia, UltPosRecXDia, TimeUsoRec->data[7 * i], TimeUsoRec->data[1
                + 7 * i], TimeUsoRec->data[5 + 7 * i], TimeUsoRec->data[6 + 7 *
                i], &contDia, tempUltPosRecXDia, DispMExD, DispME, &CPrOA,
                &IniCPrOA, &EndCPrOA, &EndCPrOAxD, EA, AA, AnA, SA, &IniSA,
                &EndSA, &EndRPxD, &CPOA, &IniCPOA, &EndCPOA, &CRA, &IniCRA,
                &EndCRA);

    /* 'sch:37' DiaOp(i)=contDia; */
    DiaOp->data[i] = contDia;

    /* 'sch:39' H(IniCPrOA:EndCPrOA,CPrOA)=i; */
    if (IniCPrOA > EndCPrOA) {
      i29 = 0;
      b_loop_ub = 0;
    } else {
      i29 = IniCPrOA - 1;
      b_loop_ub = EndCPrOA;
    }

    loop_ub = b_loop_ub - i29;
    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      H->data[(CPrOA + H->size[1] * (i29 + b_loop_ub)) - 1] = i + 1;
    }

    /* 'sch:40' UltPosRecXDia(contDia,CPrOA)=EndCPrOAxD; */
    UltPosRecXDia->data[(CPrOA + UltPosRecXDia->size[1] * (contDia - 1)) - 1] =
      EndCPrOAxD;

    /* 'sch:42' H(IniSA:EndSA,NumRec(1)+NumRec(2)+int32(SA))=i; */
    if (IniSA > EndSA) {
      i29 = 0;
      b_loop_ub = 0;
    } else {
      i29 = IniSA - 1;
      b_loop_ub = EndSA;
    }

    e_loop_ub = NumRec[0] + NumRec[1];
    k = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[1] = SA->size[1];
    b_PCPrO->size[0] = 1;
    emxEnsureCapacity_int32_T(b_PCPrO, k);
    loop_ub = SA->size[1];
    for (k = 0; k < loop_ub; k++) {
      b_PCPrO->data[k] = SA->data[k] + e_loop_ub;
    }

    d_loop_ub = b_PCPrO->size[1];
    loop_ub = b_loop_ub - i29;
    for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
      for (k = 0; k < d_loop_ub; k++) {
        H->data[(b_PCPrO->data[k] + H->size[1] * (i29 + b_loop_ub)) - 1] = i + 1;
      }
    }

    /* 'sch:43' UltPosRecXDia(contDia,NumRec(1)+NumRec(2)+int32(SA))=EndRPxD; */
    k = b_PCPrO->size[1];
    for (i29 = 0; i29 < k; i29++) {
      UltPosRecXDia->data[(b_PCPrO->data[i29] + UltPosRecXDia->size[1] *
                           (contDia - 1)) - 1] = EndRPxD;
    }

    /* 'sch:45' for j=1:size(EA,2) */
    i29 = EA->size[1];
    if (0 <= i29 - 1) {
      if (IniSA > EndSA) {
        i30 = 0;
        i31 = 0;
      } else {
        i30 = IniSA - 1;
        i31 = EndSA;
      }
    }

    for (j = 0; j < i29; j++) {
      /* 'sch:47' H(IniSA:EndSA,NumRec(1)+EA(j))=i; */
      k = NumRec[0] + EA->data[j];
      loop_ub = i31 - i30;
      for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
        H->data[(k + H->size[1] * (i30 + b_loop_ub)) - 1] = i + 1;
      }

      /* 'sch:48' UltPosRecXDia(contDia,NumRec(1)+EA(j))=EndRPxD; */
      UltPosRecXDia->data[((NumRec[0] + EA->data[j]) + UltPosRecXDia->size[1] *
                           (contDia - 1)) - 1] = EndRPxD;

      /* 'sch:50' EspMedOp(i,j)=PME(i,EA(j)); */
      EspMedOp->data[j + (i << 1)] = PME->data[(EA->data[j] + PME->size[1] * i)
        - 1];
    }

    /* 'sch:54' for j=1:size(AA,2) */
    i29 = AA->size[1];
    if (0 <= i29 - 1) {
      if (IniSA > EndSA) {
        i32 = 0;
        i33 = 0;
      } else {
        i32 = IniSA - 1;
        i33 = EndSA;
      }
    }

    for (j = 0; j < i29; j++) {
      /* 'sch:56' H(IniSA:EndSA,NumRec(1)+NumRec(2)+NumRec(3)+AA(j))=i; */
      k = (e_loop_ub + NumRec[2]) + AA->data[j];
      loop_ub = i33 - i32;
      for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
        H->data[(k + H->size[1] * (i32 + b_loop_ub)) - 1] = i + 1;
      }

      /* 'sch:57' UltPosRecXDia(contDia,NumRec(1)+NumRec(2)+NumRec(3)+AA(j))=EndRPxD; */
      UltPosRecXDia->data[((((NumRec[0] + NumRec[1]) + NumRec[2]) + AA->data[j])
                           + UltPosRecXDia->size[1] * (contDia - 1)) - 1] =
        EndRPxD;
    }

    /* 'sch:61' for j=1:size(AnA,2) */
    i29 = AnA->size[1];
    if (0 <= i29 - 1) {
      if (IniSA > EndSA) {
        i34 = 0;
        i35 = 0;
      } else {
        i34 = IniSA - 1;
        i35 = EndSA;
      }
    }

    for (j = 0; j < i29; j++) {
      /* 'sch:63' H(IniSA:EndSA,NumRec(1)+NumRec(2)+NumRec(3)+NumRec(4)+AnA(j))=i; */
      k = (((NumRec[0] + NumRec[1]) + NumRec[2]) + NumRec[3]) + AnA->data[j];
      loop_ub = i35 - i34;
      for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
        H->data[(k + H->size[1] * (i34 + b_loop_ub)) - 1] = i + 1;
      }

      /* 'sch:64' UltPosRecXDia(contDia,NumRec(1)+NumRec(2)+NumRec(3)+NumRec(4)+AnA(j))=EndRPxD; */
      UltPosRecXDia->data[(((((NumRec[0] + NumRec[1]) + NumRec[2]) + NumRec[3])
                            + AnA->data[j]) + UltPosRecXDia->size[1] * (contDia
        - 1)) - 1] = EndRPxD;
    }

    /* 'sch:68' if IniCPOA == 0 */
    if (IniCPOA == 0) {
      /* 'sch:69' H(IniCRA:EndCRA,sum(NumRec(1:6))+CRA)=i; */
      if (IniCRA > EndCRA) {
        i29 = 0;
        b_loop_ub = 0;
      } else {
        i29 = IniCRA - 1;
        b_loop_ub = EndCRA;
      }

      y = NumRec[0];
      for (k = 0; k < 5; k++) {
        y += (double)NumRec[k + 1];
      }

      k = (int)(y + (double)CRA);
      loop_ub = b_loop_ub - i29;
      for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
        H->data[(k + H->size[1] * (i29 + b_loop_ub)) - 1] = i + 1;
      }
    } else {
      /* 'sch:70' else */
      /* 'sch:71' H(IniCPOA:EndCPOA,sum(NumRec(1:5))+CPOA)=i; */
      if (IniCPOA > EndCPOA) {
        i29 = 0;
        b_loop_ub = 0;
      } else {
        i29 = IniCPOA - 1;
        b_loop_ub = EndCPOA;
      }

      k = (int)((((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2])
                  + (double)NumRec[3]) + (double)NumRec[4]) + (double)CPOA);
      loop_ub = b_loop_ub - i29;
      for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
        H->data[(k + H->size[1] * (i29 + b_loop_ub)) - 1] = i + 1;
      }

      /* 'sch:72' H(IniCRA:EndCRA,sum(NumRec(1:6))+CRA)=i; */
      if (IniCRA > EndCRA) {
        i29 = 0;
        b_loop_ub = 0;
      } else {
        i29 = IniCRA - 1;
        b_loop_ub = EndCRA;
      }

      y = NumRec[0];
      for (k = 0; k < 5; k++) {
        y += (double)NumRec[k + 1];
      }

      k = (int)(y + (double)CRA);
      loop_ub = b_loop_ub - i29;
      for (b_loop_ub = 0; b_loop_ub < loop_ub; b_loop_ub++) {
        H->data[(k + H->size[1] * (i29 + b_loop_ub)) - 1] = i + 1;
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
  emxFree_int32_T(&SA);
  emxFree_int32_T(&AnA);
  emxFree_int32_T(&AA);
  emxFree_int32_T(&EA);
  emxFree_int32_T(&DispME);
  emxFree_int32_T(&tempUltPosRecXDia);
  emxFree_int32_T(&UltPosRecXDia);

  /* 'sch:77' schedule=H; */
  /* 'sch:79' [ fitness,Tt,NOFP,TmNOFP,NOE2,NOE3] = favalia( schedule,DiaOp,int32(EP),EspMedOp,k0,k1,k2,k3 ); */
  favalia(H, DiaOp, EP, EspMedOp, k0, k1, k2, k3, &d5, &d6, &d7, &d8, &d9, &d10);
  *NOE3 = d10;
  *NOE2 = d9;
  *TmNOFP = d8;
  *NOFP = d7;
  *Tt = d6;
  *fitness = d5;
  emxFree_int32_T(&EspMedOp);
  emxFree_int32_T(&DiaOp);
  emxFree_int32_T(&H);
}

/*
 * File trailer for sch.c
 *
 * [EOF]
 */
