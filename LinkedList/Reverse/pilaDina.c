#include<stdio.h>
#include<stdlib.h>
#include"pilaDina.h"

void manejarError(int);

PILA crearPila()
{
	PILA S=(PILA)malloc(sizeof(Pila));
	if(S==NULL)
	{
		manejarError(0);
		exit(0);
	}
	S->tope=NULL;
	return S;
}

Nodo_Pila* crearNodoPila()
{
	Nodo_Pila* nvo;
	nvo=(Nodo_Pila*)malloc(sizeof(Nodo_Pila));
	if(nvo==NULL)
	{
		manejarError(0);
		exit(0);
	}
	return nvo;
}

int stackEmpty(PILA S)
{
	if(S->tope==NULL)
		return TRUE;
	else
		return FALSE;
}

int stackTop(PILA S)
{
	int e;
	if(stackEmpty(S)==TRUE)
	{
		manejarError(2);
		exit(0);		
	}
	e=S->tope->dato;
	return e;
}

int pop(PILA S)
{
	int e;
	Nodo_Pila* aux;
	if(stackEmpty(S)==TRUE)
	{
		manejarError(2);
		exit(0);
	}
	aux=S->tope;
	e=aux->dato;
	S->tope=aux->anterior;
	free(aux);
	return e;
}

void push(PILA S, int e)
{
	Nodo_Pila* nvo;
	nvo=crearNodoPila();
	nvo->dato=e;
	nvo->anterior=S->tope;
	S->tope=nvo; 
}
