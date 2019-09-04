#include "tetris.h" 
#include "display.h" 
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
    /// apagar o cursor da tela
           ShowConsoleCursor(0);   
           system("cls");      
    while(1){
        gotoxy(0,0);

        matrix[posI][posJ] = '@';

        printMatrix(matrix);

        matrix[posI][posJ] = ' ';
        
        if(posJ < COLUMNS) posJ++;
    }

    system("pause");

    return 0;

}  


