#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

int selecaoLinha, selecaoColuna;
int selecao;
int turno;
int IANaoMoveu;
int erroTurnoPretas; //identificador para testar se jogador nao realizou movimento correto
int erroTurnoBrancas; //turnoP ou turnoB são igual a 1 se não realizaram.
int naoMudarPeca; //logica para IA multi come

//matriz[linha][coluna]
char matriz[10][10] = {
    {' ', '1', '2', '3', '4', '5', '6', '7', '8', '\n'},
    {'1', 'P', 'B', 'P', ' ', 'P', ' ', 'P', ' ', '\n'},
    {'2', ' ', 'P', ' ', 'P', ' ', 'P', ' ', 'P', '\n'},
    {'3', 'P', ' ', 'P', ' ', 'P', ' ', 'P', ' ', '\n'},
    {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'},
    {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'},
    {'6', ' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B', '\n'},
    {'7', 'B', ' ', 'B', ' ', 'B', ' ', 'B', ' ', '\n'},
    {'8', ' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B', '\n'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'}
};

void printaMatriz(){
    system("cls");
    printf("\nTurno atual: %i.\n\n", turno);
    printf(" ");
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%c ", matriz[i][j]);
        }
    }
    printf("\n");
}

void movimentoBrancas(){
    if (selecaoColuna == 1){
        printf("[pressione algo para mover a direita]\n");
        getch();
        
        if (matriz[selecaoLinha - 1][selecaoColuna + 1] == ' '){
            matriz[selecaoLinha - 1][selecaoColuna + 1] = 'B';
            matriz[selecaoLinha][selecaoColuna] = ' ';
            return;
        }
        else{
            printf("\nNao eh possivel mover nesta direcao!\n"
                    "Motivo: ha uma peca a direita.\n"
                    "[pressione algo para continuar]");
            getch();
            erroTurnoBrancas = 1;
            return;
        }
    }
    if (selecaoColuna == 8){
        printf("[pressione algo para mover a esquerda]\n");
        getch();
        
        if (matriz[selecaoLinha - 1][selecaoColuna - 1] == ' '){
            matriz[selecaoLinha - 1][selecaoColuna - 1] = 'B';
            matriz[selecaoLinha][selecaoColuna] = ' ';
            return;
        }
        else{
            printf("\nNao eh possivel mover nesta direcao!\n"
                    "Motivo: ha uma peca a esquerda.\n"
                    "[pressione algo para continuar]");
            getch();
            erroTurnoBrancas = 1;
            return;
        }
    }
    
    printf("\nMover esquerda ou direita?:\n1-Direita\n2-Esquerda\nSelecao: ");
    scanf("%i", &selecao);
    if (selecao == 1){ //direita
        if (matriz[selecaoLinha - 1][selecaoColuna + 1] == ' '){
            matriz[selecaoLinha - 1][selecaoColuna + 1] = 'B';
            matriz[selecaoLinha][selecaoColuna] = ' ';
            return;
        }
        else{
            printf("Nao eh possivel mover nesta direcao!\n"
                    "Motivo: ha uma peca a direita.\n"
                    "[pressione algo para continuar]");
            getch();
            erroTurnoBrancas = 1;
            return;
        }
    }
    if (selecao == 2){ //esquerda
        if (matriz[selecaoLinha - 1][selecaoColuna - 1] == ' '){
            matriz[selecaoLinha - 1][selecaoColuna - 1] = 'B';
            matriz[selecaoLinha][selecaoColuna] = ' ';
            return;
        }
        else{
            printf("Nao eh possivel mover nesta direcao!\n"
                    "Motivo: ha uma peca a esquerda.\n"
                    "[pressione algo para continuar]");
            getch();
            erroTurnoBrancas = 1;
            return;
        }
    }
}

void movimentoPretas(){
    if (selecaoColuna == 1){
        printf("[pressione algo para mover a direita]\n");
        getch();
        
        if (matriz[selecaoLinha + 1][selecaoColuna + 1] == ' '){
            matriz[selecaoLinha + 1][selecaoColuna + 1] = 'P';
            matriz[selecaoLinha][selecaoColuna] = ' ';
            return;
        }
        else{
            printf("\nNao eh possivel mover nesta direcao!\n"
                    "Motivo: ha uma peca a direita.\n"
                    "[pressione algo para continuar]");
            getch();
            erroTurnoPretas = 1;
            return;
        }
    }
    if (selecaoColuna == 8){
        printf("[pressione algo para mover a esquerda]\n");
        getch();
        
        if (matriz[selecaoLinha + 1][selecaoColuna - 1] == ' '){
            matriz[selecaoLinha + 1][selecaoColuna - 1] = 'P';
            matriz[selecaoLinha][selecaoColuna] = ' ';
            return;
        }
        else{
            printf("\nNao eh possivel mover nesta direcao!\n"
                    "Motivo: ha uma peca a esquerda.\n"
                    "[pressione algo para continuar]");
            getch();
            erroTurnoPretas = 1;
            return;
        }
    }
    
    printf("\nMover esquerda ou direita?:\n1-Direita\n2-Esquerda\nSelecao: ");
    scanf("%i", &selecao);
    if (selecao == 1){ //direita
        if (matriz[selecaoLinha + 1][selecaoColuna + 1] == ' '){
            matriz[selecaoLinha + 1][selecaoColuna + 1] = 'P';
            matriz[selecaoLinha][selecaoColuna] = ' ';
            return;
        }
        else{
            printf("Nao eh possivel mover nesta direcao!\n"
                    "Motivo: ha uma peca a direita.\n"
                    "[pressione algo para continuar]");
            getch();
            erroTurnoPretas = 1;
            return;
        }
    }
    if (selecao == 2){ //esquerda
        if (matriz[selecaoLinha + 1][selecaoColuna - 1] == ' '){
            matriz[selecaoLinha + 1][selecaoColuna - 1] = 'P';
            matriz[selecaoLinha][selecaoColuna] = ' ';
            return;
        }
        else{
            printf("Nao eh possivel mover nesta direcao!\n"
                    "Motivo: ha uma peca a esquerda.\n"
                    "[pressione algo para continuar]");
            getch();
            erroTurnoPretas = 1;
            return;
        }
    }
}

////////////////////////
/*char matriz[10][10] = { /[linhas][colunas]/
    {' ', '1', '2', '3', '4', '5', '6', '7', '8', '\n'},
    {'1', 'P', ' ', 'P', ' ', 'P', ' ', 'P', ' ', '\n'},
    {'2', ' ', 'P', ' ', 'P', ' ', 'P', ' ', 'P', '\n'},
    {'3', 'P', ' ', 'P', ' ', 'P', ' ', 'P', ' ', '\n'},
    {'4', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'},
    {'5', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'},
    {'6', ' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B', '\n'},
    {'7', 'B', ' ', 'B', ' ', 'B', ' ', 'B', ' ', '\n'},
    {'8', ' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B', '\n'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '\n'}
}*/
void jogadorIASingleCome(){ //IA é sempre pretas
    for(int i = 7; i > 1; i--){
        for(int j = 1; j <= 8; j++){
            if (matriz[i][j] == 'P'){ //detecta peça para selecionar
                //detecta para comer primeiro
                if (j <= 2){ //detecta se estiver na parede esquerda
                    if(matriz[i+1][j+1] == 'B'
                    && matriz[i+2][j+2] == ' '){ //detecta comivel direita
                        matriz[i][j] = ' ';
                        matriz[i+1][j+1] = ' ';
                        matriz[i+2][j+2] = 'P';
                        return;
                    }
                }
                if(j >= 7){ //detecta se estiver na parede direita
                    if (matriz[i+1][j-1] == 'B'
                     && matriz[i+2][j-2] == ' '){ //detecta comivel esquerda
                        matriz[i][j] = ' ';
                        matriz[i+1][j-1] = ' ';
                        matriz[i+2][j-2] = 'P';
                        return;
                    }
                }
                //caso default: peça detectada consegue comer direita ou esquerda
                
                if(matriz[i+1][j+1] == 'B' 
                && matriz[i+2][j+2] == ' '){ //detecta comivel direita
                    matriz[i][j] = ' ';
                    matriz[i+1][j+1] = ' ';
                    matriz[i+2][j+2] = 'P';
                    return;
                }
                else if (matriz[i+1][j-1] == 'B'
                      && matriz[i+2][j-2] == ' '){ //detecta comivel esquerda
                    matriz[i][j] = ' ';
                    matriz[i+1][j-1] = ' ';
                    matriz[i+2][j-2] = 'P';
                    return;
                }
                
                //detecta para mover
                if (j == 1){ //detecta se estiver na parede esquerda
                    if(matriz[i+1][j+1] == ' '){ //detecta mover direita
                        matriz[i][j] = ' ';
                        matriz[i+1][j+1] = 'P';
                        return;
                    }
                }
                if(j == 8){ //detecta se estiver na parede direita
                    if (matriz[i+1][j-1] == ' '){ //detecta mover esquerda
                        matriz[i][j] = ' ';
                        matriz[i+1][j-1] = 'P';
                        return;
                    }
                }
                
                //caso default: peça detectada consegue mover
                if(matriz[i+1][j+1] == ' '){ //detecta mover direita
                    matriz[i][j] = ' ';
                    matriz[i+1][j+1] = 'P';
                    return;
                }
                else if (matriz[i+1][j-1] == ' '){ //detecta comivel ESQ
                    matriz[i][j] = ' ';
                    matriz[i+1][j-1] = 'P';
                    return;
                }
            }
        }
    }
    
    IANaoMoveu = 1;
}


int IAlinha;
int IAcoluna;

int IALogicaMultiComeOuMove(){
    int i = IAlinha;
    int j = IAcoluna;
    
    if (j <= 2){ //detecta se estiver na parede esquerda
        if(matriz[i+1][j+1] == 'B'
        && matriz[i+2][j+2] == ' '){ //detecta comivel direita
            matriz[i][j] = ' ';
            matriz[i+1][j+1] = ' ';
            matriz[i+2][j+2] = 'P';
            IAlinha = i+2;
            IAcoluna = j+2;
            return 1;
        }
    }
    if(j >= 7){ //detecta se estiver na parede direita
        if (matriz[i+1][j-1] == 'B'
         && matriz[i+2][j-2] == ' '){ //detecta comivel esquerda
            matriz[i][j] = ' ';
            matriz[i+1][j-1] = ' ';
            matriz[i+2][j-2] = 'P';
            IAlinha = i+2;
            IAcoluna = j-2;
            return 1;
        }
    }
    //caso default: peça detectada consegue comer direita ou esquerda

    if(matriz[i+1][j+1] == 'B' 
    && matriz[i+2][j+2] == ' '){ //detecta comivel direita
        matriz[i][j] = ' ';
        matriz[i+1][j+1] = ' ';
        matriz[i+2][j+2] = 'P';
        IAlinha = i+2;
        IAcoluna = j+2;
        return 1;
    }
    else if (matriz[i+1][j-1] == 'B'
          && matriz[i+2][j-2] == ' '){ //detecta comivel esquerda
        matriz[i][j] = ' ';
        matriz[i+1][j-1] = ' ';
        matriz[i+2][j-2] = 'P';
        IAlinha = i+2;
        IAcoluna = j-2;
        return 1;
    }

    //detecta para mover
    if (naoMudarPeca == 1)
        return 2; //IA acabou de comer, nao mover se comeu.
    
    if (j == 1){ //detecta se estiver na parede esquerda
        if(matriz[i+1][j+1] == ' '){ //detecta mover direita
            matriz[i][j] = ' ';
            matriz[i+1][j+1] = 'P';
            return 0;
        }
    }
    if(j == 8){ //detecta se estiver na parede direita
        if (matriz[i+1][j-1] == ' '){ //detecta mover esquerda
            matriz[i][j] = ' ';
            matriz[i+1][j-1] = 'P';
            return 0;
        }
    }

    //caso default: peça detectada consegue mover
    if(matriz[i+1][j+1] == ' '){ //detecta mover direita
        matriz[i][j] = ' ';
        matriz[i+1][j+1] = 'P';
        return 0;
    }
    else if (matriz[i+1][j-1] == ' '){ //detecta mover esquerda
        matriz[i][j] = ' ';
        matriz[i+1][j-1] = 'P';
        return 0;
    }

    
    return 2; //nao conseguiu fazer nada, trocar para proxima peça
}

void jogadorIAMultiCome(){
    int resultado = 2;
    naoMudarPeca = 0;
    
    for(int i = 7; i > 1; i--){
        for(int j = 1; j <= 8; j++){
            if (matriz[i][j] == 'P'){ //detecta peça para selecionar
                IAlinha = i; //salva local da peça para funçao IAMultiComeOuMove
                IAcoluna = j;
                for(;;){
                    resultado = IALogicaMultiComeOuMove(); //chama funcao
                    if (resultado == 0) //moveu
                        return; //acabou o turno, fecha funcao
                    if (resultado == 2 && naoMudarPeca == 0) //impossibilitado de fazer alguma coisa
                        break; //nao conseguiu fazer nada, trocar para prox peça
                    if (resultado == 1)
                        naoMudarPeca = 1; //forçar a nao trocar de peça se ja comeu
                    if (resultado == 2 && naoMudarPeca == 1)
                        return; //acabou o turno, ja comeu pelo menos 1
                    //comeu = 1, repete laço repeticao
                }
            }
        }
    }
    
    //nao conseguiu mover ou comer com nenhuma peça, empate
    IANaoMoveu = 1;
}


////////////////////////

int comerBrancas(){
    if (selecaoLinha == 2){
        printf("Nao eh possivel comer na linha 2.\n");
        erroTurnoBrancas = 1;
        return 0;
    }
    
    switch(selecaoColuna){
        case 1:
        case 2:
            printf("Comendo para a direita...\n[digite algo para comer]\n");
            getch();
            
            if (matriz[selecaoLinha - 1][selecaoColuna + 1] == 'P'){
                if (matriz[selecaoLinha - 2][selecaoColuna + 2] == ' '){
                    matriz[selecaoLinha][selecaoColuna] = ' ';
                    matriz[selecaoLinha - 1][selecaoColuna + 1] = ' ';
                    matriz[selecaoLinha - 2][selecaoColuna + 2] = 'B';
                    selecaoLinha = selecaoLinha + 2;
                    selecaoColuna = selecaoColuna + 2;
                    return 1;
                }
                else{
                    printf("\nNao ha espaco para comer atras da peca!\n[pressione algo]");
                    getch();
                    erroTurnoBrancas = 1;
                    return 0;
                }
            }
            else{
                printf("\nNao ha peca para comer\n[pressione algo]");
                getch();
                erroTurnoBrancas = 1;
                return 0;
            }
            
        case 7:
        case 8:
            printf("Comendo para a esquerda...\n[digite algo para comer]\n");
            getch();
            
            if (matriz[selecaoLinha - 1][selecaoColuna - 1] == 'P'){
                if (matriz[selecaoLinha - 2][selecaoColuna - 2] = ' '){
                    matriz[selecaoLinha][selecaoColuna] = ' ';
                    matriz[selecaoLinha - 1][selecaoColuna - 1] = ' ';
                    matriz[selecaoLinha - 2][selecaoColuna - 2] = 'B';
                    selecaoLinha = selecaoLinha - 2;
                    selecaoColuna = selecaoColuna - 2;
                    return 1;
                }
                else{
                    printf("\nNao ha espaco para comer atras da peca!\n[pressione algo]");
                    getch();
                    erroTurnoBrancas = 1;
                    return 0;
                }
            }
            else{
                printf("\nNao ha peca para comer\n[pressione algo]");
                getch();
                erroTurnoBrancas = 1;
                return 0;
            }
            
        default: //entre 3 e 6
            selecao = 0;
            for(;;){
                printf("Comer em qual direcao?:"
                        "\n1-Direita\n2-Esquerda\nSelecao: ");
                scanf("%i", &selecao);
                
                if (selecao == 1){
                    printf("Comendo para a direita...\n[digite algo para comer]\n");
                    getch();
                    
                    if (matriz[selecaoLinha - 1][selecaoColuna + 1] == 'P'){
                        if (matriz[selecaoLinha - 2][selecaoColuna + 2] == ' '){
                            matriz[selecaoLinha][selecaoColuna] = ' ';
                            matriz[selecaoLinha - 1][selecaoColuna + 1] = ' ';
                            matriz[selecaoLinha - 2][selecaoColuna + 2] = 'B';
                            selecaoLinha = selecaoLinha + 2;
                            selecaoColuna = selecaoColuna + 2;
                            return 1;
                        }
                        else{
                            printf("\nNao ha espaco para comer atras da peca!\n[pressione algo]");
                            getch();
                            erroTurnoBrancas = 1;
                            return 0;
                        }
                    }
                    else{
                        printf("\nNao ha peca para comer\n[pressione algo]");
                        getch();
                        erroTurnoBrancas = 1;
                        return 0;
                    }
                }
                else if (selecao == 2){
                    printf("Comendo para a esquerda...\n[digite algo para comer]\n");
                    getch();
                    
                    if (matriz[selecaoLinha - 1][selecaoColuna - 1] == 'P'){
                        if (matriz[selecaoLinha - 2][selecaoColuna - 2] = ' '){
                            matriz[selecaoLinha][selecaoColuna] = ' ';
                            matriz[selecaoLinha - 1][selecaoColuna - 1] = ' ';
                            matriz[selecaoLinha - 2][selecaoColuna - 2] = 'B';
                            selecaoLinha = selecaoLinha - 2;
                            selecaoColuna = selecaoColuna - 2;
                            return 1;
                        }
                        else{
                            printf("\nNao ha espaco para comer atras da peca!\n[pressione algo]");
                            getch();
                            erroTurnoBrancas = 1;
                            return 0;
                        }
                    }
                    else{
                        printf("\nNao ha peca para comer\n[pressione algo]");
                        getch();
                        erroTurnoBrancas = 1;
                        return 0;
                    }
                }
                else{
                    system("cls");
                    printaMatriz();
                    printf("\nSelecao incorreta! Tente novamente. [Digite algo para continuar]\n");
                    getch();
                }
            }
    } 
}

int comerPretas(){
    if (selecaoLinha == 7){
        printf("Nao eh possivel comer na linha 7.\n");
        erroTurnoPretas = 1;
        return 0;
    }
    
    switch(selecaoColuna){
        case 1:
        case 2:
            printf("Comendo para a direita...\n[digite algo para comer]\n");
            getch();
            
            if (matriz[selecaoLinha + 1][selecaoColuna + 1] == 'B'){
                if (matriz[selecaoLinha + 2][selecaoColuna + 2] == ' '){
                    matriz[selecaoLinha][selecaoColuna] = ' ';
                    matriz[selecaoLinha + 1][selecaoColuna + 1] = ' ';
                    matriz[selecaoLinha + 2][selecaoColuna + 2] = 'P';
                    selecaoLinha = selecaoLinha + 2;
                    selecaoColuna = selecaoColuna + 2;
                    return 1;
                }
                else{
                    printf("\nNao ha espaco para comer atras da peca!\n[pressione algo]");
                    getch();
                    erroTurnoPretas = 1;
                    return 0;
                }
            }
            else{
                printf("\nNao ha peca para comer\n[pressione algo]");
                getch();
                erroTurnoPretas = 1;
                return 0;
            }
        case 7:
        case 8:
            printf("Comendo para a esquerda...\n[digite algo para comer]\n");
            getch();
            
            if (matriz[selecaoLinha + 1][selecaoColuna - 1] == 'B'){
                if (matriz[selecaoLinha + 2][selecaoColuna - 2] == ' '){
                    matriz[selecaoLinha][selecaoColuna] = ' ';
                    matriz[selecaoLinha + 1][selecaoColuna - 1] = ' ';
                    matriz[selecaoLinha + 2][selecaoColuna - 2] = 'P';
                    selecaoLinha = selecaoLinha + 2;
                    selecaoColuna = selecaoColuna - 2;
                    return 1;
                }
                else{
                    printf("\nNao ha espaco para comer atras da peca!\n[pressione algo]");
                    getch();
                    erroTurnoPretas = 1;
                    return 0;
                }
            }
            else{
                printf("\nNao ha peca para comer\n[pressione algo]");
                getch();
                erroTurnoPretas = 1;
                return 0;
            }
        default: //entre 3 e 6
            selecao = 0;
            for(;;){
                printf("Comer em qual direcao?:"
                        "\n1-Direita\n2-Esquerda\nSelecao: ");
                scanf("%i", &selecao);
                
                if (selecao == 1){
                    printf("Comendo para a direita...\n");
                    if (matriz[selecaoLinha + 1][selecaoColuna + 1] == 'B'){
                        if (matriz[selecaoLinha + 2][selecaoColuna + 2] == ' '){
                            matriz[selecaoLinha][selecaoColuna] = ' ';
                            matriz[selecaoLinha + 1][selecaoColuna + 1] = ' ';
                            matriz[selecaoLinha + 2][selecaoColuna + 2] = 'P';
                            selecaoLinha = selecaoLinha + 2;
                            selecaoColuna = selecaoColuna + 2;
                            return 1;
                        }
                        else{
                            printf("\nNao ha espaco para comer atras da peca!\n[pressione algo]");
                            getch();
                            erroTurnoPretas = 1;
                            return 0;
                        }
                    }
                    else{
                        printf("\nNao ha peca para comer\n[pressione algo]");
                        getch();
                        erroTurnoPretas = 1;
                        return 0;
                    }
                }
                else if (selecao == 2){
                    printf("Comendo para a esquerda...\n");
                    if (matriz[selecaoLinha + 1][selecaoColuna - 1] == 'B'){
                        if (matriz[selecaoLinha + 2][selecaoColuna - 2] == ' '){
                            matriz[selecaoLinha][selecaoColuna] = ' ';
                            matriz[selecaoLinha + 1][selecaoColuna + 1] = ' ';
                            matriz[selecaoLinha + 2][selecaoColuna + 2] = 'P';
                            selecaoLinha = selecaoLinha + 2;
                            selecaoColuna = selecaoColuna - 2;
                            return 1;
                        }
                        else{
                            printf("\nNao ha espaco para comer atras da peca!\n[pressione algo]");
                            getch();
                            erroTurnoPretas = 1;
                            return 0;
                        }
                    }
                    else{
                        printf("\nNao ha peca para comer\n[pressione algo]");
                        getch();
                        erroTurnoPretas = 1;
                        return 0;
                    }
                }
                else{
                    system("cls");
                    printaMatriz();
                    printf("\nSelecao incorreta! tente novamente.\n");
                }
            }
    }
}

////////////////////////

void jogadorPretasComidaSingular(){
    printf("\nJogador atual: PRETAS\n");
    
    //seleção de peça
    selecaoLinha = 0;
    selecaoColuna = 0;
    while(matriz[selecaoLinha][selecaoColuna] != 'P'){
        printf("\nIndique a linha da peca (de 1 a 8): ");
        scanf("%i", &selecaoLinha);

        printf("Indique a coluna da peca (de 1 a 8): ");
        scanf("%i", &selecaoColuna);
        
        if (matriz[selecaoLinha][selecaoColuna] != 'P'){
            printf("\nErro: nao foi possivel selecionar peca, "
            "tente novamente!\n[pressione algo para continuar]\n");
            getch();
        }
        else
            break;
        
        printaMatriz();
        printf("\nJogador atual: PRETAS\n");
    }
    
    for(;;){
        printf("Deseja comer ou mover?\n-1: comer\n-2: Mover\nSelecao: ");
        scanf("%i", &selecao);
        if (selecao == 1){ //comer
            comerPretas();
            break;
        }
        else if (selecao == 2){ //mover
            movimentoPretas();
            break;
        }
        else{
            printf("\nErro: selecione corretamente.\n[pressione algo para "
            "continuar]\n");
            getch();
        }
    }
}

void jogadorBrancasComidaSingular(){
    printf("\nJogador atual: BRANCAS\n");
    
    //seleção de peça
    selecaoLinha = 0;
    selecaoColuna = 0;
    while(matriz[selecaoLinha][selecaoColuna] != 'B'){
        printf("\nIndique a linha da peca (de 1 a 8): ");
        scanf("%i", &selecaoLinha);

        printf("Indique a coluna da peca (de 1 a 8): ");
        scanf("%i", &selecaoColuna);
        
        if (matriz[selecaoLinha][selecaoColuna] != 'B'){
            printf("\nErro: nao foi possivel selecionar peca, "
            "tente novamente!\n[pressione algo para continuar]\n");
            getch();
        }
        else
            break;

        printaMatriz();
        printf("\nJogador atual: BRANCAS\n");
    }
    
    for(;;){
        printf("Deseja comer ou mover?\n-1: comer\n-2: Mover\nSelecao: ");
        scanf("%i", &selecao);
        if (selecao == 1){ //comer
            comerBrancas();
            break;
        }
        else if (selecao == 2){ //mover
            movimentoBrancas();
            break;
        }
        else{
            printf("\nErro: selecione corretamente.\n[pressione algo para "
            "continuar]\n");
            getch();
        }
    }
}

//////////////

void jogadorBrancasComidaMultipla(){
    printf("\nJogador atual: BRANCAS\n");
    
    //seleção de peça
    selecaoLinha = 0;
    selecaoColuna = 0;
    while(matriz[selecaoLinha][selecaoColuna] != 'B'){
        printf("\nIndique a linha da peca (de 1 a 8): ");
        scanf("%i", &selecaoLinha);

        printf("Indique a coluna da peca (de 1 a 8): ");
        scanf("%i", &selecaoColuna);
        
        if (matriz[selecaoLinha][selecaoColuna] != 'B'){
            printf("\nErro: nao foi possivel selecionar peca, "
            "tente novamente!\n[pressione algo para continuar]\n");
            getch();
        }
        else
            break;

        printaMatriz();
        printf("\nJogador atual: BRANCAS\n");
    }
    
    for(;;){
        printf("Deseja comer ou mover?\n-1: comer\n-2: Mover\nSelecao: ");
        scanf("%i", &selecao);
        if (selecao == 1){ //comer
            for (;;){
                if (comerBrancas() == 1){ //se comeu, perguntar para comer de novo
                    printf("\nPeca comida, comer novamente?\n1: Sim\n2: Nao\nResposta: ");
                    scanf("%i", &selecao);
                    if (selecao == 2)
                        break;
                }
            }
            return;
        }
        else if (selecao == 2){ //mover
            movimentoBrancas();
            return;
        }
        else{
            printf("\nErro: selecione corretamente.\n[pressione algo para "
            "continuar]\n");
            getch();
        }
    }
}

void jogadorPretasComidaMultipla(){
    printf("\nJogador atual: PRETAS\n");
    
    //seleção de peça
    selecaoLinha = 0;
    selecaoColuna = 0;
    while(matriz[selecaoLinha][selecaoColuna] != 'P'){
        printf("\nIndique a linha da peca (de 1 a 8): ");
        scanf("%i", &selecaoLinha);

        printf("Indique a coluna da peca (de 1 a 8): ");
        scanf("%i", &selecaoColuna);
        
        if (matriz[selecaoLinha][selecaoColuna] != 'P'){
            printf("\nErro: nao foi possivel selecionar peca, "
            "tente novamente!\n[pressione algo para continuar]\n");
            getch();
        }
        else
            break;
        
        printaMatriz();
        printf("\nJogador atual: PRETAS\n");
    }
    
    for(;;){
        printf("Deseja comer ou mover?\n-1: comer\n-2: Mover\nSelecao: ");
        scanf("%i", &selecao);
        if (selecao == 1){ //comer
            for(;;){
                if (comerPretas() == 1){ //se comeu, perguntar para comer de novo
                    printf("\nPeca comida, comer novamente?\n1: Sim\n2: Nao\nResposta: ");
                    scanf("%i", &selecao);
                    if (selecao == 2)
                        break;
                }
            }
            return;
        }
        else if (selecao == 2){ //mover
            movimentoPretas();
            return;
        }
        else{
            printf("\nErro: selecione corretamente.\n[pressione algo para "
            "continuar]\n");
            getch();
        }
    }
}

//////////////
char detectaVitoria(){
    if (IANaoMoveu == 1)
        return 'e';
    
    for(int i = 1; i <= 8; i++){
        if (matriz[1][i] == 'B'){
            return 'B'; //brancas venceram
        }
        if (matriz[8][i] == 'P'){
            return 'P'; //pretas venceram
        }
    }
    
    return '0';
}

void printaVitoria(){
    printf("\n\n /$$    /$$ /$$$$$$ /$$$$$$$$ /$$$$$$  /$$$$$$$  /$$$$$$  /$$$$$$  /$$"
             "\n| $$   | $$|_  $$_/|__  $$__//$$__  $$| $$__  $$|_  $$_/ /$$__  $$| $$"
             "\n| $$   | $$  | $$     | $$  | $$  \\ $$| $$  \\ $$  | $$  | $$  \\ $$| $$"
             "\n|  $$ / $$/  | $$     | $$  | $$  | $$| $$$$$$$/  | $$  | $$$$$$$$| $$"
             "\n \\  $$ $$/   | $$     | $$  | $$  | $$| $$__  $$  | $$  | $$__  $$|__/"
             "\n  \\  $$$/    | $$     | $$  | $$  | $$| $$  \\ $$  | $$  | $$  | $$    "
             "\n   \\  $/    /$$$$$$   | $$  |  $$$$$$/| $$  | $$ /$$$$$$| $$  | $$ /$$"
             "\n    \\_/    |______/   |__/   \\______/ |__/  |__/|______/|__/  |__/|__/"
             "\n\n[Pressione algo para fechar o jogo...]\n");
}

void printaRegras(){
    printf("\nSelecione o modo de jogo (entre 1 a 4):"
    "\n  - Modo 1: jogador x jogador, 1 comida por turno"
    "\n  - Modo 2: jogador x computador, 1 comida por turno"
    "\n  - Modo 3: jogador x jogador, comidas infinitas por turno"
    "\n  - Modo 4: jogador x computador, comidas infinitas por turno.\n\n");
}

int main(){
    char detectarVitoria = '0';
    int regras;
    
    printaRegras();
    scanf("%i", &regras);
    
    IANaoMoveu = 0;
    turno = 0;
    
    for(;;){
        erroTurnoPretas = 0;
        erroTurnoBrancas = 0;
        
        printaMatriz();
        
        detectarVitoria = detectaVitoria();
        if (detectarVitoria != '0')
            break;
        
        
        switch(regras){
            case 1:
                printaMatriz();
                jogadorBrancasComidaSingular();
                printaMatriz();
                jogadorPretasComidaSingular();
                break;
            case 2:
                printaMatriz();
                jogadorBrancasComidaSingular();
                printaMatriz();
                jogadorIASingleCome();
                break;
            case 3:
                printaMatriz();
                jogadorBrancasComidaMultipla();
                printaMatriz();
                jogadorPretasComidaMultipla();
                break;
            case 4:
                printaMatriz();
                jogadorBrancasComidaMultipla();
                printaMatriz();
                jogadorIAMultiCome();
                break;
            default:
                system("cls");
                printf("Erro: 'regras' selecionado incorretamente.\n"
                        "\nFECHANDO PROGRAMA!!!"
                        "\n[pressione algo para continuar]\n");
                getch();
                return 1;
        }
        
        turno++;
        
        if (erroTurnoPretas == 1 && erroTurnoBrancas == 1){
            detectarVitoria = 'e';
            break;
        }
        
        //getch();
        system("cls");
    }
    
    system("cls");
    if (detectarVitoria == 'B'){
        printf("Brancas venceram!");
        printaVitoria();
    }
    else if (detectarVitoria == 'P'){
        printf("Pretas venceram!");
        printaVitoria();
    }
    else if (detectarVitoria == 'e'){
        printf("EMPATE! Nenhum dos dois jogadores moveram ou comeram algo.\n"
                "Isto se deve pois:\n"
                "- Ou ambos jogadores nao realizaram movimentos corretos,\n"
                "- Ou ambos jogadores nao conseguiram fazer movimentos.\n"
                "\n[Pressione algo para fechar o jogo...]\n");
    }

    
    getch();
    return 0;
}