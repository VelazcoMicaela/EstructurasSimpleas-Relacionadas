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
#include "informes.h"
#include "mascota.h"
#include "tipo.h"
#include "colores.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"


#define TAM 11
#define TAMTIP 5
#define TAMCOL 5
#define TAMSER 3
#define TAMTRAB 15
#define TAMCLIENTE 3

int main(void) {
	setbuf(stdout,NULL);

	eMascota mascota[TAM];
	eTrabajo trabajo[TAMTRAB];

	int respuesta;
	int opcion;
	char salir;
	int idMascota=4000;
	int idTrabajo=3000;
	//int error;

	eMascota masJoven;

	int totalColorTipo;
	int totalColor;

	float totalServicio;



	eTipo tipo[TAMTIP]=
	{
			{1000, "Ave"},
			{1001, "Perro"},
			{1002, "Gato"},
			{1003, "Roedor"},
			{1004, "Pez"}
	};

	eColor color[TAMCOL]=
	{
			{5000, "Negro"},
			{5001, "Blanco"},
			{5002, "Gris"},
			{5003, "Rojo"},
			{5004, "Azul"}
	};

	eServicio servicio[TAMSER]=
	{
			{2000, "Corte",250},
			{2001, "Desparasitado",300},
			{2002, "Castrado",400},
	};

	eCliente cliente[TAMCLIENTE]=
	{
			{500, "Carlos",'m'},
			{501, "Viviana",'f'},
			{502, "Silvia",'f'},
	};

	if(inicializarMascota(mascota, TAM)==0)
	{
		printf("LISTA MASCOTA INICIALIZADA ------- ");
	}

	if(inicializarTrabajo(trabajo, TAMTRAB)==0)
	{
		printf(" LISTA TRABAJO INICIALIZADA\n");
	}

	if(hardcodearMascota(mascota, TAM, 10, &idMascota)>0)//numero cantidad de mascota q van a entrar hardcodeado
	{
		printf(" Hardcodeo  mascota cargado ------ ");
	}

	if(hardcodearTrabajo(trabajo, TAMTRAB, 10, &idTrabajo)>0)//numero cantidad de trabajo q van a entrar hardcodeado
	{
		printf(" Hardcodeo trabajo cargado\n");
	}


	do
	{
		printf("\n**** ABM MASCOTA ****");
		respuesta=utn_getNumeroEnteroConIntentos(&opcion, "\nSeleccione una opcion\n 1-Alta Mascota\n 2-Modificar Mascota \n 3-Baja Mascota\n 4-Listar Mascota\n "
				"5-Listar Tipos\n 6-Listar Color \n 7-Listar Servicios\n 8-Alta Trabajo\n 9-Listar Trabajo\n 10-Baja Trabajo\n"
				" 11-Mostrar clientes\n 12-Mostrar mascotas por tipos\n 13-Mostrar mascotas por color\n"
				" 14-Mostrar todas mascotas por tipos\n 15-Mostrar todos los trabajos por mascota\n"
				" 16-Mascota mas joven\n 17-Mascota de un mismo tipo y color\n 18-Mascota mascota con mayor cantidad de color\n "
				"19-Total de servicios por mascota \n 30-Salir ", "ERROR no es una opcion valida\n", 1, 30, 5);

		if(respuesta==0)
		{
			switch(opcion)
			{
				case 1:
					printf("\n-----Alta Mascota-----\n");

					if(cargarMascota(mascota, TAM,&idMascota,tipo,TAMTIP, color, TAMCOL, cliente, TAMCLIENTE)==0)
					{
						if(mostrarArrayMascota(mascota, TAM, tipo, TAMTIP, color, TAMCOL, cliente, TAMCLIENTE)==0)
						{
							printf("Carga exitosa\n");
						}

					}
					break;

				case 3:
					printf("\n-----Baja Mascota-----\n");
					if(bajaMascota(mascota, TAM,tipo,TAMTIP, color, TAMCOL, cliente, TAMCLIENTE)==0)
					{
						printf("Baja exitosa\n");
					}
					break;

				case 2:
					printf("\n-----Modificar Mascota-----\n");
					if(modificarMascota(mascota,TAM,tipo,TAMTIP, color, TAMCOL, cliente, TAMCLIENTE)==0)
					{
						printf("Modificacion exitosa\n");
					}
					else
					{
						printf("Cancelacion exitosa\n");
					}
					break;

				case 4:
					printf("\n-----Listar Mascota-----\n");
					if(mostrarArrayMascota(mascota,TAM,tipo,TAMTIP, color, TAMCOL, cliente, TAMCLIENTE)==0)
					{
						printf("\n");
					}
					else
					{
						printf("ERROR\n");
					}
					break;

				case 5:
					printf("\n-----Listar Tipo-----\n");
					if(mostrarArrayTipo(tipo, TAMTIP)==0)
					{
						printf("\n");
					}
					break;

				case 6:
					printf("\n-----Listar Colores-----\n");
					if(mostrarArrayColor(color, TAMCOL)==0)
					{
						printf("\n");
					}
					break;

				case 7:
					printf("\n-----Listar Servicios-----\n");
					if(mostrarArrayServicio(servicio, TAMSER)==0)
					{
						printf("\n");
					}

					break;

				case 8:
					printf("\n-----Alta Trabajo-----\n");
					if(cargarTrabajo(trabajo, TAMTRAB, &idTrabajo, servicio, TAMSER, mascota, TAM, tipo, TAMTIP, color, TAMCOL, cliente, TAMCLIENTE)==0)
					{
						if(mostrarArrayTrabajo(trabajo, TAMTRAB, servicio, TAMSER, mascota, TAM)==0)
						{
							printf("Carga exitosa\n");
						}
					}
					break;


				case 9:
					printf("\n-----Listar Trabajo-----\n");
					if(mostrarArrayTrabajo(trabajo, TAMTRAB, servicio, TAMSER, mascota, TAM)==0)
					{
						printf("\n");
					}
					break;

				case 10:
					printf("\n-----Baja Trabajo-----\n");
					if(bajaTrabajo(trabajo, TAMTRAB, servicio, TAMSER, mascota, TAM)==0)
					{
						printf("Baja exitosa\n");
					}
					break;

				case 12:
					printf("\n-----Mostrar mascotas por tipos-----\n");
					if(mostrarTipoDeMascota(tipo, TAMTIP, mascota, TAM, color, TAMCOL, cliente, TAMCLIENTE)==0)
					{
						printf("\n");
					}
	//////
					break;

				case 11:
					printf("\n-----Mostrar cliente-----\n");
					if(mostrarArrayCliente(cliente, TAMCLIENTE)==0)
					{
						printf("\n");
					}
//////
					break;

				case 13:
					printf("\n-----Mostrar mascotas por color-----\n");
					if(mostrarColorDeMascota(tipo, TAMTIP, mascota, TAM, color, TAMCOL, cliente, TAMCLIENTE)==0)
					{
						printf("\n");
					}
//////
					break;


				case 14:
					printf("\n-----Mostrar todas mascotas por tipos-----\n");
					if(mostrarTodosTiposDeMascota(tipo, TAMTIP, mascota, TAM, color, TAMCOL, cliente, TAMCLIENTE)==0)
					{
						printf("\n");
					}
//////
					break;

				case 15:
					printf("\n-----Mostrar trabajo de mascota-----\n");
					if(mostrarTrabajoDeMascotas(trabajo, TAMTRAB, servicio, TAMSER, mascota, TAM, tipo, TAMTIP, color, TAMCOL , cliente, TAMCLIENTE)==0)
					{
						printf("\n");
					}
////
					break;

				case 16:
					printf("\n-----Mascota mas joven-----\n");
					if(mascotaMasJoven(mascota, TAM, &masJoven, tipo, TAMTIP, color, TAMCOL, cliente, TAMCLIENTE)==0)
					{
						if(masJoven.edad>0)
						{
							printf("Las mascotas %s con %d de edad es la mas joven\n",masJoven.nombre, masJoven.edad);
						}

					}
					break;

				case 17:
					printf("\n-----Mascota de un mismo color y tipo-----\n");
					if(contadorTipoColorMascota(tipo, TAMTIP, mascota, TAM, color, TAMCOL, cliente, TAMCLIENTE, &totalColorTipo)==0)
					{
						if(masJoven.edad>0)
						{
							printf("Hay %d mascotas del mismo color y tipo\n",totalColorTipo);
						}

					}
					break;

				case 18:
					printf("\n-----Mascota mascota con mayor cantidad de color-----\n");
					if(contadorColorMascota(tipo, TAMTIP, mascota, TAM, color, TAMCOL, cliente, TAMCLIENTE, &totalColor)==0)
					{
						if(totalColor>0)
						{
							printf("Hay %d mascotas del mismo color y tipo\n",totalColor);
						}

					}
					break;
				case 19:
					printf("\n-----Total de servicios por mascota-----\n");
					if(promedioTrabajosMascota(trabajo, TAMTRAB, servicio, TAMSER, mascota, TAM, tipo, TAMTIP, color, TAMCOL, cliente, TAMCLIENTE, &totalServicio)==0)
					{
						printf("total %.2f\n",totalServicio);
					}
					break;

				case 30:
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


