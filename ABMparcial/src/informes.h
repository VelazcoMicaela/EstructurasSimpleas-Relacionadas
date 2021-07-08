/*
 * informes.h
 *
 *  Created on: 10 may. 2021
 *      Author: Asus
 */


#ifndef INFORMES_H_
#define INFORMES_H_


#include "servicio.h"
#include "mascota.h"
#include "tipo.h"
#include "colores.h"
#include "trabajo.h"
#include "cliente.h"

/** \brief imprime el listado de mascota elegido por el usuario por tipo
 * \param mascota eMascota
 * \param lenMas int
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int mostrarTipoDeMascota(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas, eColor color[], int lenCol, eCliente cliente[], int lenCliente);////mostrarTipoDeMascota


/* \brief imprime el listado de mascota elegido por el usuario por color
 * \param mascota eMascota
 * \param lenMas int
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int mostrarColorDeMascota(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas, eColor color[], int lenCol, eCliente cliente[], int lenCliente);////mostrarColorDeMascota


/** \brief imprime el listado de mascota por tipos
 * \param mascota eMascota
 * \param lenMas int
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int mostrarTodosTiposDeMascota(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas, eColor color[], int lenCol,eCliente cliente[], int lenCliente);//mostrarTodosTiposDeMascota


int mostrarTrabajoDeMascotas(eTrabajo trabajo[],int lenTrab, eServicio servicio[],int lenSer, eMascota mascota[], int lenMas, eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente);

int mascotaMasJoven(eMascota mascota[], int lenMas, eMascota* masMenor,eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente);


int contadorTipoColorMascota(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas, eColor color[], int lenCol, eCliente cliente[], int lenCliente, int* total);

/*\brief Busca el servicio mas barato, devuelve por la estructura servMenor el servicios más baratos ne caso de haber dos devuelve -1 en el precio de la misma
 * \param eServicio servicio
 * \param lenSer int
 * \param leServicio* servMenor
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int contadorColorMascota(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas, eColor color[], int lenCol, eCliente cliente[], int lenCliente, int* total);


/*- Pedir una mascota e informar la suma de los trabajos le hicieron a la
misma*/

/** \brief imprime el listado de trabajo por mascotas que el usuario ingrese devolviendo el total y promedio de las mismas
 * \param trabajo eTrabajo
 * \param lenTrab int
 * \param eServicio servicio
 * \param lenSer int
 * \param eMascota mascota
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 * \param float* total
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int promedioTrabajosMascota(eTrabajo trabajo[],int lenTrab, eServicio servicio[],int lenSer, eMascota mascota[], int lenMas, eTipo tipo[], int lenTip, eColor color[], int lenCol,eCliente cliente[], int lenCliente, float* total);



#endif /* INFORMES_H_ */
