/*
 ============================================================================
 Name        : empleadoTexto.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "empleado.h"
#include "utn.h"

int main(void) {
	int tam=1;
	int auxInt;
	char auxCad[100];
	char auxChar;
	float auxFloat;
	int cant;
	eEmpleado* aux=NULL;
	int indice;
	int flag=0;//son los errores

	char buffer[4][20];


	eEmpleado** lista= (eEmpleado**) malloc(sizeof(eEmpleado*)*tam);
	if(lista==NULL)
	{
		printf("No se encontro lugar\n");
		exit(1);
	}

	if(inicializarEmpleados(lista, tam)==0)
	{
		printf("Inicializacion exitosa\n");
	}

	FILE* f= fopen("listaEmpleados2.csv","r");//lectura, no crea solo lee

	if(f==NULL)
	{
		printf("No se abrio el archivo\n");
		exit(1);
	}

//	fscanf(f,"%s",auxCad);//lectura fantasma para saltar el encabezado

	cant=fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
	while(!feof(f))//itero sobre cada renglon del archivo csv
	{
		buscarLibre(lista, tam, &indice);
		if(indice==-1)
		{
			if(agrandarLista(&lista, &tam)!=0)
			{
				flag=1;
				break;//hubo un problemapara conseguir lugar
			}
		}
		else
		{//leo y parseo una fila del archivo
			//cant=fscanf(f,"%d,%[^,],%c,%f\n",&auxInt,auxCad,&auxChar,&auxFloat);
			cant=fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

			if(cant==4)
			{//si la lectura fue exitosa creo un empleado con el constructor
				//aux=newConstructorParam(auxInt, auxCad, tolower(auxChar), auxFloat);
				aux=newConstructorParamStr(buffer[0],buffer[1],buffer[2],buffer[3]);

				if(aux!=NULL)
				{
					*(lista+indice)=aux;
					aux=NULL;
				}
				else
				{
					flag=2;
					break;//hubo un problema para conseguir empleado
				}
			}
			else
			{
				flag=3;// hubo error en el parseo
				break;
			}
		}
	}

	if(flag==0)
	{
		printf("Empleados cargados exitosamente\n");
	}
	else if(flag==1)
	{
		printf("ERROR hubo un problema para conseguir lugar\n");
	}
	else if(flag==2)
	{
		printf("ERROR hubo un problema para conseguir empleado\n");
	}
	else if(flag==3)
	{
		printf("ERROR hubo problema en el parseo\n");
	}

	mostrarArrayEmpleados(lista, tam);
///guardo los empleaos en un archivo de texto

	/*f=fopen("listaEmpleados2.csv", "w");

	if(f==NULL)
	{
		printf("No se abrio el archivo\n");
		exit(1);
	}

	fprintf(f,"Legajo,Nombre,Sexo,Sueldo\n");

	for(int i=0; i<tam; i++)
	{
		aux=*(lista+i);
		if(aux!=NULL)
		{
			fprintf(f,"%d,%s,%c,%.2f\n",
					aux->legajo,
					aux->nombre,
					aux->sexo,
					aux->sueldo);
		}
	}
*/

	fclose(f);

	free(lista);
	return EXIT_SUCCESS;
}
