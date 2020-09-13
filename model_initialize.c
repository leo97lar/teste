/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * model_initialize.c
 *
 * Code generation for function 'model_initialize'
 *
 */

/* Include files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "model_initialize.h"
#include "eml_rand_shr3cong_stateful.h"
#include "eml_rand_mcg16807_stateful.h"
#include "eml_rand.h"
#include "getTime.h"
#include "timeKeeper.h"
#include "eml_rand_mt19937ar_stateful.h"

/* Function Definitions */
void model_initialize(void)
{
  state_not_empty_init();
  savedTime_not_empty_init();
  freq_not_empty_init();
  eml_rand_init();
  eml_rand_mcg16807_stateful_init();
  eml_rand_shr3cong_stateful_init();
}

/* End of code generation (model_initialize.c) */
