#include <stdio.h>
#include "vector.h"

void manejarError(int);
void leerDim(int*);
vector llenarVector(vector);
void mostrar(vector);

void main()
{
	vector v;
	int n;
	leerDim(&n);
    v=crearVector(n);
    v=llenarVector(v);
	mostrar(v);
    liberar(v);
}

vector llenarVector(vector v)
{
    int i=0;
    for(i=0;i<tamanio(v);i++)
    {
        int aux;
        printf("Ingrese el valor %d: ",i+1);
        scanf("%d",&aux);
        ponComponente(v,i,aux);
    }
    return v;
}

void leerDim(int* n)
{
	printf("Introduzca el tamanio del vector: ");
	scanf("%d",n);
}

void mostrar(vector v)
{
    int i=0;
    printf("Los elementos del vector son: ");
    for(i=0;i<tamanio(v);i++)
    {
        printf("%d ",obtenComponente(v,i));
    }
    printf("\n");
}

void manejarError(int e)
{
	char* errores[]={"No hay memoria disponible!"};
	printf("%s",errores[e]);
}
