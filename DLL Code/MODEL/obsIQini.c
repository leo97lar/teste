/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: obsIQini.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
#include "pch.h"

#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "obsIQini.h"
#include "model_emxutil.h"
#include "rdivide_helper.h"
#include "sum.h"
#include "rand.h"
#include "repmat.h"
#include "model_rtwutil.h"

/* Function Definitions */

/*
 * function [ newIC ] = obsIQini( IQ,numIQ,numObsIQ,ProbXEst)
 * UNTITLED7 Summary of this function goes here
 *    Detailed explanation goes here,
 * Arguments    : const emxArray_real_T *IQ
 *                int numIQ
 *                int numObsIQ
 *                const emxArray_real_T *ProbXEst
 *                emxArray_int32_T *newIC
 * Return Type  : void
 */
void obsIQini(const emxArray_real_T *IQ, int numIQ, int numObsIQ, const
              emxArray_real_T *ProbXEst, emxArray_int32_T *newIC)
{
  emxArray_int32_T *Lim;
  int numGen;
  int b_ProbXEst[2];
  int i22;
  int ii;
  emxArray_int32_T *r13;
  emxArray_real_T *c_ProbXEst;
  int g;
  emxArray_real_T *List;
  int idx;
  int jj;
  emxArray_real_T *r14;
  int loop_ub;
  emxArray_real_T *Q;
  emxArray_int8_T *Obs;
  emxArray_real_T *Qtem;
  emxArray_real_T *b_idx;
  emxArray_real_T *Qtem2;
  emxArray_real_T *r15;
  emxArray_real_T *r16;
  emxArray_real_T *b_Qtem;
  emxArray_boolean_T *x;
  emxArray_int32_T *b_ii;
  emxArray_boolean_T *b_x;
  emxArray_int32_T *c_ii;
  emxArray_real_T *c_Qtem;
  emxArray_int32_T *d_ii;
  emxArray_int32_T *e_ii;
  int k;
  int nx;
  int u;
  unsigned int unnamed_idx_0;
  unsigned int unnamed_idx_1;
  int i;
  double Pmax;
  boolean_T exitg1;
  boolean_T guard1 = false;
  unsigned int d_Qtem[2];
  double r;
  int j;
  emxInit_int32_T(&Lim, 2);

  /* 'obsIQini:4' numGen=size(IQ,1)/numIQ; */
  numGen = (int)rt_roundd((double)IQ->size[0] / (double)numIQ);

  /* 'obsIQini:5' Lim=zeros(1,length(ProbXEst)); */
  b_ProbXEst[0] = ProbXEst->size[0];
  i22 = Lim->size[0] * Lim->size[1];
  Lim->size[1] = b_ProbXEst[0];
  Lim->size[0] = 1;
  emxEnsureCapacity_int32_T(Lim, i22);
  ii = b_ProbXEst[0];
  for (i22 = 0; i22 < ii; i22++) {
    Lim->data[i22] = 0;
  }

  /* 'obsIQini:7' for g=1:length(ProbXEst) */
  i22 = ProbXEst->size[0];
  emxInit_int32_T(&r13, 1);
  emxInit_real_T(&c_ProbXEst, 1);
  for (g = 0; g < i22; g++) {
    /* 'obsIQini:8' Lim(g) = numGen*sum(ProbXEst(1:g),1)/100; */
    idx = r13->size[0];
    r13->size[0] = g + 1;
    emxEnsureCapacity_int32_T(r13, idx);
    for (idx = 0; idx <= g; idx++) {
      r13->data[idx] = idx;
    }

    jj = r13->size[0];
    idx = c_ProbXEst->size[0];
    c_ProbXEst->size[0] = jj;
    emxEnsureCapacity_real_T(c_ProbXEst, idx);
    for (idx = 0; idx < jj; idx++) {
      c_ProbXEst->data[idx] = ProbXEst->data[r13->data[idx]];
    }

    Lim->data[g] = (int)rt_roundd((double)(int)rt_roundd((double)numGen * b_sum
      (c_ProbXEst)) / 100.0);
  }

  emxInit_real_T(&List, 2);

  /* 'obsIQini:11' List = zeros(numGen,numObsIQ); */
  i22 = List->size[0] * List->size[1];
  List->size[1] = numObsIQ;
  List->size[0] = numGen;
  emxEnsureCapacity_real_T(List, i22);
  for (i22 = 0; i22 < numGen; i22++) {
    for (idx = 0; idx < numObsIQ; idx++) {
      List->data[idx + List->size[1] * i22] = 0.0;
    }
  }

  emxInit_real_T(&r14, 2);

  /* 'obsIQini:12' newIC = int32(repmat(List,1,numIQ)); */
  repmat(List, numIQ, r14);
  i22 = newIC->size[0] * newIC->size[1];
  newIC->size[1] = r14->size[1];
  newIC->size[0] = r14->size[0];
  emxEnsureCapacity_int32_T(newIC, i22);
  ii = r14->size[0];
  for (i22 = 0; i22 < ii; i22++) {
    loop_ub = r14->size[1];
    for (idx = 0; idx < loop_ub; idx++) {
      newIC->data[idx + newIC->size[1] * i22] = (int)rt_roundd(r14->data[idx +
        r14->size[1] * i22]);
    }
  }

  emxFree_real_T(&r14);

  /* 'obsIQini:14' for k=1:numIQ */
  emxInit_real_T(&Q, 2);
  emxInit_int8_T(&Obs, 2);
  emxInit_real_T(&Qtem, 2);
  emxInit_real_T(&b_idx, 2);
  emxInit_real_T(&Qtem2, 2);
  emxInit_real_T(&r15, 1);
  emxInit_real_T(&r16, 1);
  emxInit_real_T(&b_Qtem, 1);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&b_ii, 2);
  emxInit_boolean_T(&b_x, 2);
  emxInit_int32_T(&c_ii, 1);
  emxInit_real_T(&c_Qtem, 2);
  emxInit_int32_T(&d_ii, 1);
  emxInit_int32_T(&e_ii, 2);
  for (k = 0; k < numIQ; k++) {
    /* 'obsIQini:16' Q = IQ((k-1)*numGen+1:k*numGen,:); */
    i22 = k * numGen;
    idx = (k + 1) * numGen;
    if (i22 + 1 > idx) {
      i22 = 0;
      idx = 0;
    }

    ii = IQ->size[1];
    nx = Q->size[0] * Q->size[1];
    Q->size[1] = ii;
    loop_ub = idx - i22;
    Q->size[0] = loop_ub;
    emxEnsureCapacity_real_T(Q, nx);
    for (idx = 0; idx < loop_ub; idx++) {
      for (nx = 0; nx < ii; nx++) {
        Q->data[nx + Q->size[1] * idx] = IQ->data[nx + IQ->size[1] * (i22 + idx)];
      }
    }

    /* 'obsIQini:18' for u=1:numObsIQ */
    for (u = 0; u < numObsIQ; u++) {
      /* 'obsIQini:20' Obs = zeros(size(Q)); */
      i22 = IQ->size[1];
      unnamed_idx_0 = (unsigned int)loop_ub;
      unnamed_idx_1 = (unsigned int)i22;
      i22 = Obs->size[0] * Obs->size[1];
      Obs->size[1] = (int)unnamed_idx_1;
      Obs->size[0] = (int)unnamed_idx_0;
      emxEnsureCapacity_int8_T(Obs, i22);
      ii = (int)unnamed_idx_0;
      for (i22 = 0; i22 < ii; i22++) {
        jj = (int)unnamed_idx_1;
        for (idx = 0; idx < jj; idx++) {
          Obs->data[idx + Obs->size[1] * i22] = 0;
        }
      }

      /* 'obsIQini:21' Qtem = Q; */
      i22 = Qtem->size[0] * Qtem->size[1];
      Qtem->size[1] = Q->size[1];
      Qtem->size[0] = Q->size[0];
      emxEnsureCapacity_real_T(Qtem, i22);
      ii = Q->size[0];
      for (i22 = 0; i22 < ii; i22++) {
        jj = Q->size[1];
        for (idx = 0; idx < jj; idx++) {
          Qtem->data[idx + Qtem->size[1] * i22] = Q->data[idx + Q->size[1] * i22];
        }
      }

      /* 'obsIQini:23' for i=1:numGen */
      for (i = 0; i < numGen; i++) {
        /* 'obsIQini:25' if i<=Lim(1) */
        if (i + 1 <= Lim->data[0]) {
          /* 'obsIQini:26' Pmax=sum(Qtem(i,1:Lim(1)),2); */
          if (1 > Lim->data[0]) {
            ii = 0;
          } else {
            ii = Lim->data[0];
          }

          i22 = c_Qtem->size[0] * c_Qtem->size[1];
          c_Qtem->size[1] = ii;
          c_Qtem->size[0] = 1;
          emxEnsureCapacity_real_T(c_Qtem, i22);
          for (i22 = 0; i22 < ii; i22++) {
            c_Qtem->data[i22] = Qtem->data[i22 + Qtem->size[1] * i];
          }

          Pmax = sum(c_Qtem);

          /* 'obsIQini:28' idx=find(Qtem(i,1:Lim(1))~=0); */
          if (1 > Lim->data[0]) {
            ii = 0;
          } else {
            ii = Lim->data[0];
          }

          i22 = x->size[0] * x->size[1];
          x->size[1] = ii;
          x->size[0] = 1;
          emxEnsureCapacity_boolean_T(x, i22);
          for (i22 = 0; i22 < ii; i22++) {
            x->data[i22] = (Qtem->data[i22 + Qtem->size[1] * i] != 0.0);
          }

          nx = x->size[1];
          idx = 0;
          b_ProbXEst[1] = x->size[1];
          i22 = b_ii->size[0] * b_ii->size[1];
          b_ii->size[1] = b_ProbXEst[1];
          b_ii->size[0] = 1;
          emxEnsureCapacity_int32_T(b_ii, i22);
          ii = 0;
          exitg1 = false;
          while ((!exitg1) && (ii <= nx - 1)) {
            if (x->data[ii]) {
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

          if (x->size[1] == 1) {
            if (idx == 0) {
              b_ii->size[1] = 0;
              b_ii->size[0] = 1;
            }
          } else {
            if (1 > idx) {
              ii = 0;
            } else {
              ii = idx;
            }

            i22 = r13->size[0];
            r13->size[0] = ii;
            emxEnsureCapacity_int32_T(r13, i22);
            for (i22 = 0; i22 < ii; i22++) {
              r13->data[i22] = i22;
            }

            jj = r13->size[0];
            i22 = e_ii->size[0] * e_ii->size[1];
            e_ii->size[1] = jj;
            e_ii->size[0] = 1;
            emxEnsureCapacity_int32_T(e_ii, i22);
            for (i22 = 0; i22 < jj; i22++) {
              e_ii->data[i22] = b_ii->data[r13->data[i22]];
            }

            i22 = b_ii->size[0] * b_ii->size[1];
            b_ii->size[1] = e_ii->size[1];
            b_ii->size[0] = 1;
            emxEnsureCapacity_int32_T(b_ii, i22);
            ii = e_ii->size[1];
            for (i22 = 0; i22 < ii; i22++) {
              b_ii->data[i22] = e_ii->data[i22];
            }
          }

          i22 = b_idx->size[0] * b_idx->size[1];
          b_idx->size[1] = b_ii->size[1];
          b_idx->size[0] = 1;
          emxEnsureCapacity_real_T(b_idx, i22);
          ii = b_ii->size[1];
          for (i22 = 0; i22 < ii; i22++) {
            b_idx->data[i22] = b_ii->data[i22];
          }

          /* 'obsIQini:29' Qtem2=Qtem(i,idx); */
          jj = b_idx->size[1];
          i22 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[1] = jj;
          Qtem2->size[0] = 1;
          emxEnsureCapacity_real_T(Qtem2, i22);
          for (i22 = 0; i22 < jj; i22++) {
            Qtem2->data[i22] = Qtem->data[((int)b_idx->data[i22] + Qtem->size[1]
              * i) - 1];
          }
        } else if ((i + 1 > Lim->data[0]) && (i + 1 <= Lim->data[1])) {
          /* 'obsIQini:30' elseif i>Lim(1) && i<=Lim(2) */
          /* 'obsIQini:31' Pmax=sum(Qtem(i,1:Lim(2)),2); */
          if (1 > Lim->data[1]) {
            ii = 0;
          } else {
            ii = Lim->data[1];
          }

          i22 = c_Qtem->size[0] * c_Qtem->size[1];
          c_Qtem->size[1] = ii;
          c_Qtem->size[0] = 1;
          emxEnsureCapacity_real_T(c_Qtem, i22);
          for (i22 = 0; i22 < ii; i22++) {
            c_Qtem->data[i22] = Qtem->data[i22 + Qtem->size[1] * i];
          }

          Pmax = sum(c_Qtem);

          /* 'obsIQini:33' idx=find(Qtem(i,Lim(1)+1:Lim(2))~=0); */
          if (Lim->data[0] + 1 > Lim->data[1]) {
            i22 = 0;
            idx = 0;
          } else {
            i22 = Lim->data[0];
            idx = Lim->data[1];
          }

          jj = idx - i22;
          idx = x->size[0] * x->size[1];
          x->size[1] = jj;
          x->size[0] = 1;
          emxEnsureCapacity_boolean_T(x, idx);
          for (idx = 0; idx < jj; idx++) {
            x->data[idx] = (Qtem->data[(i22 + idx) + Qtem->size[1] * i] != 0.0);
          }

          nx = x->size[1];
          idx = 0;
          b_ProbXEst[1] = x->size[1];
          i22 = b_ii->size[0] * b_ii->size[1];
          b_ii->size[1] = b_ProbXEst[1];
          b_ii->size[0] = 1;
          emxEnsureCapacity_int32_T(b_ii, i22);
          ii = 0;
          exitg1 = false;
          while ((!exitg1) && (ii <= nx - 1)) {
            if (x->data[ii]) {
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

          if (x->size[1] == 1) {
            if (idx == 0) {
              b_ii->size[1] = 0;
              b_ii->size[0] = 1;
            }
          } else {
            if (1 > idx) {
              ii = 0;
            } else {
              ii = idx;
            }

            i22 = r13->size[0];
            r13->size[0] = ii;
            emxEnsureCapacity_int32_T(r13, i22);
            for (i22 = 0; i22 < ii; i22++) {
              r13->data[i22] = i22;
            }

            jj = r13->size[0];
            i22 = e_ii->size[0] * e_ii->size[1];
            e_ii->size[1] = jj;
            e_ii->size[0] = 1;
            emxEnsureCapacity_int32_T(e_ii, i22);
            for (i22 = 0; i22 < jj; i22++) {
              e_ii->data[i22] = b_ii->data[r13->data[i22]];
            }

            i22 = b_ii->size[0] * b_ii->size[1];
            b_ii->size[1] = e_ii->size[1];
            b_ii->size[0] = 1;
            emxEnsureCapacity_int32_T(b_ii, i22);
            ii = e_ii->size[1];
            for (i22 = 0; i22 < ii; i22++) {
              b_ii->data[i22] = e_ii->data[i22];
            }
          }

          /* 'obsIQini:34' idx=idx+Lim(1); */
          jj = Lim->data[0];
          i22 = b_idx->size[0] * b_idx->size[1];
          b_idx->size[1] = b_ii->size[1];
          b_idx->size[0] = 1;
          emxEnsureCapacity_real_T(b_idx, i22);
          ii = b_ii->size[1];
          for (i22 = 0; i22 < ii; i22++) {
            b_idx->data[i22] = b_ii->data[i22] + jj;
          }

          /* 'obsIQini:35' Qtem2=Qtem(i,idx); */
          jj = b_idx->size[1];
          i22 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[1] = jj;
          Qtem2->size[0] = 1;
          emxEnsureCapacity_real_T(Qtem2, i22);
          for (i22 = 0; i22 < jj; i22++) {
            Qtem2->data[i22] = Qtem->data[((int)b_idx->data[i22] + Qtem->size[1]
              * i) - 1];
          }
        } else if ((i + 1 > Lim->data[1]) && (i + 1 <= Lim->data[2])) {
          /* 'obsIQini:36' elseif i>Lim(2) && i<=Lim(3) */
          /* 'obsIQini:37' Pmax=sum(Qtem(i,1:Lim(3)),2); */
          if (1 > Lim->data[2]) {
            ii = 0;
          } else {
            ii = Lim->data[2];
          }

          i22 = c_Qtem->size[0] * c_Qtem->size[1];
          c_Qtem->size[1] = ii;
          c_Qtem->size[0] = 1;
          emxEnsureCapacity_real_T(c_Qtem, i22);
          for (i22 = 0; i22 < ii; i22++) {
            c_Qtem->data[i22] = Qtem->data[i22 + Qtem->size[1] * i];
          }

          Pmax = sum(c_Qtem);

          /* 'obsIQini:39' idx=find(Qtem(i,Lim(2)+1:Lim(3))~=0); */
          if (Lim->data[1] + 1 > Lim->data[2]) {
            i22 = 0;
            idx = 0;
          } else {
            i22 = Lim->data[1];
            idx = Lim->data[2];
          }

          jj = idx - i22;
          idx = x->size[0] * x->size[1];
          x->size[1] = jj;
          x->size[0] = 1;
          emxEnsureCapacity_boolean_T(x, idx);
          for (idx = 0; idx < jj; idx++) {
            x->data[idx] = (Qtem->data[(i22 + idx) + Qtem->size[1] * i] != 0.0);
          }

          nx = x->size[1];
          idx = 0;
          b_ProbXEst[1] = x->size[1];
          i22 = b_ii->size[0] * b_ii->size[1];
          b_ii->size[1] = b_ProbXEst[1];
          b_ii->size[0] = 1;
          emxEnsureCapacity_int32_T(b_ii, i22);
          ii = 0;
          exitg1 = false;
          while ((!exitg1) && (ii <= nx - 1)) {
            if (x->data[ii]) {
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

          if (x->size[1] == 1) {
            if (idx == 0) {
              b_ii->size[1] = 0;
              b_ii->size[0] = 1;
            }
          } else {
            if (1 > idx) {
              ii = 0;
            } else {
              ii = idx;
            }

            i22 = r13->size[0];
            r13->size[0] = ii;
            emxEnsureCapacity_int32_T(r13, i22);
            for (i22 = 0; i22 < ii; i22++) {
              r13->data[i22] = i22;
            }

            jj = r13->size[0];
            i22 = e_ii->size[0] * e_ii->size[1];
            e_ii->size[1] = jj;
            e_ii->size[0] = 1;
            emxEnsureCapacity_int32_T(e_ii, i22);
            for (i22 = 0; i22 < jj; i22++) {
              e_ii->data[i22] = b_ii->data[r13->data[i22]];
            }

            i22 = b_ii->size[0] * b_ii->size[1];
            b_ii->size[1] = e_ii->size[1];
            b_ii->size[0] = 1;
            emxEnsureCapacity_int32_T(b_ii, i22);
            ii = e_ii->size[1];
            for (i22 = 0; i22 < ii; i22++) {
              b_ii->data[i22] = e_ii->data[i22];
            }
          }

          /* 'obsIQini:40' idx=idx+Lim(2); */
          jj = Lim->data[1];
          i22 = b_idx->size[0] * b_idx->size[1];
          b_idx->size[1] = b_ii->size[1];
          b_idx->size[0] = 1;
          emxEnsureCapacity_real_T(b_idx, i22);
          ii = b_ii->size[1];
          for (i22 = 0; i22 < ii; i22++) {
            b_idx->data[i22] = b_ii->data[i22] + jj;
          }

          /* 'obsIQini:41' Qtem2=Qtem(i,idx); */
          jj = b_idx->size[1];
          i22 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[1] = jj;
          Qtem2->size[0] = 1;
          emxEnsureCapacity_real_T(Qtem2, i22);
          for (i22 = 0; i22 < jj; i22++) {
            Qtem2->data[i22] = Qtem->data[((int)b_idx->data[i22] + Qtem->size[1]
              * i) - 1];
          }
        } else if ((i + 1 > Lim->data[2]) && (i + 1 <= Lim->data[3])) {
          /* 'obsIQini:42' elseif i>Lim(3) && i<=Lim(4) */
          /* 'obsIQini:43' Pmax=sum(Qtem(i,1:Lim(4)),2); */
          if (1 > Lim->data[3]) {
            ii = 0;
          } else {
            ii = Lim->data[3];
          }

          i22 = c_Qtem->size[0] * c_Qtem->size[1];
          c_Qtem->size[1] = ii;
          c_Qtem->size[0] = 1;
          emxEnsureCapacity_real_T(c_Qtem, i22);
          for (i22 = 0; i22 < ii; i22++) {
            c_Qtem->data[i22] = Qtem->data[i22 + Qtem->size[1] * i];
          }

          Pmax = sum(c_Qtem);

          /* 'obsIQini:45' idx=find(Qtem(i,Lim(3)+1:Lim(4))~=0); */
          if (Lim->data[2] + 1 > Lim->data[3]) {
            i22 = 0;
            idx = 0;
          } else {
            i22 = Lim->data[2];
            idx = Lim->data[3];
          }

          jj = idx - i22;
          idx = x->size[0] * x->size[1];
          x->size[1] = jj;
          x->size[0] = 1;
          emxEnsureCapacity_boolean_T(x, idx);
          for (idx = 0; idx < jj; idx++) {
            x->data[idx] = (Qtem->data[(i22 + idx) + Qtem->size[1] * i] != 0.0);
          }

          nx = x->size[1];
          idx = 0;
          b_ProbXEst[1] = x->size[1];
          i22 = b_ii->size[0] * b_ii->size[1];
          b_ii->size[1] = b_ProbXEst[1];
          b_ii->size[0] = 1;
          emxEnsureCapacity_int32_T(b_ii, i22);
          ii = 0;
          exitg1 = false;
          while ((!exitg1) && (ii <= nx - 1)) {
            if (x->data[ii]) {
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

          if (x->size[1] == 1) {
            if (idx == 0) {
              b_ii->size[1] = 0;
              b_ii->size[0] = 1;
            }
          } else {
            if (1 > idx) {
              ii = 0;
            } else {
              ii = idx;
            }

            i22 = r13->size[0];
            r13->size[0] = ii;
            emxEnsureCapacity_int32_T(r13, i22);
            for (i22 = 0; i22 < ii; i22++) {
              r13->data[i22] = i22;
            }

            jj = r13->size[0];
            i22 = e_ii->size[0] * e_ii->size[1];
            e_ii->size[1] = jj;
            e_ii->size[0] = 1;
            emxEnsureCapacity_int32_T(e_ii, i22);
            for (i22 = 0; i22 < jj; i22++) {
              e_ii->data[i22] = b_ii->data[r13->data[i22]];
            }

            i22 = b_ii->size[0] * b_ii->size[1];
            b_ii->size[1] = e_ii->size[1];
            b_ii->size[0] = 1;
            emxEnsureCapacity_int32_T(b_ii, i22);
            ii = e_ii->size[1];
            for (i22 = 0; i22 < ii; i22++) {
              b_ii->data[i22] = e_ii->data[i22];
            }
          }

          /* 'obsIQini:46' idx=idx+Lim(3); */
          jj = Lim->data[2];
          i22 = b_idx->size[0] * b_idx->size[1];
          b_idx->size[1] = b_ii->size[1];
          b_idx->size[0] = 1;
          emxEnsureCapacity_real_T(b_idx, i22);
          ii = b_ii->size[1];
          for (i22 = 0; i22 < ii; i22++) {
            b_idx->data[i22] = b_ii->data[i22] + jj;
          }

          /* 'obsIQini:47' Qtem2=Qtem(i,idx); */
          jj = b_idx->size[1];
          i22 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[1] = jj;
          Qtem2->size[0] = 1;
          emxEnsureCapacity_real_T(Qtem2, i22);
          for (i22 = 0; i22 < jj; i22++) {
            Qtem2->data[i22] = Qtem->data[((int)b_idx->data[i22] + Qtem->size[1]
              * i) - 1];
          }
        } else {
          /* 'obsIQini:48' else */
          /* if i>Lim(4) && i<=Lim(5) */
          /* 'obsIQini:49' Pmax=1; */
          Pmax = 1.0;

          /* 'obsIQini:51' idx=find(Qtem(i,Lim(4)+1:end)~=0); */
          if (Lim->data[3] + 1 > Qtem->size[1]) {
            i22 = 0;
            idx = 0;
          } else {
            i22 = Lim->data[3];
            idx = Qtem->size[1];
          }

          jj = idx - i22;
          idx = x->size[0] * x->size[1];
          x->size[1] = jj;
          x->size[0] = 1;
          emxEnsureCapacity_boolean_T(x, idx);
          for (idx = 0; idx < jj; idx++) {
            x->data[idx] = (Qtem->data[(i22 + idx) + Qtem->size[1] * i] != 0.0);
          }

          nx = x->size[1];
          idx = 0;
          d_Qtem[1] = (unsigned int)x->size[1];
          i22 = b_ii->size[0] * b_ii->size[1];
          b_ii->size[1] = (int)d_Qtem[1];
          b_ii->size[0] = 1;
          emxEnsureCapacity_int32_T(b_ii, i22);
          ii = 0;
          exitg1 = false;
          while ((!exitg1) && (ii <= nx - 1)) {
            if (x->data[ii]) {
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

          if (x->size[1] == 1) {
            if (idx == 0) {
              b_ii->size[1] = 0;
              b_ii->size[0] = 1;
            }
          } else {
            if (1 > idx) {
              ii = 0;
            } else {
              ii = idx;
            }

            i22 = r13->size[0];
            r13->size[0] = ii;
            emxEnsureCapacity_int32_T(r13, i22);
            for (i22 = 0; i22 < ii; i22++) {
              r13->data[i22] = i22;
            }

            jj = r13->size[0];
            i22 = e_ii->size[0] * e_ii->size[1];
            e_ii->size[1] = jj;
            e_ii->size[0] = 1;
            emxEnsureCapacity_int32_T(e_ii, i22);
            for (i22 = 0; i22 < jj; i22++) {
              e_ii->data[i22] = b_ii->data[r13->data[i22]];
            }

            i22 = b_ii->size[0] * b_ii->size[1];
            b_ii->size[1] = e_ii->size[1];
            b_ii->size[0] = 1;
            emxEnsureCapacity_int32_T(b_ii, i22);
            ii = e_ii->size[1];
            for (i22 = 0; i22 < ii; i22++) {
              b_ii->data[i22] = e_ii->data[i22];
            }
          }

          /* 'obsIQini:52' idx=idx+Lim(4); */
          jj = Lim->data[3];
          i22 = b_idx->size[0] * b_idx->size[1];
          b_idx->size[1] = b_ii->size[1];
          b_idx->size[0] = 1;
          emxEnsureCapacity_real_T(b_idx, i22);
          ii = b_ii->size[1];
          for (i22 = 0; i22 < ii; i22++) {
            b_idx->data[i22] = (double)b_ii->data[i22] + (double)jj;
          }

          /* 'obsIQini:53' Qtem2=Qtem(i,idx); */
          jj = b_idx->size[1];
          i22 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[1] = jj;
          Qtem2->size[0] = 1;
          emxEnsureCapacity_real_T(Qtem2, i22);
          for (i22 = 0; i22 < jj; i22++) {
            Qtem2->data[i22] = Qtem->data[((int)b_idx->data[i22] + Qtem->size[1]
              * i) - 1];
          }
        }

        /* 'obsIQini:56' r=Pmax*rand; */
        r = Pmax * d_rand();

        /* 'obsIQini:59' for j=1:length(Qtem2) */
        j = 0;
        exitg1 = false;
        while ((!exitg1) && (j <= Qtem2->size[1] - 1)) {
          /* 'obsIQini:61' if sum(Qtem2(1:j),2)<=r && sum(Qtem2(1:j+1),2)>r */
          i22 = r13->size[0];
          r13->size[0] = j + 1;
          emxEnsureCapacity_int32_T(r13, i22);
          for (i22 = 0; i22 <= j; i22++) {
            r13->data[i22] = i22;
          }

          jj = r13->size[0];
          i22 = c_Qtem->size[0] * c_Qtem->size[1];
          c_Qtem->size[1] = jj;
          c_Qtem->size[0] = 1;
          emxEnsureCapacity_real_T(c_Qtem, i22);
          for (i22 = 0; i22 < jj; i22++) {
            c_Qtem->data[i22] = Qtem2->data[r13->data[i22]];
          }

          guard1 = false;
          if (sum(c_Qtem) <= r) {
            i22 = r13->size[0];
            r13->size[0] = j + 2;
            emxEnsureCapacity_int32_T(r13, i22);
            for (i22 = 0; i22 <= j + 1; i22++) {
              r13->data[i22] = i22;
            }

            jj = r13->size[0];
            i22 = c_Qtem->size[0] * c_Qtem->size[1];
            c_Qtem->size[1] = jj;
            c_Qtem->size[0] = 1;
            emxEnsureCapacity_real_T(c_Qtem, i22);
            for (i22 = 0; i22 < jj; i22++) {
              c_Qtem->data[i22] = Qtem2->data[r13->data[i22]];
            }

            if (sum(c_Qtem) > r) {
              /* 'obsIQini:62' Obs(i,idx(j+1))=1; */
              Obs->data[((int)(unsigned int)b_idx->data[j + 1] + Obs->size[1] *
                         i) - 1] = 1;

              /* 'obsIQini:63' Qtem = Qtem.*(1./(1-Qtem(:,idx(j+1)))); */
              jj = Qtem->size[0];
              i22 = 0;
              idx = 0;
              nx = 0;
              ii = r15->size[0];
              r15->size[0] = jj;
              emxEnsureCapacity_real_T(r15, ii);
              for (ii = 0; ii < jj; ii++) {
                r15->data[i22] = Qtem->data[nx + Qtem->size[1] * idx];
                i22++;
                idx++;
                if (idx > Qtem->size[0] - 1) {
                  idx = 0;
                  nx++;
                }
              }

              ii = Qtem->size[0];
              idx = (int)(unsigned int)b_idx->data[1 + j];
              i22 = c_ProbXEst->size[0];
              c_ProbXEst->size[0] = ii;
              emxEnsureCapacity_real_T(c_ProbXEst, i22);
              for (i22 = 0; i22 < ii; i22++) {
                c_ProbXEst->data[i22] = 1.0 - Qtem->data[(idx + Qtem->size[1] *
                  i22) - 1];
              }

              b_rdivide_helper(c_ProbXEst, b_Qtem);
              i22 = b_Qtem->size[0];
              b_Qtem->size[0] = r15->size[0];
              emxEnsureCapacity_real_T(b_Qtem, i22);
              ii = r15->size[0];
              for (i22 = 0; i22 < ii; i22++) {
                b_Qtem->data[i22] *= r15->data[i22];
              }

              d_Qtem[0] = (unsigned int)b_Qtem->size[0];
              b_ProbXEst[1] = (int)d_Qtem[0];
              i22 = Qtem->size[0] * Qtem->size[1];
              Qtem->size[1] = 1;
              Qtem->size[0] = b_ProbXEst[1];
              emxEnsureCapacity_real_T(Qtem, i22);
              ii = b_ProbXEst[1];
              for (i22 = 0; i22 < ii; i22++) {
                for (idx = 0; idx < 1; idx++) {
                  Qtem->data[Qtem->size[1] * i22] = b_Qtem->data[i22];
                }
              }

              /* 'obsIQini:64' Qtem(:,idx(j+1))=0; */
              ii = b_Qtem->size[0];
              idx = (int)(unsigned int)b_idx->data[j + 1];
              for (i22 = 0; i22 < ii; i22++) {
                Qtem->data[(idx + Qtem->size[1] * i22) - 1] = 0.0;
              }

              exitg1 = true;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            i22 = r13->size[0];
            r13->size[0] = j + 1;
            emxEnsureCapacity_int32_T(r13, i22);
            for (i22 = 0; i22 <= j; i22++) {
              r13->data[i22] = i22;
            }

            jj = r13->size[0];
            i22 = c_Qtem->size[0] * c_Qtem->size[1];
            c_Qtem->size[1] = jj;
            c_Qtem->size[0] = 1;
            emxEnsureCapacity_real_T(c_Qtem, i22);
            for (i22 = 0; i22 < jj; i22++) {
              c_Qtem->data[i22] = Qtem2->data[r13->data[i22]];
            }

            if (sum(c_Qtem) > r) {
              /* 'obsIQini:66' elseif sum(Qtem2(1:j),2)>r */
              /* 'obsIQini:67' Obs(i,idx(j))=1; */
              Obs->data[((int)(unsigned int)b_idx->data[j] + Obs->size[1] * i) -
                1] = 1;

              /* 'obsIQini:68' Qtem = Qtem.*(1./(1-Qtem(:,idx(j)))); */
              jj = Qtem->size[0];
              i22 = 0;
              idx = 0;
              nx = 0;
              ii = r16->size[0];
              r16->size[0] = jj;
              emxEnsureCapacity_real_T(r16, ii);
              for (ii = 0; ii < jj; ii++) {
                r16->data[i22] = Qtem->data[nx + Qtem->size[1] * idx];
                i22++;
                idx++;
                if (idx > Qtem->size[0] - 1) {
                  idx = 0;
                  nx++;
                }
              }

              ii = Qtem->size[0];
              idx = (int)(unsigned int)b_idx->data[j];
              i22 = c_ProbXEst->size[0];
              c_ProbXEst->size[0] = ii;
              emxEnsureCapacity_real_T(c_ProbXEst, i22);
              for (i22 = 0; i22 < ii; i22++) {
                c_ProbXEst->data[i22] = 1.0 - Qtem->data[(idx + Qtem->size[1] *
                  i22) - 1];
              }

              b_rdivide_helper(c_ProbXEst, b_Qtem);
              i22 = b_Qtem->size[0];
              b_Qtem->size[0] = r16->size[0];
              emxEnsureCapacity_real_T(b_Qtem, i22);
              ii = r16->size[0];
              for (i22 = 0; i22 < ii; i22++) {
                b_Qtem->data[i22] *= r16->data[i22];
              }

              d_Qtem[0] = (unsigned int)b_Qtem->size[0];
              b_ProbXEst[1] = (int)d_Qtem[0];
              i22 = Qtem->size[0] * Qtem->size[1];
              Qtem->size[1] = 1;
              Qtem->size[0] = b_ProbXEst[1];
              emxEnsureCapacity_real_T(Qtem, i22);
              ii = b_ProbXEst[1];
              for (i22 = 0; i22 < ii; i22++) {
                for (idx = 0; idx < 1; idx++) {
                  Qtem->data[Qtem->size[1] * i22] = b_Qtem->data[i22];
                }
              }

              /* 'obsIQini:69' Qtem(:,idx(j))=0; */
              ii = b_Qtem->size[0];
              idx = (int)(unsigned int)b_idx->data[j];
              for (i22 = 0; i22 < ii; i22++) {
                Qtem->data[(idx + Qtem->size[1] * i22) - 1] = 0.0;
              }

              exitg1 = true;
            } else {
              j++;
            }
          }
        }
      }

      /* 'obsIQini:76' [List(:,u),~]=find(Obs'==1); */
      i22 = b_x->size[0] * b_x->size[1];
      b_x->size[1] = Obs->size[0];
      b_x->size[0] = Obs->size[1];
      emxEnsureCapacity_boolean_T(b_x, i22);
      ii = Obs->size[1];
      for (i22 = 0; i22 < ii; i22++) {
        jj = Obs->size[0];
        for (idx = 0; idx < jj; idx++) {
          b_x->data[idx + b_x->size[1] * i22] = (Obs->data[i22 + Obs->size[1] *
            idx] == 1);
        }
      }

      nx = b_x->size[0] * b_x->size[1];
      if (nx == 0) {
        c_ii->size[0] = 0;
      } else {
        idx = 0;
        i22 = c_ii->size[0];
        c_ii->size[0] = nx;
        emxEnsureCapacity_int32_T(c_ii, i22);
        ii = 1;
        jj = 1;
        exitg1 = false;
        while ((!exitg1) && (jj <= b_x->size[1])) {
          guard1 = false;
          if (b_x->data[(jj + b_x->size[1] * (ii - 1)) - 1]) {
            idx++;
            c_ii->data[idx - 1] = ii;
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
            if (ii > b_x->size[0]) {
              ii = 1;
              jj++;
            }
          }
        }

        if (nx == 1) {
          if (idx == 0) {
            c_ii->size[0] = 0;
          }
        } else {
          if (1 > idx) {
            ii = 0;
          } else {
            ii = idx;
          }

          i22 = r13->size[0];
          r13->size[0] = ii;
          emxEnsureCapacity_int32_T(r13, i22);
          for (i22 = 0; i22 < ii; i22++) {
            r13->data[i22] = i22;
          }

          jj = r13->size[0];
          i22 = d_ii->size[0];
          d_ii->size[0] = jj;
          emxEnsureCapacity_int32_T(d_ii, i22);
          for (i22 = 0; i22 < jj; i22++) {
            d_ii->data[i22] = c_ii->data[r13->data[i22]];
          }

          i22 = c_ii->size[0];
          c_ii->size[0] = d_ii->size[0];
          emxEnsureCapacity_int32_T(c_ii, i22);
          ii = d_ii->size[0];
          for (i22 = 0; i22 < ii; i22++) {
            c_ii->data[i22] = d_ii->data[i22];
          }
        }
      }

      i22 = b_Qtem->size[0];
      b_Qtem->size[0] = c_ii->size[0];
      emxEnsureCapacity_real_T(b_Qtem, i22);
      ii = c_ii->size[0];
      for (i22 = 0; i22 < ii; i22++) {
        b_Qtem->data[i22] = c_ii->data[i22];
      }

      jj = b_Qtem->size[0];
      for (i22 = 0; i22 < jj; i22++) {
        List->data[u + List->size[1] * i22] = b_Qtem->data[i22];
      }

      /* 'obsIQini:76' ~ */
    }

    /* 'obsIQini:80' newIC(:,(k-1)*numObsIQ+1:k*numObsIQ) = List; */
    i22 = k * numObsIQ;
    if (i22 + 1 > (k + 1) * numObsIQ) {
      i22 = 0;
    }

    ii = List->size[0];
    for (idx = 0; idx < ii; idx++) {
      loop_ub = List->size[1];
      for (nx = 0; nx < loop_ub; nx++) {
        newIC->data[(i22 + nx) + newIC->size[1] * idx] = (int)List->data[nx +
          List->size[1] * idx];
      }
    }

    /* 'obsIQini:81' List = zeros(numGen,numObsIQ); */
    i22 = List->size[0] * List->size[1];
    List->size[1] = numObsIQ;
    List->size[0] = numGen;
    emxEnsureCapacity_real_T(List, i22);
    for (i22 = 0; i22 < numGen; i22++) {
      for (idx = 0; idx < numObsIQ; idx++) {
        List->data[idx + List->size[1] * i22] = 0.0;
      }
    }
  }

  emxFree_int32_T(&e_ii);
  emxFree_int32_T(&d_ii);
  emxFree_real_T(&c_Qtem);
  emxFree_real_T(&c_ProbXEst);
  emxFree_int32_T(&c_ii);
  emxFree_boolean_T(&b_x);
  emxFree_int32_T(&b_ii);
  emxFree_boolean_T(&x);
  emxFree_int32_T(&r13);
  emxFree_real_T(&b_Qtem);
  emxFree_real_T(&r16);
  emxFree_real_T(&r15);
  emxFree_real_T(&Qtem2);
  emxFree_real_T(&b_idx);
  emxFree_real_T(&Qtem);
  emxFree_int8_T(&Obs);
  emxFree_real_T(&Q);
  emxFree_real_T(&List);
  emxFree_int32_T(&Lim);
}

/*
 * File trailer for obsIQini.c
 *
 * [EOF]
 */
