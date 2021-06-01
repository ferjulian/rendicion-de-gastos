#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float montoViatico (float valorKm, float gastosPeaje, float gastosComida){
	
	float viaticoTotal = valorKm + gastosPeaje + gastosComida;
	
	return viaticoTotal;
}



void empleadosV(int contV){
	printf("Cantidad de empleados categoria V , con mas de 2000Km recorridos: %i", contV);
}



main(){
	
	char categoria;
	int codigoLegajo;
	float km;
	float gastosPeaje;
	float gastosComida;
	float anticipo;
	char respuesta[3];
	int contV;
	

	
	
	do{
		
		
			/*Ingreso de datos*/
	
	printf("ingrese categoria ");
	fflush(stdin);
	scanf("%c", &categoria);
	
	/*printf("ingrese codigo de legajo ");
	fflush(stdin);
	scanf("%i", codigoLegajo);*/
	
	printf("ingrese kilometros recorridos ");
	fflush(stdin);
	scanf("%f", &km);
	
	printf("ingrese gastos de peaje ");
	fflush(stdin);
	scanf("%f", &gastosPeaje);
	
	printf("ingrese gastos de comida ");
	fflush(stdin);
	scanf("%f", &gastosComida);
	
	if(categoria == 'v'){
	printf("ingrese anticipo ");
	fflush(stdin);
	scanf("%f", &anticipo);
	}else{
		anticipo = 0;
	}
	
	
	
	/*Km valorizados*/
	
	float valorKm;
	float valorTope;
	float valorRestante;
	
	if(km <= 2000){
		
		valorKm = km * 10; 
	}else{
		
		valorTope = 2000*10;
		valorRestante = km - 2000;
		
		valorKm = valorTope + (valorRestante * 5);
	}
	
	
		
	/*Viatico*/
	
	float viaticoTotal = montoViatico(valorKm, gastosPeaje, gastosComida);
	
	float viaticoAnticipo = viaticoTotal - anticipo;
	
	if (viaticoAnticipo < 0){
		
	printf("Importe a devolver por el empleado: %f", viaticoAnticipo );
		
	}else{

	printf("Importe a pagar por la empresa: %f", viaticoAnticipo );	
	}
	

	
	/*Cantidad de empleados categoria V*/
	
	if(categoria == 'v' && km > 2000){
	
	contV = contV + 1;
	
	}
		
		printf(" \n Desea seguir registrando empleados? ");
		fflush(stdin);
		scanf("%s", respuesta);
		
	} while(strcmp(respuesta,"SI") == 0);
	
	
	empleadosV(contV);
	
}
