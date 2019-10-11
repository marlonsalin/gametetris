#include "tetris.h"

/// jogo interativo tetris orientado usuario em c para uso no console terminal de comandos
/// Autor: Marlon diego    
/// 28/08/2019 

void init(char matrix[ROWS][COLUMNS]){/// inicializa a matriz principal com "espaços vazios"
    int i,j;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            
			if (i == 0 || i == 24 || j == 0 || j == 59){ 
			
			matrix[i][j] = '*';
			
			}else 
			matrix[i][j] = ' ';
    		
			
        }
    }
}

void printMatrix(char matrix[ROWS][COLUMNS]){ ///mostra o conteudo da matriz principal na tela do computador 
    int i,j;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            printf("%c", matrix[i][j]);
        }

        printf("\n");
    }
}

/// desenhar uma barra usando simbolo do caracter ascii passado por parâmetro

void drawBar( char matrix[ROWS][COLUMNS], Bloco barra, int simbolo){
     switch(barra.orientacao){
        case ORIENTACAO_DOWN:
        case ORIENTACAO_UP: 
    if(barra.i-3 >= 0) matrix[barra.i-3][barra.j] = simbolo; 
    if(barra.i-2 >= 0) matrix[barra.i-2][barra.j] = simbolo; 
    if(barra.i-1 >= 0)  matrix[barra.i-1][barra.j] = simbolo; 
    matrix[barra.i][barra.j] = simbolo;
        break; 
        case ORIENTACAO_RIGHT:
        case ORIENTACAO_LEFT: 
    if(barra.j-3 >= 0) matrix[barra.i][barra.j-3] = simbolo; 
    if(barra.j-2 >= 0) matrix[barra.i][barra.j-2] = simbolo; 
    if(barra.j-1 >= 0)  matrix[barra.i][barra.j-1] = simbolo; 
    matrix[barra.i][barra.j] = simbolo;
        break;
    } 

    


    

}