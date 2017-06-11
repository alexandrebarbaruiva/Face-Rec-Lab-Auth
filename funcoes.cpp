#include <cstdlib>
#include <iostream>

int processo(int escolhido) {
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
    return -1;
}
