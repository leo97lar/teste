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
  int i16;
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
  i16 = x->size[0] * x->size[1];
  x->size[0] = schedule->size[0];
  x->size[1] = schedule->size[1];
  emxEnsureCapacity_boolean_T(x, i16);
  jj = schedule->size[0] * schedule->size[1];
  for (i16 = 0; i16 < jj; i16++) {
    x->data[i16] = (schedule->data[i16] != 0.0);
  }

  nx = x->size[0] * x->size[1];
  emxInit_boolean_T(&v, 1);
  emxInit_int32_T(&ii, 1);
  emxInit_int32_T(&b_ii, 1);
  if (nx == 0) {
    ii->size[0] = 0;
  } else {
    idx = 0;
    i16 = ii->size[0];
    ii->size[0] = nx;
    emxEnsureCapacity_int32_T(ii, i16);
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
      i16 = ii->size[0];
      if (1 > idx) {
        ii->size[0] = 0;
      } else {
        ii->size[0] = idx;
      }

      emxEnsureCapacity_int32_T(ii, i16);
    }
  }

  emxFree_boolean_T(&x);
  emxInit_real_T(&minEsp, 1);
  i16 = minEsp->size[0];
  minEsp->size[0] = ii->size[0];
  emxEnsureCapacity_real_T(minEsp, i16);
  jj = ii->size[0];
  for (i16 = 0; i16 < jj; i16++) {
    minEsp->data[i16] = ii->data[i16];
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
  i16 = DifT->size[0];
  DifT->size[0] = nx;
  emxEnsureCapacity_int32_T(DifT, i16);
  c_ii = 0;
  for (idx = 0; idx <= jj; idx++) {
    if (EspMedOp->data[idx] == 0.0) {
      DifT->data[c_ii] = idx + 1;
      c_ii++;
    }
  }

  jj = DifT->size[0] - 1;
  for (i16 = 0; i16 <= jj; i16++) {
    EspMedOp->data[DifT->data[i16] - 1] = 5.0;
  }

  /*  Sustituyo el 0 (caso en que solo era necesario un medico) por un valor mayor para que a la hora de buscar el min no afecte el resultado. */
  c_ii = EspMedOp->size[0] - 1;
  EspMedOp_idx_0 = (unsigned int)EspMedOp->size[0];
  i16 = minEsp->size[0];
  minEsp->size[0] = (int)EspMedOp_idx_0;
  emxEnsureCapacity_real_T(minEsp, i16);
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

  i16 = v->size[0];
  v->size[0] = minEsp->size[0];
  emxEnsureCapacity_boolean_T(v, i16);
  jj = minEsp->size[0];
  for (i16 = 0; i16 < jj; i16++) {
    v->data[i16] = (minEsp->data[i16] == 2.0);
  }

  nx = v->size[0];
  idx = 0;
  i16 = ii->size[0];
  ii->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(ii, i16);
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
    i16 = ii->size[0];
    if (1 > idx) {
      ii->size[0] = 0;
    } else {
      ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(ii, i16);
  }

  *NOE2 = ii->size[0];
  i16 = v->size[0];
  v->size[0] = minEsp->size[0];
  emxEnsureCapacity_boolean_T(v, i16);
  jj = minEsp->size[0];
  for (i16 = 0; i16 < jj; i16++) {
    v->data[i16] = (minEsp->data[i16] == 3.0);
  }

  nx = v->size[0];
  idx = 0;
  i16 = b_ii->size[0];
  b_ii->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(b_ii, i16);
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
    i16 = b_ii->size[0];
    if (1 > idx) {
      b_ii->size[0] = 0;
    } else {
      b_ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(b_ii, i16);
  }

  *NOE3 = b_ii->size[0];
  i16 = DifT->size[0];
  DifT->size[0] = DiaOp->size[0];
  emxEnsureCapacity_int32_T(DifT, i16);
  jj = DiaOp->size[0];
  for (i16 = 0; i16 < jj; i16++) {
    nx = DiaOp->data[i16];
    c_ii = EP->data[i16];
    if ((nx >= 0) && (c_ii < nx - MAX_int32_T)) {
      c_ii = MAX_int32_T;
    } else if ((nx < 0) && (c_ii > nx - MIN_int32_T)) {
      c_ii = MIN_int32_T;
    } else {
      c_ii = nx - c_ii;
    }

    DifT->data[i16] = c_ii;
  }

  i16 = v->size[0];
  v->size[0] = DifT->size[0];
  emxEnsureCapacity_boolean_T(v, i16);
  jj = DifT->size[0];
  for (i16 = 0; i16 < jj; i16++) {
    v->data[i16] = (DifT->data[i16] > 0);
  }

  emxInit_int32_T(&d_ii, 1);
  nx = v->size[0];
  idx = 0;
  i16 = d_ii->size[0];
  d_ii->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(d_ii, i16);
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
    i16 = d_ii->size[0];
    if (1 > idx) {
      d_ii->size[0] = 0;
    } else {
      d_ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(d_ii, i16);
  }

  emxFree_boolean_T(&v);
  i16 = minEsp->size[0];
  minEsp->size[0] = d_ii->size[0];
  emxEnsureCapacity_real_T(minEsp, i16);
  jj = d_ii->size[0];
  for (i16 = 0; i16 < jj; i16++) {
    minEsp->data[i16] = d_ii->data[i16];
  }

  *NOFP = minEsp->size[0];
  i16 = d_ii->size[0];
  d_ii->size[0] = minEsp->size[0];
  emxEnsureCapacity_int32_T(d_ii, i16);
  jj = minEsp->size[0];
  for (i16 = 0; i16 < jj; i16++) {
    d_ii->data[i16] = DifT->data[(int)minEsp->data[i16] - 1];
  }

  emxFree_int32_T(&DifT);
  *TmNOFP = j_sum(d_ii) / (double)minEsp->size[0];
  *fitness = (((*Tt + k0 * (double)minEsp->size[0]) + k1 * *TmNOFP) + k2 *
              (double)ii->size[0]) + k3 * (double)b_ii->size[0];
  emxFree_int32_T(&d_ii);
  emxFree_int32_T(&b_ii);
  emxFree_int32_T(&ii);
  emxFree_real_T(&minEsp);
}

