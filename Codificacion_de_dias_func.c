/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Codificacion_de_dias_func.c
 *
 * Code generation for function 'Codificacion_de_dias_func'
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
#include "model_emxutil.h"
#include "nullAssignment.h"
#include "repmat.h"
#include "model_data.h"

/* Function Definitions */
void Codificacion_de_dias_func(void)
{
  double dv4[8760];
  double dias[8760];
  static double dv5[17520];
  static double dv6[17520];
  int i45;
  static double b_dias[87600];
  emxArray_real_T *Data;
  int Data_size[1];
  emxArray_real_T *r5;
  boolean_T Data_data[17520];
  int loop_ub;

  /*  Para creer mi Horario codificado desde el 1ro de enero del 2017 hasta el 31 de diciembre del 2018 */
  c_repmat(dv4);
  memcpy(&dias[0], &dv4[0], 8760U * sizeof(double));
  d_repmat(dv4);

  /*  [Dom Lun Mar Mier Jue Vier Sab] */
  h_repmat(dv5);
  i_repmat(dv6);
  for (i45 = 0; i45 < 8760; i45++) {
    b_dias[i45] = dias[i45];
    b_dias[i45 + 8760] = dias[i45];
    b_dias[17520 + i45] = dv4[i45];
    b_dias[i45 + 26280] = dv4[i45];
  }

  for (i45 = 0; i45 < 17520; i45++) {
    b_dias[35040 + i45] = iv0[i45];
    b_dias[52560 + i45] = dv5[i45];
    b_dias[70080 + i45] = dv6[i45];
  }

  emxInit_real_T(&Data, 2);
  i45 = Data->size[0] * Data->size[1];
  Data->size[0] = 17520;
  Data->size[1] = 5;
  emxEnsureCapacity_real_T(Data, i45);
  for (i45 = 0; i45 < 87600; i45++) {
    Data->data[i45] = b_dias[i45];
  }

  Data_size[0] = 17520;
  for (i45 = 0; i45 < 17520; i45++) {
    Data_data[i45] = (Data->data[i45 + (Data->size[0] << 2)] == 1.0);
  }

  emxInit_real_T(&r5, 2);
  b_nullAssignment(Data, Data_data, Data_size);
  i45 = r5->size[0] * r5->size[1];
  r5->size[0] = Data->size[0];
  r5->size[1] = 5;
  emxEnsureCapacity_real_T(r5, i45);
  loop_ub = Data->size[0] * Data->size[1];
  for (i45 = 0; i45 < loop_ub; i45++) {
    r5->data[i45] = Data->data[i45];
  }

  loop_ub = Data->size[0];
  Data_size[0] = loop_ub;
  for (i45 = 0; i45 < loop_ub; i45++) {
    Data_data[i45] = ((Data->data[i45 + (Data->size[0] << 2)] == 7.0) &&
                      (Data->data[i45 + Data->size[0] * 3] >= 16.0));
  }

  emxFree_real_T(&Data);
  b_nullAssignment(r5, Data_data, Data_size);
  emxFree_real_T(&r5);
}

/* End of code generation (Codificacion_de_dias_func.c) */
