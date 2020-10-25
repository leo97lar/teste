/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: obsIQ.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "obsIQ.h"
#include "model_emxutil.h"
#include "repmat.h"
#include "rdivide_helper.h"
#include "sum.h"
#include "rand.h"
#include "obsIQini.h"
#include "model_rtwutil.h"

/* Function Definitions */

/*
 * function [ newIC ] = obsIQ( IQ,numIQ,numObsIQ )
 * UNTITLED7 Summary of this function goes here
 *    Detailed explanation goes here,
 * Arguments    : const emxArray_real_T *IQ
 *                int numIQ
 *                int numObsIQ
 *                emxArray_int32_T *newIC
 * Return Type  : void
 */
void obsIQ(const emxArray_real_T *IQ, int numIQ, int numObsIQ, emxArray_int32_T *
           newIC)
{
  emxArray_int32_T *List;
  int numGen;
  int i25;
  int ii;
  emxArray_real_T *Q;
  emxArray_int8_T *Obs;
  emxArray_real_T *Qtem;
  emxArray_uint32_T *idx;
  emxArray_real_T *r17;
  emxArray_real_T *r18;
  emxArray_boolean_T *x;
  emxArray_int32_T *b_ii;
  emxArray_int32_T *r19;
  emxArray_boolean_T *b_x;
  emxArray_int32_T *c_ii;
  emxArray_int32_T *d_ii;
  emxArray_int32_T *e_ii;
  emxArray_real_T *r20;
  emxArray_real_T *r21;
  int k;
  int nx;
  int jj;
  int loop_ub;
  int u;
  unsigned int unnamed_idx_0;
  unsigned int unnamed_idx_1;
  int i;
  int b_idx;
  boolean_T exitg1;
  boolean_T guard1 = false;
  double r;
  int j;
  emxInit_int32_T(&List, 2);

  /* 'obsIQ:4' numGen=size(IQ,1)/numIQ; */
  numGen = (int)rt_roundd((double)IQ->size[0] / (double)numIQ);

  /* 'obsIQ:6' List = zeros(numGen,numObsIQ, 'int32'); */
  i25 = List->size[0] * List->size[1];
  List->size[1] = numObsIQ;
  List->size[0] = numGen;
  emxEnsureCapacity_int32_T(List, i25);
  for (i25 = 0; i25 < numGen; i25++) {
    for (ii = 0; ii < numObsIQ; ii++) {
      List->data[ii + List->size[1] * i25] = 0;
    }
  }

  /* 'obsIQ:7' newIC = repmat(List,1,numIQ); */
  b_repmat(List, numIQ, newIC);

  /* 'obsIQ:9' for k=1:numIQ */
  emxInit_real_T(&Q, 2);
  emxInit_int8_T(&Obs, 2);
  emxInit_real_T(&Qtem, 2);
  emxInit_uint32_T(&idx, 2);
  emxInit_real_T(&r17, 2);
  emxInit_real_T(&r18, 1);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&b_ii, 2);
  emxInit_int32_T(&r19, 1);
  emxInit_boolean_T(&b_x, 2);
  emxInit_int32_T(&c_ii, 1);
  emxInit_int32_T(&d_ii, 2);
  emxInit_int32_T(&e_ii, 1);
  emxInit_real_T(&r20, 2);
  emxInit_real_T(&r21, 1);
  for (k = 0; k < numIQ; k++) {
    /* 'obsIQ:11' Q = IQ((k-1)*numGen+1:k*numGen,:); */
    i25 = k * numGen;
    ii = (k + 1) * numGen;
    if (i25 + 1 > ii) {
      i25 = 0;
      ii = 0;
    }

    nx = IQ->size[1];
    jj = Q->size[0] * Q->size[1];
    Q->size[1] = nx;
    loop_ub = ii - i25;
    Q->size[0] = loop_ub;
    emxEnsureCapacity_real_T(Q, jj);
    for (ii = 0; ii < loop_ub; ii++) {
      for (jj = 0; jj < nx; jj++) {
        Q->data[jj + Q->size[1] * ii] = IQ->data[jj + IQ->size[1] * (i25 + ii)];
      }
    }

    /* 'obsIQ:13' for u=1:numObsIQ */
    for (u = 0; u < numObsIQ; u++) {
      /* 'obsIQ:15' Obs = zeros(size(Q), 'int32'); */
      i25 = IQ->size[1];
      unnamed_idx_0 = (unsigned int)loop_ub;
      unnamed_idx_1 = (unsigned int)i25;
      i25 = Obs->size[0] * Obs->size[1];
      Obs->size[1] = (int)unnamed_idx_1;
      Obs->size[0] = (int)unnamed_idx_0;
      emxEnsureCapacity_int8_T(Obs, i25);
      nx = (int)unnamed_idx_0;
      for (i25 = 0; i25 < nx; i25++) {
        jj = (int)unnamed_idx_1;
        for (ii = 0; ii < jj; ii++) {
          Obs->data[ii + Obs->size[1] * i25] = 0;
        }
      }

      /* 'obsIQ:16' Qtem = Q; */
      i25 = Qtem->size[0] * Qtem->size[1];
      Qtem->size[1] = Q->size[1];
      Qtem->size[0] = Q->size[0];
      emxEnsureCapacity_real_T(Qtem, i25);
      nx = Q->size[0];
      for (i25 = 0; i25 < nx; i25++) {
        jj = Q->size[1];
        for (ii = 0; ii < jj; ii++) {
          Qtem->data[ii + Qtem->size[1] * i25] = Q->data[ii + Q->size[1] * i25];
        }
      }

      /* 'obsIQ:18' for i=1:numGen */
      for (i = 0; i < numGen; i++) {
        /* 'obsIQ:20' idx=find(Qtem(i,:)~=0); */
        nx = Qtem->size[1];
        i25 = x->size[0] * x->size[1];
        x->size[1] = nx;
        x->size[0] = 1;
        emxEnsureCapacity_boolean_T(x, i25);
        for (i25 = 0; i25 < nx; i25++) {
          x->data[i25] = (Qtem->data[i25 + Qtem->size[1] * i] != 0.0);
        }

        nx = x->size[1];
        b_idx = 0;
        unnamed_idx_1 = (unsigned int)x->size[1];
        i25 = b_ii->size[0] * b_ii->size[1];
        b_ii->size[1] = (int)unnamed_idx_1;
        b_ii->size[0] = 1;
        emxEnsureCapacity_int32_T(b_ii, i25);
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
            b_ii->size[1] = 0;
            b_ii->size[0] = 1;
          }
        } else {
          if (1 > b_idx) {
            nx = 0;
          } else {
            nx = b_idx;
          }

          i25 = r19->size[0];
          r19->size[0] = nx;
          emxEnsureCapacity_int32_T(r19, i25);
          for (i25 = 0; i25 < nx; i25++) {
            r19->data[i25] = i25;
          }

          jj = r19->size[0];
          i25 = d_ii->size[0] * d_ii->size[1];
          d_ii->size[1] = jj;
          d_ii->size[0] = 1;
          emxEnsureCapacity_int32_T(d_ii, i25);
          for (i25 = 0; i25 < jj; i25++) {
            d_ii->data[i25] = b_ii->data[r19->data[i25]];
          }

          i25 = b_ii->size[0] * b_ii->size[1];
          b_ii->size[1] = d_ii->size[1];
          b_ii->size[0] = 1;
          emxEnsureCapacity_int32_T(b_ii, i25);
          nx = d_ii->size[1];
          for (i25 = 0; i25 < nx; i25++) {
            b_ii->data[i25] = d_ii->data[i25];
          }
        }

        i25 = idx->size[0] * idx->size[1];
        idx->size[1] = b_ii->size[1];
        idx->size[0] = 1;
        emxEnsureCapacity_uint32_T(idx, i25);
        nx = b_ii->size[1];
        for (i25 = 0; i25 < nx; i25++) {
          idx->data[i25] = (unsigned int)b_ii->data[i25];
        }

        /* 'obsIQ:21' Qtem2=Qtem(i,idx); */
        jj = idx->size[1];
        i25 = r18->size[0];
        r18->size[0] = jj;
        emxEnsureCapacity_real_T(r18, i25);
        for (i25 = 0; i25 < jj; i25++) {
          r18->data[i25] = Qtem->data[((int)idx->data[i25] + Qtem->size[1] * i)
            - 1];
        }

        /* 'obsIQ:22' r=rand; */
        r = d_rand();

        /* 'obsIQ:24' for j=1:length(Qtem2) */
        j = 0;
        exitg1 = false;
        while ((!exitg1) && (j <= idx->size[1] - 1)) {
          /* 'obsIQ:25' if sum(Qtem2(1:j),2)>r */
          i25 = r19->size[0];
          r19->size[0] = j + 1;
          emxEnsureCapacity_int32_T(r19, i25);
          for (i25 = 0; i25 <= j; i25++) {
            r19->data[i25] = i25;
          }

          jj = r19->size[0];
          i25 = r20->size[0] * r20->size[1];
          r20->size[1] = jj;
          r20->size[0] = 1;
          emxEnsureCapacity_real_T(r20, i25);
          for (i25 = 0; i25 < jj; i25++) {
            r20->data[i25] = r18->data[r19->data[i25]];
          }

          if (sum(r20) > r) {
            /* 'obsIQ:26' Obs(i,idx(j))=int32(1); */
            Obs->data[((int)idx->data[j] + Obs->size[1] * i) - 1] = 1;

            /* 'obsIQ:27' Qtem = (Qtem).*repmat((1./(1-Qtem(:,idx(j)))), 1, size(Qtem, 2)); */
            nx = Qtem->size[0];
            b_idx = (int)idx->data[j];
            i25 = r21->size[0];
            r21->size[0] = nx;
            emxEnsureCapacity_real_T(r21, i25);
            for (i25 = 0; i25 < nx; i25++) {
              r21->data[i25] = 1.0 - Qtem->data[(b_idx + Qtem->size[1] * i25) -
                1];
            }

            b_rdivide_helper(r21, r18);
            c_repmat(r18, Qtem->size[1], r17);
            i25 = Qtem->size[0] * Qtem->size[1];
            emxEnsureCapacity_real_T(Qtem, i25);
            nx = Qtem->size[0];
            for (i25 = 0; i25 < nx; i25++) {
              jj = Qtem->size[1];
              for (ii = 0; ii < jj; ii++) {
                Qtem->data[ii + Qtem->size[1] * i25] *= r17->data[ii + r17->
                  size[1] * i25];
              }
            }

            /* 'obsIQ:28' Qtem(:,idx(j))=0; */
            nx = Qtem->size[0];
            b_idx = (int)idx->data[j];
            for (i25 = 0; i25 < nx; i25++) {
              Qtem->data[(b_idx + Qtem->size[1] * i25) - 1] = 0.0;
            }

            exitg1 = true;
          } else {
            i25 = r19->size[0];
            r19->size[0] = j + 1;
            emxEnsureCapacity_int32_T(r19, i25);
            for (i25 = 0; i25 <= j; i25++) {
              r19->data[i25] = i25;
            }

            jj = r19->size[0];
            i25 = r20->size[0] * r20->size[1];
            r20->size[1] = jj;
            r20->size[0] = 1;
            emxEnsureCapacity_real_T(r20, i25);
            for (i25 = 0; i25 < jj; i25++) {
              r20->data[i25] = r18->data[r19->data[i25]];
            }

            if (sum(r20) <= r) {
              i25 = r19->size[0];
              r19->size[0] = j + 2;
              emxEnsureCapacity_int32_T(r19, i25);
              for (i25 = 0; i25 <= j + 1; i25++) {
                r19->data[i25] = i25;
              }

              jj = r19->size[0];
              i25 = r20->size[0] * r20->size[1];
              r20->size[1] = jj;
              r20->size[0] = 1;
              emxEnsureCapacity_real_T(r20, i25);
              for (i25 = 0; i25 < jj; i25++) {
                r20->data[i25] = r18->data[r19->data[i25]];
              }

              if (sum(r20) > r) {
                /* 'obsIQ:30' elseif sum(Qtem2(1:j),2)<=r && sum(Qtem2(1:j+1),2)>r */
                /* 'obsIQ:31' Obs(i,idx(j+1))=int32(1); */
                Obs->data[((int)idx->data[j + 1] + Obs->size[1] * i) - 1] = 1;

                /* 'obsIQ:32' Qtem = Qtem.*repmat((1./(1-Qtem(:,idx(j+1)))), 1, size(Qtem, 2)); */
                nx = Qtem->size[0];
                b_idx = (int)idx->data[1 + j];
                i25 = r21->size[0];
                r21->size[0] = nx;
                emxEnsureCapacity_real_T(r21, i25);
                for (i25 = 0; i25 < nx; i25++) {
                  r21->data[i25] = 1.0 - Qtem->data[(b_idx + Qtem->size[1] * i25)
                    - 1];
                }

                b_rdivide_helper(r21, r18);
                c_repmat(r18, Qtem->size[1], r17);
                i25 = Qtem->size[0] * Qtem->size[1];
                emxEnsureCapacity_real_T(Qtem, i25);
                nx = Qtem->size[0];
                for (i25 = 0; i25 < nx; i25++) {
                  jj = Qtem->size[1];
                  for (ii = 0; ii < jj; ii++) {
                    Qtem->data[ii + Qtem->size[1] * i25] *= r17->data[ii +
                      r17->size[1] * i25];
                  }
                }

                /* 'obsIQ:33' Qtem(:,idx(j+1))=0; */
                nx = Qtem->size[0];
                b_idx = (int)idx->data[j + 1];
                for (i25 = 0; i25 < nx; i25++) {
                  Qtem->data[(b_idx + Qtem->size[1] * i25) - 1] = 0.0;
                }

                exitg1 = true;
              } else {
                j++;
              }
            } else {
              j++;
            }
          }
        }
      }

      /* 'obsIQ:40' [List(:,u),~]=find(Obs'==1); */
      i25 = b_x->size[0] * b_x->size[1];
      b_x->size[1] = Obs->size[0];
      b_x->size[0] = Obs->size[1];
      emxEnsureCapacity_boolean_T(b_x, i25);
      nx = Obs->size[1];
      for (i25 = 0; i25 < nx; i25++) {
        jj = Obs->size[0];
        for (ii = 0; ii < jj; ii++) {
          b_x->data[ii + b_x->size[1] * i25] = (Obs->data[i25 + Obs->size[1] *
            ii] == 1);
        }
      }

      nx = b_x->size[0] * b_x->size[1];
      if (nx == 0) {
        c_ii->size[0] = 0;
      } else {
        b_idx = 0;
        i25 = c_ii->size[0];
        c_ii->size[0] = nx;
        emxEnsureCapacity_int32_T(c_ii, i25);
        ii = 1;
        jj = 1;
        exitg1 = false;
        while ((!exitg1) && (jj <= b_x->size[1])) {
          guard1 = false;
          if (b_x->data[(jj + b_x->size[1] * (ii - 1)) - 1]) {
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
          if (1 > b_idx) {
            nx = 0;
          } else {
            nx = b_idx;
          }

          i25 = r19->size[0];
          r19->size[0] = nx;
          emxEnsureCapacity_int32_T(r19, i25);
          for (i25 = 0; i25 < nx; i25++) {
            r19->data[i25] = i25;
          }

          jj = r19->size[0];
          i25 = e_ii->size[0];
          e_ii->size[0] = jj;
          emxEnsureCapacity_int32_T(e_ii, i25);
          for (i25 = 0; i25 < jj; i25++) {
            e_ii->data[i25] = c_ii->data[r19->data[i25]];
          }

          i25 = c_ii->size[0];
          c_ii->size[0] = e_ii->size[0];
          emxEnsureCapacity_int32_T(c_ii, i25);
          nx = e_ii->size[0];
          for (i25 = 0; i25 < nx; i25++) {
            c_ii->data[i25] = e_ii->data[i25];
          }
        }
      }

      jj = c_ii->size[0];
      for (i25 = 0; i25 < jj; i25++) {
        List->data[u + List->size[1] * i25] = c_ii->data[i25];
      }

      /* 'obsIQ:40' ~ */
    }

    /* 'obsIQ:44' newIC(:,(k-1)*numObsIQ+1:k*numObsIQ) = List; */
    i25 = k * numObsIQ;
    if (i25 + 1 > (k + 1) * numObsIQ) {
      i25 = 0;
    }

    nx = List->size[0];
    for (ii = 0; ii < nx; ii++) {
      loop_ub = List->size[1];
      for (jj = 0; jj < loop_ub; jj++) {
        newIC->data[(i25 + jj) + newIC->size[1] * ii] = List->data[jj +
          List->size[1] * ii];
      }
    }

    /* 'obsIQ:45' List = zeros(numGen,numObsIQ, 'int32'); */
    i25 = List->size[0] * List->size[1];
    List->size[1] = numObsIQ;
    List->size[0] = numGen;
    emxEnsureCapacity_int32_T(List, i25);
    for (i25 = 0; i25 < numGen; i25++) {
      for (ii = 0; ii < numObsIQ; ii++) {
        List->data[ii + List->size[1] * i25] = 0;
      }
    }
  }

  emxFree_real_T(&r21);
  emxFree_real_T(&r20);
  emxFree_int32_T(&e_ii);
  emxFree_int32_T(&d_ii);
  emxFree_int32_T(&c_ii);
  emxFree_boolean_T(&b_x);
  emxFree_int32_T(&r19);
  emxFree_int32_T(&b_ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&r18);
  emxFree_real_T(&r17);
  emxFree_uint32_T(&idx);
  emxFree_real_T(&Qtem);
  emxFree_int8_T(&Obs);
  emxFree_real_T(&Q);
  emxFree_int32_T(&List);
}

/*
 * File trailer for obsIQ.c
 *
 * [EOF]
 */
