/*
 * empleado.h
 *
 *  Created on: 14 jun. 2021
 *      Author: Asus
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

typedef struct
{
	int legajo;
	char nombre[20];
	char sexo;
	float sueldo;
}eEmpleado;



int setLegajo (eEmpleado* e, int legajo);
int setNombre (eEmpleado* e, char* nombre);
int setSexo (eEmpleado* e, char sexo);
int setSueldo(eEmpleado* e, float sueldo);

int getLegajo (eEmpleado* e, int* pLegajo);
int getNombre (eEmpleado* e, char* pNombre);
int getSexo (eEmpleado* e, char* pSexo);
int getSueldo(eEmpleado* e, float* pSueldo);
eEmpleado* newConstructorParam(int legajo, char* nombre, char sexo, float sueldo);
eEmpleado* newConstructorParamStr(char* strLegajo, char* strNombre, char* strSexo, char* strSueldo);
eEmpleado* newConstructor();
int mostrarEmpleado(eEmpleado*);
int mostrarArrayEmpleados(eEmpleado** lista, int len);

int agrandarLista(eEmpleado*** vec, int* pTam);


int inicializarEmpleados(eEmpleado** vec, int tam);
int buscarLibre(eEmpleado** vec, int tam, int* pIndice);


int ordenarAlfabeticamenteConAritmetica(eEmpleado** vec, int tam);


#endif /* EMPLEADO_H_ */
