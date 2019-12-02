#include<stdlib.h>
#include "cola.h"

void manejarError(int);

void crearCola(COLA* C)
{
	*C=(COLA)malloc(sizeof(Cola));
	if(*C==NULL)
	{
		manejarError(0);
		exit(0);
	}
	(*C)->primero=0;
	(*C)->ultimo=0;
	(*C)->tam=0;	
}

int esVaciaCola(COLA C)
{
	if(C->tam==0)
		return TRUE;
	else
		return FALSE;
}

void encolar(COLA C, char e)
{
	char s;
	if(C->tam==SIZE)
	{
		manejarError(4);
		exit(0);
	}
	C->cola[C->ultimo]=e;
	s=sig(C->ultimo);
	C->ultimo=s;
	(C->tam)++;
}

char desencolar(COLA C)
{
	char x;
	int s;
	if(esVaciaCola(C)==TRUE)
	{
		manejarError(5);
		exit(0);
	}
	x=C->cola[C->primero];
	s=sig(C->primero);
	C->primero=s;
	(C->tam)--;
	return x;
}

char primero(COLA C)
{
	char x;
	if(esVaciaCola(C)==TRUE)
	{
		manejarError(5);
		exit(0);
	}
	x=C->cola[C->primero];
	return x;
}

int sig(int i)
{
	i=(i+1)%SIZE;
	return i;
}


