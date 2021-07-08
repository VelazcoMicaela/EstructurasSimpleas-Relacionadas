/*
 * colores.c
 *
 *  Created on: 19 may. 2021
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

int cargarDescripcionColor(int id, eColor color[], int len, char desc[])
{
	int error=-1;

	if(color!=NULL && len>0&& id>0&& desc!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(color[i].id==id)
			{
				strcpy(desc,color[i].descripcion);
				error=0;
				break;
			}
		}
	}
	return error;
}

void mostrarColor(eColor color)
{
	printf(" %d     %8s\n",color.id,color.descripcion);
}


int mostrarArrayColor(eColor color[], int len)
{
	int error=-1;

	if(color!=NULL&& len>0)
	{
		printf("IdColor Descripcion\n");
		for(int i=0; i<len; i++)
		{
			mostrarColor(color[i]);
		}
		error=0;
	}

	return error;
}

