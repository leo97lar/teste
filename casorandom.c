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

/* Function Definitions */
void casorandom(int NumTOp, emxArray_int32_T *H, const int NumRec[7], const
                emxArray_int32_T *PCPrO, const emxArray_int32_T *PME, const
                emxArray_int32_T *PMA, const emxArray_int32_T *PMAn, const
                emxArray_int32_T *PS, const emxArray_int32_T *PCPO, const
                emxArray_int32_T *PCR, const emxArray_int32_T *Dia,
                emxArray_int32_T *UltPosRecXDia, const emxArray_int32_T
                *TimeUsoRec, const emxArray_int32_T *DispMExD, emxArray_int32_T *
                schedule, emxArray_int32_T *DiaOp, emxArray_int32_T *EspMedOp)
{
  int i27;
  int loop_ub;
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *DispME;
  emxArray_int32_T *EA;
  emxArray_int32_T *AA;
  emxArray_int32_T *AnA;
  emxArray_int32_T *SA;
  emxArray_int32_T *r4;
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
  int i28;
  int i29;
  int i30;
  int i31;
  int i32;
  int i33;
  int i34;
  double y;

  /* UNTITLED4 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /*     NCPrO  |    NME    |     NS    |     NA    |     NAn    |    NCPO     |   NCR */
  /*   Col 1-20 | Col 21-50 | Col 51-62 | Col 63-87 | Col 88-112 | Col 113-132 | Col 133-172 */
  i27 = EspMedOp->size[0] * EspMedOp->size[1];
  EspMedOp->size[0] = NumTOp;
  EspMedOp->size[1] = 2;
  emxEnsureCapacity_int32_T(EspMedOp, i27);
  loop_ub = NumTOp << 1;
  for (i27 = 0; i27 < loop_ub; i27++) {
    EspMedOp->data[i27] = 0;
  }

  i27 = DiaOp->size[0];
  DiaOp->size[0] = NumTOp;
  emxEnsureCapacity_int32_T(DiaOp, i27);
  emxInit_int32_T(&tempUltPosRecXDia, 2);
  emxInit_int32_T(&DispME, 2);
  emxInit_int32_T(&EA, 2);
  emxInit_int32_T(&AA, 2);
  emxInit_int32_T(&AnA, 2);
  emxInit_int32_T(&SA, 2);
  emxInit_int32_T(&r4, 1);
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
    i27 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPrO, i27);
    for (i27 = 0; i27 < loop_ub; i27++) {
      b_PCPrO->data[i27] = PCPrO->data[i + PCPrO->size[0] * i27];
    }

    c_funcionDia(NumRec, b_PCPrO, Dia, UltPosRecXDia, TimeUsoRec->data[i],
                 TimeUsoRec->data[i + TimeUsoRec->size[0]], &contDia, DispMExD,
                 tempUltPosRecXDia, DispME);
    loop_ub = PCPrO->size[1];
    i27 = b_PCPrO->size[0] * b_PCPrO->size[1];
    b_PCPrO->size[0] = 1;
    b_PCPrO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPrO, i27);
    for (i27 = 0; i27 < loop_ub; i27++) {
      b_PCPrO->data[i27] = PCPrO->data[i + PCPrO->size[0] * i27];
    }

    loop_ub = PME->size[1];
    i27 = b_PME->size[0] * b_PME->size[1];
    b_PME->size[0] = 1;
    b_PME->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PME, i27);
    for (i27 = 0; i27 < loop_ub; i27++) {
      b_PME->data[i27] = PME->data[i + PME->size[0] * i27];
    }

    loop_ub = PMA->size[1];
    i27 = b_PMA->size[0] * b_PMA->size[1];
    b_PMA->size[0] = 1;
    b_PMA->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PMA, i27);
    for (i27 = 0; i27 < loop_ub; i27++) {
      b_PMA->data[i27] = PMA->data[i + PMA->size[0] * i27];
    }

    loop_ub = PMAn->size[1];
    i27 = b_PMAn->size[0] * b_PMAn->size[1];
    b_PMAn->size[0] = 1;
    b_PMAn->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PMAn, i27);
    for (i27 = 0; i27 < loop_ub; i27++) {
      b_PMAn->data[i27] = PMAn->data[i + PMAn->size[0] * i27];
    }

    loop_ub = PS->size[1];
    i27 = b_PS->size[0] * b_PS->size[1];
    b_PS->size[0] = 1;
    b_PS->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PS, i27);
    for (i27 = 0; i27 < loop_ub; i27++) {
      b_PS->data[i27] = PS->data[i + PS->size[0] * i27];
    }

    loop_ub = PCPO->size[1];
    i27 = b_PCPO->size[0] * b_PCPO->size[1];
    b_PCPO->size[0] = 1;
    b_PCPO->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCPO, i27);
    for (i27 = 0; i27 < loop_ub; i27++) {
      b_PCPO->data[i27] = PCPO->data[i + PCPO->size[0] * i27];
    }

    loop_ub = PCR->size[1];
    i27 = b_PCR->size[0] * b_PCR->size[1];
    b_PCR->size[0] = 1;
    b_PCR->size[1] = loop_ub;
    emxEnsureCapacity_int32_T(b_PCR, i27);
    for (i27 = 0; i27 < loop_ub; i27++) {
      b_PCR->data[i27] = PCR->data[i + PCR->size[0] * i27];
    }

    c_funcionCPrO(NumRec, b_PCPrO, b_PME, b_PMA, b_PMAn, b_PS, b_PCPO, b_PCR, H,
                  Dia, UltPosRecXDia, TimeUsoRec->data[i], TimeUsoRec->data[i +
                  TimeUsoRec->size[0]], TimeUsoRec->data[i + TimeUsoRec->size[0]
                  * 5], TimeUsoRec->data[i + TimeUsoRec->size[0] * 6], &contDia,
                  tempUltPosRecXDia, DispMExD, DispME, &CPrOA, &IniCPrOA,
                  &EndCPrOA, &EndCPrOAxD, EA, AA, AnA, SA, &IniSA, &EndSA,
                  &EndRPxD, &CPOA, &IniCPOA, &EndCPOA, &CRA, &IniCRA, &EndCRA);
    DiaOp->data[i] = contDia;
    if (IniCPrOA > EndCPrOA) {
      i27 = 0;
      EndCPrOA = 0;
    } else {
      i27 = IniCPrOA - 1;
    }

    loop_ub = EndCPrOA - i27;
    for (i28 = 0; i28 < loop_ub; i28++) {
      H->data[(i27 + i28) + H->size[0] * (CPrOA - 1)] = i + 1;
    }

    UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (CPrOA - 1)) - 1] =
      EndCPrOAxD;
    if (IniSA > EndSA) {
      i27 = 0;
      i28 = 0;
    } else {
      i27 = IniSA - 1;
      i28 = EndSA;
    }

    if ((NumRec[0] < 0) && (NumRec[1] < MIN_int32_T - NumRec[0])) {
      CPrOA = MIN_int32_T;
    } else if ((NumRec[0] > 0) && (NumRec[1] > MAX_int32_T - NumRec[0])) {
      CPrOA = MAX_int32_T;
    } else {
      CPrOA = NumRec[0] + NumRec[1];
    }

    EndCPrOAxD = r4->size[0];
    r4->size[0] = SA->size[1];
    emxEnsureCapacity_int32_T(r4, EndCPrOAxD);
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

      r4->data[EndCPrOAxD] = IniCPrOA;
    }

    IniCPrOA = i28 - i27;
    EndCPrOA = r4->size[0];
    for (i28 = 0; i28 < EndCPrOA; i28++) {
      for (EndCPrOAxD = 0; EndCPrOAxD < IniCPrOA; EndCPrOAxD++) {
        H->data[(i27 + EndCPrOAxD) + H->size[0] * (r4->data[i28] - 1)] = i + 1;
      }
    }

    EndCPrOA = r4->size[0];
    for (i27 = 0; i27 < EndCPrOA; i27++) {
      UltPosRecXDia->data[(contDia + UltPosRecXDia->size[0] * (r4->data[i27] - 1))
        - 1] = EndRPxD;
    }

    i27 = EA->size[1];
    if (0 <= i27 - 1) {
      if (IniSA > EndSA) {
        i29 = 0;
        i30 = 0;
      } else {
        i29 = IniSA - 1;
        i30 = EndSA;
      }
    }

    for (IniCPrOA = 0; IniCPrOA < i27; IniCPrOA++) {
      EndCPrOA = EA->data[IniCPrOA];
      if ((NumRec[0] < 0) && (EndCPrOA < MIN_int32_T - NumRec[0])) {
        CPrOA = MIN_int32_T;
      } else if ((NumRec[0] > 0) && (EndCPrOA > MAX_int32_T - NumRec[0])) {
        CPrOA = MAX_int32_T;
      } else {
        CPrOA = NumRec[0] + EndCPrOA;
      }

      loop_ub = i30 - i29;
      for (i28 = 0; i28 < loop_ub; i28++) {
        H->data[(i29 + i28) + H->size[0] * (CPrOA - 1)] = i + 1;
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

    i27 = AA->size[1];
    if (0 <= i27 - 1) {
      if (IniSA > EndSA) {
        i31 = 0;
        i32 = 0;
      } else {
        i31 = IniSA - 1;
        i32 = EndSA;
      }
    }

    for (IniCPrOA = 0; IniCPrOA < i27; IniCPrOA++) {
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

      loop_ub = i32 - i31;
      for (i28 = 0; i28 < loop_ub; i28++) {
        H->data[(i31 + i28) + H->size[0] * (CPrOA - 1)] = i + 1;
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

    i27 = AnA->size[1];
    if (0 <= i27 - 1) {
      if (IniSA > EndSA) {
        i33 = 0;
        i34 = 0;
      } else {
        i33 = IniSA - 1;
        i34 = EndSA;
      }
    }

    for (IniCPrOA = 0; IniCPrOA < i27; IniCPrOA++) {
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

      loop_ub = i34 - i33;
      for (i28 = 0; i28 < loop_ub; i28++) {
        H->data[(i33 + i28) + H->size[0] * (CPrOA - 1)] = i + 1;
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
        i27 = 0;
        EndCRA = 0;
      } else {
        i27 = IniCRA - 1;
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

      loop_ub = EndCRA - i27;
      for (i28 = 0; i28 < loop_ub; i28++) {
        H->data[(i27 + i28) + H->size[0] * (IniCPrOA - 1)] = i + 1;
      }
    } else {
      if (IniCPOA > EndCPOA) {
        i27 = 0;
        EndCPOA = 0;
      } else {
        i27 = IniCPOA - 1;
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

      loop_ub = EndCPOA - i27;
      for (i28 = 0; i28 < loop_ub; i28++) {
        H->data[(i27 + i28) + H->size[0] * (IniCPrOA - 1)] = i + 1;
      }

      if (IniCRA > EndCRA) {
        i27 = 0;
        EndCRA = 0;
      } else {
        i27 = IniCRA - 1;
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

      loop_ub = EndCRA - i27;
      for (i28 = 0; i28 < loop_ub; i28++) {
        H->data[(i27 + i28) + H->size[0] * (IniCPrOA - 1)] = i + 1;
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
  emxFree_int32_T(&r4);
  emxFree_int32_T(&SA);
  emxFree_int32_T(&AnA);
  emxFree_int32_T(&AA);
  emxFree_int32_T(&EA);
  emxFree_int32_T(&DispME);
  emxFree_int32_T(&tempUltPosRecXDia);
  i27 = schedule->size[0] * schedule->size[1];
  schedule->size[0] = H->size[0];
  schedule->size[1] = H->size[1];
  emxEnsureCapacity_int32_T(schedule, i27);
  loop_ub = H->size[0] * H->size[1];
  for (i27 = 0; i27 < loop_ub; i27++) {
    schedule->data[i27] = H->data[i27];
  }
}

/* End of code generation (casorandom.c) */
