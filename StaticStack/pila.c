#include <stdlib.h>
#include "pila.h"

void manejaError(int);

void crearPila(PILA* S)
{
	*S=(PILA)malloc(sizeof(Pila));
	if(*S==NULL)
	{
		manejaError(0);
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
		manejaError(1);
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
		manejaError(2);
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
