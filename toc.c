/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * toc.c
 *
 * Code generation for function 'toc'
 *
 */

/* Include files */
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
#include "toc.h"
#include "getTime.h"
#include "timeKeeper.h"
#include <stdio.h>

/* Function Definitions */
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

/* End of code generation (toc.c) */
