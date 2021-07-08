/*
 * empleado.h
 *
 *  Created on: 3 may. 2021
 *      Author: Asus
 */

#ifndef MASCOTA_H_
#define MASCOTA_H_
#include "tipo.h"
#include "colores.h"
#include "cliente.h"



typedef struct
{
	int id;
	char nombre [20];
	int idTipo;
	int idColor;
	int idCliente;
	int edad;
	int isEmpty;
}eMascota;



/** \brief imprime el contenido de una mascota con descripciones de tipo y color
 * \param mascota eMascota
 * \param len int
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 * \param eCliente dueno
 * \param lenDueno int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int mostrarMascota(eMascota mascota, eTipo tipo[], int len,eColor color[], int lenCol, eCliente cliente[], int lenCliente);


/** \brief imprime el contenido de una un array de mascota con descripciones de tipo y color
 * \param mascota eMascota
 * \param len int
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int mostrarArrayMascota(eMascota mascota[],int len, eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente);


/** \brief todas las posisiones en isEmty esten en VACIO,
 * \param mascota eMascota
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int inicializarMascota(eMascota mascota[], int len);


/** \brief pone el isEmpty VACIO el indice ingresado por el usuario
 * \param mascota eMascota
 * \param len int
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int bajaMascota(eMascota mascota[], int len, eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente);


/** \brief Ingresa una mascota al array (pone la bandera isEmpty en 1)
 * incrementa el id,
 * \param mascota eMascota
 * \param len int
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 *  \param pLegajo int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int cargarMascota(eMascota mascota[], int len,int* pLegajo, eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente);


/** \brief busca el primer índice libre de la lista,
 * \param mascota eMascota
 * \param len int
 * \param indice int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int buscarLibreMascota(eMascota mascota[], int len,int* indice);


/** \brief busca en la lista de mascota la mascota ingresada por el usuario
 * devolviendola por puntero
 * \param mascota eMascota
 * \param len int
 * \param legajo int
 * \param indice int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int buscarMascota(eMascota mascota[], int len, int* indice, int legajo);



/** \brief busca un empleado por id y modifica los datos que el usuario desee
 * \param mascota eMascota
 * \param len int
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int modificarMascota(eMascota mascota[], int len, eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente);



/** \brief muestra las diferentes opciones para modificar la mascota
 * \param mascota eMascota
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int menuModificacionMascota(eMascota* mascota, eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente);



/** \brief imprime el contenido de una mascota con descripciones de servicio y mascota y el rotulo encima
 * \param mascota eMascota
 * \param len int
 * \param eTipo tipo
 * \param lenTip int
 * \param color eColor
 * \param lenCol int
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int mostrarUnMascotaConRotulo(eMascota mascota, eTipo tipo[], int len,eColor color[], int lenCol, eCliente cliente[],int lenCliente);



/** \brief carga el nombre del id ingresado de la lista mascota
 * \param id int
 * \param mascota eMascota
 * \param len int
 * \param desc char
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int cargarDescripcionMascota(int id, eMascota mascota[], int len, char desc[]);


/** \brief carga un array de 10 mascotas en la lista
 * \param mascota eMascota
 * \param len int
 * \param cant int
 * \param pLegajo int*
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int hardcodearMascota(eMascota mascota[], int len, int cant, int* pLegajo);
#endif /* MASCOTA_H_ */
