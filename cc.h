/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cc.h
 *
 * Code generation for function 'cc'
 *
 */

#ifndef CC_H
#define CC_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void b_cc(const emxArray_int32_T *IC, emxArray_int32_T *newIC);
extern void cc(const emxArray_int32_T *IC, int numIC, double taxC, int NumTOp,
               emxArray_int32_T *newIC);

#endif

/* End of code generation (cc.h) */