void c_favalia(const emxArray_int32_T *schedule, const int DiaOp_data[], const
               int EP_data[], int EspMedOp_data[], double *fitness, double *Tt,
               double *NOFP, double *TmNOFP, double *NOE2, double *NOE3)
{
  emxArray_boolean_T *x;
  int jj;
  int ii;
  int nx;
  emxArray_boolean_T *v;
  emxArray_int32_T *b_ii;
  int idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  int DifT_data[2000];
  int DifT_size[1];
  emxArray_int32_T b_DifT_data;
  int c_DifT_data[2000];
  emxInit_boolean_T(&x, 2);
  jj = x->size[0] * x->size[1];
  x->size[0] = 17520;
  x->size[1] = schedule->size[1];
  emxEnsureCapacity_boolean_T(x, jj);
  ii = schedule->size[0] * schedule->size[1];
  for (jj = 0; jj < ii; jj++) {
    x->data[jj] = (schedule->data[jj] != 0);
  }

  nx = 17520 * x->size[1];
  emxInit_boolean_T(&v, 1);
  emxInit_int32_T(&b_ii, 1);
  if (nx == 0) {
    b_ii->size[0] = 0;
  } else {
    idx = 0;
    jj = b_ii->size[0];
    b_ii->size[0] = nx;
    emxEnsureCapacity_int32_T(b_ii, jj);
    ii = 1;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= x->size[1])) {
      guard1 = false;
      if (x->data[(ii + x->size[0] * (jj - 1)) - 1]) {
        idx++;
        b_ii->data[idx - 1] = ii;
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
        if (ii > 17520) {
          ii = 1;
          jj++;
        }
      }
    }

    if (nx == 1) {
      if (idx == 0) {
        b_ii->size[0] = 0;
      }
    } else {
      jj = b_ii->size[0];
      if (1 > idx) {
        b_ii->size[0] = 0;
      } else {
        b_ii->size[0] = idx;
      }

      emxEnsureCapacity_int32_T(b_ii, jj);
    }
  }

  emxFree_boolean_T(&x);
  ii = b_ii->size[0];
  if (b_ii->size[0] <= 2) {
    if (b_ii->size[0] == 1) {
      *Tt = b_ii->data[0];
    } else if (b_ii->data[0] < b_ii->data[1]) {
      *Tt = b_ii->data[1];
    } else {
      *Tt = b_ii->data[0];
    }
  } else {
    jj = b_ii->data[0];
    for (nx = 2; nx <= ii; nx++) {
      if (jj < b_ii->data[nx - 1]) {
        jj = b_ii->data[nx - 1];
      }
    }

    *Tt = jj;
  }

  for (ii = 0; ii < 4000; ii++) {
    if (EspMedOp_data[ii] == 0) {
      EspMedOp_data[ii] = 5;
    }
  }

  /*  Sustituyo el 0 (caso en que solo era necesario un medico) por un valor mayor para que a la hora de buscar el min no afecte el resultado. */
  jj = b_ii->size[0];
  b_ii->size[0] = 2000;
  emxEnsureCapacity_int32_T(b_ii, jj);
  for (ii = 0; ii < 2000; ii++) {
    b_ii->data[ii] = EspMedOp_data[ii];
  }

  for (ii = 0; ii < 2000; ii++) {
    jj = EspMedOp_data[ii + 2000];
    if (b_ii->data[ii] > jj) {
      b_ii->data[ii] = jj;
    }
  }

  ii = b_ii->size[0];
  for (jj = 0; jj < ii; jj++) {
    DifT_data[jj] = b_ii->data[jj];
  }

  jj = v->size[0];
  v->size[0] = 2000;
  emxEnsureCapacity_boolean_T(v, jj);
  for (jj = 0; jj < 2000; jj++) {
    v->data[jj] = (DifT_data[jj] == 2);
  }

  idx = 0;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= 1999)) {
    if (v->data[ii]) {
      idx++;
      if (idx >= 2000) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  jj = b_ii->size[0];
  if (1 > idx) {
    b_ii->size[0] = 0;
  } else {
    b_ii->size[0] = idx;
  }

  emxEnsureCapacity_int32_T(b_ii, jj);
  *NOE2 = b_ii->size[0];
  jj = v->size[0];
  v->size[0] = 2000;
  emxEnsureCapacity_boolean_T(v, jj);
  for (jj = 0; jj < 2000; jj++) {
    v->data[jj] = (DifT_data[jj] == 3);
  }

  idx = 0;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= 1999)) {
    if (v->data[ii]) {
      idx++;
      if (idx >= 2000) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  jj = b_ii->size[0];
  if (1 > idx) {
    b_ii->size[0] = 0;
  } else {
    b_ii->size[0] = idx;
  }

  emxEnsureCapacity_int32_T(b_ii, jj);
  *NOE3 = b_ii->size[0];
  for (jj = 0; jj < 2000; jj++) {
    if ((DiaOp_data[jj] >= 0) && (EP_data[jj] < DiaOp_data[jj] - MAX_int32_T)) {
      ii = MAX_int32_T;
    } else if ((DiaOp_data[jj] < 0) && (EP_data[jj] > DiaOp_data[jj] -
                MIN_int32_T)) {
      ii = MIN_int32_T;
    } else {
      ii = DiaOp_data[jj] - EP_data[jj];
    }

    DifT_data[jj] = ii;
  }

  jj = v->size[0];
  v->size[0] = 2000;
  emxEnsureCapacity_boolean_T(v, jj);
  for (jj = 0; jj < 2000; jj++) {
    v->data[jj] = (DifT_data[jj] > 0);
  }

  idx = 0;
  jj = b_ii->size[0];
  b_ii->size[0] = 2000;
  emxEnsureCapacity_int32_T(b_ii, jj);
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= 1999)) {
    if (v->data[ii]) {
      idx++;
      b_ii->data[idx - 1] = ii + 1;
      if (idx >= 2000) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }

  emxFree_boolean_T(&v);
  jj = b_ii->size[0];
  if (1 > idx) {
    b_ii->size[0] = 0;
  } else {
    b_ii->size[0] = idx;
  }

  emxEnsureCapacity_int32_T(b_ii, jj);
  *NOFP = b_ii->size[0];
  DifT_size[0] = b_ii->size[0];
  ii = b_ii->size[0];
  for (jj = 0; jj < ii; jj++) {
    c_DifT_data[jj] = DifT_data[b_ii->data[jj] - 1];
  }

  b_DifT_data.data = &c_DifT_data[0];
  b_DifT_data.size = &DifT_size[0];
  b_DifT_data.allocatedSize = 2000;
  b_DifT_data.numDimensions = 1;
  b_DifT_data.canFreeData = false;
  *TmNOFP = j_sum(&b_DifT_data) / (double)b_ii->size[0];
  *fitness = *Tt;
  emxFree_int32_T(&b_ii);
}

