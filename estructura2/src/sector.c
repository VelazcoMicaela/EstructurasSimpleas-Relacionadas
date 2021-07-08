/*
 * sector.c
 *
 *  Created on: 7 may. 2021
 *      Author: Asus
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "empleado.h"
#include "sector.h"

int cargarDescripcionTipo(int id, eTipo sectores[], int len, char desc[])
{
	int error=-1;

	if(sectores!=NULL && len>0&& id>0&& desc!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(sectores[i].id==id)
			{
				strcpy(desc,sectores[i].descripcion);
				error=0;
				break;
			}
		}
	}
	return error;
}

void mostrarTipo(eTipo sector)
{
	printf(" %d     %8s\n",sector.id,sector.descripcion);
}


int mostrarArrayTipo(eTipo sector[], int len)
{
	int error=-1;

	if(sector!=NULL&& len>0)
	{
		printf("Id   Descripcion\n");
		for(int i=0; i<len; i++)
		{
			mostrarTipo(sector[i]);
		}
		error=0;
	}

	return error;
}





