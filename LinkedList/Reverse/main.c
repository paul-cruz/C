#include <stdlib.h>
#include <stdio.h>
#include "listaEn.h"
#include "pilaDina.h"

NODO solicitar(NODO);
void reverse(NODO);
void manejarError(int e);

int main(void)
{
	NODO list1;
	list1=crearLista();
	list1=solicitar(list1);
	reverse(list1);
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

void reverse(NODO lista)
{
	PILA pil;
	pil=crearPila();
	int i=0;
	for(i=0;i<Count(lista);i++)
	{
		push(pil,getByIndex(lista,i));
	}
	printf("Lista invertida:\n");
	while(!stackEmpty(pil))
		printf("%d ",pop(pil));
	printf("\n");	
}
void manejarError(int e)
{
	char * errores[]={"No hay memoria disponible...\n","Error en la funcion PUSH: Pila Llena ...\n\n","Error en la funcion POP: Pila Vacia ...\n\n","\n\n Division por CERO\n","Error en la funcion encolar: Cola Llena ...\n\n","Error en la funcion desencolar: Cola Vacia ...\n\n","Error Lista Vacia"};
	printf("%s",errores[e]);
}
