#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <unistd.h>

void imprimir(char arr[][5],int ren,int colum);
void imprimirAux(int aux[][5],int ren,int colum);
void llenarcon0(int aux[][5], int aux2[][5], int ren, int colum);
void llenarAleatorio(char arr[][5],int ren,int colum);

int main () {
	int ren,colum,i,j;
	int cont=0;
	printf("JUEGO DE LA VIDA\n");
	printf("De que tamaño quieres los renglones del tablero? ");
	scanf("%d",&ren);
	printf("De que tamaño quieres las columnas del tablero? ");
	scanf("%d",&colum);
	char arr[ren][colum];
	int aux[ren][colum], aux2[ren][colum];
	srand(time(NULL));

	llenarcon0(aux,aux2,ren,colum);
	//imprimirAux(aux,ren,colum);
	llenarAleatorio(arr,ren,colum);
	imprimir(arr,ren,colum);

	return 0;
}

void imprimir(char arr[][5],int ren,int colum) {
	int i,j;
	for(i=0; i<ren;i++) {
		for(j=0;j<colum;j++) {
			printf("%c\t",arr[i][j]);
		}
		printf("\n");
	}
}

void imprimirAux(int aux[][5],int ren,int colum) {
	int i,j;
	for(i=0; i<ren;i++) {
		for(j=0;j<colum;j++) {
			printf("%d\t",aux[i][j]);
		}
		printf("\n");
	}
}

void llenarcon0(int aux[][5], int aux2[][5], int ren, int colum) {
	int i,j;
	for(i=0;i<ren;i++) //Llenamos el arreglo auxiliar de 0s
		for(j=0;j<colum;j++) {
			aux[i][j]=0;
			aux2[i][j]=0;
		}
}

void llenarAleatorio(char arr[][5],int ren,int colum) {
	int i,j,num,num2;
	srand(time(NULL));
	for(i=0;i<ren;i++) //Hacemos . todo el arreglo
		for(j=0;j<colum;j++) 
			arr[i][j]='.';
	
	for(i=0;i<ren;i++){ //Primer arreglo con vidas aleatoreas
		for(j=0;j<colum;j++) {
			num=rand()% ren;
			num2=rand()% colum;
			arr[num][num2]='@';
		}
	}
}
