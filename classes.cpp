#include <string>

/*
class Autenticador;
class Gerenciador; //antiga porta, responsável por permitir entrada a lab e salas
//class BD; //onde ficam todos os dados de usuarios
class Laboratorio; //conjunto de salas
class Sala; //self explanatory
class Dia; //uma classe com struct de todos os eventos do dia
class Semana;
*/

/* Exemplo de como criar uma lista ordenada que pode ser utilizada no BD, ainda nao achei como salvar isso no arquivo json...
#include "json.hpp"

using json = nlohmann::json;

int main()
{
    // create JSON values
    json object = {{"1-CPF", "2-Nome"}};

    // print values
    std::cout << object << '\n';

    // add values
    auto res1 = object.emplace("123456789", "Caio");
    res1 = object.emplace("987654321", "Matheus");
    res1 = object.emplace("987651234", "Victor");
    res1 = object.emplace("123459876", "Alexandre");

    auto aluno = object.find("123456789");
    // print values
    std::cout << object << '\n';
    std::cout << *aluno << '\n';
    std::cout << *res1.first << " " << std::boolalpha << res1.second << '\n';
}
;
}
*/
