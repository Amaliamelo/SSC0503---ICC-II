#include <stdio.h>
#include <string.h>

void selecao(int *v, int n);
void bolha(int *v, int n);

void selecao(int *v, int n){
    int menor, posicao, aux, flag=0;
    for(int i=0;i<n-1;i++){
        menor=v[i];
        flag = 0;
        posicao = i;
        for(int j=i+1;j<n;j++){
            printf("C %d %d\n", posicao, j);
            if(v[j]<menor){
                menor=v[j];
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

void bolha(int *v, int n){
    int aux, ultposicao=n;
    for(int j=ultposicao;j>0;j--){
        int posicao=0;
        for(int i=0;i<ultposicao-1;i++){
            printf("C %d %d\n", i, i+1);
            if(v[i+1]<v[i]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1]=aux;
                posicao = i+1;
                printf("T %d %d\n", i, i+1);
            }
        }
         ultposicao = posicao;
        if(ultposicao==0) break;
    }
}

int main(){
    char metodo[100];
    int n;

    scanf("%s", metodo);//lendo metodo
    
    scanf("%d", &n);//lendo qtd elementos

    int vetor[n];

    for(int i=0;i<n;i++){
        scanf("%d", &vetor[i]);
    } //lendo vetor

    if((strcmp(metodo,"selecao")==0)){
        selecao(vetor, n);
    }
    else{
        bolha(vetor, n);
    }


    for(int i=0;i<n;i++){
        printf("%d ", vetor[i]);
    }
}