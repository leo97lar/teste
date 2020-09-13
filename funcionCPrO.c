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
#include "sum.h"
#include "colon.h"
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
  emxArray_int32_T *j;
  int nm1d2;
  emxArray_int32_T *E;
  int i78;
  double a;
  double b;
  emxArray_real_T *r12;
  double ndbl;
  double apnd;
  double cdiff;
  emxArray_int32_T *S;
  int qEnd;
  int n;
  emxArray_real_T *C;
  emxArray_int32_T *A;
  int k;
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
  int b_idx;
  boolean_T exitg1;
  int nb;
  int q;
  int na;
  int b_j;
  int p;
  long long i79;
  int exitg2;
  emxInit_int32_T(&j, 2);
  if (NumRec[0] > 2147483646) {
    nm1d2 = MAX_int32_T;
  } else {
    nm1d2 = NumRec[0] + 1;
  }

  eml_signed_integer_colon(nm1d2, (int)d_sum(*(int (*)[2])&NumRec[0]), j);
  nm1d2 = j->size[1];
  emxInit_int32_T(&E, 2);
  if (nm1d2 < 1) {
    E->size[0] = 1;
    E->size[1] = 0;
  } else {
    i78 = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = nm1d2;
    emxEnsureCapacity_int32_T(E, i78);
    for (i78 = 0; i78 < nm1d2; i78++) {
      E->data[i78] = 1 + i78;
    }
  }

  a = d_sum(*(int (*)[2])&NumRec[0]) + 1.0;
  b = e_sum(*(int (*)[3])&NumRec[0]);
  emxInit_real_T(&r12, 2);
  if (b < a) {
    i78 = r12->size[0] * r12->size[1];
    r12->size[1] = 0;
    emxEnsureCapacity_real_T(r12, i78);
  } else if (floor(a) == a) {
    i78 = r12->size[0] * r12->size[1];
    r12->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(r12, i78);
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

    i78 = r12->size[0] * r12->size[1];
    r12->size[0] = 1;
    r12->size[1] = n;
    emxEnsureCapacity_real_T(r12, i78);
    if ((n > 0) && (n > 1)) {
      r12->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (k = 0; k <= nm1d2 - 2; k++) {
        r12->data[1 + k] = a + (1.0 + (double)k);
        r12->data[(n - k) - 2] = apnd - (1.0 + (double)k);
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
    i78 = S->size[0] * S->size[1];
    S->size[0] = 1;
    S->size[1] = qEnd;
    emxEnsureCapacity_int32_T(S, i78);
    for (i78 = 0; i78 < qEnd; i78++) {
      S->data[i78] = 1 + i78;
    }
  }

  a = e_sum(*(int (*)[3])&NumRec[0]) + 1.0;
  b = g_sum(*(int (*)[4])&NumRec[0]);
  emxInit_real_T(&C, 2);
  if (b < a) {
    i78 = C->size[0] * C->size[1];
    C->size[1] = 0;
    emxEnsureCapacity_real_T(C, i78);
  } else if (floor(a) == a) {
    i78 = C->size[0] * C->size[1];
    C->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(C, i78);
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

    i78 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = n;
    emxEnsureCapacity_real_T(C, i78);
    if (n > 0) {
      C->data[0] = a;
      if (n > 1) {
        C->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 0; k <= nm1d2 - 2; k++) {
          C->data[1 + k] = a + (1.0 + (double)k);
          C->data[(n - k) - 2] = apnd - (1.0 + (double)k);
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
    i78 = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = qEnd;
    emxEnsureCapacity_int32_T(A, i78);
    for (i78 = 0; i78 < qEnd; i78++) {
      A->data[i78] = 1 + i78;
    }
  }

  a = g_sum(*(int (*)[4])&NumRec[0]) + 1.0;
  b = h_sum(*(int (*)[5])&NumRec[0]);
  emxInit_real_T(&CR, 2);
  if (b < a) {
    i78 = CR->size[0] * CR->size[1];
    CR->size[1] = 0;
    emxEnsureCapacity_real_T(CR, i78);
  } else if (floor(a) == a) {
    i78 = CR->size[0] * CR->size[1];
    CR->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(CR, i78);
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

    i78 = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    CR->size[1] = n;
    emxEnsureCapacity_real_T(CR, i78);
    if (n > 0) {
      CR->data[0] = a;
      if (n > 1) {
        CR->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 0; k <= nm1d2 - 2; k++) {
          CR->data[1 + k] = a + (1.0 + (double)k);
          CR->data[(n - k) - 2] = apnd - (1.0 + (double)k);
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
    i78 = An->size[0] * An->size[1];
    An->size[0] = 1;
    An->size[1] = qEnd;
    emxEnsureCapacity_int32_T(An, i78);
    for (i78 = 0; i78 < qEnd; i78++) {
      An->data[i78] = 1 + i78;
    }
  }

  emxInit_int32_T(&CPO, 2);
  if (PCPO->size[1] < 1) {
    CPO->size[0] = 1;
    CPO->size[1] = 0;
  } else {
    qEnd = PCPO->size[1];
    i78 = CPO->size[0] * CPO->size[1];
    CPO->size[0] = 1;
    CPO->size[1] = qEnd;
    emxEnsureCapacity_int32_T(CPO, i78);
    for (i78 = 0; i78 < qEnd; i78++) {
      CPO->data[i78] = 1 + i78;
    }
  }

  if (PCR->size[1] < 1) {
    CR->size[0] = 1;
    CR->size[1] = 0;
  } else {
    i78 = PCR->size[1];
    kEnd = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    qEnd = (int)((double)i78 - 1.0);
    CR->size[1] = qEnd + 1;
    emxEnsureCapacity_real_T(CR, kEnd);
    for (i78 = 0; i78 <= qEnd; i78++) {
      CR->data[i78] = 1.0 + (double)i78;
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
    i78 = EA->size[0] * EA->size[1];
    EA->size[0] = 1;
    EA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(EA, i78);
    for (i78 = 0; i78 <= qEnd; i78++) {
      EA->data[i78] = 1 + i78;
    }
  }

  if (PMA->size[1] - 1 < 1) {
    AA->size[0] = 1;
    AA->size[1] = 0;
  } else {
    qEnd = PMA->size[1] - 2;
    i78 = AA->size[0] * AA->size[1];
    AA->size[0] = 1;
    AA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AA, i78);
    for (i78 = 0; i78 <= qEnd; i78++) {
      AA->data[i78] = 1 + i78;
    }
  }

  if (PMAn->size[1] - 1 < 1) {
    AnA->size[0] = 1;
    AnA->size[1] = 0;
  } else {
    qEnd = PMAn->size[1] - 2;
    i78 = AnA->size[0] * AnA->size[1];
    AnA->size[0] = 1;
    AnA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AnA, i78);
    for (i78 = 0; i78 <= qEnd; i78++) {
      AnA->data[i78] = 1 + i78;
    }
  }

  if (PS->size[1] - 1 < 1) {
    SA->size[0] = 1;
    SA->size[1] = 0;
  } else {
    qEnd = PS->size[1] - 2;
    i78 = SA->size[0] * SA->size[1];
    SA->size[0] = 1;
    SA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(SA, i78);
    for (i78 = 0; i78 <= qEnd; i78++) {
      SA->data[i78] = 1 + i78;
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
    i78 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = PCPrO->size[1];
    emxEnsureCapacity_boolean_T(x, i78);
    qEnd = PCPrO->size[0] * PCPrO->size[1];
    for (i78 = 0; i78 < qEnd; i78++) {
      x->data[i78] = (PCPrO->data[i78] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i78 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i78);
      nm1d2 = 1;
      exitg1 = false;
      while ((!exitg1) && (nm1d2 <= x->size[1])) {
        if (x->data[nm1d2 - 1]) {
          b_idx++;
          j->data[b_idx - 1] = nm1d2;
          if (b_idx >= x->size[1]) {
            exitg1 = true;
          } else {
            nm1d2++;
          }
        } else {
          nm1d2++;
        }
      }

      if (x->size[1] == 1) {
        if (b_idx == 0) {
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > b_idx) {
        j->size[1] = 0;
      } else {
        i78 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i78);
      }
    }

    i78 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = j->size[1];
    emxEnsureCapacity_real_T(C, i78);
    qEnd = j->size[0] * j->size[1];
    for (i78 = 0; i78 < qEnd; i78++) {
      C->data[i78] = j->data[i78];
    }

    /*  Busco las posibles camas a usar. */
    nm1d2 = Dia->data[(*contDia + Dia->size[0] * 3) - 1];
    nb = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
    if ((nm1d2 >= 0) && (nb < nm1d2 - MAX_int32_T)) {
      nm1d2 = MAX_int32_T;
    } else if ((nm1d2 < 0) && (nb > nm1d2 - MIN_int32_T)) {
      nm1d2 = MIN_int32_T;
    } else {
      nm1d2 -= nb;
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
    i78 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = C->size[1];
    emxEnsureCapacity_boolean_T(x, i78);
    qEnd = C->size[0] * C->size[1];
    for (i78 = 0; i78 < qEnd; i78++) {
      x->data[i78] = (tempUltPosRecXDia->data[(int)C->data[i78] - 1] <= nm1d2);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i78 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i78);
      nm1d2 = 1;
      exitg1 = false;
      while ((!exitg1) && (nm1d2 <= x->size[1])) {
        if (x->data[nm1d2 - 1]) {
          b_idx++;
          j->data[b_idx - 1] = nm1d2;
          if (b_idx >= x->size[1]) {
            exitg1 = true;
          } else {
            nm1d2++;
          }
        } else {
          nm1d2++;
        }
      }

      if (x->size[1] == 1) {
        if (b_idx == 0) {
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > b_idx) {
        j->size[1] = 0;
      } else {
        i78 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i78);
      }
    }

    i78 = allC->size[0] * allC->size[1];
    allC->size[0] = 1;
    allC->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(allC, i78);
    qEnd = j->size[0] * j->size[1];
    for (i78 = 0; i78 < qEnd; i78++) {
      allC->data[i78] = j->data[i78];
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
      i78 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(j, i78);
      qEnd = allC->size[0] * allC->size[1];
      for (i78 = 0; i78 < qEnd; i78++) {
        j->data[i78] = tempUltPosRecXDia->data[(int)(unsigned int)C->data
          [allC->data[i78] - 1] - 1];
      }

      na = allC->size[1];
      n = allC->size[1] + 1;
      i78 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(idx, i78);
      qEnd = allC->size[1];
      for (i78 = 0; i78 < qEnd; i78++) {
        idx->data[i78] = 0;
      }

      i78 = iwork->size[0];
      iwork->size[0] = allC->size[1];
      emxEnsureCapacity_int32_T(iwork, i78);
      i78 = allC->size[1] - 1;
      for (k = 1; k <= i78; k += 2) {
        if (j->data[k - 1] <= j->data[k]) {
          idx->data[k - 1] = k;
          idx->data[k] = k + 1;
        } else {
          idx->data[k - 1] = k + 1;
          idx->data[k] = k;
        }
      }

      if ((allC->size[1] & 1) != 0) {
        idx->data[allC->size[1] - 1] = allC->size[1];
      }

      nm1d2 = 2;
      while (nm1d2 < n - 1) {
        nb = nm1d2 << 1;
        b_j = 1;
        for (b_idx = 1 + nm1d2; b_idx < n; b_idx = qEnd + nm1d2) {
          p = b_j;
          q = b_idx;
          qEnd = b_j + nb;
          if (qEnd > n) {
            qEnd = n;
          }

          k = 0;
          kEnd = qEnd - b_j;
          while (k + 1 <= kEnd) {
            if (j->data[idx->data[p - 1] - 1] <= j->data[idx->data[q - 1] - 1])
            {
              iwork->data[k] = idx->data[p - 1];
              p++;
              if (p == b_idx) {
                while (q < qEnd) {
                  k++;
                  iwork->data[k] = idx->data[q - 1];
                  q++;
                }
              }
            } else {
              iwork->data[k] = idx->data[q - 1];
              q++;
              if (q == qEnd) {
                while (p < b_idx) {
                  k++;
                  iwork->data[k] = idx->data[p - 1];
                  p++;
                }
              }
            }

            k++;
          }

          for (k = 0; k < kEnd; k++) {
            idx->data[(b_j + k) - 1] = iwork->data[k];
          }

          b_j = qEnd;
        }

        nm1d2 = nb;
      }

      i78 = b_b->size[0] * b_b->size[1];
      b_b->size[0] = 1;
      b_b->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(b_b, i78);
      for (k = 0; k < na; k++) {
        b_b->data[k] = j->data[idx->data[k] - 1];
      }

      nb = -1;
      k = 0;
      while (k + 1 <= na) {
        nm1d2 = b_b->data[k];
        b_idx = k;
        do {
          k++;
        } while (!((k + 1 > na) || (b_b->data[k] != nm1d2)));

        nb++;
        b_b->data[nb] = nm1d2;
        idx->data[nb] = idx->data[b_idx];
      }

      i78 = iwork->size[0];
      iwork->size[0] = nb + 1;
      emxEnsureCapacity_int32_T(iwork, i78);
      for (k = 0; k <= nb; k++) {
        iwork->data[k] = idx->data[k];
      }

      i78 = uCPrODisp->size[0] * uCPrODisp->size[1];
      uCPrODisp->size[0] = 1;
      uCPrODisp->size[1] = iwork->size[0];
      emxEnsureCapacity_uint32_T(uCPrODisp, i78);
      qEnd = iwork->size[0];
      for (i78 = 0; i78 < qEnd; i78++) {
        uCPrODisp->data[i78] = (unsigned int)C->data[allC->data[iwork->data[i78]
          - 1] - 1];
      }

      if (NumRec[0] > 2147483646) {
        nm1d2 = MAX_int32_T;
      } else {
        nm1d2 = NumRec[0] + 1;
      }

      a = rt_roundd(d_sum(*(int (*)[2])&NumRec[0]));
      if (a < 2.147483648E+9) {
        if (a >= -2.147483648E+9) {
          i78 = (int)a;
        } else {
          i78 = MIN_int32_T;
        }
      } else {
        i78 = MAX_int32_T;
      }

      if (nm1d2 > i78) {
        i78 = -1;
      } else {
        i78 = nm1d2 - 2;
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
        i79 = (long long)PME->data[kEnd] * DispME->data[kEnd];
        if (i79 > 2147483647LL) {
          i79 = 2147483647LL;
        } else {
          if (i79 < -2147483648LL) {
            i79 = -2147483648LL;
          }
        }

        x->data[kEnd] = ((int)i79 != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        b_idx = 0;
        kEnd = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, kEnd);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          kEnd = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
      a = e_sum(*(int (*)[3])&NumRec[0]) + 1.0;
      b = g_sum(*(int (*)[4])&NumRec[0]);
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
        b_idx = 0;
        n = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, n);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          n = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
      a = g_sum(*(int (*)[4])&NumRec[0]) + 1.0;
      b = h_sum(*(int (*)[5])&NumRec[0]);
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

      k = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, k);
      for (k = 0; k < qEnd; k++) {
        x->data[k] = (PMAn->data[k] != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        b_idx = 0;
        k = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, k);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          k = j->size[0] * j->size[1];
          j->size[1] = b_idx;
          emxEnsureCapacity_int32_T(j, k);
        }
      }

      k = allAn->size[0] * allAn->size[1];
      allAn->size[0] = 1;
      allAn->size[1] = j->size[1];
      emxEnsureCapacity_int32_T(allAn, k);
      qEnd = j->size[0] * j->size[1];
      for (k = 0; k < qEnd; k++) {
        allAn->data[k] = j->data[k];
      }

      /*  Busco los posibles Anestesistas a usar. */
      a = d_sum(*(int (*)[2])&NumRec[0]) + 1.0;
      b = e_sum(*(int (*)[3])&NumRec[0]);
      if (a > b) {
        k = -1;
      } else {
        k = (int)a - 2;
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
        b_idx = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
        b_idx = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
        b_idx = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
      na = -1;
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
              * (i78 + (int)C->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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
              * (k + allS->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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

            a = i_sum(*(int (*)[6])&NumRec[0]);
            b_idx = b_H->size[0] * b_H->size[1];
            qEnd = q - p;
            b_H->size[0] = qEnd;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_real_T(b_H, b_idx);
            nb = allCR->size[1];
            for (b_idx = 0; b_idx < nb; b_idx++) {
              for (nm1d2 = 0; nm1d2 < qEnd; nm1d2++) {
                b_H->data[nm1d2 + b_H->size[0] * b_idx] = H->data[(p + nm1d2) +
                  H->size[0] * ((int)(a + (double)allCR->data[b_idx]) - 1)];
              }
            }

            j_sum(b_H, r12);
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
              b_idx = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  b_idx++;
                  j->data[b_idx - 1] = nm1d2;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > b_idx) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = b_idx;
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
              b_idx = 0;
            } else {
              p = nm1d2 - 1;
              b_idx = q;
            }

            a = h_sum(*(int (*)[5])&NumRec[0]);
            nm1d2 = b_H->size[0] * b_H->size[1];
            qEnd = b_idx - p;
            b_H->size[0] = qEnd;
            b_H->size[1] = allCPO->size[1];
            emxEnsureCapacity_real_T(b_H, nm1d2);
            nb = allCPO->size[1];
            for (b_idx = 0; b_idx < nb; b_idx++) {
              for (nm1d2 = 0; nm1d2 < qEnd; nm1d2++) {
                b_H->data[nm1d2 + b_H->size[0] * b_idx] = H->data[(p + nm1d2) +
                  H->size[0] * ((int)(a + (double)allCPO->data[b_idx]) - 1)];
              }
            }

            j_sum(b_H, r12);
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
              b_idx = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  b_idx++;
                  j->data[b_idx - 1] = nm1d2;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > b_idx) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = b_idx;
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
            a = i_sum(*(int (*)[6])&NumRec[0]);
            p = b_H->size[0] * b_H->size[1];
            b_H->size[0] = TimeUsoCR;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_real_T(b_H, p);
            qEnd = allCR->size[1];
            for (p = 0; p < qEnd; p++) {
              for (b_idx = 0; b_idx < TimeUsoCR; b_idx++) {
                nb = 1 + b_idx;
                if ((q < 0) && (nb < MIN_int32_T - q)) {
                  nm1d2 = MIN_int32_T;
                } else if ((q > 0) && (nb > MAX_int32_T - q)) {
                  nm1d2 = MAX_int32_T;
                } else {
                  nm1d2 = q + nb;
                }

                b_H->data[b_idx + b_H->size[0] * p] = H->data[(nm1d2 + H->size[0]
                  * ((int)(a + (double)allCR->data[p]) - 1)) - 1];
              }
            }

            j_sum(b_H, r12);
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
              b_idx = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  b_idx++;
                  j->data[b_idx - 1] = nm1d2;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > b_idx) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = b_idx;
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
            na = (int)uCPrODisp->data[b_j];
            exitg2 = 1;
          } else {
            b_j++;
          }
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      if (na == -1) {
        i78 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        kEnd = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        tempUltPosRecXDia->size[0] = 1;
        emxEnsureCapacity_int32_T(tempUltPosRecXDia, kEnd);
        qEnd = i78 - 1;
        for (i78 = 0; i78 <= qEnd; i78++) {
          nm1d2 = tempUltPosRecXDia->data[i78];
          if (nm1d2 > 2147483646) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2++;
          }

          tempUltPosRecXDia->data[i78] = nm1d2;
        }
      } else {
        b_CPrOA = na;
        nm1d2 = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
        nb = tempUltPosRecXDia->data[na - 1];
        if ((nm1d2 < 0) && (nb < MIN_int32_T - nm1d2)) {
          qY = MIN_int32_T;
        } else if ((nm1d2 > 0) && (nb > MAX_int32_T - nm1d2)) {
          qY = MAX_int32_T;
        } else {
          qY = nm1d2 + nb;
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

        i78 = SA->size[0] * SA->size[1];
        SA->size[0] = 1;
        SA->size[1] = 1;
        emxEnsureCapacity_int32_T(SA, i78);
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

        i78 = EA->size[0] * EA->size[1];
        EA->size[0] = 1;
        EA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(EA, i78);
        for (i78 = 0; i78 < qEnd; i78++) {
          EA->data[i78] = (int)C->data[E->data[i78] - 1];
        }

        if (1 > PMA->data[PMA->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMA->data[PMA->size[1] - 1];
        }

        i78 = AA->size[0] * AA->size[1];
        AA->size[0] = 1;
        AA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AA, i78);
        for (i78 = 0; i78 < qEnd; i78++) {
          AA->data[i78] = allA->data[A->data[i78] - 1];
        }

        if (1 > PMAn->data[PMAn->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMAn->data[PMAn->size[1] - 1];
        }

        i78 = AnA->size[0] * AnA->size[1];
        AnA->size[0] = 1;
        AnA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AnA, i78);
        for (i78 = 0; i78 < qEnd; i78++) {
          AnA->data[i78] = allAn->data[An->data[i78] - 1];
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

void c_funcionCPrO(const int NumRec[7], const emxArray_int32_T *PCPrO, const
                   emxArray_int32_T *PME, const emxArray_int32_T *PMA, const
                   emxArray_int32_T *PMAn, const emxArray_int32_T *PS, const
                   emxArray_int32_T *PCPO, const emxArray_int32_T *PCR, const
                   emxArray_int32_T *H, const emxArray_int32_T *Dia, const
                   emxArray_int32_T *UltPosRecXDia, int TimeUsoCPrO, int
                   TimeUsoS, int TimeUsoCPO, int TimeUsoCR, int *contDia,
                   emxArray_int32_T *tempUltPosRecXDia, const emxArray_int32_T
                   *DispMExD, emxArray_int32_T *DispME, int *CPrOA, int
                   *IniCPrOA, int *EndCPrOA, int *EndCPrOAxD, emxArray_int32_T
                   *EA, emxArray_int32_T *AA, emxArray_int32_T *AnA,
                   emxArray_int32_T *SA, int *IniSA, int *EndSA, int *EndRPxD,
                   int *CPOA, int *IniCPOA, int *EndCPOA, int *CRA, int *IniCRA,
                   int *EndCRA)
{
  emxArray_int32_T *j;
  int nm1d2;
  emxArray_int32_T *E;
  int i89;
  double a;
  double b;
  emxArray_real_T *r14;
  double ndbl;
  double apnd;
  double cdiff;
  emxArray_int32_T *S;
  int qEnd;
  int n;
  emxArray_real_T *C;
  emxArray_int32_T *A;
  int k;
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
  int b_idx;
  boolean_T exitg1;
  int nb;
  int q;
  int na;
  int b_j;
  int p;
  long long i90;
  int exitg2;
  emxInit_int32_T(&j, 2);
  if (NumRec[0] > 2147483646) {
    nm1d2 = MAX_int32_T;
  } else {
    nm1d2 = NumRec[0] + 1;
  }

  eml_signed_integer_colon(nm1d2, (int)d_sum(*(int (*)[2])&NumRec[0]), j);
  nm1d2 = j->size[1];
  emxInit_int32_T(&E, 2);
  if (nm1d2 < 1) {
    E->size[0] = 1;
    E->size[1] = 0;
  } else {
    i89 = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = nm1d2;
    emxEnsureCapacity_int32_T(E, i89);
    for (i89 = 0; i89 < nm1d2; i89++) {
      E->data[i89] = 1 + i89;
    }
  }

  a = d_sum(*(int (*)[2])&NumRec[0]) + 1.0;
  b = e_sum(*(int (*)[3])&NumRec[0]);
  emxInit_real_T(&r14, 2);
  if (b < a) {
    i89 = r14->size[0] * r14->size[1];
    r14->size[1] = 0;
    emxEnsureCapacity_real_T(r14, i89);
  } else if (floor(a) == a) {
    i89 = r14->size[0] * r14->size[1];
    r14->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(r14, i89);
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

    i89 = r14->size[0] * r14->size[1];
    r14->size[0] = 1;
    r14->size[1] = n;
    emxEnsureCapacity_real_T(r14, i89);
    if ((n > 0) && (n > 1)) {
      r14->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (k = 0; k <= nm1d2 - 2; k++) {
        r14->data[1 + k] = a + (1.0 + (double)k);
        r14->data[(n - k) - 2] = apnd - (1.0 + (double)k);
      }

      if (nm1d2 << 1 == n - 1) {
        r14->data[nm1d2] = (a + apnd) / 2.0;
      } else {
        r14->data[nm1d2] = a + (double)nm1d2;
        r14->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_int32_T(&S, 2);
  if (r14->size[1] < 1) {
    S->size[0] = 1;
    S->size[1] = 0;
  } else {
    qEnd = r14->size[1];
    i89 = S->size[0] * S->size[1];
    S->size[0] = 1;
    S->size[1] = qEnd;
    emxEnsureCapacity_int32_T(S, i89);
    for (i89 = 0; i89 < qEnd; i89++) {
      S->data[i89] = 1 + i89;
    }
  }

  a = e_sum(*(int (*)[3])&NumRec[0]) + 1.0;
  b = g_sum(*(int (*)[4])&NumRec[0]);
  emxInit_real_T(&C, 2);
  if (b < a) {
    i89 = C->size[0] * C->size[1];
    C->size[1] = 0;
    emxEnsureCapacity_real_T(C, i89);
  } else if (floor(a) == a) {
    i89 = C->size[0] * C->size[1];
    C->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(C, i89);
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

    i89 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = n;
    emxEnsureCapacity_real_T(C, i89);
    if (n > 0) {
      C->data[0] = a;
      if (n > 1) {
        C->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 0; k <= nm1d2 - 2; k++) {
          C->data[1 + k] = a + (1.0 + (double)k);
          C->data[(n - k) - 2] = apnd - (1.0 + (double)k);
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
    i89 = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = qEnd;
    emxEnsureCapacity_int32_T(A, i89);
    for (i89 = 0; i89 < qEnd; i89++) {
      A->data[i89] = 1 + i89;
    }
  }

  a = g_sum(*(int (*)[4])&NumRec[0]) + 1.0;
  b = h_sum(*(int (*)[5])&NumRec[0]);
  emxInit_real_T(&CR, 2);
  if (b < a) {
    i89 = CR->size[0] * CR->size[1];
    CR->size[1] = 0;
    emxEnsureCapacity_real_T(CR, i89);
  } else if (floor(a) == a) {
    i89 = CR->size[0] * CR->size[1];
    CR->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(CR, i89);
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

    i89 = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    CR->size[1] = n;
    emxEnsureCapacity_real_T(CR, i89);
    if (n > 0) {
      CR->data[0] = a;
      if (n > 1) {
        CR->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 0; k <= nm1d2 - 2; k++) {
          CR->data[1 + k] = a + (1.0 + (double)k);
          CR->data[(n - k) - 2] = apnd - (1.0 + (double)k);
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
    i89 = An->size[0] * An->size[1];
    An->size[0] = 1;
    An->size[1] = qEnd;
    emxEnsureCapacity_int32_T(An, i89);
    for (i89 = 0; i89 < qEnd; i89++) {
      An->data[i89] = 1 + i89;
    }
  }

  emxInit_int32_T(&CPO, 2);
  if (PCPO->size[1] < 1) {
    CPO->size[0] = 1;
    CPO->size[1] = 0;
  } else {
    qEnd = PCPO->size[1];
    i89 = CPO->size[0] * CPO->size[1];
    CPO->size[0] = 1;
    CPO->size[1] = qEnd;
    emxEnsureCapacity_int32_T(CPO, i89);
    for (i89 = 0; i89 < qEnd; i89++) {
      CPO->data[i89] = 1 + i89;
    }
  }

  if (PCR->size[1] < 1) {
    CR->size[0] = 1;
    CR->size[1] = 0;
  } else {
    i89 = PCR->size[1];
    kEnd = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    qEnd = (int)((double)i89 - 1.0);
    CR->size[1] = qEnd + 1;
    emxEnsureCapacity_real_T(CR, kEnd);
    for (i89 = 0; i89 <= qEnd; i89++) {
      CR->data[i89] = 1.0 + (double)i89;
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
    i89 = EA->size[0] * EA->size[1];
    EA->size[0] = 1;
    EA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(EA, i89);
    for (i89 = 0; i89 <= qEnd; i89++) {
      EA->data[i89] = 1 + i89;
    }
  }

  if (PMA->size[1] - 1 < 1) {
    AA->size[0] = 1;
    AA->size[1] = 0;
  } else {
    qEnd = PMA->size[1] - 2;
    i89 = AA->size[0] * AA->size[1];
    AA->size[0] = 1;
    AA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AA, i89);
    for (i89 = 0; i89 <= qEnd; i89++) {
      AA->data[i89] = 1 + i89;
    }
  }

  if (PMAn->size[1] - 1 < 1) {
    AnA->size[0] = 1;
    AnA->size[1] = 0;
  } else {
    qEnd = PMAn->size[1] - 2;
    i89 = AnA->size[0] * AnA->size[1];
    AnA->size[0] = 1;
    AnA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AnA, i89);
    for (i89 = 0; i89 <= qEnd; i89++) {
      AnA->data[i89] = 1 + i89;
    }
  }

  if (PS->size[1] - 1 < 1) {
    SA->size[0] = 1;
    SA->size[1] = 0;
  } else {
    qEnd = PS->size[1] - 2;
    i89 = SA->size[0] * SA->size[1];
    SA->size[0] = 1;
    SA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(SA, i89);
    for (i89 = 0; i89 <= qEnd; i89++) {
      SA->data[i89] = 1 + i89;
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
    i89 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = PCPrO->size[1];
    emxEnsureCapacity_boolean_T(x, i89);
    qEnd = PCPrO->size[0] * PCPrO->size[1];
    for (i89 = 0; i89 < qEnd; i89++) {
      x->data[i89] = (PCPrO->data[i89] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i89 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i89);
      nm1d2 = 1;
      exitg1 = false;
      while ((!exitg1) && (nm1d2 <= x->size[1])) {
        if (x->data[nm1d2 - 1]) {
          b_idx++;
          j->data[b_idx - 1] = nm1d2;
          if (b_idx >= x->size[1]) {
            exitg1 = true;
          } else {
            nm1d2++;
          }
        } else {
          nm1d2++;
        }
      }

      if (x->size[1] == 1) {
        if (b_idx == 0) {
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > b_idx) {
        j->size[1] = 0;
      } else {
        i89 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i89);
      }
    }

    i89 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = j->size[1];
    emxEnsureCapacity_real_T(C, i89);
    qEnd = j->size[0] * j->size[1];
    for (i89 = 0; i89 < qEnd; i89++) {
      C->data[i89] = j->data[i89];
    }

    /*  Busco las posibles camas a usar. */
    nm1d2 = Dia->data[(*contDia + Dia->size[0] * 3) - 1];
    nb = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
    if ((nm1d2 >= 0) && (nb < nm1d2 - MAX_int32_T)) {
      nm1d2 = MAX_int32_T;
    } else if ((nm1d2 < 0) && (nb > nm1d2 - MIN_int32_T)) {
      nm1d2 = MIN_int32_T;
    } else {
      nm1d2 -= nb;
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
    i89 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = C->size[1];
    emxEnsureCapacity_boolean_T(x, i89);
    qEnd = C->size[0] * C->size[1];
    for (i89 = 0; i89 < qEnd; i89++) {
      x->data[i89] = (tempUltPosRecXDia->data[(int)C->data[i89] - 1] <= nm1d2);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i89 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i89);
      nm1d2 = 1;
      exitg1 = false;
      while ((!exitg1) && (nm1d2 <= x->size[1])) {
        if (x->data[nm1d2 - 1]) {
          b_idx++;
          j->data[b_idx - 1] = nm1d2;
          if (b_idx >= x->size[1]) {
            exitg1 = true;
          } else {
            nm1d2++;
          }
        } else {
          nm1d2++;
        }
      }

      if (x->size[1] == 1) {
        if (b_idx == 0) {
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > b_idx) {
        j->size[1] = 0;
      } else {
        i89 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i89);
      }
    }

    i89 = allC->size[0] * allC->size[1];
    allC->size[0] = 1;
    allC->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(allC, i89);
    qEnd = j->size[0] * j->size[1];
    for (i89 = 0; i89 < qEnd; i89++) {
      allC->data[i89] = j->data[i89];
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

      c_funcionDia(NumRec, PCPrO, Dia, UltPosRecXDia, TimeUsoCPrO, TimeUsoS,
                   contDia, DispMExD, tempUltPosRecXDia, DispME);
    } else {
      i89 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(j, i89);
      qEnd = allC->size[0] * allC->size[1];
      for (i89 = 0; i89 < qEnd; i89++) {
        j->data[i89] = tempUltPosRecXDia->data[(int)(unsigned int)C->data
          [allC->data[i89] - 1] - 1];
      }

      na = allC->size[1];
      n = allC->size[1] + 1;
      i89 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(idx, i89);
      qEnd = allC->size[1];
      for (i89 = 0; i89 < qEnd; i89++) {
        idx->data[i89] = 0;
      }

      i89 = iwork->size[0];
      iwork->size[0] = allC->size[1];
      emxEnsureCapacity_int32_T(iwork, i89);
      i89 = allC->size[1] - 1;
      for (k = 1; k <= i89; k += 2) {
        if (j->data[k - 1] <= j->data[k]) {
          idx->data[k - 1] = k;
          idx->data[k] = k + 1;
        } else {
          idx->data[k - 1] = k + 1;
          idx->data[k] = k;
        }
      }

      if ((allC->size[1] & 1) != 0) {
        idx->data[allC->size[1] - 1] = allC->size[1];
      }

      nm1d2 = 2;
      while (nm1d2 < n - 1) {
        nb = nm1d2 << 1;
        b_j = 1;
        for (b_idx = 1 + nm1d2; b_idx < n; b_idx = qEnd + nm1d2) {
          p = b_j;
          q = b_idx;
          qEnd = b_j + nb;
          if (qEnd > n) {
            qEnd = n;
          }

          k = 0;
          kEnd = qEnd - b_j;
          while (k + 1 <= kEnd) {
            if (j->data[idx->data[p - 1] - 1] <= j->data[idx->data[q - 1] - 1])
            {
              iwork->data[k] = idx->data[p - 1];
              p++;
              if (p == b_idx) {
                while (q < qEnd) {
                  k++;
                  iwork->data[k] = idx->data[q - 1];
                  q++;
                }
              }
            } else {
              iwork->data[k] = idx->data[q - 1];
              q++;
              if (q == qEnd) {
                while (p < b_idx) {
                  k++;
                  iwork->data[k] = idx->data[p - 1];
                  p++;
                }
              }
            }

            k++;
          }

          for (k = 0; k < kEnd; k++) {
            idx->data[(b_j + k) - 1] = iwork->data[k];
          }

          b_j = qEnd;
        }

        nm1d2 = nb;
      }

      i89 = b_b->size[0] * b_b->size[1];
      b_b->size[0] = 1;
      b_b->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(b_b, i89);
      for (k = 0; k < na; k++) {
        b_b->data[k] = j->data[idx->data[k] - 1];
      }

      nb = -1;
      k = 0;
      while (k + 1 <= na) {
        nm1d2 = b_b->data[k];
        b_idx = k;
        do {
          k++;
        } while (!((k + 1 > na) || (b_b->data[k] != nm1d2)));

        nb++;
        b_b->data[nb] = nm1d2;
        idx->data[nb] = idx->data[b_idx];
      }

      i89 = iwork->size[0];
      iwork->size[0] = nb + 1;
      emxEnsureCapacity_int32_T(iwork, i89);
      for (k = 0; k <= nb; k++) {
        iwork->data[k] = idx->data[k];
      }

      i89 = uCPrODisp->size[0] * uCPrODisp->size[1];
      uCPrODisp->size[0] = 1;
      uCPrODisp->size[1] = iwork->size[0];
      emxEnsureCapacity_uint32_T(uCPrODisp, i89);
      qEnd = iwork->size[0];
      for (i89 = 0; i89 < qEnd; i89++) {
        uCPrODisp->data[i89] = (unsigned int)C->data[allC->data[iwork->data[i89]
          - 1] - 1];
      }

      if (NumRec[0] > 2147483646) {
        nm1d2 = MAX_int32_T;
      } else {
        nm1d2 = NumRec[0] + 1;
      }

      a = rt_roundd(d_sum(*(int (*)[2])&NumRec[0]));
      if (a < 2.147483648E+9) {
        if (a >= -2.147483648E+9) {
          i89 = (int)a;
        } else {
          i89 = MIN_int32_T;
        }
      } else {
        i89 = MAX_int32_T;
      }

      if (nm1d2 > i89) {
        i89 = -1;
      } else {
        i89 = nm1d2 - 2;
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
        i90 = (long long)PME->data[kEnd] * DispME->data[kEnd];
        if (i90 > 2147483647LL) {
          i90 = 2147483647LL;
        } else {
          if (i90 < -2147483648LL) {
            i90 = -2147483648LL;
          }
        }

        x->data[kEnd] = ((int)i90 != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        b_idx = 0;
        kEnd = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, kEnd);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          kEnd = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
      a = e_sum(*(int (*)[3])&NumRec[0]) + 1.0;
      b = g_sum(*(int (*)[4])&NumRec[0]);
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
        b_idx = 0;
        n = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, n);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          n = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
      a = g_sum(*(int (*)[4])&NumRec[0]) + 1.0;
      b = h_sum(*(int (*)[5])&NumRec[0]);
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

      k = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, k);
      for (k = 0; k < qEnd; k++) {
        x->data[k] = (PMAn->data[k] != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        b_idx = 0;
        k = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, k);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          k = j->size[0] * j->size[1];
          j->size[1] = b_idx;
          emxEnsureCapacity_int32_T(j, k);
        }
      }

      k = allAn->size[0] * allAn->size[1];
      allAn->size[0] = 1;
      allAn->size[1] = j->size[1];
      emxEnsureCapacity_int32_T(allAn, k);
      qEnd = j->size[0] * j->size[1];
      for (k = 0; k < qEnd; k++) {
        allAn->data[k] = j->data[k];
      }

      /*  Busco los posibles Anestesistas a usar. */
      a = d_sum(*(int (*)[2])&NumRec[0]) + 1.0;
      b = e_sum(*(int (*)[3])&NumRec[0]);
      if (a > b) {
        k = -1;
      } else {
        k = (int)a - 2;
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
        b_idx = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
        b_idx = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
        b_idx = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
      na = -1;
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
              * (i89 + (int)C->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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
              * (k + allS->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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

            a = i_sum(*(int (*)[6])&NumRec[0]);
            b_idx = b_H->size[0] * b_H->size[1];
            qEnd = q - p;
            b_H->size[0] = qEnd;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_int32_T(b_H, b_idx);
            nb = allCR->size[1];
            for (b_idx = 0; b_idx < nb; b_idx++) {
              for (nm1d2 = 0; nm1d2 < qEnd; nm1d2++) {
                b_H->data[nm1d2 + b_H->size[0] * b_idx] = H->data[(p + nm1d2) +
                  H->size[0] * ((int)(a + (double)allCR->data[b_idx]) - 1)];
              }
            }

            n_sum(b_H, r14);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r14->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r14->size[0] * r14->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r14->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              b_idx = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  b_idx++;
                  j->data[b_idx - 1] = nm1d2;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > b_idx) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = b_idx;
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
              b_idx = 0;
            } else {
              p = nm1d2 - 1;
              b_idx = q;
            }

            a = h_sum(*(int (*)[5])&NumRec[0]);
            nm1d2 = b_H->size[0] * b_H->size[1];
            qEnd = b_idx - p;
            b_H->size[0] = qEnd;
            b_H->size[1] = allCPO->size[1];
            emxEnsureCapacity_int32_T(b_H, nm1d2);
            nb = allCPO->size[1];
            for (b_idx = 0; b_idx < nb; b_idx++) {
              for (nm1d2 = 0; nm1d2 < qEnd; nm1d2++) {
                b_H->data[nm1d2 + b_H->size[0] * b_idx] = H->data[(p + nm1d2) +
                  H->size[0] * ((int)(a + (double)allCPO->data[b_idx]) - 1)];
              }
            }

            n_sum(b_H, r14);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r14->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r14->size[0] * r14->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r14->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              b_idx = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  b_idx++;
                  j->data[b_idx - 1] = nm1d2;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > b_idx) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = b_idx;
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
            a = i_sum(*(int (*)[6])&NumRec[0]);
            p = b_H->size[0] * b_H->size[1];
            b_H->size[0] = TimeUsoCR;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_int32_T(b_H, p);
            qEnd = allCR->size[1];
            for (p = 0; p < qEnd; p++) {
              for (b_idx = 0; b_idx < TimeUsoCR; b_idx++) {
                nb = 1 + b_idx;
                if ((q < 0) && (nb < MIN_int32_T - q)) {
                  nm1d2 = MIN_int32_T;
                } else if ((q > 0) && (nb > MAX_int32_T - q)) {
                  nm1d2 = MAX_int32_T;
                } else {
                  nm1d2 = q + nb;
                }

                b_H->data[b_idx + b_H->size[0] * p] = H->data[(nm1d2 + H->size[0]
                  * ((int)(a + (double)allCR->data[p]) - 1)) - 1];
              }
            }

            n_sum(b_H, r14);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r14->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r14->size[0] * r14->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r14->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              b_idx = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  b_idx++;
                  j->data[b_idx - 1] = nm1d2;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > b_idx) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = b_idx;
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
            na = (int)uCPrODisp->data[b_j];
            exitg2 = 1;
          } else {
            b_j++;
          }
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      if (na == -1) {
        i89 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        kEnd = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        tempUltPosRecXDia->size[0] = 1;
        emxEnsureCapacity_int32_T(tempUltPosRecXDia, kEnd);
        qEnd = i89 - 1;
        for (i89 = 0; i89 <= qEnd; i89++) {
          nm1d2 = tempUltPosRecXDia->data[i89];
          if (nm1d2 > 2147483646) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2++;
          }

          tempUltPosRecXDia->data[i89] = nm1d2;
        }
      } else {
        b_CPrOA = na;
        nm1d2 = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
        nb = tempUltPosRecXDia->data[na - 1];
        if ((nm1d2 < 0) && (nb < MIN_int32_T - nm1d2)) {
          qY = MIN_int32_T;
        } else if ((nm1d2 > 0) && (nb > MAX_int32_T - nm1d2)) {
          qY = MAX_int32_T;
        } else {
          qY = nm1d2 + nb;
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

        i89 = SA->size[0] * SA->size[1];
        SA->size[0] = 1;
        SA->size[1] = 1;
        emxEnsureCapacity_int32_T(SA, i89);
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

        i89 = EA->size[0] * EA->size[1];
        EA->size[0] = 1;
        EA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(EA, i89);
        for (i89 = 0; i89 < qEnd; i89++) {
          EA->data[i89] = (int)C->data[E->data[i89] - 1];
        }

        if (1 > PMA->data[PMA->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMA->data[PMA->size[1] - 1];
        }

        i89 = AA->size[0] * AA->size[1];
        AA->size[0] = 1;
        AA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AA, i89);
        for (i89 = 0; i89 < qEnd; i89++) {
          AA->data[i89] = allA->data[A->data[i89] - 1];
        }

        if (1 > PMAn->data[PMAn->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMAn->data[PMAn->size[1] - 1];
        }

        i89 = AnA->size[0] * AnA->size[1];
        AnA->size[0] = 1;
        AnA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AnA, i89);
        for (i89 = 0; i89 < qEnd; i89++) {
          AnA->data[i89] = allAn->data[An->data[i89] - 1];
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
  emxFree_real_T(&r14);
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

void d_funcionCPrO(const int NumRec[7], const emxArray_int32_T *PCPrO, const
                   emxArray_int32_T *PME, const emxArray_int32_T *PMA, const
                   emxArray_int32_T *PMAn, const emxArray_int32_T *PS, const
                   emxArray_int32_T *PCPO, const emxArray_int32_T *PCR, const
                   emxArray_real_T *H, const emxArray_int32_T *Dia, const
                   emxArray_int32_T *UltPosRecXDia, int TimeUsoCPrO, int
                   TimeUsoS, int TimeUsoCPO, int TimeUsoCR, int *contDia,
                   emxArray_int32_T *tempUltPosRecXDia, const emxArray_int32_T
                   *DispMExD, emxArray_int32_T *DispME, int *CPrOA, int
                   *IniCPrOA, int *EndCPrOA, int *EndCPrOAxD, emxArray_int32_T
                   *EA, emxArray_int32_T *AA, emxArray_int32_T *AnA,
                   emxArray_int32_T *SA, int *IniSA, int *EndSA, int *EndRPxD,
                   int *CPOA, int *IniCPOA, int *EndCPOA, int *CRA, int *IniCRA,
                   int *EndCRA)
{
  emxArray_int32_T *j;
  int nm1d2;
  emxArray_int32_T *E;
  int i98;
  double a;
  double b;
  emxArray_real_T *r17;
  double ndbl;
  double apnd;
  double cdiff;
  emxArray_int32_T *S;
  int qEnd;
  int n;
  emxArray_real_T *C;
  emxArray_int32_T *A;
  int k;
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
  int b_idx;
  boolean_T exitg1;
  int nb;
  int q;
  int na;
  int b_j;
  int p;
  long long i99;
  int exitg2;
  emxInit_int32_T(&j, 2);
  if (NumRec[0] > 2147483646) {
    nm1d2 = MAX_int32_T;
  } else {
    nm1d2 = NumRec[0] + 1;
  }

  eml_signed_integer_colon(nm1d2, (int)d_sum(*(int (*)[2])&NumRec[0]), j);
  nm1d2 = j->size[1];
  emxInit_int32_T(&E, 2);
  if (nm1d2 < 1) {
    E->size[0] = 1;
    E->size[1] = 0;
  } else {
    i98 = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = nm1d2;
    emxEnsureCapacity_int32_T(E, i98);
    for (i98 = 0; i98 < nm1d2; i98++) {
      E->data[i98] = 1 + i98;
    }
  }

  a = d_sum(*(int (*)[2])&NumRec[0]) + 1.0;
  b = e_sum(*(int (*)[3])&NumRec[0]);
  emxInit_real_T(&r17, 2);
  if (b < a) {
    i98 = r17->size[0] * r17->size[1];
    r17->size[1] = 0;
    emxEnsureCapacity_real_T(r17, i98);
  } else if (floor(a) == a) {
    i98 = r17->size[0] * r17->size[1];
    r17->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(r17, i98);
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

    i98 = r17->size[0] * r17->size[1];
    r17->size[0] = 1;
    r17->size[1] = n;
    emxEnsureCapacity_real_T(r17, i98);
    if ((n > 0) && (n > 1)) {
      r17->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (k = 0; k <= nm1d2 - 2; k++) {
        r17->data[1 + k] = a + (1.0 + (double)k);
        r17->data[(n - k) - 2] = apnd - (1.0 + (double)k);
      }

      if (nm1d2 << 1 == n - 1) {
        r17->data[nm1d2] = (a + apnd) / 2.0;
      } else {
        r17->data[nm1d2] = a + (double)nm1d2;
        r17->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_int32_T(&S, 2);
  if (r17->size[1] < 1) {
    S->size[0] = 1;
    S->size[1] = 0;
  } else {
    qEnd = r17->size[1];
    i98 = S->size[0] * S->size[1];
    S->size[0] = 1;
    S->size[1] = qEnd;
    emxEnsureCapacity_int32_T(S, i98);
    for (i98 = 0; i98 < qEnd; i98++) {
      S->data[i98] = 1 + i98;
    }
  }

  a = e_sum(*(int (*)[3])&NumRec[0]) + 1.0;
  b = g_sum(*(int (*)[4])&NumRec[0]);
  emxInit_real_T(&C, 2);
  if (b < a) {
    i98 = C->size[0] * C->size[1];
    C->size[1] = 0;
    emxEnsureCapacity_real_T(C, i98);
  } else if (floor(a) == a) {
    i98 = C->size[0] * C->size[1];
    C->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(C, i98);
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

    i98 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = n;
    emxEnsureCapacity_real_T(C, i98);
    if (n > 0) {
      C->data[0] = a;
      if (n > 1) {
        C->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 0; k <= nm1d2 - 2; k++) {
          C->data[1 + k] = a + (1.0 + (double)k);
          C->data[(n - k) - 2] = apnd - (1.0 + (double)k);
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
    i98 = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = qEnd;
    emxEnsureCapacity_int32_T(A, i98);
    for (i98 = 0; i98 < qEnd; i98++) {
      A->data[i98] = 1 + i98;
    }
  }

  a = g_sum(*(int (*)[4])&NumRec[0]) + 1.0;
  b = h_sum(*(int (*)[5])&NumRec[0]);
  emxInit_real_T(&CR, 2);
  if (b < a) {
    i98 = CR->size[0] * CR->size[1];
    CR->size[1] = 0;
    emxEnsureCapacity_real_T(CR, i98);
  } else if (floor(a) == a) {
    i98 = CR->size[0] * CR->size[1];
    CR->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(CR, i98);
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

    i98 = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    CR->size[1] = n;
    emxEnsureCapacity_real_T(CR, i98);
    if (n > 0) {
      CR->data[0] = a;
      if (n > 1) {
        CR->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 0; k <= nm1d2 - 2; k++) {
          CR->data[1 + k] = a + (1.0 + (double)k);
          CR->data[(n - k) - 2] = apnd - (1.0 + (double)k);
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
    i98 = An->size[0] * An->size[1];
    An->size[0] = 1;
    An->size[1] = qEnd;
    emxEnsureCapacity_int32_T(An, i98);
    for (i98 = 0; i98 < qEnd; i98++) {
      An->data[i98] = 1 + i98;
    }
  }

  emxInit_int32_T(&CPO, 2);
  if (PCPO->size[1] < 1) {
    CPO->size[0] = 1;
    CPO->size[1] = 0;
  } else {
    qEnd = PCPO->size[1];
    i98 = CPO->size[0] * CPO->size[1];
    CPO->size[0] = 1;
    CPO->size[1] = qEnd;
    emxEnsureCapacity_int32_T(CPO, i98);
    for (i98 = 0; i98 < qEnd; i98++) {
      CPO->data[i98] = 1 + i98;
    }
  }

  if (PCR->size[1] < 1) {
    CR->size[0] = 1;
    CR->size[1] = 0;
  } else {
    i98 = PCR->size[1];
    kEnd = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    qEnd = (int)((double)i98 - 1.0);
    CR->size[1] = qEnd + 1;
    emxEnsureCapacity_real_T(CR, kEnd);
    for (i98 = 0; i98 <= qEnd; i98++) {
      CR->data[i98] = 1.0 + (double)i98;
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
    i98 = EA->size[0] * EA->size[1];
    EA->size[0] = 1;
    EA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(EA, i98);
    for (i98 = 0; i98 <= qEnd; i98++) {
      EA->data[i98] = 1 + i98;
    }
  }

  if (PMA->size[1] - 1 < 1) {
    AA->size[0] = 1;
    AA->size[1] = 0;
  } else {
    qEnd = PMA->size[1] - 2;
    i98 = AA->size[0] * AA->size[1];
    AA->size[0] = 1;
    AA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AA, i98);
    for (i98 = 0; i98 <= qEnd; i98++) {
      AA->data[i98] = 1 + i98;
    }
  }

  if (PMAn->size[1] - 1 < 1) {
    AnA->size[0] = 1;
    AnA->size[1] = 0;
  } else {
    qEnd = PMAn->size[1] - 2;
    i98 = AnA->size[0] * AnA->size[1];
    AnA->size[0] = 1;
    AnA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AnA, i98);
    for (i98 = 0; i98 <= qEnd; i98++) {
      AnA->data[i98] = 1 + i98;
    }
  }

  if (PS->size[1] - 1 < 1) {
    SA->size[0] = 1;
    SA->size[1] = 0;
  } else {
    qEnd = PS->size[1] - 2;
    i98 = SA->size[0] * SA->size[1];
    SA->size[0] = 1;
    SA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(SA, i98);
    for (i98 = 0; i98 <= qEnd; i98++) {
      SA->data[i98] = 1 + i98;
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
    i98 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = PCPrO->size[1];
    emxEnsureCapacity_boolean_T(x, i98);
    qEnd = PCPrO->size[0] * PCPrO->size[1];
    for (i98 = 0; i98 < qEnd; i98++) {
      x->data[i98] = (PCPrO->data[i98] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i98 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i98);
      nm1d2 = 1;
      exitg1 = false;
      while ((!exitg1) && (nm1d2 <= x->size[1])) {
        if (x->data[nm1d2 - 1]) {
          b_idx++;
          j->data[b_idx - 1] = nm1d2;
          if (b_idx >= x->size[1]) {
            exitg1 = true;
          } else {
            nm1d2++;
          }
        } else {
          nm1d2++;
        }
      }

      if (x->size[1] == 1) {
        if (b_idx == 0) {
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > b_idx) {
        j->size[1] = 0;
      } else {
        i98 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i98);
      }
    }

    i98 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = j->size[1];
    emxEnsureCapacity_real_T(C, i98);
    qEnd = j->size[0] * j->size[1];
    for (i98 = 0; i98 < qEnd; i98++) {
      C->data[i98] = j->data[i98];
    }

    /*  Busco las posibles camas a usar. */
    nm1d2 = Dia->data[(*contDia + Dia->size[0] * 3) - 1];
    nb = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
    if ((nm1d2 >= 0) && (nb < nm1d2 - MAX_int32_T)) {
      nm1d2 = MAX_int32_T;
    } else if ((nm1d2 < 0) && (nb > nm1d2 - MIN_int32_T)) {
      nm1d2 = MIN_int32_T;
    } else {
      nm1d2 -= nb;
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
    i98 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = C->size[1];
    emxEnsureCapacity_boolean_T(x, i98);
    qEnd = C->size[0] * C->size[1];
    for (i98 = 0; i98 < qEnd; i98++) {
      x->data[i98] = (tempUltPosRecXDia->data[(int)C->data[i98] - 1] <= nm1d2);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i98 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i98);
      nm1d2 = 1;
      exitg1 = false;
      while ((!exitg1) && (nm1d2 <= x->size[1])) {
        if (x->data[nm1d2 - 1]) {
          b_idx++;
          j->data[b_idx - 1] = nm1d2;
          if (b_idx >= x->size[1]) {
            exitg1 = true;
          } else {
            nm1d2++;
          }
        } else {
          nm1d2++;
        }
      }

      if (x->size[1] == 1) {
        if (b_idx == 0) {
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > b_idx) {
        j->size[1] = 0;
      } else {
        i98 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i98);
      }
    }

    i98 = allC->size[0] * allC->size[1];
    allC->size[0] = 1;
    allC->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(allC, i98);
    qEnd = j->size[0] * j->size[1];
    for (i98 = 0; i98 < qEnd; i98++) {
      allC->data[i98] = j->data[i98];
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
      i98 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(j, i98);
      qEnd = allC->size[0] * allC->size[1];
      for (i98 = 0; i98 < qEnd; i98++) {
        j->data[i98] = tempUltPosRecXDia->data[(int)(unsigned int)C->data
          [allC->data[i98] - 1] - 1];
      }

      na = allC->size[1];
      n = allC->size[1] + 1;
      i98 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(idx, i98);
      qEnd = allC->size[1];
      for (i98 = 0; i98 < qEnd; i98++) {
        idx->data[i98] = 0;
      }

      i98 = iwork->size[0];
      iwork->size[0] = allC->size[1];
      emxEnsureCapacity_int32_T(iwork, i98);
      i98 = allC->size[1] - 1;
      for (k = 1; k <= i98; k += 2) {
        if (j->data[k - 1] <= j->data[k]) {
          idx->data[k - 1] = k;
          idx->data[k] = k + 1;
        } else {
          idx->data[k - 1] = k + 1;
          idx->data[k] = k;
        }
      }

      if ((allC->size[1] & 1) != 0) {
        idx->data[allC->size[1] - 1] = allC->size[1];
      }

      nm1d2 = 2;
      while (nm1d2 < n - 1) {
        nb = nm1d2 << 1;
        b_j = 1;
        for (b_idx = 1 + nm1d2; b_idx < n; b_idx = qEnd + nm1d2) {
          p = b_j;
          q = b_idx;
          qEnd = b_j + nb;
          if (qEnd > n) {
            qEnd = n;
          }

          k = 0;
          kEnd = qEnd - b_j;
          while (k + 1 <= kEnd) {
            if (j->data[idx->data[p - 1] - 1] <= j->data[idx->data[q - 1] - 1])
            {
              iwork->data[k] = idx->data[p - 1];
              p++;
              if (p == b_idx) {
                while (q < qEnd) {
                  k++;
                  iwork->data[k] = idx->data[q - 1];
                  q++;
                }
              }
            } else {
              iwork->data[k] = idx->data[q - 1];
              q++;
              if (q == qEnd) {
                while (p < b_idx) {
                  k++;
                  iwork->data[k] = idx->data[p - 1];
                  p++;
                }
              }
            }

            k++;
          }

          for (k = 0; k < kEnd; k++) {
            idx->data[(b_j + k) - 1] = iwork->data[k];
          }

          b_j = qEnd;
        }

        nm1d2 = nb;
      }

      i98 = b_b->size[0] * b_b->size[1];
      b_b->size[0] = 1;
      b_b->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(b_b, i98);
      for (k = 0; k < na; k++) {
        b_b->data[k] = j->data[idx->data[k] - 1];
      }

      nb = -1;
      k = 0;
      while (k + 1 <= na) {
        nm1d2 = b_b->data[k];
        b_idx = k;
        do {
          k++;
        } while (!((k + 1 > na) || (b_b->data[k] != nm1d2)));

        nb++;
        b_b->data[nb] = nm1d2;
        idx->data[nb] = idx->data[b_idx];
      }

      i98 = iwork->size[0];
      iwork->size[0] = nb + 1;
      emxEnsureCapacity_int32_T(iwork, i98);
      for (k = 0; k <= nb; k++) {
        iwork->data[k] = idx->data[k];
      }

      i98 = uCPrODisp->size[0] * uCPrODisp->size[1];
      uCPrODisp->size[0] = 1;
      uCPrODisp->size[1] = iwork->size[0];
      emxEnsureCapacity_uint32_T(uCPrODisp, i98);
      qEnd = iwork->size[0];
      for (i98 = 0; i98 < qEnd; i98++) {
        uCPrODisp->data[i98] = (unsigned int)C->data[allC->data[iwork->data[i98]
          - 1] - 1];
      }

      if (NumRec[0] > 2147483646) {
        nm1d2 = MAX_int32_T;
      } else {
        nm1d2 = NumRec[0] + 1;
      }

      a = rt_roundd(d_sum(*(int (*)[2])&NumRec[0]));
      if (a < 2.147483648E+9) {
        if (a >= -2.147483648E+9) {
          i98 = (int)a;
        } else {
          i98 = MIN_int32_T;
        }
      } else {
        i98 = MAX_int32_T;
      }

      if (nm1d2 > i98) {
        i98 = -1;
      } else {
        i98 = nm1d2 - 2;
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
        i99 = (long long)PME->data[kEnd] * DispME->data[kEnd];
        if (i99 > 2147483647LL) {
          i99 = 2147483647LL;
        } else {
          if (i99 < -2147483648LL) {
            i99 = -2147483648LL;
          }
        }

        x->data[kEnd] = ((int)i99 != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        b_idx = 0;
        kEnd = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, kEnd);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          kEnd = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
      a = e_sum(*(int (*)[3])&NumRec[0]) + 1.0;
      b = g_sum(*(int (*)[4])&NumRec[0]);
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
        b_idx = 0;
        n = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, n);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          n = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
      a = g_sum(*(int (*)[4])&NumRec[0]) + 1.0;
      b = h_sum(*(int (*)[5])&NumRec[0]);
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

      k = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, k);
      for (k = 0; k < qEnd; k++) {
        x->data[k] = (PMAn->data[k] != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        b_idx = 0;
        k = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, k);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          k = j->size[0] * j->size[1];
          j->size[1] = b_idx;
          emxEnsureCapacity_int32_T(j, k);
        }
      }

      k = allAn->size[0] * allAn->size[1];
      allAn->size[0] = 1;
      allAn->size[1] = j->size[1];
      emxEnsureCapacity_int32_T(allAn, k);
      qEnd = j->size[0] * j->size[1];
      for (k = 0; k < qEnd; k++) {
        allAn->data[k] = j->data[k];
      }

      /*  Busco los posibles Anestesistas a usar. */
      a = d_sum(*(int (*)[2])&NumRec[0]) + 1.0;
      b = e_sum(*(int (*)[3])&NumRec[0]);
      if (a > b) {
        k = -1;
      } else {
        k = (int)a - 2;
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
        b_idx = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
        b_idx = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
        b_idx = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
      na = -1;
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
              * (i98 + (int)C->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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
              * (k + allS->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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

            a = i_sum(*(int (*)[6])&NumRec[0]);
            b_idx = b_H->size[0] * b_H->size[1];
            qEnd = q - p;
            b_H->size[0] = qEnd;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_real_T(b_H, b_idx);
            nb = allCR->size[1];
            for (b_idx = 0; b_idx < nb; b_idx++) {
              for (nm1d2 = 0; nm1d2 < qEnd; nm1d2++) {
                b_H->data[nm1d2 + b_H->size[0] * b_idx] = H->data[(p + nm1d2) +
                  H->size[0] * ((int)(a + (double)allCR->data[b_idx]) - 1)];
              }
            }

            j_sum(b_H, r17);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r17->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r17->size[0] * r17->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r17->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              b_idx = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  b_idx++;
                  j->data[b_idx - 1] = nm1d2;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > b_idx) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = b_idx;
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
              b_idx = 0;
            } else {
              p = nm1d2 - 1;
              b_idx = q;
            }

            a = h_sum(*(int (*)[5])&NumRec[0]);
            nm1d2 = b_H->size[0] * b_H->size[1];
            qEnd = b_idx - p;
            b_H->size[0] = qEnd;
            b_H->size[1] = allCPO->size[1];
            emxEnsureCapacity_real_T(b_H, nm1d2);
            nb = allCPO->size[1];
            for (b_idx = 0; b_idx < nb; b_idx++) {
              for (nm1d2 = 0; nm1d2 < qEnd; nm1d2++) {
                b_H->data[nm1d2 + b_H->size[0] * b_idx] = H->data[(p + nm1d2) +
                  H->size[0] * ((int)(a + (double)allCPO->data[b_idx]) - 1)];
              }
            }

            j_sum(b_H, r17);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r17->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r17->size[0] * r17->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r17->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              b_idx = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  b_idx++;
                  j->data[b_idx - 1] = nm1d2;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > b_idx) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = b_idx;
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
            a = i_sum(*(int (*)[6])&NumRec[0]);
            p = b_H->size[0] * b_H->size[1];
            b_H->size[0] = TimeUsoCR;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_real_T(b_H, p);
            qEnd = allCR->size[1];
            for (p = 0; p < qEnd; p++) {
              for (b_idx = 0; b_idx < TimeUsoCR; b_idx++) {
                nb = 1 + b_idx;
                if ((q < 0) && (nb < MIN_int32_T - q)) {
                  nm1d2 = MIN_int32_T;
                } else if ((q > 0) && (nb > MAX_int32_T - q)) {
                  nm1d2 = MAX_int32_T;
                } else {
                  nm1d2 = q + nb;
                }

                b_H->data[b_idx + b_H->size[0] * p] = H->data[(nm1d2 + H->size[0]
                  * ((int)(a + (double)allCR->data[p]) - 1)) - 1];
              }
            }

            j_sum(b_H, r17);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r17->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r17->size[0] * r17->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r17->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              b_idx = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  b_idx++;
                  j->data[b_idx - 1] = nm1d2;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > b_idx) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = b_idx;
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
            na = (int)uCPrODisp->data[b_j];
            exitg2 = 1;
          } else {
            b_j++;
          }
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      if (na == -1) {
        i98 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        kEnd = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        tempUltPosRecXDia->size[0] = 1;
        emxEnsureCapacity_int32_T(tempUltPosRecXDia, kEnd);
        qEnd = i98 - 1;
        for (i98 = 0; i98 <= qEnd; i98++) {
          nm1d2 = tempUltPosRecXDia->data[i98];
          if (nm1d2 > 2147483646) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2++;
          }

          tempUltPosRecXDia->data[i98] = nm1d2;
        }
      } else {
        b_CPrOA = na;
        nm1d2 = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
        nb = tempUltPosRecXDia->data[na - 1];
        if ((nm1d2 < 0) && (nb < MIN_int32_T - nm1d2)) {
          qY = MIN_int32_T;
        } else if ((nm1d2 > 0) && (nb > MAX_int32_T - nm1d2)) {
          qY = MAX_int32_T;
        } else {
          qY = nm1d2 + nb;
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

        i98 = SA->size[0] * SA->size[1];
        SA->size[0] = 1;
        SA->size[1] = 1;
        emxEnsureCapacity_int32_T(SA, i98);
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

        i98 = EA->size[0] * EA->size[1];
        EA->size[0] = 1;
        EA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(EA, i98);
        for (i98 = 0; i98 < qEnd; i98++) {
          EA->data[i98] = (int)C->data[E->data[i98] - 1];
        }

        if (1 > PMA->data[PMA->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMA->data[PMA->size[1] - 1];
        }

        i98 = AA->size[0] * AA->size[1];
        AA->size[0] = 1;
        AA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AA, i98);
        for (i98 = 0; i98 < qEnd; i98++) {
          AA->data[i98] = allA->data[A->data[i98] - 1];
        }

        if (1 > PMAn->data[PMAn->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMAn->data[PMAn->size[1] - 1];
        }

        i98 = AnA->size[0] * AnA->size[1];
        AnA->size[0] = 1;
        AnA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AnA, i98);
        for (i98 = 0; i98 < qEnd; i98++) {
          AnA->data[i98] = allAn->data[An->data[i98] - 1];
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
  emxFree_real_T(&r17);
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

void e_funcionCPrO(const int NumRec[7], const emxArray_int32_T *PCPrO, const
                   emxArray_int32_T *PME, const emxArray_int32_T *PMA, const
                   emxArray_int32_T *PMAn, const emxArray_int32_T *PS, const
                   emxArray_int32_T *PCPO, const emxArray_int32_T *PCR, const
                   emxArray_real_T *H, const emxArray_int32_T *Dia, const
                   emxArray_real_T *UltPosRecXDia, int TimeUsoCPrO, int TimeUsoS,
                   int TimeUsoCPO, int TimeUsoCR, int *contDia, emxArray_int32_T
                   *tempUltPosRecXDia, const emxArray_int32_T *DispMExD, int
                   DispME, int *CPrOA, int *IniCPrOA, int *EndCPrOA, int
                   *EndCPrOAxD, emxArray_int32_T *EA, emxArray_int32_T *AA,
                   emxArray_int32_T *AnA, emxArray_int32_T *SA, int *IniSA, int *
                   EndSA, int *EndRPxD, int *CPOA, int *IniCPOA, int *EndCPOA,
                   int *CRA, int *IniCRA, int *EndCRA)
{
  emxArray_int32_T *j;
  int nm1d2;
  emxArray_int32_T *E;
  int i106;
  double a;
  double b;
  emxArray_real_T *r19;
  double ndbl;
  double apnd;
  double cdiff;
  emxArray_int32_T *S;
  int qEnd;
  int n;
  emxArray_real_T *C;
  emxArray_int32_T *A;
  int k;
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
  int b_idx;
  boolean_T exitg1;
  int nb;
  int q;
  int na;
  int b_j;
  int p;
  long long i107;
  int exitg2;
  emxInit_int32_T(&j, 2);
  if (NumRec[0] > 2147483646) {
    nm1d2 = MAX_int32_T;
  } else {
    nm1d2 = NumRec[0] + 1;
  }

  eml_signed_integer_colon(nm1d2, (int)d_sum(*(int (*)[2])&NumRec[0]), j);
  nm1d2 = j->size[1];
  emxInit_int32_T(&E, 2);
  if (nm1d2 < 1) {
    E->size[0] = 1;
    E->size[1] = 0;
  } else {
    i106 = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = nm1d2;
    emxEnsureCapacity_int32_T(E, i106);
    for (i106 = 0; i106 < nm1d2; i106++) {
      E->data[i106] = 1 + i106;
    }
  }

  a = d_sum(*(int (*)[2])&NumRec[0]) + 1.0;
  b = e_sum(*(int (*)[3])&NumRec[0]);
  emxInit_real_T(&r19, 2);
  if (b < a) {
    i106 = r19->size[0] * r19->size[1];
    r19->size[1] = 0;
    emxEnsureCapacity_real_T(r19, i106);
  } else if (floor(a) == a) {
    i106 = r19->size[0] * r19->size[1];
    r19->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(r19, i106);
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

    i106 = r19->size[0] * r19->size[1];
    r19->size[0] = 1;
    r19->size[1] = n;
    emxEnsureCapacity_real_T(r19, i106);
    if ((n > 0) && (n > 1)) {
      r19->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (k = 0; k <= nm1d2 - 2; k++) {
        r19->data[1 + k] = a + (1.0 + (double)k);
        r19->data[(n - k) - 2] = apnd - (1.0 + (double)k);
      }

      if (nm1d2 << 1 == n - 1) {
        r19->data[nm1d2] = (a + apnd) / 2.0;
      } else {
        r19->data[nm1d2] = a + (double)nm1d2;
        r19->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_int32_T(&S, 2);
  if (r19->size[1] < 1) {
    S->size[0] = 1;
    S->size[1] = 0;
  } else {
    qEnd = r19->size[1];
    i106 = S->size[0] * S->size[1];
    S->size[0] = 1;
    S->size[1] = qEnd;
    emxEnsureCapacity_int32_T(S, i106);
    for (i106 = 0; i106 < qEnd; i106++) {
      S->data[i106] = 1 + i106;
    }
  }

  a = e_sum(*(int (*)[3])&NumRec[0]) + 1.0;
  b = g_sum(*(int (*)[4])&NumRec[0]);
  emxInit_real_T(&C, 2);
  if (b < a) {
    i106 = C->size[0] * C->size[1];
    C->size[1] = 0;
    emxEnsureCapacity_real_T(C, i106);
  } else if (floor(a) == a) {
    i106 = C->size[0] * C->size[1];
    C->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(C, i106);
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

    i106 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = n;
    emxEnsureCapacity_real_T(C, i106);
    if (n > 0) {
      C->data[0] = a;
      if (n > 1) {
        C->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 0; k <= nm1d2 - 2; k++) {
          C->data[1 + k] = a + (1.0 + (double)k);
          C->data[(n - k) - 2] = apnd - (1.0 + (double)k);
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
    i106 = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = qEnd;
    emxEnsureCapacity_int32_T(A, i106);
    for (i106 = 0; i106 < qEnd; i106++) {
      A->data[i106] = 1 + i106;
    }
  }

  a = g_sum(*(int (*)[4])&NumRec[0]) + 1.0;
  b = h_sum(*(int (*)[5])&NumRec[0]);
  emxInit_real_T(&CR, 2);
  if (b < a) {
    i106 = CR->size[0] * CR->size[1];
    CR->size[1] = 0;
    emxEnsureCapacity_real_T(CR, i106);
  } else if (floor(a) == a) {
    i106 = CR->size[0] * CR->size[1];
    CR->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(CR, i106);
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

    i106 = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    CR->size[1] = n;
    emxEnsureCapacity_real_T(CR, i106);
    if (n > 0) {
      CR->data[0] = a;
      if (n > 1) {
        CR->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 0; k <= nm1d2 - 2; k++) {
          CR->data[1 + k] = a + (1.0 + (double)k);
          CR->data[(n - k) - 2] = apnd - (1.0 + (double)k);
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
    i106 = An->size[0] * An->size[1];
    An->size[0] = 1;
    An->size[1] = qEnd;
    emxEnsureCapacity_int32_T(An, i106);
    for (i106 = 0; i106 < qEnd; i106++) {
      An->data[i106] = 1 + i106;
    }
  }

  emxInit_int32_T(&CPO, 2);
  if (PCPO->size[1] < 1) {
    CPO->size[0] = 1;
    CPO->size[1] = 0;
  } else {
    qEnd = PCPO->size[1];
    i106 = CPO->size[0] * CPO->size[1];
    CPO->size[0] = 1;
    CPO->size[1] = qEnd;
    emxEnsureCapacity_int32_T(CPO, i106);
    for (i106 = 0; i106 < qEnd; i106++) {
      CPO->data[i106] = 1 + i106;
    }
  }

  if (PCR->size[1] < 1) {
    CR->size[0] = 1;
    CR->size[1] = 0;
  } else {
    i106 = PCR->size[1];
    kEnd = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    qEnd = (int)((double)i106 - 1.0);
    CR->size[1] = qEnd + 1;
    emxEnsureCapacity_real_T(CR, kEnd);
    for (i106 = 0; i106 <= qEnd; i106++) {
      CR->data[i106] = 1.0 + (double)i106;
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
    i106 = EA->size[0] * EA->size[1];
    EA->size[0] = 1;
    EA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(EA, i106);
    for (i106 = 0; i106 <= qEnd; i106++) {
      EA->data[i106] = 1 + i106;
    }
  }

  if (PMA->size[1] - 1 < 1) {
    AA->size[0] = 1;
    AA->size[1] = 0;
  } else {
    qEnd = PMA->size[1] - 2;
    i106 = AA->size[0] * AA->size[1];
    AA->size[0] = 1;
    AA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AA, i106);
    for (i106 = 0; i106 <= qEnd; i106++) {
      AA->data[i106] = 1 + i106;
    }
  }

  if (PMAn->size[1] - 1 < 1) {
    AnA->size[0] = 1;
    AnA->size[1] = 0;
  } else {
    qEnd = PMAn->size[1] - 2;
    i106 = AnA->size[0] * AnA->size[1];
    AnA->size[0] = 1;
    AnA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AnA, i106);
    for (i106 = 0; i106 <= qEnd; i106++) {
      AnA->data[i106] = 1 + i106;
    }
  }

  if (PS->size[1] - 1 < 1) {
    SA->size[0] = 1;
    SA->size[1] = 0;
  } else {
    qEnd = PS->size[1] - 2;
    i106 = SA->size[0] * SA->size[1];
    SA->size[0] = 1;
    SA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(SA, i106);
    for (i106 = 0; i106 <= qEnd; i106++) {
      SA->data[i106] = 1 + i106;
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
    i106 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = PCPrO->size[1];
    emxEnsureCapacity_boolean_T(x, i106);
    qEnd = PCPrO->size[0] * PCPrO->size[1];
    for (i106 = 0; i106 < qEnd; i106++) {
      x->data[i106] = (PCPrO->data[i106] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i106 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i106);
      nm1d2 = 1;
      exitg1 = false;
      while ((!exitg1) && (nm1d2 <= x->size[1])) {
        if (x->data[nm1d2 - 1]) {
          b_idx++;
          j->data[b_idx - 1] = nm1d2;
          if (b_idx >= x->size[1]) {
            exitg1 = true;
          } else {
            nm1d2++;
          }
        } else {
          nm1d2++;
        }
      }

      if (x->size[1] == 1) {
        if (b_idx == 0) {
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > b_idx) {
        j->size[1] = 0;
      } else {
        i106 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i106);
      }
    }

    i106 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = j->size[1];
    emxEnsureCapacity_real_T(C, i106);
    qEnd = j->size[0] * j->size[1];
    for (i106 = 0; i106 < qEnd; i106++) {
      C->data[i106] = j->data[i106];
    }

    /*  Busco las posibles camas a usar. */
    nm1d2 = Dia->data[(*contDia + Dia->size[0] * 3) - 1];
    nb = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
    if ((nm1d2 >= 0) && (nb < nm1d2 - MAX_int32_T)) {
      nm1d2 = MAX_int32_T;
    } else if ((nm1d2 < 0) && (nb > nm1d2 - MIN_int32_T)) {
      nm1d2 = MIN_int32_T;
    } else {
      nm1d2 -= nb;
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
    i106 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = C->size[1];
    emxEnsureCapacity_boolean_T(x, i106);
    qEnd = C->size[0] * C->size[1];
    for (i106 = 0; i106 < qEnd; i106++) {
      x->data[i106] = (tempUltPosRecXDia->data[(int)C->data[i106] - 1] <= nm1d2);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i106 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i106);
      nm1d2 = 1;
      exitg1 = false;
      while ((!exitg1) && (nm1d2 <= x->size[1])) {
        if (x->data[nm1d2 - 1]) {
          b_idx++;
          j->data[b_idx - 1] = nm1d2;
          if (b_idx >= x->size[1]) {
            exitg1 = true;
          } else {
            nm1d2++;
          }
        } else {
          nm1d2++;
        }
      }

      if (x->size[1] == 1) {
        if (b_idx == 0) {
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > b_idx) {
        j->size[1] = 0;
      } else {
        i106 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i106);
      }
    }

    i106 = allC->size[0] * allC->size[1];
    allC->size[0] = 1;
    allC->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(allC, i106);
    qEnd = j->size[0] * j->size[1];
    for (i106 = 0; i106 < qEnd; i106++) {
      allC->data[i106] = j->data[i106];
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

      d_funcionDia(NumRec, PCPrO, Dia, UltPosRecXDia, TimeUsoCPrO, TimeUsoS,
                   contDia, DispMExD, tempUltPosRecXDia, &DispME);
    } else {
      i106 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(j, i106);
      qEnd = allC->size[0] * allC->size[1];
      for (i106 = 0; i106 < qEnd; i106++) {
        j->data[i106] = tempUltPosRecXDia->data[(int)(unsigned int)C->data
          [allC->data[i106] - 1] - 1];
      }

      na = allC->size[1];
      n = allC->size[1] + 1;
      i106 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(idx, i106);
      qEnd = allC->size[1];
      for (i106 = 0; i106 < qEnd; i106++) {
        idx->data[i106] = 0;
      }

      i106 = iwork->size[0];
      iwork->size[0] = allC->size[1];
      emxEnsureCapacity_int32_T(iwork, i106);
      i106 = allC->size[1] - 1;
      for (k = 1; k <= i106; k += 2) {
        if (j->data[k - 1] <= j->data[k]) {
          idx->data[k - 1] = k;
          idx->data[k] = k + 1;
        } else {
          idx->data[k - 1] = k + 1;
          idx->data[k] = k;
        }
      }

      if ((allC->size[1] & 1) != 0) {
        idx->data[allC->size[1] - 1] = allC->size[1];
      }

      nm1d2 = 2;
      while (nm1d2 < n - 1) {
        nb = nm1d2 << 1;
        b_j = 1;
        for (b_idx = 1 + nm1d2; b_idx < n; b_idx = qEnd + nm1d2) {
          p = b_j;
          q = b_idx;
          qEnd = b_j + nb;
          if (qEnd > n) {
            qEnd = n;
          }

          k = 0;
          kEnd = qEnd - b_j;
          while (k + 1 <= kEnd) {
            if (j->data[idx->data[p - 1] - 1] <= j->data[idx->data[q - 1] - 1])
            {
              iwork->data[k] = idx->data[p - 1];
              p++;
              if (p == b_idx) {
                while (q < qEnd) {
                  k++;
                  iwork->data[k] = idx->data[q - 1];
                  q++;
                }
              }
            } else {
              iwork->data[k] = idx->data[q - 1];
              q++;
              if (q == qEnd) {
                while (p < b_idx) {
                  k++;
                  iwork->data[k] = idx->data[p - 1];
                  p++;
                }
              }
            }

            k++;
          }

          for (k = 0; k < kEnd; k++) {
            idx->data[(b_j + k) - 1] = iwork->data[k];
          }

          b_j = qEnd;
        }

        nm1d2 = nb;
      }

      i106 = b_b->size[0] * b_b->size[1];
      b_b->size[0] = 1;
      b_b->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(b_b, i106);
      for (k = 0; k < na; k++) {
        b_b->data[k] = j->data[idx->data[k] - 1];
      }

      nb = -1;
      k = 0;
      while (k + 1 <= na) {
        nm1d2 = b_b->data[k];
        b_idx = k;
        do {
          k++;
        } while (!((k + 1 > na) || (b_b->data[k] != nm1d2)));

        nb++;
        b_b->data[nb] = nm1d2;
        idx->data[nb] = idx->data[b_idx];
      }

      i106 = iwork->size[0];
      iwork->size[0] = nb + 1;
      emxEnsureCapacity_int32_T(iwork, i106);
      for (k = 0; k <= nb; k++) {
        iwork->data[k] = idx->data[k];
      }

      i106 = uCPrODisp->size[0] * uCPrODisp->size[1];
      uCPrODisp->size[0] = 1;
      uCPrODisp->size[1] = iwork->size[0];
      emxEnsureCapacity_uint32_T(uCPrODisp, i106);
      qEnd = iwork->size[0];
      for (i106 = 0; i106 < qEnd; i106++) {
        uCPrODisp->data[i106] = (unsigned int)C->data[allC->data[iwork->
          data[i106] - 1] - 1];
      }

      if (NumRec[0] > 2147483646) {
        nm1d2 = MAX_int32_T;
      } else {
        nm1d2 = NumRec[0] + 1;
      }

      a = rt_roundd(d_sum(*(int (*)[2])&NumRec[0]));
      if (a < 2.147483648E+9) {
        if (a >= -2.147483648E+9) {
          i106 = (int)a;
        } else {
          i106 = MIN_int32_T;
        }
      } else {
        i106 = MAX_int32_T;
      }

      if (nm1d2 > i106) {
        i106 = -1;
      } else {
        i106 = nm1d2 - 2;
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
        i107 = (long long)PME->data[kEnd] * DispME;
        if (i107 > 2147483647LL) {
          i107 = 2147483647LL;
        } else {
          if (i107 < -2147483648LL) {
            i107 = -2147483648LL;
          }
        }

        x->data[kEnd] = ((int)i107 != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        b_idx = 0;
        kEnd = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, kEnd);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          kEnd = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
      a = e_sum(*(int (*)[3])&NumRec[0]) + 1.0;
      b = g_sum(*(int (*)[4])&NumRec[0]);
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
        b_idx = 0;
        n = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, n);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          n = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
      a = g_sum(*(int (*)[4])&NumRec[0]) + 1.0;
      b = h_sum(*(int (*)[5])&NumRec[0]);
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

      k = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, k);
      for (k = 0; k < qEnd; k++) {
        x->data[k] = (PMAn->data[k] != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        b_idx = 0;
        k = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, k);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          k = j->size[0] * j->size[1];
          j->size[1] = b_idx;
          emxEnsureCapacity_int32_T(j, k);
        }
      }

      k = allAn->size[0] * allAn->size[1];
      allAn->size[0] = 1;
      allAn->size[1] = j->size[1];
      emxEnsureCapacity_int32_T(allAn, k);
      qEnd = j->size[0] * j->size[1];
      for (k = 0; k < qEnd; k++) {
        allAn->data[k] = j->data[k];
      }

      /*  Busco los posibles Anestesistas a usar. */
      a = d_sum(*(int (*)[2])&NumRec[0]) + 1.0;
      b = e_sum(*(int (*)[3])&NumRec[0]);
      if (a > b) {
        k = -1;
      } else {
        k = (int)a - 2;
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
        b_idx = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
        b_idx = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
        b_idx = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
      na = -1;
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
              * (i106 + (int)C->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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
              * (k + allS->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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

            a = i_sum(*(int (*)[6])&NumRec[0]);
            b_idx = b_H->size[0] * b_H->size[1];
            qEnd = q - p;
            b_H->size[0] = qEnd;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_real_T(b_H, b_idx);
            nb = allCR->size[1];
            for (b_idx = 0; b_idx < nb; b_idx++) {
              for (nm1d2 = 0; nm1d2 < qEnd; nm1d2++) {
                b_H->data[nm1d2 + b_H->size[0] * b_idx] = H->data[(p + nm1d2) +
                  H->size[0] * ((int)(a + (double)allCR->data[b_idx]) - 1)];
              }
            }

            j_sum(b_H, r19);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r19->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r19->size[0] * r19->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r19->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              b_idx = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  b_idx++;
                  j->data[b_idx - 1] = nm1d2;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > b_idx) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = b_idx;
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
              b_idx = 0;
            } else {
              p = nm1d2 - 1;
              b_idx = q;
            }

            a = h_sum(*(int (*)[5])&NumRec[0]);
            nm1d2 = b_H->size[0] * b_H->size[1];
            qEnd = b_idx - p;
            b_H->size[0] = qEnd;
            b_H->size[1] = allCPO->size[1];
            emxEnsureCapacity_real_T(b_H, nm1d2);
            nb = allCPO->size[1];
            for (b_idx = 0; b_idx < nb; b_idx++) {
              for (nm1d2 = 0; nm1d2 < qEnd; nm1d2++) {
                b_H->data[nm1d2 + b_H->size[0] * b_idx] = H->data[(p + nm1d2) +
                  H->size[0] * ((int)(a + (double)allCPO->data[b_idx]) - 1)];
              }
            }

            j_sum(b_H, r19);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r19->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r19->size[0] * r19->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r19->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              b_idx = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  b_idx++;
                  j->data[b_idx - 1] = nm1d2;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > b_idx) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = b_idx;
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
            a = i_sum(*(int (*)[6])&NumRec[0]);
            p = b_H->size[0] * b_H->size[1];
            b_H->size[0] = TimeUsoCR;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_real_T(b_H, p);
            qEnd = allCR->size[1];
            for (p = 0; p < qEnd; p++) {
              for (b_idx = 0; b_idx < TimeUsoCR; b_idx++) {
                nb = 1 + b_idx;
                if ((q < 0) && (nb < MIN_int32_T - q)) {
                  nm1d2 = MIN_int32_T;
                } else if ((q > 0) && (nb > MAX_int32_T - q)) {
                  nm1d2 = MAX_int32_T;
                } else {
                  nm1d2 = q + nb;
                }

                b_H->data[b_idx + b_H->size[0] * p] = H->data[(nm1d2 + H->size[0]
                  * ((int)(a + (double)allCR->data[p]) - 1)) - 1];
              }
            }

            j_sum(b_H, r19);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r19->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r19->size[0] * r19->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r19->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              b_idx = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  b_idx++;
                  j->data[b_idx - 1] = nm1d2;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > b_idx) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = b_idx;
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
            na = (int)uCPrODisp->data[b_j];
            exitg2 = 1;
          } else {
            b_j++;
          }
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      if (na == -1) {
        i106 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        kEnd = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        tempUltPosRecXDia->size[0] = 1;
        emxEnsureCapacity_int32_T(tempUltPosRecXDia, kEnd);
        qEnd = i106 - 1;
        for (i106 = 0; i106 <= qEnd; i106++) {
          nm1d2 = tempUltPosRecXDia->data[i106];
          if (nm1d2 > 2147483646) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2++;
          }

          tempUltPosRecXDia->data[i106] = nm1d2;
        }
      } else {
        b_CPrOA = na;
        nm1d2 = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
        nb = tempUltPosRecXDia->data[na - 1];
        if ((nm1d2 < 0) && (nb < MIN_int32_T - nm1d2)) {
          qY = MIN_int32_T;
        } else if ((nm1d2 > 0) && (nb > MAX_int32_T - nm1d2)) {
          qY = MAX_int32_T;
        } else {
          qY = nm1d2 + nb;
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

        i106 = SA->size[0] * SA->size[1];
        SA->size[0] = 1;
        SA->size[1] = 1;
        emxEnsureCapacity_int32_T(SA, i106);
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

        i106 = EA->size[0] * EA->size[1];
        EA->size[0] = 1;
        EA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(EA, i106);
        for (i106 = 0; i106 < qEnd; i106++) {
          EA->data[i106] = (int)C->data[E->data[i106] - 1];
        }

        if (1 > PMA->data[PMA->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMA->data[PMA->size[1] - 1];
        }

        i106 = AA->size[0] * AA->size[1];
        AA->size[0] = 1;
        AA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AA, i106);
        for (i106 = 0; i106 < qEnd; i106++) {
          AA->data[i106] = allA->data[A->data[i106] - 1];
        }

        if (1 > PMAn->data[PMAn->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMAn->data[PMAn->size[1] - 1];
        }

        i106 = AnA->size[0] * AnA->size[1];
        AnA->size[0] = 1;
        AnA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AnA, i106);
        for (i106 = 0; i106 < qEnd; i106++) {
          AnA->data[i106] = allAn->data[An->data[i106] - 1];
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
  emxFree_real_T(&r19);
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
  emxArray_int32_T *j;
  int nm1d2;
  emxArray_int32_T *E;
  int i93;
  double a;
  double b;
  emxArray_real_T *r15;
  double ndbl;
  double apnd;
  double cdiff;
  emxArray_int32_T *S;
  int qEnd;
  int n;
  emxArray_real_T *C;
  emxArray_int32_T *A;
  int k;
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
  int b_idx;
  boolean_T exitg1;
  int nb;
  int q;
  int na;
  int b_j;
  int p;
  long long i94;
  int exitg2;
  emxInit_int32_T(&j, 2);
  if (NumRec[0] > 2147483646) {
    nm1d2 = MAX_int32_T;
  } else {
    nm1d2 = NumRec[0] + 1;
  }

  eml_signed_integer_colon(nm1d2, (int)d_sum(*(int (*)[2])&NumRec[0]), j);
  nm1d2 = j->size[1];
  emxInit_int32_T(&E, 2);
  if (nm1d2 < 1) {
    E->size[0] = 1;
    E->size[1] = 0;
  } else {
    i93 = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = nm1d2;
    emxEnsureCapacity_int32_T(E, i93);
    for (i93 = 0; i93 < nm1d2; i93++) {
      E->data[i93] = 1 + i93;
    }
  }

  a = d_sum(*(int (*)[2])&NumRec[0]) + 1.0;
  b = e_sum(*(int (*)[3])&NumRec[0]);
  emxInit_real_T(&r15, 2);
  if (b < a) {
    i93 = r15->size[0] * r15->size[1];
    r15->size[1] = 0;
    emxEnsureCapacity_real_T(r15, i93);
  } else if (floor(a) == a) {
    i93 = r15->size[0] * r15->size[1];
    r15->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(r15, i93);
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

    i93 = r15->size[0] * r15->size[1];
    r15->size[0] = 1;
    r15->size[1] = n;
    emxEnsureCapacity_real_T(r15, i93);
    if ((n > 0) && (n > 1)) {
      r15->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (k = 0; k <= nm1d2 - 2; k++) {
        r15->data[1 + k] = a + (1.0 + (double)k);
        r15->data[(n - k) - 2] = apnd - (1.0 + (double)k);
      }

      if (nm1d2 << 1 == n - 1) {
        r15->data[nm1d2] = (a + apnd) / 2.0;
      } else {
        r15->data[nm1d2] = a + (double)nm1d2;
        r15->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_int32_T(&S, 2);
  if (r15->size[1] < 1) {
    S->size[0] = 1;
    S->size[1] = 0;
  } else {
    qEnd = r15->size[1];
    i93 = S->size[0] * S->size[1];
    S->size[0] = 1;
    S->size[1] = qEnd;
    emxEnsureCapacity_int32_T(S, i93);
    for (i93 = 0; i93 < qEnd; i93++) {
      S->data[i93] = 1 + i93;
    }
  }

  a = e_sum(*(int (*)[3])&NumRec[0]) + 1.0;
  b = g_sum(*(int (*)[4])&NumRec[0]);
  emxInit_real_T(&C, 2);
  if (b < a) {
    i93 = C->size[0] * C->size[1];
    C->size[1] = 0;
    emxEnsureCapacity_real_T(C, i93);
  } else if (floor(a) == a) {
    i93 = C->size[0] * C->size[1];
    C->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(C, i93);
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

    i93 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = n;
    emxEnsureCapacity_real_T(C, i93);
    if (n > 0) {
      C->data[0] = a;
      if (n > 1) {
        C->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 0; k <= nm1d2 - 2; k++) {
          C->data[1 + k] = a + (1.0 + (double)k);
          C->data[(n - k) - 2] = apnd - (1.0 + (double)k);
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
    i93 = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = qEnd;
    emxEnsureCapacity_int32_T(A, i93);
    for (i93 = 0; i93 < qEnd; i93++) {
      A->data[i93] = 1 + i93;
    }
  }

  a = g_sum(*(int (*)[4])&NumRec[0]) + 1.0;
  b = h_sum(*(int (*)[5])&NumRec[0]);
  emxInit_real_T(&CR, 2);
  if (b < a) {
    i93 = CR->size[0] * CR->size[1];
    CR->size[1] = 0;
    emxEnsureCapacity_real_T(CR, i93);
  } else if (floor(a) == a) {
    i93 = CR->size[0] * CR->size[1];
    CR->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(CR, i93);
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

    i93 = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    CR->size[1] = n;
    emxEnsureCapacity_real_T(CR, i93);
    if (n > 0) {
      CR->data[0] = a;
      if (n > 1) {
        CR->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 0; k <= nm1d2 - 2; k++) {
          CR->data[1 + k] = a + (1.0 + (double)k);
          CR->data[(n - k) - 2] = apnd - (1.0 + (double)k);
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
    i93 = An->size[0] * An->size[1];
    An->size[0] = 1;
    An->size[1] = qEnd;
    emxEnsureCapacity_int32_T(An, i93);
    for (i93 = 0; i93 < qEnd; i93++) {
      An->data[i93] = 1 + i93;
    }
  }

  emxInit_int32_T(&CPO, 2);
  if (PCPO->size[1] < 1) {
    CPO->size[0] = 1;
    CPO->size[1] = 0;
  } else {
    qEnd = PCPO->size[1];
    i93 = CPO->size[0] * CPO->size[1];
    CPO->size[0] = 1;
    CPO->size[1] = qEnd;
    emxEnsureCapacity_int32_T(CPO, i93);
    for (i93 = 0; i93 < qEnd; i93++) {
      CPO->data[i93] = 1 + i93;
    }
  }

  if (PCR->size[1] < 1) {
    CR->size[0] = 1;
    CR->size[1] = 0;
  } else {
    i93 = PCR->size[1];
    kEnd = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    qEnd = (int)((double)i93 - 1.0);
    CR->size[1] = qEnd + 1;
    emxEnsureCapacity_real_T(CR, kEnd);
    for (i93 = 0; i93 <= qEnd; i93++) {
      CR->data[i93] = 1.0 + (double)i93;
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
    i93 = EA->size[0] * EA->size[1];
    EA->size[0] = 1;
    EA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(EA, i93);
    for (i93 = 0; i93 <= qEnd; i93++) {
      EA->data[i93] = 1 + i93;
    }
  }

  if (PMA->size[1] - 1 < 1) {
    AA->size[0] = 1;
    AA->size[1] = 0;
  } else {
    qEnd = PMA->size[1] - 2;
    i93 = AA->size[0] * AA->size[1];
    AA->size[0] = 1;
    AA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AA, i93);
    for (i93 = 0; i93 <= qEnd; i93++) {
      AA->data[i93] = 1 + i93;
    }
  }

  if (PMAn->size[1] - 1 < 1) {
    AnA->size[0] = 1;
    AnA->size[1] = 0;
  } else {
    qEnd = PMAn->size[1] - 2;
    i93 = AnA->size[0] * AnA->size[1];
    AnA->size[0] = 1;
    AnA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AnA, i93);
    for (i93 = 0; i93 <= qEnd; i93++) {
      AnA->data[i93] = 1 + i93;
    }
  }

  if (PS->size[1] - 1 < 1) {
    SA->size[0] = 1;
    SA->size[1] = 0;
  } else {
    qEnd = PS->size[1] - 2;
    i93 = SA->size[0] * SA->size[1];
    SA->size[0] = 1;
    SA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(SA, i93);
    for (i93 = 0; i93 <= qEnd; i93++) {
      SA->data[i93] = 1 + i93;
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
    i93 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = PCPrO->size[1];
    emxEnsureCapacity_boolean_T(x, i93);
    qEnd = PCPrO->size[0] * PCPrO->size[1];
    for (i93 = 0; i93 < qEnd; i93++) {
      x->data[i93] = (PCPrO->data[i93] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i93 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i93);
      nm1d2 = 1;
      exitg1 = false;
      while ((!exitg1) && (nm1d2 <= x->size[1])) {
        if (x->data[nm1d2 - 1]) {
          b_idx++;
          j->data[b_idx - 1] = nm1d2;
          if (b_idx >= x->size[1]) {
            exitg1 = true;
          } else {
            nm1d2++;
          }
        } else {
          nm1d2++;
        }
      }

      if (x->size[1] == 1) {
        if (b_idx == 0) {
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > b_idx) {
        j->size[1] = 0;
      } else {
        i93 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i93);
      }
    }

    i93 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = j->size[1];
    emxEnsureCapacity_real_T(C, i93);
    qEnd = j->size[0] * j->size[1];
    for (i93 = 0; i93 < qEnd; i93++) {
      C->data[i93] = j->data[i93];
    }

    /*  Busco las posibles camas a usar. */
    nm1d2 = Dia->data[(*contDia + Dia->size[0] * 3) - 1];
    nb = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
    if ((nm1d2 >= 0) && (nb < nm1d2 - MAX_int32_T)) {
      nm1d2 = MAX_int32_T;
    } else if ((nm1d2 < 0) && (nb > nm1d2 - MIN_int32_T)) {
      nm1d2 = MIN_int32_T;
    } else {
      nm1d2 -= nb;
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
    i93 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = C->size[1];
    emxEnsureCapacity_boolean_T(x, i93);
    qEnd = C->size[0] * C->size[1];
    for (i93 = 0; i93 < qEnd; i93++) {
      x->data[i93] = (tempUltPosRecXDia->data[(int)C->data[i93] - 1] <= nm1d2);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i93 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i93);
      nm1d2 = 1;
      exitg1 = false;
      while ((!exitg1) && (nm1d2 <= x->size[1])) {
        if (x->data[nm1d2 - 1]) {
          b_idx++;
          j->data[b_idx - 1] = nm1d2;
          if (b_idx >= x->size[1]) {
            exitg1 = true;
          } else {
            nm1d2++;
          }
        } else {
          nm1d2++;
        }
      }

      if (x->size[1] == 1) {
        if (b_idx == 0) {
          j->size[0] = 1;
          j->size[1] = 0;
        }
      } else if (1 > b_idx) {
        j->size[1] = 0;
      } else {
        i93 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i93);
      }
    }

    i93 = allC->size[0] * allC->size[1];
    allC->size[0] = 1;
    allC->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(allC, i93);
    qEnd = j->size[0] * j->size[1];
    for (i93 = 0; i93 < qEnd; i93++) {
      allC->data[i93] = j->data[i93];
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

      c_funcionDia(NumRec, PCPrO, Dia, UltPosRecXDia, TimeUsoCPrO, TimeUsoS,
                   contDia, DispMExD, tempUltPosRecXDia, DispME);
    } else {
      i93 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(j, i93);
      qEnd = allC->size[0] * allC->size[1];
      for (i93 = 0; i93 < qEnd; i93++) {
        j->data[i93] = tempUltPosRecXDia->data[(int)(unsigned int)C->data
          [allC->data[i93] - 1] - 1];
      }

      na = allC->size[1];
      n = allC->size[1] + 1;
      i93 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(idx, i93);
      qEnd = allC->size[1];
      for (i93 = 0; i93 < qEnd; i93++) {
        idx->data[i93] = 0;
      }

      i93 = iwork->size[0];
      iwork->size[0] = allC->size[1];
      emxEnsureCapacity_int32_T(iwork, i93);
      i93 = allC->size[1] - 1;
      for (k = 1; k <= i93; k += 2) {
        if (j->data[k - 1] <= j->data[k]) {
          idx->data[k - 1] = k;
          idx->data[k] = k + 1;
        } else {
          idx->data[k - 1] = k + 1;
          idx->data[k] = k;
        }
      }

      if ((allC->size[1] & 1) != 0) {
        idx->data[allC->size[1] - 1] = allC->size[1];
      }

      nm1d2 = 2;
      while (nm1d2 < n - 1) {
        nb = nm1d2 << 1;
        b_j = 1;
        for (b_idx = 1 + nm1d2; b_idx < n; b_idx = qEnd + nm1d2) {
          p = b_j;
          q = b_idx;
          qEnd = b_j + nb;
          if (qEnd > n) {
            qEnd = n;
          }

          k = 0;
          kEnd = qEnd - b_j;
          while (k + 1 <= kEnd) {
            if (j->data[idx->data[p - 1] - 1] <= j->data[idx->data[q - 1] - 1])
            {
              iwork->data[k] = idx->data[p - 1];
              p++;
              if (p == b_idx) {
                while (q < qEnd) {
                  k++;
                  iwork->data[k] = idx->data[q - 1];
                  q++;
                }
              }
            } else {
              iwork->data[k] = idx->data[q - 1];
              q++;
              if (q == qEnd) {
                while (p < b_idx) {
                  k++;
                  iwork->data[k] = idx->data[p - 1];
                  p++;
                }
              }
            }

            k++;
          }

          for (k = 0; k < kEnd; k++) {
            idx->data[(b_j + k) - 1] = iwork->data[k];
          }

          b_j = qEnd;
        }

        nm1d2 = nb;
      }

      i93 = b_b->size[0] * b_b->size[1];
      b_b->size[0] = 1;
      b_b->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(b_b, i93);
      for (k = 0; k < na; k++) {
        b_b->data[k] = j->data[idx->data[k] - 1];
      }

      nb = -1;
      k = 0;
      while (k + 1 <= na) {
        nm1d2 = b_b->data[k];
        b_idx = k;
        do {
          k++;
        } while (!((k + 1 > na) || (b_b->data[k] != nm1d2)));

        nb++;
        b_b->data[nb] = nm1d2;
        idx->data[nb] = idx->data[b_idx];
      }

      i93 = iwork->size[0];
      iwork->size[0] = nb + 1;
      emxEnsureCapacity_int32_T(iwork, i93);
      for (k = 0; k <= nb; k++) {
        iwork->data[k] = idx->data[k];
      }

      i93 = uCPrODisp->size[0] * uCPrODisp->size[1];
      uCPrODisp->size[0] = 1;
      uCPrODisp->size[1] = iwork->size[0];
      emxEnsureCapacity_uint32_T(uCPrODisp, i93);
      qEnd = iwork->size[0];
      for (i93 = 0; i93 < qEnd; i93++) {
        uCPrODisp->data[i93] = (unsigned int)C->data[allC->data[iwork->data[i93]
          - 1] - 1];
      }

      if (NumRec[0] > 2147483646) {
        nm1d2 = MAX_int32_T;
      } else {
        nm1d2 = NumRec[0] + 1;
      }

      a = rt_roundd(d_sum(*(int (*)[2])&NumRec[0]));
      if (a < 2.147483648E+9) {
        if (a >= -2.147483648E+9) {
          i93 = (int)a;
        } else {
          i93 = MIN_int32_T;
        }
      } else {
        i93 = MAX_int32_T;
      }

      if (nm1d2 > i93) {
        i93 = -1;
      } else {
        i93 = nm1d2 - 2;
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
        i94 = (long long)PME->data[kEnd] * DispME->data[kEnd];
        if (i94 > 2147483647LL) {
          i94 = 2147483647LL;
        } else {
          if (i94 < -2147483648LL) {
            i94 = -2147483648LL;
          }
        }

        x->data[kEnd] = ((int)i94 != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        b_idx = 0;
        kEnd = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, kEnd);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          kEnd = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
      a = e_sum(*(int (*)[3])&NumRec[0]) + 1.0;
      b = g_sum(*(int (*)[4])&NumRec[0]);
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
        b_idx = 0;
        n = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, n);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          n = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
      a = g_sum(*(int (*)[4])&NumRec[0]) + 1.0;
      b = h_sum(*(int (*)[5])&NumRec[0]);
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

      k = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = qEnd;
      emxEnsureCapacity_boolean_T(x, k);
      for (k = 0; k < qEnd; k++) {
        x->data[k] = (PMAn->data[k] != 0);
      }

      if (x->size[1] == 0) {
        j->size[0] = 1;
        j->size[1] = 0;
      } else {
        b_idx = 0;
        k = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, k);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          k = j->size[0] * j->size[1];
          j->size[1] = b_idx;
          emxEnsureCapacity_int32_T(j, k);
        }
      }

      k = allAn->size[0] * allAn->size[1];
      allAn->size[0] = 1;
      allAn->size[1] = j->size[1];
      emxEnsureCapacity_int32_T(allAn, k);
      qEnd = j->size[0] * j->size[1];
      for (k = 0; k < qEnd; k++) {
        allAn->data[k] = j->data[k];
      }

      /*  Busco los posibles Anestesistas a usar. */
      a = d_sum(*(int (*)[2])&NumRec[0]) + 1.0;
      b = e_sum(*(int (*)[3])&NumRec[0]);
      if (a > b) {
        k = -1;
      } else {
        k = (int)a - 2;
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
        b_idx = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
        b_idx = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
        b_idx = 0;
        p = j->size[0] * j->size[1];
        j->size[0] = 1;
        j->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(j, p);
        nm1d2 = 1;
        exitg1 = false;
        while ((!exitg1) && (nm1d2 <= x->size[1])) {
          if (x->data[nm1d2 - 1]) {
            b_idx++;
            j->data[b_idx - 1] = nm1d2;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              nm1d2++;
            }
          } else {
            nm1d2++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          }
        } else if (1 > b_idx) {
          j->size[1] = 0;
        } else {
          p = j->size[0] * j->size[1];
          j->size[1] = b_idx;
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
      na = -1;
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
              * (i93 + (int)C->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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
              * (k + allS->data[p])) - 1] <= e_qY);
          }

          if (x->size[1] == 0) {
            j->size[0] = 1;
            j->size[1] = 0;
          } else {
            b_idx = 0;
            p = j->size[0] * j->size[1];
            j->size[0] = 1;
            j->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(j, p);
            nm1d2 = 1;
            exitg1 = false;
            while ((!exitg1) && (nm1d2 <= x->size[1])) {
              if (x->data[nm1d2 - 1]) {
                b_idx++;
                j->data[b_idx - 1] = nm1d2;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  nm1d2++;
                }
              } else {
                nm1d2++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                j->size[0] = 1;
                j->size[1] = 0;
              }
            } else if (1 > b_idx) {
              j->size[1] = 0;
            } else {
              p = j->size[0] * j->size[1];
              j->size[1] = b_idx;
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

            a = i_sum(*(int (*)[6])&NumRec[0]);
            b_idx = b_H->size[0] * b_H->size[1];
            qEnd = q - p;
            b_H->size[0] = qEnd;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_int32_T(b_H, b_idx);
            nb = allCR->size[1];
            for (b_idx = 0; b_idx < nb; b_idx++) {
              for (nm1d2 = 0; nm1d2 < qEnd; nm1d2++) {
                b_H->data[nm1d2 + b_H->size[0] * b_idx] = H->data[(p + nm1d2) +
                  H->size[0] * ((int)(a + (double)allCR->data[b_idx]) - 1)];
              }
            }

            n_sum(b_H, r15);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r15->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r15->size[0] * r15->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r15->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              b_idx = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  b_idx++;
                  j->data[b_idx - 1] = nm1d2;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > b_idx) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = b_idx;
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
              b_idx = 0;
            } else {
              p = nm1d2 - 1;
              b_idx = q;
            }

            a = h_sum(*(int (*)[5])&NumRec[0]);
            nm1d2 = b_H->size[0] * b_H->size[1];
            qEnd = b_idx - p;
            b_H->size[0] = qEnd;
            b_H->size[1] = allCPO->size[1];
            emxEnsureCapacity_int32_T(b_H, nm1d2);
            nb = allCPO->size[1];
            for (b_idx = 0; b_idx < nb; b_idx++) {
              for (nm1d2 = 0; nm1d2 < qEnd; nm1d2++) {
                b_H->data[nm1d2 + b_H->size[0] * b_idx] = H->data[(p + nm1d2) +
                  H->size[0] * ((int)(a + (double)allCPO->data[b_idx]) - 1)];
              }
            }

            n_sum(b_H, r15);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r15->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r15->size[0] * r15->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r15->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              b_idx = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  b_idx++;
                  j->data[b_idx - 1] = nm1d2;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > b_idx) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = b_idx;
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
            a = i_sum(*(int (*)[6])&NumRec[0]);
            p = b_H->size[0] * b_H->size[1];
            b_H->size[0] = TimeUsoCR;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_int32_T(b_H, p);
            qEnd = allCR->size[1];
            for (p = 0; p < qEnd; p++) {
              for (b_idx = 0; b_idx < TimeUsoCR; b_idx++) {
                nb = 1 + b_idx;
                if ((q < 0) && (nb < MIN_int32_T - q)) {
                  nm1d2 = MIN_int32_T;
                } else if ((q > 0) && (nb > MAX_int32_T - q)) {
                  nm1d2 = MAX_int32_T;
                } else {
                  nm1d2 = q + nb;
                }

                b_H->data[b_idx + b_H->size[0] * p] = H->data[(nm1d2 + H->size[0]
                  * ((int)(a + (double)allCR->data[p]) - 1)) - 1];
              }
            }

            n_sum(b_H, r15);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r15->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r15->size[0] * r15->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r15->data[p] == 0.0);
            }

            if (x->size[1] == 0) {
              j->size[0] = 1;
              j->size[1] = 0;
            } else {
              b_idx = 0;
              p = j->size[0] * j->size[1];
              j->size[0] = 1;
              j->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(j, p);
              nm1d2 = 1;
              exitg1 = false;
              while ((!exitg1) && (nm1d2 <= x->size[1])) {
                if (x->data[nm1d2 - 1]) {
                  b_idx++;
                  j->data[b_idx - 1] = nm1d2;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    nm1d2++;
                  }
                } else {
                  nm1d2++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  j->size[0] = 1;
                  j->size[1] = 0;
                }
              } else if (1 > b_idx) {
                j->size[1] = 0;
              } else {
                p = j->size[0] * j->size[1];
                j->size[1] = b_idx;
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
            na = (int)uCPrODisp->data[b_j];
            exitg2 = 1;
          } else {
            b_j++;
          }
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      if (na == -1) {
        i93 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        kEnd = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        tempUltPosRecXDia->size[0] = 1;
        emxEnsureCapacity_int32_T(tempUltPosRecXDia, kEnd);
        qEnd = i93 - 1;
        for (i93 = 0; i93 <= qEnd; i93++) {
          nm1d2 = tempUltPosRecXDia->data[i93];
          if (nm1d2 > 2147483646) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2++;
          }

          tempUltPosRecXDia->data[i93] = nm1d2;
        }
      } else {
        b_CPrOA = na;
        nm1d2 = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1];
        nb = tempUltPosRecXDia->data[na - 1];
        if ((nm1d2 < 0) && (nb < MIN_int32_T - nm1d2)) {
          qY = MIN_int32_T;
        } else if ((nm1d2 > 0) && (nb > MAX_int32_T - nm1d2)) {
          qY = MAX_int32_T;
        } else {
          qY = nm1d2 + nb;
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

        i93 = SA->size[0] * SA->size[1];
        SA->size[0] = 1;
        SA->size[1] = 1;
        emxEnsureCapacity_int32_T(SA, i93);
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

        i93 = EA->size[0] * EA->size[1];
        EA->size[0] = 1;
        EA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(EA, i93);
        for (i93 = 0; i93 < qEnd; i93++) {
          EA->data[i93] = (int)C->data[E->data[i93] - 1];
        }

        if (1 > PMA->data[PMA->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMA->data[PMA->size[1] - 1];
        }

        i93 = AA->size[0] * AA->size[1];
        AA->size[0] = 1;
        AA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AA, i93);
        for (i93 = 0; i93 < qEnd; i93++) {
          AA->data[i93] = allA->data[A->data[i93] - 1];
        }

        if (1 > PMAn->data[PMAn->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMAn->data[PMAn->size[1] - 1];
        }

        i93 = AnA->size[0] * AnA->size[1];
        AnA->size[0] = 1;
        AnA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AnA, i93);
        for (i93 = 0; i93 < qEnd; i93++) {
          AnA->data[i93] = allAn->data[An->data[i93] - 1];
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
  emxFree_real_T(&r15);
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
