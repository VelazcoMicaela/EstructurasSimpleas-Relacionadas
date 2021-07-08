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


#define TAM 10
#define TAMTIP 5

int main(void) {
	setbuf(stdout,NULL);

	eMascota emp1[TAM];
	int respuesta;
	int opcion;
	char salir;
	int pLegajo=2000;
	//int error;

	eTipo sectores[TAMTIP]=
	{
			{500, "Sistema"},
			{501, "Legales"},
			{502, "RRHH"},
			{503, "Contable"},
			{504, "Ventas"}
	};

	if(inicializarMascota(emp1, TAM)==0)
	{
		printf("LISTA INICIALIZADA\n");
	}

	if(hardcodearMascota(emp1, TAM, 10, &pLegajo)>0)//numero cantidad de empleados q van a entrar hardcodeado
	{
		printf("Hardcodeo cargado");
	}


	do
	{
		printf("\n**** ABM EMPLEADOS ****");
		respuesta=utn_getNumeroEnteroConIntentos(&opcion, "\nSeleccione una opcion\n 1-Alta empleado \n 2-Baja empleado\n 3-Modificar empleado\n 4-Listar empleado\n "
				"5-Ordenar empleado\n 6-Mostrar sector \n 7-Informes\n 8-Mostrar por sectores\n 9-Mostrar sector que mas gana \n 10-TOtal a depositar\n\n 12-Salir\n", "ERROR no es una opcion valida\n", 1, 12, 5);

		if(respuesta==0)
		{
			switch(opcion)
			{
				case 1:
					printf("Alta empleado\n");

					if(cargarMascota(emp1, TAM,&pLegajo,sectores,TAMTIP)==0)
					{
						printf("Carga exitosa\n");
					}
					break;

				case 2:
					if(bajaMascota(emp1, TAM,sectores,TAMTIP)==0)
					{
						printf("Baja exitosa\n");
					}
					break;

				case 3:
					printf("Modificar empleado\n");
					modificarMascota(emp1, TAM);
					break;

				case 4:
					mostrarArrayMascota(emp1,TAM,sectores,TAMTIP);
					break;

				case 5:
					printf("ORDENAR\n");
					if(ordenarArrayMascota(emp1, TAM)==0)
					{
						mostrarArrayMascota(emp1,TAM,sectores,TAMTIP);
					}
					break;

				case 6:
					printf("MOSTRAR SECTORES\n");
					mostrarArrayTipo(sectores,TAMTIP);
					break;

				case 7:

					if(listarMascotaTipo(sectores,TAMTIP, emp1,TAM)==0)
					{
						printf("\n");
					}
					else
					{
						printf("ERROR SECTORES\n");
					}
					break;

				case 8:
					if(mostrarTipoYMascota(sectores, TAMTIP, emp1,TAM)==0)
					{
						printf("\n");
					}
					else
					{
						printf("ERROR SECTORES\n");
					}
					break;

				case 9:
					if(sectorMayorSueldo(sectores,TAMTIP, emp1,TAM)==0)
					{
						printf("\n");
					}
					break;

				case 10:
					if(totalADepositar(sectores,TAMTIP, emp1,TAM)==0)
					{
						printf("\n");
					}
					break;

				case 11:
					printf("INFORMES\n");
					break;

				case 12:
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


