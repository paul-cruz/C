#include <stdio.h>
#include <stdlib.h>

void darTam(int*);
void crearArregloUni(int**,int);
void datos(int*,int);
void mostrar(int*,int);
void liberar(int*);
void ordenar(int*,int);

void main()
{
	int *A, elem;
	darTam(&elem);
	crearArregloUni(&A,elem);
	datos (A,elem);
	ordenar(A,elem);
	mostrar(A,elem);
	liberar(A);
}


void darTam(int *elem)
{
	printf("Ingrese el numero de cifras: ");
	scanf("%d",elem);
}

void crearArregloUni(int **A, int elem)
{
	*A=(int *)malloc(sizeof(int)*elem);
	if(*A==NULL)
	{
		printf("No hay memoria disponible...\n");
		exit(0);
	}
}

void datos(int *A, int elem)
{
	int i=0;
	int num=0;
	printf("Introduzca el numero natural: ");
	scanf("%d",&num);
	for(i=elem-1;i>=0;i--)
	{
		A[i]=num%10;
		num/=10;
	}
}

void mostrar(int *A, int elem)
{
	int i=0;
	printf("El numero menor es: ");
	for(i=0;i<elem;i++)
	{
		printf("%d",A[i]);
		if(i==elem-1)
		printf("\n");
	}
	printf("El numero mayor es: ");
	for(i=elem-1;i>=0;i--)
	{
		printf("%d",A[i]);
		if(i==0)
		printf("\n");
	}
}

void liberar(int *A)
{
	free(A);
}

void ordenar(int *A, int elem)
{
	int i=0,j=0,temp=0,min=0;
	for(i=0;i<elem-1;i++)
	{
		min=i;
		for(j=i+1;j<elem;j++)
		{
			if(A[min]>A[j])
			{
				min=j;
			}
		}
		temp=A[min];
		A[min]=A[i];
		A[i]=temp;
	}
}
