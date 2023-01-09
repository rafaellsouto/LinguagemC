#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int dificuldade;
    int valor1;
    int valor2;
    int operacao;
    int resultado;
} Calcular;


void jogar();
int somar( int resposta, Calcular calc );
int subtrair( int resposta, Calcular calc );
int multiplicar( int resposta, Calcular calc );

int main()
{
    
    srand(time(NULL));
    
    jogar();

    return 0;
}

int pontos;

void jogar(){
    Calcular calc;
    int dificuldade;
    
    printf("\nInfome o nível de dificuldade [ 1, 2, 3 ou 4 ]\n");
    scanf("%d", &dificuldade);
    calc.dificuldade = dificuldade;
    
    calc.operacao = rand() % 3;
    
    if( calc.dificuldade == 1 )
    {
        calc.valor1 = rand() % 11;
        calc.valor2 = rand() % 11;
        
    } else if( calc.dificuldade == 2 ) {
        
        calc.valor1 = rand() % 101;
        calc.valor2 = rand() % 101;
        
    } else if( calc.dificuldade == 3 ) {
        
        calc.valor1 = rand() % 1001;
        calc.valor2 = rand() % 1001;
        
    } else if( calc.operacao == 4 ){
        
        calc.valor1 = rand() % 10001;
        calc.valor2 = rand() % 10001;
        
    } else {
        
        calc.valor1 = rand() % 100001;
        calc.valor2 = rand() % 100001;
    }
    
    int resposta;
    
    printf("\nInfome o calculo para a seguinte operacao: \n");
    
    //somar
    if( calc.operacao == 0 )
    {
        printf("%d + %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        
        if( somar( resposta, calc ) )
        {
            pontos++;
            printf("\nVoce perdeu %d ponto!", pontos);
        } else {
            pontos--;
            printf("\nVoce perdeu 1 ponto!");
        }
    } else if( calc.operacao == 1 )
    {
        printf("%d - %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        
        if( subtrair( resposta, calc ) )
        {
            pontos++;
            printf("\nVoce tem %d ponto(s)!", pontos);
        } else {
            pontos--;
            printf("\nVoce perdeu 1 ponto!");
        }
    } else if( calc.operacao == 2 )
    {
        printf("%d * %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        
        if( multiplicar( resposta, calc ) )
        {
            pontos++;
            printf("\nVoce tem %d ponto(s)!\n", pontos);
        } else {
            pontos--;
            printf("\nVoce perdeu 1 ponto!");
        }
    } else {
        printf("Operação não é conhecida.");
    }
    
    printf("\nDeseja continuar jogando? [ 1 - sim | 0 - não ]\n");
    int continuar;
    scanf("%d", &continuar);
    
    if( continuar )
    {
        jogar();
    } else {
        printf("\nVoce finalizou com %d ponto(s)\nAté a proxima\n", pontos);
    }
}

int somar( int resposta, Calcular calc )
{
    int resultado;
    int certo = 0;
    
    resultado = calc.valor1 + calc.valor2;
    calc.resultado = resultado;
    
    if( resposta == calc.resultado )
    {
        printf("\nResposta Correta!\n");
        certo = 1;
    } else {
        printf("\nResposta Errada!\n");
    }
    printf("%d + %d = %d", calc.valor1, calc.valor2, calc.resultado);
    
    return certo;
}

int subtrair( int resposta, Calcular calc )
{
    int resultado;
    int certo = 0;
    
    resultado = calc.valor1 - calc.valor2;
    calc.resultado = resultado;
    
    if( resposta == calc.resultado )
    {
        printf("\nResposta Correta!\n");
        certo = 1;
    } else {
        printf("\nResposta Errada!\n");
    }
    printf("%d - %d = %d", calc.valor1, calc.valor2, calc.resultado);
    
    return certo;
}

int multiplicar( int resposta, Calcular calc )
{
    int resultado;
    int certo = 0;
    
    resultado = calc.valor1 * calc.valor2;
    calc.resultado = resultado;
    
    if( resposta == calc.resultado )
    {
        printf("\nResposta Correta!\n");
        certo = 1;
    } else {
        printf("\nResposta Errada!\n");
    }
    printf("%d * %d = %d", calc.valor1, calc.valor2, calc.resultado);
    
    return certo;
}

/*

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int dificuldade;
    int valor1;
    int valor2;
    int operacao;
    int resultado;
} Calcular;


void jogar();
// void mostrarInfo( Calcular calc );
int somar( int resposta, Calcular calc );
int subtrair( int resposta, Calcular calc );
int multiplicar( int resposta, Calcular calc );
int dividir( int resposta, Calcular calc );

int main()
{
    
    srand(time(NULL));
    
    jogar();

    return 0;
}

int pontos;

void jogar(){
    Calcular calc;
    int dificuldade;
    
    printf("\nInfome o nível de dificuldade [ 1, 2, 3 ou 4 ]\n");
    scanf("%d", &dificuldade);
    calc.dificuldade = dificuldade;
    
    calc.operacao = rand() % 4;
    
    if( calc.dificuldade == 1 )
    {
        calc.valor1 = rand() % 11;
        calc.valor2 = rand() % 11;
        
    } else if( calc.dificuldade == 2 ) {
        
        calc.valor1 = rand() % 101;
        calc.valor2 = rand() % 101;
        
    } else if( calc.dificuldade == 3 ) {
        
        calc.valor1 = rand() % 1001;
        calc.valor2 = rand() % 1001;
        
    } else if( calc.operacao == 4 ){
        
        calc.valor1 = rand() % 10001;
        calc.valor2 = rand() % 10001;
        
    } else {
        
        calc.valor1 = rand() % 100001;
        calc.valor2 = rand() % 100001;
    }
    
    int resposta;
    
    printf("\nInfome o calculo para a seguinte operacao: \n");
    
    //somar
    if( calc.operacao == 0 )
    {
        printf("%d + %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        
        if( somar( resposta, calc ) )
        {
            pontos++;
            printf("\nVoce perdeu %d ponto!", pontos);
        } else {
            pontos--;
            printf("\nVoce perdeu 1 ponto!");
        }
    } else if( calc.operacao == 1 )
    {
        printf("%d - %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        
        if( subtrair( resposta, calc ) )
        {
            pontos++;
            printf("\nVoce tem %d ponto(s)!", pontos);
        } else {
            pontos--;
            printf("\nVoce perdeu 1 ponto!");
        }
    } else if( calc.operacao == 2 )
    {
        printf("%d * %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        
        if( multiplicar( resposta, calc ) )
        {
            pontos++;
            printf("\nVoce tem %d ponto(s)!\n", pontos);
        } else {
            pontos--;
            printf("\nVoce perdeu 1 ponto!");
        }
    } else if( calc.operacao == 3 ) {
        printf("%d / %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        
        if( dividir( resposta, calc ) )
        {
            pontos++;
            printf("\nVoce tem %d ponto(s)!\n", pontos);
        } else {
            pontos--;
            printf("\nVoce perdeu 1 ponto!");
        }
    } else {
        printf("Operação não é conhecida.");
    }
    
    printf("\nDeseja continuar jogando? [ 1 - sim | 0 - não ]\n");
    int continuar;
    scanf("%d", &continuar);
    
    if( continuar )
    {
        jogar();
    } else {
        printf("\nVoce finalizou com %d ponto(s)\nAté a proxima\n", pontos);
    }
}

// void mostrarInfo( Calcular calc )
// {
//     char opcao[15];
    
//     if( calc.operacao == 0 )
//     {
//         sprintf( opcao, "Somar" );
//     } else if( calc.operacao == 1 ) 
//     {
//         sprintf( opcao, "Substrair" );
//     } else if( calc.operacao == 2 ) 
//     {
//         sprintf( opcao, "Multiplicar" );
//     }
//     else if( calc.operacao == 3 ) 
//     {
//         sprintf( opcao, "Dividir" );
//     } else 
//     {
//         printf( "\nOperação desconhecida\n" );
//     }
    
    
//     printf("\nValor 1: %d - Valor 2: %d \nDificuldade: %d \nOperação: %s ",
//     calc.valor1, calc.valor2, calc.dificuldade, opcao);
// }

int somar( int resposta, Calcular calc )
{
    int resultado;
    int certo = 0;
    
    resultado = calc.valor1 + calc.valor2;
    calc.resultado = resultado;
    
    if( resposta == calc.resultado )
    {
        printf("\nResposta Correta!\n");
        certo = 1;
    } else {
        printf("\nResposta Errada!\n");
    }
    printf("%d + %d = %d", calc.valor1, calc.valor2, calc.resultado);
    
    return certo;
}

int subtrair( int resposta, Calcular calc )
{
    int resultado;
    int certo = 0;
    
    resultado = calc.valor1 - calc.valor2;
    calc.resultado = resultado;
    
    if( resposta == calc.resultado )
    {
        printf("\nResposta Correta!\n");
        certo = 1;
    } else {
        printf("\nResposta Errada!\n");
    }
    printf("%d - %d = %d", calc.valor1, calc.valor2, calc.resultado);
    
    return certo;
}

int multiplicar( int resposta, Calcular calc )
{
    int resultado;
    int certo = 0;
    
    resultado = calc.valor1 * calc.valor2;
    calc.resultado = resultado;
    
    if( resposta == calc.resultado )
    {
        printf("\nResposta Correta!\n");
        certo = 1;
    } else {
        printf("\nResposta Errada!\n");
    }
    printf("%d * %d = %d", calc.valor1, calc.valor2, calc.resultado);
    
    return certo;
}

int dividir( int resposta, Calcular calc )
{
    int resultado;
    int certo = 0;
    
    resultado = calc.valor1 / calc.valor2;
    calc.resultado = resultado;
    
    if( resposta == calc.resultado )
    {
        printf("Resposta Correta!\n");
        certo = 1;
    } else {
        printf("Resposta Errada!\n");
    }
    printf("%d / %d = %d", calc.valor1, calc.valor2, calc.resultado);
    
    return certo;
}




*/
