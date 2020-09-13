/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: favalia.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 18:10:16
 */

/* Include Files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "favalia.h"
#include "model_emxutil.h"

/* Function Definitions */

/*
 * function [ fitness,Tt,NOFP,TmNOFP,NOE2,NOE3] = favalia( schedule,DiaOp,EP,EspMedOp,k0,k1,k2,k3 )
 * Arguments    : const emxArray_int32_T *schedule
 *                const emxArray_int32_T *DiaOp
 *                const emxArray_int32_T *EP
 *                emxArray_int32_T *EspMedOp
 *                double k0
 *                double k1
 *                double k2
 *                double k3
 *                double *fitness
 *                double *Tt
 *                double *NOFP
 *                double *TmNOFP
 *                double *NOE2
 *                double *NOE3
 * Return Type  : void
 */
void favalia(const emxArray_int32_T *schedule, const emxArray_int32_T *DiaOp,
             const emxArray_int32_T *EP, emxArray_int32_T *EspMedOp, double k0,
             double k1, double k2, double k3, double *fitness, double *Tt,
             double *NOFP, double *TmNOFP, double *NOE2, double *NOE3)
{
  emxArray_boolean_T *x;
  int i10;
  int ii;
  int nx;
  int jj;
  emxArray_int32_T *b_ii;
  emxArray_boolean_T *v;
  emxArray_int32_T *c_ii;
  int idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  emxArray_int32_T *d_ii;
  emxArray_int32_T *minEsp;
  emxArray_int32_T *DifT;
  emxArray_uint32_T *aux;
  double y;
  emxInit_boolean_T(&x, 2);

  /* 'favalia:3' [f,~]=find(schedule~=0); */
  i10 = x->size[0] * x->size[1];
  x->size[0] = schedule->size[0];
  x->size[1] = schedule->size[1];
  emxEnsureCapacity_boolean_T(x, i10);
  ii = schedule->size[1];
  for (i10 = 0; i10 < ii; i10++) {
    jj = schedule->size[0];
    for (nx = 0; nx < jj; nx++) {
      x->data[nx + x->size[0] * i10] = (schedule->data[nx + schedule->size[0] *
        i10] != 0);
    }
  }

  nx = x->size[0] * x->size[1];
  emxInit_int32_T(&b_ii, 1);
  emxInit_boolean_T(&v, 1);
  emxInit_int32_T(&c_ii, 1);
  if (nx == 0) {
    b_ii->size[0] = 0;
  } else {
    idx = 0;
    i10 = b_ii->size[0];
    b_ii->size[0] = nx;
    emxEnsureCapacity_int32_T(b_ii, i10);
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
        if (ii > x->size[0]) {
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
      i10 = b_ii->size[0];
      if (1 > idx) {
        b_ii->size[0] = 0;
      } else {
        b_ii->size[0] = idx;
      }

      emxEnsureCapacity_int32_T(b_ii, i10);
    }
  }

  emxFree_boolean_T(&x);

  /* 'favalia:3' ~ */
  /* 'favalia:4' Tt=max(f,[],1); */
  ii = b_ii->size[0];
  if (b_ii->size[0] <= 2) {
    if (b_ii->size[0] == 0) {
      *Tt = 0.0;
    } else if (b_ii->size[0] == 1) {
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

  /* 'favalia:6' EspMedOp(EspMedOp==0)=int32(5); */
  jj = (EspMedOp->size[0] << 1) - 1;
  ii = 0;
  for (nx = 0; nx <= jj; nx++) {
    if (EspMedOp->data[nx] == 0) {
      ii++;
    }
  }

  emxInit_int32_T(&d_ii, 1);
  i10 = d_ii->size[0];
  d_ii->size[0] = ii;
  emxEnsureCapacity_int32_T(d_ii, i10);
  ii = 0;
  for (nx = 0; nx <= jj; nx++) {
    if (EspMedOp->data[nx] == 0) {
      d_ii->data[ii] = nx + 1;
      ii++;
    }
  }

  ii = d_ii->size[0];
  for (i10 = 0; i10 < ii; i10++) {
    EspMedOp->data[d_ii->data[i10] - 1] = 5;
  }

  emxInit_int32_T(&minEsp, 1);

  /*  Sustituyo el 0 (caso en que solo era necesario un medico) por un valor mayor para que a la hora de buscar el min no afecte el resultado. */
  /* 'favalia:7' minEsp = min(EspMedOp,[],2); */
  jj = EspMedOp->size[0] - 1;
  ii = EspMedOp->size[0];
  i10 = minEsp->size[0];
  minEsp->size[0] = ii;
  emxEnsureCapacity_int32_T(minEsp, i10);
  if (EspMedOp->size[0] >= 1) {
    for (nx = 0; nx <= jj; nx++) {
      minEsp->data[nx] = EspMedOp->data[nx];
    }

    for (nx = 0; nx <= jj; nx++) {
      if (minEsp->data[nx] > EspMedOp->data[nx + EspMedOp->size[0]]) {
        minEsp->data[nx] = EspMedOp->data[nx + EspMedOp->size[0]];
      }
    }
  }

  /* 'favalia:9' NOE2=size(find(minEsp==2),1); */
  i10 = v->size[0];
  v->size[0] = minEsp->size[0];
  emxEnsureCapacity_boolean_T(v, i10);
  ii = minEsp->size[0];
  for (i10 = 0; i10 < ii; i10++) {
    v->data[i10] = (minEsp->data[i10] == 2);
  }

  nx = v->size[0];
  idx = 0;
  i10 = b_ii->size[0];
  b_ii->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(b_ii, i10);
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
    i10 = b_ii->size[0];
    if (1 > idx) {
      b_ii->size[0] = 0;
    } else {
      b_ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(b_ii, i10);
  }

  *NOE2 = b_ii->size[0];

  /* 'favalia:10' NOE3=size(find(minEsp==3),1); */
  i10 = v->size[0];
  v->size[0] = minEsp->size[0];
  emxEnsureCapacity_boolean_T(v, i10);
  ii = minEsp->size[0];
  for (i10 = 0; i10 < ii; i10++) {
    v->data[i10] = (minEsp->data[i10] == 3);
  }

  emxFree_int32_T(&minEsp);
  nx = v->size[0];
  idx = 0;
  i10 = c_ii->size[0];
  c_ii->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(c_ii, i10);
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
    i10 = c_ii->size[0];
    if (1 > idx) {
      c_ii->size[0] = 0;
    } else {
      c_ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(c_ii, i10);
  }

  emxInit_int32_T(&DifT, 1);
  *NOE3 = c_ii->size[0];

  /* 'favalia:12' DifT=DiaOp-EP; */
  i10 = DifT->size[0];
  DifT->size[0] = DiaOp->size[0];
  emxEnsureCapacity_int32_T(DifT, i10);
  ii = DiaOp->size[0];
  for (i10 = 0; i10 < ii; i10++) {
    DifT->data[i10] = DiaOp->data[i10] - EP->data[i10];
  }

  /* 'favalia:14' aux=find(DifT>0); */
  i10 = v->size[0];
  v->size[0] = DifT->size[0];
  emxEnsureCapacity_boolean_T(v, i10);
  ii = DifT->size[0];
  for (i10 = 0; i10 < ii; i10++) {
    v->data[i10] = (DifT->data[i10] > 0);
  }

  nx = v->size[0];
  idx = 0;
  i10 = d_ii->size[0];
  d_ii->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(d_ii, i10);
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (v->data[ii]) {
      idx++;
      d_ii->data[idx - 1] = ii + 1;
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
      d_ii->size[0] = 0;
    }
  } else {
    i10 = d_ii->size[0];
    if (1 > idx) {
      d_ii->size[0] = 0;
    } else {
      d_ii->size[0] = idx;
    }

    emxEnsureCapacity_int32_T(d_ii, i10);
  }

  emxFree_boolean_T(&v);
  emxInit_uint32_T(&aux, 1);
  i10 = aux->size[0];
  aux->size[0] = d_ii->size[0];
  emxEnsureCapacity_uint32_T(aux, i10);
  ii = d_ii->size[0];
  for (i10 = 0; i10 < ii; i10++) {
    aux->data[i10] = (unsigned int)d_ii->data[i10];
  }

  emxFree_int32_T(&d_ii);

  /* 'favalia:15' NOFP = size(aux,1); */
  *NOFP = aux->size[0];

  /* 'favalia:16' TmNOFP = sum(DifT(aux),1)/NOFP; */
  ii = aux->size[0];
  if (aux->size[0] == 0) {
    y = 0.0;
  } else {
    y = DifT->data[(int)aux->data[0] - 1];
    for (nx = 2; nx <= ii; nx++) {
      if (ii >= 2) {
        y += (double)DifT->data[(int)aux->data[nx - 1] - 1];
      }
    }
  }

  emxFree_int32_T(&DifT);
  *TmNOFP = y / (double)aux->size[0];

  /* 'favalia:18' fitness = Tt + k0*NOFP + k1*TmNOFP + k2*NOE2 + k3*NOE3; */
  *fitness = (((*Tt + k0 * (double)aux->size[0]) + k1 * *TmNOFP) + k2 * (double)
              b_ii->size[0]) + k3 * (double)c_ii->size[0];
  emxFree_int32_T(&c_ii);
  emxFree_int32_T(&b_ii);
  emxFree_uint32_T(&aux);
}

/*
 * File trailer for favalia.c
 *
 * [EOF]
 */
