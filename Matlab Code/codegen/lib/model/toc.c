/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: toc.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "toc.h"
#include "getTime.h"
#include "timeKeeper.h"
#include <stdio.h>

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void toc(void)
{
  double tstart_tv_sec;
  double tstart_tv_nsec;
  double tnow_tv_sec;
  double tnow_tv_nsec;
  b_timeKeeper(&tstart_tv_sec, &tstart_tv_nsec);
  getTime(&tnow_tv_sec, &tnow_tv_nsec);
  printf("Elapsed time is %f seconds\n", (tnow_tv_sec - tstart_tv_sec) +
         (tnow_tv_nsec - tstart_tv_nsec) / 1.0E+9);
  fflush(stdout);
}

/*
 * File trailer for toc.c
 *
 * [EOF]
 */
