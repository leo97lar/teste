/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * nonSingletonDim.c
 *
 * Code generation for function 'nonSingletonDim'
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
#include "nonSingletonDim.h"

/* Function Definitions */
int nonSingletonDim(const emxArray_int32_T *x)
{
  int dim;
  dim = 2;
  if (x->size[0] != 1) {
    dim = 1;
  }

  return dim;
}

/* End of code generation (nonSingletonDim.c) */
