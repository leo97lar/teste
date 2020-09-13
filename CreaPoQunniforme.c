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

/* Function Definitions */
void CreaPoQunniforme(int NumTOp, int ctdadIQ, emxArray_real_T *IQ)
{
  emxArray_real_T *Qini;
  int jcol;
  int outsize_idx_0;
  int outsize_idx_1;
  int iacol;
  int ibmat;
  int itilerow;
  int ibcol;
  int k;
  emxInit_real_T(&Qini, 2);

  /* UNTITLED3 Summary of this function goes here */
  /*    Detailed explanation goes here */
  jcol = Qini->size[0] * Qini->size[1];
  Qini->size[0] = NumTOp;
  Qini->size[1] = NumTOp;
  emxEnsureCapacity_real_T(Qini, jcol);
  outsize_idx_0 = NumTOp * NumTOp;
  for (jcol = 0; jcol < outsize_idx_0; jcol++) {
    Qini->data[jcol] = 1.0 / (double)NumTOp;
  }

  outsize_idx_0 = Qini->size[0] * ctdadIQ;
  outsize_idx_1 = Qini->size[1];
  jcol = IQ->size[0] * IQ->size[1];
  IQ->size[0] = outsize_idx_0;
  IQ->size[1] = outsize_idx_1;
  emxEnsureCapacity_real_T(IQ, jcol);
  outsize_idx_0 = Qini->size[0];
  outsize_idx_1 = Qini->size[1];
  for (jcol = 0; jcol < outsize_idx_1; jcol++) {
    iacol = jcol * outsize_idx_0;
    ibmat = jcol * (outsize_idx_0 * ctdadIQ) - 1;
    for (itilerow = 0; itilerow < ctdadIQ; itilerow++) {
      ibcol = ibmat + itilerow * outsize_idx_0;
      for (k = 0; k < outsize_idx_0; k++) {
        IQ->data[(ibcol + k) + 1] = Qini->data[iacol + k];
      }
    }
  }

  emxFree_real_T(&Qini);
}

/* End of code generation (CreaPoQunniforme.c) */
