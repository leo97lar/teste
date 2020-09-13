/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Edade.c
 *
 * Code generation for function 'Edade'
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
#include "sum.h"
#include "rand.h"
#include "model_emxutil.h"
#include "rdivide_helper.h"
#include "colon.h"
#include "model_rtwutil.h"

/* Function Definitions */
void Edade(int b_min, int b_max, int Num, emxArray_real_T *c_Edade)
{
  emxArray_int32_T *PEd;
  int qY;
  long long i37;
  int CtdadXStep;
  int i38;
  double delta1;
  int pIni;
  emxArray_real_T *ProbXEdade;
  emxArray_boolean_T *x;
  emxArray_real_T *b_ProbXEdade;
  boolean_T exitg1;
  boolean_T guard1 = false;
  boolean_T y;
  boolean_T exitg2;
  emxInit_int32_T(&PEd, 2);

  /* UNTITLED3 Summary of this function goes here */
  /*    Detailed explanation goes here */
  eml_signed_integer_colon(b_min, b_max, PEd);
  if ((b_max >= 0) && (b_min < b_max - MAX_int32_T)) {
    qY = MAX_int32_T;
  } else if ((b_max < 0) && (b_min > b_max - MIN_int32_T)) {
    qY = MIN_int32_T;
  } else {
    qY = b_max - b_min;
  }

  if (qY > 2147483646) {
    qY = MAX_int32_T;
  } else {
    qY++;
  }

  i37 = (long long)(qY - 1) * qY;
  if (i37 > 2147483647LL) {
    i37 = 2147483647LL;
  } else {
    if (i37 < -2147483648LL) {
      i37 = -2147483648LL;
    }
  }

  CtdadXStep = (int)rt_roundd((double)(int)i37 / 2.0);
  if (CtdadXStep > 1073741823) {
    i38 = MAX_int32_T;
  } else if (CtdadXStep <= -1073741824) {
    i38 = MIN_int32_T;
  } else {
    i38 = CtdadXStep << 1;
  }

  delta1 = rt_roundd(1.0 / (double)i38);
  if (delta1 < 2.147483648E+9) {
    if (delta1 >= -2.147483648E+9) {
      i38 = (int)delta1;
    } else {
      i38 = MIN_int32_T;
    }
  } else {
    i38 = MAX_int32_T;
  }

  i37 = (long long)CtdadXStep * i38;
  if (i37 > 2147483647LL) {
    i37 = 2147483647LL;
  } else {
    if (i37 < -2147483648LL) {
      i37 = -2147483648LL;
    }
  }

  CtdadXStep = (int)i37;
  if (CtdadXStep < -2147483646) {
    CtdadXStep = MAX_int32_T;
  } else {
    CtdadXStep = 1 - CtdadXStep;
  }

  pIni = rdivide_helper(CtdadXStep, qY);
  if ((b_max >= 0) && (b_min < b_max - MAX_int32_T)) {
    CtdadXStep = MAX_int32_T;
  } else if ((b_max < 0) && (b_min > b_max - MIN_int32_T)) {
    CtdadXStep = MIN_int32_T;
  } else {
    CtdadXStep = b_max - b_min;
  }

  i37 = (long long)i38 * CtdadXStep;
  if (i37 > 2147483647LL) {
    i37 = 2147483647LL;
  } else {
    if (i37 < -2147483648LL) {
      i37 = -2147483648LL;
    }
  }

  CtdadXStep = (int)i37;
  if ((pIni < 0) && (CtdadXStep < MIN_int32_T - pIni)) {
    CtdadXStep = MIN_int32_T;
  } else if ((pIni > 0) && (CtdadXStep > MAX_int32_T - pIni)) {
    CtdadXStep = MAX_int32_T;
  } else {
    CtdadXStep += pIni;
  }

  if (qY < 0) {
    qY = 0;
  }

  emxInit_real_T(&ProbXEdade, 2);
  i38 = ProbXEdade->size[0] * ProbXEdade->size[1];
  ProbXEdade->size[0] = 1;
  ProbXEdade->size[1] = qY;
  emxEnsureCapacity_real_T(ProbXEdade, i38);
  if (ProbXEdade->size[1] >= 1) {
    ProbXEdade->data[ProbXEdade->size[1] - 1] = CtdadXStep;
    if (ProbXEdade->size[1] >= 2) {
      ProbXEdade->data[0] = pIni;
      if (ProbXEdade->size[1] >= 3) {
        delta1 = ((double)CtdadXStep - (double)pIni) / ((double)ProbXEdade->
          size[1] - 1.0);
        i38 = ProbXEdade->size[1];
        for (CtdadXStep = 0; CtdadXStep <= i38 - 3; CtdadXStep++) {
          ProbXEdade->data[1 + CtdadXStep] = (double)pIni + (1.0 + (double)
            CtdadXStep) * delta1;
        }
      }
    }
  }

  i38 = c_Edade->size[0];
  c_Edade->size[0] = Num;
  emxEnsureCapacity_real_T(c_Edade, i38);
  for (i38 = 0; i38 < Num; i38++) {
    c_Edade->data[i38] = 0.0;
  }

  emxInit_boolean_T(&x, 2);
  emxInit_real_T(&b_ProbXEdade, 2);
  for (qY = 0; qY < Num; qY++) {
    delta1 = b_rand();
    pIni = 1;
    exitg1 = false;
    while ((!exitg1) && (pIni - 1 <= ProbXEdade->size[1] - 1)) {
      i38 = b_ProbXEdade->size[0] * b_ProbXEdade->size[1];
      b_ProbXEdade->size[0] = 1;
      b_ProbXEdade->size[1] = pIni;
      emxEnsureCapacity_real_T(b_ProbXEdade, i38);
      for (i38 = 0; i38 < pIni; i38++) {
        b_ProbXEdade->data[i38] = ProbXEdade->data[i38];
      }

      guard1 = false;
      if (sum(b_ProbXEdade) <= delta1) {
        i38 = b_ProbXEdade->size[0] * b_ProbXEdade->size[1];
        b_ProbXEdade->size[0] = 1;
        b_ProbXEdade->size[1] = pIni + 1;
        emxEnsureCapacity_real_T(b_ProbXEdade, i38);
        for (i38 = 0; i38 <= pIni; i38++) {
          b_ProbXEdade->data[i38] = ProbXEdade->data[i38];
        }

        if (sum(b_ProbXEdade) > delta1) {
          c_Edade->data[qY] = PEd->data[pIni];
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        i38 = x->size[0] * x->size[1];
        x->size[0] = 1;
        x->size[1] = ProbXEdade->size[1];
        emxEnsureCapacity_boolean_T(x, i38);
        CtdadXStep = ProbXEdade->size[0] * ProbXEdade->size[1];
        for (i38 = 0; i38 < CtdadXStep; i38++) {
          x->data[i38] = (ProbXEdade->data[i38] > delta1);
        }

        y = (x->size[1] != 0);
        if (y) {
          CtdadXStep = 0;
          exitg2 = false;
          while ((!exitg2) && (CtdadXStep <= x->size[1] - 1)) {
            if (!x->data[CtdadXStep]) {
              y = false;
              exitg2 = true;
            } else {
              CtdadXStep++;
            }
          }
        }

        if (y) {
          c_Edade->data[qY] = PEd->data[pIni - 1];
          exitg1 = true;
        } else {
          pIni++;
        }
      }
    }
  }

  emxFree_real_T(&b_ProbXEdade);
  emxFree_boolean_T(&x);
  emxFree_real_T(&ProbXEdade);
  emxFree_int32_T(&PEd);
}

void b_Edade(double c_Edade[2000])
{
  int i;
  double r;
  int j;
  boolean_T exitg1;
  int tmp_size[2];
  double tmp_data[71];
  static const double dv0[71] = { 0.0070422535211267607, 0.0072434607645875254,
    0.00744466800804829, 0.0076458752515090548, 0.0078470824949698186,
    0.0080482897384305842, 0.008249496981891348, 0.0084507042253521118,
    0.0086519114688128774, 0.0088531187122736412, 0.0090543259557344068,
    0.00925553319919517, 0.0094567404426559344, 0.0096579476861167,
    0.0098591549295774655, 0.010060362173038229, 0.010261569416498993,
    0.010462776659959759, 0.010663983903420523, 0.010865191146881288,
    0.011066398390342052, 0.011267605633802816, 0.011468812877263581,
    0.011670020120724345, 0.011871227364185111, 0.012072434607645875,
    0.012273641851106638, 0.012474849094567404, 0.012676056338028169,
    0.012877263581488933, 0.013078470824949697, 0.013279678068410461,
    0.013480885311871227, 0.013682092555331992, 0.013883299798792756,
    0.01408450704225352, 0.014285714285714284, 0.014486921529175049,
    0.014688128772635815, 0.014889336016096578, 0.015090543259557342,
    0.015291750503018106, 0.015492957746478873, 0.015694164989939637,
    0.0158953722334004, 0.016096579476861165, 0.016297786720321929,
    0.016498993963782696, 0.01670020120724346, 0.016901408450704224,
    0.017102615694164987, 0.017303822937625755, 0.017505030181086519,
    0.017706237424547282, 0.017907444668008046, 0.01810865191146881,
    0.018309859154929577, 0.018511066398390341, 0.018712273641851105,
    0.018913480885311869, 0.019114688128772633, 0.0193158953722334,
    0.019517102615694164, 0.019718309859154928, 0.019919517102615691,
    0.020120724346076455, 0.020321931589537223, 0.020523138832997986,
    0.02072434607645875, 0.020925553319919514, 0.021126760563380281 };

  emxArray_real_T b_tmp_data;
  boolean_T guard1 = false;
  boolean_T y;
  emxArray_real_T c_tmp_data;
  int k;
  boolean_T exitg2;
  static const double ProbXEdade[71] = { 0.0070422535211267607,
    0.0072434607645875254, 0.00744466800804829, 0.0076458752515090548,
    0.0078470824949698186, 0.0080482897384305842, 0.008249496981891348,
    0.0084507042253521118, 0.0086519114688128774, 0.0088531187122736412,
    0.0090543259557344068, 0.00925553319919517, 0.0094567404426559344,
    0.0096579476861167, 0.0098591549295774655, 0.010060362173038229,
    0.010261569416498993, 0.010462776659959759, 0.010663983903420523,
    0.010865191146881288, 0.011066398390342052, 0.011267605633802816,
    0.011468812877263581, 0.011670020120724345, 0.011871227364185111,
    0.012072434607645875, 0.012273641851106638, 0.012474849094567404,
    0.012676056338028169, 0.012877263581488933, 0.013078470824949697,
    0.013279678068410461, 0.013480885311871227, 0.013682092555331992,
    0.013883299798792756, 0.01408450704225352, 0.014285714285714284,
    0.014486921529175049, 0.014688128772635815, 0.014889336016096578,
    0.015090543259557342, 0.015291750503018106, 0.015492957746478873,
    0.015694164989939637, 0.0158953722334004, 0.016096579476861165,
    0.016297786720321929, 0.016498993963782696, 0.01670020120724346,
    0.016901408450704224, 0.017102615694164987, 0.017303822937625755,
    0.017505030181086519, 0.017706237424547282, 0.017907444668008046,
    0.01810865191146881, 0.018309859154929577, 0.018511066398390341,
    0.018712273641851105, 0.018913480885311869, 0.019114688128772633,
    0.0193158953722334, 0.019517102615694164, 0.019718309859154928,
    0.019919517102615691, 0.020120724346076455, 0.020321931589537223,
    0.020523138832997986, 0.02072434607645875, 0.020925553319919514,
    0.021126760563380281 };

  /* UNTITLED3 Summary of this function goes here */
  /*    Detailed explanation goes here */
  memset(&c_Edade[0], 0, 2000U * sizeof(double));
  for (i = 0; i < 2000; i++) {
    r = b_rand();
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j < 71)) {
      tmp_size[0] = 1;
      tmp_size[1] = j + 1;
      memcpy(&tmp_data[0], &dv0[0], (unsigned int)((j + 1) * (int)sizeof(double)));
      b_tmp_data.data = &tmp_data[0];
      b_tmp_data.size = &tmp_size[0];
      b_tmp_data.allocatedSize = 71;
      b_tmp_data.numDimensions = 2;
      b_tmp_data.canFreeData = false;
      guard1 = false;
      if (sum(&b_tmp_data) <= r) {
        tmp_size[0] = 1;
        tmp_size[1] = j + 2;
        memcpy(&tmp_data[0], &dv0[0], (unsigned int)((j + 2) * (int)sizeof
                (double)));
        c_tmp_data.data = &tmp_data[0];
        c_tmp_data.size = &tmp_size[0];
        c_tmp_data.allocatedSize = 71;
        c_tmp_data.numDimensions = 2;
        c_tmp_data.canFreeData = false;
        if (sum(&c_tmp_data) > r) {
          c_Edade[i] = 5.0 + (((1.0 + (double)j) + 1.0) - 1.0);
          exitg1 = true;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        y = true;
        k = 0;
        exitg2 = false;
        while ((!exitg2) && (k < 71)) {
          if (ProbXEdade[k] <= r) {
            y = false;
            exitg2 = true;
          } else {
            k++;
          }
        }

        if (y) {
          c_Edade[i] = 5.0 + (double)j;
          exitg1 = true;
        } else {
          j++;
        }
      }
    }
  }
}

/* End of code generation (Edade.c) */
