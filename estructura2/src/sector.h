/*
 * sector.h
 *
 *  Created on: 4 may. 2021
 *      Author: Asus
 */

#ifndef SECTOR_H_
#define SECTOR_H_
#include "empleado.h"

typedef struct
{
	int id;
	char descripcion[20];
}eTipo;


int cargarDescripcionTipo(int id, eTipo sectores[], int len, char desc[]);

void mostrarTipo(eTipo sector);
int mostrarArrayTipo(eTipo sector[], int len);



#endif /* SECTOR_H_ */
