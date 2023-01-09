#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef _linux_
    #include <unistd.h>
#elif _win32_
    #include <windows.h>
#endif

typedef struct
{
    int codigo;
    char nome[30];
    float preco;
} Produto;

typedef struct
{
    Produto produto;
    int quantidade;
} Carrinho;

void infoProduto( Produto prod );
void menu();
void cadastrarProduto();
void listarProdutos();
void comprarProduto();
void visualizarCarrinho();
Produto pegarProdutoPorCodigo( int codigo );
int *temNoCarrinho( int codigo );
void fecharPedido();

static int contadorProduto = 0;
static int contadorCarrinho = 0;
static Carrinho carrinho[50];
static Produto produtos[50];

int main()
{
    menu();

    return 0;
}

void infoProduto( Produto prod )
{
    printf("Código: %d\nNome: %s\nPreço: %.2f\n", 
    prod.codigo, strtok(prod.nome, "\n"), prod.preco);
}

void menu()
{
    system("clear");
    printf("=================================\n");
    printf("========== Bem vindo(a) =========\n");
    printf("========== MERZAN SHOP  =========\n");
    printf("=================================\n\n");
    
    printf("----------- | MENU | ------------\n\n");
    printf("[ 1 ] - Cadastrar produto\n");
    printf("[ 2 ] - Listar produtos\n");
    printf("[ 3 ] - Comprar produto\n");
    printf("[ 4 ] - Visualizar carrinho\n");
    printf("[ 5 ] - Fechar pedido\n");
    printf("[ 6 ] - Sair do sistema\n");
    printf("--------------------------------\n\n");
    
    int opcao;
    printf("Informe a opcao desejada: ");
    scanf("%d", &opcao);
    getchar();
    printf("\n");
    
    switch( opcao )
    {
        case 1:
            cadastrarProduto();
            break;
        case 2:
            listarProdutos();
            break;
        case 3:
            comprarProduto();
            break;
        case 4:
            visualizarCarrinho();
            break;
        case 5:
            fecharPedido();
            break;
        case 6:
            // system("clear");
            printf("Volte sempre.");
            sleep(2);
            // break;
            exit(0);
        default:
            printf("Opção inválida.\n");
            sleep(2);
            menu();
            break;
    }
}

void cadastrarProduto()
{
    printf("Cadastro do produto\n");
    printf("===================\n\n");
    
    printf("Informe o nome do produto: \n");
    fgets(produtos[contadorProduto].nome, 30, stdin);
    
    printf("Informe o preço do produto: \n");
    scanf("%f", &produtos[contadorProduto].preco);
    
    printf("Produto %s foi cadastrado com sucesso.\n\n",
    strtok(produtos[contadorProduto].nome, "\n"));
    
    produtos[contadorProduto].codigo = contadorProduto + 1;
    
    contadorProduto++;
    
    sleep(2);
    
    menu();
}

void listarProdutos()
{
    if( contadorProduto > 0 )
    {
        printf("Listagem de produtos\n");
        printf("====================\n\n");
        
        for( int r = 0; r < contadorProduto; r++ )
        {
            infoProduto(produtos[r]);
            printf("================================\n\n");
            // sleep(1);
        }
        printf("Tecle [ENTER] para continuar.");
        getchar();
        menu();
    } else {
        printf("Você ainda não tem produtos cadastrados.\n");
        sleep(2);
        menu();
    }
}


