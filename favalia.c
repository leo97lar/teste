/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * favalia.c
 *
 * Code generation for function 'favalia'
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
#include "sum.h"

/* Function Definitions */
void b_favalia(const emxArray_real_T *schedule, const emxArray_int32_T *DiaOp,
               const emxArray_int32_T *EP, emxArray_real_T *EspMedOp, double k0,
               double k1, double k2, double k3, double *fitness, double *Tt,
               double *NOFP, double *TmNOFP, double *NOE2, double *NOE3)
{
  emxArray_boolean_T *x;
  int i23;
  int jj;
  int nx;
  emxArray_boolean_T *v;
  emxArray_int32_T *ii;
  emxArray_int32_T *b_ii;
  int idx;
  emxArray_real_T *minEsp;
  int c_ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_int32_T *DifT;
  unsigned int EspMedOp_idx_0;
  emxArray_int32_T *d_ii;
  emxInit_boolean_T(&x, 2);
  i23 = x->size[0] * x->size[1];
  x->size[0] = schedule->size[0];
  x->size[1] = schedule->size[1];
  emxEnsureCapacity_boolean_T(x, i23);
  jj = schedule->size[0] * schedule->size[1];
  for (i23 = 0; i23 < jj; i23++) {
    x->data[i23] = (schedule->data[i23] != 0.0);
  }

  nx = x->size[0] * x->size[1];
  emxInit_boolean_T(&v, 1);
  emxInit_int32_T(&ii, 1);
  emxInit_int32_T(&b_ii, 1);
  if (nx == 0) {
    ii->size[0] = 0;
  } else {
    idx = 0;
    i23 = ii->size[0];
    ii->size[0] = nx;
    emxEnsureCapacity_int32_T(ii, i23);
    c_ii = 1;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= x->size[1])) {
      guard1 = false;
      if (x->data[(c_ii + x->size[0] * (jj - 1)) - 1]) {
        idx++;
        ii->data[idx - 1] = c_ii;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        c_ii++;
        if (c_ii > x->size[0]) {
          c_ii = 1;
          jj++;
        }
      }
    }

    if (nx == 1) {
      if (idx == 0) {
        ii->size[0] = 0;
      }
    } else {
      i23 = ii->size[0];
      if (1 > idx) {
        ii->size[0] = 0;
      } else {
        ii->size[0] = idx;
      }

      emxEnsureCapacity_int32_T(ii, i23);
    }
  }

  emxFree_boolean_T(&x);
  emxInit_real_T(&minEsp, 1);
  i23 = minEsp->size[0];
  minEsp->size[0] = ii->size[0];
  emxEnsureCapacity_real_T(minEsp, i23);
  jj = ii->size[0];
  for (i23 = 0; i23 < jj; i23++) {
    minEsp->data[i23] = ii->data[i23];
  }

  c_ii = minEsp->size[0];
  if (minEsp->size[0] <= 2) {
    if (minEsp->size[0] == 1) {
      *Tt = minEsp->data[0];
    } else if (minEsp->data[0] < minEsp->data[1]) {
      *Tt = minEsp->data[1];
    } else {
      *Tt = minEsp->data[0];
    }
  } else {
    jj = (int)minEsp->data[0];
    for (nx = 2; nx <= c_ii; nx++) {
      if (jj < (int)minEsp->data[nx - 1]) {
        jj = (int)minEsp->data[nx - 1];
      }
    }

    *Tt = jj;
  }

  jj = (EspMedOp->size[0] << 1) - 1;
  nx = 0;
  for (idx = 0; idx <= jj; idx++) {
    if (EspMedOp->data[idx] == 0.0) {
      nx++;
    }
  }

  emxInit_int32_T(&DifT, 1);
  i23 = DifT->size[0];
  DifT->size[0] = nx;
  emxEnsureCapacity_int32_T(DifT, i23);
  c_ii = 0;
  for (idx = 0; idx <= jj; idx++) {
    if (EspMedOp->data[idx] == 0.0) {
      DifT->data[c_ii] = idx + 1;
      c_ii++;
    }
  }

  jj = DifT->size[0] - 1;
  for (i23 = 0; i23 <= jj; i23++) {
    EspMedOp->data[DifT->data[i23] - 1] = 5.0;
  }

  /*  Sustituyo el 0 (caso en que solo era necesario un medico) por un valor mayor para que a la hora de buscar el min no afecte el resultado. */
  c_ii = EspMedOp->size[0] - 1;
  EspMedOp_idx_0 = (unsigned int)EspMedOp->size[0];
  i23 = minEsp->size[0];
  minEsp->size[0] = (int)EspMedOp_idx_0;
  emxEnsureCapacity_real_T(minEsp, i23);
  if (EspMedOp->size[0] >= 1) {
    for (idx = 0; idx <= c_ii; idx++) {
      minEsp->data[idx] = EspMedOp->data[idx];
    }

    for (idx = 0; idx <= c_ii; idx++) {
      if (minEsp->data[idx] > EspMedOp->data[idx + EspMedOp->size[0]]) {
        minEsp->data[idx] = EspMedOp->data[idx + EspMedOp->size[0]];
      }
    }
  }

  i23 = v->size[0];
  v->size[0] = minEsp->size[0];
  emxEnsureCapacity_boolean_T(v, i23);
  jj = minEsp->size[0];
  for (i23 = 0; i23 < jj; i23++) {
    v->data[i23] = (minEsp->data[i23] == 2.0);
  }

  nx = v->size[0];
  idx = 0;
  i23 = ii->size[0];
  ii->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(ii, i23);
  c_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (c_ii <= nx - 1)) {
    if (v->data[c_ii]) {
      idx++;
      ii->data[idx - 1] = c_ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        c_ii++;
      }
    } else {
      c_ii++;
    }
  }

  if (v->size[0] == 1) {
    if (idx == 0) {
      ii->size[0] = 0;
    }
  } else {
    i23 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(ii, i23);
  }

  *NOE2 = ii->size[0];
  i23 = v->size[0];
  v->size[0] = minEsp->size[0];
  emxEnsureCapacity_boolean_T(v, i23);
  jj = minEsp->size[0];
  for (i23 = 0; i23 < jj; i23++) {
    v->data[i23] = (minEsp->data[i23] == 3.0);
  }

  nx = v->size[0];
  idx = 0;
  i23 = b_ii->size[0];
  b_ii->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(b_ii, i23);
  c_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (c_ii <= nx - 1)) {
    if (v->data[c_ii]) {
      idx++;
      b_ii->data[idx - 1] = c_ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        c_ii++;
      }
    } else {
      c_ii++;
    }
  }

  if (v->size[0] == 1) {
    if (idx == 0) {
      b_ii->size[0] = 0;
    }
  } else {
    i23 = b_ii->size[0];
    if (1 > idx) {
      b_ii->size[0] = 0;
    } else {
      b_ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(b_ii, i23);
  }

  *NOE3 = b_ii->size[0];
  i23 = DifT->size[0];
  DifT->size[0] = DiaOp->size[0];
  emxEnsureCapacity_int32_T(DifT, i23);
  jj = DiaOp->size[0];
  for (i23 = 0; i23 < jj; i23++) {
    nx = DiaOp->data[i23];
    c_ii = EP->data[i23];
    if ((nx >= 0) && (c_ii < nx - MAX_int32_T)) {
      c_ii = MAX_int32_T;
    } else if ((nx < 0) && (c_ii > nx - MIN_int32_T)) {
      c_ii = MIN_int32_T;
    } else {
      c_ii = nx - c_ii;
    }

    DifT->data[i23] = c_ii;
  }

  i23 = v->size[0];
  v->size[0] = DifT->size[0];
  emxEnsureCapacity_boolean_T(v, i23);
  jj = DifT->size[0];
  for (i23 = 0; i23 < jj; i23++) {
    v->data[i23] = (DifT->data[i23] > 0);
  }

  emxInit_int32_T(&d_ii, 1);
  nx = v->size[0];
  idx = 0;
  i23 = d_ii->size[0];
  d_ii->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(d_ii, i23);
  c_ii = 0;
  exitg1 = false;
  while ((!exitg1) && (c_ii <= nx - 1)) {
    if (v->data[c_ii]) {
      idx++;
      d_ii->data[idx - 1] = c_ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        c_ii++;
      }
    } else {
      c_ii++;
    }
  }

  if (v->size[0] == 1) {
    if (idx == 0) {
      d_ii->size[0] = 0;
    }
  } else {
    i23 = d_ii->size[0];
    if (1 > idx) {
      d_ii->size[0] = 0;
    } else {
      d_ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(d_ii, i23);
  }

  emxFree_boolean_T(&v);
  i23 = minEsp->size[0];
  minEsp->size[0] = d_ii->size[0];
  emxEnsureCapacity_real_T(minEsp, i23);
  jj = d_ii->size[0];
  for (i23 = 0; i23 < jj; i23++) {
    minEsp->data[i23] = d_ii->data[i23];
  }

  *NOFP = minEsp->size[0];
  i23 = d_ii->size[0];
  d_ii->size[0] = minEsp->size[0];
  emxEnsureCapacity_int32_T(d_ii, i23);
  jj = minEsp->size[0];
  for (i23 = 0; i23 < jj; i23++) {
    d_ii->data[i23] = DifT->data[(int)minEsp->data[i23] - 1];
  }

  emxFree_int32_T(&DifT);
  *TmNOFP = k_sum(d_ii) / (double)minEsp->size[0];
  *fitness = (((*Tt + k0 * (double)minEsp->size[0]) + k1 * *TmNOFP) + k2 *
              (double)ii->size[0]) + k3 * (double)b_ii->size[0];
  emxFree_int32_T(&d_ii);
  emxFree_int32_T(&b_ii);
  emxFree_int32_T(&ii);
  emxFree_real_T(&minEsp);
}

