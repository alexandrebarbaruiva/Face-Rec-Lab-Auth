#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "funcoes.cpp"
#include "classes.cpp"

TEST_CASE("Verificação de interface de linha de comando") {

    SECTION("Verificação de acesso", "[porta liberada], [autorização]"){
        REQUIRE(permitirAcesso(0, false) == -1 );
        REQUIRE(permitirAcesso(0, true) == 0 );
        REQUIRE(permitirAcesso(1, false) == -1 );
        REQUIRE(permitirAcesso(1, true) == 1 );
        REQUIRE(permitirAcesso(2, false) == -1 );
        REQUIRE(permitirAcesso(2, true) == 2 );
        REQUIRE(permitirAcesso(3, false) == -1 );
        REQUIRE(permitirAcesso(3, true) == 3 );
        REQUIRE(permitirAcesso(100, false) == -1 );
        REQUIRE(permitirAcesso(100, true) == -1 );
        std::cout<<"ACESSO OK"<<std::endl;
    }
}

TEST_CASE("Verificação de classes") {

    SECTION("Verifica classe Usuário", "[Informação]" ){
        Usuario userTest = Usuario("Alexandre", "Augusto", "01245678900", 1);
        REQUIRE(userTest.getNome() == "Alexandre");
        REQUIRE(userTest.getSobrenome() == "Augusto");
        REQUIRE(userTest.getCPFouMatricula() == "01245678900");
        REQUIRE(userTest.getId() == 1);

        Usuario otherTest = Usuario();
        REQUIRE(otherTest.getNome() == "");
        REQUIRE(otherTest.getSobrenome() == "");
        REQUIRE(otherTest.getCPFouMatricula() == "");
        REQUIRE(otherTest.getId() == -1);
        std::cout<<"USUARIO OK"<<std::endl;
    }
}
