#include <stdlib.h>
#include <stdio.h>
#include "listaEn.h"

void manejarError(int);

int main(void)
{
	int e,i;
	char opc;
	NODO list;
	list=crearLista();
	do{
		printf("Ingrese el elemento: ");
		scanf("%d",&e);
		list=insertar(list,e);
		getchar();
		printf("¿Desea agregar un nuevo elemento?: ");
		scanf("%c",&opc);
		if(opc=='n')
		{
			break;
		}
	}while(opc!='n');
	printf("Ingrese el indice: ");
	scanf("%d",&i);
	printf("Ingrese el elemento: ");
	scanf("%d",&e);
	list=insertInIndex(list,e,i);
	printf("\n");
	mostrarLista(list);
	printf("Ingrese el indice a eliminar: ");
    scanf("%d",&i);
	list=deleteInIndex(list,i);
	printf("\n");
    mostrarLista(list);
	printf("Ingrese el elemento a buscar: ");
	scanf("%d",&e);
	buscar(list,e)?printf("El elemento esta en la lista en el indice %d\n",indexOf(list,e)):printf("el elemento no esta en la lista\n");
	return 0;
}

void manejarError(int e)
{
	char * errores[]={"No hay memoria disponible...\n","Error en la funcion PUSH: Pila Llena ...\n\n","Error en la funcion POP: Pila Vacia ...\n\n","\n\n Division por CERO\n","Error en la funcion encolar: Cola Llena ...\n\n","Error en la funcion desencolar: Cola Vacia ...\n\n","Error Lista Vacia"};
	printf("%s",errores[e]);
}
