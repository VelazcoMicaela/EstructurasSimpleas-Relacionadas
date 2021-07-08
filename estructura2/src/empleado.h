/*
 * empleado.h
 *
 *  Created on: 3 may. 2021
 *      Author: Asus
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_
#include "sector.h"

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




void mostrarMascota(eMascota empleado, eTipo sector[], int len);//
int mostrarArrayMascota(eMascota lista[],int len, eTipo sector[], int lenSector);
int inicializarMascota(eMascota lista[], int len);
int bajaMascota(eMascota lista[], int len, eTipo sector[], int lenSec);
int ordenarArrayMascota(eMascota lista[], int len);
int cargarMascota(eMascota lista[], int len,int* pLegajo, eTipo sector[], int lenSector);
int buscarLibreMascota(eMascota lista[], int len,int* indice);

int buscarMascota(eMascota lista[], int len, int* indice, int legajo);
int modificarMascota(eMascota lista[], int len);

int listarMascotaTipo(eTipo sector[], int lenSec, eMascota lista[], int lenEmp);



int hardcodearMascota(eMascota lista[], int len, int cant, int* pLegajo);
#endif /* EMPLEADO_H_ */
