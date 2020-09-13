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
#include "main_UCI_func.h"
#include "rand.h"
#include "model_emxutil.h"
#include "model_data.h"

/* Variable Definitions */
static unsigned int c_state[625];

/* Function Declarations */
static double b_eml_rand_mt19937ar(unsigned int d_state[625]);
static double eml_rand_mcg16807(unsigned int *d_state);
static void eml_rand_mt19937ar(unsigned int d_state[625]);

/* Function Definitions */

/*
 *
 */
static double b_eml_rand_mt19937ar(unsigned int d_state[625])
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
      mti = d_state[624] + 1U;
      if (mti >= 625U) {
        for (kk = 0; kk < 227; kk++) {
          y = (d_state[kk] & 2147483648U) | (d_state[1 + kk] & 2147483647U);
          if ((y & 1U) == 0U) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          d_state[kk] = d_state[kk + 397] ^ y;
        }

        for (kk = 0; kk < 396; kk++) {
          y = (d_state[kk + 227] & 2147483648U) | (d_state[228 + kk] &
            2147483647U);
          if ((y & 1U) == 0U) {
            y >>= 1U;
          } else {
            y = y >> 1U ^ 2567483615U;
          }

          d_state[kk + 227] = d_state[kk] ^ y;
        }

        y = (d_state[623] & 2147483648U) | (d_state[0] & 2147483647U);
        if ((y & 1U) == 0U) {
          y >>= 1U;
        } else {
          y = y >> 1U ^ 2567483615U;
        }

        d_state[623] = d_state[396] ^ y;
        mti = 1U;
      }

      y = d_state[(int)mti - 1];
      d_state[624] = mti;
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

/*
 *
 */
static double eml_rand_mcg16807(unsigned int *d_state)
{
  int hi;
  unsigned int a;
  unsigned int b;
  hi = (int)(*d_state / 127773U);
  a = 16807U * (*d_state - hi * 127773U);
  b = 2836U * hi;
  if (a < b) {
    *d_state = ~(b - a) & 2147483647U;
  } else {
    *d_state = a - b;
  }

  return (double)*d_state * 4.6566128752457969E-10;
}

/*
 *
 */
static void eml_rand_mt19937ar(unsigned int d_state[625])
{
  unsigned int r;
  int mti;
  r = 5489U;
  d_state[0] = 5489U;
  for (mti = 0; mti < 623; mti++) {
    r = ((r ^ r >> 30U) * 1812433253U + mti) + 1U;
    d_state[mti + 1] = r;
  }

  d_state[624] = 624U;
}

/*
 *
 */
void b_rand(double r[200])
{
  int k;
  unsigned int u0;
  unsigned int u1;
  if (method == 4U) {
    for (k = 0; k < 200; k++) {
      r[k] = eml_rand_mcg16807(&state);
    }
  } else if (method == 5U) {
    for (k = 0; k < 200; k++) {
      u0 = 69069U * b_state[0] + 1234567U;
      u1 = b_state[1] ^ b_state[1] << 13;
      u1 ^= u1 >> 17;
      u1 ^= u1 << 5;
      b_state[0] = u0;
      b_state[1] = u1;
      r[k] = (double)(u0 + u1) * 2.328306436538696E-10;
    }
  } else {
    if (!state_not_empty) {
      eml_rand_mt19937ar(c_state);
      state_not_empty = true;
    }

    for (k = 0; k < 200; k++) {
      r[k] = b_eml_rand_mt19937ar(c_state);
    }
  }
}

/*
 *
 */
void c_rand(double r[2000])
{
  int k;
  unsigned int u2;
  unsigned int u3;
  if (method == 4U) {
    for (k = 0; k < 2000; k++) {
      r[k] = eml_rand_mcg16807(&state);
    }
  } else if (method == 5U) {
    for (k = 0; k < 2000; k++) {
      u2 = 69069U * b_state[0] + 1234567U;
      u3 = b_state[1] ^ b_state[1] << 13;
      u3 ^= u3 >> 17;
      u3 ^= u3 << 5;
      b_state[0] = u2;
      b_state[1] = u3;
      r[k] = (double)(u2 + u3) * 2.328306436538696E-10;
    }
  } else {
    if (!state_not_empty) {
      eml_rand_mt19937ar(c_state);
      state_not_empty = true;
    }

    for (k = 0; k < 2000; k++) {
      r[k] = b_eml_rand_mt19937ar(c_state);
    }
  }
}

/*
 *
 */
