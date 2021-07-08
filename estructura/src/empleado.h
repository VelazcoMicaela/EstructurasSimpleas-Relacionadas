/*
 * empleado.h
 *
 *  Created on: 3 may. 2021
 *      Author: Asus
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct
{
	int legajo;
	char nombre [20];
	int edad;
	char sexo;
	float sueldo;
	eFecha fIngreso;
	int sector;
	int isEmpty;
}eMascota;




void mostrarMascota(eMascota empleado);
int mostrarArrayMascota(eMascota lista[],int len);
int ordenarArrayMascota(eMascota lista[], int len);
int inicializarMascota(eMascota lista[], int len);
int cargarMascota(eMascota lista[], int len,int* pLegajo);
int buscarLibreMascota(eMascota lista[], int len,int* indice);
int bajaMascota(eMascota lista[], int len);
int buscarMascota(eMascota lista[], int len, int* indice, int legajo);
int modificarMascota(eMascota lista[], int len);


int hardcodearMascota(eMascota lista[], int len, int cant, int* pLegajo);
#endif /* EMPLEADO_H_ */
