
/// jogo interativo tetris orientado usuario em c para uso no console terminal de comandos
/// para executar start .\programa.exe
/// Autor: marlon diego salin   
/// 28/08/2019 

#include "tetris.h"
#include "display.h"


int main(){
    char matrix[ROWS][COLUMNS];
    Bloco tijolo;
    int keypressed=0;
    
    //apagar o cursor da tela
    ShowConsoleCursor(0);
    system("cls");

    //posicao inicial do personagem
    initBar(&tijolo);

    //inicializando matriz
    init(matrix);

    //animação do jogo
    while(keypressed != ESC){        
        gotoxy(0,0);

        #if DEBUG == 1
            printf("posicao = (%d, %d)\n", tijolo.i, tijolo.j);
            printf("dimensao = (%d, %d)\n", tijolo.width, tijolo.height);
        #endif

        //posicionar o @ no meio da tela
        drawBar(matrix, tijolo, PIXEL);

        //mostro a matriz na tela
        printMatrix(matrix);

        //faça posição anterior do @ ser apagada
        if(!collisionDetect(matrix, tijolo)){
            drawBar(matrix, tijolo, EMPTY);
            
            //faço a posição da @ ir para a direita
            if(tijolo.i < (ROWS-1)) tijolo.i++;

        }else{
            initBar(&tijolo);
        }



        //lendo teclas
        keypressed = 0;         
        if(kbhit()) keypressed = getch();            
        if(keypressed==ARROWS) keypressed = getch();

        switch(keypressed){
            case (int)'a':
            case (int)'A':
            case LEFT: 
               
                if((tijolo.j - (tijolo.width/2)) > 0) tijolo.j--; //vai para esquerda
                 if(matrix[tijolo.i][tijolo.j - (tijolo.width/2 )- 1] == EMPTY) 
                 tijolo.j--;
            break; 
            case TECLA_d:
            case TECLA_D:
            case RIGHT: 
                if((tijolo.j - (tijolo.width/2)) > 0) tijolo.j--; //vai para esquerda
                 if(matrix[tijolo.i][tijolo.j - (tijolo.width/2 )- 1] == EMPTY) 
                 tijolo.j++;

            break; 
            case TECLA_ESPACO:
                rotate(&tijolo);
            break;
        }

    }

    system("pause");

    return 0;
}