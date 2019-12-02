#include <stdlib.h>
#include <stdio.h>
#include "cola.h"
#include "pila.h"

void manejarError(int);
void darNumero(COLA,PILA);
COLA mostrarCola(COLA, PILA);
int esCapicua(PILA,COLA);

int main(void)
{

	char opc;
	COLA c1;
	crearCola(&c1);
	PILA p1;
	crearPila(&p1);
	darNumero(c1,p1);
	c1= mostrarCola(c1, p1);
	return 0;
}

COLA mostrarCola(COLA c1, PILA pil)
{
	COLA c2;
	crearCola(&c2);
	char* pal= esCapicua(pil,c1)==TRUE?"ES":"NO ES";
	printf("El numero: ");
	while(esVaciaCola(c1)==FALSE)
	{
		int aux=desencolar(c1);
		printf("%d",aux);
		encolar(c2,aux);		
	}
	printf(" %s PALINDROMO\n",pal);
	return c2;
}

void darNumero(COLA col, PILA pil)
{
	int elem;
	printf("Ingrese el numero a evaluar: ");
	scanf("%d",&elem);
	while(elem!=0)
	{
		encolar(col,elem%10);
		push(pil,elem%10);
		elem/=10;
	}
}

int esCapicua(PILA pil, COLA col)
{
	int rsp;
	COLA colaux;
	crearCola(&colaux);
	while(stackEmpty(pil)==FALSE)
	{
		int num=desencolar(col);
		int num2=pop(pil);
		encolar(colaux,num2);
		if(num2==num)
		{
			if(rsp!=FALSE)
				rsp=TRUE;
		}else{
			rsp=FALSE;
		}
	}
	while(esVaciaCola(colaux)==FALSE)
	{
		int aux=desencolar(colaux);
		encolar(col,aux);		
	}
	return rsp;	
}
void manejarError(int e)
{
	char* errores[]={"No hay memoria disponible","Error la pila esta vacia","Error la pila esta llena","Error division por cero(0)","Error cola llena","Error cola vacia"};
	printf("%s\n",errores[e]);
}
