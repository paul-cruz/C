#ifndef __ListaEnlazada__
#define __ListaEnlazada__

#define true 1
#define false 0

typedef struct Nodo
{
	int dato;
	struct Nodo* sig;
}Nodo;

typedef Nodo* NODO;

NODO crearLista();
int esVaciaLista(NODO lista);
NODO crearNodo();
void mostrarLista(NODO lista);
int buscar(NODO lista, int elem);
NODO insertar(NODO lista, int elem);
NODO borrar(NODO lista, int elem);
NODO insertInIndex(NODO lista,int elem, int index);
NODO deleteInIndex(NODO lista, int index);
int indexOf(NODO lista, int elem);
int getFirst(NODO lista);
int getLast(NODO lista);
int getByIndex(NODO lista,int index);
int Count(NODO lista);

#endif
