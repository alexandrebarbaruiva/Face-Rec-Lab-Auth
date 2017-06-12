#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "funcoes.cpp"
#include "classes.cpp"

TEST_CASE("Verificação de acesso", "[porta liberada], [autorização]") {

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
    }

    Usuario teste;
    SECTION("Verifica classes", "[]" ){
        REQUIRE(teste.)
    }

}
