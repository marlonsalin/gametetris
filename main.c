#include "tetris.h" 
/// jogo interativo tetris orientado usuario em c para uso no console terminal de comandos
/// para executar start .\programa.exe
/// Autor: marlon diego salin   
/// 28/08/2019 


int main(){ /// parte principal do programa responsavel por iniciar e chamar as funções auxiliares 
    
    char matrix[ROWS][COLUMNS];
    int posI, posJ;

    //posicao inicial do personagem
    posI = ROWS/2;
    posJ = COLUMNS/2;
    //inicializando matriz
    init(matrix);
                    
    while(1){
        system("cls");

        matrix[posI][posJ] = '@';

        printMatrix(matrix);

        matrix[posI][posJ] = ' ';
        
        if(posJ < COLUMNS) posJ++;
    }

    system("pause");

    return 0;

}  


