#ifndef __colaDinamica__
#define __colaDinamica__
#define TRUE 1
#define FALSE 0

typedef struct Nodo_Cola
{
	int dato;
	struct Nodo_Cola* sig;
}Nodo_Cola;

typedef struct
{
	struct Nodo_Cola* primero;
	struct Nodo_Cola* ultimo;
}Cola;

typedef Cola* COLA;

COLA crearCola();
Nodo_Cola* crearNodoCola();
int esVaciaCola(COLA C);
void encolar(COLA C, int e);
int desencolar(COLA C);
int primero(COLA C);

#endif
