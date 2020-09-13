/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CreaPoQunniforme.c
 *
 * Code generation for function 'CreaPoQunniforme'
 *
 */

/* Include files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "CreaPoQunniforme.h"
#include "model_emxutil.h"

/* Function Definitions */

/*
 * function [ IQ ] = CreaPoQunniforme( NumTOp,ctdadIQ )
 */
void CreaPoQunniforme(int NumTOp, int ctdadIQ, emxArray_real_T *IQ)
{
  emxArray_real_T *a;
  int i14;
  int outsize_idx_0;
  int outsize_idx_1;
  int na;
  int t;
  int offset;
  int k;
  emxInit_real_T(&a, 2);

  /* UNTITLED3 Summary of this function goes here */
  /*    Detailed explanation goes here */
  /* 'CreaPoQunniforme:5' Qini = ones(NumTOp,NumTOp)/double(NumTOp); */
  i14 = a->size[0] * a->size[1];
  a->size[0] = NumTOp;
  a->size[1] = NumTOp;
  emxEnsureCapacity_real_T(a, i14);
  for (i14 = 0; i14 < NumTOp; i14++) {
    for (outsize_idx_0 = 0; outsize_idx_0 < NumTOp; outsize_idx_0++) {
      a->data[outsize_idx_0 + a->size[0] * i14] = 1.0 / (double)NumTOp;
    }
  }

  /* 'CreaPoQunniforme:6' IQ=repmat(Qini,ctdadIQ,1); */
  outsize_idx_0 = a->size[0] * ctdadIQ;
  outsize_idx_1 = a->size[1];
  i14 = IQ->size[0] * IQ->size[1];
  IQ->size[0] = outsize_idx_0;
  IQ->size[1] = outsize_idx_1;
  emxEnsureCapacity_real_T(IQ, i14);
  if ((IQ->size[0] != 0) && (IQ->size[1] != 0)) {
    outsize_idx_0 = a->size[1];
    for (outsize_idx_1 = 0; outsize_idx_1 < outsize_idx_0; outsize_idx_1++) {
      na = a->size[0];
      i14 = ctdadIQ - 1;
      for (t = 0; t <= i14; t++) {
        offset = t * na;
        for (k = 0; k < na; k++) {
          IQ->data[(offset + k) + IQ->size[0] * outsize_idx_1] = a->data[k +
            a->size[0] * outsize_idx_1];
        }
      }
    }
  }

  emxFree_real_T(&a);
}

/* End of code generation (CreaPoQunniforme.c) */
