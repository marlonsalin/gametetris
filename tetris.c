

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

/*
    Desenhar uma barra usando o simbolo do caracter ASCII
    passado por parâmetro.
*/
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

/*
    Inicializar a peça do tipo barra
*/
void initBar(Bloco *barra){
    barra->i = 0;
    barra->j = COLUMNS/2;
    barra->tipo = TIPO_I;
    barra->orientacao = ORIENTACAO_LEFT;
    barra->width = 5;
    barra->height = 1;

    #if DEBUG == 1
        printf("posI: %d  posJ: %d \n", barra->i, barra->j);
        system("pause");
    #endif
}

/*
    Rotaciona blocos do jogo
*/
void rotate(Bloco *bloco){
    if(bloco->orientacao==ORIENTACAO_RIGHT)
        bloco->orientacao = ORIENTACAO_UP;
    else
        bloco->orientacao++;

    //inverte as dimensões do tijolo
    int aux = bloco->width;
    bloco->width = bloco->height;
    bloco->height = aux;

    //resolvendo bug dos cantos
    if(bloco->j < (bloco->width/2))
        bloco->j = bloco->width/2;
    else if(bloco->j > COLUMNS - (bloco->width/2) - 1)
        bloco->j = COLUMNS - (bloco->width/2) - 1;

}

/*
    Verifica a colisão de blocos
*/
int collisionDetect(char matrix[ROWS][COLUMNS], Bloco barra){
    int retorno = 0;

    //colisão com a base
    if((barra.i + 1) >= ROWS)
        retorno = 1;

    //colisão entre peças
    if(matrix[barra.i + 1][barra.j] != EMPTY)
        retorno = 1;

    int t2 = barra.width / 2;
    if(matrix[barra.i+1][barra.j + t2] != EMPTY )
        retorno = 1;
    if(matrix[barra.i+1][barra.j - t2] != EMPTY )
        retorno = 1;

    return retorno;
}