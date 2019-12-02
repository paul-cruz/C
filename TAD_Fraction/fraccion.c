#include <stdlib.h>
#include "fraccion.h"

void manejarError(int);

fraccion crearFraccion()
{
	fraccion f;
	f=(fraccion)malloc(sizeof(Fraccion));
	if(f==NULL)
	{
		manejarError(0);
		exit(0);
	}
	return f;
}

fraccion setNum(fraccion f, int val)
{
	f->numerador=val;
	return f;
}

fraccion setDenom(fraccion f, int val)
{
	f->denominador=val;
	return f;
}

int getNum(fraccion f)
{
	return (f->numerador);
}

int getDenom(fraccion f)
{
	return (f->denominador);
}

fraccion producto(fraccion f, fraccion f1)
{
	fraccion fp;
	fp=crearFraccion();
	fp=setNum(fp,getNum(f)*getNum(f1));
	fp=setDenom(fp,getDenom(f)*getDenom(f1));
	return fp;
}

fraccion Amplificar(fraccion f, int val)
{
	fraccion fa;
	fa=crearFraccion();
	fa=setNum(fa,getNum(f)*val);
	fa=setDenom(fa,getDenom(f)*val);
	return fa;
}

fraccion suma(fraccion f, fraccion f1)
{
	fraccion fs;
	fs=crearFraccion();
	if(getDenom(f)==getDenom(f1))
	{
		fs=setNum(fs,getNum(f)+getNum(f1));
		fs=setDenom(fs,getDenom(f));
	}else{
		fs=setDenom(fs,getDenom(f)*getDenom(f1));
		fs=setNum(fs,(getNum(f)*getDenom(f1))+(getNum(f1)*getDenom(f)));
	}
	return fs;
}
