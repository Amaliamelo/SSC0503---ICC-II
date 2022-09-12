#include <stdio.h>
#include <stdlib.h>
int **lerMatriz(int *vetor, int n);
int *lerVetor(int n);
void liberarMemoria(int **v, int n);
void insertion(int *v, int n);
void merge(int *v, int n);
void merge2(int *a, int c, int f, int *b, int *vetorTC);


int main(){
    int q;
    int *n;
    int **v;
    int **v2;//vetor auxiliar para o merge
    scanf("%d", &q);
    n = lerVetor(q);
    v = lerMatriz(n,q);
    //leitura "manual" do vetor auxiliar, criando ele a partir do vetor principal
    v2 = malloc(q*sizeof(int*));
	for(int i=0;i<q;i++){
		v2[i]=malloc(n[i]*sizeof(int));
	}
    for(int i=0; i<q; i++){
        for (int j=0;j<n[i];j++){
            v2[i][j] = v[i][j];
        }
    }

    //fazendo a ordenação dos vetores
    for(int i=0; i<q; i++){
        insertion(v[i], n[i]);
        merge(v2[i], n[i]);
    }
    //Liberando a memoria
    liberarMemoria(v,q);
    liberarMemoria(v2,q);
    return 0;
}


int **lerMatriz(int *vetor, int n){
	int **matriz = malloc(n*sizeof(int*));
	for(int i=0;i<n;i++){
        //ponteiros que apontam para um vetor
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


void liberarMemoria(int **v, int n){
    for(int i=0; i<n; i++){
        free(v[i]);
    }
    free(v);
}


void insertion(int *v, int n){
    int t=0;
    int c=0;
    for(int p=1; p<n; p++){
        int x = v[p];
        int i = p-1;
        t++;
        while(i>=0 && x<v[i]){
            c++;
            v[i+1] = v[i];
            t++;
            i--;
        }
        if(i>=0 && x>=v[i]) c++;
        v[i+1] = x;
        t++;
    }
    printf("I %d %d %d\n", n, t, c);
}


void merge(int *v, int n){
    int vetorTC[2] = {0,0}; //para contabilizar as trocas e comparações
    int *b = (int *) malloc (sizeof(int)*n);
    merge2(v,0,n-1,b,vetorTC);
    printf("M %d %d %d\n", n, vetorTC[0], vetorTC[1]);
    free(b);
}


void merge2(int *a, int c, int f, int *b, int *vetorTC){
    if(c>=f){
        return;
    }
    int m = (c+f)/2;
    merge2(a, c, m, b, vetorTC);
    merge2(a,m+1,f,b, vetorTC);
    int i1 = c;
    int i2 = m+1;
    int j = 0;
    while(i1<=m && i2<=f){
         vetorTC[1]++;
        if(a[i1] <= a[i2]){
            vetorTC[0]++;
            b[j] = a[i1];
            i1++;
        }
        else{
            vetorTC[0]++;
            b[j] = a[i2];
            i2++;
        }
        j++;
    }
    while(i1<=m){
        vetorTC[0]++;
        b[j] = a[i1];
        i1++;
        j++;
    }
    while(i2<=f){
        vetorTC[0]++;
        b[j] = a[i2];
        i2++;
        j++;
    }
    j = 0;
    for(int i=c;i<=f;i++){
        vetorTC[0]++;
        a[i] = b[j];
        j++;
    }
}