#include <stdlib.h>
#include <stdio.h>
#include "colaD.h"

void manejaError(int);
void LeerDato(COLA);
int maxCola(COLA);
void mostrar(COLA);

int main(void)
{
	COLA C;
	C=crearCola();
	LeerDato(C);
	mostrar(C);
	return 0;
}

void LeerDato(COLA C)
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

int minCola(COLA C)
{
	int num,menor=0,primero=TRUE;
	COLA aux;
	aux=crearCola();
	while(esVaciaCola(C)==FALSE)
	{
		num=desencolar(C);
		if(primero)
		{
			menor=num;
			primero=FALSE;
		}
		encolar(aux,num);
		if(menor>num)
		{
			menor=num;
		}
	}
	while(esVaciaCola(aux)==FALSE)
	{
		encolar(C,desencolar(aux));
	}
	return menor;
}

void mostrar(COLA C)
{
	printf("El minimo dato de la cola es: %d\n",minCola(C));
	printf("Datos de la cola: ");
	while(esVaciaCola(C)==FALSE)
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
