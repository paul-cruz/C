#ifndef _pila_
#define _pila_
#define TRUE 1
#define FALSE 0
#define TAM 10
typedef struct{
	char* pila[TAM];
	int tope;
}Pila;
typedef Pila* PILA;
void crearPila(PILA* S);
int stackEmpty(PILA S);
char* pop(PILA S);
void push(PILA S, char* e);
char* stackTop(PILA S);
#endif
