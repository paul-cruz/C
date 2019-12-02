#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "listaEn.h"

NODO leerBinarios(NODO);
NODO restaBinarios(NODO,NODO);
void mostrar(NODO,NODO,NODO);
void manejarError(int e);

int main(void)
{
	NODO list1,list2,list3;
	list1=crearLista();
	list2=crearLista();
	list3=crearLista();
	printf("Numero binario 1:\n");
	list1=leerBinarios(list1);
	printf("Numero binario 2:\n");
	list2=leerBinarios(list2);
	if(Count(list2)<Count(list1))
	{
		while(Count(list2)<Count(list1))
		{
			list2=insertInIndex(list2,0,0);
		}
	}
	if(Count(list1)<Count(list2))
	{
		while(Count(list1)<Count(list2))
		{
			list1=insertInIndex(list1,0,0);
		}
	}
	list3=restaBinarios(list1,list2);
	mostrar(list1,list2,list3);
	return 0;
}

NODO leerBinarios(NODO lista)
{
	int i=0;
	char cadena[100];
	scanf("%s",cadena);
	for(i=strlen(cadena)-1;i>=0;i--)
	{
		lista=insertar(lista,(cadena[i]-48));
	}
	return lista;
}

NODO restaBinarios(NODO lista1,NODO lista2)
{
	NODO rsp,aux;
	rsp=crearLista();
	aux=crearLista();
	int acarreo=false,i=0;
	for(i=Count(lista1)-1;i>=0;i--)
	{
		int p,s,r=0;
		p=getByIndex(lista1,i);
		s=getByIndex(lista2,i);
		r=p-s;
		if(acarreo)
		{
			r-=1;
			acarreo=false;
		}
		if(r==-1)
		{
			r=1;
			acarreo=true;
		}
		aux=insertar(aux,r);
	}
	for(i=Count(aux)-1;i>=0;i--)
		rsp=insertar(rsp,getByIndex(aux,i));
	return rsp;
}

void mostrar(NODO lista1,NODO lista2,NODO lista3)
{
	int i=0;
	printf("\nNumero binario 1: ");
	for(i=0;i<Count(lista1);i++)
		printf("%d",getByIndex(lista1,i));
	printf("\nNumero binario 2: ");
	for(i=0;i<Count(lista2);i++)
		printf("%d",getByIndex(lista2,i));
	printf("\nResta binario: ");
	for(i=0;i<Count(lista3);i++)
		printf("%d",getByIndex(lista3,i));
	printf("\n");
}

void manejarError(int e)
{
	char * errores[]={"No hay memoria disponible...\n","Error en la funcion PUSH: Pila Llena ...\n\n","Error en la funcion POP: Pila Vacia ...\n\n","\n\n Division por CERO\n","Error en la funcion encolar: Cola Llena ...\n\n","Error en la funcion desencolar: Cola Vacia ...\n\n","Error Lista Vacia"};
	printf("%s",errores[e]);
}
