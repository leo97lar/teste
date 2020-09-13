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
#include "main_UCI_func.h"
#include "Edade.h"
#include "model_emxutil.h"
#include "sum.h"
#include "rand.h"

/* Function Definitions */

/*
 * function [ Edade ] = Edade( min,max,Num )
 */
void Edade(double b_Edade[2000])
{
  emxArray_real_T *r1;
  int i;
  double r;
  int j;
  boolean_T exitg1;
  int k;
  int i4;
  boolean_T guard1 = false;
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

  boolean_T y;
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
  /* 'Edade:4' PEd= min:1:max; */
  /* 'Edade:6' CtdPtos = max-min+1; */
  /* 'Edade:8' CtdadXStep= ((CtdPtos-1)*CtdPtos)/2; */
  /* 'Edade:10' n=1/(CtdadXStep*2); */
  /* 'Edade:12' pIni = (1-CtdadXStep*n)/CtdPtos; */
  /* 'Edade:13' pFim = pIni+n*(max-min); */
  /* 'Edade:14' ProbXEdade = linspace(double(pIni), double(pFim), double(CtdPtos)); */
  /* 'Edade:16' Edade = zeros(Num,1); */
  memset(&b_Edade[0], 0, 2000U * sizeof(double));

  /* 'Edade:18' for i=1:Num */
  emxInit_real_T(&r1, 2);
  for (i = 0; i < 2000; i++) {
    /* 'Edade:20' r=rand; */
    r = d_rand();

    /* 'Edade:22' for j=1:length(ProbXEdade) */
    j = 0;
    exitg1 = false;
    while ((!exitg1) && (j < 71)) {
      /* 'Edade:24' if sum(ProbXEdade(1:j),2)<=r && sum(ProbXEdade(1:j+1),2)>r */
      k = j + 1;
      i4 = r1->size[0] * r1->size[1];
      r1->size[0] = 1;
      r1->size[1] = j + 1;
      emxEnsureCapacity_real_T(r1, i4);
      for (i4 = 0; i4 < k; i4++) {
        r1->data[i4] = dv0[i4];
      }

      guard1 = false;
      if (sum(r1) <= r) {
        k = j + 2;
        i4 = r1->size[0] * r1->size[1];
        r1->size[0] = 1;
        r1->size[1] = j + 2;
        emxEnsureCapacity_real_T(r1, i4);
        for (i4 = 0; i4 < k; i4++) {
          r1->data[i4] = dv0[i4];
        }

        if (sum(r1) > r) {
          /* 'Edade:25' Edade(i)=PEd(j+1); */
          b_Edade[i] = 5.0 + (((1.0 + (double)j) + 1.0) - 1.0);
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
          /* 'Edade:27' elseif ProbXEdade>r */
          /* 'Edade:28' Edade(i)=PEd(j); */
          b_Edade[i] = 5.0 + ((1.0 + (double)j) - 1.0);
          exitg1 = true;
        } else {
          j++;
        }
      }
    }
  }

  emxFree_real_T(&r1);
}

/* End of code generation (Edade.c) */
