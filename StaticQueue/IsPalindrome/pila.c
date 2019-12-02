#include <stdlib.h>
#include "pila.h"

void manejarError(int);

void crearPila(PILA* S)
{
	*S=(PILA)malloc(sizeof(Pila));
	if(*S==NULL)
	{
		manejarError(0);
		exit(0);
	}else{
		(*S)->tope=-1;
	}
}

int stackEmpty(PILA S)
{
	if(S->tope<0)
	{
		return TRUE;
	}else{
		return FALSE;
	}
}

int pop(PILA S)
{
	int v;
	if(stackEmpty(S)==TRUE)
	{
		manejarError(1);
		exit(0);
	}else{
		v=S->pila[S->tope];
		(S->tope)--;
		return v;
	}
}

void push(PILA S, int e)
{
	if(S->tope==TAM-1)
	{
		manejarError(2);
		exit(0);
	}else{
		(S->tope)++;
		S->pila[S->tope]=e;
	}
}

int stackTop(PILA S)
{
	int v;
	v=pop(S);
	push(S,v);
	return v;
}
