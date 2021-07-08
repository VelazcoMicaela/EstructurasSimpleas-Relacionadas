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
#include "mascota.h"
#include "tipo.h"
#include "colores.h"

int cargarDescripcionTipo(int id, eTipo tipo[], int len, char desc[])
{
	int error=-1;

	if(tipo!=NULL && len>0&& id>0&& desc!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(tipo[i].id==id)
			{
				strcpy(desc,tipo[i].descripcion);
				error=0;
				break;
			}
		}
	}
	return error;
}

void mostrarTipo(eTipo tipo)
{
	printf(" %d     %8s\n",tipo.id,tipo.descripcion);
}


int mostrarArrayTipo(eTipo tipo[], int len)
{
	int error=-1;

	if(tipo!=NULL&& len>0)
	{
		printf(" IdTipo Descripcion\n");
		for(int i=0; i<len; i++)
		{
			mostrarTipo(tipo[i]);
		}
		error=0;
	}

	return error;
}





