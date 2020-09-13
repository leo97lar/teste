/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_model_api.h
 *
 * Code generation for function '_coder_model_api'
 *
 */

#ifndef _CODER_MODEL_API_H
#define _CODER_MODEL_API_H

/* Include files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_model_api.h"

/* Type Definitions */
#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T

struct emxArray_int32_T
{
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_int32_T*/

#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T

typedef struct emxArray_int32_T emxArray_int32_T;

#endif                                 /*typedef_emxArray_int32_T*/

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void BDCreator_func(void);
extern void BDCreator_func_api(int32_T nlhs);
extern void Calendario(real_T Data[87600], real_T Dia[2920]);
extern void Calendario_api(int32_T nlhs, const mxArray *plhs[2]);
extern void Codificacion_de_dias_func(void);
extern void Codificacion_de_dias_func_api(int32_T nlhs);
extern void CreaPoQunniforme(int32_T NumTOp, int32_T ctdadIQ, emxArray_real_T
  *IQ);
extern void CreaPoQunniforme_api(const mxArray * const prhs[2], int32_T nlhs,
  const mxArray *plhs[1]);
extern void Edade(int32_T b_min, int32_T b_max, int32_T Num, emxArray_real_T
                  *b_Edade);
extern void Edade_api(const mxArray * const prhs[3], int32_T nlhs, const mxArray
                      *plhs[1]);
extern void PLOTT_func(emxArray_real_T *trace, emxArray_int32_T *bestexperimento);
extern void PLOTT_func_api(const mxArray * const prhs[2], int32_T nlhs);
extern void actIQ(emxArray_real_T *IQ, emxArray_int32_T *IC, real_T taxAct,
                  emxArray_real_T *IQact);
extern void actIQ_api(const mxArray * const prhs[3], int32_T nlhs, const mxArray
                      *plhs[1]);
extern void aevSPLap(int32_T NumTOp, int32_T numIC, int32_T numIQ, real_T taxC,
                     real_T taxE, real_T taxEQ, int32_T NumRec[7],
                     emxArray_int32_T *PCPrO, emxArray_int32_T *PME,
                     emxArray_int32_T *PMA, emxArray_int32_T *PMAn,
                     emxArray_int32_T *PS, emxArray_int32_T *PCPO,
                     emxArray_int32_T *PCR, emxArray_int32_T *Dia,
                     emxArray_int32_T *Data, emxArray_int32_T *TimeUsoRec,
                     real_T ProbXEst[5], real_T fitnessB[6], int32_T generations,
                     int32_T genToWidth, emxArray_int32_T *DispMExD,
                     emxArray_real_T *EP, real_T k0, real_T k1, real_T k2,
                     real_T k3, boolean_T keeppriority, emxArray_int32_T
                     *bestexperimento, emxArray_real_T *trace);
extern void aevSPLap_api(const mxArray * const prhs[28], int32_T nlhs, const
  mxArray *plhs[2]);
extern void casorandom(int32_T NumTOp, emxArray_int32_T *H, int32_T NumRec[7],
  emxArray_int32_T *PCPrO, emxArray_int32_T *PME, emxArray_int32_T *PMA,
  emxArray_int32_T *PMAn, emxArray_int32_T *PS, emxArray_int32_T *PCPO,
  emxArray_int32_T *PCR, emxArray_int32_T *Dia, emxArray_int32_T *UltPosRecXDia,
  emxArray_int32_T *TimeUsoRec, emxArray_int32_T *DispMExD, emxArray_int32_T
  *schedule, emxArray_int32_T *DiaOp, emxArray_int32_T *EspMedOp);
extern void casorandom_api(const mxArray *prhs[14], int32_T nlhs, const mxArray *
  plhs[3]);
extern void cc(emxArray_int32_T *IC, int32_T numIC, real_T taxC, int32_T NumTOp,
               emxArray_int32_T *newIC);
extern void cc_api(const mxArray * const prhs[4], int32_T nlhs, const mxArray
                   *plhs[1]);
extern void favalia(emxArray_int32_T *schedule, emxArray_int32_T *DiaOp,
                    emxArray_int32_T *EP, emxArray_int32_T *EspMedOp, real_T k0,
                    real_T k1, real_T k2, real_T k3, real_T *fitness, real_T *Tt,
                    real_T *NOFP, real_T *TmNOFP, real_T *NOE2, real_T *NOE3);
extern void favalia_api(const mxArray *prhs[8], int32_T nlhs, const mxArray
  *plhs[6]);
extern void funcionC(emxArray_int32_T *PCPO, emxArray_int32_T *PCR,
                     emxArray_int32_T *H, int32_T *EndRP, int32_T TimeUsoCPO,
                     int32_T TimeUsoCR, emxArray_int32_T *PME, emxArray_int32_T *
                     PMA, emxArray_int32_T *PMAn, emxArray_int32_T *PS, int32_T *
                     CPrOA, int32_T *IniCPrOA, int32_T *EndCPrOA, int32_T
                     *EndCPrOAxD, int32_T NumRec[7], emxArray_int32_T *PCPrO,
                     emxArray_int32_T *Dia, emxArray_int32_T *UltPosRecXDia,
                     int32_T TimeUsoCPrO, int32_T TimeUsoS, int32_T *contDia,
                     emxArray_int32_T *filCPrO, emxArray_int32_T
                     *tempUltPosRecXDia, emxArray_int32_T *EA, emxArray_int32_T *
                     SA, emxArray_int32_T *AA, emxArray_int32_T *AnA, int32_T
                     *IniRP, int32_T *EndRPxD, emxArray_int32_T *DispMExD,
                     emxArray_int32_T *DispME, emxArray_int32_T *uCPrODisp,
                     real_T *CPOA, int32_T *IniCPO, int32_T *EndCPO, real_T *CRA,
                     int32_T *IniCR, int32_T *EndCR);
extern void funcionCPrO(int32_T NumRec[7], emxArray_int32_T *PCPrO,
  emxArray_int32_T *PME, emxArray_int32_T *PMA, emxArray_int32_T *PMAn,
  emxArray_int32_T *PS, emxArray_int32_T *PCPO, emxArray_int32_T *PCR,
  emxArray_int32_T *H, emxArray_int32_T *Dia, emxArray_int32_T *UltPosRecXDia,
  int32_T TimeUsoCPrO, int32_T TimeUsoS, int32_T TimeUsoCPO, int32_T TimeUsoCR,
  int32_T *contDia, emxArray_int32_T *tempUltPosRecXDia, emxArray_int32_T
  *DispMExD, emxArray_int32_T *DispME, int32_T *CPrOA, int32_T *IniCPrOA,
  int32_T *EndCPrOA, int32_T *EndCPrOAxD, emxArray_int32_T *EA, emxArray_int32_T
  *AA, emxArray_int32_T *AnA, emxArray_int32_T *SA, int32_T *IniSA, int32_T
  *EndSA, int32_T *EndRPxD, int32_T *CPOA, int32_T *IniCPOA, int32_T *EndCPOA,
  int32_T *CRA, int32_T *IniCRA, int32_T *EndCRA);
extern void funcionCPrO_api(const mxArray *prhs[19], int32_T nlhs, const mxArray
  *plhs[18]);
extern void funcionCR(void);
extern void funcionCR_api(int32_T nlhs);
extern void funcionC_api(const mxArray *prhs[32], int32_T nlhs, const mxArray
  *plhs[18]);
extern void funcionDia(int32_T NumRec[7], emxArray_int32_T *PCPrO,
  emxArray_int32_T *Dia, emxArray_int32_T *UltPosRecXDia, int32_T TimeUsoCPrO,
  int32_T TimeUsoS, int32_T *contDia, emxArray_int32_T *DispMExD,
  emxArray_int32_T *tempUltPosRecXDia, emxArray_int32_T *DispME);
extern void funcionDia_api(const mxArray * const prhs[8], int32_T nlhs, const
  mxArray *plhs[3]);
extern void funcionRP(emxArray_int32_T *CPrOA, int32_T *IniCPrOA, int32_T
                      *EndCPrOA, int32_T *EndCPrOAxD, emxArray_int32_T *SA,
                      int32_T *IniSA, int32_T *EndSA, emxArray_int32_T *CPOA,
                      int32_T *IniCPOA, int32_T *EndCPOA, emxArray_int32_T *CRA,
                      int32_T *IniCRA, int32_T *EndCRA, int32_T NumRec[7],
                      emxArray_int32_T *PCPrO, emxArray_int32_T *PME,
                      emxArray_int32_T *PMA, emxArray_int32_T *PMAn,
                      emxArray_int32_T *PS, emxArray_int32_T *PCPO,
                      emxArray_int32_T *PCR, emxArray_real_T *H,
                      emxArray_int32_T *Dia, emxArray_int32_T *UltPosRecXDia,
                      int32_T TimeUsoCPrO, int32_T TimeUsoS, int32_T TimeUsoCPO,
                      int32_T TimeUsoCR, int32_T *contDia, emxArray_int32_T
                      *tempUltPosRecXDia, emxArray_int32_T *DispMExD,
                      emxArray_int32_T *DispME, emxArray_int32_T *EA,
                      emxArray_int32_T *AA, emxArray_int32_T *AnA, int32_T
                      *EndRPxD);
extern void funcionRP_api(const mxArray *prhs[32], int32_T nlhs, const mxArray
  *plhs[18]);
extern void main_UCI_func(emxArray_int32_T *CP, emxArray_int32_T *RO,
  emxArray_int32_T *CPO, emxArray_int32_T *CPrO, emxArray_int32_T *CR,
  emxArray_int32_T *Data, emxArray_int32_T *Dia, emxArray_int32_T *DispMExD,
  emxArray_int32_T *MA, emxArray_int32_T *MAn, emxArray_int32_T *ME,
  emxArray_int32_T *S, int32_T TipoOp, int32_T NumEsp, int32_T NumTOp, int32_T
  NumSalOp, int32_T NumCPO, int32_T NumCPrO, int32_T NumCR, int32_T NumMedEsp,
  int32_T NumEspxE, int32_T NumAsist, int32_T NumAnest, real_T k0, real_T k1,
  real_T k2, real_T k3, int32_T numIQ, int32_T numIC, real_T taxC, real_T taxE,
  real_T taxEQ, emxArray_real_T *ProbXEst, int32_T genToWidth, int32_T
  generations, boolean_T keeppriority);
extern void main_UCI_func_api(const mxArray * const prhs[36], int32_T nlhs);
extern void model_atexit(void);
extern void model_initialize(void);
extern void model_terminate(void);
extern void model_xil_shutdown(void);
extern void model_xil_terminate(void);
extern void obsIQ(emxArray_real_T *IQ, int32_T numIQ, int32_T numObsIQ,
                  emxArray_int32_T *newIC);
extern void obsIQ_api(const mxArray * const prhs[3], int32_T nlhs, const mxArray
                      *plhs[1]);
extern void obsIQini(emxArray_real_T *IQ, int32_T numIQ, int32_T numObsIQ,
                     real_T ProbXEst[5], emxArray_int32_T *newIC);
extern void obsIQini_api(const mxArray * const prhs[4], int32_T nlhs, const
  mxArray *plhs[1]);
extern void sch(int32_T NumTOp, emxArray_int32_T *list, int32_T NumRec[7],
                emxArray_int32_T *PCPrO, emxArray_int32_T *PME, emxArray_int32_T
                *PMA, emxArray_int32_T *PMAn, emxArray_int32_T *PS,
                emxArray_int32_T *PCPO, emxArray_int32_T *PCR, emxArray_int32_T *
                Dia, emxArray_int32_T *Data, emxArray_int32_T *TimeUsoRec,
                emxArray_int32_T *DispMExD, emxArray_int32_T *EP, real_T k0,
                real_T k1, real_T k2, real_T k3, real_T *fitness, real_T *Tt,
                real_T *NOFP, real_T *TmNOFP, real_T *NOE2, real_T *NOE3);
extern void sch_api(const mxArray *prhs[19], int32_T nlhs, const mxArray *plhs[6]);

#endif

/* End of code generation (_coder_model_api.h) */
