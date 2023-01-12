#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void exibeForca( int e )
{
    switch(e)
    {
        case 0:
            printf("\n-------\n");
            printf("|      \n");
            printf("|      \n");
            printf("|      \n");
            printf("\n");
            break;
        case 1:
            printf("\n-------\n");
            printf("|     o\n");
            printf("|      \n");
            printf("|      \n");
            printf("\n");
            break;
        case 2:
            printf("\n-------\n");
            printf("|     o\n");
            printf("|    / \n");
            printf("|       \n");
            printf("\n");
            break;
        case 3:
            printf("\n-------\n");
            printf("|     o\n");
            printf("|    /| \n");
            printf("|      \n");
            printf("\n");
            break;
        case 4:
            printf("\n-------\n");
            printf("|     o\n");
            printf("|    /|\\ \n");
            printf("|      \n");
            printf("\n");
            break;
        case 5:
            printf("\n-------\n");
            printf("|     o\n");
            printf("|    /|\\ \n");
            printf("|    / \n");
            printf("\n");
            break;
        case 6://default:
            printf("\n-------\n");
            printf("|     o\n");
            printf("|    /|\\ \n");
            printf("|    / \\ \n");
            printf("\n");
            break;
    }
}

int main( void )
{
    // banco de palavras
    char banco[30][30] =
    {
        "cafe",
        "garrafa",
        "notebook",
        "dinheiro",
        "programacao",
        "backend",
        "frontend",
        "fullstack",
        "github"
    };
    
    srand(time(NULL));
    
    // variáveis
    int sorteioPalavra = rand() % 4; 
    
    char letraUsuario;
    
    int TAM = strlen(banco[sorteioPalavra]);
    
    char *statusPalavra;
    
    statusPalavra = (char *)malloc(TAM * sizeof(char));
    
    int erros = 0;
    
    int encerra = 0;

    char letrasDigitadas[10] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    
    // preenche vetor statusPalavra
    for( int q = 0; q < TAM; q++ )
    {
        statusPalavra[q] = '_';
    }
    
    int pos = 0;
    
    // execução do jogo
    while( encerra == 0 )//erros < 6
    {
        system("clear");
        exibeForca(erros);
        
        for( int q = 0; q < TAM; q++ )
        {
            printf("%c ", statusPalavra[q]);
        }
        
        printf("\n\nTentativas: %d\n\n", 6-erros);

        printf("Letras digitadas: \n");
        for( int i = 0; i < 10; i++ )
        {
            printf("%c ", letrasDigitadas[i]);
        }
        printf("\n\n");
        
        printf("Digite uma letra: ");
        scanf("%c", &letraUsuario);
        getchar();
        letrasDigitadas[pos] = letraUsuario;
        pos++;
        
        int seErrou = 1;
        for( int t = 0; t < TAM; t++ )
        {
            if( letraUsuario == banco[sorteioPalavra][t] )
            {
                statusPalavra[t] = banco[sorteioPalavra][t];
                seErrou = 0;
            }
        }
        
        // verifica se houve erro
        if( seErrou == 1 )
        {
            erros++;
        }
        
        // verifica erro e finaliza o jogo
        if(erros==6)
        {
            system("clear");
            encerra = 1;
            printf("Game Over for you\n");
            printf("\nA palavra era %s", banco[sorteioPalavra]);
            getchar();
            
        } else if ( strcmp(banco[sorteioPalavra], statusPalavra) == 0 )
        {
            system("clear");
            encerra = 1;
            printf("YOU WIN");
            getchar();
        }
    }

    return 0;
}
