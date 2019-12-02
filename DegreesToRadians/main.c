#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef MPI
#define M_PI 3.14159265358979323846
#endif

void darTam(int*);
void crearArregloUni(float**,int);
void datos(float*,int);
void mostrar(float*,int);
void liberar(float*);
float convertir(float);
int factorial(int);
void formula(float*,int);

void main()
{
	float *A;
	int elem;
	darTam(&elem);
	crearArregloUni(&A,elem);
	datos(A,elem);
	//mostrar(A,elem);
	formula(A,elem);
	liberar(A);
}

void darTam(int *elem)
{
	printf("Ingrese cuantos angulos desea ingresar: ");
	scanf("%d",elem);
}

void crearArregloUni(float **A, int elem)
{
	*A=(float*)malloc(sizeof(float)*elem);
	if(*A==NULL)
	{
		printf("No hay memoria disponible\n");
		exit(0);
	}
}

void datos(float *A, int elem)
{
	int i=0;
	printf("Introduzca los angulos: \n");
	for(i=0;i<elem;i++)
	{
		printf("\nA[%d]: ",i+1);
		scanf("%f",&A[i]);
		A[i]=convertir(A[i]);
	}
}

void mostrar(float *A, int elem)
{
	int i=0;
	printf("Los grados en radianes son:\n");
	for(i=0;i<elem;i++)
		printf("A[%d]=%f\n",i+1,A[i]);
}

void liberar(float *A)
{
	free(A);
}


float convertir(float rad)
{
	rad=rad*(float)(M_PI)/180.00;
	return rad;	
}

int factorial(int n)
{
	if(n==1)
	{
		return 1;
	}else{
		return n*factorial(n-1);
	}
}

void formula(float *A, int N)
{
	int i=0;
	float result=0.0f;
	for(i=1;i<=N;i++)
	{
		result+=(pow(-1,i-1)*pow((A[i-1]),2*i-1))/factorial(2*i-1);
	}
	printf("\nEl resultado de la formula es: %f",result);
}
