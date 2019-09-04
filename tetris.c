#include "tetris.h"

/// jogo interativo tetris orientado usuario em c para uso no console terminal de comandos
/// Autor: Marlon diego    
/// 28/08/2019 

void init(char matrix[ROWS][COLUMNS]){/// inicializa a matriz principal com "espaços vazios"
    int i,j;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
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