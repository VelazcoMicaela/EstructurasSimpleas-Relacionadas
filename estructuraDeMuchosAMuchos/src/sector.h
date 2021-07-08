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
}eColor;


int cargarDescripcionColor(int id, eColor sectores[], int len, char desc[]);

void mostrarSector(eColor sector);
int mostrarArrayColore(eColor sector[], int len);



#endif /* SECTOR_H_ */
