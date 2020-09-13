/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * PLOTT_func.c
 *
 * Code generation for function 'PLOTT_func'
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
#include <stdio.h>

/* Function Definitions */
void PLOTT_func(const emxArray_real_T *trace, const emxArray_int32_T
                *bestexperimento)
{
  (void)trace;

  /* figure */
  /* hold on */
  /* plot(1:100,trace(:,3),'O') */
  /* errorbar(1:100,trace(:,3),trace(:,4),'.') */
  printf("ignore: %2d, %2d", bestexperimento->data[2], bestexperimento->data[4]);
  fflush(stdout);
}

/* End of code generation (PLOTT_func.c) */
