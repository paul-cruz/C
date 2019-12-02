#include <stdlib.h>
#include <stdio.h>
#include "listaEn.h"
#include "colaD.h"

NODO solicitar(NODO);
void mayor(NODO,char);
void manejarError(int e);

int main(void)
{
	char caracter;
	NODO list1;
	list1=crearLista();
	list1=solicitar(list1);
	getchar();
	printf("Ingrese la clave a buscar: ");
	scanf("%c",&caracter);
	getchar();
	mayor(list1,caracter);
	return 0;
}

NODO solicitar(NODO lista)
{
	char opc,e;
	do{
		printf("Ingrese el elemento: ");
       		scanf("%c",&e);
	        lista=insertar(lista,e);
        	getchar();
	        printf("¿Desea agregar un nuevo elemento?: ");
        	scanf("%c",&opc);
	        if(opc=='n')
		            break;
			getchar();
 	}while(opc!='n');
	return lista;
}

void mayor(NODO lista,char d)
{
	COLA aux;
	aux=crearCola();
	int cont=0, activo=false,mayor;
	for(int i=0;i<Count(lista);i++)
	{
		if(getByIndex(lista,i)==d && activo==false)
		{
			activo=true;
		}else if(getByIndex(lista,i)==d && activo==true)
		{
			cont++;
			activo=false;
			encolar(aux,cont);
			cont=0;
		}else if(activo==true)
		{
			cont++;
		}
	}
	mayor=desencolar(aux);
	while(!esVaciaCola(aux))
	{
		int nuevo;
		nuevo=desencolar(aux);
		if(mayor<nuevo)
		{
			mayor=nuevo;
		}
	}
	printf("La maxima distancia es: %d\n",mayor);
}
	
void manejarError(int e)
{
	char * errores[]={"No hay memoria disponible...\n","Error en la funcion PUSH: Pila Llena ...\n\n","Error en la funcion POP: Pila Vacia ...\n\n","\n\n Division por CERO\n","Error en la funcion encolar: Cola Llena ...\n\n","Error en la funcion desencolar: Cola Vacia ...\n\n","Error Lista Vacia"};
	printf("%s",errores[e]);
}
