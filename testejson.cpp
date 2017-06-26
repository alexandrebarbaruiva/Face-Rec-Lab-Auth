#include "others/json.hpp"
#include <iomanip> // for std::setw
#include <iostream>
#include <fstream>
#include <string>

using json = nlohmann::json;

int main()
{
    /*
    // Exemplo padrão:

    // create a JSON object
    json object =
    {
        {"one", 1}, {"two", 2}, {"three", 2.9}
    };

    // output element with key "two"
    std::cout << object["two"] << "\n\n";

    // change element with key "three"
    object["three"] = 3;

    // output changed array
    std::cout << std::setw(4) << object << "\n\n";

    // mention nonexisting key
    object["four"];

    // write to nonexisting key
    object["five"]["really"]["nested"] = true;

    // output changed object
    std::cout << std::setw(4) << object << '\n';
    */

    // Abre arquivo para escrita de dados
    std::ofstream myfile;
    myfile.open("001.txt");

    // Se aberto, escreve dados
    if(myfile.is_open()){
        // Criando o JSON de deverá conter as informações
        json object = {{"nome", "Alexandre"},{"cpfOuMatricula", "0123456789"},
            {"acesso", {true,false,true}}};

        // Escrevendo no arquivo de forma estruturada
        myfile<<std::setw(4)<<object<<std::endl;

        // Mostrando na tela de forma estruturada
        std::cout<<std::setw(4)<<object<<std::endl;

        // Verificando se tem como pegar informações individualmente
        std::cout<<object["nome"]<<std::endl;
        std::cout<<object["acesso"][1]<<std::endl;
    }

    // Abre arquivo para leitura de dados
    std::ifstream otherfile;
    otherfile.open("001.txt");

    // Se aberto, lê dados
    if(otherfile.is_open()){
        std::string line;
        std::string myString;

        // Faz a leitura. TODO: Precisa implementar código.
        /*
        while (getline (otherfile, line)) {
            for(int i = 0; i < sizeof(line); i++){
                if(line[i] == ':'){
                    line[i] = ',';
                }
                else if(line[i] == '['){
                    line[i] = '{';
                }
                else if(line[i] == ']'){
                    line[i] = '}';
                }
                else if(line[i] == '{'){
                    line[i] = '{{';
                }
            }
            myString += line;
        }
        std::cout<<myString<<std::endl;
        json newObject = myString;

        std::cout<<newObject<<std::endl;
        */
        myfile.close();
    }
}
