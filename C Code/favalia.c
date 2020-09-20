/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: favalia.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
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
  int i15;
  int ii;
  int nx;
  int jj;
  emxArray_int32_T *b_ii;
  int i16;
  emxArray_boolean_T *v;
  emxArray_int32_T *r9;
  emxArray_int32_T *c_ii;
  int idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T b4;
  boolean_T b5;
  emxArray_int32_T *d_ii;
  emxArray_int32_T *minEsp;
  emxArray_int32_T *DifT;
  emxArray_uint32_T *aux;
  emxArray_int32_T *e_ii;
  double y;
  emxInit_boolean_T(&x, 2);

  /* 'favalia:3' [f,~]=find(schedule~=0); */
  i15 = x->size[0] * x->size[1];
  x->size[1] = schedule->size[1];
  x->size[0] = schedule->size[0];
  emxEnsureCapacity_boolean_T(x, i15);
  ii = schedule->size[0];
  for (i15 = 0; i15 < ii; i15++) {
    jj = schedule->size[1];
    for (i16 = 0; i16 < jj; i16++) {
      x->data[i16 + x->size[1] * i15] = (schedule->data[i16 + schedule->size[1] *
        i15] != 0);
    }
  }

  nx = x->size[0] * x->size[1];
  emxInit_int32_T(&b_ii, 1);
  emxInit_boolean_T(&v, 1);
  emxInit_int32_T(&r9, 1);
  emxInit_int32_T(&c_ii, 1);
  if (nx == 0) {
    b_ii->size[0] = 0;
  } else {
    idx = 0;
    i15 = b_ii->size[0];
    b_ii->size[0] = nx;
    emxEnsureCapacity_int32_T(b_ii, i15);
    ii = 1;
    jj = 1;
    exitg1 = false;
    while ((!exitg1) && (jj <= x->size[1])) {
      guard1 = false;
      if (x->data[(jj + x->size[1] * (ii - 1)) - 1]) {
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
      if (1 > idx) {
        ii = 0;
      } else {
        ii = idx;
      }

      i15 = r9->size[0];
      r9->size[0] = ii;
      emxEnsureCapacity_int32_T(r9, i15);
      for (i15 = 0; i15 < ii; i15++) {
        r9->data[i15] = i15;
      }

      ii = r9->size[0];
      i15 = c_ii->size[0];
      c_ii->size[0] = ii;
      emxEnsureCapacity_int32_T(c_ii, i15);
      for (i15 = 0; i15 < ii; i15++) {
        c_ii->data[i15] = b_ii->data[r9->data[i15]];
      }

      i15 = b_ii->size[0];
      b_ii->size[0] = c_ii->size[0];
      emxEnsureCapacity_int32_T(b_ii, i15);
      ii = c_ii->size[0];
      for (i15 = 0; i15 < ii; i15++) {
        b_ii->data[i15] = c_ii->data[i15];
      }
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
  b4 = true;
  b5 = (EspMedOp->size[0] <= 0);
  i15 = EspMedOp->size[0] << 1;
  i16 = 0;
  for (idx = 0; idx <= jj; idx++) {
    if (b5 || (idx >= i15)) {
      i16 = 0;
      b4 = true;
    } else if (b4) {
      b4 = false;
      i16 = EspMedOp->size[0];
      i16 = ((idx % i16) << 1) + idx / i16;
    } else {
      nx = (EspMedOp->size[0] << 1) - 1;
      if (i16 > 2147483645) {
        i16 = EspMedOp->size[0];
        i16 = ((idx % i16) << 1) + idx / i16;
      } else {
        i16 += 2;
        if (i16 > nx) {
          i16 -= nx;
        }
      }
    }

    if (EspMedOp->data[i16] == 0) {
      ii++;
    }
  }

  emxInit_int32_T(&d_ii, 1);
  i15 = d_ii->size[0];
  d_ii->size[0] = ii;
  emxEnsureCapacity_int32_T(d_ii, i15);
  ii = 0;
  b4 = true;
  b5 = (EspMedOp->size[0] <= 0);
  i15 = EspMedOp->size[0] << 1;
  i16 = 0;
  for (idx = 0; idx <= jj; idx++) {
    if (b5 || (idx >= i15)) {
      i16 = 0;
      b4 = true;
    } else if (b4) {
      b4 = false;
      i16 = EspMedOp->size[0];
      i16 = ((idx % i16) << 1) + idx / i16;
    } else {
      nx = (EspMedOp->size[0] << 1) - 1;
      if (i16 > 2147483645) {
        i16 = EspMedOp->size[0];
        i16 = ((idx % i16) << 1) + idx / i16;
      } else {
        i16 += 2;
        if (i16 > nx) {
          i16 -= nx;
        }
      }
    }

    if (EspMedOp->data[i16] == 0) {
      d_ii->data[ii] = idx + 1;
      ii++;
    }
  }

  i15 = r9->size[0];
  r9->size[0] = d_ii->size[0];
  emxEnsureCapacity_int32_T(r9, i15);
  ii = d_ii->size[0];
  for (i15 = 0; i15 < ii; i15++) {
    r9->data[i15] = d_ii->data[i15] - 1;
  }

  i15 = EspMedOp->size[0];
  ii = d_ii->size[0];
  for (i16 = 0; i16 < ii; i16++) {
    EspMedOp->data[((r9->data[i16] % i15) << 1) + r9->data[i16] / i15] = 5;
  }

  emxInit_int32_T(&minEsp, 1);

  /*  Sustituyo el 0 (caso en que solo era necesario un medico) por un valor mayor para que a la hora de buscar el min no afecte el resultado. */
  /* 'favalia:7' minEsp = min(EspMedOp,[],2); */
  jj = EspMedOp->size[0];
  ii = EspMedOp->size[0];
  i15 = minEsp->size[0];
  minEsp->size[0] = ii;
  emxEnsureCapacity_int32_T(minEsp, i15);
  if (EspMedOp->size[0] >= 1) {
    for (idx = 0; idx < jj; idx++) {
      i15 = idx << 1;
      minEsp->data[idx] = EspMedOp->data[i15];
      i15++;
      if (minEsp->data[idx] > EspMedOp->data[i15]) {
        minEsp->data[idx] = EspMedOp->data[i15];
      }
    }
  }

  /* 'favalia:9' NOE2=size(find(minEsp==2),1); */
  i15 = v->size[0];
  v->size[0] = minEsp->size[0];
  emxEnsureCapacity_boolean_T(v, i15);
  ii = minEsp->size[0];
  for (i15 = 0; i15 < ii; i15++) {
    v->data[i15] = (minEsp->data[i15] == 2);
  }

  nx = v->size[0];
  idx = 0;
  i15 = b_ii->size[0];
  b_ii->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(b_ii, i15);
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
    if (1 > idx) {
      ii = 0;
    } else {
      ii = idx;
    }

    i15 = r9->size[0];
    r9->size[0] = ii;
    emxEnsureCapacity_int32_T(r9, i15);
    for (i15 = 0; i15 < ii; i15++) {
      r9->data[i15] = i15;
    }

    ii = r9->size[0];
    i15 = c_ii->size[0];
    c_ii->size[0] = ii;
    emxEnsureCapacity_int32_T(c_ii, i15);
    for (i15 = 0; i15 < ii; i15++) {
      c_ii->data[i15] = b_ii->data[r9->data[i15]];
    }

    i15 = b_ii->size[0];
    b_ii->size[0] = c_ii->size[0];
    emxEnsureCapacity_int32_T(b_ii, i15);
    ii = c_ii->size[0];
    for (i15 = 0; i15 < ii; i15++) {
      b_ii->data[i15] = c_ii->data[i15];
    }
  }

  *NOE2 = b_ii->size[0];

  /* 'favalia:10' NOE3=size(find(minEsp==3),1); */
  i15 = v->size[0];
  v->size[0] = minEsp->size[0];
  emxEnsureCapacity_boolean_T(v, i15);
  ii = minEsp->size[0];
  for (i15 = 0; i15 < ii; i15++) {
    v->data[i15] = (minEsp->data[i15] == 3);
  }

  emxFree_int32_T(&minEsp);
  nx = v->size[0];
  idx = 0;
  i15 = c_ii->size[0];
  c_ii->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(c_ii, i15);
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
    if (1 > idx) {
      ii = 0;
    } else {
      ii = idx;
    }

    i15 = r9->size[0];
    r9->size[0] = ii;
    emxEnsureCapacity_int32_T(r9, i15);
    for (i15 = 0; i15 < ii; i15++) {
      r9->data[i15] = i15;
    }

    ii = r9->size[0];
    i15 = d_ii->size[0];
    d_ii->size[0] = ii;
    emxEnsureCapacity_int32_T(d_ii, i15);
    for (i15 = 0; i15 < ii; i15++) {
      d_ii->data[i15] = c_ii->data[r9->data[i15]];
    }

    i15 = c_ii->size[0];
    c_ii->size[0] = d_ii->size[0];
    emxEnsureCapacity_int32_T(c_ii, i15);
    ii = d_ii->size[0];
    for (i15 = 0; i15 < ii; i15++) {
      c_ii->data[i15] = d_ii->data[i15];
    }
  }

  emxInit_int32_T(&DifT, 1);
  *NOE3 = c_ii->size[0];

  /* 'favalia:12' DifT=DiaOp-EP; */
  i15 = DifT->size[0];
  DifT->size[0] = DiaOp->size[0];
  emxEnsureCapacity_int32_T(DifT, i15);
  ii = DiaOp->size[0];
  for (i15 = 0; i15 < ii; i15++) {
    DifT->data[i15] = DiaOp->data[i15] - EP->data[i15];
  }

  /* 'favalia:14' aux=find(DifT>0); */
  i15 = v->size[0];
  v->size[0] = DifT->size[0];
  emxEnsureCapacity_boolean_T(v, i15);
  ii = DifT->size[0];
  for (i15 = 0; i15 < ii; i15++) {
    v->data[i15] = (DifT->data[i15] > 0);
  }

  nx = v->size[0];
  idx = 0;
  i15 = d_ii->size[0];
  d_ii->size[0] = v->size[0];
  emxEnsureCapacity_int32_T(d_ii, i15);
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
    if (1 > idx) {
      ii = 0;
    } else {
      ii = idx;
    }

    i15 = r9->size[0];
    r9->size[0] = ii;
    emxEnsureCapacity_int32_T(r9, i15);
    for (i15 = 0; i15 < ii; i15++) {
      r9->data[i15] = i15;
    }

    emxInit_int32_T(&e_ii, 1);
    ii = r9->size[0];
    i15 = e_ii->size[0];
    e_ii->size[0] = ii;
    emxEnsureCapacity_int32_T(e_ii, i15);
    for (i15 = 0; i15 < ii; i15++) {
      e_ii->data[i15] = d_ii->data[r9->data[i15]];
    }

    i15 = d_ii->size[0];
    d_ii->size[0] = e_ii->size[0];
    emxEnsureCapacity_int32_T(d_ii, i15);
    ii = e_ii->size[0];
    for (i15 = 0; i15 < ii; i15++) {
      d_ii->data[i15] = e_ii->data[i15];
    }

    emxFree_int32_T(&e_ii);
  }

  emxFree_int32_T(&r9);
  emxFree_boolean_T(&v);
  emxInit_uint32_T(&aux, 1);
  i15 = aux->size[0];
  aux->size[0] = d_ii->size[0];
  emxEnsureCapacity_uint32_T(aux, i15);
  ii = d_ii->size[0];
  for (i15 = 0; i15 < ii; i15++) {
    aux->data[i15] = (unsigned int)d_ii->data[i15];
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
