/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: rem.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "rem.h"
#include "aevSPLap.h"
#include "model_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : int x
 *                int y
 * Return Type  : int
 */
int b_rem(int x, int y)
{
  int r;
  if (y == 0) {
    r = 0;
  } else {
    r = x - y * div_s32(x, y);
  }

  return r;
}

/*
 * File trailer for rem.c
 *
 * [EOF]
 */
