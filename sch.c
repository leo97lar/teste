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
#include <string.h>
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
#include "model_rtwutil.h"

/* Function Definitions */
void b_sch(int NumTOp, const emxArray_int32_T *list, const int NumRec[7],
           emxArray_int32_T *PCPrO, emxArray_int32_T *PME, emxArray_int32_T *PMA,
           emxArray_int32_T *PMAn, emxArray_int32_T *PS, emxArray_int32_T *PCPO,
           emxArray_int32_T *PCR, const emxArray_int32_T *Dia, const
           emxArray_int32_T *Data, emxArray_int32_T *TimeUsoRec, const
           emxArray_int32_T *DispMExD, emxArray_real_T *EP, double k0, double k1,
           double k2, double k3, double *fitness, double *Tt, double *NOFP,
           double *TmNOFP, double *NOE2, double *NOE3)
{
  double y;
  int k;
  emxArray_real_T *H;
  int i8;
  int i9;
  int loop_ub;
  emxArray_real_T *UltPosRecXDia;
  emxArray_real_T *EspMedOp;
  emxArray_int32_T *b_TimeUsoRec;
  emxArray_int32_T *b_PME;
  emxArray_real_T *b_EP;
  emxArray_int32_T *DiaOp;
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *DispME;
  emxArray_int32_T *EA;
  emxArray_int32_T *AA;
  emxArray_int32_T *AnA;
  emxArray_int32_T *SA;
  emxArray_int32_T *c_EP;
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
  int i10;
  int i11;
  int i12;
  int i13;
  int i14;
  int i15;

  /* UNTITLED4 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*     NCPrO  |    NME    |     NS    |     NA    |     NAn    |    NCPO     |   NCR */
  /*   Col 1-20 | Col 21-50 | Col 51-62 | Col 63-87 | Col 88-112 | Col 113-132 | Col 133-152 */
  y = NumRec[0];
  for (k = 0; k < 6; k++) {
    y += (double)NumRec[k + 1];
  }

  emxInit_real_T(&H, 2);
  i8 = H->size[0] * H->size[1];
  H->size[0] = Data->size[0];
  i9 = (int)y;
  H->size[1] = i9;
  emxEnsureCapacity_real_T(H, i8);
  loop_ub = Data->size[0] * i9;
  for (i8 = 0; i8 < loop_ub; i8++) {
    H->data[i8] = 0.0;
  }

  emxInit_real_T(&UltPosRecXDia, 2);

  /*  Schedule completo */
  i8 = UltPosRecXDia->size[0] * UltPosRecXDia->size[1];
  UltPosRecXDia->size[0] = Dia->size[0];
  UltPosRecXDia->size[1] = i9;
  emxEnsureCapacity_real_T(UltPosRecXDia, i8);
  loop_ub = Dia->size[0] * i9;
  for (i8 = 0; i8 < loop_ub; i8++) {
    UltPosRecXDia->data[i8] = 0.0;
  }

  emxInit_real_T(&EspMedOp, 2);

  /*  Ultima posicion asignado del recurso por Dia */
  i8 = EspMedOp->size[0] * EspMedOp->size[1];
  EspMedOp->size[0] = NumTOp;
  EspMedOp->size[1] = 2;
  emxEnsureCapacity_real_T(EspMedOp, i8);
  loop_ub = NumTOp << 1;
  for (i8 = 0; i8 < loop_ub; i8++) {
    EspMedOp->data[i8] = 0.0;
  }

  emxInit_int32_T(&b_TimeUsoRec, 2);
  i8 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[0] = list->size[0];
  b_TimeUsoRec->size[1] = 7;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i8);
  for (i8 = 0; i8 < 7; i8++) {
    loop_ub = list->size[0];
    for (i9 = 0; i9 < loop_ub; i9++) {
      b_TimeUsoRec->data[i9 + b_TimeUsoRec->size[0] * i8] = TimeUsoRec->data
        [(list->data[i9] + TimeUsoRec->size[0] * i8) - 1];
    }
  }

  i8 = TimeUsoRec->size[0] * TimeUsoRec->size[1];
  TimeUsoRec->size[0] = b_TimeUsoRec->size[0];
  TimeUsoRec->size[1] = 7;
  emxEnsureCapacity_int32_T(TimeUsoRec, i8);
  loop_ub = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    TimeUsoRec->data[i8] = b_TimeUsoRec->data[i8];
  }

  emxFree_int32_T(&b_TimeUsoRec);
  emxInit_int32_T(&b_PME, 2);
  loop_ub = PME->size[1] - 1;
  i8 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i8);
  for (i8 = 0; i8 <= loop_ub; i8++) {
    k = list->size[0];
    for (i9 = 0; i9 < k; i9++) {
      b_PME->data[i9 + b_PME->size[0] * i8] = PME->data[(list->data[i9] +
        PME->size[0] * i8) - 1];
    }
  }

  i8 = PME->size[0] * PME->size[1];
  PME->size[0] = b_PME->size[0];
  PME->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PME, i8);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    PME->data[i8] = b_PME->data[i8];
  }

  loop_ub = PMA->size[1] - 1;
  i8 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i8);
  for (i8 = 0; i8 <= loop_ub; i8++) {
    k = list->size[0];
    for (i9 = 0; i9 < k; i9++) {
      b_PME->data[i9 + b_PME->size[0] * i8] = PMA->data[(list->data[i9] +
        PMA->size[0] * i8) - 1];
    }
  }

  i8 = PMA->size[0] * PMA->size[1];
  PMA->size[0] = b_PME->size[0];
  PMA->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PMA, i8);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    PMA->data[i8] = b_PME->data[i8];
  }

  loop_ub = PMAn->size[1] - 1;
  i8 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i8);
  for (i8 = 0; i8 <= loop_ub; i8++) {
    k = list->size[0];
    for (i9 = 0; i9 < k; i9++) {
      b_PME->data[i9 + b_PME->size[0] * i8] = PMAn->data[(list->data[i9] +
        PMAn->size[0] * i8) - 1];
    }
  }

  i8 = PMAn->size[0] * PMAn->size[1];
  PMAn->size[0] = b_PME->size[0];
  PMAn->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PMAn, i8);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    PMAn->data[i8] = b_PME->data[i8];
  }

  loop_ub = PCPrO->size[1] - 1;
  i8 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i8);
  for (i8 = 0; i8 <= loop_ub; i8++) {
    k = list->size[0];
    for (i9 = 0; i9 < k; i9++) {
      b_PME->data[i9 + b_PME->size[0] * i8] = PCPrO->data[(list->data[i9] +
        PCPrO->size[0] * i8) - 1];
    }
  }

  i8 = PCPrO->size[0] * PCPrO->size[1];
  PCPrO->size[0] = b_PME->size[0];
  PCPrO->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCPrO, i8);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    PCPrO->data[i8] = b_PME->data[i8];
  }

  loop_ub = PS->size[1] - 1;
  i8 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i8);
  for (i8 = 0; i8 <= loop_ub; i8++) {
    k = list->size[0];
    for (i9 = 0; i9 < k; i9++) {
      b_PME->data[i9 + b_PME->size[0] * i8] = PS->data[(list->data[i9] +
        PS->size[0] * i8) - 1];
    }
  }

  i8 = PS->size[0] * PS->size[1];
  PS->size[0] = b_PME->size[0];
  PS->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PS, i8);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    PS->data[i8] = b_PME->data[i8];
  }

  loop_ub = PCPO->size[1] - 1;
  i8 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i8);
  for (i8 = 0; i8 <= loop_ub; i8++) {
    k = list->size[0];
    for (i9 = 0; i9 < k; i9++) {
      b_PME->data[i9 + b_PME->size[0] * i8] = PCPO->data[(list->data[i9] +
        PCPO->size[0] * i8) - 1];
    }
  }

  i8 = PCPO->size[0] * PCPO->size[1];
  PCPO->size[0] = b_PME->size[0];
  PCPO->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCPO, i8);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    PCPO->data[i8] = b_PME->data[i8];
  }

  loop_ub = PCR->size[1] - 1;
  i8 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i8);
  for (i8 = 0; i8 <= loop_ub; i8++) {
    k = list->size[0];
    for (i9 = 0; i9 < k; i9++) {
      b_PME->data[i9 + b_PME->size[0] * i8] = PCR->data[(list->data[i9] +
        PCR->size[0] * i8) - 1];
    }
  }

  i8 = PCR->size[0] * PCR->size[1];
  PCR->size[0] = b_PME->size[0];
  PCR->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCR, i8);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    PCR->data[i8] = b_PME->data[i8];
  }

  emxFree_int32_T(&b_PME);
  emxInit_real_T(&b_EP, 1);
  i8 = b_EP->size[0];
  b_EP->size[0] = list->size[0];
  emxEnsureCapacity_real_T(b_EP, i8);
  loop_ub = list->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    b_EP->data[i8] = EP->data[list->data[i8] - 1];
  }

  i8 = EP->size[0];
  EP->size[0] = b_EP->size[0];
  emxEnsureCapacity_real_T(EP, i8);
  loop_ub = b_EP->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    EP->data[i8] = b_EP->data[i8];
  }

  emxFree_real_T(&b_EP);
  emxInit_int32_T(&DiaOp, 1);
  i8 = DiaOp->size[0];
  DiaOp->size[0] = NumTOp;
  emxEnsureCapacity_int32_T(DiaOp, i8);
  emxInit_int32_T(&tempUltPosRecXDia, 2);
  emxInit_int32_T(&DispME, 2);
  emxInit_int32_T(&EA, 2);
  emxInit_int32_T(&AA, 2);
  emxInit_int32_T(&AnA, 2);
  emxInit_int32_T(&SA, 2);
  emxInit_int32_T(&c_EP, 1);
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
    i8 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPrO, i8);
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_PCPrO->data[i8] = PCPrO->data[i + PCPrO->size[0] * i8];
    }

    b_funcionDia(NumRec, b_PCPrO, Dia, UltPosRecXDia, TimeUsoRec->data[i],
                 TimeUsoRec->data[i + TimeUsoRec->size[0]], &contDia, DispMExD,
                 tempUltPosRecXDia, DispME);
    loop_ub = PCPrO->size[1];
    i8 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPrO, i8);
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_PCPrO->data[i8] = PCPrO->data[i + PCPrO->size[0] * i8];
    }

    loop_ub = PME->size[1];
    i8 = c_PME->size[0] * c_PME->size[1];
    c_PME->size[0] = 1;
    c_PME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(c_PME, i8);
    for (i8 = 0; i8 < loop_ub; i8++) {
      c_PME->data[i8] = PME->data[i + PME->size[0] * i8];
    }

    loop_ub = PMA->size[1];
    i8 = b_PMA->size[0] * b_PMA->size[1];
    b_PMA->size[0] = 1;
    b_PMA->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PMA, i8);
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_PMA->data[i8] = PMA->data[i + PMA->size[0] * i8];
    }

    loop_ub = PMAn->size[1];
    i8 = b_PMAn->size[0] * b_PMAn->size[1];
    b_PMAn->size[0] = 1;
    b_PMAn->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PMAn, i8);
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_PMAn->data[i8] = PMAn->data[i + PMAn->size[0] * i8];
    }

    loop_ub = PS->size[1];
    i8 = b_PS->size[0] * b_PS->size[1];
    b_PS->size[0] = 1;
    b_PS->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PS, i8);
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_PS->data[i8] = PS->data[i + PS->size[0] * i8];
    }

    loop_ub = PCPO->size[1];
    i8 = b_PCPO->size[0] * b_PCPO->size[1];
    b_PCPO->size[0] = 1;
    b_PCPO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPO, i8);
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_PCPO->data[i8] = PCPO->data[i + PCPO->size[0] * i8];
    }

    loop_ub = PCR->size[1];
    i8 = b_PCR->size[0] * b_PCR->size[1];
    b_PCR->size[0] = 1;
    b_PCR->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCR, i8);
    for (i8 = 0; i8 < loop_ub; i8++) {
      b_PCR->data[i8] = PCR->data[i + PCR->size[0] * i8];
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
      i8 = 0;
      EndCPrOA = 0;
    } else {
      i8 = k - 1;
    }

    loop_ub = EndCPrOA - i8;
    for (i9 = 0; i9 < loop_ub; i9++) {
      H->data[(i8 + i9) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
    }

    UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (CPrOA - 1)) - 1] =
      EndCPrOAxD;
    if (IniSA > EndSA) {
      i8 = 0;
      i9 = 0;
    } else {
      i8 = IniSA - 1;
      i9 = EndSA;
    }

    if ((NumRec[0] < 0) && (NumRec[1] < MIN_int32_T - NumRec[0])) {
      CPrOA = MIN_int32_T;
    } else if ((NumRec[0] > 0) && (NumRec[1] > MAX_int32_T - NumRec[0])) {
      CPrOA = MAX_int32_T;
    } else {
      CPrOA = NumRec[0] + NumRec[1];
    }

    EndCPrOAxD = c_EP->size[0];
    c_EP->size[0] = SA->size[1];
    emxEnsureCapacity_int32_T(c_EP, EndCPrOAxD);
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

      c_EP->data[EndCPrOAxD] = k;
    }

    k = i9 - i8;
    EndCPrOA = c_EP->size[0];
    for (i9 = 0; i9 < EndCPrOA; i9++) {
      for (EndCPrOAxD = 0; EndCPrOAxD < k; EndCPrOAxD++) {
        H->data[(i8 + EndCPrOAxD) + H->size[0] * (c_EP->data[i9] - 1)] =
          (unsigned int)(i + 1);
      }
    }

    EndCPrOA = c_EP->size[0];
    for (i8 = 0; i8 < EndCPrOA; i8++) {
      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (c_EP->data[i8] -
        1)) - 1] = EndRPxD;
    }

    i8 = EA->size[1];
    if (0 <= i8 - 1) {
      if (IniSA > EndSA) {
        i10 = 0;
        i11 = 0;
      } else {
        i10 = IniSA - 1;
        i11 = EndSA;
      }
    }

    for (k = 0; k < i8; k++) {
      EndCPrOA = EA->data[k];
      if ((NumRec[0] < 0) && (EndCPrOA < MIN_int32_T - NumRec[0])) {
        CPrOA = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (EndCPrOA > MAX_int32_T - NumRec[0])) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA = NumRec[0] + EndCPrOA;
      }

      loop_ub = i11 - i10;
      for (i9 = 0; i9 < loop_ub; i9++) {
        H->data[(i10 + i9) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
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

    i8 = AA->size[1];
    if (0 <= i8 - 1) {
      if (IniSA > EndSA) {
        i12 = 0;
        i13 = 0;
      } else {
        i12 = IniSA - 1;
        i13 = EndSA;
      }
    }

    for (k = 0; k < i8; k++) {
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

      loop_ub = i13 - i12;
      for (i9 = 0; i9 < loop_ub; i9++) {
        H->data[(i12 + i9) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
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

    i8 = AnA->size[1];
    if (0 <= i8 - 1) {
      if (IniSA > EndSA) {
        i14 = 0;
        i15 = 0;
      } else {
        i14 = IniSA - 1;
        i15 = EndSA;
      }
    }

    for (k = 0; k < i8; k++) {
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

      loop_ub = i15 - i14;
      for (i9 = 0; i9 < loop_ub; i9++) {
        H->data[(i14 + i9) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
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
        i8 = 0;
        EndCRA = 0;
      } else {
        i8 = IniCRA - 1;
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

      loop_ub = EndCRA - i8;
      for (i9 = 0; i9 < loop_ub; i9++) {
        H->data[(i8 + i9) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
      }
    } else {
      if (IniCPOA > EndCPOA) {
        i8 = 0;
        EndCPOA = 0;
      } else {
        i8 = IniCPOA - 1;
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

      loop_ub = EndCPOA - i8;
      for (i9 = 0; i9 < loop_ub; i9++) {
        H->data[(i8 + i9) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
      }

      if (IniCRA > EndCRA) {
        i8 = 0;
        EndCRA = 0;
      } else {
        i8 = IniCRA - 1;
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

      loop_ub = EndCRA - i8;
      for (i9 = 0; i9 < loop_ub; i9++) {
        H->data[(i8 + i9) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
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
  emxFree_real_T(&UltPosRecXDia);
  i8 = c_EP->size[0];
  c_EP->size[0] = EP->size[0];
  emxEnsureCapacity_int32_T(c_EP, i8);
  loop_ub = EP->size[0];
  for (i8 = 0; i8 < loop_ub; i8++) {
    y = rt_roundd(EP->data[i8]);
    if (y < 2.147483648E+9) {
      if (y >= -2.147483648E+9) {
        i9 = (int)y;
      } else {
        i9 = MIN_int32_T;
      }
    } else {
      i9 = MAX_int32_T;
    }

    c_EP->data[i8] = i9;
  }

  b_favalia(H, DiaOp, c_EP, EspMedOp, k0, k1, k2, k3, &d5, &d6, &d7, &d8, &d9,
            &d10);
  *NOE3 = d10;
  *NOE2 = d9;
  *TmNOFP = d8;
  *NOFP = d7;
  *Tt = d6;
  *fitness = d5;
  emxFree_int32_T(&c_EP);
  emxFree_real_T(&EspMedOp);
  emxFree_int32_T(&DiaOp);
  emxFree_real_T(&H);
}

void c_sch(const int list_data[], const int NumRec[7], emxArray_int32_T *PCPrO,
           emxArray_int32_T *PME, emxArray_int32_T *PMA, emxArray_int32_T *PMAn,
           emxArray_int32_T *PS, emxArray_int32_T *PCPO, emxArray_int32_T *PCR,
           const int Dia_data[], const int Dia_size[2], int TimeUsoRec_data[],
           const int DispMExD_data[], const int DispMExD_size[2], int EP_data[],
           int EP_size[1], double *fitness, double *Tt, double *NOFP, double
           *TmNOFP, double *NOE2, double *NOE3)
{
  double y;
  int k;
  emxArray_real_T *H;
  int i44;
  int i45;
  int loop_ub;
  emxArray_real_T *UltPosRecXDia;
  double EspMedOp_data[4000];
  static int b_TimeUsoRec_data[14000];
  emxArray_int32_T *b_PME;
  emxArray_int32_T *b_PMA;
  emxArray_int32_T *b_PCPrO;
  emxArray_int32_T *b_PCPO;
  emxArray_int32_T *b_PCR;
  int DiaOp_size[1];
  int DiaOp_data[2000];
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *DispME;
  emxArray_int32_T *EA;
  emxArray_int32_T *AA;
  emxArray_int32_T *AnA;
  emxArray_int32_T *SA;
  int i;
  int contDia;
  int PCPrO_size[2];
  emxArray_int32_T PCPrO_data;
  int b_PCPrO_data[10];
  emxArray_real_T *EspMedOp;
  emxArray_int32_T b_Dia_data;
  emxArray_int32_T b_DiaOp_data;
  emxArray_int32_T b_DispMExD_data;
  emxArray_int32_T b_EP_data;
  double d11;
  double d12;
  double d13;
  double d14;
  double d15;
  double d16;
  int PME_size[2];
  int PME_data[31];
  int PMA_size[2];
  int PMA_data[11];
  int PMAn_size[2];
  int PS_size[2];
  int PMAn_data[11];
  int PCPO_size[2];
  int PS_data[10];
  int PCR_size[2];
  int PCPO_data[15];
  emxArray_int32_T c_PCPrO_data;
  int PCR_data[25];
  emxArray_int32_T b_PME_data;
  emxArray_int32_T b_PMA_data;
  emxArray_int32_T b_PMAn_data;
  emxArray_int32_T b_PS_data;
  emxArray_int32_T b_PCPO_data;
  emxArray_int32_T b_PCR_data;
  emxArray_int32_T c_Dia_data;
  emxArray_int32_T c_DispMExD_data;
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
  int tmp_data[9];
  int i46;
  int i47;
  int i48;
  int i49;
  int i50;
  int i51;

  /* UNTITLED4 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*     NCPrO  |    NME    |     NS    |     NA    |     NAn    |    NCPO     |   NCR */
  /*   Col 1-20 | Col 21-50 | Col 51-62 | Col 63-87 | Col 88-112 | Col 113-132 | Col 133-152 */
  y = NumRec[0];
  for (k = 0; k < 6; k++) {
    y += (double)NumRec[k + 1];
  }

  emxInit_real_T(&H, 2);
  i44 = H->size[0] * H->size[1];
  H->size[0] = 17520;
  i45 = (int)y;
  H->size[1] = i45;
  emxEnsureCapacity_real_T(H, i44);
  loop_ub = 17520 * i45;
  for (i44 = 0; i44 < loop_ub; i44++) {
    H->data[i44] = 0.0;
  }

  emxInit_real_T(&UltPosRecXDia, 2);

  /*  Schedule completo */
  i44 = UltPosRecXDia->size[0] * UltPosRecXDia->size[1];
  UltPosRecXDia->size[0] = 730;
  UltPosRecXDia->size[1] = i45;
  emxEnsureCapacity_real_T(UltPosRecXDia, i44);
  loop_ub = 730 * i45;
  for (i44 = 0; i44 < loop_ub; i44++) {
    UltPosRecXDia->data[i44] = 0.0;
  }

  /*  Ultima posicion asignado del recurso por Dia */
  memset(&EspMedOp_data[0], 0, 4000U * sizeof(double));
  for (i44 = 0; i44 < 7; i44++) {
    for (i45 = 0; i45 < 2000; i45++) {
      b_TimeUsoRec_data[i45 + 2000 * i44] = TimeUsoRec_data[(list_data[i45] +
        2000 * i44) - 1];
    }
  }

  memcpy(&TimeUsoRec_data[0], &b_TimeUsoRec_data[0], 14000U * sizeof(int));
  emxInit_int32_T(&b_PME, 2);
  loop_ub = PME->size[1] - 1;
  i44 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = 2000;
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i44);
  for (i44 = 0; i44 <= loop_ub; i44++) {
    for (i45 = 0; i45 < 2000; i45++) {
      b_PME->data[i45 + 2000 * i44] = PME->data[(list_data[i45] + 2000 * i44) -
        1];
    }
  }

  i44 = PME->size[0] * PME->size[1];
  PME->size[0] = 2000;
  PME->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PME, i44);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i44 = 0; i44 < loop_ub; i44++) {
    PME->data[i44] = b_PME->data[i44];
  }

  emxFree_int32_T(&b_PME);
  emxInit_int32_T(&b_PMA, 2);
  loop_ub = PMA->size[1] - 1;
  i44 = b_PMA->size[0] * b_PMA->size[1];
  b_PMA->size[0] = 2000;
  b_PMA->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PMA, i44);
  for (i44 = 0; i44 <= loop_ub; i44++) {
    for (i45 = 0; i45 < 2000; i45++) {
      b_PMA->data[i45 + 2000 * i44] = PMA->data[(list_data[i45] + 2000 * i44) -
        1];
    }
  }

  i44 = PMA->size[0] * PMA->size[1];
  PMA->size[0] = 2000;
  PMA->size[1] = b_PMA->size[1];
  emxEnsureCapacity_int32_T(PMA, i44);
  loop_ub = b_PMA->size[0] * b_PMA->size[1];
  for (i44 = 0; i44 < loop_ub; i44++) {
    PMA->data[i44] = b_PMA->data[i44];
  }

  loop_ub = PMAn->size[1] - 1;
  i44 = b_PMA->size[0] * b_PMA->size[1];
  b_PMA->size[0] = 2000;
  b_PMA->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PMA, i44);
  for (i44 = 0; i44 <= loop_ub; i44++) {
    for (i45 = 0; i45 < 2000; i45++) {
      b_PMA->data[i45 + 2000 * i44] = PMAn->data[(list_data[i45] + 2000 * i44) -
        1];
    }
  }

  i44 = PMAn->size[0] * PMAn->size[1];
  PMAn->size[0] = 2000;
  PMAn->size[1] = b_PMA->size[1];
  emxEnsureCapacity_int32_T(PMAn, i44);
  loop_ub = b_PMA->size[0] * b_PMA->size[1];
  for (i44 = 0; i44 < loop_ub; i44++) {
    PMAn->data[i44] = b_PMA->data[i44];
  }

  emxFree_int32_T(&b_PMA);
  emxInit_int32_T(&b_PCPrO, 2);
  i44 = b_PCPrO->size[0] * b_PCPrO->size[1];
  b_PCPrO->size[0] = 2000;
  b_PCPrO->size[1] = 10;
  emxEnsureCapacity_int32_T(b_PCPrO, i44);
  for (i44 = 0; i44 < 10; i44++) {
    for (i45 = 0; i45 < 2000; i45++) {
      b_PCPrO->data[i45 + 2000 * i44] = PCPrO->data[(list_data[i45] + 2000 * i44)
        - 1];
    }
  }

  i44 = PCPrO->size[0] * PCPrO->size[1];
  PCPrO->size[0] = 2000;
  PCPrO->size[1] = 10;
  emxEnsureCapacity_int32_T(PCPrO, i44);
  for (i44 = 0; i44 < 20000; i44++) {
    PCPrO->data[i44] = b_PCPrO->data[i44];
  }

  i44 = b_PCPrO->size[0] * b_PCPrO->size[1];
  b_PCPrO->size[0] = 2000;
  b_PCPrO->size[1] = 10;
  emxEnsureCapacity_int32_T(b_PCPrO, i44);
  for (i44 = 0; i44 < 10; i44++) {
    for (i45 = 0; i45 < 2000; i45++) {
      b_PCPrO->data[i45 + 2000 * i44] = PS->data[(list_data[i45] + 2000 * i44) -
        1];
    }
  }

  i44 = PS->size[0] * PS->size[1];
  PS->size[0] = 2000;
  PS->size[1] = 10;
  emxEnsureCapacity_int32_T(PS, i44);
  for (i44 = 0; i44 < 20000; i44++) {
    PS->data[i44] = b_PCPrO->data[i44];
  }

  emxFree_int32_T(&b_PCPrO);
  emxInit_int32_T(&b_PCPO, 2);
  i44 = b_PCPO->size[0] * b_PCPO->size[1];
  b_PCPO->size[0] = 2000;
  b_PCPO->size[1] = 15;
  emxEnsureCapacity_int32_T(b_PCPO, i44);
  for (i44 = 0; i44 < 15; i44++) {
    for (i45 = 0; i45 < 2000; i45++) {
      b_PCPO->data[i45 + 2000 * i44] = PCPO->data[(list_data[i45] + 2000 * i44)
        - 1];
    }
  }

  i44 = PCPO->size[0] * PCPO->size[1];
  PCPO->size[0] = 2000;
  PCPO->size[1] = 15;
  emxEnsureCapacity_int32_T(PCPO, i44);
  for (i44 = 0; i44 < 30000; i44++) {
    PCPO->data[i44] = b_PCPO->data[i44];
  }

  emxFree_int32_T(&b_PCPO);
  emxInit_int32_T(&b_PCR, 2);
  i44 = b_PCR->size[0] * b_PCR->size[1];
  b_PCR->size[0] = 2000;
  b_PCR->size[1] = 25;
  emxEnsureCapacity_int32_T(b_PCR, i44);
  for (i44 = 0; i44 < 25; i44++) {
    for (i45 = 0; i45 < 2000; i45++) {
      b_PCR->data[i45 + 2000 * i44] = PCR->data[(list_data[i45] + 2000 * i44) -
        1];
    }
  }

  i44 = PCR->size[0] * PCR->size[1];
  PCR->size[0] = 2000;
  PCR->size[1] = 25;
  emxEnsureCapacity_int32_T(PCR, i44);
  for (i44 = 0; i44 < 50000; i44++) {
    PCR->data[i44] = b_PCR->data[i44];
  }

  emxFree_int32_T(&b_PCR);
  DiaOp_size[0] = 2000;
  for (i44 = 0; i44 < 2000; i44++) {
    DiaOp_data[i44] = EP_data[list_data[i44] - 1];
  }

  EP_size[0] = 2000;
  memcpy(&EP_data[0], &DiaOp_data[0], 2000U * sizeof(int));
  DiaOp_size[0] = 2000;
  emxInit_int32_T(&tempUltPosRecXDia, 2);
  emxInit_int32_T(&DispME, 2);
  emxInit_int32_T(&EA, 2);
  emxInit_int32_T(&AA, 2);
  emxInit_int32_T(&AnA, 2);
  emxInit_int32_T(&SA, 2);
  for (i = 0; i < 2000; i++) {
    contDia = 2;
    PCPrO_size[0] = 1;
    PCPrO_size[1] = 10;
    for (i44 = 0; i44 < 10; i44++) {
      b_PCPrO_data[i44] = PCPrO->data[i + 2000 * i44];
    }

    PCPrO_data.data = &b_PCPrO_data[0];
    PCPrO_data.size = &PCPrO_size[0];
    PCPrO_data.allocatedSize = 10;
    PCPrO_data.numDimensions = 2;
    PCPrO_data.canFreeData = false;
    b_Dia_data.data = (int *)&Dia_data[0];
    b_Dia_data.size = (int *)&Dia_size[0];
    b_Dia_data.allocatedSize = -1;
    b_Dia_data.numDimensions = 2;
    b_Dia_data.canFreeData = false;
    b_DispMExD_data.data = (int *)&DispMExD_data[0];
    b_DispMExD_data.size = (int *)&DispMExD_size[0];
    b_DispMExD_data.allocatedSize = -1;
    b_DispMExD_data.numDimensions = 2;
    b_DispMExD_data.canFreeData = false;
    b_funcionDia(NumRec, &PCPrO_data, &b_Dia_data, UltPosRecXDia,
                 TimeUsoRec_data[i], TimeUsoRec_data[i + 2000], &contDia,
                 &b_DispMExD_data, tempUltPosRecXDia, DispME);
    PCPrO_size[0] = 1;
    PCPrO_size[1] = 10;
    for (i44 = 0; i44 < 10; i44++) {
      b_PCPrO_data[i44] = PCPrO->data[i + 2000 * i44];
    }

    loop_ub = PME->size[1];
    PME_size[0] = 1;
    PME_size[1] = loop_ub;
    for (i44 = 0; i44 < loop_ub; i44++) {
      PME_data[i44] = PME->data[i + 2000 * i44];
    }

    loop_ub = PMA->size[1];
    PMA_size[0] = 1;
    PMA_size[1] = loop_ub;
    for (i44 = 0; i44 < loop_ub; i44++) {
      PMA_data[i44] = PMA->data[i + 2000 * i44];
    }

    loop_ub = PMAn->size[1];
    PMAn_size[0] = 1;
    PMAn_size[1] = loop_ub;
    for (i44 = 0; i44 < loop_ub; i44++) {
      PMAn_data[i44] = PMAn->data[i + 2000 * i44];
    }

    PS_size[0] = 1;
    PS_size[1] = 10;
    for (i44 = 0; i44 < 10; i44++) {
      PS_data[i44] = PS->data[i + 2000 * i44];
    }

    PCPO_size[0] = 1;
    PCPO_size[1] = 15;
    for (i44 = 0; i44 < 15; i44++) {
      PCPO_data[i44] = PCPO->data[i + 2000 * i44];
    }

    PCR_size[0] = 1;
    PCR_size[1] = 25;
    for (i44 = 0; i44 < 25; i44++) {
      PCR_data[i44] = PCR->data[i + 2000 * i44];
    }

    c_PCPrO_data.data = &b_PCPrO_data[0];
    c_PCPrO_data.size = &PCPrO_size[0];
    c_PCPrO_data.allocatedSize = 10;
    c_PCPrO_data.numDimensions = 2;
    c_PCPrO_data.canFreeData = false;
    b_PME_data.data = &PME_data[0];
    b_PME_data.size = &PME_size[0];
    b_PME_data.allocatedSize = 31;
    b_PME_data.numDimensions = 2;
    b_PME_data.canFreeData = false;
    b_PMA_data.data = &PMA_data[0];
    b_PMA_data.size = &PMA_size[0];
    b_PMA_data.allocatedSize = 11;
    b_PMA_data.numDimensions = 2;
    b_PMA_data.canFreeData = false;
    b_PMAn_data.data = &PMAn_data[0];
    b_PMAn_data.size = &PMAn_size[0];
    b_PMAn_data.allocatedSize = 11;
    b_PMAn_data.numDimensions = 2;
    b_PMAn_data.canFreeData = false;
    b_PS_data.data = &PS_data[0];
    b_PS_data.size = &PS_size[0];
    b_PS_data.allocatedSize = 10;
    b_PS_data.numDimensions = 2;
    b_PS_data.canFreeData = false;
    b_PCPO_data.data = &PCPO_data[0];
    b_PCPO_data.size = &PCPO_size[0];
    b_PCPO_data.allocatedSize = 15;
    b_PCPO_data.numDimensions = 2;
    b_PCPO_data.canFreeData = false;
    b_PCR_data.data = &PCR_data[0];
    b_PCR_data.size = &PCR_size[0];
    b_PCR_data.allocatedSize = 25;
    b_PCR_data.numDimensions = 2;
    b_PCR_data.canFreeData = false;
    c_Dia_data.data = (int *)&Dia_data[0];
    c_Dia_data.size = (int *)&Dia_size[0];
    c_Dia_data.allocatedSize = -1;
    c_Dia_data.numDimensions = 2;
    c_Dia_data.canFreeData = false;
    c_DispMExD_data.data = (int *)&DispMExD_data[0];
    c_DispMExD_data.size = (int *)&DispMExD_size[0];
    c_DispMExD_data.allocatedSize = -1;
    c_DispMExD_data.numDimensions = 2;
    c_DispMExD_data.canFreeData = false;
    b_funcionCPrO(NumRec, &c_PCPrO_data, &b_PME_data, &b_PMA_data, &b_PMAn_data,
                  &b_PS_data, &b_PCPO_data, &b_PCR_data, H, &c_Dia_data,
                  UltPosRecXDia, TimeUsoRec_data[i], TimeUsoRec_data[i + 2000],
                  TimeUsoRec_data[i + 10000], TimeUsoRec_data[i + 12000],
                  &contDia, tempUltPosRecXDia, &c_DispMExD_data, DispME, &CPrOA,
                  &k, &EndCPrOA, &EndCPrOAxD, EA, AA, AnA, SA, &IniSA, &EndSA,
                  &EndRPxD, &CPOA, &IniCPOA, &EndCPOA, &CRA, &IniCRA, &EndCRA);
    DiaOp_data[i] = contDia;
    if (k > EndCPrOA) {
      i44 = 0;
      EndCPrOA = 0;
    } else {
      i44 = k - 1;
    }

    loop_ub = EndCPrOA - i44;
    for (i45 = 0; i45 < loop_ub; i45++) {
      H->data[(i44 + i45) + 17520 * (CPrOA - 1)] = (double)i + 1.0;
    }

    UltPosRecXDia->data[(contDia + 730 * (CPrOA - 1)) - 1] = EndCPrOAxD;
    if (IniSA > EndSA) {
      i44 = 0;
      i45 = 0;
    } else {
      i44 = IniSA - 1;
      i45 = EndSA;
    }

    CPrOA = SA->size[1];
    loop_ub = SA->size[1];
    for (EndCPrOAxD = 0; EndCPrOAxD < loop_ub; EndCPrOAxD++) {
      EndCPrOA = SA->data[EndCPrOAxD];
      if (EndCPrOA > 2147483607) {
        EndCPrOA = MAX_int32_T;
      } else {
        EndCPrOA += 40;
      }

      tmp_data[EndCPrOAxD] = EndCPrOA;
    }

    k = i45 - i44;
    for (i45 = 0; i45 < CPrOA; i45++) {
      for (EndCPrOAxD = 0; EndCPrOAxD < k; EndCPrOAxD++) {
        H->data[(i44 + EndCPrOAxD) + 17520 * (tmp_data[i45] - 1)] = (double)i +
          1.0;
      }
    }

    for (i44 = 0; i44 < CPrOA; i44++) {
      UltPosRecXDia->data[(contDia + 730 * (tmp_data[i44] - 1)) - 1] = EndRPxD;
    }

    i44 = EA->size[1];
    if (0 <= i44 - 1) {
      if (IniSA > EndSA) {
        i46 = 0;
        i47 = 0;
      } else {
        i46 = IniSA - 1;
        i47 = EndSA;
      }
    }

    for (k = 0; k < i44; k++) {
      EndCPrOA = EA->data[k];
      if (EndCPrOA > 2147483637) {
        EndCPrOA = MAX_int32_T;
      } else {
        EndCPrOA += 10;
      }

      loop_ub = i47 - i46;
      for (i45 = 0; i45 < loop_ub; i45++) {
        H->data[(i46 + i45) + 17520 * (EndCPrOA - 1)] = (double)i + 1.0;
      }

      EndCPrOA = EA->data[k];
      if (EndCPrOA > 2147483637) {
        EndCPrOA = MAX_int32_T;
      } else {
        EndCPrOA += 10;
      }

      UltPosRecXDia->data[(contDia + 730 * (EndCPrOA - 1)) - 1] = EndRPxD;
      EspMedOp_data[i + 2000 * k] = PME->data[i + 2000 * (EA->data[k] - 1)];
    }

    i44 = AA->size[1];
    if (0 <= i44 - 1) {
      if (IniSA > EndSA) {
        i48 = 0;
        i49 = 0;
      } else {
        i48 = IniSA - 1;
        i49 = EndSA;
      }
    }

    for (k = 0; k < i44; k++) {
      EndCPrOA = AA->data[k];
      if (EndCPrOA > 2147483597) {
        EndCPrOA = MAX_int32_T;
      } else {
        EndCPrOA += 50;
      }

      loop_ub = i49 - i48;
      for (i45 = 0; i45 < loop_ub; i45++) {
        H->data[(i48 + i45) + 17520 * (EndCPrOA - 1)] = (double)i + 1.0;
      }

      EndCPrOA = AA->data[k];
      if (EndCPrOA > 2147483597) {
        EndCPrOA = MAX_int32_T;
      } else {
        EndCPrOA += 50;
      }

      UltPosRecXDia->data[(contDia + 730 * (EndCPrOA - 1)) - 1] = EndRPxD;
    }

    i44 = AnA->size[1];
    if (0 <= i44 - 1) {
      if (IniSA > EndSA) {
        i50 = 0;
        i51 = 0;
      } else {
        i50 = IniSA - 1;
        i51 = EndSA;
      }
    }

    for (k = 0; k < i44; k++) {
      EndCPrOA = AnA->data[k];
      if (EndCPrOA > 2147483587) {
        EndCPrOA = MAX_int32_T;
      } else {
        EndCPrOA += 60;
      }

      loop_ub = i51 - i50;
      for (i45 = 0; i45 < loop_ub; i45++) {
        H->data[(i50 + i45) + 17520 * (EndCPrOA - 1)] = (double)i + 1.0;
      }

      EndCPrOA = AnA->data[k];
      if (EndCPrOA > 2147483587) {
        EndCPrOA = MAX_int32_T;
      } else {
        EndCPrOA += 60;
      }

      UltPosRecXDia->data[(contDia + 730 * (EndCPrOA - 1)) - 1] = EndRPxD;
    }

    if (IniCPOA == 0) {
      if (IniCRA > EndCRA) {
        i44 = 0;
        EndCRA = 0;
      } else {
        i44 = IniCRA - 1;
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

      loop_ub = EndCRA - i44;
      for (i45 = 0; i45 < loop_ub; i45++) {
        H->data[(i44 + i45) + 17520 * (k - 1)] = (double)i + 1.0;
      }
    } else {
      if (IniCPOA > EndCPOA) {
        i44 = 0;
        EndCPOA = 0;
      } else {
        i44 = IniCPOA - 1;
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

      loop_ub = EndCPOA - i44;
      for (i45 = 0; i45 < loop_ub; i45++) {
        H->data[(i44 + i45) + 17520 * (k - 1)] = (double)i + 1.0;
      }

      if (IniCRA > EndCRA) {
        i44 = 0;
        EndCRA = 0;
      } else {
        i44 = IniCRA - 1;
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

      loop_ub = EndCRA - i44;
      for (i45 = 0; i45 < loop_ub; i45++) {
        H->data[(i44 + i45) + 17520 * (k - 1)] = (double)i + 1.0;
      }
    }
  }

  emxFree_int32_T(&SA);
  emxFree_int32_T(&AnA);
  emxFree_int32_T(&AA);
  emxFree_int32_T(&EA);
  emxFree_int32_T(&DispME);
  emxFree_int32_T(&tempUltPosRecXDia);
  emxFree_real_T(&UltPosRecXDia);
  emxInit_real_T(&EspMedOp, 2);
  i44 = EspMedOp->size[0] * EspMedOp->size[1];
  EspMedOp->size[0] = 2000;
  EspMedOp->size[1] = 2;
  emxEnsureCapacity_real_T(EspMedOp, i44);
  for (i44 = 0; i44 < 4000; i44++) {
    EspMedOp->data[i44] = EspMedOp_data[i44];
  }

  b_DiaOp_data.data = &DiaOp_data[0];
  b_DiaOp_data.size = &DiaOp_size[0];
  b_DiaOp_data.allocatedSize = 2000;
  b_DiaOp_data.numDimensions = 1;
  b_DiaOp_data.canFreeData = false;
  b_EP_data.data = &EP_data[0];
  b_EP_data.size = &EP_size[0];
  b_EP_data.allocatedSize = -1;
  b_EP_data.numDimensions = 1;
  b_EP_data.canFreeData = false;
  b_favalia(H, &b_DiaOp_data, &b_EP_data, EspMedOp, 0.0, 0.0, 0.0, 0.0, &d11,
            &d12, &d13, &d14, &d15, &d16);
  *NOE3 = d16;
  *NOE2 = d15;
  *TmNOFP = d14;
  *NOFP = d13;
  *Tt = d12;
  *fitness = d11;
  emxFree_real_T(&EspMedOp);
  emxFree_real_T(&H);
}

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
  int i59;
  int i60;
  int loop_ub;
  emxArray_real_T *UltPosRecXDia;
  emxArray_real_T *EspMedOp;
  emxArray_int32_T *b_TimeUsoRec;
  emxArray_int32_T *b_PME;
  emxArray_int32_T *DiaOp;
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *EA;
  emxArray_int32_T *AA;
  emxArray_int32_T *AnA;
  emxArray_int32_T *SA;
  emxArray_int32_T *r11;
  emxArray_int32_T *b_PCPrO;
  emxArray_int32_T *c_PME;
  emxArray_int32_T *b_PMA;
  emxArray_int32_T *b_PMAn;
  emxArray_int32_T *b_PS;
  emxArray_int32_T *b_PCPO;
  emxArray_int32_T *b_PCR;
  int i;
  int contDia;
  int DispME;
  double d18;
  double d19;
  double d20;
  double d21;
  double d22;
  double d23;
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
  int i61;
  int i62;
  int i63;
  int i64;
  int i65;
  int i66;

  /* UNTITLED4 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*     NCPrO  |    NME    |     NS    |     NA    |     NAn    |    NCPO     |   NCR */
  /*   Col 1-20 | Col 21-50 | Col 51-62 | Col 63-87 | Col 88-112 | Col 113-132 | Col 133-152 */
  y = NumRec[0];
  for (k = 0; k < 6; k++) {
    y += (double)NumRec[k + 1];
  }

  emxInit_real_T(&H, 2);
  i59 = H->size[0] * H->size[1];
  H->size[0] = Data->size[0];
  i60 = (int)y;
  H->size[1] = i60;
  emxEnsureCapacity_real_T(H, i59);
  loop_ub = Data->size[0] * i60;
  for (i59 = 0; i59 < loop_ub; i59++) {
    H->data[i59] = 0.0;
  }

  emxInit_real_T(&UltPosRecXDia, 2);

  /*  Schedule completo */
  i59 = UltPosRecXDia->size[0] * UltPosRecXDia->size[1];
  UltPosRecXDia->size[0] = Dia->size[0];
  UltPosRecXDia->size[1] = i60;
  emxEnsureCapacity_real_T(UltPosRecXDia, i59);
  loop_ub = Dia->size[0] * i60;
  for (i59 = 0; i59 < loop_ub; i59++) {
    UltPosRecXDia->data[i59] = 0.0;
  }

  emxInit_real_T(&EspMedOp, 2);

  /*  Ultima posicion asignado del recurso por Dia */
  i59 = EspMedOp->size[0] * EspMedOp->size[1];
  EspMedOp->size[0] = NumTOp;
  EspMedOp->size[1] = 2;
  emxEnsureCapacity_real_T(EspMedOp, i59);
  loop_ub = NumTOp << 1;
  for (i59 = 0; i59 < loop_ub; i59++) {
    EspMedOp->data[i59] = 0.0;
  }

  emxInit_int32_T(&b_TimeUsoRec, 2);
  i59 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[0] = list->size[0];
  b_TimeUsoRec->size[1] = 7;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i59);
  for (i59 = 0; i59 < 7; i59++) {
    loop_ub = list->size[0];
    for (i60 = 0; i60 < loop_ub; i60++) {
      b_TimeUsoRec->data[i60 + b_TimeUsoRec->size[0] * i59] = TimeUsoRec->data
        [(list->data[i60] + TimeUsoRec->size[0] * i59) - 1];
    }
  }

  i59 = TimeUsoRec->size[0] * TimeUsoRec->size[1];
  TimeUsoRec->size[0] = b_TimeUsoRec->size[0];
  TimeUsoRec->size[1] = 7;
  emxEnsureCapacity_int32_T(TimeUsoRec, i59);
  loop_ub = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  for (i59 = 0; i59 < loop_ub; i59++) {
    TimeUsoRec->data[i59] = b_TimeUsoRec->data[i59];
  }

  emxFree_int32_T(&b_TimeUsoRec);
  emxInit_int32_T(&b_PME, 2);
  loop_ub = PME->size[1] - 1;
  i59 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i59);
  for (i59 = 0; i59 <= loop_ub; i59++) {
    k = list->size[0];
    for (i60 = 0; i60 < k; i60++) {
      b_PME->data[i60 + b_PME->size[0] * i59] = PME->data[(list->data[i60] +
        PME->size[0] * i59) - 1];
    }
  }

  i59 = PME->size[0] * PME->size[1];
  PME->size[0] = b_PME->size[0];
  PME->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PME, i59);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i59 = 0; i59 < loop_ub; i59++) {
    PME->data[i59] = b_PME->data[i59];
  }

  loop_ub = PMA->size[1] - 1;
  i59 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i59);
  for (i59 = 0; i59 <= loop_ub; i59++) {
    k = list->size[0];
    for (i60 = 0; i60 < k; i60++) {
      b_PME->data[i60 + b_PME->size[0] * i59] = PMA->data[(list->data[i60] +
        PMA->size[0] * i59) - 1];
    }
  }

  i59 = PMA->size[0] * PMA->size[1];
  PMA->size[0] = b_PME->size[0];
  PMA->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PMA, i59);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i59 = 0; i59 < loop_ub; i59++) {
    PMA->data[i59] = b_PME->data[i59];
  }

  loop_ub = PMAn->size[1] - 1;
  i59 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i59);
  for (i59 = 0; i59 <= loop_ub; i59++) {
    k = list->size[0];
    for (i60 = 0; i60 < k; i60++) {
      b_PME->data[i60 + b_PME->size[0] * i59] = PMAn->data[(list->data[i60] +
        PMAn->size[0] * i59) - 1];
    }
  }

  i59 = PMAn->size[0] * PMAn->size[1];
  PMAn->size[0] = b_PME->size[0];
  PMAn->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PMAn, i59);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i59 = 0; i59 < loop_ub; i59++) {
    PMAn->data[i59] = b_PME->data[i59];
  }

  loop_ub = PCPrO->size[1] - 1;
  i59 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i59);
  for (i59 = 0; i59 <= loop_ub; i59++) {
    k = list->size[0];
    for (i60 = 0; i60 < k; i60++) {
      b_PME->data[i60 + b_PME->size[0] * i59] = PCPrO->data[(list->data[i60] +
        PCPrO->size[0] * i59) - 1];
    }
  }

  i59 = PCPrO->size[0] * PCPrO->size[1];
  PCPrO->size[0] = b_PME->size[0];
  PCPrO->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCPrO, i59);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i59 = 0; i59 < loop_ub; i59++) {
    PCPrO->data[i59] = b_PME->data[i59];
  }

  loop_ub = PS->size[1] - 1;
  i59 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i59);
  for (i59 = 0; i59 <= loop_ub; i59++) {
    k = list->size[0];
    for (i60 = 0; i60 < k; i60++) {
      b_PME->data[i60 + b_PME->size[0] * i59] = PS->data[(list->data[i60] +
        PS->size[0] * i59) - 1];
    }
  }

  i59 = PS->size[0] * PS->size[1];
  PS->size[0] = b_PME->size[0];
  PS->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PS, i59);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i59 = 0; i59 < loop_ub; i59++) {
    PS->data[i59] = b_PME->data[i59];
  }

  loop_ub = PCPO->size[1] - 1;
  i59 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i59);
  for (i59 = 0; i59 <= loop_ub; i59++) {
    k = list->size[0];
    for (i60 = 0; i60 < k; i60++) {
      b_PME->data[i60 + b_PME->size[0] * i59] = PCPO->data[(list->data[i60] +
        PCPO->size[0] * i59) - 1];
    }
  }

  i59 = PCPO->size[0] * PCPO->size[1];
  PCPO->size[0] = b_PME->size[0];
  PCPO->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCPO, i59);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i59 = 0; i59 < loop_ub; i59++) {
    PCPO->data[i59] = b_PME->data[i59];
  }

  loop_ub = PCR->size[1] - 1;
  i59 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i59);
  for (i59 = 0; i59 <= loop_ub; i59++) {
    k = list->size[0];
    for (i60 = 0; i60 < k; i60++) {
      b_PME->data[i60 + b_PME->size[0] * i59] = PCR->data[(list->data[i60] +
        PCR->size[0] * i59) - 1];
    }
  }

  i59 = PCR->size[0] * PCR->size[1];
  PCR->size[0] = b_PME->size[0];
  PCR->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCR, i59);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i59 = 0; i59 < loop_ub; i59++) {
    PCR->data[i59] = b_PME->data[i59];
  }

  emxFree_int32_T(&b_PME);
  emxInit_int32_T(&DiaOp, 1);
  i59 = DiaOp->size[0];
  DiaOp->size[0] = list->size[0];
  emxEnsureCapacity_int32_T(DiaOp, i59);
  loop_ub = list->size[0];
  for (i59 = 0; i59 < loop_ub; i59++) {
    DiaOp->data[i59] = EP->data[list->data[i59] - 1];
  }

  i59 = EP->size[0];
  EP->size[0] = DiaOp->size[0];
  emxEnsureCapacity_int32_T(EP, i59);
  loop_ub = DiaOp->size[0];
  for (i59 = 0; i59 < loop_ub; i59++) {
    EP->data[i59] = DiaOp->data[i59];
  }

  i59 = DiaOp->size[0];
  DiaOp->size[0] = NumTOp;
  emxEnsureCapacity_int32_T(DiaOp, i59);
  emxInit_int32_T(&tempUltPosRecXDia, 2);
  emxInit_int32_T(&EA, 2);
  emxInit_int32_T(&AA, 2);
  emxInit_int32_T(&AnA, 2);
  emxInit_int32_T(&SA, 2);
  emxInit_int32_T(&r11, 1);
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
    i59 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPrO, i59);
    for (i59 = 0; i59 < loop_ub; i59++) {
      b_PCPrO->data[i59] = PCPrO->data[i + PCPrO->size[0] * i59];
    }

    d_funcionDia(NumRec, b_PCPrO, Dia, UltPosRecXDia, TimeUsoRec->data[i],
                 TimeUsoRec->data[i + TimeUsoRec->size[0]], &contDia, DispMExD,
                 tempUltPosRecXDia, &DispME);
    loop_ub = PCPrO->size[1];
    i59 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPrO, i59);
    for (i59 = 0; i59 < loop_ub; i59++) {
      b_PCPrO->data[i59] = PCPrO->data[i + PCPrO->size[0] * i59];
    }

    loop_ub = PME->size[1];
    i59 = c_PME->size[0] * c_PME->size[1];
    c_PME->size[0] = 1;
    c_PME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(c_PME, i59);
    for (i59 = 0; i59 < loop_ub; i59++) {
      c_PME->data[i59] = PME->data[i + PME->size[0] * i59];
    }

    loop_ub = PMA->size[1];
    i59 = b_PMA->size[0] * b_PMA->size[1];
    b_PMA->size[0] = 1;
    b_PMA->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PMA, i59);
    for (i59 = 0; i59 < loop_ub; i59++) {
      b_PMA->data[i59] = PMA->data[i + PMA->size[0] * i59];
    }

    loop_ub = PMAn->size[1];
    i59 = b_PMAn->size[0] * b_PMAn->size[1];
    b_PMAn->size[0] = 1;
    b_PMAn->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PMAn, i59);
    for (i59 = 0; i59 < loop_ub; i59++) {
      b_PMAn->data[i59] = PMAn->data[i + PMAn->size[0] * i59];
    }

    loop_ub = PS->size[1];
    i59 = b_PS->size[0] * b_PS->size[1];
    b_PS->size[0] = 1;
    b_PS->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PS, i59);
    for (i59 = 0; i59 < loop_ub; i59++) {
      b_PS->data[i59] = PS->data[i + PS->size[0] * i59];
    }

    loop_ub = PCPO->size[1];
    i59 = b_PCPO->size[0] * b_PCPO->size[1];
    b_PCPO->size[0] = 1;
    b_PCPO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPO, i59);
    for (i59 = 0; i59 < loop_ub; i59++) {
      b_PCPO->data[i59] = PCPO->data[i + PCPO->size[0] * i59];
    }

    loop_ub = PCR->size[1];
    i59 = b_PCR->size[0] * b_PCR->size[1];
    b_PCR->size[0] = 1;
    b_PCR->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCR, i59);
    for (i59 = 0; i59 < loop_ub; i59++) {
      b_PCR->data[i59] = PCR->data[i + PCR->size[0] * i59];
    }

    e_funcionCPrO(NumRec, b_PCPrO, c_PME, b_PMA, b_PMAn, b_PS, b_PCPO, b_PCR, H,
                  Dia, UltPosRecXDia, TimeUsoRec->data[i], TimeUsoRec->data[i +
                  TimeUsoRec->size[0]], TimeUsoRec->data[i + TimeUsoRec->size[0]
                  * 5], TimeUsoRec->data[i + TimeUsoRec->size[0] * 6], &contDia,
                  tempUltPosRecXDia, DispMExD, DispME, &CPrOA, &k, &EndCPrOA,
                  &EndCPrOAxD, EA, AA, AnA, SA, &IniSA, &EndSA, &EndRPxD, &CPOA,
                  &IniCPOA, &EndCPOA, &CRA, &IniCRA, &EndCRA);
    DiaOp->data[i] = contDia;
    if (k > EndCPrOA) {
      i59 = 0;
      EndCPrOA = 0;
    } else {
      i59 = k - 1;
    }

    loop_ub = EndCPrOA - i59;
    for (i60 = 0; i60 < loop_ub; i60++) {
      H->data[(i59 + i60) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
    }

    UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (CPrOA - 1)) - 1] =
      EndCPrOAxD;
    if (IniSA > EndSA) {
      i59 = 0;
      i60 = 0;
    } else {
      i59 = IniSA - 1;
      i60 = EndSA;
    }

    if ((NumRec[0] < 0) && (NumRec[1] < MIN_int32_T - NumRec[0])) {
      DispME = MIN_int32_T;
    } else if ((NumRec[0] > 0) && (NumRec[1] > MAX_int32_T - NumRec[0])) {
      DispME = MAX_int32_T;
    } else {
      DispME = NumRec[0] + NumRec[1];
    }

    CPrOA = r11->size[0];
    r11->size[0] = SA->size[1];
    emxEnsureCapacity_int32_T(r11, CPrOA);
    loop_ub = SA->size[1];
    for (CPrOA = 0; CPrOA < loop_ub; CPrOA++) {
      EndCPrOA = SA->data[CPrOA];
      if ((DispME < 0) && (EndCPrOA < MIN_int32_T - DispME)) {
        k = MIN_int32_T;
      } else if ((DispME > 0) && (EndCPrOA > MAX_int32_T - DispME)) {
        k = MAX_int32_T;
      } else {
        k = DispME + EndCPrOA;
      }

      r11->data[CPrOA] = k;
    }

    k = i60 - i59;
    EndCPrOA = r11->size[0];
    for (i60 = 0; i60 < EndCPrOA; i60++) {
      for (CPrOA = 0; CPrOA < k; CPrOA++) {
        H->data[(i59 + CPrOA) + H->size[0] * (r11->data[i60] - 1)] = (unsigned
          int)(i + 1);
      }
    }

    EndCPrOA = r11->size[0];
    for (i59 = 0; i59 < EndCPrOA; i59++) {
      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (r11->data[i59] -
        1)) - 1] = EndRPxD;
    }

    i59 = EA->size[1];
    if (0 <= i59 - 1) {
      if (IniSA > EndSA) {
        i61 = 0;
        i62 = 0;
      } else {
        i61 = IniSA - 1;
        i62 = EndSA;
      }
    }

    for (k = 0; k < i59; k++) {
      EndCPrOA = EA->data[k];
      if ((NumRec[0] < 0) && (EndCPrOA < MIN_int32_T - NumRec[0])) {
        DispME = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (EndCPrOA > MAX_int32_T - NumRec[0])) {
        DispME = MAX_int32_T;
      } else {
        DispME = NumRec[0] + EndCPrOA;
      }

      loop_ub = i62 - i61;
      for (i60 = 0; i60 < loop_ub; i60++) {
        H->data[(i61 + i60) + H->size[0] * (DispME - 1)] = (unsigned int)(i + 1);
      }

      EndCPrOA = EA->data[k];
      if ((NumRec[0] < 0) && (EndCPrOA < MIN_int32_T - NumRec[0])) {
        DispME = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (EndCPrOA > MAX_int32_T - NumRec[0])) {
        DispME = MAX_int32_T;
      } else {
        DispME = NumRec[0] + EndCPrOA;
      }

      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (DispME - 1)) - 1]
        = EndRPxD;
      EspMedOp->data[i + EspMedOp->size[0] * k] = PME->data[i + PME->size[0] *
        (EA->data[k] - 1)];
    }

    i59 = AA->size[1];
    if (0 <= i59 - 1) {
      if (IniSA > EndSA) {
        i63 = 0;
        i64 = 0;
      } else {
        i63 = IniSA - 1;
        i64 = EndSA;
      }
    }

    for (k = 0; k < i59; k++) {
      if ((NumRec[0] < 0) && (NumRec[1] < MIN_int32_T - NumRec[0])) {
        DispME = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (NumRec[1] > MAX_int32_T - NumRec[0])) {
        DispME = MAX_int32_T;
      } else {
        DispME = NumRec[0] + NumRec[1];
      }

      if ((DispME < 0) && (NumRec[2] < MIN_int32_T - DispME)) {
        DispME = MIN_int32_T;
      } else if ((DispME > 0) && (NumRec[2] > MAX_int32_T - DispME)) {
        DispME = MAX_int32_T;
      } else {
        DispME += NumRec[2];
      }

      EndCPrOA = AA->data[k];
      if ((DispME < 0) && (EndCPrOA < MIN_int32_T - DispME)) {
        DispME = MIN_int32_T;
      } else if ((DispME > 0) && (EndCPrOA > MAX_int32_T - DispME)) {
        DispME = MAX_int32_T;
      } else {
        DispME += EndCPrOA;
      }

      loop_ub = i64 - i63;
      for (i60 = 0; i60 < loop_ub; i60++) {
        H->data[(i63 + i60) + H->size[0] * (DispME - 1)] = (unsigned int)(i + 1);
      }

      if ((NumRec[0] < 0) && (NumRec[1] < MIN_int32_T - NumRec[0])) {
        DispME = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (NumRec[1] > MAX_int32_T - NumRec[0])) {
        DispME = MAX_int32_T;
      } else {
        DispME = NumRec[0] + NumRec[1];
      }

      if ((DispME < 0) && (NumRec[2] < MIN_int32_T - DispME)) {
        DispME = MIN_int32_T;
      } else if ((DispME > 0) && (NumRec[2] > MAX_int32_T - DispME)) {
        DispME = MAX_int32_T;
      } else {
        DispME += NumRec[2];
      }

      EndCPrOA = AA->data[k];
      if ((DispME < 0) && (EndCPrOA < MIN_int32_T - DispME)) {
        DispME = MIN_int32_T;
      } else if ((DispME > 0) && (EndCPrOA > MAX_int32_T - DispME)) {
        DispME = MAX_int32_T;
      } else {
        DispME += EndCPrOA;
      }

      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (DispME - 1)) - 1]
        = EndRPxD;
    }

    i59 = AnA->size[1];
    if (0 <= i59 - 1) {
      if (IniSA > EndSA) {
        i65 = 0;
        i66 = 0;
      } else {
        i65 = IniSA - 1;
        i66 = EndSA;
      }
    }

    for (k = 0; k < i59; k++) {
      if ((NumRec[0] < 0) && (NumRec[1] < MIN_int32_T - NumRec[0])) {
        DispME = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (NumRec[1] > MAX_int32_T - NumRec[0])) {
        DispME = MAX_int32_T;
      } else {
        DispME = NumRec[0] + NumRec[1];
      }

      if ((DispME < 0) && (NumRec[2] < MIN_int32_T - DispME)) {
        DispME = MIN_int32_T;
      } else if ((DispME > 0) && (NumRec[2] > MAX_int32_T - DispME)) {
        DispME = MAX_int32_T;
      } else {
        DispME += NumRec[2];
      }

      if ((DispME < 0) && (NumRec[3] < MIN_int32_T - DispME)) {
        DispME = MIN_int32_T;
      } else if ((DispME > 0) && (NumRec[3] > MAX_int32_T - DispME)) {
        DispME = MAX_int32_T;
      } else {
        DispME += NumRec[3];
      }

      EndCPrOA = AnA->data[k];
      if ((DispME < 0) && (EndCPrOA < MIN_int32_T - DispME)) {
        DispME = MIN_int32_T;
      } else if ((DispME > 0) && (EndCPrOA > MAX_int32_T - DispME)) {
        DispME = MAX_int32_T;
      } else {
        DispME += EndCPrOA;
      }

      loop_ub = i66 - i65;
      for (i60 = 0; i60 < loop_ub; i60++) {
        H->data[(i65 + i60) + H->size[0] * (DispME - 1)] = (unsigned int)(i + 1);
      }

      if ((NumRec[0] < 0) && (NumRec[1] < MIN_int32_T - NumRec[0])) {
        DispME = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (NumRec[1] > MAX_int32_T - NumRec[0])) {
        DispME = MAX_int32_T;
      } else {
        DispME = NumRec[0] + NumRec[1];
      }

      if ((DispME < 0) && (NumRec[2] < MIN_int32_T - DispME)) {
        DispME = MIN_int32_T;
      } else if ((DispME > 0) && (NumRec[2] > MAX_int32_T - DispME)) {
        DispME = MAX_int32_T;
      } else {
        DispME += NumRec[2];
      }

      if ((DispME < 0) && (NumRec[3] < MIN_int32_T - DispME)) {
        DispME = MIN_int32_T;
      } else if ((DispME > 0) && (NumRec[3] > MAX_int32_T - DispME)) {
        DispME = MAX_int32_T;
      } else {
        DispME += NumRec[3];
      }

      EndCPrOA = AnA->data[k];
      if ((DispME < 0) && (EndCPrOA < MIN_int32_T - DispME)) {
        DispME = MIN_int32_T;
      } else if ((DispME > 0) && (EndCPrOA > MAX_int32_T - DispME)) {
        DispME = MAX_int32_T;
      } else {
        DispME += EndCPrOA;
      }

      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (DispME - 1)) - 1]
        = EndRPxD;
    }

    if (IniCPOA == 0) {
      if (IniCRA > EndCRA) {
        i59 = 0;
        EndCRA = 0;
      } else {
        i59 = IniCRA - 1;
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

      loop_ub = EndCRA - i59;
      for (i60 = 0; i60 < loop_ub; i60++) {
        H->data[(i59 + i60) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
      }
    } else {
      if (IniCPOA > EndCPOA) {
        i59 = 0;
        EndCPOA = 0;
      } else {
        i59 = IniCPOA - 1;
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

      loop_ub = EndCPOA - i59;
      for (i60 = 0; i60 < loop_ub; i60++) {
        H->data[(i59 + i60) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
      }

      if (IniCRA > EndCRA) {
        i59 = 0;
        EndCRA = 0;
      } else {
        i59 = IniCRA - 1;
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

      loop_ub = EndCRA - i59;
      for (i60 = 0; i60 < loop_ub; i60++) {
        H->data[(i59 + i60) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
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
  emxFree_int32_T(&r11);
  emxFree_int32_T(&SA);
  emxFree_int32_T(&AnA);
  emxFree_int32_T(&AA);
  emxFree_int32_T(&EA);
  emxFree_int32_T(&tempUltPosRecXDia);
  emxFree_real_T(&UltPosRecXDia);
  b_favalia(H, DiaOp, EP, EspMedOp, k0, k1, k2, k3, &d18, &d19, &d20, &d21, &d22,
            &d23);
  *NOE3 = d23;
  *NOE2 = d22;
  *TmNOFP = d21;
  *NOFP = d20;
  *Tt = d19;
  *fitness = d18;
  emxFree_real_T(&EspMedOp);
  emxFree_int32_T(&DiaOp);
  emxFree_real_T(&H);
}

/* End of code generation (sch.c) */
