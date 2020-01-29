#include <stdlib.h>
#include <stdio.h>

int main(){
	
	int a, b; // a e b são os pontos iniciais de 2 amigos, cada um se encontra em um dos pontos

	scanf("%d%d", &a, &b);

	int NC = 0, dist = (b-a); // NC = nível de casaço, dist = distancia
	
	if(dist>1){
		int aux = dist/2;
		while(aux>0){
			NC += aux;
			aux--;
		}
	
		if((b-a)%2 == 1) NC = NC*2 + (dist/2+1); // se a distancia dos dois pontos for impar, um amigo andará uma casa a mais que o outro
		else NC = NC*2;		
	}
	else NC = dist;

	printf("%d\n", NC);

	return 0;
}