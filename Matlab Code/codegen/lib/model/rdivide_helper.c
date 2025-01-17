/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: rdivide_helper.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 19:00:28
 */

/* Include Files */
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "rdivide_helper.h"
#include "model_emxutil.h"

/* Function Definitions */

/*
 * Arguments    : const emxArray_real_T *y
 *                emxArray_real_T *z
 * Return Type  : void
 */
void b_rdivide_helper(const emxArray_real_T *y, emxArray_real_T *z)
{
  int i24;
  int loop_ub;
  i24 = z->size[0];
  z->size[0] = y->size[0];
  emxEnsureCapacity_real_T(z, i24);
  loop_ub = y->size[0];
  for (i24 = 0; i24 < loop_ub; i24++) {
    z->data[i24] = 1.0 / y->data[i24];
  }
}

/*
 * Arguments    : int x
 *                int y
 * Return Type  : int
 */
int rdivide_helper(int x, int y)
{
  int z;
  unsigned int b_x;
  unsigned int b_y;
  unsigned int q;
  if (y == 0) {
    if (x == 0) {
      z = 0;
    } else if (x < 0) {
      z = MIN_int32_T;
    } else {
      z = MAX_int32_T;
    }
  } else if (y == 1) {
    z = x;
  } else if (y == -1) {
    z = -x;
  } else {
    if (x >= 0) {
      b_x = (unsigned int)x;
    } else if (x == MIN_int32_T) {
      b_x = 2147483648U;
    } else {
      b_x = (unsigned int)-x;
    }

    if (y >= 0) {
      b_y = (unsigned int)y;
    } else if (y == MIN_int32_T) {
      b_y = 2147483648U;
    } else {
      b_y = (unsigned int)-y;
    }

    q = b_x / b_y;
    b_x -= q * b_y;
    if ((b_x > 0U) && (b_x >= (b_y >> 1U) + (b_y & 1U))) {
      q++;
    }

    z = (int)q;
    if ((x < 0) != (y < 0)) {
      z = -(int)q;
    }
  }

  return z;
}

/*
 * File trailer for rdivide_helper.c
 *
 * [EOF]
 */
