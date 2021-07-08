/*
 * empleado.c
 *
 *  Created on: 3 may. 2021
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



#define LLENO 0
#define VACIO 1


void mostrarMascota(eMascota empleado, eTipo sector[], int len)//
{
	char descripcion[20];

	if(cargarDescripcionTipo(empleado.sector, sector,len, descripcion)==0)
	{
		printf("%5d  %10s   %d    %c   %9.2f  %02d/%02d/%d   %d    %10s\n",empleado.legajo,
			empleado.nombre, empleado.edad, empleado.sexo, empleado.sueldo,
			empleado.fIngreso.dia, empleado.fIngreso.mes, empleado.fIngreso.anio,empleado.sector, descripcion);

	}
	else
	{
		printf("ERROR\n");
	}

}

int mostrarArrayMascota(eMascota lista[],int len, eTipo sector[], int lenSector)
{
	int error=-1;
	int flag=0;

	if(lista!=NULL&& len>0&& sector!=NULL&& lenSector>0)
	{
		printf("\nLegajo     Nombre  Edad Sexo    Sueldo   F. Ingreso  Sector Descripcion\n");
		for(int i=0; i<len; i++)
		{
			if(lista[i].isEmpty==LLENO)
			{
				mostrarMascota(lista[i],sector,lenSector);
				flag=1;
			}
		}

		if(flag!=1)
		{
			printf("NO HAY EMPLEADOS PARA MOSTRAR\n");
		}
		error=0;
	}
	return error;
}

int inicializarMascota(eMascota lista[], int len)
{
	int error=-1;

	if(lista!=NULL&&len>0)
	{
		for(int i=0; i<len; i++)
		{
			lista[i].isEmpty=VACIO;
		}
		error=0;
	}

	return error;
}

int cargarMascota(eMascota lista[], int len,int* pLegajo, eTipo sector[], int lenSector)
{
	int error=-1;
	int indice;
	char respuesta;
	eMascota aux;

	if(lista!=NULL&&pLegajo!=NULL&&len>0)
	{

		while(respuesta!='n')
		{
			if(buscarLibreMascota(lista, len, &indice)==0)
			{
				printf("Legajo %d\n",*pLegajo);
				if(utn_getString(aux.nombre, "Ingrese nombre", "ERROR reingrese nombre", 5)==0)
				{
					if(utn_getNumeroEnteroConIntentos(&aux.edad, "Ingrese edad ", "ERROR Reingrese edad entre 0 y 110 ", 0, 110, 5)==0)
					{
						if(mostrarArrayTipo(sector, lenSector)==0)
						{
							if(utn_getNumeroEnteroConIntentos(&aux.sector, "Ingrese sector", "ERROR Reingrese sector entre 500 y 504 ", 500, 504, 5)==0)
							{
								if(utn_getCaracterCorroboraDosCarac(&aux.sexo, "Ingrese sexo F o M ", "ERROR Reingrese sexo F o M", 'm', 'f')==0)
								{
									if(utn_getNumeroFlotante(&aux.sueldo, "Ingrese sueldo ", "Reingrese sueldo ", 0, 999999, 5)==0)
									{
										if(utn_getNumeroEnteroConIntentos(&aux.fIngreso.dia, "Ingrese dia de ingreso ", "ERROR Reingrese dia de ingreso entre 1 y 31", 1, 31, 5)==0)
										{
											if(utn_getNumeroEnteroConIntentos(&aux.fIngreso.mes, "Ingrese mes de ingreso ", "ERROR Reingrese mes de ingreso entre 1 y 12", 1, 12, 5)==0)
											{
												if(utn_getNumeroEnteroConIntentos(&aux.fIngreso.anio, "Ingrese anio de ingreso ", "ERROR Reingrese anio de ingreso entre 1900 y 2010", 1900, 2010, 5)==0)
												{
													aux.isEmpty=0;
													lista[indice]=aux;
													lista[indice].legajo=*pLegajo;
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
				}
			}
			else
			{
				printf("No hay lugar\n");
			}
			if(utn_getCaracterCorroboraDosCarac(&respuesta, "Desea seguir ingresando empleados? s-n", "ERROR reingrese s-n", 's', 'n'))
			{
				printf("Gracias\n");
			}
		}


	}

	return error;
}

int bajaMascota(eMascota lista[], int len, eTipo sector[], int lenSec)
{
	int error=-1;
	int legajo;
	int indice;
	char eliminar;

	if(lista!=NULL&&len>0)
	{
		mostrarArrayMascota(lista, len,sector,lenSec);
		if(utn_getNumeroEnteroConIntentos(&legajo, "Ingrese legajo ", "ERROR Reingrese legajo entre 2000 y 3000 ", 1999, 3000, 5)==0)
		{
			if(buscarMascota(lista, len, &indice, legajo)==0)
			{
				mostrarMascota(lista[indice],sector,lenSec);
				if(utn_getCaracterCorroboraDosCarac(&eliminar, "Desea eliminar? S/N\n", "ERROR Ingrese S para eliminar o N para volver", 's', 'n')==0)
				{
					if(eliminar=='s')
					{
						lista[indice].isEmpty=VACIO;
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

	}

	return error;
}

int buscarMascota(eMascota lista[], int len, int* indice, int legajo)
{
	int error=-1;

	if(lista!=NULL&& len>0&& indice!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(lista[i].legajo==legajo && lista[i].isEmpty==LLENO)
			{
				*indice=i;
				error=0;
				break;
			}
		}
	}

	return error;
}

int ordenarArrayMascota(eMascota lista[], int len)
{
	int error=-1;
	eMascota aux;

	if(lista!=NULL&&len> 0)
	{
		for(int i=0;i<len-1;i++)
		{
			for(int j=i+1; j<len;j++)
			{
				if(lista[i].legajo<lista[j].legajo ||//de mayor a menor
					(lista[i].legajo==lista[j].legajo &&
					strcmp(lista[i].nombre,lista[j].nombre)<0))//de mayor a menor
				{
					aux=lista[i];
					lista[i]=lista[j];
					lista[j]=aux;
				}
			}
		}
		error=0;
	}
	return error;
}

int buscarLibreMascota(eMascota lista[], int len,int* indice)
{
	int error=-1;

	if(lista!=NULL&& indice!=NULL&& len>0)
	{
		for(int i=0; i<len; i++)
		{
			if(lista[i].isEmpty==VACIO)
			{
				*indice=i;
				error=0;
				break;
			}
		}

	}
	return error;
}

int modificarMascota(eMascota lista[], int len)
{
	int error=-1;


	if(lista!=NULL&&len>0)
	{

	}

	return error;
}


int listarMascotaTipo(eTipo sector[], int lenSec, eMascota lista[], int lenEmp)
{
	int error=-1;
	int opcion;
	int respuesta;
	float total=0;

	system("cls");

	if(sector!=NULL&& lista!=NULL && lenSec>0&& lenEmp>0)
	{
		if(mostrarArrayTipo(sector, lenSec)==0)
		{
			if(utn_getNumeroEnteroConIntentos(&respuesta, "Ingrese 1-listar empleados por sector 2- mostrar total de sueldos por sector ", "ERROR REINGRESE OPCION", 1, 2, 5)==0)
			{
				if(utn_getNumeroEnteroConIntentos(&opcion, "Ingrese el sector a listar empleados ", "ERROR el sector no existe ", 500, 504, 5)==0)
				{
					switch(respuesta)
					{
						case 1:
							if(recorrerYMostrarListaTipo(sector, lenSec, lista, lenEmp, opcion,&total)==0)
							{
								error=0;
							}

						break;

						case 2:
							if(recorrerYMostrarListaTipo(sector, lenSec, lista, lenEmp, opcion,&total)==0)
							{
								printf("el total del sueldo del sector es: %.2f",total);
								error=0;
							}
							break;
					}
				}
			}
		}
	}

	return error;
}




int hardcodearMascota(eMascota lista[], int len, int cant, int* pLegajo)
{
	int cantidad=0;

	eMascota emp2[10]=
	{
			{0,"Donato",56,'m',10000,{26,4,2019},501,0},
			{0,"Carmen",71,'f',12000,{18,6,2020},500,0},
			{0,"Chepi",39,'f',11000,{11,10,2016},503,0},
			{0,"Alex",30,'m',13200,{29,4,2014},503,0},
			{0,"German",52,'m',13200,{13,3,2013},504,0},
			{0,"Maria",45,'f',11500,{15,9,2008},500,0},
			{0,"Daniel",44,'m',10800,{2,12,2018},501,0},
			{0,"Andrea",58,'f',13900,{6,11,2017},502,0},
			{0,"Candela",38,'f',12100,{16,3,2018},503,0},
			{0,"Magdalena",29,'f',11500,{19,1,2011},504,0},
	};

	if(lista!=NULL&& emp2!=NULL&& len>0 && cant>=0 && cant<=len && pLegajo!=NULL)
	{
		for(int i=0; i<cant; i++)
		{
			lista[i]=emp2[i];

			lista[i].legajo=*pLegajo;
			(*pLegajo)++;

			cantidad++;
		}
	}

	return cantidad;
}
