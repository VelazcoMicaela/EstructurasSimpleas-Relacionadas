/*
 * informes.h
 *
 *  Created on: 10 may. 2021
 *      Author: Asus
 */


#ifndef INFORMES_H_
#define INFORMES_H_

#include "sector.h"
#include "empleado.h"


int recorrerYMostrarListaTipo(eTipo sector[], int lenSec, eMascota lista[], int lenEmp, int id, float* acomulador);
int mostrarTipoYMascota(eTipo sector[], int lenSec, eMascota lista[], int lenEmp);
int totalSueldoTipo(eTipo sector[], int lenSec, eMascota lista[], int lenEmp, float* acomulador);
int sectorMayorSueldo(eTipo sector[], int lenSec, eMascota lista[], int lenEmp);
int totalADepositar(eTipo sector[], int lenSec, eMascota lista[], int lenEmp);


#endif /* INFORMES_H_ */
