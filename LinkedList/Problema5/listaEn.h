#ifndef __ListaEnlazada__
#define __ListaEnlazada__

#define true 1
#define false 0

typedef struct Nodo
{
	char dato;
	struct Nodo* sig;
}Nodo;

typedef Nodo* NODO;

NODO crearLista();
int esVaciaLista(NODO lista);
NODO crearNodo();
void mostrarLista(NODO lista);
int buscar(NODO lista, char elem);
NODO insertar(NODO lista, char elem);
NODO borrar(NODO lista, char elem);
NODO insertInIndex(NODO lista,char elem, int index);
NODO deleteInIndex(NODO lista, int index);
int indexOf(NODO lista, char elem);
char getFirst(NODO lista);
char getLast(NODO lista);
char getByIndex(NODO lista,int index);
int Count(NODO lista);

#endif