double d_rand(void)
{
  double r;
  unsigned int u4;
  unsigned int u5;
  if (method == 4U) {
    r = eml_rand_mcg16807(&state);
  } else if (method == 5U) {
    u4 = 69069U * b_state[0] + 1234567U;
    u5 = b_state[1] ^ b_state[1] << 13;
    u5 ^= u5 >> 17;
    u5 ^= u5 << 5;
    b_state[0] = u4;
    b_state[1] = u5;
    r = (double)(u4 + u5) * 2.328306436538696E-10;
  } else {
    if (!state_not_empty) {
      eml_rand_mt19937ar(c_state);
      state_not_empty = true;
    }

    r = b_eml_rand_mt19937ar(c_state);
  }

  return r;
}

/*
 *
 */
void e_rand(double r[15][10])
{
  int k;
  unsigned int u6;
  unsigned int u7;
  if (method == 4U) {
    for (k = 0; k < 150; k++) {
      (&r[0][0])[k] = eml_rand_mcg16807(&state);
    }
  } else if (method == 5U) {
    for (k = 0; k < 150; k++) {
      u6 = 69069U * b_state[0] + 1234567U;
      u7 = b_state[1] ^ b_state[1] << 13;
      u7 ^= u7 >> 17;
      u7 ^= u7 << 5;
      b_state[0] = u6;
      b_state[1] = u7;
      (&r[0][0])[k] = (double)(u6 + u7) * 2.328306436538696E-10;
    }
  } else {
    if (!state_not_empty) {
      eml_rand_mt19937ar(c_state);
      state_not_empty = true;
    }

    for (k = 0; k < 150; k++) {
      (&r[0][0])[k] = b_eml_rand_mt19937ar(c_state);
    }
  }
}

/*
 *
 */
void f_rand(double r[15][15])
{
  int k;
  unsigned int u8;
  unsigned int u9;
  if (method == 4U) {
    for (k = 0; k < 225; k++) {
      (&r[0][0])[k] = eml_rand_mcg16807(&state);
    }
  } else if (method == 5U) {
    for (k = 0; k < 225; k++) {
      u8 = 69069U * b_state[0] + 1234567U;
      u9 = b_state[1] ^ b_state[1] << 13;
      u9 ^= u9 >> 17;
      u9 ^= u9 << 5;
      b_state[0] = u8;
      b_state[1] = u9;
      (&r[0][0])[k] = (double)(u8 + u9) * 2.328306436538696E-10;
    }
  } else {
    if (!state_not_empty) {
      eml_rand_mt19937ar(c_state);
      state_not_empty = true;
    }

    for (k = 0; k < 225; k++) {
      (&r[0][0])[k] = b_eml_rand_mt19937ar(c_state);
    }
  }
}

/*
 *
 */
void g_rand(double r[15][25])
{
  int k;
  unsigned int u10;
  unsigned int u11;
  if (method == 4U) {
    for (k = 0; k < 375; k++) {
      (&r[0][0])[k] = eml_rand_mcg16807(&state);
    }
  } else if (method == 5U) {
    for (k = 0; k < 375; k++) {
      u10 = 69069U * b_state[0] + 1234567U;
      u11 = b_state[1] ^ b_state[1] << 13;
      u11 ^= u11 >> 17;
      u11 ^= u11 << 5;
      b_state[0] = u10;
      b_state[1] = u11;
      (&r[0][0])[k] = (double)(u10 + u11) * 2.328306436538696E-10;
    }
  } else {
    if (!state_not_empty) {
      eml_rand_mt19937ar(c_state);
      state_not_empty = true;
    }

    for (k = 0; k < 375; k++) {
      (&r[0][0])[k] = b_eml_rand_mt19937ar(c_state);
    }
  }
}

/*
 *
 */
void h_rand(double r[15][30])
{
  int k;
  unsigned int u12;
  unsigned int u13;
  if (method == 4U) {
    for (k = 0; k < 450; k++) {
      (&r[0][0])[k] = eml_rand_mcg16807(&state);
    }
  } else if (method == 5U) {
    for (k = 0; k < 450; k++) {
      u12 = 69069U * b_state[0] + 1234567U;
      u13 = b_state[1] ^ b_state[1] << 13;
      u13 ^= u13 >> 17;
      u13 ^= u13 << 5;
      b_state[0] = u12;
      b_state[1] = u13;
      (&r[0][0])[k] = (double)(u12 + u13) * 2.328306436538696E-10;
    }
  } else {
    if (!state_not_empty) {
      eml_rand_mt19937ar(c_state);
      state_not_empty = true;
    }

    for (k = 0; k < 450; k++) {
      (&r[0][0])[k] = b_eml_rand_mt19937ar(c_state);
    }
  }
}

