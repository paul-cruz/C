#include <stdlib.h>
#include <stdio.h>
#include "cola.h"

void manejarError(int);
void leerDatos(COLA);
COLA mostrarCola(COLA,char,char*);
void darLetra(char*);
int perteneceCola(COLA,char);

int main(void)
{
	char lt;
	COLA c1;
	crearCola(&c1);
	leerDatos(c1);
	darLetra(&lt);
	char* pert=perteneceCola(c1,lt)?"SI PERTENECE":"NO PERTENECE";
       	c1= mostrarCola(c1,lt,pert);
	return 0;
}

COLA mostrarCola(COLA c1,char letra, char* cad)
{
	COLA c2;
	crearCola(&c2);
	printf("Elementos de la cola:\n");
	while(esVaciaCola(c1)==FALSE)
	{
		char aux=desencolar(c1);
		printf("%c ",aux);
		encolar(c2,aux);		
	}
	printf("\n");
	printf("Y el caracter %c %s a la cola\n", letra, cad);
	return c2;
}

void leerDatos(COLA c1)
{
	char opc,elem;
	do{
		printf("¿quiere ingresar un elemento? S/N: ");
		scanf("%c",&opc);
		getchar();
		if(opc=='S')
		{
			char x;
			printf("Ingrese el elemento: ");
			scanf("%c",&x);
			encolar(c1,x);
			getchar();
		}
	}while(opc!='N');
}

void darLetra(char* letra)
{
	printf("Ingrese el caracter a buscar: ");
	scanf("%c",letra);
}

int perteneceCola(COLA c1, char letra)
{
	int rsp=FALSE;
	COLA c2;
	crearCola(&c2);
	while(esVaciaCola(c1)==FALSE)
	{
		char aux=desencolar(c1);
		if(aux==letra)
		{
			rsp=TRUE;
		}else if(rsp!=TRUE)
		{
			rsp=FALSE;
		}
		encolar(c2,aux);		
	}
	while(esVaciaCola(c2)==FALSE)
	{
		encolar(c1,desencolar(c2));
	}
	return rsp;
}

void manejarError(int e)
{
	char* errores[]={"No hay memoria disponible","Error la pila esta vacia","Error la pila esta llena","Error division por cero(0)","Error cola llena","Error cola vacia"};
	printf("%s\n",errores[e]);
}
