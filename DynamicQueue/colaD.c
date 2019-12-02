#include <stdlib.h>
#include "colaD.h"

void manejaError(int);

COLA crearCola()
{
	COLA C;
	C=(COLA)malloc(sizeof(Cola));
	if(C==NULL)
	{
		manejaError(0);
		exit(0);
	}
	C->primero=NULL;
	C->ultimo=NULL;
	return C;
}

Nodo_Cola* crearNodoCola()
{
	Nodo_Cola* nvo;
	nvo=(Nodo_Cola*)malloc(sizeof(Nodo_Cola));
	if(nvo==NULL);
	{
		manejaError(0);
		exit(0);
	}
	return nvo;
}

int esVaciaCola(COLA C)
{
	if(C->primero==NULL && C->ultimo==NULL)
	{
		return TRUE;
	}else{
		return FALSE;
	}
}

int primero (COLA C)
{
	int e;
	if(esVaciaCola(C)==TRUE)
	{
		manejaError(5);
		exit(0);
	}
	e=C->primero->dato;
	return e;
}

void encolar(COLA C, int e)
{
	Nodo_Cola* nvo;
	nvo=crearNodoCola();
	nvo->dato=e;
	nvo->sig=NULL;
	if(esVaciaCola(C)==TRUE)
	{
		C->primero=nvo;
	}else{
		C->ultimo->sig=nvo;
	}
	C->ultimo=nvo;
}

int desencolar(COLA C)
{
	int e;
	Nodo_Cola* aux;
	if(esVaciaCola(C)==TRUE)
	{
		manejaError(5);
		exit(0);
	}
	aux=C->primero;
	e=aux->dato;
	if(C->primero->sig==NULL)
	{
		C->primero=NULL;
		C->ultimo=NULL;
	}else{
		C->primero=aux->sig;
	}
	free(aux);
	return e;
}
