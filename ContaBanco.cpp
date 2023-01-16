#include <iostream>
#include <string>
#include "Conta.h"

using namespace std;

int main()
{
    ContaBancaria contaCliente( "Nubank", 8888, 999991, "Rafael", 20 );
    contaCliente.verSaldo();
    cout  << "\n";
    contaCliente.depositar( 140 );
    contaCliente.sacar( 50 );
    contaCliente.verSaldo();
    contaCliente.transferir( 80 );
    contaCliente.verSaldo();
    contaCliente.verDados();

    cout << "Object Orientation Programming";
    return 0;
}

ContaBancaria::ContaBancaria( string banco, int agencia, int conta, string titular, double saldo )
{
    this->banco = banco;
    this->agencia = agencia;
    this->conta = conta;
    this->titular = titular;
    this->saldo = saldo;
}

ContaBancaria::~ContaBancaria(){
    cout << "\n" << endl;
}

void ContaBancaria::depositar( int valor )
{
    this->saldo += valor; 
    cout << "Foi depositato R$" << valor << endl;
}

int ContaBancaria::sacar( int valor )
{
    if( valor <= this->saldo )
    {
        this->saldo -= valor; 
        cout << "Foi sacado R$" << valor << endl;
        return 1;
    } else {
        cout << "Saldo insuficiente." << endl;
        return 0;
    }
}

void ContaBancaria::transferir( int valor )
{
    this->saldo -= valor; 
    cout << "Foi transferido R$" << valor << endl;
}

void ContaBancaria::verSaldo()
{
    cout << "Seu saldo é R$" << this->saldo << endl;
}

void ContaBancaria::verDados()
{
    cout  << "\n";
    cout << this->titular << endl;
    cout << this->banco << endl;
    cout << this->agencia << endl;
    cout << this->conta << endl;
    cout << this->saldo << endl;
    cout  << "\n";
}