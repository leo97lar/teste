/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * BDCreator_func.c
 *
 * Code generation for function 'BDCreator_func'
 *
 */

/* Include files */
#include <math.h>
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
#include "rand.h"
#include "toc.h"
#include "sort1.h"
#include "randperm.h"
#include "sum.h"
#include "randi.h"
#include "tic.h"

/* Function Definitions */
void BDCreator_func(void)
{
  double unusedExpr[200];
  double b_unusedExpr[200];
  double c_unusedExpr[200];
  double d_unusedExpr[2000];
  double e_unusedExpr[2000];
  double f_unusedExpr[2000];
  double aux;
  double auxCExD[2000];
  int count;
  double CExD_data[2000];
  int auxCExD_size[1];
  double auxCExD_data[2000];
  short DE[2000];
  int i;
  int loop_ub_tmp;
  int i21;
  short tmp_data[2030];
  short b_DE[2000];
  int g_unusedExpr[2000];
  double h_unusedExpr[150];
  double i_unusedExpr[225];
  double j_unusedExpr[150];
  double k_unusedExpr[375];
  double l_unusedExpr[450];
  double m_unusedExpr[150];
  static double Data[87600];
  double Dia[2920];

  /*     %% Generar Base de Datos */
  /*  Vamos a tener 15 especialidades con diferentes operaciones quirurgicas */
  /*  (200 en total) que requieren diferentes tipos de especialistas y */
  /*  recursos. Algunas mas complejas que otras. 25 cirujanos especializados en */
  /*  una especialidad y con conocimientos suficientes para realizar cirujias */
  /*  de otra especialidad. 25 anestesistas y 25 asistentes. */
  tic();

  /*     %% Variables de Entrada */
  /*  Tipos de operaciones */
  /*  Numero de Especialidades */
  /*  Medicos necesarios por Operacion */
  /*  Asistentes necesarios por Operacion */
  /*  Anestesistas necesarios por Operacion */
  /*  Numero Total de Operaciones */
  /*  Recursos materiales */
  /*  Numero de Salones de operaciones */
  /*  Numero de camas Post-Operatorias */
  /*  Numero de camas Pre-Operatorias */
  /*  Numero de camas Recuperacion */
  /*  Recursos Humanos */
  /*  Numero de Especialistas por Especialidad */
  /*  Numero de Asistentes */
  /*  Numero de Anestesistas */
  /*     %% Tabla de Operaciones por Especialidad */
  /*  E  1  2  3  4  5  6  7  8  9  10  11  12  13  14 15 */
  /*  % 10  5 12  5 15 10  8  5  5   2   3  10   5   3  2 */
  /*  Vector con el porciento de tipos operaciones por especialidad */
  /*  Operaciones por especialidad */
  randperm(unusedExpr);

  /*     %% Complejidad de la operacion */
  /*  1___Alta (30%) */
  /*  2___Media (50%) */
  /*  3___Baja (20%) */
  /*  Vector con el porciento de operaciones por su complejidad */
  /*  Complejidad de la operacion */
  randperm(b_unusedExpr);

  /*     %% Tiempo de Duracion de la operacion */
  /*  1 0,5h (15%) */
  /*  2 1,0h (20%) */
  /*  3 1,5h (25%) */
  /*  4 2,0h (25%) */
  /*  5 2,5h (15%) */
  /*  Vector con el porciento de operaciones por horas de duracion */
  /*  Tiempo de operacion */
  randperm(c_unusedExpr);

  /*     %% Recursos necesarios */
  /*  Especialistas */
  /*  Asistentes */
  /*  Anestesistas */
  /*     %% Tabla de Operaciones quirurgicas con sus caracteristicas (Tabla1) */
  /*  Num Operación, Especialidad, Complejidad, Tiempo, Ctd Medicos, Ctd Ayudantes, Ctdad Anestesistas. */
  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*     %% Caracteristicas de los pacientes por Operacion */
  randi(d_unusedExpr);

  /*  Tipo de operacion por paciente */
  b_Edade(e_unusedExpr);

  /*  Edad por paciente */
  /*  Estado del paciente */
  /*  A 48  Si evidentemente el retraso afectara el progreso de la enfermedad */
  /*  B 12  Si posiblemente el retraso afectara el progreso de la enfermedad */
  /*  C  4  Si el retraso NO afectara el progreso de la enfermedad pero hay dolor severo  */
  /*  D  2  Si el retraso NO afectara el progreso de la enfermedad pero hay dolor medio */
  /*  E  1  Si el retraso NO afectara el progreso de la enfermedad ni hay dolor */
  /*  Posibles estados. */
  /*  Porciento por estado del paciente */
  b_randperm(f_unusedExpr);

  /*  Tiempos de uso de salas */
  /*  Tiempo de Preoperatorio. Caso promedio dos horas. */
  /*  Tiempo de Post-Operaorio. Caso promedio 8 horas. */
  /*  Tiempo de Recuperacion. Caso promedio 24 horas. */
  /*  Datas de entrada */
  /*  Maximo numero de entradas por dia */
  /*  Cantidad de entradas en el 1er dia */
  aux = b_rand();
  memset(&auxCExD[0], 0, 2000U * sizeof(double));
  auxCExD[0] = 30.0;
  auxCExD[1] = 1.0 + floor(aux * 30.0);

  /*  Cantidad de entradas por dia */
  count = 1;
  while (l_sum(auxCExD) < 2000.0) {
    count++;
    aux = b_rand();
    auxCExD[count] = 1.0 + floor(aux * 30.0);
  }

  if (0 <= count) {
    memcpy(&CExD_data[0], &auxCExD[0], (unsigned int)((count + 1) * (int)sizeof
            (double)));
  }

  auxCExD_size[0] = count + 1;
  if (0 <= count) {
    memcpy(&auxCExD_data[0], &auxCExD[0], (unsigned int)((count + 1) * (int)
            sizeof(double)));
  }

  /*  Operaciones excedentes */
  CExD_data[0] = auxCExD[0] - (m_sum(auxCExD_data, auxCExD_size) - 2000.0);

  /*  Numero de dias de entrada */
  memset(&DE[0], 0, 2000U * sizeof(short));

  /*  Data de entrada */
  aux = 0.0;
  for (i = 0; i <= count; i++) {
    loop_ub_tmp = (int)floor(CExD_data[i] - 1.0);
    for (i21 = 0; i21 <= loop_ub_tmp; i21++) {
      tmp_data[i21] = (short)(int)(aux + (1.0 + (double)i21));
    }

    loop_ub_tmp++;
    for (i21 = 0; i21 < loop_ub_tmp; i21++) {
      DE[tmp_data[i21] - 1] = (short)(1 + i);
    }

    aux += CExD_data[i];
  }

  b_randperm(CExD_data);
  for (i21 = 0; i21 < 2000; i21++) {
    auxCExD[i21] = CExD_data[i21];
    b_DE[i21] = DE[(int)auxCExD[i21] - 1];
  }

  /*     %% Tabla con las caracteristicas de los pacientes por Operacion (Tabla2) */
  /*  Fecha de Entrada, Estado del Paciente, Tipo de Operacion, Edad, Tiempo preOperatorio, Tiempo PostOperatorio, Tiempo Recuperacion. */
  for (i21 = 0; i21 < 2000; i21++) {
    auxCExD[i21] = b_DE[i21];
  }

  c_sort(auxCExD, g_unusedExpr);

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*     %% Recursos Disponibles */
  /*  Materiales */
  h_rand(h_unusedExpr);

  /*  Salas X Especialidad. "1" Habilitado para especialidad. */
  i_rand(i_unusedExpr);

  /*  Cama Post-Operacion X Especialidad. "1" Habilitado para especialidad. */
  h_rand(j_unusedExpr);

  /*  Cama Pre-Operacion X Especialidad. "1" Habilitado para especialidad. */
  j_rand(k_unusedExpr);

  /*  Cama Recuperacion X Especialidad. "1" Habilitado para especialidad. */
  /*  Humano */
  k_rand(l_unusedExpr);

  /*  Disponibiidad de medico especialista por dia de a semana. No todos los medicos */
  /* trabajan todos los dias. */
  h_rand(m_unusedExpr);
  Calendario(Data, Dia);

  /* save('RRR.mat','CP','RO','CPrO','S','CPO','CR','ME','MA','MAn','Data','Dia','DispMExD') */
  toc();
}

/* End of code generation (BDCreator_func.c) */
