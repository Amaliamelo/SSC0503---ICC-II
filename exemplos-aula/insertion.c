#include<stdio.h>

void ins(int *a, int n){
    for(int p=1;p<n;p++){
        int x = a[p];
        int i = p-1;
        while(i>=0 && x<a[i]){
            a[i+1]=a[i];
            i--;
        }
    
    a[i+1]=x;
    }
}

void printVetor(int *v, int n){
    for(int x=0;x<n;x++) printf("%d ", v[x]);
}

int main(){
    int n;

    scanf("%d", &n);//lendo qtd elementos

    int vetor[n];

    for(int i=0;i<n;i++){
        scanf("%d", &vetor[i]);
    } //lendo vetor  

    ins(vetor, n);

    printVetor(vetor,n);
}