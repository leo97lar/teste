#pragma once
#include "model_types.h"

#ifdef MODEL_EXPORTS
#define MODEL_API __declspec(dllexport)
#else
#define MODEL_API __declspec(dllimport)
#endif

extern "C" MODEL_API int main(void);

extern "C" MODEL_API void main_UCI_func(const emxArray_int32_T * CP, const emxArray_int32_T * RO, const
    emxArray_int32_T * CPO, const emxArray_int32_T * CPrO, const
    emxArray_int32_T * CR, const emxArray_int32_T * Data, const
    emxArray_int32_T * Dia, const emxArray_int32_T * DispMExD,
    const emxArray_int32_T * MA, const emxArray_int32_T * MAn,
    const emxArray_int32_T * ME, const emxArray_int32_T * S, int
    TipoOp, int NumEsp, int NumTOp, int NumSalOp, int NumCPO, int
    NumCPrO, int NumCR, int NumMedEsp, int NumEspxE, int NumAsist,
    int NumAnest, double k0, double k1, double k2, double k3, int
    numIQ, int numIC, double taxC, double taxE, double taxEQ,
    const emxArray_real_T * ProbXEst, int genToWidth, int
    generations, boolean_T keeppriority);

