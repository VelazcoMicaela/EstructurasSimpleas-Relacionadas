/*
 * trabajo.c
 *
 *  Created on: 20 may. 2021
 *      Author: Asus
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "servicio.h"
#include "trabajo.h"
#include "mascota.h"
#include "tipo.h"
#include "colores.h"
#include "cliente.h"




#define LLENO 0
#define VACIO 1


int mostrarTrabajo(eTrabajo trabajo,eServicio servicio[],int lenSer, eMascota mascota[], int lenMas)
{
	int error=-1;
	char descSer[20];
	char descMas[20];

	if(servicio!=NULL&& lenSer>0 && mascota!=NULL&& lenMas>0)
	{
		if(cargarDescripcionServicio(trabajo.idServicio, servicio,lenSer, descSer)==0)
		{
			if(cargarDescripcionMascota(trabajo.idMascota, mascota, lenMas, descMas)==0)
			{
				printf("%5d  %d %10s  %d %15s  %2d/%2d/%d\n",trabajo.id, trabajo.idMascota, descMas, trabajo.idServicio, descSer,
					trabajo.fTrab.dia, trabajo.fTrab.mes, trabajo.fTrab.anio);
			}
		}
		error=0;
	}
	return error;
}

int mostrarArrayTrabajo(eTrabajo trabajo[],int len, eServicio servicio[],int lenSer, eMascota mascota[], int lenMas)
{
	int error=-1;
	int flag=0;

	if(trabajo!=NULL&& len>0&& servicio!=NULL&& lenSer>0 && mascota!=NULL&& lenMas>0)
	{
		printf("\n Id   IdMas     Nombre  IdServ  DescServicio  Fecha\n");
		for(int i=0; i<len; i++)
		{
			if(trabajo[i].isEmpty==LLENO)
			{
				mostrarTrabajo(trabajo[i],servicio,lenSer,mascota,lenMas);
				flag=1;
			}
		}

		if(flag!=1)
		{
			printf("NO HAY TRABAJO PARA MOSTRAR\n");
		}
		error=0;
	}
	return error;
}

int inicializarTrabajo(eTrabajo trabajo[], int len)
{
	int error=-1;

	if(trabajo!=NULL&&len>0)
	{
		for(int i=0; i<len; i++)
		{
			trabajo[i].isEmpty=VACIO;
		}
		error=0;
	}

	return error;
}

int cargarTrabajo(eTrabajo trabajo[], int len,int* pLegajo, eServicio servicio[],int lenSer, eMascota mascota[], int lenMas, eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente)
{
	int error=-1;
	int indice;
	char respuesta;
	eTrabajo aux;

	if(trabajo!=NULL && pLegajo!=NULL && len>0 && servicio!=NULL && lenSer>0 && mascota!=NULL && lenMas>0 && tipo!=NULL && lenTip>0 && color!=NULL && lenCol>0)
	{

		while(respuesta!='n')
		{
			if(buscarLibreTrabajo(trabajo, len, &indice)==0)
			{
				printf("Id %d\n",*pLegajo);
				if(mostrarArrayMascota(mascota, lenMas, tipo, lenTip, color, lenCol, cliente,lenCliente)==0)
				{
					if(utn_getNumeroEnteroConIntentos(&aux.idMascota, "Ingrese idMascota", "ERROR Reingrese idMascota entre 4000 y 5000 ", 4000, 5000, 5)==0)
					{
						if(mostrarArrayServicio(servicio, lenSer)==0)
						{
							if(utn_getNumeroEnteroConIntentos(&aux.idServicio, "Ingrese idServicio ", "ERROR Reingrese idServicio entre 2000 y 2002 ", 2000, 2002, 5)==0)
							{
								if(utn_getNumeroEnteroConIntentos(&aux.fTrab.dia, "Ingrese dia del trabajo ", "ERROR Reingrese dia de trabajo entre 1 y 31", 1, 31, 5)==0)
								{
									if(utn_getNumeroEnteroConIntentos(&aux.fTrab.mes, "Ingrese mes del trabajo ", "ERROR Reingrese mes de trabajo entre 1 y 12", 1, 12, 5)==0)
									{
										if(utn_getNumeroEnteroConIntentos(&aux.fTrab.anio, "Ingrese anio del trabajo ", "ERROR Reingrese anio de trabajo entre 1900 y 2021", 1900, 2021, 5)==0)
										{
											aux.isEmpty=0;
											trabajo[indice]=aux;
											trabajo[indice].id=*pLegajo;
											(*pLegajo)++;
											error=0;
										}
									}
								}
							}
						}
					}
				}
			}
			else
			{
				printf("No hay lugar\n");
				break;
			}
			if(utn_getCaracterCorroboraDosCarac(&respuesta, "Desea seguir ingresando trabajo? s-n ", "ERROR reingrese s-n ", 's', 'n')==0)
			{
				printf("\n");
			}
		}
	}

	return error;
}

int buscarTrabajo(eTrabajo trabajo[], int len, int* indice, int legajo)
{
	int error=-1;

	if(trabajo!=NULL&& len>0&& indice!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(trabajo[i].id==legajo && trabajo[i].isEmpty==LLENO)
			{
				*indice=i;
				error=0;
				break;
			}
		}
	}

	return error;
}

int buscarLibreTrabajo(eTrabajo trabajo[], int len,int* indice)
{
	int error=-1;

	if(trabajo!=NULL&& indice!=NULL&& len>0)
	{
		for(int i=0; i<len; i++)
		{
			if(trabajo[i].isEmpty==VACIO)
			{
				*indice=i;
				error=0;
				break;
			}
		}

	}
	return error;
}

int bajaTrabajo(eTrabajo trabajo[],int len, eServicio servicio[],int lenSer, eMascota mascota[], int lenMas)
{
	int error=-1;
	int legajo;
	int indice;
	char eliminar;

	if(trabajo!=NULL&& len>0&& servicio!=NULL&& lenSer>0 && mascota!=NULL&& lenMas>0)
	{
		mostrarArrayTrabajo(trabajo, len, servicio, lenSer, mascota, lenMas);

		if(utn_getNumeroEnteroConIntentos(&legajo, "Ingrese id a dar de baja", "ERROR Reingrese id entre 3000 y 4000 ", 3000, 3000+len, 5)==0)
		{
			if(buscarTrabajo(trabajo, len, &indice, legajo)==0)
			{
				mostrarUnTrabajoConRotulo(trabajo[indice], servicio, lenSer, mascota, lenMas);

				if(utn_getCaracterCorroboraDosCarac(&eliminar, "Desea eliminar? S/N\n", "ERROR Ingrese S para eliminar o N para volver", 's', 'n')==0)
				{
					if(eliminar=='s')
					{
						trabajo[indice].isEmpty=VACIO;
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
				printf("No hay trabajo con ese id %d \n",legajo);
			}
		}
	}

	return error;
}

int mostrarUnTrabajoConRotulo(eTrabajo trabajo, eServicio servicio[],int lenSer, eMascota mascota[], int lenMas)
{
	int error=-1;
	if(servicio!=NULL && lenSer>0 && mascota!=NULL && lenMas>0)
	{
		printf("\n Id   IdMas     Nombre  IdServ  DescServicio  Fecha\n");
		mostrarTrabajo(trabajo, servicio, lenSer, mascota, lenMas);
		printf("-------------------------------------------------------\n");

		error=0;
	}

	return error;
}

int hardcodearTrabajo(eTrabajo trabajo[], int len, int cant, int* pLegajo)
{
	int cantidad=0;

	eTrabajo trabajo2[10]=
	{
			{0,4000,2002,{26,4,2019},0},
			{0,4001,2000,{18,6,2020},0},
			{0,4002,2002,{11,10,2016},0},
			{0,4003,2002,{29,4,2014},0},
			{0,4004,2000,{13,3,2013},0},
			{0,4000,2000,{15,9,2008},0},
			{0,4001,2002,{2,12,2018},0},
			{0,4002,2002,{6,11,2017},0},
			{0,4003,2000,{16,3,2018},0},
			{0,4004,2000,{19,1,2011},0},
	};

	if(trabajo!=NULL&& trabajo2!=NULL&& len>0 && cant>=0 && cant<=len && pLegajo!=NULL)
	{
		for(int i=0; i<cant; i++)
		{
			trabajo[i]=trabajo2[i];

			trabajo[i].id=*pLegajo;
			(*pLegajo)++;

			cantidad++;
		}
	}

	return cantidad;
}
