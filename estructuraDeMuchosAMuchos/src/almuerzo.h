/*
 * almuerzo.h
 *
 *  Created on: 11 may. 2021
 *      Author: Asus
 */

#ifndef ALMUERZO_H_
#define ALMUERZO_H_

#include "comidas.h"

typedef struct
{
	int id;
	int idComida;
	int legajo;
	eFecha fecha;
	int isEmpty;
}eTrabajo;

#endif /* ALMUERZO_H_ */
/*inicializar *
 * buscar libre*
 * buscar*
 *
 * mostrar almuerzo*
 * mostrar almuerzos*
 */

int inicializarTrabajo(eTrabajo unAlmuerzo[], int len);
int buscarLibreTrabajo(eTrabajo almuerzo[], int len, int* indice);
int buscarTrabajo(eTrabajo unAlmuerzo[], int len, int* pId, int id);
int mostrarArrayTrabajo(eTrabajo almuerzo[], eServicio comida[],int lenAlm, int lenCom, eMascota lista[], int lenEmp);

int cargarTrabajo(eTrabajo lista[], int lenAlm,int* pLegajo, eServicio comida[], int lenComida);
int bajaTrabajo(eTrabajo almuerzo[], int len, eServicio comida[], int lenCom, eMascota lista[], int lenEmp);

int modificarTrabajo(eTrabajo* almuerzo, int len, eServicio comida[], int lenCom, eMascota lista[], int lenEmp);
int menuModificacionAlmuerzo(eTrabajo* almuerzo, eServicio comida[], int lenCom, eMascota lista[], int lenEmp);



int mostrarUnTrabajo(eTrabajo almuerzo, eServicio comida[], int len, eMascota lista[], int lenEmp);


int hardcodearTrabajo(eTrabajo lista[], int len, int cant, int* pLegajo);
