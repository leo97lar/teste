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
  int i22;
  int i23;
  int loop_ub;
  emxArray_real_T *UltPosRecXDia;
  emxArray_real_T *EspMedOp;
  emxArray_int32_T *b_TimeUsoRec;
  emxArray_int32_T *b_PME;
  emxArray_int32_T *DiaOp;
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *DispME;
  emxArray_int32_T *EA;
  emxArray_int32_T *AA;
  emxArray_int32_T *AnA;
  emxArray_int32_T *SA;
  emxArray_int32_T *r7;
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
  y = NumRec[0];
  for (k = 0; k < 6; k++) {
    y += (double)NumRec[k + 1];
  }

  emxInit_real_T(&H, 2);
  i22 = H->size[0] * H->size[1];
  H->size[0] = Data->size[0];
  i23 = (int)y;
  H->size[1] = i23;
  emxEnsureCapacity_real_T(H, i22);
  loop_ub = Data->size[0] * i23;
  for (i22 = 0; i22 < loop_ub; i22++) {
    H->data[i22] = 0.0;
  }

  emxInit_real_T(&UltPosRecXDia, 2);

  /*  Schedule completo */
  i22 = UltPosRecXDia->size[0] * UltPosRecXDia->size[1];
  UltPosRecXDia->size[0] = Dia->size[0];
  UltPosRecXDia->size[1] = i23;
  emxEnsureCapacity_real_T(UltPosRecXDia, i22);
  loop_ub = Dia->size[0] * i23;
  for (i22 = 0; i22 < loop_ub; i22++) {
    UltPosRecXDia->data[i22] = 0.0;
  }

  emxInit_real_T(&EspMedOp, 2);

  /*  Ultima posicion asignado del recurso por Dia */
  i22 = EspMedOp->size[0] * EspMedOp->size[1];
  EspMedOp->size[0] = NumTOp;
  EspMedOp->size[1] = 2;
  emxEnsureCapacity_real_T(EspMedOp, i22);
  loop_ub = NumTOp << 1;
  for (i22 = 0; i22 < loop_ub; i22++) {
    EspMedOp->data[i22] = 0.0;
  }

  emxInit_int32_T(&b_TimeUsoRec, 2);
  i22 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[0] = list->size[0];
  b_TimeUsoRec->size[1] = 7;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i22);
  for (i22 = 0; i22 < 7; i22++) {
    loop_ub = list->size[0];
    for (i23 = 0; i23 < loop_ub; i23++) {
      b_TimeUsoRec->data[i23 + b_TimeUsoRec->size[0] * i22] = TimeUsoRec->data
        [(list->data[i23] + TimeUsoRec->size[0] * i22) - 1];
    }
  }

  i22 = TimeUsoRec->size[0] * TimeUsoRec->size[1];
  TimeUsoRec->size[0] = b_TimeUsoRec->size[0];
  TimeUsoRec->size[1] = 7;
  emxEnsureCapacity_int32_T(TimeUsoRec, i22);
  loop_ub = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  for (i22 = 0; i22 < loop_ub; i22++) {
    TimeUsoRec->data[i22] = b_TimeUsoRec->data[i22];
  }

  emxFree_int32_T(&b_TimeUsoRec);
  emxInit_int32_T(&b_PME, 2);
  loop_ub = PME->size[1] - 1;
  i22 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i22);
  for (i22 = 0; i22 <= loop_ub; i22++) {
    k = list->size[0];
    for (i23 = 0; i23 < k; i23++) {
      b_PME->data[i23 + b_PME->size[0] * i22] = PME->data[(list->data[i23] +
        PME->size[0] * i22) - 1];
    }
  }

  i22 = PME->size[0] * PME->size[1];
  PME->size[0] = b_PME->size[0];
  PME->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PME, i22);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i22 = 0; i22 < loop_ub; i22++) {
    PME->data[i22] = b_PME->data[i22];
  }

  loop_ub = PMA->size[1] - 1;
  i22 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i22);
  for (i22 = 0; i22 <= loop_ub; i22++) {
    k = list->size[0];
    for (i23 = 0; i23 < k; i23++) {
      b_PME->data[i23 + b_PME->size[0] * i22] = PMA->data[(list->data[i23] +
        PMA->size[0] * i22) - 1];
    }
  }

  i22 = PMA->size[0] * PMA->size[1];
  PMA->size[0] = b_PME->size[0];
  PMA->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PMA, i22);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i22 = 0; i22 < loop_ub; i22++) {
    PMA->data[i22] = b_PME->data[i22];
  }

  loop_ub = PMAn->size[1] - 1;
  i22 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i22);
  for (i22 = 0; i22 <= loop_ub; i22++) {
    k = list->size[0];
    for (i23 = 0; i23 < k; i23++) {
      b_PME->data[i23 + b_PME->size[0] * i22] = PMAn->data[(list->data[i23] +
        PMAn->size[0] * i22) - 1];
    }
  }

  i22 = PMAn->size[0] * PMAn->size[1];
  PMAn->size[0] = b_PME->size[0];
  PMAn->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PMAn, i22);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i22 = 0; i22 < loop_ub; i22++) {
    PMAn->data[i22] = b_PME->data[i22];
  }

  loop_ub = PCPrO->size[1] - 1;
  i22 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i22);
  for (i22 = 0; i22 <= loop_ub; i22++) {
    k = list->size[0];
    for (i23 = 0; i23 < k; i23++) {
      b_PME->data[i23 + b_PME->size[0] * i22] = PCPrO->data[(list->data[i23] +
        PCPrO->size[0] * i22) - 1];
    }
  }

  i22 = PCPrO->size[0] * PCPrO->size[1];
  PCPrO->size[0] = b_PME->size[0];
  PCPrO->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCPrO, i22);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i22 = 0; i22 < loop_ub; i22++) {
    PCPrO->data[i22] = b_PME->data[i22];
  }

  loop_ub = PS->size[1] - 1;
  i22 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i22);
  for (i22 = 0; i22 <= loop_ub; i22++) {
    k = list->size[0];
    for (i23 = 0; i23 < k; i23++) {
      b_PME->data[i23 + b_PME->size[0] * i22] = PS->data[(list->data[i23] +
        PS->size[0] * i22) - 1];
    }
  }

  i22 = PS->size[0] * PS->size[1];
  PS->size[0] = b_PME->size[0];
  PS->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PS, i22);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i22 = 0; i22 < loop_ub; i22++) {
    PS->data[i22] = b_PME->data[i22];
  }

  loop_ub = PCPO->size[1] - 1;
  i22 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i22);
  for (i22 = 0; i22 <= loop_ub; i22++) {
    k = list->size[0];
    for (i23 = 0; i23 < k; i23++) {
      b_PME->data[i23 + b_PME->size[0] * i22] = PCPO->data[(list->data[i23] +
        PCPO->size[0] * i22) - 1];
    }
  }

  i22 = PCPO->size[0] * PCPO->size[1];
  PCPO->size[0] = b_PME->size[0];
  PCPO->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCPO, i22);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i22 = 0; i22 < loop_ub; i22++) {
    PCPO->data[i22] = b_PME->data[i22];
  }

  loop_ub = PCR->size[1] - 1;
  i22 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i22);
  for (i22 = 0; i22 <= loop_ub; i22++) {
    k = list->size[0];
    for (i23 = 0; i23 < k; i23++) {
      b_PME->data[i23 + b_PME->size[0] * i22] = PCR->data[(list->data[i23] +
        PCR->size[0] * i22) - 1];
    }
  }

  i22 = PCR->size[0] * PCR->size[1];
  PCR->size[0] = b_PME->size[0];
  PCR->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCR, i22);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i22 = 0; i22 < loop_ub; i22++) {
    PCR->data[i22] = b_PME->data[i22];
  }

  emxFree_int32_T(&b_PME);
  emxInit_int32_T(&DiaOp, 1);
  i22 = DiaOp->size[0];
  DiaOp->size[0] = list->size[0];
  emxEnsureCapacity_int32_T(DiaOp, i22);
  loop_ub = list->size[0];
  for (i22 = 0; i22 < loop_ub; i22++) {
    DiaOp->data[i22] = EP->data[list->data[i22] - 1];
  }

  i22 = EP->size[0];
  EP->size[0] = DiaOp->size[0];
  emxEnsureCapacity_int32_T(EP, i22);
  loop_ub = DiaOp->size[0];
  for (i22 = 0; i22 < loop_ub; i22++) {
    EP->data[i22] = DiaOp->data[i22];
  }

  i22 = DiaOp->size[0];
  DiaOp->size[0] = NumTOp;
  emxEnsureCapacity_int32_T(DiaOp, i22);
  emxInit_int32_T(&tempUltPosRecXDia, 2);
  emxInit_int32_T(&DispME, 2);
  emxInit_int32_T(&EA, 2);
  emxInit_int32_T(&AA, 2);
  emxInit_int32_T(&AnA, 2);
  emxInit_int32_T(&SA, 2);
  emxInit_int32_T(&r7, 1);
  emxInit_int32_T(&b_PCPrO, 2);
  emxInit_int32_T(&c_PME, 2);
  emxInit_int32_T(&b_PMA, 2);
  emxInit_int32_T(&b_PMAn, 2);
  emxInit_int32_T(&b_PS, 2);
  emxInit_int32_T(&b_PCPO, 2);
  emxInit_int32_T(&b_PCR, 2);
  for (i = 0; i < NumTOp; i++) {
    contDia = 2;
    loop_ub = PCPrO->size[1];
    i22 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPrO, i22);
    for (i22 = 0; i22 < loop_ub; i22++) {
      b_PCPrO->data[i22] = PCPrO->data[i + PCPrO->size[0] * i22];
    }

    b_funcionDia(NumRec, b_PCPrO, Dia, UltPosRecXDia, TimeUsoRec->data[i],
                 TimeUsoRec->data[i + TimeUsoRec->size[0]], &contDia, DispMExD,
                 tempUltPosRecXDia, DispME);
    loop_ub = PCPrO->size[1];
    i22 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPrO, i22);
    for (i22 = 0; i22 < loop_ub; i22++) {
      b_PCPrO->data[i22] = PCPrO->data[i + PCPrO->size[0] * i22];
    }

    loop_ub = PME->size[1];
    i22 = c_PME->size[0] * c_PME->size[1];
    c_PME->size[0] = 1;
    c_PME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(c_PME, i22);
    for (i22 = 0; i22 < loop_ub; i22++) {
      c_PME->data[i22] = PME->data[i + PME->size[0] * i22];
    }

    loop_ub = PMA->size[1];
    i22 = b_PMA->size[0] * b_PMA->size[1];
    b_PMA->size[0] = 1;
    b_PMA->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PMA, i22);
    for (i22 = 0; i22 < loop_ub; i22++) {
      b_PMA->data[i22] = PMA->data[i + PMA->size[0] * i22];
    }

    loop_ub = PMAn->size[1];
    i22 = b_PMAn->size[0] * b_PMAn->size[1];
    b_PMAn->size[0] = 1;
    b_PMAn->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PMAn, i22);
    for (i22 = 0; i22 < loop_ub; i22++) {
      b_PMAn->data[i22] = PMAn->data[i + PMAn->size[0] * i22];
    }

    loop_ub = PS->size[1];
    i22 = b_PS->size[0] * b_PS->size[1];
    b_PS->size[0] = 1;
    b_PS->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PS, i22);
    for (i22 = 0; i22 < loop_ub; i22++) {
      b_PS->data[i22] = PS->data[i + PS->size[0] * i22];
    }

    loop_ub = PCPO->size[1];
    i22 = b_PCPO->size[0] * b_PCPO->size[1];
    b_PCPO->size[0] = 1;
    b_PCPO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPO, i22);
    for (i22 = 0; i22 < loop_ub; i22++) {
      b_PCPO->data[i22] = PCPO->data[i + PCPO->size[0] * i22];
    }

    loop_ub = PCR->size[1];
    i22 = b_PCR->size[0] * b_PCR->size[1];
    b_PCR->size[0] = 1;
    b_PCR->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCR, i22);
    for (i22 = 0; i22 < loop_ub; i22++) {
      b_PCR->data[i22] = PCR->data[i + PCR->size[0] * i22];
    }

    b_funcionCPrO(NumRec, b_PCPrO, c_PME, b_PMA, b_PMAn, b_PS, b_PCPO, b_PCR, H,
                  Dia, UltPosRecXDia, TimeUsoRec->data[i], TimeUsoRec->data[i +
                  TimeUsoRec->size[0]], TimeUsoRec->data[i + TimeUsoRec->size[0]
                  * 5], TimeUsoRec->data[i + TimeUsoRec->size[0] * 6], &contDia,
                  tempUltPosRecXDia, DispMExD, DispME, &CPrOA, &k, &EndCPrOA,
                  &EndCPrOAxD, EA, AA, AnA, SA, &IniSA, &EndSA, &EndRPxD, &CPOA,
                  &IniCPOA, &EndCPOA, &CRA, &IniCRA, &EndCRA);
    DiaOp->data[i] = contDia;
    if (k > EndCPrOA) {
      i22 = 0;
      EndCPrOA = 0;
    } else {
      i22 = k - 1;
    }

    loop_ub = EndCPrOA - i22;
    for (i23 = 0; i23 < loop_ub; i23++) {
      H->data[(i22 + i23) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
    }

    UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (CPrOA - 1)) - 1] =
      EndCPrOAxD;
    if (IniSA > EndSA) {
      i22 = 0;
      i23 = 0;
    } else {
      i22 = IniSA - 1;
      i23 = EndSA;
    }

    if ((NumRec[0] < 0) && (NumRec[1] < MIN_int32_T - NumRec[0])) {
      CPrOA = MIN_int32_T;
    } else if ((NumRec[0] > 0) && (NumRec[1] > MAX_int32_T - NumRec[0])) {
      CPrOA = MAX_int32_T;
    } else {
      CPrOA = NumRec[0] + NumRec[1];
    }

    EndCPrOAxD = r7->size[0];
    r7->size[0] = SA->size[1];
    emxEnsureCapacity_int32_T(r7, EndCPrOAxD);
    loop_ub = SA->size[1];
    for (EndCPrOAxD = 0; EndCPrOAxD < loop_ub; EndCPrOAxD++) {
      EndCPrOA = SA->data[EndCPrOAxD];
      if ((CPrOA < 0) && (EndCPrOA < MIN_int32_T - CPrOA)) {
        k = MIN_int32_T;
      } else if ((CPrOA > 0) && (EndCPrOA > MAX_int32_T - CPrOA)) {
        k = MAX_int32_T;
      } else {
        k = CPrOA + EndCPrOA;
      }

      r7->data[EndCPrOAxD] = k;
    }

    k = i23 - i22;
    EndCPrOA = r7->size[0];
    for (i23 = 0; i23 < EndCPrOA; i23++) {
      for (EndCPrOAxD = 0; EndCPrOAxD < k; EndCPrOAxD++) {
        H->data[(i22 + EndCPrOAxD) + H->size[0] * (r7->data[i23] - 1)] =
          (unsigned int)(i + 1);
      }
    }

    EndCPrOA = r7->size[0];
    for (i22 = 0; i22 < EndCPrOA; i22++) {
      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (r7->data[i22] - 1))
        - 1] = EndRPxD;
    }

    i22 = EA->size[1];
    if (0 <= i22 - 1) {
      if (IniSA > EndSA) {
        i24 = 0;
        i25 = 0;
      } else {
        i24 = IniSA - 1;
        i25 = EndSA;
      }
    }

    for (k = 0; k < i22; k++) {
      EndCPrOA = EA->data[k];
      if ((NumRec[0] < 0) && (EndCPrOA < MIN_int32_T - NumRec[0])) {
        CPrOA = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (EndCPrOA > MAX_int32_T - NumRec[0])) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA = NumRec[0] + EndCPrOA;
      }

      loop_ub = i25 - i24;
      for (i23 = 0; i23 < loop_ub; i23++) {
        H->data[(i24 + i23) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
      }

      EndCPrOA = EA->data[k];
      if ((NumRec[0] < 0) && (EndCPrOA < MIN_int32_T - NumRec[0])) {
        CPrOA = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (EndCPrOA > MAX_int32_T - NumRec[0])) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA = NumRec[0] + EndCPrOA;
      }

      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (CPrOA - 1)) - 1] =
        EndRPxD;
      EspMedOp->data[i + EspMedOp->size[0] * k] = PME->data[i + PME->size[0] *
        (EA->data[k] - 1)];
    }

    i22 = AA->size[1];
    if (0 <= i22 - 1) {
      if (IniSA > EndSA) {
        i26 = 0;
        i27 = 0;
      } else {
        i26 = IniSA - 1;
        i27 = EndSA;
      }
    }

    for (k = 0; k < i22; k++) {
      if ((NumRec[0] < 0) && (NumRec[1] < MIN_int32_T - NumRec[0])) {
        CPrOA = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (NumRec[1] > MAX_int32_T - NumRec[0])) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA = NumRec[0] + NumRec[1];
      }

      if ((CPrOA < 0) && (NumRec[2] < MIN_int32_T - CPrOA)) {
        CPrOA = MIN_int32_T;
      } else if ((CPrOA > 0) && (NumRec[2] > MAX_int32_T - CPrOA)) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA += NumRec[2];
      }

      EndCPrOA = AA->data[k];
      if ((CPrOA < 0) && (EndCPrOA < MIN_int32_T - CPrOA)) {
        CPrOA = MIN_int32_T;
      } else if ((CPrOA > 0) && (EndCPrOA > MAX_int32_T - CPrOA)) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA += EndCPrOA;
      }

      loop_ub = i27 - i26;
      for (i23 = 0; i23 < loop_ub; i23++) {
        H->data[(i26 + i23) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
      }

      if ((NumRec[0] < 0) && (NumRec[1] < MIN_int32_T - NumRec[0])) {
        CPrOA = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (NumRec[1] > MAX_int32_T - NumRec[0])) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA = NumRec[0] + NumRec[1];
      }

      if ((CPrOA < 0) && (NumRec[2] < MIN_int32_T - CPrOA)) {
        CPrOA = MIN_int32_T;
      } else if ((CPrOA > 0) && (NumRec[2] > MAX_int32_T - CPrOA)) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA += NumRec[2];
      }

      EndCPrOA = AA->data[k];
      if ((CPrOA < 0) && (EndCPrOA < MIN_int32_T - CPrOA)) {
        CPrOA = MIN_int32_T;
      } else if ((CPrOA > 0) && (EndCPrOA > MAX_int32_T - CPrOA)) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA += EndCPrOA;
      }

      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (CPrOA - 1)) - 1] =
        EndRPxD;
    }

    i22 = AnA->size[1];
    if (0 <= i22 - 1) {
      if (IniSA > EndSA) {
        i28 = 0;
        i29 = 0;
      } else {
        i28 = IniSA - 1;
        i29 = EndSA;
      }
    }

    for (k = 0; k < i22; k++) {
      if ((NumRec[0] < 0) && (NumRec[1] < MIN_int32_T - NumRec[0])) {
        CPrOA = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (NumRec[1] > MAX_int32_T - NumRec[0])) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA = NumRec[0] + NumRec[1];
      }

      if ((CPrOA < 0) && (NumRec[2] < MIN_int32_T - CPrOA)) {
        CPrOA = MIN_int32_T;
      } else if ((CPrOA > 0) && (NumRec[2] > MAX_int32_T - CPrOA)) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA += NumRec[2];
      }

      if ((CPrOA < 0) && (NumRec[3] < MIN_int32_T - CPrOA)) {
        CPrOA = MIN_int32_T;
      } else if ((CPrOA > 0) && (NumRec[3] > MAX_int32_T - CPrOA)) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA += NumRec[3];
      }

      EndCPrOA = AnA->data[k];
      if ((CPrOA < 0) && (EndCPrOA < MIN_int32_T - CPrOA)) {
        CPrOA = MIN_int32_T;
      } else if ((CPrOA > 0) && (EndCPrOA > MAX_int32_T - CPrOA)) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA += EndCPrOA;
      }

      loop_ub = i29 - i28;
      for (i23 = 0; i23 < loop_ub; i23++) {
        H->data[(i28 + i23) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
      }

      if ((NumRec[0] < 0) && (NumRec[1] < MIN_int32_T - NumRec[0])) {
        CPrOA = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (NumRec[1] > MAX_int32_T - NumRec[0])) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA = NumRec[0] + NumRec[1];
      }

      if ((CPrOA < 0) && (NumRec[2] < MIN_int32_T - CPrOA)) {
        CPrOA = MIN_int32_T;
      } else if ((CPrOA > 0) && (NumRec[2] > MAX_int32_T - CPrOA)) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA += NumRec[2];
      }

      if ((CPrOA < 0) && (NumRec[3] < MIN_int32_T - CPrOA)) {
        CPrOA = MIN_int32_T;
      } else if ((CPrOA > 0) && (NumRec[3] > MAX_int32_T - CPrOA)) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA += NumRec[3];
      }

      EndCPrOA = AnA->data[k];
      if ((CPrOA < 0) && (EndCPrOA < MIN_int32_T - CPrOA)) {
        CPrOA = MIN_int32_T;
      } else if ((CPrOA > 0) && (EndCPrOA > MAX_int32_T - CPrOA)) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA += EndCPrOA;
      }

      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (CPrOA - 1)) - 1] =
        EndRPxD;
    }

    if (IniCPOA == 0) {
      if (IniCRA > EndCRA) {
        i22 = 0;
        EndCRA = 0;
      } else {
        i22 = IniCRA - 1;
      }

      y = NumRec[0];
      for (k = 0; k < 5; k++) {
        y += (double)NumRec[k + 1];
      }

      y += (double)CRA;
      if (y < 2.147483648E+9) {
        if (y >= -2.147483648E+9) {
          k = (int)y;
        } else {
          k = MIN_int32_T;
        }
      } else {
        k = MAX_int32_T;
      }

      loop_ub = EndCRA - i22;
      for (i23 = 0; i23 < loop_ub; i23++) {
        H->data[(i22 + i23) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
      }
    } else {
      if (IniCPOA > EndCPOA) {
        i22 = 0;
        EndCPOA = 0;
      } else {
        i22 = IniCPOA - 1;
      }

      y = (((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
            (double)NumRec[3]) + (double)NumRec[4]) + (double)CPOA;
      if (y < 2.147483648E+9) {
        if (y >= -2.147483648E+9) {
          k = (int)y;
        } else {
          k = MIN_int32_T;
        }
      } else {
        k = MAX_int32_T;
      }

      loop_ub = EndCPOA - i22;
      for (i23 = 0; i23 < loop_ub; i23++) {
        H->data[(i22 + i23) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
      }

      if (IniCRA > EndCRA) {
        i22 = 0;
        EndCRA = 0;
      } else {
        i22 = IniCRA - 1;
      }

      y = NumRec[0];
      for (k = 0; k < 5; k++) {
        y += (double)NumRec[k + 1];
      }

      y += (double)CRA;
      if (y < 2.147483648E+9) {
        if (y >= -2.147483648E+9) {
          k = (int)y;
        } else {
          k = MIN_int32_T;
        }
      } else {
        k = MAX_int32_T;
      }

      loop_ub = EndCRA - i22;
      for (i23 = 0; i23 < loop_ub; i23++) {
        H->data[(i22 + i23) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
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
  emxFree_int32_T(&r7);
  emxFree_int32_T(&SA);
  emxFree_int32_T(&AnA);
  emxFree_int32_T(&AA);
  emxFree_int32_T(&EA);
  emxFree_int32_T(&DispME);
  emxFree_int32_T(&tempUltPosRecXDia);
  emxFree_real_T(&UltPosRecXDia);
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
