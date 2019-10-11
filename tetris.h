/// jogo interativo tetris orientado usuario em c para uso no console terminal de comandos
/// Autor: Marlon diego    
/// 28/08/2019 


#include <stdio.h>
#include <stdlib.h>
#include <conio.h> //biblioteca para capturar teclas  

// configuração das dimensões da matriz principal do jogo 
#define COLUMNS 60
#define ROWS 25

/// configuração de teclas
#define ESC 27
#define ARROWS 224
#define LEFT 75
#define RIGHT 77
#define TECLA_A 97
#define TECLA_D 100
#define TECLA_AA 65
#define TECLA_DD 68
#define TECLA_ESPACO 32
///criando as orientações de peças 
#define ORIENTACAO_UP 1
#define ORIENTACAO_LEFT 2
#define ORIENTACAO_DOWN 3
#define ORIENTACAO_RIGHT 4

///criando os tipos de peças 
#define TIPO_L 1
#define TIPO_L_R 2  // L reverso
#define TIPO_T 3
#define TIPO_Z 4
#define TIPO_Z_R 5 // 2 reverso
#define TIPO_O 6   // quadrado
#define TIPO_I 7 

/// configuração de layout 
#define PIXEL 219
#define EMPTY 32 



// estrutura padrão compnentes
typedef struct{
    int i; //posição na linha da matriz 
    int j; // posição nas colunas da matriz
    int orientacao; // orientação da peça
    int tipo; // os tipo da peças 
    int width; // largura da peça 
    int height; // altura da peça 
}Bloco;


/// inicializa a matriz principal com "espaços vazios"
void init(char matrix[ROWS][COLUMNS]);

///mostra o conteudo da matriz principal na tela do computador 
void printMatrix(char matrix[ROWS][COLUMNS]);

/// desenhar uma barra usando simbolo do caracter ascii passado por parâmetro
void drawBar( char matrix[ROWS][COLUMNS], Bloco barra, int simbolo);