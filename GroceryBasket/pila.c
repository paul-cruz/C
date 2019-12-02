#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
		for(int i=0;i<TAM;i++)
		{
			(*S)->pila[i]=(char*)malloc(sizeof(char)*8);
		}
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

char* pop(PILA S)
{
	char* v;
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

void push(PILA S, char* e)
{
	if(S->tope==TAM-1)
	{
		manejaError(2);
		exit(0);
	}else{
		(S->tope)++;
		strcpy(S->pila[S->tope],e);
	}
}

char* stackTop(PILA S)
{
	char* v;
	v=pop(S);
	push(S,v);
	return v;
}
