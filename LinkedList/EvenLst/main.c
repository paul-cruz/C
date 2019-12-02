#include <stdlib.h>
#include <stdio.h>
#include "listaEn.h"

NODO solicitar(NODO);
NODO tratarLista(NODO);
void manejarError(int e);

int main(void)
{
	NODO list1;
	list1=crearLista();
	list1=solicitar(list1);
	printf("Lista Original\n");
	mostrarLista(list1);
	list1=tratarLista(list1);
	printf("Lista Tratada\n");
	mostrarLista(list1);
	return 0;
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

NODO tratarLista(NODO l1)
{
	NODO aux;
	aux=crearLista();
	int tam=Count(l1);
	printf("%d\n",tam);
	if(tam&1)
	{
		for(int i=0;i<tam;i++)
		{
			if(!((i+1)&1))
			{
				aux=insertar(aux,getByIndex(l1,i));
			}
		}
	}else{
		for(int i=0;i<tam;i++)
                {
                        if((i+1)&1)
			{
				aux=insertar(aux,getByIndex(l1,i));
			}
                }
	}
	return aux;
}

void manejarError(int e)
{
	char * errores[]={"No hay memoria disponible...\n","Error en la funcion PUSH: Pila Llena ...\n\n","Error en la funcion POP: Pila Vacia ...\n\n","\n\n Division por CERO\n","Error en la funcion encolar: Cola Llena ...\n\n","Error en la funcion desencolar: Cola Vacia ...\n\n","Error Lista Vacia"};
	printf("%s",errores[e]);
}
