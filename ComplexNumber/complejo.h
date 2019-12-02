#ifndef _complejo_
#define _complejo_
typedef struct
{
	float real;
	float imaginario;
}Complejo;
typedef Complejo* complejo;
complejo crearComplejo();
complejo setReal(complejo c, float val);
complejo setImaginario(complejo c, float val);
float getReal(complejo c);
float getImaginario(complejo c);
complejo suma(complejo c, complejo c1);
complejo resta(complejo c, complejo c1);
complejo multiplicacion(complejo c, complejo c1);
complejo division(complejo c, complejo c1);
complejo conjugado(complejo c);

#endif
