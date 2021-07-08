/*
 * sector.h
 *
 *  Created on: 4 may. 2021
 *      Author: Asus
 */

#ifndef TIPO_H_
#define TIPO_H_
#include "mascota.h"

typedef struct
{
	int id;
	char descripcion[20];
}eTipo;


/** \brief carga la descripcion del id ingresado de la lista tipo
 * \param id int
 * \param tipo eTipo
 * \param len int
 * \param desc char
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int cargarDescripcionTipo(int id, eTipo tipo[], int len, char desc[]);


/** \brief imprime el contenido de un tipo
 * \param tipo eTipo
 * \return void
 *
 */
void mostrarTipo(eTipo tipo);


/** \brief imprime el contenido de una un array de tipo
 * \param tipo eTipo
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int mostrarArrayTipo(eTipo tipo[], int len);



#endif /* TIPO_H_ */
