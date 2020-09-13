/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Calendario.c
 *
 * Code generation for function 'Calendario'
 *
 */

/* Include files */
#include <string.h>
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
#include "repmat.h"
#include "model_data.h"

/* Function Definitions */
void Calendario(double Data[87600], double Dia[2920])
{
  static double mes[8760];
  static double dias[8760];
  double dv1[735];
  int i;
  static double dv2[17520];
  static double dv3[17520];

  /*  Genero el calendario con las fechas y los horarios desde el 1 de enero */
  /*  del 2017 hasta el 31 de diciembre del 2018. Luego elimino los domingos y */
  /*  las horas que no se trabajan los sabados. */
  b_repmat(mes);
  memcpy(&dias[0], &mes[0], 8760U * sizeof(double));
  c_repmat(mes);

  /*  [Dom Lun Mar Mier Jue Vier Sab] */
  e_repmat(dv1);
  for (i = 0; i < 730; i++) {
    Dia[i] = 1.0 + (double)i;
    Dia[730 + i] = dv1[i];
  }

  memset(&Dia[1460], 0, 730U * sizeof(double));
  memset(&Dia[2190], 0, 730U * sizeof(double));
  Dia[1461] = 32.0;
  Dia[2191] = 43.0;
  d_repmat(dv2);
  f_repmat(dv3);
  for (i = 0; i < 8760; i++) {
    Data[i] = dias[i];
    Data[i + 8760] = dias[i];
    Data[17520 + i] = mes[i];
    Data[i + 26280] = mes[i];
  }

  for (i = 0; i < 17520; i++) {
    Data[35040 + i] = iv0[i];
    Data[52560 + i] = dv2[i];
    Data[70080 + i] = dv3[i];
  }

  for (i = 0; i < 728; i++) {
    switch ((int)Dia[i + 732]) {
     case 1:
      break;

     case 7:
      Dia[i + 1462] = Dia[i + 1461] + 24.0;
      Dia[i + 2192] = (Dia[i + 1462] + 8.0) - 1.0;
      break;

     default:
      if (Dia[i + 732] == 2.0) {
        Dia[i + 1462] = Dia[1460 + i] + 48.0;
        Dia[i + 2192] = (Dia[i + 1462] + 12.0) - 1.0;
      } else {
        Dia[i + 1462] = Dia[i + 1461] + 24.0;
        Dia[i + 2192] = (Dia[i + 1462] + 12.0) - 1.0;
      }
      break;
    }
  }
}

/* End of code generation (Calendario.c) */
