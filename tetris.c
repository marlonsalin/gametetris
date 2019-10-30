

/// jogo interativo tetris orientado usuario em c para uso no console terminal de comandos
/// Autor: Marlon diego    
/// 28/08/2019 
#include "tetris.h"
#define DEBUG 1
/*
    Inicializa a matriz principal com 'espaços vazios'
*/
void init(char matrix[ROWS][COLUMNS]){
      int i,j;

    for(i=0; i<ROWS; i++){
        for(j=0; j<COLUMNS; j++){
            matrix[i][j] = ' ';
        }
    }
}

void printMatrix(char matrix[ROWS][COLUMNS]){
    int i,j;

    printf("\t\t\t\t\t");
    //Linha de cima
    for(j=0; j<COLUMNS+2; j++){
        printf("*");
    }
    printf("\n");

    //Matriz do jogo
    for(i=0; i<ROWS; i++){        
        printf("\t\t\t\t\t*");
        for(j=0; j<COLUMNS; j++){
            printf("%c", matrix[i][j]);
        }
        printf("*\n");
    }
    printf("\t\t\t\t\t");
    //Linha de baixo
    for(j=0; j<COLUMNS+2; j++){
        printf("*");
    }
    printf("\n");

}

void drawBar(char matrix[ROWS][COLUMNS], Bloco barra, int simbolo){

        switch(barra.orientacao){
            case ORIENTACAO_DOWN:
            case ORIENTACAO_UP:
                if(barra.i-4>=0) matrix[barra.i-4][barra.j] = simbolo;
                if(barra.i-3>=0) matrix[barra.i-3][barra.j] = simbolo;
                if(barra.i-2>=0) matrix[barra.i-2][barra.j] = simbolo;
                if(barra.i-1>=0) matrix[barra.i-1][barra.j] = simbolo;
                matrix[barra.i][barra.j] = simbolo;
                break;
            case ORIENTACAO_RIGHT:
            case ORIENTACAO_LEFT:
                if(barra.j+1>=0) matrix[barra.i][barra.j+1] = simbolo;
                if(barra.j+2>=0) matrix[barra.i][barra.j+2] = simbolo;
                if(barra.j-2>=0) matrix[barra.i][barra.j-2] = simbolo;
                if(barra.j-1>=0) matrix[barra.i][barra.j-1] = simbolo;
                matrix[barra.i][barra.j] = simbolo;
            break;
        }

}

void initBar(Bloco *barra){
//posicao inicial do personagem
    barra->i = 0;
    barra->j = COLUMNS/2;
    barra->tipo = TIPO_I;
    barra->orientacao = ORIENTACAO_LEFT;
    barra->width = 1;
    barra->height = 5;

    #if DEBUG == 1
            printf("posicao = (%d, %d)\n", barra->i, barra->j);
            system("pause");
     #endif

}

void rotacao(Bloco *barra){
  if(barra->orientacao==ORIENTACAO_RIGHT)
                    barra->orientacao = ORIENTACAO_UP;
                else
                    barra->orientacao++;

                //inverte as dimensões do tijolo
                int aux = barra->width;
                barra->width = barra->height;
                barra->height = aux;

                //resolvendo bug dos cantos
                if(barra->j < (barra->width/2))
                    barra->j = barra->width/2;
                else if(barra->j > COLUMNS - (barra->width/2) - 1)
                   barra->j = COLUMNS - (barra->width/2) - 1;

}

int collisao(char matrix[ROWS][COLUMNS], Bloco barra){
 int retorno = 1;
    if(collisao (matrix, barra))
    drawBar(matrix, barra, EMPTY);
 /// colisao com a base 
 if(!(barra.i + barra.height / 2) >= (ROWS - 1) )
 retorno = 0;

 return retorno;

}