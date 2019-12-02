#include <stdio.h>
#include <stdlib.h>

struct asignacion
{
	float transporte;
	float comida;
	float vacaciones;
};


struct deduccion
{
	float seguro;
	float AH;
};


struct empleado
{
	int codigo;
	int activo;
	char sexo;
	float sueldo_hora;
	int horas_trab;
	struct asignacion* AS;
	struct deduccion DE;
};

void crear_empleado(struct empleado**);
void leer_empleado(struct empleado*);
void calcular_sueldo(struct empleado*, float*);
void imprimir_sueldo(float*);
void liberar(struct empleado*);

void main()
{
	float sueldo_total=0.0f;
	struct empleado* emp;
	crear_empleado(&emp);
	leer_empleado(emp);
	calcular_sueldo(emp, &sueldo_total);
	imprimir_sueldo(&sueldo_total);
	liberar(emp);
}


void crear_empleado(struct empleado** EMP)
{
	*EMP=(struct empleado*)malloc(sizeof(struct empleado));
	if(*EMP==NULL)
	{
		printf("No hay memoria disponible\n");
		exit(0);
	}else{
		(*EMP)->AS=(struct asignacion*)malloc(sizeof(struct asignacion));
	}
}

void leer_empleado(struct empleado* EMP)
{
	printf("Introduzca los datos del empleado: \n");
	printf("Codigo: ");
	scanf("%d",&EMP->codigo);
	printf("Activo: ");
	scanf("%d",&EMP->activo);
	printf("Sexo (M/F): ");
	scanf("%c",&EMP->sexo);
	getchar();
	printf("Sueldo por hora: ");
	scanf("%f",&EMP->sueldo_hora);
	printf("Horas trabajadas: ");
	scanf("%d",&EMP->horas_trab);
	printf("Transporte: ");
	scanf("%f",&EMP->AS->transporte);
	printf("Comida: ");
	scanf("%f",&EMP->AS->comida);
	printf("Vacaciones: ");
	scanf("%f",&EMP->AS->vacaciones);
	printf("Seguro: ");
	scanf("%f",&EMP->DE.seguro);
	printf("Ahorro habitacional: ");
	scanf("%f",&EMP->DE.AH);
}

void calcular_sueldo(struct empleado* EMP, float* total)
{
	float SH= EMP->sueldo_hora;
	int HT= EMP->horas_trab;
	float A= (EMP->AS->transporte)+(EMP->AS->comida)+(EMP->AS->vacaciones);
	float D= (EMP->DE.seguro)+(EMP->DE.AH);
	*total=(SH*HT)+A-D;
}

void imprimir_sueldo(float* sueldo)
{
	printf("El sueldo total es: %.2f\n",*sueldo);
}

void liberar(struct empleado* EMP)
{
	free(EMP);
}
