#ifndef _cola_
#define _cola_
#define TRUE 1
#define FALSE 0
#define SIZE 100
typedef struct{
	int cola[SIZE];
	int primero;
	int ultimo;
	int tam;
}Cola;
typedef Cola* COLA;
void crearCola(COLA *C);
void encolar(COLA C, int e);
int desencolar(COLA C);
int esVaciaCola(COLA C);
int primero(COLA C);
int sig(int x);
#endif
