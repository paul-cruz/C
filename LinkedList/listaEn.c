#include <stdlib.h>
#include <stdio.h>
#include "listaEn.h"

void manejarError(int);

NODO crearLista()
{
	NODO lista;
	lista=NULL;
	return lista;
}

int esVaciaLista(NODO lista)
{
	if(lista==NULL)
	{
		return true;
	}else{
		return false;
	}
}

NODO crearNodo()
{
	NODO nvo;
	nvo=(NODO)malloc(sizeof(Nodo));
	if(nvo==NULL)
	{
		manejarError(0);
		exit(0);
	}
	return nvo;
}

void mostrarLista(NODO lista)
{
	NODO aux;
	int pos;
	if(esVaciaLista(lista))
	{
		manejarError(6);
		exit(0);
	}else{
		aux=lista;
		pos=0;
		while(aux!=NULL)
		{
			printf("NODO(%d)= %d",pos,aux->dato);
			if(aux->sig!=NULL)
				printf(", ");
			aux=aux->sig;
			pos++;
		}
		printf("\n");
	}
}

int getFirst(NODO lista)
{
	return lista->dato;
}

int getByIndex(NODO lista, int index)
{
	NODO aux;
	int i=0;
	aux=lista;
	if(index==0)
	{
		return getFirst(lista);
	}else{
		while(i!=index)
		{
			i++;
			aux=aux->sig;
		}
		return aux->dato;
	}
}

int getLast(NODO lista)
{
	NODO aux;
	aux=lista;
	while(aux->sig!=NULL)
		aux=aux->sig;
	return aux->dato;
}

int buscar(NODO lista, int elem)
{
	NODO aux;
	int pos=0;
	if(esVaciaLista(lista))
	{
		manejarError(6);
		exit(0);
	}else{
		aux=lista;
		while(aux!=NULL && aux->dato!=elem)
		{
			aux=aux->sig;
			pos++;
		}
		if(aux==NULL)
		{
			//printf("El elemento %d no se encuentra en la lista\n",elem);
			return false;
		}else{
			//printf("El elemento %d se encuentra en la posision %d\n",elem,pos);
			return true;
		}
	}
}

NODO insertar(NODO lista, int elem)
{
	NODO nvo,aux;
	nvo=crearNodo();
	nvo->dato=elem;
	nvo->sig=NULL;
	if(esVaciaLista(lista))
	{
		lista=nvo;
		return lista;
	}else{
		aux=lista;
		while(aux->sig!=NULL)
		{
			aux=aux->sig;
		}
		aux->sig=nvo;
		return lista;
	}
}

NODO insertInIndex(NODO lista,int elem, int index)
{
	int i=0;
	NODO nvo,aux,before;
	nvo=crearNodo();
	nvo->dato=elem;
	aux=lista;
	if(index==0)
	{
		nvo->sig=aux;
		lista=nvo;
	}else{
		while(i!=index)
		{
			i++;
			before=aux;
			aux=aux->sig;
		}
		nvo->sig=aux;
		before->sig=nvo;
	}
	return lista;
}

int indexOf(NODO lista, int elem)
{
    NODO aux;
    int pos=0;
    if(esVaciaLista(lista))
    {
        manejarError(6);
        exit(0);
    }else{
        aux=lista;
        while(aux!=NULL && aux->dato!=elem)
        {
            aux=aux->sig;
            pos++;
        }
        if(aux==NULL)
        {
            return (-1);
        }else{
            return pos;
        }
    }
}

NODO deleteInIndex(NODO lista, int index)
{
	int i=0;
	NODO aux,before;
	aux=lista;
    if(esVaciaLista(lista))
    {
        manejarError(6);
        exit(0);
    }else{
		if(index==0)
		{
			lista=lista->sig;
			free(aux);
		}else{
			while(i!=index)
        	{
            	i++;
	            before=aux;
    	        aux=aux->sig;
        	}
			before->sig=aux->sig;
			free(aux);
		}
	}
	return lista;
}

NODO borrar(NODO lista, int elem)
{
	NODO aux,aux2;
	if(esVaciaLista(lista))
	{
		manejarError(6);
		exit(0);
	}else{
		aux=lista;
		aux2=lista;
		while(aux!=NULL && aux->dato!=elem)
		{
			aux2=aux;
			aux=aux->sig;
		}
		if(aux==lista)
		{
			lista=aux->sig;
			free(aux);
		}else{
			aux2->sig=aux->sig;
			free(aux);
		}
		return lista;
	}
}

int Count(NODO lista)
{
	NODO aux;
	aux=lista;
	int i=0;
	while(aux->sig!=NULL)
	{
		i++;
		aux=aux->sig;
	}
	return (i+1);
}
