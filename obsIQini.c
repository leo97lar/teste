/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * obsIQini.c
 *
 * Code generation for function 'obsIQini'
 *
 */

/* Include files */
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
 */
void obsIQini(const emxArray_real_T *IQ, int numIQ, int numObsIQ, const
              emxArray_real_T *ProbXEst, emxArray_int32_T *newIC)
{
  emxArray_int32_T *Lim;
  int numGen;
  int jj;
  int i15;
  emxArray_real_T *b_ProbXEst;
  int g;
  emxArray_real_T *List;
  int ii;
  emxArray_real_T *r6;
  int nx;
  int loop_ub;
  emxArray_real_T *Q;
  emxArray_int8_T *Obs;
  emxArray_real_T *Qtem;
  emxArray_real_T *idx;
  emxArray_real_T *Qtem2;
  emxArray_boolean_T *x;
  emxArray_int32_T *b_ii;
  emxArray_boolean_T *b_x;
  emxArray_int32_T *c_ii;
  emxArray_real_T *b_Qtem;
  emxArray_int32_T *d_ii;
  emxArray_real_T *r7;
  int k;
  int u;
  unsigned int unnamed_idx_0;
  unsigned int unnamed_idx_1;
  int i;
  double Pmax;
  int b_idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  double r;
  int j;
  emxInit_int32_T(&Lim, 2);

  /* UNTITLED7 Summary of this function goes here */
  /*    Detailed explanation goes here, */
  /* 'obsIQini:4' numGen=size(IQ,1)/numIQ; */
  numGen = (int)rt_roundd((double)IQ->size[0] / (double)numIQ);

  /* 'obsIQini:5' Lim=zeros(1,length(ProbXEst)); */
  jj = ProbXEst->size[0];
  i15 = Lim->size[0] * Lim->size[1];
  Lim->size[0] = 1;
  Lim->size[1] = jj;
  emxEnsureCapacity_int32_T(Lim, i15);
  for (i15 = 0; i15 < jj; i15++) {
    Lim->data[i15] = 0;
  }

  /* 'obsIQini:7' for g=1:length(ProbXEst) */
  i15 = ProbXEst->size[0];
  emxInit_real_T(&b_ProbXEst, 1);
  for (g = 0; g < i15; g++) {
    /* 'obsIQini:8' Lim(g) = numGen*sum(ProbXEst(1:g),1)/100; */
    ii = b_ProbXEst->size[0];
    b_ProbXEst->size[0] = g + 1;
    emxEnsureCapacity_real_T(b_ProbXEst, ii);
    for (ii = 0; ii <= g; ii++) {
      b_ProbXEst->data[ii] = ProbXEst->data[ii];
    }

    Lim->data[g] = (int)rt_roundd((double)(int)rt_roundd((double)numGen * b_sum
      (b_ProbXEst)) / 100.0);
  }

  emxInit_real_T(&List, 2);

  /* 'obsIQini:11' List = zeros(numGen,numObsIQ); */
  i15 = List->size[0] * List->size[1];
  List->size[0] = numGen;
  List->size[1] = numObsIQ;
  emxEnsureCapacity_real_T(List, i15);
  for (i15 = 0; i15 < numObsIQ; i15++) {
    for (ii = 0; ii < numGen; ii++) {
      List->data[ii + List->size[0] * i15] = 0.0;
    }
  }

  emxInit_real_T(&r6, 2);

  /* 'obsIQini:12' newIC = int32(repmat(List,1,numIQ)); */
  repmat(List, numIQ, r6);
  i15 = newIC->size[0] * newIC->size[1];
  newIC->size[0] = r6->size[0];
  newIC->size[1] = r6->size[1];
  emxEnsureCapacity_int32_T(newIC, i15);
  nx = r6->size[1];
  for (i15 = 0; i15 < nx; i15++) {
    loop_ub = r6->size[0];
    for (ii = 0; ii < loop_ub; ii++) {
      newIC->data[ii + newIC->size[0] * i15] = (int)rt_roundd(r6->data[ii +
        r6->size[0] * i15]);
    }
  }

  emxFree_real_T(&r6);

  /* 'obsIQini:14' for k=1:numIQ */
  emxInit_real_T(&Q, 2);
  emxInit_int8_T(&Obs, 2);
  emxInit_real_T(&Qtem, 2);
  emxInit_real_T(&idx, 2);
  emxInit_real_T(&Qtem2, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&b_ii, 2);
  emxInit_boolean_T(&b_x, 2);
  emxInit_int32_T(&c_ii, 1);
  emxInit_real_T(&b_Qtem, 2);
  emxInit_int32_T(&d_ii, 2);
  emxInit_real_T(&r7, 1);
  for (k = 0; k < numIQ; k++) {
    /* 'obsIQini:16' Q = IQ((k-1)*numGen+1:k*numGen,:); */
    i15 = k * numGen;
    ii = (k + 1) * numGen;
    if (i15 + 1 > ii) {
      i15 = 0;
      ii = 0;
    }

    nx = IQ->size[1];
    jj = Q->size[0] * Q->size[1];
    loop_ub = ii - i15;
    Q->size[0] = loop_ub;
    Q->size[1] = nx;
    emxEnsureCapacity_real_T(Q, jj);
    for (ii = 0; ii < nx; ii++) {
      for (jj = 0; jj < loop_ub; jj++) {
        Q->data[jj + Q->size[0] * ii] = IQ->data[(i15 + jj) + IQ->size[0] * ii];
      }
    }

    /* 'obsIQini:18' for u=1:numObsIQ */
    for (u = 0; u < numObsIQ; u++) {
      /* 'obsIQini:20' Obs = zeros(size(Q)); */
      i15 = IQ->size[1];
      unnamed_idx_0 = (unsigned int)loop_ub;
      unnamed_idx_1 = (unsigned int)i15;
      i15 = Obs->size[0] * Obs->size[1];
      Obs->size[0] = (int)unnamed_idx_0;
      Obs->size[1] = (int)unnamed_idx_1;
      emxEnsureCapacity_int8_T(Obs, i15);
      nx = (int)unnamed_idx_1;
      for (i15 = 0; i15 < nx; i15++) {
        jj = (int)unnamed_idx_0;
        for (ii = 0; ii < jj; ii++) {
          Obs->data[ii + Obs->size[0] * i15] = 0;
        }
      }

      /* 'obsIQini:21' Qtem = Q; */
      i15 = Qtem->size[0] * Qtem->size[1];
      Qtem->size[0] = Q->size[0];
      Qtem->size[1] = Q->size[1];
      emxEnsureCapacity_real_T(Qtem, i15);
      nx = Q->size[1];
      for (i15 = 0; i15 < nx; i15++) {
        jj = Q->size[0];
        for (ii = 0; ii < jj; ii++) {
          Qtem->data[ii + Qtem->size[0] * i15] = Q->data[ii + Q->size[0] * i15];
        }
      }

      /* 'obsIQini:23' for i=1:numGen */
      for (i = 0; i < numGen; i++) {
        /* 'obsIQini:25' if i<=Lim(1) */
        if (i + 1 <= Lim->data[0]) {
          /* 'obsIQini:26' Pmax=sum(Qtem(i,1:Lim(1)),2); */
          if (1 > Lim->data[0]) {
            nx = 0;
          } else {
            nx = Lim->data[0];
          }

          i15 = b_Qtem->size[0] * b_Qtem->size[1];
          b_Qtem->size[0] = 1;
          b_Qtem->size[1] = nx;
          emxEnsureCapacity_real_T(b_Qtem, i15);
          for (i15 = 0; i15 < nx; i15++) {
            b_Qtem->data[i15] = Qtem->data[i + Qtem->size[0] * i15];
          }

          Pmax = sum(b_Qtem);

          /* 'obsIQini:28' idx=find(Qtem(i,1:Lim(1))~=0); */
          if (1 > Lim->data[0]) {
            nx = 0;
          } else {
            nx = Lim->data[0];
          }

          i15 = x->size[0] * x->size[1];
          x->size[0] = 1;
          x->size[1] = nx;
          emxEnsureCapacity_boolean_T(x, i15);
          for (i15 = 0; i15 < nx; i15++) {
            x->data[i15] = (Qtem->data[i + Qtem->size[0] * i15] != 0.0);
          }

          nx = x->size[1];
          b_idx = 0;
          i15 = b_ii->size[0] * b_ii->size[1];
          b_ii->size[0] = 1;
          b_ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(b_ii, i15);
          ii = 0;
          exitg1 = false;
          while ((!exitg1) && (ii <= nx - 1)) {
            if (x->data[ii]) {
              b_idx++;
              b_ii->data[b_idx - 1] = ii + 1;
              if (b_idx >= nx) {
                exitg1 = true;
              } else {
                ii++;
              }
            } else {
              ii++;
            }
          }

          if (x->size[1] == 1) {
            if (b_idx == 0) {
              b_ii->size[0] = 1;
              b_ii->size[1] = 0;
            }
          } else {
            i15 = b_ii->size[0] * b_ii->size[1];
            if (1 > b_idx) {
              b_ii->size[1] = 0;
            } else {
              b_ii->size[1] = b_idx;
            }

            emxEnsureCapacity_int32_T(b_ii, i15);
          }

          i15 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = b_ii->size[1];
          emxEnsureCapacity_real_T(idx, i15);
          nx = b_ii->size[1];
          for (i15 = 0; i15 < nx; i15++) {
            idx->data[i15] = b_ii->data[i15];
          }

          /* 'obsIQini:29' Qtem2=Qtem(i,idx); */
          i15 = b_ProbXEst->size[0];
          b_ProbXEst->size[0] = idx->size[1];
          emxEnsureCapacity_real_T(b_ProbXEst, i15);
          nx = idx->size[1];
          for (i15 = 0; i15 < nx; i15++) {
            b_ProbXEst->data[i15] = idx->data[i15];
          }

          i15 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = b_ProbXEst->size[0];
          emxEnsureCapacity_real_T(Qtem2, i15);
          nx = b_ProbXEst->size[0];
          for (i15 = 0; i15 < nx; i15++) {
            Qtem2->data[i15] = Qtem->data[i + Qtem->size[0] * ((int)
              b_ProbXEst->data[i15] - 1)];
          }
        } else if ((i + 1 > Lim->data[0]) && (i + 1 <= Lim->data[1])) {
          /* 'obsIQini:30' elseif i>Lim(1) && i<=Lim(2) */
          /* 'obsIQini:31' Pmax=sum(Qtem(i,1:Lim(2)),2); */
          if (1 > Lim->data[1]) {
            nx = 0;
          } else {
            nx = Lim->data[1];
          }

          i15 = b_Qtem->size[0] * b_Qtem->size[1];
          b_Qtem->size[0] = 1;
          b_Qtem->size[1] = nx;
          emxEnsureCapacity_real_T(b_Qtem, i15);
          for (i15 = 0; i15 < nx; i15++) {
            b_Qtem->data[i15] = Qtem->data[i + Qtem->size[0] * i15];
          }

          Pmax = sum(b_Qtem);

          /* 'obsIQini:33' idx=find(Qtem(i,Lim(1)+1:Lim(2))~=0); */
          if (Lim->data[0] + 1 > Lim->data[1]) {
            i15 = 0;
            ii = 0;
          } else {
            i15 = Lim->data[0];
            ii = Lim->data[1];
          }

          jj = x->size[0] * x->size[1];
          x->size[0] = 1;
          nx = ii - i15;
          x->size[1] = nx;
          emxEnsureCapacity_boolean_T(x, jj);
          for (ii = 0; ii < nx; ii++) {
            x->data[ii] = (Qtem->data[i + Qtem->size[0] * (i15 + ii)] != 0.0);
          }

          nx = x->size[1];
          b_idx = 0;
          i15 = b_ii->size[0] * b_ii->size[1];
          b_ii->size[0] = 1;
          b_ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(b_ii, i15);
          ii = 0;
          exitg1 = false;
          while ((!exitg1) && (ii <= nx - 1)) {
            if (x->data[ii]) {
              b_idx++;
              b_ii->data[b_idx - 1] = ii + 1;
              if (b_idx >= nx) {
                exitg1 = true;
              } else {
                ii++;
              }
            } else {
              ii++;
            }
          }

          if (x->size[1] == 1) {
            if (b_idx == 0) {
              b_ii->size[0] = 1;
              b_ii->size[1] = 0;
            }
          } else {
            i15 = b_ii->size[0] * b_ii->size[1];
            if (1 > b_idx) {
              b_ii->size[1] = 0;
            } else {
              b_ii->size[1] = b_idx;
            }

            emxEnsureCapacity_int32_T(b_ii, i15);
          }

          /* 'obsIQini:34' idx=idx+Lim(1); */
          jj = Lim->data[0];
          i15 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = b_ii->size[1];
          emxEnsureCapacity_real_T(idx, i15);
          nx = b_ii->size[1];
          for (i15 = 0; i15 < nx; i15++) {
            idx->data[i15] = b_ii->data[i15] + jj;
          }

          /* 'obsIQini:35' Qtem2=Qtem(i,idx); */
          i15 = b_ProbXEst->size[0];
          b_ProbXEst->size[0] = idx->size[1];
          emxEnsureCapacity_real_T(b_ProbXEst, i15);
          nx = idx->size[1];
          for (i15 = 0; i15 < nx; i15++) {
            b_ProbXEst->data[i15] = idx->data[i15];
          }

          i15 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = b_ProbXEst->size[0];
          emxEnsureCapacity_real_T(Qtem2, i15);
          nx = b_ProbXEst->size[0];
          for (i15 = 0; i15 < nx; i15++) {
            Qtem2->data[i15] = Qtem->data[i + Qtem->size[0] * ((int)
              b_ProbXEst->data[i15] - 1)];
          }
        } else if ((i + 1 > Lim->data[1]) && (i + 1 <= Lim->data[2])) {
          /* 'obsIQini:36' elseif i>Lim(2) && i<=Lim(3) */
          /* 'obsIQini:37' Pmax=sum(Qtem(i,1:Lim(3)),2); */
          if (1 > Lim->data[2]) {
            nx = 0;
          } else {
            nx = Lim->data[2];
          }

          i15 = b_Qtem->size[0] * b_Qtem->size[1];
          b_Qtem->size[0] = 1;
          b_Qtem->size[1] = nx;
          emxEnsureCapacity_real_T(b_Qtem, i15);
          for (i15 = 0; i15 < nx; i15++) {
            b_Qtem->data[i15] = Qtem->data[i + Qtem->size[0] * i15];
          }

          Pmax = sum(b_Qtem);

          /* 'obsIQini:39' idx=find(Qtem(i,Lim(2)+1:Lim(3))~=0); */
          if (Lim->data[1] + 1 > Lim->data[2]) {
            i15 = 0;
            ii = 0;
          } else {
            i15 = Lim->data[1];
            ii = Lim->data[2];
          }

          jj = x->size[0] * x->size[1];
          x->size[0] = 1;
          nx = ii - i15;
          x->size[1] = nx;
          emxEnsureCapacity_boolean_T(x, jj);
          for (ii = 0; ii < nx; ii++) {
            x->data[ii] = (Qtem->data[i + Qtem->size[0] * (i15 + ii)] != 0.0);
          }

          nx = x->size[1];
          b_idx = 0;
          i15 = b_ii->size[0] * b_ii->size[1];
          b_ii->size[0] = 1;
          b_ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(b_ii, i15);
          ii = 0;
          exitg1 = false;
          while ((!exitg1) && (ii <= nx - 1)) {
            if (x->data[ii]) {
              b_idx++;
              b_ii->data[b_idx - 1] = ii + 1;
              if (b_idx >= nx) {
                exitg1 = true;
              } else {
                ii++;
              }
            } else {
              ii++;
            }
          }

          if (x->size[1] == 1) {
            if (b_idx == 0) {
              b_ii->size[0] = 1;
              b_ii->size[1] = 0;
            }
          } else {
            i15 = b_ii->size[0] * b_ii->size[1];
            if (1 > b_idx) {
              b_ii->size[1] = 0;
            } else {
              b_ii->size[1] = b_idx;
            }

            emxEnsureCapacity_int32_T(b_ii, i15);
          }

          /* 'obsIQini:40' idx=idx+Lim(2); */
          jj = Lim->data[1];
          i15 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = b_ii->size[1];
          emxEnsureCapacity_real_T(idx, i15);
          nx = b_ii->size[1];
          for (i15 = 0; i15 < nx; i15++) {
            idx->data[i15] = b_ii->data[i15] + jj;
          }

          /* 'obsIQini:41' Qtem2=Qtem(i,idx); */
          i15 = b_ProbXEst->size[0];
          b_ProbXEst->size[0] = idx->size[1];
          emxEnsureCapacity_real_T(b_ProbXEst, i15);
          nx = idx->size[1];
          for (i15 = 0; i15 < nx; i15++) {
            b_ProbXEst->data[i15] = idx->data[i15];
          }

          i15 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = b_ProbXEst->size[0];
          emxEnsureCapacity_real_T(Qtem2, i15);
          nx = b_ProbXEst->size[0];
          for (i15 = 0; i15 < nx; i15++) {
            Qtem2->data[i15] = Qtem->data[i + Qtem->size[0] * ((int)
              b_ProbXEst->data[i15] - 1)];
          }
        } else if ((i + 1 > Lim->data[2]) && (i + 1 <= Lim->data[3])) {
          /* 'obsIQini:42' elseif i>Lim(3) && i<=Lim(4) */
          /* 'obsIQini:43' Pmax=sum(Qtem(i,1:Lim(4)),2); */
          if (1 > Lim->data[3]) {
            nx = 0;
          } else {
            nx = Lim->data[3];
          }

          i15 = b_Qtem->size[0] * b_Qtem->size[1];
          b_Qtem->size[0] = 1;
          b_Qtem->size[1] = nx;
          emxEnsureCapacity_real_T(b_Qtem, i15);
          for (i15 = 0; i15 < nx; i15++) {
            b_Qtem->data[i15] = Qtem->data[i + Qtem->size[0] * i15];
          }

          Pmax = sum(b_Qtem);

          /* 'obsIQini:45' idx=find(Qtem(i,Lim(3)+1:Lim(4))~=0); */
          if (Lim->data[2] + 1 > Lim->data[3]) {
            i15 = 0;
            ii = 0;
          } else {
            i15 = Lim->data[2];
            ii = Lim->data[3];
          }

          jj = x->size[0] * x->size[1];
          x->size[0] = 1;
          nx = ii - i15;
          x->size[1] = nx;
          emxEnsureCapacity_boolean_T(x, jj);
          for (ii = 0; ii < nx; ii++) {
            x->data[ii] = (Qtem->data[i + Qtem->size[0] * (i15 + ii)] != 0.0);
          }

          nx = x->size[1];
          b_idx = 0;
          i15 = b_ii->size[0] * b_ii->size[1];
          b_ii->size[0] = 1;
          b_ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(b_ii, i15);
          ii = 0;
          exitg1 = false;
          while ((!exitg1) && (ii <= nx - 1)) {
            if (x->data[ii]) {
              b_idx++;
              b_ii->data[b_idx - 1] = ii + 1;
              if (b_idx >= nx) {
                exitg1 = true;
              } else {
                ii++;
              }
            } else {
              ii++;
            }
          }

          if (x->size[1] == 1) {
            if (b_idx == 0) {
              b_ii->size[0] = 1;
              b_ii->size[1] = 0;
            }
          } else {
            i15 = b_ii->size[0] * b_ii->size[1];
            if (1 > b_idx) {
              b_ii->size[1] = 0;
            } else {
              b_ii->size[1] = b_idx;
            }

            emxEnsureCapacity_int32_T(b_ii, i15);
          }

          /* 'obsIQini:46' idx=idx+Lim(3); */
          jj = Lim->data[2];
          i15 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = b_ii->size[1];
          emxEnsureCapacity_real_T(idx, i15);
          nx = b_ii->size[1];
          for (i15 = 0; i15 < nx; i15++) {
            idx->data[i15] = b_ii->data[i15] + jj;
          }

          /* 'obsIQini:47' Qtem2=Qtem(i,idx); */
          i15 = b_ProbXEst->size[0];
          b_ProbXEst->size[0] = idx->size[1];
          emxEnsureCapacity_real_T(b_ProbXEst, i15);
          nx = idx->size[1];
          for (i15 = 0; i15 < nx; i15++) {
            b_ProbXEst->data[i15] = idx->data[i15];
          }

          i15 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = b_ProbXEst->size[0];
          emxEnsureCapacity_real_T(Qtem2, i15);
          nx = b_ProbXEst->size[0];
          for (i15 = 0; i15 < nx; i15++) {
            Qtem2->data[i15] = Qtem->data[i + Qtem->size[0] * ((int)
              b_ProbXEst->data[i15] - 1)];
          }
        } else {
          /* 'obsIQini:48' else */
          /* if i>Lim(4) && i<=Lim(5) */
          /* 'obsIQini:49' Pmax=1; */
          Pmax = 1.0;

          /* 'obsIQini:51' idx=find(Qtem(i,Lim(4)+1:end)~=0); */
          if (Lim->data[3] + 1 > Qtem->size[1]) {
            i15 = 0;
            ii = 0;
          } else {
            i15 = Lim->data[3];
            ii = Qtem->size[1];
          }

          jj = x->size[0] * x->size[1];
          x->size[0] = 1;
          nx = ii - i15;
          x->size[1] = nx;
          emxEnsureCapacity_boolean_T(x, jj);
          for (ii = 0; ii < nx; ii++) {
            x->data[ii] = (Qtem->data[i + Qtem->size[0] * (i15 + ii)] != 0.0);
          }

          nx = x->size[1];
          b_idx = 0;
          i15 = b_ii->size[0] * b_ii->size[1];
          b_ii->size[0] = 1;
          b_ii->size[1] = x->size[1];
          emxEnsureCapacity_int32_T(b_ii, i15);
          ii = 0;
          exitg1 = false;
          while ((!exitg1) && (ii <= nx - 1)) {
            if (x->data[ii]) {
              b_idx++;
              b_ii->data[b_idx - 1] = ii + 1;
              if (b_idx >= nx) {
                exitg1 = true;
              } else {
                ii++;
              }
            } else {
              ii++;
            }
          }

          if (x->size[1] == 1) {
            if (b_idx == 0) {
              b_ii->size[0] = 1;
              b_ii->size[1] = 0;
            }
          } else {
            if (1 > b_idx) {
              nx = 0;
            } else {
              nx = b_idx;
            }

            i15 = d_ii->size[0] * d_ii->size[1];
            d_ii->size[0] = 1;
            d_ii->size[1] = nx;
            emxEnsureCapacity_int32_T(d_ii, i15);
            for (i15 = 0; i15 < nx; i15++) {
              d_ii->data[i15] = b_ii->data[i15];
            }

            i15 = b_ii->size[0] * b_ii->size[1];
            b_ii->size[0] = 1;
            b_ii->size[1] = d_ii->size[1];
            emxEnsureCapacity_int32_T(b_ii, i15);
            nx = d_ii->size[1];
            for (i15 = 0; i15 < nx; i15++) {
              b_ii->data[i15] = d_ii->data[i15];
            }
          }

          /* 'obsIQini:52' idx=idx+Lim(4); */
          jj = Lim->data[3];
          i15 = idx->size[0] * idx->size[1];
          idx->size[0] = 1;
          idx->size[1] = b_ii->size[1];
          emxEnsureCapacity_real_T(idx, i15);
          nx = b_ii->size[1];
          for (i15 = 0; i15 < nx; i15++) {
            idx->data[i15] = (double)b_ii->data[i15] + (double)jj;
          }

          /* 'obsIQini:53' Qtem2=Qtem(i,idx); */
          i15 = b_ProbXEst->size[0];
          b_ProbXEst->size[0] = idx->size[1];
          emxEnsureCapacity_real_T(b_ProbXEst, i15);
          nx = idx->size[1];
          for (i15 = 0; i15 < nx; i15++) {
            b_ProbXEst->data[i15] = idx->data[i15];
          }

          i15 = Qtem2->size[0] * Qtem2->size[1];
          Qtem2->size[0] = 1;
          Qtem2->size[1] = b_ProbXEst->size[0];
          emxEnsureCapacity_real_T(Qtem2, i15);
          nx = b_ProbXEst->size[0];
          for (i15 = 0; i15 < nx; i15++) {
            Qtem2->data[i15] = Qtem->data[i + Qtem->size[0] * ((int)
              b_ProbXEst->data[i15] - 1)];
          }
        }

        /* 'obsIQini:56' r=Pmax*rand; */
        r = Pmax * d_rand();

        /* 'obsIQini:59' for j=1:length(Qtem2) */
        j = 0;
        exitg1 = false;
        while ((!exitg1) && (j <= Qtem2->size[1] - 1)) {
          /* 'obsIQini:61' if sum(Qtem2(1:j),2)<=r && sum(Qtem2(1:j+1),2)>r */
          nx = j + 1;
          i15 = b_Qtem->size[0] * b_Qtem->size[1];
          b_Qtem->size[0] = 1;
          b_Qtem->size[1] = j + 1;
          emxEnsureCapacity_real_T(b_Qtem, i15);
          for (i15 = 0; i15 < nx; i15++) {
            b_Qtem->data[i15] = Qtem2->data[i15];
          }

          guard1 = false;
          if (sum(b_Qtem) <= r) {
            jj = (int)(j + 2U);
            i15 = b_Qtem->size[0] * b_Qtem->size[1];
            b_Qtem->size[0] = 1;
            b_Qtem->size[1] = jj;
            emxEnsureCapacity_real_T(b_Qtem, i15);
            for (i15 = 0; i15 < jj; i15++) {
              b_Qtem->data[i15] = Qtem2->data[i15];
            }

            if (sum(b_Qtem) > r) {
              /* 'obsIQini:62' Obs(i,idx(j+1))=1; */
              Obs->data[i + Obs->size[0] * ((int)idx->data[j + 1] - 1)] = 1;

              /* 'obsIQini:63' Qtem = Qtem.*(1./(1-Qtem(:,idx(j+1)))); */
              nx = Qtem->size[0];
              b_idx = (int)idx->data[1 + j];
              i15 = r7->size[0];
              r7->size[0] = nx;
              emxEnsureCapacity_real_T(r7, i15);
              for (i15 = 0; i15 < nx; i15++) {
                r7->data[i15] = 1.0 - Qtem->data[i15 + Qtem->size[0] * (b_idx -
                  1)];
              }

              b_rdivide_helper(r7, b_ProbXEst);
              jj = Qtem->size[0];
              i15 = b_ProbXEst->size[0];
              b_ProbXEst->size[0] = jj;
              emxEnsureCapacity_real_T(b_ProbXEst, i15);
              for (i15 = 0; i15 < jj; i15++) {
                b_ProbXEst->data[i15] *= Qtem->data[i15];
              }

              jj = b_ProbXEst->size[0];
              i15 = Qtem->size[0] * Qtem->size[1];
              Qtem->size[0] = jj;
              Qtem->size[1] = 1;
              emxEnsureCapacity_real_T(Qtem, i15);
              for (i15 = 0; i15 < 1; i15++) {
                for (ii = 0; ii < jj; ii++) {
                  Qtem->data[ii] = b_ProbXEst->data[ii];
                }
              }

              /* 'obsIQini:64' Qtem(:,idx(j+1))=0; */
              nx = b_ProbXEst->size[0];
              for (i15 = 0; i15 < nx; i15++) {
                Qtem->data[i15] = 0.0;
              }

              exitg1 = true;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            nx = j + 1;
            i15 = b_Qtem->size[0] * b_Qtem->size[1];
            b_Qtem->size[0] = 1;
            b_Qtem->size[1] = j + 1;
            emxEnsureCapacity_real_T(b_Qtem, i15);
            for (i15 = 0; i15 < nx; i15++) {
              b_Qtem->data[i15] = Qtem2->data[i15];
            }

            if (sum(b_Qtem) > r) {
              /* 'obsIQini:66' elseif sum(Qtem2(1:j),2)>r */
              /* 'obsIQini:67' Obs(i,idx(j))=1; */
              Obs->data[i + Obs->size[0] * ((int)idx->data[j] - 1)] = 1;

              /* 'obsIQini:68' Qtem = Qtem.*(1./(1-Qtem(:,idx(j)))); */
              nx = Qtem->size[0];
              b_idx = (int)idx->data[j];
              i15 = r7->size[0];
              r7->size[0] = nx;
              emxEnsureCapacity_real_T(r7, i15);
              for (i15 = 0; i15 < nx; i15++) {
                r7->data[i15] = 1.0 - Qtem->data[i15 + Qtem->size[0] * (b_idx -
                  1)];
              }

              b_rdivide_helper(r7, b_ProbXEst);
              jj = Qtem->size[0];
              i15 = b_ProbXEst->size[0];
              b_ProbXEst->size[0] = jj;
              emxEnsureCapacity_real_T(b_ProbXEst, i15);
              for (i15 = 0; i15 < jj; i15++) {
                b_ProbXEst->data[i15] *= Qtem->data[i15];
              }

              jj = b_ProbXEst->size[0];
              i15 = Qtem->size[0] * Qtem->size[1];
              Qtem->size[0] = jj;
              Qtem->size[1] = 1;
              emxEnsureCapacity_real_T(Qtem, i15);
              for (i15 = 0; i15 < 1; i15++) {
                for (ii = 0; ii < jj; ii++) {
                  Qtem->data[ii] = b_ProbXEst->data[ii];
                }
              }

              /* 'obsIQini:69' Qtem(:,idx(j))=0; */
              nx = b_ProbXEst->size[0];
              for (i15 = 0; i15 < nx; i15++) {
                Qtem->data[i15] = 0.0;
              }

              exitg1 = true;
            } else {
              j++;
            }
          }
        }
      }

      /* 'obsIQini:76' [List(:,u),~]=find(Obs'==1); */
      i15 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = Obs->size[1];
      b_x->size[1] = Obs->size[0];
      emxEnsureCapacity_boolean_T(b_x, i15);
      nx = Obs->size[0];
      for (i15 = 0; i15 < nx; i15++) {
        jj = Obs->size[1];
        for (ii = 0; ii < jj; ii++) {
          b_x->data[ii + b_x->size[0] * i15] = (Obs->data[i15 + Obs->size[0] *
            ii] == 1);
        }
      }

      nx = b_x->size[0] * b_x->size[1];
      if (nx == 0) {
        c_ii->size[0] = 0;
      } else {
        b_idx = 0;
        i15 = c_ii->size[0];
        c_ii->size[0] = nx;
        emxEnsureCapacity_int32_T(c_ii, i15);
        ii = 1;
        jj = 1;
        exitg1 = false;
        while ((!exitg1) && (jj <= b_x->size[1])) {
          guard1 = false;
          if (b_x->data[(ii + b_x->size[0] * (jj - 1)) - 1]) {
            b_idx++;
            c_ii->data[b_idx - 1] = ii;
            if (b_idx >= nx) {
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
          if (b_idx == 0) {
            c_ii->size[0] = 0;
          }
        } else {
          i15 = c_ii->size[0];
          if (1 > b_idx) {
            c_ii->size[0] = 0;
          } else {
            c_ii->size[0] = b_idx;
          }

          emxEnsureCapacity_int32_T(c_ii, i15);
        }
      }

      nx = c_ii->size[0];
      for (i15 = 0; i15 < nx; i15++) {
        List->data[i15 + List->size[0] * u] = c_ii->data[i15];
      }

      /* 'obsIQini:76' ~ */
    }

    /* 'obsIQini:80' newIC(:,(k-1)*numObsIQ+1:k*numObsIQ) = List; */
    i15 = k * numObsIQ;
    if (i15 + 1 > (k + 1) * numObsIQ) {
      i15 = 0;
    }

    nx = List->size[1];
    for (ii = 0; ii < nx; ii++) {
      loop_ub = List->size[0];
      for (jj = 0; jj < loop_ub; jj++) {
        newIC->data[jj + newIC->size[0] * (i15 + ii)] = (int)List->data[jj +
          List->size[0] * ii];
      }
    }

    /* 'obsIQini:81' List = zeros(numGen,numObsIQ); */
    i15 = List->size[0] * List->size[1];
    List->size[0] = numGen;
    List->size[1] = numObsIQ;
    emxEnsureCapacity_real_T(List, i15);
    for (i15 = 0; i15 < numObsIQ; i15++) {
      for (ii = 0; ii < numGen; ii++) {
        List->data[ii + List->size[0] * i15] = 0.0;
      }
    }
  }

  emxFree_real_T(&r7);
  emxFree_int32_T(&d_ii);
  emxFree_real_T(&b_Qtem);
  emxFree_real_T(&b_ProbXEst);
  emxFree_int32_T(&c_ii);
  emxFree_boolean_T(&b_x);
  emxFree_int32_T(&b_ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&Qtem2);
  emxFree_real_T(&idx);
  emxFree_real_T(&Qtem);
  emxFree_int8_T(&Obs);
  emxFree_real_T(&Q);
  emxFree_real_T(&List);
  emxFree_int32_T(&Lim);
}

/* End of code generation (obsIQini.c) */
