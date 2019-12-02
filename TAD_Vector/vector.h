#ifndef _arreglo_
#define _arreglo_
typedef struct
{
	int n;
	int* arreglo;
}Vector;
typedef Vector* vector;
vector crearVector(int n);
int obtenComponente(vector v, int index);
vector ponComponente(vector v, int index, int val);
int tamanio(vector v);
void liberar(vector v);
#endif
