/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: BDCreator_func.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 13-Sep-2020 18:10:16
 */

/* Include Files */
#include <math.h>
#include <string.h>
#include "BDCreator_func.h"
#include "main_UCI_func.h"
#include "randi.h"
#include "toc.h"
#include "rand.h"
#include "sort1.h"
#include "randperm.h"
#include "model_emxutil.h"
#include "sum.h"
#include "Edade.h"
#include "tic.h"

/* Function Definitions */

/*
 * function BDCreator_func
 * %% Generar Base de Datos
 *  Vamos a tener 15 especialidades con diferentes operaciones quirurgicas
 *  (200 en total) que requieren diferentes tipos de especialistas y
 *  recursos. Algunas mas complejas que otras. 25 cirujanos especializados en
 *  una especialidad y con conocimientos suficientes para realizar cirujias
 *  de otra especialidad. 25 anestesistas y 25 asistentes.
 * Arguments    : void
 * Return Type  : void
 */
void BDCreator_func(void)
{
  double filled;
  emxArray_int16_T *r0;
  int i;
  double unusedExpr[200];
  double ops;
  static const signed char POPE[15] = { 10, 5, 12, 5, 15, 10, 8, 5, 5, 2, 3, 10,
    5, 3, 2 };

  int i0;
  int k;
  double b_unusedExpr[200];
  static const signed char PCO[3] = { 30, 50, 20 };

  double c_unusedExpr[200];
  static const signed char PTO[5] = { 15, 20, 25, 25, 15 };

  double d_unusedExpr[2000];
  double e_unusedExpr[2000];
  double f_unusedExpr[2000];
  static const signed char PPE[5] = { 10, 25, 30, 25, 10 };

  double aux;
  double auxCExD[2000];
  int count;
  int exitg1;
  double y;
  emxArray_real_T *CExD;
  double Exc;
  short DE[2000];
  int i1;
  double idx[2000];
  short b_DE[2000];
  double x[2000];
  int g_unusedExpr[2000];
  double h_unusedExpr[15][10];
  double i_unusedExpr[15][15];
  double j_unusedExpr[15][10];
  double k_unusedExpr[15][25];
  double l_unusedExpr[15][30];
  double m_unusedExpr[15][10];

  /* 'BDCreator_func:9' tic; */
  tic();

  /*     %% Variables de Entrada */
  /* 'BDCreator_func:12' TipoOp = 200; */
  /*  Tipos de operaciones */
  /* 'BDCreator_func:13' NumEsp = 15; */
  /*  Numero de Especialidades */
  /* 'BDCreator_func:14' MedNecXOp = ones(TipoOp,1)*2; */
  /*  Medicos necesarios por Operacion */
  /* 'BDCreator_func:15' AsistNecXOp = ones(TipoOp,1)*2; */
  /*  Asistentes necesarios por Operacion */
  /* 'BDCreator_func:16' AnestNecXOp = ones(TipoOp,1)*2; */
  /*  Anestesistas necesarios por Operacion */
  /* 'BDCreator_func:18' NumTOp = 2000; */
  /*  Numero Total de Operaciones */
  /*  Recursos materiales */
  /* 'BDCreator_func:21' NumSalOp = 10; */
  /*  Numero de Salones de operaciones */
  /* 'BDCreator_func:22' NumCPO = 15; */
  /*  Numero de camas Post-Operatorias */
  /* 'BDCreator_func:23' NumCPrO = 10; */
  /*  Numero de camas Pre-Operatorias */
  /* 'BDCreator_func:24' NumCR = 25; */
  /*  Numero de camas Recuperacion */
  /*  Recursos Humanos */
  /* 'BDCreator_func:27' NumEspxE = 2; */
  /*  Numero de Especialistas por Especialidad */
  /* 'BDCreator_func:28' NumAsist = 10; */
  /*  Numero de Asistentes */
  /* 'BDCreator_func:29' NumAnest = 10; */
  /*  Numero de Anestesistas */
  /*     %% Tabla de Operaciones por Especialidad */
  /*  E  1  2  3  4  5  6  7  8  9  10  11  12  13  14 15 */
  /*  % 10  5 12  5 15 10  8  5  5   2   3  10   5   3  2 */
  /* 'BDCreator_func:36' POPE = [10;5;12;5;15;10;8;5;5;2;3;10;5;3;2]; */
  /*  Vector con el porciento de tipos operaciones por especialidad */
  /* 'BDCreator_func:37' OpXEsp = zeros(TipoOp, 1); */
  /*  Operaciones por especialidad */
  /* 'BDCreator_func:39' filled=0; */
  filled = 0.0;

  /* 'BDCreator_func:40' for i=1:length(POPE) */
  emxInit_int16_T(&r0, 2);
  for (i = 0; i < 15; i++) {
    /* 'BDCreator_func:41' ops = POPE(i)*TipoOp/100; */
    ops = (double)POPE[i] * 200.0 / 100.0;

    /* 'BDCreator_func:42' OpXEsp(filled+1 : filled+ops) = i; */
    i0 = r0->size[0] * r0->size[1];
    r0->size[0] = 1;
    k = (int)floor(ops - 1.0);
    r0->size[1] = k + 1;
    emxEnsureCapacity_int16_T(r0, i0);
    for (i0 = 0; i0 <= k; i0++) {
      r0->data[i0] = (short)(filled + (1.0 + (double)i0));
    }

    /* 'BDCreator_func:43' filled = filled + ops; */
    filled += ops;
  }

  /* 'BDCreator_func:46' ind=randperm(TipoOp); */
  randperm(unusedExpr);

  /* 'BDCreator_func:47' OpXEsp = OpXEsp(ind); */
  /*     %% Complejidad de la operacion */
  /*  1___Alta (30%) */
  /*  2___Media (50%) */
  /*  3___Baja (20%) */
  /* 'BDCreator_func:55' PCO = [30;50;20]; */
  /*  Vector con el porciento de operaciones por su complejidad */
  /* 'BDCreator_func:56' CompOp = zeros(TipoOp, 1); */
  /*  Complejidad de la operacion */
  /* 'BDCreator_func:58' filled=0; */
  filled = 0.0;

  /* 'BDCreator_func:59' for i=1:length(PCO) */
  for (i = 0; i < 3; i++) {
    /* 'BDCreator_func:61' ops = PCO(i)*TipoOp/100; */
    ops = (double)PCO[i] * 200.0 / 100.0;

    /* 'BDCreator_func:62' CompOp(filled+1 : filled+ops) = i; */
    i0 = r0->size[0] * r0->size[1];
    r0->size[0] = 1;
    k = (int)floor(ops - 1.0);
    r0->size[1] = k + 1;
    emxEnsureCapacity_int16_T(r0, i0);
    for (i0 = 0; i0 <= k; i0++) {
      r0->data[i0] = (short)(filled + (1.0 + (double)i0));
    }

    /* 'BDCreator_func:63' filled = filled + ops; */
    filled += ops;
  }

  /* 'BDCreator_func:67' ind=randperm(TipoOp); */
  randperm(b_unusedExpr);

  /* 'BDCreator_func:68' CompOp = CompOp(ind); */
  /*     %% Tiempo de Duracion de la operacion */
  /*  1 0,5h (15%) */
  /*  2 1,0h (20%) */
  /*  3 1,5h (25%) */
  /*  4 2,0h (25%) */
  /*  5 2,5h (15%) */
  /* 'BDCreator_func:77' Hr = [1,2,3,4,5]; */
  /* 'BDCreator_func:78' PTO = [15;20;25;25;15]; */
  /*  Vector con el porciento de operaciones por horas de duracion */
  /* 'BDCreator_func:79' TimeOp = zeros(TipoOp, 1); */
  /*  Tiempo de operacion */
  /* 'BDCreator_func:81' filled=0; */
  filled = 0.0;

  /* 'BDCreator_func:82' for i=1:length(PTO) */
  for (i = 0; i < 5; i++) {
    /* 'BDCreator_func:84' ops = PTO(i)*TipoOp/100; */
    ops = (double)PTO[i] * 200.0 / 100.0;

    /* 'BDCreator_func:85' TimeOp(filled+1 : filled+ops) = Hr(i); */
    i0 = r0->size[0] * r0->size[1];
    r0->size[0] = 1;
    k = (int)floor(ops - 1.0);
    r0->size[1] = k + 1;
    emxEnsureCapacity_int16_T(r0, i0);
    for (i0 = 0; i0 <= k; i0++) {
      r0->data[i0] = (short)(filled + (1.0 + (double)i0));
    }

    /* 'BDCreator_func:86' filled = filled + ops; */
    filled += ops;
  }

  /* 'BDCreator_func:89' ind=randperm(TipoOp); */
  randperm(c_unusedExpr);

  /* 'BDCreator_func:90' TimeOp = TimeOp(ind); */
  /*     %% Recursos necesarios */
  /*  Especialistas */
  /*  Asistentes */
  /*  Anestesistas */
  /* 'BDCreator_func:97' for i =1:TipoOp */
  /*     %% Tabla de Operaciones quirurgicas con sus caracteristicas (Tabla1) */
  /*  Num Operación, Especialidad, Complejidad, Tiempo, Ctd Medicos, Ctd Ayudantes, Ctdad Anestesistas. */
  /* 'BDCreator_func:134' RO = [linspace(1,TipoOp,TipoOp)',OpXEsp,CompOp,TimeOp,MedNecXOp,AsistNecXOp,AnestNecXOp]; */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*     %% Caracteristicas de los pacientes por Operacion */
  /* 'BDCreator_func:140' TOPP = randi([1 TipoOp],1,NumTOp)'; */
  randi(d_unusedExpr);

  /*  Tipo de operacion por paciente */
  /* 'BDCreator_func:141' EPP = Edade( 5,75,NumTOp); */
  Edade(e_unusedExpr);

  /*  Edad por paciente */
  /*  Estado del paciente */
  /*  A 48  Si evidentemente el retraso afectara el progreso de la enfermedad */
  /*  B 12  Si posiblemente el retraso afectara el progreso de la enfermedad */
  /*  C  4  Si el retraso NO afectara el progreso de la enfermedad pero hay dolor severo  */
  /*  D  2  Si el retraso NO afectara el progreso de la enfermedad pero hay dolor medio */
  /*  E  1  Si el retraso NO afectara el progreso de la enfermedad ni hay dolor */
  /* 'BDCreator_func:151' PE = [360,180,90,30,6]; */
  /*  Posibles estados. */
  /* 'BDCreator_func:152' PPE = [10;25;30;25;10]; */
  /*  Porciento por estado del paciente */
  /* 'BDCreator_func:153' EP = zeros(TipoOp, 1); */
  /* 'BDCreator_func:155' filled=0; */
  filled = 0.0;

  /* 'BDCreator_func:156' for i=1:length(PE) */
  for (i = 0; i < 5; i++) {
    /* 'BDCreator_func:158' ops = PPE(i)*TipoOp/100; */
    ops = (double)PPE[i] * 200.0 / 100.0;

    /* 'BDCreator_func:159' EP(filled+1 : filled+ops) = PE(i); */
    i0 = r0->size[0] * r0->size[1];
    r0->size[0] = 1;
    k = (int)floor(ops - 1.0);
    r0->size[1] = k + 1;
    emxEnsureCapacity_int16_T(r0, i0);
    for (i0 = 0; i0 <= k; i0++) {
      r0->data[i0] = (short)(filled + (1.0 + (double)i0));
    }

    /* 'BDCreator_func:160' filled = filled + ops; */
    filled += ops;
  }

  /* 'BDCreator_func:164' ind=randperm(NumTOp); */
  b_randperm(f_unusedExpr);

  /* 'BDCreator_func:165' EP = EP(ind); */
  /*  Tiempos de uso de salas */
  /* 'BDCreator_func:169' TPreO = ones(NumTOp,1)*2; */
  /*  Tiempo de Preoperatorio. Caso promedio dos horas. */
  /* 'BDCreator_func:171' for i=1:NumTOp */
  /* 'BDCreator_func:193' TPOstO = ones(NumTOp,1)*8; */
  /*  Tiempo de Post-Operaorio. Caso promedio 8 horas. */
  /* 'BDCreator_func:194' TR = ones(NumTOp,1)*24; */
  /*  Tiempo de Recuperacion. Caso promedio 24 horas. */
  /* 'BDCreator_func:197' for i=1:NumTOp */
  /*  Datas de entrada */
  /* 'BDCreator_func:225' MaxEPD = 30; */
  /*  Maximo numero de entradas por dia */
  /* 'BDCreator_func:226' INI = MaxEPD; */
  /*  Cantidad de entradas en el 1er dia */
  /* 'BDCreator_func:228' aux = randi([1 MaxEPD]); */
  aux = b_randi();

  /* 'BDCreator_func:230' auxCExD = zeros(NumTOp,1); */
  memset(&auxCExD[0], 0, 2000U * sizeof(double));

  /* 'BDCreator_func:231' auxCExD(1:2) = [INI;aux]; */
  auxCExD[0] = 30.0;
  auxCExD[1] = aux;

  /*  Cantidad de entradas por dia */
  /* 'BDCreator_func:232' flag=1; */
  /* 'BDCreator_func:233' count = 2; */
  count = 1;

  /* 'BDCreator_func:235' while(flag==1) */
  do {
    exitg1 = 0;

    /* 'BDCreator_func:236' if(sum(auxCExD) < NumTOp) */
    y = auxCExD[0];
    for (k = 0; k < 1999; k++) {
      y += auxCExD[k + 1];
    }

    if (y < 2000.0) {
      /* 'BDCreator_func:237' count = count + 1; */
      count++;

      /* 'BDCreator_func:238' auxCExD(count) = randi([1 MaxEPD]); */
      auxCExD[count] = b_randi();
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  /* 'BDCreator_func:239' else */
  /* 'BDCreator_func:240' flag=0; */
  emxInit_real_T(&CExD, 1);

  /* 'BDCreator_func:243' CExD = auxCExD(1:count); */
  i0 = CExD->size[0];
  CExD->size[0] = count + 1;
  emxEnsureCapacity_real_T(CExD, i0);
  for (i0 = 0; i0 <= count; i0++) {
    CExD->data[i0] = auxCExD[i0];
  }

  /* 'BDCreator_func:246' Exc = sum(CExD)-NumTOp; */
  Exc = b_sum(CExD) - 2000.0;

  /*  Operaciones excedentes */
  /* 'BDCreator_func:248' CExD(1)= CExD(1)-Exc; */
  CExD->data[0] = auxCExD[0] - Exc;

  /* 'BDCreator_func:249' ND = size(CExD,1); */
  /*  Numero de dias de entrada */
  /* 'BDCreator_func:250' DE = zeros(NumTOp, 1); */
  memset(&DE[0], 0, 2000U * sizeof(short));

  /*  Data de entrada */
  /* 'BDCreator_func:252' filled = 0; */
  filled = 0.0;

  /* 'BDCreator_func:253' for i=1:ND */
  i0 = CExD->size[0];
  for (i = 0; i < i0; i++) {
    /* 'BDCreator_func:255' ops = CExD(i); */
    /* 'BDCreator_func:256' DE(filled+1 : filled+ops) = i; */
    i1 = r0->size[0] * r0->size[1];
    r0->size[0] = 1;
    r0->size[1] = (int)floor(CExD->data[i] - 1.0) + 1;
    emxEnsureCapacity_int16_T(r0, i1);
    k = (int)floor(CExD->data[i] - 1.0);
    for (i1 = 0; i1 <= k; i1++) {
      r0->data[i1] = (short)(filled + (1.0 + (double)i1));
    }

    k = r0->size[1];
    for (i1 = 0; i1 < k; i1++) {
      DE[r0->data[i1] - 1] = (short)(1 + i);
    }

    /* 'BDCreator_func:257' filled = filled + ops; */
    filled += CExD->data[i];
  }

  emxFree_int16_T(&r0);
  emxFree_real_T(&CExD);

  /* 'BDCreator_func:261' idx=randperm(size(DE,1)); */
  b_randperm(idx);

  /* 'BDCreator_func:263' DE=DE(idx); */
  for (i0 = 0; i0 < 2000; i0++) {
    b_DE[i0] = DE[(int)idx[i0] - 1];
  }

  /*     %% Tabla con las caracteristicas de los pacientes por Operacion (Tabla2) */
  /*  Fecha de Entrada, Estado del Paciente, Tipo de Operacion, Edad, Tiempo preOperatorio, Tiempo PostOperatorio, Tiempo Recuperacion. */
  /* 'BDCreator_func:269' aux = [DE,EP,TOPP,EPP,TPreO,TPOstO,TR]; */
  /* 'BDCreator_func:271' [~,idx] = sort(aux(:,1),'ascend'); */
  for (i0 = 0; i0 < 2000; i0++) {
    x[i0] = b_DE[i0];
  }

  sort(x, g_unusedExpr);

  /* 'BDCreator_func:271' ~ */
  /* 'BDCreator_func:273' CP = [(1:1:size(aux,1))' aux(idx,:)]; */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*     %% Recursos Disponibles */
  /*  Materiales */
  /* 'BDCreator_func:280' S = double(rand(NumSalOp,NumEsp) < 0.8); */
  e_rand(h_unusedExpr);

  /*  Salas X Especialidad. "1" Habilitado para especialidad. */
  /* 'BDCreator_func:281' CPO = double(rand(NumCPO,NumEsp) < 0.9); */
  f_rand(i_unusedExpr);

  /*  Cama Post-Operacion X Especialidad. "1" Habilitado para especialidad. */
  /* 'BDCreator_func:282' CPrO = double(rand(NumCPrO,NumEsp) < 0.9); */
  e_rand(j_unusedExpr);

  /*  Cama Pre-Operacion X Especialidad. "1" Habilitado para especialidad. */
  /* 'BDCreator_func:283' CR = double(rand(NumCR,NumEsp) < 0.95); */
  g_rand(k_unusedExpr);

  /*  Cama Recuperacion X Especialidad. "1" Habilitado para especialidad. */
  /*  Humano */
  /* 'BDCreator_func:287' aux = rand(NumEsp*NumEspxE,NumEsp); */
  h_rand(l_unusedExpr);

  /* 'BDCreator_func:289' ME = (aux>0.6)*2; */
  /* 'BDCreator_func:291' aux1 = aux>0.85; */
  /* 'BDCreator_func:293' ME = ME + aux1; */
  /* 'BDCreator_func:295' for i=1:NumEsp */
  /* 'BDCreator_func:302' DispMExD = zeros(6,NumEsp*NumEspxE); */
  /*  Disponibiidad de medico especialista por dia de a semana. No todos los medicos */
  /* trabajan todos los dias. */
  /* 'BDCreator_func:304' DiaxEsp=[1;2;7;3;7;7;4;5;1;6;2;3;4;5;6]; */
  /* 'BDCreator_func:306' for i=1:NumEsp */
  /* 'BDCreator_func:331' aux = rand(NumAsist,NumEsp); */
  e_rand(m_unusedExpr);

  /* 'BDCreator_func:333' MA = (aux<0.2)*2+(aux<0.05); */
  /* 'BDCreator_func:334' MA(MA==0)=1; */
  /* 'BDCreator_func:336' if NumAsist~=NumAnest */
  /* 'BDCreator_func:342' MAn = (aux>0.9)*2+(aux>0.95); */
  /* 'BDCreator_func:343' MAn(MAn==0)=1; */
  /* 'BDCreator_func:345' [ Data, Dia ] = Calendario(); */
  /* save('RRR.mat','CP','RO','CPrO','S','CPO','CR','ME','MA','MAn','Data','Dia','DispMExD') */
  /* 'BDCreator_func:350' toc; */
  toc();
}

/*
 * File trailer for BDCreator_func.c
 *
 * [EOF]
 */
