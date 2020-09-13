/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_model_mex.c
 *
 * Code generation for function '_coder_model_mex'
 *
 */

/* Include files */
#include "_coder_model_api.h"
#include "_coder_model_mex.h"

/* Variable Definitions */
static const char * emlrtEntryPoints[20] = { "actIQ", "aevSPLap",
  "BDCreator_func", "Calendario", "casorandom", "cc",
  "Codificacion_de_dias_func", "CreaPoQunniforme", "Edade", "favalia",
  "funcionC", "funcionCPrO", "funcionCR", "funcionDia", "funcionRP",
  "main_UCI_func", "obsIQ", "obsIQini", "PLOTT_func", "sch" };

/* Function Declarations */
static void BDCreator_func_mexFunction(int32_T nlhs, int32_T nrhs);
static void Calendario_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs);
static void CreaPoQunniforme_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[2]);
static void Edade_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[3]);
static void PLOTT_func_mexFunction(int32_T nlhs, int32_T nrhs, const mxArray
  *prhs[1]);
static void actIQ_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[3]);
static void aevSPLap_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
  const mxArray *prhs[27]);
static void c_Codificacion_de_dias_func_mex(int32_T nlhs, int32_T nrhs);
static void casorandom_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
  const mxArray *prhs[14]);
static void cc_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const
  mxArray *prhs[4]);
static void favalia_mexFunction(int32_T nlhs, mxArray *plhs[6], int32_T nrhs,
  const mxArray *prhs[8]);
static void funcionCPrO_mexFunction(int32_T nlhs, mxArray *plhs[18], int32_T
  nrhs, const mxArray *prhs[19]);
static void funcionCR_mexFunction(int32_T nlhs, int32_T nrhs);
static void funcionC_mexFunction(int32_T nlhs, mxArray *plhs[18], int32_T nrhs,
  const mxArray *prhs[32]);
static void funcionDia_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
  const mxArray *prhs[8]);
static void funcionRP_mexFunction(int32_T nlhs, mxArray *plhs[18], int32_T nrhs,
  const mxArray *prhs[32]);
static void main_UCI_func_mexFunction(int32_T nlhs, int32_T nrhs);
static void obsIQ_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[3]);
static void obsIQini_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[4]);
static void sch_mexFunction(int32_T nlhs, mxArray *plhs[6], int32_T nrhs, const
  mxArray *prhs[19]);

/* Function Definitions */
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

static void Calendario_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs)
{
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        10, "Calendario");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "Calendario");
  }

  /* Call the function. */
  Calendario_api(nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

static void CreaPoQunniforme_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T
  nrhs, const mxArray *prhs[2])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        16, "CreaPoQunniforme");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 16,
                        "CreaPoQunniforme");
  }

  /* Call the function. */
  CreaPoQunniforme_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

static void Edade_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[3])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4, 5,
                        "Edade");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 5,
                        "Edade");
  }

  /* Call the function. */
  Edade_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

static void PLOTT_func_mexFunction(int32_T nlhs, int32_T nrhs, const mxArray
  *prhs[1])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        10, "PLOTT_func");
  }

  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "PLOTT_func");
  }

  /* Call the function. */
  PLOTT_func_api(prhs, nlhs);
}

static void actIQ_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[3])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4, 5,
                        "actIQ");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 5,
                        "actIQ");
  }

  /* Call the function. */
  actIQ_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

static void aevSPLap_mexFunction(int32_T nlhs, mxArray *plhs[2], int32_T nrhs,
  const mxArray *prhs[27])
{
  const mxArray *outputs[2];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 27) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 27, 4,
                        8, "aevSPLap");
  }

  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 8,
                        "aevSPLap");
  }

  /* Call the function. */
  aevSPLap_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

static void c_Codificacion_de_dias_func_mex(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        25, "Codificacion_de_dias_func");
  }

  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 25,
                        "Codificacion_de_dias_func");
  }

  /* Call the function. */
  Codificacion_de_dias_func_api(nlhs);
}

static void casorandom_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
  const mxArray *prhs[14])
{
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 14) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 14, 4,
                        10, "casorandom");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "casorandom");
  }

  /* Call the function. */
  casorandom_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

static void cc_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs, const
  mxArray *prhs[4])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4, 2,
                        "cc");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 2,
                        "cc");
  }

  /* Call the function. */
  cc_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

static void favalia_mexFunction(int32_T nlhs, mxArray *plhs[6], int32_T nrhs,
  const mxArray *prhs[8])
{
  const mxArray *outputs[6];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 8) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 8, 4, 7,
                        "favalia");
  }

  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 7,
                        "favalia");
  }

  /* Call the function. */
  favalia_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

