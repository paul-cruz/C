#ifndef _pila_
#define _pila_
#define TRUE 1
#define FALSE 0
#define TAM 100
typedef struct{
	int pila[TAM];
	int tope;
}Pila;
typedef Pila* PILA;
void crearPila(PILA* S);
int stackEmpty(PILA S);
int pop(PILA S);
void push(PILA S, int e);
int stackTop(PILA S);
#endif
