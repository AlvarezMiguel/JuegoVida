#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//#include <windows.h>  //solo para windows 

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
	
	srand(time(NULL));
	
	for(i=0;i<ren;i++) //Llenamos el arreglo auxiliar de 0s
		for(j=0;j<colum;j++) {
			aux[i][j]=0;
			aux2[i][j]=0;
		}
	
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
	
	imprimir(arr,ren,colum);
	
   //Comparar vidas derecha 	
	for(i=0;i<ren;i++) {
		for(j=0;j<colum-1;j++) {
			if(arr[i][j]=='@') {
				if(arr[i][j]==arr[i][j+1]) {
					aux[i][j]++;
				}
			}
		}
	}
	
	
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

