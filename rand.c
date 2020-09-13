/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rand.c
 *
 * Code generation for function 'rand'
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
#include "rand.h"
#include "model_emxutil.h"
#include "model_data.h"

/* Function Declarations */
static double eml_rand_mt19937ar(unsigned int b_state[625]);

/* Function Definitions */
static double eml_rand_mt19937ar(unsigned int b_state[625])
{
  double r;
  int j;
  unsigned int u[2];
  unsigned int mti;
  int kk;
  unsigned int y;

  /* ========================= COPYRIGHT NOTICE ============================ */
  /*  This is a uniform (0,1) pseudorandom number generator based on:        */
  /*                                                                         */
  /*  A C-program for MT19937, with initialization improved 2002/1/26.       */
  /*  Coded by Takuji Nishimura and Makoto Matsumoto.                        */
  /*                                                                         */
  /*  Copyright (C) 1997 - 2002, Makoto Matsumoto and Takuji Nishimura,      */
  /*  All rights reserved.                                                   */
  /*                                                                         */
  /*  Redistribution and use in source and binary forms, with or without     */
  /*  modification, are permitted provided that the following conditions     */
  /*  are met:                                                               */
  /*                                                                         */
  /*    1. Redistributions of source code must retain the above copyright    */
  /*       notice, this list of conditions and the following disclaimer.     */
  /*                                                                         */
  /*    2. Redistributions in binary form must reproduce the above copyright */
  /*       notice, this list of conditions and the following disclaimer      */
  /*       in the documentation and/or other materials provided with the     */
  /*       distribution.                                                     */
  /*                                                                         */
  /*    3. The names of its contributors may not be used to endorse or       */
  /*       promote products derived from this software without specific      */
  /*       prior written permission.                                         */
  /*                                                                         */
  /*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    */
  /*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      */
  /*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  */
  /*  A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT  */
  /*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  */
  /*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT       */
  /*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  */
  /*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  */
  /*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT    */
  /*  (INCLUDING  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE */
  /*  OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
  /*                                                                         */
  /* =============================   END   ================================= */
  do {
    for (j = 0; j < 2; j++) {
      mti = b_state[624] + 1U;
      if (mti >= 625U) {
        for (kk = 0; kk < 227; kk++) {
          y = (b_state[kk] & 2147483648U) | (b_state[1 + kk] & 2147483647U);
          if ((y & 1U) == 0U) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          b_state[kk] = b_state[kk + 397] ^ y;
        }

        for (kk = 0; kk < 396; kk++) {
          y = (b_state[kk + 227] & 2147483648U) | (b_state[228 + kk] &
            2147483647U);
          if ((y & 1U) == 0U) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          b_state[kk + 227] = b_state[kk] ^ y;
        }

        y = (b_state[623] & 2147483648U) | (b_state[0] & 2147483647U);
        if ((y & 1U) == 0U) {
          y >>= 1U;
        } else {
          y = y >> 1U ^ 2567483615U;
        }

        b_state[623] = b_state[396] ^ y;
        mti = 1U;
      }

      y = b_state[(int)mti - 1];
      b_state[624] = mti;
      y ^= y >> 11U;
      y ^= y << 7U & 2636928640U;
      y ^= y << 15U & 4022730752U;
      u[j] = y ^ y >> 18U;
    }

    u[0] >>= 5U;
    u[1] >>= 6U;
    r = 1.1102230246251565E-16 * ((double)u[0] * 6.7108864E+7 + (double)u[1]);
  } while (r == 0.0);

  return r;
}

double b_rand(void)
{
  return eml_rand_mt19937ar(state);
}

void c_rand(int varargin_2, emxArray_real_T *r)
{
  int i24;
  int k;
  i24 = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = varargin_2;
  emxEnsureCapacity_real_T(r, i24);
  i24 = r->size[1];
  for (k = 0; k < i24; k++) {
    r->data[k] = eml_rand_mt19937ar(state);
  }
}

void d_rand(double r[2])
{
  r[0] = eml_rand_mt19937ar(state);
  r[1] = eml_rand_mt19937ar(state);
}

void e_rand(int varargin_1, emxArray_real_T *r)
{
  int i29;
  int k;
  i29 = r->size[0];
  r->size[0] = varargin_1;
  emxEnsureCapacity_real_T(r, i29);
  i29 = r->size[0];
  for (k = 0; k < i29; k++) {
    r->data[k] = eml_rand_mt19937ar(state);
  }
}

void f_rand(double r[200])
{
  int k;
  for (k = 0; k < 200; k++) {
    r[k] = eml_rand_mt19937ar(state);
  }
}

void g_rand(double r[2000])
{
  int k;
  for (k = 0; k < 2000; k++) {
    r[k] = eml_rand_mt19937ar(state);
  }
}

void h_rand(double r[150])
{
  int k;
  for (k = 0; k < 150; k++) {
    r[k] = eml_rand_mt19937ar(state);
  }
}

void i_rand(double r[225])
{
  int k;
  for (k = 0; k < 225; k++) {
    r[k] = eml_rand_mt19937ar(state);
  }
}

void j_rand(double r[375])
{
  int k;
  for (k = 0; k < 375; k++) {
    r[k] = eml_rand_mt19937ar(state);
  }
}

void k_rand(double r[450])
{
  int k;
  for (k = 0; k < 450; k++) {
    r[k] = eml_rand_mt19937ar(state);
  }
}

/* End of code generation (rand.c) */
