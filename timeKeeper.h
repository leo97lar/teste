/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: timeKeeper.h
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 18:10:16
 */

#ifndef TIMEKEEPER_H
#define TIMEKEEPER_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "model_types.h"

/* Function Declarations */
extern void b_timeKeeper(double *outTime_tv_sec, double *outTime_tv_nsec);
extern void savedTime_not_empty_init(void);
extern void timeKeeper(double newTime_tv_sec, double newTime_tv_nsec);

#endif

/*
 * File trailer for timeKeeper.h
 *
 * [EOF]
 */
