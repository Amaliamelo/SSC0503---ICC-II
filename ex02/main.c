#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int main(){

    //lendo numero de vetores
    int q;
    scanf("%d", &q);
    
    //lendo qtd elementos
    int n[q];
    for(int i=0;i<q;i++){
         scanf("%d", &n[i]);
    }

    //lendo vetores
   for(int i=0;i<q;i++){
        for(int j=0;j<n[i];j++){
            scanf("%d", &vetores[i][j]);
        }
    }

    //mostrano leituras
    printf("Q:%d\n", q);
    
    printf("N: ");
    for(int i=0;i<q;i++){
        printf("%d ", n[i]);
    }
    printf("\n");
    //lendo vetores
   for(int i=0;i<q;i++){
        printf("\n");
        for(int j=0;j<n[i];j++){
            printf("%d", vetores[j]);
        }
    }
}