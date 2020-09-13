/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * colon.c
 *
 * Code generation for function 'colon'
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
#include "colon.h"
#include "model_emxutil.h"

/* Function Definitions */
void eml_signed_integer_colon(int a, int b, emxArray_int32_T *y)
{
  int n;
  unsigned int nm1;
  int yk;
  int k;
  if (b < a) {
    n = 0;
  } else {
    if ((a < 0) && (b >= 0)) {
      nm1 = (unsigned int)b - a;
    } else {
      nm1 = (unsigned int)(b - a);
    }

    n = (int)nm1 + 1;
  }

  yk = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_int32_T(y, yk);
  if (n > 0) {
    y->data[0] = a;
    yk = a;
    for (k = 2; k <= n; k++) {
      yk++;
      y->data[k - 1] = yk;
    }
  }
}

/* End of code generation (colon.c) */
