#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

void manejarError(int);
void solicitarDatos(int*);
COLA mostrarCola(COLA);

int main(void)
{
	char opc;
	COLA c1;
	crearCola(&c1);
       	do{
		printf("¿quiere ingresar un elemento? S/N: ");
		scanf("%c",&opc);
		getchar();
		if(opc=='S')
		{
			int x;
			solicitarDatos(&x);
			encolar(c1,x);
			getchar();
		}
		c1= mostrarCola(c1);
	}while(opc!='N');
	return 0;
}

COLA mostrarCola(COLA c1)
{
	COLA c2;
	crearCola(&c2);
	printf("Elementos de la cola:\n");
	while(esVaciaCola(c1)==FALSE)
	{
		int aux=desencolar(c1);
		printf("%d ",aux);
		encolar(c2,aux);		
	}
	printf("\n");
	return c2;
}

void solicitarDatos(int* elem)
{
	printf("Ingrese el elemento: ");
	scanf("%d",elem);
}

void manejarError(int e)
{
	char* errores[]={"No hay memoria disponible","Error la pila esta vacia","Error la pila esta llena","Error division por cero(0)","Error cola llena","Error cola vacia"};
	printf("%s\n",errores[e]);
}
