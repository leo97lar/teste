/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_model_api.c
 *
 * Code generation for function '_coder_model_api'
 *
 */

/* Include files */
#include <string.h>
#include "tmwtypes.h"
#include "_coder_model_api.h"
#include "_coder_model_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131482U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "model",                             /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y);
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static const mxArray *b_emlrt_marshallOut(const emxArray_int32_T *u);
static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *EspMedOp,
  const char_T *identifier, emxArray_int32_T *y);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *IC, const
  char_T *identifier, emxArray_int32_T *y);
static const mxArray *c_emlrt_marshallOut(const real_T u[87600]);
static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y);
static const mxArray *d_emlrt_marshallOut(const real_T u[2920]);
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *PCPO, const
  char_T *identifier, emxArray_int32_T *y);
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *taxAct,
  const char_T *identifier);
static const mxArray *e_emlrt_marshallOut(const emxArray_int32_T *u);
static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *IQ, const
  char_T *identifier, emxArray_real_T *y);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int32_T
  oldNumel);
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel);
static void emxFree_int32_T(emxArray_int32_T **pEmxArray);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *f_emlrt_marshallOut(const emxArray_real_T *u);
static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *trace,
  const char_T *identifier, emxArray_real_T *y);
static int32_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *NumTOp,
  const char_T *identifier);
static const mxArray *g_emlrt_marshallOut(const real_T u);
static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static int32_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static const mxArray *h_emlrt_marshallOut(const int32_T u);
static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static int32_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *NumRec,
  const char_T *identifier))[7];
static void i_emlrt_marshallOut(const emxArray_int32_T *u, const mxArray *y);
static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret);
static int32_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[7];
static real_T jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Dia, const
  char_T *identifier, emxArray_int32_T *y);
static int32_T kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y);
static int32_T (*lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[7];
static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Data, const
  char_T *identifier, emxArray_int32_T *y);
static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret);
static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y);
static void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret);
static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *TimeUsoRec,
  const char_T *identifier, emxArray_int32_T *y);
static void ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret);
static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y);
static real_T (*pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[5];
static real_T (*q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *ProbXEst,
  const char_T *identifier))[5];
static real_T (*qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[6];
static real_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[5];
static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret);
static real_T (*s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *fitnessB,
  const char_T *identifier))[6];
static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[6];
static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *DispMExD,
  const char_T *identifier, emxArray_int32_T *y);
static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y);
static void vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret);
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *EP, const
  char_T *identifier, emxArray_real_T *y);
static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *DiaOp, const
  char_T *identifier, emxArray_int32_T *y);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y)
{
  tb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  hb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *b_emlrt_marshallOut(const emxArray_int32_T *u)
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv1[1] = { 0 };

  y = NULL;
  m1 = emlrtCreateNumericArray(1, iv1, mxINT32_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m1, &u->data[0]);
  emlrtSetDimensions((mxArray *)m1, u->size, 1);
  emlrtAssign(&y, m1);
  return y;
}

static void bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *EspMedOp,
  const char_T *identifier, emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  cb_emlrt_marshallIn(sp, emlrtAlias(EspMedOp), &thisId, y);
  emlrtDestroyArray(&EspMedOp);
}

static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *IC, const
  char_T *identifier, emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(IC), &thisId, y);
  emlrtDestroyArray(&IC);
}

static const mxArray *c_emlrt_marshallOut(const real_T u[87600])
{
  const mxArray *y;
  const mxArray *m3;
  static const int32_T iv3[2] = { 0, 0 };

  static const int32_T iv4[2] = { 17520, 5 };

  y = NULL;
  m3 = emlrtCreateNumericArray(2, iv3, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m3, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m3, iv4, 2);
  emlrtAssign(&y, m3);
  return y;
}

static void cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y)
{
  ub_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y)
{
  ib_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *d_emlrt_marshallOut(const real_T u[2920])
{
  const mxArray *y;
  const mxArray *m4;
  static const int32_T iv5[2] = { 0, 0 };

  static const int32_T iv6[2] = { 730, 4 };

  y = NULL;
  m4 = emlrtCreateNumericArray(2, iv5, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m4, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m4, iv6, 2);
  emlrtAssign(&y, m4);
  return y;
}

static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *PCPO, const
  char_T *identifier, emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  eb_emlrt_marshallIn(sp, emlrtAlias(PCPO), &thisId, y);
  emlrtDestroyArray(&PCPO);
}

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *taxAct,
  const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(taxAct), &thisId);
  emlrtDestroyArray(&taxAct);
  return y;
}

static const mxArray *e_emlrt_marshallOut(const emxArray_int32_T *u)
{
  const mxArray *y;
  const mxArray *m5;
  static const int32_T iv7[2] = { 0, 0 };

  y = NULL;
  m5 = emlrtCreateNumericArray(2, iv7, mxINT32_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m5, &u->data[0]);
  emlrtSetDimensions((mxArray *)m5, u->size, 2);
  emlrtAssign(&y, m5);
  return y;
}

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y)
{
  vb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *IQ, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(IQ), &thisId, y);
  emlrtDestroyArray(&IQ);
}

static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 0, 0 };

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m0, &u->data[0]);
  emlrtSetDimensions((mxArray *)m0, u->size, 2);
  emlrtAssign(&y, m0);
  return y;
}

static void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int32_T
  oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = emlrtCallocMex((uint32_T)i, sizeof(int32_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int32_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }

    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel)
{
  int32_T newNumel;
  int32_T i;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }

  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel *= emxArray->size[i];
  }

  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }

    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i <<= 1;
      }
    }

    newData = emlrtCallocMex((uint32_T)i, sizeof(real_T));
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }

    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

static void emxFree_int32_T(emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int32_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }

    emlrtFreeMex((*pEmxArray)->size);
    emlrtFreeMex(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

static void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_int32_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_int32_T *)emlrtMallocMex(sizeof(emxArray_int32_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_int32_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(sp, (void *)pEmxArray, (void (*)(void *))
      emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

static real_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = jb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *f_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m7;
  static const int32_T iv9[1] = { 0 };

  y = NULL;
  m7 = emlrtCreateNumericArray(1, iv9, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m7, &u->data[0]);
  emlrtSetDimensions((mxArray *)m7, u->size, 1);
  emlrtAssign(&y, m7);
  return y;
}

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *trace,
  const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  gb_emlrt_marshallIn(sp, emlrtAlias(trace), &thisId, y);
  emlrtDestroyArray(&trace);
}

static int32_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *NumTOp,
  const char_T *identifier)
{
  int32_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = h_emlrt_marshallIn(sp, emlrtAlias(NumTOp), &thisId);
  emlrtDestroyArray(&NumTOp);
  return y;
}

static const mxArray *g_emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m8;
  y = NULL;
  m8 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m8);
  return y;
}

static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  wb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static int32_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int32_T y;
  y = kb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *h_emlrt_marshallOut(const int32_T u)
{
  const mxArray *y;
  const mxArray *m9;
  y = NULL;
  m9 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m9) = u;
  emlrtAssign(&y, m9);
  return y;
}

