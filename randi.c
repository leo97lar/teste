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
#include "Calendario.h"
#include "Codificacion_de_dias_func.h"
#include "CreaPoQunniforme.h"
#include "Edade.h"
#include "PLOTT_func.h"
#include "actIQ.h"
#include "aevSPLap.h"
#include "casorandom.h"
#include "cc.h"
#include "favalia.h"
#include "funcionC.h"
#include "funcionCPrO.h"
#include "funcionCR.h"
#include "funcionDia.h"
#include "funcionRP.h"
#include "main_UCI_func.h"
#include "obsIQ.h"
#include "obsIQini.h"
#include "sch.h"
#include "randi.h"
#include "rand.h"

/* Function Definitions */
void randi(double r[2000])
{
  int k;
  g_rand(r);
  for (k = 0; k < 2000; k++) {
    r[k] = 1.0 + floor(r[k] * 200.0);
  }
}

/* End of code generation (randi.c) */
