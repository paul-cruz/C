#ifndef _fraccion_
#define _fraccion_
typedef struct
{
	int numerador;
	int denominador;
}Fraccion;
typedef Fraccion* fraccion;
fraccion crearFraccion();
fraccion setNum(fraccion f, int val);
fraccion setDenom(fraccion f, int val);
int getNum(fraccion f);
int getDenom(fraccion f);
fraccion producto(fraccion f, fraccion f1);
fraccion suma(fraccion f, fraccion f1);
fraccion Amplificar(fraccion f, int val);
#endif
