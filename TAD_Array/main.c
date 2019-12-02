#include <stdio.h>
#include "matriz.h"
#include <string.h>

void manejarError(int);
void leerDim(int*,int*);
matriz llenarMatriz(matriz);
void mostrar(matriz);

void main()
{
	matriz m;
	int fil,col;
	leerDim(&fil,&col);
    m=crearMatriz(fil,col);
    m=llenarMatriz(m);
    mostrar(m);
    liberar(m);
}

matriz llenarMatriz(matriz m)
{
    int i,j;
    for(i=0;i<tamFila(m);i++)
    {
        for(j=0;j<tamColum(m);j++)
        {
            char letra;
            printf("Ingrese el valor [%d][%d]: ",i,j);
            getchar();
            scanf("%c",&letra);
            ponValor(m,letra,i,j);
        }
    }
    return m;
}

void leerDim(int* f, int*c)
{
	printf("Introduzca el numero de filas: ");
	scanf("%d",f);
	printf("Introduzca el numero de columnas: ");
	scanf("%d",c);
}

void mostrar(matriz m)
{
    int i=0,j=0;
    printf("Los elementos son:\n");
    for(i=0;i<tamFila(m);i++)
    {
        for(j=0;j<tamColum(m);j++){
            printf("%c ",obtenValor(m,i,j));}
        printf("\n");
    }
}

void manejarError(int e)
{
	char* errores[]={"No hay memoria disponible!"};
	printf("%s",errores[e]);
}
