#include <cstdlib>
#include <iostream>

/*
Trocar bool por int para aumentar possibilidades
-1 : Acesso a nada
0: Acesso somente ao lab para agendamento
1: Acesso à sala 1 somente
2: Acesso à sala 2 somente
3: Acesso à sala 3 somente
12: Acesso às salas 1 e 2 somente
13: Acesso às salas 1 e 3 somente
23: Acesso às salas 2 e 3 somente
123: Acesso a todas as salas
*/

//processo() deverá ser incorporado em Gerenciador
int permitirAcesso(int escolhido, bool autenticado) {
    if (!autenticado){
        std::cout<<"Você não tem acesso ao laboratório."<<std::endl;
        return -1;
    }
    else {
        if (escolhido == 0) {
            std::cout<<"Portas liberadas, você tem acesso ao laboratório, agende sua sala."<<std::endl;
            return 0;
        }
        if (escolhido == 1) {
            std::cout<<"Portas liberadas, você tem acesso à sala 1, boa aula."<<std::endl;
            return 1;
        }
        if (escolhido == 2) {
            std::cout<<"Portas liberadas, você tem acesso à sala 2, boa aula."<<std::endl;
            return 2;
        }
        if (escolhido == 3) {
            std::cout<<"Portas liberadas, você tem acesso à sala 3, boa aula."<<std::endl;
            return 3;
        }
        else {
            std::cout<<"Escolha inadequada, tente novamente."<<std::endl;
        }
    }
    return -1;
}
