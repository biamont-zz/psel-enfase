#include <stdlib.h>
#include <stdio.h>

void bubble_sort (int* vetor, int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {

            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main(){
	
	int tam, max=0, prev, prox, cnt=0;
	scanf("%d", &tam);

	int* vector = (int*)calloc(tam, sizeof(int));
	for(int i=0; i<tam; i++) scanf("%d", &vector[i]);

	bubble_sort(vector, tam);

	for(int i=0; i<tam-1; i++){
		prev = i;
		for(int j=i+1; j<tam; j++){
			prox = j;
			cnt = 0;
			for(int k=0; k<tam; k++){
				if(vector[prev]+vector[prox] == vector[k]){
					//printf("vector[%d]+vector[%d] = vector[%d]\n", prev, prox, k);
					cnt++;
					prev = prox;
					prox = k;
					if(cnt > max) max = cnt;
				}
			}
		}
	}

	if(max > 0) printf("%d\n", max+2);
	else printf("%d\n", max);

	return 0;
}