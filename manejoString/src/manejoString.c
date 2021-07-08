/*
 ============================================================================
 Name        : manejoString.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int calcularMayor(int num1, int num2, int* pResultado);

int main(void) {
	setbuf(stdout,NULL);

	/*char nombre[11];
	char auxi[300];

	strcpy(nombre,"Juan");
	strcpy(auxi,nombre);//no es seguro xq puede romper

	//COPIA STRING se necesita (variable, variable) de donde va a copiar que, funciona como un = la ,
	//el sizeoff es para q no desborde
	strncpy(auxi,nombre,sizeof(auxi));//se pone el largo asi no rompe de desborde

	printf("copia con strNcpy %s\n",auxi);

	//MIDE CANTIDAD DE CARACTERES
	largoCadena=strlen(auxi); // me devuelve un numero de la cantidad de caracteres
	printf("strNlen mide %s\n",auxi);*/


	//CONCATENA TEXTO
	char nombre[10]="Carlos";
	strcat(nombre," LaLa");
	printf("concatenar strncat  %s\n",nombre);

	/*snprintf(auxi,sizeof(auxi),"Mi texto es esto %d\n",12587);

	Escribir una funcion calcularMayor(), recibe dos num enteros y devuevle x referencia el num mayor
	 * reorna 1 si encontro mayor y 0 si ambos son iguales
	 *
	 *
	int resultado;
	int retorno;

	retorno=calcularMayor(8,8,&resultado);

	switch(retorno)
	{
		case 0:
			printf("Ambos numeros son iguales");
			break;

		case 1:
			printf("El mayor es %d\n",resultado);
			break;

		default:
			printf("Hubo un error");
			break;
	}
	char cadena1[20];

	gets(cadena1);

	printf("%s",cadena1);*/

	/*
	 * registrar el valor de temperatura maxima cada dia de un mes
	 * definir un array de floars de 31 posiciones c/u x dia
	 * menu de 2 opciones
	 * 1 imprimir el array 2 cargar el array
	 * 1-se imprime el indice y valor de c/u
	 * 2- pide al usuario q ingrese el num de dia (1 a 31) y la temperatura
	 * debe volver al menu
	 * utilizar la funcion getnumeroFloat
	 *
	 * */

	return EXIT_SUCCESS;
}

int calcularMayor(int num1, int num2, int* pResultado)
{
	int error=-1;

	if(pResultado!=NULL)
	{
		if(num1>num2)
		{
			*pResultado=num1;
			error=1;
		}else if(num1<num2)
		{
			*pResultado=num2;
			error=1;
		}
		else
		{
			error=0;
		}
	}

	return error;
}
