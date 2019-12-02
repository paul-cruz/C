#include <stdlib.h>
#include <stdio.h>
#include "pila.h"

void manejaError(int);
int solicitar();
void mostrar(PILA);

int main(void)
{
	char opc;
	PILA pila1;
	crearPila(&pila1);
	do{
		printf("¿Desea agregar un elemento a la Pila? (S/N) ");
		scanf("%c",&opc);
		if(opc=='S')
		{
			getchar();
			push(pila1,solicitar());
			getchar();
		}
	}while(opc!='N');
	mostrar(pila1);
	return 0;
}

int solicitar()
{
	int elemento;
	printf("Ingrese el elemento: ");
	scanf("%d",&elemento);
	return elemento;
}

void mostrar(PILA S)
{
	PILA aux; 
	crearPila(&aux);
	printf("Elementos de la pila: \n");
	while(stackEmpty(S)==FALSE)
	{
		push(aux,pop(S));
	}
	while(stackEmpty(aux)==FALSE)
	{
		printf("%d ",pop(aux));
	}
	printf("\n");
}

void manejaError(int e)
{
        char* errores[]={"No hay memoria disponible!","Error la Pila está vacia","Error la Pila está llena"};
        printf("%s",errores[e]);
}
