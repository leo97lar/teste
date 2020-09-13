/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * funcionCPrO.c
 *
 * Code generation for function 'funcionCPrO'
 *
 */

/* Include files */
#include <math.h>
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "funcionCPrO.h"
#include "funcionDia.h"
#include "model_emxutil.h"
#include "sum.h"
#include "obsIQini.h"
#include "model_rtwutil.h"

/* Function Definitions */
void b_funcionCPrO(const int NumRec[7], const emxArray_int32_T *PCPrO, const
                   emxArray_int32_T *PME, const emxArray_int32_T *PMA, const
                   emxArray_int32_T *PMAn, const emxArray_int32_T *PS, const
                   emxArray_int32_T *PCPO, const emxArray_int32_T *PCR, const
                   emxArray_real_T *H, const emxArray_int32_T *Dia, const
                   emxArray_real_T *UltPosRecXDia, int TimeUsoCPrO, int TimeUsoS,
                   int TimeUsoCPO, int TimeUsoCR, int *contDia, emxArray_int32_T
                   *tempUltPosRecXDia, const emxArray_int32_T *DispMExD,
                   emxArray_int32_T *DispME, int *CPrOA, int *IniCPrOA, int
                   *EndCPrOA, int *EndCPrOAxD, emxArray_int32_T *EA,
                   emxArray_int32_T *AA, emxArray_int32_T *AnA, emxArray_int32_T
                   *SA, int *IniSA, int *EndSA, int *EndRPxD, int *CPOA, int
                   *IniCPOA, int *EndCPOA, int *CRA, int *IniCRA, int *EndCRA)
{
  int yk;
  int nm1d2;
  int n;
  unsigned int nm1;
  emxArray_int32_T *j;
  int i53;
  emxArray_int32_T *E;
  int temCPrO;
  int qEnd;
  double a;
  double b;
  emxArray_real_T *r12;
  double ndbl;
  double apnd;
  double cdiff;
  emxArray_int32_T *S;
  emxArray_real_T *C;
  emxArray_int32_T *A;
  emxArray_real_T *CR;
  emxArray_int32_T *An;
  emxArray_int32_T *CPO;
  int kEnd;
  int b_CPrOA;
  int b_CPOA;
  int b_CRA;
  int qY;
  int b_qY;
  int b_IniSA;
  int b_EndSA;
  int b_IniCPOA;
  int c_qY;
  int b_IniCRA;
  int d_qY;
  int e_qY;
  int f_qY;
  boolean_T flag;
  emxArray_uint32_T *uCPrODisp;
  emxArray_int32_T *allC;
  emxArray_int32_T *allA;
  emxArray_int32_T *allAn;
  emxArray_int32_T *allS;
  emxArray_int32_T *allCPO;
  emxArray_int32_T *allCR;
  emxArray_boolean_T *x;
  emxArray_int32_T *b_b;
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  emxArray_real_T *b_H;
  boolean_T exitg1;
  int q;
  int na;
  int b_j;
  int nb;
  int p;
  long long i54;
  int exitg2;
  if (NumRec[0] > 2147483646) {
    yk = MAX_int32_T;
  } else {
    yk = NumRec[0] + 1;
  }

  nm1d2 = (int)e_sum(*(int (*)[2])&NumRec[0]);
  if (nm1d2 < yk) {
    n = 0;
  } else {
    if ((yk < 0) && (nm1d2 >= 0)) {
      nm1 = (unsigned int)nm1d2 - yk;
    } else {
      nm1 = (unsigned int)(nm1d2 - yk);
    }

    n = (int)nm1 + 1;
  }

  emxInit_int32_T(&j, 2);
  i53 = j->size[0] * j->size[1];
  j->size[0] = 1;
  j->size[1] = n;
  emxEnsureCapacity_int32_T(j, i53);
  if (n > 0) {
    j->data[0] = yk;
    for (temCPrO = 2; temCPrO <= n; temCPrO++) {
      yk++;
      j->data[temCPrO - 1] = yk;
    }
  }

  emxInit_int32_T(&E, 2);
  if (j->size[1] < 1) {
    E->size[0] = 1;
    E->size[1] = 0;
  } else {
    qEnd = j->size[1];
    i53 = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = qEnd;
    emxEnsureCapacity_int32_T(E, i53);
    for (i53 = 0; i53 < qEnd; i53++) {
      E->data[i53] = 1 + i53;
    }
  }

  a = e_sum(*(int (*)[2])&NumRec[0]) + 1.0;
  b = f_sum(*(int (*)[3])&NumRec[0]);
  emxInit_real_T(&r12, 2);
  if (b < a) {
    i53 = r12->size[0] * r12->size[1];
    r12->size[1] = 0;
    emxEnsureCapacity_real_T(r12, i53);
  } else if (floor(a) == a) {
    i53 = r12->size[0] * r12->size[1];
    r12->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(r12, i53);
  } else {
    ndbl = floor((b - a) + 0.5);
    apnd = a + ndbl;
    cdiff = apnd - b;
    if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(a), fabs(b))) {
      ndbl++;
      apnd = b;
    } else if (cdiff > 0.0) {
      apnd = a + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }

    i53 = r12->size[0] * r12->size[1];
    r12->size[0] = 1;
    r12->size[1] = n;
    emxEnsureCapacity_real_T(r12, i53);
    if ((n > 0) && (n > 1)) {
      r12->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (temCPrO = 0; temCPrO <= nm1d2 - 2; temCPrO++) {
        r12->data[1 + temCPrO] = a + (1.0 + (double)temCPrO);
        r12->data[(n - temCPrO) - 2] = apnd - (1.0 + (double)temCPrO);
      }

      if (nm1d2 << 1 == n - 1) {
        r12->data[nm1d2] = (a + apnd) / 2.0;
      } else {
        r12->data[nm1d2] = a + (double)nm1d2;
        r12->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_int32_T(&S, 2);
  if (r12->size[1] < 1) {
    S->size[0] = 1;
    S->size[1] = 0;
  } else {
    qEnd = r12->size[1];
    i53 = S->size[0] * S->size[1];
    S->size[0] = 1;
    S->size[1] = qEnd;
    emxEnsureCapacity_int32_T(S, i53);
    for (i53 = 0; i53 < qEnd; i53++) {
      S->data[i53] = 1 + i53;
    }
  }

  a = f_sum(*(int (*)[3])&NumRec[0]) + 1.0;
  b = h_sum(*(int (*)[4])&NumRec[0]);
  emxInit_real_T(&C, 2);
  if (b < a) {
    i53 = C->size[0] * C->size[1];
    C->size[1] = 0;
    emxEnsureCapacity_real_T(C, i53);
  } else if (floor(a) == a) {
    i53 = C->size[0] * C->size[1];
    C->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(C, i53);
  } else {
    ndbl = floor((b - a) + 0.5);
    apnd = a + ndbl;
    cdiff = apnd - b;
    if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(a), fabs(b))) {
      ndbl++;
      apnd = b;
    } else if (cdiff > 0.0) {
      apnd = a + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }

    i53 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = n;
    emxEnsureCapacity_real_T(C, i53);
    if (n > 0) {
      C->data[0] = a;
      if (n > 1) {
        C->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (temCPrO = 0; temCPrO <= nm1d2 - 2; temCPrO++) {
          C->data[1 + temCPrO] = a + (1.0 + (double)temCPrO);
          C->data[(n - temCPrO) - 2] = apnd - (1.0 + (double)temCPrO);
        }

        if (nm1d2 << 1 == n - 1) {
          C->data[nm1d2] = (a + apnd) / 2.0;
        } else {
          C->data[nm1d2] = a + (double)nm1d2;
          C->data[nm1d2 + 1] = apnd - (double)nm1d2;
        }
      }
    }
  }

  emxInit_int32_T(&A, 2);
  if (C->size[1] < 1) {
    A->size[0] = 1;
    A->size[1] = 0;
  } else {
    qEnd = C->size[1];
    i53 = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = qEnd;
    emxEnsureCapacity_int32_T(A, i53);
    for (i53 = 0; i53 < qEnd; i53++) {
      A->data[i53] = 1 + i53;
    }
  }

  a = h_sum(*(int (*)[4])&NumRec[0]) + 1.0;
  b = i_sum(*(int (*)[5])&NumRec[0]);
  emxInit_real_T(&CR, 2);
  if (b < a) {
    i53 = CR->size[0] * CR->size[1];
    CR->size[1] = 0;
    emxEnsureCapacity_real_T(CR, i53);
  } else if (floor(a) == a) {
    i53 = CR->size[0] * CR->size[1];
    CR->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(CR, i53);
  } else {
    ndbl = floor((b - a) + 0.5);
    apnd = a + ndbl;
    cdiff = apnd - b;
    if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(a), fabs(b))) {
      ndbl++;
      apnd = b;
    } else if (cdiff > 0.0) {
      apnd = a + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }

    i53 = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    CR->size[1] = n;
    emxEnsureCapacity_real_T(CR, i53);
    if (n > 0) {
      CR->data[0] = a;
      if (n > 1) {
        CR->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (temCPrO = 0; temCPrO <= nm1d2 - 2; temCPrO++) {
          CR->data[1 + temCPrO] = a + (1.0 + (double)temCPrO);
          CR->data[(n - temCPrO) - 2] = apnd - (1.0 + (double)temCPrO);
        }

        if (nm1d2 << 1 == n - 1) {
          CR->data[nm1d2] = (a + apnd) / 2.0;
        } else {
          CR->data[nm1d2] = a + (double)nm1d2;
          CR->data[nm1d2 + 1] = apnd - (double)nm1d2;
        }
      }
    }
  }

  emxInit_int32_T(&An, 2);
  if (CR->size[1] < 1) {
    An->size[0] = 1;
    An->size[1] = 0;
  } else {
    qEnd = CR->size[1];
    i53 = An->size[0] * An->size[1];
    An->size[0] = 1;
    An->size[1] = qEnd;
    emxEnsureCapacity_int32_T(An, i53);
    for (i53 = 0; i53 < qEnd; i53++) {
      An->data[i53] = 1 + i53;
    }
  }

  emxInit_int32_T(&CPO, 2);
  if (PCPO->size[1] < 1) {
    CPO->size[0] = 1;
    CPO->size[1] = 0;
  } else {
    qEnd = PCPO->size[1];
    i53 = CPO->size[0] * CPO->size[1];
    CPO->size[0] = 1;
    CPO->size[1] = qEnd;
    emxEnsureCapacity_int32_T(CPO, i53);
    for (i53 = 0; i53 < qEnd; i53++) {
      CPO->data[i53] = 1 + i53;
    }
  }

  if (PCR->size[1] < 1) {
    CR->size[0] = 1;
    CR->size[1] = 0;
  } else {
    i53 = PCR->size[1];
    kEnd = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    qEnd = (int)((double)i53 - 1.0);
    CR->size[1] = qEnd + 1;
    emxEnsureCapacity_real_T(CR, kEnd);
    for (i53 = 0; i53 <= qEnd; i53++) {
      CR->data[i53] = 1.0 + (double)i53;
    }
  }

  b_CPrOA = 0;
  b_CPOA = 0;
  b_CRA = 0;
  qY = 0;
  b_qY = 0;
  b_IniSA = 0;
  b_EndSA = 1;
  b_IniCPOA = 0;
  c_qY = 0;
  b_IniCRA = 0;
  d_qY = 0;
  e_qY = 0;
  f_qY = 0;
  if (PME->size[1] - 1 < 1) {
    EA->size[0] = 1;
    EA->size[1] = 0;
  } else {
    qEnd = PME->size[1] - 2;
    i53 = EA->size[0] * EA->size[1];
    EA->size[0] = 1;
    EA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(EA, i53);
    for (i53 = 0; i53 <= qEnd; i53++) {
      EA->data[i53] = 1 + i53;
    }
  }

  if (PMA->size[1] - 1 < 1) {
    AA->size[0] = 1;
    AA->size[1] = 0;
  } else {
    qEnd = PMA->size[1] - 2;
    i53 = AA->size[0] * AA->size[1];
    AA->size[0] = 1;
    AA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AA, i53);
    for (i53 = 0; i53 <= qEnd; i53++) {
      AA->data[i53] = 1 + i53;
    }
  }

  if (PMAn->size[1] - 1 < 1) {
    AnA->size[0] = 1;
    AnA->size[1] = 0;
  } else {
    qEnd = PMAn->size[1] - 2;
    i53 = AnA->size[0] * AnA->size[1];
    AnA->size[0] = 1;
    AnA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AnA, i53);
    for (i53 = 0; i53 <= qEnd; i53++) {
      AnA->data[i53] = 1 + i53;
    }
  }

  if (PS->size[1] - 1 < 1) {
    SA->size[0] = 1;
    SA->size[1] = 0;
  } else {
    qEnd = PS->size[1] - 2;
    i53 = SA->size[0] * SA->size[1];
    SA->size[0] = 1;
    SA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(SA, i53);
    for (i53 = 0; i53 <= qEnd; i53++) {
      SA->data[i53] = 1 + i53;
    }
  }

  flag = true;
  emxInit_uint32_T(&uCPrODisp, 2);
  emxInit_int32_T(&allC, 2);
  emxInit_int32_T(&allA, 2);
  emxInit_int32_T(&allAn, 2);
  emxInit_int32_T(&allS, 2);
  emxInit_int32_T(&allCPO, 2);
  emxInit_int32_T(&allCR, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&b_b, 2);
  emxInit_int32_T(&idx, 2);
  emxInit_int32_T(&iwork, 1);
  emxInit_real_T(&b_H, 2);
  while (flag) {
    /*  Selecciono los ultimas posiciones a partir de donde se pueden usar las camas. */
    i53 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = PCPrO->size[1];
    emxEnsureCapacity_boolean_T(x, i53);
    qEnd = PCPrO->size[0] * PCPrO->size[1];
    for (i53 = 0; i53 < qEnd; i53++) {
      x->data[i53] = (PCPrO->data[i53] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      yk = 0;
      i53 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i53);
      nm1d2 = 1;
      exitg1 = false;
      while ((!exitg1) && (nm1d2 <= x->size[1])) {
        if (x->data[nm1d2 - 1]) {
          yk++;
          j->data[yk - 1] = nm1d2;
          if (yk >= x->size[1]) {
            exitg1 = true;
          } else {
            nm1d2++;
          }
        } else {
          nm1d2++;
        }
      }

      if (x->size[1] == 1) {
        if (yk == 0) {
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > yk) {
        j->size[1] = 0;
      } else {
        i53 = j->size[0] * j->size[1];
        j->size[1] = yk;
        emxEnsureCapacity_int32_T(j, i53);
      }
    }

    i53 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = j->size[1];
    emxEnsureCapacity_real_T(C, i53);
    qEnd = j->size[0] * j->size[1];
    for (i53 = 0; i53 < qEnd; i53++) {
      C->data[i53] = j->data[i53];
    }

    /*  Busco las posibles camas a usar. */
    nm1d2 = Dia->data[(*contDia + Dia->size[0] * 3) - 1];
    yk = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
    if ((nm1d2 >= 0) && (yk < nm1d2 - MAX_int32_T)) {
      nm1d2 = MAX_int32_T;
    } else if ((nm1d2 < 0) && (yk > nm1d2 - MIN_int32_T)) {
      nm1d2 = MIN_int32_T;
    } else {
      nm1d2 -= yk;
    }

    if (nm1d2 > 2147483646) {
      nm1d2 = MAX_int32_T;
    } else {
      nm1d2++;
    }

    if ((TimeUsoCPrO < 0) && (TimeUsoS < MIN_int32_T - TimeUsoCPrO)) {
      q = MIN_int32_T;
    } else if ((TimeUsoCPrO > 0) && (TimeUsoS > MAX_int32_T - TimeUsoCPrO)) {
      q = MAX_int32_T;
    } else {
      q = TimeUsoCPrO + TimeUsoS;
    }

    if ((nm1d2 >= 0) && (q < nm1d2 - MAX_int32_T)) {
      nm1d2 = MAX_int32_T;
    } else if ((nm1d2 < 0) && (q > nm1d2 - MIN_int32_T)) {
      nm1d2 = MIN_int32_T;
    } else {
      nm1d2 -= q;
    }

    /*  Posicion maxima a partir de la cual se puede colocar la Operacion. */
    i53 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = C->size[1];
    emxEnsureCapacity_boolean_T(x, i53);
    qEnd = C->size[0] * C->size[1];
    for (i53 = 0; i53 < qEnd; i53++) {
      x->data[i53] = (tempUltPosRecXDia->data[(int)C->data[i53] - 1] <= nm1d2);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      yk = 0;
      i53 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i53);
      nm1d2 = 1;
      exitg1 = false;
      while ((!exitg1) && (nm1d2 <= x->size[1])) {
        if (x->data[nm1d2 - 1]) {
          yk++;
          j->data[yk - 1] = nm1d2;
          if (yk >= x->size[1]) {
            exitg1 = true;
          } else {
            nm1d2++;
          }
        } else {
          nm1d2++;
        }
      }

      if (x->size[1] == 1) {
        if (yk == 0) {
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > yk) {
        j->size[1] = 0;
      } else {
        i53 = j->size[0] * j->size[1];
        j->size[1] = yk;
        emxEnsureCapacity_int32_T(j, i53);
      }
    }

    i53 = allC->size[0] * allC->size[1];
    allC->size[0] = 1;
    allC->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(allC, i53);
    qEnd = j->size[0] * j->size[1];
    for (i53 = 0; i53 < qEnd; i53++) {
      allC->data[i53] = j->data[i53];
    }

    /*  Veo en cuales es posible asignar la operacion. */
    if (allC->size[1] == 0) {
      /*  Si no es posible asignar ninguna cama incremento el contDia e llamo a funcionDia */
      nm1d2 = *contDia;
      if (nm1d2 > 2147483646) {
        *contDia = MAX_int32_T;
      } else {
        *contDia = nm1d2 + 1;
      }

      b_funcionDia(NumRec, PCPrO, Dia, UltPosRecXDia, TimeUsoCPrO, TimeUsoS,
                   contDia, DispMExD, tempUltPosRecXDia, DispME);
    } else {
      i53 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(j, i53);
      qEnd = allC->size[0] * allC->size[1];
      for (i53 = 0; i53 < qEnd; i53++) {
        j->data[i53] = tempUltPosRecXDia->data[(int)(unsigned int)C->data
          [allC->data[i53] - 1] - 1];
      }

      na = allC->size[1];
      n = allC->size[1] + 1;
      i53 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(idx, i53);
      qEnd = allC->size[1];
      for (i53 = 0; i53 < qEnd; i53++) {
        idx->data[i53] = 0;
      }

      i53 = iwork->size[0];
      iwork->size[0] = allC->size[1];
      emxEnsureCapacity_int32_T(iwork, i53);
      i53 = allC->size[1] - 1;
      for (temCPrO = 1; temCPrO <= i53; temCPrO += 2) {
        if (j->data[temCPrO - 1] <= j->data[temCPrO]) {
          idx->data[temCPrO - 1] = temCPrO;
          idx->data[temCPrO] = temCPrO + 1;
        } else {
          idx->data[temCPrO - 1] = temCPrO + 1;
          idx->data[temCPrO] = temCPrO;
        }
      }

      if ((allC->size[1] & 1) != 0) {
        idx->data[allC->size[1] - 1] = allC->size[1];
      }

      nm1d2 = 2;
      while (nm1d2 < n - 1) {
        yk = nm1d2 << 1;
        b_j = 1;
        for (nb = 1 + nm1d2; nb < n; nb = qEnd + nm1d2) {
          p = b_j;
          q = nb;
          qEnd = b_j + yk;
          if (qEnd > n) {
            qEnd = n;
          }

          temCPrO = 0;
          kEnd = qEnd - b_j;
          while (temCPrO + 1 <= kEnd) {
            if (j->data[idx->data[p - 1] - 1] <= j->data[idx->data[q - 1] - 1])
            {
              iwork->data[temCPrO] = idx->data[p - 1];
              p++;
              if (p == nb) {
                while (q < qEnd) {
                  temCPrO++;
                  iwork->data[temCPrO] = idx->data[q - 1];
                  q++;
                }
              }
            } else {
              iwork->data[temCPrO] = idx->data[q - 1];
              q++;
              if (q == qEnd) {
                while (p < nb) {
                  temCPrO++;
                  iwork->data[temCPrO] = idx->data[p - 1];
                  p++;
                }
              }
            }

            temCPrO++;
          }

          for (temCPrO = 0; temCPrO < kEnd; temCPrO++) {
            idx->data[(b_j + temCPrO) - 1] = iwork->data[temCPrO];
          }

          b_j = qEnd;
        }

        nm1d2 = yk;
      }

      i53 = b_b->size[0] * b_b->size[1];
      b_b->size[0] = 1;
      b_b->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(b_b, i53);
      for (temCPrO = 0; temCPrO < na; temCPrO++) {
        b_b->data[temCPrO] = j->data[idx->data[temCPrO] - 1];
      }

      nb = -1;
      temCPrO = 0;
      while (temCPrO + 1 <= na) {
        nm1d2 = b_b->data[temCPrO];
        yk = temCPrO;
        do {
          temCPrO++;
        } while (!((temCPrO + 1 > na) || (b_b->data[temCPrO] != nm1d2)));

        nb++;
        b_b->data[nb] = nm1d2;
        idx->data[nb] = idx->data[yk];
      }

      i53 = iwork->size[0];
      iwork->size[0] = nb + 1;
      emxEnsureCapacity_int32_T(iwork, i53);
      for (temCPrO = 0; temCPrO <= nb; temCPrO++) {
        iwork->data[temCPrO] = idx->data[temCPrO];
      }

      i53 = uCPrODisp->size[0] * uCPrODisp->size[1];
      uCPrODisp->size[0] = 1;
      uCPrODisp->size[1] = iwork->size[0];
      emxEnsureCapacity_uint32_T(uCPrODisp, i53);
      qEnd = iwork->size[0];
      for (i53 = 0; i53 < qEnd; i53++) {
        uCPrODisp->data[i53] = (unsigned int)C->data[allC->data[iwork->data[i53]
          - 1] - 1];
      }

      if (NumRec[0] > 2147483646) {
        nm1d2 = MAX_int32_T;
      } else {
        nm1d2 = NumRec[0] + 1;
      }

      a = rt_roundd(e_sum(*(int (*)[2])&NumRec[0]));
      if (a < 2.147483648E+9) {
        if (a >= -2.147483648E+9) {
          i53 = (int)a;
        } else {
          i53 = MIN_int32_T;
        }
      } else {
        i53 = MAX_int32_T;
      }

      if (nm1d2 > i53) {
        i53 = -1;
      } else {
        i53 = nm1d2 - 2;
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los ME. */
      if (1 > PME->size[1] - 1) {
        qEnd = 0;
      } else {
        qEnd = PME->size[1] - 1;
      }

      kEnd = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, kEnd);
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        i54 = (long long)PME->data[kEnd] * DispME->data[kEnd];
        if (i54 > 2147483647LL) {
          i54 = 2147483647LL;
        } else {
          if (i54 < -2147483648LL) {
            i54 = -2147483648LL;
          }
        }

        x->data[kEnd] = ((int)i54 != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        yk = 0;
        kEnd = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, kEnd);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            yk++;
            j->data[yk - 1] = nm1d2;
            if (yk >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (yk == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > yk) {
          j->size[1] = 0;
        } else {
          kEnd = j->size[0] * j->size[1];
          j->size[1] = yk;
          emxEnsureCapacity_int32_T(j, kEnd);
        }
      }

      kEnd = C->size[0] * C->size[1];
      C->size[0] = 1;
      C->size[1] = j->size[1];
      emxEnsureCapacity_real_T(C, kEnd);
      qEnd = j->size[0] * j->size[1];
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        C->data[kEnd] = j->data[kEnd];
      }

      /*  Busco los posibles Especialistas a usar. */
      a = f_sum(*(int (*)[3])&NumRec[0]) + 1.0;
      b = h_sum(*(int (*)[4])&NumRec[0]);
      if (a > b) {
        kEnd = -1;
      } else {
        kEnd = (int)a - 2;
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los A. */
      if (1 > PMA->size[1] - 1) {
        qEnd = 0;
      } else {
        qEnd = PMA->size[1] - 1;
      }

      n = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, n);
      for (n = 0; n < qEnd; n++) {
        x->data[n] = (PMA->data[n] != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        yk = 0;
        n = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, n);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            yk++;
            j->data[yk - 1] = nm1d2;
            if (yk >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (yk == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > yk) {
          j->size[1] = 0;
        } else {
          n = j->size[0] * j->size[1];
          j->size[1] = yk;
          emxEnsureCapacity_int32_T(j, n);
        }
      }

      n = allA->size[0] * allA->size[1];
      allA->size[0] = 1;
      allA->size[1] = j->size[1];
      emxEnsureCapacity_int32_T(allA, n);
      qEnd = j->size[0] * j->size[1];
      for (n = 0; n < qEnd; n++) {
        allA->data[n] = j->data[n];
      }

      /*  Busco los posibles Asistentes a usar. */
      a = h_sum(*(int (*)[4])&NumRec[0]) + 1.0;
      b = i_sum(*(int (*)[5])&NumRec[0]);
      if (a > b) {
        n = -1;
      } else {
        n = (int)a - 2;
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los An. */
      if (1 > PMAn->size[1] - 1) {
        qEnd = 0;
      } else {
        qEnd = PMAn->size[1] - 1;
      }

      na = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, na);
      for (na = 0; na < qEnd; na++) {
        x->data[na] = (PMAn->data[na] != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        yk = 0;
        na = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, na);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            yk++;
            j->data[yk - 1] = nm1d2;
            if (yk >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (yk == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > yk) {
          j->size[1] = 0;
        } else {
          na = j->size[0] * j->size[1];
          j->size[1] = yk;
          emxEnsureCapacity_int32_T(j, na);
        }
      }

      na = allAn->size[0] * allAn->size[1];
      allAn->size[0] = 1;
      allAn->size[1] = j->size[1];
      emxEnsureCapacity_int32_T(allAn, na);
      qEnd = j->size[0] * j->size[1];
      for (na = 0; na < qEnd; na++) {
        allAn->data[na] = j->data[na];
      }

      /*  Busco los posibles Anestesistas a usar. */
      a = e_sum(*(int (*)[2])&NumRec[0]) + 1.0;
      b = f_sum(*(int (*)[3])&NumRec[0]);
      if (a > b) {
        na = -1;
      } else {
        na = (int)a - 2;
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
      if (1 > PS->size[1]) {
        qEnd = 0;
      } else {
        qEnd = PS->size[1];
      }

      p = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, p);
      for (p = 0; p < qEnd; p++) {
        x->data[p] = (PS->data[p] != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        yk = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            yk++;
            j->data[yk - 1] = nm1d2;
            if (yk >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (yk == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > yk) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = yk;
          emxEnsureCapacity_int32_T(j, p);
        }
      }

      p = allS->size[0] * allS->size[1];
      allS->size[0] = 1;
      allS->size[1] = j->size[1];
      emxEnsureCapacity_int32_T(allS, p);
      qEnd = j->size[0] * j->size[1];
      for (p = 0; p < qEnd; p++) {
        allS->data[p] = j->data[p];
      }

      /*  Busco los posibles Salones a usar. */
      /* auxUPxCPO = UltPosRecXDia(contDia,NumRec(1:5)+1:sum(NumRec(1:6)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los ME. */
      if (1 > PCPO->size[1]) {
        qEnd = 0;
      } else {
        qEnd = PCPO->size[1];
      }

      p = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, p);
      for (p = 0; p < qEnd; p++) {
        x->data[p] = (PCPO->data[p] != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        yk = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            yk++;
            j->data[yk - 1] = nm1d2;
            if (yk >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (yk == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > yk) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = yk;
          emxEnsureCapacity_int32_T(j, p);
        }
      }

      p = allCPO->size[0] * allCPO->size[1];
      allCPO->size[0] = 1;
      allCPO->size[1] = j->size[1];
      emxEnsureCapacity_int32_T(allCPO, p);
      qEnd = j->size[0] * j->size[1];
      for (p = 0; p < qEnd; p++) {
        allCPO->data[p] = j->data[p];
      }

      /*  Busco los posibles Especialistas a usar. */
      /* auxUPxCR = UltPosRecXDia(contDia,sum(NumRec(1:6))+1:sum(NumRec(1:7)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
      if (1 > PCR->size[1]) {
        qEnd = 0;
      } else {
        qEnd = PCR->size[1];
      }

      p = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, p);
      for (p = 0; p < qEnd; p++) {
        x->data[p] = (PCR->data[p] != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        yk = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            yk++;
            j->data[yk - 1] = nm1d2;
            if (yk >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (yk == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > yk) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = yk;
          emxEnsureCapacity_int32_T(j, p);
        }
      }

      p = allCR->size[0] * allCR->size[1];
      allCR->size[0] = 1;
      allCR->size[1] = j->size[1];
      emxEnsureCapacity_int32_T(allCR, p);
      qEnd = j->size[0] * j->size[1];
      for (p = 0; p < qEnd; p++) {
        allCR->data[p] = j->data[p];
      }

      /*  Busco los posibles Salones a usar. */
      temCPrO = -1;
      b_j = 0;
      do {
        exitg2 = 0;
        nm1d2 = iwork->size[0];
        if (b_j <= nm1d2 - 1) {
          nm1d2 = tempUltPosRecXDia->data[(int)uCPrODisp->data[b_j] - 1];
          if ((nm1d2 < 0) && (TimeUsoCPrO < MIN_int32_T - nm1d2)) {
            e_qY = MIN_int32_T;
          } else if ((nm1d2 > 0) && (TimeUsoCPrO > MAX_int32_T - nm1d2)) {
            e_qY = MAX_int32_T;
          } else {
            e_qY = nm1d2 + TimeUsoCPrO;
          }

          if ((e_qY < 0) && (TimeUsoS < MIN_int32_T - e_qY)) {
            f_qY = MIN_int32_T;
          } else if ((e_qY > 0) && (TimeUsoS > MAX_int32_T - e_qY)) {
            f_qY = MAX_int32_T;
          } else {
            f_qY = e_qY + TimeUsoS;
          }

          p = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = C->size[1];
          emxEnsureCapacity_boolean_T(x, p);
          qEnd = C->size[1];
          for (p = 0; p < qEnd; p++) {
            x->data[p] = (UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0]
              * (i53 + (int)C->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            yk = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                yk++;
                j->data[yk - 1] = nm1d2;
                if (yk >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (yk == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > yk) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = yk;
              emxEnsureCapacity_int32_T(j, p);
            }
          }

          p = E->size[0] * E->size[1];
          E->size[0] = 1;
          E->size[1] = j->size[1];
          emxEnsureCapacity_int32_T(E, p);
          qEnd = j->size[0] * j->size[1];
          for (p = 0; p < qEnd; p++) {
            E->data[p] = j->data[p];
          }

          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
          p = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = allA->size[1];
          emxEnsureCapacity_boolean_T(x, p);
          qEnd = allA->size[1];
          for (p = 0; p < qEnd; p++) {
            x->data[p] = (UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0]
              * (kEnd + allA->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            yk = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                yk++;
                j->data[yk - 1] = nm1d2;
                if (yk >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (yk == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > yk) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = yk;
              emxEnsureCapacity_int32_T(j, p);
            }
          }

          p = A->size[0] * A->size[1];
          A->size[0] = 1;
          A->size[1] = j->size[1];
          emxEnsureCapacity_int32_T(A, p);
          qEnd = j->size[0] * j->size[1];
          for (p = 0; p < qEnd; p++) {
            A->data[p] = j->data[p];
          }

          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
          p = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = allAn->size[1];
          emxEnsureCapacity_boolean_T(x, p);
          qEnd = allAn->size[1];
          for (p = 0; p < qEnd; p++) {
            x->data[p] = (UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0]
              * (n + allAn->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            yk = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                yk++;
                j->data[yk - 1] = nm1d2;
                if (yk >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (yk == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > yk) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = yk;
              emxEnsureCapacity_int32_T(j, p);
            }
          }

          p = An->size[0] * An->size[1];
          An->size[0] = 1;
          An->size[1] = j->size[1];
          emxEnsureCapacity_int32_T(An, p);
          qEnd = j->size[0] * j->size[1];
          for (p = 0; p < qEnd; p++) {
            An->data[p] = j->data[p];
          }

          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
          p = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = allS->size[1];
          emxEnsureCapacity_boolean_T(x, p);
          qEnd = allS->size[1];
          for (p = 0; p < qEnd; p++) {
            x->data[p] = (UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0]
              * (na + allS->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            yk = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                yk++;
                j->data[yk - 1] = nm1d2;
                if (yk >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (yk == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > yk) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = yk;
              emxEnsureCapacity_int32_T(j, p);
            }
          }

          p = S->size[0] * S->size[1];
          S->size[0] = 1;
          S->size[1] = j->size[1];
          emxEnsureCapacity_int32_T(S, p);
          qEnd = j->size[0] * j->size[1];
          for (p = 0; p < qEnd; p++) {
            S->data[p] = j->data[p];
          }

          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo.         */
          if (TimeUsoCPO == 0) {
            p = CPO->size[0] * CPO->size[1];
            CPO->size[0] = 1;
            CPO->size[1] = 1;
            emxEnsureCapacity_int32_T(CPO, p);
            CPO->data[0] = 0;
            nm1d2 = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
            if ((nm1d2 < 0) && (e_qY < MIN_int32_T - nm1d2)) {
              nm1d2 = MIN_int32_T;
            } else if ((nm1d2 > 0) && (e_qY > MAX_int32_T - nm1d2)) {
              nm1d2 = MAX_int32_T;
            } else {
              nm1d2 += e_qY;
            }

            if ((nm1d2 < 0) && (TimeUsoS < MIN_int32_T - nm1d2)) {
              nm1d2 = MIN_int32_T;
            } else if ((nm1d2 > 0) && (TimeUsoS > MAX_int32_T - nm1d2)) {
              nm1d2 = MAX_int32_T;
            } else {
              nm1d2 += TimeUsoS;
            }

            if ((nm1d2 < 0) && (TimeUsoCR < MIN_int32_T - nm1d2)) {
              q = MIN_int32_T;
            } else if ((nm1d2 > 0) && (TimeUsoCR > MAX_int32_T - nm1d2)) {
              q = MAX_int32_T;
            } else {
              q = nm1d2 + TimeUsoCR;
            }

            if (q < -2147483647) {
              q = MIN_int32_T;
            } else {
              q--;
            }

            if (nm1d2 > q) {
              p = 0;
              q = 0;
            } else {
              p = nm1d2 - 1;
            }

            a = j_sum(*(int (*)[6])&NumRec[0]);
            nb = b_H->size[0] * b_H->size[1];
            qEnd = q - p;
            b_H->size[0] = qEnd;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_real_T(b_H, nb);
            yk = allCR->size[1];
            for (nb = 0; nb < yk; nb++) {
              for (nm1d2 = 0; nm1d2 < qEnd; nm1d2++) {
                b_H->data[nm1d2 + b_H->size[0] * nb] = H->data[(p + nm1d2) +
                  H->size[0] * ((int)(a + (double)allCR->data[nb]) - 1)];
              }
            }

            m_sum(b_H, r12);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r12->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r12->size[0] * r12->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r12->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              yk = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  yk++;
                  j->data[yk - 1] = nm1d2;
                  if (yk >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (yk == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > yk) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = yk;
                emxEnsureCapacity_int32_T(j, p);
              }
            }

            p = CR->size[0] * CR->size[1];
            CR->size[0] = 1;
            CR->size[1] = j->size[1];
            emxEnsureCapacity_real_T(CR, p);
            qEnd = j->size[0] * j->size[1];
            for (p = 0; p < qEnd; p++) {
              CR->data[p] = j->data[p];
            }
          } else {
            nm1d2 = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
            if ((nm1d2 < 0) && (e_qY < MIN_int32_T - nm1d2)) {
              nm1d2 = MIN_int32_T;
            } else if ((nm1d2 > 0) && (e_qY > MAX_int32_T - nm1d2)) {
              nm1d2 = MAX_int32_T;
            } else {
              nm1d2 += e_qY;
            }

            if ((nm1d2 < 0) && (TimeUsoS < MIN_int32_T - nm1d2)) {
              nm1d2 = MIN_int32_T;
            } else if ((nm1d2 > 0) && (TimeUsoS > MAX_int32_T - nm1d2)) {
              nm1d2 = MAX_int32_T;
            } else {
              nm1d2 += TimeUsoS;
            }

            if ((nm1d2 < 0) && (TimeUsoCPO < MIN_int32_T - nm1d2)) {
              q = MIN_int32_T;
            } else if ((nm1d2 > 0) && (TimeUsoCPO > MAX_int32_T - nm1d2)) {
              q = MAX_int32_T;
            } else {
              q = nm1d2 + TimeUsoCPO;
            }

            if (q < -2147483647) {
              q = MIN_int32_T;
            } else {
              q--;
            }

            if (nm1d2 > q) {
              p = 0;
              nb = 0;
            } else {
              p = nm1d2 - 1;
              nb = q;
            }

            a = i_sum(*(int (*)[5])&NumRec[0]);
            nm1d2 = b_H->size[0] * b_H->size[1];
            qEnd = nb - p;
            b_H->size[0] = qEnd;
            b_H->size[1] = allCPO->size[1];
            emxEnsureCapacity_real_T(b_H, nm1d2);
            yk = allCPO->size[1];
            for (nb = 0; nb < yk; nb++) {
              for (nm1d2 = 0; nm1d2 < qEnd; nm1d2++) {
                b_H->data[nm1d2 + b_H->size[0] * nb] = H->data[(p + nm1d2) +
                  H->size[0] * ((int)(a + (double)allCPO->data[nb]) - 1)];
              }
            }

            m_sum(b_H, r12);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r12->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r12->size[0] * r12->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r12->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              yk = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  yk++;
                  j->data[yk - 1] = nm1d2;
                  if (yk >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (yk == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > yk) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = yk;
                emxEnsureCapacity_int32_T(j, p);
              }
            }

            p = CPO->size[0] * CPO->size[1];
            CPO->size[0] = 1;
            CPO->size[1] = j->size[1];
            emxEnsureCapacity_int32_T(CPO, p);
            qEnd = j->size[0] * j->size[1];
            for (p = 0; p < qEnd; p++) {
              CPO->data[p] = j->data[p];
            }

            /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
            a = j_sum(*(int (*)[6])&NumRec[0]);
            p = b_H->size[0] * b_H->size[1];
            b_H->size[0] = TimeUsoCR;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_real_T(b_H, p);
            qEnd = allCR->size[1];
            for (p = 0; p < qEnd; p++) {
              for (nb = 0; nb < TimeUsoCR; nb++) {
                yk = 1 + nb;
                if ((q < 0) && (yk < MIN_int32_T - q)) {
                  nm1d2 = MIN_int32_T;
                } else if ((q > 0) && (yk > MAX_int32_T - q)) {
                  nm1d2 = MAX_int32_T;
                } else {
                  nm1d2 = q + yk;
                }

                b_H->data[nb + b_H->size[0] * p] = H->data[(nm1d2 + H->size[0] *
                  ((int)(a + (double)allCR->data[p]) - 1)) - 1];
              }
            }

            m_sum(b_H, r12);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r12->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r12->size[0] * r12->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r12->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              yk = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  yk++;
                  j->data[yk - 1] = nm1d2;
                  if (yk >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (yk == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > yk) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = yk;
                emxEnsureCapacity_int32_T(j, p);
              }
            }

            p = CR->size[0] * CR->size[1];
            CR->size[0] = 1;
            CR->size[1] = j->size[1];
            emxEnsureCapacity_real_T(CR, p);
            qEnd = j->size[0] * j->size[1];
            for (p = 0; p < qEnd; p++) {
              CR->data[p] = j->data[p];
            }
          }

          if ((CPO->size[1] != 0) && (CR->size[1] != 0) && (S->size[1] != 0) &&
              (E->size[1] >= PME->data[PME->size[1] - 1]) && (A->size[1] >=
               PMA->data[PMA->size[1] - 1]) && (An->size[1] >= PMAn->data
               [PMAn->size[1] - 1])) {
            temCPrO = (int)uCPrODisp->data[b_j];
            exitg2 = 1;
          } else {
            b_j++;
          }
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      if (temCPrO == -1) {
        i53 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        kEnd = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        tempUltPosRecXDia->size[0] = 1;
        emxEnsureCapacity_int32_T(tempUltPosRecXDia, kEnd);
        qEnd = i53 - 1;
        for (i53 = 0; i53 <= qEnd; i53++) {
          nm1d2 = tempUltPosRecXDia->data[i53];
          if (nm1d2 > 2147483646) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2++;
          }

          tempUltPosRecXDia->data[i53] = nm1d2;
        }
      } else {
        b_CPrOA = temCPrO;
        nm1d2 = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
        yk = tempUltPosRecXDia->data[temCPrO - 1];
        if ((nm1d2 < 0) && (yk < MIN_int32_T - nm1d2)) {
          qY = MIN_int32_T;
        } else if ((nm1d2 > 0) && (yk > MAX_int32_T - nm1d2)) {
          qY = MAX_int32_T;
        } else {
          qY = nm1d2 + yk;
        }

        if ((qY < 0) && (TimeUsoCPrO < MIN_int32_T - qY)) {
          nm1d2 = MIN_int32_T;
        } else if ((qY > 0) && (TimeUsoCPrO > MAX_int32_T - qY)) {
          nm1d2 = MAX_int32_T;
        } else {
          nm1d2 = qY + TimeUsoCPrO;
        }

        if (nm1d2 < -2147483647) {
          b_qY = MIN_int32_T;
        } else {
          b_qY = nm1d2 - 1;
        }

        i53 = SA->size[0] * SA->size[1];
        SA->size[0] = 1;
        SA->size[1] = 1;
        emxEnsureCapacity_int32_T(SA, i53);
        SA->data[0] = allS->data[S->data[0] - 1];
        b_IniSA = b_qY + 1;
        nm1d2 = b_qY + 1;
        if ((nm1d2 < 0) && (TimeUsoS < MIN_int32_T - nm1d2)) {
          nm1d2 = MIN_int32_T;
        } else if ((nm1d2 > 0) && (TimeUsoS > MAX_int32_T - nm1d2)) {
          nm1d2 = MAX_int32_T;
        } else {
          nm1d2 += TimeUsoS;
        }

        if (nm1d2 < -2147483647) {
          nm1d2 = MIN_int32_T;
        } else {
          nm1d2--;
        }

        b_EndSA = nm1d2 + 1;
        if (1 > PME->data[PME->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PME->data[PME->size[1] - 1];
        }

        i53 = EA->size[0] * EA->size[1];
        EA->size[0] = 1;
        EA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(EA, i53);
        for (i53 = 0; i53 < qEnd; i53++) {
          EA->data[i53] = (int)C->data[E->data[i53] - 1];
        }

        if (1 > PMA->data[PMA->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMA->data[PMA->size[1] - 1];
        }

        i53 = AA->size[0] * AA->size[1];
        AA->size[0] = 1;
        AA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AA, i53);
        for (i53 = 0; i53 < qEnd; i53++) {
          AA->data[i53] = allA->data[A->data[i53] - 1];
        }

        if (1 > PMAn->data[PMAn->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMAn->data[PMAn->size[1] - 1];
        }

        i53 = AnA->size[0] * AnA->size[1];
        AnA->size[0] = 1;
        AnA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AnA, i53);
        for (i53 = 0; i53 < qEnd; i53++) {
          AnA->data[i53] = allAn->data[An->data[i53] - 1];
        }

        if (TimeUsoCPO == 0) {
          b_CPOA = 0;
          b_IniCPOA = 0;
          c_qY = 0;
          b_CRA = allCR->data[(int)CR->data[0] - 1];
          b_IniCRA = b_EndSA;
          if ((b_EndSA < 0) && (TimeUsoCR < MIN_int32_T - b_EndSA)) {
            nm1d2 = MIN_int32_T;
          } else if ((b_EndSA > 0) && (TimeUsoCR > MAX_int32_T - b_EndSA)) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2 = b_EndSA + TimeUsoCR;
          }

          if (nm1d2 < -2147483647) {
            d_qY = MIN_int32_T;
          } else {
            d_qY = nm1d2 - 1;
          }
        } else {
          b_CPOA = allCPO->data[CPO->data[0] - 1];
          b_IniCPOA = b_EndSA;
          if ((b_EndSA < 0) && (TimeUsoCPO < MIN_int32_T - b_EndSA)) {
            nm1d2 = MIN_int32_T;
          } else if ((b_EndSA > 0) && (TimeUsoCPO > MAX_int32_T - b_EndSA)) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2 = b_EndSA + TimeUsoCPO;
          }

          if (nm1d2 < -2147483647) {
            c_qY = MIN_int32_T;
          } else {
            c_qY = nm1d2 - 1;
          }

          b_CRA = allCR->data[(int)CR->data[0] - 1];
          b_IniCRA = c_qY + 1;
          nm1d2 = c_qY + 1;
          if ((nm1d2 < 0) && (TimeUsoCR < MIN_int32_T - nm1d2)) {
            nm1d2 = MIN_int32_T;
          } else if ((nm1d2 > 0) && (TimeUsoCR > MAX_int32_T - nm1d2)) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2 += TimeUsoCR;
          }

          if (nm1d2 < -2147483647) {
            d_qY = MIN_int32_T;
          } else {
            d_qY = nm1d2 - 1;
          }
        }

        flag = false;
      }
    }
  }

  emxFree_real_T(&b_H);
  emxFree_int32_T(&iwork);
  emxFree_int32_T(&idx);
  emxFree_int32_T(&b_b);
  emxFree_int32_T(&j);
  emxFree_boolean_T(&x);
  emxFree_real_T(&r12);
  emxFree_int32_T(&allCR);
  emxFree_int32_T(&allCPO);
  emxFree_int32_T(&allS);
  emxFree_int32_T(&allAn);
  emxFree_int32_T(&allA);
  emxFree_int32_T(&allC);
  emxFree_real_T(&C);
  emxFree_uint32_T(&uCPrODisp);
  emxFree_real_T(&CR);
  emxFree_int32_T(&CPO);
  emxFree_int32_T(&An);
  emxFree_int32_T(&A);
  emxFree_int32_T(&S);
  emxFree_int32_T(&E);
  *CPrOA = b_CPrOA;
  *IniCPrOA = qY;
  *EndCPrOA = b_qY;
  *EndCPrOAxD = e_qY;
  *IniSA = b_IniSA;
  *EndSA = b_EndSA - 1;
  *EndRPxD = f_qY;
  *CPOA = b_CPOA;
  *IniCPOA = b_IniCPOA;
  *EndCPOA = c_qY;
  *CRA = b_CRA;
  *IniCRA = b_IniCRA;
  *EndCRA = d_qY;
}

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
  int yk;
  int nm1d2;
  int n;
  unsigned int nm1;
  emxArray_int32_T *j;
  int i47;
  emxArray_int32_T *E;
  int temCPrO;
  int qEnd;
  double a;
  double b;
  emxArray_real_T *r10;
  double ndbl;
  double apnd;
  double cdiff;
  emxArray_int32_T *S;
  emxArray_real_T *C;
  emxArray_int32_T *A;
  emxArray_real_T *CR;
  emxArray_int32_T *An;
  emxArray_int32_T *CPO;
  int kEnd;
  int b_CPrOA;
  int b_CPOA;
  int b_CRA;
  int qY;
  int b_qY;
  int b_IniSA;
  int b_EndSA;
  int b_IniCPOA;
  int c_qY;
  int b_IniCRA;
  int d_qY;
  int e_qY;
  int f_qY;
  boolean_T flag;
  emxArray_uint32_T *uCPrODisp;
  emxArray_int32_T *allC;
  emxArray_int32_T *allA;
  emxArray_int32_T *allAn;
  emxArray_int32_T *allS;
  emxArray_int32_T *allCPO;
  emxArray_int32_T *allCR;
  emxArray_boolean_T *x;
  emxArray_int32_T *b_b;
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  emxArray_int32_T *b_H;
  boolean_T exitg1;
  int q;
  int na;
  int b_j;
  int nb;
  int p;
  long long i48;
  int exitg2;
  if (NumRec[0] > 2147483646) {
    yk = MAX_int32_T;
  } else {
    yk = NumRec[0] + 1;
  }

  nm1d2 = (int)e_sum(*(int (*)[2])&NumRec[0]);
  if (nm1d2 < yk) {
    n = 0;
  } else {
    if ((yk < 0) && (nm1d2 >= 0)) {
      nm1 = (unsigned int)nm1d2 - yk;
    } else {
      nm1 = (unsigned int)(nm1d2 - yk);
    }

    n = (int)nm1 + 1;
  }

  emxInit_int32_T(&j, 2);
  i47 = j->size[0] * j->size[1];
  j->size[0] = 1;
  j->size[1] = n;
  emxEnsureCapacity_int32_T(j, i47);
  if (n > 0) {
    j->data[0] = yk;
    for (temCPrO = 2; temCPrO <= n; temCPrO++) {
      yk++;
      j->data[temCPrO - 1] = yk;
    }
  }

  emxInit_int32_T(&E, 2);
  if (j->size[1] < 1) {
    E->size[0] = 1;
    E->size[1] = 0;
  } else {
    qEnd = j->size[1];
    i47 = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = qEnd;
    emxEnsureCapacity_int32_T(E, i47);
    for (i47 = 0; i47 < qEnd; i47++) {
      E->data[i47] = 1 + i47;
    }
  }

  a = e_sum(*(int (*)[2])&NumRec[0]) + 1.0;
  b = f_sum(*(int (*)[3])&NumRec[0]);
  emxInit_real_T(&r10, 2);
  if (b < a) {
    i47 = r10->size[0] * r10->size[1];
    r10->size[1] = 0;
    emxEnsureCapacity_real_T(r10, i47);
  } else if (floor(a) == a) {
    i47 = r10->size[0] * r10->size[1];
    r10->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(r10, i47);
  } else {
    ndbl = floor((b - a) + 0.5);
    apnd = a + ndbl;
    cdiff = apnd - b;
    if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(a), fabs(b))) {
      ndbl++;
      apnd = b;
    } else if (cdiff > 0.0) {
      apnd = a + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }

    i47 = r10->size[0] * r10->size[1];
    r10->size[0] = 1;
    r10->size[1] = n;
    emxEnsureCapacity_real_T(r10, i47);
    if ((n > 0) && (n > 1)) {
      r10->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (temCPrO = 0; temCPrO <= nm1d2 - 2; temCPrO++) {
        r10->data[1 + temCPrO] = a + (1.0 + (double)temCPrO);
        r10->data[(n - temCPrO) - 2] = apnd - (1.0 + (double)temCPrO);
      }

      if (nm1d2 << 1 == n - 1) {
        r10->data[nm1d2] = (a + apnd) / 2.0;
      } else {
        r10->data[nm1d2] = a + (double)nm1d2;
        r10->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_int32_T(&S, 2);
  if (r10->size[1] < 1) {
    S->size[0] = 1;
    S->size[1] = 0;
  } else {
    qEnd = r10->size[1];
    i47 = S->size[0] * S->size[1];
    S->size[0] = 1;
    S->size[1] = qEnd;
    emxEnsureCapacity_int32_T(S, i47);
    for (i47 = 0; i47 < qEnd; i47++) {
      S->data[i47] = 1 + i47;
    }
  }

  a = f_sum(*(int (*)[3])&NumRec[0]) + 1.0;
  b = h_sum(*(int (*)[4])&NumRec[0]);
  emxInit_real_T(&C, 2);
  if (b < a) {
    i47 = C->size[0] * C->size[1];
    C->size[1] = 0;
    emxEnsureCapacity_real_T(C, i47);
  } else if (floor(a) == a) {
    i47 = C->size[0] * C->size[1];
    C->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(C, i47);
  } else {
    ndbl = floor((b - a) + 0.5);
    apnd = a + ndbl;
    cdiff = apnd - b;
    if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(a), fabs(b))) {
      ndbl++;
      apnd = b;
    } else if (cdiff > 0.0) {
      apnd = a + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }

    i47 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = n;
    emxEnsureCapacity_real_T(C, i47);
    if (n > 0) {
      C->data[0] = a;
      if (n > 1) {
        C->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (temCPrO = 0; temCPrO <= nm1d2 - 2; temCPrO++) {
          C->data[1 + temCPrO] = a + (1.0 + (double)temCPrO);
          C->data[(n - temCPrO) - 2] = apnd - (1.0 + (double)temCPrO);
        }

        if (nm1d2 << 1 == n - 1) {
          C->data[nm1d2] = (a + apnd) / 2.0;
        } else {
          C->data[nm1d2] = a + (double)nm1d2;
          C->data[nm1d2 + 1] = apnd - (double)nm1d2;
        }
      }
    }
  }

  emxInit_int32_T(&A, 2);
  if (C->size[1] < 1) {
    A->size[0] = 1;
    A->size[1] = 0;
  } else {
    qEnd = C->size[1];
    i47 = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = qEnd;
    emxEnsureCapacity_int32_T(A, i47);
    for (i47 = 0; i47 < qEnd; i47++) {
      A->data[i47] = 1 + i47;
    }
  }

  a = h_sum(*(int (*)[4])&NumRec[0]) + 1.0;
  b = i_sum(*(int (*)[5])&NumRec[0]);
  emxInit_real_T(&CR, 2);
  if (b < a) {
    i47 = CR->size[0] * CR->size[1];
    CR->size[1] = 0;
    emxEnsureCapacity_real_T(CR, i47);
  } else if (floor(a) == a) {
    i47 = CR->size[0] * CR->size[1];
    CR->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(CR, i47);
  } else {
    ndbl = floor((b - a) + 0.5);
    apnd = a + ndbl;
    cdiff = apnd - b;
    if (fabs(cdiff) < 4.4408920985006262E-16 * fmax(fabs(a), fabs(b))) {
      ndbl++;
      apnd = b;
    } else if (cdiff > 0.0) {
      apnd = a + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }

    i47 = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    CR->size[1] = n;
    emxEnsureCapacity_real_T(CR, i47);
    if (n > 0) {
      CR->data[0] = a;
      if (n > 1) {
        CR->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (temCPrO = 0; temCPrO <= nm1d2 - 2; temCPrO++) {
          CR->data[1 + temCPrO] = a + (1.0 + (double)temCPrO);
          CR->data[(n - temCPrO) - 2] = apnd - (1.0 + (double)temCPrO);
        }

        if (nm1d2 << 1 == n - 1) {
          CR->data[nm1d2] = (a + apnd) / 2.0;
        } else {
          CR->data[nm1d2] = a + (double)nm1d2;
          CR->data[nm1d2 + 1] = apnd - (double)nm1d2;
        }
      }
    }
  }

  emxInit_int32_T(&An, 2);
  if (CR->size[1] < 1) {
    An->size[0] = 1;
    An->size[1] = 0;
  } else {
    qEnd = CR->size[1];
    i47 = An->size[0] * An->size[1];
    An->size[0] = 1;
    An->size[1] = qEnd;
    emxEnsureCapacity_int32_T(An, i47);
    for (i47 = 0; i47 < qEnd; i47++) {
      An->data[i47] = 1 + i47;
    }
  }

  emxInit_int32_T(&CPO, 2);
  if (PCPO->size[1] < 1) {
    CPO->size[0] = 1;
    CPO->size[1] = 0;
  } else {
    qEnd = PCPO->size[1];
    i47 = CPO->size[0] * CPO->size[1];
    CPO->size[0] = 1;
    CPO->size[1] = qEnd;
    emxEnsureCapacity_int32_T(CPO, i47);
    for (i47 = 0; i47 < qEnd; i47++) {
      CPO->data[i47] = 1 + i47;
    }
  }

  if (PCR->size[1] < 1) {
    CR->size[0] = 1;
    CR->size[1] = 0;
  } else {
    i47 = PCR->size[1];
    kEnd = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    qEnd = (int)((double)i47 - 1.0);
    CR->size[1] = qEnd + 1;
    emxEnsureCapacity_real_T(CR, kEnd);
    for (i47 = 0; i47 <= qEnd; i47++) {
      CR->data[i47] = 1.0 + (double)i47;
    }
  }

  b_CPrOA = 0;
  b_CPOA = 0;
  b_CRA = 0;
  qY = 0;
  b_qY = 0;
  b_IniSA = 0;
  b_EndSA = 1;
  b_IniCPOA = 0;
  c_qY = 0;
  b_IniCRA = 0;
  d_qY = 0;
  e_qY = 0;
  f_qY = 0;
  if (PME->size[1] - 1 < 1) {
    EA->size[0] = 1;
    EA->size[1] = 0;
  } else {
    qEnd = PME->size[1] - 2;
    i47 = EA->size[0] * EA->size[1];
    EA->size[0] = 1;
    EA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(EA, i47);
    for (i47 = 0; i47 <= qEnd; i47++) {
      EA->data[i47] = 1 + i47;
    }
  }

  if (PMA->size[1] - 1 < 1) {
    AA->size[0] = 1;
    AA->size[1] = 0;
  } else {
    qEnd = PMA->size[1] - 2;
    i47 = AA->size[0] * AA->size[1];
    AA->size[0] = 1;
    AA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AA, i47);
    for (i47 = 0; i47 <= qEnd; i47++) {
      AA->data[i47] = 1 + i47;
    }
  }

  if (PMAn->size[1] - 1 < 1) {
    AnA->size[0] = 1;
    AnA->size[1] = 0;
  } else {
    qEnd = PMAn->size[1] - 2;
    i47 = AnA->size[0] * AnA->size[1];
    AnA->size[0] = 1;
    AnA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AnA, i47);
    for (i47 = 0; i47 <= qEnd; i47++) {
      AnA->data[i47] = 1 + i47;
    }
  }

  if (PS->size[1] - 1 < 1) {
    SA->size[0] = 1;
    SA->size[1] = 0;
  } else {
    qEnd = PS->size[1] - 2;
    i47 = SA->size[0] * SA->size[1];
    SA->size[0] = 1;
    SA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(SA, i47);
    for (i47 = 0; i47 <= qEnd; i47++) {
      SA->data[i47] = 1 + i47;
    }
  }

  flag = true;
  emxInit_uint32_T(&uCPrODisp, 2);
  emxInit_int32_T(&allC, 2);
  emxInit_int32_T(&allA, 2);
  emxInit_int32_T(&allAn, 2);
  emxInit_int32_T(&allS, 2);
  emxInit_int32_T(&allCPO, 2);
  emxInit_int32_T(&allCR, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&b_b, 2);
  emxInit_int32_T(&idx, 2);
  emxInit_int32_T(&iwork, 1);
  emxInit_int32_T(&b_H, 2);
  while (flag) {
    /*  Selecciono los ultimas posiciones a partir de donde se pueden usar las camas. */
    i47 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = PCPrO->size[1];
    emxEnsureCapacity_boolean_T(x, i47);
    qEnd = PCPrO->size[0] * PCPrO->size[1];
    for (i47 = 0; i47 < qEnd; i47++) {
      x->data[i47] = (PCPrO->data[i47] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      yk = 0;
      i47 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i47);
      nm1d2 = 1;
      exitg1 = false;
      while ((!exitg1) && (nm1d2 <= x->size[1])) {
        if (x->data[nm1d2 - 1]) {
          yk++;
          j->data[yk - 1] = nm1d2;
          if (yk >= x->size[1]) {
            exitg1 = true;
          } else {
            nm1d2++;
          }
        } else {
          nm1d2++;
        }
      }

      if (x->size[1] == 1) {
        if (yk == 0) {
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > yk) {
        j->size[1] = 0;
      } else {
        i47 = j->size[0] * j->size[1];
        j->size[1] = yk;
        emxEnsureCapacity_int32_T(j, i47);
      }
    }

    i47 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = j->size[1];
    emxEnsureCapacity_real_T(C, i47);
    qEnd = j->size[0] * j->size[1];
    for (i47 = 0; i47 < qEnd; i47++) {
      C->data[i47] = j->data[i47];
    }

    /*  Busco las posibles camas a usar. */
    nm1d2 = Dia->data[(*contDia + Dia->size[0] * 3) - 1];
    yk = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
    if ((nm1d2 >= 0) && (yk < nm1d2 - MAX_int32_T)) {
      nm1d2 = MAX_int32_T;
    } else if ((nm1d2 < 0) && (yk > nm1d2 - MIN_int32_T)) {
      nm1d2 = MIN_int32_T;
    } else {
      nm1d2 -= yk;
    }

    if (nm1d2 > 2147483646) {
      nm1d2 = MAX_int32_T;
    } else {
      nm1d2++;
    }

    if ((TimeUsoCPrO < 0) && (TimeUsoS < MIN_int32_T - TimeUsoCPrO)) {
      q = MIN_int32_T;
    } else if ((TimeUsoCPrO > 0) && (TimeUsoS > MAX_int32_T - TimeUsoCPrO)) {
      q = MAX_int32_T;
    } else {
      q = TimeUsoCPrO + TimeUsoS;
    }

    if ((nm1d2 >= 0) && (q < nm1d2 - MAX_int32_T)) {
      nm1d2 = MAX_int32_T;
    } else if ((nm1d2 < 0) && (q > nm1d2 - MIN_int32_T)) {
      nm1d2 = MIN_int32_T;
    } else {
      nm1d2 -= q;
    }

    /*  Posicion maxima a partir de la cual se puede colocar la Operacion. */
    i47 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = C->size[1];
    emxEnsureCapacity_boolean_T(x, i47);
    qEnd = C->size[0] * C->size[1];
    for (i47 = 0; i47 < qEnd; i47++) {
      x->data[i47] = (tempUltPosRecXDia->data[(int)C->data[i47] - 1] <= nm1d2);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      yk = 0;
      i47 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i47);
      nm1d2 = 1;
      exitg1 = false;
      while ((!exitg1) && (nm1d2 <= x->size[1])) {
        if (x->data[nm1d2 - 1]) {
          yk++;
          j->data[yk - 1] = nm1d2;
          if (yk >= x->size[1]) {
            exitg1 = true;
          } else {
            nm1d2++;
          }
        } else {
          nm1d2++;
        }
      }

      if (x->size[1] == 1) {
        if (yk == 0) {
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > yk) {
        j->size[1] = 0;
      } else {
        i47 = j->size[0] * j->size[1];
        j->size[1] = yk;
        emxEnsureCapacity_int32_T(j, i47);
      }
    }

    i47 = allC->size[0] * allC->size[1];
    allC->size[0] = 1;
    allC->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(allC, i47);
    qEnd = j->size[0] * j->size[1];
    for (i47 = 0; i47 < qEnd; i47++) {
      allC->data[i47] = j->data[i47];
    }

    /*  Veo en cuales es posible asignar la operacion. */
    if (allC->size[1] == 0) {
      /*  Si no es posible asignar ninguna cama incremento el contDia e llamo a funcionDia */
      nm1d2 = *contDia;
      if (nm1d2 > 2147483646) {
        *contDia = MAX_int32_T;
      } else {
        *contDia = nm1d2 + 1;
      }

      funcionDia(NumRec, PCPrO, Dia, UltPosRecXDia, TimeUsoCPrO, TimeUsoS,
                 contDia, DispMExD, tempUltPosRecXDia, DispME);
    } else {
      i47 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(j, i47);
      qEnd = allC->size[0] * allC->size[1];
      for (i47 = 0; i47 < qEnd; i47++) {
        j->data[i47] = tempUltPosRecXDia->data[(int)(unsigned int)C->data
          [allC->data[i47] - 1] - 1];
      }

      na = allC->size[1];
      n = allC->size[1] + 1;
      i47 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(idx, i47);
      qEnd = allC->size[1];
      for (i47 = 0; i47 < qEnd; i47++) {
        idx->data[i47] = 0;
      }

      i47 = iwork->size[0];
      iwork->size[0] = allC->size[1];
      emxEnsureCapacity_int32_T(iwork, i47);
      i47 = allC->size[1] - 1;
      for (temCPrO = 1; temCPrO <= i47; temCPrO += 2) {
        if (j->data[temCPrO - 1] <= j->data[temCPrO]) {
          idx->data[temCPrO - 1] = temCPrO;
          idx->data[temCPrO] = temCPrO + 1;
        } else {
          idx->data[temCPrO - 1] = temCPrO + 1;
          idx->data[temCPrO] = temCPrO;
        }
      }

      if ((allC->size[1] & 1) != 0) {
        idx->data[allC->size[1] - 1] = allC->size[1];
      }

      nm1d2 = 2;
      while (nm1d2 < n - 1) {
        yk = nm1d2 << 1;
        b_j = 1;
        for (nb = 1 + nm1d2; nb < n; nb = qEnd + nm1d2) {
          p = b_j;
          q = nb;
          qEnd = b_j + yk;
          if (qEnd > n) {
            qEnd = n;
          }

          temCPrO = 0;
          kEnd = qEnd - b_j;
          while (temCPrO + 1 <= kEnd) {
            if (j->data[idx->data[p - 1] - 1] <= j->data[idx->data[q - 1] - 1])
            {
              iwork->data[temCPrO] = idx->data[p - 1];
              p++;
              if (p == nb) {
                while (q < qEnd) {
                  temCPrO++;
                  iwork->data[temCPrO] = idx->data[q - 1];
                  q++;
                }
              }
            } else {
              iwork->data[temCPrO] = idx->data[q - 1];
              q++;
              if (q == qEnd) {
                while (p < nb) {
                  temCPrO++;
                  iwork->data[temCPrO] = idx->data[p - 1];
                  p++;
                }
              }
            }

            temCPrO++;
          }

          for (temCPrO = 0; temCPrO < kEnd; temCPrO++) {
            idx->data[(b_j + temCPrO) - 1] = iwork->data[temCPrO];
          }

          b_j = qEnd;
        }

        nm1d2 = yk;
      }

      i47 = b_b->size[0] * b_b->size[1];
      b_b->size[0] = 1;
      b_b->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(b_b, i47);
      for (temCPrO = 0; temCPrO < na; temCPrO++) {
        b_b->data[temCPrO] = j->data[idx->data[temCPrO] - 1];
      }

      nb = -1;
      temCPrO = 0;
      while (temCPrO + 1 <= na) {
        nm1d2 = b_b->data[temCPrO];
        yk = temCPrO;
        do {
          temCPrO++;
        } while (!((temCPrO + 1 > na) || (b_b->data[temCPrO] != nm1d2)));

        nb++;
        b_b->data[nb] = nm1d2;
        idx->data[nb] = idx->data[yk];
      }

      i47 = iwork->size[0];
      iwork->size[0] = nb + 1;
      emxEnsureCapacity_int32_T(iwork, i47);
      for (temCPrO = 0; temCPrO <= nb; temCPrO++) {
        iwork->data[temCPrO] = idx->data[temCPrO];
      }

      i47 = uCPrODisp->size[0] * uCPrODisp->size[1];
      uCPrODisp->size[0] = 1;
      uCPrODisp->size[1] = iwork->size[0];
      emxEnsureCapacity_uint32_T(uCPrODisp, i47);
      qEnd = iwork->size[0];
      for (i47 = 0; i47 < qEnd; i47++) {
        uCPrODisp->data[i47] = (unsigned int)C->data[allC->data[iwork->data[i47]
          - 1] - 1];
      }

      if (NumRec[0] > 2147483646) {
        nm1d2 = MAX_int32_T;
      } else {
        nm1d2 = NumRec[0] + 1;
      }

      a = rt_roundd(e_sum(*(int (*)[2])&NumRec[0]));
      if (a < 2.147483648E+9) {
        if (a >= -2.147483648E+9) {
          i47 = (int)a;
        } else {
          i47 = MIN_int32_T;
        }
      } else {
        i47 = MAX_int32_T;
      }

      if (nm1d2 > i47) {
        i47 = -1;
      } else {
        i47 = nm1d2 - 2;
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los ME. */
      if (1 > PME->size[1] - 1) {
        qEnd = 0;
      } else {
        qEnd = PME->size[1] - 1;
      }

      kEnd = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, kEnd);
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        i48 = (long long)PME->data[kEnd] * DispME->data[kEnd];
        if (i48 > 2147483647LL) {
          i48 = 2147483647LL;
        } else {
          if (i48 < -2147483648LL) {
            i48 = -2147483648LL;
          }
        }

        x->data[kEnd] = ((int)i48 != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        yk = 0;
        kEnd = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, kEnd);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            yk++;
            j->data[yk - 1] = nm1d2;
            if (yk >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (yk == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > yk) {
          j->size[1] = 0;
        } else {
          kEnd = j->size[0] * j->size[1];
          j->size[1] = yk;
          emxEnsureCapacity_int32_T(j, kEnd);
        }
      }

      kEnd = C->size[0] * C->size[1];
      C->size[0] = 1;
      C->size[1] = j->size[1];
      emxEnsureCapacity_real_T(C, kEnd);
      qEnd = j->size[0] * j->size[1];
      for (kEnd = 0; kEnd < qEnd; kEnd++) {
        C->data[kEnd] = j->data[kEnd];
      }

      /*  Busco los posibles Especialistas a usar. */
      a = f_sum(*(int (*)[3])&NumRec[0]) + 1.0;
      b = h_sum(*(int (*)[4])&NumRec[0]);
      if (a > b) {
        kEnd = -1;
      } else {
        kEnd = (int)a - 2;
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los A. */
      if (1 > PMA->size[1] - 1) {
        qEnd = 0;
      } else {
        qEnd = PMA->size[1] - 1;
      }

      n = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, n);
      for (n = 0; n < qEnd; n++) {
        x->data[n] = (PMA->data[n] != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        yk = 0;
        n = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, n);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            yk++;
            j->data[yk - 1] = nm1d2;
            if (yk >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (yk == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > yk) {
          j->size[1] = 0;
        } else {
          n = j->size[0] * j->size[1];
          j->size[1] = yk;
          emxEnsureCapacity_int32_T(j, n);
        }
      }

      n = allA->size[0] * allA->size[1];
      allA->size[0] = 1;
      allA->size[1] = j->size[1];
      emxEnsureCapacity_int32_T(allA, n);
      qEnd = j->size[0] * j->size[1];
      for (n = 0; n < qEnd; n++) {
        allA->data[n] = j->data[n];
      }

      /*  Busco los posibles Asistentes a usar. */
      a = h_sum(*(int (*)[4])&NumRec[0]) + 1.0;
      b = i_sum(*(int (*)[5])&NumRec[0]);
      if (a > b) {
        n = -1;
      } else {
        n = (int)a - 2;
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los An. */
      if (1 > PMAn->size[1] - 1) {
        qEnd = 0;
      } else {
        qEnd = PMAn->size[1] - 1;
      }

      na = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, na);
      for (na = 0; na < qEnd; na++) {
        x->data[na] = (PMAn->data[na] != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        yk = 0;
        na = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, na);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            yk++;
            j->data[yk - 1] = nm1d2;
            if (yk >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (yk == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > yk) {
          j->size[1] = 0;
        } else {
          na = j->size[0] * j->size[1];
          j->size[1] = yk;
          emxEnsureCapacity_int32_T(j, na);
        }
      }

      na = allAn->size[0] * allAn->size[1];
      allAn->size[0] = 1;
      allAn->size[1] = j->size[1];
      emxEnsureCapacity_int32_T(allAn, na);
      qEnd = j->size[0] * j->size[1];
      for (na = 0; na < qEnd; na++) {
        allAn->data[na] = j->data[na];
      }

      /*  Busco los posibles Anestesistas a usar. */
      a = e_sum(*(int (*)[2])&NumRec[0]) + 1.0;
      b = f_sum(*(int (*)[3])&NumRec[0]);
      if (a > b) {
        na = -1;
      } else {
        na = (int)a - 2;
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
      if (1 > PS->size[1]) {
        qEnd = 0;
      } else {
        qEnd = PS->size[1];
      }

      p = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, p);
      for (p = 0; p < qEnd; p++) {
        x->data[p] = (PS->data[p] != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        yk = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            yk++;
            j->data[yk - 1] = nm1d2;
            if (yk >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (yk == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > yk) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = yk;
          emxEnsureCapacity_int32_T(j, p);
        }
      }

      p = allS->size[0] * allS->size[1];
      allS->size[0] = 1;
      allS->size[1] = j->size[1];
      emxEnsureCapacity_int32_T(allS, p);
      qEnd = j->size[0] * j->size[1];
      for (p = 0; p < qEnd; p++) {
        allS->data[p] = j->data[p];
      }

      /*  Busco los posibles Salones a usar. */
      /* auxUPxCPO = UltPosRecXDia(contDia,NumRec(1:5)+1:sum(NumRec(1:6)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los ME. */
      if (1 > PCPO->size[1]) {
        qEnd = 0;
      } else {
        qEnd = PCPO->size[1];
      }

      p = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, p);
      for (p = 0; p < qEnd; p++) {
        x->data[p] = (PCPO->data[p] != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        yk = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            yk++;
            j->data[yk - 1] = nm1d2;
            if (yk >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (yk == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > yk) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = yk;
          emxEnsureCapacity_int32_T(j, p);
        }
      }

      p = allCPO->size[0] * allCPO->size[1];
      allCPO->size[0] = 1;
      allCPO->size[1] = j->size[1];
      emxEnsureCapacity_int32_T(allCPO, p);
      qEnd = j->size[0] * j->size[1];
      for (p = 0; p < qEnd; p++) {
        allCPO->data[p] = j->data[p];
      }

      /*  Busco los posibles Especialistas a usar. */
      /* auxUPxCR = UltPosRecXDia(contDia,sum(NumRec(1:6))+1:sum(NumRec(1:7)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
      if (1 > PCR->size[1]) {
        qEnd = 0;
      } else {
        qEnd = PCR->size[1];
      }

      p = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, p);
      for (p = 0; p < qEnd; p++) {
        x->data[p] = (PCR->data[p] != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        yk = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            yk++;
            j->data[yk - 1] = nm1d2;
            if (yk >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (yk == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > yk) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = yk;
          emxEnsureCapacity_int32_T(j, p);
        }
      }

      p = allCR->size[0] * allCR->size[1];
      allCR->size[0] = 1;
      allCR->size[1] = j->size[1];
      emxEnsureCapacity_int32_T(allCR, p);
      qEnd = j->size[0] * j->size[1];
      for (p = 0; p < qEnd; p++) {
        allCR->data[p] = j->data[p];
      }

      /*  Busco los posibles Salones a usar. */
      temCPrO = -1;
      b_j = 0;
      do {
        exitg2 = 0;
        nm1d2 = iwork->size[0];
        if (b_j <= nm1d2 - 1) {
          nm1d2 = tempUltPosRecXDia->data[(int)uCPrODisp->data[b_j] - 1];
          if ((nm1d2 < 0) && (TimeUsoCPrO < MIN_int32_T - nm1d2)) {
            e_qY = MIN_int32_T;
          } else if ((nm1d2 > 0) && (TimeUsoCPrO > MAX_int32_T - nm1d2)) {
            e_qY = MAX_int32_T;
          } else {
            e_qY = nm1d2 + TimeUsoCPrO;
          }

          if ((e_qY < 0) && (TimeUsoS < MIN_int32_T - e_qY)) {
            f_qY = MIN_int32_T;
          } else if ((e_qY > 0) && (TimeUsoS > MAX_int32_T - e_qY)) {
            f_qY = MAX_int32_T;
          } else {
            f_qY = e_qY + TimeUsoS;
          }

          p = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = C->size[1];
          emxEnsureCapacity_boolean_T(x, p);
          qEnd = C->size[1];
          for (p = 0; p < qEnd; p++) {
            x->data[p] = (UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0]
              * (i47 + (int)C->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            yk = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                yk++;
                j->data[yk - 1] = nm1d2;
                if (yk >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (yk == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > yk) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = yk;
              emxEnsureCapacity_int32_T(j, p);
            }
          }

          p = E->size[0] * E->size[1];
          E->size[0] = 1;
          E->size[1] = j->size[1];
          emxEnsureCapacity_int32_T(E, p);
          qEnd = j->size[0] * j->size[1];
          for (p = 0; p < qEnd; p++) {
            E->data[p] = j->data[p];
          }

          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
          p = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = allA->size[1];
          emxEnsureCapacity_boolean_T(x, p);
          qEnd = allA->size[1];
          for (p = 0; p < qEnd; p++) {
            x->data[p] = (UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0]
              * (kEnd + allA->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            yk = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                yk++;
                j->data[yk - 1] = nm1d2;
                if (yk >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (yk == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > yk) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = yk;
              emxEnsureCapacity_int32_T(j, p);
            }
          }

          p = A->size[0] * A->size[1];
          A->size[0] = 1;
          A->size[1] = j->size[1];
          emxEnsureCapacity_int32_T(A, p);
          qEnd = j->size[0] * j->size[1];
          for (p = 0; p < qEnd; p++) {
            A->data[p] = j->data[p];
          }

          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
          p = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = allAn->size[1];
          emxEnsureCapacity_boolean_T(x, p);
          qEnd = allAn->size[1];
          for (p = 0; p < qEnd; p++) {
            x->data[p] = (UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0]
              * (n + allAn->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            yk = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                yk++;
                j->data[yk - 1] = nm1d2;
                if (yk >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (yk == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > yk) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = yk;
              emxEnsureCapacity_int32_T(j, p);
            }
          }

          p = An->size[0] * An->size[1];
          An->size[0] = 1;
          An->size[1] = j->size[1];
          emxEnsureCapacity_int32_T(An, p);
          qEnd = j->size[0] * j->size[1];
          for (p = 0; p < qEnd; p++) {
            An->data[p] = j->data[p];
          }

          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
          p = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = allS->size[1];
          emxEnsureCapacity_boolean_T(x, p);
          qEnd = allS->size[1];
          for (p = 0; p < qEnd; p++) {
            x->data[p] = (UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0]
              * (na + allS->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            yk = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                yk++;
                j->data[yk - 1] = nm1d2;
                if (yk >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (yk == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > yk) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = yk;
              emxEnsureCapacity_int32_T(j, p);
            }
          }

          p = S->size[0] * S->size[1];
          S->size[0] = 1;
          S->size[1] = j->size[1];
          emxEnsureCapacity_int32_T(S, p);
          qEnd = j->size[0] * j->size[1];
          for (p = 0; p < qEnd; p++) {
            S->data[p] = j->data[p];
          }

          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo.         */
          if (TimeUsoCPO == 0) {
            p = CPO->size[0] * CPO->size[1];
            CPO->size[0] = 1;
            CPO->size[1] = 1;
            emxEnsureCapacity_int32_T(CPO, p);
            CPO->data[0] = 0;
            nm1d2 = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
            if ((nm1d2 < 0) && (e_qY < MIN_int32_T - nm1d2)) {
              nm1d2 = MIN_int32_T;
            } else if ((nm1d2 > 0) && (e_qY > MAX_int32_T - nm1d2)) {
              nm1d2 = MAX_int32_T;
            } else {
              nm1d2 += e_qY;
            }

            if ((nm1d2 < 0) && (TimeUsoS < MIN_int32_T - nm1d2)) {
              nm1d2 = MIN_int32_T;
            } else if ((nm1d2 > 0) && (TimeUsoS > MAX_int32_T - nm1d2)) {
              nm1d2 = MAX_int32_T;
            } else {
              nm1d2 += TimeUsoS;
            }

            if ((nm1d2 < 0) && (TimeUsoCR < MIN_int32_T - nm1d2)) {
              q = MIN_int32_T;
            } else if ((nm1d2 > 0) && (TimeUsoCR > MAX_int32_T - nm1d2)) {
              q = MAX_int32_T;
            } else {
              q = nm1d2 + TimeUsoCR;
            }

            if (q < -2147483647) {
              q = MIN_int32_T;
            } else {
              q--;
            }

            if (nm1d2 > q) {
              p = 0;
              q = 0;
            } else {
              p = nm1d2 - 1;
            }

            a = j_sum(*(int (*)[6])&NumRec[0]);
            nb = b_H->size[0] * b_H->size[1];
            qEnd = q - p;
            b_H->size[0] = qEnd;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_int32_T(b_H, nb);
            yk = allCR->size[1];
            for (nb = 0; nb < yk; nb++) {
              for (nm1d2 = 0; nm1d2 < qEnd; nm1d2++) {
                b_H->data[nm1d2 + b_H->size[0] * nb] = H->data[(p + nm1d2) +
                  H->size[0] * ((int)(a + (double)allCR->data[nb]) - 1)];
              }
            }

            k_sum(b_H, r10);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r10->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r10->size[0] * r10->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r10->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              yk = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  yk++;
                  j->data[yk - 1] = nm1d2;
                  if (yk >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (yk == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > yk) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = yk;
                emxEnsureCapacity_int32_T(j, p);
              }
            }

            p = CR->size[0] * CR->size[1];
            CR->size[0] = 1;
            CR->size[1] = j->size[1];
            emxEnsureCapacity_real_T(CR, p);
            qEnd = j->size[0] * j->size[1];
            for (p = 0; p < qEnd; p++) {
              CR->data[p] = j->data[p];
            }
          } else {
            nm1d2 = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
            if ((nm1d2 < 0) && (e_qY < MIN_int32_T - nm1d2)) {
              nm1d2 = MIN_int32_T;
            } else if ((nm1d2 > 0) && (e_qY > MAX_int32_T - nm1d2)) {
              nm1d2 = MAX_int32_T;
            } else {
              nm1d2 += e_qY;
            }

            if ((nm1d2 < 0) && (TimeUsoS < MIN_int32_T - nm1d2)) {
              nm1d2 = MIN_int32_T;
            } else if ((nm1d2 > 0) && (TimeUsoS > MAX_int32_T - nm1d2)) {
              nm1d2 = MAX_int32_T;
            } else {
              nm1d2 += TimeUsoS;
            }

            if ((nm1d2 < 0) && (TimeUsoCPO < MIN_int32_T - nm1d2)) {
              q = MIN_int32_T;
            } else if ((nm1d2 > 0) && (TimeUsoCPO > MAX_int32_T - nm1d2)) {
              q = MAX_int32_T;
            } else {
              q = nm1d2 + TimeUsoCPO;
            }

            if (q < -2147483647) {
              q = MIN_int32_T;
            } else {
              q--;
            }

            if (nm1d2 > q) {
              p = 0;
              nb = 0;
            } else {
              p = nm1d2 - 1;
              nb = q;
            }

            a = i_sum(*(int (*)[5])&NumRec[0]);
            nm1d2 = b_H->size[0] * b_H->size[1];
            qEnd = nb - p;
            b_H->size[0] = qEnd;
            b_H->size[1] = allCPO->size[1];
            emxEnsureCapacity_int32_T(b_H, nm1d2);
            yk = allCPO->size[1];
            for (nb = 0; nb < yk; nb++) {
              for (nm1d2 = 0; nm1d2 < qEnd; nm1d2++) {
                b_H->data[nm1d2 + b_H->size[0] * nb] = H->data[(p + nm1d2) +
                  H->size[0] * ((int)(a + (double)allCPO->data[nb]) - 1)];
              }
            }

            k_sum(b_H, r10);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r10->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r10->size[0] * r10->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r10->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              yk = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  yk++;
                  j->data[yk - 1] = nm1d2;
                  if (yk >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (yk == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > yk) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = yk;
                emxEnsureCapacity_int32_T(j, p);
              }
            }

            p = CPO->size[0] * CPO->size[1];
            CPO->size[0] = 1;
            CPO->size[1] = j->size[1];
            emxEnsureCapacity_int32_T(CPO, p);
            qEnd = j->size[0] * j->size[1];
            for (p = 0; p < qEnd; p++) {
              CPO->data[p] = j->data[p];
            }

            /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
            a = j_sum(*(int (*)[6])&NumRec[0]);
            p = b_H->size[0] * b_H->size[1];
            b_H->size[0] = TimeUsoCR;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_int32_T(b_H, p);
            qEnd = allCR->size[1];
            for (p = 0; p < qEnd; p++) {
              for (nb = 0; nb < TimeUsoCR; nb++) {
                yk = 1 + nb;
                if ((q < 0) && (yk < MIN_int32_T - q)) {
                  nm1d2 = MIN_int32_T;
                } else if ((q > 0) && (yk > MAX_int32_T - q)) {
                  nm1d2 = MAX_int32_T;
                } else {
                  nm1d2 = q + yk;
                }

                b_H->data[nb + b_H->size[0] * p] = H->data[(nm1d2 + H->size[0] *
                  ((int)(a + (double)allCR->data[p]) - 1)) - 1];
              }
            }

            k_sum(b_H, r10);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r10->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r10->size[0] * r10->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r10->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              yk = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  yk++;
                  j->data[yk - 1] = nm1d2;
                  if (yk >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (yk == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > yk) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = yk;
                emxEnsureCapacity_int32_T(j, p);
              }
            }

            p = CR->size[0] * CR->size[1];
            CR->size[0] = 1;
            CR->size[1] = j->size[1];
            emxEnsureCapacity_real_T(CR, p);
            qEnd = j->size[0] * j->size[1];
            for (p = 0; p < qEnd; p++) {
              CR->data[p] = j->data[p];
            }
          }

          if ((CPO->size[1] != 0) && (CR->size[1] != 0) && (S->size[1] != 0) &&
              (E->size[1] >= PME->data[PME->size[1] - 1]) && (A->size[1] >=
               PMA->data[PMA->size[1] - 1]) && (An->size[1] >= PMAn->data
               [PMAn->size[1] - 1])) {
            temCPrO = (int)uCPrODisp->data[b_j];
            exitg2 = 1;
          } else {
            b_j++;
          }
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      if (temCPrO == -1) {
        i47 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        kEnd = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        tempUltPosRecXDia->size[0] = 1;
        emxEnsureCapacity_int32_T(tempUltPosRecXDia, kEnd);
        qEnd = i47 - 1;
        for (i47 = 0; i47 <= qEnd; i47++) {
          nm1d2 = tempUltPosRecXDia->data[i47];
          if (nm1d2 > 2147483646) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2++;
          }

          tempUltPosRecXDia->data[i47] = nm1d2;
        }
      } else {
        b_CPrOA = temCPrO;
        nm1d2 = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
        yk = tempUltPosRecXDia->data[temCPrO - 1];
        if ((nm1d2 < 0) && (yk < MIN_int32_T - nm1d2)) {
          qY = MIN_int32_T;
        } else if ((nm1d2 > 0) && (yk > MAX_int32_T - nm1d2)) {
          qY = MAX_int32_T;
        } else {
          qY = nm1d2 + yk;
        }

        if ((qY < 0) && (TimeUsoCPrO < MIN_int32_T - qY)) {
          nm1d2 = MIN_int32_T;
        } else if ((qY > 0) && (TimeUsoCPrO > MAX_int32_T - qY)) {
          nm1d2 = MAX_int32_T;
        } else {
          nm1d2 = qY + TimeUsoCPrO;
        }

        if (nm1d2 < -2147483647) {
          b_qY = MIN_int32_T;
        } else {
          b_qY = nm1d2 - 1;
        }

        i47 = SA->size[0] * SA->size[1];
        SA->size[0] = 1;
        SA->size[1] = 1;
        emxEnsureCapacity_int32_T(SA, i47);
        SA->data[0] = allS->data[S->data[0] - 1];
        b_IniSA = b_qY + 1;
        nm1d2 = b_qY + 1;
        if ((nm1d2 < 0) && (TimeUsoS < MIN_int32_T - nm1d2)) {
          nm1d2 = MIN_int32_T;
        } else if ((nm1d2 > 0) && (TimeUsoS > MAX_int32_T - nm1d2)) {
          nm1d2 = MAX_int32_T;
        } else {
          nm1d2 += TimeUsoS;
        }

        if (nm1d2 < -2147483647) {
          nm1d2 = MIN_int32_T;
        } else {
          nm1d2--;
        }

        b_EndSA = nm1d2 + 1;
        if (1 > PME->data[PME->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PME->data[PME->size[1] - 1];
        }

        i47 = EA->size[0] * EA->size[1];
        EA->size[0] = 1;
        EA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(EA, i47);
        for (i47 = 0; i47 < qEnd; i47++) {
          EA->data[i47] = (int)C->data[E->data[i47] - 1];
        }

        if (1 > PMA->data[PMA->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMA->data[PMA->size[1] - 1];
        }

        i47 = AA->size[0] * AA->size[1];
        AA->size[0] = 1;
        AA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AA, i47);
        for (i47 = 0; i47 < qEnd; i47++) {
          AA->data[i47] = allA->data[A->data[i47] - 1];
        }

        if (1 > PMAn->data[PMAn->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMAn->data[PMAn->size[1] - 1];
        }

        i47 = AnA->size[0] * AnA->size[1];
        AnA->size[0] = 1;
        AnA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AnA, i47);
        for (i47 = 0; i47 < qEnd; i47++) {
          AnA->data[i47] = allAn->data[An->data[i47] - 1];
        }

        if (TimeUsoCPO == 0) {
          b_CPOA = 0;
          b_IniCPOA = 0;
          c_qY = 0;
          b_CRA = allCR->data[(int)CR->data[0] - 1];
          b_IniCRA = b_EndSA;
          if ((b_EndSA < 0) && (TimeUsoCR < MIN_int32_T - b_EndSA)) {
            nm1d2 = MIN_int32_T;
          } else if ((b_EndSA > 0) && (TimeUsoCR > MAX_int32_T - b_EndSA)) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2 = b_EndSA + TimeUsoCR;
          }

          if (nm1d2 < -2147483647) {
            d_qY = MIN_int32_T;
          } else {
            d_qY = nm1d2 - 1;
          }
        } else {
          b_CPOA = allCPO->data[CPO->data[0] - 1];
          b_IniCPOA = b_EndSA;
          if ((b_EndSA < 0) && (TimeUsoCPO < MIN_int32_T - b_EndSA)) {
            nm1d2 = MIN_int32_T;
          } else if ((b_EndSA > 0) && (TimeUsoCPO > MAX_int32_T - b_EndSA)) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2 = b_EndSA + TimeUsoCPO;
          }

          if (nm1d2 < -2147483647) {
            c_qY = MIN_int32_T;
          } else {
            c_qY = nm1d2 - 1;
          }

          b_CRA = allCR->data[(int)CR->data[0] - 1];
          b_IniCRA = c_qY + 1;
          nm1d2 = c_qY + 1;
          if ((nm1d2 < 0) && (TimeUsoCR < MIN_int32_T - nm1d2)) {
            nm1d2 = MIN_int32_T;
          } else if ((nm1d2 > 0) && (TimeUsoCR > MAX_int32_T - nm1d2)) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2 += TimeUsoCR;
          }

          if (nm1d2 < -2147483647) {
            d_qY = MIN_int32_T;
          } else {
            d_qY = nm1d2 - 1;
          }
        }

        flag = false;
      }
    }
  }

  emxFree_int32_T(&b_H);
  emxFree_int32_T(&iwork);
  emxFree_int32_T(&idx);
  emxFree_int32_T(&b_b);
  emxFree_int32_T(&j);
  emxFree_boolean_T(&x);
  emxFree_real_T(&r10);
  emxFree_int32_T(&allCR);
  emxFree_int32_T(&allCPO);
  emxFree_int32_T(&allS);
  emxFree_int32_T(&allAn);
  emxFree_int32_T(&allA);
  emxFree_int32_T(&allC);
  emxFree_real_T(&C);
  emxFree_uint32_T(&uCPrODisp);
  emxFree_real_T(&CR);
  emxFree_int32_T(&CPO);
  emxFree_int32_T(&An);
  emxFree_int32_T(&A);
  emxFree_int32_T(&S);
  emxFree_int32_T(&E);
  *CPrOA = b_CPrOA;
  *IniCPrOA = qY;
  *EndCPrOA = b_qY;
  *EndCPrOAxD = e_qY;
  *IniSA = b_IniSA;
  *EndSA = b_EndSA - 1;
  *EndRPxD = f_qY;
  *CPOA = b_CPOA;
  *IniCPOA = b_IniCPOA;
  *EndCPOA = c_qY;
  *CRA = b_CRA;
  *IniCRA = b_IniCRA;
  *EndCRA = d_qY;
}

/* End of code generation (funcionCPrO.c) */
