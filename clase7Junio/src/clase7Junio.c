/*
 ============================================================================
 Name        : clase7Junio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"



typedef struct
{
	int legajo;
	char nombre[20];
	char sexo;
	float sueldo;
}eEmpleado;



int setLegajo (eEmpleado* e, int legajo);
int setNombre (eEmpleado* e, char* nombre);
int setSexo (eEmpleado* e, char sexo);
int setSueldo(eEmpleado* e, float sueldo);

int getLegajo (eEmpleado* e, int* pLegajo);
int getNombre (eEmpleado* e, char* pNombre);
int getSexo (eEmpleado* e, char* pSexo);
int getSueldo(eEmpleado* e, float* pSueldo);
eEmpleado* newConstructorParam(int legajo, char* nombre, char sexo, float sueldo);
eEmpleado* newConstructor();
int mostrarEmpleado(eEmpleado*);
int mostrarArrayEmpleados(eEmpleado** lista, int len);

int agrandarLista(eEmpleado*** vec, int* pTam);


int inicializarEmpleados(eEmpleado** vec, int tam);
int buscarLibre(eEmpleado** vec, int tam, int* pIndice);


int ordenarAlfabeticamenteConAritmetica(eEmpleado** vec, int tam);

int main(void) {
	setbuf(stdout,NULL);
	int tam=10;
	int indice;

	eEmpleado* aux=NULL;


	eEmpleado** lista= (eEmpleado**) malloc (sizeof (eEmpleado*)*tam);

	if(lista==NULL)
	{
		printf("No se encontro lugar\n");
		exit(1);
	}

	if(inicializarEmpleados(lista, tam)==0)
	{
		printf("Inicializacion exitosa\n");
	}

/*	buscarLibre(lista, tam, &indice);
	*(lista+indice)=newConstructorParam(1111, "Fernanda", 'f', 85014.25);

	buscarLibre(lista, tam, &indice);
	*(lista+indice)=newConstructorParam(1222, "Carlos", 'm', 12036.25);

	buscarLibre(lista, tam, &indice);
	*(lista+indice)=newConstructorParam(1333, "Maria", 'f', 52963.25);

	buscarLibre(lista, tam, &indice);

	if(agrandarLista(&lista, &tam)==0)
	{
		printf("Lista redimensionada\n");
		buscarLibre(lista, tam, &indice);
		*(lista+indice)=newConstructorParam(1444, "Felipe", 'm', 30004.25);
		mostrarArrayEmpleados(lista, tam);
	}*/

	FILE* f= fopen("datosEmpleados.bin", "rb");
	if(f==NULL)
	{
		printf("No se pudo abrir\n");
		exit(1);
	}
	printf("Abri el archivo\n");

	int cant;
	do
	{
		buscarLibre(lista, tam, &indice);

		if(indice!=-1)
		{
			aux=newConstructor();

			if(aux!=NULL)
			{
				cant=fread(aux, sizeof(eEmpleado),1, f);
				mostrarEmpleado(aux);
				printf("cant %d\n",cant);

				if(cant==1)
				{
					*(lista+indice)=aux;
				}


			}
		}
		else
		{
			printf("No hay lugar me agrando\n");
			//agrandarLista(&lista, &tam);
		}
	}while(!feof(f));


/*	int flag=0;

	for(int i=0; i<tam; i++)
	{
		if(*(lista+i)!=NULL)
		{
			if(fwrite(*(lista+i), sizeof(eEmpleado), 1, f)<1)
			{
				flag=1;
				break;
			}
		}
	}

	if(flag==1)
	{
		exit(1);
	}
	printf("Guardado con exito\n");
	fclose(f);*/
mostrarArrayEmpleados(lista, tam);



	free(lista);
	free(aux);
	return EXIT_SUCCESS;
}

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

	if(e!=NULL && legajo>1000 && legajo<2000)
	{
		e->legajo=legajo;
		error=0;
	}

	return error;
}

int setNombre (eEmpleado* e, char* nombre)
{
	int error=-1;

	if(e!=NULL && nombre!=NULL && strlen(nombre)<20 && strlen(nombre)>2)
	{
		strcpy( e->nombre, nombre);

		error=0;
	}

	return error;
}

int setSexo (eEmpleado* e, char sexo)
{
	int error=-1;

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

	if(e!=NULL && sueldo>10000 && sueldo<100000)
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