void comprarProduto()
{
    if( contadorProduto > 0 )
    {
        int codProd;
        
        printf("Informe o código do produto que deseja adicionar ao carrinho:\n");
        printf("========== Produtos disponíveis ==========\n");
        for( int r = 0; r < contadorProduto; r++ )
        {
            infoProduto( produtos[r] );
            printf("--------------\n");
        }
        
        scanf("%d", &codProd);
        // getchar();
        
        // printf("O produto %s foi adicionado ao carrinho.\n", strtok(produtos[contadorCarrinho].nome, "\n"));
        
        // carrinho[contadorCarrinho].produto = produtos[contadorCarrinho];
        // carrinho[contadorCarrinho].quantidade++;
        // contadorCarrinho++;
        
        int temNoMercado = 0;
        
        for( int r = 0; r < contadorProduto; r++ )
        {
            if( produtos[r].codigo == codProd )
            {
                temNoMercado = 1;
                
                if( contadorCarrinho > 0 )
                {
                    int *retorno = temNoCarrinho( codProd );
                    
                    if( retorno[0] == 1 )
                    {
                        carrinho[retorno[1]].quantidade++;
                        printf("Produto %s existente na lista. Quantidade aumentada.\n",
                        strtok(carrinho[retorno[1]].produto.nome, "\n"));
                        sleep(2);
                        menu();
                    } else { // tem algum produto no carrinho
                        Produto p = pegarProdutoPorCodigo( codProd );
                        carrinho[contadorCarrinho].produto = p;
                        carrinho[contadorCarrinho].quantidade = 1;
                        contadorCarrinho++;
                        
                        printf("O produto %s foi adicionado ao carrinho.\n",
                        strtok(p.nome, "\n"));
                        
                        sleep(2);
                        menu();
                    }
                } else { // não tem produto no carrinho
                    Produto p = pegarProdutoPorCodigo( codProd );
                    carrinho[contadorCarrinho].produto = p;
                    carrinho[contadorCarrinho].quantidade = 1;
                    contadorCarrinho++;
                    
                    printf("O produto %s foi adicionado ao carrinho.\n",
                    strtok(p.nome, "\n"));
                    
                    sleep(2);
                    menu();
                }
            } else {
                printf("Não foi encontrado produto com o código %d\n", 
                codProd);
            }
        }
        
        sleep(2);
        menu();
        
    } else {
        printf("Não há produtos cadastrados.\n");
        sleep(2);
        system("clear");
        menu();
    }
}

void visualizarCarrinho()
{
    if( contadorCarrinho > 0 )
    {
        printf("Produtos no carrinho\n");
        printf("====================\n");
        
        for( int r = 0; r < contadorCarrinho; r++ )
        {
            infoProduto(carrinho[r].produto);
            printf("quantidade: %d\n", carrinho[r].quantidade);
            printf("===================\n");
        }
        printf("Tecle [ENTER] para continuar.");
        getchar();
        menu();
        
    } else {
        printf("Ainda não têm produtos no carrinho.\n");
        sleep(2);
        menu();
    }
}

Produto pegarProdutoPorCodigo( int codigo )
{
    Produto p;
    
    for( int r = 0; r < contadorCarrinho; r++ )
    {
        if( produtos[r].codigo == codigo )
        {
            p = produtos[r];
        }
    }
    
    return p;
}

int *temNoCarrinho( int codigo )
{
    int static retorno[] = { 0, 0 };
    for( int r = 0; r < contadorCarrinho; r++ )
    {
        if( carrinho[r].produto.codigo == codigo )
        {
            retorno[0] = 1;
            retorno[1] = r;
        }
    }
    
    return retorno;
}

void fecharPedido()
{
    if( contadorCarrinho > 0 )
    {
        float valorTotal = 0.0;
        
        printf("Produtos no carrinho\n");
        printf("====================\n\n");
        
        for( int r = 0; r < contadorCarrinho; r++ )
        {
            Produto p = carrinho[r].produto;
            int quantidade = carrinho[r].quantidade;
            valorTotal += p.preco * quantidade;
            infoProduto( p );
            printf("Quantidade: %d\n", quantidade);
            printf("=============\n\n");
        }
        printf("O valor da sua conta é R$ %.2f\n", valorTotal);
        contadorCarrinho = 0;
        printf("Obrigado pela preferência!\n");
        sleep(5);
        menu();
    } else {
        printf("Você ainda não tem produtos no carrinho.\n");
        sleep(3);
        menu();
    }
}
