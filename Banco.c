#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// #include <windows.h>
#include <time.h>

// Tipo cliente
typedef struct 
{
    int codigo;
    char nome[50];
    char email[50];
    char cpf[20];
    char dataNascimento[20];
    char dataCadastro[20];
} Cliente;

// Tipo conta
typedef struct
{
    int numero;
    Cliente cliente;
    float saldo;
    float limite;
    float saldoTotal; // saldo + limite
} Conta;

// Procedimentos e funções
void menu();
void infoCliente( Cliente cliente );
void infoConta( Conta conta );
void criarConta();
void efetuarSaque();
void efetuarDeposito();
void efetuarTransferencia();
void listarContas();
float atualizaSaldoTotal( Conta conta );
Conta buscaContaPorNumero( int numeroConta );
void sacar( Conta conta, float valor );
void depositar( Conta conta, float valor );
void transferir( Conta contaOrigem, Conta contaDestino, float valor );

// Variaveis estaticas
static Conta contas[50];
static int contadorContas = 0;
static int contadorClientes = 0;

int main()
{
    menu();

    return 0;
}

void menu()
{
    system("clear");
    printf("=================================\n");
    printf("========== Bem vindo(a) =========\n");
    printf("========== MERZAN BANK  =========\n");
    printf("=================================\n\n");
    
    printf("----------- | MENU | ------------\n\n");
    printf("[ 1 ] - Criar conta\n");
    printf("[ 2 ] - Listar contas\n");
    printf("[ 3 ] - Deposito\n");
    printf("[ 4 ] - Saque\n");
    printf("[ 5 ] - Transferência\n");
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
            criarConta();
            break;
        case 2:
            listarContas();
            break;
        case 3:
            efetuarDeposito();
            break;
        case 4:
            efetuarSaque();
            break;
        case 5:
            efetuarTransferencia();
            break;
        case 6:
            system("clear");
            printf("Obrigado pela preferência.");
            break;
        default:
            printf("Opção inválida.\n\n");
    }
}

void infoCliente( Cliente cliente )
{
    printf("Código: %d\nCliente: %s, E-mail: %s\nCPF: %s\nNascimento: %s\nCadastro: %s\n\n",
    cliente.codigo, strtok(cliente.nome, "\n"), strtok(cliente.email, "\n"), 
    strtok(cliente.cpf, "\n"), strtok(cliente.dataNascimento, "\n"), 
    strtok(cliente.dataCadastro, "\n"));
}

void infoConta( Conta conta )
{
    printf("Nº: %d\nCliente: %s\nSaldo: %.2f\nLimite: %.2f\nLimite Total: %.2f\n",
    conta.numero, strtok(conta.cliente.nome, "\n"), conta.saldo, conta.limite, 
    conta.saldoTotal);
}

void criarConta()
{
    Cliente cliente;
    
    char dia[3];
    char mes[3];
    char ano[3];
    char dataDeCadastro[20];
    
    time_t t = time(NULL);
    
    struct tm tempo = *localtime(&t);
    
    // dia
    if( tempo.tm_mday < 10 )
    {
        sprintf(dia, "0%d", tempo.tm_mday);
    } else {
        sprintf(dia, "%d", tempo.tm_mday);
    }
    
    // mes
    if( tempo.tm_mon < 10 )
    {
        sprintf(mes, "0%d", tempo.tm_mon);
    } else {
        sprintf(mes, "%d", tempo.tm_mon);
    }
    
    // ano
    sprintf(ano, "%d", (tempo.tm_year + 1900));
    
    strcpy(dataDeCadastro,"");
    strcat(dataDeCadastro, dia);
    strcat(dataDeCadastro, "/");
    strcat(dataDeCadastro, mes);
    strcat(dataDeCadastro, "/");
    strcat(dataDeCadastro, ano);
    strcat(dataDeCadastro, "\0");
    strcpy(dataDeCadastro,"");
    
    strcat(cliente.dataCadastro, dataDeCadastro);
    
    // criar cliente
    printf("Infome os dados do cliente.\n\n");
    cliente.codigo = contadorClientes + 1;
    
    printf("Nome do cliente: ");
    fgets(cliente.nome, 50, stdin);
    
    printf("\nE-mail: ");
    fgets(cliente.email, 50, stdin);
    
    printf("\nCPF: ");
    fgets(cliente.cpf, 20, stdin);
    
    printf("\nData de nascimento: ");
    fgets(cliente.dataNascimento, 20, stdin);
    
    infoCliente( cliente );
    printf("\n==================\n\n");
    sleep(5);
    
    contadorClientes++;
    
    // criar conta
    contas[contadorContas].numero = contadorContas + 1;
    contas[contadorContas].cliente = cliente;
    contas[contadorContas].saldo = 0.0;
    contas[contadorContas].limite = 0.0;
    contas[contadorContas].saldoTotal = atualizaSaldoTotal( contas[contadorContas] );
    
    printf("\nConta criada com sucesso.\n\n");
    
    printf("Dados da conta criada:\n");
    infoConta( contas[contadorContas] );
    
    contadorContas++;
    sleep(4);
    menu();
    
}

void efetuarSaque()
{
    if( contadorContas > 0 )
    {
        int numeroInformado;
        printf("Informe o número da conta: ");
        scanf("%d", &numeroInformado);   
        
        Conta conta = buscaContaPorNumero( numeroInformado );
        
        // dupla verificação
        if( conta.numero == numeroInformado )
        {
            float valorSaque;
            printf("Informe valor para saque: ");
            scanf("%f", &valorSaque);
            
            sacar( conta, valorSaque );
            
        } else {
            printf("Não foi encontrado uma conta com o número %d\n.", numeroInformado);
        }
        
    } else {
        printf("\nAinda não existem contas cadastradas.\n");
    }
    sleep(2);
    menu();
}

