/*
 * empleado.h
 *
 *  Created on: 3 may. 2021
 *      Author: Asus
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_
#include "sector.h"
#include "fecha.h"


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




void mostrarMascota(eMascota empleado, eColor sector[], int len);//
int mostrarArrayMascota(eMascota lista[],int len, eColor sector[], int lenSector);
int inicializarMascota(eMascota lista[], int len);
int bajaMascota(eMascota lista[], int len, eColor sector[], int lenSec);
int ordenarArrayMascota(eMascota lista[], int len);
int cargarMascota(eMascota lista[], int len,int* pLegajo, eColor sector[], int lenSector);
int buscarLibreMascota(eMascota lista[], int len,int* indice);

int buscarMascota(eMascota lista[], int len, int* indice, int legajo);
int modificarMascota(eMascota lista[], int len);

int listarEmpleadosColor(eColor sector[], int lenSec, eMascota lista[], int lenEmp);

int cargarNombreEmpleadoEnAlmuerzo(eMascota lista[], int lenEmp, int id, char nombre[]);

int hardcodearMascota(eMascota lista[], int len, int cant, int* pLegajo);
#endif /* EMPLEADO_H_ */
