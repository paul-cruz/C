#include <stdlib.h>
#include "vector.h"

void manejarError(int);

vector crearVector(int n)
{
    vector v;
    v=(vector)malloc(sizeof(Vector));
	if(v==NULL)
	{
		manejarError(0);
		exit(0);
	}else{
        int* A;
        A=(int*)malloc(sizeof(int)*n);
	    if(A==NULL)
	    {
	    	manejarError(0);
    		exit(0);
    	}else{
            v->n=n;
            v->arreglo=A;
        }
    }
    return v;
}

int obtenComponente(vector v, int index)
{
    return (v->arreglo[index]);
}

vector ponComponente(vector v, int index, int val)
{
    v->arreglo[index]=val;
    return v;
}

int tamanio(vector v)
{
    return (v->n);
}

void liberar(vector v)
{
	free(v);
}
