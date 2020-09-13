/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_model_api.h
 *
 * Code generation for function '_coder_model_api'
 *
 */

#ifndef _CODER_MODEL_API_H
#define _CODER_MODEL_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_model_api.h"

/* Type Definitions */
#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void BDCreator_func(void);
extern void BDCreator_func_api(int32_T nlhs);
extern void main_UCI_func(emxArray_int32_T *CP, emxArray_int32_T *RO,
  emxArray_int32_T *CPO, emxArray_int32_T *CPrO, emxArray_int32_T *CR,
  emxArray_int32_T *Data, emxArray_int32_T *Dia, emxArray_int32_T *DispMExD,
  emxArray_int32_T *MA, emxArray_int32_T *MAn, emxArray_int32_T *ME,
  emxArray_int32_T *S, int32_T TipoOp, int32_T NumEsp, int32_T NumTOp, int32_T
  NumSalOp, int32_T NumCPO, int32_T NumCPrO, int32_T NumCR, int32_T NumMedEsp,
  int32_T NumEspxE, int32_T NumAsist, int32_T NumAnest, real_T k0, real_T k1,
  real_T k2, real_T k3, int32_T numIQ, int32_T numIC, real_T taxC, real_T taxE,
  real_T taxEQ, emxArray_real_T *ProbXEst, int32_T genToWidth, int32_T
  generations, boolean_T keeppriority);
extern void main_UCI_func_api(const mxArray * const prhs[36], int32_T nlhs);
extern void model_atexit(void);
extern void model_initialize(void);
extern void model_terminate(void);
extern void model_xil_shutdown(void);
extern void model_xil_terminate(void);

#endif

/* End of code generation (_coder_model_api.h) */
