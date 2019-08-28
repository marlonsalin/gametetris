/// jogo interativo tetris orientado usuario em c para uso no console terminal de comandos
/// Autor: Marlon diego    
/// 28/08/2019 


#include <stdio.h>
#include <stdlib.h>

// configuração das dimensões da matriz principal do jogo 
#define COLUMNS 60
#define ROWS 25

/// inicializa a matriz principal com "espaços vazios"
void init(char matrix[ROWS][COLUMNS]);

///mostra o conteudo da matriz principal na tela do computador 
void printMatrix(char matrix[ROWS][COLUMNS]);