/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_model_mex.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
#include "_coder_model_api.h"
#include "_coder_model_mex.h"

/* Variable Definitions */
static const char * emlrtEntryPoints[2] = { "BDCreator_func", "main_UCI_func" };

/* Function Declarations */
static void BDCreator_func_mexFunction(int32_T nlhs, int32_T nrhs);
static void main_UCI_func_mexFunction(int32_T nlhs, int32_T nrhs, const mxArray *
  prhs[36]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                int32_T nrhs
 * Return Type  : void
 */
static void BDCreator_func_mexFunction(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        14, "BDCreator_func");
  }

  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 14,
                        "BDCreator_func");
  }

  /* Call the function. */
  BDCreator_func_api(nlhs);
}

/*
 * Arguments    : int32_T nlhs
 *                int32_T nrhs
 *                const mxArray *prhs[36]
 * Return Type  : void
 */
static void main_UCI_func_mexFunction(int32_T nlhs, int32_T nrhs, const mxArray *
  prhs[36])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 36) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 36, 4,
                        13, "main_UCI_func");
  }

  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "main_UCI_func");
  }

  /* Call the function. */
  main_UCI_func_api(prhs, nlhs);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray * const plhs[]
 *                int32_T nrhs
 *                const mxArray * const prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)plhs;
  mexAtExit(model_atexit);

  /* Module initialization. */
  model_initialize();
  st.tls = emlrtRootTLSGlobal;

  /* Dispatch the entry-point. */
  switch (emlrtGetEntryPointIndexR2016a(&st, nrhs, prhs, emlrtEntryPoints, 2)) {
   case 0:
    BDCreator_func_mexFunction(nlhs, nrhs - 1);
    break;

   case 1:
    main_UCI_func_mexFunction(nlhs, nrhs - 1, *(const mxArray *(*)[36])&prhs[1]);
    break;
  }

  /* Module termination. */
  model_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_model_mex.c
 *
 * [EOF]
 */
