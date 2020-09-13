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
  int i15;
  int i16;
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
  int i17;
  int i18;
  int i19;
  int i20;
  int i21;
  int i22;

  /* UNTITLED4 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*     NCPrO  |    NME    |     NS    |     NA    |     NAn    |    NCPO     |   NCR */
  /*   Col 1-20 | Col 21-50 | Col 51-62 | Col 63-87 | Col 88-112 | Col 113-132 | Col 133-152 */
  y = NumRec[0];
  for (k = 0; k < 6; k++) {
    y += (double)NumRec[k + 1];
  }

  emxInit_real_T(&H, 2);
  i15 = H->size[0] * H->size[1];
  H->size[0] = Data->size[0];
  i16 = (int)y;
  H->size[1] = i16;
  emxEnsureCapacity_real_T(H, i15);
  loop_ub = Data->size[0] * i16;
  for (i15 = 0; i15 < loop_ub; i15++) {
    H->data[i15] = 0.0;
  }

  emxInit_real_T(&UltPosRecXDia, 2);

  /*  Schedule completo */
  i15 = UltPosRecXDia->size[0] * UltPosRecXDia->size[1];
  UltPosRecXDia->size[0] = Dia->size[0];
  UltPosRecXDia->size[1] = i16;
  emxEnsureCapacity_real_T(UltPosRecXDia, i15);
  loop_ub = Dia->size[0] * i16;
  for (i15 = 0; i15 < loop_ub; i15++) {
    UltPosRecXDia->data[i15] = 0.0;
  }

  emxInit_real_T(&EspMedOp, 2);

  /*  Ultima posicion asignado del recurso por Dia */
  i15 = EspMedOp->size[0] * EspMedOp->size[1];
  EspMedOp->size[0] = NumTOp;
  EspMedOp->size[1] = 2;
  emxEnsureCapacity_real_T(EspMedOp, i15);
  loop_ub = NumTOp << 1;
  for (i15 = 0; i15 < loop_ub; i15++) {
    EspMedOp->data[i15] = 0.0;
  }

  emxInit_int32_T(&b_TimeUsoRec, 2);
  i15 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[0] = list->size[0];
  b_TimeUsoRec->size[1] = 7;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i15);
  for (i15 = 0; i15 < 7; i15++) {
    loop_ub = list->size[0];
    for (i16 = 0; i16 < loop_ub; i16++) {
      b_TimeUsoRec->data[i16 + b_TimeUsoRec->size[0] * i15] = TimeUsoRec->data
        [(list->data[i16] + TimeUsoRec->size[0] * i15) - 1];
    }
  }

  i15 = TimeUsoRec->size[0] * TimeUsoRec->size[1];
  TimeUsoRec->size[0] = b_TimeUsoRec->size[0];
  TimeUsoRec->size[1] = 7;
  emxEnsureCapacity_int32_T(TimeUsoRec, i15);
  loop_ub = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  for (i15 = 0; i15 < loop_ub; i15++) {
    TimeUsoRec->data[i15] = b_TimeUsoRec->data[i15];
  }

  emxFree_int32_T(&b_TimeUsoRec);
  emxInit_int32_T(&b_PME, 2);
  loop_ub = PME->size[1] - 1;
  i15 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i15);
  for (i15 = 0; i15 <= loop_ub; i15++) {
    k = list->size[0];
    for (i16 = 0; i16 < k; i16++) {
      b_PME->data[i16 + b_PME->size[0] * i15] = PME->data[(list->data[i16] +
        PME->size[0] * i15) - 1];
    }
  }

  i15 = PME->size[0] * PME->size[1];
  PME->size[0] = b_PME->size[0];
  PME->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PME, i15);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i15 = 0; i15 < loop_ub; i15++) {
    PME->data[i15] = b_PME->data[i15];
  }

  loop_ub = PMA->size[1] - 1;
  i15 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i15);
  for (i15 = 0; i15 <= loop_ub; i15++) {
    k = list->size[0];
    for (i16 = 0; i16 < k; i16++) {
      b_PME->data[i16 + b_PME->size[0] * i15] = PMA->data[(list->data[i16] +
        PMA->size[0] * i15) - 1];
    }
  }

  i15 = PMA->size[0] * PMA->size[1];
  PMA->size[0] = b_PME->size[0];
  PMA->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PMA, i15);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i15 = 0; i15 < loop_ub; i15++) {
    PMA->data[i15] = b_PME->data[i15];
  }

  loop_ub = PMAn->size[1] - 1;
  i15 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i15);
  for (i15 = 0; i15 <= loop_ub; i15++) {
    k = list->size[0];
    for (i16 = 0; i16 < k; i16++) {
      b_PME->data[i16 + b_PME->size[0] * i15] = PMAn->data[(list->data[i16] +
        PMAn->size[0] * i15) - 1];
    }
  }

  i15 = PMAn->size[0] * PMAn->size[1];
  PMAn->size[0] = b_PME->size[0];
  PMAn->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PMAn, i15);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i15 = 0; i15 < loop_ub; i15++) {
    PMAn->data[i15] = b_PME->data[i15];
  }

  loop_ub = PCPrO->size[1] - 1;
  i15 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i15);
  for (i15 = 0; i15 <= loop_ub; i15++) {
    k = list->size[0];
    for (i16 = 0; i16 < k; i16++) {
      b_PME->data[i16 + b_PME->size[0] * i15] = PCPrO->data[(list->data[i16] +
        PCPrO->size[0] * i15) - 1];
    }
  }

  i15 = PCPrO->size[0] * PCPrO->size[1];
  PCPrO->size[0] = b_PME->size[0];
  PCPrO->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCPrO, i15);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i15 = 0; i15 < loop_ub; i15++) {
    PCPrO->data[i15] = b_PME->data[i15];
  }

  loop_ub = PS->size[1] - 1;
  i15 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i15);
  for (i15 = 0; i15 <= loop_ub; i15++) {
    k = list->size[0];
    for (i16 = 0; i16 < k; i16++) {
      b_PME->data[i16 + b_PME->size[0] * i15] = PS->data[(list->data[i16] +
        PS->size[0] * i15) - 1];
    }
  }

  i15 = PS->size[0] * PS->size[1];
  PS->size[0] = b_PME->size[0];
  PS->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PS, i15);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i15 = 0; i15 < loop_ub; i15++) {
    PS->data[i15] = b_PME->data[i15];
  }

  loop_ub = PCPO->size[1] - 1;
  i15 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i15);
  for (i15 = 0; i15 <= loop_ub; i15++) {
    k = list->size[0];
    for (i16 = 0; i16 < k; i16++) {
      b_PME->data[i16 + b_PME->size[0] * i15] = PCPO->data[(list->data[i16] +
        PCPO->size[0] * i15) - 1];
    }
  }

  i15 = PCPO->size[0] * PCPO->size[1];
  PCPO->size[0] = b_PME->size[0];
  PCPO->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCPO, i15);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i15 = 0; i15 < loop_ub; i15++) {
    PCPO->data[i15] = b_PME->data[i15];
  }

  loop_ub = PCR->size[1] - 1;
  i15 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i15);
  for (i15 = 0; i15 <= loop_ub; i15++) {
    k = list->size[0];
    for (i16 = 0; i16 < k; i16++) {
      b_PME->data[i16 + b_PME->size[0] * i15] = PCR->data[(list->data[i16] +
        PCR->size[0] * i15) - 1];
    }
  }

  i15 = PCR->size[0] * PCR->size[1];
  PCR->size[0] = b_PME->size[0];
  PCR->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCR, i15);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i15 = 0; i15 < loop_ub; i15++) {
    PCR->data[i15] = b_PME->data[i15];
  }

  emxFree_int32_T(&b_PME);
  emxInit_real_T(&b_EP, 1);
  i15 = b_EP->size[0];
  b_EP->size[0] = list->size[0];
  emxEnsureCapacity_real_T(b_EP, i15);
  loop_ub = list->size[0];
  for (i15 = 0; i15 < loop_ub; i15++) {
    b_EP->data[i15] = EP->data[list->data[i15] - 1];
  }

  i15 = EP->size[0];
  EP->size[0] = b_EP->size[0];
  emxEnsureCapacity_real_T(EP, i15);
  loop_ub = b_EP->size[0];
  for (i15 = 0; i15 < loop_ub; i15++) {
    EP->data[i15] = b_EP->data[i15];
  }

  emxFree_real_T(&b_EP);
  emxInit_int32_T(&DiaOp, 1);
  i15 = DiaOp->size[0];
  DiaOp->size[0] = NumTOp;
  emxEnsureCapacity_int32_T(DiaOp, i15);
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
    i15 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPrO, i15);
    for (i15 = 0; i15 < loop_ub; i15++) {
      b_PCPrO->data[i15] = PCPrO->data[i + PCPrO->size[0] * i15];
    }

    b_funcionDia(NumRec, b_PCPrO, Dia, UltPosRecXDia, TimeUsoRec->data[i],
                 TimeUsoRec->data[i + TimeUsoRec->size[0]], &contDia, DispMExD,
                 tempUltPosRecXDia, DispME);
    loop_ub = PCPrO->size[1];
    i15 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPrO, i15);
    for (i15 = 0; i15 < loop_ub; i15++) {
      b_PCPrO->data[i15] = PCPrO->data[i + PCPrO->size[0] * i15];
    }

    loop_ub = PME->size[1];
    i15 = c_PME->size[0] * c_PME->size[1];
    c_PME->size[0] = 1;
    c_PME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(c_PME, i15);
    for (i15 = 0; i15 < loop_ub; i15++) {
      c_PME->data[i15] = PME->data[i + PME->size[0] * i15];
    }

    loop_ub = PMA->size[1];
    i15 = b_PMA->size[0] * b_PMA->size[1];
    b_PMA->size[0] = 1;
    b_PMA->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PMA, i15);
    for (i15 = 0; i15 < loop_ub; i15++) {
      b_PMA->data[i15] = PMA->data[i + PMA->size[0] * i15];
    }

    loop_ub = PMAn->size[1];
    i15 = b_PMAn->size[0] * b_PMAn->size[1];
    b_PMAn->size[0] = 1;
    b_PMAn->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PMAn, i15);
    for (i15 = 0; i15 < loop_ub; i15++) {
      b_PMAn->data[i15] = PMAn->data[i + PMAn->size[0] * i15];
    }

    loop_ub = PS->size[1];
    i15 = b_PS->size[0] * b_PS->size[1];
    b_PS->size[0] = 1;
    b_PS->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PS, i15);
    for (i15 = 0; i15 < loop_ub; i15++) {
      b_PS->data[i15] = PS->data[i + PS->size[0] * i15];
    }

    loop_ub = PCPO->size[1];
    i15 = b_PCPO->size[0] * b_PCPO->size[1];
    b_PCPO->size[0] = 1;
    b_PCPO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPO, i15);
    for (i15 = 0; i15 < loop_ub; i15++) {
      b_PCPO->data[i15] = PCPO->data[i + PCPO->size[0] * i15];
    }

    loop_ub = PCR->size[1];
    i15 = b_PCR->size[0] * b_PCR->size[1];
    b_PCR->size[0] = 1;
    b_PCR->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCR, i15);
    for (i15 = 0; i15 < loop_ub; i15++) {
      b_PCR->data[i15] = PCR->data[i + PCR->size[0] * i15];
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
      i15 = 0;
      EndCPrOA = 0;
    } else {
      i15 = k - 1;
    }

    loop_ub = EndCPrOA - i15;
    for (i16 = 0; i16 < loop_ub; i16++) {
      H->data[(i15 + i16) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
    }

    UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (CPrOA - 1)) - 1] =
      EndCPrOAxD;
    if (IniSA > EndSA) {
      i15 = 0;
      i16 = 0;
    } else {
      i15 = IniSA - 1;
      i16 = EndSA;
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

    k = i16 - i15;
    EndCPrOA = c_EP->size[0];
    for (i16 = 0; i16 < EndCPrOA; i16++) {
      for (EndCPrOAxD = 0; EndCPrOAxD < k; EndCPrOAxD++) {
        H->data[(i15 + EndCPrOAxD) + H->size[0] * (c_EP->data[i16] - 1)] =
          (unsigned int)(i + 1);
      }
    }

    EndCPrOA = c_EP->size[0];
    for (i15 = 0; i15 < EndCPrOA; i15++) {
      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (c_EP->data[i15] -
        1)) - 1] = EndRPxD;
    }

    i15 = EA->size[1];
    if (0 <= i15 - 1) {
      if (IniSA > EndSA) {
        i17 = 0;
        i18 = 0;
      } else {
        i17 = IniSA - 1;
        i18 = EndSA;
      }
    }

    for (k = 0; k < i15; k++) {
      EndCPrOA = EA->data[k];
      if ((NumRec[0] < 0) && (EndCPrOA < MIN_int32_T - NumRec[0])) {
        CPrOA = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (EndCPrOA > MAX_int32_T - NumRec[0])) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA = NumRec[0] + EndCPrOA;
      }

      loop_ub = i18 - i17;
      for (i16 = 0; i16 < loop_ub; i16++) {
        H->data[(i17 + i16) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
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

    i15 = AA->size[1];
    if (0 <= i15 - 1) {
      if (IniSA > EndSA) {
        i19 = 0;
        i20 = 0;
      } else {
        i19 = IniSA - 1;
        i20 = EndSA;
      }
    }

    for (k = 0; k < i15; k++) {
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

      loop_ub = i20 - i19;
      for (i16 = 0; i16 < loop_ub; i16++) {
        H->data[(i19 + i16) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
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

    i15 = AnA->size[1];
    if (0 <= i15 - 1) {
      if (IniSA > EndSA) {
        i21 = 0;
        i22 = 0;
      } else {
        i21 = IniSA - 1;
        i22 = EndSA;
      }
    }

    for (k = 0; k < i15; k++) {
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

      loop_ub = i22 - i21;
      for (i16 = 0; i16 < loop_ub; i16++) {
        H->data[(i21 + i16) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
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
        i15 = 0;
        EndCRA = 0;
      } else {
        i15 = IniCRA - 1;
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

      loop_ub = EndCRA - i15;
      for (i16 = 0; i16 < loop_ub; i16++) {
        H->data[(i15 + i16) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
      }
    } else {
      if (IniCPOA > EndCPOA) {
        i15 = 0;
        EndCPOA = 0;
      } else {
        i15 = IniCPOA - 1;
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

      loop_ub = EndCPOA - i15;
      for (i16 = 0; i16 < loop_ub; i16++) {
        H->data[(i15 + i16) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
      }

      if (IniCRA > EndCRA) {
        i15 = 0;
        EndCRA = 0;
      } else {
        i15 = IniCRA - 1;
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

      loop_ub = EndCRA - i15;
      for (i16 = 0; i16 < loop_ub; i16++) {
        H->data[(i15 + i16) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
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
  i15 = c_EP->size[0];
  c_EP->size[0] = EP->size[0];
  emxEnsureCapacity_int32_T(c_EP, i15);
  loop_ub = EP->size[0];
  for (i15 = 0; i15 < loop_ub; i15++) {
    y = rt_roundd(EP->data[i15]);
    if (y < 2.147483648E+9) {
      if (y >= -2.147483648E+9) {
        i16 = (int)y;
      } else {
        i16 = MIN_int32_T;
      }
    } else {
      i16 = MAX_int32_T;
    }

    c_EP->data[i15] = i16;
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

void c_sch(int NumTOp, const emxArray_int32_T *list, const int NumRec[7],
           emxArray_int32_T *PCPrO, emxArray_int32_T *PME, emxArray_int32_T *PMA,
           emxArray_int32_T *PMAn, emxArray_int32_T *PS, emxArray_int32_T *PCPO,
           emxArray_int32_T *PCR, const emxArray_int32_T *Dia, const
           emxArray_int32_T *Data, emxArray_int32_T *TimeUsoRec, const
           emxArray_int32_T *DispMExD, emxArray_int32_T *EP, double k0, double
           k1, double k2, double k3, double *fitness, double *Tt, double *NOFP,
           double *TmNOFP, double *NOE2, double *NOE3)
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
  emxArray_int32_T *DispME;
  emxArray_int32_T *EA;
  emxArray_int32_T *AA;
  emxArray_int32_T *AnA;
  emxArray_int32_T *SA;
  emxArray_int32_T *r9;
  emxArray_int32_T *b_PCPrO;
  emxArray_int32_T *c_PME;
  emxArray_int32_T *b_PMA;
  emxArray_int32_T *b_PMAn;
  emxArray_int32_T *b_PS;
  emxArray_int32_T *b_PCPO;
  emxArray_int32_T *b_PCR;
  int i;
  int contDia;
  double d16;
  double d17;
  double d18;
  double d19;
  double d20;
  double d21;
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
  emxInit_int32_T(&DispME, 2);
  emxInit_int32_T(&EA, 2);
  emxInit_int32_T(&AA, 2);
  emxInit_int32_T(&AnA, 2);
  emxInit_int32_T(&SA, 2);
  emxInit_int32_T(&r9, 1);
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

    b_funcionDia(NumRec, b_PCPrO, Dia, UltPosRecXDia, TimeUsoRec->data[i],
                 TimeUsoRec->data[i + TimeUsoRec->size[0]], &contDia, DispMExD,
                 tempUltPosRecXDia, DispME);
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

    b_funcionCPrO(NumRec, b_PCPrO, c_PME, b_PMA, b_PMAn, b_PS, b_PCPO, b_PCR, H,
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
      CPrOA = MIN_int32_T;
    } else if ((NumRec[0] > 0) && (NumRec[1] > MAX_int32_T - NumRec[0])) {
      CPrOA = MAX_int32_T;
    } else {
      CPrOA = NumRec[0] + NumRec[1];
    }

    EndCPrOAxD = r9->size[0];
    r9->size[0] = SA->size[1];
    emxEnsureCapacity_int32_T(r9, EndCPrOAxD);
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

      r9->data[EndCPrOAxD] = k;
    }

    k = i60 - i59;
    EndCPrOA = r9->size[0];
    for (i60 = 0; i60 < EndCPrOA; i60++) {
      for (EndCPrOAxD = 0; EndCPrOAxD < k; EndCPrOAxD++) {
        H->data[(i59 + EndCPrOAxD) + H->size[0] * (r9->data[i60] - 1)] =
          (unsigned int)(i + 1);
      }
    }

    EndCPrOA = r9->size[0];
    for (i59 = 0; i59 < EndCPrOA; i59++) {
      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (r9->data[i59] - 1))
        - 1] = EndRPxD;
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
        CPrOA = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (EndCPrOA > MAX_int32_T - NumRec[0])) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA = NumRec[0] + EndCPrOA;
      }

      loop_ub = i62 - i61;
      for (i60 = 0; i60 < loop_ub; i60++) {
        H->data[(i61 + i60) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
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

      loop_ub = i64 - i63;
      for (i60 = 0; i60 < loop_ub; i60++) {
        H->data[(i63 + i60) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
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

      loop_ub = i66 - i65;
      for (i60 = 0; i60 < loop_ub; i60++) {
        H->data[(i65 + i60) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
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
  emxFree_int32_T(&r9);
  emxFree_int32_T(&SA);
  emxFree_int32_T(&AnA);
  emxFree_int32_T(&AA);
  emxFree_int32_T(&EA);
  emxFree_int32_T(&DispME);
  emxFree_int32_T(&tempUltPosRecXDia);
  emxFree_real_T(&UltPosRecXDia);
  b_favalia(H, DiaOp, EP, EspMedOp, k0, k1, k2, k3, &d16, &d17, &d18, &d19, &d20,
            &d21);
  *NOE3 = d21;
  *NOE2 = d20;
  *TmNOFP = d19;
  *NOFP = d18;
  *Tt = d17;
  *fitness = d16;
  emxFree_real_T(&EspMedOp);
  emxFree_int32_T(&DiaOp);
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
  int i67;
  int i68;
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
  emxArray_int32_T *r10;
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
  double d22;
  double d23;
  double d24;
  double d25;
  double d26;
  double d27;
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
  int i69;
  int i70;
  int i71;
  int i72;
  int i73;
  int i74;

  /* UNTITLED4 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*     NCPrO  |    NME    |     NS    |     NA    |     NAn    |    NCPO     |   NCR */
  /*   Col 1-20 | Col 21-50 | Col 51-62 | Col 63-87 | Col 88-112 | Col 113-132 | Col 133-152 */
  y = NumRec[0];
  for (k = 0; k < 6; k++) {
    y += (double)NumRec[k + 1];
  }

  emxInit_real_T(&H, 2);
  i67 = H->size[0] * H->size[1];
  H->size[0] = Data->size[0];
  i68 = (int)y;
  H->size[1] = i68;
  emxEnsureCapacity_real_T(H, i67);
  loop_ub = Data->size[0] * i68;
  for (i67 = 0; i67 < loop_ub; i67++) {
    H->data[i67] = 0.0;
  }

  emxInit_real_T(&UltPosRecXDia, 2);

  /*  Schedule completo */
  i67 = UltPosRecXDia->size[0] * UltPosRecXDia->size[1];
  UltPosRecXDia->size[0] = Dia->size[0];
  UltPosRecXDia->size[1] = i68;
  emxEnsureCapacity_real_T(UltPosRecXDia, i67);
  loop_ub = Dia->size[0] * i68;
  for (i67 = 0; i67 < loop_ub; i67++) {
    UltPosRecXDia->data[i67] = 0.0;
  }

  emxInit_real_T(&EspMedOp, 2);

  /*  Ultima posicion asignado del recurso por Dia */
  i67 = EspMedOp->size[0] * EspMedOp->size[1];
  EspMedOp->size[0] = NumTOp;
  EspMedOp->size[1] = 2;
  emxEnsureCapacity_real_T(EspMedOp, i67);
  loop_ub = NumTOp << 1;
  for (i67 = 0; i67 < loop_ub; i67++) {
    EspMedOp->data[i67] = 0.0;
  }

  emxInit_int32_T(&b_TimeUsoRec, 2);
  i67 = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  b_TimeUsoRec->size[0] = list->size[0];
  b_TimeUsoRec->size[1] = 7;
  emxEnsureCapacity_int32_T(b_TimeUsoRec, i67);
  for (i67 = 0; i67 < 7; i67++) {
    loop_ub = list->size[0];
    for (i68 = 0; i68 < loop_ub; i68++) {
      b_TimeUsoRec->data[i68 + b_TimeUsoRec->size[0] * i67] = TimeUsoRec->data
        [(list->data[i68] + TimeUsoRec->size[0] * i67) - 1];
    }
  }

  i67 = TimeUsoRec->size[0] * TimeUsoRec->size[1];
  TimeUsoRec->size[0] = b_TimeUsoRec->size[0];
  TimeUsoRec->size[1] = 7;
  emxEnsureCapacity_int32_T(TimeUsoRec, i67);
  loop_ub = b_TimeUsoRec->size[0] * b_TimeUsoRec->size[1];
  for (i67 = 0; i67 < loop_ub; i67++) {
    TimeUsoRec->data[i67] = b_TimeUsoRec->data[i67];
  }

  emxFree_int32_T(&b_TimeUsoRec);
  emxInit_int32_T(&b_PME, 2);
  loop_ub = PME->size[1] - 1;
  i67 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i67);
  for (i67 = 0; i67 <= loop_ub; i67++) {
    k = list->size[0];
    for (i68 = 0; i68 < k; i68++) {
      b_PME->data[i68 + b_PME->size[0] * i67] = PME->data[(list->data[i68] +
        PME->size[0] * i67) - 1];
    }
  }

  i67 = PME->size[0] * PME->size[1];
  PME->size[0] = b_PME->size[0];
  PME->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PME, i67);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i67 = 0; i67 < loop_ub; i67++) {
    PME->data[i67] = b_PME->data[i67];
  }

  loop_ub = PMA->size[1] - 1;
  i67 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i67);
  for (i67 = 0; i67 <= loop_ub; i67++) {
    k = list->size[0];
    for (i68 = 0; i68 < k; i68++) {
      b_PME->data[i68 + b_PME->size[0] * i67] = PMA->data[(list->data[i68] +
        PMA->size[0] * i67) - 1];
    }
  }

  i67 = PMA->size[0] * PMA->size[1];
  PMA->size[0] = b_PME->size[0];
  PMA->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PMA, i67);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i67 = 0; i67 < loop_ub; i67++) {
    PMA->data[i67] = b_PME->data[i67];
  }

  loop_ub = PMAn->size[1] - 1;
  i67 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i67);
  for (i67 = 0; i67 <= loop_ub; i67++) {
    k = list->size[0];
    for (i68 = 0; i68 < k; i68++) {
      b_PME->data[i68 + b_PME->size[0] * i67] = PMAn->data[(list->data[i68] +
        PMAn->size[0] * i67) - 1];
    }
  }

  i67 = PMAn->size[0] * PMAn->size[1];
  PMAn->size[0] = b_PME->size[0];
  PMAn->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PMAn, i67);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i67 = 0; i67 < loop_ub; i67++) {
    PMAn->data[i67] = b_PME->data[i67];
  }

  loop_ub = PCPrO->size[1] - 1;
  i67 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i67);
  for (i67 = 0; i67 <= loop_ub; i67++) {
    k = list->size[0];
    for (i68 = 0; i68 < k; i68++) {
      b_PME->data[i68 + b_PME->size[0] * i67] = PCPrO->data[(list->data[i68] +
        PCPrO->size[0] * i67) - 1];
    }
  }

  i67 = PCPrO->size[0] * PCPrO->size[1];
  PCPrO->size[0] = b_PME->size[0];
  PCPrO->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCPrO, i67);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i67 = 0; i67 < loop_ub; i67++) {
    PCPrO->data[i67] = b_PME->data[i67];
  }

  loop_ub = PS->size[1] - 1;
  i67 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i67);
  for (i67 = 0; i67 <= loop_ub; i67++) {
    k = list->size[0];
    for (i68 = 0; i68 < k; i68++) {
      b_PME->data[i68 + b_PME->size[0] * i67] = PS->data[(list->data[i68] +
        PS->size[0] * i67) - 1];
    }
  }

  i67 = PS->size[0] * PS->size[1];
  PS->size[0] = b_PME->size[0];
  PS->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PS, i67);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i67 = 0; i67 < loop_ub; i67++) {
    PS->data[i67] = b_PME->data[i67];
  }

  loop_ub = PCPO->size[1] - 1;
  i67 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i67);
  for (i67 = 0; i67 <= loop_ub; i67++) {
    k = list->size[0];
    for (i68 = 0; i68 < k; i68++) {
      b_PME->data[i68 + b_PME->size[0] * i67] = PCPO->data[(list->data[i68] +
        PCPO->size[0] * i67) - 1];
    }
  }

  i67 = PCPO->size[0] * PCPO->size[1];
  PCPO->size[0] = b_PME->size[0];
  PCPO->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCPO, i67);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i67 = 0; i67 < loop_ub; i67++) {
    PCPO->data[i67] = b_PME->data[i67];
  }

  loop_ub = PCR->size[1] - 1;
  i67 = b_PME->size[0] * b_PME->size[1];
  b_PME->size[0] = list->size[0];
  b_PME->size[1] = loop_ub + 1;
  emxEnsureCapacity_int32_T(b_PME, i67);
  for (i67 = 0; i67 <= loop_ub; i67++) {
    k = list->size[0];
    for (i68 = 0; i68 < k; i68++) {
      b_PME->data[i68 + b_PME->size[0] * i67] = PCR->data[(list->data[i68] +
        PCR->size[0] * i67) - 1];
    }
  }

  i67 = PCR->size[0] * PCR->size[1];
  PCR->size[0] = b_PME->size[0];
  PCR->size[1] = b_PME->size[1];
  emxEnsureCapacity_int32_T(PCR, i67);
  loop_ub = b_PME->size[0] * b_PME->size[1];
  for (i67 = 0; i67 < loop_ub; i67++) {
    PCR->data[i67] = b_PME->data[i67];
  }

  emxFree_int32_T(&b_PME);
  emxInit_int32_T(&DiaOp, 1);
  i67 = DiaOp->size[0];
  DiaOp->size[0] = list->size[0];
  emxEnsureCapacity_int32_T(DiaOp, i67);
  loop_ub = list->size[0];
  for (i67 = 0; i67 < loop_ub; i67++) {
    DiaOp->data[i67] = EP->data[list->data[i67] - 1];
  }

  i67 = EP->size[0];
  EP->size[0] = DiaOp->size[0];
  emxEnsureCapacity_int32_T(EP, i67);
  loop_ub = DiaOp->size[0];
  for (i67 = 0; i67 < loop_ub; i67++) {
    EP->data[i67] = DiaOp->data[i67];
  }

  i67 = DiaOp->size[0];
  DiaOp->size[0] = NumTOp;
  emxEnsureCapacity_int32_T(DiaOp, i67);
  emxInit_int32_T(&tempUltPosRecXDia, 2);
  emxInit_int32_T(&EA, 2);
  emxInit_int32_T(&AA, 2);
  emxInit_int32_T(&AnA, 2);
  emxInit_int32_T(&SA, 2);
  emxInit_int32_T(&r10, 1);
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
    i67 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPrO, i67);
    for (i67 = 0; i67 < loop_ub; i67++) {
      b_PCPrO->data[i67] = PCPrO->data[i + PCPrO->size[0] * i67];
    }

    d_funcionDia(NumRec, b_PCPrO, Dia, UltPosRecXDia, TimeUsoRec->data[i],
                 TimeUsoRec->data[i + TimeUsoRec->size[0]], &contDia, DispMExD,
                 tempUltPosRecXDia, &DispME);
    loop_ub = PCPrO->size[1];
    i67 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPrO, i67);
    for (i67 = 0; i67 < loop_ub; i67++) {
      b_PCPrO->data[i67] = PCPrO->data[i + PCPrO->size[0] * i67];
    }

    loop_ub = PME->size[1];
    i67 = c_PME->size[0] * c_PME->size[1];
    c_PME->size[0] = 1;
    c_PME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(c_PME, i67);
    for (i67 = 0; i67 < loop_ub; i67++) {
      c_PME->data[i67] = PME->data[i + PME->size[0] * i67];
    }

    loop_ub = PMA->size[1];
    i67 = b_PMA->size[0] * b_PMA->size[1];
    b_PMA->size[0] = 1;
    b_PMA->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PMA, i67);
    for (i67 = 0; i67 < loop_ub; i67++) {
      b_PMA->data[i67] = PMA->data[i + PMA->size[0] * i67];
    }

    loop_ub = PMAn->size[1];
    i67 = b_PMAn->size[0] * b_PMAn->size[1];
    b_PMAn->size[0] = 1;
    b_PMAn->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PMAn, i67);
    for (i67 = 0; i67 < loop_ub; i67++) {
      b_PMAn->data[i67] = PMAn->data[i + PMAn->size[0] * i67];
    }

    loop_ub = PS->size[1];
    i67 = b_PS->size[0] * b_PS->size[1];
    b_PS->size[0] = 1;
    b_PS->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PS, i67);
    for (i67 = 0; i67 < loop_ub; i67++) {
      b_PS->data[i67] = PS->data[i + PS->size[0] * i67];
    }

    loop_ub = PCPO->size[1];
    i67 = b_PCPO->size[0] * b_PCPO->size[1];
    b_PCPO->size[0] = 1;
    b_PCPO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPO, i67);
    for (i67 = 0; i67 < loop_ub; i67++) {
      b_PCPO->data[i67] = PCPO->data[i + PCPO->size[0] * i67];
    }

    loop_ub = PCR->size[1];
    i67 = b_PCR->size[0] * b_PCR->size[1];
    b_PCR->size[0] = 1;
    b_PCR->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCR, i67);
    for (i67 = 0; i67 < loop_ub; i67++) {
      b_PCR->data[i67] = PCR->data[i + PCR->size[0] * i67];
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
      i67 = 0;
      EndCPrOA = 0;
    } else {
      i67 = k - 1;
    }

    loop_ub = EndCPrOA - i67;
    for (i68 = 0; i68 < loop_ub; i68++) {
      H->data[(i67 + i68) + H->size[0] * (CPrOA - 1)] = (unsigned int)(i + 1);
    }

    UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (CPrOA - 1)) - 1] =
      EndCPrOAxD;
    if (IniSA > EndSA) {
      i67 = 0;
      i68 = 0;
    } else {
      i67 = IniSA - 1;
      i68 = EndSA;
    }

    if ((NumRec[0] < 0) && (NumRec[1] < MIN_int32_T - NumRec[0])) {
      DispME = MIN_int32_T;
    } else if ((NumRec[0] > 0) && (NumRec[1] > MAX_int32_T - NumRec[0])) {
      DispME = MAX_int32_T;
    } else {
      DispME = NumRec[0] + NumRec[1];
    }

    CPrOA = r10->size[0];
    r10->size[0] = SA->size[1];
    emxEnsureCapacity_int32_T(r10, CPrOA);
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

      r10->data[CPrOA] = k;
    }

    k = i68 - i67;
    EndCPrOA = r10->size[0];
    for (i68 = 0; i68 < EndCPrOA; i68++) {
      for (CPrOA = 0; CPrOA < k; CPrOA++) {
        H->data[(i67 + CPrOA) + H->size[0] * (r10->data[i68] - 1)] = (unsigned
          int)(i + 1);
      }
    }

    EndCPrOA = r10->size[0];
    for (i67 = 0; i67 < EndCPrOA; i67++) {
      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (r10->data[i67] -
        1)) - 1] = EndRPxD;
    }

    i67 = EA->size[1];
    if (0 <= i67 - 1) {
      if (IniSA > EndSA) {
        i69 = 0;
        i70 = 0;
      } else {
        i69 = IniSA - 1;
        i70 = EndSA;
      }
    }

    for (k = 0; k < i67; k++) {
      EndCPrOA = EA->data[k];
      if ((NumRec[0] < 0) && (EndCPrOA < MIN_int32_T - NumRec[0])) {
        DispME = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (EndCPrOA > MAX_int32_T - NumRec[0])) {
        DispME = MAX_int32_T;
      } else {
        DispME = NumRec[0] + EndCPrOA;
      }

      loop_ub = i70 - i69;
      for (i68 = 0; i68 < loop_ub; i68++) {
        H->data[(i69 + i68) + H->size[0] * (DispME - 1)] = (unsigned int)(i + 1);
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

    i67 = AA->size[1];
    if (0 <= i67 - 1) {
      if (IniSA > EndSA) {
        i71 = 0;
        i72 = 0;
      } else {
        i71 = IniSA - 1;
        i72 = EndSA;
      }
    }

    for (k = 0; k < i67; k++) {
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

      loop_ub = i72 - i71;
      for (i68 = 0; i68 < loop_ub; i68++) {
        H->data[(i71 + i68) + H->size[0] * (DispME - 1)] = (unsigned int)(i + 1);
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

    i67 = AnA->size[1];
    if (0 <= i67 - 1) {
      if (IniSA > EndSA) {
        i73 = 0;
        i74 = 0;
      } else {
        i73 = IniSA - 1;
        i74 = EndSA;
      }
    }

    for (k = 0; k < i67; k++) {
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

      loop_ub = i74 - i73;
      for (i68 = 0; i68 < loop_ub; i68++) {
        H->data[(i73 + i68) + H->size[0] * (DispME - 1)] = (unsigned int)(i + 1);
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
        i67 = 0;
        EndCRA = 0;
      } else {
        i67 = IniCRA - 1;
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

      loop_ub = EndCRA - i67;
      for (i68 = 0; i68 < loop_ub; i68++) {
        H->data[(i67 + i68) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
      }
    } else {
      if (IniCPOA > EndCPOA) {
        i67 = 0;
        EndCPOA = 0;
      } else {
        i67 = IniCPOA - 1;
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

      loop_ub = EndCPOA - i67;
      for (i68 = 0; i68 < loop_ub; i68++) {
        H->data[(i67 + i68) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
      }

      if (IniCRA > EndCRA) {
        i67 = 0;
        EndCRA = 0;
      } else {
        i67 = IniCRA - 1;
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

      loop_ub = EndCRA - i67;
      for (i68 = 0; i68 < loop_ub; i68++) {
        H->data[(i67 + i68) + H->size[0] * (k - 1)] = (unsigned int)(i + 1);
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
  emxFree_int32_T(&r10);
  emxFree_int32_T(&SA);
  emxFree_int32_T(&AnA);
  emxFree_int32_T(&AA);
  emxFree_int32_T(&EA);
  emxFree_int32_T(&tempUltPosRecXDia);
  emxFree_real_T(&UltPosRecXDia);
  b_favalia(H, DiaOp, EP, EspMedOp, k0, k1, k2, k3, &d22, &d23, &d24, &d25, &d26,
            &d27);
  *NOE3 = d27;
  *NOE2 = d26;
  *TmNOFP = d25;
  *NOFP = d24;
  *Tt = d23;
  *fitness = d22;
  emxFree_real_T(&EspMedOp);
  emxFree_int32_T(&DiaOp);
  emxFree_real_T(&H);
}

/* End of code generation (sch.c) */
