#include<stdio.h>
#include <string.h>

//declarando metodos de ordenação
void shell(int v[], int n[]);
void quick(int v[], int f, int l);

int main(){
    int **subvetores;

    //Lendo as Entradas
    int N;
    scanf("%d/n", &N);

    int v[N];
    for(int i=0; i<N; i++){
        scanf("%d", &v[i]);
    }

    //Verificando Entradas 
    /*printf("%d\n", N);

    int V[N];
    for(int i=0; i<N; i++){
        printf("%d", v[i]);
    }*/

    //criando Subvetores de v[]
    for(int i=0; i<N; i++){
        subvetores = lerMatriz(v,n);   
    }

    /*
    for(int i=0; i<N; i++){
        for(int j=0;j<i;j++){
            printf("V[%d]: %d ", i, subvetor[j]);
        }
        printf("\n");
    }*/

    return 0;
}

int **lerMatriz(int *vetor, int q){
    int **matriz = malloc(q*sizeof(int*));
    for(int i=0;i<q;i++){
        matriz[i] = lerVetor(vetor[i]);
    }
    return matriz;
}
int *lerVetor(int n){
    int *vetor = malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&vetor[i]);
    }
    return vetor;
}

void imprimir_matriz(int **mat, int linhas, int colunas)
{

	for (int i = 0; i < linhas; i++)
	{
		for (int j = 0; j < colunas; j++)
		{
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
}