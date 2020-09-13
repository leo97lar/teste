/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: randi.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 18:10:16
 */

/* Include Files */
#include <math.h>
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "randi.h"
#include "rand.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : double
 */
double b_randi(void)
{
  double r;
  r = d_rand();
  return 1.0 + floor(r * 30.0);
}

/*
 * Arguments    : double r[2000]
 * Return Type  : void
 */
void randi(double r[2000])
{
  int k;
  c_rand(r);
  for (k = 0; k < 2000; k++) {
    r[k] = 1.0 + floor(r[k] * 200.0);
  }
}

/*
 * File trailer for randi.c
 *
 * [EOF]
 */
