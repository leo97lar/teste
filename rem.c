/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rem.c
 *
 * Code generation for function 'rem'
 *
 */

/* Include files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "rem.h"
#include "aevSPLap.h"
#include "model_rtwutil.h"

/* Function Definitions */
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

/* End of code generation (rem.c) */
