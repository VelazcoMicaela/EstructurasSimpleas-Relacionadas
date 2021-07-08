/*
 * dueno.h
 *
 *  Created on: 25 may. 2021
 *      Author: Asus
 *      campo id, nombre, sexo.
 *
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
	int id;
	char nombre[20];
	char sexo;
}eCliente;

int cargarDescripcionCliente(int id, eCliente dueno[], int len, char desc[]);

void mostrarCliente(eCliente dueno);

int mostrarArrayCliente(eCliente dueno[], int len);


#endif /* CLIENTE_H_ */
