#include <stdlib.h>
#include <stdio.h>
#include "colaD.h"

void manejaError(int);
void agregarDato(COLA);
int tamCola(COLA);
void mostrar(COLA);

int main(void)
{
	COLA C;
	C=crearCola();
	agregarDato(C);
	mostrar(C);
	return 0;
}

void agregarDato(COLA C)
{
	int e;
	char opc;
	do{
		printf("¿Desea agregar un elemento? (S/N): ");
		scanf("%c",&opc);
		getchar();
		if(opc!='N' || opc!='n')
		{
			printf("Ingrese el elemento: ");
			scanf("%d",&e);
			encolar(C,e);
		}else
		{
			break;
		}
	}while(opc!='N' || opc!='n');

}

int tamCola(COLA C)
{
	int cont=0;
	COLA aux;
	aux=crearCola();
	while(esVaciaCola(C))
	{
		encolar(aux,desencolar(C));
		cont++;
	}
	while(esVaciaCola(aux))
	{
		encolar(C,desencolar(aux));
	}
	return cont;
}

void mostrar(COLA C)
{
	printf("Los datos de la cola con tamaño %d son: ",tamCola(C));
	while(esVaciaCola(C))
	{
		printf("%d, ",desencolar(C));
	}
	printf("\n");
}

void manejaError(int e)
{
	char * errores[]={"No hay memoria disponible...\n","Error en la funcion PUSH: Pila Llena ...\n\n","Error en la funcion POP: Pila Vacia ...\n\n","\n\n Division por CERO\n","Error en la funcion encolar: Cola Llena ...\n\n","Error en la funcion desencolar: Cola Vacia ...\n\n"};
	printf("%s",errores[e]);
}
