#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <unistd.h>

void imprimir(char arr[][10],int ren,int colum);
void imprimirAux(int aux[][10],int ren,int colum);
void llenarcon0(int aux[][10], int aux2[][10], int ren, int colum);
void llenarAleatorio(char arr[][10],int ren,int colum);
void celulasVivas(char arr[][10],int aux[][10],int ren, int colum);
void matarCelulas(char arr[][10],int aux[][10],int ren, int colum);
void celulasMuertas(char arr[][10],int aux2[][10],int ren, int colum);
void revivirCelulas(char arr[][10],int aux2[][10],int ren, int colum);

int main () {
	int ren,colum,i,j;
	int repe,cont=0;
	printf("JUEGO DE LA VIDA\n");
	printf("De que tamaño quieres los renglones del tablero? ");
	scanf("%d",&ren);
	printf("De que tamaño quieres las columnas del tablero? ");
	scanf("%d",&colum);
	char arr[ren][colum];
	int aux[ren][colum], aux2[ren][colum];
	srand(time(NULL));

	llenarcon0(aux,aux2,ren,colum);
	llenarAleatorio(arr,ren,colum);

	printf("Inicia el juego\n");
	imprimir(arr,ren,colum);

	do {
		printf("\n");
		printf("****** Round %d ******",cont+1);
		//imprimirAux(aux,ren,colum);
		printf("\nVamos a matar a las celulas...\n");
		sleep(2);
		celulasVivas(arr,aux,ren,colum);
		matarCelulas(arr,aux,ren,colum);
		imprimir(arr,ren,colum);
		printf("\nVamos a revivir a las celulas...\n");
		sleep(2);
		celulasMuertas(arr,aux2,ren,colum);
		//imprimirAux(aux2,ren,colum);
		revivirCelulas(arr,aux2,ren,colum);
		imprimir(arr,ren,colum);
		llenarcon0(aux,aux2,ren,colum);
		cont++;
	}while(cont!=repe);

	return 0;
}

void imprimir(char arr[][10],int ren,int colum) {
	int i,j;
	for(i=0; i<ren;i++) {
		for(j=0;j<colum;j++) {
			printf("%c\t",arr[i][j]);
		}
		printf("\n");
	}
}

void imprimirAux(int aux[][10],int ren,int colum) {
	int i,j;
	for(i=0; i<ren;i++) {
		for(j=0;j<colum;j++) {
			printf("%d\t",aux[i][j]);
		}
		printf("\n");
	}
}

void llenarcon0(int aux[][10], int aux2[][10], int ren, int colum) {
	int i,j;
	for(i=0;i<ren;i++) //Llenamos el arreglo auxiliar de 0s
		for(j=0;j<colum;j++) {
			aux[i][j]=0;
			aux2[i][j]=0;
		}
}

void llenarAleatorio(char arr[][10],int ren,int colum) {
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

void celulasVivas(char arr[][10],int aux[][10],int ren, int colum){
	int i,j;
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
	//Comparar vidas izquierda
	for(i=0;i<ren;i++) {
		for(j=colum-1;j>0;j--) {
			if(arr[i][j]=='@') {
				if(arr[i][j]==arr[i][j-1]) {
					aux[i][j]++;
				}
			}
		}
	}
	//Compara vidas arriba
	for(i=1;i<ren;i++) {
		for(j=0;j<ren;j++) {
			if(arr[i][j]=='@') {
				if(arr[i][j]==arr[i-1][j]) {
					aux[i][j]++;
				}
			}
		}
	}
	//Compara vidas abajo
	for(i=0;i<ren;i++) {
		for(j=0;j<colum;j++) {
			if(arr[i][j]=='@') {
				if(arr[i][j]==arr[i+1][j]) {
					aux[i][j]++;
				}
			}
		}
	}
}

void matarCelulas(char arr[][10],int aux[][10],int ren, int colum){
	int i,j;
	for(i=0;i<ren;i++) {
		for(j=0;j<colum;j++) {
			if(aux[i][j]>3){ //Muere de sobrepoblacion 
				arr[i][j]='.'; 
			}
			else if(aux[i][j]<2){
				arr[i][j]='.'; //Muere de soledad
			}
		}
	}
}

void celulasMuertas(char arr[][10],int aux2[][10],int ren, int colum) {
	int i,j;
	//Comparar muertas derecha 	
	for(i=0;i<ren;i++) {
		for(j=0;j<colum-1;j++) {
			if(arr[i][j]=='.') {
				if(arr[i][j+1]=='@') {
					aux2[i][j]++;
				}
			}
		}
	}
	//Comparar muertas izquierda
	for(i=0;i<ren;i++) {
		for(j=colum-1;j>0;j--) {
			if(arr[i][j]=='.') {
				if(arr[i][j-1]=='@') {
					aux2[i][j]++;
				}
			}
		}
	}
	//Compara muertas arriba
	for(i=1;i<ren;i++) {
		for(j=0;j<ren;j++) {
			if(arr[i][j]=='.') {
				if(arr[i-1][j]=='@') {
					aux2[i][j]++;
				}
			}
		}
	}
	//Compara muertas abajo
	for(i=0;i<ren;i++) {
		for(j=0;j<colum;j++) {
			if(arr[i][j]=='.') {
				if(arr[i+1][j]=='@') {
					aux2[i][j]++;
				}
			}
		}
	}
}

void revivirCelulas(char arr[][10],int aux2[][10],int ren, int colum){
	int i,j;
	for(i=0;i<ren;i++) {
		for(j=0;j<colum;j++){
			if(aux2[i][j]>2){
				arr[i][j]='@';
			}
		}
	}
}