static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { -1, -1 };

  const boolean_T bv0[2] = { true, true };

  int32_T iv11[2];
  int32_T i0;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv0[0],
    iv11);
  ret->allocatedSize = iv11[0] * iv11[1];
  i0 = ret->size[0] * ret->size[1];
  ret->size[0] = iv11[0];
  ret->size[1] = iv11[1];
  emxEnsureCapacity_real_T(ret, i0);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static int32_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *NumRec,
  const char_T *identifier))[7]
{
  int32_T (*y)[7];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = j_emlrt_marshallIn(sp, emlrtAlias(NumRec), &thisId);
  emlrtDestroyArray(&NumRec);
  return y;
}
  static void i_emlrt_marshallOut(const emxArray_int32_T *u, const mxArray *y)
{
  emlrtMxSetData((mxArray *)y, &u->data[0]);
  emlrtSetDimensions((mxArray *)y, u->size, 2);
}

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret)
{
  static const int32_T dims[2] = { -1, -1 };

  const boolean_T bv1[2] = { true, true };

  int32_T iv12[2];
  int32_T i1;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "int32", false, 2U, dims, &bv1[0],
    iv12);
  ret->allocatedSize = iv12[0] * iv12[1];
  i1 = ret->size[0] * ret->size[1];
  ret->size[0] = iv12[0];
  ret->size[1] = iv12[1];
  emxEnsureCapacity_int32_T(ret, i1);
  ret->data = (int32_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static int32_T (*j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[7]
{
  int32_T (*y)[7];
  y = lb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 0U, &dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Dia, const
  char_T *identifier, emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  l_emlrt_marshallIn(sp, emlrtAlias(Dia), &thisId, y);
  emlrtDestroyArray(&Dia);
}

static int32_T kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  int32_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, msgId, src, "int32", false, 0U, &dims);
  ret = *(int32_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y)
{
  mb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static int32_T (*lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[7]
{
  int32_T (*ret)[7];
  static const int32_T dims[2] = { 1, 7 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "int32", false, 2U, dims);
  ret = (int32_T (*)[7])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Data,
  const char_T *identifier, emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  n_emlrt_marshallIn(sp, emlrtAlias(Data), &thisId, y);
  emlrtDestroyArray(&Data);
}

static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret)
{
  static const int32_T dims[2] = { -1, 4 };

  const boolean_T bv2[2] = { true, false };

  int32_T iv13[2];
  int32_T i2;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "int32", false, 2U, dims, &bv2[0],
    iv13);
  ret->allocatedSize = iv13[0] * iv13[1];
  i2 = ret->size[0] * ret->size[1];
  ret->size[0] = iv13[0];
  ret->size[1] = iv13[1];
  emxEnsureCapacity_int32_T(ret, i2);
  ret->data = (int32_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y)
{
  nb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret)
{
  static const int32_T dims[2] = { -1, 5 };

  const boolean_T bv3[2] = { true, false };

  int32_T iv14[2];
  int32_T i3;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "int32", false, 2U, dims, &bv3[0],
    iv14);
  ret->allocatedSize = iv14[0] * iv14[1];
  i3 = ret->size[0] * ret->size[1];
  ret->size[0] = iv14[0];
  ret->size[1] = iv14[1];
  emxEnsureCapacity_int32_T(ret, i3);
  ret->data = (int32_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *TimeUsoRec,
  const char_T *identifier, emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  p_emlrt_marshallIn(sp, emlrtAlias(TimeUsoRec), &thisId, y);
  emlrtDestroyArray(&TimeUsoRec);
}

static void ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret)
{
  static const int32_T dims[2] = { -1, 7 };

  const boolean_T bv4[2] = { true, false };

  int32_T iv15[2];
  int32_T i4;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "int32", false, 2U, dims, &bv4[0],
    iv15);
  ret->allocatedSize = iv15[0] * iv15[1];
  i4 = ret->size[0] * ret->size[1];
  ret->size[0] = iv15[0];
  ret->size[1] = iv15[1];
  emxEnsureCapacity_int32_T(ret, i4);
  ret->data = (int32_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y)
{
  ob_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T (*pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[5]
{
  real_T (*ret)[5];
  static const int32_T dims[1] = { 5 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims);
  ret = (real_T (*)[5])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*q_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *ProbXEst, const char_T *identifier))[5]
{
  real_T (*y)[5];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = r_emlrt_marshallIn(sp, emlrtAlias(ProbXEst), &thisId);
  emlrtDestroyArray(&ProbXEst);
  return y;
}

static real_T (*qb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[6]
{
  real_T (*ret)[6];
  static const int32_T dims[2] = { 1, 6 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[6])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
  static real_T (*r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId))[5]
{
  real_T (*y)[5];
  y = pb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void rb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret)
{
  static const int32_T dims[2] = { 6, -1 };

  const boolean_T bv5[2] = { false, true };

  int32_T iv16[2];
  int32_T i5;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "int32", false, 2U, dims, &bv5[0],
    iv16);
  ret->allocatedSize = iv16[0] * iv16[1];
  i5 = ret->size[0] * ret->size[1];
  ret->size[0] = iv16[0];
  ret->size[1] = iv16[1];
  emxEnsureCapacity_int32_T(ret, i5);
  ret->data = (int32_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T (*s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *fitnessB,
  const char_T *identifier))[6]
{
  real_T (*y)[6];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = t_emlrt_marshallIn(sp, emlrtAlias(fitnessB), &thisId);
  emlrtDestroyArray(&fitnessB);
  return y;
}
  static void sb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[1] = { -1 };

  const boolean_T bv6[1] = { true };

  int32_T iv17[1];
  int32_T i6;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 1U, dims, &bv6[0],
    iv17);
  ret->allocatedSize = iv17[0];
  i6 = ret->size[0];
  ret->size[0] = iv17[0];
  emxEnsureCapacity_real_T(ret, i6);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static real_T (*t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[6]
{
  real_T (*y)[6];
  y = qb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static void tb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId, emxArray_int32_T *ret)
{
  static const int32_T dims[1] = { -1 };

  const boolean_T bv7[1] = { true };

  int32_T iv18[1];
  int32_T i7;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "int32", false, 1U, dims, &bv7[0],
    iv18);
  ret->allocatedSize = iv18[0];
  i7 = ret->size[0];
  ret->size[0] = iv18[0];
  emxEnsureCapacity_int32_T(ret, i7);
  ret->data = (int32_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *DispMExD,
  const char_T *identifier, emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  v_emlrt_marshallIn(sp, emlrtAlias(DispMExD), &thisId, y);
  emlrtDestroyArray(&DispMExD);
}

static void ub_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret)
{
  static const int32_T dims[2] = { -1, 2 };

  const boolean_T bv8[2] = { true, false };

  int32_T iv19[2];
  int32_T i8;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "int32", false, 2U, dims, &bv8[0],
    iv19);
  ret->allocatedSize = iv19[0] * iv19[1];
  i8 = ret->size[0] * ret->size[1];
  ret->size[0] = iv19[0];
  ret->size[1] = iv19[1];
  emxEnsureCapacity_int32_T(ret, i8);
  ret->data = (int32_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y)
{
  rb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void vb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret)
{
  static const int32_T dims[2] = { 1, -1 };

  const boolean_T bv9[2] = { false, true };

  int32_T iv20[2];
  int32_T i9;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "int32", false, 2U, dims, &bv9[0],
    iv20);
  ret->allocatedSize = iv20[0] * iv20[1];
  i9 = ret->size[0] * ret->size[1];
  ret->size[0] = iv20[0];
  ret->size[1] = iv20[1];
  emxEnsureCapacity_int32_T(ret, i9);
  ret->data = (int32_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *EP, const
  char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  x_emlrt_marshallIn(sp, emlrtAlias(EP), &thisId, y);
  emlrtDestroyArray(&EP);
}

static void wb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[2] = { -1, 9 };

  const boolean_T bv10[2] = { true, false };

  int32_T iv21[2];
  int32_T i10;
  emlrtCheckVsBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims, &bv10[0],
    iv21);
  ret->allocatedSize = iv21[0] * iv21[1];
  i10 = ret->size[0] * ret->size[1];
  ret->size[0] = iv21[0];
  ret->size[1] = iv21[1];
  emxEnsureCapacity_real_T(ret, i10);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  sb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *DiaOp, const
  char_T *identifier, emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  ab_emlrt_marshallIn(sp, emlrtAlias(DiaOp), &thisId, y);
  emlrtDestroyArray(&DiaOp);
}

void BDCreator_func_api(int32_T nlhs)
{
  (void)nlhs;

  /* Invoke the target function */
  BDCreator_func();
}

void Calendario_api(int32_T nlhs, const mxArray *plhs[2])
{
  real_T (*Data)[87600];
  real_T (*Dia)[2920];
  Data = (real_T (*)[87600])mxMalloc(sizeof(real_T [87600]));
  Dia = (real_T (*)[2920])mxMalloc(sizeof(real_T [2920]));

  /* Invoke the target function */
  Calendario(*Data, *Dia);

  /* Marshall function outputs */
  plhs[0] = c_emlrt_marshallOut(*Data);
  if (nlhs > 1) {
    plhs[1] = d_emlrt_marshallOut(*Dia);
  }
}

void Codificacion_de_dias_func_api(int32_T nlhs)
{
  (void)nlhs;

  /* Invoke the target function */
  Codificacion_de_dias_func();
}

