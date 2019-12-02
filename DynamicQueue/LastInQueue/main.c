#include <stdlib.h>
#include <stdio.h>
#include "colaD.h"

void manejaError(int);
void agregarDato(COLA);
int ultimoCola(COLA);
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
		if(opc!='N')
		{
			printf("Ingrese el elemento: ");
			scanf("%d",&e);
			encolar(C,e);
			getchar();
		}else
		{
			break;
		}
	}while(opc!='N');

}

int ultimoCola(COLA C)
{
	int num;
	COLA aux;
	aux=crearCola();
	while(esVaciaCola(C)==FALSE)
	{
		num=desencolar(C);
		encolar(aux,num);
	}
	while(esVaciaCola(aux)==FALSE)
	{
		encolar(C,desencolar(aux));
	}
	return num;
}

void mostrar(COLA C)
{
	printf("El ultimo dato de la cola es: %d\n",ultimoCola(C));
}

void manejaError(int e)
{
	char * errores[]={"No hay memoria disponible...\n","Error en la funcion PUSH: Pila Llena ...\n\n","Error en la funcion POP: Pila Vacia ...\n\n","\n\n Division por CERO\n","Error en la funcion encolar: Cola Llena ...\n\n","Error en la funcion desencolar: Cola Vacia ...\n\n"};
	printf("%s",errores[e]);
}
