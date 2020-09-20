#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#define MAX_LINE_CSV 1000


#include <stdio.h>
#include "main_UCI_func.h"
#include "model_terminate.h"
#include "model_initialize.h"
#include "model_emxAPI.h"


emxArray_int32_T* read_csv(char filename[])
{
	int i, j, lin = 2, col = 1, count = 1, aux_int;
	char aux_char = 0, aux_str[MAX_LINE_CSV];
	emxArray_int32_T* mat;
	FILE* f = fopen(filename, "r");


	for (i = 0; aux_char != '\n'; i++)
	{
		fscanf(f, "%c", &aux_char);
		col += (aux_char == ',');
	}

	for (lin = 1; fgets(aux_str, MAX_LINE_CSV, f) != NULL; lin++);

	rewind(f);
	mat = emxCreate_int32_T(lin, col);
	for (i = 0; i < lin * col; i++)
		count = fscanf(f, "%d%*c", &mat->data[i]);

	return mat;
}

int main(void)
{
	emxArray_int32_T* CP, * RO, * CPO, * CPrO, * CR, * Data, * Dia, * DispMExD, * MA, * MAn, * ME, * S;
	emxArray_real_T* ProbXEst;
	boolean_T keeppriority;
	int TipoOp, NumEsp, NumTOp, NumSalOp, NumCPO, NumCPrO, NumCR, NumMedEsp, NumEspxE, NumAsist, NumAnest, numIQ, numIC, genToWidth, generations;
	double k0, k1, k2, k3, taxC, taxE, taxEQ;

	/* Initialize the application.
	   You do not need to do this more than one time. */
	model_initialize();

	CP = read_csv("CP.csv");
	RO = read_csv("RO.csv");
	CPO = read_csv("CPO.csv");
	CPrO = read_csv("CPrO.csv");
	CR = read_csv("CR.csv");
	Data = read_csv("Data.csv");
	Dia = read_csv("Dia.csv");
	DispMExD = read_csv("DispMExD.csv");
	MA = read_csv("MA.csv");
	MAn = read_csv("MAn.csv");
	ME = read_csv("ME.csv");
	S = read_csv("S.csv");

	// Variables de Interes

	TipoOp = RO->size[0];// Tipos de operaciones
	NumEsp = ME->size[1];// Numero de Especialidades
	NumTOp = CP->size[0];// Numero Total de Operaciones

	// Recursos materiales
	NumSalOp = S->size[0];// Numero de Salones de operaciones
	NumCPO = CPO->size[0];// Numero de camas Post - Operatorias
	NumCPrO = CPrO->size[0];// Numero de camas Pre - Operatorias
	NumCR = CR->size[0];// Numero de camas Recuperacion

	NumMedEsp = ME->size[0];// Numero de Medicos Especialistas
	NumEspxE = NumMedEsp / NumEsp;// Numero de Especialistas por Especialidad
	NumAsist = MA->size[0];// Numero de Medico Asistentes
	NumAnest = MAn->size[0];// Numero de Anestesistas

	//// Variables del model
	k0 = 0;
	k1 = 0;
	k2 = 0;
	k3 = 0;

	numIQ = 5;// Numero de individuos cuanticos.
	numIC = 20;// Numero de individuos clasicos.
	taxC = 0.9;// Tasa de cruzamiento
	taxE = 50;// Tasa de elitismo[%]
	taxEQ = 10;

	ProbXEst = emxCreate_real_T(5, 1);
	ProbXEst->data[0] = 10.0; ProbXEst->data[1] = 20.0; ProbXEst->data[2] = 40.0; ProbXEst->data[3] = 20.0; ProbXEst->data[4] = 10.0;
	genToWidth = 5;// N�mero de gera��es de espera antes de reduzir a largura dos indiv�duos qu�nticos
	generations = 2;// N�mero de gera��es

	keeppriority = false;

	/* Call the entry-point 'main_UCI_func'. */
	main_UCI_func(CP, RO, CPO, CPrO, CR, Data, Dia, DispMExD, MA, MAn, ME, S,
		TipoOp, NumEsp, NumTOp, NumSalOp, NumCPO, NumCPrO, NumCR,
		NumMedEsp, NumEspxE, NumAsist, NumAnest, k0, k1, k2, k3,
		numIQ, numIC, taxC, taxE, taxEQ, ProbXEst, genToWidth,
		generations, keeppriority);

	emxDestroyArray_int32_T(S);
	emxDestroyArray_int32_T(ME);
	emxDestroyArray_int32_T(MAn);
	emxDestroyArray_int32_T(MA);
	emxDestroyArray_int32_T(DispMExD);
	emxDestroyArray_int32_T(Dia);
	emxDestroyArray_int32_T(Data);
	emxDestroyArray_int32_T(CR);
	emxDestroyArray_int32_T(CPrO);
	emxDestroyArray_int32_T(CPO);
	emxDestroyArray_int32_T(RO);
	emxDestroyArray_int32_T(CP);

	/* Terminate the application.
	   You do not need to do this more than one time. */
	model_terminate();
	return 0;
}