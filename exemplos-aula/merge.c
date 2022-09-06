#include<stdio.h>
#include<stdlib.h>

void merge(int *a, int n);
void merge2(int *a, int c, int f, int *b);


void merge(int *a, int n){
    int *b = (int*)malloc(sizeof(int)*n);
    merge2(a,0,n-1,b);
    free(b);
}

void merge2( int *a, int c, int f, int *b){
    if(c>=f){
        return;
    }
    int m=(c+f)/2;
    merge2(a,c,m,b);
    merge2(a, m+1,f,b);
    int i1=c;
    int i2 = m+1;
    int j=0;
    while(i1<=m && i2<= f){
        if(a[i1]<=a[i2]){
            b[j]=a[i1];
            i1++;
        }
        else{
            b[j]=a[i2];
            i2++;
        }
        j++;
    }
    while(i1<=m){
        b[j]=a[i1];
        i1++;
        j++;
    }
    while(i2<=f){
        b[j]=a[i2];
        i2++;
        j++;
    }
    j=0;
    for(int i=c;i<=f;i++){
        a[i]=b[j];
        j++;
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

    merge(vetor, n);

    printVetor(vetor,n);
}