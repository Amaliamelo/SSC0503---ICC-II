#include <stdio.h>
#include <string.h>
void lerVetor(int *v, int n);
void printVetor(int *v, int n);
void selecao(int *v, int n);
void bolha(int *v, int n);

int main(){
    int n;
    int v[1000];
    char s[10];
    scanf("%s", s);
    scanf("%d", &n);
    lerVetor(v,n);
    if(strcmp(s,"selecao")==0) selecao(v,n);
    if(strcmp(s,"bolha")==0) bolha(v,n);
    printVetor(v,n);
    return 0;
}

void lerVetor(int *v, int n){
    for(int x=0;x<n;x++) scanf("%d", &v[x]);
}

void printVetor(int *v, int n){
    for(int x=0;x<n;x++) printf("%d ", v[x]);
}

void selecao(int *v, int n){
    int menor, posicao, aux, flag;
    for(int i=0; i<n-1; i++){
        menor = v[i];
        flag = 0;
        posicao = i;
        for(int j=i+1; j<n; j++){
            printf("C %d %d\n", posicao, j);
            if(v[j]<menor){
                menor = v[j];
                posicao = j;
                flag = 1;
            }
        }
        aux = v[i];
        v[i] = menor;
        if(flag==1){
            v[posicao] = aux;
            printf("T %d %d\n", i, posicao);
        }
    }
}

void bolha(int*v, int n){
    int ultposicao=n;//ultima posição que troca
    for(int i=ultposicao;i>0;i--){
        int posicao=0;
        for(int j=0;j<ultposicao-1;j++){
            printf("C %d %d\n", j, j+1);
            if(v[j] > v[j+1]){
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
                posicao = j+1;
                printf("T %d %d\n", j, j+1);
            }
        }
        ultposicao = posicao;
        if(ultposicao==0) break;
    }
}