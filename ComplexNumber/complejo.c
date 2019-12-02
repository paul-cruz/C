#include <stdio.h>
#include <stdlib.h>
#include "complejo.h"

void manejarError(int);

complejo crearComplejo()
{
	complejo c;
	c=(complejo)malloc(sizeof(Complejo));
	if(c==NULL)
	{
		manejarError(0);
		exit(0);
	}
	return c;
}

complejo setReal(complejo c, float val)
{
	c->real=val;
	return c;
}

complejo setImaginario(complejo c, float val)
{
	c->imaginario=val;
	return c;
}

float getReal(complejo c)
{
	return (c->real);
}

float getImaginario(complejo c)
{
	return (c->imaginario);
}

complejo suma(complejo c, complejo c1)
{
	complejo cs;
	cs=crearComplejo();
	cs=setReal(cs, getReal(c)+getReal(c1));
	cs=setImaginario(cs, getImaginario(c)+getImaginario(c1));
	return cs;
}

complejo resta(complejo c, complejo c1)
{

	complejo cs;
        cs=crearComplejo();
        cs=setReal(cs, getReal(c)-getReal(c1));
        cs=setImaginario(cs, getImaginario(c)-getImaginario(c1));
        return cs;
}

complejo multiplicacion(complejo c, complejo c1)
{
	complejo cr;
	cr=crearComplejo();
	cr=setReal(cr,(getReal(c)*getReal(c1))+(getImaginario(c)*getImaginario(c1)*(-1)));
	cr=setImaginario(cr,(getReal(c)*getImaginario(c1))+(getReal(c1)*getImaginario(c)));
	return cr;
}

complejo division(complejo c, complejo c1)
{
	complejo cd;
	cd=crearComplejo();
	cd=setReal(cd,(getReal(c1)*getReal(c)+getImaginario(c)*getImaginario(c1))/(getReal(c1)*getReal(c1)-getImaginario(c1)*getImaginario(c1)));
	cd=setImaginario(cd,(getImaginario(c)-(getImaginario(c1))*((getReal(c1)*getReal(c)+getImaginario(c)*getImaginario(c1))/(getReal(c1)*getReal(c1)-getImaginario(c1)*getImaginario(c1)))/getReal(c)));
	return cd;
}

complejo conjugado(complejo c)
{
	c=setImaginario(c,getImaginario(c)*(-1.0f));
	return c;
}
