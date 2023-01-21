// =============================== bibliotecas =================================
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
// =============================== std:: =======================================
using namespace std;
// ============================ Protótipo de funções ===========================
void menu();
void nomeJogo();
void jogar();
void iniciaTabuleiro( char tabuleiro[3][3] );
void exibeTatuleiro( char tabuleiro[3][3] );
int verificaGanhador( char tabuleiro[3][3] );
void mapaPosicoes();
// =============================================================================
int main()
{
    menu();

    return 0;
}
// =============================================================================
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
// ================================= Funções ===================================
void nomeJogo()
{
    cout << "===========================\n";
    cout << "====== JOGO DA VELHA ======\n";
    cout << "===========================\n\n";
}
// =============================================================================
void jogar()
{
    char tabuleiro[3][3];
    char nomeJogadorUm[50], nomeJogadorDois[50];
    int linhaJogada, colunaJogada;
    int tentativas = 0, maxTentativas = 9;
    int mudaTurno = 0;
    int estadoJogo = 1;
    int posicaoJogada;
    int posicoes[9][2] = 
    {
        {2,0},{2,1},{2,2},
        {1,0},{1,1},{1,2},
        {0,0},{0,1},{0,2},
    };
    
    // iniciando e preenchendo tabuleiro
    iniciaTabuleiro( tabuleiro );
    
    // pega nome dos jogadores
    cout << "Qual o nome do primeiro jogador? ";
    cin >> nomeJogadorUm;
    cout << "Qual o nome do segundo jogador? ";
    cin >> nomeJogadorDois;
    system("clear");
    
    nomeJogo();
    
    // saudação ao jogador
    cout << "Olá, " << nomeJogadorUm <<" e "<< nomeJogadorDois<< "\nBEM VINDOS AO JOGO!\n\n";
    
    // exibe tentativas
    cout << "\nTentativas: " << maxTentativas-tentativas << "\n";
    
    exibeTatuleiro(tabuleiro);
    mapaPosicoes();
    
    while( tentativas < maxTentativas && estadoJogo )
    {
        // Mostra o turno do jogador
        if( mudaTurno % 2 == 0 )
            cout << "Vez do "<< nomeJogadorUm << ", faça sua joagada!" << endl;
        else
            cout << "Vez do "<< nomeJogadorDois << ", faça sua joagada!" << endl;
        
        // comentada parte que pegava linha e coluna de forma individual
        
        // pega linha e coluna   
        // cout << "\n" << "Digite a linha: ";
        // cin >> linhaJogada;
        // cout << "\n" << "Digite a coluna: ";
        // cin >> colunaJogada;
        
        int invalido = 1;
        while( invalido == 1 )
        {
            cout << "Digite a posição conforme o mapa: " << endl;
            cin >> posicaoJogada;
            if( posicaoJogada < 0 || posicaoJogada > 9 )
            {
                invalido = 1;
                cout << "Numero inválido. Tente novamente.\n" << endl;
            }
            else 
                invalido = 0;
        }
        
        // o 1º [] pega a posição do par. o 2º [] pega a posição dentro do par
        // a linha pegará o valor da posição 0 do par e a coluna o valor da posição 1
        linhaJogada = posicoes[posicaoJogada-1][0];
        colunaJogada = posicoes[posicaoJogada-1][1];
        
        
        // bloqueia posições inválidas
        if( tabuleiro[linhaJogada][colunaJogada] == '*' )
        {
            // preenche tabuleiro com o valor de acordo com o turno
            if( mudaTurno % 2 == 0 )
            {
                tabuleiro[linhaJogada][colunaJogada] = 'x';
            }
            else
            {
                tabuleiro[linhaJogada][colunaJogada] = 'o';
            }
            // encerra loop quando for 0
            estadoJogo = verificaGanhador( tabuleiro ); 
            
            tentativas++;
            mudaTurno++;
        } else {
            cout << "opção inválida." << endl;
            sleep(1);
        }
        
        system("clear");
        nomeJogo();
        exibeTatuleiro(tabuleiro);
        mapaPosicoes();
    }
    // mostra quem ganhou
    if( tentativas == 9 )
    {
        // empate
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        cout << "-| DEU VELHA! - FIM DE JOGO! |-" << endl;
        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl;
        sleep(2);
        cout << "Pressione [ENTER] para continuar." << endl;
        getchar();
        system("clear");
        menu();
    } else {
        verificaGanhador( tabuleiro );
        sleep(2);
        cout << "Pressione [ENTER] para continuar." << endl;
        getchar();
        system("clear");
        menu();
    }
}
// =============================================================================
void iniciaTabuleiro( char tabuleiro[3][3] )
{
    // preenche tabuleiro
    for( int i = 0; i < 3; i++ )
    {
        for( int j = 0; j < 3; j++ )
        {
            tabuleiro[i][j] = '*';
        }
    }
}
// =============================================================================
void exibeTatuleiro(char tabuleiro[3][3])
{
    // Foi comentada indicações da linhas e colunas para o user
    
    // exibe posições da coluna
    // cout << "\t";
    // for( int i = 0; i < 3; i++ )
    // {
    //     if( i < 3 )
    //         cout << " " << i;
    //     cout << "  ";
    // }
    // cout << endl;
    // exibe separador coluna
    // cout << "\t";
    // for( int i = 0; i < 3; i++ )
    // {
    //     if( i < 3 )
    //         cout << " |  ";
    // }
    // cout << endl;
    
    for( int i = 0; i < 3; i++ )
    {
        // exibe posições das linhas
        // if( i < 3 )
        // {
        //     cout << i << " - ";
        // }
        cout << "\t";
        for( int j = 0; j < 3; j++ )
        {
            if( j < 2 )
                cout << " " << tabuleiro[i][j] << " " << "|";
            else
                cout << " " << tabuleiro[i][j];
        }
        cout << endl;
        if( i < 2 )
            cout << "\t" "-----------" << endl; // divisória horizontal
    }
}
// =============================================================================
int verificaGanhador( char tabuleiro[3][3] )
{
    // digaonais para x
    if( tabuleiro[0][0] == 'x' && tabuleiro[1][1] == 'x' && tabuleiro[2][2] == 'x' || 
        tabuleiro[2][0] == 'x' && tabuleiro[1][1] == 'x' && tabuleiro[0][2] == 'x' )
    {
        cout << "X Ganhow! Diagonal preenchida!" << endl;
        return 0;
        // verticais para x
    } else if( tabuleiro[0][0] == 'x' && tabuleiro[1][0] == 'x' && tabuleiro[2][0] == 'x' || 
               tabuleiro[0][1] == 'x' && tabuleiro[1][1] == 'x' && tabuleiro[2][1] == 'x' || 
               tabuleiro[0][2] == 'x' && tabuleiro[1][2] == 'x' && tabuleiro[2][2] == 'x' )
    {
        cout << "X Ganhow! Vertical preenchida!" << endl;
        return 0;
        // horizontais para x
    }  else if( tabuleiro[0][0] == 'x' && tabuleiro[0][1] == 'x' && tabuleiro[0][2] == 'x' || 
                tabuleiro[1][0] == 'x' && tabuleiro[1][1] == 'x' && tabuleiro[1][2] == 'x' || 
                tabuleiro[2][0] == 'x' && tabuleiro[2][1] == 'x' && tabuleiro[2][2] == 'x' )
    {
        cout << "X Ganhow! Horizontal preenchida!" << endl;
        return 0;
        //diagonais para o
    } else if( tabuleiro[0][0] == 'o' && tabuleiro[1][1] == 'o' && tabuleiro[2][2] == 'o' || 
        tabuleiro[2][0] == 'o' && tabuleiro[1][1] == 'o' && tabuleiro[0][2] == 'o'  )
    {
        cout << "O Ganhow! Diagonal preenchida!" << endl;
        // verticais para o
    } else if( tabuleiro[0][0] == 'o' && tabuleiro[1][0] == 'o' && tabuleiro[2][0] == 'o' || 
               tabuleiro[0][1] == 'o' && tabuleiro[1][1] == 'o' && tabuleiro[2][1] == 'o' || 
               tabuleiro[0][2] == 'o' && tabuleiro[1][2] == 'o' && tabuleiro[2][2] == 'o' )
    {
        cout << "O Ganhow! Vertical preenchida!" << endl;
        return 0;
        // horizontais para o
    }  else if( tabuleiro[0][0] == 'o' && tabuleiro[0][1] == 'o' && tabuleiro[0][2] == 'o' || 
                tabuleiro[1][0] == 'o' && tabuleiro[1][1] == 'o' && tabuleiro[1][2] == 'o' || 
                tabuleiro[2][0] == 'o' && tabuleiro[2][1] == 'o' && tabuleiro[2][2] == 'o' )
    {
        cout << "O Ganhow! Horizontal preenchida!" << endl;
        return 0;
    }
    
    return 1;
}

void mapaPosicoes()
{
    cout << "\n   -| MAPA DE POSIÇÕES |-" << endl;
    cout << "    ==================== " << endl;
    
    cout << "\t 7 | 8 | 9 " << endl;
    cout << "\t-----------" << endl;
    cout << "\t 4 | 5 | 6 " << endl;
    cout << "\t-----------" << endl;
    cout << "\t 1 | 2 | 3 " << endl;
}
// ============================================================================
                            // FIM DO PROGRAMA //
// =============================================================================
