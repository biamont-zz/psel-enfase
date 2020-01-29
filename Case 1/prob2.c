#include <stdlib.h>
#include <stdio.h>

char checkResult(char jogo[3][3]){
	
	//verifica diagonais
	if(jogo[0][0] == jogo[1][1] == jogo[2][2]) return jogo[1][1];
	if(jogo[2][0] == jogo[1][1] == jogo[0][2]) return jogo[1][1];

	//verifica linhas e colunas
	int linX, linY, colX, colY; // contadores de X's e Y's por linha e coluna
	
	for(int i=0; i<3; i++){
		
		linX = 0;
		linY = 0;
		colX = 0;
		colY = 0;

		for(int j=0; j<3; j++){
			if(jogo[i][j] == 'X') linX++;
			else linY++;

			if(jogo[j][i] == 'X') colX++;
			else colY++;

			if(linX == 3 || colX ==3) return 'X'; // 'X' venceu;
			if(linY == 3 || colY ==3) return '0'; //'Y' venceu;
		}	
	}

	return '.';
}

int main(){

	char jogo[3][3], vit;
	int cntX=0, cntY=0, cntV;

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			scanf("%c", &jogo[i][j]);
			if(jogo[i][j] == 'X') cntX++;
			if(jogo[i][j] == '0') cntY++;
			if(jogo[i][j] == '.') cntV++;
		}
		scanf("%*c");
	}

	printf("cntX = %d\ncntY = %d\ncntV = %d\n", cntX, cntY, cntV);

	if(cntX-cntY < -1 || cntX-cntY > 1) printf("Invalido\n");
	if(cntX + cntY + cntV != 9) printf("Invalido\n");
	else{ 
		vit = checkResult(jogo);
		if(vit == 'X'){
			if(cntX>cntY) printf("O primeiro venceu\n");
			else printf("O segundo venceu\n");
		}
		else if(vit == '0'){
			if(cntY>cntX) printf("O primeiro venceu\n");
			else printf("O segundo venceu\n");
		}
		else if(cntX+cntY == 9) printf("Empate\n");
		else{
			if(cntX==cntY) printf("Vez do primeiro\n");
			else printf("Vez do segundo\n");
		}
	}

	return 0;
}

