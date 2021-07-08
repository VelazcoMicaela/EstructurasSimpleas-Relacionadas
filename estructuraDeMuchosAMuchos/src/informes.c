/*
 * informes.c
 *
 *  Created on: 10 may. 2021
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


#define LLENO 0
#define VACIO 1

int recorrerYMostrarListaColor(eColor sector[], int lenSec, eMascota lista[], int lenEmp, int id, float* acomulador)
{
	int error=-1;
	int flag=-1;

	if(sector!=NULL && lenSec>0 && lista!=NULL && lenEmp>0 && id>0)
	{
		printf("\n    SECTOR %d\n",id);
		printf("Legajo     Nombre  Edad Sexo    Sueldo   F. Ingreso  Sector Descripcion\n");
		for(int i=0; i<lenEmp; i++)
		{
			if(lista[i].sector==id&& lista[i].isEmpty==LLENO)
			{
				mostrarMascota(lista[i], sector, lenSec);
				*acomulador=lista[i].sueldo+*acomulador;
				flag=0;
			}
		}
		if(flag==-1)
		{
			printf("No hay empleado en este sector\n");
		}
		error=0;
	}

	return error;
}

int totalADepositar(eColor sector[], int lenSec, eMascota lista[], int lenEmp)
{
	int error=-1;
	float total;
	float totalSec;

	if(sector!=NULL&& lista!=NULL && lenSec>0&& lenEmp>0)
	{
		for(int i=0; i<lenSec; i++)
		{
			total=0;
			if(recorrerYMostrarListaColor(sector, lenSec, lista, lenEmp, sector[i].id,&total)==0)
			{
				totalSec=totalSec+total;
			}
		}
		error=0;
		printf("TOTAL %.2f\n", totalSec);
	}


	return error;

}

int mostrarSectoresYEmpleados(eColor sector[], int lenSec, eMascota lista[], int lenEmp)
{
	int error=-1;
	float total;

	if(sector!=NULL&& lista!=NULL && lenSec>0&& lenEmp>0)
	{
		for(int i=0; i<lenSec; i++)
		{
			if(recorrerYMostrarListaColor(sector, lenSec, lista, lenEmp, sector[i].id,&total)==0)
			{
				printf("\n");
			}
		}
		error=0;
	}

	return error;
}

int sectorMayorSueldo(eColor sector[], int lenSec, eMascota lista[], int lenEmp)
{
	int error=-1;
	float total=0;
	int flag=0;
	float totalSueldo[lenSec];
	float mayor;
	int sectorMayor;

	if(sector!=NULL&& lista!=NULL && lenSec>0&& lenEmp>0)
	{
		for(int i=0; i<lenSec; i++)
		{
			total=0;
			if(recorrerYMostrarListaColor(sector, lenSec, lista, lenEmp, sector[i].id,&total)==0)
			{
				printf("Total %.2f\n",total);
				totalSueldo[i]=total;
			}
		}

		for(int i=0; i<lenSec; i++)
		{
			if(flag==0|| totalSueldo[i]>mayor)
			{
				mayor= totalSueldo[i];
				flag=1;
			}
			else
			{
				if(mayor>totalSueldo[i])
				{
					mayor= totalSueldo[i];
					sectorMayor=i;
				}

				if(mayor==totalSueldo[i])
				{
					printf("los secotores %s y %s poseen %.2f de sueldos",sector[i].descripcion,sector[i].descripcion,mayor);
				}
			}
		}

		for(int i=0; i<lenSec; i++)
		{

		}

		printf("El secotr %s posee el mayor sueldo con %.2f\n", sector[sectorMayor].descripcion, mayor);

		error=0;
	}

	return error;
}


int mostrarAlmuerzoEmpleado(eMascota lista[], int lenEmp, eTrabajo almuerzo[], int lenAlm, eColor sector[], int lenSec, eServicio comida[], int lenCom)
{
	int error=-1;
	int legajo;

	if(lista!=NULL && almuerzo!=NULL && lenEmp>0 && lenAlm>0 && sector!=NULL && lenSec>0)
	{
		mostrarArrayMascota(lista, lenEmp, sector, lenSec);
		if(utn_getNumeroEnteroConIntentos(&legajo, "Ingrese un legajo de empleado", "ERROR Reingrese un legajo entre 2000 y 3000", 2000, 3000, 5)==0)
		{
			for(int i=0; i<lenAlm; i++)
			{
				if(legajo==lista[i].legajo)
				{
					mostrarUnTrabajo(almuerzo[i], comida, lenCom, lista, lenEmp);
				}
			}

	}
		error=0;
	}

	return error;
}




