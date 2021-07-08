/*
 * comidas.h
 *
 *  Created on: 11 may. 2021
 *      Author: Asus
 */

#ifndef COMIDAS_H_
#define COMIDAS_H_

/*mostrar comida*
mostrar array comida*
alta almuerzo- lista de comida y meto el id de la comida, muestra los empleados y meto el legajo en el q se cargue  y cargar la fecha
*/
typedef struct
{
	int id;//1000
	char descripcion[20];
	float precio;
}eServicio;


int mostrarTipo(eServicio comida);
int mostrarArrayTipo(eServicio comida[], int len);

int cargarDescripcionTipo(eServicio comida[], int len,int id, char desc[]);

#endif /* COMIDAS_H_ */
