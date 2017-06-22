#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "funcoes.cpp"
#include "classes.cpp"

Laboratorio labOficial = Laboratorio();

int boasVindas(){
    int opcaoEscolhida;
    std::cout<<"====================================================="<<std::endl;
    std::cout<<"Olá, você já possui registro?"<<std::endl;
    std::cout<<"\n";
    std::cout<<"0) Não \n1) Sim"<<std::endl;
    std::cout<<"\n\n\n";
    std::cout<<"Opção: ";
    try{
        std::cin>>opcaoEscolhida;
    }
    catch (int e){
        std::cout<<"Opção inválida."<<std::endl;
    }
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    if(opcaoEscolhida == 1){
        escolhaOpcoes();
    }
    else{
        //TODO: registrar.
        break;
    }
}
int escolhaOpcoes(){
    int salaEscolhida;
    std::cout<<"====================================================="<<std::endl;
    std::cout<<"O que deseja fazer?"<<std::endl;
    std::cout<<"\n";
    std::cout<<"1) Ir à sala 1 \t2) Ir à sala 2 \t3) Ir à sala 3"<<std::endl;
    std::cout<<"4) Criar novo evento\t5) Modificar evento\t6) Adicionar Participante"<<std::endl;
    std::cout<<"\n\n\n\n";
    std::cout<<"Opção: ";
    try{
        std::cin>>salaEscolhida;
    }
    catch (int e){
        std::cout<<"Opção inválida."<<std::endl;
    }
    std::cout<<"Aguarde verificação facial e autenticação."<<std::endl;
    sleep(2);
    std::cout<<"Verificação facial não identificada."<<std::endl;
    std::cout<<"Tentando login manualmente."<<std::endl;
    sleep(2);
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    return salaEscolhida;
}
int fazerLogin(){
    std::string cpf;
    std::cout<<"====================================================="<<std::endl;
    std::cout<<"Digite seu CPF:"<<std::endl;
    //std::cout<<labOficial.gerenciador.verificaCPF(cpf)<<std::endl;
    if()
    std::cout<<"4) Criar novo evento\t5) Modificar evento\t6) Adicionar Participante"<<std::endl;
    std::cout<<"\n\n\n\n";
    std::cout<<"Opção: ";
    try{
        std::cin>>salaEscolhida;
    }
    catch (int e){
        std::cout<<"Opção inválida."<<std::endl;
    }
    std::cout<<"Aguarde verificação facial e autenticação."<<std::endl;
    sleep(2);
    std::cout<<"Verificação facial não identificada."<<std::endl;
    sleep(2);
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    return salaEscolhida;
}

int main(int argc, char * argv[]) {
    int escolha;
    //CLI
    while(true){
        boasVindas();
    }
}
