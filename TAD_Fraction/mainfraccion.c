#include <stdio.h>
#include "fraccion.h"

void manejarError(int);
fraccion solicitarDatos(fraccion);
void mostrar(fraccion,fraccion,fraccion);

void main()
{
	fraccion f1,f2,fp,fs,fa;
	f1=crearFraccion();
	f2=crearFraccion();
	
	f1=solicitarDatos(f1);
	f2=solicitarDatos(f2);
	
	fp=producto(f1,f2);
	fs=suma(f1,f2);
	fa=Amplificar(f1,7);
	
	mostrar(fp,fs,fa);
}

fraccion solicitarDatos(fraccion f)
{
	int num,denom;
	printf("Introduzca el numerador: ");
	scanf("%d",&num);
	printf("Introduzca el denominador: ");
	scanf("%d",&denom);
	f=setNum(f,num);
	f=setDenom(f,denom);
	return f;
}

void mostrar(fraccion fp, fraccion fs, fraccion fa)
{
	printf("El producto es: %d/%d\n",getNum(fp),getDenom(fp));
	printf("La suma es: %d/%d\n",getNum(fs),getDenom(fs));
	printf("La amplificacion es: %d/%d\n",getNum(fa),getDenom(fa));
}

void manejarError(int e)
{
	char* errores[]={"No hay memoria disponible!"};
	printf("%s",errores[e]);
}
