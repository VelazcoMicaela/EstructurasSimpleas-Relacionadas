/*
 * trabajo.h
 *
 *  Created on: 20 may. 2021
 *      Author: Asus
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_
#include "servicio.h"
#include "fecha.h"
#include "mascota.h"
#include "tipo.h"
#include "colores.h"


typedef struct
{
	int id;
	int idMascota;
	int idServicio;
	eFecha fTrab;
	int isEmpty;
}eTrabajo;

/** \brief imprime el contenido de una trabajo con descripciones de servicio y mascota
 * \param trabajo eTrabajo
 * \param eServicio servicio
 * \param lenSer int
 * \param eMascota mascota
 * \param lenMas int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int mostrarTrabajo(eTrabajo trabajo,eServicio servicio[],int lenSer, eMascota mascota[], int lenMas);


/** \brief imprime el contenido de una un array de trabajo con descripciones de tipo y color
 * \param trabajo eTrabajo
 * \param len int
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int mostrarArrayTrabajo(eTrabajo trabajo[],int len, eServicio servicio[],int lenSer, eMascota mascota[], int lenMas);


/** \brief todas las posisiones en isEmty esten en VACIO,
 * \param trabajo eTrabajo
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int inicializarTrabajo(eTrabajo trabajo[], int len);


/** \brief Ingresa una trabajo al array (pone la bandera isEmpty en 1)
 * incrementa el id,
 * \param trabajo eTrabajo
 * \param len int
 * \param eMascota mascota
 * \param lenMas int
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 *  \param pLegajo int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int cargarTrabajo(eTrabajo trabajo[], int len,int* pLegajo, eServicio servicio[],int lenSer, eMascota mascota[], int lenMas, eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente);


/** \brief busca el primer índice libre de la lista,
 * \param trabajo eTrabajo
 * \param len int
 * \param indice int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int buscarLibreTrabajo(eTrabajo trabajo[], int len,int* indice);


/** \brief busca en la lista de trabajo la mascota ingresada por el usuario
 * devolviendola por puntero
 * \param trabajo eTrabajo
 * \param len int
 * \param legajo int
 * \param indice int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int buscarTrabajo(eTrabajo trabajo[], int len, int* indice, int legajo);



/** \brief pone el isEmpty VACIO el indice ingresado por el usuario
 * en la primera posición vacía
 * \param trabajo eTrabajo
 * \param eServicio servicio
 * \param lenSer int
 * \param eMascota mascota
 * \param lenMas int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int bajaTrabajo(eTrabajo trabajo[],int len, eServicio servicio[],int lenSer, eMascota mascota[], int lenMas);


/** \brief imprime el contenido de una trabajo con descripciones de servicio y mascota y el rotulo encima
 * \param trabajo eTrabajo
 * \param eServicio servicio
 * \param lenSer int
 * \param eMascota mascota
 * \param lenMas int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int mostrarUnTrabajoConRotulo(eTrabajo trabajo, eServicio servicio[],int lenSer, eMascota mascota[], int lenMas);

/** \brief carga un array de 10 trabajo en la lista
 * \param trabajo eTrabajo
 * \param len int
 * \param cant int
 * \param pLegajo int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int hardcodearTrabajo(eTrabajo trabajo[], int len, int cant, int* pLegajo);

#endif /* TRABAJO_H_ */
