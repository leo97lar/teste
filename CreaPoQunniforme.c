/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: CreaPoQunniforme.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "CreaPoQunniforme.h"
#include "model_emxutil.h"

/* Function Definitions */

/*
 * function [ IQ ] = CreaPoQunniforme( NumTOp,ctdadIQ )
 * UNTITLED3 Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : int NumTOp
 *                int ctdadIQ
 *                emxArray_real_T *IQ
 * Return Type  : void
 */
void CreaPoQunniforme(int NumTOp, int ctdadIQ, emxArray_real_T *IQ)
{
  emxArray_real_T *a;
  int i21;
  int outsize_idx_0;
  int outsize_idx_1;
  int offset;
  int k;
  int na;
  int b_k;
  emxInit_real_T(&a, 2);

  /* 'CreaPoQunniforme:5' Qini = ones(NumTOp,NumTOp)/double(NumTOp); */
  i21 = a->size[0] * a->size[1];
  a->size[1] = NumTOp;
  a->size[0] = NumTOp;
  emxEnsureCapacity_real_T(a, i21);
  for (i21 = 0; i21 < NumTOp; i21++) {
    for (outsize_idx_0 = 0; outsize_idx_0 < NumTOp; outsize_idx_0++) {
      a->data[outsize_idx_0 + a->size[1] * i21] = 1.0 / (double)NumTOp;
    }
  }

  /* 'CreaPoQunniforme:6' IQ=repmat(Qini,ctdadIQ,1); */
  outsize_idx_0 = a->size[0] * ctdadIQ;
  outsize_idx_1 = a->size[1];
  i21 = IQ->size[0] * IQ->size[1];
  IQ->size[1] = outsize_idx_1;
  IQ->size[0] = outsize_idx_0;
  emxEnsureCapacity_real_T(IQ, i21);
  if ((IQ->size[0] != 0) && (IQ->size[1] != 0)) {
    outsize_idx_0 = a->size[0];
    i21 = ctdadIQ - 1;
    for (outsize_idx_1 = 0; outsize_idx_1 <= i21; outsize_idx_1++) {
      offset = outsize_idx_1 * outsize_idx_0;
      for (k = 0; k < outsize_idx_0; k++) {
        na = a->size[1];
        for (b_k = 0; b_k < na; b_k++) {
          IQ->data[b_k + IQ->size[1] * (offset + k)] = a->data[b_k + a->size[1] *
            k];
        }
      }
    }
  }

  emxFree_real_T(&a);
}

/*
 * File trailer for CreaPoQunniforme.c
 *
 * [EOF]
 */
