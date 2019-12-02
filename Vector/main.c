#include <stdio.h>
#include <stdlib.h>

void darTam(int*);
void crearArregloUni(int**,int);
void datos(int*,int);
void mostrar(int*,int);
void liberar(int*);

void main()
{
	int *Arreglo, elem;
	darTam(&elem);
	crearArregloUni(&Arreglo,elem);
	datos(Arreglo,elem);
	mostrar(Arreglo,elem);
	liberar(Arreglo);
}

void darTam(int *elem)
{
	printf("Ingrese el tamaño del arreglo: ");
	scanf("%d",elem);
}

void crearArregloUni(int **A, int elem)
{
	*A=(int*)malloc(sizeof(int)*elem);
	if(*A==NULL)
	{
		printf("No hay memoria disponible\n");
		exit(0);
	}
}

void datos(int *A, int elem)
{
	int i=0;
	printf("Introduzca elementos \n");
	for(i=0;i<elem;i++)
	{
		printf("\nA[%d]: ",i+1);
		scanf("%d",&A[i]);
	}
}

void mostrar(int *A, int elem)
{
	int i=0;
	printf("Los elementos son:\n");
	for(i=0;i<elem;i++)
		printf("A[%d]=%d\n",i+1,A[i]);
}

void liberar(int *A)
{
	free(A);
}
