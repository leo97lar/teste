/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_model_api.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
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
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret);
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y);
static int32_T bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *RO, const
  char_T *identifier, emxArray_int32_T *y);
static real_T cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y);
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *CPO, const
  char_T *identifier, emxArray_int32_T *y);
static boolean_T eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *CP, const
  char_T *identifier, emxArray_int32_T *y);
static void emxEnsureCapacity_int32_T(emxArray_int32_T *emxArray, int32_T
  oldNumel);
static void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int32_T oldNumel);
static void emxFree_int32_T(emxArray_int32_T **pEmxArray);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
  int32_T numDimensions, boolean_T doPush);
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y);
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Data, const
  char_T *identifier, emxArray_int32_T *y);
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y);
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Dia, const
  char_T *identifier, emxArray_int32_T *y);
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y);
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *DispMExD,
  const char_T *identifier, emxArray_int32_T *y);
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y);
static int32_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *TipoOp,
  const char_T *identifier);
static int32_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *k0, const
  char_T *identifier);
static real_T p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *ProbXEst,
  const char_T *identifier, emxArray_real_T *y);
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y);
static boolean_T s_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *keeppriority, const char_T *identifier);
static boolean_T t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret);
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret);
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret);
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret);
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_int32_T *ret
 * Return Type  : void
 */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret)
{
  static const int32_T dims[2] = { 6, -1 };

  const boolean_T bv5[2] = { false, true };

  int32_T iv5[2];
  int32_T i17;
  emlrtCheckVsBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "int32",
    false, 2U, *(int32_T (*)[2])&dims[0], (boolean_T *)&bv5[0], iv5);
  i17 = ret->size[0] * ret->size[1];
  ret->size[1] = iv5[0];
  ret->size[0] = iv5[1];
  emxEnsureCapacity_int32_T(ret, i17);
  emlrtImportArrayR2015b(sp, src, ret->data, 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_int32_T *y
 * Return Type  : void
 */
static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y)
{
  emxArray_int32_T *r0;
  int32_T i0;
  int32_T loop_ub;
  int32_T i1;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &r0, 2, true);
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, r0);
  i0 = y->size[0] * y->size[1];
  y->size[1] = 8;
  y->size[0] = r0->size[1];
  emxEnsureCapacity_int32_T(y, i0);
  loop_ub = r0->size[1];
  for (i0 = 0; i0 < loop_ub; i0++) {
    for (i1 = 0; i1 < 8; i1++) {
      y->data[i1 + (i0 << 3)] = r0->data[i0 + r0->size[1] * i1];
    }
  }

  emxFree_int32_T(&r0);
  emlrtDestroyArray(&u);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : int32_T
 */
static int32_T bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  int32_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "int32",
    false, 0U, (int32_T *)&dims);
  ret = *(int32_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *RO
 *                const char_T *identifier
 *                emxArray_int32_T *y
 * Return Type  : void
 */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *RO, const
  char_T *identifier, emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(RO), &thisId, y);
  emlrtDestroyArray(&RO);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 0U, (int32_T *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_int32_T *y
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y)
{
  emxArray_int32_T *r1;
  int32_T i2;
  int32_T loop_ub;
  int32_T i3;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &r1, 2, true);
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId, r1);
  i2 = y->size[0] * y->size[1];
  y->size[1] = 7;
  y->size[0] = r1->size[1];
  emxEnsureCapacity_int32_T(y, i2);
  loop_ub = r1->size[1];
  for (i2 = 0; i2 < loop_ub; i2++) {
    for (i3 = 0; i3 < 7; i3++) {
      y->data[i3 + 7 * i2] = r1->data[i2 + r1->size[1] * i3];
    }
  }

  emxFree_int32_T(&r1);
  emlrtDestroyArray(&u);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_real_T *ret
 * Return Type  : void
 */
