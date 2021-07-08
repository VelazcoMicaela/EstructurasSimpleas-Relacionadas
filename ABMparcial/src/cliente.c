/*
 * dueño.c
 *
 *  Created on: 25 may. 2021
 *      Author: Asus
 */
#include "cliente.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"

int cargarDescripcionCliente(int id, eCliente cliente[], int len, char desc[])
{
	int error=-1;

	if(cliente!=NULL && len>0&& id>0&& desc!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(cliente[i].id==id)
			{
				strcpy(desc,cliente[i].nombre);
				error=0;
				break;
			}
		}
	}
	return error;
}

void mostrarCliente(eCliente cliente)
{
	printf(" %d    %10s %c\n",cliente.id, cliente.nombre, cliente.sexo);
}


int mostrarArrayCliente(eCliente cliente[], int len)
{
	int error=-1;

	if(cliente!=NULL&& len>0)
	{
		printf(" IdCliente  Nombre sexo\n");
		for(int i=0; i<len; i++)
		{
			mostrarCliente(cliente[i]);
		}
		error=0;
	}

	return error;
}
