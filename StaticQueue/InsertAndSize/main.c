#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

void manejarError(int);
void agregarDato(COLA);
void mostrar(COLA);
int tamCola(COLA);

int main(void)
{
	int opc;
	COLA c1;
	crearCola(&c1);
	printf("\t\tMENU:\n");
	printf("   1.- Agregar dato\n   2.- Mostrar tamaño\n   0.-Salir\n");
       	do{
		printf("Ingrese opcion: ");
		scanf("%d",&opc);
		switch(opc)
		{
			case 1:
				agregarDato(c1);
			break;
			case 2:
				mostrar(c1);
			break;
			case 0:
			break;
		}
	}while(opc!=0);
	return 0;
}

void mostrar(COLA c1)
{
	printf("El tamaño de la cola es: %d\n",tamCola(c1));
}

void agregarDato(COLA c1)
{
	int elem;
	printf("Ingrese el elemento: ");
	scanf("%d",&elem);
	encolar(c1,elem);
}

int tamCola(COLA c1)
{
	COLA c2;
	crearCola(&c2);
	int cont=0;
	while(esVaciaCola(c1)==FALSE)
	{
		int aux=desencolar(c1);
		cont++;
		encolar(c2,aux);		
	}
	while(esVaciaCola(c2)==FALSE)
	{
		int aux=desencolar(c2);
		encolar(c1,aux);		
	}
	return cont;
}
void manejarError(int e)
{
	char* errores[]={"No hay memoria disponible","Error la pila esta vacia","Error la pila esta llena","Error division por cero(0)","Error cola llena","Error cola vacia"};
	printf("%s\n",errores[e]);
}
