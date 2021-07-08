/*
 * informes.c
 *
 *  Created on: 10 may. 2021
 *      Author: Asus
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "informes.h"
#include "mascota.h"
#include "tipo.h"
#include "colores.h"
#include "servicio.h"
#include "trabajo.h"
#include "cliente.h"


#define LLENO 0
#define VACIO 1


//mostrar las mascotas del tipo seleccionado
int mostrarTipoDeMascota(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas, eColor color[], int lenCol, eCliente cliente[], int lenCliente)
{
	int error=-1;
	int idTipo;


	if(tipo!=NULL && mascota!=NULL && lenCol>0 && color!=NULL && lenTip>0 && lenMas>0 && cliente>0 && lenCliente>0)
	{
		if(mostrarArrayTipo(tipo, lenTip)==0)
		{
			if(utn_getNumeroEnteroConIntentos(&idTipo, "Ingrese el idTipo de mascota a listar", "ERROR el idTipo tiene q estar entre 1000 y 1004", 1000, 1000+lenTip, 5)==0)
			{
				for(int i=0; i<lenTip; i++)
				{
					if(tipo[i].id== idTipo)
					{
						printf("\nTIPO %s\n",tipo[i].descripcion);
						printf("Id        Nombre  IdTipo  DescTipo  IdColor DescColor Edad\n");
						for(int m=0; m<lenMas; m++)
						{
							if(mascota[m].idTipo== idTipo && mascota[m].isEmpty==LLENO)
							{
								mostrarMascota(mascota[m],tipo, lenTip, color, lenCol, cliente,lenCliente );
								error=0;
							}
						}

						if(error==-1)
						{
							printf("No hay mascota del tipo %s\n",tipo[i].descripcion);
							error=0;
						}
					}
				}
			}
		}


	}

	return error;
}

//mostrar las mascotas del color seleccionado
int mostrarColorDeMascota(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas, eColor color[], int lenCol, eCliente cliente[], int lenCliente)
{
	int error=-1;
	int idColor;


	if(tipo!=NULL && mascota!=NULL && lenCol>0 && color!=NULL && lenTip>0 && lenMas>0 && cliente!=NULL && lenCliente>0)
	{
		if(mostrarArrayColor(color, lenCol)==0)
		{
			if(utn_getNumeroEnteroConIntentos(&idColor, "Ingrese el idColor de mascota a listar", "ERROR el idColor tiene q estar entre 5000 y 5004", 5000, 5000+lenCol, 5)==0)
			{
				for(int i=0; i<lenCol; i++)
				{
					if(color[i].id== idColor)
					{
						printf("\n COLOR %s\n",color[i].descripcion);
						printf("Id        Nombre  IdTipo  DescTipo  IdColor DescColor Edad\n");
						for(int m=0; m<lenMas; m++)
						{
							if(mascota[m].idColor== idColor && mascota[m].isEmpty== LLENO)
							{
								mostrarMascota(mascota[m],tipo, lenTip, color, lenCol,cliente, lenCliente);
								error=0;
							}
						}

						if(error==-1)
						{
							printf("No hay mascota del color %s\n",color[i].descripcion);
							error=0;
						}
					}
				}
			}
		}

	}

	return error;
}


//mostrar TODAS las mascotas del tipo seleccionado
int mostrarTodosTiposDeMascota(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas, eColor color[], int lenCol, eCliente cliente[], int lenCliente)
{
	int error=-1;
	int flag=-1;

	if(tipo!=NULL && mascota!=NULL && lenCol>0 && color!=NULL && lenTip>0 && lenMas>0 && cliente!=NULL && lenCliente>0)
	{
		for(int i=0; i<lenTip; i++)
		{
			printf("\nTIPO %d %s\n",tipo[i].id,tipo[i].descripcion);
			printf("Id        Nombre  IdTipo  DescTipo  IdColor DescColor Edad\n");
			for(int m=0; m<lenMas; m++)
			{
				if(mascota[m].idTipo== tipo[i].id && mascota[m].isEmpty==LLENO)
				{
					mostrarMascota(mascota[m],tipo, lenTip, color, lenCol,cliente, lenCliente);
					flag=0;
				}
			}

			if(flag==-1)
			{
				printf("No hay mascota del tipo %s\n",tipo[i].descripcion);
			}

			flag=-1;
		}
		error=0;
	}

	return error;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
int mostrarTrabajoDeMascotas(eTrabajo trabajo[],int lenTrab, eServicio servicio[],int lenSer, eMascota mascota[], int lenMas, eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente)
{
	int error=-1;
	int idMascota;


	if(trabajo!=NULL && lenTrab>0 && servicio!=NULL&& lenSer>0 && mascota!=NULL&& lenMas>0 && cliente!=NULL && lenCliente>0)
	{
		if(mostrarArrayMascota(mascota, lenMas, tipo, lenTip, color, lenCol,cliente, lenCliente)==0)
		{
			if(utn_getNumeroEnteroConIntentos(&idMascota, "Ingrese el idMascota de trabajo a listar", "ERROR el idMascota tiene q estar entre 4000 y 5000 ", 4000, 4000+lenMas, 5)==0)
			{
				for(int i=0; i<lenMas; i++)
				{
					if(mascota[i].id== idMascota && mascota[i].isEmpty==LLENO)
					{
						printf("\nMASCOTA %s\n",mascota[i].nombre);
						printf(" Id   IdMas     Nombre  IdServ  DescServicio  Fecha\n");
						for(int t=0; t<lenTrab; t++)
						{
							if(trabajo[t].idMascota== idMascota && trabajo[t].isEmpty==LLENO)
							{
								mostrarTrabajo(trabajo[t], servicio, lenSer, mascota, lenMas);
								error=0;
							}
						}

						if(error==-1)
						{
							printf("No hay trabajo con mascota %s\n",mascota[i].nombre);
							error=0;
						}
					}
				}
			}
		}

		error=0;
	}

	return error;
}



///Elegir un color y un tipo y contar cuantas mascotas hay de ese color y ese tipo.
int contadorTipoColorMascota(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas, eColor color[], int lenCol, eCliente cliente[], int lenCliente, int* total)
{
	int error=-1;
	int idColor;
	int idTipo;
	int contador=0;

	if(tipo!=NULL && mascota!=NULL && lenCol>0 && color!=NULL && lenTip>0 && lenMas>0 && cliente!=NULL && lenCliente>0)
	{
		if(mostrarArrayColor(color, lenCol)==0)
		{
			if(utn_getNumeroEnteroConIntentos(&idColor, "Ingrese el idColor", "ERROR el idColor tiene q estar entre 5000 y 5004", 5000, 5000+lenCol, 5)==0)
			{
				if(mostrarArrayTipo(tipo, lenTip)==0)
				{
					if(utn_getNumeroEnteroConIntentos(&idTipo, "Ingrese el idTipo", "ERROR el idTipo tiene q estar entre 1000 y 1005", 1000, 1000+lenTip, 5)==0)
					{
						for(int i=0; i<lenCol; i++)
						{
							if(color[i].id== idColor)
							{
								printf("\n COLOR %s\n",color[i].descripcion);
								for(int t=0; t<lenTip; t++)
								{
									if(tipo[t].id== idTipo)
									{
										printf("\n TIPO %s\n",tipo[t].descripcion);

										printf("Id        Nombre  IdTipo  DescTipo  IdColor DescColor Edad\n");
										for(int m=0; m<lenMas; m++)
										{
											if(mascota[m].idColor== idColor && mascota[m].idTipo== idTipo && mascota[m].isEmpty== LLENO)
											{
												mostrarMascota(mascota[m],tipo, lenTip, color, lenCol,cliente, lenCliente);
												error=0;
												contador++;
											}
										}
									}
								}

								if(error==-1)
								{
									printf("No hay mascota del color %s\n",color[i].descripcion);
									error=0;
								}
							}
						}
					}
				}
			}
		}
		(*total)=contador;
	}

	return error;
}



int mascotaMasJoven(eMascota mascota[], int lenMas, eMascota* masMenor,eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente)
{
	int error=-1;
	float masJoven;
	eMascota aux;
	int flag=0;

	if(mascota!=NULL&& lenMas>0  && tipo!=NULL && lenTip>0 && color!=NULL && lenCol>0 && masMenor!=NULL&& cliente!=NULL && lenCliente>0)
	{
		mostrarArrayMascota(mascota, lenMas, tipo, lenTip, color, lenCol, cliente, lenCliente);
		for(int i=0; i<lenMas; i++)
		{
			if(flag==0 && mascota[i].isEmpty==LLENO)
			{
				masJoven=mascota[i].edad;
				aux=mascota[i];

				flag=1;
			}
			else
			{
				if(masJoven>mascota[i].edad&& mascota[i].isEmpty==LLENO)
				{
					masJoven=mascota[i].edad;
					aux=mascota[i];
				}

				if(masJoven==mascota[i].edad&& mascota[i].isEmpty==LLENO)
				{
					masJoven=mascota[i].edad;
					printf("Las mascotas %s y %s tienen la misma edad %d\n",mascota[i].nombre, aux.nombre, mascota[i].edad);
					aux.edad=-1;
				}
			}
		}
		(*masMenor)=aux;
		error=0;
	}

	return error;
}

//Mostrar el o los colores con mas cantidad de mascotas
int contadorColorMascota(eTipo tipo[], int lenTip, eMascota mascota[], int lenMas, eColor color[], int lenCol, eCliente cliente[], int lenCliente, int* total)
{
	int error=-1;
	int flag=0;
	int contador=0;
	int contadorArray[lenCol];
	int mayorCantidad;

	if(tipo!=NULL && mascota!=NULL && lenCol>0 && color!=NULL && lenTip>0 && lenMas>0)
	{
		for(int i=0; i<lenCol; i++)
		{
			printf("\n COLOR %d %s\n",color[i].id,color[i].descripcion);
			printf("Id        Nombre  IdTipo  DescTipo  IdColor DescColor Edad\n");
			contador=0;
			for(int m=0; m<lenMas; m++)
			{
				if(mascota[m].idColor== color[i].id && mascota[m].isEmpty== LLENO)
				{
					mostrarMascota(mascota[m],tipo, lenTip, color, lenCol,cliente,lenCliente);
					contador++;
				}
				contadorArray[i]=contador;
			}
		}

		for(int i=0;i<lenCol;i++)
		{
			if(flag==0 || mayorCantidad> contadorArray[i])
			{
				mayorCantidad=contadorArray[i];
				flag=1;
			}
			else
			{
				if(mayorCantidad> contadorArray[i])
				{
					mayorCantidad=contadorArray[i];
				}

				if(mayorCantidad== contadorArray[i])
				{

					mayorCantidad=contadorArray[i];
					printf("el color %s tiene %d igual que \n",mascota[i].nombre, mayorCantidad);
					mayorCantidad=-1;
				}
			}
		}
		error=0;
		(*total)=mayorCantidad;
	}

	return error;
}

//promedio de los servicios hechos por mascota
int promedioTrabajosMascota(eTrabajo trabajo[],int lenTrab, eServicio servicio[],int lenSer, eMascota mascota[], int lenMas, eTipo tipo[], int lenTip, eColor color[], int lenCol,eCliente cliente[], int lenCliente, float* total)
{
	int error=-1;
	float acomulador=0;
	//int flag=-1;
	int contador=0;
	int idMascota;

	if(trabajo!=NULL && lenTrab>0 && servicio!=NULL&& lenSer>0 && mascota!=NULL&& lenMas>0 && tipo!=NULL && lenSer>0 && color!=NULL && lenCol>0 && total!=NULL && cliente!=NULL && lenCliente>0)
		{
			if(mostrarArrayMascota(mascota, lenMas, tipo, lenTip, color, lenCol, cliente, lenCliente)==0)
			{
				if(utn_getNumeroEnteroConIntentos(&idMascota, "Ingrese el idMascota de trabajo a listar", "ERROR el idMascota tiene q estar entre 4000 y 5000 ", 4000, 4000+lenMas, 5)==0)
				{
					for(int i=0; i<lenMas; i++)
					{
						if(mascota[i].id== idMascota && mascota[i].isEmpty==LLENO)
						{
							printf("\nMASCOTA %s\n",mascota[i].nombre);
							printf(" Id   IdMas     Nombre  IdServ  DescServicio  Fecha\n");
							for(int t=0; t<lenTrab; t++)
							{
								if(trabajo[t].idMascota== idMascota && trabajo[t].isEmpty==LLENO)
								{
									mostrarTrabajo(trabajo[t], servicio, lenSer, mascota, lenMas);
									for(int s=0; s<lenSer; s++)
									{
										if(trabajo[t].idServicio==servicio[s].id)
										{
											acomulador=acomulador+servicio[s].precio;
											contador++;
										}

									}
									error=0;
								}
							}

							if(error==-1)
							{
								printf("No hay trabajo con mascota %s\n",mascota[i].nombre);
								error=0;
							}
						}
					}
				}
			}

			(*total)=acomulador;
			error=0;
		}

	return error;
}
