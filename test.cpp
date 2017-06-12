#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "funcoes.cpp"
#include "classes.cpp"

TEST_CASE("Verificação de acesso", "[porta liberada], [autorização]") {

    SECTION("Verificação de acesso", "[porta liberada], [autorização]")
    REQUIRE(processo(0, false) == -1 );
    REQUIRE(processo(0, true) == 0 );
    REQUIRE(processo(1, false) == -1 );
    REQUIRE(processo(1, true) == 1 );
    REQUIRE(processo(2, false) == -1 );
    REQUIRE(processo(2, true) == 2 );
    REQUIRE(processo(3, false) == -1 );
    REQUIRE(processo(3, true) == 3 );
    REQUIRE(processo(100, false) == -1 );
    REQUIRE(processo(100, true) == -1 );

    Usuario teste;
    SECTION("Verifica classes", "[]" )

}
