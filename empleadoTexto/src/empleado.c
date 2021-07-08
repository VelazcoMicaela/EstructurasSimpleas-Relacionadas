/*
 * empleado.c
 *
 *  Created on: 14 jun. 2021
 *      Author: Asus
 */
#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"
#include <string.h>
#include <ctype.h>
#include "utn.h"

int agrandarLista(eEmpleado*** vec, int* pTam)
{
	int error=-1;
	eEmpleado** aux=NULL;
	int tam;

	if(vec!=NULL && pTam!=NULL)
	{
		tam=*pTam+1;
		aux=(eEmpleado**) realloc(*vec, sizeof(eEmpleado*)*tam);
		if(aux!=NULL)
		{
			*vec= aux;
			*pTam=tam;
			aux=NULL;
			*(*vec+tam-1)=NULL;
			error=0;
		}

	}

	return error;

}
int ordenarAlfabeticamenteConAritmetica(eEmpleado** vec, int tam)
{
	int error=-1;
	eEmpleado* aux=NULL;

	if(vec!=NULL && tam>0)
	{

		for(int i=0; i<tam-1; i++)
		{
			for(int j=i+1; j<tam; j++)
			{
				if( strcmp( (*(vec+i))->nombre , (*(vec+j))->nombre)<0)
				{
					aux= *(vec+i);
					*(vec+i)= *(vec+j);
					*(vec+j)= aux;
				}
			}
		}
		aux=NULL;
		error=0;
	}

	return error;
}

int inicializarEmpleados(eEmpleado** vec, int tam)
{
	int error=-1;

	if(vec!=NULL && tam>0)
	{
		for(int i=0; i<tam; i++)
		{
			*(vec+i)=NULL;
		}
		error=0;
	}

	return error;
}

int buscarLibre(eEmpleado** vec, int tam, int* pIndice)
{
	int error=-1;

	if(pIndice!=NULL && vec!=NULL && tam>0)
	{
		*pIndice=-1;
		for(int i=0; i<tam; i++)
		{
			if(*(vec+i)==NULL)
			{
				*pIndice=i;
				break;
			}
		}
		error=0;
	}

	return error;
}
int setLegajo (eEmpleado* e, int legajo)
{
	int error=-1;

	if(e!=NULL && legajo>0 && legajo<1000)
	{
		e->legajo=legajo;
		error=0;
	}

	return error;
}

int setNombre (eEmpleado* e, char* nombre)
{
	int error=-1;

	if(e!=NULL && nombre!=NULL && strlen(nombre)<100 && strlen(nombre)>2)
	{
		strcpy( e->nombre, nombre);

		error=0;
	}

	return error;
}
int setSexo (eEmpleado* e, char sexo)
{
	int error=-1;
	sexo=tolower(sexo);

	if(e!=NULL &&  (sexo=='m' || sexo=='f'))
	{
		e->sexo=sexo;
		error=0;
	}

	return error;
}
int setSueldo(eEmpleado* e, float sueldo)
{
	int error=-1;

	if(e!=NULL && sueldo>100 && sueldo<100000)
	{
		e->sueldo=sueldo;

		error=0;
	}

	return error;
}
int getLegajo (eEmpleado* e, int* pLegajo)
{
	int error=-1;
	if(e!=NULL && pLegajo!=NULL)
	{
		*pLegajo= e->legajo;
		error=0;
	}

	return error;
}
int getNombre (eEmpleado* e, char* pNombre)
{
	int error=-1;
	if(e!=NULL && pNombre!=NULL)
		{
			strcpy( pNombre, e->nombre);
			error=0;
		}

	return error;
}
int getSexo (eEmpleado* e, char* pSexo)
{
	int error=-1;
	if(e!=NULL && pSexo!=NULL)
	{
		*pSexo= e->sexo;
		error=0;
	}

	return error;
}
int getSueldo(eEmpleado* e, float* pSueldo)
{
	int error=-1;
	if(e!=NULL && pSueldo!=NULL)
	{
		*pSueldo= e->sueldo;
		error=0;
	}

	return error;
}

eEmpleado* newConstructorParam(int legajo, char* nombre, char sexo, float sueldo)
{
	eEmpleado* aux;

	aux=newConstructor();

	if(aux!=NULL)
	{
		if(!(setLegajo(aux, legajo)==0 &&
			setNombre(aux, nombre)==0 &&
			setSexo(aux, sexo)==0 &&
			setSueldo(aux, sueldo)==0) )
		{
			free(aux);
			aux=NULL;
		}


	}
	return aux;
}

eEmpleado* newConstructorParamStr(char* strLegajo, char* strNombre, char* strSexo, char* strSueldo)
{
	eEmpleado* aux;

	aux=newConstructor();

	if(aux!=NULL)
	{
		if(!(setLegajo(aux, atoi(strLegajo))==0 &&
			setNombre(aux, strNombre)==0 &&
			setSexo(aux, strSexo[0])==0 &&
			setSueldo(aux, atof(strSueldo))==0) )
		{
			free(aux);
			aux=NULL;
		}


	}
	return aux;
}

eEmpleado* newConstructor()
{
	eEmpleado* estructura;

	estructura= (eEmpleado*) malloc (sizeof(eEmpleado));
	if(estructura!=NULL)
	{
		//estructura= (eEmpleado*) calloc (1,sizeof(eEmpleado));
		estructura->legajo=0;
		strcpy( estructura->nombre, " ");
		estructura->sexo=' ';
		estructura->sueldo=0;
	}


	return estructura;
}

int mostrarEmpleado(eEmpleado* emp)
{
	int error=-1;

	int legajo;
	char nombre[20];
	char sexo;
	float sueldo;

	if(emp!= NULL)
	{
		if(getLegajo(emp, &legajo)==0 &&
			getNombre(emp, nombre)==0 &&
			getSexo(emp, &sexo)==0 &&
			getSueldo(emp, &sueldo)==0 )
		{
			printf(" %d %10s  %c   %.2f\n",
				legajo, nombre, sexo, sueldo);
		}

		error=0;
	}

	return error;

}

int mostrarArrayEmpleados(eEmpleado** lista, int len)
{
	int error=-1;

	if(lista!= NULL && len>0)
	{
		printf("Legajo    Nombre Sexo Sueldo\n");
		for(int i=0; i<len; i++)
		{
			mostrarEmpleado(*(lista+i));
		}

		error=0;
	}

	return error;

}
