#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

using namespace std;

// funções
void menu();
void jogar();
void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10]);
void mostraTabuleiro(char tabuleiro[10][10], char mascara[10][10], bool gabarito);
void posicionaBarcos(char tabuleiro[10][10]);
void nomeJogo();


int main()
{
    srand((unsigned)time(NULL));
    
    menu();

    return 0;
}

void menu()
{
    int opcao;
    nomeJogo();
    cout << "[1] - JOGAR\n";
    cout << "[2] - SAIR\n";
    cout << "Escolha a opcao desejada: ";
    cin >> opcao;
    
    switch( opcao )
    {
        case 1:
            jogar();
            break;
        case 2:
            system("clear");
            cout << "Obrigado por jogar.";
            break;
        default:
            cout << "\nopcao inválida.\n";
            sleep(2);
            menu();
    }
    
}

void nomeJogo()
{
    cout << "===========================\n";
    cout << "====== BATALHA NAVAL ======\n";
    cout << "===========================\n\n";
}

void jogar()
{
    // variáveis 
    string nomeJogador;
    char tabuleiro[10][10];
    char mascara[10][10];
    int linhaJogada, colunaJogada;
    int tentativas = 0, maxTentativas = 10;
    
    // saudação ao jogador
    cout << "Qual seu nome? ";
    cin >> nomeJogador;
    system("clear");
    cout << "Olá, " << nomeJogador << "\nBEM VINDO AO JOGO!\n\n";

    // iniciando e preenchendo tabuleiro
    iniciaTabuleiro(tabuleiro, mascara);
    posicionaBarcos(tabuleiro);
    
    // execução do jogo
    while( tentativas < maxTentativas )
    {
        system("clear");
        nomeJogo();
        
        mostraTabuleiro(tabuleiro, mascara, false);
        
        cout << "\nPontos: " << pontos;
        cout << "\nTentativas: " << maxTentativas-tentativas << "\n";
        
        // bloqueia fora do intervalo [0 - 9]
        linhaJogada = -1;
        colunaJogada = -1;
        while( (linhaJogada < 0 || colunaJogada < 0) || (linhaJogada > 9 || colunaJogada > 9) )
        {
            cout << "\n" << nomeJogador << ", digite a linha: ";
            cin >> linhaJogada;
            cout << "\n" << nomeJogador << ", digite a coluna: ";
            cin >> colunaJogada;
        }
        
        // associa tabuleiro e mascara
        mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];
        
        // verifica acertos e erros
        if( mascara[linhaJogada][colunaJogada] == 'P')
        {
            cout << "\nIsso! Você acertou!.\n";
            sleep(2);
            pontos++;
        } else {
            printf("\nPutz, você atingiu a água.\n");
            sleep(2);
            tentativas++;
        }
    }
    if( tentativas == maxTentativas )
        cout << "\nJogo encerrado. Você perdeu.\n";
    else
        cout << "\nJogo encerrado. Você ganhow.\n";
    sleep(2);
    system("clear");
    menu();
}

void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10])
{
    int linha, coluna;
    
    for( linha = 0; linha < 10; linha++ )
    {
        for( coluna = 0; coluna < 10; coluna++ )
        {
            tabuleiro[linha][coluna] = 'A';
            mascara[linha][coluna] = '*';
        }
        cout << "\n";
    }
}

void mostraTabuleiro( char tabuleiro[10][10], char mascara[10][10], bool gabarito )
{
    int linha, coluna;
    char blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
    char normal[] = { 0x1b, '[', '1', ';', '3', '9', 'm', 0 };
    char green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
    
    // mostra colunas
    for( int cont = 0; cont < 10; cont++ )
    {
        if( cont == 0 )
            cout << "    ";
        
        cout << cont << " ";
    }
    cout << "\n";
    for( int cont = 0; cont < 10; cont++ )
    {
        if( cont == 0 )
            cout << "    ";
        
        cout << "| ";
    }
    cout << "\n";
    
    // exibe tabuleiro
    for( linha = 0; linha < 10; linha++ )
    {
        // mostra linhas
        if( linha < 10 )
            cout << linha << " - ";
        else 
            cout << linha << " - ";
            
        for( coluna = 0; coluna < 10; coluna++ )
        {
            if( mascara[linha][coluna] == 'P' )
                cout << green << mascara[linha][coluna] << " " << normal;
            else if( mascara[linha][coluna] == 'A' )
                cout << blue << mascara[linha][coluna] << " " << normal;
            else
                cout << normal << mascara[linha][coluna] << " ";
            
        }
        cout << "\n";
    }
    
    cout << "\n";
    
    // exibir gabarito
    if( gabarito == true )
    {
        for( linha = 0; linha < 10; linha++ )
        {
            for( coluna = 0; coluna < 10; coluna++ )
            {
                cout << tabuleiro[linha][coluna] << " ";
            }
            cout << "\n";
        }
    }
    cout << "\n";
}

void posicionaBarcos(char tabuleiro[10][10])
{
    // variáveis
    int posicao;
    int linhaBarco;
    int colunaBarco;
    int quantidade = 0;
    
    // insere barcos no tabuleiro
    while( quantidade < 10 )
    {
        linhaBarco = rand() % 10;
        colunaBarco = rand() % 10;
        
        if( tabuleiro[linhaBarco][colunaBarco] == 'A' )
        {
            tabuleiro[linhaBarco][colunaBarco] = 'P';
            
            quantidade++;
        }
    }
}