static void db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_real_T *ret)
{
  static const int32_T dims[1] = { -1 };

  const boolean_T bv6[1] = { true };

  int32_T iv6[1];
  int32_T i18;
  emlrtCheckVsBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 1U, *(int32_T (*)[1])&dims[0], (boolean_T *)&bv6[0], iv6);
  i18 = ret->size[0];
  ret->size[0] = iv6[0];
  emxEnsureCapacity_real_T(ret, i18);
  emlrtImportArrayR2015b(sp, src, ret->data, 8, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *CPO
 *                const char_T *identifier
 *                emxArray_int32_T *y
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *CPO, const
  char_T *identifier, emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  f_emlrt_marshallIn(sp, emlrtAlias(CPO), &thisId, y);
  emlrtDestroyArray(&CPO);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : boolean_T
 */
static boolean_T eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  boolean_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "logical",
    false, 0U, (int32_T *)&dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *CP
 *                const char_T *identifier
 *                emxArray_int32_T *y
 * Return Type  : void
 */
static void emlrt_marshallIn(const emlrtStack *sp, const mxArray *CP, const
  char_T *identifier, emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(CP), &thisId, y);
  emlrtDestroyArray(&CP);
}

/*
 * Arguments    : emxArray_int32_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
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

/*
 * Arguments    : emxArray_real_T *emxArray
 *                int32_T oldNumel
 * Return Type  : void
 */
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

/*
 * Arguments    : emxArray_int32_T **pEmxArray
 * Return Type  : void
 */
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

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_int32_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
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

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_int32_T *y
 * Return Type  : void
 */
static void f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y)
{
  emxArray_int32_T *r2;
  int32_T i4;
  int32_T loop_ub;
  int32_T b_loop_ub;
  int32_T i5;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &r2, 2, true);
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId, r2);
  i4 = y->size[0] * y->size[1];
  y->size[1] = r2->size[0];
  y->size[0] = r2->size[1];
  emxEnsureCapacity_int32_T(y, i4);
  loop_ub = r2->size[1];
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_loop_ub = r2->size[0];
    for (i5 = 0; i5 < b_loop_ub; i5++) {
      y->data[i5 + y->size[1] * i4] = r2->data[i4 + r2->size[1] * i5];
    }
  }

  emxFree_int32_T(&r2);
  emlrtDestroyArray(&u);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *Data
 *                const char_T *identifier
 *                emxArray_int32_T *y
 * Return Type  : void
 */
static void g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Data, const
  char_T *identifier, emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  h_emlrt_marshallIn(sp, emlrtAlias(Data), &thisId, y);
  emlrtDestroyArray(&Data);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_int32_T *y
 * Return Type  : void
 */
static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y)
{
  emxArray_int32_T *r3;
  int32_T i6;
  int32_T loop_ub;
  int32_T i7;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &r3, 2, true);
  x_emlrt_marshallIn(sp, emlrtAlias(u), parentId, r3);
  i6 = y->size[0] * y->size[1];
  y->size[1] = 5;
  y->size[0] = r3->size[1];
  emxEnsureCapacity_int32_T(y, i6);
  loop_ub = r3->size[1];
  for (i6 = 0; i6 < loop_ub; i6++) {
    for (i7 = 0; i7 < 5; i7++) {
      y->data[i7 + 5 * i6] = r3->data[i6 + r3->size[1] * i7];
    }
  }

  emxFree_int32_T(&r3);
  emlrtDestroyArray(&u);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *Dia
 *                const char_T *identifier
 *                emxArray_int32_T *y
 * Return Type  : void
 */
static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Dia, const
  char_T *identifier, emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  j_emlrt_marshallIn(sp, emlrtAlias(Dia), &thisId, y);
  emlrtDestroyArray(&Dia);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_int32_T *y
 * Return Type  : void
 */
static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y)
{
  emxArray_int32_T *r4;
  int32_T i8;
  int32_T loop_ub;
  int32_T i9;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &r4, 2, true);
  y_emlrt_marshallIn(sp, emlrtAlias(u), parentId, r4);
  i8 = y->size[0] * y->size[1];
  y->size[1] = 4;
  y->size[0] = r4->size[1];
  emxEnsureCapacity_int32_T(y, i8);
  loop_ub = r4->size[1];
  for (i8 = 0; i8 < loop_ub; i8++) {
    i9 = i8 << 2;
    y->data[i9] = r4->data[i8];
    y->data[1 + i9] = r4->data[i8 + r4->size[1]];
    y->data[2 + i9] = r4->data[i8 + (r4->size[1] << 1)];
    y->data[3 + i9] = r4->data[i8 + r4->size[1] * 3];
  }

  emxFree_int32_T(&r4);
  emlrtDestroyArray(&u);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *DispMExD
 *                const char_T *identifier
 *                emxArray_int32_T *y
 * Return Type  : void
 */
