#include <stdlib.h>
#include <stdio.h>
#include "listaEn.h"

NODO solicitar(NODO);
int comparar(NODO,NODO);
void manejarError(int e);

int main(void)
{
	NODO list1,list2;
	list1=crearLista();
	list2=crearLista();
	list1=solicitar(list1);
	list2=solicitar(list2);
	mostrarLista(list1);
	mostrarLista(list2);
	comparar(list1,list2)?printf("Son iguales\n"):printf("Son diferentes\n");
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

int comparar(NODO l1, NODO l2)
{
	int rsp=true;
	int tam=Count(l2);
	for(int i=0;i<tam;i++)
	{
		if(buscar(l1,getByIndex(l2,i))&&rsp!=false)
			rsp=true;
		else
			rsp=false;
	}
	return rsp;
}

void manejarError(int e)
{
	char * errores[]={"No hay memoria disponible...\n","Error en la funcion PUSH: Pila Llena ...\n\n","Error en la funcion POP: Pila Vacia ...\n\n","\n\n Division por CERO\n","Error en la funcion encolar: Cola Llena ...\n\n","Error en la funcion desencolar: Cola Vacia ...\n\n","Error Lista Vacia"};
	printf("%s",errores[e]);
}
