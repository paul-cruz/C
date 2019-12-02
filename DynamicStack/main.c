#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"pilaDinamica.h"

void leerDatos(PILA);
void estado_disponible(PILA);
void numMovil(PILA);
void nombresM(PILA);
void mostrar(PILA);

void main()
{
	PILA S;
	S=crearPila();
	leerDatos(S);
    estado_disponible(S);
    numMovil(S);
    nombresM(S);
    liberar(S);
}

void leerDatos(PILA S)
{
	telefonia aux;
    char numaux[10], numconectaux[10];
	int a=1;
	do
	{
		printf("Introduzca los valores de la telefonia:\n");
		printf("Nombre del cliente: ");
		scanf("%s",aux.nombre);
		getchar();
		printf("Número celular: ");
		scanf("%s", numaux);
        for(int i=0; i<10;i++)
        {
            aux.num[i]=(numaux[i]-48);
        }
		printf("Estado del celular: ");
		scanf("%s", aux.estado);
		if(strcmp(aux.estado,"disponible"))
		{
			printf("Conectado con: ");
			scanf("%s", numconectaux);
			for(int i=0; i<10;i++)
            {
               aux.numconect[i]=(numconectaux[i]-48);
            }
		}else{
			for(int k=0;k<10;k++)
			{
				aux.numconect[k]=0;
			}
		}
		push(S,aux);
		printf("Desea agregar otra telefonia?:\n1.Si\n2.No\n");
		scanf("%d",&a);
	}while(a!=2);
		
}

void estado_disponible(PILA S)
{
    telefonia aux;
	PILA D;
    D=crearPila();
    PILA pilauax;
    pilauax=crearPila();
    while(stackEmpty(S)==FALSE)
	{
		aux=pop(S);
        if(!strcmp(aux.estado,"disponible"))
        {
		    push(D,aux);
            push(pilauax,aux);
        }else{
               push(pilauax,aux);
        }
	}
    while(stackEmpty(pilauax)==FALSE)
	{
		aux=pop(pilauax);
        push(S,aux);
	}
    printf("\n-----------------Telefonias Registradas------------\n");
	mostrar(S);
    printf("-----------------Telefonias con estado disponible------------\n");
    mostrar(D);
}

void numMovil(PILA S)
{
    int cont=0;
    char numero[10], numaux[10];
    char *num;
    num=(char*)malloc(10);
    telefonia a;
    PILA aux;
    aux=crearPila();
    printf("Ingrese el número a buscar: ");
    scanf("%s",numero);
    strcpy(num,numero);
    while(stackEmpty(S)==FALSE)
	{
		a=pop(S);
		push(aux,a);
        for(int i=0;i<10;i++)
        {
            numaux[i]=(a.numconect[i]+48);
        }
        if(!strcmp(numaux,num))
        {
            cont++;
        }
	}
    while(stackEmpty(aux)==FALSE)
	{
		a=pop(aux);
		push(S,a);
	}
    printf("El número %s se ha conectado %d veces\n",num,cont);
}

void nombresM(PILA S)
{
    int i=0,n=0,r;
    telefonia aux[100];
    telefonia aux2;
    PILA pil;
    pil=crearPila();
    while(stackEmpty(S)==FALSE)
    {
        aux[i]=pop(S);
        push(pil,aux[i]);
        i++;
        n++;
    }
    for(i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            r=strcmp(aux[i].nombre,aux[j].nombre);
            if(r>0)
            {
                aux2=aux[i];
                aux[i]=aux[j];
                aux[j]=aux2;
            }
        }
    }   
    for(i=0;i<n;i++)
    {
         push(S,aux[i]); 
    }
    printf("------------Telefonias ordenadas alfabeticamente-----------\n");
    mostrar(S);
}

void mostrar(PILA S)
{
	telefonia a;
	PILA S1;
	S1=crearPila();
	while(stackEmpty(S)==FALSE)
	{
		a=pop(S);
		push(S1,a);
	}
	printf("Las telefonias son:\n");
	while(stackEmpty(S1)==FALSE)
	{
		a=pop(S1);
        push(S,a);
		printf("Nombre del cliente: %s\n", a.nombre);
		printf("Número: ");
		for(int i=0; i<10;i++)
			printf("%d",a.num[i]);
		printf("\nEstado: %s\n", a.estado);
        if(strcmp(a.estado,"disponible"))
        {
		    printf("Número conectado: ");
		    for(int i=0; i<10;i++)
			    printf("%d",a.numconect[i]);
        }
		printf("\n");
	}
	printf("\n");
}

void manejarError(int e)
{
	char * errores[]={"No hay memoria disponible...\n","Error en la funcion PUSH: Pila Llena ...\n\n","Error en la funcion POP: Pila Vacia ...\n\n","\n\n Division por CERO\n"};
	printf("%s",errores[e]);
}