static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *DispMExD,
  const char_T *identifier, emxArray_int32_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  l_emlrt_marshallIn(sp, emlrtAlias(DispMExD), &thisId, y);
  emlrtDestroyArray(&DispMExD);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_int32_T *y
 * Return Type  : void
 */
static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_int32_T *y)
{
  emxArray_int32_T *r5;
  int32_T i10;
  int32_T loop_ub;
  int32_T i11;
  emlrtHeapReferenceStackEnterFcnR2012b(sp);
  emxInit_int32_T(sp, &r5, 2, true);
  ab_emlrt_marshallIn(sp, emlrtAlias(u), parentId, r5);
  i10 = y->size[0] * y->size[1];
  y->size[1] = r5->size[0];
  y->size[0] = 6;
  emxEnsureCapacity_int32_T(y, i10);
  for (i10 = 0; i10 < 6; i10++) {
    loop_ub = r5->size[0];
    for (i11 = 0; i11 < loop_ub; i11++) {
      y->data[i11 + y->size[1] * i10] = r5->data[i10 + 6 * i11];
    }
  }

  emxFree_int32_T(&r5);
  emlrtDestroyArray(&u);
  emlrtHeapReferenceStackLeaveFcnR2012b(sp);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *TipoOp
 *                const char_T *identifier
 * Return Type  : int32_T
 */
static int32_T m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *TipoOp,
  const char_T *identifier)
{
  int32_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = n_emlrt_marshallIn(sp, emlrtAlias(TipoOp), &thisId);
  emlrtDestroyArray(&TipoOp);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : int32_T
 */
static int32_T n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int32_T y;
  y = bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *k0
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *k0, const
  char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = p_emlrt_marshallIn(sp, emlrtAlias(k0), &thisId);
  emlrtDestroyArray(&k0);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *ProbXEst
 *                const char_T *identifier
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *ProbXEst,
  const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  r_emlrt_marshallIn(sp, emlrtAlias(ProbXEst), &thisId, y);
  emlrtDestroyArray(&ProbXEst);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                emxArray_real_T *y
 * Return Type  : void
 */
static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, emxArray_real_T *y)
{
  db_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *keeppriority
 *                const char_T *identifier
 * Return Type  : boolean_T
 */
static boolean_T s_emlrt_marshallIn(const emlrtStack *sp, const mxArray
  *keeppriority, const char_T *identifier)
{
  boolean_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = t_emlrt_marshallIn(sp, emlrtAlias(keeppriority), &thisId);
  emlrtDestroyArray(&keeppriority);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : boolean_T
 */
static boolean_T t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = eb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_int32_T *ret
 * Return Type  : void
 */
static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret)
{
  static const int32_T dims[2] = { -1, 8 };

  const boolean_T bv0[2] = { true, false };

  int32_T iv0[2];
  int32_T i12;
  emlrtCheckVsBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "int32",
    false, 2U, *(int32_T (*)[2])&dims[0], (boolean_T *)&bv0[0], iv0);
  i12 = ret->size[0] * ret->size[1];
  ret->size[1] = iv0[0];
  ret->size[0] = iv0[1];
  emxEnsureCapacity_int32_T(ret, i12);
  emlrtImportArrayR2015b(sp, src, ret->data, 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_int32_T *ret
 * Return Type  : void
 */
static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret)
{
  static const int32_T dims[2] = { -1, 7 };

  const boolean_T bv1[2] = { true, false };

  int32_T iv1[2];
  int32_T i13;
  emlrtCheckVsBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "int32",
    false, 2U, *(int32_T (*)[2])&dims[0], (boolean_T *)&bv1[0], iv1);
  i13 = ret->size[0] * ret->size[1];
  ret->size[1] = iv1[0];
  ret->size[0] = iv1[1];
  emxEnsureCapacity_int32_T(ret, i13);
  emlrtImportArrayR2015b(sp, src, ret->data, 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_int32_T *ret
 * Return Type  : void
 */
static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret)
{
  static const int32_T dims[2] = { -1, -1 };

  const boolean_T bv2[2] = { true, true };

  int32_T iv2[2];
  int32_T i14;
  emlrtCheckVsBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "int32",
    false, 2U, *(int32_T (*)[2])&dims[0], (boolean_T *)&bv2[0], iv2);
  i14 = ret->size[0] * ret->size[1];
  ret->size[1] = iv2[0];
  ret->size[0] = iv2[1];
  emxEnsureCapacity_int32_T(ret, i14);
  emlrtImportArrayR2015b(sp, src, ret->data, 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_int32_T *ret
 * Return Type  : void
 */
static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret)
{
  static const int32_T dims[2] = { -1, 5 };

  const boolean_T bv3[2] = { true, false };

  int32_T iv3[2];
  int32_T i15;
  emlrtCheckVsBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "int32",
    false, 2U, *(int32_T (*)[2])&dims[0], (boolean_T *)&bv3[0], iv3);
  i15 = ret->size[0] * ret->size[1];
  ret->size[1] = iv3[0];
  ret->size[0] = iv3[1];
  emxEnsureCapacity_int32_T(ret, i15);
  emlrtImportArrayR2015b(sp, src, ret->data, 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 *                emxArray_int32_T *ret
 * Return Type  : void
 */
static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId, emxArray_int32_T *ret)
{
  static const int32_T dims[2] = { -1, 4 };

  const boolean_T bv4[2] = { true, false };

  int32_T iv4[2];
  int32_T i16;
  emlrtCheckVsBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "int32",
    false, 2U, *(int32_T (*)[2])&dims[0], (boolean_T *)&bv4[0], iv4);
  i16 = ret->size[0] * ret->size[1];
  ret->size[1] = iv4[0];
  ret->size[0] = iv4[1];
  emxEnsureCapacity_int32_T(ret, i16);
  emlrtImportArrayR2015b(sp, src, ret->data, 4, false);
  emlrtDestroyArray(&src);
}

