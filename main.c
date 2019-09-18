#include "tetris.h" 
#include "display.h" 
/// jogo interativo tetris orientado usuario em c para uso no console terminal de comandos
/// para executar start .\programa.exe
/// Autor: marlon diego salin   
/// 28/08/2019 


int main(){ /// parte principal do programa responsavel por iniciar e chamar as funções auxiliares 
    
    char matrix[ROWS][COLUMNS];
    int posI, posJ;
    int keypressed=0;

    //posicao inicial do personagem
    
    posI = 1;
    posJ = COLUMNS/2;
    //inicializando matriz
    init(matrix);
    /// apagar o cursor da tela
           ShowConsoleCursor(0);   
           system("cls");      
    while(keypressed != 27){
        
        gotoxy(0,0);
       
        matrix[posI][posJ] = '@';

        printMatrix(matrix);

        matrix[posI][posJ] = ' ';
        
        if(posI < (ROWS - 2)) posI++;

         keypressed = 0;
         if(kbhit()) keypressed = getch();
         if(keypressed == ARROWS) keypressed = getch();
        
            switch(keypressed){
                case TECLA_AA: 
                case TECLA_A:
                case LEFT:
                 if(posJ > 0) posJ--; /// tecla seta <-
            break; 
            case TECLA_DD:
            case TECLA_D:
            case RIGHT: if(posJ < COLUMNS - 2) posJ++; /// tecla seta ->
            break;

            }
       
    }

    system("pause");

    return 0;

}  


