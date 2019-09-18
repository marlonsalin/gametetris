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


/// inicializa a matriz principal com "espaços vazios"
void init(char matrix[ROWS][COLUMNS]);

///mostra o conteudo da matriz principal na tela do computador 
void printMatrix(char matrix[ROWS][COLUMNS]);