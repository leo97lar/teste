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

/* Function Definitions */

/*
 * function [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,AA,AnA,SA,IniSA,EndSA,EndRPxD,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,contDia] = ...
 *     funcionCPrO(NumRec, PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,H,Dia,UltPosRecXDia, TimeUsoCPrO, TimeUsoS,TimeUsoCPO,TimeUsoCR,contDia,...
 *     tempUltPosRecXDia,DispMExD,DispME)
 */
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
  int b_tmp;
  int n;
  unsigned int nm1;
  emxArray_int32_T *jj;
  int q;
  emxArray_int32_T *E;
  int yk;
  int k;
  int nb;
  double y_tmp;
  double y;
  emxArray_real_T *r17;
  double ndbl;
  double apnd;
  double cdiff;
  emxArray_int32_T *S;
  emxArray_real_T *r18;
  emxArray_int32_T *A;
  emxArray_real_T *r19;
  emxArray_int32_T *An;
  emxArray_int32_T *CPO;
  emxArray_int32_T *CR;
  int b_CPrOA;
  int b_CPOA;
  int b_CRA;
  int b_IniCPrOA;
  int b_EndCPrOA;
  int b_IniSA;
  int b_EndSA;
  int b_IniCPOA;
  int b_EndCPOA;
  int b_IniCRA;
  int b_EndCRA;
  int b_EndCPrOAxD;
  int b_EndRPxD;
  emxArray_int32_T *EA_double;
  emxArray_int32_T *AA_double;
  emxArray_int32_T *AnA_double;
  emxArray_int32_T *SA_double;
  boolean_T flag;
  emxArray_uint32_T *uCPrODisp;
  emxArray_real_T *auxUPxE;
  emxArray_real_T *auxUPxA;
  emxArray_real_T *auxUPxAn;
  emxArray_real_T *auxUPxS;
  emxArray_int32_T *C;
  emxArray_int32_T *allC;
  emxArray_int32_T *u;
  emxArray_int32_T *allE;
  emxArray_int32_T *allA;
  emxArray_int32_T *allAn;
  emxArray_int32_T *allS;
  emxArray_int32_T *allCPO;
  emxArray_int32_T *allCR;
  emxArray_boolean_T *x;
  emxArray_int32_T *b;
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  emxArray_real_T *b_H;
  int b_idx;
  boolean_T exitg1;
  int minP;
  int na;
  int j;
  int p;
  int qEnd;
  int kEnd;
  int temCPrO;
  int exitg2;
  int IniCPO;
  int EndCPO;
  int IniCR;

  /* 'funcionCPrO:5' E = 1:size(NumRec(1)+1:sum(NumRec(1:2)),2); */
  b_tmp = NumRec[0] + NumRec[1];
  if (b_tmp < NumRec[0] + 1) {
    n = 0;
  } else {
    if ((NumRec[0] + 1 < 0) && (b_tmp >= 0)) {
      nm1 = ((unsigned int)b_tmp - NumRec[0]) - 1U;
    } else {
      nm1 = (unsigned int)((b_tmp - NumRec[0]) - 1);
    }

    n = (int)nm1 + 1;
  }

  emxInit_int32_T(&jj, 2);
  q = jj->size[0] * jj->size[1];
  jj->size[0] = 1;
  jj->size[1] = n;
  emxEnsureCapacity_int32_T(jj, q);
  if (n > 0) {
    jj->data[0] = NumRec[0] + 1;
    yk = NumRec[0] + 1;
    for (k = 2; k <= n; k++) {
      yk++;
      jj->data[k - 1] = yk;
    }
  }

  emxInit_int32_T(&E, 2);
  if (jj->size[1] < 1) {
    E->size[0] = 1;
    E->size[1] = 0;
  } else {
    nb = jj->size[1];
    q = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = nb;
    emxEnsureCapacity_int32_T(E, q);
    for (q = 0; q < nb; q++) {
      E->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:6' S = 1:size(sum(NumRec(1:2))+1:sum(NumRec(1:3)),2); */
  y_tmp = (double)NumRec[0] + (double)NumRec[1];
  y = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
  emxInit_real_T(&r17, 2);
  if (y < y_tmp + 1.0) {
    q = r17->size[0] * r17->size[1];
    r17->size[1] = 0;
    emxEnsureCapacity_real_T(r17, q);
  } else if (((double)NumRec[0] + (double)NumRec[1]) + 1.0 == y_tmp + 1.0) {
    q = r17->size[0] * r17->size[1];
    r17->size[1] = (int)(y - (y_tmp + 1.0)) + 1;
    emxEnsureCapacity_real_T(r17, q);
  } else {
    ndbl = floor((y - (y_tmp + 1.0)) + 0.5);
    apnd = (y_tmp + 1.0) + ndbl;
    cdiff = apnd - y;
    if (fabs(cdiff) < 4.4408920985006262E-16 * fmax((unsigned int)fabs(y_tmp +
          1.0), fabs(y))) {
      ndbl++;
      apnd = y;
    } else if (cdiff > 0.0) {
      apnd = (y_tmp + 1.0) + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }

    q = r17->size[0] * r17->size[1];
    r17->size[0] = 1;
    r17->size[1] = n;
    emxEnsureCapacity_real_T(r17, q);
    if ((n > 0) && (n > 1)) {
      r17->data[n - 1] = apnd;
      yk = (n - 1) / 2;
      for (k = 0; k <= yk - 2; k++) {
        r17->data[1 + k] = (y_tmp + 1.0) + (1.0 + (double)k);
        r17->data[(n - k) - 2] = apnd - (1.0 + (double)k);
      }

      if (yk << 1 == n - 1) {
        r17->data[yk] = ((y_tmp + 1.0) + apnd) / 2.0;
      } else {
        r17->data[yk] = (y_tmp + 1.0) + (double)yk;
        r17->data[yk + 1] = apnd - (double)yk;
      }
    }
  }

  emxInit_int32_T(&S, 2);
  if (r17->size[1] < 1) {
    S->size[0] = 1;
    S->size[1] = 0;
  } else {
    nb = r17->size[1];
    q = S->size[0] * S->size[1];
    S->size[0] = 1;
    S->size[1] = nb;
    emxEnsureCapacity_int32_T(S, q);
    for (q = 0; q < nb; q++) {
      S->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:7' A = 1:size(sum(NumRec(1:3))+1:sum(NumRec(1:4)),2); */
  y = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
  ndbl = (((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) + (double)
    NumRec[3];
  emxInit_real_T(&r18, 2);
  if (ndbl < y + 1.0) {
    q = r18->size[0] * r18->size[1];
    r18->size[1] = 0;
    emxEnsureCapacity_real_T(r18, q);
  } else {
    q = r18->size[0] * r18->size[1];
    r18->size[1] = (int)(ndbl - (y + 1.0)) + 1;
    emxEnsureCapacity_real_T(r18, q);
  }

  emxInit_int32_T(&A, 2);
  if (r18->size[1] < 1) {
    A->size[0] = 1;
    A->size[1] = 0;
  } else {
    nb = r18->size[1];
    q = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = nb;
    emxEnsureCapacity_int32_T(A, q);
    for (q = 0; q < nb; q++) {
      A->data[q] = 1 + q;
    }
  }

  emxFree_real_T(&r18);

  /* 'funcionCPrO:8' An = 1:size(sum(NumRec(1:4))+1:sum(NumRec(1:5)),2); */
  y = (((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) + (double)
    NumRec[3];
  ndbl = ((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
          (double)NumRec[3]) + (double)NumRec[4];
  emxInit_real_T(&r19, 2);
  if (ndbl < y + 1.0) {
    q = r19->size[0] * r19->size[1];
    r19->size[1] = 0;
    emxEnsureCapacity_real_T(r19, q);
  } else {
    q = r19->size[0] * r19->size[1];
    r19->size[1] = (int)(ndbl - (y + 1.0)) + 1;
    emxEnsureCapacity_real_T(r19, q);
  }

  emxInit_int32_T(&An, 2);
  if (r19->size[1] < 1) {
    An->size[0] = 1;
    An->size[1] = 0;
  } else {
    nb = r19->size[1];
    q = An->size[0] * An->size[1];
    An->size[0] = 1;
    An->size[1] = nb;
    emxEnsureCapacity_int32_T(An, q);
    for (q = 0; q < nb; q++) {
      An->data[q] = 1 + q;
    }
  }

  emxFree_real_T(&r19);

  /* 'funcionCPrO:9' CPO = 1:size(PCPO, 2); */
  emxInit_int32_T(&CPO, 2);
  if (PCPO->size[1] < 1) {
    CPO->size[0] = 1;
    CPO->size[1] = 0;
  } else {
    nb = PCPO->size[1];
    q = CPO->size[0] * CPO->size[1];
    CPO->size[0] = 1;
    CPO->size[1] = nb;
    emxEnsureCapacity_int32_T(CPO, q);
    for (q = 0; q < nb; q++) {
      CPO->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:10' CR = 1:size(PCR, 2); */
  emxInit_int32_T(&CR, 2);
  if (PCR->size[1] < 1) {
    CR->size[0] = 1;
    CR->size[1] = 0;
  } else {
    nb = PCR->size[1];
    q = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    CR->size[1] = nb;
    emxEnsureCapacity_int32_T(CR, q);
    for (q = 0; q < nb; q++) {
      CR->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:11' CPrOA = int32(0); */
  b_CPrOA = 0;

  /* 'funcionCPrO:12' CPOA = int32(0); */
  b_CPOA = 0;

  /* 'funcionCPrO:13' CRA = int32(0); */
  b_CRA = 0;

  /* 'funcionCPrO:14' IniCPrOA = int32(0); */
  b_IniCPrOA = 0;

  /* 'funcionCPrO:15' EndCPrOA = int32(0); */
  b_EndCPrOA = 1;

  /* 'funcionCPrO:16' IniSA = int32(0); */
  b_IniSA = 0;

  /* 'funcionCPrO:17' EndSA = int32(0); */
  b_EndSA = 0;

  /* 'funcionCPrO:18' IniCPOA = int32(0); */
  b_IniCPOA = -1;

  /* 'funcionCPrO:19' EndCPOA = int32(0); */
  b_EndCPOA = 0;

  /* 'funcionCPrO:20' IniCRA = int32(0); */
  b_IniCRA = -1;

  /* 'funcionCPrO:21' EndCRA = int32(0); */
  b_EndCRA = 0;

  /* 'funcionCPrO:22' EndCPrOAxD = int32(0); */
  b_EndCPrOAxD = 0;

  /* 'funcionCPrO:23' EndRPxD = int32(0); */
  b_EndRPxD = 0;

  /* 'funcionCPrO:24' EA_double = 1:size(PME,2)-1; */
  emxInit_int32_T(&EA_double, 2);
  if (PME->size[1] - 1 < 1) {
    EA_double->size[0] = 1;
    EA_double->size[1] = 0;
  } else {
    nb = PME->size[1] - 2;
    q = EA_double->size[0] * EA_double->size[1];
    EA_double->size[0] = 1;
    EA_double->size[1] = nb + 1;
    emxEnsureCapacity_int32_T(EA_double, q);
    for (q = 0; q <= nb; q++) {
      EA_double->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:25' AA_double = 1:size(PMA,2)-1; */
  emxInit_int32_T(&AA_double, 2);
  if (PMA->size[1] - 1 < 1) {
    AA_double->size[0] = 1;
    AA_double->size[1] = 0;
  } else {
    nb = PMA->size[1] - 2;
    q = AA_double->size[0] * AA_double->size[1];
    AA_double->size[0] = 1;
    AA_double->size[1] = nb + 1;
    emxEnsureCapacity_int32_T(AA_double, q);
    for (q = 0; q <= nb; q++) {
      AA_double->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:26' AnA_double = 1:size(PMAn,2)-1; */
  emxInit_int32_T(&AnA_double, 2);
  if (PMAn->size[1] - 1 < 1) {
    AnA_double->size[0] = 1;
    AnA_double->size[1] = 0;
  } else {
    nb = PMAn->size[1] - 2;
    q = AnA_double->size[0] * AnA_double->size[1];
    AnA_double->size[0] = 1;
    AnA_double->size[1] = nb + 1;
    emxEnsureCapacity_int32_T(AnA_double, q);
    for (q = 0; q <= nb; q++) {
      AnA_double->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:27' SA_double = 1:size(PS,2)-1; */
  emxInit_int32_T(&SA_double, 2);
  if (PS->size[1] - 1 < 1) {
    SA_double->size[0] = 1;
    SA_double->size[1] = 0;
  } else {
    nb = PS->size[1] - 2;
    q = SA_double->size[0] * SA_double->size[1];
    SA_double->size[0] = 1;
    SA_double->size[1] = nb + 1;
    emxEnsureCapacity_int32_T(SA_double, q);
    for (q = 0; q <= nb; q++) {
      SA_double->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:29' flag = true; */
  flag = true;

  /* 'funcionCPrO:30' while flag */
  emxInit_uint32_T(&uCPrODisp, 2);
  emxInit_real_T(&auxUPxE, 2);
  emxInit_real_T(&auxUPxA, 2);
  emxInit_real_T(&auxUPxAn, 2);
  emxInit_real_T(&auxUPxS, 2);
  emxInit_int32_T(&C, 2);
  emxInit_int32_T(&allC, 2);
  emxInit_int32_T(&u, 1);
  emxInit_int32_T(&allE, 2);
  emxInit_int32_T(&allA, 2);
  emxInit_int32_T(&allAn, 2);
  emxInit_int32_T(&allS, 2);
  emxInit_int32_T(&allCPO, 2);
  emxInit_int32_T(&allCR, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&b, 2);
  emxInit_int32_T(&idx, 2);
  emxInit_int32_T(&iwork, 1);
  emxInit_real_T(&b_H, 2);
  while (flag) {
    /* 'funcionCPrO:32' auxUPxR = tempUltPosRecXDia; */
    /*  Selecciono los ultimas posiciones a partir de donde se pueden usar las camas. */
    /* 'funcionCPrO:33' [~,C]=find(PCPrO~=0); */
    q = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = PCPrO->size[1];
    emxEnsureCapacity_boolean_T(x, q);
    nb = PCPrO->size[1];
    for (q = 0; q < nb; q++) {
      x->data[q] = (PCPrO->data[q] != 0);
    }

    if (x->size[1] == 0) {
      jj->size[0] = 1;
      jj->size[1] = 0;
    } else {
      b_idx = 0;
      q = jj->size[0] * jj->size[1];
      jj->size[0] = 1;
      jj->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(jj, q);
      yk = 1;
      exitg1 = false;
      while ((!exitg1) && (yk <= x->size[1])) {
        if (x->data[yk - 1]) {
          b_idx++;
          jj->data[b_idx - 1] = yk;
          if (b_idx >= x->size[1]) {
            exitg1 = true;
          } else {
            yk++;
          }
        } else {
          yk++;
        }
      }

      if (x->size[1] == 1) {
        if (b_idx == 0) {
          jj->size[0] = 1;
          jj->size[1] = 0;
        }
      } else {
        q = jj->size[0] * jj->size[1];
        if (1 > b_idx) {
          jj->size[1] = 0;
        } else {
          jj->size[1] = b_idx;
        }

        emxEnsureCapacity_int32_T(jj, q);
      }
    }

    q = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = jj->size[1];
    emxEnsureCapacity_int32_T(C, q);
    nb = jj->size[1];
    for (q = 0; q < nb; q++) {
      C->data[q] = jj->data[q];
    }

    /* 'funcionCPrO:33' ~ */
    /*  Busco las posibles camas a usar. */
    /* 'funcionCPrO:34' minP = Dia(contDia,4)-Dia(contDia,3)+1-(TimeUsoCPrO+TimeUsoS); */
    minP = (((Dia->data[(*contDia + Dia->size[0] * 3) - 1] - Dia->data[(*contDia
               + (Dia->size[0] << 1)) - 1]) - TimeUsoCPrO) - TimeUsoS) + 1;

    /*  Posicion maxima a partir de la cual se puede colocar la Operacion. */
    /* 'funcionCPrO:35' [~,allC]=find(auxUPxR(C)<=minP); */
    q = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = C->size[1];
    emxEnsureCapacity_boolean_T(x, q);
    nb = C->size[1];
    for (q = 0; q < nb; q++) {
      x->data[q] = (tempUltPosRecXDia->data[C->data[q] - 1] <= minP);
    }

    if (x->size[1] == 0) {
      jj->size[0] = 1;
      jj->size[1] = 0;
    } else {
      b_idx = 0;
      q = jj->size[0] * jj->size[1];
      jj->size[0] = 1;
      jj->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(jj, q);
      yk = 1;
      exitg1 = false;
      while ((!exitg1) && (yk <= x->size[1])) {
        if (x->data[yk - 1]) {
          b_idx++;
          jj->data[b_idx - 1] = yk;
          if (b_idx >= x->size[1]) {
            exitg1 = true;
          } else {
            yk++;
          }
        } else {
          yk++;
        }
      }

      if (x->size[1] == 1) {
        if (b_idx == 0) {
          jj->size[0] = 1;
          jj->size[1] = 0;
        }
      } else {
        q = jj->size[0] * jj->size[1];
        if (1 > b_idx) {
          jj->size[1] = 0;
        } else {
          jj->size[1] = b_idx;
        }

        emxEnsureCapacity_int32_T(jj, q);
      }
    }

    q = allC->size[0] * allC->size[1];
    allC->size[0] = 1;
    allC->size[1] = jj->size[1];
    emxEnsureCapacity_int32_T(allC, q);
    nb = jj->size[1];
    for (q = 0; q < nb; q++) {
      allC->data[q] = jj->data[q];
    }

    /* 'funcionCPrO:35' ~ */
    /*  Veo en cuales es posible asignar la operacion. */
    /* 'funcionCPrO:37' if isempty(allC) */
    if (allC->size[1] == 0) {
      /*  Si no es posible asignar ninguna cama incremento el contDia e llamo a funcionDia */
      /* 'funcionCPrO:38' contDia = contDia + 1; */
      (*contDia)++;

      /* 'funcionCPrO:39' [contDia,tempUltPosRecXDia,DispME] = funcionDia(NumRec, PCPrO, Dia,UltPosRecXDia, TimeUsoCPrO, TimeUsoS, contDia, DispMExD); */
      b_funcionDia(NumRec, PCPrO, Dia, UltPosRecXDia, TimeUsoCPrO, TimeUsoS,
                   contDia, DispMExD, tempUltPosRecXDia, DispME);
    } else {
      /* 'funcionCPrO:40' else */
      /* 'funcionCPrO:41' [~,u]=unique(auxUPxR(C(allC))); */
      q = jj->size[0] * jj->size[1];
      jj->size[0] = 1;
      jj->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(jj, q);
      nb = allC->size[1];
      for (q = 0; q < nb; q++) {
        jj->data[q] = tempUltPosRecXDia->data[C->data[allC->data[q] - 1] - 1];
      }

      na = allC->size[1];
      n = allC->size[1] + 1;
      yk = allC->size[1];
      q = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = yk;
      emxEnsureCapacity_int32_T(idx, q);
      for (q = 0; q < yk; q++) {
        idx->data[q] = 0;
      }

      q = iwork->size[0];
      iwork->size[0] = allC->size[1];
      emxEnsureCapacity_int32_T(iwork, q);
      q = allC->size[1] - 1;
      for (k = 1; k <= q; k += 2) {
        if (jj->data[k - 1] <= jj->data[k]) {
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

      yk = 2;
      while (yk < n - 1) {
        b_idx = yk << 1;
        j = 1;
        for (nb = 1 + yk; nb < n; nb = qEnd + yk) {
          p = j;
          q = nb;
          qEnd = j + b_idx;
          if (qEnd > n) {
            qEnd = n;
          }

          k = 0;
          kEnd = qEnd - j;
          while (k + 1 <= kEnd) {
            if (jj->data[idx->data[p - 1] - 1] <= jj->data[idx->data[q - 1] - 1])
            {
              iwork->data[k] = idx->data[p - 1];
              p++;
              if (p == nb) {
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
                while (p < nb) {
                  k++;
                  iwork->data[k] = idx->data[p - 1];
                  p++;
                }
              }
            }

            k++;
          }

          for (k = 0; k < kEnd; k++) {
            idx->data[(j + k) - 1] = iwork->data[k];
          }

          j = qEnd;
        }

        yk = b_idx;
      }

      nm1 = (unsigned int)allC->size[1];
      q = b->size[0] * b->size[1];
      b->size[0] = 1;
      b->size[1] = (int)nm1;
      emxEnsureCapacity_int32_T(b, q);
      for (k = 0; k < na; k++) {
        b->data[k] = jj->data[idx->data[k] - 1];
      }

      nb = -1;
      k = 0;
      while (k + 1 <= na) {
        yk = b->data[k];
        b_idx = k;
        do {
          k++;
        } while (!((k + 1 > na) || (b->data[k] != yk)));

        nb++;
        b->data[nb] = yk;
        idx->data[nb] = idx->data[b_idx];
      }

      q = iwork->size[0];
      iwork->size[0] = nb + 1;
      emxEnsureCapacity_int32_T(iwork, q);
      for (k = 0; k <= nb; k++) {
        iwork->data[k] = idx->data[k];
      }

      q = u->size[0];
      u->size[0] = iwork->size[0];
      emxEnsureCapacity_int32_T(u, q);
      nb = iwork->size[0];
      for (q = 0; q < nb; q++) {
        u->data[q] = iwork->data[q];
      }

      /* 'funcionCPrO:41' ~ */
      /* 'funcionCPrO:42' uCPrODisp=C(allC(u)); */
      q = uCPrODisp->size[0] * uCPrODisp->size[1];
      uCPrODisp->size[0] = 1;
      uCPrODisp->size[1] = u->size[0];
      emxEnsureCapacity_uint32_T(uCPrODisp, q);
      nb = u->size[0];
      for (q = 0; q < nb; q++) {
        uCPrODisp->data[q] = (unsigned int)C->data[allC->data[u->data[q] - 1] -
          1];
      }

      /* 'funcionCPrO:46' auxUPxE = UltPosRecXDia(contDia,NumRec(1)+1:sum(NumRec(1:2))); */
      if (NumRec[0] + 1 > b_tmp) {
        q = 0;
        p = -1;
      } else {
        q = NumRec[0];
        p = b_tmp - 1;
      }

      yk = auxUPxE->size[0] * auxUPxE->size[1];
      auxUPxE->size[0] = 1;
      nb = p - q;
      auxUPxE->size[1] = nb + 1;
      emxEnsureCapacity_real_T(auxUPxE, yk);
      for (p = 0; p <= nb; p++) {
        auxUPxE->data[p] = UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0]
          * (q + p)) - 1];
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los ME. */
      /* 'funcionCPrO:47' auxPME=PME(1:end-1).*DispME; */
      if (1 > PME->size[1] - 1) {
        nb = 0;
      } else {
        nb = PME->size[1] - 1;
      }

      /* 'funcionCPrO:48' [~,allE]=find(auxPME~=0); */
      q = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = nb;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < nb; q++) {
        x->data[q] = (PME->data[q] * DispME->data[q] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[0] = 1;
        jj->size[1] = 0;
      } else {
        b_idx = 0;
        q = jj->size[0] * jj->size[1];
        jj->size[0] = 1;
        jj->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            b_idx++;
            jj->data[b_idx - 1] = yk;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          }
        } else {
          q = jj->size[0] * jj->size[1];
          if (1 > b_idx) {
            jj->size[1] = 0;
          } else {
            jj->size[1] = b_idx;
          }

          emxEnsureCapacity_int32_T(jj, q);
        }
      }

      q = allE->size[0] * allE->size[1];
      allE->size[0] = 1;
      allE->size[1] = jj->size[1];
      emxEnsureCapacity_int32_T(allE, q);
      nb = jj->size[1];
      for (q = 0; q < nb; q++) {
        allE->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:48' ~ */
      /*  Busco los posibles Especialistas a usar. */
      /* 'funcionCPrO:50' auxUPxA = UltPosRecXDia(contDia,sum(NumRec(1:3))+1:sum(NumRec(1:4))); */
      y = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
      ndbl = (((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
        (double)NumRec[3];
      if (y + 1.0 > ndbl) {
        q = 0;
        p = -1;
      } else {
        q = (int)(y + 1.0) - 1;
        p = (int)ndbl - 1;
      }

      yk = auxUPxA->size[0] * auxUPxA->size[1];
      auxUPxA->size[0] = 1;
      nb = p - q;
      auxUPxA->size[1] = nb + 1;
      emxEnsureCapacity_real_T(auxUPxA, yk);
      for (p = 0; p <= nb; p++) {
        auxUPxA->data[p] = UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0]
          * (q + p)) - 1];
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los A. */
      /* 'funcionCPrO:51' [~,allA]=find(PMA(1:end-1)~=0); */
      if (1 > PMA->size[1] - 1) {
        nb = 0;
      } else {
        nb = PMA->size[1] - 1;
      }

      q = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = nb;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < nb; q++) {
        x->data[q] = (PMA->data[q] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[0] = 1;
        jj->size[1] = 0;
      } else {
        b_idx = 0;
        q = jj->size[0] * jj->size[1];
        jj->size[0] = 1;
        jj->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            b_idx++;
            jj->data[b_idx - 1] = yk;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          }
        } else {
          q = jj->size[0] * jj->size[1];
          if (1 > b_idx) {
            jj->size[1] = 0;
          } else {
            jj->size[1] = b_idx;
          }

          emxEnsureCapacity_int32_T(jj, q);
        }
      }

      q = allA->size[0] * allA->size[1];
      allA->size[0] = 1;
      allA->size[1] = jj->size[1];
      emxEnsureCapacity_int32_T(allA, q);
      nb = jj->size[1];
      for (q = 0; q < nb; q++) {
        allA->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:51' ~ */
      /*  Busco los posibles Asistentes a usar. */
      /* 'funcionCPrO:53' auxUPxAn = UltPosRecXDia(contDia,sum(NumRec(1:4))+1:sum(NumRec(1:5))); */
      y = (((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
        (double)NumRec[3];
      ndbl = ((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
              (double)NumRec[3]) + (double)NumRec[4];
      if (y + 1.0 > ndbl) {
        q = 0;
        p = -1;
      } else {
        q = (int)(y + 1.0) - 1;
        p = (int)ndbl - 1;
      }

      yk = auxUPxAn->size[0] * auxUPxAn->size[1];
      auxUPxAn->size[0] = 1;
      nb = p - q;
      auxUPxAn->size[1] = nb + 1;
      emxEnsureCapacity_real_T(auxUPxAn, yk);
      for (p = 0; p <= nb; p++) {
        auxUPxAn->data[p] = UltPosRecXDia->data[(*contDia + UltPosRecXDia->size
          [0] * (q + p)) - 1];
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los An. */
      /* 'funcionCPrO:54' [~,allAn]=find(PMAn(1:end-1)~=0); */
      if (1 > PMAn->size[1] - 1) {
        nb = 0;
      } else {
        nb = PMAn->size[1] - 1;
      }

      q = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = nb;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < nb; q++) {
        x->data[q] = (PMAn->data[q] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[0] = 1;
        jj->size[1] = 0;
      } else {
        b_idx = 0;
        q = jj->size[0] * jj->size[1];
        jj->size[0] = 1;
        jj->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            b_idx++;
            jj->data[b_idx - 1] = yk;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          }
        } else {
          q = jj->size[0] * jj->size[1];
          if (1 > b_idx) {
            jj->size[1] = 0;
          } else {
            jj->size[1] = b_idx;
          }

          emxEnsureCapacity_int32_T(jj, q);
        }
      }

      q = allAn->size[0] * allAn->size[1];
      allAn->size[0] = 1;
      allAn->size[1] = jj->size[1];
      emxEnsureCapacity_int32_T(allAn, q);
      nb = jj->size[1];
      for (q = 0; q < nb; q++) {
        allAn->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:54' ~ */
      /*  Busco los posibles Anestesistas a usar. */
      /* 'funcionCPrO:56' auxUPxS = UltPosRecXDia(contDia,sum(NumRec(1:2))+1:sum(NumRec(1:3))); */
      y = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
      if (y_tmp + 1.0 > y) {
        q = 0;
        p = -1;
      } else {
        q = (int)(y_tmp + 1.0) - 1;
        p = (int)y - 1;
      }

      yk = auxUPxS->size[0] * auxUPxS->size[1];
      auxUPxS->size[0] = 1;
      nb = p - q;
      auxUPxS->size[1] = nb + 1;
      emxEnsureCapacity_real_T(auxUPxS, yk);
      for (p = 0; p <= nb; p++) {
        auxUPxS->data[p] = UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0]
          * (q + p)) - 1];
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
      /* 'funcionCPrO:57' [~,allS]=find(PS(1:end)~=0); */
      if (1 > PS->size[1]) {
        nb = 0;
      } else {
        nb = PS->size[1];
      }

      q = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = nb;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < nb; q++) {
        x->data[q] = (PS->data[q] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[0] = 1;
        jj->size[1] = 0;
      } else {
        b_idx = 0;
        q = jj->size[0] * jj->size[1];
        jj->size[0] = 1;
        jj->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            b_idx++;
            jj->data[b_idx - 1] = yk;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          }
        } else {
          q = jj->size[0] * jj->size[1];
          if (1 > b_idx) {
            jj->size[1] = 0;
          } else {
            jj->size[1] = b_idx;
          }

          emxEnsureCapacity_int32_T(jj, q);
        }
      }

      q = allS->size[0] * allS->size[1];
      allS->size[0] = 1;
      allS->size[1] = jj->size[1];
      emxEnsureCapacity_int32_T(allS, q);
      nb = jj->size[1];
      for (q = 0; q < nb; q++) {
        allS->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:57' ~ */
      /*  Busco los posibles Salones a usar. */
      /* auxUPxCPO = UltPosRecXDia(contDia,NumRec(1:5)+1:sum(NumRec(1:6)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los ME. */
      /* 'funcionCPrO:60' [~,allCPO]=find(PCPO(1:end)~=0); */
      if (1 > PCPO->size[1]) {
        nb = 0;
      } else {
        nb = PCPO->size[1];
      }

      q = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = nb;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < nb; q++) {
        x->data[q] = (PCPO->data[q] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[0] = 1;
        jj->size[1] = 0;
      } else {
        b_idx = 0;
        q = jj->size[0] * jj->size[1];
        jj->size[0] = 1;
        jj->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            b_idx++;
            jj->data[b_idx - 1] = yk;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          }
        } else {
          q = jj->size[0] * jj->size[1];
          if (1 > b_idx) {
            jj->size[1] = 0;
          } else {
            jj->size[1] = b_idx;
          }

          emxEnsureCapacity_int32_T(jj, q);
        }
      }

      q = allCPO->size[0] * allCPO->size[1];
      allCPO->size[0] = 1;
      allCPO->size[1] = jj->size[1];
      emxEnsureCapacity_int32_T(allCPO, q);
      nb = jj->size[1];
      for (q = 0; q < nb; q++) {
        allCPO->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:60' ~ */
      /*  Busco los posibles Especialistas a usar. */
      /* auxUPxCR = UltPosRecXDia(contDia,sum(NumRec(1:6))+1:sum(NumRec(1:7)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
      /* 'funcionCPrO:63' [~,allCR]=find(PCR(1:end)~=0); */
      if (1 > PCR->size[1]) {
        nb = 0;
      } else {
        nb = PCR->size[1];
      }

      q = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = nb;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < nb; q++) {
        x->data[q] = (PCR->data[q] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[0] = 1;
        jj->size[1] = 0;
      } else {
        b_idx = 0;
        q = jj->size[0] * jj->size[1];
        jj->size[0] = 1;
        jj->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            b_idx++;
            jj->data[b_idx - 1] = yk;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          }
        } else {
          q = jj->size[0] * jj->size[1];
          if (1 > b_idx) {
            jj->size[1] = 0;
          } else {
            jj->size[1] = b_idx;
          }

          emxEnsureCapacity_int32_T(jj, q);
        }
      }

      q = allCR->size[0] * allCR->size[1];
      allCR->size[0] = 1;
      allCR->size[1] = jj->size[1];
      emxEnsureCapacity_int32_T(allCR, q);
      nb = jj->size[1];
      for (q = 0; q < nb; q++) {
        allCR->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:63' ~ */
      /*  Busco los posibles Salones a usar. */
      /* 'funcionCPrO:64' temCPrO=-1; */
      temCPrO = -1;

      /* 'funcionCPrO:66' for j=1:length(uCPrODisp) */
      j = 0;
      do {
        exitg2 = 0;
        yk = u->size[0];
        if (j <= yk - 1) {
          /* 'funcionCPrO:68' EndCPrOAxD = auxUPxR(uCPrODisp(j))+TimeUsoCPrO; */
          b_EndCPrOAxD = tempUltPosRecXDia->data[(int)uCPrODisp->data[j] - 1] +
            TimeUsoCPrO;

          /* 'funcionCPrO:69' EndRPxD = EndCPrOAxD+TimeUsoS; */
          b_EndRPxD = b_EndCPrOAxD + TimeUsoS;

          /* 'funcionCPrO:71' [~,E]=find(auxUPxE(allE)<=EndCPrOAxD); */
          q = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = allE->size[1];
          emxEnsureCapacity_boolean_T(x, q);
          nb = allE->size[1];
          for (q = 0; q < nb; q++) {
            x->data[q] = (auxUPxE->data[allE->data[q] - 1] <= b_EndCPrOAxD);
          }

          if (x->size[1] == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          } else {
            b_idx = 0;
            q = jj->size[0] * jj->size[1];
            jj->size[0] = 1;
            jj->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(jj, q);
            yk = 1;
            exitg1 = false;
            while ((!exitg1) && (yk <= x->size[1])) {
              if (x->data[yk - 1]) {
                b_idx++;
                jj->data[b_idx - 1] = yk;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  yk++;
                }
              } else {
                yk++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                jj->size[0] = 1;
                jj->size[1] = 0;
              }
            } else {
              q = jj->size[0] * jj->size[1];
              if (1 > b_idx) {
                jj->size[1] = 0;
              } else {
                jj->size[1] = b_idx;
              }

              emxEnsureCapacity_int32_T(jj, q);
            }
          }

          q = E->size[0] * E->size[1];
          E->size[0] = 1;
          E->size[1] = jj->size[1];
          emxEnsureCapacity_int32_T(E, q);
          nb = jj->size[1];
          for (q = 0; q < nb; q++) {
            E->data[q] = jj->data[q];
          }

          /* 'funcionCPrO:71' ~ */
          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
          /* 'funcionCPrO:72' [~,A]=find(auxUPxA(allA)<=EndCPrOAxD); */
          q = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = allA->size[1];
          emxEnsureCapacity_boolean_T(x, q);
          nb = allA->size[1];
          for (q = 0; q < nb; q++) {
            x->data[q] = (auxUPxA->data[allA->data[q] - 1] <= b_EndCPrOAxD);
          }

          if (x->size[1] == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          } else {
            b_idx = 0;
            q = jj->size[0] * jj->size[1];
            jj->size[0] = 1;
            jj->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(jj, q);
            yk = 1;
            exitg1 = false;
            while ((!exitg1) && (yk <= x->size[1])) {
              if (x->data[yk - 1]) {
                b_idx++;
                jj->data[b_idx - 1] = yk;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  yk++;
                }
              } else {
                yk++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                jj->size[0] = 1;
                jj->size[1] = 0;
              }
            } else {
              q = jj->size[0] * jj->size[1];
              if (1 > b_idx) {
                jj->size[1] = 0;
              } else {
                jj->size[1] = b_idx;
              }

              emxEnsureCapacity_int32_T(jj, q);
            }
          }

          q = A->size[0] * A->size[1];
          A->size[0] = 1;
          A->size[1] = jj->size[1];
          emxEnsureCapacity_int32_T(A, q);
          nb = jj->size[1];
          for (q = 0; q < nb; q++) {
            A->data[q] = jj->data[q];
          }

          /* 'funcionCPrO:72' ~ */
          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
          /* 'funcionCPrO:73' [~,An]=find(auxUPxAn(allAn)<=EndCPrOAxD); */
          q = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = allAn->size[1];
          emxEnsureCapacity_boolean_T(x, q);
          nb = allAn->size[1];
          for (q = 0; q < nb; q++) {
            x->data[q] = (auxUPxAn->data[allAn->data[q] - 1] <= b_EndCPrOAxD);
          }

          if (x->size[1] == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          } else {
            b_idx = 0;
            q = jj->size[0] * jj->size[1];
            jj->size[0] = 1;
            jj->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(jj, q);
            yk = 1;
            exitg1 = false;
            while ((!exitg1) && (yk <= x->size[1])) {
              if (x->data[yk - 1]) {
                b_idx++;
                jj->data[b_idx - 1] = yk;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  yk++;
                }
              } else {
                yk++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                jj->size[0] = 1;
                jj->size[1] = 0;
              }
            } else {
              q = jj->size[0] * jj->size[1];
              if (1 > b_idx) {
                jj->size[1] = 0;
              } else {
                jj->size[1] = b_idx;
              }

              emxEnsureCapacity_int32_T(jj, q);
            }
          }

          q = An->size[0] * An->size[1];
          An->size[0] = 1;
          An->size[1] = jj->size[1];
          emxEnsureCapacity_int32_T(An, q);
          nb = jj->size[1];
          for (q = 0; q < nb; q++) {
            An->data[q] = jj->data[q];
          }

          /* 'funcionCPrO:73' ~ */
          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
          /* 'funcionCPrO:74' [~,S]=find(auxUPxS(allS)<=EndCPrOAxD); */
          q = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = allS->size[1];
          emxEnsureCapacity_boolean_T(x, q);
          nb = allS->size[1];
          for (q = 0; q < nb; q++) {
            x->data[q] = (auxUPxS->data[allS->data[q] - 1] <= b_EndCPrOAxD);
          }

          if (x->size[1] == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          } else {
            b_idx = 0;
            q = jj->size[0] * jj->size[1];
            jj->size[0] = 1;
            jj->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(jj, q);
            yk = 1;
            exitg1 = false;
            while ((!exitg1) && (yk <= x->size[1])) {
              if (x->data[yk - 1]) {
                b_idx++;
                jj->data[b_idx - 1] = yk;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  yk++;
                }
              } else {
                yk++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                jj->size[0] = 1;
                jj->size[1] = 0;
              }
            } else {
              q = jj->size[0] * jj->size[1];
              if (1 > b_idx) {
                jj->size[1] = 0;
              } else {
                jj->size[1] = b_idx;
              }

              emxEnsureCapacity_int32_T(jj, q);
            }
          }

          q = S->size[0] * S->size[1];
          S->size[0] = 1;
          S->size[1] = jj->size[1];
          emxEnsureCapacity_int32_T(S, q);
          nb = jj->size[1];
          for (q = 0; q < nb; q++) {
            S->data[q] = jj->data[q];
          }

          /* 'funcionCPrO:74' ~ */
          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo.         */
          /* 'funcionCPrO:76' if TimeUsoCPO == 0 */
          if (TimeUsoCPO == 0) {
            /* 'funcionCPrO:77' CPO=0; */
            q = CPO->size[0] * CPO->size[1];
            CPO->size[0] = 1;
            CPO->size[1] = 1;
            emxEnsureCapacity_int32_T(CPO, q);
            CPO->data[0] = 0;

            /* 'funcionCPrO:78' IniCR=Dia(contDia,3)+EndCPrOAxD+TimeUsoS; */
            IniCR = ((Dia->data[(*contDia + (Dia->size[0] << 1)) - 1] +
                      b_EndCPrOAxD) + TimeUsoS) - 1;

            /* 'funcionCPrO:79' [~,CR]=find(sum(H(IniCR:IniCR+TimeUsoCR-1,sum(NumRec(1:6))+allCR))==0); */
            q = IniCR + TimeUsoCR;
            if (IniCR + 1 > q) {
              p = 0;
              q = 0;
            } else {
              p = IniCR;
            }

            y = NumRec[0];
            for (k = 0; k < 5; k++) {
              y += (double)NumRec[k + 1];
            }

            yk = b_H->size[0] * b_H->size[1];
            nb = q - p;
            b_H->size[0] = nb;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_real_T(b_H, yk);
            b_idx = allCR->size[1];
            for (q = 0; q < b_idx; q++) {
              for (yk = 0; yk < nb; yk++) {
                b_H->data[yk + b_H->size[0] * q] = H->data[(p + yk) + H->size[0]
                  * ((int)(y + (double)allCR->data[q]) - 1)];
              }
            }

            f_sum(b_H, r17);
            q = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r17->size[1];
            emxEnsureCapacity_boolean_T(x, q);
            nb = r17->size[1];
            for (q = 0; q < nb; q++) {
              x->data[q] = (r17->data[q] == 0.0);
            }

            if (x->size[1] == 0) {
              jj->size[0] = 1;
              jj->size[1] = 0;
            } else {
              b_idx = 0;
              q = jj->size[0] * jj->size[1];
              jj->size[0] = 1;
              jj->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(jj, q);
              yk = 1;
              exitg1 = false;
              while ((!exitg1) && (yk <= x->size[1])) {
                if (x->data[yk - 1]) {
                  b_idx++;
                  jj->data[b_idx - 1] = yk;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    yk++;
                  }
                } else {
                  yk++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  jj->size[0] = 1;
                  jj->size[1] = 0;
                }
              } else {
                q = jj->size[0] * jj->size[1];
                if (1 > b_idx) {
                  jj->size[1] = 0;
                } else {
                  jj->size[1] = b_idx;
                }

                emxEnsureCapacity_int32_T(jj, q);
              }
            }

            q = CR->size[0] * CR->size[1];
            CR->size[0] = 1;
            CR->size[1] = jj->size[1];
            emxEnsureCapacity_int32_T(CR, q);
            nb = jj->size[1];
            for (q = 0; q < nb; q++) {
              CR->data[q] = jj->data[q];
            }

            /* 'funcionCPrO:79' ~ */
          } else {
            /* 'funcionCPrO:80' else */
            /* 'funcionCPrO:81' IniCPO=Dia(contDia,3)+EndCPrOAxD+TimeUsoS; */
            IniCPO = ((Dia->data[(*contDia + (Dia->size[0] << 1)) - 1] +
                       b_EndCPrOAxD) + TimeUsoS) - 1;

            /* 'funcionCPrO:82' EndCPO=IniCPO+TimeUsoCPO-1; */
            EndCPO = (IniCPO + TimeUsoCPO) - 1;

            /* 'funcionCPrO:83' [~,CPO]=find(sum(H(IniCPO:EndCPO,sum(NumRec(1:5))+allCPO))==0); */
            if (IniCPO + 1 > EndCPO + 1) {
              q = 0;
              p = -1;
            } else {
              q = IniCPO;
              p = EndCPO;
            }

            y = ((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
                 (double)NumRec[3]) + (double)NumRec[4];
            yk = b_H->size[0] * b_H->size[1];
            nb = p - q;
            b_H->size[0] = nb + 1;
            b_H->size[1] = allCPO->size[1];
            emxEnsureCapacity_real_T(b_H, yk);
            b_idx = allCPO->size[1];
            for (p = 0; p < b_idx; p++) {
              for (yk = 0; yk <= nb; yk++) {
                b_H->data[yk + b_H->size[0] * p] = H->data[(q + yk) + H->size[0]
                  * ((int)(y + (double)allCPO->data[p]) - 1)];
              }
            }

            f_sum(b_H, r17);
            q = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r17->size[1];
            emxEnsureCapacity_boolean_T(x, q);
            nb = r17->size[1];
            for (q = 0; q < nb; q++) {
              x->data[q] = (r17->data[q] == 0.0);
            }

            if (x->size[1] == 0) {
              jj->size[0] = 1;
              jj->size[1] = 0;
            } else {
              b_idx = 0;
              q = jj->size[0] * jj->size[1];
              jj->size[0] = 1;
              jj->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(jj, q);
              yk = 1;
              exitg1 = false;
              while ((!exitg1) && (yk <= x->size[1])) {
                if (x->data[yk - 1]) {
                  b_idx++;
                  jj->data[b_idx - 1] = yk;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    yk++;
                  }
                } else {
                  yk++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  jj->size[0] = 1;
                  jj->size[1] = 0;
                }
              } else {
                q = jj->size[0] * jj->size[1];
                if (1 > b_idx) {
                  jj->size[1] = 0;
                } else {
                  jj->size[1] = b_idx;
                }

                emxEnsureCapacity_int32_T(jj, q);
              }
            }

            q = CPO->size[0] * CPO->size[1];
            CPO->size[0] = 1;
            CPO->size[1] = jj->size[1];
            emxEnsureCapacity_int32_T(CPO, q);
            nb = jj->size[1];
            for (q = 0; q < nb; q++) {
              CPO->data[q] = jj->data[q];
            }

            /* 'funcionCPrO:83' ~ */
            /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
            /* 'funcionCPrO:84' [~,CR]=find(~sum(H(EndCPO+1:EndCPO+TimeUsoCR,sum(NumRec(1:6))+allCR))); */
            y = NumRec[0];
            for (k = 0; k < 5; k++) {
              y += (double)NumRec[k + 1];
            }

            q = b_H->size[0] * b_H->size[1];
            b_H->size[0] = TimeUsoCR;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_real_T(b_H, q);
            nb = allCR->size[1];
            for (q = 0; q < nb; q++) {
              for (p = 0; p < TimeUsoCR; p++) {
                b_H->data[p + b_H->size[0] * q] = H->data[((p + EndCPO) +
                  H->size[0] * ((int)(y + (double)allCR->data[q]) - 1)) + 1];
              }
            }

            f_sum(b_H, r17);
            q = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r17->size[1];
            emxEnsureCapacity_boolean_T(x, q);
            nb = r17->size[1];
            for (q = 0; q < nb; q++) {
              x->data[q] = (r17->data[q] == 0.0);
            }

            if (x->size[1] == 0) {
              jj->size[0] = 1;
              jj->size[1] = 0;
            } else {
              b_idx = 0;
              q = jj->size[0] * jj->size[1];
              jj->size[0] = 1;
              jj->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(jj, q);
              yk = 1;
              exitg1 = false;
              while ((!exitg1) && (yk <= x->size[1])) {
                if (x->data[yk - 1]) {
                  b_idx++;
                  jj->data[b_idx - 1] = yk;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    yk++;
                  }
                } else {
                  yk++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  jj->size[0] = 1;
                  jj->size[1] = 0;
                }
              } else {
                q = jj->size[0] * jj->size[1];
                if (1 > b_idx) {
                  jj->size[1] = 0;
                } else {
                  jj->size[1] = b_idx;
                }

                emxEnsureCapacity_int32_T(jj, q);
              }
            }

            q = CR->size[0] * CR->size[1];
            CR->size[0] = 1;
            CR->size[1] = jj->size[1];
            emxEnsureCapacity_int32_T(CR, q);
            nb = jj->size[1];
            for (q = 0; q < nb; q++) {
              CR->data[q] = jj->data[q];
            }

            /* 'funcionCPrO:84' ~ */
          }

          /* 'funcionCPrO:88' if ~isempty(CPO)&&~isempty(CR)&&~isempty(S)&&size(E,2)>=PME(end)&&size(A,2)>=PMA(end)&&size(An,2)>=PMAn(end) */
          if ((CPO->size[1] != 0) && (CR->size[1] != 0) && (S->size[1] != 0) &&
              (E->size[1] >= PME->data[PME->size[1] - 1]) && (A->size[1] >=
               PMA->data[PMA->size[1] - 1]) && (An->size[1] >= PMAn->data
               [PMAn->size[1] - 1])) {
            /* 'funcionCPrO:89' temCPrO = uCPrODisp(j); */
            temCPrO = (int)uCPrODisp->data[j];
            exitg2 = 1;
          } else {
            j++;
          }
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      /* 'funcionCPrO:95' if temCPrO == -1 */
      if (temCPrO == -1) {
        /* 'funcionCPrO:97' tempUltPosRecXDia = tempUltPosRecXDia+1; */
        q = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        tempUltPosRecXDia->size[0] = 1;
        emxEnsureCapacity_int32_T(tempUltPosRecXDia, q);
        nb = tempUltPosRecXDia->size[1];
        for (q = 0; q < nb; q++) {
          tempUltPosRecXDia->data[q]++;
        }
      } else {
        /* 'funcionCPrO:99' else */
        /* 'funcionCPrO:101' CPrOA = int32(temCPrO); */
        b_CPrOA = temCPrO;

        /* 'funcionCPrO:102' IniCPrOA = Dia(contDia,3)+int32(auxUPxR(CPrOA)); */
        b_IniCPrOA = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1] +
          tempUltPosRecXDia->data[temCPrO - 1];

        /* 'funcionCPrO:103' EndCPrOA = IniCPrOA + TimeUsoCPrO-1; */
        b_EndCPrOA = b_IniCPrOA + TimeUsoCPrO;

        /* 'funcionCPrO:105' SA_double = allS(S(1)); */
        q = SA_double->size[0] * SA_double->size[1];
        SA_double->size[0] = 1;
        SA_double->size[1] = 1;
        emxEnsureCapacity_int32_T(SA_double, q);
        SA_double->data[0] = allS->data[S->data[0] - 1];

        /* 'funcionCPrO:106' IniSA = EndCPrOA+1; */
        b_IniSA = b_EndCPrOA;

        /* 'funcionCPrO:107' EndSA = IniSA+TimeUsoS-1; */
        b_EndSA = (b_EndCPrOA + TimeUsoS) - 1;

        /* 'funcionCPrO:109' EA_double = allE(E(1:PME(end))); */
        if (1 > PME->data[PME->size[1] - 1]) {
          nb = 0;
        } else {
          nb = PME->data[PME->size[1] - 1];
        }

        q = EA_double->size[0] * EA_double->size[1];
        EA_double->size[0] = 1;
        EA_double->size[1] = nb;
        emxEnsureCapacity_int32_T(EA_double, q);
        for (q = 0; q < nb; q++) {
          EA_double->data[q] = allE->data[E->data[q] - 1];
        }

        /* 'funcionCPrO:111' AA_double = allA(A(1:PMA(end))); */
        if (1 > PMA->data[PMA->size[1] - 1]) {
          nb = 0;
        } else {
          nb = PMA->data[PMA->size[1] - 1];
        }

        q = AA_double->size[0] * AA_double->size[1];
        AA_double->size[0] = 1;
        AA_double->size[1] = nb;
        emxEnsureCapacity_int32_T(AA_double, q);
        for (q = 0; q < nb; q++) {
          AA_double->data[q] = allA->data[A->data[q] - 1];
        }

        /* 'funcionCPrO:113' AnA_double = allAn(An(1:PMAn(end))); */
        if (1 > PMAn->data[PMAn->size[1] - 1]) {
          nb = 0;
        } else {
          nb = PMAn->data[PMAn->size[1] - 1];
        }

        q = AnA_double->size[0] * AnA_double->size[1];
        AnA_double->size[0] = 1;
        AnA_double->size[1] = nb;
        emxEnsureCapacity_int32_T(AnA_double, q);
        for (q = 0; q < nb; q++) {
          AnA_double->data[q] = allAn->data[An->data[q] - 1];
        }

        /* 'funcionCPrO:115' if TimeUsoCPO==0 */
        if (TimeUsoCPO == 0) {
          /* 'funcionCPrO:116' CPOA = int32(0); */
          b_CPOA = 0;

          /* 'funcionCPrO:117' IniCPOA = int32(0); */
          b_IniCPOA = -1;

          /* 'funcionCPrO:118' EndCPOA = int32(0); */
          b_EndCPOA = 0;

          /* 'funcionCPrO:120' CRA = int32(allCR(CR(1))); */
          b_CRA = allCR->data[CR->data[0] - 1];

          /* 'funcionCPrO:121' IniCRA = EndSA+1; */
          b_IniCRA = b_EndSA;

          /* 'funcionCPrO:122' EndCRA = IniCRA + TimeUsoCR-1; */
          b_EndCRA = b_EndSA + TimeUsoCR;
        } else {
          /* 'funcionCPrO:123' else */
          /* 'funcionCPrO:124' CPOA = int32(allCPO(CPO(1))); */
          b_CPOA = allCPO->data[CPO->data[0] - 1];

          /* 'funcionCPrO:125' IniCPOA = EndSA+1; */
          b_IniCPOA = b_EndSA;

          /* 'funcionCPrO:126' EndCPOA = IniCPOA + TimeUsoCPO-1; */
          b_EndCPOA = b_EndSA + TimeUsoCPO;

          /* 'funcionCPrO:128' CRA = int32(allCR(CR(1))); */
          b_CRA = allCR->data[CR->data[0] - 1];

          /* 'funcionCPrO:129' IniCRA = EndCPOA+1; */
          b_IniCRA = b_EndCPOA;

          /* 'funcionCPrO:130' EndCRA = IniCRA + TimeUsoCR-1; */
          b_EndCRA = b_EndCPOA + TimeUsoCR;
        }

        /* 'funcionCPrO:133' flag = false; */
        flag = false;
      }
    }
  }

  emxFree_real_T(&b_H);
  emxFree_int32_T(&iwork);
  emxFree_int32_T(&idx);
  emxFree_int32_T(&b);
  emxFree_int32_T(&jj);
  emxFree_boolean_T(&x);
  emxFree_real_T(&r17);
  emxFree_int32_T(&allCR);
  emxFree_int32_T(&allCPO);
  emxFree_int32_T(&allS);
  emxFree_int32_T(&allAn);
  emxFree_int32_T(&allA);
  emxFree_int32_T(&allE);
  emxFree_int32_T(&u);
  emxFree_int32_T(&allC);
  emxFree_int32_T(&C);
  emxFree_real_T(&auxUPxS);
  emxFree_real_T(&auxUPxAn);
  emxFree_real_T(&auxUPxA);
  emxFree_real_T(&auxUPxE);
  emxFree_uint32_T(&uCPrODisp);
  emxFree_int32_T(&CR);
  emxFree_int32_T(&CPO);
  emxFree_int32_T(&An);
  emxFree_int32_T(&A);
  emxFree_int32_T(&S);
  emxFree_int32_T(&E);

  /* 'funcionCPrO:140' EA = int32(EA_double); */
  q = EA->size[0] * EA->size[1];
  EA->size[0] = 1;
  EA->size[1] = EA_double->size[1];
  emxEnsureCapacity_int32_T(EA, q);
  nb = EA_double->size[1];
  for (q = 0; q < nb; q++) {
    EA->data[q] = EA_double->data[q];
  }

  emxFree_int32_T(&EA_double);

  /* 'funcionCPrO:141' AA = int32(AA_double); */
  q = AA->size[0] * AA->size[1];
  AA->size[0] = 1;
  AA->size[1] = AA_double->size[1];
  emxEnsureCapacity_int32_T(AA, q);
  nb = AA_double->size[1];
  for (q = 0; q < nb; q++) {
    AA->data[q] = AA_double->data[q];
  }

  emxFree_int32_T(&AA_double);

  /* 'funcionCPrO:142' AnA = int32(AnA_double); */
  q = AnA->size[0] * AnA->size[1];
  AnA->size[0] = 1;
  AnA->size[1] = AnA_double->size[1];
  emxEnsureCapacity_int32_T(AnA, q);
  nb = AnA_double->size[1];
  for (q = 0; q < nb; q++) {
    AnA->data[q] = AnA_double->data[q];
  }

  emxFree_int32_T(&AnA_double);

  /* 'funcionCPrO:143' SA = int32(SA_double); */
  q = SA->size[0] * SA->size[1];
  SA->size[0] = 1;
  SA->size[1] = SA_double->size[1];
  emxEnsureCapacity_int32_T(SA, q);
  nb = SA_double->size[1];
  for (q = 0; q < nb; q++) {
    SA->data[q] = SA_double->data[q];
  }

  emxFree_int32_T(&SA_double);
  *CPrOA = b_CPrOA;
  *IniCPrOA = b_IniCPrOA;
  *EndCPrOA = b_EndCPrOA - 1;
  *EndCPrOAxD = b_EndCPrOAxD;
  *IniSA = b_IniSA;
  *EndSA = b_EndSA;
  *EndRPxD = b_EndRPxD;
  *CPOA = b_CPOA;
  *IniCPOA = b_IniCPOA + 1;
  *EndCPOA = b_EndCPOA;
  *CRA = b_CRA;
  *IniCRA = b_IniCRA + 1;
  *EndCRA = b_EndCRA;
}

/*
 * function [ CPrOA,IniCPrOA, EndCPrOA,EndCPrOAxD,EA,AA,AnA,SA,IniSA,EndSA,EndRPxD,CPOA,IniCPOA,EndCPOA,CRA,IniCRA,EndCRA,contDia] = ...
 *     funcionCPrO(NumRec, PCPrO,PME,PMA,PMAn,PS,PCPO,PCR,H,Dia,UltPosRecXDia, TimeUsoCPrO, TimeUsoS,TimeUsoCPO,TimeUsoCR,contDia,...
 *     tempUltPosRecXDia,DispMExD,DispME)
 */
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
  int b_tmp;
  int n;
  unsigned int nm1;
  emxArray_int32_T *jj;
  int q;
  emxArray_int32_T *E;
  int yk;
  int k;
  int nb;
  double y_tmp;
  double y;
  emxArray_real_T *r13;
  double ndbl;
  double apnd;
  double cdiff;
  emxArray_int32_T *S;
  emxArray_real_T *r14;
  emxArray_int32_T *A;
  emxArray_real_T *r15;
  emxArray_int32_T *An;
  emxArray_int32_T *CPO;
  emxArray_int32_T *CR;
  int b_CPrOA;
  int b_CPOA;
  int b_CRA;
  int b_IniCPrOA;
  int b_EndCPrOA;
  int b_IniSA;
  int b_EndSA;
  int b_IniCPOA;
  int b_EndCPOA;
  int b_IniCRA;
  int b_EndCRA;
  int b_EndCPrOAxD;
  int b_EndRPxD;
  emxArray_int32_T *EA_double;
  emxArray_int32_T *AA_double;
  emxArray_int32_T *AnA_double;
  emxArray_int32_T *SA_double;
  boolean_T flag;
  emxArray_uint32_T *uCPrODisp;
  emxArray_int32_T *auxUPxE;
  emxArray_int32_T *auxUPxA;
  emxArray_int32_T *auxUPxAn;
  emxArray_int32_T *auxUPxS;
  emxArray_int32_T *C;
  emxArray_int32_T *allC;
  emxArray_int32_T *u;
  emxArray_int32_T *allE;
  emxArray_int32_T *allA;
  emxArray_int32_T *allAn;
  emxArray_int32_T *allS;
  emxArray_int32_T *allCPO;
  emxArray_int32_T *allCR;
  emxArray_boolean_T *x;
  emxArray_int32_T *b;
  emxArray_int32_T *idx;
  emxArray_int32_T *iwork;
  emxArray_int32_T *b_H;
  int b_idx;
  boolean_T exitg1;
  int minP;
  int na;
  int j;
  int p;
  int qEnd;
  int kEnd;
  int temCPrO;
  int exitg2;
  int IniCPO;
  int EndCPO;
  int IniCR;

  /* 'funcionCPrO:5' E = 1:size(NumRec(1)+1:sum(NumRec(1:2)),2); */
  b_tmp = NumRec[0] + NumRec[1];
  if (b_tmp < NumRec[0] + 1) {
    n = 0;
  } else {
    if ((NumRec[0] + 1 < 0) && (b_tmp >= 0)) {
      nm1 = ((unsigned int)b_tmp - NumRec[0]) - 1U;
    } else {
      nm1 = (unsigned int)((b_tmp - NumRec[0]) - 1);
    }

    n = (int)nm1 + 1;
  }

  emxInit_int32_T(&jj, 2);
  q = jj->size[0] * jj->size[1];
  jj->size[0] = 1;
  jj->size[1] = n;
  emxEnsureCapacity_int32_T(jj, q);
  if (n > 0) {
    jj->data[0] = NumRec[0] + 1;
    yk = NumRec[0] + 1;
    for (k = 2; k <= n; k++) {
      yk++;
      jj->data[k - 1] = yk;
    }
  }

  emxInit_int32_T(&E, 2);
  if (jj->size[1] < 1) {
    E->size[0] = 1;
    E->size[1] = 0;
  } else {
    nb = jj->size[1];
    q = E->size[0] * E->size[1];
    E->size[0] = 1;
    E->size[1] = nb;
    emxEnsureCapacity_int32_T(E, q);
    for (q = 0; q < nb; q++) {
      E->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:6' S = 1:size(sum(NumRec(1:2))+1:sum(NumRec(1:3)),2); */
  y_tmp = (double)NumRec[0] + (double)NumRec[1];
  y = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
  emxInit_real_T(&r13, 2);
  if (y < y_tmp + 1.0) {
    q = r13->size[0] * r13->size[1];
    r13->size[1] = 0;
    emxEnsureCapacity_real_T(r13, q);
  } else if (((double)NumRec[0] + (double)NumRec[1]) + 1.0 == y_tmp + 1.0) {
    q = r13->size[0] * r13->size[1];
    r13->size[1] = (int)(y - (y_tmp + 1.0)) + 1;
    emxEnsureCapacity_real_T(r13, q);
  } else {
    ndbl = floor((y - (y_tmp + 1.0)) + 0.5);
    apnd = (y_tmp + 1.0) + ndbl;
    cdiff = apnd - y;
    if (fabs(cdiff) < 4.4408920985006262E-16 * fmax((unsigned int)fabs(y_tmp +
          1.0), fabs(y))) {
      ndbl++;
      apnd = y;
    } else if (cdiff > 0.0) {
      apnd = (y_tmp + 1.0) + (ndbl - 1.0);
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }

    q = r13->size[0] * r13->size[1];
    r13->size[0] = 1;
    r13->size[1] = n;
    emxEnsureCapacity_real_T(r13, q);
    if ((n > 0) && (n > 1)) {
      r13->data[n - 1] = apnd;
      yk = (n - 1) / 2;
      for (k = 0; k <= yk - 2; k++) {
        r13->data[1 + k] = (y_tmp + 1.0) + (1.0 + (double)k);
        r13->data[(n - k) - 2] = apnd - (1.0 + (double)k);
      }

      if (yk << 1 == n - 1) {
        r13->data[yk] = ((y_tmp + 1.0) + apnd) / 2.0;
      } else {
        r13->data[yk] = (y_tmp + 1.0) + (double)yk;
        r13->data[yk + 1] = apnd - (double)yk;
      }
    }
  }

  emxInit_int32_T(&S, 2);
  if (r13->size[1] < 1) {
    S->size[0] = 1;
    S->size[1] = 0;
  } else {
    nb = r13->size[1];
    q = S->size[0] * S->size[1];
    S->size[0] = 1;
    S->size[1] = nb;
    emxEnsureCapacity_int32_T(S, q);
    for (q = 0; q < nb; q++) {
      S->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:7' A = 1:size(sum(NumRec(1:3))+1:sum(NumRec(1:4)),2); */
  y = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
  ndbl = (((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) + (double)
    NumRec[3];
  emxInit_real_T(&r14, 2);
  if (ndbl < y + 1.0) {
    q = r14->size[0] * r14->size[1];
    r14->size[1] = 0;
    emxEnsureCapacity_real_T(r14, q);
  } else {
    q = r14->size[0] * r14->size[1];
    r14->size[1] = (int)(ndbl - (y + 1.0)) + 1;
    emxEnsureCapacity_real_T(r14, q);
  }

  emxInit_int32_T(&A, 2);
  if (r14->size[1] < 1) {
    A->size[0] = 1;
    A->size[1] = 0;
  } else {
    nb = r14->size[1];
    q = A->size[0] * A->size[1];
    A->size[0] = 1;
    A->size[1] = nb;
    emxEnsureCapacity_int32_T(A, q);
    for (q = 0; q < nb; q++) {
      A->data[q] = 1 + q;
    }
  }

  emxFree_real_T(&r14);

  /* 'funcionCPrO:8' An = 1:size(sum(NumRec(1:4))+1:sum(NumRec(1:5)),2); */
  y = (((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) + (double)
    NumRec[3];
  ndbl = ((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
          (double)NumRec[3]) + (double)NumRec[4];
  emxInit_real_T(&r15, 2);
  if (ndbl < y + 1.0) {
    q = r15->size[0] * r15->size[1];
    r15->size[1] = 0;
    emxEnsureCapacity_real_T(r15, q);
  } else {
    q = r15->size[0] * r15->size[1];
    r15->size[1] = (int)(ndbl - (y + 1.0)) + 1;
    emxEnsureCapacity_real_T(r15, q);
  }

  emxInit_int32_T(&An, 2);
  if (r15->size[1] < 1) {
    An->size[0] = 1;
    An->size[1] = 0;
  } else {
    nb = r15->size[1];
    q = An->size[0] * An->size[1];
    An->size[0] = 1;
    An->size[1] = nb;
    emxEnsureCapacity_int32_T(An, q);
    for (q = 0; q < nb; q++) {
      An->data[q] = 1 + q;
    }
  }

  emxFree_real_T(&r15);

  /* 'funcionCPrO:9' CPO = 1:size(PCPO, 2); */
  emxInit_int32_T(&CPO, 2);
  if (PCPO->size[1] < 1) {
    CPO->size[0] = 1;
    CPO->size[1] = 0;
  } else {
    nb = PCPO->size[1];
    q = CPO->size[0] * CPO->size[1];
    CPO->size[0] = 1;
    CPO->size[1] = nb;
    emxEnsureCapacity_int32_T(CPO, q);
    for (q = 0; q < nb; q++) {
      CPO->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:10' CR = 1:size(PCR, 2); */
  emxInit_int32_T(&CR, 2);
  if (PCR->size[1] < 1) {
    CR->size[0] = 1;
    CR->size[1] = 0;
  } else {
    nb = PCR->size[1];
    q = CR->size[0] * CR->size[1];
    CR->size[0] = 1;
    CR->size[1] = nb;
    emxEnsureCapacity_int32_T(CR, q);
    for (q = 0; q < nb; q++) {
      CR->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:11' CPrOA = int32(0); */
  b_CPrOA = 0;

  /* 'funcionCPrO:12' CPOA = int32(0); */
  b_CPOA = 0;

  /* 'funcionCPrO:13' CRA = int32(0); */
  b_CRA = 0;

  /* 'funcionCPrO:14' IniCPrOA = int32(0); */
  b_IniCPrOA = 0;

  /* 'funcionCPrO:15' EndCPrOA = int32(0); */
  b_EndCPrOA = 1;

  /* 'funcionCPrO:16' IniSA = int32(0); */
  b_IniSA = 0;

  /* 'funcionCPrO:17' EndSA = int32(0); */
  b_EndSA = 0;

  /* 'funcionCPrO:18' IniCPOA = int32(0); */
  b_IniCPOA = -1;

  /* 'funcionCPrO:19' EndCPOA = int32(0); */
  b_EndCPOA = 0;

  /* 'funcionCPrO:20' IniCRA = int32(0); */
  b_IniCRA = -1;

  /* 'funcionCPrO:21' EndCRA = int32(0); */
  b_EndCRA = 0;

  /* 'funcionCPrO:22' EndCPrOAxD = int32(0); */
  b_EndCPrOAxD = 0;

  /* 'funcionCPrO:23' EndRPxD = int32(0); */
  b_EndRPxD = 0;

  /* 'funcionCPrO:24' EA_double = 1:size(PME,2)-1; */
  emxInit_int32_T(&EA_double, 2);
  if (PME->size[1] - 1 < 1) {
    EA_double->size[0] = 1;
    EA_double->size[1] = 0;
  } else {
    nb = PME->size[1] - 2;
    q = EA_double->size[0] * EA_double->size[1];
    EA_double->size[0] = 1;
    EA_double->size[1] = nb + 1;
    emxEnsureCapacity_int32_T(EA_double, q);
    for (q = 0; q <= nb; q++) {
      EA_double->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:25' AA_double = 1:size(PMA,2)-1; */
  emxInit_int32_T(&AA_double, 2);
  if (PMA->size[1] - 1 < 1) {
    AA_double->size[0] = 1;
    AA_double->size[1] = 0;
  } else {
    nb = PMA->size[1] - 2;
    q = AA_double->size[0] * AA_double->size[1];
    AA_double->size[0] = 1;
    AA_double->size[1] = nb + 1;
    emxEnsureCapacity_int32_T(AA_double, q);
    for (q = 0; q <= nb; q++) {
      AA_double->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:26' AnA_double = 1:size(PMAn,2)-1; */
  emxInit_int32_T(&AnA_double, 2);
  if (PMAn->size[1] - 1 < 1) {
    AnA_double->size[0] = 1;
    AnA_double->size[1] = 0;
  } else {
    nb = PMAn->size[1] - 2;
    q = AnA_double->size[0] * AnA_double->size[1];
    AnA_double->size[0] = 1;
    AnA_double->size[1] = nb + 1;
    emxEnsureCapacity_int32_T(AnA_double, q);
    for (q = 0; q <= nb; q++) {
      AnA_double->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:27' SA_double = 1:size(PS,2)-1; */
  emxInit_int32_T(&SA_double, 2);
  if (PS->size[1] - 1 < 1) {
    SA_double->size[0] = 1;
    SA_double->size[1] = 0;
  } else {
    nb = PS->size[1] - 2;
    q = SA_double->size[0] * SA_double->size[1];
    SA_double->size[0] = 1;
    SA_double->size[1] = nb + 1;
    emxEnsureCapacity_int32_T(SA_double, q);
    for (q = 0; q <= nb; q++) {
      SA_double->data[q] = 1 + q;
    }
  }

  /* 'funcionCPrO:29' flag = true; */
  flag = true;

  /* 'funcionCPrO:30' while flag */
  emxInit_uint32_T(&uCPrODisp, 2);
  emxInit_int32_T(&auxUPxE, 2);
  emxInit_int32_T(&auxUPxA, 2);
  emxInit_int32_T(&auxUPxAn, 2);
  emxInit_int32_T(&auxUPxS, 2);
  emxInit_int32_T(&C, 2);
  emxInit_int32_T(&allC, 2);
  emxInit_int32_T(&u, 1);
  emxInit_int32_T(&allE, 2);
  emxInit_int32_T(&allA, 2);
  emxInit_int32_T(&allAn, 2);
  emxInit_int32_T(&allS, 2);
  emxInit_int32_T(&allCPO, 2);
  emxInit_int32_T(&allCR, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&b, 2);
  emxInit_int32_T(&idx, 2);
  emxInit_int32_T(&iwork, 1);
  emxInit_int32_T(&b_H, 2);
  while (flag) {
    /* 'funcionCPrO:32' auxUPxR = tempUltPosRecXDia; */
    /*  Selecciono los ultimas posiciones a partir de donde se pueden usar las camas. */
    /* 'funcionCPrO:33' [~,C]=find(PCPrO~=0); */
    q = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = PCPrO->size[1];
    emxEnsureCapacity_boolean_T(x, q);
    nb = PCPrO->size[1];
    for (q = 0; q < nb; q++) {
      x->data[q] = (PCPrO->data[q] != 0);
    }

    if (x->size[1] == 0) {
      jj->size[0] = 1;
      jj->size[1] = 0;
    } else {
      b_idx = 0;
      q = jj->size[0] * jj->size[1];
      jj->size[0] = 1;
      jj->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(jj, q);
      yk = 1;
      exitg1 = false;
      while ((!exitg1) && (yk <= x->size[1])) {
        if (x->data[yk - 1]) {
          b_idx++;
          jj->data[b_idx - 1] = yk;
          if (b_idx >= x->size[1]) {
            exitg1 = true;
          } else {
            yk++;
          }
        } else {
          yk++;
        }
      }

      if (x->size[1] == 1) {
        if (b_idx == 0) {
          jj->size[0] = 1;
          jj->size[1] = 0;
        }
      } else {
        q = jj->size[0] * jj->size[1];
        if (1 > b_idx) {
          jj->size[1] = 0;
        } else {
          jj->size[1] = b_idx;
        }

        emxEnsureCapacity_int32_T(jj, q);
      }
    }

    q = C->size[0] * C->size[1];
    C->size[0] = 1;
    C->size[1] = jj->size[1];
    emxEnsureCapacity_int32_T(C, q);
    nb = jj->size[1];
    for (q = 0; q < nb; q++) {
      C->data[q] = jj->data[q];
    }

    /* 'funcionCPrO:33' ~ */
    /*  Busco las posibles camas a usar. */
    /* 'funcionCPrO:34' minP = Dia(contDia,4)-Dia(contDia,3)+1-(TimeUsoCPrO+TimeUsoS); */
    minP = (((Dia->data[(*contDia + Dia->size[0] * 3) - 1] - Dia->data[(*contDia
               + (Dia->size[0] << 1)) - 1]) - TimeUsoCPrO) - TimeUsoS) + 1;

    /*  Posicion maxima a partir de la cual se puede colocar la Operacion. */
    /* 'funcionCPrO:35' [~,allC]=find(auxUPxR(C)<=minP); */
    q = x->size[0] * x->size[1];
    x->size[0] = 1;
    x->size[1] = C->size[1];
    emxEnsureCapacity_boolean_T(x, q);
    nb = C->size[1];
    for (q = 0; q < nb; q++) {
      x->data[q] = (tempUltPosRecXDia->data[C->data[q] - 1] <= minP);
    }

    if (x->size[1] == 0) {
      jj->size[0] = 1;
      jj->size[1] = 0;
    } else {
      b_idx = 0;
      q = jj->size[0] * jj->size[1];
      jj->size[0] = 1;
      jj->size[1] = x->size[1];
      emxEnsureCapacity_int32_T(jj, q);
      yk = 1;
      exitg1 = false;
      while ((!exitg1) && (yk <= x->size[1])) {
        if (x->data[yk - 1]) {
          b_idx++;
          jj->data[b_idx - 1] = yk;
          if (b_idx >= x->size[1]) {
            exitg1 = true;
          } else {
            yk++;
          }
        } else {
          yk++;
        }
      }

      if (x->size[1] == 1) {
        if (b_idx == 0) {
          jj->size[0] = 1;
          jj->size[1] = 0;
        }
      } else {
        q = jj->size[0] * jj->size[1];
        if (1 > b_idx) {
          jj->size[1] = 0;
        } else {
          jj->size[1] = b_idx;
        }

        emxEnsureCapacity_int32_T(jj, q);
      }
    }

    q = allC->size[0] * allC->size[1];
    allC->size[0] = 1;
    allC->size[1] = jj->size[1];
    emxEnsureCapacity_int32_T(allC, q);
    nb = jj->size[1];
    for (q = 0; q < nb; q++) {
      allC->data[q] = jj->data[q];
    }

    /* 'funcionCPrO:35' ~ */
    /*  Veo en cuales es posible asignar la operacion. */
    /* 'funcionCPrO:37' if isempty(allC) */
    if (allC->size[1] == 0) {
      /*  Si no es posible asignar ninguna cama incremento el contDia e llamo a funcionDia */
      /* 'funcionCPrO:38' contDia = contDia + 1; */
      (*contDia)++;

      /* 'funcionCPrO:39' [contDia,tempUltPosRecXDia,DispME] = funcionDia(NumRec, PCPrO, Dia,UltPosRecXDia, TimeUsoCPrO, TimeUsoS, contDia, DispMExD); */
      funcionDia(NumRec, PCPrO, Dia, UltPosRecXDia, TimeUsoCPrO, TimeUsoS,
                 contDia, DispMExD, tempUltPosRecXDia, DispME);
    } else {
      /* 'funcionCPrO:40' else */
      /* 'funcionCPrO:41' [~,u]=unique(auxUPxR(C(allC))); */
      q = jj->size[0] * jj->size[1];
      jj->size[0] = 1;
      jj->size[1] = allC->size[1];
      emxEnsureCapacity_int32_T(jj, q);
      nb = allC->size[1];
      for (q = 0; q < nb; q++) {
        jj->data[q] = tempUltPosRecXDia->data[C->data[allC->data[q] - 1] - 1];
      }

      na = allC->size[1];
      n = allC->size[1] + 1;
      yk = allC->size[1];
      q = idx->size[0] * idx->size[1];
      idx->size[0] = 1;
      idx->size[1] = yk;
      emxEnsureCapacity_int32_T(idx, q);
      for (q = 0; q < yk; q++) {
        idx->data[q] = 0;
      }

      q = iwork->size[0];
      iwork->size[0] = allC->size[1];
      emxEnsureCapacity_int32_T(iwork, q);
      q = allC->size[1] - 1;
      for (k = 1; k <= q; k += 2) {
        if (jj->data[k - 1] <= jj->data[k]) {
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

      yk = 2;
      while (yk < n - 1) {
        b_idx = yk << 1;
        j = 1;
        for (nb = 1 + yk; nb < n; nb = qEnd + yk) {
          p = j;
          q = nb;
          qEnd = j + b_idx;
          if (qEnd > n) {
            qEnd = n;
          }

          k = 0;
          kEnd = qEnd - j;
          while (k + 1 <= kEnd) {
            if (jj->data[idx->data[p - 1] - 1] <= jj->data[idx->data[q - 1] - 1])
            {
              iwork->data[k] = idx->data[p - 1];
              p++;
              if (p == nb) {
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
                while (p < nb) {
                  k++;
                  iwork->data[k] = idx->data[p - 1];
                  p++;
                }
              }
            }

            k++;
          }

          for (k = 0; k < kEnd; k++) {
            idx->data[(j + k) - 1] = iwork->data[k];
          }

          j = qEnd;
        }

        yk = b_idx;
      }

      nm1 = (unsigned int)allC->size[1];
      q = b->size[0] * b->size[1];
      b->size[0] = 1;
      b->size[1] = (int)nm1;
      emxEnsureCapacity_int32_T(b, q);
      for (k = 0; k < na; k++) {
        b->data[k] = jj->data[idx->data[k] - 1];
      }

      nb = -1;
      k = 0;
      while (k + 1 <= na) {
        yk = b->data[k];
        b_idx = k;
        do {
          k++;
        } while (!((k + 1 > na) || (b->data[k] != yk)));

        nb++;
        b->data[nb] = yk;
        idx->data[nb] = idx->data[b_idx];
      }

      q = iwork->size[0];
      iwork->size[0] = nb + 1;
      emxEnsureCapacity_int32_T(iwork, q);
      for (k = 0; k <= nb; k++) {
        iwork->data[k] = idx->data[k];
      }

      q = u->size[0];
      u->size[0] = iwork->size[0];
      emxEnsureCapacity_int32_T(u, q);
      nb = iwork->size[0];
      for (q = 0; q < nb; q++) {
        u->data[q] = iwork->data[q];
      }

      /* 'funcionCPrO:41' ~ */
      /* 'funcionCPrO:42' uCPrODisp=C(allC(u)); */
      q = uCPrODisp->size[0] * uCPrODisp->size[1];
      uCPrODisp->size[0] = 1;
      uCPrODisp->size[1] = u->size[0];
      emxEnsureCapacity_uint32_T(uCPrODisp, q);
      nb = u->size[0];
      for (q = 0; q < nb; q++) {
        uCPrODisp->data[q] = (unsigned int)C->data[allC->data[u->data[q] - 1] -
          1];
      }

      /* 'funcionCPrO:46' auxUPxE = UltPosRecXDia(contDia,NumRec(1)+1:sum(NumRec(1:2))); */
      if (NumRec[0] + 1 > b_tmp) {
        q = 0;
        p = -1;
      } else {
        q = NumRec[0];
        p = b_tmp - 1;
      }

      yk = auxUPxE->size[0] * auxUPxE->size[1];
      auxUPxE->size[0] = 1;
      nb = p - q;
      auxUPxE->size[1] = nb + 1;
      emxEnsureCapacity_int32_T(auxUPxE, yk);
      for (p = 0; p <= nb; p++) {
        auxUPxE->data[p] = UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0]
          * (q + p)) - 1];
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los ME. */
      /* 'funcionCPrO:47' auxPME=PME(1:end-1).*DispME; */
      if (1 > PME->size[1] - 1) {
        nb = 0;
      } else {
        nb = PME->size[1] - 1;
      }

      /* 'funcionCPrO:48' [~,allE]=find(auxPME~=0); */
      q = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = nb;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < nb; q++) {
        x->data[q] = (PME->data[q] * DispME->data[q] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[0] = 1;
        jj->size[1] = 0;
      } else {
        b_idx = 0;
        q = jj->size[0] * jj->size[1];
        jj->size[0] = 1;
        jj->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            b_idx++;
            jj->data[b_idx - 1] = yk;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          }
        } else {
          q = jj->size[0] * jj->size[1];
          if (1 > b_idx) {
            jj->size[1] = 0;
          } else {
            jj->size[1] = b_idx;
          }

          emxEnsureCapacity_int32_T(jj, q);
        }
      }

      q = allE->size[0] * allE->size[1];
      allE->size[0] = 1;
      allE->size[1] = jj->size[1];
      emxEnsureCapacity_int32_T(allE, q);
      nb = jj->size[1];
      for (q = 0; q < nb; q++) {
        allE->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:48' ~ */
      /*  Busco los posibles Especialistas a usar. */
      /* 'funcionCPrO:50' auxUPxA = UltPosRecXDia(contDia,sum(NumRec(1:3))+1:sum(NumRec(1:4))); */
      y = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
      ndbl = (((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
        (double)NumRec[3];
      if (y + 1.0 > ndbl) {
        q = 0;
        p = -1;
      } else {
        q = (int)(y + 1.0) - 1;
        p = (int)ndbl - 1;
      }

      yk = auxUPxA->size[0] * auxUPxA->size[1];
      auxUPxA->size[0] = 1;
      nb = p - q;
      auxUPxA->size[1] = nb + 1;
      emxEnsureCapacity_int32_T(auxUPxA, yk);
      for (p = 0; p <= nb; p++) {
        auxUPxA->data[p] = UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0]
          * (q + p)) - 1];
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los A. */
      /* 'funcionCPrO:51' [~,allA]=find(PMA(1:end-1)~=0); */
      if (1 > PMA->size[1] - 1) {
        nb = 0;
      } else {
        nb = PMA->size[1] - 1;
      }

      q = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = nb;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < nb; q++) {
        x->data[q] = (PMA->data[q] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[0] = 1;
        jj->size[1] = 0;
      } else {
        b_idx = 0;
        q = jj->size[0] * jj->size[1];
        jj->size[0] = 1;
        jj->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            b_idx++;
            jj->data[b_idx - 1] = yk;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          }
        } else {
          q = jj->size[0] * jj->size[1];
          if (1 > b_idx) {
            jj->size[1] = 0;
          } else {
            jj->size[1] = b_idx;
          }

          emxEnsureCapacity_int32_T(jj, q);
        }
      }

      q = allA->size[0] * allA->size[1];
      allA->size[0] = 1;
      allA->size[1] = jj->size[1];
      emxEnsureCapacity_int32_T(allA, q);
      nb = jj->size[1];
      for (q = 0; q < nb; q++) {
        allA->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:51' ~ */
      /*  Busco los posibles Asistentes a usar. */
      /* 'funcionCPrO:53' auxUPxAn = UltPosRecXDia(contDia,sum(NumRec(1:4))+1:sum(NumRec(1:5))); */
      y = (((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
        (double)NumRec[3];
      ndbl = ((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
              (double)NumRec[3]) + (double)NumRec[4];
      if (y + 1.0 > ndbl) {
        q = 0;
        p = -1;
      } else {
        q = (int)(y + 1.0) - 1;
        p = (int)ndbl - 1;
      }

      yk = auxUPxAn->size[0] * auxUPxAn->size[1];
      auxUPxAn->size[0] = 1;
      nb = p - q;
      auxUPxAn->size[1] = nb + 1;
      emxEnsureCapacity_int32_T(auxUPxAn, yk);
      for (p = 0; p <= nb; p++) {
        auxUPxAn->data[p] = UltPosRecXDia->data[(*contDia + UltPosRecXDia->size
          [0] * (q + p)) - 1];
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los An. */
      /* 'funcionCPrO:54' [~,allAn]=find(PMAn(1:end-1)~=0); */
      if (1 > PMAn->size[1] - 1) {
        nb = 0;
      } else {
        nb = PMAn->size[1] - 1;
      }

      q = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = nb;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < nb; q++) {
        x->data[q] = (PMAn->data[q] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[0] = 1;
        jj->size[1] = 0;
      } else {
        b_idx = 0;
        q = jj->size[0] * jj->size[1];
        jj->size[0] = 1;
        jj->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            b_idx++;
            jj->data[b_idx - 1] = yk;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          }
        } else {
          q = jj->size[0] * jj->size[1];
          if (1 > b_idx) {
            jj->size[1] = 0;
          } else {
            jj->size[1] = b_idx;
          }

          emxEnsureCapacity_int32_T(jj, q);
        }
      }

      q = allAn->size[0] * allAn->size[1];
      allAn->size[0] = 1;
      allAn->size[1] = jj->size[1];
      emxEnsureCapacity_int32_T(allAn, q);
      nb = jj->size[1];
      for (q = 0; q < nb; q++) {
        allAn->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:54' ~ */
      /*  Busco los posibles Anestesistas a usar. */
      /* 'funcionCPrO:56' auxUPxS = UltPosRecXDia(contDia,sum(NumRec(1:2))+1:sum(NumRec(1:3))); */
      y = ((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2];
      if (y_tmp + 1.0 > y) {
        q = 0;
        p = -1;
      } else {
        q = (int)(y_tmp + 1.0) - 1;
        p = (int)y - 1;
      }

      yk = auxUPxS->size[0] * auxUPxS->size[1];
      auxUPxS->size[0] = 1;
      nb = p - q;
      auxUPxS->size[1] = nb + 1;
      emxEnsureCapacity_int32_T(auxUPxS, yk);
      for (p = 0; p <= nb; p++) {
        auxUPxS->data[p] = UltPosRecXDia->data[(*contDia + UltPosRecXDia->size[0]
          * (q + p)) - 1];
      }

      /*  Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
      /* 'funcionCPrO:57' [~,allS]=find(PS(1:end)~=0); */
      if (1 > PS->size[1]) {
        nb = 0;
      } else {
        nb = PS->size[1];
      }

      q = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = nb;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < nb; q++) {
        x->data[q] = (PS->data[q] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[0] = 1;
        jj->size[1] = 0;
      } else {
        b_idx = 0;
        q = jj->size[0] * jj->size[1];
        jj->size[0] = 1;
        jj->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            b_idx++;
            jj->data[b_idx - 1] = yk;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          }
        } else {
          q = jj->size[0] * jj->size[1];
          if (1 > b_idx) {
            jj->size[1] = 0;
          } else {
            jj->size[1] = b_idx;
          }

          emxEnsureCapacity_int32_T(jj, q);
        }
      }

      q = allS->size[0] * allS->size[1];
      allS->size[0] = 1;
      allS->size[1] = jj->size[1];
      emxEnsureCapacity_int32_T(allS, q);
      nb = jj->size[1];
      for (q = 0; q < nb; q++) {
        allS->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:57' ~ */
      /*  Busco los posibles Salones a usar. */
      /* auxUPxCPO = UltPosRecXDia(contDia,NumRec(1:5)+1:sum(NumRec(1:6)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los ME. */
      /* 'funcionCPrO:60' [~,allCPO]=find(PCPO(1:end)~=0); */
      if (1 > PCPO->size[1]) {
        nb = 0;
      } else {
        nb = PCPO->size[1];
      }

      q = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = nb;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < nb; q++) {
        x->data[q] = (PCPO->data[q] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[0] = 1;
        jj->size[1] = 0;
      } else {
        b_idx = 0;
        q = jj->size[0] * jj->size[1];
        jj->size[0] = 1;
        jj->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            b_idx++;
            jj->data[b_idx - 1] = yk;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          }
        } else {
          q = jj->size[0] * jj->size[1];
          if (1 > b_idx) {
            jj->size[1] = 0;
          } else {
            jj->size[1] = b_idx;
          }

          emxEnsureCapacity_int32_T(jj, q);
        }
      }

      q = allCPO->size[0] * allCPO->size[1];
      allCPO->size[0] = 1;
      allCPO->size[1] = jj->size[1];
      emxEnsureCapacity_int32_T(allCPO, q);
      nb = jj->size[1];
      for (q = 0; q < nb; q++) {
        allCPO->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:60' ~ */
      /*  Busco los posibles Especialistas a usar. */
      /* auxUPxCR = UltPosRecXDia(contDia,sum(NumRec(1:6))+1:sum(NumRec(1:7)));% Selecciono los ultimas posiciones a partir de donde se pueden seleccionar los S. */
      /* 'funcionCPrO:63' [~,allCR]=find(PCR(1:end)~=0); */
      if (1 > PCR->size[1]) {
        nb = 0;
      } else {
        nb = PCR->size[1];
      }

      q = x->size[0] * x->size[1];
      x->size[0] = 1;
      x->size[1] = nb;
      emxEnsureCapacity_boolean_T(x, q);
      for (q = 0; q < nb; q++) {
        x->data[q] = (PCR->data[q] != 0);
      }

      if (x->size[1] == 0) {
        jj->size[0] = 1;
        jj->size[1] = 0;
      } else {
        b_idx = 0;
        q = jj->size[0] * jj->size[1];
        jj->size[0] = 1;
        jj->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(jj, q);
        yk = 1;
        exitg1 = false;
        while ((!exitg1) && (yk <= x->size[1])) {
          if (x->data[yk - 1]) {
            b_idx++;
            jj->data[b_idx - 1] = yk;
            if (b_idx >= x->size[1]) {
              exitg1 = true;
            } else {
              yk++;
            }
          } else {
            yk++;
          }
        }

        if (x->size[1] == 1) {
          if (b_idx == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          }
        } else {
          q = jj->size[0] * jj->size[1];
          if (1 > b_idx) {
            jj->size[1] = 0;
          } else {
            jj->size[1] = b_idx;
          }

          emxEnsureCapacity_int32_T(jj, q);
        }
      }

      q = allCR->size[0] * allCR->size[1];
      allCR->size[0] = 1;
      allCR->size[1] = jj->size[1];
      emxEnsureCapacity_int32_T(allCR, q);
      nb = jj->size[1];
      for (q = 0; q < nb; q++) {
        allCR->data[q] = jj->data[q];
      }

      /* 'funcionCPrO:63' ~ */
      /*  Busco los posibles Salones a usar. */
      /* 'funcionCPrO:64' temCPrO=-1; */
      temCPrO = -1;

      /* 'funcionCPrO:66' for j=1:length(uCPrODisp) */
      j = 0;
      do {
        exitg2 = 0;
        yk = u->size[0];
        if (j <= yk - 1) {
          /* 'funcionCPrO:68' EndCPrOAxD = auxUPxR(uCPrODisp(j))+TimeUsoCPrO; */
          b_EndCPrOAxD = tempUltPosRecXDia->data[(int)uCPrODisp->data[j] - 1] +
            TimeUsoCPrO;

          /* 'funcionCPrO:69' EndRPxD = EndCPrOAxD+TimeUsoS; */
          b_EndRPxD = b_EndCPrOAxD + TimeUsoS;

          /* 'funcionCPrO:71' [~,E]=find(auxUPxE(allE)<=EndCPrOAxD); */
          q = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = allE->size[1];
          emxEnsureCapacity_boolean_T(x, q);
          nb = allE->size[1];
          for (q = 0; q < nb; q++) {
            x->data[q] = (auxUPxE->data[allE->data[q] - 1] <= b_EndCPrOAxD);
          }

          if (x->size[1] == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          } else {
            b_idx = 0;
            q = jj->size[0] * jj->size[1];
            jj->size[0] = 1;
            jj->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(jj, q);
            yk = 1;
            exitg1 = false;
            while ((!exitg1) && (yk <= x->size[1])) {
              if (x->data[yk - 1]) {
                b_idx++;
                jj->data[b_idx - 1] = yk;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  yk++;
                }
              } else {
                yk++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                jj->size[0] = 1;
                jj->size[1] = 0;
              }
            } else {
              q = jj->size[0] * jj->size[1];
              if (1 > b_idx) {
                jj->size[1] = 0;
              } else {
                jj->size[1] = b_idx;
              }

              emxEnsureCapacity_int32_T(jj, q);
            }
          }

          q = E->size[0] * E->size[1];
          E->size[0] = 1;
          E->size[1] = jj->size[1];
          emxEnsureCapacity_int32_T(E, q);
          nb = jj->size[1];
          for (q = 0; q < nb; q++) {
            E->data[q] = jj->data[q];
          }

          /* 'funcionCPrO:71' ~ */
          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
          /* 'funcionCPrO:72' [~,A]=find(auxUPxA(allA)<=EndCPrOAxD); */
          q = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = allA->size[1];
          emxEnsureCapacity_boolean_T(x, q);
          nb = allA->size[1];
          for (q = 0; q < nb; q++) {
            x->data[q] = (auxUPxA->data[allA->data[q] - 1] <= b_EndCPrOAxD);
          }

          if (x->size[1] == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          } else {
            b_idx = 0;
            q = jj->size[0] * jj->size[1];
            jj->size[0] = 1;
            jj->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(jj, q);
            yk = 1;
            exitg1 = false;
            while ((!exitg1) && (yk <= x->size[1])) {
              if (x->data[yk - 1]) {
                b_idx++;
                jj->data[b_idx - 1] = yk;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  yk++;
                }
              } else {
                yk++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                jj->size[0] = 1;
                jj->size[1] = 0;
              }
            } else {
              q = jj->size[0] * jj->size[1];
              if (1 > b_idx) {
                jj->size[1] = 0;
              } else {
                jj->size[1] = b_idx;
              }

              emxEnsureCapacity_int32_T(jj, q);
            }
          }

          q = A->size[0] * A->size[1];
          A->size[0] = 1;
          A->size[1] = jj->size[1];
          emxEnsureCapacity_int32_T(A, q);
          nb = jj->size[1];
          for (q = 0; q < nb; q++) {
            A->data[q] = jj->data[q];
          }

          /* 'funcionCPrO:72' ~ */
          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
          /* 'funcionCPrO:73' [~,An]=find(auxUPxAn(allAn)<=EndCPrOAxD); */
          q = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = allAn->size[1];
          emxEnsureCapacity_boolean_T(x, q);
          nb = allAn->size[1];
          for (q = 0; q < nb; q++) {
            x->data[q] = (auxUPxAn->data[allAn->data[q] - 1] <= b_EndCPrOAxD);
          }

          if (x->size[1] == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          } else {
            b_idx = 0;
            q = jj->size[0] * jj->size[1];
            jj->size[0] = 1;
            jj->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(jj, q);
            yk = 1;
            exitg1 = false;
            while ((!exitg1) && (yk <= x->size[1])) {
              if (x->data[yk - 1]) {
                b_idx++;
                jj->data[b_idx - 1] = yk;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  yk++;
                }
              } else {
                yk++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                jj->size[0] = 1;
                jj->size[1] = 0;
              }
            } else {
              q = jj->size[0] * jj->size[1];
              if (1 > b_idx) {
                jj->size[1] = 0;
              } else {
                jj->size[1] = b_idx;
              }

              emxEnsureCapacity_int32_T(jj, q);
            }
          }

          q = An->size[0] * An->size[1];
          An->size[0] = 1;
          An->size[1] = jj->size[1];
          emxEnsureCapacity_int32_T(An, q);
          nb = jj->size[1];
          for (q = 0; q < nb; q++) {
            An->data[q] = jj->data[q];
          }

          /* 'funcionCPrO:73' ~ */
          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
          /* 'funcionCPrO:74' [~,S]=find(auxUPxS(allS)<=EndCPrOAxD); */
          q = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = allS->size[1];
          emxEnsureCapacity_boolean_T(x, q);
          nb = allS->size[1];
          for (q = 0; q < nb; q++) {
            x->data[q] = (auxUPxS->data[allS->data[q] - 1] <= b_EndCPrOAxD);
          }

          if (x->size[1] == 0) {
            jj->size[0] = 1;
            jj->size[1] = 0;
          } else {
            b_idx = 0;
            q = jj->size[0] * jj->size[1];
            jj->size[0] = 1;
            jj->size[1] = x->size[1];
            emxEnsureCapacity_int32_T(jj, q);
            yk = 1;
            exitg1 = false;
            while ((!exitg1) && (yk <= x->size[1])) {
              if (x->data[yk - 1]) {
                b_idx++;
                jj->data[b_idx - 1] = yk;
                if (b_idx >= x->size[1]) {
                  exitg1 = true;
                } else {
                  yk++;
                }
              } else {
                yk++;
              }
            }

            if (x->size[1] == 1) {
              if (b_idx == 0) {
                jj->size[0] = 1;
                jj->size[1] = 0;
              }
            } else {
              q = jj->size[0] * jj->size[1];
              if (1 > b_idx) {
                jj->size[1] = 0;
              } else {
                jj->size[1] = b_idx;
              }

              emxEnsureCapacity_int32_T(jj, q);
            }
          }

          q = S->size[0] * S->size[1];
          S->size[0] = 1;
          S->size[1] = jj->size[1];
          emxEnsureCapacity_int32_T(S, q);
          nb = jj->size[1];
          for (q = 0; q < nb; q++) {
            S->data[q] = jj->data[q];
          }

          /* 'funcionCPrO:74' ~ */
          /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo.         */
          /* 'funcionCPrO:76' if TimeUsoCPO == 0 */
          if (TimeUsoCPO == 0) {
            /* 'funcionCPrO:77' CPO=0; */
            q = CPO->size[0] * CPO->size[1];
            CPO->size[0] = 1;
            CPO->size[1] = 1;
            emxEnsureCapacity_int32_T(CPO, q);
            CPO->data[0] = 0;

            /* 'funcionCPrO:78' IniCR=Dia(contDia,3)+EndCPrOAxD+TimeUsoS; */
            IniCR = ((Dia->data[(*contDia + (Dia->size[0] << 1)) - 1] +
                      b_EndCPrOAxD) + TimeUsoS) - 1;

            /* 'funcionCPrO:79' [~,CR]=find(sum(H(IniCR:IniCR+TimeUsoCR-1,sum(NumRec(1:6))+allCR))==0); */
            q = IniCR + TimeUsoCR;
            if (IniCR + 1 > q) {
              p = 0;
              q = 0;
            } else {
              p = IniCR;
            }

            y = NumRec[0];
            for (k = 0; k < 5; k++) {
              y += (double)NumRec[k + 1];
            }

            yk = b_H->size[0] * b_H->size[1];
            nb = q - p;
            b_H->size[0] = nb;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_int32_T(b_H, yk);
            b_idx = allCR->size[1];
            for (q = 0; q < b_idx; q++) {
              for (yk = 0; yk < nb; yk++) {
                b_H->data[yk + b_H->size[0] * q] = H->data[(p + yk) + H->size[0]
                  * ((int)(y + (double)allCR->data[q]) - 1)];
              }
            }

            d_sum(b_H, r13);
            q = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r13->size[1];
            emxEnsureCapacity_boolean_T(x, q);
            nb = r13->size[1];
            for (q = 0; q < nb; q++) {
              x->data[q] = (r13->data[q] == 0.0);
            }

            if (x->size[1] == 0) {
              jj->size[0] = 1;
              jj->size[1] = 0;
            } else {
              b_idx = 0;
              q = jj->size[0] * jj->size[1];
              jj->size[0] = 1;
              jj->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(jj, q);
              yk = 1;
              exitg1 = false;
              while ((!exitg1) && (yk <= x->size[1])) {
                if (x->data[yk - 1]) {
                  b_idx++;
                  jj->data[b_idx - 1] = yk;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    yk++;
                  }
                } else {
                  yk++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  jj->size[0] = 1;
                  jj->size[1] = 0;
                }
              } else {
                q = jj->size[0] * jj->size[1];
                if (1 > b_idx) {
                  jj->size[1] = 0;
                } else {
                  jj->size[1] = b_idx;
                }

                emxEnsureCapacity_int32_T(jj, q);
              }
            }

            q = CR->size[0] * CR->size[1];
            CR->size[0] = 1;
            CR->size[1] = jj->size[1];
            emxEnsureCapacity_int32_T(CR, q);
            nb = jj->size[1];
            for (q = 0; q < nb; q++) {
              CR->data[q] = jj->data[q];
            }

            /* 'funcionCPrO:79' ~ */
          } else {
            /* 'funcionCPrO:80' else */
            /* 'funcionCPrO:81' IniCPO=Dia(contDia,3)+EndCPrOAxD+TimeUsoS; */
            IniCPO = ((Dia->data[(*contDia + (Dia->size[0] << 1)) - 1] +
                       b_EndCPrOAxD) + TimeUsoS) - 1;

            /* 'funcionCPrO:82' EndCPO=IniCPO+TimeUsoCPO-1; */
            EndCPO = (IniCPO + TimeUsoCPO) - 1;

            /* 'funcionCPrO:83' [~,CPO]=find(sum(H(IniCPO:EndCPO,sum(NumRec(1:5))+allCPO))==0); */
            if (IniCPO + 1 > EndCPO + 1) {
              q = 0;
              p = -1;
            } else {
              q = IniCPO;
              p = EndCPO;
            }

            y = ((((double)NumRec[0] + (double)NumRec[1]) + (double)NumRec[2]) +
                 (double)NumRec[3]) + (double)NumRec[4];
            yk = b_H->size[0] * b_H->size[1];
            nb = p - q;
            b_H->size[0] = nb + 1;
            b_H->size[1] = allCPO->size[1];
            emxEnsureCapacity_int32_T(b_H, yk);
            b_idx = allCPO->size[1];
            for (p = 0; p < b_idx; p++) {
              for (yk = 0; yk <= nb; yk++) {
                b_H->data[yk + b_H->size[0] * p] = H->data[(q + yk) + H->size[0]
                  * ((int)(y + (double)allCPO->data[p]) - 1)];
              }
            }

            d_sum(b_H, r13);
            q = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r13->size[1];
            emxEnsureCapacity_boolean_T(x, q);
            nb = r13->size[1];
            for (q = 0; q < nb; q++) {
              x->data[q] = (r13->data[q] == 0.0);
            }

            if (x->size[1] == 0) {
              jj->size[0] = 1;
              jj->size[1] = 0;
            } else {
              b_idx = 0;
              q = jj->size[0] * jj->size[1];
              jj->size[0] = 1;
              jj->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(jj, q);
              yk = 1;
              exitg1 = false;
              while ((!exitg1) && (yk <= x->size[1])) {
                if (x->data[yk - 1]) {
                  b_idx++;
                  jj->data[b_idx - 1] = yk;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    yk++;
                  }
                } else {
                  yk++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  jj->size[0] = 1;
                  jj->size[1] = 0;
                }
              } else {
                q = jj->size[0] * jj->size[1];
                if (1 > b_idx) {
                  jj->size[1] = 0;
                } else {
                  jj->size[1] = b_idx;
                }

                emxEnsureCapacity_int32_T(jj, q);
              }
            }

            q = CPO->size[0] * CPO->size[1];
            CPO->size[0] = 1;
            CPO->size[1] = jj->size[1];
            emxEnsureCapacity_int32_T(CPO, q);
            nb = jj->size[1];
            for (q = 0; q < nb; q++) {
              CPO->data[q] = jj->data[q];
            }

            /* 'funcionCPrO:83' ~ */
            /*  Veo, dentro de los posibles, cuales estan libre en ese tiempo. */
            /* 'funcionCPrO:84' [~,CR]=find(~sum(H(EndCPO+1:EndCPO+TimeUsoCR,sum(NumRec(1:6))+allCR))); */
            y = NumRec[0];
            for (k = 0; k < 5; k++) {
              y += (double)NumRec[k + 1];
            }

            q = b_H->size[0] * b_H->size[1];
            b_H->size[0] = TimeUsoCR;
            b_H->size[1] = allCR->size[1];
            emxEnsureCapacity_int32_T(b_H, q);
            nb = allCR->size[1];
            for (q = 0; q < nb; q++) {
              for (p = 0; p < TimeUsoCR; p++) {
                b_H->data[p + b_H->size[0] * q] = H->data[((p + EndCPO) +
                  H->size[0] * ((int)(y + (double)allCR->data[q]) - 1)) + 1];
              }
            }

            d_sum(b_H, r13);
            q = x->size[0] * x->size[1];
            x->size[0] = 1;
            x->size[1] = r13->size[1];
            emxEnsureCapacity_boolean_T(x, q);
            nb = r13->size[1];
            for (q = 0; q < nb; q++) {
              x->data[q] = (r13->data[q] == 0.0);
            }

            if (x->size[1] == 0) {
              jj->size[0] = 1;
              jj->size[1] = 0;
            } else {
              b_idx = 0;
              q = jj->size[0] * jj->size[1];
              jj->size[0] = 1;
              jj->size[1] = x->size[1];
              emxEnsureCapacity_int32_T(jj, q);
              yk = 1;
              exitg1 = false;
              while ((!exitg1) && (yk <= x->size[1])) {
                if (x->data[yk - 1]) {
                  b_idx++;
                  jj->data[b_idx - 1] = yk;
                  if (b_idx >= x->size[1]) {
                    exitg1 = true;
                  } else {
                    yk++;
                  }
                } else {
                  yk++;
                }
              }

              if (x->size[1] == 1) {
                if (b_idx == 0) {
                  jj->size[0] = 1;
                  jj->size[1] = 0;
                }
              } else {
                q = jj->size[0] * jj->size[1];
                if (1 > b_idx) {
                  jj->size[1] = 0;
                } else {
                  jj->size[1] = b_idx;
                }

                emxEnsureCapacity_int32_T(jj, q);
              }
            }

            q = CR->size[0] * CR->size[1];
            CR->size[0] = 1;
            CR->size[1] = jj->size[1];
            emxEnsureCapacity_int32_T(CR, q);
            nb = jj->size[1];
            for (q = 0; q < nb; q++) {
              CR->data[q] = jj->data[q];
            }

            /* 'funcionCPrO:84' ~ */
          }

          /* 'funcionCPrO:88' if ~isempty(CPO)&&~isempty(CR)&&~isempty(S)&&size(E,2)>=PME(end)&&size(A,2)>=PMA(end)&&size(An,2)>=PMAn(end) */
          if ((CPO->size[1] != 0) && (CR->size[1] != 0) && (S->size[1] != 0) &&
              (E->size[1] >= PME->data[PME->size[1] - 1]) && (A->size[1] >=
               PMA->data[PMA->size[1] - 1]) && (An->size[1] >= PMAn->data
               [PMAn->size[1] - 1])) {
            /* 'funcionCPrO:89' temCPrO = uCPrODisp(j); */
            temCPrO = (int)uCPrODisp->data[j];
            exitg2 = 1;
          } else {
            j++;
          }
        } else {
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      /* 'funcionCPrO:95' if temCPrO == -1 */
      if (temCPrO == -1) {
        /* 'funcionCPrO:97' tempUltPosRecXDia = tempUltPosRecXDia+1; */
        q = tempUltPosRecXDia->size[0] * tempUltPosRecXDia->size[1];
        tempUltPosRecXDia->size[0] = 1;
        emxEnsureCapacity_int32_T(tempUltPosRecXDia, q);
        nb = tempUltPosRecXDia->size[1];
        for (q = 0; q < nb; q++) {
          tempUltPosRecXDia->data[q]++;
        }
      } else {
        /* 'funcionCPrO:99' else */
        /* 'funcionCPrO:101' CPrOA = int32(temCPrO); */
        b_CPrOA = temCPrO;

        /* 'funcionCPrO:102' IniCPrOA = Dia(contDia,3)+int32(auxUPxR(CPrOA)); */
        b_IniCPrOA = Dia->data[(*contDia + (Dia->size[0] << 1)) - 1] +
          tempUltPosRecXDia->data[temCPrO - 1];

        /* 'funcionCPrO:103' EndCPrOA = IniCPrOA + TimeUsoCPrO-1; */
        b_EndCPrOA = b_IniCPrOA + TimeUsoCPrO;

        /* 'funcionCPrO:105' SA_double = allS(S(1)); */
        q = SA_double->size[0] * SA_double->size[1];
        SA_double->size[0] = 1;
        SA_double->size[1] = 1;
        emxEnsureCapacity_int32_T(SA_double, q);
        SA_double->data[0] = allS->data[S->data[0] - 1];

        /* 'funcionCPrO:106' IniSA = EndCPrOA+1; */
        b_IniSA = b_EndCPrOA;

        /* 'funcionCPrO:107' EndSA = IniSA+TimeUsoS-1; */
        b_EndSA = (b_EndCPrOA + TimeUsoS) - 1;

        /* 'funcionCPrO:109' EA_double = allE(E(1:PME(end))); */
        if (1 > PME->data[PME->size[1] - 1]) {
          nb = 0;
        } else {
          nb = PME->data[PME->size[1] - 1];
        }

        q = EA_double->size[0] * EA_double->size[1];
        EA_double->size[0] = 1;
        EA_double->size[1] = nb;
        emxEnsureCapacity_int32_T(EA_double, q);
        for (q = 0; q < nb; q++) {
          EA_double->data[q] = allE->data[E->data[q] - 1];
        }

        /* 'funcionCPrO:111' AA_double = allA(A(1:PMA(end))); */
        if (1 > PMA->data[PMA->size[1] - 1]) {
          nb = 0;
        } else {
          nb = PMA->data[PMA->size[1] - 1];
        }

        q = AA_double->size[0] * AA_double->size[1];
        AA_double->size[0] = 1;
        AA_double->size[1] = nb;
        emxEnsureCapacity_int32_T(AA_double, q);
        for (q = 0; q < nb; q++) {
          AA_double->data[q] = allA->data[A->data[q] - 1];
        }

        /* 'funcionCPrO:113' AnA_double = allAn(An(1:PMAn(end))); */
        if (1 > PMAn->data[PMAn->size[1] - 1]) {
          nb = 0;
        } else {
          nb = PMAn->data[PMAn->size[1] - 1];
        }

        q = AnA_double->size[0] * AnA_double->size[1];
        AnA_double->size[0] = 1;
        AnA_double->size[1] = nb;
        emxEnsureCapacity_int32_T(AnA_double, q);
        for (q = 0; q < nb; q++) {
          AnA_double->data[q] = allAn->data[An->data[q] - 1];
        }

        /* 'funcionCPrO:115' if TimeUsoCPO==0 */
        if (TimeUsoCPO == 0) {
          /* 'funcionCPrO:116' CPOA = int32(0); */
          b_CPOA = 0;

          /* 'funcionCPrO:117' IniCPOA = int32(0); */
          b_IniCPOA = -1;

          /* 'funcionCPrO:118' EndCPOA = int32(0); */
          b_EndCPOA = 0;

          /* 'funcionCPrO:120' CRA = int32(allCR(CR(1))); */
          b_CRA = allCR->data[CR->data[0] - 1];

          /* 'funcionCPrO:121' IniCRA = EndSA+1; */
          b_IniCRA = b_EndSA;

          /* 'funcionCPrO:122' EndCRA = IniCRA + TimeUsoCR-1; */
          b_EndCRA = b_EndSA + TimeUsoCR;
        } else {
          /* 'funcionCPrO:123' else */
          /* 'funcionCPrO:124' CPOA = int32(allCPO(CPO(1))); */
          b_CPOA = allCPO->data[CPO->data[0] - 1];

          /* 'funcionCPrO:125' IniCPOA = EndSA+1; */
          b_IniCPOA = b_EndSA;

          /* 'funcionCPrO:126' EndCPOA = IniCPOA + TimeUsoCPO-1; */
          b_EndCPOA = b_EndSA + TimeUsoCPO;

          /* 'funcionCPrO:128' CRA = int32(allCR(CR(1))); */
          b_CRA = allCR->data[CR->data[0] - 1];

          /* 'funcionCPrO:129' IniCRA = EndCPOA+1; */
          b_IniCRA = b_EndCPOA;

          /* 'funcionCPrO:130' EndCRA = IniCRA + TimeUsoCR-1; */
          b_EndCRA = b_EndCPOA + TimeUsoCR;
        }

        /* 'funcionCPrO:133' flag = false; */
        flag = false;
      }
    }
  }

  emxFree_int32_T(&b_H);
  emxFree_int32_T(&iwork);
  emxFree_int32_T(&idx);
  emxFree_int32_T(&b);
  emxFree_int32_T(&jj);
  emxFree_boolean_T(&x);
  emxFree_real_T(&r13);
  emxFree_int32_T(&allCR);
  emxFree_int32_T(&allCPO);
  emxFree_int32_T(&allS);
  emxFree_int32_T(&allAn);
  emxFree_int32_T(&allA);
  emxFree_int32_T(&allE);
  emxFree_int32_T(&u);
  emxFree_int32_T(&allC);
  emxFree_int32_T(&C);
  emxFree_int32_T(&auxUPxS);
  emxFree_int32_T(&auxUPxAn);
  emxFree_int32_T(&auxUPxA);
  emxFree_int32_T(&auxUPxE);
  emxFree_uint32_T(&uCPrODisp);
  emxFree_int32_T(&CR);
  emxFree_int32_T(&CPO);
  emxFree_int32_T(&An);
  emxFree_int32_T(&A);
  emxFree_int32_T(&S);
  emxFree_int32_T(&E);

  /* 'funcionCPrO:140' EA = int32(EA_double); */
  q = EA->size[0] * EA->size[1];
  EA->size[0] = 1;
  EA->size[1] = EA_double->size[1];
  emxEnsureCapacity_int32_T(EA, q);
  nb = EA_double->size[1];
  for (q = 0; q < nb; q++) {
    EA->data[q] = EA_double->data[q];
  }

  emxFree_int32_T(&EA_double);

  /* 'funcionCPrO:141' AA = int32(AA_double); */
  q = AA->size[0] * AA->size[1];
  AA->size[0] = 1;
  AA->size[1] = AA_double->size[1];
  emxEnsureCapacity_int32_T(AA, q);
  nb = AA_double->size[1];
  for (q = 0; q < nb; q++) {
    AA->data[q] = AA_double->data[q];
  }

  emxFree_int32_T(&AA_double);

  /* 'funcionCPrO:142' AnA = int32(AnA_double); */
  q = AnA->size[0] * AnA->size[1];
  AnA->size[0] = 1;
  AnA->size[1] = AnA_double->size[1];
  emxEnsureCapacity_int32_T(AnA, q);
  nb = AnA_double->size[1];
  for (q = 0; q < nb; q++) {
    AnA->data[q] = AnA_double->data[q];
  }

  emxFree_int32_T(&AnA_double);

  /* 'funcionCPrO:143' SA = int32(SA_double); */
  q = SA->size[0] * SA->size[1];
  SA->size[0] = 1;
  SA->size[1] = SA_double->size[1];
  emxEnsureCapacity_int32_T(SA, q);
  nb = SA_double->size[1];
  for (q = 0; q < nb; q++) {
    SA->data[q] = SA_double->data[q];
  }

  emxFree_int32_T(&SA_double);
  *CPrOA = b_CPrOA;
  *IniCPrOA = b_IniCPrOA;
  *EndCPrOA = b_EndCPrOA - 1;
  *EndCPrOAxD = b_EndCPrOAxD;
  *IniSA = b_IniSA;
  *EndSA = b_EndSA;
  *EndRPxD = b_EndRPxD;
  *CPOA = b_CPOA;
  *IniCPOA = b_IniCPOA + 1;
  *EndCPOA = b_EndCPOA;
  *CRA = b_CRA;
  *IniCRA = b_IniCRA + 1;
  *EndCRA = b_EndCRA;
}

/* End of code generation (funcionCPrO.c) */