/*
 *
 */
void i_rand(int varargin_2, emxArray_real_T *r)
{
  int i30;
  int k;
  unsigned int u14;
  unsigned int u15;
  if (method == 4U) {
    i30 = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = varargin_2;
    emxEnsureCapacity_real_T(r, i30);
    i30 = r->size[1];
    for (k = 0; k < i30; k++) {
      r->data[k] = eml_rand_mcg16807(&state);
    }
  } else if (method == 5U) {
    i30 = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = varargin_2;
    emxEnsureCapacity_real_T(r, i30);
    i30 = r->size[1];
    for (k = 0; k < i30; k++) {
      u14 = 69069U * b_state[0] + 1234567U;
      u15 = b_state[1] ^ b_state[1] << 13;
      u15 ^= u15 >> 17;
      u15 ^= u15 << 5;
      b_state[0] = u14;
      b_state[1] = u15;
      r->data[k] = (double)(u14 + u15) * 2.328306436538696E-10;
    }
  } else {
    if (!state_not_empty) {
      eml_rand_mt19937ar(c_state);
      state_not_empty = true;
    }

    i30 = r->size[0] * r->size[1];
    r->size[0] = 1;
    r->size[1] = varargin_2;
    emxEnsureCapacity_real_T(r, i30);
    i30 = r->size[1];
    for (k = 0; k < i30; k++) {
      r->data[k] = b_eml_rand_mt19937ar(c_state);
    }
  }
}

/*
 *
 */
void j_rand(double r[2])
{
  unsigned int u17;
  unsigned int u18;
  if (method == 4U) {
    r[0] = eml_rand_mcg16807(&state);
    r[1] = eml_rand_mcg16807(&state);
  } else if (method == 5U) {
    u17 = 69069U * b_state[0] + 1234567U;
    u18 = b_state[1] ^ b_state[1] << 13;
    u18 ^= u18 >> 17;
    u18 ^= u18 << 5;
    b_state[0] = u17;
    b_state[1] = u18;
    r[0] = (double)(u17 + u18) * 2.328306436538696E-10;
    u17 = 69069U * b_state[0] + 1234567U;
    u18 = b_state[1] ^ b_state[1] << 13;
    u18 ^= u18 >> 17;
    u18 ^= u18 << 5;
    b_state[0] = u17;
    b_state[1] = u18;
    r[1] = (double)(u17 + u18) * 2.328306436538696E-10;
  } else {
    if (!state_not_empty) {
      eml_rand_mt19937ar(c_state);
      state_not_empty = true;
    }

    r[0] = b_eml_rand_mt19937ar(c_state);
    r[1] = b_eml_rand_mt19937ar(c_state);
  }
}

/*
 *
 */
void k_rand(int varargin_1, emxArray_real_T *r)
{
  int i33;
  int k;
  unsigned int u19;
  unsigned int u20;
  if (method == 4U) {
    i33 = r->size[0];
    r->size[0] = varargin_1;
    emxEnsureCapacity_real_T(r, i33);
    i33 = r->size[0];
    for (k = 0; k < i33; k++) {
      r->data[k] = eml_rand_mcg16807(&state);
    }
  } else if (method == 5U) {
    i33 = r->size[0];
    r->size[0] = varargin_1;
    emxEnsureCapacity_real_T(r, i33);
    i33 = r->size[0];
    for (k = 0; k < i33; k++) {
      u19 = 69069U * b_state[0] + 1234567U;
      u20 = b_state[1] ^ b_state[1] << 13;
      u20 ^= u20 >> 17;
      u20 ^= u20 << 5;
      b_state[0] = u19;
      b_state[1] = u20;
      r->data[k] = (double)(u19 + u20) * 2.328306436538696E-10;
    }
  } else {
    if (!state_not_empty) {
      eml_rand_mt19937ar(c_state);
      state_not_empty = true;
    }

    i33 = r->size[0];
    r->size[0] = varargin_1;
    emxEnsureCapacity_real_T(r, i33);
    i33 = r->size[0];
    for (k = 0; k < i33; k++) {
      r->data[k] = b_eml_rand_mt19937ar(c_state);
    }
  }
}

/* End of code generation (rand.c) */