void efetuarDeposito()
{
    if( contadorContas > 0 )
    {
        int numeroInformado;
        printf("Informe o número da sua conta: ");
        scanf("%d", &numeroInformado);   
        
        Conta conta = buscaContaPorNumero( numeroInformado );
        
        // dupla verificação
        if( conta.numero == numeroInformado )
        {
            float valorDeposito;
            printf("Informe valor para depósito: ");
            scanf("%f", &valorDeposito);
            
            depositar( conta, valorDeposito );
            
        } else {
            printf("Não foi encontrado uma conta com o número %d\n.", numeroInformado);
        }
        
    } else {
        printf("\nAinda não existem contas cadastradas.\n");
    }
    sleep(2);
    menu();
}

void efetuarTransferencia()
{
    if( contadorContas > 0 )
    {
        int numeroOrigem;
        int numeroDestino;
        
        printf("Informe o número da sua conta: ");
        scanf("%d", &numeroOrigem);   
        
        Conta contaOrigem = buscaContaPorNumero( numeroOrigem );
        
        // dupla verificação
        if( contaOrigem.numero == numeroOrigem )
        {
            printf("\nInforme o número da conta destino: ");
            scanf("%d", &numeroDestino);
            
            Conta contaDestino = buscaContaPorNumero( numeroDestino );
            
            if( contaDestino.numero == numeroDestino )
            {
                float valorTransf;
                printf("\nInforme valor para transferência: ");
                scanf("%f", &valorTransf);
                
                transferir( contaOrigem, contaDestino, valorTransf );
            }
            
        } else {
            printf("Não foi encontrado uma conta com o número %d\n.", numeroOrigem);
        }
        
    } else {
        printf("\nAinda não existem contas cadastradas.\n");
        sleep(2);
        menu();
    }
    sleep(2);
    menu();
}

void listarContas()
{
    if( contadorContas > 0 )
    {
        for( int indice = 0; indice < contadorContas; indice++ )
        {
            infoConta( contas[indice] );
            printf("\n======================\n");
        }
        printf("Presione [ENTER] para continuar.");
        getchar();
        menu();
        
    } else {
        printf("\nNão há contas cadastradas.\n");
        sleep(2);
        menu();
    }
}

float atualizaSaldoTotal( Conta conta )
{
    return conta.saldo + conta.limite;
}

Conta buscaContaPorNumero( int numeroConta )
{
    Conta contaBanco;
    
    if( contadorContas > 0 )
    {
        for( int busca = 0; busca < contadorContas; busca++ )
        {
            if( contas[busca].numero == numeroConta )
            {
                contaBanco = contas[busca];
            }
        }
    }
    
    return contaBanco;
}

void sacar( Conta conta, float valor )
{
    if( valor > 0 && valor <= conta.saldoTotal )
    {
        for( int busca = 0; busca < contadorContas; busca++ )
        {
            if( contas[busca].numero == conta.numero )
            {
                if( valor <= conta.saldoTotal )
                {
                    contas[busca].saldo -= valor;
                    contas[busca].saldoTotal = atualizaSaldoTotal( contas[busca] );
                    printf("\nSaque efetuado com sucesso.\n");
                } else {
                    float restante = contas[busca].saldo - valor;
                    contas[busca].limite += restante;
                    contas[busca].saldo = 0.0;
                    contas[busca].saldoTotal = atualizaSaldoTotal( contas[busca] );
                    printf("\nSaldo insuficiente. Limite dispoinivel utilizado.\n");
                }
            }
        }
    } else {
        printf("Verifique o valor e tente novamente.\n");
        sleep(2);
    }
}

void depositar( Conta conta, float valor )
{
    if( valor > 0 )
    {
        for( int busca = 0; busca < contadorContas; busca++ )
        {
            if( contas[busca].numero == conta.numero )
            {
                contas[busca].saldo += valor;
                contas[busca].saldoTotal = atualizaSaldoTotal( contas[busca] );
                printf("\nDeposito realizado com sucesso.\n");
            }
        }
    } else {
        printf("\nErro no deposito. Verifique valor informado.\n");
        sleep(2);
    }
}

void transferir( Conta contaOrigem, Conta contaDestino, float valor )
{
    if( valor > 0 && contaOrigem.saldoTotal >= valor )
    {
        for( int origem = 0; origem < contadorContas; origem++ )
        {
            if( contas[origem].numero == contaOrigem.numero )
            {
                for(  int destino = 0; destino < contadorContas; destino++  )
                {
                    if( contas[destino].numero == contaDestino.numero )
                    {
                        if( valor <= contas[origem].saldo )
                        {
                            contas[origem].saldo -= valor;
                            contas[origem].saldo = atualizaSaldoTotal( contas[origem] );
                            
                            contas[destino].saldo += valor;
                            contas[destino].saldo = atualizaSaldoTotal( contas[destino] );
                            
                            printf("\nTransferência realizada.\n");
                            
                        } else {
                            float restante = contas[origem].saldo - valor;
                            contas[origem].limite += restante;
                            contas[origem].saldo = 0.0;
                            contas[origem].saldoTotal = atualizaSaldoTotal( contas[origem] );
                            
                            contas[destino].saldo += valor;
                            contas[destino].saldo = atualizaSaldoTotal( contas[destino] );
                            
                            printf("\nSaldo insuficiente. Limite dispoinivel utilizado.\n");
                        }
                    }
                }
            }
        }
        
    } else {
        printf("\nErro ao efetuar transferência. Tente novamente.\n");
    }
}
