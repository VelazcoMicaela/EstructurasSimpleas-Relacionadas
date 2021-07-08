/*
 * colores.h
 *
 *  Created on: 19 may. 2021
 *      Author: Asus
 */

#ifndef COLORES_H_
#define COLORES_H_

#include "mascota.h"

typedef struct
{
	int id;//5000
	char descripcion[20];
}eColor;


/** \brief carga la descripcion del id ingresado de la lista color
 * \param id int
 * \param color eColor
 * \param len int
 * \param desc char
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int cargarDescripcionColor(int id, eColor color[], int len, char desc[]);


/** \brief imprime el contenido de un color
 * \param color eColor
 * \return void
 *
 */
void mostrarColor(eColor color);


/** \brief imprime el contenido de una un array de color
 * \param color eColor
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int mostrarArrayColor(eColor color[], int len);



#endif /* COLORES_H_ */