void CreaPoQunniforme_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[1])
{
  emxArray_real_T *IQ;
  int32_T NumTOp;
  int32_T ctdadIQ;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &IQ, 2, true);

  /* Marshall function inputs */
  NumTOp = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "NumTOp");
  ctdadIQ = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "ctdadIQ");

  /* Invoke the target function */
  CreaPoQunniforme(NumTOp, ctdadIQ, IQ);

  /* Marshall function outputs */
  IQ->canFreeData = false;
  plhs[0] = emlrt_marshallOut(IQ);
  emxFree_real_T(&IQ);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void Edade_api(const mxArray * const prhs[3], int32_T nlhs, const mxArray *plhs
               [1])
{
  emxArray_real_T *b_Edade;
  int32_T b_min;
  int32_T b_max;
  int32_T Num;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &b_Edade, 1, true);

  /* Marshall function inputs */
  b_min = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "min");
  b_max = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "max");
  Num = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "Num");

  /* Invoke the target function */
  Edade(b_min, b_max, Num, b_Edade);

  /* Marshall function outputs */
  b_Edade->canFreeData = false;
  plhs[0] = f_emlrt_marshallOut(b_Edade);
  emxFree_real_T(&b_Edade);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void PLOTT_func_api(const mxArray * const prhs[1], int32_T nlhs)
{
  emxArray_real_T *trace;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &trace, 2, true);

  /* Marshall function inputs */
  trace->canFreeData = false;
  fb_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "trace", trace);

  /* Invoke the target function */
  PLOTT_func(trace);
  emxFree_real_T(&trace);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void actIQ_api(const mxArray * const prhs[3], int32_T nlhs, const mxArray *plhs
               [1])
{
  emxArray_real_T *IQ;
  emxArray_int32_T *IC;
  emxArray_real_T *IQact;
  real_T taxAct;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &IQ, 2, true);
  emxInit_int32_T(&st, &IC, 2, true);
  emxInit_real_T(&st, &IQact, 2, true);

  /* Marshall function inputs */
  IQ->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "IQ", IQ);
  IC->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "IC", IC);
  taxAct = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "taxAct");

  /* Invoke the target function */
  actIQ(IQ, IC, taxAct, IQact);

  /* Marshall function outputs */
  IQact->canFreeData = false;
  plhs[0] = emlrt_marshallOut(IQact);
  emxFree_real_T(&IQact);
  emxFree_int32_T(&IC);
  emxFree_real_T(&IQ);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void aevSPLap_api(const mxArray * const prhs[27], int32_T nlhs, const mxArray
                  *plhs[2])
{
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *PME;
  emxArray_int32_T *PMA;
  emxArray_int32_T *PMAn;
  emxArray_int32_T *PS;
  emxArray_int32_T *PCPO;
  emxArray_int32_T *PCR;
  emxArray_int32_T *Dia;
  emxArray_int32_T *Data;
  emxArray_int32_T *TimeUsoRec;
  emxArray_int32_T *DispMExD;
  emxArray_real_T *EP;
  emxArray_int32_T *bestexperimento;
  emxArray_real_T *trace;
  int32_T NumTOp;
  int32_T numIC;
  int32_T numIQ;
  real_T taxC;
  real_T taxE;
  real_T taxEQ;
  int32_T (*NumRec)[7];
  real_T (*ProbXEst)[5];
  real_T (*fitnessB)[6];
  int32_T generations;
  int32_T genToWidth;
  real_T k0;
  real_T k1;
  real_T k2;
  real_T k3;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_int32_T(&st, &PCPrO, 2, true);
  emxInit_int32_T(&st, &PME, 2, true);
  emxInit_int32_T(&st, &PMA, 2, true);
  emxInit_int32_T(&st, &PMAn, 2, true);
  emxInit_int32_T(&st, &PS, 2, true);
  emxInit_int32_T(&st, &PCPO, 2, true);
  emxInit_int32_T(&st, &PCR, 2, true);
  emxInit_int32_T(&st, &Dia, 2, true);
  emxInit_int32_T(&st, &Data, 2, true);
  emxInit_int32_T(&st, &TimeUsoRec, 2, true);
  emxInit_int32_T(&st, &DispMExD, 2, true);
  emxInit_real_T(&st, &EP, 1, true);
  emxInit_int32_T(&st, &bestexperimento, 1, true);
  emxInit_real_T(&st, &trace, 2, true);

  /* Marshall function inputs */
  NumTOp = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "NumTOp");
  numIC = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "numIC");
  numIQ = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "numIQ");
  taxC = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "taxC");
  taxE = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "taxE");
  taxEQ = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "taxEQ");
  NumRec = i_emlrt_marshallIn(&st, emlrtAlias(prhs[6]), "NumRec");
  PCPrO->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "PCPrO", PCPrO);
  PME->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[8]), "PME", PME);
  PMA->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[9]), "PMA", PMA);
  PMAn->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[10]), "PMAn", PMAn);
  PS->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[11]), "PS", PS);
  PCPO->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[12]), "PCPO", PCPO);
  PCR->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[13]), "PCR", PCR);
  Dia->canFreeData = false;
  k_emlrt_marshallIn(&st, emlrtAlias(prhs[14]), "Dia", Dia);
  Data->canFreeData = false;
  m_emlrt_marshallIn(&st, emlrtAlias(prhs[15]), "Data", Data);
  TimeUsoRec->canFreeData = false;
  o_emlrt_marshallIn(&st, emlrtAlias(prhs[16]), "TimeUsoRec", TimeUsoRec);
  ProbXEst = q_emlrt_marshallIn(&st, emlrtAlias(prhs[17]), "ProbXEst");
  fitnessB = s_emlrt_marshallIn(&st, emlrtAlias(prhs[18]), "fitnessB");
  generations = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[19]), "generations");
  genToWidth = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[20]), "genToWidth");
  DispMExD->canFreeData = false;
  u_emlrt_marshallIn(&st, emlrtAlias(prhs[21]), "DispMExD", DispMExD);
  EP->canFreeData = false;
  w_emlrt_marshallIn(&st, emlrtAlias(prhs[22]), "EP", EP);
  k0 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[23]), "k0");
  k1 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[24]), "k1");
  k2 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[25]), "k2");
  k3 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[26]), "k3");

  /* Invoke the target function */
  aevSPLap(NumTOp, numIC, numIQ, taxC, taxE, taxEQ, *NumRec, PCPrO, PME, PMA,
           PMAn, PS, PCPO, PCR, Dia, Data, TimeUsoRec, *ProbXEst, *fitnessB,
           generations, genToWidth, DispMExD, EP, k0, k1, k2, k3,
           bestexperimento, trace);

  /* Marshall function outputs */
  bestexperimento->canFreeData = false;
  plhs[0] = b_emlrt_marshallOut(bestexperimento);
  emxFree_int32_T(&bestexperimento);
  emxFree_real_T(&EP);
  emxFree_int32_T(&DispMExD);
  emxFree_int32_T(&TimeUsoRec);
  emxFree_int32_T(&Data);
  emxFree_int32_T(&Dia);
  emxFree_int32_T(&PCR);
  emxFree_int32_T(&PCPO);
  emxFree_int32_T(&PS);
  emxFree_int32_T(&PMAn);
  emxFree_int32_T(&PMA);
  emxFree_int32_T(&PME);
  emxFree_int32_T(&PCPrO);
  if (nlhs > 1) {
    trace->canFreeData = false;
    plhs[1] = emlrt_marshallOut(trace);
  }

  emxFree_real_T(&trace);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void casorandom_api(const mxArray *prhs[14], int32_T nlhs, const mxArray *plhs[3])
{
  emxArray_int32_T *H;
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *PME;
  emxArray_int32_T *PMA;
  emxArray_int32_T *PMAn;
  emxArray_int32_T *PS;
  emxArray_int32_T *PCPO;
  emxArray_int32_T *PCR;
  emxArray_int32_T *Dia;
  emxArray_int32_T *UltPosRecXDia;
  emxArray_int32_T *TimeUsoRec;
  emxArray_int32_T *DispMExD;
  emxArray_int32_T *schedule;
  emxArray_int32_T *DiaOp;
  emxArray_int32_T *EspMedOp;
  const mxArray *prhs_copy_idx_0;
  const mxArray *prhs_copy_idx_1;
  const mxArray *prhs_copy_idx_2;
  const mxArray *prhs_copy_idx_3;
  const mxArray *prhs_copy_idx_4;
  const mxArray *prhs_copy_idx_5;
  const mxArray *prhs_copy_idx_6;
  const mxArray *prhs_copy_idx_7;
  const mxArray *prhs_copy_idx_8;
  const mxArray *prhs_copy_idx_9;
  const mxArray *prhs_copy_idx_10;
  const mxArray *prhs_copy_idx_11;
  int32_T NumTOp;
  int32_T (*NumRec)[7];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_int32_T(&st, &H, 2, true);
  emxInit_int32_T(&st, &PCPrO, 2, true);
  emxInit_int32_T(&st, &PME, 2, true);
  emxInit_int32_T(&st, &PMA, 2, true);
  emxInit_int32_T(&st, &PMAn, 2, true);
  emxInit_int32_T(&st, &PS, 2, true);
  emxInit_int32_T(&st, &PCPO, 2, true);
  emxInit_int32_T(&st, &PCR, 2, true);
  emxInit_int32_T(&st, &Dia, 2, true);
  emxInit_int32_T(&st, &UltPosRecXDia, 2, true);
  emxInit_int32_T(&st, &TimeUsoRec, 2, true);
  emxInit_int32_T(&st, &DispMExD, 2, true);
  emxInit_int32_T(&st, &schedule, 2, true);
  emxInit_int32_T(&st, &DiaOp, 1, true);
  emxInit_int32_T(&st, &EspMedOp, 2, true);
  prhs_copy_idx_0 = prhs[0];
  prhs_copy_idx_1 = emlrtProtectR2012b(prhs[1], 1, false, -1);
  prhs_copy_idx_2 = prhs[2];
  prhs_copy_idx_3 = prhs[3];
  prhs_copy_idx_4 = prhs[4];
  prhs_copy_idx_5 = prhs[5];
  prhs_copy_idx_6 = prhs[6];
  prhs_copy_idx_7 = prhs[7];
  prhs_copy_idx_8 = prhs[8];
  prhs_copy_idx_9 = prhs[9];
  prhs_copy_idx_10 = prhs[10];
  prhs_copy_idx_11 = emlrtProtectR2012b(prhs[11], 11, false, -1);

  /* Marshall function inputs */
  NumTOp = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_0), "NumTOp");
  H->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_1), "H", H);
  NumRec = i_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_2), "NumRec");
  PCPrO->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_3), "PCPrO", PCPrO);
  PME->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_4), "PME", PME);
  PMA->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_5), "PMA", PMA);
  PMAn->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_6), "PMAn", PMAn);
  PS->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_7), "PS", PS);
  PCPO->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_8), "PCPO", PCPO);
  PCR->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_9), "PCR", PCR);
  Dia->canFreeData = false;
  k_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_10), "Dia", Dia);
  UltPosRecXDia->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_11), "UltPosRecXDia",
                     UltPosRecXDia);
  TimeUsoRec->canFreeData = false;
  o_emlrt_marshallIn(&st, emlrtAlias(prhs[12]), "TimeUsoRec", TimeUsoRec);
  DispMExD->canFreeData = false;
  u_emlrt_marshallIn(&st, emlrtAlias(prhs[13]), "DispMExD", DispMExD);

  /* Invoke the target function */
  casorandom(NumTOp, H, *NumRec, PCPrO, PME, PMA, PMAn, PS, PCPO, PCR, Dia,
             UltPosRecXDia, TimeUsoRec, DispMExD, schedule, DiaOp, EspMedOp);

  /* Marshall function outputs */
  schedule->canFreeData = false;
  plhs[0] = e_emlrt_marshallOut(schedule);
  emxFree_int32_T(&schedule);
  emxFree_int32_T(&DispMExD);
  emxFree_int32_T(&TimeUsoRec);
  emxFree_int32_T(&UltPosRecXDia);
  emxFree_int32_T(&Dia);
  emxFree_int32_T(&PCR);
  emxFree_int32_T(&PCPO);
  emxFree_int32_T(&PS);
  emxFree_int32_T(&PMAn);
  emxFree_int32_T(&PMA);
  emxFree_int32_T(&PME);
  emxFree_int32_T(&PCPrO);
  emxFree_int32_T(&H);
  if (nlhs > 1) {
    DiaOp->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(DiaOp);
  }

  emxFree_int32_T(&DiaOp);
  if (nlhs > 2) {
    EspMedOp->canFreeData = false;
    plhs[2] = e_emlrt_marshallOut(EspMedOp);
  }

  emxFree_int32_T(&EspMedOp);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void cc_api(const mxArray * const prhs[4], int32_T nlhs, const mxArray *plhs[1])
{
  emxArray_int32_T *IC;
  emxArray_int32_T *newIC;
  int32_T numIC;
  real_T taxC;
  int32_T NumTOp;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_int32_T(&st, &IC, 2, true);
  emxInit_int32_T(&st, &newIC, 2, true);

  /* Marshall function inputs */
  IC->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "IC", IC);
  numIC = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "numIC");
  taxC = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "taxC");
  NumTOp = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "NumTOp");

  /* Invoke the target function */
  cc(IC, numIC, taxC, NumTOp, newIC);

  /* Marshall function outputs */
  newIC->canFreeData = false;
  plhs[0] = e_emlrt_marshallOut(newIC);
  emxFree_int32_T(&newIC);
  emxFree_int32_T(&IC);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void favalia_api(const mxArray *prhs[8], int32_T nlhs, const mxArray *plhs[6])
{
  emxArray_int32_T *schedule;
  emxArray_int32_T *DiaOp;
  emxArray_int32_T *EP;
  emxArray_int32_T *EspMedOp;
  const mxArray *prhs_copy_idx_0;
  const mxArray *prhs_copy_idx_1;
  const mxArray *prhs_copy_idx_2;
  const mxArray *prhs_copy_idx_3;
  real_T k0;
  real_T k1;
  real_T k2;
  real_T k3;
  real_T fitness;
  real_T Tt;
  real_T NOFP;
  real_T TmNOFP;
  real_T NOE2;
  real_T NOE3;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_int32_T(&st, &schedule, 2, true);
  emxInit_int32_T(&st, &DiaOp, 1, true);
  emxInit_int32_T(&st, &EP, 1, true);
  emxInit_int32_T(&st, &EspMedOp, 2, true);
  prhs_copy_idx_0 = prhs[0];
  prhs_copy_idx_1 = prhs[1];
  prhs_copy_idx_2 = prhs[2];
  prhs_copy_idx_3 = emlrtProtectR2012b(prhs[3], 3, false, -1);

  /* Marshall function inputs */
  schedule->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "schedule", schedule);
  DiaOp->canFreeData = false;
  y_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_1), "DiaOp", DiaOp);
  EP->canFreeData = false;
  y_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_2), "EP", EP);
  EspMedOp->canFreeData = false;
  bb_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_3), "EspMedOp", EspMedOp);
  k0 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "k0");
  k1 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "k1");
  k2 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "k2");
  k3 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "k3");

  /* Invoke the target function */
  favalia(schedule, DiaOp, EP, EspMedOp, k0, k1, k2, k3, &fitness, &Tt, &NOFP,
          &TmNOFP, &NOE2, &NOE3);

  /* Marshall function outputs */
  plhs[0] = g_emlrt_marshallOut(fitness);
  emxFree_int32_T(&EspMedOp);
  emxFree_int32_T(&EP);
  emxFree_int32_T(&DiaOp);
  emxFree_int32_T(&schedule);
  if (nlhs > 1) {
    plhs[1] = g_emlrt_marshallOut(Tt);
  }

  if (nlhs > 2) {
    plhs[2] = g_emlrt_marshallOut(NOFP);
  }

  if (nlhs > 3) {
    plhs[3] = g_emlrt_marshallOut(TmNOFP);
  }

  if (nlhs > 4) {
    plhs[4] = g_emlrt_marshallOut(NOE2);
  }

  if (nlhs > 5) {
    plhs[5] = g_emlrt_marshallOut(NOE3);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void funcionCPrO_api(const mxArray *prhs[19], int32_T nlhs, const mxArray *plhs
                     [18])
{
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *PME;
  emxArray_int32_T *PMA;
  emxArray_int32_T *PMAn;
  emxArray_int32_T *PS;
  emxArray_int32_T *PCPO;
  emxArray_int32_T *PCR;
  emxArray_int32_T *H;
  emxArray_int32_T *Dia;
  emxArray_int32_T *UltPosRecXDia;
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *DispMExD;
  emxArray_int32_T *DispME;
  emxArray_int32_T *EA;
  emxArray_int32_T *AA;
  emxArray_int32_T *AnA;
  emxArray_int32_T *SA;
  const mxArray *prhs_copy_idx_0;
  const mxArray *prhs_copy_idx_1;
  const mxArray *prhs_copy_idx_2;
  const mxArray *prhs_copy_idx_3;
  const mxArray *prhs_copy_idx_4;
  const mxArray *prhs_copy_idx_5;
  const mxArray *prhs_copy_idx_6;
  const mxArray *prhs_copy_idx_7;
  const mxArray *prhs_copy_idx_8;
  const mxArray *prhs_copy_idx_9;
  const mxArray *prhs_copy_idx_10;
  const mxArray *prhs_copy_idx_11;
  const mxArray *prhs_copy_idx_12;
  const mxArray *prhs_copy_idx_13;
  const mxArray *prhs_copy_idx_14;
  const mxArray *prhs_copy_idx_15;
  const mxArray *prhs_copy_idx_16;
  const mxArray *prhs_copy_idx_17;
  const mxArray *prhs_copy_idx_18;
  int32_T (*NumRec)[7];
  int32_T TimeUsoCPrO;
  int32_T TimeUsoS;
  int32_T TimeUsoCPO;
  int32_T TimeUsoCR;
  int32_T contDia;
  int32_T CPrOA;
  int32_T IniCPrOA;
  int32_T EndCPrOA;
  int32_T EndCPrOAxD;
  int32_T IniSA;
  int32_T EndSA;
  int32_T EndRPxD;
  int32_T CPOA;
  int32_T IniCPOA;
  int32_T EndCPOA;
  int32_T CRA;
  int32_T IniCRA;
  int32_T EndCRA;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_int32_T(&st, &PCPrO, 2, true);
  emxInit_int32_T(&st, &PME, 2, true);
  emxInit_int32_T(&st, &PMA, 2, true);
  emxInit_int32_T(&st, &PMAn, 2, true);
  emxInit_int32_T(&st, &PS, 2, true);
  emxInit_int32_T(&st, &PCPO, 2, true);
  emxInit_int32_T(&st, &PCR, 2, true);
  emxInit_int32_T(&st, &H, 2, true);
  emxInit_int32_T(&st, &Dia, 2, true);
  emxInit_int32_T(&st, &UltPosRecXDia, 2, true);
  emxInit_int32_T(&st, &tempUltPosRecXDia, 2, true);
  emxInit_int32_T(&st, &DispMExD, 2, true);
  emxInit_int32_T(&st, &DispME, 2, true);
  emxInit_int32_T(&st, &EA, 2, true);
  emxInit_int32_T(&st, &AA, 2, true);
  emxInit_int32_T(&st, &AnA, 2, true);
  emxInit_int32_T(&st, &SA, 2, true);
  prhs_copy_idx_0 = prhs[0];
  prhs_copy_idx_1 = prhs[1];
  prhs_copy_idx_2 = prhs[2];
  prhs_copy_idx_3 = prhs[3];
  prhs_copy_idx_4 = prhs[4];
  prhs_copy_idx_5 = prhs[5];
  prhs_copy_idx_6 = prhs[6];
  prhs_copy_idx_7 = prhs[7];
  prhs_copy_idx_8 = prhs[8];
  prhs_copy_idx_9 = prhs[9];
  prhs_copy_idx_10 = prhs[10];
  prhs_copy_idx_11 = prhs[11];
  prhs_copy_idx_12 = prhs[12];
  prhs_copy_idx_13 = prhs[13];
  prhs_copy_idx_14 = prhs[14];
  prhs_copy_idx_15 = prhs[15];
  prhs_copy_idx_16 = emlrtProtectR2012b(prhs[16], 16, false, -1);
  prhs_copy_idx_17 = prhs[17];
  prhs_copy_idx_18 = emlrtProtectR2012b(prhs[18], 18, false, -1);

  /* Marshall function inputs */
  NumRec = i_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "NumRec");
  PCPrO->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_1), "PCPrO", PCPrO);
  PME->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_2), "PME", PME);
  PMA->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_3), "PMA", PMA);
  PMAn->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_4), "PMAn", PMAn);
  PS->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_5), "PS", PS);
  PCPO->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_6), "PCPO", PCPO);
  PCR->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_7), "PCR", PCR);
  H->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_8), "H", H);
  Dia->canFreeData = false;
  k_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_9), "Dia", Dia);
  UltPosRecXDia->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_10), "UltPosRecXDia",
                     UltPosRecXDia);
  TimeUsoCPrO = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_11),
    "TimeUsoCPrO");
  TimeUsoS = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_12), "TimeUsoS");
  TimeUsoCPO = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_13),
    "TimeUsoCPO");
  TimeUsoCR = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_14), "TimeUsoCR");
  contDia = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_15), "contDia");
  tempUltPosRecXDia->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_16), "tempUltPosRecXDia",
                      tempUltPosRecXDia);
  DispMExD->canFreeData = false;
  u_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_17), "DispMExD", DispMExD);
  DispME->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_18), "DispME", DispME);

  /* Invoke the target function */
  funcionCPrO(*NumRec, PCPrO, PME, PMA, PMAn, PS, PCPO, PCR, H, Dia,
              UltPosRecXDia, TimeUsoCPrO, TimeUsoS, TimeUsoCPO, TimeUsoCR,
              &contDia, tempUltPosRecXDia, DispMExD, DispME, &CPrOA, &IniCPrOA,
              &EndCPrOA, &EndCPrOAxD, EA, AA, AnA, SA, &IniSA, &EndSA, &EndRPxD,
              &CPOA, &IniCPOA, &EndCPOA, &CRA, &IniCRA, &EndCRA);

  /* Marshall function outputs */
  plhs[0] = h_emlrt_marshallOut(CPrOA);
  emxFree_int32_T(&DispME);
  emxFree_int32_T(&DispMExD);
  emxFree_int32_T(&tempUltPosRecXDia);
  emxFree_int32_T(&UltPosRecXDia);
  emxFree_int32_T(&Dia);
  emxFree_int32_T(&H);
  emxFree_int32_T(&PCR);
  emxFree_int32_T(&PCPO);
  emxFree_int32_T(&PS);
  emxFree_int32_T(&PMAn);
  emxFree_int32_T(&PMA);
  emxFree_int32_T(&PME);
  emxFree_int32_T(&PCPrO);
  if (nlhs > 1) {
    plhs[1] = h_emlrt_marshallOut(IniCPrOA);
  }

  if (nlhs > 2) {
    plhs[2] = h_emlrt_marshallOut(EndCPrOA);
  }

  if (nlhs > 3) {
    plhs[3] = h_emlrt_marshallOut(EndCPrOAxD);
  }

  if (nlhs > 4) {
    EA->canFreeData = false;
    plhs[4] = e_emlrt_marshallOut(EA);
  }

  emxFree_int32_T(&EA);
  if (nlhs > 5) {
    AA->canFreeData = false;
    plhs[5] = e_emlrt_marshallOut(AA);
  }

  emxFree_int32_T(&AA);
  if (nlhs > 6) {
    AnA->canFreeData = false;
    plhs[6] = e_emlrt_marshallOut(AnA);
  }

  emxFree_int32_T(&AnA);
  if (nlhs > 7) {
    SA->canFreeData = false;
    plhs[7] = e_emlrt_marshallOut(SA);
  }

  emxFree_int32_T(&SA);
  if (nlhs > 8) {
    plhs[8] = h_emlrt_marshallOut(IniSA);
  }

  if (nlhs > 9) {
    plhs[9] = h_emlrt_marshallOut(EndSA);
  }

  if (nlhs > 10) {
    plhs[10] = h_emlrt_marshallOut(EndRPxD);
  }

  if (nlhs > 11) {
    plhs[11] = h_emlrt_marshallOut(CPOA);
  }

  if (nlhs > 12) {
    plhs[12] = h_emlrt_marshallOut(IniCPOA);
  }

  if (nlhs > 13) {
    plhs[13] = h_emlrt_marshallOut(EndCPOA);
  }

  if (nlhs > 14) {
    plhs[14] = h_emlrt_marshallOut(CRA);
  }

  if (nlhs > 15) {
    plhs[15] = h_emlrt_marshallOut(IniCRA);
  }

  if (nlhs > 16) {
    plhs[16] = h_emlrt_marshallOut(EndCRA);
  }

  if (nlhs > 17) {
    plhs[17] = h_emlrt_marshallOut(contDia);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void funcionCR_api(int32_T nlhs)
{
  (void)nlhs;

  /* Invoke the target function */
  funcionCR();
}

void funcionC_api(const mxArray *prhs[32], int32_T nlhs, const mxArray *plhs[18])
{
  emxArray_int32_T *PCPO;
  emxArray_int32_T *PCR;
  emxArray_int32_T *H;
  emxArray_int32_T *PME;
  emxArray_int32_T *PMA;
  emxArray_int32_T *PMAn;
  emxArray_int32_T *PS;
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *Dia;
  emxArray_int32_T *UltPosRecXDia;
  emxArray_int32_T *filCPrO;
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *EA;
  emxArray_int32_T *SA;
  emxArray_int32_T *AA;
  emxArray_int32_T *AnA;
  emxArray_int32_T *DispMExD;
  emxArray_int32_T *DispME;
  emxArray_int32_T *uCPrODisp;
  const mxArray *prhs_copy_idx_0;
  const mxArray *prhs_copy_idx_1;
  const mxArray *prhs_copy_idx_2;
  const mxArray *prhs_copy_idx_3;
  const mxArray *prhs_copy_idx_4;
  const mxArray *prhs_copy_idx_5;
  const mxArray *prhs_copy_idx_6;
  const mxArray *prhs_copy_idx_7;
  const mxArray *prhs_copy_idx_8;
  const mxArray *prhs_copy_idx_9;
  const mxArray *prhs_copy_idx_10;
  const mxArray *prhs_copy_idx_11;
  const mxArray *prhs_copy_idx_12;
  const mxArray *prhs_copy_idx_13;
  const mxArray *prhs_copy_idx_14;
  const mxArray *prhs_copy_idx_15;
  const mxArray *prhs_copy_idx_16;
  const mxArray *prhs_copy_idx_17;
  const mxArray *prhs_copy_idx_18;
  const mxArray *prhs_copy_idx_19;
  const mxArray *prhs_copy_idx_20;
  const mxArray *prhs_copy_idx_21;
  const mxArray *prhs_copy_idx_22;
  const mxArray *prhs_copy_idx_23;
  const mxArray *prhs_copy_idx_24;
  const mxArray *prhs_copy_idx_25;
  const mxArray *prhs_copy_idx_26;
  int32_T EndRP;
  int32_T TimeUsoCPO;
  int32_T TimeUsoCR;
  int32_T CPrOA;
  int32_T IniCPrOA;
  int32_T EndCPrOA;
  int32_T EndCPrOAxD;
  int32_T (*NumRec)[7];
  int32_T TimeUsoCPrO;
  int32_T TimeUsoS;
  int32_T contDia;
  int32_T IniRP;
  int32_T EndRPxD;
  real_T CPOA;
  int32_T IniCPO;
  int32_T EndCPO;
  real_T CRA;
  int32_T IniCR;
  int32_T EndCR;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_int32_T(&st, &PCPO, 2, true);
  emxInit_int32_T(&st, &PCR, 2, true);
  emxInit_int32_T(&st, &H, 2, true);
  emxInit_int32_T(&st, &PME, 2, true);
  emxInit_int32_T(&st, &PMA, 2, true);
  emxInit_int32_T(&st, &PMAn, 2, true);
  emxInit_int32_T(&st, &PS, 2, true);
  emxInit_int32_T(&st, &PCPrO, 2, true);
  emxInit_int32_T(&st, &Dia, 2, true);
  emxInit_int32_T(&st, &UltPosRecXDia, 2, true);
  emxInit_int32_T(&st, &filCPrO, 2, true);
  emxInit_int32_T(&st, &tempUltPosRecXDia, 2, true);
  emxInit_int32_T(&st, &EA, 2, true);
  emxInit_int32_T(&st, &SA, 2, true);
  emxInit_int32_T(&st, &AA, 2, true);
  emxInit_int32_T(&st, &AnA, 2, true);
  emxInit_int32_T(&st, &DispMExD, 2, true);
  emxInit_int32_T(&st, &DispME, 2, true);
  emxInit_int32_T(&st, &uCPrODisp, 2, true);
  prhs_copy_idx_0 = prhs[0];
  prhs_copy_idx_1 = prhs[1];
  prhs_copy_idx_2 = prhs[2];
  prhs_copy_idx_3 = prhs[3];
  prhs_copy_idx_4 = prhs[4];
  prhs_copy_idx_5 = prhs[5];
  prhs_copy_idx_6 = prhs[6];
  prhs_copy_idx_7 = prhs[7];
  prhs_copy_idx_8 = prhs[8];
  prhs_copy_idx_9 = prhs[9];
  prhs_copy_idx_10 = prhs[10];
  prhs_copy_idx_11 = prhs[11];
  prhs_copy_idx_12 = prhs[12];
  prhs_copy_idx_13 = prhs[13];
  prhs_copy_idx_14 = prhs[14];
  prhs_copy_idx_15 = prhs[15];
  prhs_copy_idx_16 = prhs[16];
  prhs_copy_idx_17 = prhs[17];
  prhs_copy_idx_18 = prhs[18];
  prhs_copy_idx_19 = prhs[19];
  prhs_copy_idx_20 = prhs[20];
  prhs_copy_idx_21 = prhs[21];
  prhs_copy_idx_22 = prhs[22];
  prhs_copy_idx_23 = emlrtProtectR2012b(prhs[23], 23, true, -1);
  prhs_copy_idx_24 = emlrtProtectR2012b(prhs[24], 24, true, -1);
  prhs_copy_idx_25 = emlrtProtectR2012b(prhs[25], 25, true, -1);
  prhs_copy_idx_26 = emlrtProtectR2012b(prhs[26], 26, true, -1);

  /* Marshall function inputs */
  PCPO->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "PCPO", PCPO);
  PCR->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_1), "PCR", PCR);
  H->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_2), "H", H);
  EndRP = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_3), "EndRP");
  TimeUsoCPO = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_4),
    "TimeUsoCPO");
  TimeUsoCR = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_5), "TimeUsoCR");
  PME->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_6), "PME", PME);
  PMA->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_7), "PMA", PMA);
  PMAn->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_8), "PMAn", PMAn);
  PS->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_9), "PS", PS);
  CPrOA = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_10), "CPrOA");
  IniCPrOA = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_11), "IniCPrOA");
  EndCPrOA = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_12), "EndCPrOA");
  EndCPrOAxD = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_13),
    "EndCPrOAxD");
  NumRec = i_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_14), "NumRec");
  PCPrO->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_15), "PCPrO", PCPrO);
  Dia->canFreeData = false;
  k_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_16), "Dia", Dia);
  UltPosRecXDia->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_17), "UltPosRecXDia",
                     UltPosRecXDia);
  TimeUsoCPrO = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_18),
    "TimeUsoCPrO");
  TimeUsoS = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_19), "TimeUsoS");
  contDia = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_20), "contDia");
  filCPrO->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_21), "filCPrO", filCPrO);
  tempUltPosRecXDia->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_22), "tempUltPosRecXDia",
                      tempUltPosRecXDia);
  EA->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_23), "EA", EA);
  SA->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_24), "SA", SA);
  AA->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_25), "AA", AA);
  AnA->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_26), "AnA", AnA);
  IniRP = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[27]), "IniRP");
  EndRPxD = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[28]), "EndRPxD");
  DispMExD->canFreeData = false;
  u_emlrt_marshallIn(&st, emlrtAlias(prhs[29]), "DispMExD", DispMExD);
  DispME->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs[30]), "DispME", DispME);
  uCPrODisp->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs[31]), "uCPrODisp", uCPrODisp);

  /* Invoke the target function */
  funcionC(PCPO, PCR, H, &EndRP, TimeUsoCPO, TimeUsoCR, PME, PMA, PMAn, PS,
           &CPrOA, &IniCPrOA, &EndCPrOA, &EndCPrOAxD, *NumRec, PCPrO, Dia,
           UltPosRecXDia, TimeUsoCPrO, TimeUsoS, &contDia, filCPrO,
           tempUltPosRecXDia, EA, SA, AA, AnA, &IniRP, &EndRPxD, DispMExD,
           DispME, uCPrODisp, &CPOA, &IniCPO, &EndCPO, &CRA, &IniCR, &EndCR);

  /* Marshall function outputs */
  plhs[0] = h_emlrt_marshallOut(CPrOA);
  emxFree_int32_T(&uCPrODisp);
  emxFree_int32_T(&DispME);
  emxFree_int32_T(&DispMExD);
  emxFree_int32_T(&tempUltPosRecXDia);
  emxFree_int32_T(&filCPrO);
  emxFree_int32_T(&UltPosRecXDia);
  emxFree_int32_T(&Dia);
  emxFree_int32_T(&PCPrO);
  emxFree_int32_T(&PS);
  emxFree_int32_T(&PMAn);
  emxFree_int32_T(&PMA);
  emxFree_int32_T(&PME);
  emxFree_int32_T(&H);
  emxFree_int32_T(&PCR);
  emxFree_int32_T(&PCPO);
  if (nlhs > 1) {
    plhs[1] = h_emlrt_marshallOut(IniCPrOA);
  }

  if (nlhs > 2) {
    plhs[2] = h_emlrt_marshallOut(EndCPrOA);
  }

  if (nlhs > 3) {
    plhs[3] = h_emlrt_marshallOut(EndCPrOAxD);
  }

  if (nlhs > 4) {
    EA->canFreeData = false;
    i_emlrt_marshallOut(EA, prhs_copy_idx_23);
    plhs[4] = prhs_copy_idx_23;
  }

  emxFree_int32_T(&EA);
  if (nlhs > 5) {
    SA->canFreeData = false;
    i_emlrt_marshallOut(SA, prhs_copy_idx_24);
    plhs[5] = prhs_copy_idx_24;
  }

  emxFree_int32_T(&SA);
  if (nlhs > 6) {
    AA->canFreeData = false;
    i_emlrt_marshallOut(AA, prhs_copy_idx_25);
    plhs[6] = prhs_copy_idx_25;
  }

  emxFree_int32_T(&AA);
  if (nlhs > 7) {
    AnA->canFreeData = false;
    i_emlrt_marshallOut(AnA, prhs_copy_idx_26);
    plhs[7] = prhs_copy_idx_26;
  }

  emxFree_int32_T(&AnA);
  if (nlhs > 8) {
    plhs[8] = h_emlrt_marshallOut(IniRP);
  }

  if (nlhs > 9) {
    plhs[9] = h_emlrt_marshallOut(EndRP);
  }

  if (nlhs > 10) {
    plhs[10] = h_emlrt_marshallOut(EndRPxD);
  }

  if (nlhs > 11) {
    plhs[11] = g_emlrt_marshallOut(CPOA);
  }

  if (nlhs > 12) {
    plhs[12] = h_emlrt_marshallOut(IniCPO);
  }

  if (nlhs > 13) {
    plhs[13] = h_emlrt_marshallOut(EndCPO);
  }

  if (nlhs > 14) {
    plhs[14] = g_emlrt_marshallOut(CRA);
  }

  if (nlhs > 15) {
    plhs[15] = h_emlrt_marshallOut(IniCR);
  }

  if (nlhs > 16) {
    plhs[16] = h_emlrt_marshallOut(EndCR);
  }

  if (nlhs > 17) {
    plhs[17] = h_emlrt_marshallOut(contDia);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void funcionDia_api(const mxArray * const prhs[8], int32_T nlhs, const mxArray
                    *plhs[3])
{
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *Dia;
  emxArray_int32_T *UltPosRecXDia;
  emxArray_int32_T *DispMExD;
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *DispME;
  int32_T (*NumRec)[7];
  int32_T TimeUsoCPrO;
  int32_T TimeUsoS;
  int32_T contDia;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_int32_T(&st, &PCPrO, 2, true);
  emxInit_int32_T(&st, &Dia, 2, true);
  emxInit_int32_T(&st, &UltPosRecXDia, 2, true);
  emxInit_int32_T(&st, &DispMExD, 2, true);
  emxInit_int32_T(&st, &tempUltPosRecXDia, 2, true);
  emxInit_int32_T(&st, &DispME, 2, true);

  /* Marshall function inputs */
  NumRec = i_emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "NumRec");
  PCPrO->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "PCPrO", PCPrO);
  Dia->canFreeData = false;
  k_emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Dia", Dia);
  UltPosRecXDia->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "UltPosRecXDia", UltPosRecXDia);
  TimeUsoCPrO = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "TimeUsoCPrO");
  TimeUsoS = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "TimeUsoS");
  contDia = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "contDia");
  DispMExD->canFreeData = false;
  u_emlrt_marshallIn(&st, emlrtAlias(prhs[7]), "DispMExD", DispMExD);

  /* Invoke the target function */
  funcionDia(*NumRec, PCPrO, Dia, UltPosRecXDia, TimeUsoCPrO, TimeUsoS, &contDia,
             DispMExD, tempUltPosRecXDia, DispME);

  /* Marshall function outputs */
  plhs[0] = h_emlrt_marshallOut(contDia);
  emxFree_int32_T(&DispMExD);
  emxFree_int32_T(&UltPosRecXDia);
  emxFree_int32_T(&Dia);
  emxFree_int32_T(&PCPrO);
  if (nlhs > 1) {
    tempUltPosRecXDia->canFreeData = false;
    plhs[1] = e_emlrt_marshallOut(tempUltPosRecXDia);
  }

  emxFree_int32_T(&tempUltPosRecXDia);
  if (nlhs > 2) {
    DispME->canFreeData = false;
    plhs[2] = e_emlrt_marshallOut(DispME);
  }

  emxFree_int32_T(&DispME);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void funcionRP_api(const mxArray *prhs[32], int32_T nlhs, const mxArray *plhs[18])
{
  emxArray_int32_T *CPrOA;
  emxArray_int32_T *SA;
  emxArray_int32_T *CPOA;
  emxArray_int32_T *CRA;
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *PME;
  emxArray_int32_T *PMA;
  emxArray_int32_T *PMAn;
  emxArray_int32_T *PS;
  emxArray_int32_T *PCPO;
  emxArray_int32_T *PCR;
  emxArray_real_T *H;
  emxArray_int32_T *Dia;
  emxArray_int32_T *UltPosRecXDia;
  emxArray_int32_T *tempUltPosRecXDia;
  emxArray_int32_T *DispMExD;
  emxArray_int32_T *DispME;
  emxArray_int32_T *EA;
  emxArray_int32_T *AA;
  emxArray_int32_T *AnA;
  const mxArray *prhs_copy_idx_0;
  const mxArray *prhs_copy_idx_1;
  const mxArray *prhs_copy_idx_2;
  const mxArray *prhs_copy_idx_3;
  const mxArray *prhs_copy_idx_4;
  const mxArray *prhs_copy_idx_5;
  const mxArray *prhs_copy_idx_6;
  const mxArray *prhs_copy_idx_7;
  const mxArray *prhs_copy_idx_8;
  const mxArray *prhs_copy_idx_9;
  const mxArray *prhs_copy_idx_10;
  int32_T IniCPrOA;
  int32_T EndCPrOA;
  int32_T EndCPrOAxD;
  int32_T IniSA;
  int32_T EndSA;
  int32_T IniCPOA;
  int32_T EndCPOA;
  int32_T IniCRA;
  int32_T EndCRA;
  int32_T (*NumRec)[7];
  int32_T TimeUsoCPrO;
  int32_T TimeUsoS;
  int32_T TimeUsoCPO;
  int32_T TimeUsoCR;
  int32_T contDia;
  int32_T EndRPxD;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_int32_T(&st, &CPrOA, 2, true);
  emxInit_int32_T(&st, &SA, 2, true);
  emxInit_int32_T(&st, &CPOA, 2, true);
  emxInit_int32_T(&st, &CRA, 2, true);
  emxInit_int32_T(&st, &PCPrO, 2, true);
  emxInit_int32_T(&st, &PME, 2, true);
  emxInit_int32_T(&st, &PMA, 2, true);
  emxInit_int32_T(&st, &PMAn, 2, true);
  emxInit_int32_T(&st, &PS, 2, true);
  emxInit_int32_T(&st, &PCPO, 2, true);
  emxInit_int32_T(&st, &PCR, 2, true);
  emxInit_real_T(&st, &H, 2, true);
  emxInit_int32_T(&st, &Dia, 2, true);
  emxInit_int32_T(&st, &UltPosRecXDia, 2, true);
  emxInit_int32_T(&st, &tempUltPosRecXDia, 2, true);
  emxInit_int32_T(&st, &DispMExD, 2, true);
  emxInit_int32_T(&st, &DispME, 2, true);
  emxInit_int32_T(&st, &EA, 2, true);
  emxInit_int32_T(&st, &AA, 2, true);
  emxInit_int32_T(&st, &AnA, 2, true);
  prhs_copy_idx_0 = emlrtProtectR2012b(prhs[0], 0, true, -1);
  prhs_copy_idx_1 = prhs[1];
  prhs_copy_idx_2 = prhs[2];
  prhs_copy_idx_3 = prhs[3];
  prhs_copy_idx_4 = emlrtProtectR2012b(prhs[4], 4, true, -1);
  prhs_copy_idx_5 = prhs[5];
  prhs_copy_idx_6 = prhs[6];
  prhs_copy_idx_7 = emlrtProtectR2012b(prhs[7], 7, true, -1);
  prhs_copy_idx_8 = prhs[8];
  prhs_copy_idx_9 = prhs[9];
  prhs_copy_idx_10 = emlrtProtectR2012b(prhs[10], 10, true, -1);

  /* Marshall function inputs */
  CPrOA->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_0), "CPrOA", CPrOA);
  IniCPrOA = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_1), "IniCPrOA");
  EndCPrOA = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_2), "EndCPrOA");
  EndCPrOAxD = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_3),
    "EndCPrOAxD");
  SA->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_4), "SA", SA);
  IniSA = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_5), "IniSA");
  EndSA = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_6), "EndSA");
  CPOA->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_7), "CPOA", CPOA);
  IniCPOA = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_8), "IniCPOA");
  EndCPOA = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_9), "EndCPOA");
  CRA->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_10), "CRA", CRA);
  IniCRA = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "IniCRA");
  EndCRA = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "EndCRA");
  NumRec = i_emlrt_marshallIn(&st, emlrtAlias(prhs[13]), "NumRec");
  PCPrO->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs[14]), "PCPrO", PCPrO);
  PME->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs[15]), "PME", PME);
  PMA->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs[16]), "PMA", PMA);
  PMAn->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs[17]), "PMAn", PMAn);
  PS->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs[18]), "PS", PS);
  PCPO->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs[19]), "PCPO", PCPO);
  PCR->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs[20]), "PCR", PCR);
  H->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[21]), "H", H);
  Dia->canFreeData = false;
  k_emlrt_marshallIn(&st, emlrtAlias(prhs[22]), "Dia", Dia);
  UltPosRecXDia->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs[23]), "UltPosRecXDia", UltPosRecXDia);
  TimeUsoCPrO = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[24]), "TimeUsoCPrO");
  TimeUsoS = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[25]), "TimeUsoS");
  TimeUsoCPO = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[26]), "TimeUsoCPO");
  TimeUsoCR = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[27]), "TimeUsoCR");
  contDia = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[28]), "contDia");
  tempUltPosRecXDia->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs[29]), "tempUltPosRecXDia",
                      tempUltPosRecXDia);
  DispMExD->canFreeData = false;
  u_emlrt_marshallIn(&st, emlrtAlias(prhs[30]), "DispMExD", DispMExD);
  DispME->canFreeData = false;
  db_emlrt_marshallIn(&st, emlrtAlias(prhs[31]), "DispME", DispME);

  /* Invoke the target function */
  funcionRP(CPrOA, &IniCPrOA, &EndCPrOA, &EndCPrOAxD, SA, &IniSA, &EndSA, CPOA,
            &IniCPOA, &EndCPOA, CRA, &IniCRA, &EndCRA, *NumRec, PCPrO, PME, PMA,
            PMAn, PS, PCPO, PCR, H, Dia, UltPosRecXDia, TimeUsoCPrO, TimeUsoS,
            TimeUsoCPO, TimeUsoCR, &contDia, tempUltPosRecXDia, DispMExD, DispME,
            EA, AA, AnA, &EndRPxD);

  /* Marshall function outputs */
  CPrOA->canFreeData = false;
  i_emlrt_marshallOut(CPrOA, prhs_copy_idx_0);
  plhs[0] = prhs_copy_idx_0;
  emxFree_int32_T(&DispME);
  emxFree_int32_T(&DispMExD);
  emxFree_int32_T(&tempUltPosRecXDia);
  emxFree_int32_T(&UltPosRecXDia);
  emxFree_int32_T(&Dia);
  emxFree_real_T(&H);
  emxFree_int32_T(&PCR);
  emxFree_int32_T(&PCPO);
  emxFree_int32_T(&PS);
  emxFree_int32_T(&PMAn);
  emxFree_int32_T(&PMA);
  emxFree_int32_T(&PME);
  emxFree_int32_T(&PCPrO);
  emxFree_int32_T(&CPrOA);
  if (nlhs > 1) {
    plhs[1] = h_emlrt_marshallOut(IniCPrOA);
  }

  if (nlhs > 2) {
    plhs[2] = h_emlrt_marshallOut(EndCPrOA);
  }

  if (nlhs > 3) {
    plhs[3] = h_emlrt_marshallOut(EndCPrOAxD);
  }

  if (nlhs > 4) {
    EA->canFreeData = false;
    plhs[4] = e_emlrt_marshallOut(EA);
  }

  emxFree_int32_T(&EA);
  if (nlhs > 5) {
    SA->canFreeData = false;
    i_emlrt_marshallOut(SA, prhs_copy_idx_4);
    plhs[5] = prhs_copy_idx_4;
  }

  emxFree_int32_T(&SA);
  if (nlhs > 6) {
    AA->canFreeData = false;
    plhs[6] = e_emlrt_marshallOut(AA);
  }

  emxFree_int32_T(&AA);
  if (nlhs > 7) {
    AnA->canFreeData = false;
    plhs[7] = e_emlrt_marshallOut(AnA);
  }

  emxFree_int32_T(&AnA);
  if (nlhs > 8) {
    plhs[8] = h_emlrt_marshallOut(IniSA);
  }

  if (nlhs > 9) {
    plhs[9] = h_emlrt_marshallOut(EndSA);
  }

  if (nlhs > 10) {
    plhs[10] = h_emlrt_marshallOut(EndRPxD);
  }

  if (nlhs > 11) {
    CPOA->canFreeData = false;
    i_emlrt_marshallOut(CPOA, prhs_copy_idx_7);
    plhs[11] = prhs_copy_idx_7;
  }

  emxFree_int32_T(&CPOA);
  if (nlhs > 12) {
    plhs[12] = h_emlrt_marshallOut(IniCPOA);
  }

  if (nlhs > 13) {
    plhs[13] = h_emlrt_marshallOut(EndCPOA);
  }

  if (nlhs > 14) {
    CRA->canFreeData = false;
    i_emlrt_marshallOut(CRA, prhs_copy_idx_10);
    plhs[14] = prhs_copy_idx_10;
  }

  emxFree_int32_T(&CRA);
  if (nlhs > 15) {
    plhs[15] = h_emlrt_marshallOut(IniCRA);
  }

  if (nlhs > 16) {
    plhs[16] = h_emlrt_marshallOut(EndCRA);
  }

  if (nlhs > 17) {
    plhs[17] = h_emlrt_marshallOut(contDia);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void main_UCI_func_api(int32_T nlhs)
{
  (void)nlhs;

  /* Invoke the target function */
  main_UCI_func();
}

void model_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  model_xil_terminate();
  model_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void model_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void model_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void obsIQ_api(const mxArray * const prhs[3], int32_T nlhs, const mxArray *plhs
               [1])
{
  emxArray_real_T *IQ;
  emxArray_int32_T *newIC;
  int32_T numIQ;
  int32_T numObsIQ;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &IQ, 2, true);
  emxInit_int32_T(&st, &newIC, 2, true);

  /* Marshall function inputs */
  IQ->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "IQ", IQ);
  numIQ = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "numIQ");
  numObsIQ = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "numObsIQ");

  /* Invoke the target function */
  obsIQ(IQ, numIQ, numObsIQ, newIC);

  /* Marshall function outputs */
  newIC->canFreeData = false;
  plhs[0] = e_emlrt_marshallOut(newIC);
  emxFree_int32_T(&newIC);
  emxFree_real_T(&IQ);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void obsIQini_api(const mxArray * const prhs[4], int32_T nlhs, const mxArray
                  *plhs[1])
{
  emxArray_real_T *IQ;
  emxArray_real_T *newIC;
  int32_T numIQ;
  int32_T numObsIQ;
  real_T (*ProbXEst)[5];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &IQ, 2, true);
  emxInit_real_T(&st, &newIC, 2, true);

  /* Marshall function inputs */
  IQ->canFreeData = false;
  emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "IQ", IQ);
  numIQ = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "numIQ");
  numObsIQ = g_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "numObsIQ");
  ProbXEst = q_emlrt_marshallIn(&st, emlrtAlias(prhs[3]), "ProbXEst");

  /* Invoke the target function */
  obsIQini(IQ, numIQ, numObsIQ, *ProbXEst, newIC);

  /* Marshall function outputs */
  newIC->canFreeData = false;
  plhs[0] = emlrt_marshallOut(newIC);
  emxFree_real_T(&newIC);
  emxFree_real_T(&IQ);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void sch_api(const mxArray *prhs[19], int32_T nlhs, const mxArray *plhs[6])
{
  emxArray_int32_T *list;
  emxArray_int32_T *PCPrO;
  emxArray_int32_T *PME;
  emxArray_int32_T *PMA;
  emxArray_int32_T *PMAn;
  emxArray_int32_T *PS;
  emxArray_int32_T *PCPO;
  emxArray_int32_T *PCR;
  emxArray_int32_T *Dia;
  emxArray_int32_T *Data;
  emxArray_int32_T *TimeUsoRec;
  emxArray_int32_T *DispMExD;
  emxArray_int32_T *EP;
  const mxArray *prhs_copy_idx_0;
  const mxArray *prhs_copy_idx_1;
  const mxArray *prhs_copy_idx_2;
  const mxArray *prhs_copy_idx_3;
  const mxArray *prhs_copy_idx_4;
  const mxArray *prhs_copy_idx_5;
  const mxArray *prhs_copy_idx_6;
  const mxArray *prhs_copy_idx_7;
  const mxArray *prhs_copy_idx_8;
  const mxArray *prhs_copy_idx_9;
  const mxArray *prhs_copy_idx_10;
  const mxArray *prhs_copy_idx_11;
  const mxArray *prhs_copy_idx_12;
  const mxArray *prhs_copy_idx_13;
  const mxArray *prhs_copy_idx_14;
  int32_T NumTOp;
  int32_T (*NumRec)[7];
  real_T k0;
  real_T k1;
  real_T k2;
  real_T k3;
  real_T fitness;
  real_T Tt;
  real_T NOFP;
  real_T TmNOFP;
  real_T NOE2;
  real_T NOE3;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_int32_T(&st, &list, 1, true);
  emxInit_int32_T(&st, &PCPrO, 2, true);
  emxInit_int32_T(&st, &PME, 2, true);
  emxInit_int32_T(&st, &PMA, 2, true);
  emxInit_int32_T(&st, &PMAn, 2, true);
  emxInit_int32_T(&st, &PS, 2, true);
  emxInit_int32_T(&st, &PCPO, 2, true);
  emxInit_int32_T(&st, &PCR, 2, true);
  emxInit_int32_T(&st, &Dia, 2, true);
  emxInit_int32_T(&st, &Data, 2, true);
  emxInit_int32_T(&st, &TimeUsoRec, 2, true);
  emxInit_int32_T(&st, &DispMExD, 1, true);
  emxInit_int32_T(&st, &EP, 1, true);
  prhs_copy_idx_0 = prhs[0];
  prhs_copy_idx_1 = prhs[1];
  prhs_copy_idx_2 = prhs[2];
  prhs_copy_idx_3 = emlrtProtectR2012b(prhs[3], 3, false, -1);
  prhs_copy_idx_4 = emlrtProtectR2012b(prhs[4], 4, false, -1);
  prhs_copy_idx_5 = emlrtProtectR2012b(prhs[5], 5, false, -1);
  prhs_copy_idx_6 = emlrtProtectR2012b(prhs[6], 6, false, -1);
  prhs_copy_idx_7 = emlrtProtectR2012b(prhs[7], 7, false, -1);
  prhs_copy_idx_8 = emlrtProtectR2012b(prhs[8], 8, false, -1);
  prhs_copy_idx_9 = emlrtProtectR2012b(prhs[9], 9, false, -1);
  prhs_copy_idx_10 = prhs[10];
  prhs_copy_idx_11 = prhs[11];
  prhs_copy_idx_12 = emlrtProtectR2012b(prhs[12], 12, false, -1);
  prhs_copy_idx_13 = prhs[13];
  prhs_copy_idx_14 = emlrtProtectR2012b(prhs[14], 14, false, -1);

  /* Marshall function inputs */
  NumTOp = g_emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_0), "NumTOp");
  list->canFreeData = false;
  y_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_1), "list", list);
  NumRec = i_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_2), "NumRec");
  PCPrO->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_3), "PCPrO", PCPrO);
  PME->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_4), "PME", PME);
  PMA->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_5), "PMA", PMA);
  PMAn->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_6), "PMAn", PMAn);
  PS->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_7), "PS", PS);
  PCPO->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_8), "PCPO", PCPO);
  PCR->canFreeData = false;
  c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_9), "PCR", PCR);
  Dia->canFreeData = false;
  k_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_10), "Dia", Dia);
  Data->canFreeData = false;
  m_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_11), "Data", Data);
  TimeUsoRec->canFreeData = false;
  o_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_12), "TimeUsoRec", TimeUsoRec);
  DispMExD->canFreeData = false;
  y_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_13), "DispMExD", DispMExD);
  EP->canFreeData = false;
  y_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_14), "EP", EP);
  k0 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[15]), "k0");
  k1 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[16]), "k1");
  k2 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[17]), "k2");
  k3 = e_emlrt_marshallIn(&st, emlrtAliasP(prhs[18]), "k3");

  /* Invoke the target function */
  sch(NumTOp, list, *NumRec, PCPrO, PME, PMA, PMAn, PS, PCPO, PCR, Dia, Data,
      TimeUsoRec, DispMExD, EP, k0, k1, k2, k3, &fitness, &Tt, &NOFP, &TmNOFP,
      &NOE2, &NOE3);

  /* Marshall function outputs */
  plhs[0] = g_emlrt_marshallOut(fitness);
  emxFree_int32_T(&EP);
  emxFree_int32_T(&DispMExD);
  emxFree_int32_T(&TimeUsoRec);
  emxFree_int32_T(&Data);
  emxFree_int32_T(&Dia);
  emxFree_int32_T(&PCR);
  emxFree_int32_T(&PCPO);
  emxFree_int32_T(&PS);
  emxFree_int32_T(&PMAn);
  emxFree_int32_T(&PMA);
  emxFree_int32_T(&PME);
  emxFree_int32_T(&PCPrO);
  emxFree_int32_T(&list);
  if (nlhs > 1) {
    plhs[1] = g_emlrt_marshallOut(Tt);
  }

  if (nlhs > 2) {
    plhs[2] = g_emlrt_marshallOut(NOFP);
  }

  if (nlhs > 3) {
    plhs[3] = g_emlrt_marshallOut(TmNOFP);
  }

  if (nlhs > 4) {
    plhs[4] = g_emlrt_marshallOut(NOE2);
  }

  if (nlhs > 5) {
    plhs[5] = g_emlrt_marshallOut(NOE3);
  }

  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_model_api.c) */
