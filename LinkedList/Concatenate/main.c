#include <stdlib.h>
#include <stdio.h>
#include "listaEn.h"

NODO solicitar(NODO);
NODO concatenar(NODO,NODO);
void manejarError(int e);

int main(void)
{
	NODO list1,list2,listaresultante;
	list1=crearLista();
	list2=crearLista();
	listaresultante=crearLista();
	list1=solicitar(list1);
	list2=solicitar(list2);
	printf("Lista 1:\n");
	mostrarLista(list1);
	printf("Lista 2:\n");
	mostrarLista(list2);
	listaresultante=concatenar(list1,list2);
	printf("Lista concatenada:\n");
	mostrarLista(listaresultante);
}

NODO solicitar(NODO lista)
{
	char opc;
	int e;
	do{
		printf("Ingrese el elemento: ");
        scanf("%d",&e);
        lista=insertar(lista,e);
        getchar();
        printf("¿Desea agregar un nuevo elemento?: ");
        scanf("%c",&opc);
        if(opc=='n')
            break;
    }while(opc!='n');
	return lista;
}

NODO concatenar(NODO l1, NODO l2)
{
	NODO l3;
	l3=crearLista();	
	int tam1=Count(l1),tam2=Count(l2);
	for(int i=0;i<tam1;i++)
	{
		l3=insertar(l3,getByIndex(l1,i));
	}
	for(int i=0;i<tam2;i++)
        {
                l3=insertar(l3,getByIndex(l2,i));
	}
	return l3;
}

void manejarError(int e)
{
	char * errores[]={"No hay memoria disponible...\n","Error en la funcion PUSH: Pila Llena ...\n\n","Error en la funcion POP: Pila Vacia ...\n\n","\n\n Division por CERO\n","Error en la funcion encolar: Cola Llena ...\n\n","Error en la funcion desencolar: Cola Vacia ...\n\n","Error Lista Vacia"};
	printf("%s",errores[e]);
}
