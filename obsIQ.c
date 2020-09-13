/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * obsIQ.c
 *
 * Code generation for function 'obsIQ'
 *
 */

/* Include files */
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
 */
void obsIQ(const emxArray_real_T *IQ, int numIQ, int numObsIQ, emxArray_int32_T *
           newIC)
{
  emxArray_int32_T *List;
  int numGen;
  int i18;
  int ii;
  emxArray_real_T *Q;
  emxArray_int8_T *Obs;
  emxArray_real_T *Qtem;
  emxArray_uint32_T *idx;
  emxArray_real_T *Qtem2;
  emxArray_real_T *r8;
  emxArray_boolean_T *x;
  emxArray_int32_T *b_ii;
  emxArray_boolean_T *b_x;
  emxArray_int32_T *c_ii;
  emxArray_real_T *r9;
  emxArray_int32_T *d_ii;
  emxArray_real_T *b_Qtem2;
  emxArray_real_T *r10;
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
  int exitg2;
  emxInit_int32_T(&List, 2);

  /* UNTITLED7 Summary of this function goes here */
  /*    Detailed explanation goes here, */
  /* 'obsIQ:4' numGen=size(IQ,1)/numIQ; */
  numGen = (int)rt_roundd((double)IQ->size[0] / (double)numIQ);

  /* 'obsIQ:6' List = zeros(numGen,numObsIQ, 'int32'); */
  i18 = List->size[0] * List->size[1];
  List->size[0] = numGen;
  List->size[1] = numObsIQ;
  emxEnsureCapacity_int32_T(List, i18);
  for (i18 = 0; i18 < numObsIQ; i18++) {
    for (ii = 0; ii < numGen; ii++) {
      List->data[ii + List->size[0] * i18] = 0;
    }
  }

  /* 'obsIQ:7' newIC = repmat(List,1,numIQ); */
  b_repmat(List, numIQ, newIC);

  /* 'obsIQ:9' for k=1:numIQ */
  emxInit_real_T(&Q, 2);
  emxInit_int8_T(&Obs, 2);
  emxInit_real_T(&Qtem, 2);
  emxInit_uint32_T(&idx, 2);
  emxInit_real_T(&Qtem2, 2);
  emxInit_real_T(&r8, 2);
  emxInit_boolean_T(&x, 2);
  emxInit_int32_T(&b_ii, 2);
  emxInit_boolean_T(&b_x, 2);
  emxInit_int32_T(&c_ii, 1);
  emxInit_real_T(&r9, 1);
  emxInit_int32_T(&d_ii, 2);
  emxInit_real_T(&b_Qtem2, 2);
  emxInit_real_T(&r10, 1);
  for (k = 0; k < numIQ; k++) {
    /* 'obsIQ:11' Q = IQ((k-1)*numGen+1:k*numGen,:); */
    i18 = k * numGen;
    ii = (k + 1) * numGen;
    if (i18 + 1 > ii) {
      i18 = 0;
      ii = 0;
    }

    nx = IQ->size[1];
    jj = Q->size[0] * Q->size[1];
    loop_ub = ii - i18;
    Q->size[0] = loop_ub;
    Q->size[1] = nx;
    emxEnsureCapacity_real_T(Q, jj);
    for (ii = 0; ii < nx; ii++) {
      for (jj = 0; jj < loop_ub; jj++) {
        Q->data[jj + Q->size[0] * ii] = IQ->data[(i18 + jj) + IQ->size[0] * ii];
      }
    }

    /* 'obsIQ:13' for u=1:numObsIQ */
    for (u = 0; u < numObsIQ; u++) {
      /* 'obsIQ:15' Obs = zeros(size(Q), 'int32'); */
      i18 = IQ->size[1];
      unnamed_idx_0 = (unsigned int)loop_ub;
      unnamed_idx_1 = (unsigned int)i18;
      i18 = Obs->size[0] * Obs->size[1];
      Obs->size[0] = (int)unnamed_idx_0;
      Obs->size[1] = (int)unnamed_idx_1;
      emxEnsureCapacity_int8_T(Obs, i18);
      nx = (int)unnamed_idx_1;
      for (i18 = 0; i18 < nx; i18++) {
        jj = (int)unnamed_idx_0;
        for (ii = 0; ii < jj; ii++) {
          Obs->data[ii + Obs->size[0] * i18] = 0;
        }
      }

      /* 'obsIQ:16' Qtem = Q; */
      i18 = Qtem->size[0] * Qtem->size[1];
      Qtem->size[0] = Q->size[0];
      Qtem->size[1] = Q->size[1];
      emxEnsureCapacity_real_T(Qtem, i18);
      nx = Q->size[1];
      for (i18 = 0; i18 < nx; i18++) {
        jj = Q->size[0];
        for (ii = 0; ii < jj; ii++) {
          Qtem->data[ii + Qtem->size[0] * i18] = Q->data[ii + Q->size[0] * i18];
        }
      }

      /* 'obsIQ:18' for i=1:numGen */
      for (i = 0; i < numGen; i++) {
        /* 'obsIQ:20' idx=find(Qtem(i,:)~=0); */
        nx = Qtem->size[1];
        i18 = x->size[0] * x->size[1];
        x->size[0] = 1;
        x->size[1] = nx;
        emxEnsureCapacity_boolean_T(x, i18);
        for (i18 = 0; i18 < nx; i18++) {
          x->data[i18] = (Qtem->data[i + Qtem->size[0] * i18] != 0.0);
        }

        nx = x->size[1];
        b_idx = 0;
        i18 = b_ii->size[0] * b_ii->size[1];
        b_ii->size[0] = 1;
        b_ii->size[1] = x->size[1];
        emxEnsureCapacity_int32_T(b_ii, i18);
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

          i18 = d_ii->size[0] * d_ii->size[1];
          d_ii->size[0] = 1;
          d_ii->size[1] = nx;
          emxEnsureCapacity_int32_T(d_ii, i18);
          for (i18 = 0; i18 < nx; i18++) {
            d_ii->data[i18] = b_ii->data[i18];
          }

          i18 = b_ii->size[0] * b_ii->size[1];
          b_ii->size[0] = 1;
          b_ii->size[1] = d_ii->size[1];
          emxEnsureCapacity_int32_T(b_ii, i18);
          nx = d_ii->size[1];
          for (i18 = 0; i18 < nx; i18++) {
            b_ii->data[i18] = d_ii->data[i18];
          }
        }

        i18 = idx->size[0] * idx->size[1];
        idx->size[0] = 1;
        idx->size[1] = b_ii->size[1];
        emxEnsureCapacity_uint32_T(idx, i18);
        nx = b_ii->size[1];
        for (i18 = 0; i18 < nx; i18++) {
          idx->data[i18] = (unsigned int)b_ii->data[i18];
        }

        /* 'obsIQ:21' Qtem2=Qtem(i,idx); */
        i18 = Qtem2->size[0] * Qtem2->size[1];
        Qtem2->size[0] = 1;
        Qtem2->size[1] = idx->size[1];
        emxEnsureCapacity_real_T(Qtem2, i18);
        nx = idx->size[1];
        for (i18 = 0; i18 < nx; i18++) {
          Qtem2->data[i18] = Qtem->data[i + Qtem->size[0] * ((int)idx->data[i18]
            - 1)];
        }

        /* 'obsIQ:22' r=rand; */
        r = d_rand();

        /* 'obsIQ:24' for j=1:length(Qtem2) */
        j = 0;
        do {
          exitg2 = 0;
          i18 = c_ii->size[0];
          c_ii->size[0] = idx->size[1];
          emxEnsureCapacity_int32_T(c_ii, i18);
          nx = idx->size[1];
          for (i18 = 0; i18 < nx; i18++) {
            c_ii->data[i18] = (int)idx->data[i18];
          }

          if (j <= c_ii->size[0] - 1) {
            /* 'obsIQ:25' if sum(Qtem2(1:j))>r */
            nx = j + 1;
            i18 = c_ii->size[0];
            c_ii->size[0] = idx->size[1];
            emxEnsureCapacity_int32_T(c_ii, i18);
            jj = idx->size[1];
            for (i18 = 0; i18 < jj; i18++) {
              c_ii->data[i18] = (int)idx->data[i18];
            }

            i18 = b_Qtem2->size[0] * b_Qtem2->size[1];
            b_Qtem2->size[0] = 1;
            b_Qtem2->size[1] = j + 1;
            emxEnsureCapacity_real_T(b_Qtem2, i18);
            for (i18 = 0; i18 < nx; i18++) {
              b_Qtem2->data[i18] = Qtem2->data[i18];
            }

            if (sum(b_Qtem2) > r) {
              /* 'obsIQ:26' Obs(i,idx(j))=int32(1); */
              Obs->data[i + Obs->size[0] * ((int)idx->data[j] - 1)] = 1;

              /* 'obsIQ:27' Qtem = (Qtem).*repmat((1./(1-Qtem(:,idx(j)))), 1, size(Qtem, 2)); */
              nx = Qtem->size[0];
              b_idx = (int)idx->data[j];
              i18 = r10->size[0];
              r10->size[0] = nx;
              emxEnsureCapacity_real_T(r10, i18);
              for (i18 = 0; i18 < nx; i18++) {
                r10->data[i18] = 1.0 - Qtem->data[i18 + Qtem->size[0] * (b_idx -
                  1)];
              }

              b_rdivide_helper(r10, r9);
              c_repmat(r9, Qtem->size[1], r8);
              i18 = Qtem->size[0] * Qtem->size[1];
              emxEnsureCapacity_real_T(Qtem, i18);
              nx = Qtem->size[1];
              for (i18 = 0; i18 < nx; i18++) {
                jj = Qtem->size[0];
                for (ii = 0; ii < jj; ii++) {
                  Qtem->data[ii + Qtem->size[0] * i18] *= r8->data[ii + r8->
                    size[0] * i18];
                }
              }

              /* 'obsIQ:28' Qtem(:,idx(j))=0; */
              nx = Qtem->size[0];
              b_idx = (int)idx->data[j];
              for (i18 = 0; i18 < nx; i18++) {
                Qtem->data[i18 + Qtem->size[0] * (b_idx - 1)] = 0.0;
              }

              exitg2 = 1;
            } else {
              nx = j + 1;
              i18 = b_Qtem2->size[0] * b_Qtem2->size[1];
              b_Qtem2->size[0] = 1;
              b_Qtem2->size[1] = j + 1;
              emxEnsureCapacity_real_T(b_Qtem2, i18);
              for (i18 = 0; i18 < nx; i18++) {
                b_Qtem2->data[i18] = Qtem2->data[i18];
              }

              if (sum(b_Qtem2) <= r) {
                jj = (int)(j + 2U);
                i18 = c_ii->size[0];
                c_ii->size[0] = idx->size[1];
                emxEnsureCapacity_int32_T(c_ii, i18);
                nx = idx->size[1];
                for (i18 = 0; i18 < nx; i18++) {
                  c_ii->data[i18] = (int)idx->data[i18];
                }

                i18 = b_Qtem2->size[0] * b_Qtem2->size[1];
                b_Qtem2->size[0] = 1;
                b_Qtem2->size[1] = jj;
                emxEnsureCapacity_real_T(b_Qtem2, i18);
                for (i18 = 0; i18 < jj; i18++) {
                  b_Qtem2->data[i18] = Qtem2->data[i18];
                }

                if (sum(b_Qtem2) > r) {
                  /* 'obsIQ:30' elseif sum(Qtem2(1:j))<=r && sum(Qtem2(1:j+1))>r */
                  /* 'obsIQ:31' Obs(i,idx(j+1))=int32(1); */
                  Obs->data[i + Obs->size[0] * ((int)idx->data[j + 1] - 1)] = 1;

                  /* 'obsIQ:32' Qtem = Qtem.*repmat((1./(1-Qtem(:,idx(j+1)))), 1, size(Qtem, 2)); */
                  nx = Qtem->size[0];
                  b_idx = (int)idx->data[j + 1];
                  i18 = r10->size[0];
                  r10->size[0] = nx;
                  emxEnsureCapacity_real_T(r10, i18);
                  for (i18 = 0; i18 < nx; i18++) {
                    r10->data[i18] = 1.0 - Qtem->data[i18 + Qtem->size[0] *
                      (b_idx - 1)];
                  }

                  b_rdivide_helper(r10, r9);
                  c_repmat(r9, Qtem->size[1], r8);
                  i18 = Qtem->size[0] * Qtem->size[1];
                  emxEnsureCapacity_real_T(Qtem, i18);
                  nx = Qtem->size[1];
                  for (i18 = 0; i18 < nx; i18++) {
                    jj = Qtem->size[0];
                    for (ii = 0; ii < jj; ii++) {
                      Qtem->data[ii + Qtem->size[0] * i18] *= r8->data[ii +
                        r8->size[0] * i18];
                    }
                  }

                  /* 'obsIQ:33' Qtem(:,idx(j+1))=0; */
                  nx = Qtem->size[0];
                  b_idx = (int)idx->data[j + 1];
                  for (i18 = 0; i18 < nx; i18++) {
                    Qtem->data[i18 + Qtem->size[0] * (b_idx - 1)] = 0.0;
                  }

                  exitg2 = 1;
                } else {
                  j++;
                }
              } else {
                j++;
              }
            }
          } else {
            exitg2 = 1;
          }
        } while (exitg2 == 0);
      }

      /* 'obsIQ:40' [List(:,u),~]=find(Obs'==1); */
      i18 = b_x->size[0] * b_x->size[1];
      b_x->size[0] = Obs->size[1];
      b_x->size[1] = Obs->size[0];
      emxEnsureCapacity_boolean_T(b_x, i18);
      nx = Obs->size[0];
      for (i18 = 0; i18 < nx; i18++) {
        jj = Obs->size[1];
        for (ii = 0; ii < jj; ii++) {
          b_x->data[ii + b_x->size[0] * i18] = (Obs->data[i18 + Obs->size[0] *
            ii] == 1);
        }
      }

      nx = b_x->size[0] * b_x->size[1];
      if (nx == 0) {
        c_ii->size[0] = 0;
      } else {
        b_idx = 0;
        i18 = c_ii->size[0];
        c_ii->size[0] = nx;
        emxEnsureCapacity_int32_T(c_ii, i18);
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
          i18 = c_ii->size[0];
          if (1 > b_idx) {
            c_ii->size[0] = 0;
          } else {
            c_ii->size[0] = b_idx;
          }

          emxEnsureCapacity_int32_T(c_ii, i18);
        }
      }

      nx = c_ii->size[0];
      for (i18 = 0; i18 < nx; i18++) {
        List->data[i18 + List->size[0] * u] = c_ii->data[i18];
      }

      /* 'obsIQ:40' ~ */
    }

    /* 'obsIQ:44' newIC(:,(k-1)*numObsIQ+1:k*numObsIQ) = List; */
    i18 = k * numObsIQ;
    if (i18 + 1 > (k + 1) * numObsIQ) {
      i18 = 0;
    }

    nx = List->size[1];
    for (ii = 0; ii < nx; ii++) {
      loop_ub = List->size[0];
      for (jj = 0; jj < loop_ub; jj++) {
        newIC->data[jj + newIC->size[0] * (i18 + ii)] = List->data[jj +
          List->size[0] * ii];
      }
    }

    /* 'obsIQ:45' List = zeros(numGen,numObsIQ, 'int32'); */
    i18 = List->size[0] * List->size[1];
    List->size[0] = numGen;
    List->size[1] = numObsIQ;
    emxEnsureCapacity_int32_T(List, i18);
    for (i18 = 0; i18 < numObsIQ; i18++) {
      for (ii = 0; ii < numGen; ii++) {
        List->data[ii + List->size[0] * i18] = 0;
      }
    }
  }

  emxFree_real_T(&r10);
  emxFree_real_T(&b_Qtem2);
  emxFree_int32_T(&d_ii);
  emxFree_real_T(&r9);
  emxFree_int32_T(&c_ii);
  emxFree_boolean_T(&b_x);
  emxFree_int32_T(&b_ii);
  emxFree_boolean_T(&x);
  emxFree_real_T(&r8);
  emxFree_real_T(&Qtem2);
  emxFree_uint32_T(&idx);
  emxFree_real_T(&Qtem);
  emxFree_int8_T(&Obs);
  emxFree_real_T(&Q);
  emxFree_int32_T(&List);
}

/* End of code generation (obsIQ.c) */
