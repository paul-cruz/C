#ifndef _tablero_
#define _tablero_
typedef struct
{
	int fila;
	int columna;
	char** mtz;
}Tablero;
typedef Tablero* tablero;
tablero crearTabla(int fil, int col);
tablero ponValor(tablero t, char val, int fil, int col);
char obtenValor(tablero t, int fil, int col);
int tamFila(tablero t);
int tamColum(tablero t);
tablero iniciaObstaculo(tablero t, int posF, int posC);
int esPosibleMover(tablero t, int movF, int movC);
void liberar(tablero t);
#endif