static void funcionCPrO_mexFunction(int32_T nlhs, mxArray *plhs[18], int32_T
  nrhs, const mxArray *prhs[19])
{
  const mxArray *outputs[18];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 19) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 19, 4,
                        11, "funcionCPrO");
  }

  if (nlhs > 18) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "funcionCPrO");
  }

  /* Call the function. */
  funcionCPrO_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

static void funcionCR_mexFunction(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4, 9,
                        "funcionCR");
  }

  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "funcionCR");
  }

  /* Call the function. */
  funcionCR_api(nlhs);
}

static void funcionC_mexFunction(int32_T nlhs, mxArray *plhs[18], int32_T nrhs,
  const mxArray *prhs[32])
{
  const mxArray *outputs[18];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 32) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 32, 4,
                        8, "funcionC");
  }

  if (nlhs > 18) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 8,
                        "funcionC");
  }

  /* Call the function. */
  funcionC_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

static void funcionDia_mexFunction(int32_T nlhs, mxArray *plhs[3], int32_T nrhs,
  const mxArray *prhs[8])
{
  const mxArray *outputs[3];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 8) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 8, 4,
                        10, "funcionDia");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 10,
                        "funcionDia");
  }

  /* Call the function. */
  funcionDia_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

static void funcionRP_mexFunction(int32_T nlhs, mxArray *plhs[18], int32_T nrhs,
  const mxArray *prhs[32])
{
  const mxArray *outputs[18];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 32) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 32, 4,
                        9, "funcionRP");
  }

  if (nlhs > 18) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 9,
                        "funcionRP");
  }

  /* Call the function. */
  funcionRP_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

static void main_UCI_func_mexFunction(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        13, "main_UCI_func");
  }

  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 13,
                        "main_UCI_func");
  }

  /* Call the function. */
  main_UCI_func_api(nlhs);
}

static void obsIQ_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[3])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4, 5,
                        "obsIQ");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 5,
                        "obsIQ");
  }

  /* Call the function. */
  obsIQ_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

static void obsIQini_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[4])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 4) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 4, 4, 8,
                        "obsIQini");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 8,
                        "obsIQini");
  }

  /* Call the function. */
  obsIQini_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

static void sch_mexFunction(int32_T nlhs, mxArray *plhs[6], int32_T nrhs, const
  mxArray *prhs[19])
{
  const mxArray *outputs[6];
  int32_T b_nlhs;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 19) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 19, 4,
                        3, "sch");
  }

  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 3,
                        "sch");
  }

  /* Call the function. */
  sch_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexAtExit(model_atexit);

  /* Module initialization. */
  model_initialize();
  st.tls = emlrtRootTLSGlobal;

  /* Dispatch the entry-point. */
  switch (emlrtGetEntryPointIndexR2016a(&st, nrhs, prhs, emlrtEntryPoints, 20))
  {
   case 0:
    actIQ_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[3])&prhs[1]);
    break;

   case 1:
    aevSPLap_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[27])&prhs[1]);
    break;

   case 2:
    BDCreator_func_mexFunction(nlhs, nrhs - 1);
    break;

   case 3:
    Calendario_mexFunction(nlhs, plhs, nrhs - 1);
    break;

   case 4:
    casorandom_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[14])&prhs
      [1]);
    break;

   case 5:
    cc_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[4])&prhs[1]);
    break;

   case 6:
    c_Codificacion_de_dias_func_mex(nlhs, nrhs - 1);
    break;

   case 7:
    CreaPoQunniforme_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[2])&
      prhs[1]);
    break;

   case 8:
    Edade_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[3])&prhs[1]);
    break;

   case 9:
    favalia_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[8])&prhs[1]);
    break;

   case 10:
    funcionC_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[32])&prhs[1]);
    break;

   case 11:
    funcionCPrO_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[19])&
      prhs[1]);
    break;

   case 12:
    funcionCR_mexFunction(nlhs, nrhs - 1);
    break;

   case 13:
    funcionDia_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[8])&prhs[1]);
    break;

   case 14:
    funcionRP_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[32])&prhs[1]);
    break;

   case 15:
    main_UCI_func_mexFunction(nlhs, nrhs - 1);
    break;

   case 16:
    obsIQ_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[3])&prhs[1]);
    break;

   case 17:
    obsIQini_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[4])&prhs[1]);
    break;

   case 18:
    PLOTT_func_mexFunction(nlhs, nrhs - 1, *(const mxArray *(*)[1])&prhs[1]);
    break;

   case 19:
    sch_mexFunction(nlhs, plhs, nrhs - 1, *(const mxArray *(*)[19])&prhs[1]);
    break;
  }

  /* Module termination. */
  model_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_model_mex.c) */