void favalia(const emxArray_int32_T *schedule, const emxArray_int32_T *DiaOp,
             const emxArray_int32_T *EP, emxArray_int32_T *EspMedOp, double k0,
             double k1, double k2, double k3, double *fitness, double *Tt,
             double *NOFP, double *TmNOFP, double *NOE2, double *NOE3)
{
  emxArray_boolean_T *x;
  int i39;
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
  i39 = x->size[0] * x->size[1];
  x->size[0] = schedule->size[0];
  x->size[1] = schedule->size[1];
  emxEnsureCapacity_boolean_T(x, i39);
  jj = schedule->size[0] * schedule->size[1];
  for (i39 = 0; i39 < jj; i39++) {
    x->data[i39] = (schedule->data[i39] != 0);
  }

  nx = x->size[0] * x->size[1];
  emxInit_int32_T(&minEsp, 1);
  emxInit_int32_T(&DifT, 1);
  emxInit_boolean_T(&v, 1);
  if (nx == 0) {
    minEsp->size[0] = 0;
  } else {
    idx = 0;
    i39 = minEsp->size[0];
    minEsp->size[0] = nx;
    emxEnsureCapacity_int32_T(minEsp, i39);
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
      i39 = minEsp->size[0];
      if (1 > idx) {
        minEsp->size[0] = 0;
      } else {
        minEsp->size[0] = idx;
      }

      emxEnsureCapacity_int32_T(minEsp, i39);
    }
  }

  emxFree_boolean_T(&x);
  emxInit_int32_T(&aux, 1);
  i39 = aux->size[0];
  aux->size[0] = minEsp->size[0];
  emxEnsureCapacity_int32_T(aux, i39);
  jj = minEsp->size[0];
  for (i39 = 0; i39 < jj; i39++) {
    aux->data[i39] = minEsp->data[i39];
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
  i39 = b_ii->size[0];
  b_ii->size[0] = nx;
  emxEnsureCapacity_int32_T(b_ii, i39);
  ii = 0;
  for (idx = 0; idx <= jj; idx++) {
    if (EspMedOp->data[idx] == 0) {
      b_ii->data[ii] = idx + 1;
      ii++;
    }
  }

  jj = b_ii->size[0] - 1;
  for (i39 = 0; i39 <= jj; i39++) {
    EspMedOp->data[b_ii->data[i39] - 1] = 5;
  }

  /*  Sustituyo el 0 (caso en que solo era necesario un medico) por un valor mayor para que a la hora de buscar el min no afecte el resultado. */
  ii = EspMedOp->size[0] - 1;
  EspMedOp_idx_0 = (unsigned int)EspMedOp->size[0];
  i39 = minEsp->size[0];
  minEsp->size[0] = (int)EspMedOp_idx_0;
  emxEnsureCapacity_int32_T(minEsp, i39);
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

  i39 = v->size[0];
  v->size[0] = minEsp->size[0];
  emxEnsureCapacity_boolean_T(v, i39);
  jj = minEsp->size[0];
  for (i39 = 0; i39 < jj; i39++) {
    v->data[i39] = (minEsp->data[i39] == 2);
  }

  emxInit_int32_T(&c_ii, 1);
  nx = v->size[0];
  idx = 0;
  i39 = c_ii->size[0];
  c_ii->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(c_ii, i39);
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
    i39 = c_ii->size[0];
    if (1 > idx) {
      c_ii->size[0] = 0;
    } else {
      c_ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(c_ii, i39);
  }

  *NOE2 = c_ii->size[0];
  i39 = v->size[0];
  v->size[0] = minEsp->size[0];
  emxEnsureCapacity_boolean_T(v, i39);
  jj = minEsp->size[0];
  for (i39 = 0; i39 < jj; i39++) {
    v->data[i39] = (minEsp->data[i39] == 3);
  }

  nx = v->size[0];
  idx = 0;
  i39 = minEsp->size[0];
  minEsp->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(minEsp, i39);
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
    i39 = minEsp->size[0];
    if (1 > idx) {
      minEsp->size[0] = 0;
    } else {
      minEsp->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(minEsp, i39);
  }

  *NOE3 = minEsp->size[0];
  i39 = DifT->size[0];
  DifT->size[0] = DiaOp->size[0];
  emxEnsureCapacity_int32_T(DifT, i39);
  jj = DiaOp->size[0];
  for (i39 = 0; i39 < jj; i39++) {
    nx = DiaOp->data[i39];
    ii = EP->data[i39];
    if ((nx >= 0) && (ii < nx - MAX_int32_T)) {
      ii = MAX_int32_T;
    } else if ((nx < 0) && (ii > nx - MIN_int32_T)) {
      ii = MIN_int32_T;
    } else {
      ii = nx - ii;
    }

    DifT->data[i39] = ii;
  }

  i39 = v->size[0];
  v->size[0] = DifT->size[0];
  emxEnsureCapacity_boolean_T(v, i39);
  jj = DifT->size[0];
  for (i39 = 0; i39 < jj; i39++) {
    v->data[i39] = (DifT->data[i39] > 0);
  }

  nx = v->size[0];
  idx = 0;
  i39 = b_ii->size[0];
  b_ii->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(b_ii, i39);
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
    i39 = b_ii->size[0];
    if (1 > idx) {
      b_ii->size[0] = 0;
    } else {
      b_ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(b_ii, i39);
  }

  emxFree_boolean_T(&v);
  i39 = aux->size[0];
  aux->size[0] = b_ii->size[0];
  emxEnsureCapacity_int32_T(aux, i39);
  jj = b_ii->size[0];
  for (i39 = 0; i39 < jj; i39++) {
    aux->data[i39] = b_ii->data[i39];
  }

  *NOFP = aux->size[0];
  i39 = b_ii->size[0];
  b_ii->size[0] = aux->size[0];
  emxEnsureCapacity_int32_T(b_ii, i39);
  jj = aux->size[0];
  for (i39 = 0; i39 < jj; i39++) {
    b_ii->data[i39] = DifT->data[aux->data[i39] - 1];
  }

  emxFree_int32_T(&DifT);
  *TmNOFP = j_sum(b_ii) / (double)aux->size[0];
  *fitness = (((*Tt + k0 * (double)aux->size[0]) + k1 * *TmNOFP) + k2 * (double)
              c_ii->size[0]) + k3 * (double)minEsp->size[0];
  emxFree_int32_T(&b_ii);
  emxFree_int32_T(&c_ii);
  emxFree_int32_T(&aux);
  emxFree_int32_T(&minEsp);
}

/* End of code generation (favalia.c) */
