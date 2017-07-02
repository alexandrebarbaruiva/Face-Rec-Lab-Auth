#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include "classes.cpp"

int boasVindas();
int escolhaOpcoes();
int fazerLogin(int opcaoEscolhida);
void registrar();

Laboratorio labOficial = Laboratorio();
Usuario usuarioAtual;

// INICIO
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
    if(opcaoEscolhida == 1){
        escolhaOpcoes();
    }
    else{
        registrar();
    }
    return -1;
}

// OPCAO 0
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

// OPCAO 1
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
    fazerLogin(opcaoEscolhida);
    return 0;
}
int fazerLogin(int opcaoEscolhida){
    std::string cpf;
    int horarioUsuario;
    std::cout<<"====================================================="<<std::endl;
    bool allowed = false;
    if(opcaoEscolhida > 0 and opcaoEscolhida <= 3){
        std::cout<<"\n\n\n\n\n\n\n\n\n\n";
        std::cout<<"Qual o horário do evento? Digite apenas o número: ";
        std::cout<<"Digite seu CPF: ";
        try{
            std::cin>>cpf;
        }
        catch (int e){
            std::cout<<"Opção inválida."<<std::endl;
        }
        for(int i = 0; i < 24; i++){
            if(labOficial.salas[opcaoEscolhida].semanas[0].dias[0].eventos[(i/2)].verificaParticipante(cpf)== "Participante encontra-se registrado no evento."){
                allowed = true;
                std::cout<<"Participante encontra-se registrado no evento. Portas para sala " + std::to_string(opcaoEscolhida) + " abertas.";
                break;
            }
        }
    }
    else if(usuarioAtual.getTipo() >= 2 and usuarioAtual.getTipo() <= 4){
        std::cout<<"\n\n\n\n\n\n\n\n\n\n";
        std::cout<<"Digite seu CPF: ";
        try{
            std::cin>>cpf;
        }
        catch (int e){
            std::cout<<"Opção inválida."<<std::endl;
        }
        // Por enquanto evento sobrescreve o que estiver no local
        if(opcaoEscolhida == 4){
            std::string nomeEvento;
            std::string propositoEvento;
            std::string reservadorEvento = usuarioAtual.getNome();
            int semanaEvento;
            int diaEvento;
            int horarioEvento;

            std::cout<<"Qual o nome do evento? ";
            std::cin>>nomeEvento;

            std::cout<<"Qual o propósito do evento? ";
            std::cin>>propositoEvento;

            std::cout<<"Qual a semana do evento? ";
            std::cin>>semanaEvento;
            std::cout<<"Qual o dia do evento?\n0) Segunda\t1) Terça\t2) Quarta\t3) Quinta\t4) Sexta\t5) Sábado\t6) Domingo\n";
            std::cin>>diaEvento;
            std::cout<<"Qual o horário do evento? ";
            std::cin>>horarioEvento;

        }
    }

    if(allowed){
        std::cout<<"Fim do programa.";
        sleep(3);
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
    while(true){
        boasVindas();
    }
    return 0;
}
