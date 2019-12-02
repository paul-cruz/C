#ifndef _cola_
#define _cola_
#define TRUE 1
#define FALSE 0
#define SIZE 100
typedef struct{
	char cola[SIZE];
	int primero;
	int ultimo;
	int tam;
}Cola;
typedef Cola* COLA;
void crearCola(COLA *C);
void encolar(COLA C, char e);
char desencolar(COLA C);
int esVaciaCola(COLA C);
char primero(COLA C);
int sig(int x);
#endif
