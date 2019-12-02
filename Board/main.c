#include <stdio.h>
#include "tablero.h"
#include <string.h>

void manejarError(int);
void leerDim(int*,int*);
void darMovi(tablero);
tablero darCoorObst(tablero);
void mostrar(int);

void main()
{
	tablero t;
	int fil,col;
	leerDim(&fil,&col);
	t=crearTabla(fil,col);
	t=darCoorObst(t);
	darMovi(t);
}

void leerDim(int* f, int*c)
{
	printf("Introduzca el numero de filas: ");
	scanf("%d",f);
	printf("Introduzca el numero de columnas: ");
	scanf("%d",c);
}

void darMovi(tablero t)
{
	int i,j, rsp;
	char* direccion;
	do{
		printf("Introduzca la fila de la pieza a mover: ");
		scanf("%d",&i);
		printf("Introduzca la columna de la pieza a mover: ");
		scanf("%d",&j);
		getchar();
		printf("Introduzca la direccion: ");
		scanf("%s",direccion);
		if(strcmp(direccion,"arriba"))
		{
			if(i-1<0)
			{
				rsp=esPosibleMover(t,tamFila(t)-1,j);
			}else{
				rsp=esPosibleMover(t,i-1,j);
			}
		}else if(strcmp(direccion,"abajo"))
		{
			if(i+1>tamFila(t)-1)
			{
				rsp=esPosibleMover(t,0,j);
			}else{
				rsp=esPosibleMover(t,i+1,j);
			}
		}else if(strcmp(direccion,"izquierda"))
		{
			if(j-1<0)
			{
				rsp=esPosibleMover(t,i,tamColum(t)-1);
			}else{
				rsp=esPosibleMover(t,i,j-1);
			}
		}else if(strcmp(direccion,"derecha"))
		{
			if(j+1>tamColum(t))
			{
				rsp=esPosibleMover(t,i,0);
			}else{
				rsp=esPosibleMover(t,i,j+1);
			}
		}
		mostrar(rsp);
	}while(rsp!=1);
}

tablero darCoorObst(tablero t)
{
	int k,i,j,n;
	printf("Introduzca el numero de obstaculos: ");
	scanf("%d",&n);
	for(k=0;k<n;k++)
	{
		printf("Introduzca la fila del obstaculo: ");
		scanf("%d",&i);
		printf("Introduzca la columna del obstaculo: ");
		scanf("%d",&j);
		t=iniciaObstaculo(t,i,j);
	}
	return t;
}

void mostrar(int opc)
{
	if(opc==0)
	{
		printf("No es posible moverse\n");
	}else{
		printf("Fue posible moverse\n");
	}
}

void manejarError(int e)
{
	char* errores[]={"No hay memoria disponible!"};
	printf("%s",errores[e]);
}
