#ifndef _pilaDina_
#define _pilaDina_
#define TRUE 1
#define FALSE 0

typedef struct 
{
	char nombre[15];
	int num[10];
	char estado[10];
	int numconect[10];
}telefonia;

typedef telefonia* TELEFONIA;

typedef struct Nodo_Pila
{
	//int dato;
	TELEFONIA tel;
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
TELEFONIA stackTop(PILA S);
telefonia pop(PILA S);
void push(PILA S, telefonia e);
void liberar(PILA S);
#endif
