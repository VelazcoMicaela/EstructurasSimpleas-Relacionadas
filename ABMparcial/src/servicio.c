/*
 * servicio.c
 *
 *  Created on: 20 may. 2021
 *      Author: Asus
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

int cargarDescripcionServicio(int id, eServicio servicio[], int len, char desc[])
{
	int error=-1;

	if(servicio!=NULL && len>0&& id>0&& desc!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(servicio[i].id==id)
			{
				strcpy(desc,servicio[i].descripcion);
				error=0;
				break;
			}
		}
	}
	return error;
}

void mostrarServicio(eServicio servicio)
{
	printf(" %d    %15s %3.2f\n",servicio.id, servicio.descripcion, servicio.precio);
}


int mostrarArrayServicio(eServicio servicio[], int len)
{
	int error=-1;

	if(servicio!=NULL&& len>0)
	{
		printf(" IdServicio  Descripcion Precio\n");
		for(int i=0; i<len; i++)
		{
			mostrarServicio(servicio[i]);
		}
		error=0;
	}

	return error;
}
