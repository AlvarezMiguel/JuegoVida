#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <windows.h>  //solo para windows 

void imprimir(char arr[][5],int ren,int colum);

int main () {
	int ren,colum,i,j,num,num2;
	int cont=0;
	clock_t tiempo = clock();
	printf("JUEGO DE LA VIDA\n");
	printf("De que tamaño quieres los renglones del tablero? ");
	scanf("%d",&ren);
	printf("De que tamaño quieres las columnas del tablero? ");
	scanf("%d",&colum);
	char arr[ren][colum];
	int aux[ren][colum], aux2[ren][colum];
}
