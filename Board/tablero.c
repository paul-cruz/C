#include <stdlib.h>
#include "tablero.h"

void manejarError(int);

tablero crearTabla(int fil, int col)
{
	tablero t;
	t=(tablero)malloc(sizeof(Tablero));
	if(t==NULL)
	{
		manejarError(0);
		exit(0);
	}

	char **A, i;
	A=(char**)malloc(sizeof(char*)*fil);
	if(A==NULL)
	{
		manejarError(0);
		exit(0);
	}
	for(i=0;i<fil;i++)
		A[i]=(char*)malloc((sizeof(char))*col);

	t->mtz=A;

	return t;
}

tablero ponValor(tablero t, char val, int fil, int col)
{
	t->mtz[fil][col]=val;
	return t;
}

char obtenValor(tablero t, int fil, int col)
{
	return (t->mtz[fil][col]);
}

int tamFila(tablero t)
{
	return (t->fila);
}

int tamColum(tablero t)
{
	return (t->columna);
}

tablero iniciaObstaculo(tablero t, int posF, int posC)
{
	t=ponValor(t,'*',posF,posC);
	return t;
}

int esPosibleMover(tablero t, int movF, int movC)
{
	if(obtenValor(t,movF,movC)=='*')
	{
		return 1;
	}else{
		return 0;
	}
}

void liberar(tablero t)
{
	free(t);
}
