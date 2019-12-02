#ifndef _pilaDina_
#define _pilaDina
#define TRUE 1
#define FALSE 0

typedef struct Nodo_Pila
{
	int dato;
	struct Nodo_Pila* anterior;
}Nodo_Pila;

typedef struct
{
	struct Nodo_Pila* tope;
}Pila;

typedef Pila* PILA;

PILA crearPila();
Nodo_Pila* crearNodoPila();
int stackEmpty(PILA S);
int stackTop(PILA S);
int pop(PILA S);
void push(PILA S, int e);
#endif
