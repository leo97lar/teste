/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * obsIQini.h
 *
 * Code generation for function 'obsIQini'
 *
 */

#ifndef OBSIQINI_H
#define OBSIQINI_H

/* Include files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void obsIQini(const emxArray_real_T *IQ, int numIQ, int numObsIQ, const
                     emxArray_real_T *ProbXEst, emxArray_int32_T *newIC);

#endif

/* End of code generation (obsIQini.h) */
