#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int **lerMatriz(int *vetor, int n);
int *lerVetor(int n);
void ins(int *a, int n);

int main(){
    int **v;

    //lendo numero de vetores
    int q;
    scanf("%d", &q);
    
    //lendo qtd elementos
    int n[q];
    for(int i=0;i<q;i++){
         scanf("%d", &n[i]);
    }

    //lendo vetores
    v = lerMatriz(n,q);
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

void ins(int *a, int n){
    int t=0;
    int c=0;
    for(int p=1;p<n;p++){
        int x = a[p];
        int i = p-1;
        t++;
        while(i>=0 && x<a[i]){
            a[i+1]=a[i];
            c++;
            t++;
            i--;
        }
        if(i>=0 && x>=a[i]) c++;
        a[i+1]=x;
        t++;
    }
    printf("I %d %d %d\n", n, t, c);
}