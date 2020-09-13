/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * obsIQ.h
 *
 * Code generation for function 'obsIQ'
 *
 */

#ifndef OBSIQ_H
#define OBSIQ_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void obsIQ(const emxArray_real_T *IQ, int numIQ, int numObsIQ,
                  emxArray_int32_T *newIC);

#endif

/* End of code generation (obsIQ.h) */