void favalia(const emxArray_int32_T *schedule, const emxArray_int32_T *DiaOp,
             const emxArray_int32_T *EP, emxArray_int32_T *EspMedOp, double k0,
             double k1, double k2, double k3, double *fitness, double *Tt,
             double *NOFP, double *TmNOFP, double *NOE2, double *NOE3)
{
  emxArray_boolean_T *x;
  int i48;
  int jj;
  int nx;
  emxArray_int32_T *minEsp;
  emxArray_int32_T *DifT;
  emxArray_boolean_T *v;
  int idx;
  emxArray_int32_T *aux;
  int ii;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_int32_T *b_ii;
  unsigned int EspMedOp_idx_0;
  emxArray_int32_T *c_ii;
  emxInit_boolean_T(&x, 2);
  i48 = x->size[0] * x->size[1];
  x->size[0] = schedule->size[0];
  x->size[1] = schedule->size[1];
  emxEnsureCapacity_boolean_T(x, i48);
  jj = schedule->size[0] * schedule->size[1];
  for (i48 = 0; i48 < jj; i48++) {
    x->data[i48] = (schedule->data[i48] != 0);
  }

  nx = x->size[0] * x->size[1];
  emxInit_int32_T(&minEsp, 1);
  emxInit_int32_T(&DifT, 1);
  emxInit_boolean_T(&v, 1);
  if (nx == 0) {
    minEsp->size[0] = 0;
  } else {
    idx = 0;
    i48 = minEsp->size[0];
    minEsp->size[0] = nx;
    emxEnsureCapacity_int32_T(minEsp, i48);
    ii = 1;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= x->size[1])) {
      guard1 = false;
      if (x->data[(ii + x->size[0] * (jj - 1)) - 1]) {
        idx++;
        minEsp->data[idx - 1] = ii;
        if (idx >= nx) {
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        ii++;
        if (ii > x->size[0]) {
          ii = 1;
          jj++;
        }
      }
    }

    if (nx == 1) {
      if (idx == 0) {
        minEsp->size[0] = 0;
      }
    } else {
      i48 = minEsp->size[0];
      if (1 > idx) {
        minEsp->size[0] = 0;
      } else {
        minEsp->size[0] = idx;
      }

      emxEnsureCapacity_int32_T(minEsp, i48);
    }
  }

  emxFree_boolean_T(&x);
  emxInit_int32_T(&aux, 1);
  i48 = aux->size[0];
  aux->size[0] = minEsp->size[0];
  emxEnsureCapacity_int32_T(aux, i48);
  jj = minEsp->size[0];
  for (i48 = 0; i48 < jj; i48++) {
    aux->data[i48] = minEsp->data[i48];
  }

  ii = aux->size[0];
  if (aux->size[0] <= 2) {
    if (aux->size[0] == 1) {
      *Tt = aux->data[0];
    } else if (aux->data[0] < aux->data[1]) {
      *Tt = aux->data[1];
    } else {
      *Tt = aux->data[0];
    }
  } else {
    jj = aux->data[0];
    for (nx = 2; nx <= ii; nx++) {
      if (jj < aux->data[nx - 1]) {
        jj = aux->data[nx - 1];
      }
    }

    *Tt = jj;
  }

  jj = (EspMedOp->size[0] << 1) - 1;
  nx = 0;
  for (idx = 0; idx <= jj; idx++) {
    if (EspMedOp->data[idx] == 0) {
      nx++;
    }
  }

  emxInit_int32_T(&b_ii, 1);
  i48 = b_ii->size[0];
  b_ii->size[0] = nx;
  emxEnsureCapacity_int32_T(b_ii, i48);
  ii = 0;
  for (idx = 0; idx <= jj; idx++) {
    if (EspMedOp->data[idx] == 0) {
      b_ii->data[ii] = idx + 1;
      ii++;
    }
  }

  jj = b_ii->size[0] - 1;
  for (i48 = 0; i48 <= jj; i48++) {
    EspMedOp->data[b_ii->data[i48] - 1] = 5;
  }

  /*  Sustituyo el 0 (caso en que solo era necesario un medico) por un valor mayor para que a la hora de buscar el min no afecte el resultado. */
  ii = EspMedOp->size[0] - 1;
  EspMedOp_idx_0 = (unsigned int)EspMedOp->size[0];
  i48 = minEsp->size[0];
  minEsp->size[0] = (int)EspMedOp_idx_0;
  emxEnsureCapacity_int32_T(minEsp, i48);
  if (EspMedOp->size[0] >= 1) {
    for (idx = 0; idx <= ii; idx++) {
      minEsp->data[idx] = EspMedOp->data[idx];
    }

    for (idx = 0; idx <= ii; idx++) {
      if (minEsp->data[idx] > EspMedOp->data[idx + EspMedOp->size[0]]) {
        minEsp->data[idx] = EspMedOp->data[idx + EspMedOp->size[0]];
      }
    }
  }

  i48 = v->size[0];
  v->size[0] = minEsp->size[0];
  emxEnsureCapacity_boolean_T(v, i48);
  jj = minEsp->size[0];
  for (i48 = 0; i48 < jj; i48++) {
    v->data[i48] = (minEsp->data[i48] == 2);
  }

  emxInit_int32_T(&c_ii, 1);
  nx = v->size[0];
  idx = 0;
  i48 = c_ii->size[0];
  c_ii->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(c_ii, i48);
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (v->data[ii]) {
      idx++;
      c_ii->data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (v->size[0] == 1) {
    if (idx == 0) {
      c_ii->size[0] = 0;
    }
  } else {
    i48 = c_ii->size[0];
    if (1 > idx) {
      c_ii->size[0] = 0;
    } else {
      c_ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(c_ii, i48);
  }

  *NOE2 = c_ii->size[0];
  i48 = v->size[0];
  v->size[0] = minEsp->size[0];
  emxEnsureCapacity_boolean_T(v, i48);
  jj = minEsp->size[0];
  for (i48 = 0; i48 < jj; i48++) {
    v->data[i48] = (minEsp->data[i48] == 3);
  }

  nx = v->size[0];
  idx = 0;
  i48 = minEsp->size[0];
  minEsp->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(minEsp, i48);
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (v->data[ii]) {
      idx++;
      minEsp->data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (v->size[0] == 1) {
    if (idx == 0) {
      minEsp->size[0] = 0;
    }
  } else {
    i48 = minEsp->size[0];
    if (1 > idx) {
      minEsp->size[0] = 0;
    } else {
      minEsp->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(minEsp, i48);
  }

  *NOE3 = minEsp->size[0];
  i48 = DifT->size[0];
  DifT->size[0] = DiaOp->size[0];
  emxEnsureCapacity_int32_T(DifT, i48);
  jj = DiaOp->size[0];
  for (i48 = 0; i48 < jj; i48++) {
    nx = DiaOp->data[i48];
    ii = EP->data[i48];
    if ((nx >= 0) && (ii < nx - MAX_int32_T)) {
      ii = MAX_int32_T;
    } else if ((nx < 0) && (ii > nx - MIN_int32_T)) {
      ii = MIN_int32_T;
    } else {
      ii = nx - ii;
    }

    DifT->data[i48] = ii;
  }

  i48 = v->size[0];
  v->size[0] = DifT->size[0];
  emxEnsureCapacity_boolean_T(v, i48);
  jj = DifT->size[0];
  for (i48 = 0; i48 < jj; i48++) {
    v->data[i48] = (DifT->data[i48] > 0);
  }

  nx = v->size[0];
  idx = 0;
  i48 = b_ii->size[0];
  b_ii->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(b_ii, i48);
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (v->data[ii]) {
      idx++;
      b_ii->data[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  if (v->size[0] == 1) {
    if (idx == 0) {
      b_ii->size[0] = 0;
    }
  } else {
    i48 = b_ii->size[0];
    if (1 > idx) {
      b_ii->size[0] = 0;
    } else {
      b_ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(b_ii, i48);
  }

  emxFree_boolean_T(&v);
  i48 = aux->size[0];
  aux->size[0] = b_ii->size[0];
  emxEnsureCapacity_int32_T(aux, i48);
  jj = b_ii->size[0];
  for (i48 = 0; i48 < jj; i48++) {
    aux->data[i48] = b_ii->data[i48];
  }

  *NOFP = aux->size[0];
  i48 = b_ii->size[0];
  b_ii->size[0] = aux->size[0];
  emxEnsureCapacity_int32_T(b_ii, i48);
  jj = aux->size[0];
  for (i48 = 0; i48 < jj; i48++) {
    b_ii->data[i48] = DifT->data[aux->data[i48] - 1];
  }

  emxFree_int32_T(&DifT);
  *TmNOFP = k_sum(b_ii) / (double)aux->size[0];
  *fitness = (((*Tt + k0 * (double)aux->size[0]) + k1 * *TmNOFP) + k2 * (double)
              c_ii->size[0]) + k3 * (double)minEsp->size[0];
  emxFree_int32_T(&b_ii);
  emxFree_int32_T(&c_ii);
  emxFree_int32_T(&aux);
  emxFree_int32_T(&minEsp);
}

/* End of code generation (favalia.c) */
