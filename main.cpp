#include <cstdlib>
#include <iostream>
#include "funcoes.cpp"

int main(int argc, char * argv[]) {
    int escolha;
    std::cout<<"========================================"<<std::endl;
    std::cout<<"Bom dia, o que deseja fazer?"<<std::endl;
    std::cout<<"0) Agendar sala \n1)Ir à sala 1 \t2)Ir à sala 2 \t3) Ir à sala 3"<<std::endl;
    std::cout<<"4) Novo cadastro \t5)Outros"<<std::endl;
    std::cout<<"Opção: ";
    std::cin>>escolha;
    std::cout<<"Aguarde verificação facial e autenticação."<<std::endl;
    permitirAcesso(escolha, true);
    return 0;
}
