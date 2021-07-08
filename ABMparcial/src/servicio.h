/*
 * servicio.h
 *
 *  Created on: 20 may. 2021
 *      Author: Asus
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct
{
	int id;
	char descripcion[20];
	float precio;
}eServicio;


/** \brief carga la descripcion del id ingresado de la lista servicio
 * \param id int
 * \param servicio eServicio
 * \param len int
 * \param desc char
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int cargarDescripcionServicio(int id, eServicio servicio[], int len, char desc[]);


/** \brief imprime el contenido de un servicio
 * \param servicio eServicio
 * \return void
 *
 */
void mostrarServicio(eServicio servicio);


/** \brief imprime el contenido de una un array de servicio
 * \param servicio eServicio
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int mostrarArrayServicio(eServicio servicio[], int len);

#endif /* SERVICIO_H_ */
