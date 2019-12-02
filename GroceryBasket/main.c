#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pila.h"

void manejaError(int);
void solicitar(PILA);
void mostrar(PILA);

int main(void)
{
	int opc;
	char* cad;
	char* sacado;
	PILA pila1;
	crearPila(&pila1);
	printf("\t\tMENU\n");
	printf("  1.- Introducir un elemento en la cesta\n  2.-Sacar un elemento de la cesta\n  3.-Imprimir los elementos de la cesta\n  4.-Salir\n");
	do{
		printf("Ingrese la opcion deseada:");
		scanf("%d",&opc);
		switch(opc)
		{
			case 1:
				solicitar(pila1);
			break;
			case 2:
				sacado=pop(pila1);
			break;
			case 3:
				mostrar(pila1);
			break;
			case 4:
				exit(0);
			break;
		}
	}while(opc!=4);
	return 0;
}

void solicitar(PILA S)
{
	char elemento[8];
	printf("Ingrese el producto: ");
	scanf("%s",elemento);
	push(S,elemento);
}

void mostrar(PILA S)
{
	char auxiliar[8];
	PILA aux;
	crearPila(&aux);
	printf("Productos en la cesta: \n");
	while(stackEmpty(S)==FALSE)
	{
		push(aux,pop(S));
	}
	while(stackEmpty(aux)==FALSE)
	{
		strcpy(auxiliar,pop(aux));
		push(S,auxiliar);
		printf("%s\n",auxiliar);
	}
}

void manejaError(int e)
{
        char* errores[]={"No hay memoria disponible!","Error la Pila está vacia","Error la Pila está llena"};
        printf("%s",errores[e]);
}