/*
 * Arguments    : int32_T nlhs
 * Return Type  : void
 */
void BDCreator_func_api(int32_T nlhs)
{
  (void)nlhs;

  /* Invoke the target function */
  BDCreator_func();
}

/*
 * Arguments    : const mxArray * const prhs[36]
 *                int32_T nlhs
 * Return Type  : void
 */
void main_UCI_func_api(const mxArray * const prhs[36], int32_T nlhs)
{
  emxArray_int32_T *CP;
  emxArray_int32_T *RO;
  emxArray_int32_T *CPO;
  emxArray_int32_T *CPrO;
  emxArray_int32_T *CR;
  emxArray_int32_T *Data;
  emxArray_int32_T *Dia;
  emxArray_int32_T *DispMExD;
  emxArray_int32_T *MA;
  emxArray_int32_T *MAn;
  emxArray_int32_T *ME;
  emxArray_int32_T *S;
  emxArray_real_T *ProbXEst;
  int32_T TipoOp;
  int32_T NumEsp;
  int32_T NumTOp;
  int32_T NumSalOp;
  int32_T NumCPO;
  int32_T NumCPrO;
  int32_T NumCR;
  int32_T NumMedEsp;
  int32_T NumEspxE;
  int32_T NumAsist;
  int32_T NumAnest;
  real_T k0;
  real_T k1;
  real_T k2;
  real_T k3;
  int32_T numIQ;
  int32_T numIC;
  real_T taxC;
  real_T taxE;
  real_T taxEQ;
  int32_T genToWidth;
  int32_T generations;
  boolean_T keeppriority;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_int32_T(&st, &CP, 2, true);
  emxInit_int32_T(&st, &RO, 2, true);
  emxInit_int32_T(&st, &CPO, 2, true);
  emxInit_int32_T(&st, &CPrO, 2, true);
  emxInit_int32_T(&st, &CR, 2, true);
  emxInit_int32_T(&st, &Data, 2, true);
  emxInit_int32_T(&st, &Dia, 2, true);
  emxInit_int32_T(&st, &DispMExD, 2, true);
  emxInit_int32_T(&st, &MA, 2, true);
  emxInit_int32_T(&st, &MAn, 2, true);
  emxInit_int32_T(&st, &ME, 2, true);
  emxInit_int32_T(&st, &S, 2, true);
  emxInit_real_T(&st, &ProbXEst, 1, true);

  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "CP", CP);
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "RO", RO);
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "CPO", CPO);
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "CPrO", CPrO);
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[4]), "CR", CR);
  g_emlrt_marshallIn(&st, emlrtAliasP(prhs[5]), "Data", Data);
  i_emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "Dia", Dia);
  k_emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "DispMExD", DispMExD);
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "MA", MA);
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[9]), "MAn", MAn);
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[10]), "ME", ME);
  e_emlrt_marshallIn(&st, emlrtAliasP(prhs[11]), "S", S);
  TipoOp = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[12]), "TipoOp");
  NumEsp = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[13]), "NumEsp");
  NumTOp = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[14]), "NumTOp");
  NumSalOp = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[15]), "NumSalOp");
  NumCPO = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[16]), "NumCPO");
  NumCPrO = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[17]), "NumCPrO");
  NumCR = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[18]), "NumCR");
  NumMedEsp = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[19]), "NumMedEsp");
  NumEspxE = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[20]), "NumEspxE");
  NumAsist = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[21]), "NumAsist");
  NumAnest = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[22]), "NumAnest");
  k0 = o_emlrt_marshallIn(&st, emlrtAliasP(prhs[23]), "k0");
  k1 = o_emlrt_marshallIn(&st, emlrtAliasP(prhs[24]), "k1");
  k2 = o_emlrt_marshallIn(&st, emlrtAliasP(prhs[25]), "k2");
  k3 = o_emlrt_marshallIn(&st, emlrtAliasP(prhs[26]), "k3");
  numIQ = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[27]), "numIQ");
  numIC = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[28]), "numIC");
  taxC = o_emlrt_marshallIn(&st, emlrtAliasP(prhs[29]), "taxC");
  taxE = o_emlrt_marshallIn(&st, emlrtAliasP(prhs[30]), "taxE");
  taxEQ = o_emlrt_marshallIn(&st, emlrtAliasP(prhs[31]), "taxEQ");
  q_emlrt_marshallIn(&st, emlrtAliasP(prhs[32]), "ProbXEst", ProbXEst);
  genToWidth = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[33]), "genToWidth");
  generations = m_emlrt_marshallIn(&st, emlrtAliasP(prhs[34]), "generations");
  keeppriority = s_emlrt_marshallIn(&st, emlrtAliasP(prhs[35]), "keeppriority");

  /* Invoke the target function */
  main_UCI_func(CP, RO, CPO, CPrO, CR, Data, Dia, DispMExD, MA, MAn, ME, S,
                TipoOp, NumEsp, NumTOp, NumSalOp, NumCPO, NumCPrO, NumCR,
                NumMedEsp, NumEspxE, NumAsist, NumAnest, k0, k1, k2, k3, numIQ,
                numIC, taxC, taxE, taxEQ, ProbXEst, genToWidth, generations,
                keeppriority);
  emxFree_real_T(&ProbXEst);
  emxFree_int32_T(&S);
  emxFree_int32_T(&ME);
  emxFree_int32_T(&MAn);
  emxFree_int32_T(&MA);
  emxFree_int32_T(&DispMExD);
  emxFree_int32_T(&Dia);
  emxFree_int32_T(&Data);
  emxFree_int32_T(&CR);
  emxFree_int32_T(&CPrO);
  emxFree_int32_T(&CPO);
  emxFree_int32_T(&RO);
  emxFree_int32_T(&CP);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
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

/*
 * Arguments    : void
 * Return Type  : void
 */
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

/*
 * Arguments    : void
 * Return Type  : void
 */
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

/*
 * File trailer for _coder_model_api.c
 *
 * [EOF]
 */
