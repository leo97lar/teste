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
  int i70;
  double a;
  double b;
  emxArray_real_T *r13;
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
  long long i71;
  int exitg2;
  emxInit_int32_T(&j, 2);
  if (NumRec[0] > 2147483646) {
    nm1d2 = MAX_int32_T;
  } else {
    nm1d2 = NumRec[0] + 1;
  }

  eml_signed_integer_colon(nm1d2, (int)c_sum(*(int (*)[2])&NumRec[0]), j);
  nm1d2 = j->size[1];
  emxInit_int32_T(&E, 2);
  if (nm1d2 < 1) {
    E->size[0] = 1;
    E->size[1] = 0;
  } else {
    i70 = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = nm1d2;
    emxEnsureCapacity_int32_T(E, i70);
    for (i70 = 0; i70 < nm1d2; i70++) {
      E->data[i70] = 1 + i70;
    }
  }

  a = c_sum(*(int (*)[2])&NumRec[0]) + 1.0;
  b = d_sum(*(int (*)[3])&NumRec[0]);
  emxInit_real_T(&r13, 2);
  if (b < a) {
    i70 = r13->size[0] * r13->size[1];
    r13->size[1] = 0;
    emxEnsureCapacity_real_T(r13, i70);
  } else if (floor(a) == a) {
    i70 = r13->size[0] * r13->size[1];
    r13->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(r13, i70);
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

    i70 = r13->size[0] * r13->size[1];
    r13->size[0] = 1;
    r13->size[1] = n;
    emxEnsureCapacity_real_T(r13, i70);
    if ((n > 0) && (n > 1)) {
      r13->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (k = 0; k <= nm1d2 - 2; k++) {
        r13->data[1 + k] = a + (1.0 + (double)k);
        r13->data[(n - k) - 2] = apnd - (1.0 + (double)k);
      }

      if (nm1d2 << 1 == n - 1) {
        r13->data[nm1d2] = (a + apnd) / 2.0;
      } else {
        r13->data[nm1d2] = a + (double)nm1d2;
        r13->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_int32_T(&S, 2);
  if (r13->size[1] < 1) {
    S->size[0] = 1;
    S->size[1] = 0;
  } else {
    qEnd = r13->size[1];
    i70 = S->size[0] * S->size[1];
    S->size[0] = 1;
    S->size[1] = qEnd;
    emxEnsureCapacity_int32_T(S, i70);
    for (i70 = 0; i70 < qEnd; i70++) {
      S->data[i70] = 1 + i70;
    }
  }

  a = d_sum(*(int (*)[3])&NumRec[0]) + 1.0;
  b = f_sum(*(int (*)[4])&NumRec[0]);
  emxInit_real_T(&C, 2);
  if (b < a) {
    i70 = C->size[0] * C->size[1];
    C->size[1] = 0;
    emxEnsureCapacity_real_T(C, i70);
  } else if (floor(a) == a) {
    i70 = C->size[0] * C->size[1];
    C->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(C, i70);
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

    i70 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = n;
    emxEnsureCapacity_real_T(C, i70);
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
    i70 = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = qEnd;
    emxEnsureCapacity_int32_T(A, i70);
    for (i70 = 0; i70 < qEnd; i70++) {
      A->data[i70] = 1 + i70;
    }
  }

  a = f_sum(*(int (*)[4])&NumRec[0]) + 1.0;
  b = g_sum(*(int (*)[5])&NumRec[0]);
  emxInit_real_T(&CR, 2);
  if (b < a) {
    i70 = CR->size[0] * CR->size[1];
    CR->size[1] = 0;
    emxEnsureCapacity_real_T(CR, i70);
  } else if (floor(a) == a) {
    i70 = CR->size[0] * CR->size[1];
    CR->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(CR, i70);
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

    i70 = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    CR->size[1] = n;
    emxEnsureCapacity_real_T(CR, i70);
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
    i70 = An->size[0] * An->size[1];
    An->size[0] = 1;
    An->size[1] = qEnd;
    emxEnsureCapacity_int32_T(An, i70);
    for (i70 = 0; i70 < qEnd; i70++) {
      An->data[i70] = 1 + i70;
    }
  }

  emxInit_int32_T(&CPO, 2);
  if (PCPO->size[1] < 1) {
    CPO->size[0] = 1;
    CPO->size[1] = 0;
  } else {
    qEnd = PCPO->size[1];
    i70 = CPO->size[0] * CPO->size[1];
    CPO->size[0] = 1;
    CPO->size[1] = qEnd;
    emxEnsureCapacity_int32_T(CPO, i70);
    for (i70 = 0; i70 < qEnd; i70++) {
      CPO->data[i70] = 1 + i70;
    }
  }

  if (PCR->size[1] < 1) {
    CR->size[0] = 1;
    CR->size[1] = 0;
  } else {
    i70 = PCR->size[1];
    kEnd = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    qEnd = (int)((double)i70 - 1.0);
    CR->size[1] = qEnd + 1;
    emxEnsureCapacity_real_T(CR, kEnd);
    for (i70 = 0; i70 <= qEnd; i70++) {
      CR->data[i70] = 1.0 + (double)i70;
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
    i70 = EA->size[0] * EA->size[1];
    EA->size[0] = 1;
    EA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(EA, i70);
    for (i70 = 0; i70 <= qEnd; i70++) {
      EA->data[i70] = 1 + i70;
    }
  }

  if (PMA->size[1] - 1 < 1) {
    AA->size[0] = 1;
    AA->size[1] = 0;
  } else {
    qEnd = PMA->size[1] - 2;
    i70 = AA->size[0] * AA->size[1];
    AA->size[0] = 1;
    AA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AA, i70);
    for (i70 = 0; i70 <= qEnd; i70++) {
      AA->data[i70] = 1 + i70;
    }
  }

  if (PMAn->size[1] - 1 < 1) {
    AnA->size[0] = 1;
    AnA->size[1] = 0;
  } else {
    qEnd = PMAn->size[1] - 2;
    i70 = AnA->size[0] * AnA->size[1];
    AnA->size[0] = 1;
    AnA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AnA, i70);
    for (i70 = 0; i70 <= qEnd; i70++) {
      AnA->data[i70] = 1 + i70;
    }
  }

  if (PS->size[1] - 1 < 1) {
    SA->size[0] = 1;
    SA->size[1] = 0;
  } else {
    qEnd = PS->size[1] - 2;
    i70 = SA->size[0] * SA->size[1];
    SA->size[0] = 1;
    SA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(SA, i70);
    for (i70 = 0; i70 <= qEnd; i70++) {
      SA->data[i70] = 1 + i70;
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
    i70 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = PCPrO->size[1];
    emxEnsureCapacity_boolean_T(x, i70);
    qEnd = PCPrO->size[0] * PCPrO->size[1];
    for (i70 = 0; i70 < qEnd; i70++) {
      x->data[i70] = (PCPrO->data[i70] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i70 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i70);
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
        i70 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i70);
      }
    }

    i70 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = j->size[1];
    emxEnsureCapacity_real_T(C, i70);
    qEnd = j->size[0] * j->size[1];
    for (i70 = 0; i70 < qEnd; i70++) {
      C->data[i70] = j->data[i70];
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
    i70 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = C->size[1];
    emxEnsureCapacity_boolean_T(x, i70);
    qEnd = C->size[0] * C->size[1];
    for (i70 = 0; i70 < qEnd; i70++) {
      x->data[i70] = (tempUltPosRecXDia->data[(int)C->data[i70] - 1] <= nm1d2);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i70 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i70);
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
        i70 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i70);
      }
    }

    i70 = allC->size[0] * allC->size[1];
    allC->size[0] = 1;
    allC->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(allC, i70);
    qEnd = j->size[0] * j->size[1];
    for (i70 = 0; i70 < qEnd; i70++) {
      allC->data[i70] = j->data[i70];
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
      i70 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(j, i70);
      qEnd = allC->size[0] * allC->size[1];
      for (i70 = 0; i70 < qEnd; i70++) {
        j->data[i70] = tempUltPosRecXDia->data[(int)(unsigned int)C->data
          [allC->data[i70] - 1] - 1];
      }

      na = allC->size[1];
      n = allC->size[1] + 1;
      i70 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(idx, i70);
      qEnd = allC->size[1];
      for (i70 = 0; i70 < qEnd; i70++) {
        idx->data[i70] = 0;
      }

      i70 = iwork->size[0];
      iwork->size[0] = allC->size[1];
      emxEnsureCapacity_int32_T(iwork, i70);
      i70 = allC->size[1] - 1;
      for (k = 1; k <= i70; k += 2) {
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

      i70 = b_b->size[0] * b_b->size[1];
      b_b->size[0] = 1;
      b_b->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(b_b, i70);
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

      i70 = iwork->size[0];
      iwork->size[0] = nb + 1;
      emxEnsureCapacity_int32_T(iwork, i70);
      for (k = 0; k <= nb; k++) {
        iwork->data[k] = idx->data[k];
      }

      i70 = uCPrODisp->size[0] * uCPrODisp->size[1];
      uCPrODisp->size[0] = 1;
      uCPrODisp->size[1] = iwork->size[0];
      emxEnsureCapacity_uint32_T(uCPrODisp, i70);
      qEnd = iwork->size[0];
      for (i70 = 0; i70 < qEnd; i70++) {
        uCPrODisp->data[i70] = (unsigned int)C->data[allC->data[iwork->data[i70]
          - 1] - 1];
      }

      if (NumRec[0] > 2147483646) {
        nm1d2 = MAX_int32_T;
      } else {
        nm1d2 = NumRec[0] + 1;
      }

      a = rt_roundd(c_sum(*(int (*)[2])&NumRec[0]));
      if (a < 2.147483648E+9) {
        if (a >= -2.147483648E+9) {
          i70 = (int)a;
        } else {
          i70 = MIN_int32_T;
        }
      } else {
        i70 = MAX_int32_T;
      }

      if (nm1d2 > i70) {
        i70 = -1;
      } else {
        i70 = nm1d2 - 2;
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
        i71 = (long long)PME->data[kEnd] * DispME->data[kEnd];
        if (i71 > 2147483647LL) {
          i71 = 2147483647LL;
        } else {
          if (i71 < -2147483648LL) {
            i71 = -2147483648LL;
          }
        }

        x->data[kEnd] = ((int)i71 != 0);
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
      a = d_sum(*(int (*)[3])&NumRec[0]) + 1.0;
      b = f_sum(*(int (*)[4])&NumRec[0]);
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
      a = f_sum(*(int (*)[4])&NumRec[0]) + 1.0;
      b = g_sum(*(int (*)[5])&NumRec[0]);
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
      a = c_sum(*(int (*)[2])&NumRec[0]) + 1.0;
      b = d_sum(*(int (*)[3])&NumRec[0]);
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
              * (i70 + (int)C->data[p])) - 1] <= e_qY);
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

            a = h_sum(*(int (*)[6])&NumRec[0]);
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

            i_sum(b_H, r13);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r13->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r13->size[0] * r13->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r13->data[p] == 0.0);
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

            a = g_sum(*(int (*)[5])&NumRec[0]);
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

            i_sum(b_H, r13);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r13->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r13->size[0] * r13->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r13->data[p] == 0.0);
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
            a = h_sum(*(int (*)[6])&NumRec[0]);
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

            i_sum(b_H, r13);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r13->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r13->size[0] * r13->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r13->data[p] == 0.0);
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
        i70 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        kEnd = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        tempUltPosRecXDia->size[0] = 1;
        emxEnsureCapacity_int32_T(tempUltPosRecXDia, kEnd);
        qEnd = i70 - 1;
        for (i70 = 0; i70 <= qEnd; i70++) {
          nm1d2 = tempUltPosRecXDia->data[i70];
          if (nm1d2 > 2147483646) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2++;
          }

          tempUltPosRecXDia->data[i70] = nm1d2;
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

        i70 = SA->size[0] * SA->size[1];
        SA->size[0] = 1;
        SA->size[1] = 1;
        emxEnsureCapacity_int32_T(SA, i70);
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

        i70 = EA->size[0] * EA->size[1];
        EA->size[0] = 1;
        EA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(EA, i70);
        for (i70 = 0; i70 < qEnd; i70++) {
          EA->data[i70] = (int)C->data[E->data[i70] - 1];
        }

        if (1 > PMA->data[PMA->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMA->data[PMA->size[1] - 1];
        }

        i70 = AA->size[0] * AA->size[1];
        AA->size[0] = 1;
        AA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AA, i70);
        for (i70 = 0; i70 < qEnd; i70++) {
          AA->data[i70] = allA->data[A->data[i70] - 1];
        }

        if (1 > PMAn->data[PMAn->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMAn->data[PMAn->size[1] - 1];
        }

        i70 = AnA->size[0] * AnA->size[1];
        AnA->size[0] = 1;
        AnA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AnA, i70);
        for (i70 = 0; i70 < qEnd; i70++) {
          AnA->data[i70] = allAn->data[An->data[i70] - 1];
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
  emxFree_real_T(&r13);
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
  int i81;
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
  long long i82;
  int exitg2;
  emxInit_int32_T(&j, 2);
  if (NumRec[0] > 2147483646) {
    nm1d2 = MAX_int32_T;
  } else {
    nm1d2 = NumRec[0] + 1;
  }

  eml_signed_integer_colon(nm1d2, (int)c_sum(*(int (*)[2])&NumRec[0]), j);
  nm1d2 = j->size[1];
  emxInit_int32_T(&E, 2);
  if (nm1d2 < 1) {
    E->size[0] = 1;
    E->size[1] = 0;
  } else {
    i81 = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = nm1d2;
    emxEnsureCapacity_int32_T(E, i81);
    for (i81 = 0; i81 < nm1d2; i81++) {
      E->data[i81] = 1 + i81;
    }
  }

  a = c_sum(*(int (*)[2])&NumRec[0]) + 1.0;
  b = d_sum(*(int (*)[3])&NumRec[0]);
  emxInit_real_T(&r15, 2);
  if (b < a) {
    i81 = r15->size[0] * r15->size[1];
    r15->size[1] = 0;
    emxEnsureCapacity_real_T(r15, i81);
  } else if (floor(a) == a) {
    i81 = r15->size[0] * r15->size[1];
    r15->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(r15, i81);
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

    i81 = r15->size[0] * r15->size[1];
    r15->size[0] = 1;
    r15->size[1] = n;
    emxEnsureCapacity_real_T(r15, i81);
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
    i81 = S->size[0] * S->size[1];
    S->size[0] = 1;
    S->size[1] = qEnd;
    emxEnsureCapacity_int32_T(S, i81);
    for (i81 = 0; i81 < qEnd; i81++) {
      S->data[i81] = 1 + i81;
    }
  }

  a = d_sum(*(int (*)[3])&NumRec[0]) + 1.0;
  b = f_sum(*(int (*)[4])&NumRec[0]);
  emxInit_real_T(&C, 2);
  if (b < a) {
    i81 = C->size[0] * C->size[1];
    C->size[1] = 0;
    emxEnsureCapacity_real_T(C, i81);
  } else if (floor(a) == a) {
    i81 = C->size[0] * C->size[1];
    C->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(C, i81);
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

    i81 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = n;
    emxEnsureCapacity_real_T(C, i81);
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
    i81 = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = qEnd;
    emxEnsureCapacity_int32_T(A, i81);
    for (i81 = 0; i81 < qEnd; i81++) {
      A->data[i81] = 1 + i81;
    }
  }

  a = f_sum(*(int (*)[4])&NumRec[0]) + 1.0;
  b = g_sum(*(int (*)[5])&NumRec[0]);
  emxInit_real_T(&CR, 2);
  if (b < a) {
    i81 = CR->size[0] * CR->size[1];
    CR->size[1] = 0;
    emxEnsureCapacity_real_T(CR, i81);
  } else if (floor(a) == a) {
    i81 = CR->size[0] * CR->size[1];
    CR->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(CR, i81);
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

    i81 = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    CR->size[1] = n;
    emxEnsureCapacity_real_T(CR, i81);
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
    i81 = An->size[0] * An->size[1];
    An->size[0] = 1;
    An->size[1] = qEnd;
    emxEnsureCapacity_int32_T(An, i81);
    for (i81 = 0; i81 < qEnd; i81++) {
      An->data[i81] = 1 + i81;
    }
  }

  emxInit_int32_T(&CPO, 2);
  if (PCPO->size[1] < 1) {
    CPO->size[0] = 1;
    CPO->size[1] = 0;
  } else {
    qEnd = PCPO->size[1];
    i81 = CPO->size[0] * CPO->size[1];
    CPO->size[0] = 1;
    CPO->size[1] = qEnd;
    emxEnsureCapacity_int32_T(CPO, i81);
    for (i81 = 0; i81 < qEnd; i81++) {
      CPO->data[i81] = 1 + i81;
    }
  }

  if (PCR->size[1] < 1) {
    CR->size[0] = 1;
    CR->size[1] = 0;
  } else {
    i81 = PCR->size[1];
    kEnd = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    qEnd = (int)((double)i81 - 1.0);
    CR->size[1] = qEnd + 1;
    emxEnsureCapacity_real_T(CR, kEnd);
    for (i81 = 0; i81 <= qEnd; i81++) {
      CR->data[i81] = 1.0 + (double)i81;
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
    i81 = EA->size[0] * EA->size[1];
    EA->size[0] = 1;
    EA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(EA, i81);
    for (i81 = 0; i81 <= qEnd; i81++) {
      EA->data[i81] = 1 + i81;
    }
  }

  if (PMA->size[1] - 1 < 1) {
    AA->size[0] = 1;
    AA->size[1] = 0;
  } else {
    qEnd = PMA->size[1] - 2;
    i81 = AA->size[0] * AA->size[1];
    AA->size[0] = 1;
    AA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AA, i81);
    for (i81 = 0; i81 <= qEnd; i81++) {
      AA->data[i81] = 1 + i81;
    }
  }

  if (PMAn->size[1] - 1 < 1) {
    AnA->size[0] = 1;
    AnA->size[1] = 0;
  } else {
    qEnd = PMAn->size[1] - 2;
    i81 = AnA->size[0] * AnA->size[1];
    AnA->size[0] = 1;
    AnA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AnA, i81);
    for (i81 = 0; i81 <= qEnd; i81++) {
      AnA->data[i81] = 1 + i81;
    }
  }

  if (PS->size[1] - 1 < 1) {
    SA->size[0] = 1;
    SA->size[1] = 0;
  } else {
    qEnd = PS->size[1] - 2;
    i81 = SA->size[0] * SA->size[1];
    SA->size[0] = 1;
    SA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(SA, i81);
    for (i81 = 0; i81 <= qEnd; i81++) {
      SA->data[i81] = 1 + i81;
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
    i81 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = PCPrO->size[1];
    emxEnsureCapacity_boolean_T(x, i81);
    qEnd = PCPrO->size[0] * PCPrO->size[1];
    for (i81 = 0; i81 < qEnd; i81++) {
      x->data[i81] = (PCPrO->data[i81] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i81 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i81);
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
        i81 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i81);
      }
    }

    i81 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = j->size[1];
    emxEnsureCapacity_real_T(C, i81);
    qEnd = j->size[0] * j->size[1];
    for (i81 = 0; i81 < qEnd; i81++) {
      C->data[i81] = j->data[i81];
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
    i81 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = C->size[1];
    emxEnsureCapacity_boolean_T(x, i81);
    qEnd = C->size[0] * C->size[1];
    for (i81 = 0; i81 < qEnd; i81++) {
      x->data[i81] = (tempUltPosRecXDia->data[(int)C->data[i81] - 1] <= nm1d2);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i81 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i81);
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
        i81 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i81);
      }
    }

    i81 = allC->size[0] * allC->size[1];
    allC->size[0] = 1;
    allC->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(allC, i81);
    qEnd = j->size[0] * j->size[1];
    for (i81 = 0; i81 < qEnd; i81++) {
      allC->data[i81] = j->data[i81];
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
      i81 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(j, i81);
      qEnd = allC->size[0] * allC->size[1];
      for (i81 = 0; i81 < qEnd; i81++) {
        j->data[i81] = tempUltPosRecXDia->data[(int)(unsigned int)C->data
          [allC->data[i81] - 1] - 1];
      }

      na = allC->size[1];
      n = allC->size[1] + 1;
      i81 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(idx, i81);
      qEnd = allC->size[1];
      for (i81 = 0; i81 < qEnd; i81++) {
        idx->data[i81] = 0;
      }

      i81 = iwork->size[0];
      iwork->size[0] = allC->size[1];
      emxEnsureCapacity_int32_T(iwork, i81);
      i81 = allC->size[1] - 1;
      for (k = 1; k <= i81; k += 2) {
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

      i81 = b_b->size[0] * b_b->size[1];
      b_b->size[0] = 1;
      b_b->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(b_b, i81);
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

      i81 = iwork->size[0];
      iwork->size[0] = nb + 1;
      emxEnsureCapacity_int32_T(iwork, i81);
      for (k = 0; k <= nb; k++) {
        iwork->data[k] = idx->data[k];
      }

      i81 = uCPrODisp->size[0] * uCPrODisp->size[1];
      uCPrODisp->size[0] = 1;
      uCPrODisp->size[1] = iwork->size[0];
      emxEnsureCapacity_uint32_T(uCPrODisp, i81);
      qEnd = iwork->size[0];
      for (i81 = 0; i81 < qEnd; i81++) {
        uCPrODisp->data[i81] = (unsigned int)C->data[allC->data[iwork->data[i81]
          - 1] - 1];
      }

      if (NumRec[0] > 2147483646) {
        nm1d2 = MAX_int32_T;
      } else {
        nm1d2 = NumRec[0] + 1;
      }

      a = rt_roundd(c_sum(*(int (*)[2])&NumRec[0]));
      if (a < 2.147483648E+9) {
        if (a >= -2.147483648E+9) {
          i81 = (int)a;
        } else {
          i81 = MIN_int32_T;
        }
      } else {
        i81 = MAX_int32_T;
      }

      if (nm1d2 > i81) {
        i81 = -1;
      } else {
        i81 = nm1d2 - 2;
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
        i82 = (long long)PME->data[kEnd] * DispME->data[kEnd];
        if (i82 > 2147483647LL) {
          i82 = 2147483647LL;
        } else {
          if (i82 < -2147483648LL) {
            i82 = -2147483648LL;
          }
        }

        x->data[kEnd] = ((int)i82 != 0);
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
      a = d_sum(*(int (*)[3])&NumRec[0]) + 1.0;
      b = f_sum(*(int (*)[4])&NumRec[0]);
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
      a = f_sum(*(int (*)[4])&NumRec[0]) + 1.0;
      b = g_sum(*(int (*)[5])&NumRec[0]);
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
      a = c_sum(*(int (*)[2])&NumRec[0]) + 1.0;
      b = d_sum(*(int (*)[3])&NumRec[0]);
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
              * (i81 + (int)C->data[p])) - 1] <= e_qY);
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

            a = h_sum(*(int (*)[6])&NumRec[0]);
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

            a = g_sum(*(int (*)[5])&NumRec[0]);
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
            a = h_sum(*(int (*)[6])&NumRec[0]);
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
        i81 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        kEnd = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        tempUltPosRecXDia->size[0] = 1;
        emxEnsureCapacity_int32_T(tempUltPosRecXDia, kEnd);
        qEnd = i81 - 1;
        for (i81 = 0; i81 <= qEnd; i81++) {
          nm1d2 = tempUltPosRecXDia->data[i81];
          if (nm1d2 > 2147483646) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2++;
          }

          tempUltPosRecXDia->data[i81] = nm1d2;
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

        i81 = SA->size[0] * SA->size[1];
        SA->size[0] = 1;
        SA->size[1] = 1;
        emxEnsureCapacity_int32_T(SA, i81);
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

        i81 = EA->size[0] * EA->size[1];
        EA->size[0] = 1;
        EA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(EA, i81);
        for (i81 = 0; i81 < qEnd; i81++) {
          EA->data[i81] = (int)C->data[E->data[i81] - 1];
        }

        if (1 > PMA->data[PMA->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMA->data[PMA->size[1] - 1];
        }

        i81 = AA->size[0] * AA->size[1];
        AA->size[0] = 1;
        AA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AA, i81);
        for (i81 = 0; i81 < qEnd; i81++) {
          AA->data[i81] = allA->data[A->data[i81] - 1];
        }

        if (1 > PMAn->data[PMAn->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMAn->data[PMAn->size[1] - 1];
        }

        i81 = AnA->size[0] * AnA->size[1];
        AnA->size[0] = 1;
        AnA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AnA, i81);
        for (i81 = 0; i81 < qEnd; i81++) {
          AnA->data[i81] = allAn->data[An->data[i81] - 1];
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
  int i90;
  double a;
  double b;
  emxArray_real_T *r18;
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
  long long i91;
  int exitg2;
  emxInit_int32_T(&j, 2);
  if (NumRec[0] > 2147483646) {
    nm1d2 = MAX_int32_T;
  } else {
    nm1d2 = NumRec[0] + 1;
  }

  eml_signed_integer_colon(nm1d2, (int)c_sum(*(int (*)[2])&NumRec[0]), j);
  nm1d2 = j->size[1];
  emxInit_int32_T(&E, 2);
  if (nm1d2 < 1) {
    E->size[0] = 1;
    E->size[1] = 0;
  } else {
    i90 = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = nm1d2;
    emxEnsureCapacity_int32_T(E, i90);
    for (i90 = 0; i90 < nm1d2; i90++) {
      E->data[i90] = 1 + i90;
    }
  }

  a = c_sum(*(int (*)[2])&NumRec[0]) + 1.0;
  b = d_sum(*(int (*)[3])&NumRec[0]);
  emxInit_real_T(&r18, 2);
  if (b < a) {
    i90 = r18->size[0] * r18->size[1];
    r18->size[1] = 0;
    emxEnsureCapacity_real_T(r18, i90);
  } else if (floor(a) == a) {
    i90 = r18->size[0] * r18->size[1];
    r18->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(r18, i90);
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

    i90 = r18->size[0] * r18->size[1];
    r18->size[0] = 1;
    r18->size[1] = n;
    emxEnsureCapacity_real_T(r18, i90);
    if ((n > 0) && (n > 1)) {
      r18->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (k = 0; k <= nm1d2 - 2; k++) {
        r18->data[1 + k] = a + (1.0 + (double)k);
        r18->data[(n - k) - 2] = apnd - (1.0 + (double)k);
      }

      if (nm1d2 << 1 == n - 1) {
        r18->data[nm1d2] = (a + apnd) / 2.0;
      } else {
        r18->data[nm1d2] = a + (double)nm1d2;
        r18->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_int32_T(&S, 2);
  if (r18->size[1] < 1) {
    S->size[0] = 1;
    S->size[1] = 0;
  } else {
    qEnd = r18->size[1];
    i90 = S->size[0] * S->size[1];
    S->size[0] = 1;
    S->size[1] = qEnd;
    emxEnsureCapacity_int32_T(S, i90);
    for (i90 = 0; i90 < qEnd; i90++) {
      S->data[i90] = 1 + i90;
    }
  }

  a = d_sum(*(int (*)[3])&NumRec[0]) + 1.0;
  b = f_sum(*(int (*)[4])&NumRec[0]);
  emxInit_real_T(&C, 2);
  if (b < a) {
    i90 = C->size[0] * C->size[1];
    C->size[1] = 0;
    emxEnsureCapacity_real_T(C, i90);
  } else if (floor(a) == a) {
    i90 = C->size[0] * C->size[1];
    C->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(C, i90);
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

    i90 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = n;
    emxEnsureCapacity_real_T(C, i90);
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
    i90 = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = qEnd;
    emxEnsureCapacity_int32_T(A, i90);
    for (i90 = 0; i90 < qEnd; i90++) {
      A->data[i90] = 1 + i90;
    }
  }

  a = f_sum(*(int (*)[4])&NumRec[0]) + 1.0;
  b = g_sum(*(int (*)[5])&NumRec[0]);
  emxInit_real_T(&CR, 2);
  if (b < a) {
    i90 = CR->size[0] * CR->size[1];
    CR->size[1] = 0;
    emxEnsureCapacity_real_T(CR, i90);
  } else if (floor(a) == a) {
    i90 = CR->size[0] * CR->size[1];
    CR->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(CR, i90);
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

    i90 = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    CR->size[1] = n;
    emxEnsureCapacity_real_T(CR, i90);
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
    i90 = An->size[0] * An->size[1];
    An->size[0] = 1;
    An->size[1] = qEnd;
    emxEnsureCapacity_int32_T(An, i90);
    for (i90 = 0; i90 < qEnd; i90++) {
      An->data[i90] = 1 + i90;
    }
  }

  emxInit_int32_T(&CPO, 2);
  if (PCPO->size[1] < 1) {
    CPO->size[0] = 1;
    CPO->size[1] = 0;
  } else {
    qEnd = PCPO->size[1];
    i90 = CPO->size[0] * CPO->size[1];
    CPO->size[0] = 1;
    CPO->size[1] = qEnd;
    emxEnsureCapacity_int32_T(CPO, i90);
    for (i90 = 0; i90 < qEnd; i90++) {
      CPO->data[i90] = 1 + i90;
    }
  }

  if (PCR->size[1] < 1) {
    CR->size[0] = 1;
    CR->size[1] = 0;
  } else {
    i90 = PCR->size[1];
    kEnd = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    qEnd = (int)((double)i90 - 1.0);
    CR->size[1] = qEnd + 1;
    emxEnsureCapacity_real_T(CR, kEnd);
    for (i90 = 0; i90 <= qEnd; i90++) {
      CR->data[i90] = 1.0 + (double)i90;
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
    i90 = EA->size[0] * EA->size[1];
    EA->size[0] = 1;
    EA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(EA, i90);
    for (i90 = 0; i90 <= qEnd; i90++) {
      EA->data[i90] = 1 + i90;
    }
  }

  if (PMA->size[1] - 1 < 1) {
    AA->size[0] = 1;
    AA->size[1] = 0;
  } else {
    qEnd = PMA->size[1] - 2;
    i90 = AA->size[0] * AA->size[1];
    AA->size[0] = 1;
    AA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AA, i90);
    for (i90 = 0; i90 <= qEnd; i90++) {
      AA->data[i90] = 1 + i90;
    }
  }

  if (PMAn->size[1] - 1 < 1) {
    AnA->size[0] = 1;
    AnA->size[1] = 0;
  } else {
    qEnd = PMAn->size[1] - 2;
    i90 = AnA->size[0] * AnA->size[1];
    AnA->size[0] = 1;
    AnA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AnA, i90);
    for (i90 = 0; i90 <= qEnd; i90++) {
      AnA->data[i90] = 1 + i90;
    }
  }

  if (PS->size[1] - 1 < 1) {
    SA->size[0] = 1;
    SA->size[1] = 0;
  } else {
    qEnd = PS->size[1] - 2;
    i90 = SA->size[0] * SA->size[1];
    SA->size[0] = 1;
    SA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(SA, i90);
    for (i90 = 0; i90 <= qEnd; i90++) {
      SA->data[i90] = 1 + i90;
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
    i90 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = PCPrO->size[1];
    emxEnsureCapacity_boolean_T(x, i90);
    qEnd = PCPrO->size[0] * PCPrO->size[1];
    for (i90 = 0; i90 < qEnd; i90++) {
      x->data[i90] = (PCPrO->data[i90] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i90 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i90);
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
        i90 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i90);
      }
    }

    i90 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = j->size[1];
    emxEnsureCapacity_real_T(C, i90);
    qEnd = j->size[0] * j->size[1];
    for (i90 = 0; i90 < qEnd; i90++) {
      C->data[i90] = j->data[i90];
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
    i90 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = C->size[1];
    emxEnsureCapacity_boolean_T(x, i90);
    qEnd = C->size[0] * C->size[1];
    for (i90 = 0; i90 < qEnd; i90++) {
      x->data[i90] = (tempUltPosRecXDia->data[(int)C->data[i90] - 1] <= nm1d2);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i90 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i90);
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
        i90 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i90);
      }
    }

    i90 = allC->size[0] * allC->size[1];
    allC->size[0] = 1;
    allC->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(allC, i90);
    qEnd = j->size[0] * j->size[1];
    for (i90 = 0; i90 < qEnd; i90++) {
      allC->data[i90] = j->data[i90];
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
      i90 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(j, i90);
      qEnd = allC->size[0] * allC->size[1];
      for (i90 = 0; i90 < qEnd; i90++) {
        j->data[i90] = tempUltPosRecXDia->data[(int)(unsigned int)C->data
          [allC->data[i90] - 1] - 1];
      }

      na = allC->size[1];
      n = allC->size[1] + 1;
      i90 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(idx, i90);
      qEnd = allC->size[1];
      for (i90 = 0; i90 < qEnd; i90++) {
        idx->data[i90] = 0;
      }

      i90 = iwork->size[0];
      iwork->size[0] = allC->size[1];
      emxEnsureCapacity_int32_T(iwork, i90);
      i90 = allC->size[1] - 1;
      for (k = 1; k <= i90; k += 2) {
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

      i90 = b_b->size[0] * b_b->size[1];
      b_b->size[0] = 1;
      b_b->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(b_b, i90);
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

      i90 = iwork->size[0];
      iwork->size[0] = nb + 1;
      emxEnsureCapacity_int32_T(iwork, i90);
      for (k = 0; k <= nb; k++) {
        iwork->data[k] = idx->data[k];
      }

      i90 = uCPrODisp->size[0] * uCPrODisp->size[1];
      uCPrODisp->size[0] = 1;
      uCPrODisp->size[1] = iwork->size[0];
      emxEnsureCapacity_uint32_T(uCPrODisp, i90);
      qEnd = iwork->size[0];
      for (i90 = 0; i90 < qEnd; i90++) {
        uCPrODisp->data[i90] = (unsigned int)C->data[allC->data[iwork->data[i90]
          - 1] - 1];
      }

      if (NumRec[0] > 2147483646) {
        nm1d2 = MAX_int32_T;
      } else {
        nm1d2 = NumRec[0] + 1;
      }

      a = rt_roundd(c_sum(*(int (*)[2])&NumRec[0]));
      if (a < 2.147483648E+9) {
        if (a >= -2.147483648E+9) {
          i90 = (int)a;
        } else {
          i90 = MIN_int32_T;
        }
      } else {
        i90 = MAX_int32_T;
      }

      if (nm1d2 > i90) {
        i90 = -1;
      } else {
        i90 = nm1d2 - 2;
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
        i91 = (long long)PME->data[kEnd] * DispME->data[kEnd];
        if (i91 > 2147483647LL) {
          i91 = 2147483647LL;
        } else {
          if (i91 < -2147483648LL) {
            i91 = -2147483648LL;
          }
        }

        x->data[kEnd] = ((int)i91 != 0);
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
      a = d_sum(*(int (*)[3])&NumRec[0]) + 1.0;
      b = f_sum(*(int (*)[4])&NumRec[0]);
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
      a = f_sum(*(int (*)[4])&NumRec[0]) + 1.0;
      b = g_sum(*(int (*)[5])&NumRec[0]);
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
      a = c_sum(*(int (*)[2])&NumRec[0]) + 1.0;
      b = d_sum(*(int (*)[3])&NumRec[0]);
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
              * (i90 + (int)C->data[p])) - 1] <= e_qY);
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

            a = h_sum(*(int (*)[6])&NumRec[0]);
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

            i_sum(b_H, r18);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r18->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r18->size[0] * r18->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r18->data[p] == 0.0);
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

            a = g_sum(*(int (*)[5])&NumRec[0]);
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

            i_sum(b_H, r18);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r18->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r18->size[0] * r18->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r18->data[p] == 0.0);
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
            a = h_sum(*(int (*)[6])&NumRec[0]);
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

            i_sum(b_H, r18);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r18->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r18->size[0] * r18->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r18->data[p] == 0.0);
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
        i90 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        kEnd = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        tempUltPosRecXDia->size[0] = 1;
        emxEnsureCapacity_int32_T(tempUltPosRecXDia, kEnd);
        qEnd = i90 - 1;
        for (i90 = 0; i90 <= qEnd; i90++) {
          nm1d2 = tempUltPosRecXDia->data[i90];
          if (nm1d2 > 2147483646) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2++;
          }

          tempUltPosRecXDia->data[i90] = nm1d2;
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

        i90 = SA->size[0] * SA->size[1];
        SA->size[0] = 1;
        SA->size[1] = 1;
        emxEnsureCapacity_int32_T(SA, i90);
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

        i90 = EA->size[0] * EA->size[1];
        EA->size[0] = 1;
        EA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(EA, i90);
        for (i90 = 0; i90 < qEnd; i90++) {
          EA->data[i90] = (int)C->data[E->data[i90] - 1];
        }

        if (1 > PMA->data[PMA->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMA->data[PMA->size[1] - 1];
        }

        i90 = AA->size[0] * AA->size[1];
        AA->size[0] = 1;
        AA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AA, i90);
        for (i90 = 0; i90 < qEnd; i90++) {
          AA->data[i90] = allA->data[A->data[i90] - 1];
        }

        if (1 > PMAn->data[PMAn->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMAn->data[PMAn->size[1] - 1];
        }

        i90 = AnA->size[0] * AnA->size[1];
        AnA->size[0] = 1;
        AnA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AnA, i90);
        for (i90 = 0; i90 < qEnd; i90++) {
          AnA->data[i90] = allAn->data[An->data[i90] - 1];
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
  emxFree_real_T(&r18);
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
  int i99;
  double a;
  double b;
  emxArray_real_T *r20;
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
  long long i100;
  int exitg2;
  emxInit_int32_T(&j, 2);
  if (NumRec[0] > 2147483646) {
    nm1d2 = MAX_int32_T;
  } else {
    nm1d2 = NumRec[0] + 1;
  }

  eml_signed_integer_colon(nm1d2, (int)c_sum(*(int (*)[2])&NumRec[0]), j);
  nm1d2 = j->size[1];
  emxInit_int32_T(&E, 2);
  if (nm1d2 < 1) {
    E->size[0] = 1;
    E->size[1] = 0;
  } else {
    i99 = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = nm1d2;
    emxEnsureCapacity_int32_T(E, i99);
    for (i99 = 0; i99 < nm1d2; i99++) {
      E->data[i99] = 1 + i99;
    }
  }

  a = c_sum(*(int (*)[2])&NumRec[0]) + 1.0;
  b = d_sum(*(int (*)[3])&NumRec[0]);
  emxInit_real_T(&r20, 2);
  if (b < a) {
    i99 = r20->size[0] * r20->size[1];
    r20->size[1] = 0;
    emxEnsureCapacity_real_T(r20, i99);
  } else if (floor(a) == a) {
    i99 = r20->size[0] * r20->size[1];
    r20->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(r20, i99);
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

    i99 = r20->size[0] * r20->size[1];
    r20->size[0] = 1;
    r20->size[1] = n;
    emxEnsureCapacity_real_T(r20, i99);
    if ((n > 0) && (n > 1)) {
      r20->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (k = 0; k <= nm1d2 - 2; k++) {
        r20->data[1 + k] = a + (1.0 + (double)k);
        r20->data[(n - k) - 2] = apnd - (1.0 + (double)k);
      }

      if (nm1d2 << 1 == n - 1) {
        r20->data[nm1d2] = (a + apnd) / 2.0;
      } else {
        r20->data[nm1d2] = a + (double)nm1d2;
        r20->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_int32_T(&S, 2);
  if (r20->size[1] < 1) {
    S->size[0] = 1;
    S->size[1] = 0;
  } else {
    qEnd = r20->size[1];
    i99 = S->size[0] * S->size[1];
    S->size[0] = 1;
    S->size[1] = qEnd;
    emxEnsureCapacity_int32_T(S, i99);
    for (i99 = 0; i99 < qEnd; i99++) {
      S->data[i99] = 1 + i99;
    }
  }

  a = d_sum(*(int (*)[3])&NumRec[0]) + 1.0;
  b = f_sum(*(int (*)[4])&NumRec[0]);
  emxInit_real_T(&C, 2);
  if (b < a) {
    i99 = C->size[0] * C->size[1];
    C->size[1] = 0;
    emxEnsureCapacity_real_T(C, i99);
  } else if (floor(a) == a) {
    i99 = C->size[0] * C->size[1];
    C->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(C, i99);
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

    i99 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = n;
    emxEnsureCapacity_real_T(C, i99);
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
    i99 = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = qEnd;
    emxEnsureCapacity_int32_T(A, i99);
    for (i99 = 0; i99 < qEnd; i99++) {
      A->data[i99] = 1 + i99;
    }
  }

  a = f_sum(*(int (*)[4])&NumRec[0]) + 1.0;
  b = g_sum(*(int (*)[5])&NumRec[0]);
  emxInit_real_T(&CR, 2);
  if (b < a) {
    i99 = CR->size[0] * CR->size[1];
    CR->size[1] = 0;
    emxEnsureCapacity_real_T(CR, i99);
  } else if (floor(a) == a) {
    i99 = CR->size[0] * CR->size[1];
    CR->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(CR, i99);
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

    i99 = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    CR->size[1] = n;
    emxEnsureCapacity_real_T(CR, i99);
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
    i99 = An->size[0] * An->size[1];
    An->size[0] = 1;
    An->size[1] = qEnd;
    emxEnsureCapacity_int32_T(An, i99);
    for (i99 = 0; i99 < qEnd; i99++) {
      An->data[i99] = 1 + i99;
    }
  }

  emxInit_int32_T(&CPO, 2);
  if (PCPO->size[1] < 1) {
    CPO->size[0] = 1;
    CPO->size[1] = 0;
  } else {
    qEnd = PCPO->size[1];
    i99 = CPO->size[0] * CPO->size[1];
    CPO->size[0] = 1;
    CPO->size[1] = qEnd;
    emxEnsureCapacity_int32_T(CPO, i99);
    for (i99 = 0; i99 < qEnd; i99++) {
      CPO->data[i99] = 1 + i99;
    }
  }

  if (PCR->size[1] < 1) {
    CR->size[0] = 1;
    CR->size[1] = 0;
  } else {
    i99 = PCR->size[1];
    kEnd = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    qEnd = (int)((double)i99 - 1.0);
    CR->size[1] = qEnd + 1;
    emxEnsureCapacity_real_T(CR, kEnd);
    for (i99 = 0; i99 <= qEnd; i99++) {
      CR->data[i99] = 1.0 + (double)i99;
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
    i99 = EA->size[0] * EA->size[1];
    EA->size[0] = 1;
    EA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(EA, i99);
    for (i99 = 0; i99 <= qEnd; i99++) {
      EA->data[i99] = 1 + i99;
    }
  }

  if (PMA->size[1] - 1 < 1) {
    AA->size[0] = 1;
    AA->size[1] = 0;
  } else {
    qEnd = PMA->size[1] - 2;
    i99 = AA->size[0] * AA->size[1];
    AA->size[0] = 1;
    AA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AA, i99);
    for (i99 = 0; i99 <= qEnd; i99++) {
      AA->data[i99] = 1 + i99;
    }
  }

  if (PMAn->size[1] - 1 < 1) {
    AnA->size[0] = 1;
    AnA->size[1] = 0;
  } else {
    qEnd = PMAn->size[1] - 2;
    i99 = AnA->size[0] * AnA->size[1];
    AnA->size[0] = 1;
    AnA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AnA, i99);
    for (i99 = 0; i99 <= qEnd; i99++) {
      AnA->data[i99] = 1 + i99;
    }
  }

  if (PS->size[1] - 1 < 1) {
    SA->size[0] = 1;
    SA->size[1] = 0;
  } else {
    qEnd = PS->size[1] - 2;
    i99 = SA->size[0] * SA->size[1];
    SA->size[0] = 1;
    SA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(SA, i99);
    for (i99 = 0; i99 <= qEnd; i99++) {
      SA->data[i99] = 1 + i99;
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
    i99 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = PCPrO->size[1];
    emxEnsureCapacity_boolean_T(x, i99);
    qEnd = PCPrO->size[0] * PCPrO->size[1];
    for (i99 = 0; i99 < qEnd; i99++) {
      x->data[i99] = (PCPrO->data[i99] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i99 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i99);
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
        i99 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i99);
      }
    }

    i99 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = j->size[1];
    emxEnsureCapacity_real_T(C, i99);
    qEnd = j->size[0] * j->size[1];
    for (i99 = 0; i99 < qEnd; i99++) {
      C->data[i99] = j->data[i99];
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
    i99 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = C->size[1];
    emxEnsureCapacity_boolean_T(x, i99);
    qEnd = C->size[0] * C->size[1];
    for (i99 = 0; i99 < qEnd; i99++) {
      x->data[i99] = (tempUltPosRecXDia->data[(int)C->data[i99] - 1] <= nm1d2);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i99 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i99);
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
        i99 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i99);
      }
    }

    i99 = allC->size[0] * allC->size[1];
    allC->size[0] = 1;
    allC->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(allC, i99);
    qEnd = j->size[0] * j->size[1];
    for (i99 = 0; i99 < qEnd; i99++) {
      allC->data[i99] = j->data[i99];
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
      i99 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(j, i99);
      qEnd = allC->size[0] * allC->size[1];
      for (i99 = 0; i99 < qEnd; i99++) {
        j->data[i99] = tempUltPosRecXDia->data[(int)(unsigned int)C->data
          [allC->data[i99] - 1] - 1];
      }

      na = allC->size[1];
      n = allC->size[1] + 1;
      i99 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(idx, i99);
      qEnd = allC->size[1];
      for (i99 = 0; i99 < qEnd; i99++) {
        idx->data[i99] = 0;
      }

      i99 = iwork->size[0];
      iwork->size[0] = allC->size[1];
      emxEnsureCapacity_int32_T(iwork, i99);
      i99 = allC->size[1] - 1;
      for (k = 1; k <= i99; k += 2) {
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

      i99 = b_b->size[0] * b_b->size[1];
      b_b->size[0] = 1;
      b_b->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(b_b, i99);
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

      i99 = iwork->size[0];
      iwork->size[0] = nb + 1;
      emxEnsureCapacity_int32_T(iwork, i99);
      for (k = 0; k <= nb; k++) {
        iwork->data[k] = idx->data[k];
      }

      i99 = uCPrODisp->size[0] * uCPrODisp->size[1];
      uCPrODisp->size[0] = 1;
      uCPrODisp->size[1] = iwork->size[0];
      emxEnsureCapacity_uint32_T(uCPrODisp, i99);
      qEnd = iwork->size[0];
      for (i99 = 0; i99 < qEnd; i99++) {
        uCPrODisp->data[i99] = (unsigned int)C->data[allC->data[iwork->data[i99]
          - 1] - 1];
      }

      if (NumRec[0] > 2147483646) {
        nm1d2 = MAX_int32_T;
      } else {
        nm1d2 = NumRec[0] + 1;
      }

      a = rt_roundd(c_sum(*(int (*)[2])&NumRec[0]));
      if (a < 2.147483648E+9) {
        if (a >= -2.147483648E+9) {
          i99 = (int)a;
        } else {
          i99 = MIN_int32_T;
        }
      } else {
        i99 = MAX_int32_T;
      }

      if (nm1d2 > i99) {
        i99 = -1;
      } else {
        i99 = nm1d2 - 2;
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
        i100 = (long long)PME->data[kEnd] * DispME;
        if (i100 > 2147483647LL) {
          i100 = 2147483647LL;
        } else {
          if (i100 < -2147483648LL) {
            i100 = -2147483648LL;
          }
        }

        x->data[kEnd] = ((int)i100 != 0);
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
      a = d_sum(*(int (*)[3])&NumRec[0]) + 1.0;
      b = f_sum(*(int (*)[4])&NumRec[0]);
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
      a = f_sum(*(int (*)[4])&NumRec[0]) + 1.0;
      b = g_sum(*(int (*)[5])&NumRec[0]);
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
      a = c_sum(*(int (*)[2])&NumRec[0]) + 1.0;
      b = d_sum(*(int (*)[3])&NumRec[0]);
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
              * (i99 + (int)C->data[p])) - 1] <= e_qY);
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

            a = h_sum(*(int (*)[6])&NumRec[0]);
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

            i_sum(b_H, r20);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r20->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r20->size[0] * r20->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r20->data[p] == 0.0);
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

            a = g_sum(*(int (*)[5])&NumRec[0]);
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

            i_sum(b_H, r20);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r20->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r20->size[0] * r20->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r20->data[p] == 0.0);
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
            a = h_sum(*(int (*)[6])&NumRec[0]);
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

            i_sum(b_H, r20);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r20->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r20->size[0] * r20->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r20->data[p] == 0.0);
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
        i99 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        kEnd = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        tempUltPosRecXDia->size[0] = 1;
        emxEnsureCapacity_int32_T(tempUltPosRecXDia, kEnd);
        qEnd = i99 - 1;
        for (i99 = 0; i99 <= qEnd; i99++) {
          nm1d2 = tempUltPosRecXDia->data[i99];
          if (nm1d2 > 2147483646) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2++;
          }

          tempUltPosRecXDia->data[i99] = nm1d2;
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

        i99 = SA->size[0] * SA->size[1];
        SA->size[0] = 1;
        SA->size[1] = 1;
        emxEnsureCapacity_int32_T(SA, i99);
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

        i99 = EA->size[0] * EA->size[1];
        EA->size[0] = 1;
        EA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(EA, i99);
        for (i99 = 0; i99 < qEnd; i99++) {
          EA->data[i99] = (int)C->data[E->data[i99] - 1];
        }

        if (1 > PMA->data[PMA->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMA->data[PMA->size[1] - 1];
        }

        i99 = AA->size[0] * AA->size[1];
        AA->size[0] = 1;
        AA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AA, i99);
        for (i99 = 0; i99 < qEnd; i99++) {
          AA->data[i99] = allA->data[A->data[i99] - 1];
        }

        if (1 > PMAn->data[PMAn->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMAn->data[PMAn->size[1] - 1];
        }

        i99 = AnA->size[0] * AnA->size[1];
        AnA->size[0] = 1;
        AnA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AnA, i99);
        for (i99 = 0; i99 < qEnd; i99++) {
          AnA->data[i99] = allAn->data[An->data[i99] - 1];
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
  emxFree_real_T(&r20);
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
  int i85;
  double a;
  double b;
  emxArray_real_T *r16;
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
  long long i86;
  int exitg2;
  emxInit_int32_T(&j, 2);
  if (NumRec[0] > 2147483646) {
    nm1d2 = MAX_int32_T;
  } else {
    nm1d2 = NumRec[0] + 1;
  }

  eml_signed_integer_colon(nm1d2, (int)c_sum(*(int (*)[2])&NumRec[0]), j);
  nm1d2 = j->size[1];
  emxInit_int32_T(&E, 2);
  if (nm1d2 < 1) {
    E->size[0] = 1;
    E->size[1] = 0;
  } else {
    i85 = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = nm1d2;
    emxEnsureCapacity_int32_T(E, i85);
    for (i85 = 0; i85 < nm1d2; i85++) {
      E->data[i85] = 1 + i85;
    }
  }

  a = c_sum(*(int (*)[2])&NumRec[0]) + 1.0;
  b = d_sum(*(int (*)[3])&NumRec[0]);
  emxInit_real_T(&r16, 2);
  if (b < a) {
    i85 = r16->size[0] * r16->size[1];
    r16->size[1] = 0;
    emxEnsureCapacity_real_T(r16, i85);
  } else if (floor(a) == a) {
    i85 = r16->size[0] * r16->size[1];
    r16->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(r16, i85);
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

    i85 = r16->size[0] * r16->size[1];
    r16->size[0] = 1;
    r16->size[1] = n;
    emxEnsureCapacity_real_T(r16, i85);
    if ((n > 0) && (n > 1)) {
      r16->data[n - 1] = apnd;
      nm1d2 = (n - 1) / 2;
      for (k = 0; k <= nm1d2 - 2; k++) {
        r16->data[1 + k] = a + (1.0 + (double)k);
        r16->data[(n - k) - 2] = apnd - (1.0 + (double)k);
      }

      if (nm1d2 << 1 == n - 1) {
        r16->data[nm1d2] = (a + apnd) / 2.0;
      } else {
        r16->data[nm1d2] = a + (double)nm1d2;
        r16->data[nm1d2 + 1] = apnd - (double)nm1d2;
      }
    }
  }

  emxInit_int32_T(&S, 2);
  if (r16->size[1] < 1) {
    S->size[0] = 1;
    S->size[1] = 0;
  } else {
    qEnd = r16->size[1];
    i85 = S->size[0] * S->size[1];
    S->size[0] = 1;
    S->size[1] = qEnd;
    emxEnsureCapacity_int32_T(S, i85);
    for (i85 = 0; i85 < qEnd; i85++) {
      S->data[i85] = 1 + i85;
    }
  }

  a = d_sum(*(int (*)[3])&NumRec[0]) + 1.0;
  b = f_sum(*(int (*)[4])&NumRec[0]);
  emxInit_real_T(&C, 2);
  if (b < a) {
    i85 = C->size[0] * C->size[1];
    C->size[1] = 0;
    emxEnsureCapacity_real_T(C, i85);
  } else if (floor(a) == a) {
    i85 = C->size[0] * C->size[1];
    C->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(C, i85);
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

    i85 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = n;
    emxEnsureCapacity_real_T(C, i85);
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
    i85 = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = qEnd;
    emxEnsureCapacity_int32_T(A, i85);
    for (i85 = 0; i85 < qEnd; i85++) {
      A->data[i85] = 1 + i85;
    }
  }

  a = f_sum(*(int (*)[4])&NumRec[0]) + 1.0;
  b = g_sum(*(int (*)[5])&NumRec[0]);
  emxInit_real_T(&CR, 2);
  if (b < a) {
    i85 = CR->size[0] * CR->size[1];
    CR->size[1] = 0;
    emxEnsureCapacity_real_T(CR, i85);
  } else if (floor(a) == a) {
    i85 = CR->size[0] * CR->size[1];
    CR->size[1] = (int)floor(b - a) + 1;
    emxEnsureCapacity_real_T(CR, i85);
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

    i85 = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    CR->size[1] = n;
    emxEnsureCapacity_real_T(CR, i85);
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
    i85 = An->size[0] * An->size[1];
    An->size[0] = 1;
    An->size[1] = qEnd;
    emxEnsureCapacity_int32_T(An, i85);
    for (i85 = 0; i85 < qEnd; i85++) {
      An->data[i85] = 1 + i85;
    }
  }

  emxInit_int32_T(&CPO, 2);
  if (PCPO->size[1] < 1) {
    CPO->size[0] = 1;
    CPO->size[1] = 0;
  } else {
    qEnd = PCPO->size[1];
    i85 = CPO->size[0] * CPO->size[1];
    CPO->size[0] = 1;
    CPO->size[1] = qEnd;
    emxEnsureCapacity_int32_T(CPO, i85);
    for (i85 = 0; i85 < qEnd; i85++) {
      CPO->data[i85] = 1 + i85;
    }
  }

  if (PCR->size[1] < 1) {
    CR->size[0] = 1;
    CR->size[1] = 0;
  } else {
    i85 = PCR->size[1];
    kEnd = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    qEnd = (int)((double)i85 - 1.0);
    CR->size[1] = qEnd + 1;
    emxEnsureCapacity_real_T(CR, kEnd);
    for (i85 = 0; i85 <= qEnd; i85++) {
      CR->data[i85] = 1.0 + (double)i85;
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
    i85 = EA->size[0] * EA->size[1];
    EA->size[0] = 1;
    EA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(EA, i85);
    for (i85 = 0; i85 <= qEnd; i85++) {
      EA->data[i85] = 1 + i85;
    }
  }

  if (PMA->size[1] - 1 < 1) {
    AA->size[0] = 1;
    AA->size[1] = 0;
  } else {
    qEnd = PMA->size[1] - 2;
    i85 = AA->size[0] * AA->size[1];
    AA->size[0] = 1;
    AA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AA, i85);
    for (i85 = 0; i85 <= qEnd; i85++) {
      AA->data[i85] = 1 + i85;
    }
  }

  if (PMAn->size[1] - 1 < 1) {
    AnA->size[0] = 1;
    AnA->size[1] = 0;
  } else {
    qEnd = PMAn->size[1] - 2;
    i85 = AnA->size[0] * AnA->size[1];
    AnA->size[0] = 1;
    AnA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(AnA, i85);
    for (i85 = 0; i85 <= qEnd; i85++) {
      AnA->data[i85] = 1 + i85;
    }
  }

  if (PS->size[1] - 1 < 1) {
    SA->size[0] = 1;
    SA->size[1] = 0;
  } else {
    qEnd = PS->size[1] - 2;
    i85 = SA->size[0] * SA->size[1];
    SA->size[0] = 1;
    SA->size[1] = qEnd + 1;
    emxEnsureCapacity_int32_T(SA, i85);
    for (i85 = 0; i85 <= qEnd; i85++) {
      SA->data[i85] = 1 + i85;
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
    i85 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = PCPrO->size[1];
    emxEnsureCapacity_boolean_T(x, i85);
    qEnd = PCPrO->size[0] * PCPrO->size[1];
    for (i85 = 0; i85 < qEnd; i85++) {
      x->data[i85] = (PCPrO->data[i85] != 0);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i85 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i85);
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
        i85 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i85);
      }
    }

    i85 = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = j->size[1];
    emxEnsureCapacity_real_T(C, i85);
    qEnd = j->size[0] * j->size[1];
    for (i85 = 0; i85 < qEnd; i85++) {
      C->data[i85] = j->data[i85];
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
    i85 = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = C->size[1];
    emxEnsureCapacity_boolean_T(x, i85);
    qEnd = C->size[0] * C->size[1];
    for (i85 = 0; i85 < qEnd; i85++) {
      x->data[i85] = (tempUltPosRecXDia->data[(int)C->data[i85] - 1] <= nm1d2);
    }

    if (x->size[1] == 0) {
      j->size[0] = 1;
      j->size[1] = 0;
    } else {
      b_idx = 0;
      i85 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(j, i85);
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
        i85 = j->size[0] * j->size[1];
        j->size[1] = b_idx;
        emxEnsureCapacity_int32_T(j, i85);
      }
    }

    i85 = allC->size[0] * allC->size[1];
    allC->size[0] = 1;
    allC->size[1] = j->size[1];
    emxEnsureCapacity_int32_T(allC, i85);
    qEnd = j->size[0] * j->size[1];
    for (i85 = 0; i85 < qEnd; i85++) {
      allC->data[i85] = j->data[i85];
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
      i85 = j->size[0] * j->size[1];
      j->size[0] = 1;
      j->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(j, i85);
      qEnd = allC->size[0] * allC->size[1];
      for (i85 = 0; i85 < qEnd; i85++) {
        j->data[i85] = tempUltPosRecXDia->data[(int)(unsigned int)C->data
          [allC->data[i85] - 1] - 1];
      }

      na = allC->size[1];
      n = allC->size[1] + 1;
      i85 = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(idx, i85);
      qEnd = allC->size[1];
      for (i85 = 0; i85 < qEnd; i85++) {
        idx->data[i85] = 0;
      }

      i85 = iwork->size[0];
      iwork->size[0] = allC->size[1];
      emxEnsureCapacity_int32_T(iwork, i85);
      i85 = allC->size[1] - 1;
      for (k = 1; k <= i85; k += 2) {
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

      i85 = b_b->size[0] * b_b->size[1];
      b_b->size[0] = 1;
      b_b->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(b_b, i85);
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

      i85 = iwork->size[0];
      iwork->size[0] = nb + 1;
      emxEnsureCapacity_int32_T(iwork, i85);
      for (k = 0; k <= nb; k++) {
        iwork->data[k] = idx->data[k];
      }

      i85 = uCPrODisp->size[0] * uCPrODisp->size[1];
      uCPrODisp->size[0] = 1;
      uCPrODisp->size[1] = iwork->size[0];
      emxEnsureCapacity_uint32_T(uCPrODisp, i85);
      qEnd = iwork->size[0];
      for (i85 = 0; i85 < qEnd; i85++) {
        uCPrODisp->data[i85] = (unsigned int)C->data[allC->data[iwork->data[i85]
          - 1] - 1];
      }

      if (NumRec[0] > 2147483646) {
        nm1d2 = MAX_int32_T;
      } else {
        nm1d2 = NumRec[0] + 1;
      }

      a = rt_roundd(c_sum(*(int (*)[2])&NumRec[0]));
      if (a < 2.147483648E+9) {
        if (a >= -2.147483648E+9) {
          i85 = (int)a;
        } else {
          i85 = MIN_int32_T;
        }
      } else {
        i85 = MAX_int32_T;
      }

      if (nm1d2 > i85) {
        i85 = -1;
      } else {
        i85 = nm1d2 - 2;
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
        i86 = (long long)PME->data[kEnd] * DispME->data[kEnd];
        if (i86 > 2147483647LL) {
          i86 = 2147483647LL;
        } else {
          if (i86 < -2147483648LL) {
            i86 = -2147483648LL;
          }
        }

        x->data[kEnd] = ((int)i86 != 0);
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
      a = d_sum(*(int (*)[3])&NumRec[0]) + 1.0;
      b = f_sum(*(int (*)[4])&NumRec[0]);
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
      a = f_sum(*(int (*)[4])&NumRec[0]) + 1.0;
      b = g_sum(*(int (*)[5])&NumRec[0]);
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
      a = c_sum(*(int (*)[2])&NumRec[0]) + 1.0;
      b = d_sum(*(int (*)[3])&NumRec[0]);
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
              * (i85 + (int)C->data[p])) - 1] <= e_qY);
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

            a = h_sum(*(int (*)[6])&NumRec[0]);
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

            n_sum(b_H, r16);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r16->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r16->size[0] * r16->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r16->data[p] == 0.0);
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

            a = g_sum(*(int (*)[5])&NumRec[0]);
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

            n_sum(b_H, r16);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r16->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r16->size[0] * r16->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r16->data[p] == 0.0);
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
            a = h_sum(*(int (*)[6])&NumRec[0]);
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

            n_sum(b_H, r16);
            p = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r16->size[1];
            emxEnsureCapacity_boolean_T(x, p);
            qEnd = r16->size[0] * r16->size[1];
            for (p = 0; p < qEnd; p++) {
              x->data[p] = (r16->data[p] == 0.0);
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
        i85 = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        kEnd = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        tempUltPosRecXDia->size[0] = 1;
        emxEnsureCapacity_int32_T(tempUltPosRecXDia, kEnd);
        qEnd = i85 - 1;
        for (i85 = 0; i85 <= qEnd; i85++) {
          nm1d2 = tempUltPosRecXDia->data[i85];
          if (nm1d2 > 2147483646) {
            nm1d2 = MAX_int32_T;
          } else {
            nm1d2++;
          }

          tempUltPosRecXDia->data[i85] = nm1d2;
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

        i85 = SA->size[0] * SA->size[1];
        SA->size[0] = 1;
        SA->size[1] = 1;
        emxEnsureCapacity_int32_T(SA, i85);
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

        i85 = EA->size[0] * EA->size[1];
        EA->size[0] = 1;
        EA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(EA, i85);
        for (i85 = 0; i85 < qEnd; i85++) {
          EA->data[i85] = (int)C->data[E->data[i85] - 1];
        }

        if (1 > PMA->data[PMA->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMA->data[PMA->size[1] - 1];
        }

        i85 = AA->size[0] * AA->size[1];
        AA->size[0] = 1;
        AA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AA, i85);
        for (i85 = 0; i85 < qEnd; i85++) {
          AA->data[i85] = allA->data[A->data[i85] - 1];
        }

        if (1 > PMAn->data[PMAn->size[1] - 1]) {
          qEnd = 0;
        } else {
          qEnd = PMAn->data[PMAn->size[1] - 1];
        }

        i85 = AnA->size[0] * AnA->size[1];
        AnA->size[0] = 1;
        AnA->size[1] = qEnd;
        emxEnsureCapacity_int32_T(AnA, i85);
        for (i85 = 0; i85 < qEnd; i85++) {
          AnA->data[i85] = allAn->data[An->data[i85] - 1];
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
  emxFree_real_T(&r16);
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
