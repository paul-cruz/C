#include <stdlib.h>
#include "matriz.h"

void manejarError(int);

matriz crearMatriz(int fil, int col)
{
	matriz m;
	m=(matriz)malloc(sizeof(Matriz));
	if(m==NULL)
	{
		manejarError(0);
		exit(0);
	}else{
	    char **A, i;
	    A=(char**)malloc(sizeof(char*)*fil);
    	if(A==NULL)
    	{
    		manejarError(0);
    		exit(0);
    	}else{
    	    for(i=0;i<fil;i++)
    		A[i]=(char*)malloc((sizeof(char))*col);
            m->fila=fil;
            m->columna=col;
	        m->mtz=A;
        }
    }
	return m;
}

matriz ponValor(matriz m, char val, int fil, int col)
{
	m->mtz[fil][col]=val;
	return m;
}

char obtenValor(matriz m, int fil, int col)
{
	return (m->mtz[fil][col]);
}

int tamFila(matriz m)
{
	return (m->fila);
}

int tamColum(matriz m)
{
	return (m->columna);
}

void liberar(matriz m)
{
	free(m);
}
