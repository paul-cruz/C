#ifndef _matriz_
#define _matriz_
typedef struct
{
	int fila;
	int columna;
	char** mtz;
}Matriz;
typedef Matriz* matriz;
matriz crearMatriz(int fil, int col);
matriz ponValor(matriz t, char val, int fil, int col);
char obtenValor(matriz t, int fil, int col);
int tamFila(matriz t);
int tamColum(matriz t);
void liberar(matriz t);
#endif
