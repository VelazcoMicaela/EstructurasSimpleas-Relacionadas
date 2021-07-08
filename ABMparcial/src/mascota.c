/*
 * empleado.c
 *
 *  Created on: 3 may. 2021
 *      Author: Asus
 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utn.h"
#include "mascota.h"

#include "cliente.h"
#include "tipo.h"
#include "informes.h"
#include "colores.h"




#define LLENO 0
#define VACIO 1


int mostrarMascota(eMascota mascota, eTipo tipo[], int len,eColor color[], int lenCol, eCliente cliente[], int lenCliente)//
{
	int error=-1;
	char descTip[20];
	char descCol[20];
	char descCliente[20];

	if(tipo!=NULL&& len>0 && color!=NULL&& lenCol>0 && cliente!=NULL&& lenCliente>0)
	{
		if(cargarDescripcionTipo(mascota.idTipo, tipo,len, descTip)==0)
		{
			if(cargarDescripcionColor(mascota.idColor, color, lenCol, descCol)==0)
			{
				if(cargarDescripcionCliente(mascota.idCliente, cliente, len, descCliente)==0)
				printf("%5d  %10s   %d  %10s   %d %10s  %d %10s %d\n",mascota.id,
				mascota.nombre, mascota.idTipo, descTip, mascota.idColor,descCol, mascota.idCliente,descCliente,
				mascota.edad);
			}
		}
		error=0;
	}

	return error;

}

int mostrarArrayMascota(eMascota mascota[],int len, eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente)
{
	int error=-1;
	int flag=0;

	if(mascota!=NULL&& len>0&& tipo!=NULL&& lenTip>0 && color!=NULL&& lenCol>0 && cliente!=NULL&& lenCliente>0)
	{
		printf("\n Id        Nombre  IdTipo  DescTipo  IdColor DescColor IdDueno DescDueno Edad\n");
		for(int i=0; i<len; i++)
		{
			if(mascota[i].isEmpty==LLENO)
			{
				mostrarMascota(mascota[i],tipo,lenTip,color, lenCol, cliente, lenCliente);
				flag=1;
			}
		}

		if(flag!=1)
		{
			printf("NO HAY MASCOTAS PARA MOSTRAR\n");
		}
		error=0;
	}
	return error;
}

int inicializarMascota(eMascota mascota[], int len)
{
	int error=-1;

	if(mascota!=NULL&&len>0)
	{
		for(int i=0; i<len; i++)
		{
			mascota[i].isEmpty=VACIO;
		}
		error=0;
	}

	return error;
}

int cargarMascota(eMascota mascota[], int len,int* pLegajo, eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente )
{
	int error=-1;
	int indice;
	char respuesta;
	eMascota aux;

	if(mascota!=NULL && pLegajo!=NULL && len>0 && tipo!=NULL && lenTip>0 && color!=NULL && lenCol>0  && cliente!=NULL&& lenCliente>0)
	{

		while(respuesta!='n')
		{
			if(buscarLibreMascota(mascota, len, &indice)==0)
			{
				printf("Legajo %d\n",*pLegajo);
				if(utn_getString(aux.nombre, "Ingrese nombre", "ERROR reingrese nombre", 5)==0)
				{
					if(mostrarArrayTipo(tipo, lenTip)==0)
					{
						if(utn_getNumeroEnteroConIntentos(&aux.idTipo, "Ingrese IdTipo ", "ERROR Reingrese IdTipo entre 1000 y 1004 ", 1000, 1004, 5)==0)
						{
							if(mostrarArrayColor(color, lenCol)==0)
							{
								if(utn_getNumeroEnteroConIntentos(&aux.idColor, "Ingrese idColor", "ERROR Reingrese idColor entre 5000 y 5004 ", 5000, 5004, 5)==0)
								{
									if(mostrarArrayCliente(cliente, lenCliente)==0)
									{
										if(utn_getNumeroEnteroConIntentos(&aux.idCliente, "Ingrese idCliente", "ERROR Reingrese idCliente entre 500 y 502 ", 500, 500+lenCliente, 5)==0)
										{
											if(utn_getNumeroEnteroConIntentos(&aux.edad, "Ingrese edad ", "ERROR Reingrese edad 0 y 100", 0, 100, 5)==0)
											{
												aux.isEmpty=0;
												mascota[indice]=aux;
												mascota[indice].id=*pLegajo;
												(*pLegajo)++;
												error=0;
											}
										}
									}

								}
							}
						}
					}
				}
			}
			else
			{
				printf("No hay lugar\n");
				break;
			}
			if(utn_getCaracterCorroboraDosCarac(&respuesta, "Desea seguir ingresando mascotas? s-n ", "ERROR reingrese s-n ", 's', 'n')==0)
			{
				printf("\n");
			}
		}
	}

	return error;
}

int bajaMascota(eMascota mascota[], int len, eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente)
{
	int error=-1;
	int legajo;
	int indice;
	char eliminar;

	if(mascota!=NULL && len>0 && tipo!=NULL && lenTip>0 && color!=NULL && lenCol>0  && cliente!=NULL&& lenCliente>0)
	{
		mostrarArrayMascota(mascota, len,tipo,lenTip,color, lenCol, cliente,lenCliente );
		if(utn_getNumeroEnteroConIntentos(&legajo, "Ingrese id a dar de baja", "ERROR Reingrese id entre 4000 y 5000 ", 4000, 4000+len, 5)==0)
		{
			if(buscarMascota(mascota, len, &indice, legajo)==0)
			{
				mostrarUnMascotaConRotulo(mascota[indice], tipo, lenTip, color, lenCol, cliente,lenCliente);
				if(utn_getCaracterCorroboraDosCarac(&eliminar, "Desea eliminar? S/N\n", "ERROR Ingrese S para eliminar o N para volver", 's', 'n')==0)
				{
					if(eliminar=='s')
					{
						mascota[indice].isEmpty=VACIO;
						error=0;
					}
					else
					{
						printf("Baja cancelada por el usuario\n");
					}
				}
			}
			else
			{
				printf("No hay empleado con legajo %d \n",legajo);
			}
		}

	}

	return error;
}

int buscarMascota(eMascota mascota[], int len, int* indice, int legajo)
{
	int error=-1;

	if(mascota!=NULL&& len>0&& indice!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(mascota[i].id==legajo && mascota[i].isEmpty==LLENO)
			{
				*indice=i;
				error=0;
				break;
			}
		}
	}

	return error;
}

int buscarLibreMascota(eMascota mascota[], int len,int* indice)
{
	int error=-1;

	if(mascota!=NULL&& indice!=NULL&& len>0)
	{
		for(int i=0; i<len; i++)
		{
			if(mascota[i].isEmpty==VACIO)
			{
				*indice=i;
				error=0;
				break;
			}
		}

	}
	return error;
}


int modificarMascota(eMascota mascota[], int len, eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente )
{
	int error=-1;
	int id;
	int indice;

	if(mascota!=NULL && len>0 && tipo!=NULL && lenTip>0 && color!=NULL && lenCol>0 && cliente!=NULL && lenCliente>0)
	{
		if(mostrarArrayMascota(mascota, len, tipo, lenTip, color, lenCol, cliente,lenCliente)==0 &&
				utn_getNumeroEnteroConIntentos(&id, "Ingrese el id a modificar ", "ERROR id debe esta entre 4000 a 5000. Reingrese ", 4000, 4000+len, 5)==0 &&
				buscarMascota(mascota, len, &indice, id)==0)
		{
			mostrarUnMascotaConRotulo(mascota[indice], tipo, lenTip, color, lenCol, cliente,lenCliente);

			if(menuModificacionMascota(&mascota[indice], tipo, lenTip, color, lenCol, cliente,lenCliente)==0)
			{
				error=0;
			}
		}
	}

	return error;
}

int menuModificacionMascota(eMascota* mascota, eTipo tipo[], int lenTip, eColor color[], int lenCol, eCliente cliente[], int lenCliente)
{
	int error=-1;
	int opcion;
	char salir;
	eMascota aux;
	eMascota cancelacion;

	cancelacion=*mascota;

	if(mascota!=NULL && tipo!=NULL && lenTip>0 && color!=NULL && lenCol>0 && cliente!=NULL && lenCliente>0)
	{
		do
		{
			if(utn_getNumeroEnteroConIntentos(&opcion, "\nQue desea modificar? \n 1. IDTIPO\n 2. IDCOLOR\n 3. NOMBRE\n 4. EDAD\n 5. GUARDAR ", "ERROR reingrese una opcion ", 1, 5, 5)==0)
			{
				switch(opcion)
				{
					case 1:
						printf("---------------IDTIPO---------------\n");
						if(mostrarArrayTipo(tipo, lenTip)==0)
						{
							if(utn_getNumeroEnteroConIntentos(&aux.idTipo, "\nIngrese IdTipo ", "ERROR Reingrese IdTipo entre 1000 y 1004 ", 1000, 1000+lenTip, 5)==0)
							{
								(*mascota).idTipo=aux.idTipo;

								mostrarUnMascotaConRotulo(*mascota, tipo, lenTip, color, lenCol, cliente,lenCliente);
							}
						}
						break;

					case 2:
						printf("---------------IDCOLOR---------------\n");
						if(mostrarArrayColor(color, lenCol)==0)
						{
							if(utn_getNumeroEnteroConIntentos(&aux.idColor, "Ingrese idColor", "ERROR Reingrese idColor entre 5000 y 5004 ", 5000, 5000+lenCol, 5)==0)
							{
								(*mascota).idColor=aux.idColor;

								mostrarUnMascotaConRotulo(*mascota, tipo, lenTip, color, lenCol, cliente,lenCliente);
							}
						}
						break;

					case 3:
						printf("---------------NOMBRE---------------\n");
						if(utn_getString(aux.nombre, "Ingrese nombre", "ERROR reingrese nombre", 5)==0)
						{
							strcpy((*mascota).nombre,aux.nombre);

							mostrarUnMascotaConRotulo(*mascota, tipo, lenTip, color, lenCol, cliente,lenCliente);
						}
						break;

					case 4:
						printf("---------------EDAD---------------\n");
						if(utn_getNumeroEnteroConIntentos(&aux.edad, "Ingrese edad ", "ERROR Reingrese edad 0 y 100", 0, 100, 5)==0)
						{
							(*mascota).edad=aux.edad;

							mostrarUnMascotaConRotulo(*mascota, tipo, lenTip, color, lenCol, cliente,lenCliente);
						}
						break;

					case 5:
						printf("---------------GUARDAR---------------\n");

						mostrarUnMascotaConRotulo(*mascota, tipo, lenTip, color, lenCol, cliente,lenCliente);

						if(utn_getCaracterCorroboraDosCarac(&salir, "Desea guardar los cambios? S/N ", "ERROR reingrese S/N ", 's', 'n')==0)
						{
							if(salir=='n')
							{
								printf("Modificacion cancelada\n");
								(*mascota)=cancelacion;
								error=1;
							}
							else
							{
								error=0;
							}

						}
						break;
				}
			}
		}while(error<0);
	}

	return error;
}


int mostrarUnMascotaConRotulo(eMascota mascota, eTipo tipo[], int len,eColor color[], int lenCol, eCliente cliente[],int lenCliente)
{
	int error=-1;
	if(tipo!=NULL && len>0 && color!=NULL && lenCol>0 && cliente!=NULL && lenCliente>0)
	{
		printf("\n Id        Nombre  IdTipo  DescTipo  IdColor DescColor Edad\n");
		mostrarMascota(mascota,tipo,len,color, lenCol, cliente,lenCliente);
		printf("-------------------------------------------------------\n");
		error=0;
	}

	return error;
}

int cargarDescripcionMascota(int id, eMascota mascota[], int len, char desc[])
{
	int error=-1;

	if(mascota!=NULL && len>0&& id>0&& desc!=NULL)
	{
		for(int i=0; i<len; i++)
		{
			if(mascota[i].id==id)
			{
				strcpy(desc,mascota[i].nombre);
				error=0;
				break;
			}
		}
	}
	return error;
}


int hardcodearMascota(eMascota mascota[], int len, int cant, int* pLegajo)
{
	int cantidad=0;

	eMascota mascota2[10]=
	{
			{0,"Donato",1000,5000,500,1,0},
			{0,"Carmen",1000,5001,501,2,0},
			{0,"Chepi",1003,5002,502,3,0},
			{0,"Alex",1003,5003,500,4,0},
			{0,"German",1004,5004,501,5,0},
			{0,"Maria",1000,5000,502,1,0},
			{0,"Daniel",1001,5001,500,2,0},
			{0,"Andrea",1002,5002,501,3,0},
			{0,"Candela",1003,5003,502,4,0},
			{0,"Magdalena",1004,5004,500,5,0},
	};

	if(mascota!=NULL&& mascota2!=NULL&& len>0 && cant>=0 && cant<=len && pLegajo!=NULL)
	{
		for(int i=0; i<cant; i++)
		{
			mascota[i]=mascota2[i];

			mascota[i].id=*pLegajo;
			(*pLegajo)++;

			cantidad++;
		}
	}

	return cantidad;
}
