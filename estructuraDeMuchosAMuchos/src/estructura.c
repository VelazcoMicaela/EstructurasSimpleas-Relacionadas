/*
 ============================================================================
 Name        : estructura.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
#include "sector.h"
#include "informes.h"
#include "comidas.h"
#include "almuerzo.h"
#include "fecha.h"


#define TAM 10
#define TAMCOL 5
#define TAMTIP 5
#define TAMTRAB 15

int main(void) {
	setbuf(stdout,NULL);

	eMascota emp1[TAM];
	eTrabajo almuerzo[TAMTRAB];
	int respuesta;
	int opcion;
	char salir;
	int pLegajo=2000;
	int pAlmuerzo=3000;
	//int error;

	eColor sectores[TAMCOL]=
	{
			{500, "Sistema"},
			{501, "Legales"},
			{502, "RRHH"},
			{503, "Contable"},
			{504, "Ventas"}
	};

	eServicio comida[TAMTIP]=
	{
			{1000, "Milanesa",150},
			{1001, "Ensalada",190},
			{1002, "Fideos",140},
			{1003, "Pizza",120},
			{1004, "Sopa",110}
	};


	if(inicializarMascota(emp1, TAM)==0)
	{
		printf("LISTA INICIALIZADA EMPLEADOS----  ");
	}

	if(inicializarTrabajo(almuerzo, TAMTRAB)==0)
	{
		printf("LISTA INICIALIZADA ALMUERZOS\n");
	}

	if(hardcodearMascota(emp1, TAM, 8, &pLegajo)>0)//numero cantidad de empleados q van a entrar hardcodeado
	{
		printf("Hardcodeo Empleado cargado --------  ");
	}

	/*if(hardcodearAlmuerzos(almuerzo, TAMALM, 5, &pAlmuerzo)>0)//numero cantidad de almuerzos q van a entrar hardcodeado
	{
		printf("Hardcodeo Almuerzo cargado\n");
	}*/

	do
	{
		printf("\n**** ABM EMPLEADOS ****");
		respuesta=utn_getNumeroEnteroConIntentos(&opcion, "\nSeleccione una opcion\n 1-Alta empleado \n 2-Baja empleado\n 3-Modificar empleado\n 4-Listar empleado\n "
				"5-Ordenar empleado\n 6-Mostrar sector \n 7-Informes\n 8-Mostrar por sectores\n 9-Mostrar sector que mas gana \n 10-TOtal a depositar\n 11-Mostrar Almuerzos\n "
				"12-Mostrar Comidas\n 13-Alta Almuerzo\n 14-Baja Almuerzo\n 15-Modificar Almuerzo\n 16-Mostrar Almuerzos de un empleado\n20-Salir\n", "ERROR no es una opcion valida\n", 1, 20, 5);

		if(respuesta==0)
		{
			switch(opcion)
			{
				case 1:
					printf("Alta empleado\n");

					if(cargarMascota(emp1, TAM,&pLegajo,sectores,TAMCOL)==0)
					{
						printf("Carga exitosa\n");
					}
					break;

				case 2:
					if(bajaMascota(emp1, TAM,sectores,TAMCOL)==0)
					{
						mostrarArrayMascota(emp1, TAM,sectores,TAMCOL);
						printf("Baja exitosa\n");
					}
					break;

				case 3:
					printf("Modificar empleado\n");
					modificarMascota(emp1, TAM);
					break;

				case 4:
					mostrarArrayMascota(emp1,TAM,sectores,TAMCOL);
					break;

				case 5:
					printf("ORDENAR\n");
					if(ordenarArrayMascota(emp1, TAM)==0)
					{
						mostrarArrayMascota(emp1,TAM,sectores,TAMCOL);
					}
					break;

				case 6:
					printf("MOSTRAR SECTORES\n");
					mostrarArrayColore(sectores,TAMCOL);
					break;

				case 7:

					if(listarEmpleadosColor(sectores,TAMCOL, emp1,TAM)==0)
					{
						printf("\n");
					}

					break;

				case 8:
					if(mostrarSectoresYEmpleados(sectores, TAMCOL, emp1,TAM)==0)
					{
						printf("\n");
					}

					break;

				case 9:
					if(sectorMayorSueldo(sectores,TAMCOL, emp1,TAM)==0)
					{
						printf("\n");
					}
					break;

				case 10:
					if(totalADepositar(sectores,TAMCOL, emp1,TAM)==0)
					{
						printf("\n");
					}
					break;

				case 11:
					printf("ALMUERZOS\n");
					if(mostrarArrayTrabajo(almuerzo, comida, TAMTRAB, TAMTIP,emp1, TAM)==0)
					{
						printf("----------------------------------------------------------\n");
					}
					break;

				case 12:
					printf("COMIDA\n");
					if(mostrarArrayTipo(comida, TAMTIP)==0)
					{
						printf("----------------------------------------------------------\n");
					}
					break;

				case 13:
					printf("ALTA ALMUERZO\n");
					if(cargarTrabajo(almuerzo, TAMTIP, &pAlmuerzo, comida, TAMTRAB)==0)
					{
						if(mostrarArrayTrabajo(almuerzo, comida, TAMTRAB, TAMTIP, emp1, TAM)==0)
						{
							printf("----------------------------------------------------------\n");
						}

					}
					break;

				case 14:
					printf("BAJA ALMUERZO\n");
					if(bajaTrabajo(almuerzo, TAMTIP, comida, TAMTRAB, emp1, TAM)==0)
					{
						if(mostrarArrayTrabajo(almuerzo, comida, TAMTRAB, TAMTIP, emp1, TAM)==0)
						{
							printf("Baja exitosa\n");
							printf("----------------------------------------------------------\n");
						}
					}

					break;

				case 15:
					printf("MODIFICAR ALMUERZO\n");
					if(modificarTrabajo(almuerzo, TAMTRAB, comida, TAMTIP, emp1, TAM)==0)
					{
						if(mostrarArrayTrabajo(almuerzo, comida, TAMTRAB, TAMTIP, emp1, TAM)==0)
						{
							printf("Modificacion exitosa\n");
							printf("----------------------------------------------------------\n");
						}

					}
					break;

				case 16:
					printf("MOSTRAR ALMUERZOS DE UN EMPLEADO\n");
					if(mostrarAlmuerzoEmpleado(emp1, TAM, almuerzo, TAMTRAB, sectores, TAMCOL, comida, TAMTIP)==0)
					{
						printf("----------------------------------------------------------\n");
					}
					break;

				case 20:
					printf("salir?\n");
					if(utn_getCaracterCorroboraDosCarac(&salir, "Desea salir? S/N\n", "ERROR Ingrese S para salir o N para quedarse", 's', 'n')==0)
					{
						if(salir=='s')
						{
							printf("Gracias, adios");
						}
					}
					break;

				system("pause");
			}
		}
	}while(salir!='s');


	return EXIT_SUCCESS;
}


