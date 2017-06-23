#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "funcoes.cpp"
#include "classes.cpp"

int boasVindas();
int escolhaOpcoes();
int fazerLogin(int opcaoEscolhida);
void registrar();

Laboratorio labOficial = Laboratorio();
Usuario usuarioAtual;

int boasVindas(){
    int opcaoEscolhida;
    std::cout<<"====================================================="<<std::endl;
    std::cout<<"Bem vindo, você já possui registro?"<<std::endl;
    std::cout<<"\n";
    std::cout<<"0) Não \n1) Sim"<<std::endl;
    std::cout<<"\n\n\n\n\n\n";
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
        registrar();
    }
    return -1;
}
void registrar(){
    std::string novoNome;
    std::string novoSobrenome;
    std::string novoCPF;
    int novoTipo;
    std::cout<<"====================================================="<<std::endl;
    std::cout<<"Qual seu nome? ";
    std::cin>>novoNome;
    std::cout<<"Qual seu sobrenome? ";
    std::cin>>novoSobrenome;
    std::cout<<"Qual seu cpf? ";
    std::cin>>novoCPF;
    std::cout<<"Qual seu cargo?"<<std::endl;
    std::cout<<"\n";
    std::cout<<"1) Estudante \t2) Palestrante \t3)Professor \t4)Funcionário do laboratório"<<std::endl;
    std::cout<<"\n\n\n\n";
    std::cout<<"Opção: ";
    std::cin>>novoTipo;
    usuarioAtual = Usuario(novoNome,novoSobrenome,novoCPF,novoTipo);
    std::cout<<"Registro efetuado com sucesso"<<std::endl;
}
int escolhaOpcoes(){
    int opcaoEscolhida;
    std::cout<<"====================================================="<<std::endl;
    std::cout<<"O que deseja fazer?"<<std::endl;
    std::cout<<"\n";
    std::cout<<"1) Ir à sala 1 \t2) Ir à sala 2 \t3) Ir à sala 3"<<std::endl;
    std::cout<<"4) Criar novo evento\t5) Modificar evento\t6) Adicionar Participante"<<std::endl;
    std::cout<<"\n\n\n\n\n\n";
    std::cout<<"Opção: ";
    try{
        std::cin>>opcaoEscolhida;
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
    fazerLogin(opcaoEscolhida);
    return 0;
}
int fazerLogin(int opcaoEscolhida){
    std::string cpf;
    std::cout<<"====================================================="<<std::endl;
    std::cout<<"\n\n\n\n\n\n\n\n\n\n";
    std::cout<<"Digite seu CPF: ";
    try{
        std::cin>>cpf;
    }
    catch (int e){
        std::cout<<"Opção inválida."<<std::endl;
    }
    bool allowed = false;
    for(int i = 0; i < 24; i++){
        if(labOficial.salas[opcaoEscolhida].semanas[0].dias[0].eventos[(i/2)].verificaParticipante(cpf)== "Participante encontra-se registrado no evento."){
            allowed = true;
            std::cout<<"Participante encontra-se registrado no evento. Portas para sala " + std::to_string(opcaoEscolhida) + " abertas.";
            break;
        }
    }
    if(allowed){
        std::cout<<"Fim do programa.";
        sleep(3);
        std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

        return 0;
    }
    else{
        std::cout<<"Fim do programa!";
        sleep(5);

    }
    sleep(5);
    std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    return -1;
}

int main(int argc, char * argv[]) {
    int escolha;
    //CLI
    while(true){
        boasVindas();
    }
    return 0;
}
