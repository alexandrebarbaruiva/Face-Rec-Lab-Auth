#define CATCH_CONFIG_MAIN // Para rodar código sem unit testing é só comentar esta linha e TEST_CASE e tirar o coment da main
#include <cstdlib>
#include <iostream>
#include "catch.hpp"

int processo(int escolhido);

// Comente isto quando for usar Catch
/*
int main(int argc, char * argv[]) {
    int escolha;
    std::cout<<"========================================"<<std::endl;
    std::cout<<"Bom dia, o que deseja fazer?"<<std::endl;
    std::cout<<"0) Agendar sala \n1)Ir à sala 1 \t2)Ir à sala 2 \t3) Ir à sala 3"<<std::endl;
    std::cout<<"Opção: ";
    std::cin>>escolha;
    std::cout<<"Aguarde verificação facial e autenticação."<<std::endl;
    processo(escolha);
    return 0;
}
*/

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

// Comente todo o código abaixo para rodar a main daqui

TEST_CASE("Verificação de acesso", "[porta liberada]") {
    REQUIRE( processo(0) == 0 );
    REQUIRE( processo(1) == 1 );
    REQUIRE( processo(2) == 2 );
    REQUIRE( processo(3) == 3 );
    REQUIRE( processo(100) == -1 );

}
