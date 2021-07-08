/*
 * comidas.c
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
#include "fecha.h"

int mostrarTipo(eServicio comida)
{
	int error=-1;

	printf("%4d  %10s %.2f\n",comida.id, comida.descripcion,comida.precio);

	return error;
}


int mostrarArrayTipo(eServicio comida[], int len)
{
	int error=-1;

	if(comida!=NULL && len>0)
	{
		printf("id   descripcion precio\n");
		for(int i=0; i<len; i++)
		{
			mostrarTipo(comida[i]);
		}
		error=0;
	}
	return error;
}

int cargarDescripcionTipo(eServicio comida[], int len,int id, char desc[])
{
	int error=-1;

	if(comida!=NULL && len>0&& id>0&& desc!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(comida[i].id==id)
			{
				strcpy(desc,comida[i].descripcion);
				error=0;
				break;
			}
		}
	}
	return error;
}
