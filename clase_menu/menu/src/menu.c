/*
 ============================================================================
 Name        : menu.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>


//int TomaDeDatos();


int main(void) {
	setbuf(stdout,NULL);
	
	int primerOperando;
	int opcionesMenu;

	printf("****MENU****\n");
	printf("1-Ingresar 1er operando\n");
	printf("2-Ingresar 2do operando\n");
	printf("3-Calcular todas las operaciones\n");
	printf("4-nformar resultados\n");
	printf("5- Salir\n");
	
	
	
	do
	{
		scanf("%d",&opcionesMenu);
		
		switch(opcionesMenu)
		{
			case '1':
				printf("Ingresar 1er operando\n");
				primerOperando=TomaDeDatos();
				break;
			
			case '2':
				printf("Ingresar 2do operando (B=y)\n");
				break;
			

		}


	}while(opcionesMenu!='5');

	return EXIT_SUCCESS;
}

int TomaDeDatos()
{
	int dato;
	scanf("%d",&dato);
	
	return dato;
}
