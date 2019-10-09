#include "tetris.h" 
#include "display.h"
#define DEBUG 1  
/// jogo interativo tetris orientado usuario em c para uso no console terminal de comandos
/// para executar start .\programa.exe
/// Autor: marlon diego salin   
/// 28/08/2019 


int main(){ /// parte principal do programa responsavel por iniciar e chamar as funções auxiliares 
    
    char matrix[ROWS][COLUMNS];
    
    int keypressed=0;
    Bloco tijolo; 


    //posicao inicial do personagem
    
    tijolo.i = 0;
    tijolo.j = COLUMNS/2;
    tijolo.tipo = TIPO_I;
    tijolo.orientacao = ORIENTACAO_UP;
    tijolo.width = 1;
    tijolo.height = 4;

    //inicializando matriz
    init(matrix);
    /// apagar o cursor da tela
           ShowConsoleCursor(0);   
           system("cls");      
    while(keypressed != ESC){
        
        gotoxy(0,0);

    #if DEBUG == 1
        printf("@ = (%d, %d)", tijolo.i, tijolo.j); // printa o debug no terminal 
    #endif


       // posicionar o curso no meio da tela 
    switch(tijolo.orientacao){
        case ORIENTACAO_UP: 
    if(tijolo.i-3 >= 0) matrix[tijolo.i-3][tijolo.j] = PIXEL; 
    if(tijolo.i-2 >= 0) matrix[tijolo.i-2][tijolo.j] = PIXEL; 
    if(tijolo.i-1 >= 0)  matrix[tijolo.i-1][tijolo.j] = PIXEL; 
    matrix[tijolo.i][tijolo.j] = PIXEL;
        break; 
        case ORIENTACAO_LEFT: 

        break;
    } 

     


        // mostra a matriz na tela
        printMatrix(matrix);

        // faça a posição anteriror ser apagada 
       if(tijolo.i-3 >= 0)  matrix[tijolo.i-3][tijolo.j] = EMPTY;
       if(tijolo.i-2 >= 0)  matrix[tijolo.i-2][tijolo.j] = EMPTY;
       if(tijolo.i-1 >= 0)  matrix[tijolo.i-1][tijolo.j] = EMPTY;
        matrix[tijolo.i][tijolo.j] = EMPTY;
        
        if(tijolo.i< (ROWS - 2)) tijolo.i++;

         keypressed = 0;
         if(kbhit()) keypressed = getch();
         if(keypressed == ARROWS) keypressed = getch();
        
            switch(keypressed){
                case TECLA_AA: 
                case TECLA_A:
                case LEFT:
                 if(tijolo.j > 0) tijolo.j--; /// tecla seta <- esquerda
            break; 
            case TECLA_DD:
            case TECLA_D:
            case RIGHT: if(tijolo.j < COLUMNS - 2) tijolo.j++; /// tecla seta -> direita
            break;

   }
       
    }

    system("pause");

    return 0;

}  


