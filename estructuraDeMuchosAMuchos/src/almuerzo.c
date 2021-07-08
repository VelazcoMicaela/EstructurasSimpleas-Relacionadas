/*
 * almuerzo.c
 *
 *  Created on: 11 may. 2021
 *      Author: Asus
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

#define LLENO 0
#define VACIO 1

int inicializarTrabajo(eTrabajo unAlmuerzo[], int len)
{
	int error=-1;

	if(unAlmuerzo!=NULL&& len>0)
	{
		for(int i=0; i<len; i++)
		{
			unAlmuerzo[i].isEmpty=VACIO;

		}
		error=0;
	}

	return error;
}

int buscarLibreTrabajo(eTrabajo almuerzo[], int len, int* indice)
{
	int error=-1;

	if(almuerzo!=NULL&& indice!=NULL&& len>0)
	{
		for(int i=0; i<len; i++)
		{
			if(almuerzo[i].isEmpty==VACIO)
			{
				*indice=i;
				error=0;
				break;
			}
		}

	}
	return error;
}

int buscarTrabajo(eTrabajo unAlmuerzo[], int len, int* pId, int id)
{
	int error=-1;

	if(unAlmuerzo!=NULL && len>0 && id>0 && pId!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(unAlmuerzo[i].id==id && unAlmuerzo[i].isEmpty==LLENO)
			{
				*pId= i;
				break;
			}
		}
		error=0;
	}

	return error;
}

int mostrarUnTrabajo(eTrabajo almuerzo, eServicio comida[], int len, eMascota lista[], int lenEmp)
{
	int error=-1;
	char desc[20];
	char nombre[20];

	if(cargarDescripcionTipo(comida, len, almuerzo.idComida, desc)==0 && cargarNombreEmpleadoEnAlmuerzo(lista, lenEmp, almuerzo.legajo, nombre)==0)
	{
		printf("%d  %d  %10s  %d      %10s  %d/%d/%d %d \n",almuerzo.id,almuerzo.legajo,nombre,almuerzo.idComida,desc,almuerzo.fecha.dia,
															almuerzo.fecha.mes,almuerzo.fecha.anio,almuerzo.isEmpty);

	}
	return error;
}

int mostrarArrayTrabajo(eTrabajo almuerzo[], eServicio comida[],int lenAlm, int lenCom, eMascota lista[], int lenEmp)
{
	int error=-1;

	if(almuerzo!=NULL && lenAlm>0 && comida!=NULL && lenCom>0 && lista!=NULL && lenEmp>0)
	{
		printf("id  legajo      nombre  idComida Descripcion   fecha    isEmpty\n");

		for(int i=0;i<10;i++)
		{
			if(almuerzo[i].isEmpty==LLENO)
			{
				mostrarUnTrabajo(almuerzo[i], comida, lenCom, lista, lenEmp);
				error=0;
			}
		}

		if(error!=0)
		{
			printf("No hay almuerzos para mostrar\n");
			error=0;
		}

	}

	return error;
}

int cargarTrabajo(eTrabajo lista[], int lenComida,int* pLegajo, eServicio comida[], int lenAlm)
{
	int error=-1;
	int indice;
	char respuesta;
	eTrabajo aux;

	if(lista!=NULL && pLegajo!=NULL && lenAlm>0 && lenComida>0 && comida!=NULL)
	{

		while(respuesta!='n')
		{
			if(buscarLibreTrabajo(lista, lenAlm, &indice)==0)
			{
				printf("INDICE DEVUELTO %d\n",indice);
				printf("Legajo %d\n",*pLegajo);
				mostrarArrayTipo(comida, lenComida);
				if(utn_getNumeroEnteroConIntentos(&aux.idComida, "Ingrese idComida ", "ERROR Reingrese idComida entre 1000 y 1004 ", 1000, 1004, 5)==0)
				{
					if(utn_getNumeroEnteroConIntentos(&aux.legajo, "Ingrese legajo", "ERROR Reingrese legajo entre 2000 y 3000 ", 2000, 3000, 5)==0)
					{
						if(utn_getNumeroEnteroConIntentos(&aux.fecha.dia, "Ingrese dia de almuerzo ", "ERROR Reingrese dia de ingreso entre 1 y 31", 1, 31, 5)==0)
						{
							if(utn_getNumeroEnteroConIntentos(&aux.fecha.mes, "Ingrese mes de almuerzo ", "ERROR Reingrese mes de ingreso entre 1 y 12", 1, 12, 5)==0)
							{
								if(utn_getNumeroEnteroConIntentos(&aux.fecha.anio, "Ingrese anio de almuerzo ", "ERROR Reingrese anio de ingreso entre 1900 y 2021", 1900, 2021, 5)==0)
								{
									aux.isEmpty=LLENO;
									lista[indice]=aux;
									lista[indice].id=*pLegajo;
									printf("%d",indice);
									(*pLegajo)++;
									error=0;
								}
							}
						}
					}
				}
			}
			else
			{
				printf("No hay lugar\n");
			}
			if(utn_getCaracterCorroboraDosCarac(&respuesta, "Desea seguir ingresando almuerzo? s-n", "ERROR reingrese s-n", 's', 'n'))
			{
				printf("Gracias\n");
			}
		}
	}

	return error;
}

int bajaTrabajo(eTrabajo almuerzo[], int len, eServicio comida[], int lenCom, eMascota lista[], int lenEmp)
{
	int error=-1;
	int legajo;
	int indice;
	char eliminar;

	if(almuerzo!=NULL && len>0 && comida!=NULL && lenCom>0 && lista!=NULL && lenEmp>0)
	{
		mostrarArrayTrabajo(almuerzo, comida, len, lenCom, lista, lenEmp);
		if(utn_getNumeroEnteroConIntentos(&legajo, "Ingrese id ", "ERROR Reingrese id entre 3000 y 4000 ", 3000, 4000, 5)==0 &&
			buscarTrabajo(almuerzo, len, &indice, legajo)==0)
		{
			mostrarUnTrabajo(almuerzo[indice],comida,lenCom, lista, lenEmp);
			if(utn_getCaracterCorroboraDosCarac(&eliminar, "Desea eliminar? S/N\n", "ERROR Ingrese S para eliminar o N para volver", 's', 'n')==0)
			{
				if(eliminar=='s')
				{
					almuerzo[indice].isEmpty=VACIO;
					error=0;
				}
				else
				{
					printf("Baja cancelada por el usuario\n");
				}
			}
		}
		else
		{
			printf("No hay empleado con legajo %d \n",legajo);
		}
	}

	return error;
}

int modificarTrabajo(eTrabajo* almuerzo, int len, eServicio comida[], int lenCom, eMascota lista[], int lenEmp)
{
	int error=-1;
	int id;
	int indice;

	if(almuerzo!=NULL && len>0 && comida!=NULL && lenCom>0 && lista!=NULL && lenEmp>0)
	{
		if(mostrarArrayTrabajo(almuerzo, comida, len, lenCom, lista, lenEmp)==0 &&
				utn_getNumeroEnteroConIntentos(&id, "Ingrese el id a modificar ", "ERROR id debe esta entre 2000 a 3000. Reingrese ", 3000, 4000, 5)==0 &&
				buscarTrabajo(almuerzo, len, &indice, id)==0)
		{
			printf("id  legajo idComida Descripcion   fecha    isEmpty\n");
			mostrarUnTrabajo(almuerzo[indice], comida, lenCom, lista, lenEmp);
			if(menuModificacionAlmuerzo(&almuerzo[indice],comida,lenCom, lista, lenEmp)==0)
			{
				error=0;
			}
		}
	}

	return error;
}

int menuModificacionAlmuerzo(eTrabajo* almuerzo, eServicio comida[], int lenCom, eMascota lista[], int lenEmp)
{
	int error=-1;
	int opcion;
	char salir;
	eTrabajo aux;
	eTrabajo cancelacion;

	cancelacion=*almuerzo;

	if(almuerzo!=NULL && comida!=NULL && lenCom>0)
	{
		do
		{
			if(utn_getNumeroEnteroConIntentos(&opcion, "\nQue desea modificar? \n 1. LEGAJO\n 2. IDCOMIDA\n 3. FECHA\n 4. GUARDAR ", "ERROR reingrese una opcion ", 1, 4, 5)==0)
			{
				switch(opcion)
				{
					case 1:
						printf("---------------LEGAJO---------------\n");
						if(utn_getNumeroEnteroConIntentos(&aux.legajo, "Ingrese el legajo ", "ERROR reingrese legajo ", 2000, 3000, 5)==0)
						{
							(*almuerzo).legajo=aux.legajo;

							printf("id  legajo idComida Descripcion   fecha    isEmpty\n");
							mostrarUnTrabajo(*almuerzo, comida, lenCom,lista, lenEmp);
							printf("-------------------------------------------------------\n");
						}
						break;

					case 2:
						printf("---------------IDCOMIDA---------------\n");
						if(utn_getNumeroEnteroConIntentos(&aux.idComida, "Ingrese el idComida ", "ERROR reingrese idComida ", 1000, 2000, 5)==0)
						{
							(*almuerzo).idComida=aux.idComida;

							printf("id  legajo idComida Descripcion   fecha    isEmpty\n");
							mostrarUnTrabajo(*almuerzo, comida, lenCom,lista, lenEmp);
							printf("-------------------------------------------------------\n");
						}
						break;

					case 3:
						printf("---------------FECHA---------------\n");
						if(utn_getNumeroEnteroConIntentos(&aux.fecha.dia, "Ingrese dia de almuerzo ", "ERROR Reingrese dia de ingreso entre 1 y 31", 1, 31, 5)==0 &&
							utn_getNumeroEnteroConIntentos(&aux.fecha.mes, "Ingrese mes de almuerzo ", "ERROR Reingrese mes de ingreso entre 1 y 12", 1, 12, 5)==0 &&
							utn_getNumeroEnteroConIntentos(&aux.fecha.anio, "Ingrese anio de almuerzo ", "ERROR Reingrese anio de ingreso entre 1900 y 2021", 1900, 2021, 5)==0)
						{
							(*almuerzo).fecha=aux.fecha;

							printf("id  legajo idComida Descripcion   fecha    isEmpty\n");
							mostrarUnTrabajo(*almuerzo, comida, lenCom,lista, lenEmp);
							printf("-------------------------------------------------------\n");
						}
						break;

					case 4:
						printf("---------------GUARDAR---------------\n");
						printf("id  legajo idComida Descripcion   fecha    isEmpty\n");
						mostrarUnTrabajo(*almuerzo, comida, lenCom, lista, lenEmp);

						if(utn_getCaracterCorroboraDosCarac(&salir, "Desea guardar los cambios? S/N ", "ERROR reingrese S/N ", 's', 'n')==0)
						{
							if(salir=='n')
							{
								printf("Modificacion cancelada\n");
								(*almuerzo)=cancelacion;
								error=0;
							}
							else
							{
								error=0;
							}

						}
						break;
				}
			}

		}while(error!=0);

	}

	return error;

}

int hardcodearTrabajo(eTrabajo lista[], int len, int cant, int* pLegajo)
{
	int cantidad=0;

	eTrabajo almuerzo[10]=
	{
			{0,1000,2000,{26,4,2019},0},
			{0,1001,2001,{18,6,2020},0},
			{0,1002,2002,{11,10,2016},0},
			{0,1003,2003,{29,4,2014},0},
			{0,1004,2004,{13,3,2013},0},
			{0,1000,2005,{15,9,2008},0},
			{0,1001,2006,{2,12,2018},0},
			{0,1002,2007,{6,11,2017},0},
			{0,1003,2008,{16,3,2018},0},
			{0,1004,2009,{19,1,2011},0},
	};

	if(lista!=NULL&& almuerzo!=NULL&& len>0 && cant>=0 && cant<=len && pLegajo!=NULL)
	{
		for(int i=0; i<cant; i++)
		{
			lista[i]=almuerzo[i];

			lista[i].id=*pLegajo;
			(*pLegajo)++;

			cantidad++;
		}
	}

	return cantidad;
}
