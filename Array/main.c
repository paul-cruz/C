#include<stdio.h>
#include<stdlib.h>

void dimension_Matriz(int *,int *);
int** crear_Matriz(int,int);
void llenar_Matriz(int **,int,int);
void mostrar_Matriz(int **,int,int);
void liberar_Matriz(int **,int);

void main()
{
	int **mtz,fil,col;
	dimension_Matriz(&fil,&col);
	mtz=crear_Matriz(fil,col);
	llenar_Matriz(mtz,fil,col);
	mostrar_Matriz(mtz,fil,col);
	liberar_Matriz(mtz,fil);
}

void dimension_Matriz(int *fil, int *col)
{
	printf("Introduzca el numero de filas\n");
	scanf("%d",fil);
	printf("Intruduzca el numero de columnas\n");
	scanf("%d",col);
}

int** crear_Matriz(int fil, int col)
{
	int **A, i;
	A=(int**)malloc(sizeof(int*)*fil);
	if(A==NULL)
	{
		printf("No hay memoria disponible...\n");
		exit(0);
	}
	for(i=0;i<fil;i++)
		A[i]=(int *)malloc((sizeof(int))*col);
	return A;
}

void llenar_Matriz(int **mtz, int fil, int col)
{
	int i, j;
	printf("Introduzca los datos\n");
	for(i=0;i<fil;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("\nmtz[%d][%d]: ",i+1,j+1);
			scanf("%d",&mtz[i][j]);
		}
	}
}

void mostrar_Matriz(int **mtz, int fil, int col)
{
	int i=0,j=0;
	printf("Los datos de la matriz son: \n");
	for(i=0;i<fil;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("mtz[%d][%d]=%d\n",i,j,mtz[i][j]);
		}
		printf("\n");
	}
}

void liberar_Matriz(int **mtz,int fil)
{
	int i=0;
	for(i=0; i<fil;i++)
	{
		free(mtz[i]);
	}
	printf("Memoria liberada... \n");
}		
