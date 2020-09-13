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
  int loop_ub;
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *DispME;
  emxArray_int32_T *EA;
  emxArray_int32_T *AA;
  emxArray_int32_T *AnA;
  emxArray_int32_T *SA;
  emxArray_int32_T *r8;
  emxArray_int32_T *b_PCPrO;
  emxArray_int32_T *b_PME;
  emxArray_int32_T *b_PMA;
  emxArray_int32_T *b_PMAn;
  emxArray_int32_T *b_PS;
  emxArray_int32_T *b_PCPO;
  emxArray_int32_T *b_PCR;
  int i;
  int contDia;
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
  int i40;
  int i41;
  int i42;
  int i43;
  int i44;
  int i45;
  double y;

  /* UNTITLED4 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*     NCPrO  |    NME    |     NS    |     NA    |     NAn    |    NCPO     |   NCR */
  /*   Col 1-20 | Col 21-50 | Col 51-62 | Col 63-87 | Col 88-112 | Col 113-132 | Col 133-172 */
  i38 = EspMedOp->size[0] * EspMedOp->size[1];
  EspMedOp->size[0] = NumTOp;
  EspMedOp->size[1] = 2;
  emxEnsureCapacity_int32_T(EspMedOp, i38);
  loop_ub = NumTOp << 1;
  for (i38 = 0; i38 < loop_ub; i38++) {
    EspMedOp->data[i38] = 0;
  }

  i38 = DiaOp->size[0];
  DiaOp->size[0] = NumTOp;
  emxEnsureCapacity_int32_T(DiaOp, i38);
  emxInit_int32_T(&tempUltPosRecXDia, 2);
  emxInit_int32_T(&DispME, 2);
  emxInit_int32_T(&EA, 2);
  emxInit_int32_T(&AA, 2);
  emxInit_int32_T(&AnA, 2);
  emxInit_int32_T(&SA, 2);
  emxInit_int32_T(&r8, 1);
  emxInit_int32_T(&b_PCPrO, 2);
  emxInit_int32_T(&b_PME, 2);
  emxInit_int32_T(&b_PMA, 2);
  emxInit_int32_T(&b_PMAn, 2);
  emxInit_int32_T(&b_PS, 2);
  emxInit_int32_T(&b_PCPO, 2);
  emxInit_int32_T(&b_PCR, 2);
  for (i = 0; i < NumTOp; i++) {
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
    DiaOp->data[i] = contDia;
    if (IniCPrOA > EndCPrOA) {
      i38 = 0;
      EndCPrOA = 0;
    } else {
      i38 = IniCPrOA - 1;
    }

    loop_ub = EndCPrOA - i38;
    for (i39 = 0; i39 < loop_ub; i39++) {
      H->data[(i38 + i39) + H->size[0] * (CPrOA - 1)] = i + 1;
    }

    UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (CPrOA - 1)) - 1] =
      EndCPrOAxD;
    if (IniSA > EndSA) {
      i38 = 0;
      i39 = 0;
    } else {
      i38 = IniSA - 1;
      i39 = EndSA;
    }

    if ((NumRec[0] < 0) && (NumRec[1] < MIN_int32_T - NumRec[0])) {
      CPrOA = MIN_int32_T;
    } else if ((NumRec[0] > 0) && (NumRec[1] > MAX_int32_T - NumRec[0])) {
      CPrOA = MAX_int32_T;
    } else {
      CPrOA = NumRec[0] + NumRec[1];
    }

    EndCPrOAxD = r8->size[0];
    r8->size[0] = SA->size[1];
    emxEnsureCapacity_int32_T(r8, EndCPrOAxD);
    loop_ub = SA->size[1];
    for (EndCPrOAxD = 0; EndCPrOAxD < loop_ub; EndCPrOAxD++) {
      EndCPrOA = SA->data[EndCPrOAxD];
      if ((CPrOA < 0) && (EndCPrOA < MIN_int32_T - CPrOA)) {
        IniCPrOA = MIN_int32_T;
      } else if ((CPrOA > 0) && (EndCPrOA > MAX_int32_T - CPrOA)) {
        IniCPrOA = MAX_int32_T;
      } else {
        IniCPrOA = CPrOA + EndCPrOA;
      }

      r8->data[EndCPrOAxD] = IniCPrOA;
    }

    IniCPrOA = i39 - i38;
    EndCPrOA = r8->size[0];
    for (i39 = 0; i39 < EndCPrOA; i39++) {
      for (EndCPrOAxD = 0; EndCPrOAxD < IniCPrOA; EndCPrOAxD++) {
        H->data[(i38 + EndCPrOAxD) + H->size[0] * (r8->data[i39] - 1)] = i + 1;
      }
    }

    EndCPrOA = r8->size[0];
    for (i38 = 0; i38 < EndCPrOA; i38++) {
      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (r8->data[i38] - 1))
        - 1] = EndRPxD;
    }

    i38 = EA->size[1];
    if (0 <= i38 - 1) {
      if (IniSA > EndSA) {
        i40 = 0;
        i41 = 0;
      } else {
        i40 = IniSA - 1;
        i41 = EndSA;
      }
    }

    for (IniCPrOA = 0; IniCPrOA < i38; IniCPrOA++) {
      EndCPrOA = EA->data[IniCPrOA];
      if ((NumRec[0] < 0) && (EndCPrOA < MIN_int32_T - NumRec[0])) {
        CPrOA = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (EndCPrOA > MAX_int32_T - NumRec[0])) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA = NumRec[0] + EndCPrOA;
      }

      loop_ub = i41 - i40;
      for (i39 = 0; i39 < loop_ub; i39++) {
        H->data[(i40 + i39) + H->size[0] * (CPrOA - 1)] = i + 1;
      }

      EndCPrOA = EA->data[IniCPrOA];
      if ((NumRec[0] < 0) && (EndCPrOA < MIN_int32_T - NumRec[0])) {
        CPrOA = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (EndCPrOA > MAX_int32_T - NumRec[0])) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA = NumRec[0] + EndCPrOA;
      }

      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (CPrOA - 1)) - 1] =
        EndRPxD;
      EspMedOp->data[i + EspMedOp->size[0] * IniCPrOA] = PME->data[i + PME->
        size[0] * (EA->data[IniCPrOA] - 1)];
    }

    i38 = AA->size[1];
    if (0 <= i38 - 1) {
      if (IniSA > EndSA) {
        i42 = 0;
        i43 = 0;
      } else {
        i42 = IniSA - 1;
        i43 = EndSA;
      }
    }

    for (IniCPrOA = 0; IniCPrOA < i38; IniCPrOA++) {
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

      EndCPrOA = AA->data[IniCPrOA];
      if ((CPrOA < 0) && (EndCPrOA < MIN_int32_T - CPrOA)) {
        CPrOA = MIN_int32_T;
      } else if ((CPrOA > 0) && (EndCPrOA > MAX_int32_T - CPrOA)) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA += EndCPrOA;
      }

      loop_ub = i43 - i42;
      for (i39 = 0; i39 < loop_ub; i39++) {
        H->data[(i42 + i39) + H->size[0] * (CPrOA - 1)] = i + 1;
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

      EndCPrOA = AA->data[IniCPrOA];
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

    i38 = AnA->size[1];
    if (0 <= i38 - 1) {
      if (IniSA > EndSA) {
        i44 = 0;
        i45 = 0;
      } else {
        i44 = IniSA - 1;
        i45 = EndSA;
      }
    }

    for (IniCPrOA = 0; IniCPrOA < i38; IniCPrOA++) {
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

      EndCPrOA = AnA->data[IniCPrOA];
      if ((CPrOA < 0) && (EndCPrOA < MIN_int32_T - CPrOA)) {
        CPrOA = MIN_int32_T;
      } else if ((CPrOA > 0) && (EndCPrOA > MAX_int32_T - CPrOA)) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA += EndCPrOA;
      }

      loop_ub = i45 - i44;
      for (i39 = 0; i39 < loop_ub; i39++) {
        H->data[(i44 + i39) + H->size[0] * (CPrOA - 1)] = i + 1;
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

      EndCPrOA = AnA->data[IniCPrOA];
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
        i38 = 0;
        EndCRA = 0;
      } else {
        i38 = IniCRA - 1;
      }

      y = NumRec[0];
      for (IniCPrOA = 0; IniCPrOA < 5; IniCPrOA++) {
        y += (double)NumRec[IniCPrOA + 1];
      }

      y += (double)CRA;
      if (y < 2.147483648E+9) {
        if (y >= -2.147483648E+9) {
          IniCPrOA = (int)y;
        } else {
          IniCPrOA = MIN_int32_T;
        }
      } else {
        IniCPrOA = MAX_int32_T;
      }

      loop_ub = EndCRA - i38;
      for (i39 = 0; i39 < loop_ub; i39++) {
        H->data[(i38 + i39) + H->size[0] * (IniCPrOA - 1)] = i + 1;
      }
    } else {
      if (IniCPOA > EndCPOA) {
        i38 = 0;
        EndCPOA = 0;
      } else {
        i38 = IniCPOA - 1;
      }

      y = (((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
            (double)NumRec[3]) + (double)NumRec[4]) + (double)CPOA;
      if (y < 2.147483648E+9) {
        if (y >= -2.147483648E+9) {
          IniCPrOA = (int)y;
        } else {
          IniCPrOA = MIN_int32_T;
        }
      } else {
        IniCPrOA = MAX_int32_T;
      }

      loop_ub = EndCPOA - i38;
      for (i39 = 0; i39 < loop_ub; i39++) {
        H->data[(i38 + i39) + H->size[0] * (IniCPrOA - 1)] = i + 1;
      }

      if (IniCRA > EndCRA) {
        i38 = 0;
        EndCRA = 0;
      } else {
        i38 = IniCRA - 1;
      }

      y = NumRec[0];
      for (IniCPrOA = 0; IniCPrOA < 5; IniCPrOA++) {
        y += (double)NumRec[IniCPrOA + 1];
      }

      y += (double)CRA;
      if (y < 2.147483648E+9) {
        if (y >= -2.147483648E+9) {
          IniCPrOA = (int)y;
        } else {
          IniCPrOA = MIN_int32_T;
        }
      } else {
        IniCPrOA = MAX_int32_T;
      }

      loop_ub = EndCRA - i38;
      for (i39 = 0; i39 < loop_ub; i39++) {
        H->data[(i38 + i39) + H->size[0] * (IniCPrOA - 1)] = i + 1;
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
  emxFree_int32_T(&r8);
  emxFree_int32_T(&SA);
  emxFree_int32_T(&AnA);
  emxFree_int32_T(&AA);
  emxFree_int32_T(&EA);
  emxFree_int32_T(&DispME);
  emxFree_int32_T(&tempUltPosRecXDia);
}

/* End of code generation (casorandom.c) */
