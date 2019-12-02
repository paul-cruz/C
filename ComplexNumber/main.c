#include <stdlib.h>
#include <stdio.h>
#include "complejo.h"

complejo solicitarDatos(complejo);
void imprimir(complejo,complejo,complejo,complejo,complejo,complejo);
void manejarError(int);

int main(void)
{
	complejo c1,c2,cs,cr,cd,cm,cc1,cc2;
	c1=crearComplejo();
	c2=crearComplejo();
	c1=solicitarDatos(c1);
	c2=solicitarDatos(c2);
	cs=suma(c1,c2);
	cr=resta(c1,c2);
	cd=division(c1,c2);
	cm=multiplicacion(c1,c2);
	cc1=conjugado(c1);
	cc2=conjugado(c2);
	imprimir(cs,cr,cd,cm,cc1,cc2);
	return 0;
}

complejo solicitarDatos(complejo c)
{
	float aux=0.0f;
	printf("Ingrese la parte real: ");
	scanf("%f",&aux);
	c=setReal(c,aux);
	printf("Ingrese la parte imaginaria: ");
	scanf("%f",&aux);
	c=setImaginario(c,aux);
	return c;
}

void imprimir(complejo cs,complejo cr,complejo cd,complejo cm,complejo cc1, complejo cc2)
{
	printf("Suma: %.2f + %.2f i\n",getReal(cs),getImaginario(cs));
        printf("Resta: %.2f + %.2f i\n",getReal(cr),getImaginario(cr));
        printf("Multiplicacion: %.2f + %.2f i\n",getReal(cm),getImaginario(cm));
        printf("Division: %.2f + %.2f i\n",getReal(cd),getImaginario(cd));
        printf("Conjugado de c1: %.2f + %.2f i\n",getReal(cc1),getImaginario(cc1));
        printf("Conjugado de c2: %.2f + %.2f i\n",getReal(cc2),getImaginario(cc2));
}

void manejarError(int e)
{
	char* errores[]={"No hay memoria disponible..."};
	printf("%s",errores[e]);
} 
