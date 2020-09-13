/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * randi.c
 *
 * Code generation for function 'randi'
 *
 */

/* Include files */
#include <math.h>
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "randi.h"
#include "rand.h"

/* Function Definitions */

/*
 *
 */
double b_randi(void)
{
  double r;
  r = d_rand();
  return 1.0 + floor(r * 30.0);
}

/*
 *
 */
void randi(double r[2000])
{
  int k;
  c_rand(r);
  for (k = 0; k < 2000; k++) {
    r[k] = 1.0 + floor(r[k] * 200.0);
  }
}

/* End of code generation (randi.c) */
